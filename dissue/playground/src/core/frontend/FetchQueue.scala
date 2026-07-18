package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{Decoupled, PopCount, Valid, log2Ceil}
import top.config.ICacheConfig
import top.core.frontend.bundle.FetchInst

class FetchQueueEntry(cacheCfg: ICacheConfig) extends Bundle {
  val inst     = new FetchInst
  val sequence = UInt(cacheCfg.fetchSequenceBits.W)
  val epoch    = UInt(cacheCfg.fetchEpochBits.W)
}

class FetchQueueEnqueue(cacheCfg: ICacheConfig, enqWidth: Int = 4) extends Bundle {
  require(enqWidth > 0, "FetchQueue enqueue width must be positive")

  val insts = Vec(enqWidth, Valid(new FetchQueueEntry(cacheCfg)))
}

class FetchQueue(
  cacheCfg: ICacheConfig = ICacheConfig(),
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
    val flush        = Input(Bool())
    val currentEpoch = Input(UInt(cacheCfg.fetchEpochBits.W))
    val enq          = Flipped(Decoupled(new FetchQueueEnqueue(cacheCfg, enqWidth)))
    val out          = Decoupled(new FetchPacket)

    val count     = Output(UInt(countWidth.W))
    val freeCount = Output(UInt(countWidth.W))
    val empty     = Output(Bool())
    val full      = Output(Bool())
    val enqueueWidth = Output(UInt(enqCountWidth.W))
    val dequeueWidth = Output(UInt(countWidth.W))
  })

  private def ptrAdd(ptr: UInt, increment: UInt): UInt =
    (ptr + increment)(ptrWidth - 1, 0)

  private def sequenceAfter(next: UInt, previous: UInt): Bool = {
    val distance = (next - previous)(cacheCfg.fetchSequenceBits - 1, 0)
    next =/= previous && !distance(cacheCfg.fetchSequenceBits - 1)
  }

  private def entryAfter(next: FetchQueueEntry, previous: FetchQueueEntry): Bool =
    sequenceAfter(next.sequence, previous.sequence) ||
      (next.sequence === previous.sequence && next.inst.pc > previous.inst.pc)

  private val entries  = Reg(Vec(depth, new FetchQueueEntry(cacheCfg)))
  private val readPtr  = RegInit(0.U(ptrWidth.W))
  private val writePtr = RegInit(0.U(ptrWidth.W))
  private val count    = RegInit(0.U(countWidth.W))

  private val empty = count === 0.U
  private val full  = count === depth.U

  private val headEntry   = entries(readPtr)
  private val secondEntry = entries(ptrAdd(readPtr, 1.U(ptrWidth.W)))
  private val headLive    = !empty && headEntry.epoch === io.currentEpoch
  private val secondLive  = headLive && count >= deqWidth.U && secondEntry.epoch === io.currentEpoch

  io.out.valid := !io.flush && headLive
  io.out.bits  := 0.U.asTypeOf(new FetchPacket)
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

  io.enq.ready := !io.flush && freeAfterDequeue >= enqueueCountWide

  private val enqueueFire = io.enq.fire
  private val dequeueFire = io.out.fire
  private val acceptedEnqueueCount = Wire(UInt(enqCountWidth.W))
  acceptedEnqueueCount := Mux(enqueueFire, enqueueCount, 0.U(enqCountWidth.W))
  private val acceptedEnqueueCountWide = Wire(UInt(countWidth.W))
  acceptedEnqueueCountWide := acceptedEnqueueCount

  io.count     := count
  io.freeCount := depth.U(countWidth.W) - count
  io.empty     := empty
  io.full      := full
  io.enqueueWidth := Mux(enqueueFire, enqueueCount, 0.U)
  io.dequeueWidth := dequeueCount

  val tailEntry = entries(ptrAdd(readPtr, count - 1.U))

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
  when(enqueueFire) {
    assert(enqueueCountWide <= freeAfterDequeue)
  }
}
