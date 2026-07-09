package top.core.backend.exu

import chisel3._
import top.core.backend.bundle.IssuePacket
import top.core.backend.csr.CsrAddr
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.{CfiType, FetchInstPayload}
import top.config.BackendConfig

class ExuRequest(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val fetch  = new FetchInstPayload(cfg.addrWidth)
  val robIdx = UInt(cfg.robIdxWidth.W)
  val rd     = UInt(5.W)

  val fuType = UInt(top.core.backend.decoder.FuType.width.W)
  val fuOp   = UInt(top.core.backend.decoder.FuOp.width.W)

  val rfWen = Bool()
  val cfi   = UInt(CfiType.width.W)

  val src1 = UInt(cfg.dataWidth.W)
  val src2 = UInt(cfg.dataWidth.W)
  val imm  = UInt(cfg.dataWidth.W)

  val isLoad      = Bool()
  val isStore     = Bool()
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()

  val isCsr   = Bool()
  val csrAddr = UInt(CsrAddr.width.W)
  val csrWen  = Bool()

  val exception = new ExceptionInfo(cfg)
}

object ExuRequest {
  def fromIssue(issue: IssuePacket, cfg: BackendConfig): ExuRequest = {
    val request = Wire(new ExuRequest(cfg))
    request := 0.U.asTypeOf(new ExuRequest(cfg))

    request.fetch  := issue.fetch
    request.robIdx := issue.robIdx
    request.rd     := issue.rd
    request.fuType := issue.fuType
    request.fuOp   := issue.fuOp
    request.rfWen  := issue.rfWen
    request.cfi    := issue.cfi
    request.src1   := issue.src1.data
    request.src2   := issue.src2.data
    request.imm    := issue.imm.asTypeOf(UInt(cfg.dataWidth.W))

    request.isLoad      := issue.isLoad
    request.isStore     := issue.isStore
    request.memSize     := issue.memSize
    request.memUnsigned := issue.memUnsigned
    request.isCsr       := issue.isCsr
    request.csrAddr     := issue.csrAddr
    request.csrWen      := issue.csrWen
    request.exception   := issue.exception

    request
  }
}

class ExuResult(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx = UInt(cfg.robIdxWidth.W)
  val rd     = UInt(5.W)
  val rfWen  = Bool()

  val result = UInt(cfg.dataWidth.W)

  val storeAddr = UInt(cfg.addrWidth.W)
  val storeData = UInt(cfg.dataWidth.W)
  val storeMask = UInt((cfg.dataWidth / 8).W)

  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val branchTaken    = Bool()
  val branchTarget   = UInt(cfg.addrWidth.W)

  val csrWen   = Bool()
  val csrWdata = UInt(cfg.dataWidth.W)

  val exception = new ExceptionInfo(cfg)
}
