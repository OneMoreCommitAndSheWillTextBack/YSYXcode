package top.core.frontend

import chisel3._
import chisel3.util.{Decoupled, MuxCase, Valid}
import top.config.{BackendConfig, FrontendConfig}
import top.core.backend.csr.CsrStatus
import top.core.bundle.{CfiRecoveryPayload, CfiType, DataMemReq, DataMemResp}
import top.core.frontend.Bpu.Bpu
import top.core.frontend.bundle._
import top.core.frontend.icache._
import top.core.frontend.ifetch.{FetchPacket, FetchQueue, FetchTargetQueue, FetchWidth, IFetch}
import top.core.frontend.pcgen.FetchAddressGenerator
import top.core.trace.{FrontendTrace, FrontendTraceSample, IfuTrace, PipelineTraceEvent, TraceTap}

class Frontend(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         FrontendConfig = FrontendConfig(),
  backendCfg:  BackendConfig = BackendConfig(),
  enableTrace: Boolean = true)
    extends Module {
  require(backendCfg.addrWidth == cfg.addrWidth, "frontend and backend address widths must match")
  require(backendCfg.frontendPayload == cfg.payload, "frontend and backend payload widths must match")
  require(cfg.backendWidth == backendCfg.issueWidth, "frontend backendWidth must match backend issue width")
  require(cfg.frontendWidth == FetchWidth.frontend, "frontendWidth must match the implemented enqueue width")
  require(
    backendCfg.commitWidth == PredictorConstants.commitUpdateWidth,
    "BPU update width must match backend commit width"
  )

  val io = IO(new Bundle {
    val trapRedirect   = Input(new PcRedirect)
    val branchRedirect = Input(new PcRedirect)
    val predRedirect   = Input(new PcRedirect)
    val cfiRecovery    = Input(Valid(new CfiRecoveryPayload(cfg.payload)))
    val ftqRetire      = Input(Vec(cfg.backendWidth, Valid(new FtqRetire(cfg))))

    val pc    = Output(UInt(cfg.addrWidth.W))
    val fetch = Decoupled(new FetchPacket(cfg.payload))

    val cacheRefillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
    val cacheRefillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.icacheLineBytes)))

    val ptwReq           = Decoupled(new DataMemReq(backendCfg.addrWidth, backendCfg.dataWidth))
    val ptwResp          = Flipped(Decoupled(new DataMemResp(backendCfg.dataWidth)))
    val csrStatus        = Input(new CsrStatus(backendCfg))
    val icacheInvalidate = Input(Bool())
    val pipelineTrace    = Output(Vec(FetchWidth.frontend, Valid(new PipelineTraceEvent)))
    val perfTrace        = Output(new FrontendTraceSample(cfg))
  })

  val addressGen = Module(new FetchAddressGenerator(resetVector, cfg))
  val bpu        = Module(new Bpu(cfg, backendCfg.commitWidth))
  val ftq        = Module(new FetchTargetQueue(cfg))
  val iCache     = Module(new ICache(cfg))
  val ifetch     = Module(new IFetch(cfg))
  val fetchQueue = Module(new FetchQueue(cfg, cfg.ifetch.fetchQueueEntries, FetchWidth.frontend))
  val refillMmu  = Module(new ICacheRefillMmu(cfg.icache, backendCfg))

  val redirect = Wire(new PcRedirect)
  redirect.valid := io.trapRedirect.valid || io.branchRedirect.valid || io.predRedirect.valid
  redirect.value := MuxCase(
    addressGen.io.currentPc,
    Seq(
      io.trapRedirect.valid   -> io.trapRedirect.value,
      io.branchRedirect.valid -> io.branchRedirect.value,
      io.predRedirect.valid   -> io.predRedirect.value
    )
  )

  val backendRecovery = Wire(Valid(new FrontendRecovery(cfg)))
  backendRecovery               := 0.U.asTypeOf(backendRecovery)
  backendRecovery.valid         := redirect.valid || io.icacheInvalidate
  backendRecovery.bits.kind     := Mux(io.trapRedirect.valid, FrontendRecoveryKind.trap, FrontendRecoveryKind.backend)
  backendRecovery.bits.targetPc := redirect.value
  ftq.io.backendLookupTag       := io.cfiRecovery.bits.ftqTag
  when(io.cfiRecovery.valid) {
    backendRecovery.bits.kind                  := FrontendRecoveryKind.backend
    backendRecovery.bits.tokenValid            := ftq.io.backendLookup.valid
    backendRecovery.bits.token                 := ftq.io.backendLookup.bits
    backendRecovery.bits.targetPc              := io.cfiRecovery.bits.actualNpc
    backendRecovery.bits.cfiOrdinal            := io.cfiRecovery.bits.ftqInstOrdinal
    backendRecovery.bits.survivingInsts        := io.cfiRecovery.bits.ftqInstOrdinal + 1.U
    backendRecovery.bits.actualCfiValid        := io.cfiRecovery.bits.cfiType =/= CfiType.none
    backendRecovery.bits.actualCfiType         := io.cfiRecovery.bits.cfiType
    backendRecovery.bits.actualCfiPc           := io.cfiRecovery.bits.pc
    backendRecovery.bits.actualInstLen         := io.cfiRecovery.bits.instLen
    backendRecovery.bits.actualRasAction       := io.cfiRecovery.bits.rasAction
    backendRecovery.bits.actualCanonicalReturn := io.cfiRecovery.bits.canonicalReturn
    backendRecovery.bits.actualTaken           := io.cfiRecovery.bits.actualTaken
    backendRecovery.bits.actualTarget          := io.cfiRecovery.bits.actualTarget
  }

  val ifuRecovery = Wire(Valid(new FrontendRecovery(cfg)))
  ifuRecovery                            := 0.U.asTypeOf(ifuRecovery)
  ifuRecovery.valid                      := ifetch.io.correction.valid && fetchQueue.io.empty
  ifuRecovery.bits.kind                  := FrontendRecoveryKind.ifuCorrection
  ifuRecovery.bits.tokenValid            := true.B
  ifuRecovery.bits.token                 := ifetch.io.correction.bits.token
  ifuRecovery.bits.targetPc              := ifetch.io.correction.bits.redirectTarget
  ifuRecovery.bits.cfiOrdinal            := ifetch.io.correction.bits.cfiOrdinal
  ifuRecovery.bits.survivingInsts        := ifetch.io.correction.bits.emittedInsts
  ifuRecovery.bits.actualCfiValid        := ifetch.io.correction.bits.cfi.valid &&
    ifetch.io.correction.bits.cfi.cfiType === CfiType.jal
  ifuRecovery.bits.actualCfiType         := ifetch.io.correction.bits.cfi.cfiType
  ifuRecovery.bits.actualCfiPc           := ifetch.io.correction.bits.cfiPc
  ifuRecovery.bits.actualInstLen         := ifetch.io.correction.bits.cfiInstLen
  ifuRecovery.bits.actualRasAction       := ifetch.io.correction.bits.cfi.rasAction
  ifuRecovery.bits.actualCanonicalReturn := ifetch.io.correction.bits.cfi.canonicalReturn
  ifuRecovery.bits.actualTaken           := ifuRecovery.bits.actualCfiValid
  ifuRecovery.bits.actualTarget          := ifetch.io.correction.bits.cfi.directTarget
  ifuRecovery.bits.dropTargetEntry       := false.B

  val bpuRecovery = Wire(Valid(new FrontendRecovery(cfg)))
  bpuRecovery                 := 0.U.asTypeOf(bpuRecovery)
  bpuRecovery.valid           := bpu.io.finalResult.valid && bpu.io.finalResult.bits.overrideFastPath
  bpuRecovery.bits.kind       := FrontendRecoveryKind.bpuOverride
  bpuRecovery.bits.tokenValid := true.B
  bpuRecovery.bits.token      := bpu.io.finalResult.bits.token
  bpuRecovery.bits.targetPc   := bpu.io.finalResult.bits.finalNextPc

  val selectedRecovery = FrontendRecoveryArbiter.select(backendRecovery, ifuRecovery, bpuRecovery, cfg)
  val dataRecovery     = Wire(Valid(new FrontendRecovery(cfg)))
  dataRecovery       := selectedRecovery
  dataRecovery.valid := selectedRecovery.valid && selectedRecovery.bits.kind =/= FrontendRecoveryKind.bpuOverride
  val dataFlush = dataRecovery.valid || io.icacheInvalidate

  addressGen.io.fastResult := bpu.io.fastResult
  addressGen.io.recovery   := selectedRecovery
  ftq.io.recovery          := selectedRecovery
  bpu.io.recover           := ftq.io.bpuRecover
  iCache.io.recovery       := dataRecovery
  iCache.io.invalidate     := io.icacheInvalidate

  val s0JoinReady = ftq.io.reserve.ready && bpu.io.req.ready && !selectedRecovery.valid
  addressGen.io.addressReq.ready := s0JoinReady
  ftq.io.reserve.valid           := addressGen.io.addressReq.valid && bpu.io.req.ready && !selectedRecovery.valid
  ftq.io.reserve.bits.startPc    := addressGen.io.addressReq.bits.startPc
  bpu.io.req.valid               := addressGen.io.addressReq.valid && ftq.io.reserve.ready && !selectedRecovery.valid
  bpu.io.req.bits.token          := ftq.io.reserveToken
  bpu.io.req.bits.startPc        := addressGen.io.addressReq.bits.startPc

  ftq.io.writeFast  := bpu.io.fastResult
  ftq.io.writeFinal := bpu.io.finalResult
  bpu.io.train      := ftq.io.train

  iCache.io.req.valid      := ftq.io.fetchTarget.valid
  iCache.io.req.bits       := ICacheFetchReq.fromFtqTarget(ftq.io.fetchTarget.bits, cfg)
  ftq.io.fetchTarget.ready := iCache.io.req.ready

  ifetch.io.flush                 := dataFlush
  ifetch.io.acceptCorrection      := selectedRecovery.valid &&
    selectedRecovery.bits.kind === FrontendRecoveryKind.ifuCorrection
  ifetch.io.icacheResp <> iCache.io.resp
  ftq.io.fetchComplete.valid      := iCache.io.resp.fire
  ftq.io.fetchComplete.bits.token := iCache.io.resp.bits.token

  ftq.io.blockLookupToken   := ifetch.io.blockLookupToken
  ifetch.io.blockLookup     := ftq.io.blockLookup
  ftq.io.alignLookupToken   := ifetch.io.alignLookupToken
  ifetch.io.alignLookup     := ftq.io.alignLookup
  ftq.io.checkerLookupToken := ifetch.io.checkerLookupToken
  ifetch.io.checkerLookup   := ftq.io.checkerLookup

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

  val fetchQueueEpoch = RegInit(0.U(cfg.fetchEpochBits.W))
  when(dataFlush) {
    fetchQueueEpoch := fetchQueueEpoch +% 1.U
  }
  fetchQueue.io.flush := dataFlush
  fetchQueue.io.pruneFrom.valid := selectedRecovery.valid &&
    selectedRecovery.bits.kind === FrontendRecoveryKind.bpuOverride && ftq.io.recoverySequence.valid
  fetchQueue.io.pruneFrom.bits := ftq.io.recoverySequence.bits
  fetchQueue.io.currentEpoch := fetchQueueEpoch
  // Recovery owns the FTQ state transition for this cycle. Hold a completed IFU packet until the following cycle so
  // its emission accounting cannot be lost behind that transition; BPU overrides still retain all buffered data.
  val allowIfuEnqueue = !selectedRecovery.valid
  fetchQueue.io.enq.valid := ifetch.io.fetchEnqueue.valid && allowIfuEnqueue
  fetchQueue.io.enq.bits  := ifetch.io.fetchEnqueue.bits
  for (lane <- 0 until FetchWidth.frontend) {
    fetchQueue.io.enq.bits.insts(lane).bits.epoch := fetchQueueEpoch
  }
  ifetch.io.fetchEnqueue.ready := fetchQueue.io.enq.ready && allowIfuEnqueue
  io.fetch <> fetchQueue.io.out

  ftq.io.ifuEmission := ifetch.io.emission
  ftq.io.retire      := io.ftqRetire

  io.pc := addressGen.io.currentPc

  when(addressGen.io.addressReq.fire || ftq.io.reserve.fire || bpu.io.req.fire) {
    assert(addressGen.io.addressReq.fire)
    assert(ftq.io.reserve.fire)
    assert(bpu.io.req.fire)
    assert(bpu.io.req.bits.token === ftq.io.reserveToken)
  }
  when(bpu.io.fastResult.valid && !selectedRecovery.valid) {
    assert(bpu.io.fastResult.bits.blockCount >= 1.U)
    assert(bpu.io.fastResult.bits.blockCount <= cfg.fetchGroupBlocks.U)
    when(bpu.io.fastResult.bits.blockTaken(1)) {
      assert(bpu.io.fastResult.bits.blockCount === cfg.fetchGroupBlocks.U)
    }
  }
  when(selectedRecovery.valid) {
    assert(!fetchQueue.io.enq.fire)
  }
  when(io.cfiRecovery.valid) {
    assert(ftq.io.backendLookup.valid)
  }

  io.pipelineTrace := 0.U.asTypeOf(io.pipelineTrace)
  io.perfTrace     := 0.U.asTypeOf(new FrontendTraceSample(cfg))
  if (enableTrace) {
    val ifuTrace           = Module(new IfuTrace(cfg, FetchWidth.frontend))
    val frontendTrace      = Module(new FrontendTrace(cfg))
    val selectedPcRedirect = Wire(new PcRedirect)
    selectedPcRedirect.valid := selectedRecovery.valid
    selectedPcRedirect.value := selectedRecovery.bits.targetPc

    ifuTrace.io.enqueue := TraceTap.observe(fetchQueue.io.enq)
    io.pipelineTrace    := ifuTrace.io.events

    frontendTrace.io.backendRedirect        := redirect
    frontendTrace.io.pcRedirect             := selectedPcRedirect
    frontendTrace.io.invalidate             := io.icacheInvalidate
    frontendTrace.io.recovery               := selectedRecovery
    frontendTrace.io.fetchValid             := io.fetch.valid
    frontendTrace.io.fetchReady             := io.fetch.ready
    frontendTrace.io.refillPhysicalReqValid := refillMmu.io.physReq.valid
    frontendTrace.io.refillPhysicalReqReady := io.cacheRefillReq.ready
    frontendTrace.io.icacheReq              := TraceTap.observe(iCache.io.req)
    frontendTrace.io.icacheResp             := TraceTap.observe(iCache.io.resp)
    frontendTrace.io.icacheRefillReq        := TraceTap.observe(iCache.io.refillReq)
    frontendTrace.io.icacheRefillResp       := TraceTap.observe(iCache.io.refillResp)
    frontendTrace.io.icacheLookup           := iCache.io.lookup
    frontendTrace.io.bpuMonitor             := bpu.io.perf
    frontendTrace.io.ifuStaleDrop           := ifetch.io.staleResponseDrop || ftq.io.staleIfuDrop ||
      ftq.io.staleFastDrop || ftq.io.staleFinalDrop || ftq.io.staleCompleteDrop || ftq.io.staleRetireDrop
    frontendTrace.io.fetchQueueEmpty        := fetchQueue.io.empty
    frontendTrace.io.fetchQueueFull         := fetchQueue.io.full
    frontendTrace.io.fetchQueueOccupancy    := fetchQueue.io.count.pad(32)
    frontendTrace.io.fetchQueueEnqueueWidth := fetchQueue.io.enqueueWidth.pad(32)
    frontendTrace.io.fetchQueueDequeueWidth := fetchQueue.io.dequeueWidth.pad(32)
    io.perfTrace                            := frontendTrace.io.sample
  }
}
