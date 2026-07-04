package top.backend.decoder.rvi

import chisel3._
import chisel3.util.BitPat
import top.backend.decoder._

private[decoder] object RviMemDecode extends DecodeGroup {
  import DecodeDsl._
  import RviPatterns._

  val table: Seq[(BitPat, List[UInt])] = Seq(
    LB  -> load(size = MemSize.byte),
    LH  -> load(size = MemSize.half),
    LW  -> load(size = MemSize.word),
    LBU -> load(size = MemSize.byte, unsigned = true),
    LHU -> load(size = MemSize.half, unsigned = true),
    SB  -> store(size = MemSize.byte),
    SH  -> store(size = MemSize.half),
    SW  -> store(size = MemSize.word)
  )
}
