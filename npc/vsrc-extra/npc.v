module npc (
  input clock,
  input reset
);

  // 暂时不处理外部中断，拉低
  wire io_interrupt = 1'b0;

  // -----------------------------
  // AXI master 侧信号声明（从 axi_memory 输出）
  // -----------------------------
  wire              io_master_awready;
  wire              io_master_wready;
  wire              io_master_arready;
  wire              io_master_rvalid;
  wire [1:0]        io_master_rresp;
  wire [31:0]       io_master_rdata;
  wire              io_master_rlast;
  wire              io_master_bvalid;
  wire [1:0]        io_master_bresp;
  wire [3:0]        io_master_bid;
  wire [3:0]        io_master_rid;  // 修复：添加rid信号

  // -----------------------------
  // AXI master 侧：来自 core 的输出（wire）
  // -----------------------------
  wire              io_master_awvalid;
  wire [31:0]       io_master_awaddr;
  wire [3:0]        io_master_awid;
  wire [7:0]        io_master_awlen;
  wire [2:0]        io_master_awsize;
  wire [1:0]        io_master_awburst;

  wire              io_master_wvalid;
  wire [31:0]       io_master_wdata;
  wire [3:0]        io_master_wstrb;
  wire              io_master_wlast;

  wire              io_master_bready;

  wire              io_master_arvalid;
  wire [31:0]       io_master_araddr;
  wire [3:0]        io_master_arid;
  wire [7:0]        io_master_arlen;
  wire [2:0]        io_master_arsize;
  wire [1:0]        io_master_arburst;

  wire              io_master_rready;

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
    .io_master_awvalid  (io_master_awvalid),
    .io_master_awaddr   (io_master_awaddr),
    .io_master_awid     (io_master_awid),
    .io_master_awlen    (io_master_awlen),
    .io_master_awsize   (io_master_awsize),
    .io_master_awburst  (io_master_awburst),

    .io_master_wready   (io_master_wready),
    .io_master_wvalid   (io_master_wvalid),
    .io_master_wdata    (io_master_wdata),
    .io_master_wstrb    (io_master_wstrb),
    .io_master_wlast    (io_master_wlast),

    .io_master_bready   (io_master_bready),
    .io_master_bvalid   (io_master_bvalid),
    .io_master_bresp    (io_master_bresp),
    .io_master_bid      (io_master_bid),

    .io_master_arready  (io_master_arready),
    .io_master_arvalid  (io_master_arvalid),
    .io_master_araddr   (io_master_araddr),
    .io_master_arid     (io_master_arid),
    .io_master_arlen    (io_master_arlen),
    .io_master_arsize   (io_master_arsize),
    .io_master_arburst  (io_master_arburst),

    .io_master_rready   (io_master_rready),
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

  // -----------------------------
  // 实例化 axi_memory 模块
  // -----------------------------
  axi_memory u_memory (
    .clk                 (clock),
    .rst                 (reset),

    // Write Address Channel
    .io_awready          (io_master_awready),
    .io_awvalid          (io_master_awvalid),
    .io_awaddr           (io_master_awaddr),
    .io_awid             (io_master_awid),
    .io_awlen            (io_master_awlen),
    .io_awsize           (io_master_awsize),
    .io_awburst          (io_master_awburst),

    // Write Data Channel
    .io_wready           (io_master_wready),
    .io_wvalid           (io_master_wvalid),
    .io_wdata            (io_master_wdata),
    .io_wstrb            (io_master_wstrb),
    .io_wlast            (io_master_wlast),

    // Write Response Channel
    .io_bready           (io_master_bready),
    .io_bvalid           (io_master_bvalid),
    .io_bresp            (io_master_bresp),
    .io_bid              (io_master_bid),

    // Read Address Channel
    .io_arready          (io_master_arready),
    .io_arvalid          (io_master_arvalid),
    .io_araddr           (io_master_araddr),
    .io_arid             (io_master_arid),
    .io_arlen            (io_master_arlen),
    .io_arsize           (io_master_arsize),
    .io_arburst          (io_master_arburst),

    // Read Data Channel
    .io_rready           (io_master_rready),
    .io_rvalid           (io_master_rvalid),
    .io_rresp            (io_master_rresp),
    .io_rdata            (io_master_rdata),
    .io_rlast            (io_master_rlast),
    .io_rid              (io_master_rid)
  );

endmodule

module axi_memory (
    input clk,
    input rst,

    output              io_awready,
    input               io_awvalid,
    input  [31:0]       io_awaddr,
    input  [3:0]        io_awid,
    input  [7:0]        io_awlen,
    input  [2:0]        io_awsize,
    input  [1:0]        io_awburst,

    output              io_wready,
    input               io_wvalid,
    input  [31:0]       io_wdata,
    input  [3:0]        io_wstrb,
    input               io_wlast,

    input               io_bready,
    output              io_bvalid,
    output [1:0]        io_bresp,
    output [3:0]        io_bid,

    output              io_arready,
    input               io_arvalid,
    input  [31:0]       io_araddr,
    input  [3:0]        io_arid,
    input  [7:0]        io_arlen,
    input  [2:0]        io_arsize,
    input  [1:0]        io_arburst,

    input               io_rready,
    output              io_rvalid,
    output [1:0]        io_rresp,
    output [31:0]       io_rdata,
    output              io_rlast,
    output [3:0]        io_rid
);

  typedef enum logic [2:0] {
    IDLE, READ, WRITE, READ_VALID, B_VALID
  } state_t;

  state_t state_current;
  state_t state_next;

  always @(posedge clk) begin
    if(rst) begin
      state_current <= IDLE;
    end else begin
      state_current <= state_next;
    end 
  end

  always @(*) begin
    state_next = IDLE;
    case(state_current) 
      IDLE: begin
        if(io_awvalid && io_wvalid) begin
          state_next = WRITE;
        end else if (io_arvalid) begin
          state_next = READ;
        end
      end

      READ: begin
        state_next = READ;
        if(read_done) begin
          state_next = READ_VALID;
        end
      end

      WRITE: begin
        state_next = WRITE;
        if(write_done) begin
          state_next = B_VALID;
        end
      end

      READ_VALID: begin
        state_next = READ_VALID;
        if(io_rready) begin
          state_next = IDLE;
        end
      end

      B_VALID: begin
        state_next = B_VALID;
        if(io_bready) begin
          state_next = IDLE;
        end
      end

      default: begin
        $error("Invalid state");
      end
    endcase
  end

  wire is_read = (state_current == IDLE) && io_arvalid;
  wire is_write = (state_current == IDLE) && (io_awvalid && io_wvalid);

  assign io_rvalid = (state_current == READ_VALID) ? 1'b1 : 1'b0;
  assign io_bvalid = (state_current == B_VALID) ? 1'b1 : 1'b0;

  // -----------------------------
  // lock the singal
  // -----------------------------
  reg [31:0] addr_i;
  reg [31:0] data_i;
  reg [2:0] arsize_i;
  reg [3:0] wstrb_i;
  always @(posedge clk) begin
    if(is_read) begin
      addr_i <= io_araddr;
      arsize_i <= io_arsize;
    end else if(is_write) begin
      addr_i <= io_awaddr;
      data_i <= io_wdata;
      wstrb_i <= io_wstrb;
    end else begin
      addr_i <= 32'b0;
      data_i <= 32'b0;
      arsize_i <= 3'b0;
      wstrb_i <= 4'b0;
    end
  end

  // -----------------------------
  // hand shake reply
  // -----------------------------
  reg io_arready_o_q, io_awready_o_q, io_wready_o_q;
  always @(posedge clk) begin
    if(is_write) begin
      io_awready_o_q <= 1'b1;
      io_wready_o_q <= 1'b1;
    end else if(is_read) begin
      io_arready_o_q <= 1'b1;
    end else begin
      io_arready_o_q <= 1'b0;
      io_awready_o_q <= 1'b0;
      io_wready_o_q <= 1'b0;
    end
  end

  assign io_arready = io_arready_o_q;
  assign io_awready = io_awready_o_q;
  assign io_wready = io_wready_o_q;

  // --------------------------
  // READ PART
  // --------------------------
  // AXI协议：根据size对齐地址
  // size=0 (1字节): 不需要对齐
  // size=1 (2字节): 地址[0]必须为0
  // size=2 (4字节): 地址[1:0]必须为0
  // wire [31:0] addr_align_mask = (arsize_i == 3'd0) ? 32'hFFFFFFFF :  // 1字节：不掩码
  //                               (arsize_i == 3'd1) ? 32'hFFFFFFFE :  // 2字节：清除bit[0]
  //                               32'hFFFFFFFC;                        // 4字节：清除bit[1:0]
  wire [31:0] addr_align_mask = 32'hFFFFFFFC;
  wire [31:0] addr_aligned = addr_i & addr_align_mask;

  import "DPI-C" function void npc_pmem_read(
    input int addr,
    input int len,
    output int data
  );

  reg read_done;
  reg [31:0] data_output;  // 修复：改为32位
  always @(negedge clk) begin
    if(state_current == READ) begin
      npc_pmem_read(addr_aligned, 32'd4, data_output);
      read_done <= 1'b1;
    end else begin
      read_done <= 1'b0;
    end
  end

  assign io_rdata = (state_current == READ_VALID) ? data_output : 32'b0;
 
  // --------------------------
  // WRITE PART
  // --------------------------
  import "DPI-C" function void npc_pmem_write(
    input int addr,
    input int len,
    input int data
  );
  reg write_done;
  
  always @(negedge clk) begin
    if(state_current == WRITE) begin
      if(wstrb_i[0]) begin
        npc_pmem_write(addr_aligned, 32'd1, {24'b0, data_i[7:0]});  // 修复：扩展到32位
      end
      if(wstrb_i[1]) begin
        npc_pmem_write(addr_aligned + 32'd1, 32'd1, {24'b0, data_i[15:8]});  // 修复
      end
      if(wstrb_i[2]) begin
        npc_pmem_write(addr_aligned + 32'd2, 32'd1, {24'b0, data_i[23:16]});  // 修复
      end
      if(wstrb_i[3]) begin
        npc_pmem_write(addr_aligned + 32'd3, 32'd1, {24'b0, data_i[31:24]});  // 修复
      end
      write_done <= 1'b1;
    end else begin
      write_done <= 1'b0;
    end
  end

  assign io_rresp = 2'b00;  // OKAY响应
  assign io_rid = 4'b0;
  assign io_rlast = 1'b1;  // 单拍传输，rlast总是1
  assign io_bid = 4'b0;
  assign io_bresp = 2'b00;
endmodule