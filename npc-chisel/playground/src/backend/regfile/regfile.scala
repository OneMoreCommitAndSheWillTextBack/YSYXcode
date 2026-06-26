package top.backend.regfile

import chisel3._
import top.backend.bundle._
import chisel3.util.MuxCase

class RegFile(
  readPorts:  Int = 2,
  writePorts: Int = 2,
  dataWidth:  Int = 32)
    extends Module {
  require(readPorts > 0, "RegFile must have at least one read port")
  require(writePorts > 0, "RegFile must have at least one write port")

  val io = IO(
    new RegFilePortBundle(
      readPorts = readPorts,
      writePorts = writePorts,
      dataWidth = dataWidth
    )
  )

  private val gpr = Reg(Vec(31, UInt(dataWidth.W)))

  for (read <- io.read) {
    read.data := MuxCase(
      0.U(dataWidth.W),
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
