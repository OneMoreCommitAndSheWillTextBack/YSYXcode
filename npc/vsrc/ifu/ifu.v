module ifu(
  input clk,
  input rst,
  input [31:0] npc,

  output [31:0] pc,
  output [31:0] inst,

);
  wire [31:0] pcbridge;
  wire [31:0] instbridge;
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge)
  );
  
  infetch infetch0(
    .pc(pcbridge),
    .inst(instbridge)
  );

  assign pc = pcbridge;
  assign inst = instbridge;

endmodule
