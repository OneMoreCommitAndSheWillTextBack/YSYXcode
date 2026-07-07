package top.sim

import chisel3._
import chisel3.util.Cat
import top.backend.csr.CsrSpec
import top.config.BackendConfig

class DifftestCsrState(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val values = Vec(CsrSpec.difftestExport.size, UInt(cfg.dataWidth.W))

  def packed: UInt =
    Cat((0 until CsrSpec.difftestExport.size).reverse.map(values(_)))
}

class DifftestCpuContext(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
  val pc    = UInt(cfg.addrWidth.W)
  val priv  = UInt(2.W)
  val csr   = new DifftestCsrState(cfg)
  val gpr   = Vec(32, UInt(cfg.dataWidth.W))

  def gprPacked: UInt = gpr.asUInt
}
