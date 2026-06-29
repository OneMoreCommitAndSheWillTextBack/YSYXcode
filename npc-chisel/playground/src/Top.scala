package top

import chisel3._

final class AxiPort extends Bundle {
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr  = Output(UInt(32.W))
  val awid    = Output(UInt(4.W))
  val awlen   = Output(UInt(8.W))
  val awsize  = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))

  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata  = Output(UInt(32.W))
  val wstrb  = Output(UInt(4.W))
  val wlast  = Output(Bool())

  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp  = Input(UInt(2.W))
  val bid    = Input(UInt(4.W))

  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr  = Output(UInt(32.W))
  val arid    = Output(UInt(4.W))
  val arlen   = Output(UInt(8.W))
  val arsize  = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))

  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp  = Input(UInt(2.W))
  val rdata  = Input(UInt(32.W))
  val rlast  = Input(Bool())
  val rid    = Input(UInt(4.W))
}

class Core(resetVector: BigInt) extends Module {}

class Top(target: Target = Target.Npc) extends Module {
  override def desiredName: String = "ysyx_24100007"
  private val resetVector = target.resetVector

  val io = IO(new Bundle {
    val interrupt = Input(Bool())
    val master    = new AxiPort
    val slave     = Flipped(new AxiPort)
  })

  io.master.awvalid := false.B
  io.master.awaddr  := 0.U
  io.master.awid    := 0.U
  io.master.awlen   := 0.U
  io.master.awsize  := 0.U
  io.master.awburst := 0.U

  io.master.wvalid := false.B
  io.master.wdata  := 0.U
  io.master.wstrb  := 0.U
  io.master.wlast  := false.B

  io.master.bready := false.B

  io.master.arvalid := false.B
  io.master.araddr  := 0.U
  io.master.arid    := 0.U
  io.master.arlen   := 0.U
  io.master.arsize  := 0.U
  io.master.arburst := 0.U

  io.master.rready := false.B

  io.slave.awready := false.B
  io.slave.wready  := false.B

  io.slave.bvalid := false.B
  io.slave.bresp  := 0.U
  io.slave.bid    := 0.U

  io.slave.arready := false.B

  io.slave.rvalid := false.B
  io.slave.rresp  := 0.U
  io.slave.rdata  := 0.U
  io.slave.rlast  := false.B
  io.slave.rid    := 0.U
}
