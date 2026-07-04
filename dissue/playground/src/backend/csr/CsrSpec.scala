package top.backend.csr

final case class CsrSpec(
  name:      String,
  addr:      Int,
  reset:     BigInt,
  writeMask: BigInt,
  doc:       String)

object CsrSpec {
  val supported: Seq[CsrSpec] = Seq(
    CsrSpec(
      name = "mstatus",
      addr = CsrAddr.mstatus,
      reset = 0,
      writeMask = Mstatus.firstWriteMask,
      doc = "Machine status register. First version exposes MIE, MPIE, and MPP."
    ),
    CsrSpec(
      name = "mtvec",
      addr = CsrAddr.mtvec,
      reset = 0,
      writeMask = BigInt("ffffffff", 16),
      doc = "Machine trap vector. First version stores MODE but synchronous traps target BASE."
    ),
    CsrSpec(
      name = "mepc",
      addr = CsrAddr.mepc,
      reset = 0,
      writeMask = BigInt("ffffffff", 16),
      doc = "Machine exception program counter. Bit 0 is hardwired to zero on writes."
    ),
    CsrSpec(
      name = "mcause",
      addr = CsrAddr.mcause,
      reset = 0,
      writeMask = BigInt("ffffffff", 16),
      doc = "Machine trap cause register. First version treats all bits as writable."
    ),
    CsrSpec(
      name = "mtval",
      addr = CsrAddr.mtval,
      reset = 0,
      writeMask = BigInt("ffffffff", 16),
      doc = "Machine trap value register. First version treats all bits as writable."
    )
  )

  val byAddr: Map[Int, CsrSpec] =
    supported.map(spec => spec.addr -> spec).toMap
}
