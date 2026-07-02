package top.backend.dispatch

import chisel3._
import chisel3.util.{Decoupled, MuxLookup}
import top.backend.bundle.{DecodePacket, IssueOperand, IssuePacket, RegFileReadPort, ScoreboardAlloc, ScoreboardQuery}
import top.backend.decoder.{FuType, SrcType}
import top.config.BackendConfig

class Dispatch(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in              = Input(Vec(cfg.dispatchWidth, new DecodePacket(cfg.addrWidth)))
    val robIdx          = Input(Vec(cfg.dispatchWidth, UInt(cfg.robIdxWidth.W)))
    val rfRead          = Vec(cfg.scoreboardQueries, Flipped(new RegFileReadPort(cfg.dataWidth)))
    val scoreboardQuery = Vec(cfg.scoreboardQueries, Flipped(new ScoreboardQuery(cfg)))
    val scoreboardAlloc = Output(Vec(cfg.dispatchWidth, new ScoreboardAlloc(cfg)))
    val out             = Vec(cfg.dispatchWidth, Decoupled(new IssuePacket(cfg)))
  })

  private def operandPort(lane: Int, operand: Int): Int =
    lane * cfg.operandsPerInst + operand

  private def readsRs(decode: DecodePacket, srcType: UInt, rs: UInt): Bool =
    decode.legal && (srcType === SrcType.reg) && (rs =/= 0.U)

  private def writesRd(decode: DecodePacket): Bool =
    decode.legal && decode.rfWen && (decode.rd =/= 0.U)

  private def isControlBoundary(decode: DecodePacket): Bool =
    decode.legal && (decode.isBranch || decode.isJal || (decode.fuType === FuType.bru) || (decode.fuType === FuType.jmp))

  private def asDataWidth(value: UInt): UInt =
    value.asTypeOf(UInt(cfg.dataWidth.W))

  private def selectSrc(decode: DecodePacket, srcType: UInt, regData: UInt): UInt =
    MuxLookup(srcType, 0.U(cfg.dataWidth.W))(
      Seq(
        SrcType.reg -> regData,
        SrcType.imm -> asDataWidth(decode.imm),
        SrcType.pc  -> asDataWidth(decode.fetch.pc)
      )
    )

  private def makeOperand(
    decode:     DecodePacket,
    srcType:    UInt,
    regData:    UInt,
    scoreboard: ScoreboardQuery
  ): IssueOperand = {
    val operand = Wire(new IssueOperand(cfg))
    val isReg   = srcType === SrcType.reg

    operand.data  := selectSrc(decode, srcType, regData)
    operand.ready := !decode.legal || !isReg || scoreboard.ready
    operand.tag   := Mux(isReg && !scoreboard.ready, scoreboard.producer, 0.U)
    operand
  }

  val laneAllowed = Wire(Vec(cfg.dispatchWidth, Bool()))
  for (lane <- 0 until cfg.dispatchWidth) {
    laneAllowed(lane) := io.in(lane).legal
  }

  if (cfg.dispatchWidth > 1) {
    for (lane <- 1 until cfg.dispatchWidth) {
      val olderHazards = (0 until lane).map { olderLane =>
        val older = io.in(olderLane)
        val young = io.in(lane)

        val raw             =
          writesRd(older) &&
            ((readsRs(young, young.src1Type, young.rs1) && (young.rs1 === older.rd)) ||
              (readsRs(young, young.src2Type, young.rs2) && (young.rs2 === older.rd)))
        val waw             = writesRd(older) && writesRd(young) && (older.rd === young.rd)
        val controlBoundary = isControlBoundary(older)

        !io.out(olderLane).fire || raw || waw || controlBoundary
      }.reduce(_ || _)

      // Without rename, a dispatch group is only allowed to expose a dependency-free prefix.
      laneAllowed(lane) := io.in(lane).legal && !olderHazards
    }
  }

  for (lane <- 0 until cfg.dispatchWidth) {
    val decode = io.in(lane)

    val src1Port = operandPort(lane, 0)
    val src2Port = operandPort(lane, 1)

    val src1IsReg = decode.src1Type === SrcType.reg
    val src2IsReg = decode.src2Type === SrcType.reg

    io.rfRead(src1Port).enable := decode.legal && src1IsReg
    io.rfRead(src1Port).addr   := decode.rs1
    io.rfRead(src2Port).enable := decode.legal && src2IsReg
    io.rfRead(src2Port).addr   := decode.rs2

    io.scoreboardQuery(src1Port).valid := decode.legal && src1IsReg
    io.scoreboardQuery(src1Port).rs    := decode.rs1
    io.scoreboardQuery(src2Port).valid := decode.legal && src2IsReg
    io.scoreboardQuery(src2Port).rs    := decode.rs2

    io.scoreboardAlloc(lane).valid  := io.out(lane).fire
    io.scoreboardAlloc(lane).rd     := decode.rd
    io.scoreboardAlloc(lane).rfWen  := decode.rfWen
    io.scoreboardAlloc(lane).robIdx := io.robIdx(lane)

    io.out(lane).valid            := laneAllowed(lane)
    io.out(lane).bits             := 0.U.asTypeOf(new IssuePacket(cfg))
    io.out(lane).bits.fetch       := decode.fetch
    io.out(lane).bits.legal       := decode.legal
    io.out(lane).bits.robIdx      := io.robIdx(lane)
    io.out(lane).bits.rd          := decode.rd
    io.out(lane).bits.imm         := decode.imm
    io.out(lane).bits.src1        := makeOperand(
      decode,
      decode.src1Type,
      io.rfRead(src1Port).data,
      io.scoreboardQuery(src1Port)
    )
    io.out(lane).bits.src2        := makeOperand(
      decode,
      decode.src2Type,
      io.rfRead(src2Port).data,
      io.scoreboardQuery(src2Port)
    )
    io.out(lane).bits.fuType      := decode.fuType
    io.out(lane).bits.fuOp        := decode.fuOp
    io.out(lane).bits.rfWen       := decode.rfWen
    io.out(lane).bits.isLoad      := decode.isLoad
    io.out(lane).bits.isStore     := decode.isStore
    io.out(lane).bits.isBranch    := decode.isBranch
    io.out(lane).bits.isJal       := decode.isJal
    io.out(lane).bits.memSize     := decode.memSize
    io.out(lane).bits.memUnsigned := decode.memUnsigned
  }
}
