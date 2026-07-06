package top.backend.csr

import chisel3._
import chisel3.util.{MuxLookup, Valid}
import top.config.BackendConfig

final case class CsrArchValues(
  mepc:          UInt,
  sepc:          UInt,
  misa:          UInt,
  mstatus:       UInt,
  mstatush:      UInt,
  mcause:        UInt,
  mtval:         UInt,
  mtvec:         UInt,
  mscratch:      UInt,
  satp:          UInt,
  medeleg:       UInt,
  mideleg:       UInt,
  mvendorid:     UInt,
  marchid:       UInt,
  mhartid:       UInt,
  mimpid:        UInt,
  pmpaddr0:      UInt,
  pmpaddr1:      UInt,
  pmpaddr2:      UInt,
  pmpaddr3:      UInt,
  pmpaddr4:      UInt,
  pmpaddr5:      UInt,
  pmpaddr6:      UInt,
  pmpaddr7:      UInt,
  pmpcfg0:       UInt,
  pmpcfg1:       UInt,
  scause:        UInt,
  stval:         UInt,
  sscratch:      UInt,
  stvec:         UInt,
  mie:           UInt,
  mcounteren:    UInt,
  scounteren:    UInt,
  mcountinhibit: UInt,
  mip:           UInt,
  mcycle:        UInt,
  minstret:      UInt)

object CsrArch {
  def resetValues(cfg: BackendConfig = BackendConfig()): CsrArchValues =
    CsrArchValues(
      mepc = reset(CsrAddr.mepc, cfg),
      sepc = reset(CsrAddr.sepc, cfg),
      misa = reset(CsrAddr.misa, cfg),
      mstatus = reset(CsrAddr.mstatus, cfg),
      mstatush = reset(CsrAddr.mstatush, cfg),
      mcause = reset(CsrAddr.mcause, cfg),
      mtval = reset(CsrAddr.mtval, cfg),
      mtvec = reset(CsrAddr.mtvec, cfg),
      mscratch = reset(CsrAddr.mscratch, cfg),
      satp = reset(CsrAddr.satp, cfg),
      medeleg = reset(CsrAddr.medeleg, cfg),
      mideleg = reset(CsrAddr.mideleg, cfg),
      mvendorid = reset(CsrAddr.mvendorid, cfg),
      marchid = reset(CsrAddr.marchid, cfg),
      mhartid = reset(CsrAddr.mhartid, cfg),
      mimpid = reset(CsrAddr.mimpid, cfg),
      pmpaddr0 = reset(CsrAddr.pmpaddr0, cfg),
      pmpaddr1 = reset(CsrAddr.pmpaddr1, cfg),
      pmpaddr2 = reset(CsrAddr.pmpaddr2, cfg),
      pmpaddr3 = reset(CsrAddr.pmpaddr3, cfg),
      pmpaddr4 = reset(CsrAddr.pmpaddr4, cfg),
      pmpaddr5 = reset(CsrAddr.pmpaddr5, cfg),
      pmpaddr6 = reset(CsrAddr.pmpaddr6, cfg),
      pmpaddr7 = reset(CsrAddr.pmpaddr7, cfg),
      pmpcfg0 = reset(CsrAddr.pmpcfg0, cfg),
      pmpcfg1 = reset(CsrAddr.pmpcfg1, cfg),
      scause = reset(CsrAddr.scause, cfg),
      stval = reset(CsrAddr.stval, cfg),
      sscratch = reset(CsrAddr.sscratch, cfg),
      stvec = reset(CsrAddr.stvec, cfg),
      mie = reset(CsrAddr.mie, cfg),
      mcounteren = reset(CsrAddr.mcounteren, cfg),
      scounteren = reset(CsrAddr.scounteren, cfg),
      mcountinhibit = reset(CsrAddr.mcountinhibit, cfg),
      mip = 0.U(cfg.dataWidth.W),
      mcycle = 0.U(cfg.dataWidth.W),
      minstret = 0.U(cfg.dataWidth.W)
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

    val afterMret = next.copy(
      mstatus = Mux(mret.valid, mretMstatus(next.mstatus, cfg), next.mstatus)
    )

    val trapToSupervisor = trap.valid && trap.toSupervisor
    val trapToMachine    = trap.valid && !trap.toSupervisor
    val trapMstatusValue = Mux(
      trap.toSupervisor,
      trapSstatus(afterMret.mstatus, priv, cfg),
      trapMstatus(afterMret.mstatus, priv, cfg)
    )

    afterMret.copy(
      mstatus = Mux(trap.valid, trapMstatusValue, afterMret.mstatus),
      mepc = Mux(trapToMachine, canonicalEpc(trap.epc, cfg), afterMret.mepc),
      sepc = Mux(trapToSupervisor, canonicalEpc(trap.epc, cfg), afterMret.sepc),
      mcause = Mux(trapToMachine, trap.cause, afterMret.mcause),
      mtval = Mux(trapToMachine, trap.tval, afterMret.mtval),
      scause = Mux(trapToSupervisor, trap.cause, afterMret.scause),
      stval = Mux(trapToSupervisor, trap.tval, afterMret.stval)
    )
  }

  def countedValues(
    current:     CsrArchValues,
    retireCount: UInt,
    cfg:         BackendConfig = BackendConfig()
  ): CsrArchValues =
    current.copy(
      mcycle = current.mcycle + 1.U,
      minstret = current.minstret + retireCount.pad(cfg.dataWidth)
    )

  def commitValues(
    current: CsrArchValues,
    commit:  Seq[Valid[CsrCommit]],
    cfg:     BackendConfig = BackendConfig()
  ): CsrArchValues = {
    var next = current

    for (lane <- commit) {
      next = writeValue(next, lane.valid, lane.bits.addr, lane.bits.wdata, cfg)
    }

    next
  }

  def readValue(addr: UInt, values: CsrArchValues, cfg: BackendConfig = BackendConfig()): UInt =
    MuxLookup(addr, 0.U(cfg.dataWidth.W))(
      Seq(
        CsrAddr(CsrAddr.sstatus)       -> (values.mstatus & data(Sstatus.mask, cfg)),
        CsrAddr(CsrAddr.sie)           -> (values.mie & delegatedMask(values.mideleg, CsrInterrupt.sieMask, cfg)),
        CsrAddr(CsrAddr.stvec)         -> values.stvec,
        CsrAddr(CsrAddr.scounteren)    -> values.scounteren,
        CsrAddr(CsrAddr.sscratch)      -> values.sscratch,
        CsrAddr(CsrAddr.sepc)          -> values.sepc,
        CsrAddr(CsrAddr.scause)        -> values.scause,
        CsrAddr(CsrAddr.stval)         -> values.stval,
        CsrAddr(CsrAddr.sip)           -> (values.mip & delegatedMask(values.mideleg, CsrInterrupt.sieMask, cfg)),
        CsrAddr(CsrAddr.satp)          -> values.satp,
        CsrAddr(CsrAddr.mstatus)       -> values.mstatus,
        CsrAddr(CsrAddr.misa)          -> values.misa,
        CsrAddr(CsrAddr.medeleg)       -> values.medeleg,
        CsrAddr(CsrAddr.mideleg)       -> values.mideleg,
        CsrAddr(CsrAddr.mie)           -> values.mie,
        CsrAddr(CsrAddr.mtvec)         -> values.mtvec,
        CsrAddr(CsrAddr.mcounteren)    -> values.mcounteren,
        CsrAddr(CsrAddr.mstatush)      -> values.mstatush,
        CsrAddr(CsrAddr.mcountinhibit) -> values.mcountinhibit,
        CsrAddr(CsrAddr.mscratch)      -> values.mscratch,
        CsrAddr(CsrAddr.mepc)          -> values.mepc,
        CsrAddr(CsrAddr.mcause)        -> values.mcause,
        CsrAddr(CsrAddr.mtval)         -> values.mtval,
        CsrAddr(CsrAddr.mip)           -> values.mip,
        CsrAddr(CsrAddr.pmpcfg0)       -> values.pmpcfg0,
        CsrAddr(CsrAddr.pmpcfg1)       -> values.pmpcfg1,
        CsrAddr(CsrAddr.pmpaddr0)      -> values.pmpaddr0,
        CsrAddr(CsrAddr.pmpaddr1)      -> values.pmpaddr1,
        CsrAddr(CsrAddr.pmpaddr2)      -> values.pmpaddr2,
        CsrAddr(CsrAddr.pmpaddr3)      -> values.pmpaddr3,
        CsrAddr(CsrAddr.pmpaddr4)      -> values.pmpaddr4,
        CsrAddr(CsrAddr.pmpaddr5)      -> values.pmpaddr5,
        CsrAddr(CsrAddr.pmpaddr6)      -> values.pmpaddr6,
        CsrAddr(CsrAddr.pmpaddr7)      -> values.pmpaddr7,
        CsrAddr(CsrAddr.cycle)         -> values.mcycle,
        CsrAddr(CsrAddr.time)          -> values.mcycle,
        CsrAddr(CsrAddr.instret)       -> values.minstret,
        CsrAddr(CsrAddr.cycleh)        -> 0.U,
        CsrAddr(CsrAddr.timeh)         -> 0.U,
        CsrAddr(CsrAddr.instreth)      -> 0.U,
        CsrAddr(CsrAddr.mvendorid)     -> values.mvendorid,
        CsrAddr(CsrAddr.marchid)       -> values.marchid,
        CsrAddr(CsrAddr.mimpid)        -> values.mimpid,
        CsrAddr(CsrAddr.mhartid)       -> values.mhartid
      )
    )

  def readLegal(addr: UInt, priv: UInt): Bool =
    implemented(addr) && privilegeAllows(addr, priv)

  def writeLegal(addr: UInt, priv: UInt): Bool =
    readLegal(addr, priv) && !readOnlyByEncoding(addr) && writable(addr)

  def trapBase(mtvecValue: UInt, cfg: BackendConfig = BackendConfig()): UInt =
    mtvecValue(cfg.addrWidth - 1, 2) ## 0.U(2.W)

  def trapVector(
    toSupervisor: Bool,
    mtvecValue:   UInt,
    stvecValue:   UInt,
    cfg:          BackendConfig = BackendConfig()
  ): UInt =
    trapBase(Mux(toSupervisor, stvecValue, mtvecValue), cfg)

  def trapDelegated(
    cause:     UInt,
    interrupt: Bool,
    priv:      UInt,
    medeleg:   UInt,
    mideleg:   UInt,
    cfg:       BackendConfig = BackendConfig()
  ): Bool = {
    val causeBit = (1.U(cfg.dataWidth.W) << cause)(cfg.dataWidth - 1, 0)
    val deleg    = Mux(interrupt, mideleg, medeleg)

    priv =/= PrivMode.M && (deleg & causeBit).orR
  }

  def mretPriv(mstatusValue: UInt): UInt = {
    val mode = mstatusValue(Mstatus.mppMsb, Mstatus.mppLsb)
    Mux(PrivMode.legal(mode), mode, PrivMode.M)
  }

  private def writeValue(
    current: CsrArchValues,
    valid:   Bool,
    addr:    UInt,
    wdata:   UInt,
    cfg:     BackendConfig
  ): CsrArchValues = {
    val mstatusAfterRaw     = writeMasked(current.mstatus, wdata, CsrAddr.mstatus, addr, valid, cfg)
    val mstatusAfterVirtual = Mux(
      hit(CsrAddr.sstatus, addr, valid),
      maskWrite(mstatusAfterRaw, wdata, Sstatus.mask, cfg),
      mstatusAfterRaw
    )

    val mieAfterRaw     = writeMasked(current.mie, wdata, CsrAddr.mie, addr, valid, cfg)
    val sieMask         = delegatedMask(current.mideleg, CsrInterrupt.sieMask, cfg)
    val mieAfterVirtual = Mux(
      hit(CsrAddr.sie, addr, valid),
      (mieAfterRaw & ~sieMask).asUInt | (wdata & sieMask),
      mieAfterRaw
    )

    val mipAfterMip     = writeMasked(current.mip, wdata, CsrAddr.mip, addr, valid, cfg)
    val sipMask         = delegatedMask(current.mideleg, CsrInterrupt.writableSipMask, cfg)
    val mipAfterVirtual = Mux(
      hit(CsrAddr.sip, addr, valid),
      (mipAfterMip & ~sipMask).asUInt | (wdata & sipMask),
      mipAfterMip
    )

    current.copy(
      mepc = Mux(hit(CsrAddr.mepc, addr, valid), canonicalEpc(wdata, cfg), current.mepc),
      sepc = Mux(hit(CsrAddr.sepc, addr, valid), canonicalEpc(wdata, cfg), current.sepc),
      misa = writeMasked(current.misa, wdata, CsrAddr.misa, addr, valid, cfg),
      mstatus = mstatusAfterVirtual,
      mstatush = writeMasked(current.mstatush, wdata, CsrAddr.mstatush, addr, valid, cfg),
      mcause = writeMasked(current.mcause, wdata, CsrAddr.mcause, addr, valid, cfg),
      mtval = writeMasked(current.mtval, wdata, CsrAddr.mtval, addr, valid, cfg),
      mtvec = writeMasked(current.mtvec, wdata, CsrAddr.mtvec, addr, valid, cfg),
      mscratch = writeMasked(current.mscratch, wdata, CsrAddr.mscratch, addr, valid, cfg),
      satp = writeMasked(current.satp, wdata, CsrAddr.satp, addr, valid, cfg),
      medeleg = writeMasked(current.medeleg, wdata, CsrAddr.medeleg, addr, valid, cfg),
      mideleg = writeMasked(current.mideleg, wdata, CsrAddr.mideleg, addr, valid, cfg),
      mvendorid = writeMasked(current.mvendorid, wdata, CsrAddr.mvendorid, addr, valid, cfg),
      marchid = writeMasked(current.marchid, wdata, CsrAddr.marchid, addr, valid, cfg),
      mhartid = writeMasked(current.mhartid, wdata, CsrAddr.mhartid, addr, valid, cfg),
      mimpid = writeMasked(current.mimpid, wdata, CsrAddr.mimpid, addr, valid, cfg),
      pmpaddr0 = writeMasked(current.pmpaddr0, wdata, CsrAddr.pmpaddr0, addr, valid, cfg),
      pmpaddr1 = writeMasked(current.pmpaddr1, wdata, CsrAddr.pmpaddr1, addr, valid, cfg),
      pmpaddr2 = writeMasked(current.pmpaddr2, wdata, CsrAddr.pmpaddr2, addr, valid, cfg),
      pmpaddr3 = writeMasked(current.pmpaddr3, wdata, CsrAddr.pmpaddr3, addr, valid, cfg),
      pmpaddr4 = writeMasked(current.pmpaddr4, wdata, CsrAddr.pmpaddr4, addr, valid, cfg),
      pmpaddr5 = writeMasked(current.pmpaddr5, wdata, CsrAddr.pmpaddr5, addr, valid, cfg),
      pmpaddr6 = writeMasked(current.pmpaddr6, wdata, CsrAddr.pmpaddr6, addr, valid, cfg),
      pmpaddr7 = writeMasked(current.pmpaddr7, wdata, CsrAddr.pmpaddr7, addr, valid, cfg),
      pmpcfg0 = writeMasked(current.pmpcfg0, wdata, CsrAddr.pmpcfg0, addr, valid, cfg),
      pmpcfg1 = writeMasked(current.pmpcfg1, wdata, CsrAddr.pmpcfg1, addr, valid, cfg),
      scause = writeMasked(current.scause, wdata, CsrAddr.scause, addr, valid, cfg),
      stval = writeMasked(current.stval, wdata, CsrAddr.stval, addr, valid, cfg),
      sscratch = writeMasked(current.sscratch, wdata, CsrAddr.sscratch, addr, valid, cfg),
      stvec = writeMasked(current.stvec, wdata, CsrAddr.stvec, addr, valid, cfg),
      mie = mieAfterVirtual,
      mcounteren = writeMasked(current.mcounteren, wdata, CsrAddr.mcounteren, addr, valid, cfg),
      scounteren = writeMasked(current.scounteren, wdata, CsrAddr.scounteren, addr, valid, cfg),
      mcountinhibit = writeMasked(current.mcountinhibit, wdata, CsrAddr.mcountinhibit, addr, valid, cfg),
      mip = mipAfterVirtual
    )
  }

  private def reset(addr: Int, cfg: BackendConfig): UInt =
    data(CsrSpec.byAddr(addr).reset, cfg)

  private def data(value: BigInt, cfg: BackendConfig): UInt =
    value.U(cfg.dataWidth.W)

  private def hit(csrAddr: Int, addr: UInt, valid: Bool): Bool =
    valid && addr === CsrAddr(csrAddr)

  private def writeMask(addr: Int): BigInt =
    CsrSpec.byAddr(addr).writeMask

  private def writeMasked(old: UInt, wdata: UInt, csrAddr: Int, addr: UInt, valid: Bool, cfg: BackendConfig): UInt =
    Mux(hit(csrAddr, addr, valid), maskWrite(old, wdata, writeMask(csrAddr), cfg), old)

  private def maskWrite(old: UInt, wdata: UInt, mask: BigInt, cfg: BackendConfig): UInt = {
    val writeMask = data(mask, cfg)
    (old & ~writeMask).asUInt | (wdata & writeMask)
  }

  private def canonicalEpc(wdata: UInt, cfg: BackendConfig): UInt =
    wdata & ~1.U(cfg.dataWidth.W)

  private def delegatedMask(deleg: UInt, mask: BigInt, cfg: BackendConfig): UInt =
    deleg & data(mask, cfg)

  private def implemented(addr: UInt): Bool =
    VecInit(CsrSpec.supported.map(spec => addr === CsrAddr(spec.addr))).asUInt.orR

  private def writable(addr: UInt): Bool =
    VecInit(CsrSpec.supported.filter(_.writeMask != 0).map(spec => addr === CsrAddr(spec.addr))).asUInt.orR

  private def privilegeAllows(addr: UInt, priv: UInt): Bool =
    priv >= addr(9, 8)

  private def readOnlyByEncoding(addr: UInt): Bool =
    addr(11, 10) === "b11".U

  private def trapMstatus(old: UInt, previousPriv: UInt, cfg: BackendConfig): UInt = {
    val writeMask = data(Mstatus.trapWriteMask, cfg)
    val mpie      = old(Mstatus.mieBit).asUInt << Mstatus.mpieBit
    val mpp       = previousPriv.pad(cfg.dataWidth) << Mstatus.mppLsb

    (old & ~writeMask).asUInt | mpie | mpp
  }

  private def trapSstatus(old: UInt, previousPriv: UInt, cfg: BackendConfig): UInt = {
    val writeMask = data(Mstatus.supervisorTrapWriteMask, cfg)
    val spie      = old(Mstatus.sieBit).asUInt << Mstatus.spieBit
    val spp       = (previousPriv === PrivMode.S).asUInt << Mstatus.sppBit

    (old & ~writeMask).asUInt | spie | spp
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
