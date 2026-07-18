package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{log2Ceil, Valid}
import top.config.ICacheConfig
import top.core.frontend.bundle.{FetchControlMeta, FetchPred}

class FetchTargetQueue(cacheCfg: ICacheConfig, depth: Int) extends Module {
  require(depth > 1, "FetchTargetQueue requires at least two entries")
  require((depth & (depth - 1)) == 0, "FetchTargetQueue depth must be a power of two")
  require(log2Ceil(depth) == cacheCfg.fetchTargetIndexBits, "FetchTargetQueue index width must match its depth")

  private val ptrWidth   = log2Ceil(depth)
  private val countWidth = log2Ceil(depth + 1)

  val io = IO(new Bundle {
    val redirect = Input(Bool())

    val allocate      = Input(Bool())
    val allocatePc    = Input(UInt(cacheCfg.addrWidth.W))
    val allocatePred  = Input(new FetchPred(cacheCfg))
    val allocateReady = Output(Bool())
    val allocateMeta  = Output(new FetchControlMeta(cacheCfg))

    val release     = Input(Bool())
    val releaseMeta = Input(new FetchControlMeta(cacheCfg))
    val head        = Output(Valid(new FetchControlMeta(cacheCfg)))

    val epoch = Output(UInt(cacheCfg.fetchEpochBits.W))
    val count = Output(UInt(countWidth.W))
  })

  private def ptrNext(ptr: UInt): UInt =
    (ptr + 1.U)(ptrWidth - 1, 0)

  val entries      = Reg(Vec(depth, new FetchControlMeta(cacheCfg)))
  val readPtr      = RegInit(0.U(ptrWidth.W))
  val writePtr     = RegInit(0.U(ptrWidth.W))
  val count        = RegInit(0.U(countWidth.W))
  val nextSequence = RegInit(0.U(cacheCfg.fetchSequenceBits.W))
  val epoch        = RegInit(0.U(cacheCfg.fetchEpochBits.W))

  private val empty = count === 0.U
  private val full  = count === depth.U

  io.allocateReady := !io.redirect && (!full || io.release)
  io.allocateMeta.sequence       := nextSequence
  io.allocateMeta.epoch          := epoch
  io.allocateMeta.ftqIndex       := writePtr
  io.allocateMeta.pc             := io.allocatePc
  io.allocateMeta.fastPrediction := io.allocatePred
  io.head.valid                   := !empty
  io.head.bits                    := entries(readPtr)
  io.epoch                        := epoch
  io.count                        := count

  private val allocateFire = io.allocate && io.allocateReady
  private val releaseFire  = io.release

  when(io.redirect) {
    readPtr  := 0.U
    writePtr := 0.U
    count    := 0.U
    epoch    := epoch + 1.U
  }.otherwise {
    when(allocateFire) {
      entries(writePtr) := io.allocateMeta
      writePtr          := ptrNext(writePtr)
      nextSequence      := nextSequence + 1.U
    }
    when(releaseFire) {
      readPtr := ptrNext(readPtr)
    }
    count := count + allocateFire.asUInt - releaseFire.asUInt
  }

  assert(count <= depth.U)
  when(io.allocate) {
    assert(!io.redirect)
  }
  when(io.release) {
    assert(!io.redirect)
    assert(!empty)
    assert(io.releaseMeta.sequence === entries(readPtr).sequence)
    assert(io.releaseMeta.epoch === entries(readPtr).epoch)
    assert(io.releaseMeta.ftqIndex === entries(readPtr).ftqIndex)
  }
}
