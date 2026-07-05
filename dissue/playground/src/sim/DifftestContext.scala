package top.sim

import chisel3._
import chisel3.util.Cat
import top.config.BackendConfig

class DifftestCsrState(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val mstatus  = UInt(cfg.dataWidth.W)
  val mtvec    = UInt(cfg.dataWidth.W)
  val mepc     = UInt(cfg.dataWidth.W)
  val mcause   = UInt(cfg.dataWidth.W)
  val mtval    = UInt(cfg.dataWidth.W)
  val mie      = UInt(cfg.dataWidth.W)
  val mip      = UInt(cfg.dataWidth.W)
  val mscratch = UInt(cfg.dataWidth.W)
  val mcycle   = UInt(cfg.dataWidth.W)
  val minstret = UInt(cfg.dataWidth.W)

  def packed: UInt =
    Cat(
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
