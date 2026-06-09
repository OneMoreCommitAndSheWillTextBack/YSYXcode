package top.frontend.ifetch

import chisel3._
import freechips.rocketchip.rocket.ExpandedInstruction
import freechips.rocketchip.rocket.RVCDecoder
import top.frontend.bundle.FetchInst

class RvcExpander(
  xLen:         Int = 32,
  fLen:         Int = 0,
  useAddiForMv: Boolean = false)
    extends Module {
  val io = IO(new Bundle {
    val in  = Input(UInt(32.W))
    val out = Output(new ExpandedInstruction)
    val rvc = Output(Bool())
    val ill = Output(Bool())
  })

  val decoder = new RVCDecoder(io.in, xLen, fLen, useAddiForMv)

  io.rvc := io.in(1, 0) =/= 3.U
  io.out := decoder.decode
  io.ill := decoder.ill
}

class IFetch extends Module {
  val io = IO(new Bundle {
    val pc        = Input(UInt(32.W))
    val instBlock = Input(UInt(64.W))
    val fetchInst = Output(new FetchInst)
  })

  val rvcExpander = Module(new RvcExpander)
  rvcExpander.io.in := io.instBlock(31, 0)

  io.fetchInst.pc         := io.pc
  io.fetchInst.inst       := rvcExpander.io.out.bits
  io.fetchInst.rawInst    := Mux(rvcExpander.io.rvc, io.instBlock(15, 0), io.instBlock(31, 0))
  io.fetchInst.isRVC      := rvcExpander.io.rvc
  io.fetchInst.instLen    := Mux(rvcExpander.io.rvc, 2.U, 4.U)
  io.fetchInst.predTaken  := false.B
  io.fetchInst.predNpc    := 0.U
  io.fetchInst.predTarget := 0.U
}
