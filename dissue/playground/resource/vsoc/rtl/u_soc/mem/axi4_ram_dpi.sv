// axi4_ram_dpi -- pmem: the only place in vsoc that touches host memory.
//
// Protocol notes (doc/timing.md):
//   * rvalid never depends on rready; a beat is held until it is taken.
//   * AW and W are accepted independently; W is back-pressured until AW arrives.
//   * A write that errors still drains every W beat before raising B.
//   * Out-of-range addresses answer DECERR without calling into the host.
module axi4_ram_dpi #(
    parameter logic [ADDR_W-1:0] BASE_ADDR   = vsoc_pkg::PMEM_BASE,
    parameter logic [ADDR_W-1:0] REGION_SIZE = vsoc_pkg::PMEM_SIZE
) (
    input logic clk,
    input logic rst,
    vsoc_axi_if.slave s_axi
);
  import vsoc_pkg::*;

  // Host bridge. Signatures are frozen; see doc/interfaces.md section 6.
  import "DPI-C" function void npc_pmem_read(input int addr, input int len, output int data);
  import "DPI-C" function void npc_pmem_write(input int addr, input int len, input int data);

  logic [DATA_W-1:0] dpi_word;

  // =========================================================== read channel
  logic              r_active_q;
  logic [1:0]        r_resp_q;
  logic [ID_W-1:0]   r_id_q;
  logic [ADDR_W-1:0] r_addr_q;
  logic [SIZE_W-1:0] r_size_q;
  logic [LEN_W-1:0]  r_len_q;
  logic [LEN_W:0]    r_beat_q;
  logic [DATA_W-1:0] r_data_q;

  wire r_last = (r_beat_q == {1'b0, r_len_q}) || (r_resp_q != RESP_OKAY);
  wire ar_legal = burst_legal(s_axi.arsize, s_axi.arburst);
  wire ar_mapped = burst_in_range(s_axi.araddr, s_axi.arsize, s_axi.arlen, BASE_ADDR, REGION_SIZE);

  assign s_axi.arready = ~r_active_q;
  assign s_axi.rvalid  = r_active_q;
  assign s_axi.rdata   = r_data_q;
  assign s_axi.rresp   = r_resp_q;
  assign s_axi.rlast   = r_last;
  assign s_axi.rid     = r_id_q;

  always_ff @(posedge clk) begin
    if (rst) begin
      r_active_q <= 1'b0;
      r_resp_q   <= RESP_OKAY;
      r_id_q     <= '0;
      r_addr_q   <= '0;
      r_size_q   <= '0;
      r_len_q    <= '0;
      r_beat_q   <= '0;
      r_data_q   <= '0;
    end else if (!r_active_q) begin
      if (s_axi.arvalid && s_axi.arready) begin
        r_active_q <= 1'b1;
        r_id_q     <= s_axi.arid;
        r_addr_q   <= s_axi.araddr;
        r_size_q   <= s_axi.arsize;
        r_len_q    <= s_axi.arlen;
        r_beat_q   <= '0;
        if (!ar_legal) begin
          r_resp_q <= RESP_SLVERR;
          r_data_q <= '0;
        end else if (!ar_mapped) begin
          r_resp_q <= RESP_DECERR;
          r_data_q <= '0;
        end else begin
          r_resp_q <= RESP_OKAY;
          npc_pmem_read(int'(beat_base(s_axi.araddr, s_axi.arsize, '0)), 32'd4, dpi_word);
          r_data_q <= dpi_word;
        end
      end
    end else if (s_axi.rvalid && s_axi.rready) begin
      if (r_last) begin
        r_active_q <= 1'b0;
      end else begin
        r_beat_q <= r_beat_q + 1'b1;
        // Prefetch the next beat so beats can stream back-to-back.
        npc_pmem_read(int'(beat_base(r_addr_q, r_size_q, r_beat_q + 1'b1)), 32'd4, dpi_word);
        r_data_q <= dpi_word;
      end
    end
  end

  // ========================================================== write channel
  logic              w_active_q;   // AW accepted, write data still arriving
  logic              b_pending_q;
  logic [1:0]        w_resp_q;
  logic [ID_W-1:0]   b_id_q;
  logic [ADDR_W-1:0] w_addr_q;
  logic [SIZE_W-1:0] w_size_q;
  logic [LEN_W-1:0]  w_len_q;
  logic [LEN_W:0]    w_beat_q;

  wire aw_legal  = burst_legal(s_axi.awsize, s_axi.awburst);
  wire aw_mapped = burst_in_range(s_axi.awaddr, s_axi.awsize, s_axi.awlen, BASE_ADDR, REGION_SIZE);

  assign s_axi.awready = ~w_active_q && ~b_pending_q;
  assign s_axi.wready  = w_active_q;  // data is accepted even when the address errored
  assign s_axi.bvalid  = b_pending_q;
  assign s_axi.bresp   = w_resp_q;
  assign s_axi.bid     = b_id_q;

  // Per-beat byte address; lanes always map to (address % STRB_W).
  localparam logic [63:0] STRB_BYTES = 64'(STRB_W);

  logic [ADDR_W-1:0] w_beat_addr;
  logic              w_word_aligned;
  assign w_beat_addr    = beat_base(w_addr_q, w_size_q, w_beat_q);
  assign w_word_aligned = ({32'b0, w_beat_addr} >= {32'b0, BASE_ADDR}) &&
                          (({32'b0, w_beat_addr} + STRB_BYTES) <=
                           ({32'b0, BASE_ADDR} + {32'b0, REGION_SIZE}));

  always_ff @(posedge clk) begin
    if (rst) begin
      w_active_q  <= 1'b0;
      b_pending_q <= 1'b0;
      w_resp_q    <= RESP_OKAY;
      b_id_q      <= '0;
      w_addr_q    <= '0;
      w_size_q    <= '0;
      w_len_q     <= '0;
      w_beat_q    <= '0;
    end else begin
      if (s_axi.awvalid && s_axi.awready) begin
        w_active_q <= 1'b1;
        b_id_q     <= s_axi.awid;
        w_addr_q   <= s_axi.awaddr;
        w_size_q   <= s_axi.awsize;
        w_len_q    <= s_axi.awlen;
        w_beat_q   <= '0;
        w_resp_q   <= !aw_legal ? RESP_SLVERR : (!aw_mapped ? RESP_DECERR : RESP_OKAY);
      end else if (s_axi.wvalid && s_axi.wready) begin
        if (w_resp_q == RESP_OKAY) begin
          if (s_axi.wstrb == {STRB_W{1'b1}} && w_word_aligned) begin
            // Fast path: one host call per beat instead of one per byte lane.
            npc_pmem_write(int'(w_beat_addr), 32'd4, int'(s_axi.wdata));
          end else begin
            for (int unsigned lane = 0; lane < STRB_W; lane++) begin
              if (s_axi.wstrb[lane]) begin
                npc_pmem_write(int'(w_beat_addr + ADDR_W'(lane)), 32'd1,
                               int'(s_axi.wdata[8*lane +: 8]));
              end
            end
          end
        end

        if (s_axi.wlast) begin
          assert (w_beat_q == {1'b0, w_len_q})
          else $error("axi4_ram_dpi: W beat count does not match awlen");
          w_active_q  <= 1'b0;
          b_pending_q <= 1'b1;
        end else begin
          w_beat_q <= w_beat_q + 1'b1;
        end
      end

      if (s_axi.bvalid && s_axi.bready) begin
        b_pending_q <= 1'b0;
      end
    end
  end

  // One transaction per direction at a time (matches the current core, see
  // doc/timing.md section 3). Revisit together with the ID table upgrade.
  assert property (@(posedge clk) disable iff (rst) !(s_axi.arvalid && s_axi.arready && r_active_q));
  assert property (@(posedge clk) disable iff (rst) !(s_axi.awvalid && s_axi.awready && w_active_q));
endmodule
