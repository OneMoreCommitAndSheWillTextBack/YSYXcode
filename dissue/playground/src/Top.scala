package top

import chisel3._
import top.bus.AxiXbar
import top.bus.axi.AxiPort
import top.config.{FrontendConfig, MemConfig}
import top.core.Core

class Top(
  target:      Target = Target.Npc,
  view:        View = View.Sim,
  enableTrace: Boolean = true,
  frontendCfg: FrontendConfig = FrontendConfig())
    extends Module {
  override def desiredName: String = "ysyx_24100007"
  private val resetVector     = target.resetVector
  private val simulationBuild = view.isSim && target == Target.Npc

  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master    = new AxiPort
    val slave     = Flipped(new AxiPort)
  })

  private val memCfg = MemConfig()

  val core = Module(new Core(resetVector, enableTrace && simulationBuild, frontendCfg, simulationBuild))
  val xbar = Module(new AxiXbar(memCfg))

  xbar.io.externalInterrupt := io.interrupt
  core.io.interrupt         := xbar.io.interrupt
  core.io.mtime             := xbar.io.mtime

  xbar.io.core <> core.io.axi
  io.master <> xbar.io.mem

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
