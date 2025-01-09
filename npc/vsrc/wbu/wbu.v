import "DPI-C" function void host_get_valid(int valid);
module wbu(
  input clk,
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
  output ready_to
);

  wire [31:0] readdata;
  wire [31:0] memread;
/*
  mem mem0(
    .clk(clk),
    .addr(res),
    .write(regout2),
    .memew(memew),
    .memer(memer),
    .memmask(memmask),
    .read(readdata),
    .ready_to(ready_to),
    .valid_from(valid_from)
  );
  */
  wire [3:0] wstrb = (memmask == 3'b001) ? 4'b0001 :
                     (memmask == 3'b010) ? 4'b0010 :
                     (memmask == 3'b011) ? 4'b0100 :
                     (memmask == 3'b100) ? 4'b1000 :
                     4'b0000;
  
  wire awready, wready, bvalid;
  wire arready, rready, bresp;
  sram mem(
	  .clk(clk),
	  // write address channel
	  .awvalid(memew),
	  .awready(awready),
	  .awaddr(res),
	
	  // write data channel
	  .wvalid(memew),
	  .wready(wready),
	  .wdata(regout2),
	  .wstrb(wstrb),
	  
	  // write response channel
	  .bvalid(bvalid),
	  .bready(memew),
	  .bresp(bresp),
	
	  // read address channel
	  .arvalid(memer),
	  .arready(arready),
	  .araddr(res),
	
	  // read data channel
	  .rvalid(memer),
	  .rready(rready),
	  .rdata(readdata)
  );

  memreadlen memreadlen0(
    .data(readdata),
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
  
  wire ready = rready & arready & wready & awready;
  wire memready = (~(memer | memew)) | ~(ready);
  wire [31:0] valid;

  assign ready_to = memready;
  assign valid = {31'b0,valid_from & memready};

  always @(*) begin
    host_get_valid(valid);
  end

endmodule
