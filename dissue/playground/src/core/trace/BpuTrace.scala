package top.core.trace

import chisel3._
import top.core.bundle.FrontendPerfEvent
import top.core.frontend.bundle.RasPerf

/** Converts passive predictor monitor pulses into the stable frontend performance ABI. */
class BpuTrace extends Module {
  val io = IO(new Bundle {
    val monitor = Input(new RasPerf)
    val events  = Output(UInt(FrontendPerfEvent.width.W))
  })

  io.events := Seq(
    FrontendPerfEvent.bit(FrontendPerfEvent.rasPush, io.monitor.push),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasPop, io.monitor.pop),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasPopThenPush, io.monitor.popThenPush),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasUse, io.monitor.use),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasHit, io.monitor.hit),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasMiss, io.monitor.miss),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasUnderflow, io.monitor.underflow),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasOverflow, io.monitor.overflow),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasCheckpointRestore, io.monitor.checkpointRestore),
    FrontendPerfEvent.bit(FrontendPerfEvent.rasRecoveryDiscard, io.monitor.recoveryDiscard),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageTaggedProvider, io.monitor.taggedProvider),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageAlternateDisagree, io.monitor.alternateDisagree),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageAllocation, io.monitor.allocation),
    FrontendPerfEvent.bit(FrontendPerfEvent.tageUsefulnessAging, io.monitor.usefulnessAging),
    FrontendPerfEvent.bit(FrontendPerfEvent.lateOverride, io.monitor.lateOverride)
  ).reduce(_ | _)
}
