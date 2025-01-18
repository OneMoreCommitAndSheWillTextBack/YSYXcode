module wbu(
  input [31:0] res,
  input [31:0] regout2,
  input memew,
  input memer,
  input [31:0] imm,
  input [31:0] pcwritereg,
  input [2:0] muxsig,
  input valid_from,
  input [2:0] memmask,
  input memsextsig,

  output [31:0] regwrite,
  output ready_to,
  output memvalid,

  // axi-lite interface
  output awvalid,
  input awready,
  output [31:0] awaddr,

  output wvalid,
  input wready,
  output [31:0] wdata,
  output [3:0] wstrb,

  input bvalid,
  output bready,
  input bresp,

  output arvalid,
  input arready,
  output [31:0] araddr,

  input rvalid,
  output rready,
  input [31:0] rdata
);

  wire [31:0] memread;
  reg bresp_get;

  assign wstrb = (memmask == 3'b001) ? 4'b0001 :
                 (memmask == 3'b010) ? 4'b0010 :
                 (memmask == 3'b011) ? 4'b0100 :
                 (memmask == 3'b100) ? 4'b1000 :
                 4'b0000;
  

	assign awvalid = memew;
  assign awaddr = res;
  assign wvalid = memew;
  assign wdata = regout2;
  assign bready = memew;
  assign arvalid = memer;
  assign araddr = res;
  assign rready = memer; 

  memreadlen memreadlen0(
    .data(rdata),
    .memsextsig(memsextsig),
    .memmask(memmask),
    .read(memread)
  );

  MuxKeyWithDefault#(4, 3, 32) muxpc(regwrite, muxsig, 0, {
    3'b000, res,
    3'b001, memread,
    3'b010, imm,
    3'b100, pcwritereg
  });
  

  wire ready = arready & wready & awready;

  assign ready_to = ((memer | memew) == 0) ? 1 :
                    ((rvalid & memer) == 1) ? 1 : 
                    ((bresp & memew) == 1) ? 1 : 0;
  assign memvalid = ready_to;

endmodule
