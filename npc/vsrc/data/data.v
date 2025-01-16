module data #(parameter NUM=2)(
  input wire clk,

  // master interface
  input [NUM-1:0] awvalid, 
  input [NUM-1:0] wvalid,  
  input [NUM-1:0] arvalid, 
  input [NUM-1:0] rready,
  input [NUM-1:0] bready,
  output [NUM-1:0] bvalid,
  output [NUM-1:0] rvalid,
  output [NUM-1:0] awready, 
  output [NUM-1:0] wready,  
  output [NUM-1:0] arready, 

  // master data channel
  input [31:0] araddr [NUM-1:0],
  output [31:0] rdata [NUM-1:0],
  input [31:0] awaddr [NUM-1:0],
  input [31:0] wdata [NUM-1:0],
  input [3:0] wstrb [NUM-1:0],
  output bresp [NUM-1:0]
);

parameter DEVICE = 0;
wire [NUM + DEVICE -1:0] 
  awvalid_in, wvalid_in, arvalid_in, rready_in, 
  bready_in, 
  rvalid_out, awready_out, wready_out, arready_out, 
  bvalid_out;

assign awvalid_in = awvalid;
assign wvalid_in = wvalid;
assign arvalid_in = arvalid;
assign rready_in = rready;
assign bready_in = bready;

assign bvalid = bvalid_out;
assign rvalid = rvalid_out;
assign awready = awready_out;
assign wready = wready_out;
assign arready = arready_out;


// connect the arviter and sram
wire 
  awvalid_sram, wvalid_sram, arvalid_sram, rready_sram, 
  bready_sram,
  rvalid_sram, awready_sram, wready_sram, arready_sram,
  bvalid_sram;

wire [31:0] 
  awaddr_sram, araddr_sram, wdata_sram, rdata_sram;
wire [3:0]
  wstrb_sram;
wire 
  bresp_sram;

arbiter #(NUM + DEVICE) arviter0(
  .clk(clk), //input

  // master interface
  .awvalid(awvalid_in),   //input
  .wvalid(wvalid_in),     //input
  .arvalid(arvalid_in),   //input
  .rready(rready_in),     //input
  .bready(bready_in),     //input
  .bvalid(bvalid_out),     //ouptut
  .rvalid(rvalid_out),    //output
  .awready(awready_out),  //output
  .wready(wready_out),	  //output  
  .arready(arready_out),  //output 

  // master data channel
  .araddr(araddr),
  .awaddr(awaddr),
  .wdata(wdata),
  .rdata(rdata),
  .wstrb(wstrb),
  .bresp(bresp),

  // subordinate interface
  .awvalid_out(awvalid_sram), 
  .wvalid_out(wvalid_sram),  
  .arvalid_out(arvalid_sram), 
  .rready_out(rready_sram),
  .bready_out(bready_sram),
  .bvalid_in(bvalid_sram),
  .rvalid_in(rvalid_sram),
  .awready_in(awready_sram),  
  .wready_in(wready_sram),   
  .arready_in(arready_sram),

  .araddr_out(araddr_sram),
  .awaddr_out(awaddr_sram),
  .wdata_out(wdata_sram),
  .wstrb_out(wstrb_sram),
  .rdata_in(rdata_sram),
  .bresp_in(bresp_sram)
);

sram mem0(
  .clk(clk),
  
  .awvalid(awvalid_sram),
  .awready(awready_sram),
  .awaddr(awaddr_sram),
  
  .wvalid(wvalid_sram),
  .wready(wready_sram),
  .wdata(wdata_sram),
  .wstrb(wstrb_sram),

  .bvalid(bvalid_sram),
  .bready(bready_sram),
  .bresp(bresp_sram),

  .arvalid(arvalid_sram),
  .arready(arready_sram),
  .araddr(araddr_sram),

  .rready(rready_sram),
  .rvalid(rvalid_sram),
  .rdata(rdata_sram)
);

endmodule
