package top.core

import chisel3._
import chisel3.util.Valid
import top.core.backend.Backend
import top.core.backend.csr.CsrInterruptPending
import top.bus.axi.AxiPort
import top.core.bundle.{DataMemTxn, FrontendToBackend}
import top.config.{BackendConfig, FrontendConfig, MemConfig}
import top.core.mem.Mem
import top.core.frontend.Frontend
import top.core.frontend.ifetch.FetchWidth
import top.core.frontend.bundle.RasAction
import top.core.trace.{BackendPipelineTrace, PipelineTraceEvent}
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
  val backend  = Module(new Backend(resetVector, backendCfg, enableTrace, enableSimulation, enableSimulation))
  val mem      = Module(new Mem(memCfg, backendCfg.robEntries))

  // Observation layer: producers export plain trace bundles, sim bridges own
  // every DPI call. All bridges are instantiated unconditionally; enableDpi =
  // false turns them into empty shells so both views share this exact wiring.
  private val monitor = backend.io.monitor

  private val backendTrace = Option.when(enableTrace)(Module(new BackendPipelineTrace(backendCfg)))
  backendTrace.foreach { trace =>
    trace.io.frontendFire        := monitor.frontendFire
    trace.io.frontend            := monitor.frontend
    trace.io.dispatchFire        := monitor.dispatchFire
    trace.io.dispatchDecode      := monitor.dispatchDecode
    trace.io.dispatchIssue       := monitor.dispatchIssue
    trace.io.intIssueFire        := monitor.intIssueFire
    trace.io.intIssue            := monitor.intIssue
    trace.io.memIssueFire        := monitor.memIssueFire
    trace.io.memIssue            := monitor.memIssue
    trace.io.writeback           := monitor.writeback
    trace.io.retire              := monitor.retire
    trace.io.storeReady          := monitor.storeReady
    trace.io.storeCommit         := monitor.storeCommit
    trace.io.storeRequest        := monitor.storeRequest
    trace.io.storeResponse       := monitor.storeResponse
    trace.io.memoryRequestFire   := monitor.memoryRequestFire
    trace.io.memoryRequestRobIdx := monitor.memoryRequestRobIdx
    trace.io.memoryRequestKind   := monitor.memoryRequestKind
    trace.io.memoryRequestWrite  := monitor.memoryRequestWrite
    trace.io.memoryRequestTxnId  := monitor.memoryRequestTxnId
    trace.io.robHead             := monitor.robHead
    trace.io.recover             := monitor.recover
    trace.io.globalFlush         := monitor.globalFlush
  }

  private val pipelineTraceEventCount = FetchWidth.frontend + BackendPipelineTrace.eventCount(backendCfg)
  private val pipelineTrace           = Module(new PipelineTraceBridge(pipelineTraceEventCount, enableDpi = enableTrace))
  for (lane <- 0 until FetchWidth.frontend) {
    pipelineTrace.io.events(lane) := frontend.io.pipelineTrace(lane)
  }
  backendTrace match {
    case Some(trace) =>
      for (event <- 0 until BackendPipelineTrace.eventCount(backendCfg)) {
        pipelineTrace.io.events(FetchWidth.frontend + event) := trace.io.events(event)
      }
    case None        =>
      for (event <- 0 until BackendPipelineTrace.eventCount(backendCfg)) {
        pipelineTrace.io.events(FetchWidth.frontend + event) := 0.U.asTypeOf(Valid(new PipelineTraceEvent))
      }
  }

  private val frontendPerf = Module(new FrontendPerfBridge(frontendCfg, enableDpi = enableTrace))
  frontendPerf.io.trace <> frontend.io.perfTrace

  for (lane <- 0 until backendCfg.commitWidth) {
    val bpuPerf = Module(new BpuPerfBridge(enableDpi = enableTrace))
    bpuPerf.io.sample <> monitor.bpuPerf(lane)
  }

  private val memPerf = Module(new MemPerfBridge(memCfg.dcache, backendCfg, enableDpi = enableSimulation))
  memPerf.io.memTrace <> mem.io.perf
  memPerf.io.backendTrace <> backend.io.memPerf

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

  io.axi <> mem.io.axi
}
