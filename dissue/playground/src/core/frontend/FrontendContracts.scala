package top.core.frontend.bundle

import chisel3._
import chisel3.util.{log2Ceil, Cat, Valid, ValidIO}
import top.config.{FrontendConfig, FrontendPayloadConfig}
import top.core.bundle.{CfiType, FetchException}

class FetchTargetTag(cfg: FrontendPayloadConfig) extends Bundle {
  val index      = UInt(cfg.ftqIndexBits.W)
  val generation = UInt(cfg.ftqGenerationBits.W)
}

class FetchToken(cfg: FrontendConfig) extends Bundle {
  val tag         = new FetchTargetTag(cfg.payload)
  val streamEpoch = UInt(cfg.fetchEpochBits.W)
}

class FetchAddressRequest(cfg: FrontendConfig) extends Bundle {
  val startPc = UInt(cfg.addrWidth.W)
}

class BpuRequest(cfg: FrontendConfig) extends Bundle {
  val token   = new FetchToken(cfg)
  val startPc = UInt(cfg.addrWidth.W)
}

class ICacheFetchReq(cfg: FrontendConfig) extends Bundle {
  val token      = new FetchToken(cfg)
  val startPc    = UInt(cfg.addrWidth.W)
  val blockAddr  = Vec(cfg.fetchGroupBlocks, UInt(cfg.addrWidth.W))
  val blockValid = Vec(cfg.fetchGroupBlocks, Bool())
}

class ICacheBlockData(cfg: FrontendConfig) extends Bundle {
  val data      = UInt((cfg.fetchBytes * 8).W)
  val hit       = Bool()
  val exception = new FetchException(cfg.addrWidth)
}

class ICacheFetchResp(cfg: FrontendConfig) extends Bundle {
  val token  = new FetchToken(cfg)
  val blocks = Vec(cfg.fetchGroupBlocks, Valid(new ICacheBlockData(cfg)))
}

/** Registered tag/data lookup result exposed as a semantic observation boundary. */
class ICacheLookupResult(cfg: FrontendConfig) extends Bundle {
  val token       = new FetchToken(cfg)
  val blockAddr   = Vec(cfg.fetchGroupBlocks, UInt(cfg.addrWidth.W))
  val blockValid  = Vec(cfg.fetchGroupBlocks, Bool())
  val hitMask     = UInt(cfg.fetchGroupBlocks.W)
  val missingMask = UInt(cfg.fetchGroupBlocks.W)
}

object FetchToken {
  def matches(left: FetchToken, right: FetchToken): Bool =
    left.tag.index === right.tag.index &&
      left.tag.generation === right.tag.generation &&
      left.streamEpoch === right.streamEpoch

}

class BtbCfiMeta(cfg: FrontendConfig) extends Bundle {
  val valid     = Bool()
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
  val target    = UInt(cfg.addrWidth.W)
  val rasAction = UInt(RasAction.width.W)
}

class BpuFastResult(cfg: FrontendConfig) extends Bundle {
  val token             = new FetchToken(cfg)
  val startPc           = UInt(cfg.addrWidth.W)
  val blockPred         = Vec(cfg.fetchGroupBlocks, new BtbCfiMeta(cfg))
  val blockTaken        = Vec(cfg.fetchGroupBlocks, Bool())
  val predictedNextPc   = UInt(cfg.addrWidth.W)
  val blockCount        = UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W)
  val historyCheckpoint = UInt(cfg.historyBits.W)
  val pathCheckpoint    = UInt(cfg.historyBits.W)
  val rasCheckpoint     = new RasCheckpoint(cfg.addrWidth)
}

class ConditionalPrediction(cfg: FrontendConfig) extends Bundle {
  val blockIndex     = UInt(math.max(log2Ceil(cfg.fetchGroupBlocks), 1).W)
  val cfiOffset      = UInt(cfg.cfiOffsetBits.W)
  val taken          = Bool()
  val provider       = UInt(PredictorConstants.providerBits.W)
  val alternate      = UInt(PredictorConstants.providerBits.W)
  val confidence     = UInt(PredictorConstants.confidenceBits.W)
  val alternateTaken = Bool()
}

class IndirectPrediction(cfg: FrontendConfig) extends Bundle {
  val blockIndex = UInt(math.max(log2Ceil(cfg.fetchGroupBlocks), 1).W)
  val cfiOffset  = UInt(cfg.cfiOffsetBits.W)
  val target     = UInt(cfg.addrWidth.W)
  val provider   = UInt(PredictorConstants.providerBits.W)
  val alternate  = UInt(PredictorConstants.providerBits.W)
  val confidence = UInt(PredictorConstants.confidenceBits.W)
}

/** Control-path prediction view. Predictor checkpoints and table-training state are intentionally separate. */
class PredictionSummary(cfg: FrontendConfig) extends Bundle {
  val blockPred       = Vec(cfg.fetchGroupBlocks, new BtbCfiMeta(cfg))
  val conditionalPred = Vec(cfg.maxConditionalCandidatesPerGroup, Valid(new ConditionalPrediction(cfg)))
  val indirectPred    = Vec(cfg.maxIndirectCandidatesPerGroup, Valid(new IndirectPrediction(cfg)))
  val predictedNextPc = UInt(cfg.addrWidth.W)
}

object PredictionSummary {
  def fromFastPrediction(
    predictions:     Vec[FetchPred],
    predictedNextPc: UInt,
    cfg:             FrontendConfig
  ): PredictionSummary = {
    val summary = Wire(new PredictionSummary(cfg))
    summary := 0.U.asTypeOf(new PredictionSummary(cfg))
    for (block <- 0 until cfg.fetchGroupBlocks) {
      summary.blockPred(block).valid     := predictions(block).valid
      summary.blockPred(block).cfiOffset := predictions(block).cfiOffset
      summary.blockPred(block).cfiType   := predictions(block).cfiType
      summary.blockPred(block).target    := predictions(block).target
      summary.blockPred(block).rasAction := RasAction.none
    }
    summary.predictedNextPc := predictedNextPc
    summary
  }

}

class PredictorTrainMeta(cfg: FrontendConfig) extends Bundle {
  val blockIndex = UInt(math.max(log2Ceil(cfg.fetchGroupBlocks), 1).W)
  val cfiOffset  = UInt(cfg.cfiOffsetBits.W)
  val context    = new PredictorTrainingContext(cfg.bpu)
}

class BpuFinalResult(cfg: FrontendConfig) extends Bundle {
  val token            = new FetchToken(cfg)
  val startPc          = UInt(cfg.addrWidth.W)
  val fastNextPc       = UInt(cfg.addrWidth.W)
  val finalNextPc      = UInt(cfg.addrWidth.W)
  val blockCount       = UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W)
  val finalPrediction  = new PredictionSummary(cfg)
  val overrideFastPath = Bool()
  val trainMeta        = Vec(cfg.fetchGroupBlocks, Valid(new PredictorTrainMeta(cfg)))
}

class BpuRecover(cfg: FrontendConfig) extends Bundle {
  val recovery          = new FrontendRecovery(cfg)
  val checkpointValid   = Bool()
  val historyCheckpoint = UInt(cfg.historyBits.W)
  val pathCheckpoint    = UInt(cfg.historyBits.W)
  val rasCheckpoint     = new RasCheckpoint(cfg.addrWidth)
}

object FtqEntryPhase extends ChiselEnum {
  val free, reserved, fastReady, finalReady, fetchIssued, dataReady, resident = Value
}

class FtqReserveRequest(cfg: FrontendConfig) extends Bundle {
  val startPc = UInt(cfg.addrWidth.W)
}

class FtqFetchTarget(cfg: FrontendConfig) extends Bundle {
  val token             = new FetchToken(cfg)
  val sequence          = UInt(cfg.ftqSequenceBits.W)
  val startPc           = UInt(cfg.addrWidth.W)
  val blockCount        = UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W)
  val fastNextPc        = UInt(cfg.addrWidth.W)
  val finalNextPc       = UInt(cfg.addrWidth.W)
  val fastBlockPred     = Vec(cfg.fetchGroupBlocks, new BtbCfiMeta(cfg))
  val fastBlockTaken    = Vec(cfg.fetchGroupBlocks, Bool())
  val prediction        = new PredictionSummary(cfg)
  val trainMeta         = Vec(cfg.fetchGroupBlocks, Valid(new PredictorTrainMeta(cfg)))
  val historyCheckpoint = UInt(cfg.historyBits.W)
  val pathCheckpoint    = UInt(cfg.historyBits.W)
  val rasCheckpoint     = new RasCheckpoint(cfg.addrWidth)
}

object ICacheFetchReq {
  def fromFtqTarget(target: FtqFetchTarget, cfg: FrontendConfig): ICacheFetchReq = {
    val request        = Wire(new ICacheFetchReq(cfg))
    val firstBlockAddr = Cat(
      target.startPc(cfg.addrWidth - 1, cfg.icache.offsetBits),
      0.U(cfg.icache.offsetBits.W)
    )

    request.token   := target.token
    request.startPc := target.startPc
    for (block <- 0 until cfg.fetchGroupBlocks) {
      request.blockValid(block) := block.U < target.blockCount
      request.blockAddr(block)  := firstBlockAddr +% (block * cfg.fetchBytes).U(cfg.addrWidth.W)
    }
    request
  }
}

class FtqFetchComplete(cfg: FrontendConfig) extends Bundle {
  val token = new FetchToken(cfg)
}

class FtqIfuEmission(cfg: FrontendConfig) extends Bundle {
  val token           = new FetchToken(cfg)
  val instOrdinal     = UInt(cfg.ftqInstCountBits.W)
  val terminatesEntry = Bool()
}

class FtqRetire(cfg: FrontendConfig) extends Bundle {
  val tag             = new FetchTargetTag(cfg.payload)
  val instOrdinal     = UInt(cfg.ftqInstCountBits.W)
  val retired         = Bool()
  val trap            = Bool()
  val cfiValid        = Bool()
  val pc              = UInt(cfg.addrWidth.W)
  val cfiType         = UInt(CfiType.width.W)
  val taken           = Bool()
  val target          = UInt(cfg.addrWidth.W)
  val instLen         = UInt(3.W)
  val rasAction       = UInt(RasAction.width.W)
  val canonicalReturn = Bool()
}

class FtqPredictionView(cfg: FrontendConfig) extends Bundle {
  val token           = new FetchToken(cfg)
  val startPc         = UInt(cfg.addrWidth.W)
  val blockCount      = UInt(chisel3.util.log2Ceil(cfg.fetchGroupBlocks + 1).W)
  val predictedNextPc = UInt(cfg.addrWidth.W)
  val prediction      = new PredictionSummary(cfg)
}

/** Read-only IFU view. Cache data never carries these fields. */
class FtqIfuView(cfg: FrontendConfig) extends Bundle {
  val token          = new FetchToken(cfg)
  val sequence       = UInt(cfg.ftqSequenceBits.W)
  val startPc        = UInt(cfg.addrWidth.W)
  val blockCount     = UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W)
  val fastNextPc     = UInt(cfg.addrWidth.W)
  val finalNextPc    = UInt(cfg.addrWidth.W)
  val fastBlockPred  = Vec(cfg.fetchGroupBlocks, new BtbCfiMeta(cfg))
  val fastBlockTaken = Vec(cfg.fetchGroupBlocks, Bool())
  val prediction     = new PredictionSummary(cfg)
}

/** Strictly ordered ICache group buffered before alignment. */
class FetchBlockGroup(cfg: FrontendConfig) extends Bundle {
  val token  = new FetchToken(cfg)
  val blocks = Vec(cfg.fetchGroupBlocks, Valid(new ICacheBlockData(cfg)))
}

class AlignedInstruction(cfg: FrontendConfig) extends Bundle {
  val token          = new FetchToken(cfg)
  val sequence       = UInt(cfg.ftqSequenceBits.W)
  val instOrdinal    = UInt(cfg.ftqInstCountBits.W)
  val pc             = UInt(cfg.addrWidth.W)
  val rawInst        = UInt(32.W)
  val isRvc          = Bool()
  val instLen        = UInt(3.W)
  val lastInFtqEntry = Bool()
  val exception      = new FetchException(cfg.addrWidth)
}

class AlignedInstructionGroup(cfg: FrontendConfig) extends Bundle {
  val insts = Vec(cfg.frontendWidth, Valid(new AlignedInstruction(cfg)))
}

class CfiInfo(cfg: FrontendConfig) extends Bundle {
  val valid             = Bool()
  val cfiType           = UInt(CfiType.width.W)
  val rasAction         = UInt(RasAction.width.W)
  val canonicalReturn   = Bool()
  val directTargetValid = Bool()
  val directTarget      = UInt(cfg.addrWidth.W)
}

class PredecodedInstruction(cfg: FrontendConfig) extends Bundle {
  val aligned     = new AlignedInstruction(cfg)
  val inst        = UInt(32.W)
  val cfi         = new CfiInfo(cfg)
  val fallThrough = UInt(cfg.addrWidth.W)
}

class PredecodedInstructionGroup(cfg: FrontendConfig) extends Bundle {
  val insts = Vec(cfg.frontendWidth, Valid(new PredecodedInstruction(cfg)))
}

object IfuCorrectionReason {
  val width = 3

  val none                 = 0.U(width.W)
  val btbMissCfi           = 1.U(width.W)
  val btbFalseHit          = 2.U(width.W)
  val cfiOffsetMismatch    = 3.U(width.W)
  val cfiTypeMismatch      = 4.U(width.W)
  val directTargetMismatch = 5.U(width.W)
  val candidateOverflow    = 6.U(width.W)
}

/** Prediction verdict needed by execution validation. */
class CheckedPrediction(cfg: FrontendConfig) extends Bundle {
  val hit    = Bool()
  val taken  = Bool()
  val target = UInt(cfg.addrWidth.W)
  val npc    = UInt(cfg.addrWidth.W)
}

class CheckedInstruction(cfg: FrontendConfig) extends Bundle {
  val predecoded = new PredecodedInstruction(cfg)
  val prediction = new CheckedPrediction(cfg)
}

class IfuControlResult(cfg: FrontendConfig) extends Bundle {
  val token          = new FetchToken(cfg)
  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val reason         = UInt(IfuCorrectionReason.width.W)
  val cfiOrdinal     = UInt(cfg.ftqInstCountBits.W)
  val cfiPc          = UInt(cfg.addrWidth.W)
  val cfiInstLen     = UInt(3.W)
  val cfi            = new CfiInfo(cfg)
  val emittedInsts   = UInt(cfg.ftqInstCountBits.W)
  val emissionDone   = Bool()
}

class CheckedInstructionGroup(cfg: FrontendConfig) extends Bundle {
  val insts   = Vec(cfg.frontendWidth, Valid(new CheckedInstruction(cfg)))
  val control = new IfuControlResult(cfg)
}

object FrontendRecoveryKind extends ChiselEnum {
  val backend, ifuCorrection, bpuOverride, trap, reset = Value
}

class FrontendRecovery(cfg: FrontendConfig) extends Bundle {
  val kind                  = FrontendRecoveryKind()
  val tokenValid            = Bool()
  val token                 = new FetchToken(cfg)
  val targetPc              = UInt(cfg.addrWidth.W)
  val cfiOrdinal            = UInt(cfg.ftqInstCountBits.W)
  val survivingInsts        = UInt(cfg.ftqInstCountBits.W)
  val actualCfiValid        = Bool()
  val actualCfiType         = UInt(CfiType.width.W)
  val actualCfiPc           = UInt(cfg.addrWidth.W)
  val actualInstLen         = UInt(3.W)
  val actualRasAction       = UInt(RasAction.width.W)
  val actualCanonicalReturn = Bool()
  val actualTaken           = Bool()
  val actualTarget          = UInt(cfg.addrWidth.W)
  val dropTargetEntry       = Bool()
}

object FrontendRecoveryArbiter {
  def select(
    backend: ValidIO[FrontendRecovery],
    ifu:     ValidIO[FrontendRecovery],
    bpu:     ValidIO[FrontendRecovery],
    cfg:     FrontendConfig
  ): ValidIO[FrontendRecovery] = {
    val selected = Wire(Valid(new FrontendRecovery(cfg)))
    selected := bpu
    when(ifu.valid) {
      selected := ifu
    }
    when(backend.valid) {
      selected := backend
    }
    selected
  }
}
