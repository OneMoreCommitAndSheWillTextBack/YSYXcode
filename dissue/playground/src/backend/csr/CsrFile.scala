package top.backend.csr

import chisel3._
import top.config.BackendConfig

class CsrFile(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         BackendConfig = BackendConfig())
    extends Module {
  val io = IO(new CsrFileIO(cfg))

  private val resetValues = CsrArch.resetValues(cfg)
  private val mstatus     = RegInit(resetValues.mstatus)
  private val mtvec       = RegInit(resetValues.mtvec)
  private val mepc        = RegInit(resetValues.mepc)
  private val mcause      = RegInit(resetValues.mcause)
  private val mtval       = RegInit(resetValues.mtval)
  private val priv    = RegInit(PrivMode.M)

  private val current   = CsrArchValues(mstatus, mtvec, mepc, mcause, mtval)
  private val committed = CsrArch.commitValues(current, io.commit, cfg)
  private val next      = CsrArch.nextValues(current, io.commit, io.trap, io.mret, priv, cfg)

  io.read.data := CsrArch.readValue(io.read.addr, next, cfg)

  when(io.commit.map(_.valid).reduce(_ || _) || io.trap.valid || io.mret.valid) {
    mstatus := next.mstatus
    mtvec   := next.mtvec
    mepc    := next.mepc
    mcause  := next.mcause
    mtval   := next.mtval
  }

  when(io.trap.valid) {
    priv := PrivMode.M
  }.elsewhen(io.mret.valid) {
    priv := CsrArch.mretPriv(committed.mstatus)
  }

  io.status.priv.mode  := priv
  io.status.trapVector := CsrArch.trapBase(next.mtvec, cfg)
  io.status.mretTarget := committed.mepc
}
