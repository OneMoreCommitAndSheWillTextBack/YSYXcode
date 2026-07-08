package top.core.backend.bundle

import chisel3._
import top.core.backend.csr.CsrAddr
import top.core.backend.decoder.{FuOp, FuType, SrcType}
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.FetchInstPayload
import top.config.BackendConfig
import top.core.bundle.CfiType

class DecodePacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid       = Bool()
  val fetch       = new FetchInstPayload(cfg.addrWidth)
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
  val isAmo       = Bool()
  val cfi         = UInt(CfiType.width.W)
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()
  val isEbreak    = Bool()
  val isEcall     = Bool()
  val isMret      = Bool()
  val isSret      = Bool()
  val isFence     = Bool()
  val isSfence    = Bool()
  val isCsr       = Bool()
  val csrAddr     = UInt(CsrAddr.width.W)
  val csrWen      = Bool()
  val exception   = new ExceptionInfo(cfg)

  def hasTrapAtRetire: Bool =
    exception.valid || isEcall

  def isRetireOnly: Bool =
    hasTrapAtRetire || isMret || isSret || isFence

  def needsIssue: Bool =
    valid && !isRetireOnly
}

class IssueControl(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val request = Input(Vec(cfg.issueQueueEntries, Bool()))
  val robIdx  = Input(Vec(cfg.issueQueueEntries, UInt(cfg.robIdxWidth.W)))
  val robHead = Input(UInt(cfg.robIdxWidth.W))
  val grantOH = Output(Vec(cfg.issueQueueEntries, Bool()))
}

class IssuePortStatus extends Bundle {
  val alu   = Bool()
  val mul   = Bool()
  val div   = Bool()
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

class RetireException(cfg: BackendConfig = BackendConfig()) extends ExceptionInfo(cfg) {
  val blocksYounger = Bool()
}

class RetireStore(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
  val addr  = UInt(cfg.addrWidth.W)
  val data  = UInt(cfg.dataWidth.W)
  val mask  = UInt((cfg.dataWidth / 8).W)
  val size  = UInt(3.W)
}

class RetireMemory(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
  val write = Bool()
  val addr  = UInt(cfg.addrWidth.W)
  val size  = UInt(3.W)
}

class RetireControl(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val branchTaken    = Bool()
  val branchTarget   = UInt(cfg.addrWidth.W)
}

class RetireLane(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid     = Bool()
  val robIdx    = UInt(cfg.robIdxWidth.W)
  val fetch     = new FetchInstPayload(cfg.addrWidth)
  val nextPc    = UInt(cfg.addrWidth.W)
  val rf        = new CommitRegWrite(cfg)
  val store     = new RetireStore(cfg)
  val memory    = new RetireMemory(cfg)
  val control   = new RetireControl(cfg)
  val exception = new RetireException(cfg)
  val finish    = Bool()
}

class RetireGroup(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val lanes      = Vec(cfg.commitWidth, new RetireLane(cfg))
  val validMask  = UInt(cfg.commitWidth.W)
  val finishMask = UInt(cfg.commitWidth.W)
  val finalPc    = UInt(cfg.addrWidth.W)
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
  val isAmo       = Bool()
  val cfi         = UInt(CfiType.width.W)
  val memSize     = UInt(3.W)
  val memUnsigned = Bool()
  val isCsr       = Bool()
  val csrAddr     = UInt(CsrAddr.width.W)
  val csrWen      = Bool()
  val exception   = new ExceptionInfo(cfg)

  def needsExecution: Bool =
    legal && !exception.valid
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
  val decode = new DecodePacket(cfg)
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
  val csrWen         = Bool()
  val csrWdata       = UInt(cfg.dataWidth.W)
  val exception      = new ExceptionInfo(cfg)
}

class RobCommitPacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx         = UInt(cfg.robIdxWidth.W)
  val fetch          = new FetchInstPayload(cfg.addrWidth)
  val rd             = UInt(5.W)
  val rfWen          = Bool()
  val isLoad         = Bool()
  val isStore        = Bool()
  val isAmo          = Bool()
  val cfi            = UInt(CfiType.width.W)
  val memSize        = UInt(3.W)
  val memUnsigned    = Bool()
  val isEbreak       = Bool()
  val isEcall        = Bool()
  val isMret         = Bool()
  val isSret         = Bool()
  val isFence        = Bool()
  val isSfence       = Bool()
  val result         = UInt(cfg.dataWidth.W)
  val storeAddr      = UInt(cfg.addrWidth.W)
  val storeData      = UInt(cfg.dataWidth.W)
  val storeMask      = UInt((cfg.dataWidth / 8).W)
  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val branchTaken    = Bool()
  val branchTarget   = UInt(cfg.addrWidth.W)
  val isCsr          = Bool()
  val csrAddr        = UInt(CsrAddr.width.W)
  val csrWen         = Bool()
  val csrWdata       = UInt(cfg.dataWidth.W)
  val exception      = new ExceptionInfo(cfg)

  def hasTrapAtRetire: Bool =
    exception.valid || isEcall
}

class CommitRegWrite(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val enable = Bool()
  val addr   = UInt(5.W)
  val data   = UInt(cfg.dataWidth.W)
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
