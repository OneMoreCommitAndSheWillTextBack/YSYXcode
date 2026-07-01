package top.backend.regfile

import chisel3._
import top.backend.bundle._
import chisel3.util.MuxCase
import top.config.BackendConfig

class RegFile(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(
    new RegFilePortBundle(
      readPorts = cfg.regfileReadPorts,
      writePorts = cfg.regfileWritePorts,
      dataWidth = cfg.dataWidth
    )
  )

  private val gpr = Reg(Vec(31, UInt(cfg.dataWidth.W)))

  for (read <- io.read) {
    read.data := MuxCase(
      0.U(cfg.dataWidth.W),
      (1 until 32).map(idx => (read.enable && read.addr === idx.U) -> gpr(idx - 1))
    )
  }

  for (idx <- 1 until 32) {
    val hits = io.write.map(write => write.enable && write.addr === idx.U)
    val data = MuxCase(
      gpr(idx - 1),
      hits.zip(io.write).reverse.map { case (hit, write) => hit -> write.data }
    )

    when(hits.reduce((a, b) => a || b)) {
      gpr(idx - 1) := data
    }
  }
}
