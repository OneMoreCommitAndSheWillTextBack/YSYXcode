package top.dpi

import chisel3._
import chisel3.util.circt.dpi._

object NpcDifftestCommit extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_difftest_commit"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "validMask",
      "finishMask",
      "pc0",
      "inst0",
      "pc1",
      "inst1"
    )
  )
}

object NpcDifftestContext extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_difftest_context"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "valid",
      "pc",
      "priv",
      "csr",
      "gpr"
    )
  )
}

object NpcCacheHit extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_cache_hit"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "hit"
    )
  )
}

object NpcIssueQueuePerf extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_issue_queue_perf"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "issueCount",
      "occupancy",
      "blockReady",
      "blockOperand"
    )
  )
}
