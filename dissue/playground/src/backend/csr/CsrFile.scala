package top.backend.csr

import chisel3._
import top.config.BackendConfig

class CsrFile(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         BackendConfig = BackendConfig())
    extends Module {
  val io = IO(new CsrFileIO(cfg))

  private val resetValues = CsrArch.resetValues(cfg)

  private val mepc          = RegInit(resetValues.mepc)
  private val sepc          = RegInit(resetValues.sepc)
  private val misa          = RegInit(resetValues.misa)
  private val mstatus       = RegInit(resetValues.mstatus)
  private val mstatush      = RegInit(resetValues.mstatush)
  private val mcause        = RegInit(resetValues.mcause)
  private val mtval         = RegInit(resetValues.mtval)
  private val mtvec         = RegInit(resetValues.mtvec)
  private val mscratch      = RegInit(resetValues.mscratch)
  private val satp          = RegInit(resetValues.satp)
  private val medeleg       = RegInit(resetValues.medeleg)
  private val mideleg       = RegInit(resetValues.mideleg)
  private val mvendorid     = RegInit(resetValues.mvendorid)
  private val marchid       = RegInit(resetValues.marchid)
  private val mhartid       = RegInit(resetValues.mhartid)
  private val mimpid        = RegInit(resetValues.mimpid)
  private val pmpaddr0      = RegInit(resetValues.pmpaddr0)
  private val pmpaddr1      = RegInit(resetValues.pmpaddr1)
  private val pmpaddr2      = RegInit(resetValues.pmpaddr2)
  private val pmpaddr3      = RegInit(resetValues.pmpaddr3)
  private val pmpaddr4      = RegInit(resetValues.pmpaddr4)
  private val pmpaddr5      = RegInit(resetValues.pmpaddr5)
  private val pmpaddr6      = RegInit(resetValues.pmpaddr6)
  private val pmpaddr7      = RegInit(resetValues.pmpaddr7)
  private val pmpcfg0       = RegInit(resetValues.pmpcfg0)
  private val pmpcfg1       = RegInit(resetValues.pmpcfg1)
  private val scause        = RegInit(resetValues.scause)
  private val stval         = RegInit(resetValues.stval)
  private val sscratch      = RegInit(resetValues.sscratch)
  private val stvec         = RegInit(resetValues.stvec)
  private val mie           = RegInit(resetValues.mie)
  private val mcounteren    = RegInit(resetValues.mcounteren)
  private val scounteren    = RegInit(resetValues.scounteren)
  private val mcountinhibit = RegInit(resetValues.mcountinhibit)
  private val mip           = RegInit(resetValues.mip)
  private val mcycle        = RegInit(resetValues.mcycle)
  private val minstret      = RegInit(resetValues.minstret)
  private val priv          = RegInit(PrivMode.M)

  private val current = CsrArchValues(
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

  private val committed = CsrArch.commitValues(current, io.commit, cfg)
  private val nextArch  = CsrArch.nextValues(current, io.commit, io.trap, io.mret, priv, cfg)
  private val next      = CsrArch.countedValues(nextArch, io.retireCount, cfg)

  io.read.data       := CsrArch.readValue(io.read.addr, next, cfg)
  io.read.readLegal  := CsrArch.readLegal(io.read.addr, priv)
  io.read.writeLegal := CsrArch.writeLegal(io.read.addr, priv)

  mepc          := next.mepc
  sepc          := next.sepc
  misa          := next.misa
  mstatus       := next.mstatus
  mstatush      := next.mstatush
  mcause        := next.mcause
  mtval         := next.mtval
  mtvec         := next.mtvec
  mscratch      := next.mscratch
  satp          := next.satp
  medeleg       := next.medeleg
  mideleg       := next.mideleg
  mvendorid     := next.mvendorid
  marchid       := next.marchid
  mhartid       := next.mhartid
  mimpid        := next.mimpid
  pmpaddr0      := next.pmpaddr0
  pmpaddr1      := next.pmpaddr1
  pmpaddr2      := next.pmpaddr2
  pmpaddr3      := next.pmpaddr3
  pmpaddr4      := next.pmpaddr4
  pmpaddr5      := next.pmpaddr5
  pmpaddr6      := next.pmpaddr6
  pmpaddr7      := next.pmpaddr7
  pmpcfg0       := next.pmpcfg0
  pmpcfg1       := next.pmpcfg1
  scause        := next.scause
  stval         := next.stval
  sscratch      := next.sscratch
  stvec         := next.stvec
  mie           := next.mie
  mcounteren    := next.mcounteren
  scounteren    := next.scounteren
  mcountinhibit := next.mcountinhibit
  mip           := next.mip
  mcycle        := next.mcycle
  minstret      := next.minstret

  when(io.trap.valid) {
    priv := Mux(io.trap.toSupervisor, PrivMode.S, PrivMode.M)
  }.elsewhen(io.mret.valid) {
    priv := CsrArch.mretPriv(committed.mstatus)
  }

  io.status.priv.mode  := priv
  io.status.mretTarget := committed.mepc
  io.status.mtvec      := committed.mtvec
  io.status.stvec      := committed.stvec
  io.status.medeleg    := committed.medeleg
  io.status.mideleg    := committed.mideleg
}
