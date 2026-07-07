package top.backend.csr

sealed trait CsrKind

object CsrKind {
  case object Raw     extends CsrKind
  case object Virtual extends CsrKind
}

final case class CsrSpec(
  name:      String,
  addr:      Int,
  reset:     BigInt,
  writeMask: BigInt,
  kind:      CsrKind,
  doc:       String)

final case class CsrStateSpec(name: String, reset: BigInt)

object CsrSpec {
  private val fullMask = BigInt("ffffffff", 16)

  private def raw(name: String, addr: Int, reset: BigInt = 0, writeMask: BigInt = fullMask, doc: String): CsrSpec =
    CsrSpec(name, addr, reset, writeMask, CsrKind.Raw, doc)

  private def virt(name: String, addr: Int, writeMask: BigInt = fullMask, doc: String): CsrSpec =
    CsrSpec(name, addr, 0, writeMask, CsrKind.Virtual, doc)

  val supported: Seq[CsrSpec] = Seq(
    raw("mepc", 0x341, writeMask = fullMask & ~BigInt(1), doc = "Machine exception PC."),
    raw("sepc", 0x141, writeMask = fullMask & ~BigInt(1), doc = "Supervisor exception PC."),
    raw("misa", 0x301, reset = Misa.rv32ImacSu, writeMask = 0, doc = "NEMU-compatible RV32 IMACSU ISA view."),
    raw("mstatus", 0x300, writeMask = Mstatus.writeMask, doc = "Machine status register."),
    raw("mstatush", 0x310, doc = "RV32 upper mstatus placeholder."),
    raw("mcause", 0x342, doc = "Machine trap cause."),
    raw("mtval", 0x343, doc = "Machine trap value."),
    raw("mtvec", 0x305, doc = "Machine trap vector."),
    raw("mscratch", 0x340, doc = "Machine scratch register."),
    raw("satp", 0x180, doc = "Address translation root. Stored for software compatibility."),
    raw(
      "medeleg",
      0x302,
      writeMask = CsrDelegation.writableMedelegMask,
      doc = "Machine exception delegation."
    ),
    raw(
      "mideleg",
      0x303,
      writeMask = CsrInterrupt.writableMidelegMask,
      doc = "Machine interrupt delegation."
    ),
    raw("mvendorid", 0xf11, reset = CsrId.mvendorid, writeMask = 0, doc = "YSYX vendor ID."),
    raw("marchid", 0xf12, reset = CsrId.marchid, writeMask = 0, doc = "YSYX architecture ID."),
    raw("mhartid", 0xf14, reset = CsrId.mhartid, writeMask = 0, doc = "Hart ID."),
    raw("mimpid", 0xf13, reset = CsrId.mimpid, writeMask = 0, doc = "Implementation ID placeholder."),
    raw("pmpaddr0", 0x3b0, doc = "PMP address placeholder."),
    raw("pmpaddr1", 0x3b1, doc = "PMP address placeholder."),
    raw("pmpaddr2", 0x3b2, doc = "PMP address placeholder."),
    raw("pmpaddr3", 0x3b3, doc = "PMP address placeholder."),
    raw("pmpaddr4", 0x3b4, doc = "PMP address placeholder."),
    raw("pmpaddr5", 0x3b5, doc = "PMP address placeholder."),
    raw("pmpaddr6", 0x3b6, doc = "PMP address placeholder."),
    raw("pmpaddr7", 0x3b7, doc = "PMP address placeholder."),
    raw("pmpcfg0", 0x3a0, doc = "PMP config placeholder."),
    raw("pmpcfg1", 0x3a1, doc = "PMP config placeholder."),
    raw("scause", 0x142, doc = "Supervisor trap cause."),
    raw("stval", 0x143, doc = "Supervisor trap value."),
    raw("sscratch", 0x140, doc = "Supervisor scratch register."),
    raw("stvec", 0x105, doc = "Supervisor trap vector."),
    raw("mie", 0x304, doc = "Machine interrupt-enable bits."),
    raw("mcounteren", 0x306, writeMask = CsrCounter.counterenMask, doc = "Machine counter delegation."),
    raw("scounteren", 0x106, writeMask = CsrCounter.counterenMask, doc = "Supervisor counter delegation."),
    raw(
      "mcountinhibit",
      0x320,
      writeMask = CsrCounter.countInhibitMask,
      doc = "Counter inhibit register."
    ),
    virt("cycle", 0xc00, writeMask = 0, doc = "Low cycle counter view."),
    virt("time", 0xc01, writeMask = 0, doc = "Low time counter view."),
    virt("instret", 0xc02, writeMask = 0, doc = "Low retired-instruction counter view."),
    virt("cycleh", 0xc80, writeMask = 0, doc = "High cycle counter view."),
    virt("timeh", 0xc81, writeMask = 0, doc = "High time counter view."),
    virt("instreth", 0xc82, writeMask = 0, doc = "High retired-instruction counter view."),
    virt("sie", 0x104, writeMask = CsrInterrupt.sieMask, doc = "Supervisor view of delegated mie bits."),
    virt("sip", 0x144, writeMask = CsrInterrupt.writableSipMask, doc = "Supervisor view of delegated mip bits."),
    raw("mip", 0x344, writeMask = CsrInterrupt.writableMipMask, doc = "Machine interrupt-pending bits."),
    virt("sstatus", 0x100, writeMask = Sstatus.writeMask, doc = "Supervisor-visible mstatus projection.")
  )

  require(supported.map(_.addr).distinct.size == supported.size, "duplicate CSR address in CsrSpec.supported")
  require(supported.map(_.name).distinct.size == supported.size, "duplicate CSR name in CsrSpec.supported")

  val raw: Seq[CsrSpec] =
    supported.filter(_.kind == CsrKind.Raw)

  private val counterState: Seq[CsrStateSpec] =
    Seq(
      CsrStateSpec("mcycle", 0),
      CsrStateSpec("minstret", 0)
    )

  val state: Seq[CsrStateSpec] =
    raw.map(spec => CsrStateSpec(spec.name, spec.reset)) ++ counterState

  require(state.map(_.name).distinct.size == state.size, "duplicate CSR state name in CsrSpec.state")

  val stateIndex: Map[String, Int] =
    state.map(_.name).zipWithIndex.toMap

  val difftestExport: Seq[String] =
    state.map(_.name)

  val byAddr: Map[Int, CsrSpec] =
    supported.map(spec => spec.addr -> spec).toMap

  val byName: Map[String, CsrSpec] =
    supported.map(spec => spec.name -> spec).toMap

  def contains(addr: Int): Boolean =
    byAddr.contains(addr)

  def addrOf(name: String): Int =
    byName(name).addr
}
