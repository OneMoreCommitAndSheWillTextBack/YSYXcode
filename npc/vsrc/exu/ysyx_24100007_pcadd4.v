module ysyx_24100007_pcadd4(
  input [31:0] pc,
  output [31:0] npc
);
 assign npc = pc + 4;
endmodule
