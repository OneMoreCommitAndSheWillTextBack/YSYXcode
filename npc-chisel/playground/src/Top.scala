package top

import chisel3._
import top.backend.Backend
import top.bundle.FrontendToBackend
import top.config.{BackendConfig, FrontendConfig, MemConfig}
import top.frontend.Frontend
import top.frontend.bundle.{BpuUpdate, CfiType}
import top.mem.Mem

final class AxiPort extends Bundle {
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr  = Output(UInt(32.W))
  val awid    = Output(UInt(4.W))
  val awlen   = Output(UInt(8.W))
  val awsize  = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))

  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata  = Output(UInt(32.W))
  val wstrb  = Output(UInt(4.W))
  val wlast  = Output(Bool())

  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp  = Input(UInt(2.W))
  val bid    = Input(UInt(4.W))

  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr  = Output(UInt(32.W))
  val arid    = Output(UInt(4.W))
  val arlen   = Output(UInt(8.W))
  val arsize  = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))

  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp  = Input(UInt(2.W))
  val rdata  = Input(UInt(32.W))
  val rlast  = Input(Bool())
  val rid    = Input(UInt(4.W))
}

class Core(resetVector: BigInt) extends Module {
  private val frontendCfg = FrontendConfig()
  private val backendCfg  = BackendConfig()
  private val memCfg      = MemConfig()

  require(backendCfg.addrWidth == frontendCfg.addrWidth, "frontend/backend addrWidth must match")
  require(backendCfg.addrWidth == memCfg.addrWidth, "backend/mem addrWidth must match")
  require(backendCfg.dataWidth == memCfg.axiDataWidth, "backend dataWidth must match memory data width")
  require(backendCfg.issueWidth == 2, "Core bridge currently assumes the frontend produces two slots")

  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master    = new AxiPort
  })

  val frontend = Module(new Frontend(resetVector, frontendCfg))
  val backend  = Module(new Backend(backendCfg))
  val mem      = Module(new Mem(memCfg))

  frontend.io.trapRedirect.valid := backend.io.redirect.trapRedirect.valid
  frontend.io.trapRedirect.value := backend.io.redirect.trapRedirect.target

  frontend.io.branchRedirect.valid := backend.io.redirect.branchRedirect.valid
  frontend.io.branchRedirect.value := backend.io.redirect.branchRedirect.target

  frontend.io.predRedirect.valid := backend.io.redirect.predRedirect.valid
  frontend.io.predRedirect.value := backend.io.redirect.predRedirect.target

  frontend.io.bpuUpdate.valid        := backend.io.redirect.bpuUpdate.valid
  frontend.io.bpuUpdate.bits         := 0.U.asTypeOf(new BpuUpdate(frontendCfg.bpu))
  frontend.io.bpuUpdate.bits.pc      := backend.io.redirect.bpuUpdate.bits.pc
  frontend.io.bpuUpdate.bits.cfiType := Mux(
    backend.io.redirect.bpuUpdate.bits.cfiType === 2.U,
    CfiType.jal,
    CfiType.branch
  )
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
  }

  mem.io.imemReq.valid             := frontend.io.cacheRefillReq.valid
  mem.io.imemReq.bits.addr         := frontend.io.cacheRefillReq.bits.addr
  frontend.io.cacheRefillReq.ready := mem.io.imemReq.ready

  frontend.io.cacheRefillResp.valid     := mem.io.imemResp.valid
  frontend.io.cacheRefillResp.bits.data := mem.io.imemResp.bits.data
  mem.io.imemResp.ready                 := frontend.io.cacheRefillResp.ready

  mem.io.dmemReq <> backend.io.dmemReq
  backend.io.dmemResp <> mem.io.dmemResp

  io.master <> mem.io.axi
}

class Top(target: Target = Target.Npc) extends Module {
  override def desiredName: String = "ysyx_24100007"
  private val resetVector = target.resetVector

  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master    = new AxiPort
    val slave     = Flipped(new AxiPort)
  })

  val core = Module(new Core(resetVector))
  core.io.interrupt := io.interrupt
  io.master <> core.io.master

  io.slave.awready := false.B
  io.slave.wready  := false.B

  io.slave.bvalid := false.B
  io.slave.bresp  := 0.U
  io.slave.bid    := 0.U

  io.slave.arready := false.B

  io.slave.rvalid := false.B
  io.slave.rresp  := 0.U
  io.slave.rdata  := 0.U
  io.slave.rlast  := false.B
  io.slave.rid    := 0.U
}
