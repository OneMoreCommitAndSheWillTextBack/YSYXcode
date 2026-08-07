package top.core.backend.lsu

import chisel3._
import chisel3.util.{Decoupled, OHToUInt, PopCount, PriorityEncoderOH, RegEnable, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{StoreDrainRequest, StoreQueueEvent, StoreResponseEvent}
import top.core.bundle.{DataMemKind, DataMemResp, DataMemTxn, OwnedDataMemReq}

/** Reserves store transaction slots and retains their SQ mapping through the matching response.
  *
  * One request may wait at the arbiter while older requests are already in the outbound FIFO or lower memory. Slot
  * reuse is permitted only after the response that frees the previous mapping.
  */
class StoreDrainEngine(cfg: BackendConfig = BackendConfig()) extends Module {
  private val slotCount = cfg.storeTxnEntries
  private val slotWidth = math.max(chisel3.util.log2Ceil(slotCount), 1)

  require(slotCount <= DataMemTxn.slotCount, "store transaction entries exceed the store tag slot field")

  val io = IO(new Bundle {
    val normal = Flipped(Decoupled(new StoreDrainRequest(cfg)))

    val serialized         = Input(Valid(new StoreDrainRequest(cfg)))
    val serializedCanStart = Input(Bool())
    val serializedSuccess  = Output(Bool())
    val serializedFault    = Output(Valid(new StoreDrainRequest(cfg)))

    val request             = Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
    val externalFire        = Input(Valid(UInt(DataMemTxn.width.W)))
    val response            = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val allowFaultWriteback = Input(Bool())

    val reserve  = Output(Valid(new StoreQueueEvent(cfg)))
    val issue    = Output(Valid(new StoreQueueEvent(cfg)))
    val complete = Output(Valid(new StoreResponseEvent(cfg)))

    val normalOutstanding     = Output(Bool())
    val serializedOutstanding = Output(Bool())
    val idle                  = Output(Bool())
  })

  private val active       = RegInit(VecInit(Seq.fill(slotCount)(false.B)))
  private val externalized = RegInit(VecInit(Seq.fill(slotCount)(false.B)))
  private val slotInfo     = RegInit(
    VecInit(Seq.fill(slotCount)(0.U.asTypeOf(new StoreDrainRequest(cfg))))
  )

  private val holdValid = RegInit(false.B)
  private val holdSlot  = RegInit(0.U(slotWidth.W))
  private val holdInfo  = RegInit(0.U.asTypeOf(new StoreDrainRequest(cfg)))

  private val responseSlot           = DataMemTxn.slot(io.response.bits.txnId)
  private val responseInRange        = responseSlot < slotCount.U
  private val responseMatchOH        = VecInit((0 until slotCount).map { slot =>
    DataMemTxn.isStore(io.response.bits.txnId) && responseInRange && responseSlot === slot.U &&
    active(slot) && externalized(slot)
  })
  private val responseMatch          = responseMatchOH.asUInt.orR
  private val responseIdx            = OHToUInt(responseMatchOH)
  private val responseInfo           = slotInfo(responseIdx)
  private val responseNeedsWriteback = responseMatch && responseInfo.mmio && io.response.bits.fault

  // Unknown store tags are consumed to keep the lower response path live, then reported as protocol errors below.
  io.response.ready := !responseMatch || !responseNeedsWriteback || io.allowFaultWriteback
  private val responseFire = io.response.fire && responseMatch

  private val freeSlotOH     = VecInit(
    (0 until slotCount).map(slot =>
      !active(slot) ||
        (responseFire && responseIdx === slot.U)
    )
  ).asUInt
  private val hasFreeSlot    = freeSlotOH.orR
  private val freeSlot       = OHToUInt(PriorityEncoderOH(freeSlotOH))
  private val canCapture     = !holdValid && hasFreeSlot
  private val takeSerialized = canCapture && io.serializedCanStart && io.serialized.valid

  io.normal.ready := canCapture && !takeSerialized
  private val takeNormal  = io.normal.fire
  private val capture     = takeSerialized || takeNormal
  private val captureInfo = Mux(takeSerialized, io.serialized.bits, io.normal.bits)

  io.reserve.valid       := capture
  io.reserve.bits.sqIdx  := captureInfo.sqIdx
  io.reserve.bits.robIdx := captureInfo.robIdx

  io.request.valid                  := holdValid
  io.request.bits                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  io.request.bits.request.addr      := holdInfo.addr
  io.request.bits.request.write     := true.B
  io.request.bits.request.size      := holdInfo.size
  io.request.bits.request.unsigned  := false.B
  io.request.bits.request.wdata     := holdInfo.data
  io.request.bits.request.wmask     := holdInfo.mask
  io.request.bits.request.txnId     := DataMemTxn.storeTag(holdSlot)
  io.request.bits.request.cacheable := !holdInfo.mmio
  io.request.bits.request.kind      := DataMemKind.normal
  io.request.bits.owner.squashable  := false.B
  io.request.bits.owner.robIdx      := holdInfo.robIdx

  private val externalSlot    = DataMemTxn.slot(io.externalFire.bits)
  private val externalMatchOH = VecInit((0 until slotCount).map { slot =>
    io.externalFire.valid && DataMemTxn.isStore(io.externalFire.bits) && externalSlot === slot.U &&
    active(slot) && !externalized(slot)
  })
  private val externalMatch   = externalMatchOH.asUInt.orR
  private val externalIdx     = OHToUInt(externalMatchOH)

  io.issue.valid       := externalMatch
  io.issue.bits.sqIdx  := slotInfo(externalIdx).sqIdx
  io.issue.bits.robIdx := slotInfo(externalIdx).robIdx

  io.complete.valid        := responseFire
  io.complete.bits.sqIdx   := responseInfo.sqIdx
  io.complete.bits.robIdx  := responseInfo.robIdx
  io.complete.bits.fault   := io.response.bits.fault
  io.complete.bits.mmio    := responseInfo.mmio
  io.serializedSuccess     := responseFire && responseInfo.mmio && !io.response.bits.fault
  io.serializedFault.valid := responseFire && responseInfo.mmio && io.response.bits.fault
  io.serializedFault.bits  := responseInfo

  when(capture) {
    holdValid              := true.B
    holdSlot               := freeSlot
    holdInfo               := captureInfo
    active(freeSlot)       := true.B
    externalized(freeSlot) := false.B
    slotInfo(freeSlot)     := captureInfo
  }
  when(io.request.fire) {
    holdValid := false.B
  }
  for (slot <- 0 until slotCount) {
    when(externalMatchOH(slot)) {
      externalized(slot) := true.B
    }
    when(responseFire && responseIdx === slot.U) {
      active(slot)       := false.B
      externalized(slot) := false.B
    }
    when(capture && freeSlot === slot.U) {
      active(slot)       := true.B
      externalized(slot) := false.B
    }
  }

  io.normalOutstanding     := VecInit((0 until slotCount).map(slot => active(slot) && !slotInfo(slot).mmio)).asUInt.orR
  io.serializedOutstanding := VecInit((0 until slotCount).map(slot => active(slot) && slotInfo(slot).mmio)).asUInt.orR
  io.idle                  := !active.asUInt.orR && !holdValid

  when(io.externalFire.valid && DataMemTxn.isStore(io.externalFire.bits)) {
    assert(PopCount(externalMatchOH) === 1.U, "external store request must match one reserved transaction slot")
  }
  when(io.response.valid) {
    assert(DataMemTxn.isStore(io.response.bits.txnId), "store drain engine received a non-store response")
  }
  when(io.response.fire) {
    assert(PopCount(responseMatchOH) === 1.U, "store response must match one externalized transaction slot")
  }
  when(responseFire && !responseInfo.mmio) {
    assert(!io.response.bits.fault, "committed cacheable store response fault is fatal")
  }
  for (left <- 0 until slotCount) {
    for (right <- left + 1 until slotCount) {
      when(active(left) && active(right)) {
        assert(DataMemTxn.storeTag(left.U) =/= DataMemTxn.storeTag(right.U), "live store tags must be unique")
      }
    }
  }

  private val stalledRequest = RegNext(io.request.valid && !io.request.ready, false.B)
  private val stalledBits    = RegEnable(io.request.bits.asUInt, io.request.valid && !io.request.ready)
  when(stalledRequest) {
    assert(io.request.valid && io.request.bits.asUInt === stalledBits, "store request changed while stalled")
  }
}
