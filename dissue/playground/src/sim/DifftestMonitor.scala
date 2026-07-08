package top.sim

import chisel3._
import chisel3.util.{MuxCase, PopCount, Valid}
import top.core.backend.bundle.{CommitRegWrite, RetireGroup}
import top.core.backend.csr.{
  CsrArch,
  CsrArchValues,
  CsrAddr,
  CsrCommit,
  CsrContextUpdate,
  CsrMretCommit,
  CsrSpec,
  CsrSretCommit,
  CsrTrapCommit,
  PrivMode
}
import top.config.BackendConfig

class DifftestMonitor(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         BackendConfig = BackendConfig())
    extends Module {
  val io = IO(new Bundle {
    val retire    = Input(new RetireGroup(cfg))
    val regWrite  = Input(Vec(cfg.commitWidth, new CommitRegWrite(cfg)))
    val csrCommit = Input(Vec(cfg.commitWidth, Valid(new CsrCommit(cfg))))
    val csrTrap   = Input(new CsrTrapCommit(cfg))
    val csrMret   = Input(new CsrMretCommit(cfg))
    val csrSret   = Input(new CsrSretCommit(cfg))
    val context   = Input(new CsrContextUpdate(cfg))
  })

  private val gpr = RegInit(VecInit(Seq.fill(32)(0.U(cfg.dataWidth.W))))

  private val resetCsr = CsrArch.resetValues(cfg)
  private val csrRegs  = RegInit(VecInit(resetCsr.values))
  private val priv     = RegInit(PrivMode.M)
  private val pc       = RegInit(resetVector.U(cfg.addrWidth.W))

  private val nextGpr = Wire(Vec(32, UInt(cfg.dataWidth.W)))
  nextGpr(0) := 0.U
  for (idx <- 1 until 32) {
    val hits = io.regWrite.map(write => write.enable && write.addr === idx.U)
    nextGpr(idx) := MuxCase(
      gpr(idx),
      hits.zip(io.regWrite).reverse.map { case (hit, write) => hit -> write.data }
    )
  }

  private val currentCsr = CsrArchValues.fromVec(csrRegs)

  private val retireCount  = PopCount(io.retire.validMask)
  private val committedCsr = CsrArch.commitValues(currentCsr, io.csrCommit, cfg)
  private val archNextCsr  = CsrArch.nextValues(currentCsr, io.csrCommit, io.csrTrap, io.csrMret, io.csrSret, priv, cfg)
  private val nextCsr      = CsrArch.countedValues(archNextCsr, retireCount, cfg)
  private val nextPriv     =
    Mux(
      io.csrTrap.valid,
      Mux(io.csrTrap.toSupervisor, PrivMode.S, PrivMode.M),
      Mux(
        io.csrMret.valid,
        CsrArch.mretPriv(committedCsr(CsrAddr.of("mstatus"))),
        Mux(io.csrSret.valid, CsrArch.sretPriv(committedCsr(CsrAddr.of("mstatus"))), priv)
      )
    )
  private val nextPc       = Mux(io.context.valid, io.context.pc, pc)

  private def writeCsrReport(report: DifftestCsrState, values: CsrArchValues): Unit = {
    for ((name, idx) <- CsrSpec.difftestExport.zipWithIndex) {
      report.values(idx) := values(name)
    }
  }

  private val hasCommit     = io.retire.validMask.orR
  private val reportContext = Wire(new DifftestCpuContext(cfg))

  reportContext.valid := reset.asBool || hasCommit
  reportContext.pc    := Mux(reset.asBool, resetVector.U(cfg.addrWidth.W), nextPc)
  reportContext.priv  := Mux(reset.asBool, PrivMode.M, nextPriv)
  for (idx <- 0 until 32) {
    reportContext.gpr(idx) := Mux(reset.asBool, 0.U, nextGpr(idx))
  }
  writeCsrReport(reportContext.csr, nextCsr)
  when(reset.asBool) {
    writeCsrReport(reportContext.csr, resetCsr)
  }

  private val bridge = Module(new DifftestBridge(cfg))
  bridge.io.retire  := io.retire
  bridge.io.context := reportContext

  when(hasCommit) {
    gpr     := nextGpr
    csrRegs := VecInit(nextCsr.values)
    priv    := nextPriv
    pc      := nextPc
  }.otherwise {
    csrRegs(CsrSpec.stateIndex("mcycle"))   := nextCsr("mcycle")
    csrRegs(CsrSpec.stateIndex("minstret")) := nextCsr("minstret")
  }
}
