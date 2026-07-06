package top.backend.exu

import chisel3._
import chisel3.util.{Decoupled, Valid}
import top.backend.bundle.{IssuePortStatus, IssueWakeup, RobWritebackPacket}
import top.backend.csr.CsrReadPort
import top.config.BackendConfig

class ExecuteBlock(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in      = Vec(cfg.intIssueWidth, Flipped(Decoupled(new ExuRequest(cfg))))
    val flush   = Input(Bool())
    val status  = Output(Vec(cfg.intIssueWidth, new IssuePortStatus))
    val csrRead = new CsrReadPort(cfg)

    val writeback = Output(Vec(cfg.intIssueWidth, Valid(new RobWritebackPacket(cfg))))
    val wakeup    = Output(Vec(cfg.intIssueWidth, new IssueWakeup(cfg)))
  })

  private val unitConfigs = (0 until cfg.intIssueWidth).map { port =>
    IntExeUnitConfig.defaultIssuePort(port, cfg.intIssueWidth)
  }
  private val units       = unitConfigs.map { unitConfig =>
    Module(new IntExeUnit(cfg, unitConfig)).suggestName(unitConfig.name)
  }

  for (port <- 0 until cfg.intIssueWidth) {
    units(port).io.flush              := io.flush
    units(port).io.in <> io.in(port)
    units(port).io.csrRead.data       := io.csrRead.data
    units(port).io.csrRead.readLegal  := io.csrRead.readLegal
    units(port).io.csrRead.writeLegal := io.csrRead.writeLegal
    io.status(port)                   := units(port).io.status
    io.writeback(port)                := units(port).io.writeback
    io.wakeup(port)                   := units(port).io.wakeup
  }

  private val csrReadSources = unitConfigs.zip(units).collect {
    case (unitConfig, unit) if unitConfig.supports(ExuFuKind.Csr) =>
      unit.io.csrRead.addr
  }
  require(csrReadSources.size <= 1, "ExecuteBlock has one CSR read port; add ports before enabling multiple CSR units")

  io.csrRead.addr := (if (csrReadSources.isEmpty) 0.U else csrReadSources.head)
}
