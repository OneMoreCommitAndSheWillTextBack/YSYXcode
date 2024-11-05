import "DPI-C" function void guest_write(int addr, int data);
import "DPI-C" function int guest_read(int addr);

module mem(
  input clk,
  input [31:0] addr,
  input [31:0] write,
  input er,
  input ew,
  output [31:0] read
);
  reg [31:0] readreg;
  always @(*) begin
    // $display("ew: %d, er: %d", ew, er);
    if(ew) begin
      guest_write(addr, write);
    end

    if (er) begin
      readreg = guest_read(addr);
      // $display("read data: 0x%08x", readreg);
    end else 
      readreg = 0;

  end
  assign read = readreg;
endmodule
