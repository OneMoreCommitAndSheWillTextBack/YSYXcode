module synth (
  input clock,
  input reset
);

  // 暂时不处理外部中断，拉低
  wire io_interrupt = 1'b0;

  // -----------------------------
  // AXI master 侧：给 core 的输入（全部赋值为常量）
  // -----------------------------
  wire              io_master_awready = 1'b0;
  wire              io_master_wready  = 1'b0;
  wire              io_master_arready = 1'b0;
  wire              io_master_rvalid  = 1'b0;
  wire [1:0]        io_master_rresp   = 2'b0;
  wire [31:0]       io_master_rdata   = 32'b0;
  wire              io_master_rlast   = 1'b0;
  wire              io_master_bvalid  = 1'b0;
  wire [1:0]        io_master_bresp   = 2'b0;
  wire [3:0]        io_master_bid     = 4'b0;
  wire [3:0]        io_master_rid     = 4'b0;

  // -----------------------------
  // AXI master 侧：来自 core 的输出（中间wire，用于连接到core）
  // -----------------------------
  wire              io_master_awvalid_w;
  wire [31:0]       io_master_awaddr_w;
  wire [3:0]        io_master_awid_w;
  wire [7:0]        io_master_awlen_w;
  wire [2:0]        io_master_awsize_w;
  wire [1:0]        io_master_awburst_w;

  wire              io_master_wvalid_w;
  wire [31:0]       io_master_wdata_w;
  wire [3:0]        io_master_wstrb_w;
  wire              io_master_wlast_w;

  wire              io_master_bready_w;

  wire              io_master_arvalid_w;
  wire [31:0]       io_master_araddr_w;
  wire [3:0]        io_master_arid_w;
  wire [7:0]        io_master_arlen_w;
  wire [2:0]        io_master_arsize_w;
  wire [1:0]        io_master_arburst_w;

  wire              io_master_rready_w;

  // -----------------------------
  // AXI master 侧：来自 core 的输出（寄存器，采样core的输出）
  // -----------------------------
  reg               io_master_awvalid;
  reg  [31:0]       io_master_awaddr;
  reg  [3:0]        io_master_awid;
  reg  [7:0]        io_master_awlen;
  reg  [2:0]        io_master_awsize;
  reg  [1:0]        io_master_awburst;

  reg               io_master_wvalid;
  reg  [31:0]       io_master_wdata;
  reg  [3:0]        io_master_wstrb;
  reg               io_master_wlast;

  reg               io_master_bready;

  reg               io_master_arvalid;
  reg  [31:0]       io_master_araddr;
  reg  [3:0]        io_master_arid;
  reg  [7:0]        io_master_arlen;
  reg  [2:0]        io_master_arsize;
  reg  [1:0]        io_master_arburst;

  reg               io_master_rready;

  // -----------------------------
  // AXI slave 侧：给 ysyx_24100007 的输入，先全部拉 0
  // -----------------------------
  reg               io_slave_awvalid;
  reg  [31:0]       io_slave_awaddr;
  reg  [3:0]        io_slave_awid;
  reg  [7:0]        io_slave_awlen;
  reg  [2:0]        io_slave_awsize;
  reg  [1:0]        io_slave_awburst;

  reg               io_slave_wvalid;
  reg  [31:0]       io_slave_wdata;
  reg  [3:0]        io_slave_wstrb;
  reg               io_slave_wlast;

  reg               io_slave_bready;

  reg               io_slave_arvalid;
  reg  [31:0]       io_slave_araddr;
  reg  [3:0]        io_slave_arid;
  reg  [7:0]        io_slave_arlen;
  reg  [2:0]        io_slave_arsize;
  reg  [1:0]        io_slave_arburst;

  reg               io_slave_rready;

  // -----------------------------
  // 打桩的简单初始化逻辑
  // -----------------------------
  always @(posedge clock or posedge reset) begin
    if (reset) begin
      // slave 侧输入全部清零
      io_slave_awvalid  <= 1'b0;
      io_slave_awaddr   <= 32'b0;
      io_slave_awid     <= 4'b0;
      io_slave_awlen    <= 8'b0;
      io_slave_awsize   <= 3'b0;
      io_slave_awburst  <= 2'b0;

      io_slave_wvalid   <= 1'b0;
      io_slave_wdata    <= 32'b0;
      io_slave_wstrb    <= 4'b0;
      io_slave_wlast    <= 1'b0;

      io_slave_bready   <= 1'b0;

      io_slave_arvalid  <= 1'b0;
      io_slave_araddr   <= 32'b0;
      io_slave_arid     <= 4'b0;
      io_slave_arlen    <= 8'b0;
      io_slave_arsize   <= 3'b0;
      io_slave_arburst  <= 2'b0;

      io_slave_rready   <= 1'b0;

      // master 侧输出（来自core）全部清零
      io_master_awvalid <= 1'b0;
      io_master_awaddr  <= 32'b0;
      io_master_awid    <= 4'b0;
      io_master_awlen   <= 8'b0;
      io_master_awsize  <= 3'b0;
      io_master_awburst <= 2'b0;

      io_master_wvalid  <= 1'b0;
      io_master_wdata   <= 32'b0;
      io_master_wstrb   <= 4'b0;
      io_master_wlast   <= 1'b0;

      io_master_bready  <= 1'b0;

      io_master_arvalid <= 1'b0;
      io_master_araddr  <= 32'b0;
      io_master_arid    <= 4'b0;
      io_master_arlen   <= 8'b0;
      io_master_arsize  <= 3'b0;
      io_master_arburst <= 2'b0;

      io_master_rready  <= 1'b0;
    end
    else begin
      io_slave_awvalid  <= io_slave_awvalid;
      io_slave_awaddr   <= io_slave_awaddr;
      io_slave_awid     <= io_slave_awid;
      io_slave_awlen    <= io_slave_awlen;
      io_slave_awsize   <= io_slave_awsize;
      io_slave_awburst  <= io_slave_awburst;

      io_slave_wvalid   <= io_slave_wvalid;
      io_slave_wdata    <= io_slave_wdata;
      io_slave_wstrb    <= io_slave_wstrb;
      io_slave_wlast    <= io_slave_wlast;

      io_slave_bready   <= io_slave_bready;

      io_slave_arvalid  <= io_slave_arvalid;
      io_slave_araddr   <= io_slave_araddr;
      io_slave_arid     <= io_slave_arid;
      io_slave_arlen    <= io_slave_arlen;
      io_slave_arsize   <= io_slave_arsize;
      io_slave_arburst  <= io_slave_arburst;

      io_slave_rready   <= io_slave_rready;

      // master 侧输出（来自core）采样到寄存器
      io_master_awvalid <= io_master_awvalid_w;
      io_master_awaddr  <= io_master_awaddr_w;
      io_master_awid    <= io_master_awid_w;
      io_master_awlen   <= io_master_awlen_w;
      io_master_awsize  <= io_master_awsize_w;
      io_master_awburst <= io_master_awburst_w;

      io_master_wvalid  <= io_master_wvalid_w;
      io_master_wdata   <= io_master_wdata_w;
      io_master_wstrb   <= io_master_wstrb_w;
      io_master_wlast   <= io_master_wlast_w;

      io_master_bready  <= io_master_bready_w;

      io_master_arvalid <= io_master_arvalid_w;
      io_master_araddr  <= io_master_araddr_w;
      io_master_arid    <= io_master_arid_w;
      io_master_arlen   <= io_master_arlen_w;
      io_master_arsize  <= io_master_arsize_w;
      io_master_arburst <= io_master_arburst_w;

      io_master_rready  <= io_master_rready_w;
    end
  end

  wire              io_slave_awready;
  wire              io_slave_wready;
  wire              io_slave_bvalid;
  wire [1:0]        io_slave_bresp;
  wire [3:0]        io_slave_bid;
  wire              io_slave_arready;
  wire              io_slave_rvalid;
  wire [1:0]        io_slave_rresp;
  wire [31:0]       io_slave_rdata;
  wire              io_slave_rlast;
  wire [3:0]        io_slave_rid;



  ysyx_24100007 u_core (
    .clock              (clock),
    .reset              (reset),
    .io_interrupt       (io_interrupt),

    .io_master_awready  (io_master_awready),
    .io_master_awvalid  (io_master_awvalid_w),
    .io_master_awaddr   (io_master_awaddr_w),
    .io_master_awid     (io_master_awid_w),
    .io_master_awlen    (io_master_awlen_w),
    .io_master_awsize   (io_master_awsize_w),
    .io_master_awburst  (io_master_awburst_w),

    .io_master_wready   (io_master_wready),
    .io_master_wvalid   (io_master_wvalid_w),
    .io_master_wdata    (io_master_wdata_w),
    .io_master_wstrb    (io_master_wstrb_w),
    .io_master_wlast    (io_master_wlast_w),

    .io_master_bready   (io_master_bready_w),
    .io_master_bvalid   (io_master_bvalid),
    .io_master_bresp    (io_master_bresp),
    .io_master_bid      (io_master_bid),

    .io_master_arready  (io_master_arready),
    .io_master_arvalid  (io_master_arvalid_w),
    .io_master_araddr   (io_master_araddr_w),
    .io_master_arid     (io_master_arid_w),
    .io_master_arlen    (io_master_arlen_w),
    .io_master_arsize   (io_master_arsize_w),
    .io_master_arburst  (io_master_arburst_w),

    .io_master_rready   (io_master_rready_w),
    .io_master_rvalid   (io_master_rvalid),
    .io_master_rresp    (io_master_rresp),
    .io_master_rdata    (io_master_rdata),
    .io_master_rlast    (io_master_rlast),
    .io_master_rid      (io_master_rid),  // 修复：使用io_master_rid而不是io_master_bid

    .io_slave_awready   (io_slave_awready),
    .io_slave_awvalid   (io_slave_awvalid),
    .io_slave_awaddr    (io_slave_awaddr),
    .io_slave_awid      (io_slave_awid),
    .io_slave_awlen     (io_slave_awlen),
    .io_slave_awsize    (io_slave_awsize),
    .io_slave_awburst   (io_slave_awburst),

    .io_slave_wready    (io_slave_wready),
    .io_slave_wvalid    (io_slave_wvalid),
    .io_slave_wdata     (io_slave_wdata),
    .io_slave_wstrb     (io_slave_wstrb),
    .io_slave_wlast     (io_slave_wlast),

    .io_slave_bready    (io_slave_bready),
    .io_slave_bvalid    (io_slave_bvalid),
    .io_slave_bresp     (io_slave_bresp),
    .io_slave_bid       (io_slave_bid),

    .io_slave_arready   (io_slave_arready),
    .io_slave_arvalid   (io_slave_arvalid),
    .io_slave_araddr    (io_slave_araddr),
    .io_slave_arid      (io_slave_arid),
    .io_slave_arlen     (io_slave_arlen),
    .io_slave_arsize    (io_slave_arsize),
    .io_slave_arburst   (io_slave_arburst),

    .io_slave_rready    (io_slave_rready),
    .io_slave_rvalid    (io_slave_rvalid),
    .io_slave_rresp     (io_slave_rresp),
    .io_slave_rdata     (io_slave_rdata),
    .io_slave_rlast     (io_slave_rlast),
    .io_slave_rid       (io_slave_rid)
  );
endmodule