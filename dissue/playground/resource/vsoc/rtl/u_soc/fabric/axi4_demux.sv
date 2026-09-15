// axi4_demux -- one upstream AXI4 master port to N downstream slave ports.
//
// This is the whole "topology + address decode + response routing" of the SoC.
// Rules it must never break (doc/timing.md):
//   * every address is routed, unclaimed ones go to the default slave;
//   * a *valid is never gated by a *ready (only the other way round);
//   * the W channel is routed by the recorded AW winner, never broadcast;
//   * rready/bready are sent to exactly one downstream port.
module axi4_demux #(
    parameter int unsigned NUM_SLAVES = vsoc_pkg::NUM_SLAVES
) (
    input logic clk,
    input logic rst,
    vsoc_axi_if.slave  s_axi,
    vsoc_axi_if.master m_axi [NUM_SLAVES]
);
  import vsoc_pkg::*;

  localparam int unsigned PORT_SEL_W = (NUM_SLAVES > 1) ? $clog2(NUM_SLAVES) : 1;

  logic [NUM_SLAVES-1:0][ID_W-1:0]   rid_v;
  logic [NUM_SLAVES-1:0][ID_W-1:0]   bid_v;
  logic [NUM_SLAVES-1:0]             arready_v;
  logic [NUM_SLAVES-1:0]             awready_v;
  logic [NUM_SLAVES-1:0]             wready_v;
  logic [NUM_SLAVES-1:0]             rvalid_v;
  logic [NUM_SLAVES-1:0]             rlast_v;
  logic [NUM_SLAVES-1:0]             bvalid_v;
  logic [NUM_SLAVES-1:0][1:0]        rresp_v;
  logic [NUM_SLAVES-1:0][1:0]        bresp_v;
  logic [NUM_SLAVES-1:0][DATA_W-1:0] rdata_v;

  // Route tags. The core keeps one read and one write in flight, so one
  // register per direction is enough; the ID upgrade path is in doc/roadmap.md.
  logic              ar_valid_q;
  logic              aw_valid_q;
  logic [PORT_SEL_W-1:0] ar_sel_q;
  logic [PORT_SEL_W-1:0] aw_sel_q;

  wire [PORT_SEL_W-1:0] ar_sel = PORT_SEL_W'(vsoc_decode(s_axi.araddr));
  wire [PORT_SEL_W-1:0] aw_sel = PORT_SEL_W'(vsoc_decode(s_axi.awaddr));

  wire ar_fire = s_axi.arvalid && s_axi.arready;
  wire aw_fire = s_axi.awvalid && s_axi.awready;

  // W carries no address: it follows the AW route. A route becomes valid in the
  // same cycle AW is accepted, so the common AW+W case does not cost a cycle.
  wire                 w_route_valid = aw_valid_q || aw_fire;
  wire [PORT_SEL_W-1:0] w_sel        = aw_valid_q ? aw_sel_q : aw_sel;

  genvar i;
  generate
    for (i = 0; i < NUM_SLAVES; i++) begin : g_port
      assign m_axi[i].arvalid = s_axi.arvalid && (ar_sel == PORT_SEL_W'(i));
      assign m_axi[i].araddr  = s_axi.araddr;
      assign m_axi[i].arid    = s_axi.arid;
      assign m_axi[i].arlen   = s_axi.arlen;
      assign m_axi[i].arsize  = s_axi.arsize;
      assign m_axi[i].arburst = s_axi.arburst;

      assign m_axi[i].awvalid = s_axi.awvalid && (aw_sel == PORT_SEL_W'(i));
      assign m_axi[i].awaddr  = s_axi.awaddr;
      assign m_axi[i].awid    = s_axi.awid;
      assign m_axi[i].awlen   = s_axi.awlen;
      assign m_axi[i].awsize  = s_axi.awsize;
      assign m_axi[i].awburst = s_axi.awburst;

      assign m_axi[i].wvalid  = s_axi.wvalid && w_route_valid && (w_sel == PORT_SEL_W'(i));
      assign m_axi[i].wdata   = s_axi.wdata;
      assign m_axi[i].wstrb   = s_axi.wstrb;
      assign m_axi[i].wlast   = s_axi.wlast;

      assign m_axi[i].rready  = s_axi.rready && ar_valid_q && (ar_sel_q == PORT_SEL_W'(i));
      assign m_axi[i].bready  = s_axi.bready && aw_valid_q && (aw_sel_q == PORT_SEL_W'(i));

      assign arready_v[i] = m_axi[i].arready;
      assign awready_v[i] = m_axi[i].awready;
      assign wready_v[i]  = m_axi[i].wready;

      assign rvalid_v[i]  = m_axi[i].rvalid;
      assign rlast_v[i]   = m_axi[i].rlast;
      assign rresp_v[i]   = m_axi[i].rresp;
      assign rdata_v[i]   = m_axi[i].rdata;
      assign rid_v[i]     = m_axi[i].rid;

      assign bvalid_v[i]  = m_axi[i].bvalid;
      assign bresp_v[i]   = m_axi[i].bresp;
      assign bid_v[i]     = m_axi[i].bid;
    end
  endgenerate

  // Address decode: the selected downstream port sees the request, the rest stay
  // idle. Because the decode happens in the same cycle, no request is delayed.
  assign s_axi.arready = arready_v[ar_sel];
  assign s_axi.awready = awready_v[aw_sel];
  assign s_axi.wready  = w_route_valid ? wready_v[w_sel] : 1'b0;

  assign s_axi.rresp   = rresp_v[ar_sel_q];
  assign s_axi.rdata   = rdata_v[ar_sel_q];
  assign s_axi.rlast   = rlast_v[ar_sel_q];
  assign s_axi.rid     = rid_v[ar_sel_q];
  assign s_axi.rvalid  = ar_valid_q && rvalid_v[ar_sel_q];

  assign s_axi.bresp   = bresp_v[aw_sel_q];
  assign s_axi.bid     = bid_v[aw_sel_q];
  assign s_axi.bvalid  = aw_valid_q && bvalid_v[aw_sel_q];

  always_ff @(posedge clk) begin
    if (rst) begin
      ar_valid_q <= 1'b0;
      aw_valid_q <= 1'b0;
      ar_sel_q   <= '0;
      aw_sel_q   <= '0;
    end else begin
      if (ar_fire) begin
        ar_valid_q <= 1'b1;
        ar_sel_q   <= ar_sel;
      end else if (s_axi.rvalid && s_axi.rready && s_axi.rlast) begin
        ar_valid_q <= 1'b0;
      end

      if (aw_fire) begin
        aw_valid_q <= 1'b1;
        aw_sel_q   <= aw_sel;
      end else if (s_axi.bvalid && s_axi.bready) begin
        aw_valid_q <= 1'b0;
      end
    end
  end

  assert property (@(posedge clk) disable iff (rst) !(ar_fire && ar_valid_q));
  assert property (@(posedge clk) disable iff (rst) !(aw_fire && aw_valid_q));
endmodule
