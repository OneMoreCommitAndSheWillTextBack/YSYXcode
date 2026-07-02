package top.backend.decoder

import chisel3._
import chisel3.util.BitPat
import top.backend.decoder.rvi._

private[decoder] object DecodeTable {
  val default: List[UInt] = NpcDecode(legal = false).signals

  private val groups: Seq[DecodeGroup] = Seq(
    RviAluDecode,
    RviUpperDecode,
    RviMemDecode,
    RviBranchDecode,
    RviJumpDecode,
    RviSystemDecode
  )

  val table: Array[(BitPat, List[UInt])] =
    groups.flatMap(_.table).toArray

  require(
    table.forall { case (_, signals) => signals.length == default.length },
    "Decode tables have different column size"
  )
}
