package top.backend.exu

import chisel3._
import chisel3.util.{Decoupled, Valid}
import top.backend.bundle.{IssuePortStatus, IssueWakeup, RobWritebackPacket}
import top.config.BackendConfig

class ExecuteBlock(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in     = Vec(cfg.intIssueWidth, Flipped(Decoupled(new ExuRequest(cfg))))
    val flush  = Input(Bool())
    val status = Output(Vec(cfg.intIssueWidth, new IssuePortStatus))

    val writeback = Output(Vec(cfg.intIssueWidth, Valid(new RobWritebackPacket(cfg))))
    val wakeup    = Output(Vec(cfg.intIssueWidth, new IssueWakeup(cfg)))
  })

  private val units = (0 until cfg.intIssueWidth).map { port =>
    val unitConfig = IntExeUnitConfig.defaultIssuePort(port, cfg.intIssueWidth)
    Module(new IntExeUnit(cfg, unitConfig)).suggestName(unitConfig.name)
  }

  for (port <- 0 until cfg.intIssueWidth) {
    units(port).io.flush := io.flush
    units(port).io.in <> io.in(port)
    io.status(port)      := units(port).io.status
    io.writeback(port)   := units(port).io.writeback
    io.wakeup(port)      := units(port).io.wakeup
  }
}
