module axiinputbatchtool(
    input awvalid,
    input [31:0] awaddr,
    input wvalid,
    input [31:0] wdata,
    input [3:0] wstrb,
    input bready,
    input arvalid,
    input [31:0] araddr,
    input rready,
    input sig,
    output awvalid_out,
    output [31:0] awaddr_out,
    output wvalid_out,
    output [31:0] wdata_out,
    output [3:0] wstrb_out,
    output bready_out,
    output arvalid_out,
    output [31:0] araddr_out,
    output rready_out
);

    assign awaddr_out = awaddr & {32{sig}};
    assign wdata_out = wdata & {32{sig}};
    assign wstrb_out = wstrb & {4{sig}};
    assign araddr_out = araddr & {32{sig}};
    assign awvalid_out = awvalid & sig;
    assign wvalid_out = wvalid & sig;
    assign bready_out = bready & sig;
    assign arvalid_out = arvalid & sig;
    assign rready_out = rready & sig;

endmodule
