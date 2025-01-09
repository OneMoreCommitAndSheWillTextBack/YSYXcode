module memreadlen(
  input [31:0] data,
  input [2:0] memmask,
  input memsextsig,
  output [31:0] read
);

  wire [31:0] read_u, read_s;
  wire [31:0] read_sb, read_sh;
  sext#(8, 32) sext0(data[7:0], read_sb);
  sext#(16, 32) sext1(data[15:0], read_sh);

  assign read_s = (memmask == 3'b001) ? read_sb :
                  (memmask == 3'b010) ? read_sh :
                  data;
  assign read_u = data;
  assign read = (memsextsig == 1) ? read_s : read_u;

endmodule
