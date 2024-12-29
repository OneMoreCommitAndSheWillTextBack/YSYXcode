import "DPI-C" function void host_get_valid(int valid);
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
  input [2:0] memmask,
  input memsextsig,

  output [31:0] regwrite,
  output ready_to
);

  wire [31:0] memread;
  mem mem0(
  .clk(clk),
  .addr(res),
  .write(regout2),
  .ew(memew),
  .er(memer),
  .memmask(memmask),
  .memsextsig(memsextsig),
  .read(memread)
);

MuxKeyWithDefault#(4, 3, 32) muxpc(regwrite, muxsig, 0, {
    3'b000, res,
    3'b001, memread,
    3'b010, imm,
    3'b100, pcwritereg
});


  wire [31:0] valid;
  assign valid = {31'b0,valid_from_exu};
  always @(*) begin
    host_get_valid(valid);
  end


endmodule
