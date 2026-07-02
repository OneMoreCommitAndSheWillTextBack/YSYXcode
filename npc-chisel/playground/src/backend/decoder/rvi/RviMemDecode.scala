package top.backend.decoder.rvi

import chisel3._
import chisel3.util.BitPat
import top.backend.decoder._

private[decoder] object RviMemDecode extends DecodeGroup {
  import DecodeDsl._
  import RviPatterns._

  val table: Seq[(BitPat, List[UInt])] = Seq(
    LW  -> load(size = 2),
    LBU -> load(size = 0, unsigned = true),
    SW  -> store(size = 2),
    SB  -> store(size = 0)
  )
}
