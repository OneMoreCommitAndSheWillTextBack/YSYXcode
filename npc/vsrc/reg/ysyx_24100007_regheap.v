module ysyx_24100007_regheap(
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
  input valid,
  output [31:0] regout1,
  output [31:0] regout2,
  output [31:0] mepc,
  output [31:0] mtvec
);

  wire [31:0] rf [31:0];
  wire [31:0] rf_csr [5:0];
  wire [2:0] csr_choose;
  wire [31:0] reg_write_data;

  // pay attention that the src1 should not be direct use
  assign reg_write_data = (!(csrrw | csrrs)) ? data : 
                          (src1 == 0) ? 0 : rf[src1];

  ysyx_24100007_MuxKey#(6, 12, 3) muxcsr(csr_choose, csr, {
    12'h300, 3'b000, // mstatus
    12'h305, 3'b001, // mtvec
    12'h341, 3'b010, // mepc
    12'h342, 3'b011, // mcause
    12'hf11, 3'b100, // mvendorid
    12'hf12, 3'b101  // marchid
});

  ysyx_24100007_registers registers0(
    .clk(clk),
    .rst(rst),
    .ew(ew & valid),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .ecall(ecallsig),
    .addr(addr),
    .csr_choose(csr_choose),
    .data(reg_write_data),
    .gr(rf),
    .csr(rf_csr)
  );

  assign regout1 = (src1 == 0) ? 0 : rf[src1];
  assign regout2 = (src2 == 0) ? 0 : rf[src2];

  assign mepc = rf_csr[2];
  assign mtvec = rf_csr[1];

endmodule

