// u_core -- thin adapter between the generated core and vsoc_axi_if. No logic:
// wiring, the slave-port tie-off and the interrupt tie-off. See doc/interfaces.md
// section 4.
module u_core (
    input  logic            clock,
    input  logic            reset,
    vsoc_axi_if.master      m_axi
);
  // io.master: flat AXI4 master port of the core
  logic        io_master_awready;
  logic        io_master_awvalid;
  logic [31:0] io_master_awaddr;
  logic [3:0]  io_master_awid;
  logic [7:0]  io_master_awlen;
  logic [2:0]  io_master_awsize;
  logic [1:0]  io_master_awburst;
  logic        io_master_wready;
  logic        io_master_wvalid;
  logic [31:0] io_master_wdata;
  logic [3:0]  io_master_wstrb;
  logic        io_master_wlast;
  logic        io_master_bready;
  logic        io_master_bvalid;
  logic [1:0]  io_master_bresp;
  logic [3:0]  io_master_bid;
  logic        io_master_arready;
  logic        io_master_arvalid;
  logic [31:0] io_master_araddr;
  logic [3:0]  io_master_arid;
  logic [7:0]  io_master_arlen;
  logic [2:0]  io_master_arsize;
  logic [1:0]  io_master_arburst;
  logic        io_master_rready;
  logic        io_master_rvalid;
  logic [1:0]  io_master_rresp;
  logic [31:0] io_master_rdata;
  logic        io_master_rlast;
  logic [3:0]  io_master_rid;

  // io.slave: the core has no externally visible memory, and vsoc has no second
  // master, so this port stays permanently idle. Its outputs are left open.
  logic        io_slave_awvalid;
  logic [31:0] io_slave_awaddr;
  logic [3:0]  io_slave_awid;
  logic [7:0]  io_slave_awlen;
  logic [2:0]  io_slave_awsize;
  logic [1:0]  io_slave_awburst;
  logic        io_slave_wvalid;
  logic [31:0] io_slave_wdata;
  logic [3:0]  io_slave_wstrb;
  logic        io_slave_wlast;
  logic        io_slave_bready;
  logic        io_slave_arvalid;
  logic [31:0] io_slave_araddr;
  logic [3:0]  io_slave_arid;
  logic [7:0]  io_slave_arlen;
  logic [2:0]  io_slave_arsize;
  logic [1:0]  io_slave_arburst;
  logic        io_slave_rready;
  logic        io_slave_awready;
  logic        io_slave_wready;
  logic        io_slave_bvalid;
  logic [1:0]  io_slave_bresp;
  logic [3:0]  io_slave_bid;
  logic        io_slave_arready;
  logic        io_slave_rvalid;
  logic [1:0]  io_slave_rresp;
  logic [31:0] io_slave_rdata;
  logic        io_slave_rlast;
  logic [3:0]  io_slave_rid;

  // The core's slave port is never addressed in this design (see above); the
  // outputs are intentionally left dangling.
  /* verilator lint_off UNUSEDSIGNAL */
  ysyx_24100007 u_cpu (
      .clock (clock),
      .reset (reset),
      .io_interrupt(1'b0),  // PLIC lives inside the core; no external IRQ source yet

      .io_master_awready(io_master_awready),
      .io_master_awvalid(io_master_awvalid),
      .io_master_awaddr (io_master_awaddr),
      .io_master_awid   (io_master_awid),
      .io_master_awlen  (io_master_awlen),
      .io_master_awsize (io_master_awsize),
      .io_master_awburst(io_master_awburst),
      .io_master_wready (io_master_wready),
      .io_master_wvalid (io_master_wvalid),
      .io_master_wdata  (io_master_wdata),
      .io_master_wstrb  (io_master_wstrb),
      .io_master_wlast  (io_master_wlast),
      .io_master_bready (io_master_bready),
      .io_master_bvalid (io_master_bvalid),
      .io_master_bresp  (io_master_bresp),
      .io_master_bid    (io_master_bid),
      .io_master_arready(io_master_arready),
      .io_master_arvalid(io_master_arvalid),
      .io_master_araddr (io_master_araddr),
      .io_master_arid   (io_master_arid),
      .io_master_arlen  (io_master_arlen),
      .io_master_arsize (io_master_arsize),
      .io_master_arburst(io_master_arburst),
      .io_master_rready (io_master_rready),
      .io_master_rvalid (io_master_rvalid),
      .io_master_rresp  (io_master_rresp),
      .io_master_rdata  (io_master_rdata),
      .io_master_rlast  (io_master_rlast),
      .io_master_rid    (io_master_rid),

      .io_slave_awvalid(io_slave_awvalid),
      .io_slave_awaddr (io_slave_awaddr),
      .io_slave_awid   (io_slave_awid),
      .io_slave_awlen  (io_slave_awlen),
      .io_slave_awsize (io_slave_awsize),
      .io_slave_awburst(io_slave_awburst),
      .io_slave_wvalid (io_slave_wvalid),
      .io_slave_wdata  (io_slave_wdata),
      .io_slave_wstrb  (io_slave_wstrb),
      .io_slave_wlast  (io_slave_wlast),
      .io_slave_bready (io_slave_bready),
      .io_slave_arvalid(io_slave_arvalid),
      .io_slave_araddr (io_slave_araddr),
      .io_slave_arid   (io_slave_arid),
      .io_slave_arlen  (io_slave_arlen),
      .io_slave_arsize (io_slave_arsize),
      .io_slave_arburst(io_slave_arburst),
      .io_slave_rready (io_slave_rready),
      .io_slave_awready(io_slave_awready),
      .io_slave_wready (io_slave_wready),
      .io_slave_bvalid (io_slave_bvalid),
      .io_slave_bresp  (io_slave_bresp),
      .io_slave_bid    (io_slave_bid),
      .io_slave_arready(io_slave_arready),
      .io_slave_rvalid (io_slave_rvalid),
      .io_slave_rresp  (io_slave_rresp),
      .io_slave_rdata  (io_slave_rdata),
      .io_slave_rlast  (io_slave_rlast),
      .io_slave_rid    (io_slave_rid)
  );
  /* verilator lint_on UNUSEDSIGNAL */

  assign io_slave_awvalid = 1'b0;
  assign io_slave_awaddr  = '0;
  assign io_slave_awid    = '0;
  assign io_slave_awlen   = '0;
  assign io_slave_awsize  = '0;
  assign io_slave_awburst = '0;
  assign io_slave_wvalid  = 1'b0;
  assign io_slave_wdata   = '0;
  assign io_slave_wstrb   = '0;
  assign io_slave_wlast   = 1'b0;
  assign io_slave_bready  = 1'b0;
  assign io_slave_arvalid = 1'b0;
  assign io_slave_araddr  = '0;
  assign io_slave_arid    = '0;
  assign io_slave_arlen   = '0;
  assign io_slave_arsize  = '0;
  assign io_slave_arburst = '0;
  assign io_slave_rready  = 1'b0;

  assign m_axi.awvalid = io_master_awvalid;
  assign m_axi.awaddr  = io_master_awaddr;
  assign m_axi.awid    = io_master_awid;
  assign m_axi.awlen   = io_master_awlen;
  assign m_axi.awsize  = io_master_awsize;
  assign m_axi.awburst = io_master_awburst;
  assign io_master_awready = m_axi.awready;

  assign m_axi.wvalid = io_master_wvalid;
  assign m_axi.wdata  = io_master_wdata;
  assign m_axi.wstrb  = io_master_wstrb;
  assign m_axi.wlast  = io_master_wlast;
  assign io_master_wready = m_axi.wready;

  assign m_axi.bready   = io_master_bready;
  assign io_master_bvalid = m_axi.bvalid;
  assign io_master_bresp  = m_axi.bresp;
  assign io_master_bid    = m_axi.bid;

  assign m_axi.arvalid = io_master_arvalid;
  assign m_axi.araddr  = io_master_araddr;
  assign m_axi.arid    = io_master_arid;
  assign m_axi.arlen   = io_master_arlen;
  assign m_axi.arsize  = io_master_arsize;
  assign m_axi.arburst = io_master_arburst;
  assign io_master_arready = m_axi.arready;

  assign m_axi.rready    = io_master_rready;
  assign io_master_rvalid = m_axi.rvalid;
  assign io_master_rresp  = m_axi.rresp;
  assign io_master_rdata  = m_axi.rdata;
  assign io_master_rlast  = m_axi.rlast;
  assign io_master_rid    = m_axi.rid;
endmodule
