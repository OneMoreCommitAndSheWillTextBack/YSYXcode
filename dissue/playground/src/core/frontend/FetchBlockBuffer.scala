package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{log2Ceil, Decoupled}
import top.config.FrontendConfig
import top.core.frontend.bundle.{FetchBlockGroup, ICacheFetchResp}

/** Ordered token/data buffer between ICache and alignment. Prediction state remains in the FTQ. */
class FetchBlockBuffer(cfg: FrontendConfig, depth: Int) extends Module {
  require(depth > 1, "FetchBlockBuffer must absorb more than one cache response")
  require((depth & (depth - 1)) == 0, "FetchBlockBuffer depth must be a power of two")

  private val ptrWidth   = log2Ceil(depth)
  private val countWidth = log2Ceil(depth + 1)

  val io = IO(new Bundle {
    val flush    = Input(Bool())
    val in       = Flipped(Decoupled(new ICacheFetchResp(cfg)))
    val headLive = Input(Bool())
    val out      = Decoupled(new FetchBlockGroup(cfg))

    val count     = Output(UInt(countWidth.W))
    val empty     = Output(Bool())
    val full      = Output(Bool())
    val staleDrop = Output(Bool())
  })

  private def ptrNext(ptr: UInt): UInt =
    (ptr + 1.U)(ptrWidth - 1, 0)

  val entries  = Reg(Vec(depth, new FetchBlockGroup(cfg)))
  val readPtr  = RegInit(0.U(ptrWidth.W))
  val writePtr = RegInit(0.U(ptrWidth.W))
  val count    = RegInit(0.U(countWidth.W))

  val empty = count === 0.U
  val full  = count === depth.U
  val stale = !io.flush && !empty && !io.headLive

  io.count     := count
  io.empty     := empty
  io.full      := full
  io.staleDrop := stale

  io.out.valid := !io.flush && !empty && io.headLive
  io.out.bits  := entries(readPtr)

  val release = io.out.fire || stale
  io.in.ready := !io.flush && (!full || release)

  when(io.flush) {
    readPtr  := 0.U
    writePtr := 0.U
    count    := 0.U
  }.otherwise {
    when(io.in.fire) {
      entries(writePtr).token  := io.in.bits.token
      entries(writePtr).blocks := io.in.bits.blocks
      writePtr                 := ptrNext(writePtr)
      assert(io.in.bits.blocks(0).valid)
    }
    when(release) {
      readPtr := ptrNext(readPtr)
    }
    count := count + io.in.fire.asUInt - release.asUInt
  }

  assert(count <= depth.U)
  when(io.out.fire) {
    assert(io.headLive)
  }
}
