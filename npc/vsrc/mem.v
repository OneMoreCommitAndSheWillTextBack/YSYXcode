import "DPI-C" function void guest_write(int addr, int data, int len);
import "DPI-C" function int guest_read(int addr, int len);

module mem(
  input clk,
  input [31:0] addr,
  input [31:0] write,
  input [2:0] func3,
  input er,
  input ew,
  output [31:0] read
);
  reg [31:0] readreg;
  wire [2:0] len;
  wire signalsig; // if is need sext
  wire [31:0] read_u, read_s;

  assign len = (func3 == 3'b000) ? 3'b001 :
               (func3 == 3'b001) ? 3'b010 :
               (func3 == 3'b010) ? 3'b100 :
               (func3 == 3'b100) ? 3'b001 :
               (func3 == 3'b101) ? 3'b010 :
               3'b000;

  assign signalsig = (func3 == 3'b100) ? 1'b0 :
                     (func3 == 3'b101) ? 1'b0 :
                     (func3 == 3'b101) ? 1'b0 :
                     1'b1;
  
  always @(clk) begin
    if(ew && clk == 0) begin
      guest_write(addr, write, {{29{1'b0}},len});
    end

    if (er && clk == 0) begin
      readreg = guest_read(addr, {{29{1'b0}},len});
      // $display("read data: 0x%08x", readreg);
    end else 
      readreg = 0;
  end

  wire [31:0] read_sb, read_sh;
  sext#(8, 32) sext0(readreg[7:0], read_sb);
  sext#(16, 32) sext1(readreg[15:0], read_sh);

  assign read_s = (len == 3'b001) ? read_sb :
                  (len == 3'b010) ? read_sh :
                  readreg;
  assign read_u = readreg;
  assign read = (signalsig == 1) ? read_s : read_u;
endmodule
