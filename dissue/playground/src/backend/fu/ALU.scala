package top.backend.fu

import chisel3._
import chisel3.util.{log2Ceil, Cat, MuxLookup}
import top.backend.decoder.AluOp
import top.backend.fubundle.AluReq

class ALU(dataWidth: Int) extends Module {
  require(dataWidth > 1, "ALU requires at least two data bits")

  val io = IO(new AluReq(dataWidth))

  private val shamtWidth = math.max(log2Ceil(dataWidth), 1)
  private val shamt      = io.src2(shamtWidth - 1, 0)

  private def lowData(value: UInt): UInt =
    value(dataWidth - 1, 0)

  private def compare(value: Bool): UInt =
    Cat(0.U((dataWidth - 1).W), value.asUInt)

  io.out := MuxLookup(io.op, 0.U(dataWidth.W))(
    Seq(
      AluOp.add  -> lowData(io.src1 + io.src2),
      AluOp.sub  -> lowData(io.src1 - io.src2),
      AluOp.slt  -> compare(io.src1.asSInt < io.src2.asSInt),
      AluOp.sltu -> compare(io.src1 < io.src2),
      AluOp.xor  -> (io.src1 ^ io.src2),
      AluOp.or   -> (io.src1 | io.src2),
      AluOp.and  -> (io.src1 & io.src2),
      AluOp.sll  -> lowData(io.src1 << shamt),
      AluOp.srl  -> (io.src1 >> shamt),
      AluOp.sra  -> lowData((io.src1.asSInt >> shamt).asUInt)
    )
  )
}
