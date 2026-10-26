package top.core.backend.lsu

import chisel3._
import chisel3.util.{Decoupled, Mux1H, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.config.BackendConfig
import top.core.bundle.{RobAge, RobRecovery}
import top.core.mmu.MmuTranslateResp

object ReplayState {
  val width = 2

  val free       = 0.U(width.W)
  val reserved   = 1.U(width.W) // lookup issued, waiting for the immediate response
  val pending    = 2.U(width.W) // miss queued in the DTLB, waiting for completion
  val translated = 3.U(width.W)
}

class TranslationReplayEntry(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val req  = new TranslationRequest(cfg)
  val resp = new MmuTranslateResp(cfg)
}

/** Read-only per-entry view used by the LSU dispatcher to compute eligibility. */
class TranslationReplayView(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val translated = Bool()
  val pending    = Bool()
  val req        = new TranslationRequest(cfg)
  val resp       = new MmuTranslateResp(cfg)
}

class TranslationReplayQueueIO(cfg: BackendConfig = BackendConfig()) extends Bundle {
  // A slot is reserved when the lookup fires so a deferred response always has
  // a home. A hit completes the reserved slot, a miss parks it as pending.
  val reserve      = Flipped(Valid(new TranslationRequest(cfg)))
  val reserveReady = Output(Bool())

  val park            = Input(Valid(UInt(cfg.translationIdWidth.W)))
  val release         = Input(Valid(UInt(cfg.translationIdWidth.W)))
  val resolve         = Flipped(Valid(new MmuTranslateResp(cfg)))
  val complete        = Flipped(Valid(new MmuTranslateResp(cfg)))
  val completeMatched = Output(Bool())

  val eligible = Input(Vec(cfg.translationReplayEntries, Bool()))
  val deq      = Decoupled(new TranslationReplayEntry(cfg))
  val view     = Output(Vec(cfg.translationReplayEntries, new TranslationReplayView(cfg)))

  val recover = Input(new RobRecovery(cfg.robIdxWidth))
  val robHead = Input(UInt(cfg.robIdxWidth.W))
  val flush   = Input(Bool())

  val occupancy = Output(UInt(cfg.translationReplayCountWidth.W))
  val empty     = Output(Bool())
  val hasFree   = Output(Bool())
}

/** Holds translated and in-flight translations until the S3 dispatcher can use them.
  *
  * Entries are reserved in lookup order, but dispatch is out of order: the LSU supplies an `eligible` predicate per
  * entry so a younger store can resolve and unblock an older load while an unrelated miss is still walking. The oldest
  * eligible translated entry wins, which keeps progress deterministic without requiring program-order completion.
  */
class TranslationReplayQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount = cfg.translationReplayEntries

  val io = IO(new TranslationReplayQueueIO(cfg))

  private val state = RegInit(VecInit(Seq.fill(entryCount)(ReplayState.free)))
  private val req   = Reg(Vec(entryCount, new TranslationRequest(cfg)))
  private val resp  = Reg(Vec(entryCount, new MmuTranslateResp(cfg)))

  private val valid   = VecInit(state.map(_ =/= ReplayState.free))
  private val freeOH  = PriorityEncoderOH(~valid.asUInt)
  private val freeIdx = OHToUInt(freeOH)
  private val hasFree = freeOH.orR

  io.hasFree   := hasFree
  io.occupancy := PopCount(valid)
  io.empty     := !valid.asUInt.orR

  private def idMatch(entry: Int, id: UInt): Bool =
    req(entry).translationId === id

  private def age(entry: Int): UInt =
    RobAge.fromHead(req(entry).packet.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

  // ------------------------------------------------------------- reservations

  for (entry <- 0 until entryCount) {
    when(io.park.valid && state(entry) === ReplayState.reserved && idMatch(entry, io.park.bits)) {
      state(entry) := ReplayState.pending
    }
    when(io.release.valid && valid(entry) && idMatch(entry, io.release.bits)) {
      state(entry) := ReplayState.free
    }
    when(io.resolve.valid && state(entry) === ReplayState.reserved && idMatch(entry, io.resolve.bits.id)) {
      resp(entry)  := io.resolve.bits
      state(entry) := ReplayState.translated
    }
    when(
      io.complete.valid && (state(entry) === ReplayState.reserved || state(entry) === ReplayState.pending) &&
        idMatch(entry, io.complete.bits.id)
    ) {
      resp(entry)  := io.complete.bits
      state(entry) := ReplayState.translated
    }
  }

  // ---------------------------------------------------------------- dispatch

  private val translated = VecInit(state.map(_ === ReplayState.translated))
  private val candidate  = VecInit((0 until entryCount).map { entry =>
    translated(entry) && io.eligible(entry) && !VecInit((0 until entryCount).map { older =>
      translated(older) && io.eligible(older) && age(older) < age(entry)
    }).asUInt.orR
  })
  private val selectOH   = PriorityEncoderOH(candidate.asUInt)
  private val selectIdx  = OHToUInt(selectOH)

  io.deq.valid     := selectOH.orR
  io.deq.bits.req  := Mux1H(selectOH, req)
  io.deq.bits.resp := Mux1H(selectOH, resp)

  when(io.deq.fire) {
    state(selectIdx) := ReplayState.free
  }

  // A dispatch or a fast-path hit release may free the only usable slot in
  // this cycle. Reserve after both so a lookup issued in the response cycle
  // never needs an extra bubble.
  private val releaseOH  = PriorityEncoderOH(VecInit((0 until entryCount).map { entry =>
    valid(entry) && io.release.valid && idMatch(entry, io.release.bits)
  }).asUInt)
  private val releaseIdx = OHToUInt(releaseOH)
  private val canReserve = hasFree || io.deq.fire || releaseOH.orR
  private val reserveIdx = Mux(hasFree, freeIdx, Mux(io.deq.fire, selectIdx, releaseIdx))
  io.reserveReady := canReserve && !io.flush

  when(io.reserve.fire) {
    state(reserveIdx) := ReplayState.reserved
    req(reserveIdx)   := io.reserve.bits
    resp(reserveIdx)  := 0.U.asTypeOf(new MmuTranslateResp(cfg))
  }

  for (entry <- 0 until entryCount) {
    io.view(entry).translated := translated(entry)
    io.view(entry).pending    := state(entry) === ReplayState.pending
    io.view(entry).req        := req(entry)
    io.view(entry).resp       := resp(entry)
  }

  // ------------------------------------------------------------ flush/recover

  private val younger = VecInit((0 until entryCount).map { entry =>
    valid(entry) &&
    RobAge.isYounger(req(entry).packet.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  })

  when(io.flush) {
    for (entry <- 0 until entryCount) {
      state(entry) := ReplayState.free
    }
  }.otherwise {
    when(io.recover.valid) {
      for (entry <- 0 until entryCount) {
        when(younger(entry)) {
          state(entry) := ReplayState.free
        }
      }
    }
  }

  // A lookup completion may arrive for a killed reservation in the same cycle
  // the recover frees it; recover wins (assigned later).
  io.completeMatched := VecInit((0 until entryCount).map { entry =>
    (state(entry) === ReplayState.reserved || state(entry) === ReplayState.pending) &&
    idMatch(entry, io.complete.bits.id)
  }).asUInt.orR

  when(io.reserve.valid) {
    assert(io.reserveReady, "translation replay reservation without a free slot")
  }
  when(io.complete.valid) {
    assert(io.completeMatched, "asynchronous translation completion must match one live replay entry")
  }
}
