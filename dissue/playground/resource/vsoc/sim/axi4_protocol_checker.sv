// axi4_protocol_checker -- simulation-only AXI4 rule checker.
//
// Rationale: the old memory model hung the machine silently. These checks turn
// "nothing happens any more" into "this specific rule broke, at this cycle".
// See doc/timing.md section 9 for the rule list this implements.
//
// It is a pure monitor: read-only modport, no effect on traffic.
module axi4_protocol_checker #(
    parameter int unsigned TIMEOUT = 4000
) (
    input logic clk,
    input logic rst,
    vsoc_axi_if.monitor bus
);
  import vsoc_pkg::*;

  localparam int unsigned CW = $clog2(TIMEOUT + 1);

  // ---------------------------------------------------- stability check state
  logic              aw_stalled_q, w_stalled_q, ar_stalled_q;
  logic [ADDR_W-1:0] aw_addr_q, ar_addr_q;
  logic [ID_W-1:0]   aw_id_q, ar_id_q;
  logic [LEN_W-1:0]  aw_len_q, ar_len_q;
  logic [SIZE_W-1:0] aw_size_q, ar_size_q;
  logic [BURST_W-1:0] aw_burst_q, ar_burst_q;
  logic [DATA_W-1:0] w_data_q;
  logic [STRB_W-1:0] w_strb_q;
  logic              w_last_q;

  // ------------------------------------------------------- transaction tracking
  logic           rd_active_q;   // a read burst is in flight
  logic [LEN_W:0] rd_beats_q;
  logic [CW-1:0]  rd_wait_q;
  logic           wr_active_q;   // a write transaction is in flight
  logic [LEN_W:0] wr_beats_q;
  logic [LEN_W-1:0] wr_len_q;
  logic [ID_W-1:0]  wr_id_q;
  logic [CW-1:0]  wr_wait_q;
  logic [CW-1:0]  ar_stall_q, aw_stall_q, w_stall_q;

  logic [63:0] ar_first, ar_last, aw_first, aw_last;
  assign ar_first = burst_first(bus.araddr, bus.arsize);
  assign ar_last  = burst_last(bus.araddr, bus.arsize, bus.arlen);
  assign aw_first = burst_first(bus.awaddr, bus.awsize);
  assign aw_last  = burst_last(bus.awaddr, bus.awsize, bus.awlen);

  always_ff @(posedge clk) begin
    if (rst) begin
      aw_stalled_q <= 1'b0;
      w_stalled_q  <= 1'b0;
      ar_stalled_q <= 1'b0;
      aw_addr_q    <= '0;
      ar_addr_q    <= '0;
      rd_active_q  <= 1'b0;
      rd_beats_q   <= '0;
      rd_wait_q    <= '0;
      wr_active_q  <= 1'b0;
      wr_beats_q   <= '0;
      wr_wait_q    <= '0;
      ar_stall_q   <= '0;
      aw_stall_q   <= '0;
      w_stall_q    <= '0;
    end else begin
      // ============================================ R2/R3: VALID and payload
      if (ar_stalled_q) begin
        if (!bus.arvalid) $error("AXI4 violation: ARVALID dropped before handshake");
        else if (bus.araddr != ar_addr_q || bus.arid != ar_id_q || bus.arlen != ar_len_q ||
                 bus.arsize != ar_size_q || bus.arburst != ar_burst_q)
          $error("AXI4 violation: AR payload changed while stalled");
      end
      if (aw_stalled_q) begin
        if (!bus.awvalid) $error("AXI4 violation: AWVALID dropped before handshake");
        else if (bus.awaddr != aw_addr_q || bus.awid != aw_id_q || bus.awlen != aw_len_q ||
                 bus.awsize != aw_size_q || bus.awburst != aw_burst_q)
          $error("AXI4 violation: AW payload changed while stalled");
      end
      if (w_stalled_q) begin
        if (!bus.wvalid) $error("AXI4 violation: WVALID dropped before handshake");
        else if (bus.wdata != w_data_q || bus.wstrb != w_strb_q || bus.wlast != w_last_q)
          $error("AXI4 violation: W payload changed while stalled");
      end

      ar_stalled_q <= bus.arvalid && !bus.arready;
      aw_stalled_q <= bus.awvalid && !bus.awready;
      w_stalled_q  <= bus.wvalid && !bus.wready;
      if (bus.arvalid && !bus.arready) begin
        ar_addr_q <= bus.araddr;  ar_id_q <= bus.arid;   ar_len_q <= bus.arlen;
        ar_size_q <= bus.arsize;  ar_burst_q <= bus.arburst;
      end
      if (bus.awvalid && !bus.awready) begin
        aw_addr_q <= bus.awaddr;  aw_id_q <= bus.awid;   aw_len_q <= bus.awlen;
        aw_size_q <= bus.awsize;  aw_burst_q <= bus.awburst;
      end
      if (bus.wvalid && !bus.wready) begin
        w_data_q <= bus.wdata;  w_strb_q <= bus.wstrb;  w_last_q <= bus.wlast;
      end

      // ================================================== address/AR protocol
      if (bus.arvalid && bus.arready) begin
        if (in_core_region(bus.araddr))
          $error("address map: core-internal address 0x%08x reached the SoC", bus.araddr);
        if (bus.arsize > MAX_BEAT_SIZE)
          $error("AXI4 violation: arsize=%0d exceeds the %0d-byte bus", bus.arsize, STRB_W);
        if (bus.arburst != BURST_INCR)
          $error("AXI4 violation: only INCR bursts are supported (arburst=%0d)", bus.arburst);
        if ((ar_first >> 12) != (ar_last >> 12))
          $error("AXI4 violation: AR burst crosses a 4KB boundary (0x%08x)", bus.araddr);
        if (rd_active_q)
          $error("AXI4 violation: AR accepted while a read is already in flight");
        rd_active_q <= 1'b1;
        rd_beats_q  <= '0;
        rd_wait_q   <= '0;
      end

      // ================================================== address/AW protocol
      if (bus.awvalid && bus.awready) begin
        if (in_core_region(bus.awaddr))
          $error("address map: core-internal address 0x%08x reached the SoC", bus.awaddr);
        if (bus.awsize > MAX_BEAT_SIZE)
          $error("AXI4 violation: awsize=%0d exceeds the %0d-byte bus", bus.awsize, STRB_W);
        if (bus.awburst != BURST_INCR)
          $error("AXI4 violation: only INCR bursts are supported (awburst=%0d)", bus.awburst);
        if ((aw_first >> 12) != (aw_last >> 12))
          $error("AXI4 violation: AW burst crosses a 4KB boundary (0x%08x)", bus.awaddr);
        if (wr_active_q)
          $error("AXI4 violation: AW accepted while a write is already in flight");
        wr_active_q <= 1'b1;
        wr_beats_q  <= '0;
        wr_len_q    <= bus.awlen;
        wr_id_q     <= bus.awid;
        wr_wait_q   <= '0;
      end

      // ========================================================= read response
      if (bus.rvalid) begin
        if (!rd_active_q) $error("AXI4 violation: RVALID without an outstanding AR");
        if (bus.rresp == RESP_EXOKAY) $error("AXI4 violation: slave used EXOKAY");
        if (bus.rresp[1] && !bus.rlast)
          $error("AXI4 violation: an error read response must terminate the burst (rlast=1)");
      end
      if (bus.rvalid && bus.rready) begin
        if (bus.rlast) rd_active_q <= 1'b0;
        else rd_beats_q <= rd_beats_q + 1'b1;
      end

      // ======================================================== write response
      if (bus.bvalid) begin
        if (!wr_active_q) $error("AXI4 violation: BVALID without an outstanding AW");
        if (bus.bresp == RESP_EXOKAY) $error("AXI4 violation: slave used EXOKAY");
        if (bus.bid != wr_id_q) $error("AXI4 violation: BID != AWID");
      end
      if (bus.bvalid && bus.bready) wr_active_q <= 1'b0;

      // =========================================================== W counting
      if (bus.wvalid && bus.wready) begin
        wr_beats_q <= wr_beats_q + 1'b1;
        if (bus.wlast && (wr_beats_q != {1'b0, wr_len_q}))
          $error("AXI4 violation: W beat count (%0d) does not match awlen+1 (%0d)",
                 wr_beats_q + 1'b1, {1'b0, wr_len_q} + 1'b1);
      end

      // ==================================================== liveness / timeouts
      ar_stall_q <= (bus.arvalid && !bus.arready) ? ar_stall_q + 1'b1 : '0;
      aw_stall_q <= (bus.awvalid && !bus.awready) ? aw_stall_q + 1'b1 : '0;
      w_stall_q  <= (bus.wvalid && !bus.wready) ? w_stall_q + 1'b1 : '0;

      if (ar_stall_q >= CW'(TIMEOUT))
        $error("liveness: ARVALID stalled for %0d cycles without ARREADY", TIMEOUT);
      if (aw_stall_q >= CW'(TIMEOUT))
        $error("liveness: AWVALID stalled for %0d cycles without AWREADY", TIMEOUT);
      if (w_stall_q >= CW'(TIMEOUT))
        $error("liveness: WVALID stalled for %0d cycles without WREADY", TIMEOUT);

      if (rd_active_q) begin
        if (rd_wait_q >= CW'(TIMEOUT))
          $error("liveness: read did not complete within %0d cycles", TIMEOUT);
        else
          rd_wait_q <= rd_wait_q + 1'b1;
      end
      if (wr_active_q) begin
        if (wr_wait_q >= CW'(TIMEOUT))
          $error("liveness: write did not complete within %0d cycles", TIMEOUT);
        else
          wr_wait_q <= wr_wait_q + 1'b1;
      end
    end
  end
endmodule
