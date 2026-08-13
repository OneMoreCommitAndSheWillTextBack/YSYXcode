package top.core.frontend.bundle

import chisel3._
import top.config.BpuConfig
import top.core.bundle.{CfiType, FetchException}

class PcRedirect extends Bundle {
  val valid = Bool()
  val value = UInt(32.W)
}

class ICacheRefillReq(addrWidth: Int = 32) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class ICacheRefillResp(fetchBytes: Int = 8) extends Bundle {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val data      = UInt((fetchBytes * 8).W)
  val exception = new FetchException(32)
}

class BpuUpdate(cfg: BpuConfig) extends Bundle {
  val pc              = UInt(cfg.addrWidth.W) // 真实分支指令 PC
  val cfiType         = UInt(CfiType.width.W)
  val taken           = Bool()
  val target          = UInt(cfg.addrWidth.W)
  val instLen         = UInt(3.W)
  val rasAction       = UInt(RasAction.width.W)
  val canonicalReturn = Bool()
  val context         = new PredictorTrainingContext(cfg)
}
