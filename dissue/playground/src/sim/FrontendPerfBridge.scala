package top.sim

import chisel3._
import top.core.bundle.FrontendPerfEvent
import top.dpi.NpcFrontendPerf

/** Aggregates frontend events into one DPI sample per active cycle. */
class FrontendPerfBridge extends Module {
  val io = IO(new Bundle {
    val events                 = Input(UInt(FrontendPerfEvent.width.W))
    val fetchQueueOccupancy    = Input(UInt(32.W))
    val fetchQueueEnqueueWidth = Input(UInt(32.W))
    val fetchQueueDequeueWidth = Input(UInt(32.W))
  })

  NpcFrontendPerf.callWithEnable(
    !reset.asBool,
    io.events.pad(32),
    io.fetchQueueOccupancy,
    io.fetchQueueEnqueueWidth,
    io.fetchQueueDequeueWidth
  )
}
