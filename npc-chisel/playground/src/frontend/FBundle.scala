package top.frontend.bundle

import chisel3._
import chisel3.util.{log2Ceil, Cat}
import top.config._

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

class IFetchBlockMeta() extends Bundle {
  val pc        = UInt(32.W)
  val blockAddr = UInt(32.W)
}

class ICacheReq(cfg: ICacheConfig) extends Bundle {
  require(cfg.fetchBytes > 0 && (cfg.fetchBytes & (cfg.fetchBytes - 1)) == 0, "fetchBytes must be a power of two")
  require(cfg.addrWidth > log2Ceil(cfg.fetchBytes), "addrWidth must cover the fetch block offset")

  val meta = new IFetchBlockMeta()
}

class ICacheResp(cfg: ICacheConfig) extends Bundle {
  require(cfg.fetchBytes > 0 && (cfg.fetchBytes & (cfg.fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val meta = new IFetchBlockMeta()
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
  def fromPc(pc: UInt, cfg: ICacheConfig): ICacheReq = {
    val addrWidth   = pc.getWidth
    val offsetWidth = log2Ceil(cfg.fetchBytes)
    val req         = Wire(new ICacheReq(cfg))

    req.meta.pc        := pc
    req.meta.blockAddr := {
      Cat(pc(addrWidth - 1, offsetWidth), 0.U(offsetWidth.W))
    }

    return req
  }
}
