package top.backend.bundle

import chisel3._
import top.bundle.FetchInstPayload

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
}

object FuType {
  val width = 3

  val none = 0.U(width.W)
  val alu  = 1.U(width.W)
  val lsu  = 2.U(width.W)
  val bru  = 3.U(width.W)
  val jmp  = 4.U(width.W)
}

object FuOp {
  val width = 4

  val none = 0.U(width.W)
  val add  = 1.U(width.W)
  val lw   = 2.U(width.W)
  val sw   = 3.U(width.W)
  val beq  = 4.U(width.W)
  val jal  = 5.U(width.W)
}

class DecodePacket(addrWidth: Int = 32) extends Bundle {
  val fetch       = new FetchInstPayload(addrWidth)
  val legal       = Bool()
  val rs1         = UInt(5.W)
  val rs2         = UInt(5.W)
  val rd          = UInt(5.W)
  val imm         = UInt(32.W)
  val src1Type    = UInt(SrcType.width.W)
  val src2Type    = UInt(SrcType.width.W)
  val immSel      = UInt(ImmSel.width.W)
  val fuType      = UInt(FuType.width.W)
  val fuOp        = UInt(FuOp.width.W)
  val rfWen       = Bool()
  val isLoad      = Bool()
  val isStore     = Bool()
  val isBranch    = Bool()
  val isJal       = Bool()
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()
}

class ExecutePacket(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val pc        = UInt(addrWidth.W)
  val inst      = UInt(32.W)
  val rd        = UInt(5.W)
  val result    = UInt(dataWidth.W)
  val writeback = Bool()
}

class WritebackPacket(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val pc   = UInt(addrWidth.W)
  val inst = UInt(32.W)
  val rd   = UInt(5.W)
  val data = UInt(dataWidth.W)
  val wen  = Bool()
}

class RegFileReadPort(dataWidth: Int = 32) extends Bundle {
  val enable = Input(Bool())
  val addr   = Input(UInt(5.W))
  val data   = Output(UInt(dataWidth.W))
}

class RegFileWritePort(dataWidth: Int = 32) extends Bundle {
  val enable = Input(Bool())
  val addr   = Input(UInt())
  val data   = Input(UInt(dataWidth.W))
}

class RegFilePortBundle(
  readPorts:  Int = 2,
  writePorts: Int = 2,
  dataWidth:  Int = 32)
    extends Bundle {
  val read  = Vec(readPorts, new RegFileReadPort(dataWidth))
  val write = Vec(writePorts, new RegFileWritePort(dataWidth))
}
