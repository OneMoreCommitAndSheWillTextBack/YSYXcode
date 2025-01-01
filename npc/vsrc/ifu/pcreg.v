module pcreg(
  input clk,
  input [31:0] npc,
  input rst,
  input ready_from,
  output reg [31:0] pcout
);
  localparam init = 32'h80000000 - 4;
  initial begin 
    pcout = init;
  end
  
  always @(posedge clk or posedge rst) begin
    if(rst) begin
      pcout <= init;
    end
    else
    if (ready_from == 1) begin
      if (npc == pcout) 
        ret(0);
      pcout <= npc;
    end
  end

endmodule
