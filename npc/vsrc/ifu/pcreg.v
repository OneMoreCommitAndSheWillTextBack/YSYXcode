module pcreg(
  input clk,
  input [31:0] npc,
  input rst,
  input valid_from_wbu,
  output reg [31:0] pcout
);
  localparam init = 32'h80000000;
  initial pcout = init;
  
  always @(posedge clk or posedge rst) begin
    if(rst) begin
      pcout <= init;
    end
    else begin
      if (valid_from_wbu == 1) begin
        pcout <= npc;
      end

    if(npc == pcout)
      ret(npc);
  end
  end

endmodule
