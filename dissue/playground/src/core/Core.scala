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
import top.trace.{BackendPipelineTrace, FrontendTrace, IfuTrace}
import top.sim.{
  BackendPerfBridge,
  BpuPerfBridge,
  DifftestMonitor,
  FrontendPerfBridge,
  MemPerfBridge,
  PipelineTraceBridge
}

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
  val mem      = Module(new Mem(memCfg, backendCfg.robEntries, enableTrace))

  private val frontendTrace = Option.when(enableTrace)(Module(new FrontendTrace(frontendCfg)))
  private val ifuTrace      = Option.when(enableTrace)(Module(new IfuTrace(frontendCfg, FetchWidth.frontend)))
  private val backendTrace  = Option.when(enableTrace)(Module(new BackendPipelineTrace(backendCfg)))

  frontendTrace.foreach(_.io.monitor := frontend.io.monitor)
  ifuTrace.foreach(_.io.monitor := frontend.io.monitor)

  backendTrace.foreach { trace =>
    trace.io.frontendFire        := backend.io.monitor.frontendFire
    trace.io.frontend            := backend.io.monitor.frontend
    trace.io.dispatchFire        := backend.io.monitor.dispatchFire
    trace.io.dispatchDecode      := backend.io.monitor.dispatchDecode
    trace.io.dispatchIssue       := backend.io.monitor.dispatchIssue
    trace.io.intIssueFire        := backend.io.monitor.intIssueFire
    trace.io.intIssue            := backend.io.monitor.intIssue
    trace.io.memIssueFire        := backend.io.monitor.memIssueFire
    trace.io.memIssue            := backend.io.monitor.memIssue
    trace.io.writeback           := backend.io.monitor.writeback
    trace.io.retire              := backend.io.monitor.retire
    trace.io.storeReady          := backend.io.monitor.storeReady
    trace.io.storeCommit         := backend.io.monitor.storeCommit
    trace.io.storeRequest        := backend.io.monitor.storeRequest
    trace.io.storeResponse       := backend.io.monitor.storeResponse
    trace.io.memoryRequestFire   := backend.io.monitor.memoryRequestFire
    trace.io.memoryRequestRobIdx := backend.io.monitor.memoryRequestRobIdx
    trace.io.memoryRequestKind   := backend.io.monitor.memoryRequestKind
    trace.io.memoryRequestWrite  := backend.io.monitor.memoryRequestWrite
    trace.io.memoryRequestTxnId  := backend.io.monitor.memoryRequestTxnId
    trace.io.robHead             := backend.io.monitor.robHead
    trace.io.recover             := backend.io.monitor.recover
    trace.io.globalFlush         := backend.io.monitor.globalFlush
  }

  private val pipelineTrace = Option.when(enableTrace) {
    val eventCount = FetchWidth.frontend + BackendPipelineTrace.eventCount(backendCfg)
    val bridge     = Module(new PipelineTraceBridge(eventCount))
    for (lane  <- 0 until FetchWidth.frontend) {
      bridge.io.events(lane) := ifuTrace.get.io.events(lane)
    }
    for (event <- 0 until BackendPipelineTrace.eventCount(backendCfg)) {
      bridge.io.events(FetchWidth.frontend + event) := backendTrace.get.io.events(event)
    }
    bridge
  }

  private val frontendPerf = Option.when(enableTrace)(Module(new FrontendPerfBridge(frontendCfg)))
  frontendPerf.foreach(_.io.trace := frontendTrace.get.io.sample)

  private val bpuPerf = Option.when(enableTrace) {
    Seq.tabulate(backendCfg.commitWidth) { lane =>
      val bridge = Module(new BpuPerfBridge)
      bridge.io.sample := backend.io.monitor.bpuPerf(lane)
      bridge
    }
  }

  private val backendPerf = Option.when(enableTrace)(Module(new BackendPerfBridge))
  backendPerf.foreach { bridge =>
    bridge.io.issueQueue := backend.io.perf.issueQueue
    bridge.io.div        := backend.io.perf.div
  }

  private val memPerf = Option.when(enableTrace)(Module(new MemPerfBridge(memCfg.dcache, backendCfg)))
  memPerf.foreach { bridge =>
    bridge.io.memTrace     := mem.io.monitor
    bridge.io.backendTrace := backend.io.memPerf
  }

  private val difftest = Option.when(enableSimulation)(Module(new DifftestMonitor(resetVector, backendCfg)))
  difftest.foreach { monitor =>
    monitor.io.retire    := backend.io.retire
    monitor.io.regWrite  := backend.io.difftest.regWrite
    monitor.io.csrCommit := backend.io.difftest.csrCommit
    monitor.io.csrTrap   := backend.io.difftest.csrTrap
    monitor.io.csrMret   := backend.io.difftest.csrMret
    monitor.io.csrSret   := backend.io.difftest.csrSret
    monitor.io.context   := backend.io.difftest.context
    monitor.io.interrupt := io.interrupt
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

  mem.io.flush   := backend.io.globalFlush
  mem.io.recover := backend.io.recover
  mem.io.robHead := backend.io.robHead

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
