package top.sim

import chisel3._
import top.core.trace.{DivPerfTrace, IssueQueuePerfTrace}
import top.dpi.{NpcDivPerf, NpcIssueQueuePerf}

/** Translates backend perf snapshots into DPI samples.
  *
  * With enableDpi = false the module elaborates to an empty shell, so the synthesis view contains neither DPI imports
  * nor DPI calls. The producer modules (IssueQueue, DIV) only fill their trace ports; this bridge is the only place
  * that knows the DPI functions.
  */
class BackendPerfBridge(enableDpi: Boolean = true) extends Module {
  val io = IO(new Bundle {
    val issueQueue = Input(new IssueQueuePerfTrace)
    val div        = Input(new DivPerfTrace)
  })

  if (enableDpi) {
    NpcIssueQueuePerf.callWithEnable(
      io.issueQueue.enable,
      io.issueQueue.issueCount,
      io.issueQueue.occupancy,
      io.issueQueue.blockReady,
      io.issueQueue.blockOperand,
      io.issueQueue.blockReason,
      io.issueQueue.robDoneOperandCount
    )
    NpcDivPerf.callWithEnable(io.div.enable, io.div.cycles, io.div.special)
  }
}
