package top.sim

import chisel3._
import top.config.FrontendConfig
import top.core.trace.FrontendTraceSample
import top.dpi.NpcFrontendPerf

/** Translates the frontend trace sample into one DPI sample per active cycle.
  *
  * With enableDpi = false the module elaborates to an empty shell, so the synthesis view contains no DPI import.
  */
class FrontendPerfBridge(frontendCfg: FrontendConfig = FrontendConfig(), enableDpi: Boolean = true) extends Module {
  val io = IO(new Bundle {
    val trace = Input(new FrontendTraceSample(frontendCfg))
  })

  if (enableDpi) {
    NpcFrontendPerf.callWithEnable(
      !reset.asBool,
      io.trace.events.pad(32),
      io.trace.stallEvents.pad(32),
      io.trace.ifuCorrection,
      io.trace.fetchQueueOccupancy,
      io.trace.fetchQueueEnqueueWidth,
      io.trace.fetchQueueDequeueWidth,
      io.trace.icacheLookupValid,
      io.trace.icacheBlockValidMask.pad(32),
      io.trace.icacheMissMask.pad(32),
      io.trace.icacheBlockAddr(0),
      io.trace.icacheBlockAddr(1)
    )
  }
}
