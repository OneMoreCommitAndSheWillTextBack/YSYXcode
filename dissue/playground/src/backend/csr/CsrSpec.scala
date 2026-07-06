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

object CsrSpec {
  private val fullMask = BigInt("ffffffff", 16)

  private def raw(name: String, addr: Int, reset: BigInt = 0, writeMask: BigInt = fullMask, doc: String): CsrSpec =
    CsrSpec(name, addr, reset, writeMask, CsrKind.Raw, doc)

  private def virt(name: String, addr: Int, writeMask: BigInt = fullMask, doc: String): CsrSpec =
    CsrSpec(name, addr, 0, writeMask, CsrKind.Virtual, doc)

  val supported: Seq[CsrSpec] = Seq(
    raw("mepc", CsrAddr.mepc, writeMask = fullMask & ~BigInt(1), doc = "Machine exception PC."),
    raw("sepc", CsrAddr.sepc, writeMask = fullMask & ~BigInt(1), doc = "Supervisor exception PC."),
    raw("misa", CsrAddr.misa, reset = Misa.rv32ImacSu, writeMask = 0, doc = "NEMU-compatible RV32 IMACSU ISA view."),
    raw("mstatus", CsrAddr.mstatus, writeMask = Mstatus.writeMask, doc = "Machine status register."),
    raw("mstatush", CsrAddr.mstatush, doc = "RV32 upper mstatus placeholder."),
    raw("mcause", CsrAddr.mcause, doc = "Machine trap cause."),
    raw("mtval", CsrAddr.mtval, doc = "Machine trap value."),
    raw("mtvec", CsrAddr.mtvec, doc = "Machine trap vector."),
    raw("mscratch", CsrAddr.mscratch, doc = "Machine scratch register."),
    raw("satp", CsrAddr.satp, doc = "Address translation root. Stored for software compatibility."),
    raw(
      "medeleg",
      CsrAddr.medeleg,
      writeMask = CsrDelegation.writableMedelegMask,
      doc = "Machine exception delegation."
    ),
    raw(
      "mideleg",
      CsrAddr.mideleg,
      writeMask = CsrInterrupt.writableMidelegMask,
      doc = "Machine interrupt delegation."
    ),
    raw("mvendorid", CsrAddr.mvendorid, reset = CsrId.mvendorid, writeMask = 0, doc = "YSYX vendor ID."),
    raw("marchid", CsrAddr.marchid, reset = CsrId.marchid, writeMask = 0, doc = "YSYX architecture ID."),
    raw("mhartid", CsrAddr.mhartid, reset = CsrId.mhartid, writeMask = 0, doc = "Hart ID."),
    raw("mimpid", CsrAddr.mimpid, reset = CsrId.mimpid, writeMask = 0, doc = "Implementation ID placeholder."),
    raw("pmpaddr0", CsrAddr.pmpaddr0, doc = "PMP address placeholder."),
    raw("pmpaddr1", CsrAddr.pmpaddr1, doc = "PMP address placeholder."),
    raw("pmpaddr2", CsrAddr.pmpaddr2, doc = "PMP address placeholder."),
    raw("pmpaddr3", CsrAddr.pmpaddr3, doc = "PMP address placeholder."),
    raw("pmpaddr4", CsrAddr.pmpaddr4, doc = "PMP address placeholder."),
    raw("pmpaddr5", CsrAddr.pmpaddr5, doc = "PMP address placeholder."),
    raw("pmpaddr6", CsrAddr.pmpaddr6, doc = "PMP address placeholder."),
    raw("pmpaddr7", CsrAddr.pmpaddr7, doc = "PMP address placeholder."),
    raw("pmpcfg0", CsrAddr.pmpcfg0, doc = "PMP config placeholder."),
    raw("pmpcfg1", CsrAddr.pmpcfg1, doc = "PMP config placeholder."),
    raw("scause", CsrAddr.scause, doc = "Supervisor trap cause."),
    raw("stval", CsrAddr.stval, doc = "Supervisor trap value."),
    raw("sscratch", CsrAddr.sscratch, doc = "Supervisor scratch register."),
    raw("stvec", CsrAddr.stvec, doc = "Supervisor trap vector."),
    raw("mie", CsrAddr.mie, doc = "Machine interrupt-enable bits."),
    raw("mcounteren", CsrAddr.mcounteren, writeMask = CsrCounter.counterenMask, doc = "Machine counter delegation."),
    raw("scounteren", CsrAddr.scounteren, writeMask = CsrCounter.counterenMask, doc = "Supervisor counter delegation."),
    raw(
      "mcountinhibit",
      CsrAddr.mcountinhibit,
      writeMask = CsrCounter.countInhibitMask,
      doc = "Counter inhibit register."
    ),
    virt("cycle", CsrAddr.cycle, writeMask = 0, doc = "Low cycle counter view."),
    virt("time", CsrAddr.time, writeMask = 0, doc = "Low time counter view."),
    virt("instret", CsrAddr.instret, writeMask = 0, doc = "Low retired-instruction counter view."),
    virt("cycleh", CsrAddr.cycleh, writeMask = 0, doc = "High cycle counter view."),
    virt("timeh", CsrAddr.timeh, writeMask = 0, doc = "High time counter view."),
    virt("instreth", CsrAddr.instreth, writeMask = 0, doc = "High retired-instruction counter view."),
    virt("sie", CsrAddr.sie, writeMask = CsrInterrupt.sieMask, doc = "Supervisor view of delegated mie bits."),
    virt("sip", CsrAddr.sip, writeMask = CsrInterrupt.writableSipMask, doc = "Supervisor view of delegated mip bits."),
    virt("mip", CsrAddr.mip, writeMask = CsrInterrupt.writableMipMask, doc = "Machine interrupt-pending bits."),
    virt("sstatus", CsrAddr.sstatus, writeMask = Sstatus.mask, doc = "Supervisor-visible mstatus projection.")
  )

  val raw: Seq[CsrSpec] =
    supported.filter(_.kind == CsrKind.Raw)

  val byAddr: Map[Int, CsrSpec] =
    supported.map(spec => spec.addr -> spec).toMap

  def contains(addr: Int): Boolean =
    byAddr.contains(addr)
}
