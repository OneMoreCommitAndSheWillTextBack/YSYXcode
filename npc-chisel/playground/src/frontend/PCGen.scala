package top.frontend.pcgen

import chisel3._
import chisel3.util.MuxCase
import top.frontend.bundle.PcRedirect

class PCGen(resetVector: BigInt) extends Module {
  val io = IO(new Bundle {
    val trapRedirect   = Input(new PcRedirect)
    val branchRedirect = Input(new PcRedirect)
    val predRedirect   = Input(new PcRedirect)
    val isRVC          = Input(UInt(2.W))
    val nextPC         = Output(UInt(32.W))
  })

  val pcReg = RegInit(resetVector.U(32.W))

  private def instLen(isRVC: Bool): UInt =
    Mux(isRVC, 2.U(32.W), 4.U(32.W))

  val seqNextPC = pcReg + instLen(io.isRVC(0)) + instLen(io.isRVC(1))

  val selectedNextPC = MuxCase(
    seqNextPC,
    Seq(
      io.trapRedirect.valid   -> io.trapRedirect.value,
      io.branchRedirect.valid -> io.branchRedirect.value,
      io.predRedirect.valid   -> io.predRedirect.value
    )
  )

  pcReg     := selectedNextPC
  io.nextPC := pcReg
}
