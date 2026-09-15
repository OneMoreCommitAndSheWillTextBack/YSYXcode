// axi4_uart -- AM/NEMU serial port (0xa000_03f8), transmit side only.
//
// Reads are side-effect free and always report "transmitter ready"; reads
// return zero, which matches the old sim_mmio/sim_uart behaviour. Writes to
// offset 0 emit one character. Byte lanes are inspected individually so byte
// and word stores both work.
module axi4_uart #(
    parameter logic [ADDR_W-1:0] BASE_ADDR   = vsoc_pkg::UART_BASE,
    parameter logic [ADDR_W-1:0] REGION_SIZE = vsoc_pkg::UART_SIZE
) (
    input logic clk,
    input logic rst,
    vsoc_axi_if.slave s_axi
);
  import vsoc_pkg::*;

`ifdef VSOC_UART_DPI
  import "DPI-C" function void vsoc_uart_tx(input byte ch);
`endif

  // ------------------------------------------------------------- read channel
  logic            r_pending_q;
  logic [1:0]      r_resp_q;
  logic [ID_W-1:0] rid_q;

  wire ar_mapped = in_range(s_axi.araddr, BASE_ADDR, REGION_SIZE);

  assign s_axi.arready = ~r_pending_q;
  assign s_axi.rvalid  = r_pending_q;
  assign s_axi.rdata   = {DATA_W{1'b0}};
  assign s_axi.rresp   = r_resp_q;
  assign s_axi.rlast   = 1'b1;
  assign s_axi.rid     = rid_q;

  // ------------------------------------------------------------ write channel
  logic              aw_seen_q;
  logic              b_pending_q;
  logic [1:0]        w_resp_q;
  logic [ID_W-1:0]   bid_q;
  logic [ADDR_W-1:0] w_addr_q;
  logic [SIZE_W-1:0] w_size_q;
  logic [LEN_W:0]    w_beat_q;

  wire aw_mapped = burst_in_range(s_axi.awaddr, s_axi.awsize, s_axi.awlen, BASE_ADDR, REGION_SIZE);

  assign s_axi.awready = ~aw_seen_q && ~b_pending_q;
  assign s_axi.wready  = aw_seen_q;
  assign s_axi.bvalid  = b_pending_q;
  assign s_axi.bresp   = w_resp_q;
  assign s_axi.bid     = bid_q;

  logic [ADDR_W-1:0] w_beat_addr;
  assign w_beat_addr = beat_base(w_addr_q, w_size_q, w_beat_q);

  // TX side effect. Simulation only; the synthesis view has no console.
  task automatic uart_emit(input logic [7:0] ch);
`ifdef VSOC_UART_DPI
    vsoc_uart_tx(byte'(ch));
`else
`ifndef SYNTHESIS
    $write("%c", ch);
    $fflush();
`endif
`endif
  endtask

  always_ff @(posedge clk) begin
    if (rst) begin
      r_pending_q <= 1'b0;
      r_resp_q    <= RESP_OKAY;
      rid_q       <= '0;
      aw_seen_q   <= 1'b0;
      b_pending_q <= 1'b0;
      w_resp_q    <= RESP_OKAY;
      bid_q       <= '0;
      w_addr_q    <= '0;
      w_size_q    <= '0;
      w_beat_q    <= '0;
    end else begin
      if (s_axi.arvalid && s_axi.arready) begin
        r_pending_q <= 1'b1;
        rid_q       <= s_axi.arid;
        r_resp_q    <= ar_mapped ? RESP_OKAY : RESP_DECERR;
      end else if (s_axi.rvalid && s_axi.rready) begin
        r_pending_q <= 1'b0;
      end

      if (s_axi.awvalid && s_axi.awready) begin
        aw_seen_q <= 1'b1;
        bid_q     <= s_axi.awid;
        w_addr_q  <= s_axi.awaddr;
        w_size_q  <= s_axi.awsize;
        w_beat_q  <= '0;
        w_resp_q  <= aw_mapped ? RESP_OKAY : RESP_DECERR;
      end else if (s_axi.wvalid && s_axi.wready) begin
        if (w_resp_q == RESP_OKAY) begin
          for (int unsigned lane = 0; lane < STRB_W; lane++) begin
            if (s_axi.wstrb[lane] && ((w_beat_addr + ADDR_W'(lane)) == BASE_ADDR)) begin
              uart_emit(s_axi.wdata[8*lane +: 8]);
            end
          end
        end

        if (s_axi.wlast) begin
          aw_seen_q   <= 1'b0;
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

  assert property (@(posedge clk) disable iff (rst) !(s_axi.arvalid && s_axi.arready && r_pending_q));
  assert property (@(posedge clk) disable iff (rst) !(s_axi.awvalid && s_axi.awready && aw_seen_q));
endmodule
