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
  awvalid_from_arbiter, wvalid_from_arbiter, arvalid_from_arbiter, rready_from_arbiter, 
  bready_from_arbiter,
  rvalid_from_arbiter, awready_from_arbiter, wready_from_arbiter, arready_from_arbiter,
  bvalid_from_arbiter;

wire [31:0] 
  awaddr_from_arbiter, araddr_from_arbiter, wdata_from_arbiter, rdata_from_arbiter;
wire [3:0]
  wstrb_from_arbiter;
wire 
  bresp_from_arbiter;

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
  .awvalid_out(awvalid_from_arbiter), 
  .wvalid_out(wvalid_from_arbiter),  
  .arvalid_out(arvalid_from_arbiter), 
  .rready_out(rready_from_arbiter),
  .bready_out(bready_from_arbiter),
  .bvalid_in(bvalid_from_arbiter),
  .rvalid_in(rvalid_from_arbiter),
  .awready_in(awready_from_arbiter),  
  .wready_in(wready_from_arbiter),   
  .arready_in(arready_from_arbiter),

  .araddr_out(araddr_from_arbiter),
  .awaddr_out(awaddr_from_arbiter),
  .wdata_out(wdata_from_arbiter),
  .wstrb_out(wstrb_from_arbiter),
  .rdata_in(rdata_from_arbiter),
  .bresp_in(bresp_from_arbiter)
);

`define needxbar
`ifndef needxbar
sram mem0(
  .clk(clk),
  
  .awvalid(awvalid_from_arbiter),
  .awready(awready_from_arbiter),
  .awaddr(awaddr_from_arbiter),
  
  .wvalid(wvalid_from_arbiter),
  .wready(wready_from_arbiter),
  .wdata(wdata_from_arbiter),
  .wstrb(wstrb_from_arbiter),

  .bvalid(bvalid_from_arbiter),
  .bready(bready_from_arbiter),
  .bresp(bresp_from_arbiter),

  .arvalid(arvalid_from_arbiter),
  .arready(arready_from_arbiter),
  .araddr(araddr_from_arbiter),

  .rready(rready_from_arbiter),
  .rvalid(rvalid_from_arbiter),
  .rdata(rdata_from_arbiter)
);

`else
wire  
  awvalid_from_xbar [1:0], wvalid_from_xbar [1:0], arvalid_from_xbar [1:0], rready_from_xbar [1:0], 
  bready_from_xbar [1:0],
  rvalid_from_xbar [1:0], awready_from_xbar [1:0], wready_from_xbar [1:0], arready_from_xbar [1:0],
  bvalid_from_xbar [1:0];

wire [31:0] 
  awaddr_from_xbar [1:0], araddr_from_xbar [1:0], wdata_from_xbar [1:0], rdata_from_xbar [1:0];
wire [3:0]
  wstrb_from_xbar [1:0];
wire
  bresp_from_xbar [1:0];

xbar xbar(
  .m_awvalid(awvalid_from_arbiter),
  .m_awready(awready_from_arbiter),
  .m_awaddr(awaddr_from_arbiter),
  
  .m_wvalid(wvalid_from_arbiter),
  .m_wready(wready_from_arbiter),
  .m_wdata(wdata_from_arbiter),
  .m_wstrb(wstrb_from_arbiter),

  .m_bvalid(bvalid_from_arbiter),
  .m_bready(bready_from_arbiter),
  .m_bresp(bresp_from_arbiter),

  .m_arvalid(arvalid_from_arbiter),
  .m_arready(arready_from_arbiter),
  .m_araddr(araddr_from_arbiter),

  .m_rready(rready_from_arbiter),
  .m_rvalid(rvalid_from_arbiter),
  .m_rdata(rdata_from_arbiter),

  .s_awvalid(awvalid_from_xbar),
  .s_awready(awready_from_xbar),
  .s_awaddr(awaddr_from_xbar),
  
  .s_wvalid(wvalid_from_xbar),
  .s_wready(wready_from_xbar),
  .s_wdata(wdata_from_xbar),
  .s_wstrb(wstrb_from_xbar),

  .s_bvalid(bvalid_from_xbar),
  .s_bready(bready_from_xbar),
  .s_bresp(bresp_from_xbar),

  .s_arvalid(arvalid_from_xbar),
  .s_arready(arready_from_xbar),
  .s_araddr(araddr_from_xbar),

  .s_rready(rready_from_xbar),
  .s_rvalid(rvalid_from_xbar),
  .s_rdata(rdata_from_xbar)
);

sram mem0(
  .clk(clk),
  .awvalid(awvalid_from_xbar[0]),
  .awready(awready_from_xbar[0]),
  .awaddr(awaddr_from_xbar[0]),
  
  .wvalid(wvalid_from_xbar[0]),
  .wready(wready_from_xbar[0]),
  .wdata(wdata_from_xbar[0]),
  .wstrb(wstrb_from_xbar[0]),

  .bvalid(bvalid_from_xbar[0]),
  .bready(bready_from_xbar[0]),
  .bresp(bresp_from_xbar[0]),

  .arvalid(arvalid_from_xbar[0]),
  .arready(arready_from_xbar[0]),
  .araddr(araddr_from_xbar[0]),

  .rready(rready_from_xbar[0]),
  .rvalid(rvalid_from_xbar[0]),
  .rdata(rdata_from_xbar[0])
);

uart uart0(
  .clk(clk),
  .awvalid(awvalid_from_xbar[1]),
  .awready(awready_from_xbar[1]),
  .awaddr(awaddr_from_xbar[1]),
  
  .wvalid(wvalid_from_xbar[1]),
  .wready(wready_from_xbar[1]),
  .wdata(wdata_from_xbar[1]),
  .wstrb(wstrb_from_xbar[1]),

  .bvalid(bvalid_from_xbar[1]),
  .bready(bready_from_xbar[1]),
  .bresp(bresp_from_xbar[1]),

  .arvalid(arvalid_from_xbar[1]),
  .arready(arready_from_xbar[1]),
  .araddr(araddr_from_xbar[1]),

  .rready(rready_from_xbar[1]),
  .rvalid(rvalid_from_xbar[1]),
  .rdata(rdata_from_xbar[1])
);

`endif

endmodule
