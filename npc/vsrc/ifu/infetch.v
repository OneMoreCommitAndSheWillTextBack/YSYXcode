import "DPI-C" function int get_inst(int pc);
import "DPI-C" function void host_get_pc(int pc);
import "DPI-C" function void host_get_inst(int inst);

module infetch(
  input clk,
  input [31:0] pc,
  input ready,
  output reg [31:0] inst,
  output valid
);
  reg [31:0] reg_inst;
  always @(pc) begin
      reg_inst = get_inst(pc);
  end

  assign inst = reg_inst;
  assign valid = inst != 0;
endmodule


