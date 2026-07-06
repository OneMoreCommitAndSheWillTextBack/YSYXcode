package top.backend.fu

import chisel3._
import chisel3.util.{is, log2Ceil, switch, Cat, Decoupled, Enum, Fill, Valid}
import top.backend.decoder.{AluOp, FuOp}
import top.dpi.NpcDivPerf

class DivReq(dataWidth: Int = 32) extends Bundle {
  val src1 = UInt(dataWidth.W)
  val src2 = UInt(dataWidth.W)
  val op   = UInt(FuOp.width.W)
}

class DIV(dataWidth: Int = 32) extends Module {
  require(dataWidth > 1, "DIV requires at least two data bits")

  val io = IO(new Bundle {
    val in    = Flipped(Decoupled(new DivReq(dataWidth)))
    val out   = Valid(UInt(dataWidth.W))
    val flush = Input(Bool())
    val busy  = Output(Bool())
  })

  private val countWidth = math.max(log2Ceil(dataWidth + 1), 1)

  private val sIdle :: sIterate :: sDone :: Nil = Enum(3)
  private val state                             = RegInit(sIdle)

  private val divisor   = Reg(UInt((dataWidth + 1).W))
  private val dividend  = Reg(UInt(dataWidth.W))
  private val quotient  = Reg(UInt(dataWidth.W))
  private val remainder = Reg(UInt((dataWidth + 1).W))
  private val remaining = Reg(UInt(countWidth.W))

  private val result            = Reg(UInt(dataWidth.W))
  private val quotientNegative  = Reg(Bool())
  private val remainderNegative = Reg(Bool())
  private val selectRemainder   = Reg(Bool())
  private val cycleCount        = RegInit(0.U(16.W))
  private val specialResult     = RegInit(false.B)

  private def lowData(value: UInt): UInt =
    value(dataWidth - 1, 0)

  private def twosComplement(value: UInt): UInt =
    lowData(0.U(dataWidth.W) - value)

  private def magnitude(value: UInt, signed: Bool): UInt =
    Mux(signed && value(dataWidth - 1), twosComplement(value), value)

  // RISC-V signed DIV/REM runs through the same unsigned core after magnitude conversion.
  private val reqSigned       = io.in.bits.op === AluOp.div || io.in.bits.op === AluOp.rem
  private val reqRemainder    = io.in.bits.op === AluOp.rem || io.in.bits.op === AluOp.remu
  private val reqDivByZero    = io.in.bits.src2 === 0.U
  private val allOnes         = Fill(dataWidth, 1.U(1.W))
  private val minSigned       = (BigInt(1) << (dataWidth - 1)).U(dataWidth.W)
  private val signedOverflow  = reqSigned && io.in.bits.src1 === minSigned && io.in.bits.src2 === allOnes
  private val specialCase     = reqDivByZero || signedOverflow
  private val divByZeroResult = Mux(reqRemainder, io.in.bits.src1, allOnes)
  private val overflowResult  = Mux(reqRemainder, 0.U(dataWidth.W), minSigned)

  private val dividendSign = reqSigned && io.in.bits.src1(dataWidth - 1)
  private val divisorSign  = reqSigned && io.in.bits.src2(dataWidth - 1)
  private val dividendAbs  = magnitude(io.in.bits.src1, reqSigned)
  private val divisorAbs   = magnitude(io.in.bits.src2, reqSigned)

  // One restoring radix-2 step: shift in the next dividend bit, subtract when possible, emit one quotient bit.
  private val shiftedRemainder = Cat(remainder(dataWidth - 1, 0), dividend(dataWidth - 1))
  private val canSubtract      = shiftedRemainder >= divisor
  private val subtractResult   = shiftedRemainder - divisor
  private val nextRemainder    = Mux(canSubtract, subtractResult, shiftedRemainder)
  private val nextQuotient     = Cat(quotient(dataWidth - 2, 0), canSubtract)
  private val nextDividend     = Cat(dividend(dataWidth - 2, 0), 0.U(1.W))
  private val finalIteration   = remaining === 1.U

  private val unsignedRemainder = nextRemainder(dataWidth - 1, 0)
  private val signedQuotient    = Mux(quotientNegative, twosComplement(nextQuotient), nextQuotient)
  private val signedRemainder   = Mux(remainderNegative, twosComplement(unsignedRemainder), unsignedRemainder)

  io.in.ready  := state === sIdle && !io.flush
  io.out.valid := state === sDone && !io.flush
  io.out.bits  := result
  io.busy      := state =/= sIdle

  NpcDivPerf.callWithEnable(!reset.asBool && state === sDone && !io.flush, cycleCount.pad(32), specialResult)

  when(io.flush) {
    state := sIdle
  }.otherwise {
    switch(state) {
      is(sIdle) {
        when(io.in.fire) {
          cycleCount    := 1.U
          specialResult := specialCase

          when(specialCase) {
            result := Mux(reqDivByZero, divByZeroResult, overflowResult)
            state  := sDone
          }.otherwise {
            divisor           := Cat(0.U(1.W), divisorAbs)
            dividend          := dividendAbs
            quotient          := 0.U
            remainder         := 0.U
            remaining         := dataWidth.U(countWidth.W)
            quotientNegative  := !reqRemainder && (dividendSign ^ divisorSign)
            remainderNegative := reqRemainder && dividendSign
            selectRemainder   := reqRemainder
            state             := sIterate
          }
        }
      }

      is(sIterate) {
        dividend   := nextDividend
        quotient   := nextQuotient
        remainder  := nextRemainder
        remaining  := remaining - 1.U
        cycleCount := cycleCount + 1.U

        when(finalIteration) {
          result := Mux(selectRemainder, signedRemainder, signedQuotient)
          state  := sDone
        }
      }

      is(sDone) {
        state := sIdle
      }
    }
  }
}
