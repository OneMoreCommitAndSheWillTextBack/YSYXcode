package top.backend.decoder.rvi

import chisel3._
import chisel3.util.BitPat
import top.backend.decoder._

private[decoder] object RviAluDecode extends DecodeGroup {
  import DecodeDsl._
  import RviPatterns._

  val table: Seq[(BitPat, List[UInt])] = Seq(
    ADD  -> aluReg(AluOp.add),
    ADDI -> aluImm(AluOp.add)
  )
}
