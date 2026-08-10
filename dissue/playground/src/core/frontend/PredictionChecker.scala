package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{Cat, Mux1H, PopCount, Valid}
import top.config.FrontendConfig
import top.core.bundle.CfiType
import top.core.frontend.bundle._

/** Static prediction validation. Conditional outcomes and JALR targets remain backend-owned. */
class PredictionChecker(cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val in   = Input(new PredecodedInstructionGroup(cfg))
    val view = Input(Valid(new FtqIfuView(cfg)))
    val out  = Output(new CheckedInstructionGroup(cfg))
  })

  private val blockIndexWidth = math.max(chisel3.util.log2Ceil(cfg.fetchGroupBlocks), 1)

  io.out := 0.U.asTypeOf(new CheckedInstructionGroup(cfg))
  val stopBefore = Wire(Vec(cfg.frontendWidth, Bool()))
  val correction = Wire(Vec(cfg.frontendWidth, Bool()))
  val terminal   = Wire(Vec(cfg.frontendWidth, Bool()))
  val reasons    = Wire(Vec(cfg.frontendWidth, UInt(IfuCorrectionReason.width.W)))
  val redirect   = Wire(Vec(cfg.frontendWidth, UInt(cfg.addrWidth.W)))
  stopBefore(0) := false.B

  for (lane <- 0 until cfg.frontendWidth) {
    val predecoded       = io.in.insts(lane).bits
    val aligned          = predecoded.aligned
    val cfi              = predecoded.cfi
    val firstBlockBase   = Cat(
      io.view.bits.startPc(cfg.addrWidth - 1, cfg.icache.offsetBits),
      0.U(cfg.icache.offsetBits.W)
    )
    val relativePc       = aligned.pc - firstBlockBase
    val blockIndex       = (relativePc >> cfg.icache.offsetBits)(blockIndexWidth - 1, 0)
    val cfiOffset        = aligned.pc(cfg.icache.offsetBits - 1, 1)
    val finalMeta        = io.view.bits.prediction.blockPred(blockIndex)
    val conditionalMatch = VecInit(io.view.bits.prediction.conditionalPred.map { candidate =>
      candidate.valid && candidate.bits.blockIndex === blockIndex && candidate.bits.cfiOffset === cfiOffset
    })
    val conditional      = Mux1H(conditionalMatch, io.view.bits.prediction.conditionalPred.map(_.bits))
    val indirectMatch    = VecInit(io.view.bits.prediction.indirectPred.map { candidate =>
      candidate.valid && candidate.bits.blockIndex === blockIndex && candidate.bits.cfiOffset === cfiOffset
    })
    val indirect         = Mux1H(indirectMatch, io.view.bits.prediction.indirectPred.map(_.bits))
    val predictedAtPc    = finalMeta.valid && finalMeta.cfiOffset === cfiOffset
    val typeMatches      = finalMeta.cfiType === cfi.cfiType
    val metadataMatch    = cfi.valid && predictedAtPc && typeMatches
    val isConditional    = cfi.cfiType === CfiType.branch
    val isJal            = cfi.cfiType === CfiType.jal
    val isJalr           = cfi.cfiType === CfiType.jalr
    val genericIndirect  = isJalr && !cfi.canonicalReturn
    val candidateMissing = metadataMatch &&
      ((isConditional && !conditionalMatch.asUInt.orR) || (genericIndirect && !indirectMatch.asUInt.orR))
    val predictionHit    = metadataMatch && !candidateMissing

    val predictedTaken  = Mux(
      isConditional,
      conditionalMatch.asUInt.orR && conditional.taken,
      predictionHit && (isJal || isJalr)
    )
    val predictedTarget = Mux(
      genericIndirect && indirectMatch.asUInt.orR,
      indirect.target,
      finalMeta.target
    )

    val falseHit        = !cfi.valid && predictedAtPc
    // A block may contain an unpredicted conditional before a later predicted CFI. Treat that branch as the normal
    // not-taken fallback; only a JAL needs an immediate IFU correction because its target is statically known.
    val offsetMismatch  = isJal && finalMeta.valid && finalMeta.cfiOffset =/= cfiOffset
    val typeMismatch    = cfi.valid && predictedAtPc && !typeMatches
    val btbMissCfi      = isJal && !finalMeta.valid
    val directMismatch  = predictionHit && cfi.directTargetValid && predictedTaken &&
      predictedTarget =/= cfi.directTarget
    val needsCorrection = !aligned.exception.valid &&
      (falseHit || offsetMismatch || typeMismatch || btbMissCfi || candidateMissing || directMismatch)

    reasons(lane) := Mux(
      falseHit,
      IfuCorrectionReason.btbFalseHit,
      Mux(
        offsetMismatch,
        IfuCorrectionReason.cfiOffsetMismatch,
        Mux(
          typeMismatch,
          IfuCorrectionReason.cfiTypeMismatch,
          Mux(
            candidateMissing,
            IfuCorrectionReason.candidateOverflow,
            Mux(directMismatch, IfuCorrectionReason.directTargetMismatch, IfuCorrectionReason.btbMissCfi)
          )
        )
      )
    )

    val preserveTaken   = directMismatch && predictedTaken
    val correctedTaken  = Mux(
      needsCorrection,
      isJal || preserveTaken,
      predictedTaken
    )
    val correctedTarget = Mux(
      needsCorrection,
      Mux(isJal || preserveTaken, cfi.directTarget, predecoded.fallThrough),
      predictedTarget
    )
    val correctedHit    = Mux(needsCorrection, isJal || preserveTaken, predictionHit)

    val laneValid = io.in.insts(lane).valid && io.view.valid && !stopBefore(lane)
    correction(lane) := laneValid && needsCorrection
    redirect(lane)   := correctedTarget
    terminal(lane)   := laneValid &&
      (aligned.exception.valid || correctedTaken || needsCorrection || aligned.lastInFtqEntry)

    io.out.insts(lane).valid                  := laneValid
    io.out.insts(lane).bits.predecoded        := predecoded
    io.out.insts(lane).bits.prediction.hit    := correctedHit
    io.out.insts(lane).bits.prediction.taken  := correctedTaken
    io.out.insts(lane).bits.prediction.target := correctedTarget
    io.out.insts(lane).bits.prediction.npc    := Mux(correctedTaken, correctedTarget, predecoded.fallThrough)

    if (lane + 1 < cfg.frontendWidth) {
      stopBefore(lane + 1) := stopBefore(lane) ||
        (laneValid && (aligned.exception.valid || correctedTaken || needsCorrection))
    }

    when(laneValid) {
      assert(FetchToken.matches(aligned.token, io.view.bits.token))
      assert(blockIndex < cfg.fetchGroupBlocks.U)
    }
  }

  val correctionOH = chisel3.util.PriorityEncoderOH(correction.asUInt).asBools
  val selected     = Mux1H(correctionOH, io.in.insts.map(_.bits))
  io.out.control.token          := io.in.insts(0).bits.aligned.token
  io.out.control.redirectValid  := correction.asUInt.orR
  io.out.control.redirectTarget := Mux1H(correctionOH, redirect)
  io.out.control.reason         := Mux1H(correctionOH, reasons)
  io.out.control.cfiOrdinal     := selected.aligned.instOrdinal
  io.out.control.cfiPc          := selected.aligned.pc
  io.out.control.cfiInstLen     := selected.aligned.instLen
  io.out.control.cfi            := selected.cfi
  io.out.control.emissionDone   := terminal.asUInt.orR

  var emittedInsts = 0.U(cfg.ftqInstCountBits.W)
  for (lane <- 0 until cfg.frontendWidth) {
    emittedInsts = Mux(
      io.out.insts(lane).valid,
      io.out.insts(lane).bits.predecoded.aligned.instOrdinal + 1.U,
      emittedInsts
    )
  }
  io.out.control.emittedInsts := emittedInsts

  when(io.out.insts(0).valid) {
    assert(io.view.valid)
  }
  for (lane <- 1 until cfg.frontendWidth) {
    when(io.out.insts(lane).valid) {
      assert(io.out.insts(lane - 1).valid)
    }
  }
}
