import "DPI-C" function int get_inst(int pc);
import "DPI-C" function void host_get_pc(int pc);
import "DPI-C" function void host_get_inst(int inst);

module infetch(
  input clk,
  input [31:0] pc,
  output reg [31:0] inst,
  
  output valid_to,
  input valid_from,
  output ready_to,
  input ready_from
  
);
  reg [31:0] reg_inst;
  always @(posedge clk) begin
    if(valid_from == 1)
      reg_inst = get_inst(pc);
  end

  assign inst = reg_inst;
  assign valid_to = inst != 0;
  assign ready_to = 1;
endmodule


