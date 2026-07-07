package top.device

import chisel3._
import chisel3.util.HasBlackBoxInline

class DeviceTimeDpi extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val value = Output(UInt(64.W))
  })

  setInline(
    "DeviceTimeDpi.sv",
    """
      |import "DPI-C" function longint unsigned npc_time_read();
      |
      |module DeviceTimeDpi(
      |  input  clock,
      |  output reg [63:0] value
      |);
      |  always @(posedge clock) begin
      |    value <= npc_time_read();
      |  end
      |endmodule
      |""".stripMargin
  )
}
