package top.core.backend.decoder.rvi

import chisel3._
import chisel3.util.BitPat
import top.core.backend.csr.CsrOp
import top.core.backend.decoder._

private[decoder] object RviSystemDecode extends DecodeGroup {
  import DecodeDsl._
  import RviPatterns._

  val table: Seq[(BitPat, List[UInt])] = Seq(
    CSRRW  -> csr(CsrOp.rw),
    CSRRS  -> csr(CsrOp.rs),
    CSRRC  -> csr(CsrOp.rc),
    CSRRWI -> csrImm(CsrOp.rw),
    CSRRSI -> csrImm(CsrOp.rs),
    CSRRCI -> csrImm(CsrOp.rc),
    FENCE  -> fence(),
    FENCE_I -> fence(fenceI = true),
    ECALL  -> ecall,
    EBREAK -> ebreak,
    // WFI currently returns immediately through the retire-only fence path.
    WFI    -> fence(),
    SFENCE_VMA -> fence(sfence = true),
    SRET   -> sret,
    MRET   -> mret
  )
}
