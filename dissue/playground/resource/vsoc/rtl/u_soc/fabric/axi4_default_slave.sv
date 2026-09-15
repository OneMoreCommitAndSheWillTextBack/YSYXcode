// axi4_default_slave -- answers every unclaimed address with DECERR.
//
// This module is the reason a speculative load to a bogus address can no longer
// hang the machine: "no slave claimed this address" must still produce a
// response. See doc/modules.md section 5 and doc/timing.md section 6.
module axi4_default_slave (
    input logic clk,
    input logic rst,
    vsoc_axi_if.slave s_axi
);
  import vsoc_pkg::*;

  // ------------------------------------------------------------- read channel
  logic            r_pending_q;
  logic [ID_W-1:0] rid_q;

  assign s_axi.arready = ~r_pending_q;
  assign s_axi.rvalid  = r_pending_q;
  assign s_axi.rdata   = {DATA_W{1'b0}};
  assign s_axi.rresp   = RESP_DECERR;
  assign s_axi.rlast   = 1'b1;  // one beat terminates the burst
  assign s_axi.rid     = rid_q;

  // ------------------------------------------------------------ write channel
  logic             aw_seen_q;  // address accepted, still draining write data
  logic             b_pending_q;
  logic [ID_W-1:0]  bid_q;
  logic [LEN_W-1:0] awlen_q;
  logic [LEN_W:0]   wbeat_q;    // write beats accepted so far

  assign s_axi.awready = ~aw_seen_q && ~b_pending_q;
  assign s_axi.wready  = aw_seen_q;  // write data is accepted even though we error
  assign s_axi.bvalid  = b_pending_q;
  assign s_axi.bresp   = RESP_DECERR;
  assign s_axi.bid     = bid_q;

  always_ff @(posedge clk) begin
    if (rst) begin
      r_pending_q <= 1'b0;
      rid_q       <= '0;
      aw_seen_q   <= 1'b0;
      b_pending_q <= 1'b0;
      bid_q       <= '0;
      awlen_q     <= '0;
      wbeat_q     <= '0;
    end else begin
      // Read: accept one AR, hold the error beat until it is taken.
      if (s_axi.arvalid && s_axi.arready) begin
        r_pending_q <= 1'b1;
        rid_q       <= s_axi.arid;
      end else if (s_axi.rvalid && s_axi.rready) begin
        r_pending_q <= 1'b0;
      end

      // Write: accept AW, then drain exactly len+1 W beats, then raise B.
      if (s_axi.awvalid && s_axi.awready) begin
        aw_seen_q <= 1'b1;
        bid_q     <= s_axi.awid;
        awlen_q   <= s_axi.awlen;
        wbeat_q   <= '0;
      end else if (s_axi.wvalid && s_axi.wready) begin
        if (s_axi.wlast) begin
          assert (wbeat_q == {1'b0, awlen_q})
          else $error("axi4_default_slave: W beat count does not match awlen");
          aw_seen_q   <= 1'b0;
          b_pending_q <= 1'b1;
        end else begin
          wbeat_q <= wbeat_q + 1'b1;
        end
      end

      if (s_axi.bvalid && s_axi.bready) begin
        b_pending_q <= 1'b0;
      end
    end
  end

  // The slave only ever has one transaction in flight; a second one means the
  // fabric above lost track of a response.
  assert property (@(posedge clk) disable iff (rst) !(s_axi.arvalid && s_axi.arready && r_pending_q));
endmodule
