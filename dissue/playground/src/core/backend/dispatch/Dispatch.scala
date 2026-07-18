package top.core.backend.dispatch

import chisel3._
import chisel3.util.{Decoupled, MuxLookup}
import top.core.backend.bundle.{
  DecodePacket,
  IssueOperand,
  IssuePacket,
  RegFileReadPort,
  ScoreboardAlloc,
  ScoreboardQuery
}
import top.core.backend.decoder.{FuType, SrcType}
import top.config.BackendConfig
import top.core.bundle.CfiType

class Dispatch(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in              = Input(Vec(cfg.dispatchWidth, new DecodePacket(cfg)))
    val robIdx          = Input(Vec(cfg.dispatchWidth, UInt(cfg.robIdxWidth.W)))
    val rfRead          = Vec(cfg.scoreboardQueries, Flipped(new RegFileReadPort(cfg.dataWidth)))
    val scoreboardQuery = Vec(cfg.scoreboardQueries, Flipped(new ScoreboardQuery(cfg)))
    val scoreboardAlloc = Output(Vec(cfg.dispatchWidth, new ScoreboardAlloc(cfg)))
    val out             = Vec(cfg.dispatchWidth, Decoupled(new IssuePacket(cfg)))
  })

  private def operandPort(lane: Int, operand: Int): Int =
    lane * cfg.operandsPerInst + operand

  private def isDispatchBoundary(decode: DecodePacket): Bool =
    decode.valid && (decode.isRetireOnly || (decode.cfi =/= CfiType.none))

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
    operand.ready := !decode.needsIssue || !isReg || scoreboard.ready
    operand.tag   := Mux(isReg && !scoreboard.ready, scoreboard.producer, 0.U)
    operand
  }

  val laneAllowed = Wire(Vec(cfg.dispatchWidth, Bool()))
  for (lane <- 0 until cfg.dispatchWidth) {
    laneAllowed(lane) := io.in(lane).valid
  }

  if (cfg.dispatchWidth > 1) {
    for (lane <- 1 until cfg.dispatchWidth) {
      val olderLaneBlocksDispatch = (0 until lane).map { olderLane =>
        !io.out(olderLane).fire || isDispatchBoundary(io.in(olderLane))
      }.reduce(_ || _)

      // The scoreboard assigns same-packet RAW tags and preserves the youngest WAW producer.
      // Only an older dispatch failure or an architectural boundary truncates the packet.
      laneAllowed(lane) := io.in(lane).valid && !olderLaneBlocksDispatch
    }
  }

  for (lane <- 0 until cfg.dispatchWidth) {
    val decode = io.in(lane)

    val src1Port = operandPort(lane, 0)
    val src2Port = operandPort(lane, 1)

    val src1IsReg = decode.src1Type === SrcType.reg
    val src2IsReg = decode.src2Type === SrcType.reg

    io.rfRead(src1Port).enable := decode.needsIssue && src1IsReg
    io.rfRead(src1Port).addr   := decode.rs1
    io.rfRead(src2Port).enable := decode.needsIssue && src2IsReg
    io.rfRead(src2Port).addr   := decode.rs2

    io.scoreboardQuery(src1Port).valid := decode.needsIssue && src1IsReg
    io.scoreboardQuery(src1Port).rs    := decode.rs1
    io.scoreboardQuery(src2Port).valid := decode.needsIssue && src2IsReg
    io.scoreboardQuery(src2Port).rs    := decode.rs2

    io.scoreboardAlloc(lane).valid  := io.out(lane).fire && decode.needsIssue
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
    io.out(lane).bits.isAmo       := decode.isAmo
    io.out(lane).bits.cfi         := decode.cfi
    io.out(lane).bits.memSize     := decode.memSize
    io.out(lane).bits.memUnsigned := decode.memUnsigned
    io.out(lane).bits.isCsr       := decode.isCsr
    io.out(lane).bits.csrAddr     := decode.csrAddr
    io.out(lane).bits.csrWen      := decode.csrWen
    io.out(lane).bits.exception   := decode.exception
  }
}
