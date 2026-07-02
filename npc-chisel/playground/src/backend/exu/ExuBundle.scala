package top.backend.exu

import chisel3._
import top.backend.bundle.IssuePacket
import top.bundle.{CfiType, FetchInstPayload}
import top.config.BackendConfig

class ExuRequest(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val fetch  = new FetchInstPayload(cfg.addrWidth)
  val robIdx = UInt(cfg.robIdxWidth.W)
  val rd     = UInt(5.W)

  val fuType = UInt(top.backend.decoder.FuType.width.W)
  val fuOp   = UInt(top.backend.decoder.FuOp.width.W)

  val rfWen = Bool()
  val cfi   = UInt(CfiType.width.W)

  val src1 = UInt(cfg.dataWidth.W)
  val src2 = UInt(cfg.dataWidth.W)
  val imm  = UInt(cfg.dataWidth.W)

  val isLoad      = Bool()
  val isStore     = Bool()
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()
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
}
