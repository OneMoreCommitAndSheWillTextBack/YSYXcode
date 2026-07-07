package top.dpi

import chisel3._
import chisel3.util.circt.dpi._

object NpcDifftestCommit extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_difftest_commit"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "validMask",
      "finishMask",
      "memValidMask",
      "memWriteMask",
      "pc0",
      "inst0",
      "rawInst0",
      "instLen0",
      "nextPc0",
      "memAddr0",
      "memSize0",
      "pc1",
      "inst1",
      "rawInst1",
      "instLen1",
      "nextPc1",
      "memAddr1",
      "memSize1"
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

object NpcDivPerf extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_div_perf"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "cycles",
      "special"
    )
  )
}
