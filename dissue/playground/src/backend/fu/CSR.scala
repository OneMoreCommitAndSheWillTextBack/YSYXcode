package top.backend.fu

import chisel3._
import chisel3.util.MuxLookup
import top.backend.csr.CsrOp
import top.config.BackendConfig

class CSR(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val old         = Input(UInt(cfg.dataWidth.W))
    val src         = Input(UInt(cfg.dataWidth.W))
    val op          = Input(UInt(CsrOp.width.W))
    val writeEnable = Input(Bool())

    val result = Output(UInt(cfg.dataWidth.W))
    val wen    = Output(Bool())
    val wdata  = Output(UInt(cfg.dataWidth.W))
  })

  io.result := io.old
  io.wdata  := MuxLookup(io.op, io.old)(
    Seq(
      CsrOp.rw -> io.src,
      CsrOp.rs -> (io.old | io.src),
      CsrOp.rc -> (io.old & ~io.src).asUInt
    )
  )
  io.wen    := io.writeEnable
}
