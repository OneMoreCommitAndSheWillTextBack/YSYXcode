package top.trace

import chisel3._
import chisel3.util.PopCount
import top.config.FrontendConfig
import top.core.monitor.FrontendMonitor
import top.core.frontend.bundle.FrontendRecoveryKind

class FrontendTraceSample(cfg: FrontendConfig) extends Bundle {
  val events                 = UInt(FrontendPerfEvent.width.W)
  val stallEvents            = UInt(FrontendStallEvent.width.W)
  val fetchQueueOccupancy    = UInt(32.W)
  val fetchQueueEnqueueWidth = UInt(32.W)
  val fetchQueueDequeueWidth = UInt(32.W)
  val ifuCorrection          = Bool()
  val icacheLookupValid      = Bool()
  val icacheBlockValidMask   = UInt(cfg.fetchGroupBlocks.W)
  val icacheMissMask         = UInt(cfg.fetchGroupBlocks.W)
  val icacheBlockAddr        = Vec(cfg.fetchGroupBlocks, UInt(cfg.addrWidth.W))
}

/** Composition-level frontend observer. It has no outputs that can affect functional control. */
class FrontendTrace(cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val monitor = Input(new FrontendMonitor(cfg))
    val sample  = Output(new FrontendTraceSample(cfg))
  })

  val icacheTrace = Module(new ICacheTrace(cfg))
  val bpuTrace    = Module(new BpuTrace)
  icacheTrace.io.req        := io.monitor.icacheReq
  icacheTrace.io.resp       := io.monitor.icacheResp
  icacheTrace.io.refillReq  := io.monitor.icacheRefillReq
  icacheTrace.io.refillResp := io.monitor.icacheRefillResp
  icacheTrace.io.lookup     := io.monitor.icacheLookup
  icacheTrace.io.recovery   := io.monitor.recovery
  icacheTrace.io.invalidate := io.monitor.invalidate
  bpuTrace.io.monitor       := io.monitor.bpu

  private val redirectDuringMshr            =
    io.monitor.backendRedirect.valid && icacheTrace.io.missActive && !io.monitor.invalidate
  private val fetchQueueSupplyStarved       =
    !io.monitor.fetchValid && io.monitor.fetchReady && !io.monitor.pcRedirect.valid && !io.monitor.invalidate
  private val backendBackpressure           = io.monitor.fetchValid && !io.monitor.fetchReady
  private val fetchQueueEnqueueBackpressure = io.monitor.fetchQueueEnqueue.valid && !io.monitor.fetchQueueEnqueue.ready
  private val icacheRequestBackpressure     = io.monitor.icacheReq.valid && !io.monitor.icacheReq.ready
  private val fetchQueueIncomingEnqueue     = io.monitor.fetchQueueEnqueue.valid && io.monitor.fetchQueueEnqueue.ready
  private val recoveryRefillPending         = RegInit(false.B)
  private val recoveryRefillKind            = Reg(FrontendRecoveryKind())
  when(io.monitor.recovery.valid) {
    recoveryRefillPending := true.B
    recoveryRefillKind    := io.monitor.recovery.bits.kind
  }.elsewhen(fetchQueueIncomingEnqueue) {
    recoveryRefillPending := false.B
  }
  private def backendLike(kind: FrontendRecoveryKind.Type): Bool =
    kind === FrontendRecoveryKind.backend || kind === FrontendRecoveryKind.trap ||
      kind === FrontendRecoveryKind.reset

  private val backendRecoveryHold            = io.monitor.recovery.valid && backendLike(io.monitor.recovery.bits.kind)
  private val ifuRecoveryHold                =
    io.monitor.recovery.valid && io.monitor.recovery.bits.kind === FrontendRecoveryKind.ifuCorrection
  private val bpuRecoveryHold                =
    io.monitor.recovery.valid && io.monitor.recovery.bits.kind === FrontendRecoveryKind.bpuOverride
  private val fetchQueueNoIncomingStarvation = fetchQueueSupplyStarved && !fetchQueueIncomingEnqueue
  private val starvationByIcacheMiss         = fetchQueueNoIncomingStarvation && icacheTrace.io.missActive
  private val starvationByRecoveryRefill     = fetchQueueNoIncomingStarvation && !icacheTrace.io.missActive &&
    recoveryRefillPending
  private val starvationByFtqReserve         = fetchQueueNoIncomingStarvation && !icacheTrace.io.missActive &&
    !recoveryRefillPending && io.monitor.ftqReserveBackpressure
  private val starvationByPipelineBubble     = fetchQueueNoIncomingStarvation && !icacheTrace.io.missActive &&
    !recoveryRefillPending && !io.monitor.ftqReserveBackpressure
  private val starvationAfterBackendRecovery = starvationByRecoveryRefill && backendLike(recoveryRefillKind)
  private val starvationAfterIfuCorrection   = starvationByRecoveryRefill &&
    recoveryRefillKind === FrontendRecoveryKind.ifuCorrection
  private val starvationAfterBpuOverride     = starvationByRecoveryRefill &&
    recoveryRefillKind === FrontendRecoveryKind.bpuOverride
  private val starvationCauses               = VecInit(
    Seq(starvationByIcacheMiss, starvationByRecoveryRefill, starvationByFtqReserve, starvationByPipelineBubble)
  )
  private val recoveryHoldCauses             = VecInit(Seq(backendRecoveryHold, ifuRecoveryHold, bpuRecoveryHold))
  private val recoveryRefillCauses           = VecInit(
    Seq(starvationAfterBackendRecovery, starvationAfterIfuCorrection, starvationAfterBpuOverride)
  )

  when(fetchQueueNoIncomingStarvation) {
    assert(PopCount(starvationCauses) === 1.U)
  }
  when(io.monitor.recovery.valid) {
    assert(PopCount(recoveryHoldCauses) === 1.U)
  }
  when(starvationByRecoveryRefill) {
    assert(PopCount(recoveryRefillCauses) === 1.U)
  }

  private val compositionEvents = Seq(
    FrontendPerfEvent.bit(FrontendPerfEvent.backendRedirect, io.monitor.backendRedirect.valid),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheInvalidate, io.monitor.invalidate),
    FrontendPerfEvent.bit(FrontendPerfEvent.frontendEmpty, io.monitor.fetchReady && !io.monitor.fetchValid),
    FrontendPerfEvent.bit(
      FrontendPerfEvent.axiRequestWait,
      io.monitor.refillPhysicalReqValid && !io.monitor.refillPhysicalReqReady
    ),
    FrontendPerfEvent.bit(FrontendPerfEvent.fetchQueueEmptyWithBackendReady, fetchQueueSupplyStarved),
    FrontendPerfEvent.bit(FrontendPerfEvent.fetchQueueFull, io.monitor.fetchQueueFull),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshr, redirectDuringMshr),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshrTargetHit, false.B),
    FrontendPerfEvent.bit(FrontendPerfEvent.staleResponseDrop, io.monitor.ifuStaleDrop)
  ).reduce(_ | _)

  private val stallEvents = Seq(
    FrontendStallEvent.bit(FrontendStallEvent.backendBackpressure, backendBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.backendBackpressureFetchQueueFull,
      backendBackpressure && io.monitor.fetchQueueFull
    ),
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueEnqueueBackpressure, fetchQueueEnqueueBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueFullBackpressure,
      fetchQueueEnqueueBackpressure && io.monitor.fetchQueueFull
    ),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueuePartialBackpressure,
      fetchQueueEnqueueBackpressure && !io.monitor.fetchQueueFull
    ),
    FrontendStallEvent.bit(FrontendStallEvent.alignerOutputBackpressure, io.monitor.alignerOutputBackpressure),
    FrontendStallEvent.bit(FrontendStallEvent.blockBufferOutputBackpressure, io.monitor.blockBufferBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.icacheResponseBackpressure,
      io.monitor.icacheResp.valid && !io.monitor.icacheResp.ready
    ),
    FrontendStallEvent.bit(FrontendStallEvent.icacheRequestBackpressure, icacheRequestBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.icacheRequestMissBackpressure,
      icacheRequestBackpressure && icacheTrace.io.missActive
    ),
    FrontendStallEvent.bit(
      FrontendStallEvent.icacheRequestNonMissBackpressure,
      icacheRequestBackpressure && !icacheTrace.io.missActive
    ),
    FrontendStallEvent.bit(FrontendStallEvent.ftqReserveBackpressure, io.monitor.ftqReserveBackpressure),
    FrontendStallEvent.bit(FrontendStallEvent.recoveryHold, io.monitor.recovery.valid),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueStarvedWithIncomingEnqueue,
      fetchQueueSupplyStarved && fetchQueueIncomingEnqueue
    ),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueStarvedWithoutIncomingEnqueue,
      fetchQueueNoIncomingStarvation
    ),
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueStarvedByIcacheMiss, starvationByIcacheMiss),
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueStarvedByRecoveryRefill, starvationByRecoveryRefill),
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueStarvedByFtqReserve, starvationByFtqReserve),
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueStarvedByPipelineBubble, starvationByPipelineBubble),
    FrontendStallEvent.bit(FrontendStallEvent.recoveryHoldBackend, backendRecoveryHold),
    FrontendStallEvent.bit(FrontendStallEvent.recoveryHoldIfuCorrection, ifuRecoveryHold),
    FrontendStallEvent.bit(FrontendStallEvent.recoveryHoldBpuOverride, bpuRecoveryHold),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueStarvedAfterBackendRecovery,
      starvationAfterBackendRecovery
    ),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueStarvedAfterIfuCorrection,
      starvationAfterIfuCorrection
    ),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueStarvedAfterBpuOverride,
      starvationAfterBpuOverride
    )
  ).reduce(_ | _)

  io.sample.events                 := icacheTrace.io.events | bpuTrace.io.events | compositionEvents
  io.sample.stallEvents            := stallEvents
  io.sample.fetchQueueOccupancy    := io.monitor.fetchQueueOccupancy
  io.sample.fetchQueueEnqueueWidth := io.monitor.fetchQueueEnqueueWidth
  io.sample.fetchQueueDequeueWidth := io.monitor.fetchQueueDequeueWidth
  io.sample.ifuCorrection          := io.monitor.recovery.valid &&
    io.monitor.recovery.bits.kind === top.core.frontend.bundle.FrontendRecoveryKind.ifuCorrection
  io.sample.icacheLookupValid      := icacheTrace.io.semantic.lookupValid
  io.sample.icacheBlockValidMask   := icacheTrace.io.semantic.blockValidMask
  io.sample.icacheMissMask         := icacheTrace.io.semantic.missMask
  io.sample.icacheBlockAddr        := icacheTrace.io.semantic.blockAddr
}
