// vsoc_pkg -- single source of truth for widths, response codes and the address map.
// See doc/README.md (address map) and doc/interfaces.md (contract).
package vsoc_pkg;

  // ---------------------------------------------------------------- widths
  localparam int unsigned ADDR_W  = 32;
  localparam int unsigned DATA_W  = 32;
  localparam int unsigned ID_W    = 4;
  localparam int unsigned STRB_W  = DATA_W / 8;
  localparam int unsigned LEN_W   = 8;
  localparam int unsigned SIZE_W  = 3;
  localparam int unsigned BURST_W = 2;
  localparam int unsigned RESP_W  = 2;
  // Largest legal AxSIZE: one beat must fit inside the data bus.
  localparam logic [SIZE_W-1:0] MAX_BEAT_SIZE = SIZE_W'($clog2(STRB_W));

  // ------------------------------------------------------------ burst types
  localparam logic [BURST_W-1:0] BURST_FIXED = 2'b00;
  localparam logic [BURST_W-1:0] BURST_INCR  = 2'b01;
  localparam logic [BURST_W-1:0] BURST_WRAP  = 2'b10;

  // -------------------------------------------------------------- responses
  localparam logic [RESP_W-1:0] RESP_OKAY   = 2'b00;
  localparam logic [RESP_W-1:0] RESP_EXOKAY = 2'b01;
  localparam logic [RESP_W-1:0] RESP_SLVERR = 2'b10;
  localparam logic [RESP_W-1:0] RESP_DECERR = 2'b11;

  // ------------------------------------------------- SoC address map (decoded here)
  localparam logic [ADDR_W-1:0] PMEM_BASE = 32'h8000_0000;
  localparam logic [ADDR_W-1:0] PMEM_SIZE = 32'h2000_0000;  // 512 MiB, matches host DEFAULT_PMEM_SIZE
  localparam logic [ADDR_W-1:0] UART_BASE = 32'hA000_03F8;
  localparam logic [ADDR_W-1:0] UART_SIZE = 32'h0000_0004;

  // Downstream port index of the demux. Adding a peripheral = add an id here,
  // bump NUM_SLAVES, add the range to vsoc_decode() and instantiate it in u_soc.
  localparam int unsigned DEV_PMEM    = 0;
  localparam int unsigned DEV_UART    = 1;
  localparam int unsigned DEV_DEFAULT = 2;
  localparam int unsigned NUM_SLAVES  = 3;
  localparam int unsigned SEL_W       = $clog2(NUM_SLAVES);

  // ------------------- regions decoded inside the core (must never reach the SoC)
  localparam logic [ADDR_W-1:0] CLINT_BASE = 32'h0200_0000;
  localparam logic [ADDR_W-1:0] CLINT_SIZE = 32'h0001_0000;
  localparam logic [ADDR_W-1:0] RTC_BASE   = 32'hA000_0048;
  localparam logic [ADDR_W-1:0] RTC_SIZE   = 32'h0000_0008;
  localparam logic [ADDR_W-1:0] PLIC_BASE  = 32'h0C00_0000;
  localparam logic [ADDR_W-1:0] PLIC_SIZE  = 32'h0400_0000;

  // ------------------------------------------------------------ delay defaults
  // 0 == pure pass-through (see doc/timing.md section 7).
  localparam int unsigned PMEM_AR_LATENCY = 0;
  localparam int unsigned PMEM_AW_LATENCY = 0;
  localparam int unsigned PMEM_R_GAP      = 0;
  localparam int unsigned UART_AR_LATENCY = 0;
  localparam int unsigned UART_AW_LATENCY = 0;
  localparam int unsigned UART_R_GAP      = 0;

  // ------------------------------------------------------------------ helpers
  function automatic logic in_range(
      input logic [ADDR_W-1:0] addr,
      input logic [ADDR_W-1:0] base,
      input logic [ADDR_W-1:0] size
  );
    in_range = (addr >= base) && (addr < (base + size));
  endfunction

  // Address decode for the one-to-N fabric. Longest/most specific region first.
  function automatic logic [SEL_W-1:0] vsoc_decode(input logic [ADDR_W-1:0] addr);
    if (in_range(addr, PMEM_BASE, PMEM_SIZE))      vsoc_decode = SEL_W'(DEV_PMEM);
    else if (in_range(addr, UART_BASE, UART_SIZE)) vsoc_decode = SEL_W'(DEV_UART);
    else                                           vsoc_decode = SEL_W'(DEV_DEFAULT);
  endfunction

  // True when the core should have intercepted the address. The protocol checker
  // uses this to catch crossbar regressions.
  function automatic logic in_core_region(input logic [ADDR_W-1:0] addr);
    in_core_region = in_range(addr, CLINT_BASE, CLINT_SIZE) ||
                     in_range(addr, RTC_BASE, RTC_SIZE) ||
                     in_range(addr, PLIC_BASE, PLIC_SIZE);
  endfunction

  // First and last byte touched by a burst, using the AXI "container" definition.
  function automatic logic [63:0] burst_first(
      input logic [ADDR_W-1:0] addr,
      input logic [SIZE_W-1:0] size
  );
    logic [63:0] mask;
    mask        = (64'd1 << size) - 64'd1;
    burst_first = {32'b0, addr} & ~mask;
  endfunction

  function automatic logic [63:0] burst_last(
      input logic [ADDR_W-1:0] addr,
      input logic [SIZE_W-1:0] size,
      input logic [LEN_W-1:0]  len
  );
    burst_last = burst_first(addr, size) + (({56'b0, len} + 64'd1) << size) - 64'd1;
  endfunction

  // Whole-burst range check: every byte of every beat must be inside the region.
  function automatic logic burst_in_range(
      input logic [ADDR_W-1:0] addr,
      input logic [SIZE_W-1:0] size,
      input logic [LEN_W-1:0]  len,
      input logic [ADDR_W-1:0] base,
      input logic [ADDR_W-1:0] region_size
  );
    logic [63:0] first;
    logic [63:0] last;
    first = burst_first(addr, size);
    last  = burst_last(addr, size, len);
    burst_in_range = (first >= {32'b0, base}) && (last <= ({32'b0, base} + {32'b0, region_size} - 64'd1));
  endfunction

  function automatic logic burst_legal(
      input logic [SIZE_W-1:0]  size,
      input logic [BURST_W-1:0] burst
  );
    burst_legal = (burst == BURST_INCR) && (size <= MAX_BEAT_SIZE);
  endfunction

  // Beat base address: lanes always map to (addr % STRB_W), so narrow and
  // unaligned transfers land on the right byte lanes.
  function automatic logic [ADDR_W-1:0] beat_base(
      input logic [ADDR_W-1:0] start_addr,
      input logic [SIZE_W-1:0] size,
      input logic [LEN_W:0]    beat
  );
    logic [ADDR_W-1:0] addr;
    addr      = start_addr + (ADDR_W'(beat) << size);
    beat_base = addr & ~(ADDR_W'(STRB_W) - ADDR_W'(1));
  endfunction

endpackage
