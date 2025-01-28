module xbar #(parameter DEVICE = 3)(
  // 和Master 接口
  // 写地址通道
  input        m_awvalid,
  output       m_awready,
  input  [31:0] m_awaddr,

  // 写数据通道
  input        m_wvalid,
  output       m_wready,
  input  [31:0] m_wdata,
  input  [3:0]  m_wstrb,

  // 写响应通道
  output       m_bvalid,
  input        m_bready,
  output        m_bresp,

  // 读地址通道
  input        m_arvalid,
  output       m_arready,
  input  [31:0] m_araddr,

  // 读数据通道
  output       m_rvalid,
  input        m_rready,
  output [31:0] m_rdata,

  // 和Slave 接口
  // 写地址通道
  output       s_awvalid [DEVICE-1:0],
  input        s_awready [DEVICE-1:0],
  output [31:0] s_awaddr [DEVICE-1:0],

  // 写数据通道
  output       s_wvalid [DEVICE-1:0],
  input        s_wready [DEVICE-1:0],
  output [31:0] s_wdata [DEVICE-1:0],
  output [3:0]  s_wstrb [DEVICE-1:0],

  // 写响应通道
  input        s_bvalid [DEVICE-1:0],
  output       s_bready [DEVICE-1:0],
  input        s_bresp [DEVICE-1:0],
  // 读地址通道
  output       s_arvalid [DEVICE-1:0],
  input        s_arready [DEVICE-1:0],
  output [31:0] s_araddr [DEVICE-1:0],
 
  // 读数据通道
  input        s_rvalid [DEVICE-1:0],
  output       s_rready [DEVICE-1:0],
  input  [31:0] s_rdata [DEVICE-1:0]
);
  
  wire sig_sram;
  wire [DEVICE-2:0] sig_device;
  compare #(DEVICE-1, 32) mux(
    .data(({32{m_arvalid}} & m_araddr) | ({32{m_awvalid}} & m_awaddr)),
    .out(sig_device),
    .tbl({
          32'ha00003f8, 32'ha00003ff,
          32'ha0000048, 32'ha000004f
      })
  );

  assign sig_sram = ~sig_device[0] & ~sig_device[1];
  
  axiinputbatchtool urt_input(
    .awvalid(m_awvalid),         // 连接输入信号 awvalid
    .awaddr(m_awaddr),           // 连接输入信号 awaddr
    .wvalid(m_wvalid),           // 连接输入信号 wvalid
    .wdata(m_wdata),             // 连接输入信号 wdata
    .wstrb(m_wstrb),             // 连接输入信号 wstrb
    .bready(m_bready),           // 连接输入信号 bready
    .arvalid(m_arvalid),         // 连接输入信号 arvalid
    .araddr(m_araddr),           // 连接输入信号 araddr
    .rready(m_rready),           // 连接输入信号 rready
    .sig(sig_device[0]),                 // 连接输入信号 sig
    .awvalid_out(s_awvalid[1]), // 连接输出信号 awvalid_out
    .awaddr_out(s_awaddr[1]),   // 连接输出信号 awaddr_out
    .wvalid_out(s_wvalid[1]),   // 连接输出信号 wvalid_out
    .wdata_out(s_wdata[1]),     // 连接输出信号 wdata_out
    .wstrb_out(s_wstrb[1]),     // 连接输出信号 wstrb_out
    .bready_out(s_bready[1]),   // 连接输出信号 bready_out
    .arvalid_out(s_arvalid[1]), // 连接输出信号 arvalid_out
    .araddr_out(s_araddr[1]),   // 连接输出信号 araddr_out
    .rready_out(s_rready[1])    // 连接输出信号 rready_out
  );

  axiinputbatchtool sram_input(
    .awvalid(m_awvalid),         // 连接输入信号 awvalid
    .awaddr(m_awaddr),           // 连接输入信号 awaddr
    .wvalid(m_wvalid),           // 连接输入信号 wvalid
    .wdata(m_wdata),             // 连接输入信号 wdata
    .wstrb(m_wstrb),             // 连接输入信号 wstrb
    .bready(m_bready),           // 连接输入信号 bready
    .arvalid(m_arvalid),         // 连接输入信号 arvalid
    .araddr(m_araddr),           // 连接输入信号 araddr
    .rready(m_rready),           // 连接输入信号 rready
    .sig(sig_sram),              // 连接输入信号 sig
    .awvalid_out(s_awvalid[0]), // 连接输出信号 awvalid_out
    .awaddr_out(s_awaddr[0]),   // 连接输出信号 awaddr_out
    .wvalid_out(s_wvalid[0]),   // 连接输出信号 wvalid_out
    .wdata_out(s_wdata[0]),     // 连接输出信号 wdata_out
    .wstrb_out(s_wstrb[0]),     // 连接输出信号 wstrb_out
    .bready_out(s_bready[0]),   // 连接输出信号 bready_out
    .arvalid_out(s_arvalid[0]), // 连接输出信号 arvalid_out
    .araddr_out(s_araddr[0]),   // 连接输出信号 araddr_out
    .rready_out(s_rready[0])    // 连接输出信号 rready_out
  );

    axiinputbatchtool client_input(
    .awvalid(m_awvalid),         // 连接输入信号 awvalid
    .awaddr(m_awaddr),           // 连接输入信号 awaddr
    .wvalid(m_wvalid),           // 连接输入信号 wvalid
    .wdata(m_wdata),             // 连接输入信号 wdata
    .wstrb(m_wstrb),             // 连接输入信号 wstrb
    .bready(m_bready),           // 连接输入信号 bready
    .arvalid(m_arvalid),         // 连接输入信号 arvalid
    .araddr(m_araddr),           // 连接输入信号 araddr
    .rready(m_rready),           // 连接输入信号 rready
    .sig(sig_device[1]),         // 连接输入信号 sig
    .awvalid_out(s_awvalid[2]), // 连接输出信号 awvalid_out
    .awaddr_out(s_awaddr[2]),   // 连接输出信号 awaddr_out
    .wvalid_out(s_wvalid[2]),   // 连接输出信号 wvalid_out
    .wdata_out(s_wdata[2]),     // 连接输出信号 wdata_out
    .wstrb_out(s_wstrb[2]),     // 连接输出信号 wstrb_out
    .bready_out(s_bready[2]),   // 连接输出信号 bready_out
    .arvalid_out(s_arvalid[2]), // 连接输出信号 arvalid_out
    .araddr_out(s_araddr[2]),   // 连接输出信号 araddr_out
    .rready_out(s_rready[2])    // 连接输出信号 rready_out
  );
  
  wire m_awready_urt, m_wready_urt, m_bvalid_urt,
    m_bresp_urt, m_arready_urt, m_rvalid_urt;
  wire [31:0] m_rdata_urt;
  
   wire m_awready_sram, m_wready_sram, m_bvalid_sram,
    m_bresp_sram, m_arready_sram, m_rvalid_sram;
  wire [31:0] m_rdata_sram;

  wire m_awready_client, m_wready_client, m_bvalid_client,
    m_bresp_client, m_arready_client, m_rvalid_client;
  wire [31:0] m_rdata_client;
  
  axioutputbatchtool urt_output (
    .awready(m_awready_urt),
    .wready(m_wready_urt),
    .bvalid(m_bvalid_urt),
    .bresp(m_bresp_urt),
    .arready(m_arready_urt),
    .rvalid(m_rvalid_urt),
    .rdata(m_rdata_urt),
    .sig(sig_device[0]),
    .awready_in(s_awready[1]),
    .wready_in(s_wready[1]),
    .bvalid_in(s_bvalid[1]),
    .bresp_in(s_bresp[1]),
    .arready_in(s_arready[1]),
    .rvalid_in(s_rvalid[1]),
    .rdata_in(s_rdata[1])
  );

  axioutputbatchtool sram_output (
    .awready(m_awready_sram),
    .wready(m_wready_sram),
    .bvalid(m_bvalid_sram),
    .bresp(m_bresp_sram),
    .arready(m_arready_sram),
    .rvalid(m_rvalid_sram),
    .rdata(m_rdata_sram),
    .sig(sig_sram),
    .awready_in(s_awready[0]),
    .wready_in(s_wready[0]),
    .bvalid_in(s_bvalid[0]),
    .bresp_in(s_bresp[0]),
    .arready_in(s_arready[0]),
    .rvalid_in(s_rvalid[0]),
    .rdata_in(s_rdata[0])
  );

    axioutputbatchtool client_output (
    .awready(m_awready_client),
    .wready(m_wready_client),
    .bvalid(m_bvalid_client),
    .bresp(m_bresp_client),
    .arready(m_arready_client),
    .rvalid(m_rvalid_client),
    .rdata(m_rdata_client),
    .sig(sig_device[1]),
    .awready_in(s_awready[2]),
    .wready_in(s_wready[2]),
    .bvalid_in(s_bvalid[2]),
    .bresp_in(s_bresp[2]),
    .arready_in(s_arready[2]),
    .rvalid_in(s_rvalid[2]),
    .rdata_in(s_rdata[2])
  );
  
  assign m_awready = m_awready_urt | m_awready_sram | m_awready_client;
  assign m_wready = m_wready_urt | m_wready_sram | m_wready_client;
  assign m_bvalid = m_bvalid_urt | m_bvalid_sram | m_bvalid_client;
  assign m_bresp = m_bresp_urt | m_bresp_sram | m_bresp_client;
  assign m_arready = m_arready_urt | m_arready_sram | m_arready_client;
  assign m_rvalid = m_rvalid_urt | m_rvalid_sram | m_rvalid_client;
  assign m_rdata = m_rdata_urt | m_rdata_sram | m_rdata_client;
endmodule
