package top.sim

import chisel3._
import top.core.bundle.FrontendPerfEvent
import top.dpi.NpcFrontendPerf

/** Aggregates frontend events into one DPI sample per active cycle. */
class FrontendPerfBridge extends Module {
  val io = IO(new Bundle {
    val events = Input(UInt(FrontendPerfEvent.width.W))
  })

  NpcFrontendPerf.callWithEnable(
    !reset.asBool,
    io.events.pad(32)
  )
}
