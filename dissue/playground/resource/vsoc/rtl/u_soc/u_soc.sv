// u_soc -- the SoC. Instances and wiring only; every constant comes from vsoc_pkg.
//
//   s_axi ──> u_demux ──┬── u_delay_pmem ──> u_pmem        (0x8000_0000, 512 MiB, DPI)
//                       ├── u_delay_uart ──> u_uart        (0xa000_03f8, 4 B, TX only)
//                       └─────────────────> u_default_slave (DECERR)
module u_soc (
    input logic clk,
    input logic rst,
    vsoc_axi_if.slave s_axi
);
  import vsoc_pkg::*;

`ifndef SYNTHESIS
  // The address map is a contract; a silent overlap would be a nightmare to debug.
  initial begin
    if (!(({32'b0, PMEM_BASE} + {32'b0, PMEM_SIZE}) <= {32'b0, UART_BASE}) &&
        !(({32'b0, UART_BASE} + {32'b0, UART_SIZE}) <= {32'b0, PMEM_BASE})) begin
      $fatal(1, "vsoc: PMEM and UART regions overlap");
    end
    if (!(({32'b0, PMEM_BASE} + {32'b0, PMEM_SIZE}) <= {32'b0, CLINT_BASE}) &&
        !(({32'b0, CLINT_BASE} + {32'b0, CLINT_SIZE}) <= {32'b0, PMEM_BASE})) begin
      $fatal(1, "vsoc: PMEM overlaps a core-internal region");
    end
    if (in_core_region(UART_BASE)) begin
      $fatal(1, "vsoc: UART overlaps a core-internal region");
    end
  end
`endif

  vsoc_axi_if #() slave_bus [NUM_SLAVES] ();
  vsoc_axi_if #() pmem_bus ();
  vsoc_axi_if #() uart_bus ();

  axi4_demux u_demux (
      .clk  (clk),
      .rst  (rst),
      .s_axi(s_axi),
      .m_axi(slave_bus)
  );

  axi4_delay #(
      .AR_LATENCY(PMEM_AR_LATENCY),
      .AW_LATENCY(PMEM_AW_LATENCY),
      .R_GAP     (PMEM_R_GAP)
  ) u_delay_pmem (
      .clk  (clk),
      .rst  (rst),
      .s_axi(slave_bus[DEV_PMEM]),
      .m_axi(pmem_bus)
  );

  axi4_ram_dpi u_pmem (
      .clk  (clk),
      .rst  (rst),
      .s_axi(pmem_bus)
  );

  axi4_delay #(
      .AR_LATENCY(UART_AR_LATENCY),
      .AW_LATENCY(UART_AW_LATENCY),
      .R_GAP     (UART_R_GAP)
  ) u_delay_uart (
      .clk  (clk),
      .rst  (rst),
      .s_axi(slave_bus[DEV_UART]),
      .m_axi(uart_bus)
  );

  axi4_uart u_uart (
      .clk  (clk),
      .rst  (rst),
      .s_axi(uart_bus)
  );

  axi4_default_slave u_default_slave (
      .clk  (clk),
      .rst  (rst),
      .s_axi(slave_bus[DEV_DEFAULT])
  );
endmodule
