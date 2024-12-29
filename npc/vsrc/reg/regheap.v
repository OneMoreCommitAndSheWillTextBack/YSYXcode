module regheap(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [4:0] src1,
  input [4:0] src2,
  input [11:0] csr,
  input [31:0] data,
  input csrrw,
  input csrrs,
  input ecallsig,
  output [31:0] regout1,
  output [31:0] regout2,
  output [31:0] mepc,
  output [31:0] mtvec
);

  wire [31:0] rf [31:0];
  wire [31:0] rf_csr [3:0];
  wire [1:0] csr_choose;
  wire [31:0] reg_write_data;

  assign reg_write_data = (csrrw | csrrs) ? rf[src1] : 
                                            data;

  MuxKey#(4, 12, 2) muxcsr(csr_choose, csr, {
    12'h300, 2'b00, // mstatus
    12'h305, 2'b01, // mtvec
    12'h341, 2'b10, // mepc
    12'h342, 2'b11  // mcause
});

  registers registers0(
    .clk(clk),
    .rst(rst),
    .ew(ew),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .ecall(ecallsig),
    .addr(addr),
    .csr_choose(csr_choose),
    .data(reg_write_data),
    .gr(rf),
    .csr(rf_csr)
  );

  assign regout1 = rf[src1];
  assign regout2 = rf[src2];

  assign mepc = rf_csr[2];
  assign mtvec = rf_csr[1];

endmodule

