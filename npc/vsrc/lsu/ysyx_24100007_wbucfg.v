/**
 * WBU AXI 配置模块
 * 将 load/store 请求转换为 AXI 通道参数
 * - 单 beat 传输
 * - arsize/awsize 由 mem_mask 决定
 * - awburst 由地址范围决定（UART 用 FIXED，其它用 INCR）
 * - 复用 memwritelen 逻辑处理 wstrb、awsize、wdata 对齐
 */
module ysyx_24100007_wbucfg (
    input        mem_we,
    input [31:0] mem_addr,
    input [31:0] mem_wdata,
    input [2:0]  mem_mask,
    input is_unalign,

    output [31:0] araddr,
    output [31:0] awaddr,
    output [2:0]  arsize,
    output [2:0]  awsize,
    output [7:0]  arlen,
    output [7:0]  awlen,
    output [1:0]  arburst,
    output [1:0]  awburst,
    output [31:0] wdata,
    output [3:0]  wstrb
);

  // 地址范围（与 axi_mem_controller 一致）
  wire in_sram  = (mem_addr >= 32'h0f000000) && (mem_addr <= 32'h0fffffff);
  wire in_psram = (mem_addr >= 32'h80000000) && (mem_addr <= 32'h9fffffff);
  wire in_sdram = (mem_addr >= 32'ha0000000) && (mem_addr <= 32'hbfffffff);

  // 读地址：SRAM/PSRAM/SDRAM 需 4B 对齐
  assign araddr = (is_unalign) ? {mem_addr[31:2], 2'b00} : mem_addr;

  // 写地址
  assign awaddr = mem_addr;

  // 读通道：单 beat
  assign arlen   = 8'd0;
  assign arburst = 2'b01;  // INCR
  assign arsize  = (mem_mask == 3'b001) ? 3'b000 :
                   (mem_mask == 3'b010) ? 3'b001 :
                   3'b010;

  // 写通道：单 beat
  assign awlen   = 8'd0;

  wire [1:0] wdata_offset;

  ysyx_24100007_memwritelen strbcontrol (
      .awaddr (mem_addr),
      .wirtelen(mem_mask),
      .wstrb  (wstrb),
      .awsize (awsize),
      .wdata_offset(wdata_offset),
      .awburst(awburst)
  );

  assign wdata = mem_wdata << ({3'b0, wdata_offset} << 3);

endmodule
