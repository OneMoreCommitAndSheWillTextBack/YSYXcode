package top.core.monitor

import chisel3._
import top.config.BackendConfig

class BackendMemPerf(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val sqAlloc                     = Bool()
  val sqFullStall                 = Bool()
  val forwardFull                 = Bool()
  val forwardPartial              = Bool()
  val forwardUnresolvedStoreStall = Bool()
  val storeCommit                 = Bool()
  val storeDrain                  = Bool()
  val storeResponse               = Bool()
  val loadTxnFullStall            = Bool()
  val sqOccupancy                 = UInt(math.max(chisel3.util.log2Ceil(cfg.storeQueueEntries + 1), 1).W)
  val loadTxnOccupancy            = UInt(math.max(chisel3.util.log2Ceil(cfg.loadTxnEntries + 1), 1).W)
}
