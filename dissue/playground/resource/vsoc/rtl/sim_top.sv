// sim_top -- the one and only top level.
//
// Ports: clock and reset only. Simulation control (exit, watchdog, waves,
// timeouts) belongs to the host program, not to the RTL. If a second simulator
// (iverilog, VCS) needs its own harness later, wrap this module from outside.
module sim_top (
    input logic clock,
    input logic reset
);
  vsoc_axi_if #() core_bus ();

  u_core u_core (
      .clock(clock),
      .reset(reset),
      .m_axi(core_bus)
  );

  u_soc u_soc (
      .clk  (clock),
      .rst  (reset),
      .s_axi(core_bus)
  );

  axi4_protocol_checker u_protocol_checker (
      .clk(clock),
      .rst(reset),
      .bus(core_bus)
  );
endmodule
