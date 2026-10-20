package top.core.monitor

import chisel3._
import chisel3.util.Valid
import top.config.BackendConfig
import top.core.backend.bundle.{
  DecodePacket,
  IssuePacket,
  RetireGroup,
  RobWritebackPacket,
  StoreQueueCommit,
  StoreQueueEvent,
  StoreQueueUpdate,
  StoreResponseEvent
}
import top.core.bundle.{DataMemKind, DataMemTxn, FrontendToBackend, RobRecovery}

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
