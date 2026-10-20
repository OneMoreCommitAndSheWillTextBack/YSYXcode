package top.core.monitor

import chisel3._
import chisel3.util.Valid
import top.config.FrontendConfig
import top.core.frontend.bundle.{
  FrontendRecovery,
  ICacheFetchReq,
  ICacheFetchResp,
  ICacheLookupResult,
  ICacheRefillReq,
  ICacheRefillResp,
  PcRedirect
}
import top.core.frontend.ifetch.{FetchQueueEnqueue, FetchWidth}

/** Composition-level frontend observation bundle.
  *
  * Filled only when the parent enables monitoring. It contains no logic that can affect the functional handshakes.
  */
class FrontendMonitor(cfg: FrontendConfig) extends Bundle {
  val backendRedirect = new PcRedirect
  val pcRedirect      = new PcRedirect
  val invalidate      = Bool()
  val recovery        = Valid(new FrontendRecovery(cfg))

  val fetchValid = Bool()
  val fetchReady = Bool()

  val fetchQueueEnqueue = new MonitorTap(new FetchQueueEnqueue(cfg, FetchWidth.frontend))

  val alignerOutputBackpressure = Bool()
  val blockBufferBackpressure   = Bool()
  val ftqReserveBackpressure    = Bool()

  val refillPhysicalReqValid = Bool()
  val refillPhysicalReqReady = Bool()

  val icacheReq        = new MonitorTap(new ICacheFetchReq(cfg))
  val icacheResp       = new MonitorTap(new ICacheFetchResp(cfg))
  val icacheRefillReq  = new MonitorTap(new ICacheRefillReq(cfg.addrWidth))
  val icacheRefillResp = new MonitorTap(new ICacheRefillResp(cfg.icacheLineBytes))
  val icacheLookup     = Valid(new ICacheLookupResult(cfg))

  val bpu          = new BpuMonitor
  val ifuStaleDrop = Bool()

  val fetchQueueEmpty        = Bool()
  val fetchQueueFull         = Bool()
  val fetchQueueOccupancy    = UInt(32.W)
  val fetchQueueEnqueueWidth = UInt(32.W)
  val fetchQueueDequeueWidth = UInt(32.W)
}
