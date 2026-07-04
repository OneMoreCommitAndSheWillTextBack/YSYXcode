package top.backend.fu

import chisel3._
import chisel3.util.MuxLookup
import top.backend.decoder.BruOp
import top.backend.fubundle.BruReq

class BRU(addrWidth: Int = 32, dataWidth: Int = 32) extends Module {
  val io = IO(new BruReq(addrWidth, dataWidth))

  private def asAddr(value: UInt): UInt =
    value.pad(addrWidth)(addrWidth - 1, 0)

  private val signedLess   = io.src1.asSInt < io.src2.asSInt
  private val unsignedLess = io.src1 < io.src2
  private val equal        = io.src1 === io.src2
  private val fallThrough  = asAddr(io.pc + io.instLen)
  private val branchTarget = asAddr(io.pc + asAddr(io.imm))

  io.taken := MuxLookup(io.op, false.B)(
    Seq(
      BruOp.beq  -> equal,
      BruOp.bne  -> !equal,
      BruOp.blt  -> signedLess,
      BruOp.bge  -> !signedLess,
      BruOp.bltu -> unsignedLess,
      BruOp.bgeu -> !unsignedLess
    )
  )

  io.target         := branchTarget
  io.redirectTarget := Mux(io.taken, branchTarget, fallThrough)
}
