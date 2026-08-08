package top.core.frontend

import chisel3._
import chisel3.util.{Cat, Decoupled, MuxCase, Valid}
import top.core.backend.csr.CsrStatus
import top.core.bundle.{DataMemReq, DataMemResp, FrontendPerfEvent}
import top.config.{BackendConfig, FrontendConfig}
import top.core.frontend.Bpu.Bpu
import top.core.frontend.bundle.{
  BpuUpdate,
  ICacheRefillReq,
  ICacheRefillResp,
  PcRedirect,
  PredictorConstants,
  PredictorRecovery
}
import top.core.frontend.ifetch.{FetchPacket, FetchWidth, IFetch}
import top.core.frontend.pcgen.PCGen
import top.core.frontend.icache._
import top.core.trace.PipelineTraceEvent
import top.sim.FrontendPerfBridge

class Frontend(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         FrontendConfig = FrontendConfig())
    extends Module {
  private val backendCfg = BackendConfig(addrWidth = cfg.addrWidth)
  require(
    backendCfg.commitWidth == PredictorConstants.commitUpdateWidth,
    "BPU update width must match backend commit width"
  )

  val io = IO(new Bundle {
    val trapRedirect      = Input(new PcRedirect)
    val branchRedirect    = Input(new PcRedirect)
    val predRedirect      = Input(new PcRedirect)
    val bpuUpdates        = Input(Vec(PredictorConstants.commitUpdateWidth, Valid(new BpuUpdate(cfg.bpu))))
    val predictorRecovery = Input(Valid(new PredictorRecovery(cfg.addrWidth)))

    val pc    = Output(UInt(cfg.addrWidth.W))
    val fetch = Decoupled(new FetchPacket)

    val cacheRefillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
    val cacheRefillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))

    val ptwReq           = Decoupled(new DataMemReq(backendCfg.addrWidth, backendCfg.dataWidth))
    val ptwResp          = Flipped(Decoupled(new DataMemResp(backendCfg.dataWidth)))
    val csrStatus        = Input(new CsrStatus(backendCfg))
    val icacheInvalidate = Input(Bool())
    val pipelineTrace    = Output(Vec(FetchWidth.frontend, Valid(new PipelineTraceEvent)))
  })

  val pcGen     = Module(
    new PCGen(
      resetVector = resetVector,
      addrWidth = cfg.addrWidth,
      fetchBytes = cfg.fetchBytes,
      maxAdvanceBlocks = cfg.icache.fetchGroupBlocks
    )
  )
  val ifetch    = Module(new IFetch(cfg.icache, cfg.ifetch))
  val iCache    = Module(new ICache(cfg.icache))
  val refillMmu = Module(new ICacheRefillMmu(cfg.icache, backendCfg))
  val bpu       = Module(new Bpu(cfg.bpu))
  val perf      = Module(new FrontendPerfBridge)

  val redirect = Wire(new PcRedirect)
  redirect.valid := io.trapRedirect.valid || io.branchRedirect.valid || io.predRedirect.valid
  redirect.value := MuxCase(
    0.U(cfg.addrWidth.W),
    Seq(
      io.trapRedirect.valid   -> io.trapRedirect.value,
      io.branchRedirect.valid -> io.branchRedirect.value,
      io.predRedirect.valid   -> io.predRedirect.value
    )
  )

  val pcRedirect = Wire(new PcRedirect)
  pcRedirect.valid := redirect.valid || ifetch.io.predRedirect.valid
  pcRedirect.value := Mux(redirect.valid, redirect.value, ifetch.io.predRedirect.value)

  pcGen.io.redirect      := pcRedirect
  pcGen.io.advanceBlocks := ifetch.io.pcAdvanceBlocks

  ifetch.io.redirect                := redirect
  ifetch.io.flush                   := io.icacheInvalidate
  ifetch.io.pc                      := pcGen.io.pc
  ifetch.io.pred(0).valid           := bpu.io.pred.valid
  ifetch.io.pred(0).taken           := bpu.io.pred.taken
  ifetch.io.pred(0).target          := bpu.io.pred.target
  ifetch.io.pred(0).cfiOffset       := bpu.io.pred.cfiOffset
  ifetch.io.pred(0).cfiType         := bpu.io.pred.cfiType
  ifetch.io.pred(1).valid           := bpu.io.predSecondary.valid
  ifetch.io.pred(1).taken           := bpu.io.predSecondary.taken
  ifetch.io.pred(1).target          := bpu.io.predSecondary.target
  ifetch.io.pred(1).cfiOffset       := bpu.io.predSecondary.cfiOffset
  ifetch.io.pred(1).cfiType         := bpu.io.predSecondary.cfiType
  ifetch.io.rasTop                  := bpu.io.rasTop
  ifetch.io.rasValid                := bpu.io.rasValid
  ifetch.io.rasCheckpoint           := bpu.io.rasCheckpoint
  ifetch.io.latePrediction          := bpu.io.latePrediction
  ifetch.io.lateOverrideEnable      := cfg.bpu.enableLateOverride.B
  ifetch.io.predictorRecovery.valid := io.predictorRecovery.valid
  ifetch.io.predictorRecovery.bits  := io.predictorRecovery.bits.prediction

  val firstBlockAddr = Cat(
    pcGen.io.pc(cfg.addrWidth - 1, cfg.icache.offsetBits),
    0.U(cfg.icache.offsetBits.W)
  )
  bpu.io.lookup.valid            := true.B
  bpu.io.lookup.bits.pc          := pcGen.io.pc
  bpu.io.lookupSecondary.valid   := true.B
  bpu.io.lookupSecondary.bits.pc := firstBlockAddr + cfg.fetchBytes.U
  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    bpu.io.update(lane) := io.bpuUpdates(lane)
  }
  bpu.io.lateQuery := ifetch.io.lateQuery
  bpu.io.lateSpecUpdate := ifetch.io.lateSpecUpdate
  bpu.io.rasSpecUpdate  := ifetch.io.rasSpecUpdate
  
  val localPredictorRecovery = Wire(Valid(new PredictorRecovery(cfg.addrWidth)))
  localPredictorRecovery                   := 0.U.asTypeOf(Valid(new PredictorRecovery(cfg.addrWidth)))
  localPredictorRecovery.valid             := ifetch.io.lateRecovery.valid
  localPredictorRecovery.bits.prediction   := ifetch.io.lateRecovery.bits
  localPredictorRecovery.bits.cfiType      := ifetch.io.lateRecovery.bits.cfiType
  localPredictorRecovery.bits.actualTaken  := ifetch.io.lateRecovery.bits.specTaken
  localPredictorRecovery.bits.actualTarget := ifetch.io.lateRecovery.bits.predictedTarget

  val bpuRecovery = Wire(Valid(new PredictorRecovery(cfg.addrWidth)))
  bpuRecovery        := localPredictorRecovery
  when(io.predictorRecovery.valid) {
    bpuRecovery                 := io.predictorRecovery
    bpuRecovery.bits.prediction := ifetch.io.recoveryPrediction
  }
  bpu.io.rasRecovery := bpuRecovery
  bpu.io.rasFlush    := io.icacheInvalidate || io.trapRedirect.valid || io.predRedirect.valid ||
    (io.branchRedirect.valid && !io.predictorRecovery.valid)

  ifetch.io.icacheReq <> iCache.io.req
  ifetch.io.icacheResp <> iCache.io.resp
  ifetch.io.icacheAcceptedBlocks := iCache.io.acceptedBlocks
  iCache.io.invalidate           := io.icacheInvalidate
  iCache.io.redirect             := ifetch.io.frontendRedirect

  private val redirectDuringMshr          = redirect.valid && iCache.io.perf.mshrActive && !io.icacheInvalidate
  private val redirectMshrPending         = RegInit(false.B)
  private val redirectMshrTarget          = Reg(UInt(cfg.addrWidth.W))
  private val redirectTargetRequest       = iCache.io.req.fire &&
    iCache.io.req.bits.blocks(0).bits.meta.control.pc === redirectMshrTarget
  private val redirectDuringMshrTargetHit = redirectMshrPending && redirectTargetRequest &&
    iCache.io.perf.hitUnderMiss

  when(io.icacheInvalidate) {
    redirectMshrPending := false.B
  }.elsewhen(redirect.valid) {
    redirectMshrPending := redirectDuringMshr
    redirectMshrTarget  := redirect.value
  }.elsewhen(redirectMshrPending && iCache.io.req.fire) {
    redirectMshrPending := false.B
  }

  when(redirectMshrPending && iCache.io.req.fire) {
    assert(redirectTargetRequest)
  }

  refillMmu.io.csrStatus     := io.csrStatus
  iCache.io.refillReq <> refillMmu.io.refillReq
  iCache.io.refillResp <> refillMmu.io.refillResp
  io.cacheRefillReq <> refillMmu.io.physReq
  refillMmu.io.physResp <> io.cacheRefillResp
  io.ptwReq.valid            := refillMmu.io.ptwReq.valid
  io.ptwReq.bits             := refillMmu.io.ptwReq.bits
  refillMmu.io.ptwReq.ready  := io.ptwReq.ready
  refillMmu.io.ptwResp.valid := io.ptwResp.valid
  refillMmu.io.ptwResp.bits  := io.ptwResp.bits
  io.ptwResp.ready           := refillMmu.io.ptwResp.ready

  io.pc := pcGen.io.pc
  io.fetch <> ifetch.io.fetch
  io.pipelineTrace := ifetch.io.pipelineTrace

  private val fetchQueueSupplyStarved =
    ifetch.io.fetchQueueEmpty && io.fetch.ready && !pcRedirect.valid && !io.icacheInvalidate

  private val perfEvents = Seq(
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheRequest, iCache.io.perf.request),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheHit, iCache.io.perf.hit),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMiss, iCache.io.perf.miss),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMissWaitCycle, iCache.io.perf.missWait),
    FrontendPerfEvent.bit(FrontendPerfEvent.backendRedirect, redirect.valid),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheInvalidate, io.icacheInvalidate),
    FrontendPerfEvent.bit(FrontendPerfEvent.frontendEmpty, io.fetch.ready && !io.fetch.valid),
    FrontendPerfEvent.bit(FrontendPerfEvent.axiRequestWait, refillMmu.io.physReq.valid && !io.cacheRefillReq.ready),
    FrontendPerfEvent.bit(
      FrontendPerfEvent.fetchQueueEmptyWithBackendReady,
      fetchQueueSupplyStarved
    ),
    FrontendPerfEvent.bit(FrontendPerfEvent.fetchQueueFull, ifetch.io.fetchQueueFull),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMshrActiveCycle, iCache.io.perf.mshrActive),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheHitUnderMiss, iCache.io.perf.hitUnderMiss),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheSameLineWaitCycle, iCache.io.perf.sameLineWait),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheQueuedMiss, iCache.io.perf.queuedMiss),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshr, redirectDuringMshr),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshrTargetHit, redirectDuringMshrTargetHit),
    FrontendPerfEvent.bit(
      FrontendPerfEvent.staleResponseDrop,
      ifetch.io.staleResponseDrop || iCache.io.perf.staleResponseDrop
    ),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasPush, bpu.io.perf.push),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasPop, bpu.io.perf.pop),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasPopThenPush, bpu.io.perf.popThenPush),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasUse, bpu.io.perf.use),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasHit, bpu.io.perf.hit),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasMiss, bpu.io.perf.miss),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasUnderflow, bpu.io.perf.underflow),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasOverflow, bpu.io.perf.overflow),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasCheckpointRestore, bpu.io.perf.checkpointRestore),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasRecoveryDiscard, bpu.io.perf.recoveryDiscard),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageTaggedProvider, bpu.io.perf.taggedProvider),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageAlternateDisagree, bpu.io.perf.alternateDisagree),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageAllocation, bpu.io.perf.allocation),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageUsefulnessAging, bpu.io.perf.usefulnessAging),
    FrontendPerfEvent.bit(FrontendPerfEvent.lateOverride, bpu.io.perf.lateOverride)
  ).reduce(_ | _)

  perf.io.events                 := perfEvents
  perf.io.fetchQueueOccupancy    := ifetch.io.fetchQueueOccupancy.pad(32)
  perf.io.fetchQueueEnqueueWidth := ifetch.io.fetchQueueEnqueueWidth.pad(32)
  perf.io.fetchQueueDequeueWidth := ifetch.io.fetchQueueDequeueWidth.pad(32)
}
