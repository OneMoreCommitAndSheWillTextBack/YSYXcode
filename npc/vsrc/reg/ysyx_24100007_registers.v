// synopsys translate_off
import "DPI-C" function void host_get_reg(int regval, int regnum);
import "DPI-C" function void host_get_csr(int csrval, int csrnum);
// synopsys translate_on
module ysyx_24100007_registers(
  input clk,
  input rst,
  input ew,
  input csrrw,
  input csrrs,
  input ecall,
  input [2:0]csr_choose,
  input [4:0] addr,
  input [31:0] data,
  output [32*15-1:0] gr_flat,
  output [32*6-1:0] csr_flat
);
  
  reg [31:0] gr [15:1];
  reg [31:0] csr [5:0];

  wire [3:0] reg_addr = addr[3:0];

  // write op
  always @(posedge clk) begin 
    if(rst) begin
      gr[1] <= 0;
      gr[2] <= 0;
      gr[3] <= 0;
      gr[4] <= 0;
      gr[5] <= 0;
      gr[6] <= 0;
      gr[7] <= 0;
      gr[8] <= 0;
      gr[9] <= 0;
      gr[10] <= 0;
      gr[11] <= 0;
      gr[12] <= 0;
      gr[13] <= 0;
      gr[14] <= 0;
      gr[15] <= 0;

      csr[0] <= 0;
      csr[1] <= 0;
      csr[2] <= 0;
      csr[3] <= 0;
      csr[4] <= 32'h79737978;
      csr[5] <= 32'h016FBCA7;
    end else begin

      // 使用互斥的条件，避免多驱动
      if(csrrw) begin
        // $display("csrrw: writing data 0x%08x to csr[%0d], addr=%0d, gr[%0d]", data, csr_choose, addr, addr);
        {gr[reg_addr], csr[csr_choose]} <= {csr[csr_choose], data};
      end else if(csrrs) begin
        {gr[reg_addr], csr[csr_choose]} <= {csr[csr_choose], data|csr[csr_choose]};
      end else if(ew && reg_addr != 4'b0) begin
        gr[reg_addr] <= data;
      end

      if(ecall) begin
        csr[2] <= data;
        csr[3] <= 1;
      end
    end
  end

  // synopsys translate_off
  always @(*) begin
    integer i;
    host_get_reg(0, 0);
    for(i=1;i<16;i=i+1) begin
      host_get_reg(gr[i], i);
    end

    for(i=0;i<4;i++) begin
      host_get_csr(csr[i], i);
    end
  end
  // synopsys translate_on

  genvar gi;
  generate
    for (gi = 1; gi < 16; gi = gi + 1) begin: PACK_GR
      assign gr_flat[(gi-1)*32 +: 32] = gr[gi];
    end
  endgenerate

  genvar ci;
  generate
    for (ci = 0; ci < 6; ci = ci + 1) begin: PACK_CSR
      assign csr_flat[ci*32 +: 32] = csr[ci];
    end
  endgenerate

endmodule
