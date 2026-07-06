package top.sim

import chisel3._
import chisel3.util.Cat
import top.config.BackendConfig

class DifftestCsrState(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val mstatus       = UInt(cfg.dataWidth.W)
  val mtvec         = UInt(cfg.dataWidth.W)
  val mepc          = UInt(cfg.dataWidth.W)
  val mcause        = UInt(cfg.dataWidth.W)
  val mtval         = UInt(cfg.dataWidth.W)
  val mie           = UInt(cfg.dataWidth.W)
  val mip           = UInt(cfg.dataWidth.W)
  val mscratch      = UInt(cfg.dataWidth.W)
  val mcycle        = UInt(cfg.dataWidth.W)
  val minstret      = UInt(cfg.dataWidth.W)
  val sepc          = UInt(cfg.dataWidth.W)
  val misa          = UInt(cfg.dataWidth.W)
  val mstatush      = UInt(cfg.dataWidth.W)
  val satp          = UInt(cfg.dataWidth.W)
  val medeleg       = UInt(cfg.dataWidth.W)
  val mideleg       = UInt(cfg.dataWidth.W)
  val mvendorid     = UInt(cfg.dataWidth.W)
  val marchid       = UInt(cfg.dataWidth.W)
  val mhartid       = UInt(cfg.dataWidth.W)
  val mimpid        = UInt(cfg.dataWidth.W)
  val pmpaddr0      = UInt(cfg.dataWidth.W)
  val pmpaddr1      = UInt(cfg.dataWidth.W)
  val pmpaddr2      = UInt(cfg.dataWidth.W)
  val pmpaddr3      = UInt(cfg.dataWidth.W)
  val pmpaddr4      = UInt(cfg.dataWidth.W)
  val pmpaddr5      = UInt(cfg.dataWidth.W)
  val pmpaddr6      = UInt(cfg.dataWidth.W)
  val pmpaddr7      = UInt(cfg.dataWidth.W)
  val pmpcfg0       = UInt(cfg.dataWidth.W)
  val pmpcfg1       = UInt(cfg.dataWidth.W)
  val scause        = UInt(cfg.dataWidth.W)
  val stval         = UInt(cfg.dataWidth.W)
  val sscratch      = UInt(cfg.dataWidth.W)
  val stvec         = UInt(cfg.dataWidth.W)
  val mcounteren    = UInt(cfg.dataWidth.W)
  val scounteren    = UInt(cfg.dataWidth.W)
  val mcountinhibit = UInt(cfg.dataWidth.W)

  def packed: UInt =
    Cat(
      mcountinhibit,
      scounteren,
      mcounteren,
      stvec,
      sscratch,
      stval,
      scause,
      pmpcfg1,
      pmpcfg0,
      pmpaddr7,
      pmpaddr6,
      pmpaddr5,
      pmpaddr4,
      pmpaddr3,
      pmpaddr2,
      pmpaddr1,
      pmpaddr0,
      mimpid,
      mhartid,
      marchid,
      mvendorid,
      mideleg,
      medeleg,
      satp,
      mstatush,
      misa,
      sepc,
      minstret,
      mcycle,
      mscratch,
      mip,
      mie,
      mtval,
      mcause,
      mepc,
      mtvec,
      mstatus
    )
}

class DifftestCpuContext(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
  val pc    = UInt(cfg.addrWidth.W)
  val priv  = UInt(2.W)
  val csr   = new DifftestCsrState(cfg)
  val gpr   = Vec(32, UInt(cfg.dataWidth.W))

  def gprPacked: UInt = gpr.asUInt
}
