package top.mem.bundle

import chisel3._

object AxiBurst {
  val fixed = 0.U(2.W)
  val incr  = 1.U(2.W)
  val wrap  = 2.U(2.W)
}

object AxiResp {
  val okay   = 0.U(2.W)
  val exokay = 1.U(2.W)
  val slverr = 2.U(2.W)
  val decerr = 3.U(2.W)
}

class AxiMasterReadReq(addrWidth: Int = 32, idWidth: Int = 4) extends Bundle {
  val addr  = UInt(addrWidth.W)
  val id    = UInt(idWidth.W)
  val len   = UInt(8.W)
  val size  = UInt(3.W)
  val burst = UInt(2.W)
}

class AxiMasterReadResp(dataWidth: Int = 32, idWidth: Int = 4) extends Bundle {
  val data = UInt(dataWidth.W)
  val id   = UInt(idWidth.W)
  val resp = UInt(2.W)
  val last = Bool()
}

class AxiMasterWriteReq(addrWidth: Int = 32, dataWidth: Int = 32, idWidth: Int = 4) extends Bundle {
  val addr  = UInt(addrWidth.W)
  val id    = UInt(idWidth.W)
  val len   = UInt(8.W)
  val size  = UInt(3.W)
  val burst = UInt(2.W)
  val data  = UInt(dataWidth.W)
  val strb  = UInt((dataWidth / 8).W)
  val last  = Bool()
}

class AxiMasterWriteResp(idWidth: Int = 4) extends Bundle {
  val id   = UInt(idWidth.W)
  val resp = UInt(2.W)
}
