module data #(parameter NUM=2)(
  input wire clk,
  input wire rst,

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
  input [31:0] araddr,
  output [31:0] rdata,
  input [31:0] awaddr,
  input [31:0] wdata,
  input [3:0] wstrb,
  output bresp
);

parameter DEVICE = 0;
wire [NUM + DEVICE -1:0] 
  awvalid_in, wvalid_in, arvalid_in, rready_in, 
  bready_in, 
  rvalid_out, awready_out, wready_out, arready_out, 
  bvalid_out;

// connect the arviter and sram
wire 
  awvalid_sram, wvalid_sram, arvalid_sram, rready_sram, 
  bready_sram,
  rvalid_sram, awready_sram, wready_sram, arready_sram,
  bvalid_sram;

arbiter #(NUM + DEVICE) arviter0(
  .clk(clk), //input
  .rst(rst), //input

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
  .arready_in(arready_sram)   
);

sram mem0(
  .clk(clk),
  
  .awvalid(awvalid_sram),
  .awready(awready_sram),
  .awaddr(awaddr),
  
  .wvalid(wvalid_sram),
  .wready(wready_sram),
  .wdata(wdata),
  .wstrb(wstrb),

  .bvalid(bvalid_sram),
  .bready(bready_sram),
  .bresp(bresp),

  .arvalid(arvalid_sram),
  .arready(arready_sram),
  .araddr(araddr),

  .rready(rready_sram),
  .rvalid(rvalid_sram),
  .rdata(rdata)
);

endmodule
