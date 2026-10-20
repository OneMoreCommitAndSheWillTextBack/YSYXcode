package top.sim

import chisel3._
import top.core.monitor.{DivMonitor, IssueQueueMonitor}
import top.dpi.{NpcDivPerf, NpcIssueQueuePerf}

/** Translates backend perf snapshots into DPI samples.
  *
  * With enableDpi = false the module elaborates to an empty shell, so the synthesis view contains neither DPI imports
  * nor DPI calls. The producer modules (IssueQueue, DIV) only fill their monitor ports; this bridge is the only place
  * that knows the DPI functions and owns the DIV cycle counter.
  */
class BackendPerfBridge(enableDpi: Boolean = true) extends Module {
  val io = IO(new Bundle {
    val issueQueue = Input(new IssueQueueMonitor)
    val div        = Input(new DivMonitor)
  })

  if (enableDpi) {
    val divCycles  = RegInit(0.U(16.W))
    val divSpecial = RegInit(false.B)

    when(io.div.issue) {
      divCycles  := 1.U
      divSpecial := io.div.special
    }.elsewhen(io.div.busy) {
      divCycles := divCycles + 1.U
    }.otherwise {
      divCycles := 0.U
    }

    NpcIssueQueuePerf.callWithEnable(
      io.issueQueue.enable,
      io.issueQueue.issueCount,
      io.issueQueue.occupancy,
      io.issueQueue.blockReady,
      io.issueQueue.blockOperand,
      io.issueQueue.blockReason,
      io.issueQueue.robDoneOperandCount
    )
    NpcDivPerf.callWithEnable(io.div.enable, divCycles, divSpecial)
  }
}
