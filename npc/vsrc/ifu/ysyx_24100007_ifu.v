import "DPI-C" function void host_get_valid(int valid);
module ysyx_24100007_ifu(
  input clk,
  input rst,
  input [31:0] npc,
  input ready,

  output [31:0] pc,
  output [31:0] inst,
  output valid,
  output regprocess,

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
  reg [1:0] state;

  typedef enum logic[1:0]{
    START,
    VALID,
    WAIT_HANDSHAKE,
    WAIT_SLAVE
  } state_t;

  // PC register module
  ysyx_24100007_pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(infetch_ready)
  );
  
  reg [31:0] inst_reg;
  always @(posedge clk) begin
     case (state)
      START: begin
        if (ready) begin
          state <= WAIT_HANDSHAKE;
        end
      end

      VALID: begin
        if (ready)
          state <= WAIT_HANDSHAKE;
      end

      WAIT_HANDSHAKE: begin
        if (arready) begin
          state <= WAIT_SLAVE;
        end
      end

      WAIT_SLAVE: begin
        if (rvalid) begin
          state <= VALID;
        end
      end
     endcase
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = state == VALID;

  assign arvalid = ready & (state != WAIT_HANDSHAKE);
  assign araddr = npc;
  assign rready = ready;

  assign infetch_ready = state == VALID;

  always @(posedge clk) begin
    host_get_valid({31'b0, arready});
  end

endmodule
