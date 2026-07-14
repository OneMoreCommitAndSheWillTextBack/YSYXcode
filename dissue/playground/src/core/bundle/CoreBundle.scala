package top.core.bundle

import chisel3._
import chisel3.util.Valid

/** Identifies the youngest instruction that survives a selective backend recovery.
  *
  * Every live ROB entry at or before `robIdx` remains architecturally visible; later entries belong to the abandoned
  * path. The boundary is intentionally independent of redirect target so backend structures can consume it without
  * depending on frontend control flow.
  */
class RobRecovery(robIdxWidth: Int) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(robIdxWidth.W)
}

/** Common ROB-ring ordering helpers for speculative backend state. */
object RobAge {
  private def extend(index: UInt, width: Int): UInt = {
    val extended = Wire(UInt(width.W))
    extended := index
    extended
  }

  def fromHead(index: UInt, head: UInt, entries: Int, robIdxWidth: Int): UInt = {
    val width    = robIdxWidth + 1
    val indexExt = extend(index, width)
    val headExt  = extend(head, width)

    Mux(
      index >= head,
      indexExt - headExt,
      indexExt + entries.U(width.W) - headExt
    )
  }

  def isYounger(index: UInt, boundary: UInt, head: UInt, entries: Int, robIdxWidth: Int): Bool =
    fromHead(index, head, entries, robIdxWidth) > fromHead(boundary, head, entries, robIdxWidth)
}

object DataMemKind {
  val width = 2

  val normal = 0.U(width.W)
  val ptw    = 1.U(width.W)
  val atomic = 2.U(width.W)
}

object DataMemTxn {
  val width = 4

  // Keep normal-load tags below the fixed protocol tags used by non-load paths.
  val loadTagCount = 12
  val atomic       = 12.U(width.W)
  val ptw          = 13.U(width.W)
  val store        = 14.U(width.W)

  def isLoad(txnId: UInt): Bool =
    txnId < loadTagCount.U(width.W)
}

object MemPerfEvent {
  val dcacheAccess                = 0
  val dcacheHit                   = 1
  val dcacheMiss                  = 2
  val dcacheBypass                = 3
  val mshrAlloc                   = 4
  val mshrMerge                   = 5
  val mshrFullStallCycle          = 6
  val hitUnderMiss                = 7
  val queuedMiss                  = 8
  val refillStart                 = 9
  val refillComplete              = 10
  val refillFault                 = 11
  val loadTxnFullStallCycle       = 12
  val sqAlloc                     = 13
  val sqFullStallCycle            = 14
  val forwardFull                 = 15
  val forwardPartial              = 16
  val forwardUnresolvedStallCycle = 17
  val storeDrain                  = 18
  val width                       = 19

  def bit(index: Int, enabled: Bool): UInt =
    Mux(enabled, (1.U(width.W) << index)(width - 1, 0), 0.U(width.W))
}

object CfiType {
  val width = 3

  val none   = 0.U(width.W)
  val branch = 1.U(width.W)
  val jal    = 2.U(width.W)
  val jalr   = 3.U(width.W)
  val call   = 4.U(width.W)
  val ret    = 5.U(width.W)
}

class Redirect(addrWidth: Int = 32) extends Bundle {
  val valid  = Bool()
  val target = UInt(addrWidth.W)
}

class FetchInstPayload(addrWidth: Int = 32) extends Bundle {
  val pc      = UInt(addrWidth.W)
  val inst    = UInt(32.W)
  val rawInst = UInt(32.W)
  val isRVC   = Bool()
  val instLen = UInt(3.W)

  val predTaken  = Bool()
  val predNpc    = UInt(addrWidth.W)
  val predTarget = UInt(addrWidth.W)

  val exception = new FetchException(addrWidth)
}

class FetchException(addrWidth: Int = 32) extends Bundle {
  val valid = Bool()
  val cause = UInt(5.W)
  val tval  = UInt(addrWidth.W)
}

class FrontendToBackend(issueWidth: Int = 2, addrWidth: Int = 32) extends Bundle {
  val insts = Vec(issueWidth, Valid(new FetchInstPayload(addrWidth)))
}

class BpuUpdatePayload(addrWidth: Int = 32) extends Bundle {
  val pc      = UInt(addrWidth.W)
  val cfiType = UInt(CfiType.width.W)
  val taken   = Bool()
  val target  = UInt(addrWidth.W)
  val instLen = UInt(3.W)
}

class BackendToFrontend(addrWidth: Int = 32) extends Bundle {
  val trapRedirect   = new Redirect(addrWidth)
  val branchRedirect = new Redirect(addrWidth)
  val predRedirect   = new Redirect(addrWidth)
  val bpuUpdate      = Valid(new BpuUpdatePayload(addrWidth))
}

class InstMemReq(addrWidth: Int = 32) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class InstMemResp(fetchBytes: Int = 8) extends Bundle {
  val data = UInt((fetchBytes * 8).W)
}

class DataMemReq(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val addr      = UInt(addrWidth.W)
  val write     = Bool()
  val size      = UInt(3.W)
  val unsigned  = Bool()
  val wdata     = UInt(dataWidth.W)
  val wmask     = UInt((dataWidth / 8).W)
  val txnId     = UInt(DataMemTxn.width.W)
  val cacheable = Bool()
  val kind      = UInt(DataMemKind.width.W)
}

/** Metadata that lets the internal memory path distinguish committed requests from speculative ones. */
class DataMemOwner(robIdxWidth: Int) extends Bundle {
  val squashable = Bool()
  val robIdx     = UInt(robIdxWidth.W)
}

/** A backend data request together with the ROB instruction that owns it. */
class OwnedDataMemReq(addrWidth: Int, dataWidth: Int, robIdxWidth: Int) extends Bundle {
  val request = new DataMemReq(addrWidth, dataWidth)
  val owner   = new DataMemOwner(robIdxWidth)
}

class DataMemResp(dataWidth: Int = 32) extends Bundle {
  val data  = UInt(dataWidth.W)
  val fault = Bool()
  val txnId = UInt(DataMemTxn.width.W)
}
