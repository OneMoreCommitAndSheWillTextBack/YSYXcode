package top.sim

import chisel3._
import top.core.bundle.MemPerfEvent
import top.dpi.NpcMemPerf

/** Aggregates memory-system events into one DPI sample per active cycle. */
class MemPerfBridge extends Module {
  val io = IO(new Bundle {
    val events              = Input(UInt(MemPerfEvent.width.W))
    val mshrOccupancy       = Input(UInt(32.W))
    val storeQueueOccupancy = Input(UInt(32.W))
    val loadTxnOccupancy    = Input(UInt(32.W))
  })

  NpcMemPerf.callWithEnable(
    !reset.asBool,
    io.events.pad(32),
    io.mshrOccupancy,
    io.storeQueueOccupancy,
    io.loadTxnOccupancy
  )
}
