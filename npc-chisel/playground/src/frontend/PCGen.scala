package top.frontend.pcgen

import chisel3._
import chisel3.util.MuxCase
import top.frontend.bundle.PcRedirect

class PCGen(resetVector: BigInt, addrWidth: Int = 32) extends Module {
  val io = IO(new Bundle {
    val redirect     = Input(new PcRedirect)
    val advance      = Input(Bool())
    val advanceBytes = Input(UInt(addrWidth.W))
    val pc           = Output(UInt(addrWidth.W))
  })

  val pcReg     = RegInit(resetVector.U(addrWidth.W))
  val seqNextPC = Mux(io.advance, pcReg +% io.advanceBytes, pcReg)

  val selectedNextPC = MuxCase(
    seqNextPC,
    Seq(
      io.redirect.valid -> io.redirect.value
    )
  )

  pcReg := selectedNextPC
  io.pc := pcReg
}
