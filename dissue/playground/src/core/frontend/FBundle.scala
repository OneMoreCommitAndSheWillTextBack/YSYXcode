package top.core.frontend.bundle

import chisel3._
import chisel3.util.{log2Ceil, Cat, Valid}
import top.config._
import top.core.bundle.{CfiType, FetchException}

// the bundle cross module in the frontend

class FetchInst extends Bundle {
  val pc      = UInt(32.W)
  val inst    = UInt(32.W) // 已展开后的 32-bit 指令
  val rawInst = UInt(32.W) // 原始取到的指令，use for Debug/tval
  val isRVC   = Bool()
  val instLen = UInt(3.W)  // 2 or 4

  /** A BTB prediction matched this instruction's PC within its fetch block. */
  val predHit    = Bool()
  val predTaken  = Bool()
  val predNpc    = UInt(32.W)
  val predTarget = UInt(32.W)

  val prediction = new PredictionMeta

  val exception = new FetchException(32)
}

class PcRedirect extends Bundle {
  val valid = Bool()
  val value = UInt(32.W)
}

class FetchControlMeta(cfg: ICacheConfig) extends Bundle {
  val pc         = UInt(cfg.addrWidth.W)
  val prediction = new PredictionMeta(cfg)

  def sequence: UInt = prediction.sequence
  def epoch: UInt = prediction.epoch
  def ftqIndex: UInt = prediction.ftqIndex
  def fastPrediction: FetchPred = prediction.fastPrediction
}

class IFetchBlockMeta(cfg: ICacheConfig) extends Bundle {
  val control   = new FetchControlMeta(cfg)
  val blockAddr = UInt(cfg.addrWidth.W)
}

class ICacheReq(cfg: ICacheConfig) extends Bundle {
  require(cfg.fetchBytes > 0 && (cfg.fetchBytes & (cfg.fetchBytes - 1)) == 0, "fetchBytes must be a power of two")
  require(cfg.addrWidth > log2Ceil(cfg.fetchBytes), "addrWidth must cover the fetch block offset")

  val meta = new IFetchBlockMeta(cfg)
}

class ICacheResp(cfg: ICacheConfig) extends Bundle {
  require(cfg.fetchBytes > 0 && (cfg.fetchBytes & (cfg.fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val meta = new IFetchBlockMeta(cfg)
  val data = UInt((cfg.fetchBytes * 8).W)
  val hit  = Bool()
  val exception = new FetchException(cfg.addrWidth)
}

class ICacheFetchGroupReq(cfg: ICacheConfig) extends Bundle {
  val blocks = Vec(cfg.fetchGroupBlocks, Valid(new ICacheReq(cfg)))
}

class ICacheFetchGroupResp(cfg: ICacheConfig) extends Bundle {
  val blocks = Vec(cfg.fetchGroupBlocks, Valid(new ICacheResp(cfg)))
}

class ICacheRefillReq(addrWidth: Int = 32) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class ICacheRefillResp(fetchBytes: Int = 8) extends Bundle {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val data = UInt((fetchBytes * 8).W)
  val exception = new FetchException(32)
}

object ICacheReq {
  def fromControl(control: FetchControlMeta, cfg: ICacheConfig): ICacheReq = {
    val addrWidth   = control.pc.getWidth
    val offsetWidth = log2Ceil(cfg.fetchBytes)
    val req         = Wire(new ICacheReq(cfg))

    req.meta.control := control
    req.meta.blockAddr := {
      Cat(control.pc(addrWidth - 1, offsetWidth), 0.U(offsetWidth.W))
    }

    req
  }

  def fromPc(pc: UInt, cfg: ICacheConfig, pred: FetchPred): ICacheReq = {
    val control = Wire(new FetchControlMeta(cfg))
    control := 0.U.asTypeOf(new FetchControlMeta(cfg))
    control.sequence       := 0.U
    control.epoch          := 0.U
    control.ftqIndex       := 0.U
    control.pc             := pc
    control.fastPrediction := pred
    control.prediction.provider := Mux(pred.valid, PredictorProvider.fastBtb, PredictorProvider.none)
    control.prediction.confidence := pred.valid.asUInt
    control.prediction.predictedTarget := pred.target
    fromControl(control, cfg)
  }

  def fromPc(pc: UInt, cfg: ICacheConfig): ICacheReq = {
    val pred = Wire(new FetchPred(cfg))
    pred := 0.U.asTypeOf(new FetchPred(cfg))
    fromPc(pc, cfg, pred)
  }
}

class BpuLookupReq(cfg: BpuConfig) extends Bundle {
  val pc = UInt(cfg.addrWidth.W) // 当前 fetch startPc
}

class BpuPred(cfg: BpuConfig) extends Bundle {
  val valid     = Bool() // BTB hit
  val taken     = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
}

class BpuUpdate(cfg: BpuConfig) extends Bundle {
  val pc      = UInt(cfg.addrWidth.W) // 真实分支指令 PC
  val cfiType = UInt(CfiType.width.W)
  val taken   = Bool()
  val target  = UInt(cfg.addrWidth.W)
  val instLen = UInt(3.W)             // 2 or 4，后面算 fallThrough 有用
  val rasAction = UInt(RasAction.width.W)
  val prediction = new PredictionMeta(ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes))
}

class BpuBundle(cfg: BpuConfig) extends Bundle {
  val lookup          = Flipped(Valid(new BpuLookupReq(cfg)))
  val lookupSecondary = Flipped(Valid(new BpuLookupReq(cfg)))
  val pred            = Output(new BpuPred(cfg))
  val predSecondary   = Output(new BpuPred(cfg))
  val update          = Input(Vec(PredictorConstants.commitUpdateWidth, Valid(new BpuUpdate(cfg))))
  val lateQuery       = Input(Vec(PredictorConstants.latePredictionWidth, new LatePredictQuery(ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes))))
  val latePrediction  = Output(Vec(PredictorConstants.latePredictionWidth, new LatePrediction(ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes))))
  val lateSpecUpdate  = Input(Vec(PredictorConstants.latePredictionWidth, Valid(new PredictionMeta(ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes)))))
  val rasSpecUpdate   = Input(Valid(new PredictionMeta(ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes))))
  val rasRecovery     = Input(Valid(new PredictorRecovery(cfg.addrWidth)))
  val rasFlush        = Input(Bool())
  val rasTop          = Output(UInt(cfg.addrWidth.W))
  val rasValid        = Output(Bool())
  val rasCheckpoint   = Output(new RasCheckpoint(cfg.addrWidth))
  val perf            = Output(new RasPerf)
}
