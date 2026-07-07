package top.mmu

import chisel3._
import top.backend.exception.ExceptionInfo
import top.bundle.DataMemReq
import top.config.BackendConfig

object MmuAccessType {
  val width = 2

  val fetch = 0.U(width.W)
  val load  = 1.U(width.W)
  val store = 2.U(width.W)
  val amo   = 3.U(width.W)
}

class MmuTranslateReq(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val vaddr   = UInt(cfg.addrWidth.W)
  val access  = UInt(MmuAccessType.width.W)
  val priv    = UInt(top.backend.csr.PrivMode.width.W)
  val mstatus = UInt(cfg.dataWidth.W)
  val satp    = UInt(cfg.dataWidth.W)
}

class MmuTranslateResp(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val paddr     = UInt(cfg.addrWidth.W)
  val exception = new ExceptionInfo(cfg)
}

object MmuMemReq {
  def pteRead(addr: UInt, cfg: BackendConfig = BackendConfig()): DataMemReq = {
    val req = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    req.addr     := addr
    req.write    := false.B
    req.size     := top.backend.decoder.MemSize.word.U
    req.unsigned := true.B
    req.wdata    := 0.U
    req.wmask    := 0.U
    req
  }
}
