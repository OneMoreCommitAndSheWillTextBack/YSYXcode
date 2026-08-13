package top.core.trace

import chisel3._
import chisel3.util.{Cat, Valid}
import top.config.FrontendConfig
import top.core.frontend.ifetch.FetchQueueEnqueue

/** Observes the exact point where instructions acquire FetchQueue lifetime. */
class IfuTrace(cfg: FrontendConfig, enqueueWidth: Int) extends Module {
  val io = IO(new Bundle {
    val enqueue = Input(new DecoupledTraceTap(new FetchQueueEnqueue(cfg, enqueueWidth)))
    val events  = Output(Vec(enqueueWidth, Valid(new PipelineTraceEvent)))
  })

  for (lane <- 0 until enqueueWidth) {
    val entry = io.enqueue.bits.insts(lane)
    io.events(lane)       := 0.U.asTypeOf(Valid(new PipelineTraceEvent))
    io.events(lane).valid := io.enqueue.fire && entry.valid
    io.events(lane).bits  := PipelineTraceEventBuilder.instruction(
      PipelineTraceKind.fetchQueueEnqueue,
      lane,
      entry.bits.inst.pc,
      entry.bits.inst.inst,
      entry.bits.inst.rawInst,
      Cat(entry.bits.inst.ftqTag.generation, entry.bits.inst.ftqTag.index, entry.bits.inst.ftqInstOrdinal),
      0.U
    )
  }
}
