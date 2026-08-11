package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, PopCount, Valid}
import top.config.FrontendConfig
import top.core.bundle.FetchInstPayload

class FetchQueueEntry(cfg: FrontendConfig) extends Bundle {
  val inst     = new FetchInstPayload(cfg.payload)
  val sequence = UInt(cfg.fetchSequenceBits.W)
  val epoch    = UInt(cfg.fetchEpochBits.W)
}

class FetchQueueEnqueue(cfg: FrontendConfig, enqWidth: Int = 4) extends Bundle {
  require(enqWidth > 0, "FetchQueue enqueue width must be positive")

  val insts = Vec(enqWidth, Valid(new FetchQueueEntry(cfg)))
}

class FetchQueueOrderBoundary(cfg: FrontendConfig) extends Bundle {
  val sequence    = UInt(cfg.fetchSequenceBits.W)
  val instOrdinal = UInt(cfg.ftqInstCountBits.W)
}

class FetchQueue(
  cfg:      FrontendConfig = FrontendConfig(),
  depth:    Int = 32,
  enqWidth: Int = 4)
    extends Module {
  require(depth >= 32, "FetchQueue must provide at least 32 instruction slots")
  require((depth & (depth - 1)) == 0, "FetchQueue depth must be a power of two")
  require(enqWidth <= 4, "FetchQueue supports at most four enqueue lanes")

  private val deqWidth      = 2
  private val ptrWidth      = log2Ceil(depth)
  private val countWidth    = log2Ceil(depth + 1)
  private val enqCountWidth = log2Ceil(enqWidth + 1)

  val io = IO(new Bundle {
    val flush          = Input(Bool())
    val pruneFrom      = Flipped(Valid(UInt(cfg.fetchSequenceBits.W)))
    val preserveBefore = Flipped(Valid(new FetchQueueOrderBoundary(cfg)))
    val currentEpoch   = Input(UInt(cfg.fetchEpochBits.W))
    val enq            = Flipped(Decoupled(new FetchQueueEnqueue(cfg, enqWidth)))
    val out            = Decoupled(new FetchPacket(cfg.payload))

    val count        = Output(UInt(countWidth.W))
    val freeCount    = Output(UInt(countWidth.W))
    val empty        = Output(Bool())
    val full         = Output(Bool())
    val enqueueWidth = Output(UInt(enqCountWidth.W))
    val dequeueWidth = Output(UInt(countWidth.W))
  })

  private def ptrAdd(ptr: UInt, increment: UInt): UInt =
    (ptr + increment)(ptrWidth - 1, 0)

  private def sequenceAfter(next: UInt, previous: UInt): Bool = {
    val distance = (next - previous)(cfg.fetchSequenceBits - 1, 0)
    next =/= previous && !distance(cfg.fetchSequenceBits - 1)
  }

  private def entryAfter(next: FetchQueueEntry, previous: FetchQueueEntry): Bool =
    sequenceAfter(next.sequence, previous.sequence) ||
      (next.sequence === previous.sequence && next.inst.pc > previous.inst.pc)

  private def entryBefore(entry: FetchQueueEntry, boundary: FetchQueueOrderBoundary): Bool =
    sequenceAfter(boundary.sequence, entry.sequence) ||
      (entry.sequence === boundary.sequence && entry.inst.ftqInstOrdinal < boundary.instOrdinal)

  private val entries  = Reg(Vec(depth, new FetchQueueEntry(cfg)))
  private val readPtr  = RegInit(0.U(ptrWidth.W))
  private val writePtr = RegInit(0.U(ptrWidth.W))
  private val count    = RegInit(0.U(countWidth.W))

  private val empty = count === 0.U
  private val full  = count === depth.U

  private val headEntry   = entries(readPtr)
  private val secondEntry = entries(ptrAdd(readPtr, 1.U(ptrWidth.W)))
  private val headLive    = !empty && headEntry.epoch === io.currentEpoch
  private val secondLive  = headLive && count >= deqWidth.U && secondEntry.epoch === io.currentEpoch

  io.out.valid               := !io.flush && !io.pruneFrom.valid && headLive
  io.out.bits                := 0.U.asTypeOf(new FetchPacket(cfg.payload))
  io.out.bits.insts(0).valid := !io.flush && headLive
  io.out.bits.insts(0).bits  := headEntry.inst
  io.out.bits.insts(1).valid := !io.flush && secondLive
  io.out.bits.insts(1).bits  := secondEntry.inst

  private val dequeueCount = Wire(UInt(countWidth.W))
  dequeueCount := Mux(
    io.out.fire,
    Mux(secondLive, deqWidth.U(countWidth.W), 1.U(countWidth.W)),
    0.U(countWidth.W)
  )

  private val enqueueCount = Wire(UInt(enqCountWidth.W))
  enqueueCount := Mux(io.enq.valid, PopCount(io.enq.bits.insts.map(_.valid)), 0.U)

  private val enqueueCountWide = Wire(UInt(countWidth.W))
  enqueueCountWide := enqueueCount
  private val freeAfterDequeue = depth.U(countWidth.W) - count + dequeueCount

  io.enq.ready := !io.flush && !io.pruneFrom.valid && freeAfterDequeue >= enqueueCountWide

  private val enqueueFire          = io.enq.fire
  private val dequeueFire          = io.out.fire
  private val acceptedEnqueueCount = Wire(UInt(enqCountWidth.W))
  acceptedEnqueueCount := Mux(enqueueFire, enqueueCount, 0.U(enqCountWidth.W))
  private val acceptedEnqueueCountWide = Wire(UInt(countWidth.W))
  acceptedEnqueueCountWide := acceptedEnqueueCount

  io.count        := count
  io.freeCount    := depth.U(countWidth.W) - count
  io.empty        := empty
  io.full         := full
  io.enqueueWidth := Mux(enqueueFire, enqueueCount, 0.U)
  io.dequeueWidth := dequeueCount

  val tailEntry   = entries(ptrAdd(readPtr, count - 1.U))
  val keepOnPrune = VecInit((0 until depth).map { offset =>
    val slot = entries(ptrAdd(readPtr, offset.U(ptrWidth.W)))
    offset.U(countWidth.W) < count && !sequenceAfter(slot.sequence, io.pruneFrom.bits) &&
    slot.sequence =/= io.pruneFrom.bits
  })
  val keepCount   = PopCount(keepOnPrune)

  when(io.preserveBefore.valid) {
    assert(empty || entryBefore(tailEntry, io.preserveBefore.bits))
  }

  when(enqueueFire) {
    assert(enqueueCount =/= 0.U)
    for (lane <- 0 until enqWidth) {
      when(io.enq.bits.insts(lane).valid) {
        assert(io.enq.bits.insts(lane).bits.epoch === io.currentEpoch)
      }
      if (lane > 0) {
        when(io.enq.bits.insts(lane).valid) {
          assert(io.enq.bits.insts(lane - 1).valid)
          assert(entryAfter(io.enq.bits.insts(lane).bits, io.enq.bits.insts(lane - 1).bits))
        }
      }
    }
    when(!empty) {
      assert(entryAfter(io.enq.bits.insts(0).bits, tailEntry))
    }
  }

  for (offset <- 0 until depth) {
    val slot = entries(ptrAdd(readPtr, offset.U(ptrWidth.W)))
    when(!io.flush && offset.U(countWidth.W) < count) {
      assert(slot.epoch === io.currentEpoch)
      if (offset > 0) {
        val previous = entries(ptrAdd(readPtr, (offset - 1).U(ptrWidth.W)))
        assert(entryAfter(slot, previous))
      }
    }
  }

  when(io.flush) {
    readPtr  := 0.U
    writePtr := 0.U
    count    := 0.U
  }.elsewhen(io.pruneFrom.valid) {
    writePtr := ptrAdd(readPtr, keepCount)
    count    := keepCount
  }.otherwise {
    when(enqueueFire) {
      for (lane <- 0 until enqWidth) {
        when(io.enq.bits.insts(lane).valid) {
          entries(ptrAdd(writePtr, lane.U(ptrWidth.W))) := io.enq.bits.insts(lane).bits
        }
      }
      writePtr := ptrAdd(writePtr, enqueueCount)
    }

    when(dequeueFire) {
      readPtr := ptrAdd(readPtr, dequeueCount)
    }

    count := count + acceptedEnqueueCountWide - dequeueCount
  }

  assert(count <= depth.U)
  assert(dequeueCount <= deqWidth.U)
  when(io.pruneFrom.valid) {
    assert(!io.out.fire)
    assert(!io.enq.fire)
  }
  when(enqueueFire) {
    assert(enqueueCountWide <= freeAfterDequeue)
  }
}
