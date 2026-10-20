package top.core.monitor

import chisel3._

/** Issue-queue observation snapshot. Filled only when the parent enables monitoring. */
class IssueQueueMonitor extends Bundle {
  val enable              = Bool()
  val issueCount          = UInt(32.W)
  val occupancy           = UInt(32.W)
  val blockReady          = Bool()
  val blockOperand        = Bool()
  val blockReason         = UInt(32.W)
  val robDoneOperandCount = UInt(32.W)
}

/** DIV observation snapshot. Cycle counting lives in the sim bridge. */
class DivMonitor extends Bundle {
  val issue   = Bool()
  val busy    = Bool()
  val enable  = Bool()
  val special = Bool()
}

/** Backend perf-monitor aggregate consumed by BackendPerfBridge. */
class BackendPerf extends Bundle {
  val issueQueue = new IssueQueueMonitor
  val div        = new DivMonitor
}
