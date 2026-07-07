package top.sim

import chisel3._
import top.backend.bundle.RetireGroup
import top.config.BackendConfig
import top.dpi.{NpcCacheHit, NpcDifftestCommit, NpcDifftestContext}

class DifftestBridge(cfg: BackendConfig = BackendConfig()) extends Module {
  require(cfg.commitWidth == 2, "Difftest DPI currently exposes exactly two retire lanes")

  val io = IO(new Bundle {
    val retire  = Input(new RetireGroup(cfg))
    val context = Input(new DifftestCpuContext(cfg))
  })

  private val validMask  = io.retire.validMask.pad(32)
  private val finishMask = io.retire.finishMask.pad(32)
  private val memValidMask =
    VecInit((0 until cfg.commitWidth).map(i => io.retire.lanes(i).memory.valid)).asUInt.pad(32)
  private val memWriteMask =
    VecInit((0 until cfg.commitWidth).map(i => io.retire.lanes(i).memory.write)).asUInt.pad(32)

  NpcDifftestCommit.callWithEnable(
    io.retire.validMask.orR,
    validMask,
    finishMask,
    memValidMask,
    memWriteMask,
    io.retire.lanes(0).fetch.pc,
    io.retire.lanes(0).fetch.inst,
    io.retire.lanes(0).fetch.rawInst,
    io.retire.lanes(0).fetch.instLen.pad(32),
    io.retire.lanes(0).nextPc,
    io.retire.lanes(0).memory.addr,
    io.retire.lanes(0).memory.size.pad(32),
    io.retire.lanes(1).fetch.pc,
    io.retire.lanes(1).fetch.inst,
    io.retire.lanes(1).fetch.rawInst,
    io.retire.lanes(1).fetch.instLen.pad(32),
    io.retire.lanes(1).nextPc,
    io.retire.lanes(1).memory.addr,
    io.retire.lanes(1).memory.size.pad(32)
  )

  NpcDifftestContext.callWithEnable(
    io.context.valid,
    Mux(io.context.valid, 1.U(32.W), 0.U(32.W)),
    io.context.pc,
    io.context.priv.pad(32),
    io.context.csr.packed,
    io.context.gprPacked
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
