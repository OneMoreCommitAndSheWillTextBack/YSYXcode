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
  wire pc_valid, infetch_ready;
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    
    .valid_to(pc_valid),
    .ready_from(infetch_ready)
  );
  
  infetch infetch0(
    .clk(clk),
    .pc(pc),
    .inst(instbridge),
    
    .valid_from(pc_valid),
    .valid_to(valid),
    .ready_from(ready),
    .ready_to(infetch_ready)
  );

  assign pc = pcbridge;
  assign inst = instbridge;

endmodule
