package top.backend.fu

import chisel3._
import chisel3.util.{Cat, Decoupled, Fill, MuxLookup, Valid}
import top.backend.decoder.AluOp

class MulReq(dataWidth: Int = 32) extends Bundle {
  val src1 = UInt(dataWidth.W)
  val src2 = UInt(dataWidth.W)
  val op   = UInt(top.backend.decoder.FuOp.width.W)
}

class MUL(dataWidth: Int = 32) extends Module {
  require(dataWidth > 1, "MUL requires at least two data bits")

  val io = IO(new Bundle {
    val in    = Flipped(Decoupled(new MulReq(dataWidth)))
    val out   = Valid(UInt(dataWidth.W))
    val flush = Input(Bool())
  })

  private val productWidth = dataWidth * 2
  private val termWidth    = productWidth + 4
  private val boothGroups  = (dataWidth + 2) / 2

  private def lowData(value: UInt): UInt =
    value(dataWidth - 1, 0)

  private def highData(value: UInt): UInt =
    value(productWidth - 1, dataWidth)

  private def operand(value: UInt, signed: Bool): UInt =
    Cat(Fill(termWidth - dataWidth, signed && value(dataWidth - 1)), value)

  private def boothPartials(lhs: UInt, rhs: UInt, lhsSigned: Bool, rhsSigned: Bool): Seq[UInt] = {
    val lhsExt  = operand(lhs, lhsSigned)
    val lhs2Ext = (lhsExt << 1)(termWidth - 1, 0)
    val negLhs  = (0.U(termWidth.W) - lhsExt)(termWidth - 1, 0)
    val negLhs2 = (0.U(termWidth.W) - lhs2Ext)(termWidth - 1, 0)

    def rhsBit(pos: Int): Bool =
      if (pos < 0) {
        false.B
      } else if (pos < dataWidth) {
        rhs(pos)
      } else {
        rhsSigned && rhs(dataWidth - 1)
      }

    (0 until boothGroups).map { group =>
      val shift = group * 2
      val code  = Cat(rhsBit(shift + 1), rhsBit(shift), rhsBit(shift - 1))
      val part  = MuxLookup(code, 0.U(termWidth.W))(
        Seq(
          "b001".U -> lhsExt,
          "b010".U -> lhsExt,
          "b011".U -> lhs2Ext,
          "b100".U -> negLhs2,
          "b101".U -> negLhs,
          "b110".U -> negLhs
        )
      )

      (part << shift)(termWidth - 1, 0)
    }
  }

  private def compressor3(a: UInt, b: UInt, c: UInt): Seq[UInt] = {
    val sum   = a ^ b ^ c
    val carry = (((a & b) | (a & c) | (b & c)) << 1)(termWidth - 1, 0)

    Seq(sum, carry)
  }

  private def carrySaveCompress(values: Seq[UInt]): (UInt, UInt) = {
    require(values.nonEmpty, "carry-save compressor requires at least one input")

    def compressLayer(current: Seq[UInt]): Seq[UInt] =
      current
        .grouped(3)
        .flatMap {
          case Seq(a, b, c) => compressor3(a, b, c)
          case tail         => tail
        }
        .toSeq

    def compressUntilPair(current: Seq[UInt]): Seq[UInt] =
      if (current.length <= 2) {
        current
      } else {
        compressUntilPair(compressLayer(current))
      }

    val reduced = compressUntilPair(values)
    (reduced.head, if (reduced.length == 2) reduced(1) else 0.U(termWidth.W))
  }

  private val lhsSigned                        = io.in.bits.op === AluOp.mulh || io.in.bits.op === AluOp.mulhsu
  private val rhsSigned                        = io.in.bits.op === AluOp.mulh
  private val partials                         = boothPartials(io.in.bits.src1, io.in.bits.src2, lhsSigned, rhsSigned)
  private val (compressedSum, compressedCarry) = carrySaveCompress(partials)

  private val stage0Valid = RegInit(false.B)
  private val stage0Sum   = Reg(UInt(termWidth.W))
  private val stage0Carry = Reg(UInt(termWidth.W))
  private val stage0Op    = Reg(UInt(top.backend.decoder.FuOp.width.W))
  private val stage1Valid = RegInit(false.B)
  private val stage1Data  = Reg(UInt(dataWidth.W))

  private val stage0Product = (stage0Sum +& stage0Carry)(termWidth - 1, 0)(productWidth - 1, 0)
  private val stage0Result  = MuxLookup(stage0Op, 0.U(dataWidth.W))(
    Seq(
      AluOp.mul    -> lowData(stage0Product),
      AluOp.mulh   -> highData(stage0Product),
      AluOp.mulhsu -> highData(stage0Product),
      AluOp.mulhu  -> highData(stage0Product)
    )
  )

  io.in.ready  := !io.flush
  io.out.valid := !io.flush && stage1Valid
  io.out.bits  := stage1Data

  when(io.flush) {
    stage0Valid := false.B
    stage1Valid := false.B
  }.otherwise {
    stage1Valid := stage0Valid
    when(stage0Valid) {
      stage1Data := stage0Result
    }

    stage0Valid := io.in.fire
    when(io.in.fire) {
      stage0Sum   := compressedSum
      stage0Carry := compressedCarry
      stage0Op    := io.in.bits.op
    }
  }
}
