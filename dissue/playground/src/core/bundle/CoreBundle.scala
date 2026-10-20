package top.core.bundle

import chisel3._
import chisel3.util.{Cat, Valid}
import top.config.FrontendPayloadConfig
import top.core.frontend.bundle.{FetchTargetTag, RasAction}

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
  val classWidth = 2
  val slotWidth  = 2
  val width      = classWidth + slotWidth
  val slotCount  = 1 << slotWidth

  private val loadClass   = 0
  private val storeClass  = 1
  private val ptwClass    = 2
  private val atomicClass = 3

  private def encode(txnClass: Int, slot: UInt): UInt = {
    val result = Wire(UInt(width.W))
    result := (txnClass << slotWidth).U(width.W) | slot
    result
  }

  def loadTag(slot: UInt): UInt = encode(loadClass, slot)

  def storeTag(slot: UInt): UInt = encode(storeClass, slot)

  val ptwTag:    UInt = "b1000".U(width.W)
  val atomicTag: UInt = "b1100".U(width.W)

  def txnClass(txnId: UInt): UInt = txnId(width - 1, slotWidth)

  def slot(txnId: UInt): UInt = txnId(slotWidth - 1, 0)

  def isLoad(txnId: UInt): Bool = txnClass(txnId) === loadClass.U

  def isStore(txnId: UInt): Bool = txnClass(txnId) === storeClass.U

  def isPtw(txnId: UInt): Bool = txnClass(txnId) === ptwClass.U

  def isAtomic(txnId: UInt): Bool = txnClass(txnId) === atomicClass.U
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

/** Performance-only control-flow buckets. These do not change the architectural CFI decode. */
object BpuCfiClass {
  val width = 2

  val branch = 0.U(width.W)
  val jal    = 1.U(width.W)
  val jalr   = 2.U(width.W)
  val ret    = 3.U(width.W)
}

class Redirect(addrWidth: Int = 32) extends Bundle {
  val valid  = Bool()
  val target = UInt(addrWidth.W)
}

class FetchInstPayload(cfg: FrontendPayloadConfig = FrontendPayloadConfig()) extends Bundle {
  val pc      = UInt(cfg.addrWidth.W)
  val inst    = UInt(32.W)
  val rawInst = UInt(32.W)
  val isRVC   = Bool()
  val instLen = UInt(3.W)

  /** A BTB prediction matched this instruction's PC within its fetch block. */
  val predHit    = Bool()
  val predTaken  = Bool()
  val predNpc    = UInt(cfg.addrWidth.W)
  val predTarget = UInt(cfg.addrWidth.W)

  val ftqTag         = new FetchTargetTag(cfg)
  val ftqInstOrdinal = UInt(cfg.ftqInstCountBits.W)

  val exception = new FetchException(cfg.addrWidth)
}

class FetchException(addrWidth: Int = 32) extends Bundle {
  val valid = Bool()
  val cause = UInt(5.W)
  val tval  = UInt(addrWidth.W)
}

class FrontendToBackend(issueWidth: Int = 2, cfg: FrontendPayloadConfig = FrontendPayloadConfig()) extends Bundle {
  val insts = Vec(issueWidth, Valid(new FetchInstPayload(cfg)))
}

class CfiRecoveryPayload(cfg: FrontendPayloadConfig = FrontendPayloadConfig()) extends Bundle {
  val ftqTag          = new FetchTargetTag(cfg)
  val ftqInstOrdinal  = UInt(cfg.ftqInstCountBits.W)
  val pc              = UInt(cfg.addrWidth.W)
  val cfiType         = UInt(CfiType.width.W)
  val actualTaken     = Bool()
  val actualTarget    = UInt(cfg.addrWidth.W)
  val actualNpc       = UInt(cfg.addrWidth.W)
  val instLen         = UInt(3.W)
  val rasAction       = UInt(RasAction.width.W)
  val canonicalReturn = Bool()
}

class BackendToFrontend(cfg: FrontendPayloadConfig = FrontendPayloadConfig()) extends Bundle {
  val trapRedirect     = new Redirect(cfg.addrWidth)
  val branchRedirect   = new Redirect(cfg.addrWidth)
  val predRedirect     = new Redirect(cfg.addrWidth)
  val icacheInvalidate = Bool()
  val cfiRecovery      = Valid(new CfiRecoveryPayload(cfg))
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
