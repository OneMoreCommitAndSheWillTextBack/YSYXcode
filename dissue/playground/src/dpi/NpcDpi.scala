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
      "memSize1",
      "asyncIntrValid",
      "asyncIntrCause",
      "asyncIntrEpc"
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

object NpcFrontendPerf extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_frontend_perf"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "events",
      "ifuCorrection",
      "fetchQueueOccupancy",
      "fetchQueueEnqueueWidth",
      "fetchQueueDequeueWidth",
      "icacheLookupValid",
      "icacheBlockValidMask",
      "icacheMissMask",
      "icacheBlockAddr0",
      "icacheBlockAddr1"
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

object NpcBpuPerf extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_bpu_perf"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "cfiClass",
      "predHit",
      "predTaken",
      "actualTaken",
      "correct"
    )
  )
}

object NpcMemPerf extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_mem_perf"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "events",
      "mshrOccupancy",
      "storeQueueOccupancy",
      "loadTxnOccupancy"
    )
  )
}

object NpcPipelineTrace extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_pipeline_trace"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "kind",
      "flags",
      "slot",
      "robIdx",
      "producer0",
      "producer1",
      "pc",
      "inst",
      "rawInst",
      "sequence",
      "epoch",
      "resource",
      "txnId"
    )
  )
}
