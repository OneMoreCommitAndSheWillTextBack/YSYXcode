package top.core.frontend.pcgen

import chisel3._
import chisel3.util.{log2Ceil, Cat, Decoupled, MuxCase, Valid}
import top.config.FrontendConfig
import top.core.frontend.bundle.{BpuFastResult, FetchAddressRequest, FrontendRecovery, PcRedirect}

/** Owns only the next BPU request address.
  *
  * A fixed-latency S1 result may be consumed in the same cycle as the next S0 request. If the S0 join stalls, the
  * result is retained in `nextPcReg`, keeping Decoupled bits stable after the one-cycle Valid notification disappears.
  */
class FetchAddressGenerator(resetVector: BigInt, cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val addressReq = Decoupled(new FetchAddressRequest(cfg))
    val fastResult = Flipped(Valid(new BpuFastResult(cfg)))
    val recovery   = Flipped(Valid(new FrontendRecovery(cfg)))
    val currentPc  = Output(UInt(cfg.addrWidth.W))
  })

  val nextPcReg = RegInit(resetVector.U(cfg.addrWidth.W))
  val pcReady   = RegInit(true.B)
  val inFlight  = RegInit(false.B)

  val offeredPc = Mux(io.fastResult.valid, io.fastResult.bits.predictedNextPc, nextPcReg)
  io.addressReq.valid        := !io.recovery.valid && (pcReady || io.fastResult.valid)
  io.addressReq.bits.startPc := offeredPc
  io.currentPc               := offeredPc

  when(io.recovery.valid) {
    nextPcReg := io.recovery.bits.targetPc
    pcReady   := true.B
    inFlight  := false.B
  }.otherwise {
    when(io.fastResult.valid) {
      nextPcReg := io.fastResult.bits.predictedNextPc
    }

    when(io.addressReq.fire) {
      pcReady := false.B
    }.elsewhen(io.fastResult.valid) {
      pcReady := true.B
    }

    inFlight := (inFlight && !io.fastResult.valid) || io.addressReq.fire
  }

  when(io.fastResult.valid && !io.recovery.valid) {
    assert(inFlight)
  }
  assert(!(io.addressReq.fire && io.recovery.valid))
}

class PCGen(
  resetVector:      BigInt,
  addrWidth:        Int = 32,
  fetchBytes:       Int = 8,
  maxAdvanceBlocks: Int = 2)
    extends Module {
  require(fetchBytes > 0 && (fetchBytes & (fetchBytes - 1)) == 0, "fetchBytes must be a power of two")
  require(fetchBytes >= 2, "fetchBytes must contain at least one halfword")
  require(maxAdvanceBlocks > 0, "maxAdvanceBlocks must be positive")

  private val offsetBits = log2Ceil(fetchBytes)
  require(addrWidth > offsetBits, "addrWidth must cover the fetch block offset")

  val io = IO(new Bundle {
    val redirect      = Input(new PcRedirect)
    val advanceBlocks = Input(UInt(log2Ceil(maxAdvanceBlocks + 1).W))
    val pc            = Output(UInt(addrWidth.W))
  })

  val pcReg = RegInit(resetVector.U(addrWidth.W))

  val blockAddr    = Cat(pcReg(addrWidth - 1, offsetBits), 0.U(offsetBits.W))
  val advanceBytes = io.advanceBlocks * fetchBytes.U
  val nextBlockPc  = blockAddr +% advanceBytes
  val seqNextPc    = Mux(io.advanceBlocks.orR, nextBlockPc, pcReg)

  val nextPc = MuxCase(
    seqNextPc,
    Seq(
      io.redirect.valid -> io.redirect.value
    )
  )

  pcReg := nextPc

  io.pc := pcReg
}
