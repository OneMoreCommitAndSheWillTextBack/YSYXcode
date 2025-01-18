module arbiter #(parameter DEVICE_NUM=2) (
  input wire clk,

  // master interface
  input [DEVICE_NUM-1:0] awvalid, 
  input [DEVICE_NUM-1:0] wvalid,  
  input [DEVICE_NUM-1:0] arvalid, 
  input [DEVICE_NUM-1:0] rready,
  input [DEVICE_NUM-1:0] bready,
  output [DEVICE_NUM-1:0] bvalid,
  output [DEVICE_NUM-1:0] rvalid,
  output [DEVICE_NUM-1:0] awready, 
  output [DEVICE_NUM-1:0] wready,  
  output [DEVICE_NUM-1:0] arready, 

  // master data channel
  input [31:0] araddr [DEVICE_NUM-1:0],
  input [31:0] awaddr [DEVICE_NUM-1:0],
  input [31:0] wdata  [DEVICE_NUM-1:0],
  input [3:0] wstrb [DEVICE_NUM-1:0],
  output [31:0] rdata [DEVICE_NUM-1:0],
  output bresp [DEVICE_NUM-1:0],

  // subordinate interface
  output awvalid_out, 
  output wvalid_out,  
  output arvalid_out, 
  output rready_out,
  output bready_out,
  input bvalid_in,
  input rvalid_in,
  input awready_in,  
  input wready_in,   
  input arready_in,

  output [31:0] araddr_out,
  output [31:0] awaddr_out,
  output [31:0] wdata_out,
  output [3:0] wstrb_out,
  input [31:0] rdata_in,
  input bresp_in
);
reg busy;
reg [DEVICE_NUM-1:0] grant;
reg [DEVICE_NUM-1:0] next_grant;

always @(posedge clk) begin
    if (!busy) begin
        grant <= next_grant;
        next_grant <= {next_grant[DEVICE_NUM-2:0], next_grant[DEVICE_NUM-1]};  // Round Robin
    end
end

always @(posedge clk) begin
  if ((awvalid && wvalid) || arvalid) begin
    busy <= 1;
  end else if (bresp_in | rvalid_in) begin
    busy <= 0;
  end
end

assign awvalid_out = |(awvalid & grant);
assign wvalid_out = |(wvalid & grant);
assign arvalid_out = |(arvalid & grant);

assign rready_out = |(rready & grant);
assign bready_out = |(bready & grant);

assign awready = (grant & {DEVICE_NUM{awready_in}});
assign wready = (grant & {DEVICE_NUM{wready_in}});
assign arready = (grant & {DEVICE_NUM{arready_in}});

assign bvalid = (grant & {DEVICE_NUM{bvalid_in}});
assign rvalid = (grant & {DEVICE_NUM{rvalid_in}});

reg [31:0] awaddr_out_reg;
reg [31:0] wdata_out_reg;
reg [31:0] araddr_out_reg;
reg [3:0] wstrb_out_reg;

integer j;
always @(*) begin
    awaddr_out_reg = 32'b0;
    wdata_out_reg = 32'b0;
    araddr_out_reg = 32'b0;
    wstrb_out_reg = 4'b0;
    for (j = 0; j < DEVICE_NUM; j = j + 1) begin
        if (grant[j]) begin
            awaddr_out_reg = awaddr[j];
            wdata_out_reg = wdata[j];
            araddr_out_reg = araddr[j];
            wstrb_out_reg = wstrb[j];
        end
    end
end

assign awaddr_out = awaddr_out_reg;
assign wdata_out = wdata_out_reg;
assign araddr_out = araddr_out_reg;
assign wstrb_out = wstrb_out_reg;

assign rdata[0] = rdata_in;
assign rdata[1] = rdata_in;
assign bresp[0] = bresp_in;
assign bresp[1] = bresp_in;

endmodule
