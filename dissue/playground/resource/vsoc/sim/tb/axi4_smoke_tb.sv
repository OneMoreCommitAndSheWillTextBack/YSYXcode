// axi4_smoke_tb -- drives u_soc directly (no core) with scripted AXI4 traffic.
//
// Covers the failure modes that used to hang the machine: writes, reads, byte
// strobes, a burst, the UART, and unclaimed addresses answering DECERR.
// The clock is toggled by the C++ harness; this module has no timing constructs.
module axi4_smoke_tb (
    input  logic        clock,
    input  logic        reset,
    output logic        done,
    output logic [31:0] error_count
);
  import vsoc_pkg::*;

  vsoc_axi_if #() bus ();

  u_soc u_soc (
      .clk  (clock),
      .rst  (reset),
      .s_axi(bus)
  );

  axi4_protocol_checker u_checker (
      .clk(clock),
      .rst(reset),
      .bus(bus)
  );

  initial begin
    done        = 1'b0;
    error_count = '0;
  end

  // All master outputs are driven at the negedge, so the DUT always samples a
  // stable value. Ready is never a function of valid inside vsoc, so checking
  // ready right after asserting valid is safe.
  task automatic bus_idle();
    bus.awvalid = 1'b0;
    bus.awaddr  = '0;
    bus.awid    = '0;
    bus.awlen   = '0;
    bus.awsize  = '0;
    bus.awburst = BURST_INCR;
    bus.wvalid  = 1'b0;
    bus.wdata   = '0;
    bus.wstrb   = '0;
    bus.wlast   = 1'b0;
    bus.bready  = 1'b0;
    bus.arvalid = 1'b0;
    bus.araddr  = '0;
    bus.arid    = '0;
    bus.arlen   = '0;
    bus.arsize  = '0;
    bus.arburst = BURST_INCR;
    bus.rready  = 1'b0;
  endtask

  task automatic check(input string name, input logic ok);
    if (!ok) begin
      error_count = error_count + 1'b1;
      $display("[smoke] FAIL  %s", name);
    end else begin
      $display("[smoke] ok    %s", name);
    end
  endtask

  // One write burst of `beats` beats, all data equal to `data`.
  task automatic write_burst(
      input  logic [31:0] addr,
      input  logic [31:0] data,
      input  logic [3:0]  strb,
      input  int unsigned beats,
      output logic [1:0]  resp
  );
    @(negedge clock);
    bus.awvalid = 1'b1;
    bus.awaddr  = addr;
    bus.awlen   = 8'(beats - 1);
    bus.awsize  = 3'd2;
    bus.awburst = BURST_INCR;
    while (!bus.awready) @(negedge clock);
    @(negedge clock);
    bus.awvalid = 1'b0;

    for (int unsigned i = 0; i < beats; i++) begin
      bus.wvalid = 1'b1;
      bus.wdata  = data + i;
      bus.wstrb  = strb;
      bus.wlast  = (i == (beats - 1));
      while (!bus.wready) @(negedge clock);
      @(negedge clock);
    end
    bus.wvalid = 1'b0;
    bus.wlast  = 1'b0;

    bus.bready = 1'b1;
    while (!bus.bvalid) @(negedge clock);
    resp = bus.bresp;
    @(negedge clock);
    bus.bready = 1'b0;
  endtask

  // One read burst of `beats` beats; returns the first beat and the response.
  task automatic read_burst(
      input  logic [31:0] addr,
      input  int unsigned beats,
      output logic [31:0] data0,
      output logic [31:0] datalast,
      output logic [1:0]  resp,
      output logic        saw_more
  );
    int unsigned seen;
    @(negedge clock);
    bus.arvalid = 1'b1;
    bus.araddr  = addr;
    bus.arlen   = 8'(beats - 1);
    bus.arsize  = 3'd2;
    bus.arburst = BURST_INCR;
    bus.rready  = 1'b1;
    while (!bus.arready) @(negedge clock);
    @(negedge clock);
    bus.arvalid = 1'b0;

    seen   = 0;
    data0  = '0;
    datalast = '0;
    saw_more = 1'b0;
    while (seen < beats) begin
      while (!bus.rvalid) @(negedge clock);
      if (seen == 0) begin
        data0 = bus.rdata;
        resp  = bus.rresp;
      end
      if (bus.rlast && (seen != (beats - 1))) saw_more = 1'b1;
      datalast = bus.rdata;
      seen     = seen + 1;
      @(negedge clock);
    end
    bus.rready = 1'b0;
  endtask

  logic [31:0] rdata;
  logic [31:0] rdata0;
  logic [31:0] rlast;
  logic [1:0]  resp;
  logic        saw_more;

  initial begin : main_sequence
    logic [31:0] d0, d1;

    bus_idle();
    wait (!reset);
    repeat (2) @(negedge clock);

    // ---- 1. word write / read back ------------------------------------
    write_burst(32'h8000_0100, 32'hDEAD_BEEF, 4'hF, 1, resp);
    check("pmem word write -> OKAY", resp == RESP_OKAY);
    read_burst(32'h8000_0100, 1, rdata, rlast, resp, saw_more);
    check("pmem word read -> OKAY", resp == RESP_OKAY);
    check("pmem word read data", rdata == 32'hDEAD_BEEF);

    // ---- 2. byte strobe ------------------------------------------------
    write_burst(32'h8000_0200, 32'h0005_0000, 4'b0100, 1, resp);
    check("pmem byte write -> OKAY", resp == RESP_OKAY);
    read_burst(32'h8000_0200, 1, rdata, rlast, resp, saw_more);
    check("pmem byte write visible", rdata == 32'h0005_0000);

    // ---- 3. four-beat burst read ---------------------------------------
    write_burst(32'h8000_0300, 32'h1122_3344, 4'hF, 1, resp);
    write_burst(32'h8000_0304, 32'h5566_7788, 4'hF, 1, resp);
    write_burst(32'h8000_0308, 32'h99AA_BBCC, 4'hF, 1, resp);
    write_burst(32'h8000_030C, 32'hDDEE_FF00, 4'hF, 1, resp);
    read_burst(32'h8000_0300, 4, rdata0, rlast, resp, saw_more);
    check("burst read -> OKAY", resp == RESP_OKAY);
    check("burst read beat0", rdata0 == 32'h1122_3344);
    check("burst read beat3 (rlast)", rlast == 32'hDDEE_FF00);

    // ---- 4. two-beat burst write ---------------------------------------
    write_burst(32'h8000_0400, 32'hAAAA_0000, 4'hF, 2, resp);
    check("burst write -> OKAY", resp == RESP_OKAY);
    read_burst(32'h8000_0400, 2, d0, d1, resp, saw_more);
    check("burst write beat1 visible", d1 == 32'hAAAA_0001);

    // ---- 5. uart transmit ('U' goes to stdout) --------------------------
    $display("[smoke] uart-char-follows:");
    write_burst(32'hA000_03F8, 32'h0000_0055, 4'b0001, 1, resp);
    check("uart write -> OKAY", resp == RESP_OKAY);

    // ---- 6. unclaimed address: read and write both answer --------------
    read_burst(32'h1000_0000, 1, rdata, rlast, resp, saw_more);
    check("unmapped read -> DECERR", resp == RESP_DECERR);

    write_burst(32'h1000_0000, 32'h1234_5678, 4'hF, 2, resp);
    check("unmapped 2-beat write -> DECERR (W drained)", resp == RESP_DECERR);

    // ---- 7. first address past pmem: still answered ---------------------
    read_burst(32'hA000_0000, 1, rdata, rlast, resp, saw_more);
    check("past-pmem read -> DECERR", resp == RESP_DECERR);

    // ---- 8. unaligned narrow access -------------------------------------
    write_burst(32'h8000_0501, 32'h0000_AB00, 4'b0010, 1, resp);
    check("unaligned byte write -> OKAY", resp == RESP_OKAY);
    read_burst(32'h8000_0500, 1, rdata, rlast, resp, saw_more);
    check("unaligned byte lands on lane 1", rdata == 32'h0000_AB00);

    if (error_count == 0) $display("[smoke] PASS (all checks)");
    else                  $display("[smoke] FAILED: %0d check(s)", error_count);
    done = 1'b1;
  end
endmodule
