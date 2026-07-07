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

  private def mipWithInterrupts(mip: UInt): UInt = {
    val hardwareMask =
      (BigInt(1) << CsrInterrupt.msipBit) |
        (BigInt(1) << CsrInterrupt.mtipBit) |
        (BigInt(1) << CsrInterrupt.meipBit) |
        (BigInt(1) << CsrInterrupt.seipBit)
    val pending =
      (io.interrupt.msip.asUInt << CsrInterrupt.msipBit) |
        (io.interrupt.mtip.asUInt << CsrInterrupt.mtipBit) |
        (io.interrupt.meip.asUInt << CsrInterrupt.meipBit) |
        (io.interrupt.seip.asUInt << CsrInterrupt.seipBit)

    (mip & ~hardwareMask.U(cfg.dataWidth.W)).asUInt | pending
  }

  private val currentWithInterrupts = current.withValue(CsrAddr.of("mip"), mipWithInterrupts(current(CsrAddr.of("mip"))))

  private val committed = CsrArch.commitValues(currentWithInterrupts, io.commit, cfg)
  private val nextArch  = CsrArch.nextValues(currentWithInterrupts, io.commit, io.trap, io.mret, io.sret, priv, cfg)
  private val next      = CsrArch.countedValues(nextArch, io.retireCount, cfg)
  private val nextWithInterrupts = next.withValue(CsrAddr.of("mip"), mipWithInterrupts(next(CsrAddr.of("mip"))))

  io.read.data       := CsrArch.readValue(io.read.addr, nextWithInterrupts, cfg)
  io.read.readLegal  := CsrArch.readLegal(io.read.addr, priv, currentWithInterrupts)
  io.read.writeLegal := CsrArch.writeLegal(io.read.addr, priv, currentWithInterrupts)

  regs := VecInit(next.values)

  when(io.trap.valid) {
    priv := Mux(io.trap.toSupervisor, PrivMode.S, PrivMode.M)
  }.elsewhen(io.mret.valid) {
    priv := CsrArch.mretPriv(committed(CsrAddr.of("mstatus")))
  }.elsewhen(io.sret.valid) {
    priv := CsrArch.sretPriv(committed(CsrAddr.of("mstatus")))
  }

  io.status.priv.mode  := priv
  io.status.mretTarget := current(CsrAddr.of("mepc"))
  io.status.sretTarget := current(CsrAddr.of("sepc"))
  io.status.mstatus    := currentWithInterrupts(CsrAddr.of("mstatus"))
  io.status.satp       := currentWithInterrupts(CsrAddr.of("satp"))
  io.status.mtvec      := currentWithInterrupts(CsrAddr.of("mtvec"))
  io.status.stvec      := currentWithInterrupts(CsrAddr.of("stvec"))
  io.status.medeleg    := currentWithInterrupts(CsrAddr.of("medeleg"))
  io.status.mideleg    := currentWithInterrupts(CsrAddr.of("mideleg"))
  io.status.mie        := currentWithInterrupts(CsrAddr.of("mie"))
  io.status.mip        := currentWithInterrupts(CsrAddr.of("mip"))
}
