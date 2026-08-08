package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Fill, MuxLookup, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{IssueWakeup, RobWritebackPacket}
import top.core.backend.decoder.MemSize
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.bundle.{DataMemResp, DataMemTxn, RobAge, RobRecovery}

class LoadTxnAlloc(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx      = UInt(cfg.robIdxWidth.W)
  val vaddr       = UInt(cfg.addrWidth.W)
  val paddr       = UInt(cfg.addrWidth.W)
  val size        = UInt(3.W)
  val unsigned    = Bool()
  val forwardMask = UInt((cfg.dataWidth / 8).W)
  val forwardData = UInt(cfg.dataWidth.W)
}

/** Owns every normal-load tag from reservation through response or reliable cancellation.
  *
  * Recovery marks a transaction killed but does not release its tag. A killed response is still an exact live match and
  * is consumed without writeback. Only a response, a lower-path cancellation guarantee, or an explicit abort before the
  * request entered the outbound queue can make the slot reusable.
  */
class LoadTxnQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount  = cfg.loadTxnEntries
  private val idxWidth    = math.max(chisel3.util.log2Ceil(entryCount), 1)
  private val dataBytes   = cfg.dataWidth / 8
  private val cancelPorts = cfg.dmemQueueEntries + cfg.recoveryCancelPorts

  require(entryCount <= DataMemTxn.slotCount, "load transaction entries exceed the load tag slot field")

  val io = IO(new Bundle {
    val alloc      = Flipped(Decoupled(new LoadTxnAlloc(cfg)))
    val allocTxnId = Output(UInt(DataMemTxn.width.W))
    val markIssued = Input(Valid(UInt(DataMemTxn.width.W)))
    val abort      = Input(Valid(UInt(DataMemTxn.width.W)))

    val complete      = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val allowComplete = Input(Bool())
    val responseMatch = Output(Bool())
    val writeback     = Valid(new RobWritebackPacket(cfg))
    val wakeup        = Output(new IssueWakeup(cfg))

    val flush   = Input(Bool())
    val recover = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead = Input(UInt(cfg.robIdxWidth.W))
    val cancel  = Input(Vec(cancelPorts, Valid(UInt(DataMemTxn.width.W))))

    val occupancy = Output(UInt(math.max(chisel3.util.log2Ceil(entryCount + 1), 1).W))
    val empty     = Output(Bool())
  })

  private val active      = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val killed      = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val issued      = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val robIdx      = Reg(Vec(entryCount, UInt(cfg.robIdxWidth.W)))
  private val vaddr       = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val paddr       = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val size        = Reg(Vec(entryCount, UInt(3.W)))
  private val unsigned    = Reg(Vec(entryCount, Bool()))
  private val forwardMask = Reg(Vec(entryCount, UInt(dataBytes.W)))
  private val forwardData = Reg(Vec(entryCount, UInt(cfg.dataWidth.W)))

  private def tag(entry: Int): UInt =
    DataMemTxn.loadTag(entry.U(idxWidth.W))

  private val responseMatchOH = VecInit((0 until entryCount).map { entry =>
    active(entry) && io.complete.bits.txnId === tag(entry)
  })
  private val responseValid   = responseMatchOH.asUInt.orR
  private val responseIdx     = OHToUInt(responseMatchOH)

  private val cancelHit = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    cancelHit(entry) := active(entry) && io.cancel
      .map(cancel => cancel.valid && cancel.bits === tag(entry))
      .reduce(_ || _)
  }
  private val abortHit = VecInit((0 until entryCount).map { entry =>
    active(entry) && !issued(entry) && io.abort.valid && io.abort.bits === tag(entry)
  })

  private val killedNow = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    killedNow(entry) := active(entry) && (io.flush || (io.recover.valid &&
      RobAge.isYounger(robIdx(entry), io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)))
  }
  private val selectedKilled = killed(responseIdx) || killedNow(responseIdx)

  // Unknown tags are consumed and asserted below. Killed-but-live tags are recognized stale responses.
  io.complete.ready := !responseValid || selectedKilled || io.allowComplete
  private val responseFire = io.complete.fire && responseValid
  private val release      = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    release(entry) := (responseFire && responseIdx === entry.U) || cancelHit(entry) || abortHit(entry)
  }

  private val freeEntryOH  = VecInit(active.map(!_)).asUInt
  private val hasFreeEntry = freeEntryOH.orR
  private val freeEntryIdx = OHToUInt(PriorityEncoderOH(freeEntryOH))

  io.alloc.ready   := hasFreeEntry && !io.flush && !io.recover.valid
  io.allocTxnId    := DataMemTxn.loadTag(freeEntryIdx)
  io.responseMatch := responseValid
  io.occupancy     := PopCount(active)
  io.empty         := !active.asUInt.orR

  private val selectedForwardMask = forwardMask(responseIdx)
  private val expandedForwardMask = Cat((0 until dataBytes).reverse.map { byte =>
    Fill(8, selectedForwardMask(byte))
  })
  private val mergedData          = (io.complete.bits.data & ~expandedForwardMask) |
    (forwardData(responseIdx) & expandedForwardMask)

  private def extendLoad(data: UInt, loadSize: UInt, loadUnsigned: Bool): UInt = {
    val byte = data(7, 0)
    val half = data(15, 0)
    MuxLookup(loadSize, data)(
      Seq(
        MemSize.byte.U -> Mux(
          loadUnsigned,
          Cat(0.U((cfg.dataWidth - 8).W), byte),
          Cat(Fill(cfg.dataWidth - 8, byte(7)), byte)
        ),
        MemSize.half.U -> Mux(
          loadUnsigned,
          Cat(0.U((cfg.dataWidth - 16).W), half),
          Cat(Fill(cfg.dataWidth - 16, half(15)), half)
        )
      )
    )
  }

  private val responseResult        = extendLoad(mergedData, size(responseIdx), unsigned(responseIdx))
  private val architecturalResponse = responseFire && !selectedKilled

  io.writeback.valid          := architecturalResponse
  io.writeback.bits           := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.robIdx    := robIdx(responseIdx)
  io.writeback.bits.result    := responseResult
  io.writeback.bits.storeAddr := paddr(responseIdx)
  when(io.complete.bits.fault) {
    io.writeback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAccessFault, vaddr(responseIdx), cfg)
  }

  io.wakeup.valid  := architecturalResponse && !io.complete.bits.fault
  io.wakeup.robIdx := robIdx(responseIdx)
  io.wakeup.data   := responseResult

  for (entry <- 0 until entryCount) {
    when(killedNow(entry)) {
      killed(entry) := true.B
    }
    when(io.markIssued.valid && io.markIssued.bits === tag(entry) && active(entry)) {
      issued(entry) := true.B
    }
    when(release(entry)) {
      active(entry) := false.B
      killed(entry) := false.B
      issued(entry) := false.B
    }
    when(io.alloc.fire && freeEntryIdx === entry.U) {
      active(entry)      := true.B
      killed(entry)      := false.B
      issued(entry)      := false.B
      robIdx(entry)      := io.alloc.bits.robIdx
      vaddr(entry)       := io.alloc.bits.vaddr
      paddr(entry)       := io.alloc.bits.paddr
      size(entry)        := io.alloc.bits.size
      unsigned(entry)    := io.alloc.bits.unsigned
      forwardMask(entry) := io.alloc.bits.forwardMask
      forwardData(entry) := io.alloc.bits.forwardData
    }
  }

  when(io.markIssued.valid) {
    val hits = VecInit((0 until entryCount).map(entry => active(entry) && io.markIssued.bits === tag(entry)))
    assert(PopCount(hits) === 1.U, "issued load request must reference one reserved transaction tag")
  }
  when(io.abort.valid) {
    assert(PopCount(abortHit) === 1.U, "unissued load abort must reference one reserved transaction tag")
  }
  when(io.complete.fire) {
    assert(responseValid, "load response must match one live or killed transaction")
    assert(PopCount(responseMatchOH) === 1.U, "load response matched multiple transaction slots")
  }
  for (port <- 0 until cancelPorts) {
    when(io.cancel(port).valid && DataMemTxn.isLoad(io.cancel(port).bits)) {
      val hits = VecInit((0 until entryCount).map(entry => active(entry) && io.cancel(port).bits === tag(entry)))
      assert(PopCount(hits) === 1.U, "load cancellation must reference one live transaction")
    }
  }
  for (left <- 0 until entryCount) {
    for (right <- left + 1 until entryCount) {
      when(active(left) && active(right)) {
        assert(tag(left) =/= tag(right), "live load transaction tags must be unique")
      }
    }
  }
}
