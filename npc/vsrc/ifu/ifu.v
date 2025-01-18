import "DPI-C" function void host_get_valid(int valid);
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
  wire infetch_ready;

  // PC register module
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(infetch_ready)
  );
  
  reg [31:0] inst_reg;
  always @(posedge clk) begin
    if(rvalid)
      inst_reg <= rdata;
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = inst != 0;

  assign arvalid = ready;
  assign araddr = npc;
  assign rready = ready;

  assign infetch_ready = rvalid;

  
  always @(*) begin
    host_get_valid({31'b0, rready});
  end

endmodule
