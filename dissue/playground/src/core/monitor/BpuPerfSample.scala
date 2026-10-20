package top.core.monitor

import chisel3._
import top.core.bundle.BpuCfiClass

/** Passive retirement-side BPU accuracy sample. */
class BpuPerfSample extends Bundle {
  val valid       = Bool()
  val cfiClass    = UInt(BpuCfiClass.width.W)
  val predHit     = Bool()
  val predTaken   = Bool()
  val actualTaken = Bool()
  val correct     = Bool()
}
