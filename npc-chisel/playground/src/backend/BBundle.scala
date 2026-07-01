package top.backend.bundle

import chisel3._
import top.backend.decoder.{FuOp, FuType, SrcType}
import top.bundle.FetchInstPayload
import top.config.BackendConfig

class DecodePacket(addrWidth: Int = 32) extends Bundle {
  val fetch       = new FetchInstPayload(addrWidth)
  val legal       = Bool()
  val rs1         = UInt(5.W)
  val rs2         = UInt(5.W)
  val rd          = UInt(5.W)
  val imm         = UInt(32.W)
  val src1Type    = UInt(SrcType.width.W)
  val src2Type    = UInt(SrcType.width.W)
  val fuType      = UInt(FuType.width.W)
  val fuOp        = UInt(FuOp.width.W)
  val rfWen       = Bool()
  val isLoad      = Bool()
  val isStore     = Bool()
  val isBranch    = Bool()
  val isJal       = Bool()
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()
  val isEcall     = Bool()
}

class IssueControl(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val request = Input(Vec(cfg.issueQueueEntries, Bool()))
  val robIdx  = Input(Vec(cfg.issueQueueEntries, UInt(cfg.robIdxWidth.W)))
  val robHead = Input(UInt(cfg.robIdxWidth.W))
  val grantOH = Output(Vec(cfg.issueQueueEntries, Bool()))
}

class IssueFuReady extends Bundle {
  val alu   = Bool()
  val lsu   = Bool()
  val bru   = Bool()
  val jmp   = Bool()
  val csr   = Bool()
  val fence = Bool()
}

class IssueWakeup(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
  val data   = UInt(cfg.dataWidth.W)
}

class StoreTrackerQuery(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid         = Input(Bool())
  val robIdx        = Input(UInt(cfg.robIdxWidth.W))
  val hasOlderStore = Output(Bool())
}

class StoreTrackerAlloc(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class StoreTrackerCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class IssueOperand(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val data  = UInt(cfg.dataWidth.W)
  val ready = Bool()
  val tag   = UInt(cfg.robIdxWidth.W)
}

class IssuePacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val fetch       = new FetchInstPayload(cfg.addrWidth)
  val legal       = Bool()
  val robIdx      = UInt(cfg.robIdxWidth.W)
  val rd          = UInt(5.W)
  val imm         = UInt(32.W)
  val src1        = new IssueOperand(cfg)
  val src2        = new IssueOperand(cfg)
  val fuType      = UInt(FuType.width.W)
  val fuOp        = UInt(FuOp.width.W)
  val rfWen       = Bool()
  val isLoad      = Bool()
  val isStore     = Bool()
  val isBranch    = Bool()
  val isJal       = Bool()
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()
}

class ScoreboardQuery(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid    = Input(Bool())
  val rs       = Input(UInt(5.W))
  val ready    = Output(Bool())
  val producer = Output(UInt(cfg.robIdxWidth.W))
}

class ScoreboardAlloc(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val rd     = UInt(5.W)
  val rfWen  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class ScoreboardCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val rd     = UInt(5.W)
  val rfWen  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class RobAllocPacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val decode = new DecodePacket(cfg.addrWidth)
}

class RobWritebackPacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx         = UInt(cfg.robIdxWidth.W)
  val result         = UInt(cfg.dataWidth.W)
  val storeAddr      = UInt(cfg.addrWidth.W)
  val storeData      = UInt(cfg.dataWidth.W)
  val storeMask      = UInt((cfg.dataWidth / 8).W)
  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val branchTaken    = Bool()
  val branchTarget   = UInt(cfg.addrWidth.W)
}

class RobCommitPacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx         = UInt(cfg.robIdxWidth.W)
  val fetch          = new FetchInstPayload(cfg.addrWidth)
  val rd             = UInt(5.W)
  val rfWen          = Bool()
  val isLoad         = Bool()
  val isStore        = Bool()
  val isBranch       = Bool()
  val isJal          = Bool()
  val memSize        = UInt(3.W)
  val memUnsigned    = Bool()
  val isEcall        = Bool()
  val result         = UInt(cfg.dataWidth.W)
  val storeAddr      = UInt(cfg.addrWidth.W)
  val storeData      = UInt(cfg.dataWidth.W)
  val storeMask      = UInt((cfg.dataWidth / 8).W)
  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val branchTaken    = Bool()
  val branchTarget   = UInt(cfg.addrWidth.W)
}

class CommitRegWrite(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val enable = Bool()
  val addr   = UInt(5.W)
  val data   = UInt(cfg.dataWidth.W)
}

class ExecutePacket(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val pc        = UInt(addrWidth.W)
  val inst      = UInt(32.W)
  val rd        = UInt(5.W)
  val result    = UInt(dataWidth.W)
  val writeback = Bool()
}

class WritebackPacket(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val pc   = UInt(addrWidth.W)
  val inst = UInt(32.W)
  val rd   = UInt(5.W)
  val data = UInt(dataWidth.W)
  val wen  = Bool()
}

class RegFileReadPort(dataWidth: Int = 32) extends Bundle {
  val enable = Input(Bool())
  val addr   = Input(UInt(5.W))
  val data   = Output(UInt(dataWidth.W))
}

class RegFileWritePort(dataWidth: Int = 32) extends Bundle {
  val enable = Input(Bool())
  val addr   = Input(UInt(5.W))
  val data   = Input(UInt(dataWidth.W))
}

class RegFilePortBundle(
  readPorts:  Int = 4,
  writePorts: Int = 2,
  dataWidth:  Int = 32)
    extends Bundle {
  val read  = Vec(readPorts, new RegFileReadPort(dataWidth))
  val write = Vec(writePorts, new RegFileWritePort(dataWidth))
}
