package top.sim

import chisel3._
import chisel3.util.Valid
import top.core.trace.PipelineTraceEvent
import top.dpi.NpcPipelineTrace

/** Serializes independent semantic events into DPI calls without introducing backpressure. */
class PipelineTraceBridge(eventCount: Int) extends Module {
  require(eventCount > 0, "PipelineTraceBridge requires at least one event input")

  val io = IO(new Bundle {
    val events = Input(Vec(eventCount, Valid(new PipelineTraceEvent)))
  })

  for (event <- io.events) {
    NpcPipelineTrace.callWithEnable(
      event.valid && !reset.asBool,
      event.bits.kind,
      event.bits.flags,
      event.bits.slot,
      event.bits.robIdx,
      event.bits.producer0,
      event.bits.producer1,
      event.bits.pc,
      event.bits.inst,
      event.bits.rawInst,
      event.bits.sequence,
      event.bits.epoch,
      event.bits.resource,
      event.bits.txnId
    )
  }
}
