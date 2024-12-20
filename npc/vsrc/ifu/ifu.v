module ifu(
  input clk,
  input rst,
  input [31:0] npc,
  input valid_from_wbu,

  output [31:0] pc,
  output [31:0] inst,
  output valid
);
  wire [31:0] pcbridge;
  wire [31:0] instbridge;
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .valid_from_wbu(valid_from_wbu)
  );
  
  infetch infetch0(
    .clk(clk),
    .pc(pcbridge),
    .valid_from_wbu(valid_from_wbu),
    .inst(instbridge),
    .valid(valid)
  );

  assign pc = pcbridge;
  assign inst = instbridge;

endmodule
