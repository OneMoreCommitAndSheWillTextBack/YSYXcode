package top.core.trace

import chisel3._
import chisel3.util.{Cat, Valid}
import top.config.FrontendConfig
import top.core.bundle.FrontendPerfEvent
import top.core.frontend.bundle.{
  FrontendRecovery,
  ICacheFetchReq,
  ICacheFetchResp,
  ICacheLookupResult,
  ICacheRefillReq,
  ICacheRefillResp
}

/** Reconstructs cache performance state from passive protocol boundaries. */
class ICacheSemanticSample(cfg: FrontendConfig) extends Bundle {
  val lookupValid    = Bool()
  val blockValidMask = UInt(cfg.fetchGroupBlocks.W)
  val missMask       = UInt(cfg.fetchGroupBlocks.W)
  val blockAddr      = Vec(cfg.fetchGroupBlocks, UInt(cfg.addrWidth.W))
}

class ICacheTrace(cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val req        = Input(new DecoupledTraceTap(new ICacheFetchReq(cfg)))
    val resp       = Input(new DecoupledTraceTap(new ICacheFetchResp(cfg)))
    val refillReq  = Input(new DecoupledTraceTap(new ICacheRefillReq(cfg.addrWidth)))
    val refillResp = Input(new DecoupledTraceTap(new ICacheRefillResp(cfg.icacheLineBytes)))
    val lookup     = Input(Valid(new ICacheLookupResult(cfg)))
    val recovery   = Input(Valid(new FrontendRecovery(cfg)))
    val invalidate = Input(Bool())

    val events     = Output(UInt(FrontendPerfEvent.width.W))
    val missActive = Output(Bool())
    val semantic   = Output(new ICacheSemanticSample(cfg))
  })

  val missActive        = RegInit(false.B)
  val refillOutstanding = RegInit(false.B)
  val stalePending      = RegInit(false.B)
  val missBlockAddr     = Reg(Vec(cfg.fetchGroupBlocks, UInt(cfg.addrWidth.W)))
  val missBlockValid    = RegInit(VecInit(Seq.fill(cfg.fetchGroupBlocks)(false.B)))

  private val lookupMiss   = io.lookup.valid && io.lookup.bits.missingMask.orR
  private val lookupHit    = io.lookup.valid && !io.lookup.bits.missingMask.orR
  private val cancellation = io.invalidate || io.recovery.valid

  private def lineAddress(addr: UInt): UInt =
    Cat(addr(cfg.addrWidth - 1, cfg.icache.lineOffsetBits), 0.U(cfg.icache.lineOffsetBits.W))

  when(lookupMiss) {
    missActive     := true.B
    stalePending   := false.B
    missBlockAddr  := io.lookup.bits.blockAddr
    missBlockValid := io.lookup.bits.blockValid
  }
  when(io.refillReq.fire) {
    refillOutstanding := true.B
  }
  when(io.refillResp.fire) {
    refillOutstanding := false.B
    when(stalePending) {
      missActive := false.B
    }
  }
  when(io.resp.fire && missActive && !lookupMiss) {
    missActive := false.B
  }
  when(cancellation && missActive) {
    when(refillOutstanding) {
      stalePending := true.B
    }.otherwise {
      missActive   := false.B
      stalePending := false.B
    }
  }

  private val sharesMiss   = VecInit((0 until cfg.fetchGroupBlocks).map { requestLane =>
    io.req.bits.blockValid(requestLane) && VecInit((0 until cfg.fetchGroupBlocks).map { missLane =>
      missBlockValid(missLane) &&
      lineAddress(io.req.bits.blockAddr(requestLane)) === lineAddress(missBlockAddr(missLane))
    }).asUInt.orR
  }).asUInt.orR
  private val sameLineWait = io.req.valid && !io.req.ready && missActive && sharesMiss
  private val staleDrop    = io.refillResp.fire && stalePending

  io.missActive              := missActive
  io.semantic.lookupValid    := io.lookup.valid
  io.semantic.blockValidMask := io.lookup.bits.blockValid.asUInt
  io.semantic.missMask       := io.lookup.bits.missingMask
  io.semantic.blockAddr      := io.lookup.bits.blockAddr
  io.events                  := Seq(
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheRequest, io.req.fire),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheHit, lookupHit),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMiss, lookupMiss),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMissWaitCycle, missActive && !io.resp.fire),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMshrActiveCycle, missActive),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheHitUnderMiss, false.B),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheSameLineWaitCycle, sameLineWait),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheQueuedMiss, false.B),
    FrontendPerfEvent.bit(FrontendPerfEvent.staleResponseDrop, staleDrop)
  ).reduce(_ | _)
}
