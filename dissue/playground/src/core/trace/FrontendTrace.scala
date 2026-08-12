package top.core.trace

import chisel3._
import chisel3.util.{PopCount, Valid}
import top.config.FrontendConfig
import top.core.bundle.{FrontendPerfEvent, FrontendStallEvent}
import top.core.frontend.bundle.{
  FrontendRecovery,
  ICacheFetchReq,
  ICacheFetchResp,
  ICacheLookupResult,
  ICacheRefillReq,
  ICacheRefillResp,
  PcRedirect,
  RasPerf
}

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
    val backendRedirect = Input(new PcRedirect)
    val pcRedirect      = Input(new PcRedirect)
    val invalidate      = Input(Bool())
    val recovery        = Input(Valid(new FrontendRecovery(cfg)))

    val fetchValid = Input(Bool())
    val fetchReady = Input(Bool())

    val fetchQueueEnqueueValid    = Input(Bool())
    val fetchQueueEnqueueReady    = Input(Bool())
    val alignerOutputBackpressure = Input(Bool())
    val blockBufferBackpressure   = Input(Bool())
    val ftqReserveBackpressure    = Input(Bool())

    val refillPhysicalReqValid = Input(Bool())
    val refillPhysicalReqReady = Input(Bool())

    val icacheReq        = Input(new DecoupledTraceTap(new ICacheFetchReq(cfg)))
    val icacheResp       = Input(new DecoupledTraceTap(new ICacheFetchResp(cfg)))
    val icacheRefillReq  = Input(new DecoupledTraceTap(new ICacheRefillReq(cfg.addrWidth)))
    val icacheRefillResp = Input(new DecoupledTraceTap(new ICacheRefillResp(cfg.icacheLineBytes)))
    val icacheLookup     = Input(Valid(new ICacheLookupResult(cfg)))
    val bpuMonitor       = Input(new RasPerf)
    val ifuStaleDrop     = Input(Bool())

    val fetchQueueEmpty        = Input(Bool())
    val fetchQueueFull         = Input(Bool())
    val fetchQueueOccupancy    = Input(UInt(32.W))
    val fetchQueueEnqueueWidth = Input(UInt(32.W))
    val fetchQueueDequeueWidth = Input(UInt(32.W))

    val sample = Output(new FrontendTraceSample(cfg))
  })

  val icacheTrace = Module(new ICacheTrace(cfg))
  val bpuTrace    = Module(new BpuTrace)
  icacheTrace.io.req        := io.icacheReq
  icacheTrace.io.resp       := io.icacheResp
  icacheTrace.io.refillReq  := io.icacheRefillReq
  icacheTrace.io.refillResp := io.icacheRefillResp
  icacheTrace.io.lookup     := io.icacheLookup
  icacheTrace.io.recovery   := io.recovery
  icacheTrace.io.invalidate := io.invalidate
  bpuTrace.io.monitor       := io.bpuMonitor

  private val redirectDuringMshr             = io.backendRedirect.valid && icacheTrace.io.missActive && !io.invalidate
  private val fetchQueueSupplyStarved        =
    io.fetchQueueEmpty && io.fetchReady && !io.pcRedirect.valid && !io.invalidate
  private val backendBackpressure            = io.fetchValid && !io.fetchReady
  private val fetchQueueEnqueueBackpressure  = io.fetchQueueEnqueueValid && !io.fetchQueueEnqueueReady
  private val icacheRequestBackpressure      = io.icacheReq.valid && !io.icacheReq.ready
  private val fetchQueueIncomingEnqueue      = io.fetchQueueEnqueueValid && io.fetchQueueEnqueueReady
  private val recoveryRefillPending          = RegInit(false.B)
  when(io.recovery.valid) {
    recoveryRefillPending := true.B
  }.elsewhen(fetchQueueIncomingEnqueue) {
    recoveryRefillPending := false.B
  }
  private val fetchQueueNoIncomingStarvation = fetchQueueSupplyStarved && !fetchQueueIncomingEnqueue
  private val starvationByIcacheMiss         = fetchQueueNoIncomingStarvation && icacheTrace.io.missActive
  private val starvationByRecoveryRefill     = fetchQueueNoIncomingStarvation && !icacheTrace.io.missActive &&
    recoveryRefillPending
  private val starvationByFtqReserve         = fetchQueueNoIncomingStarvation && !icacheTrace.io.missActive &&
    !recoveryRefillPending && io.ftqReserveBackpressure
  private val starvationByPipelineBubble     = fetchQueueNoIncomingStarvation && !icacheTrace.io.missActive &&
    !recoveryRefillPending && !io.ftqReserveBackpressure
  private val starvationCauses               = VecInit(
    Seq(starvationByIcacheMiss, starvationByRecoveryRefill, starvationByFtqReserve, starvationByPipelineBubble)
  )

  when(fetchQueueNoIncomingStarvation) {
    assert(PopCount(starvationCauses) === 1.U)
  }

  private val compositionEvents = Seq(
    FrontendPerfEvent.bit(FrontendPerfEvent.backendRedirect, io.backendRedirect.valid),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheInvalidate, io.invalidate),
    FrontendPerfEvent.bit(FrontendPerfEvent.frontendEmpty, io.fetchReady && !io.fetchValid),
    FrontendPerfEvent.bit(
      FrontendPerfEvent.axiRequestWait,
      io.refillPhysicalReqValid && !io.refillPhysicalReqReady
    ),
    FrontendPerfEvent.bit(FrontendPerfEvent.fetchQueueEmptyWithBackendReady, fetchQueueSupplyStarved),
    FrontendPerfEvent.bit(FrontendPerfEvent.fetchQueueFull, io.fetchQueueFull),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshr, redirectDuringMshr),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshrTargetHit, false.B),
    FrontendPerfEvent.bit(FrontendPerfEvent.staleResponseDrop, io.ifuStaleDrop)
  ).reduce(_ | _)

  private val stallEvents = Seq(
    FrontendStallEvent.bit(FrontendStallEvent.backendBackpressure, backendBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.backendBackpressureFetchQueueFull,
      backendBackpressure && io.fetchQueueFull
    ),
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueEnqueueBackpressure, fetchQueueEnqueueBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueueFullBackpressure,
      fetchQueueEnqueueBackpressure && io.fetchQueueFull
    ),
    FrontendStallEvent.bit(
      FrontendStallEvent.fetchQueuePartialBackpressure,
      fetchQueueEnqueueBackpressure && !io.fetchQueueFull
    ),
    FrontendStallEvent.bit(FrontendStallEvent.alignerOutputBackpressure, io.alignerOutputBackpressure),
    FrontendStallEvent.bit(FrontendStallEvent.blockBufferOutputBackpressure, io.blockBufferBackpressure),
    FrontendStallEvent.bit(
      FrontendStallEvent.icacheResponseBackpressure,
      io.icacheResp.valid && !io.icacheResp.ready
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
    FrontendStallEvent.bit(FrontendStallEvent.ftqReserveBackpressure, io.ftqReserveBackpressure),
    FrontendStallEvent.bit(FrontendStallEvent.recoveryHold, io.recovery.valid),
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
    FrontendStallEvent.bit(FrontendStallEvent.fetchQueueStarvedByPipelineBubble, starvationByPipelineBubble)
  ).reduce(_ | _)

  io.sample.events                 := icacheTrace.io.events | bpuTrace.io.events | compositionEvents
  io.sample.stallEvents            := stallEvents
  io.sample.fetchQueueOccupancy    := io.fetchQueueOccupancy
  io.sample.fetchQueueEnqueueWidth := io.fetchQueueEnqueueWidth
  io.sample.fetchQueueDequeueWidth := io.fetchQueueDequeueWidth
  io.sample.ifuCorrection          := io.recovery.valid &&
    io.recovery.bits.kind === top.core.frontend.bundle.FrontendRecoveryKind.ifuCorrection
  io.sample.icacheLookupValid      := icacheTrace.io.semantic.lookupValid
  io.sample.icacheBlockValidMask   := icacheTrace.io.semantic.blockValidMask
  io.sample.icacheMissMask         := icacheTrace.io.semantic.missMask
  io.sample.icacheBlockAddr        := icacheTrace.io.semantic.blockAddr
}
