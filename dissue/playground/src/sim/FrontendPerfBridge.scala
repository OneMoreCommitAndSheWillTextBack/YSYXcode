package top.sim

import chisel3._
import top.core.bundle.{FrontendPerfEvent, FrontendStallEvent}
import top.dpi.NpcFrontendPerf

/** Aggregates frontend events into one DPI sample per active cycle. */
class FrontendPerfBridge extends Module {
  val io = IO(new Bundle {
    val events                 = Input(UInt(FrontendPerfEvent.width.W))
    val stallEvents            = Input(UInt(FrontendStallEvent.width.W))
    val fetchQueueOccupancy    = Input(UInt(32.W))
    val fetchQueueEnqueueWidth = Input(UInt(32.W))
    val fetchQueueDequeueWidth = Input(UInt(32.W))
    val ifuCorrection          = Input(Bool())
    val icacheLookupValid      = Input(Bool())
    val icacheBlockValidMask   = Input(UInt(2.W))
    val icacheMissMask         = Input(UInt(2.W))
    val icacheBlockAddr        = Input(Vec(2, UInt(32.W)))
  })

  NpcFrontendPerf.callWithEnable(
    !reset.asBool,
    io.events.pad(32),
    io.stallEvents.pad(32),
    io.ifuCorrection,
    io.fetchQueueOccupancy,
    io.fetchQueueEnqueueWidth,
    io.fetchQueueDequeueWidth,
    io.icacheLookupValid,
    io.icacheBlockValidMask.pad(32),
    io.icacheMissMask.pad(32),
    io.icacheBlockAddr(0),
    io.icacheBlockAddr(1)
  )
}
