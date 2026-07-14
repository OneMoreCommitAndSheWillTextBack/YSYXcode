package top.core.mem

import chisel3._
import chisel3.util.{Decoupled, Mux1H, PopCount}
import top.core.bundle.{OwnedDataMemReq, RobAge, RobRecovery}

/** Small FIFO that can discard requests belonging to a recovered speculative path.
  *
  * A recovery pauses both sides for one cycle, then compacts retained requests. Committed stores use an owner with
  * `squashable = false` and therefore remain ordered with the older requests that precede them.
  */
class RecoverableDmemQueue(
  addrWidth:   Int,
  dataWidth:   Int,
  robIdxWidth: Int,
  robEntries:  Int,
  depth:       Int)
    extends Module {
  require(depth > 0, "RecoverableDmemQueue depth must be positive")

  private val countWidth = math.max(chisel3.util.log2Ceil(depth + 1), 1)
  private val entryIdxWidth = math.max(chisel3.util.log2Ceil(depth), 1)

  val io = IO(new Bundle {
    val enq = Flipped(Decoupled(new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth)))
    val deq = Decoupled(new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth))

    val flush   = Input(Bool())
    val recover = Input(new RobRecovery(robIdxWidth))
    val robHead = Input(UInt(robIdxWidth.W))
  })

  private val entries = Reg(Vec(depth, new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth)))
  private val count   = RegInit(0.U(countWidth.W))
  private val squash  = io.flush || io.recover.valid

  io.deq.valid := count =/= 0.U && !squash
  io.deq.bits  := entries(0)
  // Do not let global flush influence ready: retirement may need to enqueue an older committed store in the same cycle
  // that produces the flush. Recovery itself already blocks all backend producers.
  io.enq.ready := count < depth.U && !io.recover.valid

  private def discard(entry: OwnedDataMemReq): Bool =
    entry.owner.squashable && (io.flush ||
      (io.recover.valid && RobAge.isYounger(entry.owner.robIdx, io.recover.robIdx, io.robHead, robEntries, robIdxWidth)))

  private val keep = Wire(Vec(depth, Bool()))
  for (index <- 0 until depth) {
    keep(index) := index.U < count && !discard(entries(index))
  }

  private val compacted = Wire(Vec(depth, new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth)))
  for (destination <- 0 until depth) {
    val sourceOH = Wire(Vec(depth, Bool()))
    for (source <- 0 until depth) {
      sourceOH(source) := keep(source) && PopCount(keep.take(source)) === destination.U
    }
      compacted(destination) := Mux1H(sourceOH, entries)
  }

  private val squashNext = Wire(Vec(depth, new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth)))
  for (index <- 0 until depth) {
    squashNext(index) := compacted(index)
  }
  private val retainedCount = PopCount(keep)
  private val squashEnqueue = io.enq.fire && !discard(io.enq.bits)
  private val squashEnqueueIndex = Wire(UInt(entryIdxWidth.W))
  squashEnqueueIndex := retainedCount(entryIdxWidth - 1, 0)
  when(squashEnqueue) {
    squashNext(squashEnqueueIndex) := io.enq.bits
  }

  private val afterDequeue = Wire(Vec(depth, new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth)))
  for (index <- 0 until depth) {
    afterDequeue(index) := (if (index == depth - 1) 0.U.asTypeOf(entries(index)) else entries(index + 1))
  }

  private val normalNext = Wire(Vec(depth, new OwnedDataMemReq(addrWidth, dataWidth, robIdxWidth)))
  for (index <- 0 until depth) {
    normalNext(index) := Mux(io.deq.fire, afterDequeue(index), entries(index))
  }
  private val enqueueIndex = Wire(UInt(entryIdxWidth.W))
  private val enqueuePosition = Mux(io.deq.fire, count - 1.U, count)
  enqueueIndex := enqueuePosition(entryIdxWidth - 1, 0)
  when(io.enq.fire) {
    normalNext(enqueueIndex) := io.enq.bits
  }

  when(squash) {
    entries := squashNext
    count   := retainedCount + squashEnqueue
  }.otherwise {
    entries := normalNext
    when(io.enq.fire && !io.deq.fire) {
      count := count + 1.U
    }.elsewhen(io.deq.fire && !io.enq.fire) {
      count := count - 1.U
    }
  }
}
