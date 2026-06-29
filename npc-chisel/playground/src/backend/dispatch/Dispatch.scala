package top.backend.dispatch

import chisel3._
import chisel3.util.MuxLookup
import top.backend.bundle.{DecodePacket, IssueOperand, IssuePacket, RegFileReadPort, ScoreboardAlloc, ScoreboardQuery}
import top.backend.decoder.SrcType
import top.config.BackendConfig

class Dispatch(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in              = Input(new DecodePacket(cfg.addrWidth))
    val robIdx          = Input(UInt(cfg.robIdxWidth.W))
    val rfRead          = Vec(cfg.operandsPerInst, Flipped(new RegFileReadPort(cfg.dataWidth)))
    val scoreboardQuery = Vec(cfg.operandsPerInst, Flipped(new ScoreboardQuery(cfg)))
    val scoreboardAlloc = Output(new ScoreboardAlloc(cfg))
    val out             = Output(new IssuePacket(cfg))
  })

  private val src1IsReg = io.in.src1Type === SrcType.reg
  private val src2IsReg = io.in.src2Type === SrcType.reg

  io.rfRead(0).enable := io.in.legal && src1IsReg
  io.rfRead(0).addr   := io.in.rs1
  io.rfRead(1).enable := io.in.legal && src2IsReg
  io.rfRead(1).addr   := io.in.rs2

  io.scoreboardQuery(0).valid := io.in.legal && src1IsReg
  io.scoreboardQuery(0).rs    := io.in.rs1
  io.scoreboardQuery(1).valid := io.in.legal && src2IsReg
  io.scoreboardQuery(1).rs    := io.in.rs2

  io.scoreboardAlloc.valid  := io.in.legal
  io.scoreboardAlloc.rd     := io.in.rd
  io.scoreboardAlloc.rfWen  := io.in.rfWen
  io.scoreboardAlloc.robIdx := io.robIdx

  private def asDataWidth(value: UInt): UInt =
    value.asTypeOf(UInt(cfg.dataWidth.W))

  private def selectSrc(srcType: UInt, regData: UInt): UInt =
    MuxLookup(srcType, 0.U(cfg.dataWidth.W))(
      Seq(
        SrcType.reg -> regData,
        SrcType.imm -> asDataWidth(io.in.imm),
        SrcType.pc  -> asDataWidth(io.in.fetch.pc)
      )
    )

  private def makeOperand(srcType: UInt, regData: UInt, scoreboard: ScoreboardQuery): IssueOperand = {
    val operand = Wire(new IssueOperand(cfg))
    val isReg   = srcType === SrcType.reg

    operand.data  := selectSrc(srcType, regData)
    operand.ready := !io.in.legal || !isReg || scoreboard.ready
    operand.tag   := Mux(isReg && !scoreboard.ready, scoreboard.producer, 0.U)
    return operand
  }

  io.out             := 0.U.asTypeOf(new IssuePacket(cfg))
  io.out.fetch       := io.in.fetch
  io.out.legal       := io.in.legal
  io.out.robIdx      := io.robIdx
  io.out.rd          := io.in.rd
  io.out.imm         := io.in.imm
  io.out.src1        := makeOperand(io.in.src1Type, io.rfRead(0).data, io.scoreboardQuery(0))
  io.out.src2        := makeOperand(io.in.src2Type, io.rfRead(1).data, io.scoreboardQuery(1))
  io.out.fuType      := io.in.fuType
  io.out.fuOp        := io.in.fuOp
  io.out.rfWen       := io.in.rfWen
  io.out.isLoad      := io.in.isLoad
  io.out.isStore     := io.in.isStore
  io.out.isBranch    := io.in.isBranch
  io.out.isJal       := io.in.isJal
  io.out.memSize     := io.in.memSize
  io.out.memUnsigned := io.in.memUnsigned
}
