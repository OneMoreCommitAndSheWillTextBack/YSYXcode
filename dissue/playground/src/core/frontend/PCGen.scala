package top.core.frontend.pcgen

import chisel3._
import chisel3.util.{log2Ceil, Cat, MuxCase}
import top.core.frontend.bundle.PcRedirect

class PCGen(
  resetVector:       BigInt,
  addrWidth:         Int = 32,
  fetchBytes:        Int = 8,
  maxAdvanceBlocks:  Int = 2)
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

  val blockAddr   = Cat(pcReg(addrWidth - 1, offsetBits), 0.U(offsetBits.W))
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
