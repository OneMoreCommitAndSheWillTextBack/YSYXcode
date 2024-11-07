import "DPI-C" function void host_get_reg(int regval, int regnum);

module registers(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [31:0] data,
  output reg [31:0] out [31:0]
);
  
  integer i;

  // write op
  always @(posedge clk or posedge rst) begin 
    if(rst) begin
      for(i=0;i<32;i=i+1) begin
        out[i] = 0;
      end
    end else if(ew) begin
      out[addr] = data;
      $display("reg[%d] write a 0x%08x", addr, data);
      out[0] <= 0;
    end 
  end

  always @(*) begin
    for(i=0;i<32;i=i+1) begin
      host_get_reg(out[i], i);
    end
  end
  // always @(posedge clk) begin
  //   $display("out[1] is %d | %x", out[1], out[1]);
  //   $display("out[2] is %d | %x", out[2], out[2]);
  // end

endmodule
