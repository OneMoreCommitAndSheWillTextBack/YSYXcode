module ysyx_24100007_pcreg(
  input clk,
  input [31:0] npc,
  input rst,
  input ready_from,
  output reg [31:0] pcout
);

`ifdef __NPC__
  localparam init = 32'h80000000;
`else
  localparam init = 32'h30000000;
`endif

  initial begin 
    pcout = init;
  end
  
  always @(posedge clk) begin
    if(rst) begin
      pcout <= init;
    end else
    if (ready_from == 1) begin
      pcout <= npc;
    end
  end

endmodule
