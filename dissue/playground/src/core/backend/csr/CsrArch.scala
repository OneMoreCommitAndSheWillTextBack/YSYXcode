package top.core.backend.csr

import chisel3._
import chisel3.util.{MuxLookup, Valid}
import top.config.BackendConfig

final case class CsrArchValues(values: Seq[UInt]) {
  require(values.size == CsrSpec.state.size, "CSR state value count does not match CsrSpec.state")

  def apply(name: String): UInt =
    values(CsrSpec.stateIndex(name))

  def apply(addr: Int): UInt =
    apply(CsrSpec.byAddr(addr).name)

  def get(name: String): Option[UInt] =
    CsrSpec.stateIndex.get(name).map(values)

  def withValue(name: String, value: UInt): CsrArchValues =
    CsrArchValues(values.updated(CsrSpec.stateIndex(name), value))

  def withValue(addr: Int, value: UInt): CsrArchValues =
    withValue(CsrSpec.byAddr(addr).name, value)

  def withValues(updates: (String, UInt)*): CsrArchValues =
    updates.foldLeft(this) { case (next, (name, value)) => next.withValue(name, value) }

  def withAddrValues(updates: (Int, UInt)*): CsrArchValues =
    updates.foldLeft(this) { case (next, (addr, value)) => next.withValue(addr, value) }
}

object CsrArchValues {
  def fromVec(values: Vec[UInt]): CsrArchValues =
    CsrArchValues(CsrSpec.state.indices.map(values(_)))
}

object CsrArch {
  def resetValues(cfg: BackendConfig = BackendConfig()): CsrArchValues =
    CsrArchValues(CsrSpec.state.map(spec => data(spec.reset, cfg)))

  def nextValues(
    current: CsrArchValues,
    commit:  Seq[Valid[CsrCommit]],
    trap:    CsrTrapCommit,
    mret:    CsrMretCommit,
    sret:    CsrSretCommit,
    priv:    UInt,
    cfg:     BackendConfig = BackendConfig()
  ): CsrArchValues = {
    val next = commitValues(current, commit, cfg)

    val afterReturn = next.withValue(
      CsrAddr.of("mstatus"),
      Mux(
        mret.valid,
        mretMstatus(next(CsrAddr.of("mstatus")), cfg),
        Mux(sret.valid, sretMstatus(next(CsrAddr.of("mstatus")), cfg), next(CsrAddr.of("mstatus")))
      )
    )

    val trapToSupervisor = trap.valid && trap.toSupervisor
    val trapToMachine    = trap.valid && !trap.toSupervisor
    val trapMstatusValue = Mux(
      trap.toSupervisor,
      trapSstatus(afterReturn(CsrAddr.of("mstatus")), priv, cfg),
      trapMstatus(afterReturn(CsrAddr.of("mstatus")), priv, cfg)
    )

    afterReturn.withAddrValues(
      CsrAddr.of("mstatus") -> Mux(trap.valid, trapMstatusValue, afterReturn(CsrAddr.of("mstatus"))),
      CsrAddr.of("mepc")    -> Mux(trapToMachine, canonicalEpc(trap.epc, cfg), afterReturn(CsrAddr.of("mepc"))),
      CsrAddr.of("sepc")    -> Mux(trapToSupervisor, canonicalEpc(trap.epc, cfg), afterReturn(CsrAddr.of("sepc"))),
      CsrAddr.of("mcause")  -> Mux(trapToMachine, trap.cause, afterReturn(CsrAddr.of("mcause"))),
      CsrAddr.of("mtval")   -> Mux(trapToMachine, trap.tval, afterReturn(CsrAddr.of("mtval"))),
      CsrAddr.of("scause")  -> Mux(trapToSupervisor, trap.cause, afterReturn(CsrAddr.of("scause"))),
      CsrAddr.of("stval")   -> Mux(trapToSupervisor, trap.tval, afterReturn(CsrAddr.of("stval")))
    )
  }

  def countedValues(
    current:     CsrArchValues,
    retireCount: UInt,
    cfg:         BackendConfig = BackendConfig()
  ): CsrArchValues =
    current.withValues(
      "mcycle"   -> (current("mcycle") + 1.U),
      "minstret" -> (current("minstret") + retireCount.pad(cfg.dataWidth))
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
      CsrSpec.supported.map(spec => CsrAddr(spec.addr) -> readValue(spec, values, cfg))
    )

  def readLegal(addr: UInt, priv: UInt, values: CsrArchValues): Bool =
    implemented(addr) && privilegeAllows(addr, priv) && counterAllows(addr, priv, values)

  def writeLegal(addr: UInt, priv: UInt, values: CsrArchValues): Bool =
    readLegal(addr, priv, values) && !readOnlyByEncoding(addr) && writable(addr)

  def trapBase(mtvecValue: UInt, cfg: BackendConfig = BackendConfig()): UInt =
    mtvecValue(cfg.addrWidth - 1, 2) ## 0.U(2.W)

  def trapVector(
    toSupervisor: Bool,
    mtvecValue:   UInt,
    stvecValue:   UInt,
    cause:        UInt,
    interrupt:    Bool,
    cfg:          BackendConfig = BackendConfig()
  ): UInt = {
    val tvec     = Mux(toSupervisor, stvecValue, mtvecValue)
    val base     = trapBase(tvec, cfg)
    val offset   = (cause.pad(cfg.addrWidth) << 2)(cfg.addrWidth - 1, 0)
    val vectored = interrupt && tvec(1, 0) === 1.U

    base + Mux(vectored, offset, 0.U(cfg.addrWidth.W))
  }

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

  def sretPriv(mstatusValue: UInt): UInt =
    Mux(mstatusValue(Mstatus.sppBit), PrivMode.S, PrivMode.U)

  private def writeValue(
    current: CsrArchValues,
    valid:   Bool,
    addr:    UInt,
    wdata:   UInt,
    cfg:     BackendConfig
  ): CsrArchValues = {
    val afterRaw = CsrSpec.raw.foldLeft(current) { case (next, spec) =>
      next.withValue(spec.name, writeRawValue(spec, current, valid, addr, wdata, cfg))
    }

    val mstatusAfterRaw     = afterRaw(CsrAddr.of("mstatus"))
    val mstatusAfterVirtual = Mux(
      hit(CsrAddr.of("sstatus"), addr, valid),
      maskWrite(mstatusAfterRaw, wdata, Sstatus.writeMask, cfg),
      mstatusAfterRaw
    )

    val mieAfterRaw     = afterRaw(CsrAddr.of("mie"))
    val sieMask         = delegatedMask(afterRaw(CsrAddr.of("mideleg")), CsrInterrupt.sieMask, cfg)
    val mieAfterVirtual = Mux(
      hit(CsrAddr.of("sie"), addr, valid),
      (mieAfterRaw & ~sieMask).asUInt | (wdata & sieMask),
      mieAfterRaw
    )

    val mipAfterMip     = afterRaw(CsrAddr.of("mip"))
    val sipMask         = delegatedMask(afterRaw(CsrAddr.of("mideleg")), CsrInterrupt.writableSipMask, cfg)
    val mipAfterVirtual = Mux(
      hit(CsrAddr.of("sip"), addr, valid),
      (mipAfterMip & ~sipMask).asUInt | (wdata & sipMask),
      mipAfterMip
    )

    afterRaw.withAddrValues(
      CsrAddr.of("mstatus") -> mstatusAfterVirtual,
      CsrAddr.of("mie")     -> mieAfterVirtual,
      CsrAddr.of("mip")     -> mipAfterVirtual
    )
  }

  private def readValue(spec: CsrSpec, values: CsrArchValues, cfg: BackendConfig): UInt =
    spec.name match {
      case "sstatus"                       => values(CsrAddr.of("mstatus")) & data(Sstatus.visibleMask, cfg)
      case "sie"                           => values(CsrAddr.of("mie")) & delegatedMask(values(CsrAddr.of("mideleg")), CsrInterrupt.sieMask, cfg)
      case "sip"                           => values(CsrAddr.of("mip")) & delegatedMask(values(CsrAddr.of("mideleg")), CsrInterrupt.sieMask, cfg)
      case "cycle" | "time"                =>
        values("mcycle")
      case "instret"                       =>
        values("minstret")
      case "cycleh" | "timeh" | "instreth" =>
        0.U(cfg.dataWidth.W)
      case name                            =>
        values
          .get(name)
          .getOrElse(throw new IllegalArgumentException(s"CSR ${spec.name} has no stored state or read behavior"))
    }

  private def writeRawValue(
    spec:    CsrSpec,
    current: CsrArchValues,
    valid:   Bool,
    addr:    UInt,
    wdata:   UInt,
    cfg:     BackendConfig
  ): UInt =
    spec.name match {
      case "mepc" | "sepc" => Mux(hit(spec.addr, addr, valid), canonicalEpc(wdata, cfg), current(spec.name))
      case _               => writeMasked(current(spec.name), wdata, spec.addr, addr, valid, cfg)
    }

  private def data(value: BigInt, cfg: BackendConfig): UInt =
    value.U(cfg.dataWidth.W)

  private def hit(csrAddr: Int, addr: UInt, valid: Bool): Bool =
    valid && addr === CsrAddr(csrAddr)

  private def writeMasked(old: UInt, wdata: UInt, csrAddr: Int, addr: UInt, valid: Bool, cfg: BackendConfig): UInt =
    Mux(hit(csrAddr, addr, valid), maskWrite(old, wdata, CsrSpec.byAddr(csrAddr).writeMask, cfg), old)

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

  private def counterAllows(addr: UInt, priv: UInt, values: CsrArchValues): Bool = {
    val bit     = counterBit(addr)
    val isCount = bit.orR

    !isCount ||
    priv === PrivMode.M ||
    (priv === PrivMode.S && (values(CsrAddr.of("mcounteren")) & bit).orR) ||
    (priv === PrivMode.U && (values(CsrAddr.of("mcounteren")) & bit).orR && (values(CsrAddr.of("scounteren")) & bit).orR)
  }

  private def counterBit(addr: UInt): UInt =
    MuxLookup(addr, 0.U(CsrCounter.counterenMask.bitLength.W))(
      Seq(
        CsrAddr("cycle")    -> 1.U,
        CsrAddr("time")     -> 2.U,
        CsrAddr("instret")  -> 4.U,
        CsrAddr("cycleh")   -> 1.U,
        CsrAddr("timeh")    -> 2.U,
        CsrAddr("instreth") -> 4.U
      )
    )

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

  private def sretMstatus(old: UInt, cfg: BackendConfig): UInt = {
    val writeMask = data(Mstatus.supervisorTrapWriteMask, cfg)
    val sie       = old(Mstatus.spieBit).asUInt << Mstatus.sieBit
    val spie      = 1.U(cfg.dataWidth.W) << Mstatus.spieBit

    (old & ~(writeMask | data(Mstatus.mprvMask, cfg))).asUInt | sie | spie
  }
}
