package top.core

import chisel3._
import top.core.backend.Backend
import top.core.backend.csr.CsrInterruptPending
import top.bus.axi.AxiPort
import top.core.bundle.FrontendToBackend
import top.config.{BackendConfig, FrontendConfig, MemConfig}
import top.core.mem.Mem
import top.core.frontend.Frontend
import top.core.frontend.bundle.BpuUpdate

class Core(resetVector: BigInt) extends Module {
  private val frontendCfg = FrontendConfig()
  private val backendCfg  = BackendConfig()
  private val memCfg      = MemConfig()

  require(backendCfg.addrWidth == frontendCfg.addrWidth, "frontend/backend addrWidth must match")
  require(backendCfg.addrWidth == memCfg.addrWidth, "backend/mem addrWidth must match")
  require(backendCfg.dataWidth == memCfg.axiDataWidth, "backend dataWidth must match memory data width")
  require(backendCfg.issueWidth == 2, "Core bridge currently assumes the frontend produces two slots")

  val io = IO(new Bundle {
    val interrupt = Input(new CsrInterruptPending)
    val axi       = new AxiPort
  })

  val frontend = Module(new Frontend(resetVector, frontendCfg))
  val backend  = Module(new Backend(resetVector, backendCfg))
  val mem      = Module(new Mem(memCfg))

  frontend.io.csrStatus := backend.io.csrStatus
  backend.io.interrupt  := io.interrupt

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

  private val dmemRespToFrontend  = RegInit(false.B)
  private val dmemOutstanding     = RegInit(false.B)
  private val backendDmemSelected = !dmemOutstanding && backend.io.dmemReq.valid
  private val frontendPtwSelected = !dmemOutstanding && !backend.io.dmemReq.valid && frontend.io.ptwReq.valid

  mem.io.dmemReq.valid := backendDmemSelected || frontendPtwSelected
  mem.io.dmemReq.bits  := Mux(backendDmemSelected, backend.io.dmemReq.bits, frontend.io.ptwReq.bits)

  backend.io.dmemReq.ready := !dmemOutstanding && mem.io.dmemReq.ready
  frontend.io.ptwReq.ready := frontendPtwSelected && mem.io.dmemReq.ready

  backend.io.dmemResp.valid := dmemOutstanding && !dmemRespToFrontend && mem.io.dmemResp.valid
  backend.io.dmemResp.bits  := mem.io.dmemResp.bits
  frontend.io.ptwResp.valid := dmemOutstanding && dmemRespToFrontend && mem.io.dmemResp.valid
  frontend.io.ptwResp.bits  := mem.io.dmemResp.bits
  mem.io.dmemResp.ready     := Mux(
    dmemRespToFrontend,
    frontend.io.ptwResp.ready,
    backend.io.dmemResp.ready
  )

  when(mem.io.dmemReq.fire) {
    dmemOutstanding    := true.B
    dmemRespToFrontend := frontendPtwSelected
  }.elsewhen(mem.io.dmemResp.fire) {
    dmemOutstanding    := false.B
    dmemRespToFrontend := false.B
  }

  io.axi <> mem.io.axi
}
