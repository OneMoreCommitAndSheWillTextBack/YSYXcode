module ysyx_24100007_memreadlen(
  input [31:0] data,      // 从内存中读取的完整32位数据
  input [2:0] memmask,    // 内存掩码，用于确定读取的长度（byte, halfword, word）
  input memsextsig,       // 符号扩展信号，1表示有符号扩展，0表示无符号扩展
  input [1:0] addr_offset, // 地址的最低两位，用于确定偏移量
  output [31:0] read      // 读取并扩展后的数据
);

  wire [31:0] read_u, read_s;
  wire [31:0] read_sb, read_sh;
  wire [7:0]  byte_data;
  wire [15:0] halfword_data;

  // assign byte_data = (addr_offset == 2'b00) ? data[7:0] :
  //                    (addr_offset == 2'b01) ? data[15:8] :
  //                    (addr_offset == 2'b10) ? data[23:16] :
  //                    data[31:24];
  assign byte_data = data[7:0];

  // assign halfword_data = (addr_offset[1] == 1'b0) ? data[15:0] : data[31:16];
  assign halfword_data = data[15:0];

  // 符号扩展
  ysyx_24100007_sext#(8, 32) sext0(byte_data, read_sb);
  ysyx_24100007_sext#(16, 32) sext1(halfword_data, read_sh);

  assign read_s = (memmask == 3'b001) ? read_sb :  // lb
                  (memmask == 3'b010) ? read_sh :  // lh
                  data;                            // lw

  assign read_u = (memmask == 3'b001) ? {{24{1'b0}}, byte_data} :  // lbu
                  (memmask == 3'b010) ? {{16{1'b0}}, halfword_data} :  // lhu
                  data;  // lw

  // 根据符号扩展信号选择最终的输出
  assign read = (memsextsig == 1) ? read_s : read_u;
endmodule