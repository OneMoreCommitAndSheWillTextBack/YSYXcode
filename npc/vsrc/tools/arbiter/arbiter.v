module arbiter #(parameter DEVICE_NUM=2) (
  input wire clk,
  input wire rst,

  // master interface
  input [DEVICE_NUM-1:0] awvalid, 
  input [DEVICE_NUM-1:0] wvalid,  
  input [DEVICE_NUM-1:0] arvalid, 
  input [DEVICE_NUM-1:0] rready,
  output [DEVICE_NUM-1:0] rvalid,
  output [DEVICE_NUM-1:0] awready, 
  output [DEVICE_NUM-1:0] wready,  
  output [DEVICE_NUM-1:0] arready, 

  // master data channel
  input [31:0] araddr,
  output [31:0] rdata,
  input [31:0] awaddr,
  input [31:0] wdata,
  
  // subordinate interface
  output awvalid_out, 
  output wvalid_out,  
  output arvalid_out, 
  output rready_out,
  input rvalid_in,
  input awready_in,  
  input wready_in,   
  input arready_in,   

  // subordinate data channel
  output [31:0] araddr_out,
  input [31:0] rdata_in,
  output [31:0] awaddr_out,
  output [31:0] wdata_out
);
reg busy;
reg [DEVICE_NUM-1:0] giant;
integer i;

// still need to change
always @(posedge clk or posedge rst) begin
  if(!busy) begin
    // here will choose the first devide to master
    for(i=0;i<DEVICE_NUM;i=i+1) begin
      if(arvalid[i] || awvalid[i]) begin
        giant = (1 << i);
        busy = 1;
      end
    end
  end else begin
    // here need to check if the sram is done
    if(arready_in & rvalid_in & awready_in & wready_in) begin
      busy = 0;
      giant = {DEVICE_NUM{1'b0}};
    end
  end
end

assign wdata_out = wdata;
assign rdata = rdata_in;
assign araddr_out = araddr;
assign awaddr_out = awaddr;

assign awvalid_out = |(awvalid & giant) != 0;
assign wvalid_out = |(wvalid & giant) != 0;
assign arvalid_out = |(arvalid & giant) != 0;

assign rdata = (rvalid_in) ? rdata_in : 32'b0;

endmodule
