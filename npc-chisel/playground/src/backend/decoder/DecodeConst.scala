package top.backend.decoder

import chisel3._

object SrcType {
  val width = 2

  val none = 0.U(width.W)
  val reg  = 1.U(width.W)
  val imm  = 2.U(width.W)
  val pc   = 3.U(width.W)
}

object ImmSel {
  val width = 3

  val none = 0.U(width.W)
  val i    = 1.U(width.W)
  val s    = 2.U(width.W)
  val b    = 3.U(width.W)
  val j    = 4.U(width.W)
  val u    = 5.U(width.W)
}

object FuType {
  val width = 3

  val none  = 0.U(width.W)
  val alu   = 1.U(width.W)
  val lsu   = 2.U(width.W)
  val bru   = 3.U(width.W)
  val jmp   = 4.U(width.W)
  val csr   = 5.U(width.W)
  val fence = 6.U(width.W)
}

object FuOp {
  val width = 4

  val none = 0.U(width.W)
}

object AluOp {
  val add = 1.U(FuOp.width.W)
}

object LsuOp {
  val load  = 1.U(FuOp.width.W)
  val store = 2.U(FuOp.width.W)
}

object BruOp {
  val beq = 1.U(FuOp.width.W)
}

object JmpOp {
  val jal = 1.U(FuOp.width.W)
}
