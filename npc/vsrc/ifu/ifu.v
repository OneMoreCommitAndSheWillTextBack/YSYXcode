module ifu(
  input clk,
  input rst,
  input [31:0] npc,
  input ready,

  output [31:0] pc,
  output [31:0] inst,
  output valid,

  // AXI-Lite interface for external SRAM
  output arvalid,          // Read address valid
  input arready,           // Read address ready
  output [31:0] araddr,    // Read address
  input rvalid,            // Read data valid
  output rready,           // Read data ready
  input [31:0] rdata       // Read data
);

  wire [31:0] pcbridge;
  wire [31:0] instbridge;
  wire infetch_ready;

  // PC register module
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(infetch_ready)
  );

  // Assign outputs
  assign pc = pcbridge;
  assign inst = instbridge;
  assign valid = rvalid; // Assuming valid is driven by rvalid from SRAM

  // Control logic for AXI-Lite interface
  assign arvalid = ready; // Start a read transaction when ready
  assign araddr = pc;     // Address to read is the current PC
  assign rready = ready;  // Always ready to accept read data when ready

  // Connect SRAM read data to instruction bridge
  assign instbridge = rdata;

  // Logic to determine if the fetch is ready
  assign infetch_ready = ready & rvalid;

endmodule
