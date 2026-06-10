package top.frontend.bundle

import chisel3._
import chisel3.util.{Cat, log2Ceil}

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

class ICacheReq(addrWidth: Int = 32, fetchBytes: Int = 8) extends Bundle {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")
  require(addrWidth > log2Ceil(fetchBytes), "addrWidth must cover the fetch block offset")

  val pc        = UInt(addrWidth.W) // 原始取指 PC，返回 IFetch 时用于指令选择/调试
  val blockAddr = UInt(addrWidth.W) // 按 fetchBytes 对齐后的 ICache 访问地址
}

class ICacheResp(addrWidth: Int = 32, fetchBytes: Int = 8) extends Bundle {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val pc        = UInt(addrWidth.W)
  val blockAddr = UInt(addrWidth.W)
  val data      = UInt((fetchBytes * 8).W)
  val hit       = Bool()
}

class ICacheRefillReq(addrWidth: Int = 32) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class ICacheRefillResp(fetchBytes: Int = 8) extends Bundle {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")

  val data = UInt((fetchBytes * 8).W)
}

object ICacheReq {
  def fromPc(pc: UInt, fetchBytes: Int = 8): ICacheReq = {
    val addrWidth   = pc.getWidth
    val offsetWidth = log2Ceil(fetchBytes)
    val req         = Wire(new ICacheReq(addrWidth, fetchBytes))

    req.pc        := pc
    req.blockAddr := {
      if (offsetWidth == 0) pc
      else Cat(pc(addrWidth - 1, offsetWidth), 0.U(offsetWidth.W))
    }
    req
  }
}
