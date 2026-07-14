package top.core

import chisel3._
import chisel3.util.Valid
import top.core.backend.Backend
import top.core.backend.csr.CsrInterruptPending
import top.bus.axi.AxiPort
import top.core.bundle.{DataMemTxn, FrontendToBackend, MemPerfEvent}
import top.config.{BackendConfig, FrontendConfig, MemConfig}
import top.core.mem.{DCache, Mem, RecoverableDmemQueue}
import top.core.frontend.Frontend
import top.core.frontend.bundle.BpuUpdate
import top.sim.MemPerfBridge

class Core(resetVector: BigInt) extends Module {
  private val frontendCfg = FrontendConfig()
  private val backendCfg  = BackendConfig()
  private val memCfg      = MemConfig()
  private val dmemQueueDepth = 4

  require(backendCfg.addrWidth == frontendCfg.addrWidth, "frontend/backend addrWidth must match")
  require(backendCfg.addrWidth == memCfg.addrWidth, "backend/mem addrWidth must match")
  require(backendCfg.dataWidth == memCfg.axiDataWidth, "backend dataWidth must match memory data width")
  require(backendCfg.issueWidth == 2, "Core bridge currently assumes the frontend produces two slots")
  require(
    dmemQueueDepth + DCache.cancelPorts(memCfg.dcache) <= backendCfg.recoveryCancelPorts,
    "BackendConfig.recoveryCancelPorts must cover dmem queue and DCache cancellation sources"
  )

  val io = IO(new Bundle {
    val interrupt = Input(new CsrInterruptPending)
    val mtime     = Input(UInt(64.W))
    val axi       = new AxiPort
  })

  val frontend         = Module(new Frontend(resetVector, frontendCfg))
  val backend          = Module(new Backend(resetVector, backendCfg))
  val mem              = Module(new Mem(memCfg, backendCfg.robEntries))
  val dmemRequestQueue = Module(
    new RecoverableDmemQueue(
      addrWidth = memCfg.addrWidth,
      dataWidth = memCfg.axiDataWidth,
      robIdxWidth = backendCfg.robIdxWidth,
      robEntries = backendCfg.robEntries,
      depth = dmemQueueDepth
    )
  )
  val memPerf          = Module(new MemPerfBridge)

  frontend.io.csrStatus := backend.io.csrStatus
  backend.io.interrupt  := io.interrupt
  backend.io.mtime      := io.mtime

  frontend.io.trapRedirect.valid := backend.io.redirect.trapRedirect.valid
  frontend.io.trapRedirect.value := backend.io.redirect.trapRedirect.target

  frontend.io.branchRedirect.valid := backend.io.redirect.branchRedirect.valid
  frontend.io.branchRedirect.value := backend.io.redirect.branchRedirect.target

  frontend.io.predRedirect.valid := backend.io.redirect.predRedirect.valid
  frontend.io.predRedirect.value := backend.io.redirect.predRedirect.target

  frontend.io.bpuUpdate.valid        := backend.io.redirect.bpuUpdate.valid
  frontend.io.bpuUpdate.bits         := 0.U.asTypeOf(new BpuUpdate(frontendCfg.bpu))
  frontend.io.bpuUpdate.bits.pc      := backend.io.redirect.bpuUpdate.bits.pc
  frontend.io.bpuUpdate.bits.cfiType := backend.io.redirect.bpuUpdate.bits.cfiType
  frontend.io.bpuUpdate.bits.taken   := backend.io.redirect.bpuUpdate.bits.taken
  frontend.io.bpuUpdate.bits.target  := backend.io.redirect.bpuUpdate.bits.target
  frontend.io.bpuUpdate.bits.instLen := backend.io.redirect.bpuUpdate.bits.instLen

  backend.io.frontend.valid := frontend.io.fetch.valid
  backend.io.frontend.bits  := 0.U.asTypeOf(new FrontendToBackend(backendCfg.issueWidth, backendCfg.addrWidth))
  frontend.io.fetch.ready   := backend.io.frontend.ready

  for (i <- 0 until backendCfg.issueWidth) {
    backend.io.frontend.bits.insts(i).valid           := frontend.io.fetch.bits.insts(i).valid
    backend.io.frontend.bits.insts(i).bits.pc         := frontend.io.fetch.bits.insts(i).bits.pc
    backend.io.frontend.bits.insts(i).bits.inst       := frontend.io.fetch.bits.insts(i).bits.inst
    backend.io.frontend.bits.insts(i).bits.rawInst    := frontend.io.fetch.bits.insts(i).bits.rawInst
    backend.io.frontend.bits.insts(i).bits.isRVC      := frontend.io.fetch.bits.insts(i).bits.isRVC
    backend.io.frontend.bits.insts(i).bits.instLen    := frontend.io.fetch.bits.insts(i).bits.instLen
    backend.io.frontend.bits.insts(i).bits.predTaken  := frontend.io.fetch.bits.insts(i).bits.predTaken
    backend.io.frontend.bits.insts(i).bits.predNpc    := frontend.io.fetch.bits.insts(i).bits.predNpc
    backend.io.frontend.bits.insts(i).bits.predTarget := frontend.io.fetch.bits.insts(i).bits.predTarget
    backend.io.frontend.bits.insts(i).bits.exception  := frontend.io.fetch.bits.insts(i).bits.exception
  }

  mem.io.imemReq.valid             := frontend.io.cacheRefillReq.valid
  mem.io.imemReq.bits.addr         := frontend.io.cacheRefillReq.bits.addr
  frontend.io.cacheRefillReq.ready := mem.io.imemReq.ready

  frontend.io.cacheRefillResp.valid          := mem.io.imemResp.valid
  frontend.io.cacheRefillResp.bits.data      := mem.io.imemResp.bits.data
  frontend.io.cacheRefillResp.bits.exception := 0.U.asTypeOf(frontend.io.cacheRefillResp.bits.exception)
  mem.io.imemResp.ready                      := frontend.io.cacheRefillResp.ready

  dmemRequestQueue.io.enq.valid := backend.io.dmemReq.valid
  dmemRequestQueue.io.enq.bits  := backend.io.dmemReq.bits
  backend.io.dmemReq.ready      := dmemRequestQueue.io.enq.ready
  dmemRequestQueue.io.flush     := backend.io.globalFlush
  dmemRequestQueue.io.recover   := backend.io.recover
  dmemRequestQueue.io.robHead   := backend.io.robHead

  mem.io.dmemReq.valid          := dmemRequestQueue.io.deq.valid
  mem.io.dmemReq.bits           := dmemRequestQueue.io.deq.bits
  dmemRequestQueue.io.deq.ready := mem.io.dmemReq.ready
  mem.io.flush                   := backend.io.globalFlush
  mem.io.recover                 := backend.io.recover
  mem.io.robHead                 := backend.io.robHead

  private val dmemCancel = Wire(Vec(backendCfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))
  for (port <- 0 until backendCfg.recoveryCancelPorts) {
    dmemCancel(port) := 0.U.asTypeOf(Valid(UInt(DataMemTxn.width.W)))
  }
  for (port <- 0 until dmemQueueDepth) {
    dmemCancel(port) := dmemRequestQueue.io.cancel(port)
  }
  for (port <- 0 until DCache.cancelPorts(memCfg.dcache)) {
    dmemCancel(dmemQueueDepth + port) := mem.io.dmemCancel(port)
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

  private val memPerfEvents = Seq(
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
    MemPerfEvent.bit(MemPerfEvent.storeDrain, backend.io.memPerf.storeDrain)
  ).reduce(_ | _)

  memPerf.io.events              := memPerfEvents
  memPerf.io.mshrOccupancy       := mem.io.perf.mshrOccupancy.pad(32)
  memPerf.io.storeQueueOccupancy := backend.io.memPerf.sqOccupancy.pad(32)
  memPerf.io.loadTxnOccupancy    := backend.io.memPerf.loadTxnOccupancy.pad(32)

  io.axi <> mem.io.axi
}
