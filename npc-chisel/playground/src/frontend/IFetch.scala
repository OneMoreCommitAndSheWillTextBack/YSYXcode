package top.frontend.ifetch

import chisel3._
import top.frontend.bundle.FetchInst

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
