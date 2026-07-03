package top.sim

import chisel3._
import top.backend.bundle.RetireGroup
import top.config.BackendConfig
import top.dpi.{NpcCacheHit, NpcCommitGroup}

class DifftestBridge(cfg: BackendConfig = BackendConfig()) extends Module {
  require(cfg.commitWidth == 2, "NpcCommitGroup DPI currently exposes exactly two retire lanes")

  val io = IO(new Bundle {
    val retire = Input(new RetireGroup(cfg))
  })

  private val validMask  = io.retire.validMask.pad(32)
  private val finishMask = io.retire.finishMask.pad(32)

  NpcCommitGroup.callWithEnable(
    io.retire.validMask.orR,
    validMask,
    finishMask,
    io.retire.lanes(0).fetch.pc,
    io.retire.lanes(0).fetch.inst,
    io.retire.lanes(1).fetch.pc,
    io.retire.lanes(1).fetch.inst
  )
}

class CacheHitBridge extends Module {
  val io = IO(new Bundle {
    val cacheFire = Input(Bool())
    val cacheHit  = Input(Bool())
  })

  NpcCacheHit.callWithEnable(
    io.cacheFire,
    io.cacheHit
  )
}
