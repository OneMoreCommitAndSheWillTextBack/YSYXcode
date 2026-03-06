/**
 * IFU AXI 配置模块
 * 将取指请求转换为 AXI 读通道参数
 * - 4-beat burst (16B cache line)
 * - 32-bit 传输宽度
 * - WRAP 突发类型（cache line 对齐）
 */
module ysyx_24100007_ifucfg (
    input  [31:0] addr,

    output [31:0] araddr,
    output [7:0]  arlen,
    output [2:0]  arsize,
    output [1:0]  arburst
);

  localparam [7:0] ARLEN = 8'd3;   // 4 beats (arlen=3)
  localparam [1:0] WRAP = 2'b10;

  assign araddr  = addr;           // IFU 传入的 PC，对 WRAP 可直接使用
  assign arlen   = ARLEN;          // 4 次传输
  assign arsize  = 3'b010;         // 32-bit
  assign arburst = WRAP;           // WRAP 用于 cache line 取指

endmodule
