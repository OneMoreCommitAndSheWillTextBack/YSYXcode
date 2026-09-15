// vsoc_axi_if -- the AXI4 interface used everywhere inside vsoc.
// See doc/interfaces.md section 3. Do not add signals without updating that doc.
interface vsoc_axi_if #(
    parameter int unsigned ADDR_W = vsoc_pkg::ADDR_W,
    parameter int unsigned DATA_W = vsoc_pkg::DATA_W,
    parameter int unsigned ID_W   = vsoc_pkg::ID_W
);
  localparam int unsigned STRB_W = DATA_W / 8;

  // AW: write address
  logic              awvalid;
  logic              awready;
  logic [ADDR_W-1:0] awaddr;
  logic [ID_W-1:0]   awid;
  logic [7:0]        awlen;
  logic [2:0]        awsize;
  logic [1:0]        awburst;

  // W: write data
  logic              wvalid;
  logic              wready;
  logic [DATA_W-1:0] wdata;
  logic [STRB_W-1:0] wstrb;
  logic              wlast;

  // B: write response
  logic              bvalid;
  logic              bready;
  logic [1:0]        bresp;
  logic [ID_W-1:0]   bid;

  // AR: read address
  logic              arvalid;
  logic              arready;
  logic [ADDR_W-1:0] araddr;
  logic [ID_W-1:0]   arid;
  logic [7:0]        arlen;
  logic [2:0]        arsize;
  logic [1:0]        arburst;

  // R: read data
  logic              rvalid;
  logic              rready;
  logic [1:0]        rresp;
  logic [DATA_W-1:0] rdata;
  logic              rlast;
  logic [ID_W-1:0]   rid;

  modport master (
      output awvalid, awaddr, awid, awlen, awsize, awburst,
      input  awready,
      output wvalid, wdata, wstrb, wlast,
      input  wready,
      input  bvalid, bresp, bid,
      output bready,
      output arvalid, araddr, arid, arlen, arsize, arburst,
      input  arready,
      input  rvalid, rresp, rdata, rlast, rid,
      output rready
  );

  modport slave (
      input  awvalid, awaddr, awid, awlen, awsize, awburst,
      output awready,
      input  wvalid, wdata, wstrb, wlast,
      output wready,
      output bvalid, bresp, bid,
      input  bready,
      input  arvalid, araddr, arid, arlen, arsize, arburst,
      output arready,
      output rvalid, rresp, rdata, rlast, rid,
      input  rready
  );

  // Read-only view for the protocol checker.
  modport monitor (
      input awvalid, awready, awaddr, awid, awlen, awsize, awburst,
      input wvalid, wready, wdata, wstrb, wlast,
      input bvalid, bready, bresp, bid,
      input arvalid, arready, araddr, arid, arlen, arsize, arburst,
      input rvalid, rready, rresp, rdata, rlast, rid
  );
endinterface
