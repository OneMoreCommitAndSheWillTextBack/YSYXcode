package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{Cat, log2Ceil, Valid}
import top.config.ICacheConfig
import top.core.frontend.bundle.{FetchControlMeta, FetchPred, PredictionMeta, PredictorProvider}

class FetchTargetQueue(cacheCfg: ICacheConfig, depth: Int, groupWidth: Int = 2) extends Module {
  require(depth > groupWidth, "FetchTargetQueue must hold one complete fetch group")
  require((depth & (depth - 1)) == 0, "FetchTargetQueue depth must be a power of two")
  require(groupWidth > 0, "FetchTargetQueue group width must be positive")
  require(log2Ceil(depth) == cacheCfg.fetchTargetIndexBits, "FetchTargetQueue index width must match its depth")

  private val ptrWidth        = log2Ceil(depth)
  private val countWidth      = log2Ceil(depth + 1)
  private val groupCountWidth = log2Ceil(groupWidth + 1)

  val io = IO(new Bundle {
    val redirect = Input(Bool())

    val allocate      = Input(Bool())
    val allocateCount = Input(UInt(groupCountWidth.W))
    val allocatePc    = Input(Vec(groupWidth, UInt(cacheCfg.addrWidth.W)))
    val allocatePred  = Input(Vec(groupWidth, new FetchPred(cacheCfg)))
    val allocateReady = Output(Bool())
    val allocateMeta  = Output(Vec(groupWidth, new FetchControlMeta(cacheCfg)))

    val release      = Input(Bool())
    val releaseCount = Input(UInt(groupCountWidth.W))
    val releaseMeta  = Input(Vec(groupWidth, new FetchControlMeta(cacheCfg)))
    val peek         = Output(Vec(groupWidth, Valid(new FetchControlMeta(cacheCfg))))

    val checkpointWrite   = Input(Vec(FetchWidth.frontend, Valid(new PredictionMeta(cacheCfg))))
    val checkpointRead    = Input(new PredictionMeta(cacheCfg))
    val checkpointReadHit = Output(Bool())
    val checkpointReadMeta = Output(new PredictionMeta(cacheCfg))

    val epoch = Output(UInt(cacheCfg.fetchEpochBits.W))
    val count = Output(UInt(countWidth.W))
  })

  private def ptrAdd(ptr: UInt, increment: UInt): UInt =
    (ptr + increment)(ptrWidth - 1, 0)

  private val checkpointsPerEntry = cacheCfg.fetchBytes / 2
  private val checkpointEntries   = depth * checkpointsPerEntry

  private def checkpointIndex(meta: PredictionMeta): UInt = {
    val entryIndex = meta.ftqIndex(ptrWidth - 1, 0)
    if (checkpointsPerEntry == 1) entryIndex
    else Cat(entryIndex, meta.cfiPc(cacheCfg.offsetBits - 1, 1))
  }

  val entries      = Reg(Vec(depth, new FetchControlMeta(cacheCfg)))
  val checkpoints  = Reg(Vec(checkpointEntries, new PredictionMeta(cacheCfg)))
  val checkpointValid = RegInit(VecInit(Seq.fill(checkpointEntries)(false.B)))
  val readPtr      = RegInit(0.U(ptrWidth.W))
  val writePtr     = RegInit(0.U(ptrWidth.W))
  val count        = RegInit(0.U(countWidth.W))
  val nextSequence = RegInit(0.U(cacheCfg.fetchSequenceBits.W))
  val epoch        = RegInit(0.U(cacheCfg.fetchEpochBits.W))

  private val freeCount = depth.U(countWidth.W) - count
  private val releaseCountWide = Wire(UInt(countWidth.W))
  private val allocateCountWide = Wire(UInt(countWidth.W))
  releaseCountWide := io.releaseCount
  allocateCountWide := io.allocateCount
  private val releasedSlots = Mux(io.release, releaseCountWide, 0.U(countWidth.W))

  private val checkpointReadIndex = checkpointIndex(io.checkpointRead)
  private val checkpointReadEntry = checkpoints(checkpointReadIndex)
  io.checkpointReadHit := checkpointValid(checkpointReadIndex) &&
    checkpointReadEntry.sequence === io.checkpointRead.sequence &&
    checkpointReadEntry.epoch === io.checkpointRead.epoch &&
    checkpointReadEntry.ftqIndex === io.checkpointRead.ftqIndex &&
    checkpointReadEntry.cfiPc === io.checkpointRead.cfiPc
  io.checkpointReadMeta := checkpointReadEntry

  io.allocateReady := !io.redirect && freeCount +& releasedSlots >= allocateCountWide
  for (lane <- 0 until groupWidth) {
    io.allocateMeta(lane) := 0.U.asTypeOf(new FetchControlMeta(cacheCfg))
    io.allocateMeta(lane).sequence       := nextSequence + lane.U
    io.allocateMeta(lane).epoch          := epoch
    io.allocateMeta(lane).ftqIndex       := ptrAdd(writePtr, lane.U)
    io.allocateMeta(lane).pc             := io.allocatePc(lane)
    io.allocateMeta(lane).fastPrediction := io.allocatePred(lane)
    io.allocateMeta(lane).prediction.provider := Mux(
      io.allocatePred(lane).valid,
      PredictorProvider.fastBtb,
      PredictorProvider.none
    )
    io.allocateMeta(lane).prediction.confidence := io.allocatePred(lane).valid.asUInt
    io.allocateMeta(lane).prediction.predictedTarget := io.allocatePred(lane).target

    io.peek(lane).valid := count > lane.U
    io.peek(lane).bits  := entries(ptrAdd(readPtr, lane.U))
  }
  io.epoch := epoch
  io.count := count

  private val allocateFire = io.allocate && io.allocateReady
  private val releaseFire  = io.release
  private val allocatedSlots = Mux(allocateFire, allocateCountWide, 0.U(countWidth.W))

  when(io.redirect) {
    readPtr  := 0.U
    writePtr := 0.U
    count    := 0.U
    epoch    := epoch + 1.U
  }.otherwise {
    when(allocateFire) {
      for (lane <- 0 until groupWidth) {
        when(lane.U < io.allocateCount) {
          entries(ptrAdd(writePtr, lane.U)) := io.allocateMeta(lane)
        }
      }
      writePtr     := ptrAdd(writePtr, io.allocateCount)
      nextSequence := nextSequence + io.allocateCount
    }
    when(releaseFire) {
      readPtr := ptrAdd(readPtr, io.releaseCount)
    }
    count := count + allocatedSlots - releasedSlots
  }

  for (lane <- 0 until FetchWidth.frontend) {
    when(io.checkpointWrite(lane).valid) {
      val index = checkpointIndex(io.checkpointWrite(lane).bits)
      checkpoints(index)    := io.checkpointWrite(lane).bits
      checkpointValid(index) := true.B
    }
  }

  assert(count <= depth.U)
  assert(io.allocateCount <= groupWidth.U)
  assert(io.releaseCount <= groupWidth.U)
  when(io.allocate) {
    assert(!io.redirect)
    assert(io.allocateCount =/= 0.U)
  }
  when(io.release) {
    assert(!io.redirect)
    assert(io.releaseCount =/= 0.U)
    assert(releaseCountWide <= count)
    for (lane <- 0 until groupWidth) {
      when(lane.U < io.releaseCount) {
        assert(io.peek(lane).valid)
        assert(io.releaseMeta(lane).sequence === io.peek(lane).bits.sequence)
        assert(io.releaseMeta(lane).epoch === io.peek(lane).bits.epoch)
        assert(io.releaseMeta(lane).ftqIndex === io.peek(lane).bits.ftqIndex)
      }
    }
  }
  for (lane <- 0 until FetchWidth.frontend) {
    when(io.checkpointWrite(lane).valid) {
      assert(io.checkpointWrite(lane).bits.checkpointValid)
    }
  }
}
