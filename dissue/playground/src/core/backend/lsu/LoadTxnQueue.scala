package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Fill, MuxLookup, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{IssueWakeup, RobWritebackPacket}
import top.core.backend.decoder.MemSize
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.bundle.{DataMemResp, DataMemTxn, RobAge, RobRecovery}

class LoadTxnAlloc(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val robIdx      = UInt(cfg.robIdxWidth.W)
  val vaddr       = UInt(cfg.addrWidth.W)
  val paddr       = UInt(cfg.addrWidth.W)
  val size        = UInt(3.W)
  val unsigned    = Bool()
  val forwardMask = UInt((cfg.dataWidth / 8).W)
  val forwardData = UInt(cfg.dataWidth.W)
}

/** Associates an outstanding data-cache request with backend state.
  *
  * DCache responses carry only txnId and raw data. This queue restores the ROB destination, applies any partial store
  * forwarding, and owns load fault attribution.
  */
class LoadTxnQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount = cfg.loadTxnEntries
  private val idxWidth   = math.max(chisel3.util.log2Ceil(entryCount), 1)
  private val dataBytes  = cfg.dataWidth / 8
  private val tagCount   = top.core.bundle.DataMemTxn.loadTagCount

  require(entryCount <= tagCount, "load transaction entries exceed available data-memory tags")

  val io = IO(new Bundle {
    val alloc         = Flipped(Decoupled(new LoadTxnAlloc(cfg)))
    val allocTxnId    = Output(UInt(top.core.bundle.DataMemTxn.width.W))
    val complete      = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val allowComplete = Input(Bool())
    val writeback     = Valid(new RobWritebackPacket(cfg))
    val wakeup        = Output(new IssueWakeup(cfg))
    val flush         = Input(Bool())
    val recover       = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead       = Input(UInt(cfg.robIdxWidth.W))
    // A cancellation source may release a tag only after it has guaranteed that
    // the corresponding request cannot produce a later response.
    val cancel        = Input(Vec(cfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))
    val occupancy     = Output(UInt(math.max(chisel3.util.log2Ceil(entryCount + 1), 1).W))
    val empty         = Output(Bool())
  })

  private val valid       = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val txnId       = Reg(Vec(entryCount, UInt(top.core.bundle.DataMemTxn.width.W)))
  private val robIdx      = Reg(Vec(entryCount, UInt(cfg.robIdxWidth.W)))
  private val vaddr       = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val paddr       = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val size        = Reg(Vec(entryCount, UInt(3.W)))
  private val unsigned    = Reg(Vec(entryCount, Bool()))
  private val forwardMask = Reg(Vec(entryCount, UInt(dataBytes.W)))
  private val forwardData = Reg(Vec(entryCount, UInt(cfg.dataWidth.W)))

  private val freeEntryOH  = PriorityEncoderOH(VecInit(valid.map(!_)).asUInt)
  private val freeEntryIdx = OHToUInt(freeEntryOH)
  private val hasFreeEntry = freeEntryOH.orR

  // Recovering the ROB entry alone is insufficient to reuse its tag: a bypass
  // transaction may still return. Only completion or an explicit cancellation
  // source is allowed to release the tag.
  private val tagInUse   = RegInit(VecInit(Seq.fill(tagCount)(false.B)))
  private val freeTagOH  = PriorityEncoderOH(VecInit(tagInUse.map(!_)).asUInt)
  private val hasFreeTag = freeTagOH.orR
  private val allocTxnId = Wire(UInt(top.core.bundle.DataMemTxn.width.W))
  allocTxnId := OHToUInt(freeTagOH)

  io.alloc.ready := hasFreeEntry && hasFreeTag && !io.flush && !io.recover.valid
  io.allocTxnId  := allocTxnId
  io.occupancy   := PopCount(valid)
  io.empty       := !valid.asUInt.orR

  private val responseInRange = DataMemTxn.isLoad(io.complete.bits.txnId)
  private val responseMatchOH = VecInit((0 until entryCount).map { entry =>
    valid(entry) && txnId(entry) === io.complete.bits.txnId
  }).asUInt
  private val responseValid   = responseMatchOH.orR
  private val responseIdx     = OHToUInt(responseMatchOH)

  private val killedByRecovery = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    killedByRecovery(entry) := valid(entry) && io.recover.valid &&
      RobAge.isYounger(robIdx(entry), io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  }

  private val responseKilledByRecovery = responseValid && io.recover.valid &&
    RobAge.isYounger(robIdx(responseIdx), io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

  // Unknown tags and squashed owners are stale responses. Acknowledge them so the DCache can retire its waiter and
  // the transaction tag can never alias a newer load.
  io.complete.ready := io.flush || !responseValid || responseKilledByRecovery || io.allowComplete

  private val selectedForwardMask = forwardMask(responseIdx)
  private val expandedForwardMask = Cat((0 until dataBytes).reverse.map { byte =>
    Fill(8, selectedForwardMask(byte))
  })
  private val mergedData          = (io.complete.bits.data & ~expandedForwardMask) |
    (forwardData(responseIdx) & expandedForwardMask)

  private def extendLoad(data: UInt, loadSize: UInt, loadUnsigned: Bool): UInt = {
    val byte = data(7, 0)
    val half = data(15, 0)
    MuxLookup(loadSize, data)(
      Seq(
        MemSize.byte.U -> Mux(
          loadUnsigned,
          Cat(0.U((cfg.dataWidth - 8).W), byte),
          Cat(Fill(cfg.dataWidth - 8, byte(7)), byte)
        ),
        MemSize.half.U -> Mux(
          loadUnsigned,
          Cat(0.U((cfg.dataWidth - 16).W), half),
          Cat(Fill(cfg.dataWidth - 16, half(15)), half)
        )
      )
    )
  }

  val responseResult = extendLoad(mergedData, size(responseIdx), unsigned(responseIdx))
  val responseFire   = io.complete.valid && io.complete.ready && responseValid && !io.flush && !responseKilledByRecovery

  io.writeback.valid          := responseFire
  io.writeback.bits           := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.robIdx    := robIdx(responseIdx)
  io.writeback.bits.result    := responseResult
  io.writeback.bits.storeAddr := paddr(responseIdx)
  when(io.complete.bits.fault) {
    io.writeback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAccessFault, vaddr(responseIdx), cfg)
  }

  io.wakeup.valid  := responseFire && !io.complete.bits.fault
  io.wakeup.robIdx := robIdx(responseIdx)
  io.wakeup.data   := responseResult

  for (entry <- 0 until entryCount) {
    when(io.flush) {
      valid(entry) := false.B
    }.elsewhen(io.recover.valid) {
      when(responseFire && responseIdx === entry.U) {
        valid(entry) := false.B
      }
      when(killedByRecovery(entry)) {
        valid(entry) := false.B
      }
    }.otherwise {
      when(responseFire && responseIdx === entry.U) {
        valid(entry) := false.B
      }
      when(io.alloc.fire && freeEntryIdx === entry.U) {
        valid(entry)       := true.B
        txnId(entry)       := allocTxnId
        robIdx(entry)      := io.alloc.bits.robIdx
        vaddr(entry)       := io.alloc.bits.vaddr
        paddr(entry)       := io.alloc.bits.paddr
        size(entry)        := io.alloc.bits.size
        unsigned(entry)    := io.alloc.bits.unsigned
        forwardMask(entry) := io.alloc.bits.forwardMask
        forwardData(entry) := io.alloc.bits.forwardData
      }
    }
  }

  for (tag <- 0 until tagCount) {
    when(io.alloc.fire && allocTxnId === tag.U) {
      tagInUse(tag) := true.B
    }
    when(io.complete.fire && responseInRange && io.complete.bits.txnId === tag.U) {
      tagInUse(tag) := false.B
    }
    val canceled = io.cancel.map(cancel => cancel.valid && cancel.bits === tag.U).reduce(_ || _)
    when(canceled) {
      tagInUse(tag) := false.B
    }
  }
}
