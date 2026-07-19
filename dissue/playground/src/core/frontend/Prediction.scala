package top.core.frontend.bundle

import chisel3._
import chisel3.util.{MuxLookup, log2Ceil}
import top.config.ICacheConfig
import top.core.bundle.CfiType

object PredictorConstants {
  val commitUpdateWidth = 2
  val providerBits      = 3
  val confidenceBits    = 2
  val historyBits       = 16
  val rasEntries        = 8
  val rasIndexBits      = log2Ceil(rasEntries)
  val rasCountBits      = log2Ceil(rasEntries + 1)
}

object PredictorProvider {
  val none    = 0.U(PredictorConstants.providerBits.W)
  val fastBtb = 1.U(PredictorConstants.providerBits.W)
  val tage    = 2.U(PredictorConstants.providerBits.W)
  val ittage  = 3.U(PredictorConstants.providerBits.W)
}

object RasAction {
  val width = 2

  val none        = 0.U(width.W)
  val push        = 1.U(width.W)
  val pop         = 2.U(width.W)
  val popThenPush = 3.U(width.W)

  def isLink(reg: UInt): Bool =
    reg === 1.U(5.W) || reg === 5.U(5.W)

  def cfiType(inst: UInt): UInt =
    MuxLookup(inst(6, 0), CfiType.none)(
      Seq(
        "b1100011".U -> CfiType.branch,
        "b1101111".U -> CfiType.jal,
        "b1100111".U -> CfiType.jalr
      )
    )

  def action(inst: UInt): UInt = {
    val opcode  = inst(6, 0)
    val rd      = inst(11, 7)
    val rs1     = inst(19, 15)
    val rdLink  = isLink(rd)
    val rs1Link = isLink(rs1)

    Mux(
      opcode === "b1101111".U,
      Mux(rdLink, push, none),
      Mux(
        opcode === "b1100111".U,
        Mux(
          !rdLink && !rs1Link,
          none,
          Mux(
            !rdLink && rs1Link,
            pop,
            Mux(rdLink && !rs1Link, push, Mux(rd === rs1, push, popThenPush))
          )
        ),
        none
      )
    )
  }

  def isCanonicalReturn(inst: UInt): Bool =
    inst(6, 0) === "b1100111".U && inst(11, 7) === 0.U && isLink(inst(19, 15)) && inst(31, 20) === 0.U
}

class FetchPred(cfg: ICacheConfig) extends Bundle {
  require(cfg.fetchBytes >= 2, "fetchBytes must contain at least one halfword")

  val valid     = Bool()
  val taken     = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(log2Ceil(cfg.fetchBytes / 2).W)
  val cfiType   = UInt(CfiType.width.W)
}

class RasCheckpoint(addrWidth: Int = 32) extends Bundle {
  val entries = Vec(PredictorConstants.rasEntries, UInt(addrWidth.W))
  val count   = UInt(PredictorConstants.rasCountBits.W)
}

/** Immutable prediction and recovery data carried with a fetched instruction. */
class PredictionMeta(cfg: ICacheConfig = ICacheConfig()) extends Bundle {
  val sequence       = UInt(cfg.fetchSequenceBits.W)
  val epoch          = UInt(cfg.fetchEpochBits.W)
  val ftqIndex       = UInt(cfg.fetchTargetIndexBits.W)
  val fastPrediction = new FetchPred(cfg)

  val provider       = UInt(PredictorConstants.providerBits.W)
  val alternate      = UInt(PredictorConstants.providerBits.W)
  val confidence     = UInt(PredictorConstants.confidenceBits.W)
  val predictedTarget = UInt(cfg.addrWidth.W)
  val predictedNpc    = UInt(cfg.addrWidth.W)
  val cfiPc           = UInt(cfg.addrWidth.W)
  val cfiType         = UInt(CfiType.width.W)
  val instLen         = UInt(3.W)
  val rasAction       = UInt(RasAction.width.W)
  val rasUsed         = Bool()

  val historyCheckpoint = UInt(PredictorConstants.historyBits.W)
  val pathCheckpoint    = UInt(PredictorConstants.historyBits.W)
  val checkpointValid   = Bool()
  val rasCheckpoint     = new RasCheckpoint(cfg.addrWidth)
}

class PredictorRecovery(addrWidth: Int = 32) extends Bundle {
  val prediction = new PredictionMeta(ICacheConfig(addrWidth = addrWidth))
}

class RasPerf extends Bundle {
  val push             = Bool()
  val pop              = Bool()
  val popThenPush      = Bool()
  val use              = Bool()
  val hit              = Bool()
  val miss             = Bool()
  val underflow        = Bool()
  val overflow         = Bool()
  val checkpointRestore = Bool()
  val recoveryDiscard  = Bool()
}
