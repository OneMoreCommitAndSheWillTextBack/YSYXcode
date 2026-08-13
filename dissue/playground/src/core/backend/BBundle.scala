package top.core.backend.bundle

import chisel3._
import chisel3.util.Valid
import top.core.backend.csr.CsrAddr
import top.core.backend.decoder.{FuOp, FuType, SrcType}
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.{BpuCfiClass, CfiType, DataMemKind, DataMemTxn, FetchInstPayload, FrontendToBackend, RobRecovery}
import top.config.BackendConfig

class DecodePacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid       = Bool()
  val fetch       = new FetchInstPayload(cfg.frontendPayload)
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
  val isFenceI    = Bool()
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
  val alu    = Bool()
  val mul    = Bool()
  val div    = Bool()
  val lsu    = Bool()
  val bru    = Bool()
  val jmp    = Bool()
  val csr    = Bool()
  val fence  = Bool()
  val load   = Bool()
  val store  = Bool()
  val atomic = Bool()
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

class StoreQueueAlloc(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class StoreQueueUpdate(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val sqIdx  = UInt(cfg.sqIdxWidth.W)
  val robIdx = UInt(cfg.robIdxWidth.W)
  val vaddr  = UInt(cfg.addrWidth.W)
  val addr   = UInt(cfg.addrWidth.W)
  val data   = UInt(cfg.dataWidth.W)
  val mask   = UInt((cfg.dataWidth / 8).W)
  val size   = UInt(3.W)
  val mmio   = Bool()
}

class StoreQueueCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val sqIdx  = UInt(cfg.sqIdxWidth.W)
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class StoreQueueEvent(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val sqIdx  = UInt(cfg.sqIdxWidth.W)
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class StoreDrainRequest(cfg: BackendConfig = BackendConfig()) extends StoreQueueEvent(cfg) {
  val vaddr = UInt(cfg.addrWidth.W)
  val addr  = UInt(cfg.addrWidth.W)
  val data  = UInt(cfg.dataWidth.W)
  val mask  = UInt((cfg.dataWidth / 8).W)
  val size  = UInt(3.W)
  val mmio  = Bool()
}

class StoreResponseEvent(cfg: BackendConfig = BackendConfig()) extends StoreQueueEvent(cfg) {
  val fault = Bool()
  val mmio  = Bool()
}

class StoreQueuePerf(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val alloc     = Bool()
  val fullStall = Bool()
  val commit    = Bool()
  val request   = Bool()
  val response  = Bool()
  val occupancy = UInt(math.max(chisel3.util.log2Ceil(cfg.storeQueueEntries + 1), 1).W)
}

class BackendMemPerf(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val sqAlloc                     = Bool()
  val sqFullStall                 = Bool()
  val forwardFull                 = Bool()
  val forwardPartial              = Bool()
  val forwardUnresolvedStoreStall = Bool()
  val storeCommit                 = Bool()
  val storeDrain                  = Bool()
  val storeResponse               = Bool()
  val loadTxnFullStall            = Bool()
  val sqOccupancy                 = UInt(math.max(chisel3.util.log2Ceil(cfg.storeQueueEntries + 1), 1).W)
  val loadTxnOccupancy            = UInt(math.max(chisel3.util.log2Ceil(cfg.loadTxnEntries + 1), 1).W)
}

class StoreForwardQuery(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid          = Input(Bool())
  val robIdx         = Input(UInt(cfg.robIdxWidth.W))
  val addr           = Input(UInt(cfg.addrWidth.W))
  val mask           = Input(UInt((cfg.dataWidth / 8).W))
  val unresolved     = Output(Bool())
  val fullForward    = Output(Bool())
  val partialForward = Output(Bool())
  val forwardMask    = Output(UInt((cfg.dataWidth / 8).W))
  val forwardData    = Output(UInt(cfg.dataWidth.W))
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
  val sqIdx     = UInt(cfg.sqIdxWidth.W)
  val fetch     = new FetchInstPayload(cfg.frontendPayload)
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

/** Passive retirement-side BPU accuracy sample. */
class BpuPerfSample extends Bundle {
  val valid       = Bool()
  val cfiClass    = UInt(BpuCfiClass.width.W)
  val predHit     = Bool()
  val predTaken   = Bool()
  val actualTaken = Bool()
  val correct     = Bool()
}

class IssueOperand(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val data  = UInt(cfg.dataWidth.W)
  val ready = Bool()
  val tag   = UInt(cfg.robIdxWidth.W)
}

class IssuePacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val fetch       = new FetchInstPayload(cfg.frontendPayload)
  val legal       = Bool()
  val robIdx      = UInt(cfg.robIdxWidth.W)
  val sqIdx       = UInt(cfg.sqIdxWidth.W)
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
  val valid        = Input(Bool())
  val rs           = Input(UInt(5.W))
  val ready        = Output(Bool())
  val producer     = Output(UInt(cfg.robIdxWidth.W))
  val producerDone = Output(Bool())
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
  val sqIdx  = UInt(cfg.sqIdxWidth.W)
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

/** Control-flow outcome produced by an execution unit.
  *
  * This is deliberately separate from ROB writeback: recovery consumes it as soon as execution has resolved the
  * control-flow instruction, while retirement later consumes the same outcome retained in the ROB for BPU training.
  */
class BranchResolve(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx          = UInt(cfg.robIdxWidth.W)
  val pc              = UInt(cfg.addrWidth.W)
  val cfiType         = UInt(CfiType.width.W)
  val predNpc         = UInt(cfg.addrWidth.W)
  val actualNpc       = UInt(cfg.addrWidth.W)
  val taken           = Bool()
  val branchTarget    = UInt(cfg.addrWidth.W)
  val instLen         = UInt(3.W)
  val ftqTag          = new top.core.frontend.bundle.FetchTargetTag(cfg.frontendPayload)
  val ftqInstOrdinal  = UInt(cfg.frontendPayload.ftqInstCountBits.W)
  val rasAction       = UInt(top.core.frontend.bundle.RasAction.width.W)
  val canonicalReturn = Bool()
}

/** Read-only semantic boundary used by composition-level observers.
  *
  * This port cannot influence backend ready, recovery, or state transitions. When monitoring is disabled at elaboration
  * time the backend drives the whole bundle to zero so the associated observation cone is removed.
  */
class BackendMonitor(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val frontendFire = Bool()
  val frontend     = new FrontendToBackend(cfg.issueWidth, cfg.frontendPayload)

  val dispatchFire   = Vec(cfg.dispatchWidth, Bool())
  val dispatchDecode = Vec(cfg.dispatchWidth, new DecodePacket(cfg))
  val dispatchIssue  = Vec(cfg.dispatchWidth, new IssuePacket(cfg))

  val intIssueFire = Vec(cfg.intIssueWidth, Bool())
  val intIssue     = Vec(cfg.intIssueWidth, new IssuePacket(cfg))
  val memIssueFire = Bool()
  val memIssue     = new IssuePacket(cfg)

  val writeback     = Vec(cfg.writebackWidth, Valid(new RobWritebackPacket(cfg)))
  val retire        = new RetireGroup(cfg)
  val bpuPerf       = Vec(cfg.commitWidth, new BpuPerfSample)
  val storeReady    = Valid(new StoreQueueUpdate(cfg))
  val storeCommit   = Vec(cfg.commitWidth, new StoreQueueCommit(cfg))
  val storeRequest  = Valid(new StoreQueueEvent(cfg))
  val storeResponse = Valid(new StoreResponseEvent(cfg))

  val memoryRequestFire   = Bool()
  val memoryRequestRobIdx = UInt(cfg.robIdxWidth.W)
  val memoryRequestKind   = UInt(DataMemKind.width.W)
  val memoryRequestWrite  = Bool()
  val memoryRequestTxnId  = UInt(DataMemTxn.width.W)

  val robHead     = UInt(cfg.robIdxWidth.W)
  val recover     = new RobRecovery(cfg.robIdxWidth)
  val globalFlush = Bool()
}

/** The portion of a ROB entry needed to reconstruct register dependencies after selective recovery. */
class RobProducerEntry(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val done   = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
  val rd     = UInt(5.W)
  val rfWen  = Bool()
}

class RobCommitPacket(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx         = UInt(cfg.robIdxWidth.W)
  val sqIdx          = UInt(cfg.sqIdxWidth.W)
  val fetch          = new FetchInstPayload(cfg.frontendPayload)
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
  val isFenceI       = Bool()
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
