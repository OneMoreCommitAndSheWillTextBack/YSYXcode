import "DPI-C" function int get_inst(int pc);
import "DPI-C" function void host_get_pc(int pc);
import "DPI-C" function void host_get_inst(int inst);

module infetch(
  input [31:0] pc,
  output [31:0] inst
);
  reg [31:0] reg_inst;
  always @(*) begin
    reg_inst = get_inst(pc);
  end

  assign inst = reg_inst;
endmodule


