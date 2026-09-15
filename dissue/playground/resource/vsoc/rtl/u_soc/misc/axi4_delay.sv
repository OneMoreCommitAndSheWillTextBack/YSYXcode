// axi4_delay -- configurable memory-system latency, for calibration sweeps.
//
// Two independent knobs (doc/timing.md section 7):
//   AR_LATENCY / AW_LATENCY : cycles between accepting a request and issuing it
//                             downstream. The master cannot tell this apart from
//                             a slower memory, which is exactly the point.
//   R_GAP                   : cycles inserted between consecutive read beats,
//                             i.e. a bandwidth throttle.
//
// Every knob defaults to 0 and is then a plain wire (no register, no cost).
// A delayed channel is strictly single-outstanding, which matches the current
// core; revisit together with the ID table upgrade (doc/roadmap.md).
module axi4_delay #(
    parameter int unsigned AR_LATENCY = 0,
    parameter int unsigned AW_LATENCY = 0,
    parameter int unsigned R_GAP      = 0
) (
    input logic clk,
    input logic rst,
    vsoc_axi_if.slave  s_axi,
    vsoc_axi_if.master m_axi
);
  import vsoc_pkg::*;

  localparam int unsigned CNT_W = 16;

  // ============================================================ AR channel
  generate
    if (AR_LATENCY == 0) begin : g_ar_bypass
      assign m_axi.arvalid = s_axi.arvalid;
      assign m_axi.araddr  = s_axi.araddr;
      assign m_axi.arid    = s_axi.arid;
      assign m_axi.arlen   = s_axi.arlen;
      assign m_axi.arsize  = s_axi.arsize;
      assign m_axi.arburst = s_axi.arburst;
      assign s_axi.arready = m_axi.arready;
    end else begin : g_ar_delay
      logic              busy_q;
      logic [CNT_W-1:0]  wait_q;
      logic [ADDR_W-1:0] addr_q;
      logic [ID_W-1:0]   id_q;
      logic [LEN_W-1:0]  len_q;
      logic [SIZE_W-1:0] size_q;
      logic [BURST_W-1:0] burst_q;

      assign s_axi.arready = ~busy_q;
      assign m_axi.arvalid = busy_q && (wait_q == '0);  // never depends on arready
      assign m_axi.araddr  = addr_q;
      assign m_axi.arid    = id_q;
      assign m_axi.arlen   = len_q;
      assign m_axi.arsize  = size_q;
      assign m_axi.arburst = burst_q;

      always_ff @(posedge clk) begin
        if (rst) begin
          busy_q <= 1'b0;
          wait_q <= '0;
        end else if (!busy_q) begin
          if (s_axi.arvalid && s_axi.arready) begin
            busy_q  <= 1'b1;
            wait_q  <= CNT_W'(AR_LATENCY);
            addr_q  <= s_axi.araddr;
            id_q    <= s_axi.arid;
            len_q   <= s_axi.arlen;
            size_q  <= s_axi.arsize;
            burst_q <= s_axi.arburst;
          end
        end else begin
          if (wait_q != '0) begin
            wait_q <= wait_q - 1'b1;
          end
          // Released only when the whole read has been delivered upstream, so
          // no two reads can ever be in flight through this block.
          if (s_axi.rvalid && s_axi.rready && s_axi.rlast) begin
            busy_q <= 1'b0;
          end
        end
      end
    end
  endgenerate

  // ============================================================ AW channel
  generate
    if (AW_LATENCY == 0) begin : g_aw_bypass
      assign m_axi.awvalid = s_axi.awvalid;
      assign m_axi.awaddr  = s_axi.awaddr;
      assign m_axi.awid    = s_axi.awid;
      assign m_axi.awlen   = s_axi.awlen;
      assign m_axi.awsize  = s_axi.awsize;
      assign m_axi.awburst = s_axi.awburst;
      assign s_axi.awready = m_axi.awready;
    end else begin : g_aw_delay
      logic              busy_q;
      logic [CNT_W-1:0]  wait_q;
      logic [ADDR_W-1:0] addr_q;
      logic [ID_W-1:0]   id_q;
      logic [LEN_W-1:0]  len_q;
      logic [SIZE_W-1:0] size_q;
      logic [BURST_W-1:0] burst_q;

      assign s_axi.awready = ~busy_q;
      assign m_axi.awvalid = busy_q && (wait_q == '0);
      assign m_axi.awaddr  = addr_q;
      assign m_axi.awid    = id_q;
      assign m_axi.awlen   = len_q;
      assign m_axi.awsize  = size_q;
      assign m_axi.awburst = burst_q;

      always_ff @(posedge clk) begin
        if (rst) begin
          busy_q <= 1'b0;
          wait_q <= '0;
        end else if (!busy_q) begin
          if (s_axi.awvalid && s_axi.awready) begin
            busy_q  <= 1'b1;
            wait_q  <= CNT_W'(AW_LATENCY);
            addr_q  <= s_axi.awaddr;
            id_q    <= s_axi.awid;
            len_q   <= s_axi.awlen;
            size_q  <= s_axi.awsize;
            burst_q <= s_axi.awburst;
          end
        end else begin
          if (wait_q != '0) begin
            wait_q <= wait_q - 1'b1;
          end
          if (s_axi.bvalid && s_axi.bready) begin
            busy_q <= 1'b0;
          end
        end
      end
    end
  endgenerate

  // ====================================================== W / B (pass-through)
  assign m_axi.wvalid = s_axi.wvalid;
  assign m_axi.wdata  = s_axi.wdata;
  assign m_axi.wstrb  = s_axi.wstrb;
  assign m_axi.wlast  = s_axi.wlast;
  assign s_axi.wready = m_axi.wready;

  assign s_axi.bvalid = m_axi.bvalid;
  assign s_axi.bresp  = m_axi.bresp;
  assign s_axi.bid    = m_axi.bid;
  assign m_axi.bready = s_axi.bready;

  // ============================================================ R channel
  generate
    if (R_GAP == 0) begin : g_r_bypass
      assign s_axi.rvalid = m_axi.rvalid;
      assign s_axi.rresp  = m_axi.rresp;
      assign s_axi.rdata  = m_axi.rdata;
      assign s_axi.rlast  = m_axi.rlast;
      assign s_axi.rid    = m_axi.rid;
      assign m_axi.rready = s_axi.rready;
    end else begin : g_r_gap
      logic [CNT_W-1:0] hold_q;
      wire              allow = (hold_q == '0);

      assign s_axi.rvalid = m_axi.rvalid && allow;
      assign s_axi.rresp  = m_axi.rresp;
      assign s_axi.rdata  = m_axi.rdata;
      assign s_axi.rlast  = m_axi.rlast;
      assign s_axi.rid    = m_axi.rid;
      assign m_axi.rready = s_axi.rready && allow;

      always_ff @(posedge clk) begin
        if (rst) begin
          hold_q <= '0;
        end else if (m_axi.rvalid && s_axi.rready && allow) begin
          hold_q <= CNT_W'(R_GAP);
        end else if (hold_q != '0) begin
          hold_q <= hold_q - 1'b1;
        end
      end
    end
  endgenerate
endmodule
