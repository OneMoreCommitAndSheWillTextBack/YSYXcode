package top.core.monitor

import chisel3._
import top.config.BackendConfig

/** Read-only observation boundary for the data TLB.
  *
  * The bundle exports transaction events and backpressure levels only. It deliberately carries no counters or control
  * signals: observers count `fire` events and sample levels, and nothing in this bundle may influence TLB state or
  * handshakes. When monitoring is disabled at elaboration time the TLB drives the whole bundle to zero.
  */
class TlbMonitor(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val request       = Bool()
  val hit           = Bool()
  val miss          = Bool()
  val superpageHit  = Bool()
  val response      = Bool()
  val complete      = Bool()
  val walkStart     = Bool()
  val refill        = Bool()
  val refillFault   = Bool()
  val sfence        = Bool()
  val flush         = Bool()
  val reqStall      = Bool()
  val refillStall   = Bool()
  val occupancy     = UInt(cfg.dtlbCountWidth.W)
  val missOccupancy = UInt(cfg.dtlbMissQueueCountWidth.W)
}
