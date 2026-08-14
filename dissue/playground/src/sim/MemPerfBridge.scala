package top.sim

import chisel3._
import top.config.{BackendConfig, DCacheConfig}
import top.core.backend.bundle.BackendMemPerf
import top.core.bundle.MemPerfEvent
import top.core.mem.DCachePerf
import top.dpi.NpcMemPerf

/** Aggregates memory-system events into one DPI sample per active cycle.
  *
  * Event bit-packing lives here on purpose: the producers export plain named bundles (Mem's DCachePerf, Backend's
  * BackendMemPerf) and the integration layer connects them with bulk-connect. With enableDpi = false the module
  * elaborates to an empty shell, so the synthesis view contains no DPI.
  */
class MemPerfBridge(
  dcacheCfg:  DCacheConfig = DCacheConfig(),
  backendCfg: BackendConfig = BackendConfig(),
  enableDpi:  Boolean = true)
    extends Module {
  val io = IO(new Bundle {
    val memTrace     = Input(new DCachePerf(dcacheCfg))
    val backendTrace = Input(new BackendMemPerf(backendCfg))
  })

  private val events = Seq(
    MemPerfEvent.bit(MemPerfEvent.dcacheAccess, io.memTrace.access),
    MemPerfEvent.bit(MemPerfEvent.dcacheHit, io.memTrace.hit),
    MemPerfEvent.bit(MemPerfEvent.dcacheMiss, io.memTrace.miss),
    MemPerfEvent.bit(MemPerfEvent.dcacheBypass, io.memTrace.bypass),
    MemPerfEvent.bit(MemPerfEvent.mshrAlloc, io.memTrace.mshrAlloc),
    MemPerfEvent.bit(MemPerfEvent.mshrMerge, io.memTrace.mshrMerge),
    MemPerfEvent.bit(MemPerfEvent.mshrFullStallCycle, io.memTrace.mshrFullStall),
    MemPerfEvent.bit(MemPerfEvent.hitUnderMiss, io.memTrace.hitUnderMiss),
    MemPerfEvent.bit(MemPerfEvent.queuedMiss, io.memTrace.queuedMiss),
    MemPerfEvent.bit(MemPerfEvent.refillStart, io.memTrace.refillStart),
    MemPerfEvent.bit(MemPerfEvent.refillComplete, io.memTrace.refillComplete),
    MemPerfEvent.bit(MemPerfEvent.refillFault, io.memTrace.refillFault),
    MemPerfEvent.bit(MemPerfEvent.loadTxnFullStallCycle, io.backendTrace.loadTxnFullStall),
    MemPerfEvent.bit(MemPerfEvent.sqAlloc, io.backendTrace.sqAlloc),
    MemPerfEvent.bit(MemPerfEvent.sqFullStallCycle, io.backendTrace.sqFullStall),
    MemPerfEvent.bit(MemPerfEvent.forwardFull, io.backendTrace.forwardFull),
    MemPerfEvent.bit(MemPerfEvent.forwardPartial, io.backendTrace.forwardPartial),
    MemPerfEvent.bit(MemPerfEvent.forwardUnresolvedStallCycle, io.backendTrace.forwardUnresolvedStoreStall),
    MemPerfEvent.bit(MemPerfEvent.storeDrain, io.backendTrace.storeDrain),
    MemPerfEvent.bit(MemPerfEvent.storeCommit, io.backendTrace.storeCommit),
    MemPerfEvent.bit(MemPerfEvent.storeResponse, io.backendTrace.storeResponse)
  ).reduce(_ | _)

  if (enableDpi) {
    NpcMemPerf.callWithEnable(
      !reset.asBool,
      events.pad(32),
      io.memTrace.mshrOccupancy.pad(32),
      io.backendTrace.sqOccupancy.pad(32),
      io.backendTrace.loadTxnOccupancy.pad(32)
    )
  }
}
