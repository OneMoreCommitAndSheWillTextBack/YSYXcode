package top.core.frontend

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.bundle.CfiType
import top.core.frontend.bundle._
import top.core.frontend.ifetch.{FetchWidth, PredecodeStage, PredictionChecker}

private class PredecodePredictionCheckerHarness extends Module {
  val cfg = FrontendConfig(fetchTargetEntries = 4)

  val io = IO(new Bundle {
    val laneValid     = Input(Vec(FetchWidth.frontend, Bool()))
    val lanePc        = Input(Vec(FetchWidth.frontend, UInt(cfg.addrWidth.W)))
    val laneRaw       = Input(Vec(FetchWidth.frontend, UInt(32.W)))
    val laneRvc       = Input(Vec(FetchWidth.frontend, Bool()))
    val laneException = Input(Vec(FetchWidth.frontend, Bool()))
    val laneLast      = Input(Vec(FetchWidth.frontend, Bool()))

    val viewValid         = Input(Bool())
    val startPc           = Input(UInt(cfg.addrWidth.W))
    val blockMetaValid    = Input(Vec(cfg.fetchGroupBlocks, Bool()))
    val blockMetaOffset   = Input(Vec(cfg.fetchGroupBlocks, UInt(cfg.cfiOffsetBits.W)))
    val blockMetaType     = Input(Vec(cfg.fetchGroupBlocks, UInt(CfiType.width.W)))
    val blockMetaTarget   = Input(Vec(cfg.fetchGroupBlocks, UInt(cfg.addrWidth.W)))
    val blockMetaTaken    = Input(Vec(cfg.fetchGroupBlocks, Bool()))
    val conditionalValid  = Input(Bool())
    val conditionalBlock  = Input(UInt(1.W))
    val conditionalOffset = Input(UInt(cfg.cfiOffsetBits.W))
    val conditionalTaken  = Input(Bool())
    val indirectValid     = Input(Bool())
    val indirectBlock     = Input(UInt(1.W))
    val indirectOffset    = Input(UInt(cfg.cfiOffsetBits.W))
    val indirectTarget    = Input(UInt(cfg.addrWidth.W))

    val preValid        = Output(Vec(FetchWidth.frontend, Bool()))
    val preInst         = Output(Vec(FetchWidth.frontend, UInt(32.W)))
    val preType         = Output(Vec(FetchWidth.frontend, UInt(CfiType.width.W)))
    val preRasAction    = Output(Vec(FetchWidth.frontend, UInt(RasAction.width.W)))
    val preReturn       = Output(Vec(FetchWidth.frontend, Bool()))
    val preDirectValid  = Output(Vec(FetchWidth.frontend, Bool()))
    val preDirectTarget = Output(Vec(FetchWidth.frontend, UInt(cfg.addrWidth.W)))

    val checkedValid     = Output(Vec(FetchWidth.frontend, Bool()))
    val checkedTaken     = Output(Vec(FetchWidth.frontend, Bool()))
    val checkedTarget    = Output(Vec(FetchWidth.frontend, UInt(cfg.addrWidth.W)))
    val correction       = Output(Bool())
    val correctionReason = Output(UInt(IfuCorrectionReason.width.W))
    val correctionTarget = Output(UInt(cfg.addrWidth.W))
  })

  val predecode = Module(new PredecodeStage(cfg))
  val checker   = Module(new PredictionChecker(cfg))

  predecode.io.in := 0.U.asTypeOf(predecode.io.in)
  for (lane <- 0 until FetchWidth.frontend) {
    val aligned = predecode.io.in.insts(lane)
    aligned.valid                     := io.laneValid(lane)
    aligned.bits.token.tag.index      := 0.U
    aligned.bits.token.tag.generation := 1.U
    aligned.bits.token.streamEpoch    := 0.U
    aligned.bits.sequence             := 7.U
    aligned.bits.instOrdinal          := lane.U
    aligned.bits.pc                   := io.lanePc(lane)
    aligned.bits.rawInst              := io.laneRaw(lane)
    aligned.bits.isRvc                := io.laneRvc(lane)
    aligned.bits.instLen              := Mux(io.laneRvc(lane), 2.U, 4.U)
    aligned.bits.lastInFtqEntry       := io.laneLast(lane)
    aligned.bits.exception.valid      := io.laneException(lane)
    aligned.bits.exception.cause      := 1.U
    aligned.bits.exception.tval       := io.lanePc(lane)
  }

  checker.io.in                             := predecode.io.out
  checker.io.view                           := 0.U.asTypeOf(checker.io.view)
  checker.io.view.valid                     := io.viewValid
  checker.io.view.bits.token.tag.index      := 0.U
  checker.io.view.bits.token.tag.generation := 1.U
  checker.io.view.bits.token.streamEpoch    := 0.U
  checker.io.view.bits.sequence             := 7.U
  checker.io.view.bits.startPc              := io.startPc
  checker.io.view.bits.blockCount           := cfg.fetchGroupBlocks.U
  for (block <- 0 until cfg.fetchGroupBlocks) {
    val finalMeta = checker.io.view.bits.prediction.blockPred(block)
    finalMeta.valid                            := io.blockMetaValid(block)
    finalMeta.cfiOffset                        := io.blockMetaOffset(block)
    finalMeta.cfiType                          := io.blockMetaType(block)
    finalMeta.target                           := io.blockMetaTarget(block)
    finalMeta.rasAction                        := RasAction.none
    checker.io.view.bits.fastBlockPred(block)  := finalMeta
    checker.io.view.bits.fastBlockTaken(block) := io.blockMetaTaken(block)
  }

  val conditional = checker.io.view.bits.prediction.conditionalPred(0)
  conditional.valid                                        := io.conditionalValid
  conditional.bits.blockIndex                              := io.conditionalBlock
  conditional.bits.cfiOffset                               := io.conditionalOffset
  conditional.bits.taken                                   := io.conditionalTaken
  conditional.bits.provider                                := PredictorProvider.tageBase
  conditional.bits.alternate                               := PredictorProvider.none
  conditional.bits.confidence                              := 2.U
  conditional.bits.alternateTaken                          := false.B
  checker.io.view.bits.prediction.conditionalPred(1).valid := false.B

  val indirect = checker.io.view.bits.prediction.indirectPred(0)
  indirect.valid           := io.indirectValid
  indirect.bits.blockIndex := io.indirectBlock
  indirect.bits.cfiOffset  := io.indirectOffset
  indirect.bits.target     := io.indirectTarget
  indirect.bits.provider   := PredictorProvider.ittageBase
  indirect.bits.alternate  := PredictorProvider.none
  indirect.bits.confidence := 2.U

  for (lane <- 0 until FetchWidth.frontend) {
    val pre     = predecode.io.out.insts(lane)
    val checked = checker.io.out.insts(lane)
    io.preValid(lane)        := pre.valid
    io.preInst(lane)         := pre.bits.inst
    io.preType(lane)         := pre.bits.cfi.cfiType
    io.preRasAction(lane)    := pre.bits.cfi.rasAction
    io.preReturn(lane)       := pre.bits.cfi.canonicalReturn
    io.preDirectValid(lane)  := pre.bits.cfi.directTargetValid
    io.preDirectTarget(lane) := pre.bits.cfi.directTarget
    io.checkedValid(lane)    := checked.valid
    io.checkedTaken(lane)    := checked.bits.prediction.taken
    io.checkedTarget(lane)   := checked.bits.prediction.target
  }
  io.correction := checker.io.out.control.redirectValid
  io.correctionReason := checker.io.out.control.reason
  io.correctionTarget := checker.io.out.control.redirectTarget
}

object PredecodePredictionCheckerSpec {
  private val Nop    = BigInt("00000013", 16)
  private val Branch = BigInt("00000463", 16) // beq x0, x0, +8
  private val Jal    = BigInt("008000ef", 16) // jal x1, +8
  private val Call   = BigInt("000100e7", 16) // jalr x1, 0(x2)
  private val Ret    = BigInt("00008067", 16) // jalr x0, 0(x1)

  def main(args: Array[String]): Unit = {
    simulate(new PredecodePredictionCheckerHarness) { dut =>
      def clear(): Unit = {
        for (lane  <- 0 until FetchWidth.frontend) {
          dut.io.laneValid(lane).poke(false)
          dut.io.lanePc(lane).poke(0)
          dut.io.laneRaw(lane).poke(Nop)
          dut.io.laneRvc(lane).poke(false)
          dut.io.laneException(lane).poke(false)
          dut.io.laneLast(lane).poke(false)
        }
        dut.io.viewValid.poke(true)
        dut.io.startPc.poke(0x1000)
        for (block <- dut.io.blockMetaValid.indices) {
          dut.io.blockMetaValid(block).poke(false)
          dut.io.blockMetaOffset(block).poke(0)
          dut.io.blockMetaType(block).poke(CfiType.none)
          dut.io.blockMetaTarget(block).poke(0)
          dut.io.blockMetaTaken(block).poke(false)
        }
        dut.io.conditionalValid.poke(false)
        dut.io.conditionalBlock.poke(0)
        dut.io.conditionalOffset.poke(0)
        dut.io.conditionalTaken.poke(false)
        dut.io.indirectValid.poke(false)
        dut.io.indirectBlock.poke(0)
        dut.io.indirectOffset.poke(0)
        dut.io.indirectTarget.poke(0)
      }

      clear()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // RVC expansion and structured branch/JAL/JALR metadata are independent of prediction.
      val pcs  = Seq(0x1000, 0x1002, 0x1006, 0x100a)
      val inst = Seq(BigInt(1), Branch, Jal, Call)
      for (lane <- 0 until FetchWidth.frontend) {
        dut.io.laneValid(lane).poke(true)
        dut.io.lanePc(lane).poke(pcs(lane))
        dut.io.laneRaw(lane).poke(inst(lane))
        dut.io.laneRvc(lane).poke(lane == 0)
      }
      dut.io.preInst(0).expect(Nop)
      dut.io.preType(0).expect(CfiType.none)
      dut.io.preType(1).expect(CfiType.branch)
      dut.io.preDirectTarget(1).expect(0x100a)
      dut.io.preType(2).expect(CfiType.jal)
      dut.io.preDirectTarget(2).expect(0x100e)
      dut.io.preRasAction(2).expect(RasAction.push)
      dut.io.preType(3).expect(CfiType.jalr)
      dut.io.preDirectValid(3).expect(false)
      dut.io.preRasAction(3).expect(RasAction.push)

      clear()
      dut.io.laneValid(0).poke(true)
      dut.io.lanePc(0).poke(0x2000)
      dut.io.laneRaw(0).poke(Ret)
      dut.io.startPc.poke(0x2000)
      dut.io.preType(0).expect(CfiType.jalr)
      dut.io.preReturn(0).expect(true)
      dut.io.preRasAction(0).expect(RasAction.pop)

      // An exception is retained at its lane and masks all younger instructions.
      clear()
      for (lane <- 0 until 3) {
        dut.io.laneValid(lane).poke(true)
        dut.io.lanePc(lane).poke(0x3000 + lane * 4)
      }
      dut.io.startPc.poke(0x3000)
      dut.io.laneException(1).poke(true)
      dut.io.preValid(0).expect(true)
      dut.io.preValid(1).expect(true)
      dut.io.preValid(2).expect(false)
      dut.io.checkedValid(2).expect(false)

      // A JAL missed by the BTB is corrected from its static immediate target.
      clear()
      dut.io.laneValid(0).poke(true)
      dut.io.lanePc(0).poke(0x4000)
      dut.io.laneRaw(0).poke(Jal)
      dut.io.startPc.poke(0x4000)
      dut.io.correction.expect(true)
      dut.io.correctionReason.expect(IfuCorrectionReason.btbMissCfi)
      dut.io.correctionTarget.expect(0x4008)

      // Offset and type mismatches use distinct static correction reasons.
      dut.io.blockMetaValid(0).poke(true)
      dut.io.blockMetaOffset(0).poke(1)
      dut.io.blockMetaType(0).poke(CfiType.jal)
      dut.io.blockMetaTarget(0).poke(0x4008)
      dut.io.correctionReason.expect(IfuCorrectionReason.cfiOffsetMismatch)
      dut.io.blockMetaOffset(0).poke(0)
      dut.io.blockMetaType(0).poke(CfiType.branch)
      dut.io.correctionReason.expect(IfuCorrectionReason.cfiTypeMismatch)

      // A taken direct-target mismatch is corrected to the decoded immediate.
      dut.io.blockMetaType(0).poke(CfiType.jal)
      dut.io.blockMetaTarget(0).poke(0x4100)
      dut.io.blockMetaTaken(0).poke(true)
      dut.io.correction.expect(true)
      dut.io.correctionReason.expect(IfuCorrectionReason.directTargetMismatch)
      dut.io.correctionTarget.expect(0x4008)

      // Conditional direction only masks from the prediction; it is never manufactured as an IFU actual result.
      clear()
      dut.io.startPc.poke(0x5000)
      dut.io.laneValid(0).poke(true)
      dut.io.laneValid(1).poke(true)
      dut.io.lanePc(0).poke(0x5000)
      dut.io.lanePc(1).poke(0x5004)
      dut.io.laneRaw(0).poke(Branch)
      dut.io.blockMetaValid(0).poke(true)
      dut.io.blockMetaOffset(0).poke(0)
      dut.io.blockMetaType(0).poke(CfiType.branch)
      dut.io.blockMetaTarget(0).poke(0x5008)
      dut.io.conditionalValid.poke(true)
      dut.io.conditionalOffset.poke(0)
      dut.io.conditionalTaken.poke(true)
      dut.io.correction.expect(false)
      dut.io.checkedTaken(0).expect(true)
      dut.io.checkedValid(1).expect(false)

      dut.io.conditionalTaken.poke(false)
      dut.io.correction.expect(false)
      dut.io.checkedTaken(0).expect(false)
      dut.io.checkedValid(1).expect(true)

      // A not-predicted conditional may precede a predicted JAL in one block. It falls through without forcing an
      // IFU recovery, while the later JAL still terminates the packet at its predicted target.
      clear()
      dut.io.startPc.poke(0x5000)
      dut.io.laneValid(0).poke(true)
      dut.io.laneValid(1).poke(true)
      dut.io.lanePc(0).poke(0x5000)
      dut.io.lanePc(1).poke(0x5004)
      dut.io.laneRaw(0).poke(Branch)
      dut.io.laneRaw(1).poke(Jal)
      dut.io.blockMetaValid(0).poke(true)
      dut.io.blockMetaOffset(0).poke(2)
      dut.io.blockMetaType(0).poke(CfiType.jal)
      dut.io.blockMetaTarget(0).poke(0x500c)
      dut.io.blockMetaTaken(0).poke(true)
      dut.io.correction.expect(false)
      dut.io.checkedValid(0).expect(true)
      dut.io.checkedTaken(0).expect(false)
      dut.io.checkedValid(1).expect(true)
      dut.io.checkedTaken(1).expect(true)
      dut.io.checkedTarget(1).expect(0x500c)

      // A JALR target comes only from prediction metadata; the checker has no static target to compare against it.
      clear()
      dut.io.startPc.poke(0x6000)
      dut.io.laneValid(0).poke(true)
      dut.io.laneValid(1).poke(true)
      dut.io.lanePc(0).poke(0x6000)
      dut.io.lanePc(1).poke(0x6004)
      dut.io.laneRaw(0).poke(Call)
      dut.io.blockMetaValid(0).poke(true)
      dut.io.blockMetaOffset(0).poke(0)
      dut.io.blockMetaType(0).poke(CfiType.jalr)
      dut.io.blockMetaTarget(0).poke(0x6100)
      dut.io.indirectValid.poke(true)
      dut.io.indirectOffset.poke(0)
      dut.io.indirectTarget.poke(0x6200)
      dut.io.correction.expect(false)
      dut.io.checkedTaken(0).expect(true)
      dut.io.checkedTarget(0).expect(0x6200)
      dut.io.checkedValid(1).expect(false)
    }

    println("PredecodePredictionCheckerSpec: PASS")
  }
}
