package top.sim

import chisel3._
import chisel3.util.{MuxCase, PopCount, Valid}
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

  private val resetCsr      = CsrArch.resetValues(cfg)
  private val mepc          = RegInit(resetCsr.mepc)
  private val sepc          = RegInit(resetCsr.sepc)
  private val misa          = RegInit(resetCsr.misa)
  private val mstatus       = RegInit(resetCsr.mstatus)
  private val mstatush      = RegInit(resetCsr.mstatush)
  private val mcause        = RegInit(resetCsr.mcause)
  private val mtval         = RegInit(resetCsr.mtval)
  private val mtvec         = RegInit(resetCsr.mtvec)
  private val mscratch      = RegInit(resetCsr.mscratch)
  private val satp          = RegInit(resetCsr.satp)
  private val medeleg       = RegInit(resetCsr.medeleg)
  private val mideleg       = RegInit(resetCsr.mideleg)
  private val mvendorid     = RegInit(resetCsr.mvendorid)
  private val marchid       = RegInit(resetCsr.marchid)
  private val mhartid       = RegInit(resetCsr.mhartid)
  private val mimpid        = RegInit(resetCsr.mimpid)
  private val pmpaddr0      = RegInit(resetCsr.pmpaddr0)
  private val pmpaddr1      = RegInit(resetCsr.pmpaddr1)
  private val pmpaddr2      = RegInit(resetCsr.pmpaddr2)
  private val pmpaddr3      = RegInit(resetCsr.pmpaddr3)
  private val pmpaddr4      = RegInit(resetCsr.pmpaddr4)
  private val pmpaddr5      = RegInit(resetCsr.pmpaddr5)
  private val pmpaddr6      = RegInit(resetCsr.pmpaddr6)
  private val pmpaddr7      = RegInit(resetCsr.pmpaddr7)
  private val pmpcfg0       = RegInit(resetCsr.pmpcfg0)
  private val pmpcfg1       = RegInit(resetCsr.pmpcfg1)
  private val scause        = RegInit(resetCsr.scause)
  private val stval         = RegInit(resetCsr.stval)
  private val sscratch      = RegInit(resetCsr.sscratch)
  private val stvec         = RegInit(resetCsr.stvec)
  private val mie           = RegInit(resetCsr.mie)
  private val mcounteren    = RegInit(resetCsr.mcounteren)
  private val scounteren    = RegInit(resetCsr.scounteren)
  private val mcountinhibit = RegInit(resetCsr.mcountinhibit)
  private val mip           = RegInit(resetCsr.mip)
  private val mcycle        = RegInit(resetCsr.mcycle)
  private val minstret      = RegInit(resetCsr.minstret)
  private val priv          = RegInit(PrivMode.M)
  private val pc            = RegInit(resetVector.U(cfg.addrWidth.W))

  private val nextGpr = Wire(Vec(32, UInt(cfg.dataWidth.W)))
  nextGpr(0) := 0.U
  for (idx <- 1 until 32) {
    val hits = io.regWrite.map(write => write.enable && write.addr === idx.U)
    nextGpr(idx) := MuxCase(
      gpr(idx),
      hits.zip(io.regWrite).reverse.map { case (hit, write) => hit -> write.data }
    )
  }

  private val currentCsr = CsrArchValues(
    mepc = mepc,
    sepc = sepc,
    misa = misa,
    mstatus = mstatus,
    mstatush = mstatush,
    mcause = mcause,
    mtval = mtval,
    mtvec = mtvec,
    mscratch = mscratch,
    satp = satp,
    medeleg = medeleg,
    mideleg = mideleg,
    mvendorid = mvendorid,
    marchid = marchid,
    mhartid = mhartid,
    mimpid = mimpid,
    pmpaddr0 = pmpaddr0,
    pmpaddr1 = pmpaddr1,
    pmpaddr2 = pmpaddr2,
    pmpaddr3 = pmpaddr3,
    pmpaddr4 = pmpaddr4,
    pmpaddr5 = pmpaddr5,
    pmpaddr6 = pmpaddr6,
    pmpaddr7 = pmpaddr7,
    pmpcfg0 = pmpcfg0,
    pmpcfg1 = pmpcfg1,
    scause = scause,
    stval = stval,
    sscratch = sscratch,
    stvec = stvec,
    mie = mie,
    mcounteren = mcounteren,
    scounteren = scounteren,
    mcountinhibit = mcountinhibit,
    mip = mip,
    mcycle = mcycle,
    minstret = minstret
  )

  private val retireCount  = PopCount(io.retire.validMask)
  private val committedCsr = CsrArch.commitValues(currentCsr, io.csrCommit, cfg)
  private val archNextCsr  = CsrArch.nextValues(currentCsr, io.csrCommit, io.csrTrap, io.csrMret, priv, cfg)
  private val nextCsr      = CsrArch.countedValues(archNextCsr, retireCount, cfg)
  private val nextPriv     =
    Mux(
      io.csrTrap.valid,
      Mux(io.csrTrap.toSupervisor, PrivMode.S, PrivMode.M),
      Mux(io.csrMret.valid, CsrArch.mretPriv(committedCsr.mstatus), priv)
    )
  private val nextPc       = Mux(io.context.valid, io.context.pc, pc)

  private def writeCsrReport(report: DifftestCsrState, values: CsrArchValues): Unit = {
    report.mstatus       := values.mstatus
    report.mtvec         := values.mtvec
    report.mepc          := values.mepc
    report.mcause        := values.mcause
    report.mtval         := values.mtval
    report.mie           := values.mie
    report.mip           := values.mip
    report.mscratch      := values.mscratch
    report.mcycle        := values.mcycle
    report.minstret      := values.minstret
    report.sepc          := values.sepc
    report.misa          := values.misa
    report.mstatush      := values.mstatush
    report.satp          := values.satp
    report.medeleg       := values.medeleg
    report.mideleg       := values.mideleg
    report.mvendorid     := values.mvendorid
    report.marchid       := values.marchid
    report.mhartid       := values.mhartid
    report.mimpid        := values.mimpid
    report.pmpaddr0      := values.pmpaddr0
    report.pmpaddr1      := values.pmpaddr1
    report.pmpaddr2      := values.pmpaddr2
    report.pmpaddr3      := values.pmpaddr3
    report.pmpaddr4      := values.pmpaddr4
    report.pmpaddr5      := values.pmpaddr5
    report.pmpaddr6      := values.pmpaddr6
    report.pmpaddr7      := values.pmpaddr7
    report.pmpcfg0       := values.pmpcfg0
    report.pmpcfg1       := values.pmpcfg1
    report.scause        := values.scause
    report.stval         := values.stval
    report.sscratch      := values.sscratch
    report.stvec         := values.stvec
    report.mcounteren    := values.mcounteren
    report.scounteren    := values.scounteren
    report.mcountinhibit := values.mcountinhibit
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
    gpr           := nextGpr
    mepc          := nextCsr.mepc
    sepc          := nextCsr.sepc
    misa          := nextCsr.misa
    mstatus       := nextCsr.mstatus
    mstatush      := nextCsr.mstatush
    mcause        := nextCsr.mcause
    mtval         := nextCsr.mtval
    mtvec         := nextCsr.mtvec
    mscratch      := nextCsr.mscratch
    satp          := nextCsr.satp
    medeleg       := nextCsr.medeleg
    mideleg       := nextCsr.mideleg
    mvendorid     := nextCsr.mvendorid
    marchid       := nextCsr.marchid
    mhartid       := nextCsr.mhartid
    mimpid        := nextCsr.mimpid
    pmpaddr0      := nextCsr.pmpaddr0
    pmpaddr1      := nextCsr.pmpaddr1
    pmpaddr2      := nextCsr.pmpaddr2
    pmpaddr3      := nextCsr.pmpaddr3
    pmpaddr4      := nextCsr.pmpaddr4
    pmpaddr5      := nextCsr.pmpaddr5
    pmpaddr6      := nextCsr.pmpaddr6
    pmpaddr7      := nextCsr.pmpaddr7
    pmpcfg0       := nextCsr.pmpcfg0
    pmpcfg1       := nextCsr.pmpcfg1
    scause        := nextCsr.scause
    stval         := nextCsr.stval
    sscratch      := nextCsr.sscratch
    stvec         := nextCsr.stvec
    mie           := nextCsr.mie
    mcounteren    := nextCsr.mcounteren
    scounteren    := nextCsr.scounteren
    mcountinhibit := nextCsr.mcountinhibit
    mip           := nextCsr.mip
    mcycle        := nextCsr.mcycle
    minstret      := nextCsr.minstret
    priv          := nextPriv
    pc            := nextPc
  }.otherwise {
    mcycle   := nextCsr.mcycle
    minstret := nextCsr.minstret
  }
}
