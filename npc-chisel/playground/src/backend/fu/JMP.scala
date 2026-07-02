package top.backend.fu

import chisel3._
import top.backend.decoder.JmpOp
import top.backend.fubundle.JmpReq

class JMP(addrWidth: Int = 32, dataWidth: Int = 32) extends Module {
  val io = IO(new JmpReq(addrWidth, dataWidth))

  private def asAddr(value: UInt): UInt =
    value.pad(addrWidth)(addrWidth - 1, 0)

  private def asData(value: UInt): UInt =
    value.pad(dataWidth)(dataWidth - 1, 0)

  private val fallThrough = asAddr(io.pc + io.instLen)
  private val jalTarget   = asAddr(io.pc + asAddr(io.imm))
  private val jalrTarget  = asAddr(io.src1 + io.imm) & ~1.U(addrWidth.W)
  private val target      = Mux(io.op === JmpOp.jalr, jalrTarget, jalTarget)

  io.target         := target
  io.redirectTarget := target
  io.link           := asData(fallThrough)
}
