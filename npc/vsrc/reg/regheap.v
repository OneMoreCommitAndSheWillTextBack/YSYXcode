module regheap(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [4:0] src1,
  input [4:0] src2,
  input [31:0] data,
  output [31:0] regout1,
  output [31:0] regout2
);

  wire [31:0] rf [31:0];

  registers registers0(
    .clk(clk),
    .rst(rst),
    .ew(ew),
    .addr(addr),
    .data(data),
    .out(rf)
  );

  assign regout1 = rf[src1];
  assign regout2 = rf[src2];

endmodule

