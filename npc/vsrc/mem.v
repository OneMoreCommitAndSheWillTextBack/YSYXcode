import "DPI-C" function void pmem_write(int addr, int data);
import "DPI-C" function int pmem_read(int addr);

module mem(
  input [31:0] addr,
  input [31:0] write,
  input er,
  input ew,
  output [31:0] read
);
  reg [31:0] readreg;
  always @(ew | er) begin
    if(ew)
      pmem_write(addr, write);
    else if (er)
      readreg = pmem_read(addr);
  end
  assign read = readreg;
endmodule
