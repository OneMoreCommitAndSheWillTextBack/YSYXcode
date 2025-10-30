import "DPI-C" function void host_get_reg(int regval, int regnum);
import "DPI-C" function void host_get_csr(int csrval, int csrnum);


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
  output reg [31:0] gr [31:0],
  output reg [31:0] csr [5:0]
);
  
  integer i;

  initial begin
    csr[4] = 32'h79737978;
    csr[5] = 32'h016FBCA7;
  end

  // write op
  always @(posedge clk or posedge rst) begin 
    if(rst) begin
      for(i=1;i<32;i=i+1) begin
        gr[i] <= 0;
      end
    end else if(ew) begin
      gr[addr] <= data;
      // $display("reg[%d] write a 0x%08x", addr, data);
    end 

    if(csrrw) begin 
      {gr[addr], csr[csr_choose]} <= {csr[csr_choose], data};
    end
  
    if(csrrs) begin
      {gr[addr], csr[csr_choose]} <= {csr[csr_choose], data|csr[csr_choose]};
    end

    if(ecall) begin
      csr[2] <= data;
      csr[3] <= 1;
    end
  end

  always @(*) begin
    host_get_reg(0, 0);
    for(i=1;i<32;i=i+1) begin
      host_get_reg(gr[i], i);
    end

    for(i=0;i<4;i++) begin
      host_get_csr(csr[i], i);
    end
  end
  // always @(posedge clk) begin
  //   $display("out[1] is %d | %x", out[1], out[1]);
  //   $display("out[2] is %d | %x", out[2], out[2]);
  // end

endmodule
