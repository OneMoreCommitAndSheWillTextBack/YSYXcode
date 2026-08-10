package top.core

import chisel3._
import chisel3.util.Valid
import top.core.backend.Backend
import top.core.backend.csr.CsrInterruptPending
import top.bus.axi.AxiPort
import top.core.bundle.{DataMemTxn, FrontendToBackend, MemPerfEvent}
import top.config.{BackendConfig, FrontendConfig, MemConfig}
import top.core.mem.Mem
import top.core.frontend.Frontend
import top.core.frontend.ifetch.FetchWidth
import top.core.frontend.bundle.RasAction
import top.core.trace.BackendPipelineTrace
import top.sim.{BpuPerfBridge, FrontendPerfBridge, MemPerfBridge, PipelineTraceBridge}

class Core(
  resetVector:      BigInt,
  enableTrace:      Boolean = true,
  frontendShape:    FrontendConfig = FrontendConfig(),
  enableSimulation: Boolean = true)
    extends Module {
  private val backendShape = BackendConfig()
  private val frontendCfg  = frontendShape.copy(backendWidth = backendShape.issueWidth)
  private val backendCfg   = backendShape.copy(frontendPayload = frontendCfg.payload)
  private val memCfg       = MemConfig(fetchBytes = frontendCfg.icacheLineBytes)

  require(backendCfg.addrWidth == frontendCfg.addrWidth, "frontend/backend addrWidth must match")
  require(backendCfg.addrWidth == memCfg.addrWidth, "backend/mem addrWidth must match")
  require(backendCfg.dataWidth == memCfg.axiDataWidth, "backend dataWidth must match memory data width")
  require(backendCfg.issueWidth == 2, "Core bridge currently assumes the frontend produces two slots")
  require(
    Mem.cancelPorts(memCfg.dcache) <= backendCfg.recoveryCancelPorts,
    "BackendConfig.recoveryCancelPorts must cover lower-memory cancellation sources"
  )

  val io = IO(new Bundle {
    val interrupt = Input(new CsrInterruptPending)
    val mtime     = Input(UInt(64.W))
    val axi       = new AxiPort
  })

  val frontend = Module(new Frontend(resetVector, frontendCfg, backendCfg, enableTrace))
  val backend  = Module(new Backend(resetVector, backendCfg, enableTrace, enableSimulation))
  val mem      = Module(new Mem(memCfg, backendCfg.robEntries))

  if (enableTrace) {
    val backendTrace = Module(new BackendPipelineTrace(backendCfg))
    val monitor      = backend.io.monitor

    backendTrace.io.frontendFire        := monitor.frontendFire
    backendTrace.io.frontend            := monitor.frontend
    backendTrace.io.dispatchFire        := monitor.dispatchFire
    backendTrace.io.dispatchDecode      := monitor.dispatchDecode
    backendTrace.io.dispatchIssue       := monitor.dispatchIssue
    backendTrace.io.intIssueFire        := monitor.intIssueFire
    backendTrace.io.intIssue            := monitor.intIssue
    backendTrace.io.memIssueFire        := monitor.memIssueFire
    backendTrace.io.memIssue            := monitor.memIssue
    backendTrace.io.writeback           := monitor.writeback
    backendTrace.io.retire              := monitor.retire
    backendTrace.io.storeReady          := monitor.storeReady
    backendTrace.io.storeCommit         := monitor.storeCommit
    backendTrace.io.storeRequest        := monitor.storeRequest
    backendTrace.io.storeResponse       := monitor.storeResponse
    backendTrace.io.memoryRequestFire   := monitor.memoryRequestFire
    backendTrace.io.memoryRequestRobIdx := monitor.memoryRequestRobIdx
    backendTrace.io.memoryRequestKind   := monitor.memoryRequestKind
    backendTrace.io.memoryRequestWrite  := monitor.memoryRequestWrite
    backendTrace.io.memoryRequestTxnId  := monitor.memoryRequestTxnId
    backendTrace.io.robHead             := monitor.robHead
    backendTrace.io.recover             := monitor.recover
    backendTrace.io.globalFlush         := monitor.globalFlush

    val pipelineTraceEventCount = FetchWidth.frontend + BackendPipelineTrace.eventCount(backendCfg)
    val pipelineTrace           = Module(new PipelineTraceBridge(pipelineTraceEventCount))
    for (lane  <- 0 until FetchWidth.frontend) {
      pipelineTrace.io.events(lane) := frontend.io.pipelineTrace(lane)
    }
    for (event <- 0 until BackendPipelineTrace.eventCount(backendCfg)) {
      pipelineTrace.io.events(FetchWidth.frontend + event) := backendTrace.io.events(event)
    }

    val frontendPerf = Module(new FrontendPerfBridge)
    frontendPerf.io.events                 := frontend.io.perfTrace.events
    frontendPerf.io.fetchQueueOccupancy    := frontend.io.perfTrace.fetchQueueOccupancy
    frontendPerf.io.fetchQueueEnqueueWidth := frontend.io.perfTrace.fetchQueueEnqueueWidth
    frontendPerf.io.fetchQueueDequeueWidth := frontend.io.perfTrace.fetchQueueDequeueWidth
    frontendPerf.io.ifuCorrection          := frontend.io.perfTrace.ifuCorrection
    frontendPerf.io.icacheLookupValid      := frontend.io.perfTrace.icacheLookupValid
    frontendPerf.io.icacheBlockValidMask   := frontend.io.perfTrace.icacheBlockValidMask
    frontendPerf.io.icacheMissMask         := frontend.io.perfTrace.icacheMissMask
    frontendPerf.io.icacheBlockAddr        := frontend.io.perfTrace.icacheBlockAddr

    for (lane <- 0 until backendCfg.commitWidth) {
      val bpuPerf = Module(new BpuPerfBridge)
      bpuPerf.io.valid       := monitor.bpuPerf(lane).valid
      bpuPerf.io.cfiClass    := monitor.bpuPerf(lane).cfiClass
      bpuPerf.io.predHit     := monitor.bpuPerf(lane).predHit
      bpuPerf.io.predTaken   := monitor.bpuPerf(lane).predTaken
      bpuPerf.io.actualTaken := monitor.bpuPerf(lane).actualTaken
      bpuPerf.io.correct     := monitor.bpuPerf(lane).correct
    }
  }

  frontend.io.csrStatus := backend.io.csrStatus
  backend.io.interrupt  := io.interrupt
  backend.io.mtime      := io.mtime

  frontend.io.trapRedirect.valid := backend.io.redirect.trapRedirect.valid
  frontend.io.trapRedirect.value := backend.io.redirect.trapRedirect.target

  frontend.io.branchRedirect.valid := backend.io.redirect.branchRedirect.valid
  frontend.io.branchRedirect.value := backend.io.redirect.branchRedirect.target

  frontend.io.predRedirect.valid := backend.io.redirect.predRedirect.valid
  frontend.io.predRedirect.value := backend.io.redirect.predRedirect.target
  frontend.io.icacheInvalidate   := backend.io.redirect.icacheInvalidate

  frontend.io.cfiRecovery := backend.io.redirect.cfiRecovery
  for (lane <- 0 until backendCfg.commitWidth) {
    val retired = backend.io.retire.lanes(lane)
    val cfiType = RasAction.cfiType(retired.fetch.inst)
    frontend.io.ftqRetire(lane)                      := 0.U.asTypeOf(frontend.io.ftqRetire(lane))
    frontend.io.ftqRetire(lane).valid                := retired.valid
    frontend.io.ftqRetire(lane).bits.tag             := retired.fetch.ftqTag
    frontend.io.ftqRetire(lane).bits.instOrdinal     := retired.fetch.ftqInstOrdinal
    frontend.io.ftqRetire(lane).bits.retired         := !retired.exception.valid
    frontend.io.ftqRetire(lane).bits.trap            := retired.exception.valid
    frontend.io.ftqRetire(lane).bits.cfiValid        := !retired.exception.valid && cfiType =/= top.core.bundle.CfiType.none
    frontend.io.ftqRetire(lane).bits.pc              := retired.fetch.pc
    frontend.io.ftqRetire(lane).bits.cfiType         := cfiType
    frontend.io.ftqRetire(lane).bits.taken           := Mux(
      cfiType === top.core.bundle.CfiType.branch,
      retired.control.branchTaken,
      true.B
    )
    frontend.io.ftqRetire(lane).bits.target          := retired.control.branchTarget
    frontend.io.ftqRetire(lane).bits.instLen         := retired.fetch.instLen
    frontend.io.ftqRetire(lane).bits.rasAction       := RasAction.action(retired.fetch.inst)
    frontend.io.ftqRetire(lane).bits.canonicalReturn := RasAction.isCanonicalReturn(retired.fetch.inst)
  }

  backend.io.frontend.valid := frontend.io.fetch.valid
  backend.io.frontend.bits  := 0.U.asTypeOf(new FrontendToBackend(backendCfg.issueWidth, backendCfg.frontendPayload))
  frontend.io.fetch.ready   := backend.io.frontend.ready

  for (i <- 0 until backendCfg.issueWidth) {
    backend.io.frontend.bits.insts(i) := frontend.io.fetch.bits.insts(i)
  }

  mem.io.imemReq.valid             := frontend.io.cacheRefillReq.valid
  mem.io.imemReq.bits.addr         := frontend.io.cacheRefillReq.bits.addr
  frontend.io.cacheRefillReq.ready := mem.io.imemReq.ready

  frontend.io.cacheRefillResp.valid          := mem.io.imemResp.valid
  frontend.io.cacheRefillResp.bits.data      := mem.io.imemResp.bits.data
  frontend.io.cacheRefillResp.bits.exception := 0.U.asTypeOf(frontend.io.cacheRefillResp.bits.exception)
  mem.io.imemResp.ready                      := frontend.io.cacheRefillResp.ready

  mem.io.fenceIReq.valid     := backend.io.fenceIReq.valid
  mem.io.fenceIReq.bits      := backend.io.fenceIReq.bits
  backend.io.fenceIReq.ready := mem.io.fenceIReq.ready
  backend.io.fenceIDone      := mem.io.fenceIDone

  mem.io.dmemReq.valid     := backend.io.dmemReq.valid
  mem.io.dmemReq.bits      := backend.io.dmemReq.bits
  backend.io.dmemReq.ready := mem.io.dmemReq.ready

  mem.io.flush         := backend.io.globalFlush
  mem.io.recover       := backend.io.recover
  mem.io.robHead       := backend.io.robHead
  mem.io.unresolvedCfi := backend.io.unresolvedCfi

  private val dmemCancel = Wire(Vec(backendCfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))
  for (port <- 0 until backendCfg.recoveryCancelPorts) {
    dmemCancel(port) := 0.U.asTypeOf(Valid(UInt(DataMemTxn.width.W)))
  }
  for (port <- 0 until Mem.cancelPorts(memCfg.dcache)) {
    dmemCancel(port) := mem.io.dmemCancel(port)
  }
  backend.io.dmemCancel := dmemCancel

  backend.io.dmemResp.valid := mem.io.dmemResp.valid
  backend.io.dmemResp.bits  := mem.io.dmemResp.bits
  mem.io.dmemResp.ready     := backend.io.dmemResp.ready

  mem.io.ptwReq.valid      := frontend.io.ptwReq.valid
  mem.io.ptwReq.bits       := frontend.io.ptwReq.bits
  frontend.io.ptwReq.ready := mem.io.ptwReq.ready

  frontend.io.ptwResp.valid := mem.io.ptwResp.valid
  frontend.io.ptwResp.bits  := mem.io.ptwResp.bits
  mem.io.ptwResp.ready      := frontend.io.ptwResp.ready

  if (enableSimulation) {
    val memPerf       = Module(new MemPerfBridge)
    val memPerfEvents = Seq(
      MemPerfEvent.bit(MemPerfEvent.dcacheAccess, mem.io.perf.access),
      MemPerfEvent.bit(MemPerfEvent.dcacheHit, mem.io.perf.hit),
      MemPerfEvent.bit(MemPerfEvent.dcacheMiss, mem.io.perf.miss),
      MemPerfEvent.bit(MemPerfEvent.dcacheBypass, mem.io.perf.bypass),
      MemPerfEvent.bit(MemPerfEvent.mshrAlloc, mem.io.perf.mshrAlloc),
      MemPerfEvent.bit(MemPerfEvent.mshrMerge, mem.io.perf.mshrMerge),
      MemPerfEvent.bit(MemPerfEvent.mshrFullStallCycle, mem.io.perf.mshrFullStall),
      MemPerfEvent.bit(MemPerfEvent.hitUnderMiss, mem.io.perf.hitUnderMiss),
      MemPerfEvent.bit(MemPerfEvent.queuedMiss, mem.io.perf.queuedMiss),
      MemPerfEvent.bit(MemPerfEvent.refillStart, mem.io.perf.refillStart),
      MemPerfEvent.bit(MemPerfEvent.refillComplete, mem.io.perf.refillComplete),
      MemPerfEvent.bit(MemPerfEvent.refillFault, mem.io.perf.refillFault),
      MemPerfEvent.bit(MemPerfEvent.loadTxnFullStallCycle, backend.io.memPerf.loadTxnFullStall),
      MemPerfEvent.bit(MemPerfEvent.sqAlloc, backend.io.memPerf.sqAlloc),
      MemPerfEvent.bit(MemPerfEvent.sqFullStallCycle, backend.io.memPerf.sqFullStall),
      MemPerfEvent.bit(MemPerfEvent.forwardFull, backend.io.memPerf.forwardFull),
      MemPerfEvent.bit(MemPerfEvent.forwardPartial, backend.io.memPerf.forwardPartial),
      MemPerfEvent.bit(MemPerfEvent.forwardUnresolvedStallCycle, backend.io.memPerf.forwardUnresolvedStoreStall),
      MemPerfEvent.bit(MemPerfEvent.storeDrain, backend.io.memPerf.storeDrain),
      MemPerfEvent.bit(MemPerfEvent.storeCommit, backend.io.memPerf.storeCommit),
      MemPerfEvent.bit(MemPerfEvent.storeResponse, backend.io.memPerf.storeResponse)
    ).reduce(_ | _)

    memPerf.io.events              := memPerfEvents
    memPerf.io.mshrOccupancy       := mem.io.perf.mshrOccupancy.pad(32)
    memPerf.io.storeQueueOccupancy := backend.io.memPerf.sqOccupancy.pad(32)
    memPerf.io.loadTxnOccupancy    := backend.io.memPerf.loadTxnOccupancy.pad(32)
  }

  io.axi <> mem.io.axi
}
