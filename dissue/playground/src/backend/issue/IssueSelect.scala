package top.backend.issue

import chisel3._
import top.backend.bundle.IssueControl
import top.config.BackendConfig

class IssueSelect(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new IssueControl(cfg))

  private val ageWidth = cfg.robIdxWidth + 1

  private def extendRobIdx(idx: UInt): UInt = {
    val extended = Wire(UInt(ageWidth.W))
    extended := idx
    extended
  }

  private def ageFromHead(idx: UInt): UInt = {
    val idxExt  = extendRobIdx(idx)
    val headExt = extendRobIdx(io.robHead)

    Mux(
      idx >= io.robHead,
      idxExt - headExt,
      idxExt + cfg.robEntries.U(ageWidth.W) - headExt
    )
  }

  private val age = Wire(Vec(cfg.issueQueueEntries, UInt(ageWidth.W)))
  for (i <- 0 until cfg.issueQueueEntries) {
    age(i) := ageFromHead(io.robIdx(i))
  }

  for (i <- 0 until cfg.issueQueueEntries) {
    val hasOlder = (0 until cfg.issueQueueEntries).map { j =>
      val olderAge = age(j) < age(i)
      val tieBreak = if (j < i) age(j) === age(i) else false.B
      io.request(j) && (olderAge || tieBreak)
    }.reduce(_ || _)

    io.grantOH(i) := io.request(i) && !hasOlder
  }
}
