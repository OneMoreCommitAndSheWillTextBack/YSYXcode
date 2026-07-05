package top.backend.csr

import chisel3._
import chisel3.util.MuxLookup
import chisel3.util.Valid
import top.config.BackendConfig

final case class CsrArchValues(
  mstatus: UInt,
  mtvec:   UInt,
  mepc:    UInt,
  mcause:  UInt,
  mtval:   UInt)

object CsrArch {
  def resetValues(cfg: BackendConfig = BackendConfig()): CsrArchValues =
    CsrArchValues(
      data(CsrSpec.byAddr(CsrAddr.mstatus).reset, cfg),
      data(CsrSpec.byAddr(CsrAddr.mtvec).reset, cfg),
      data(CsrSpec.byAddr(CsrAddr.mepc).reset, cfg),
      data(CsrSpec.byAddr(CsrAddr.mcause).reset, cfg),
      data(CsrSpec.byAddr(CsrAddr.mtval).reset, cfg)
    )

  def nextValues(
    current: CsrArchValues,
    commit:  Seq[Valid[CsrCommit]],
    trap:    CsrTrapCommit,
    mret:    CsrMretCommit,
    priv:    UInt,
    cfg:     BackendConfig = BackendConfig()
  ): CsrArchValues = {
    val next = commitValues(current, commit, cfg)

    val afterMret = CsrArchValues(
      mstatus = Mux(mret.valid, mretMstatus(next.mstatus, cfg), next.mstatus),
      mtvec = next.mtvec,
      mepc = next.mepc,
      mcause = next.mcause,
      mtval = next.mtval
    )

    CsrArchValues(
      mstatus = Mux(trap.valid, trapMstatus(next.mstatus, priv, cfg), afterMret.mstatus),
      mtvec = next.mtvec,
      mepc = Mux(trap.valid, canonicalMepc(trap.epc, cfg), afterMret.mepc),
      mcause = Mux(trap.valid, trap.cause, afterMret.mcause),
      mtval = Mux(trap.valid, trap.tval, afterMret.mtval)
    )
  }

  def commitValues(
    current: CsrArchValues,
    commit:  Seq[Valid[CsrCommit]],
    cfg:     BackendConfig = BackendConfig()
  ): CsrArchValues = {
    var next = current

    for (lane <- commit) {
      next = CsrArchValues(
        mstatus = Mux(
          lane.valid && lane.bits.addr === CsrAddr(CsrAddr.mstatus),
          writeMstatus(next.mstatus, lane.bits.wdata, cfg),
          next.mstatus
        ),
        mtvec = Mux(
          lane.valid && lane.bits.addr === CsrAddr(CsrAddr.mtvec),
          writeMtvec(next.mtvec, lane.bits.wdata, cfg),
          next.mtvec
        ),
        mepc = Mux(
          lane.valid && lane.bits.addr === CsrAddr(CsrAddr.mepc),
          canonicalMepc(lane.bits.wdata, cfg),
          next.mepc
        ),
        mcause = Mux(
          lane.valid && lane.bits.addr === CsrAddr(CsrAddr.mcause),
          lane.bits.wdata,
          next.mcause
        ),
        mtval = Mux(
          lane.valid && lane.bits.addr === CsrAddr(CsrAddr.mtval),
          lane.bits.wdata,
          next.mtval
        )
      )
    }

    next
  }

  def readValue(addr: UInt, values: CsrArchValues, cfg: BackendConfig = BackendConfig()): UInt =
    MuxLookup(addr, 0.U(cfg.dataWidth.W))(
      Seq(
        CsrAddr(CsrAddr.mstatus) -> values.mstatus,
        CsrAddr(CsrAddr.mtvec)   -> values.mtvec,
        CsrAddr(CsrAddr.mepc)    -> values.mepc,
        CsrAddr(CsrAddr.mcause)  -> values.mcause,
        CsrAddr(CsrAddr.mtval)   -> values.mtval
      )
    )

  def trapBase(mtvecValue: UInt, cfg: BackendConfig = BackendConfig()): UInt =
    mtvecValue(cfg.addrWidth - 1, 2) ## 0.U(2.W)

  def mretPriv(mstatusValue: UInt): UInt = {
    val mode = mstatusValue(Mstatus.mppMsb, Mstatus.mppLsb)
    Mux(PrivMode.legal(mode), mode, PrivMode.M)
  }

  private def data(value: BigInt, cfg: BackendConfig): UInt =
    value.U(cfg.dataWidth.W)

  private def maskWrite(old: UInt, wdata: UInt, mask: BigInt, cfg: BackendConfig): UInt = {
    val writeMask = data(mask, cfg)
    (old & ~writeMask).asUInt | (wdata & writeMask)
  }

  private def canonicalMepc(wdata: UInt, cfg: BackendConfig): UInt =
    wdata & ~1.U(cfg.dataWidth.W)

  private def writeMstatus(old: UInt, wdata: UInt, cfg: BackendConfig): UInt =
    maskWrite(old, wdata, CsrSpec.byAddr(CsrAddr.mstatus).writeMask, cfg)

  private def writeMtvec(old: UInt, wdata: UInt, cfg: BackendConfig): UInt =
    maskWrite(old, wdata, CsrSpec.byAddr(CsrAddr.mtvec).writeMask, cfg)

  private def trapMstatus(old: UInt, previousPriv: UInt, cfg: BackendConfig): UInt = {
    val writeMask = data(Mstatus.trapWriteMask, cfg)
    val mpie      = old(Mstatus.mieBit).asUInt << Mstatus.mpieBit
    val mpp       = previousPriv.pad(cfg.dataWidth) << Mstatus.mppLsb

    (old & ~writeMask).asUInt | mpie | mpp
  }

  private def mretMstatus(old: UInt, cfg: BackendConfig): UInt = {
    val returnPriv = mretPriv(old)
    val writeMask  = data(Mstatus.trapWriteMask, cfg)
    val mprvMask   = Mux(returnPriv === PrivMode.M, 0.U(cfg.dataWidth.W), data(Mstatus.mprvMask, cfg))
    val mie        = old(Mstatus.mpieBit).asUInt << Mstatus.mieBit
    val mpie       = 1.U(cfg.dataWidth.W) << Mstatus.mpieBit

    (old & ~(writeMask | mprvMask)).asUInt | mie | mpie
  }
}
