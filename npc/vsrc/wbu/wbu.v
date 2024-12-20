module wbu(
  input clk,
  input [31:0] res,
  input [31:0] regout2,
  input memew,
  input memer,
  input [2:0] func3,
  input [31:0] imm,
  input [31:0] pcwritereg,
  input [2:0] muxsig,
  input valid_from_exu,

  output [31:0] regwrite,
  output valid
);

  wire [31:0] memread;
  mem mem0(
  .clk(clk),
  .addr(res),
  .write(regout2),
  .ew(memew),
  .er(memer),
  .read(memread),
  .func3(func3)
);

MuxKeyWithDefault#(4, 3, 32) muxpc(regwrite, muxsig, 0, {
    3'b000, res,
    3'b001, memread,
    3'b010, imm,
    3'b100, pcwritereg
});

endmodule
