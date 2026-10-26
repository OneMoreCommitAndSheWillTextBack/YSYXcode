package top.core.mmu

import chisel3._
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.{DataMemKind, DataMemReq, DataMemTxn}
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
  val priv    = UInt(top.core.backend.csr.PrivMode.width.W)
  val mstatus = UInt(cfg.dataWidth.W)
  val satp    = UInt(cfg.dataWidth.W)
  // Translation window identity. The LSU allocates this for every queued
  // request; async miss completions echo it back so they can be matched after
  // younger lookups have overtaken the original request.
  val id      = UInt(cfg.translationIdWidth.W)
  val robIdx  = UInt(cfg.robIdxWidth.W)
}

class MmuTranslateResp(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val paddr     = UInt(cfg.addrWidth.W)
  val exception = new ExceptionInfo(cfg)

  // Walker-to-DTLB refill information. `fill` is false for faults and for
  // translation-disabled responses; the DTLB bypasses the latter before lookup.
  val vaddr = UInt(cfg.addrWidth.W)
  val pte   = UInt(cfg.dataWidth.W)
  val level = UInt(1.W)
  val fill  = Bool()

  // Echo of the request identity plus the lookup result class. `deferred`
  // means the translation was enqueued in the DTLB miss queue and the final
  // result will arrive on the completion port.
  val id       = UInt(cfg.translationIdWidth.W)
  val robIdx   = UInt(cfg.robIdxWidth.W)
  val deferred = Bool()
}

object MmuMemReq {
  def pteRead(addr: UInt, cfg: BackendConfig = BackendConfig()): DataMemReq = {
    val req = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    req.addr      := addr
    req.write     := false.B
    req.size      := top.core.backend.decoder.MemSize.word.U
    req.unsigned  := true.B
    req.wdata     := 0.U
    req.wmask     := 0.U
    req.txnId     := DataMemTxn.ptwTag
    req.cacheable := false.B
    req.kind      := DataMemKind.ptw
    req
  }
}
