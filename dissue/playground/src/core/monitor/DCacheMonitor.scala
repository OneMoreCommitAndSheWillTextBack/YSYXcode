package top.core.monitor

import chisel3._
import top.config.DCacheConfig

class DCacheMonitor(cfg: DCacheConfig) extends Bundle {
  val access         = Bool()
  val hit            = Bool()
  val miss           = Bool()
  val bypass         = Bool()
  val mshrAlloc      = Bool()
  val mshrMerge      = Bool()
  val mshrFullStall  = Bool()
  val hitUnderMiss   = Bool()
  val queuedMiss     = Bool()
  val refillStart    = Bool()
  val refillComplete = Bool()
  val refillFault    = Bool()
  val mshrOccupancy  = UInt(math.max(chisel3.util.log2Ceil(cfg.mshrEntries + 1), 1).W)
}
