package top.core.frontend.bundle

import chisel3._
import chisel3.util.{log2Ceil, Cat, Fill, MuxLookup}
import top.config.ICacheConfig
import top.core.bundle.CfiType

object PredictorConstants {
  val commitUpdateWidth   = 2
  val latePredictionWidth = 4
  val maxTaggedTables     = 6
  val providerBits        = 5
  val confidenceBits      = 2
  val historyBits         = 16
  val sequenceBits        = 16
  val epochBits           = 8
  val ftqIndexBits        = 8
  val ftqGenerationBits   = 8
  val rasEntries          = 8
  val rasIndexBits        = log2Ceil(rasEntries)
  val rasCountBits        = log2Ceil(rasEntries + 1)
}

object PredictorProvider {
  val none       = 0.U(PredictorConstants.providerBits.W)
  val fastBtb    = 1.U(PredictorConstants.providerBits.W)
  val ras        = 2.U(PredictorConstants.providerBits.W)
  val tageBase   = 3.U(PredictorConstants.providerBits.W)
  val ittageBase = 4.U(PredictorConstants.providerBits.W)

  def tageTable(index:   Int): UInt = (5 + index).U(PredictorConstants.providerBits.W)
  def ittageTable(index: Int): UInt = (11 + index).U(PredictorConstants.providerBits.W)
}

object RasAction {
  val width = 2

  val none        = 0.U(width.W)
  val push        = 1.U(width.W)
  val pop         = 2.U(width.W)
  val popThenPush = 3.U(width.W)

  def isLink(reg: UInt): Bool =
    reg === 1.U(5.W) || reg === 5.U(5.W)

  def isJalr(inst: UInt): Bool =
    inst(6, 0) === "b1100111".U && inst(14, 12) === 0.U

  def cfiType(inst: UInt): UInt =
    Mux(
      inst(6, 0) === "b1100011".U,
      CfiType.branch,
      Mux(inst(6, 0) === "b1101111".U, CfiType.jal, Mux(isJalr(inst), CfiType.jalr, CfiType.none))
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
        isJalr(inst),
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
    isJalr(inst) && inst(11, 7) === 0.U && isLink(inst(19, 15)) && inst(31, 20) === 0.U
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

/** Predictor-only context retained in the FTQ until the corresponding CFI commits. */
class PredictorTrainingContext(cfg: top.config.BpuConfig) extends Bundle {
  val provider        = UInt(PredictorConstants.providerBits.W)
  val alternate       = UInt(PredictorConstants.providerBits.W)
  val confidence      = UInt(PredictorConstants.confidenceBits.W)
  val providerUseful  = UInt(2.W)
  val allocationMask  = UInt(PredictorConstants.maxTaggedTables.W)
  val predictedTarget = UInt(cfg.addrWidth.W)
  val rasUsed         = Bool()
  val lateQueried     = Bool()
  val lateValid       = Bool()
  val lateTaken       = Bool()
  val alternateTaken  = Bool()
  val lateTarget      = UInt(cfg.addrWidth.W)
  val alternateTarget = UInt(cfg.addrWidth.W)

  val historyCheckpoint = UInt(PredictorConstants.historyBits.W)
  val pathCheckpoint    = UInt(PredictorConstants.historyBits.W)
}

class LatePredictQuery(cfg: ICacheConfig) extends Bundle {
  val valid           = Bool()
  val pc              = UInt(cfg.addrWidth.W)
  val cfiType         = UInt(CfiType.width.W)
  val fastValid       = Bool()
  val fastTaken       = Bool()
  val fastTarget      = UInt(cfg.addrWidth.W)
  val canonicalReturn = Bool()
  val history         = UInt(PredictorConstants.historyBits.W)
  val pathHistory     = UInt(PredictorConstants.historyBits.W)
}

class LatePrediction(cfg: ICacheConfig) extends Bundle {
  val queried           = Bool()
  val valid             = Bool()
  val taken             = Bool()
  val target            = UInt(cfg.addrWidth.W)
  val provider          = UInt(PredictorConstants.providerBits.W)
  val alternate         = UInt(PredictorConstants.providerBits.W)
  val confidence        = UInt(PredictorConstants.confidenceBits.W)
  val providerUseful    = UInt(2.W)
  val allocationMask    = UInt(PredictorConstants.maxTaggedTables.W)
  val alternateTaken    = Bool()
  val alternateTarget   = UInt(cfg.addrWidth.W)
  val historyCheckpoint = UInt(PredictorConstants.historyBits.W)
  val pathCheckpoint    = UInt(PredictorConstants.historyBits.W)
}

class TaggedPredictorPerf extends Bundle {
  val provider          = Bool()
  val alternateDisagree = Bool()
  val allocation        = Bool()
  val usefulnessAging   = Bool()
}

object CfiTarget {
  def branch(pc: UInt, inst: UInt): UInt = {
    val offset = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W))
    pc +% offset
  }

  def jal(pc: UInt, inst: UInt): UInt = {
    val offset = Cat(Fill(11, inst(31)), inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
    pc +% offset
  }
}

class RasPerf extends Bundle {
  val push              = Bool()
  val pop               = Bool()
  val popThenPush       = Bool()
  val use               = Bool()
  val hit               = Bool()
  val miss              = Bool()
  val underflow         = Bool()
  val overflow          = Bool()
  val checkpointRestore = Bool()
  val recoveryDiscard   = Bool()
  val taggedProvider    = Bool()
  val alternateDisagree = Bool()
  val allocation        = Bool()
  val usefulnessAging   = Bool()
  val lateOverride      = Bool()
}
