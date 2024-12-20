module ifu(
  input clk,
  input rst,
  input [31:0] npc,
  input ready,

  output [31:0] pc,
  output [31:0] inst,
  output valid
);
  wire [31:0] pcbridge;
  wire [31:0] instbridge;
  wire get_inst;
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .get_inst(get_inst)
  );
  
  infetch infetch0(
    .clk(clk),
    .pc(pcbridge),
    .inst(instbridge),
    .ready(ready), 
    .valid(get_inst)
  );

  assign pc = pcbridge;
  assign inst = instbridge;
  assign valid = get_inst;

endmodule
