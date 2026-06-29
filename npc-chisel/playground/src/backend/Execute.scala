package top.backend.execute

import chisel3._
import top.backend.bundle.{ExecutePacket, IssuePacket}
import top.backend.fu.ALU
import top.config.BackendConfig

class Execute(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in  = Input(new IssuePacket(cfg))
    val out = Output(new ExecutePacket(cfg.addrWidth, cfg.dataWidth))
  })

  val alu = Module(new ALU(cfg.dataWidth))
}
