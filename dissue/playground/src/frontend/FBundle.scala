package top.frontend.bundle

import chisel3._
import chisel3.util.{log2Ceil, Cat, Valid}
import top.config._
import top.bundle.CfiType

// the bundle cross module in the frontend

class FetchInst extends Bundle {
  val pc      = UInt(32.W)
  val inst    = UInt(32.W) // 已展开后的 32-bit 指令
  val rawInst = UInt(32.W) // 原始取到的指令，use for Debug/tval
  val isRVC   = Bool()
  val instLen = UInt(3.W)  // 2 or 4

  val predTaken  = Bool()
  val predNpc    = UInt(32.W)
  val predTarget = UInt(32.W)
}

class PcRedirect extends Bundle {
  val valid = Bool()
  val value = UInt(32.W)
}

class FetchPred(cfg: ICacheConfig) extends Bundle {
  require(cfg.fetchBytes >= 2, "fetchBytes must contain at least one halfword")

  val valid     = Bool()
  val taken     = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(log2Ceil(cfg.fetchBytes / 2).W)
  val cfiType   = UInt(CfiType.width.W)
}

class IFetchBlockMeta(cfg: ICacheConfig) extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val blockAddr = UInt(cfg.addrWidth.W)
  val pred      = new FetchPred(cfg)
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
}

class ICacheRefillReq(addrWidth: Int = 32) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class ICacheRefillResp(fetchBytes: Int = 8) extends Bundle {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val data = UInt((fetchBytes * 8).W)
}

object ICacheReq {
  def fromPc(pc: UInt, cfg: ICacheConfig, pred: FetchPred): ICacheReq = {
    val addrWidth   = pc.getWidth
    val offsetWidth = log2Ceil(cfg.fetchBytes)
    val req         = Wire(new ICacheReq(cfg))

    req.meta.pc        := pc
    req.meta.blockAddr := {
      Cat(pc(addrWidth - 1, offsetWidth), 0.U(offsetWidth.W))
    }
    req.meta.pred      := pred

    return req
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
}

class BpuBundle(cfg: BpuConfig) extends Bundle {
  val lookup = Flipped(Valid(new BpuLookupReq(cfg)))
  val pred   = Output(new BpuPred(cfg))
  val update = Flipped(Valid(new BpuUpdate(cfg)))
}
