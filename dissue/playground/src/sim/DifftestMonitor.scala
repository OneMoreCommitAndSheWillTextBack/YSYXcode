package top.sim

import chisel3._
import chisel3.util.{MuxCase, Valid}
import top.backend.bundle.{CommitRegWrite, RetireGroup}
import top.backend.csr.{CsrArch, CsrArchValues, CsrCommit, CsrContextUpdate, CsrMretCommit, CsrTrapCommit, PrivMode}
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
    val context   = Input(new CsrContextUpdate(cfg))
  })

  private val gpr = RegInit(VecInit(Seq.fill(32)(0.U(cfg.dataWidth.W))))

  private val resetCsr = CsrArch.resetValues(cfg)
  private val mstatus  = RegInit(resetCsr.mstatus)
  private val mtvec    = RegInit(resetCsr.mtvec)
  private val mepc     = RegInit(resetCsr.mepc)
  private val mcause   = RegInit(resetCsr.mcause)
  private val mtval    = RegInit(resetCsr.mtval)
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

  private val currentCsr = CsrArchValues(mstatus, mtvec, mepc, mcause, mtval)
  private val committedCsr = CsrArch.commitValues(currentCsr, io.csrCommit, cfg)
  private val nextCsr    = CsrArch.nextValues(currentCsr, io.csrCommit, io.csrTrap, io.csrMret, priv, cfg)
  private val nextPriv   = Mux(io.csrTrap.valid, PrivMode.M, Mux(io.csrMret.valid, CsrArch.mretPriv(committedCsr.mstatus), priv))
  private val nextPc     = Mux(io.context.valid, io.context.pc, pc)

  private val hasCommit    = io.retire.validMask.orR
  private val reportContext = Wire(new DifftestCpuContext(cfg))

  reportContext.valid := reset.asBool || hasCommit
  reportContext.pc    := Mux(reset.asBool, resetVector.U(cfg.addrWidth.W), nextPc)
  reportContext.priv  := Mux(reset.asBool, PrivMode.M, nextPriv)
  for (idx <- 0 until 32) {
    reportContext.gpr(idx) := Mux(reset.asBool, 0.U, nextGpr(idx))
  }
  reportContext.csr.mstatus  := Mux(reset.asBool, resetCsr.mstatus, nextCsr.mstatus)
  reportContext.csr.mtvec    := Mux(reset.asBool, resetCsr.mtvec, nextCsr.mtvec)
  reportContext.csr.mepc     := Mux(reset.asBool, resetCsr.mepc, nextCsr.mepc)
  reportContext.csr.mcause   := Mux(reset.asBool, resetCsr.mcause, nextCsr.mcause)
  reportContext.csr.mtval    := Mux(reset.asBool, resetCsr.mtval, nextCsr.mtval)
  reportContext.csr.mie      := 0.U
  reportContext.csr.mip      := 0.U
  reportContext.csr.mscratch := 0.U
  reportContext.csr.mcycle   := 0.U
  reportContext.csr.minstret := 0.U

  private val bridge = Module(new DifftestBridge(cfg))
  bridge.io.retire  := io.retire
  bridge.io.context := reportContext

  when(hasCommit) {
    gpr     := nextGpr
    mstatus := nextCsr.mstatus
    mtvec   := nextCsr.mtvec
    mepc    := nextCsr.mepc
    mcause  := nextCsr.mcause
    mtval   := nextCsr.mtval
    priv    := nextPriv
    pc      := nextPc
  }
}
