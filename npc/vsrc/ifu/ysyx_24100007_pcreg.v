module ysyx_24100007_pcreg(
  input clk,
  input [31:0] npc,
  input rst,
  input ready_from,
  output reg [31:0] pcout
);

`ifdef __NPC__
  localparam init = 32'h80000000;
`elsif __YSYXSOC__
  localparam init = 32'h30000000;
`else
  localparam init = 32'h80000000;   // 或 0x30000000，依默认需求
`endif

// synopsys translate_off
  initial begin
    pcout = init;
    `ifdef __ICARUS__
      $display("[Init] Start PC: 0x%h", pcout);
    `endif 
  end
// synopsys translate_on
  
  always @(posedge clk) begin
    if(rst) begin
      pcout <= init;
    end else
    if (ready_from == 1) begin
      pcout <= npc;
    end
  end

endmodule
