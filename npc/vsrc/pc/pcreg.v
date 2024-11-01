import "DPI-C" function void host_get_pc(int pc);
module pcreg(
  input clk,
  input [31:0] npc,
  input rst,
  output reg [31:0] pcout
);
  localparam init = 32'h80000000;
  initial pcout = init;
  
  always @(posedge clk or posedge rst) begin
    if(rst) begin
      pcout <= init;
    end
    else 
      pcout <= npc;

    if(npc == pcout)
      ret();
  host_get_pc(pcout);
  end

endmodule
