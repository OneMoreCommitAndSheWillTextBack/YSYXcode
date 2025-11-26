// synopsys translate_off
import "DPI-C" function void host_get_valid(int valid);
import "DPI-C" function void host_get_ifu_start();
import "DPI-C" function void host_get_ifu_finish();
// synopsys translate_on
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
  reg [2:0] state;

  typedef enum logic[2:0]{
    START,
    PROCESSION,
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

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // divide it so it couldnot disrupt the synthetic
  // synopsys translate_off
  always @(posedge clk) begin
    host_get_valid({31'b0, infetch_ready});
  end

  always @(posedge clk) begin
    if (!rst) begin
      case (state)
        START: begin
          if(ready) begin
            host_get_ifu_start();
          end
        end

        PROCESSION: begin
          if (ready) begin
            host_get_ifu_finish();
            host_get_ifu_start();
          end else begin
            host_get_ifu_finish();
          end
        end

        VALID: begin
          if (ready) begin
            host_get_ifu_start();
          end
        end

        default: begin end
      endcase
    end
  end
  // synopsys translate_on
  
  reg [31:0] inst_reg;
  always @(posedge clk) begin
    if(rst) begin
      state <= START;
    end else begin
      case (state)
        START: begin
          if (ready) begin
            state <= WAIT_HANDSHAKE;
          end
        end

        PROCESSION: begin
          if (ready) begin
            state <= WAIT_HANDSHAKE;
            inst_reg <= 0;
          end else begin
            state <= VALID;
          end
        end

        VALID: begin
          if (ready) begin
            state <= WAIT_HANDSHAKE;
            inst_reg <= 0;
          end
        end

        WAIT_HANDSHAKE: begin
          if (arready) begin
            state <= WAIT_SLAVE;
          end
        end

        WAIT_SLAVE: begin
          if (rvalid) begin
            state <= PROCESSION;
            inst_reg <= rdata;
          end
        end

        default: begin 
          // synopsys translate_off
          $error("state error");
          // synopsys translate_on
        end
      endcase
    end
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = state == VALID | state == PROCESSION;

  assign arvalid = state == WAIT_HANDSHAKE;
  assign araddr = pc;
  assign rready = ready;

  assign infetch_ready = valid & ready;
  assign regprocess = state == PROCESSION;

endmodule
