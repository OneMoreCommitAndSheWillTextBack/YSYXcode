package top.sim

import chisel3._
import top.config.BackendConfig
import top.core.backend.bundle.RetireGroup
import top.core.backend.csr.CsrTrapCommit
import top.core.bundle.BpuCfiClass
import top.dpi.{NpcBpuPerf, NpcDifftestCommit, NpcDifftestContext}

class DifftestBridge(cfg: BackendConfig = BackendConfig()) extends Module {
  require(cfg.commitWidth == 2, "Difftest DPI currently exposes exactly two retire lanes")

  val io = IO(new Bundle {
    val retire  = Input(new RetireGroup(cfg))
    val csrTrap = Input(new CsrTrapCommit(cfg))
    val context = Input(new DifftestCpuContext(cfg))
  })

  private val validMask      = io.retire.validMask.pad(32)
  private val finishMask     = io.retire.finishMask.pad(32)
  private val memValidMask   =
    VecInit((0 until cfg.commitWidth).map(i => io.retire.lanes(i).memory.valid)).asUInt.pad(32)
  private val memWriteMask   =
    VecInit((0 until cfg.commitWidth).map(i => io.retire.lanes(i).memory.write)).asUInt.pad(32)
  private val asyncIntrValid = io.csrTrap.valid && io.csrTrap.cause(cfg.dataWidth - 1)

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
    io.retire.lanes(1).memory.size.pad(32),
    Mux(asyncIntrValid, 1.U(32.W), 0.U(32.W)),
    io.csrTrap.cause,
    io.csrTrap.epc
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

class BpuPerfBridge extends Module {
  val io = IO(new Bundle {
    val valid       = Input(Bool())
    val cfiClass    = Input(UInt(BpuCfiClass.width.W))
    val predHit     = Input(Bool())
    val predTaken   = Input(Bool())
    val actualTaken = Input(Bool())
    val correct     = Input(Bool())
  })

  NpcBpuPerf.callWithEnable(
    io.valid,
    io.cfiClass.pad(32),
    io.predHit,
    io.predTaken,
    io.actualTaken,
    io.correct
  )
}
