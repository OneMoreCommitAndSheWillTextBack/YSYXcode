package top.backend.fubundle

import chisel3._
import top.backend.decoder.FuOp

class AluReq(dataWidth: Int = 32) extends Bundle {
  val src1 = Input(UInt(dataWidth.W))
  val src2 = Input(UInt(dataWidth.W))
  val out  = Output(UInt(dataWidth.W))
  val op   = Input(UInt(FuOp.width.W))
}

class BruReq(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val src1           = Input(UInt(dataWidth.W))
  val src2           = Input(UInt(dataWidth.W))
  val pc             = Input(UInt(addrWidth.W))
  val imm            = Input(UInt(dataWidth.W))
  val instLen        = Input(UInt(3.W))
  val op             = Input(UInt(FuOp.width.W))
  val taken          = Output(Bool())
  val target         = Output(UInt(addrWidth.W))
  val redirectTarget = Output(UInt(addrWidth.W))
}

class JmpReq(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val src1           = Input(UInt(dataWidth.W))
  val pc             = Input(UInt(addrWidth.W))
  val imm            = Input(UInt(dataWidth.W))
  val instLen        = Input(UInt(3.W))
  val op             = Input(UInt(FuOp.width.W))
  val target         = Output(UInt(addrWidth.W))
  val redirectTarget = Output(UInt(addrWidth.W))
  val link           = Output(UInt(dataWidth.W))
}
