package top.backend.csr

import chisel3._
import top.config.BackendConfig

class CsrFile(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         BackendConfig = BackendConfig())
    extends Module {
  val io = IO(new CsrFileIO(cfg))

  private val resetValues = CsrArch.resetValues(cfg)

  private val regs    = RegInit(VecInit(resetValues.values))
  private val priv    = RegInit(PrivMode.M)
  private val current = CsrArchValues.fromVec(regs)

  private val committed = CsrArch.commitValues(current, io.commit, cfg)
  private val nextArch  = CsrArch.nextValues(current, io.commit, io.trap, io.mret, io.sret, priv, cfg)
  private val next      = CsrArch.countedValues(nextArch, io.retireCount, cfg)

  io.read.data       := CsrArch.readValue(io.read.addr, next, cfg)
  io.read.readLegal  := CsrArch.readLegal(io.read.addr, priv, current)
  io.read.writeLegal := CsrArch.writeLegal(io.read.addr, priv, current)

  regs := VecInit(next.values)

  when(io.trap.valid) {
    priv := Mux(io.trap.toSupervisor, PrivMode.S, PrivMode.M)
  }.elsewhen(io.mret.valid) {
    priv := CsrArch.mretPriv(committed(CsrAddr.mstatus))
  }.elsewhen(io.sret.valid) {
    priv := CsrArch.sretPriv(committed(CsrAddr.mstatus))
  }

  io.status.priv.mode  := priv
  io.status.mretTarget := current(CsrAddr.mepc)
  io.status.sretTarget := current(CsrAddr.sepc)
  io.status.mstatus    := current(CsrAddr.mstatus)
  io.status.mtvec      := current(CsrAddr.mtvec)
  io.status.stvec      := current(CsrAddr.stvec)
  io.status.medeleg    := current(CsrAddr.medeleg)
  io.status.mideleg    := current(CsrAddr.mideleg)
}
