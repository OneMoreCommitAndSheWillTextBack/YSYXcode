package top.core.trace

import chisel3._

/** Read-only issue-queue perf snapshot for the sim-layer DPI bridge.
  *
  * The producer (IssueQueue) only fills fields; translating them into a DPI sample is the bridge's job, so this bundle
  * must stay free of top.dpi.
  */
class IssueQueuePerfTrace extends Bundle {
  val enable              = Bool()
  val issueCount          = UInt(32.W)
  val occupancy           = UInt(32.W)
  val blockReady          = Bool()
  val blockOperand        = Bool()
  val blockReason         = UInt(32.W)
  val robDoneOperandCount = UInt(32.W)
}

/** Read-only DIV perf snapshot for the sim-layer DPI bridge. */
class DivPerfTrace extends Bundle {
  val enable  = Bool()
  val cycles  = UInt(32.W)
  val special = Bool()
}
