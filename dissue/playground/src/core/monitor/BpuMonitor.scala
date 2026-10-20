package top.core.monitor

import chisel3._

class TaggedPredictorMonitor extends Bundle {
  val provider          = Bool()
  val alternateDisagree = Bool()
  val allocation        = Bool()
  val usefulnessAging   = Bool()
}

class BpuMonitor extends Bundle {
  val push              = Bool()
  val pop               = Bool()
  val popThenPush       = Bool()
  val use               = Bool()
  val hit               = Bool()
  val miss              = Bool()
  val underflow         = Bool()
  val overflow          = Bool()
  val checkpointRestore = Bool()
  val recoveryDiscard   = Bool()
  val taggedProvider    = Bool()
  val alternateDisagree = Bool()
  val allocation        = Bool()
  val usefulnessAging   = Bool()
  val lateOverride      = Bool()
}
