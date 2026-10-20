package top.core.monitor

import chisel3._
import top.config.BackendConfig

class StoreQueueMonitor(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val alloc     = Bool()
  val fullStall = Bool()
  val commit    = Bool()
  val request   = Bool()
  val response  = Bool()
  val occupancy = UInt(math.max(chisel3.util.log2Ceil(cfg.storeQueueEntries + 1), 1).W)
}
