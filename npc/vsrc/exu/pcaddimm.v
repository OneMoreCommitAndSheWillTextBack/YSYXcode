module pcaddimm(
  input [31:0] pc,
  input [31:0] imm,
  output [31:0] npc
);
  assign npc = pc + imm;
endmodule
