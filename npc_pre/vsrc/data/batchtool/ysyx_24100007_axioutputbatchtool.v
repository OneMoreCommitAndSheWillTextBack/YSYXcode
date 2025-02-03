module ysyx_24100007_axioutputbatchtool(
    // 写地址通道
    output awready,

    // 写数据通道
    output wready,

    // 写响应通道
    output bvalid,
    output bresp,

    // 读地址通道
    output arready,

    // 读数据通道
    output rvalid,
    output [31:0] rdata,

    // 输入信号
    input sig,

    input awready_in,
    input wready_in,
    input bvalid_in,
    input bresp_in,
    input arready_in,
    input rvalid_in,
    input [31:0] rdata_in
);

    assign awready = awready_in & sig;
    assign wready = wready_in & sig;
    assign bvalid = bvalid_in & sig;
    assign bresp = bresp_in & sig;
    assign arready = arready_in & sig;
    assign rvalid = rvalid_in & sig;
    assign rdata = rdata_in & {32{sig}};

endmodule
