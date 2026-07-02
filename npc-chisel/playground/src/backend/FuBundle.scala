package top.backend.fubundle

import chisel3._
import top.backend.decoder.FuOp

class AluReq(dataWidth: Int = 32) extends Bundle {
  val src1 = Input(UInt(dataWidth.W))
  val src2 = Input(UInt(dataWidth.W))
  val out  = Output(UInt(dataWidth.W))
  val op   = Input(UInt(FuOp.width.W))
}
