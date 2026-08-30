module ysyx_24100007_ifu(
  input clk,
  input rst,
  input [31:0] exu_npc,

  output [31:0] pc,
  output [31:0] inst,
  output valid,
  input ready,

  input is_jmp,
  input fence_active,
  input fence_commit,
  input [31:0] fence_next_pc,

  // LSU handshake
  output        ifu_read_req,
  input         ifu_req_acp,
  input         ifu_req_finish,
  output        ifu_req_ready,
  output [31:0] ifu_addr,
  input  [127:0] ifu_line_data
);

  localparam [3:0] INIT            = 4'd0;
  localparam [3:0] VALID           = 4'd1;
  localparam [3:0] CHECK_CACHE     = 4'd2;
  localparam [3:0] BUS_HANDSHAKE   = 4'd3;
  localparam [3:0] BUS_TRANSACTION = 4'd4;
  localparam [3:0] UPDATE_CACHE    = 4'd5;
  localparam [3:0] BUS_INVALID     = 4'd6;
  localparam [3:0] UPDATE_PC       = 4'd7;
  localparam [3:0] FENCE_WAIT      = 4'd8;

  reg [3:0] ifu_state;
  reg [31:0] inst_reg;
  reg fence_bus_pending;

  wire [31:0] pcbridge;
  wire infetch_req = is_jmp | (ready & valid); // update pc
  // Keep the PC register clock-enabled during reset so a synthesized
  // clock-gate cannot block the synchronous reset value from loading.
  wire pcreg_en = infetch_req | fence_commit | rst;
  wire [31:0] pc_add_4 = pc + 32'd4;
  wire [31:0] npc = fence_commit ? fence_next_pc :
                    ((is_jmp) ? exu_npc : pc_add_4);

  // PC register module
  ysyx_24100007_pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(pcreg_en)
  );

  // ------------------------------------
  // ICACHE
  // ------------------------------------
  localparam OFFSET_LEN = 4;
  localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
  localparam ARLEN = (2 ** OFFSET_LEN) / 4 - 1;
  wire w_valid, cache_hit;
  wire [31:0] cache_rdata;
  wire set_invalid;
  ysyx_24100007_icache icache_u (
    .clk(clk),
    .rst(rst),

    .addr(pcbridge),
    .w_valid(w_valid),
    .w_data(ifu_line_data),
    .set_invalid(set_invalid),
    .hit(cache_hit),
    .data_r(cache_rdata)
  );
  wire hit = cache_hit && (ifu_state == CHECK_CACHE) &&
             !fence_active && !fence_commit;
  assign w_valid = (ifu_state == UPDATE_CACHE) &&
                   !fence_active && !fence_commit;
  assign set_invalid = fence_commit;

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // divide it so it couldnot disrupt the synthetic
  // synopsys translate_off
  `ifdef VERILATOR
  import "DPI-C" function void host_get_ifu_start();
  import "DPI-C" function void host_get_ifu_finish();
  import "DPI-C" function void host_get_ifu_giveup();
  import "DPI-C" function void host_get_icache_miss();
  always @(posedge clk) begin
    if (!rst) begin
      if (is_jmp) begin
        host_get_ifu_giveup();   // 立即放弃当前取指流
      end else begin
        case (ifu_state)
          INIT: begin
            if (ready) begin
              host_get_ifu_start();
            end
          end

          VALID: begin
            if (ready) begin
              host_get_ifu_start();
            end
          end

          CHECK_CACHE: begin
            if (hit) begin
              host_get_ifu_finish();
            end
          end

          UPDATE_CACHE: begin
            host_get_icache_miss();
          end

          default: begin end
        endcase
      end
    end
  end
  `endif
  // synopsys translate_on

  // ------------------------------------
  // IFU STATE MACHINE
  // ------------------------------------
  always @(posedge clk) begin
    if(rst) begin
      ifu_state <= INIT;
    end else begin
      case(ifu_state) 
        INIT: begin
          if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        VALID: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else if(ready) begin
            ifu_state <= CHECK_CACHE;
          end else begin
            ifu_state <= VALID;
          end
        end

        CHECK_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else if(hit)begin
            ifu_state <= VALID;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_HANDSHAKE: begin
          if(is_jmp) begin
            if(ifu_req_acp) begin
              ifu_state <= BUS_INVALID;
            end else begin
              ifu_state <= UPDATE_PC;
            end
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else if(ifu_req_acp) begin
            ifu_state <= BUS_TRANSACTION;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_TRANSACTION: begin
          if(is_jmp) begin
            ifu_state <= BUS_INVALID;
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else if(ifu_req_finish) begin
            ifu_state <= UPDATE_CACHE;
          end else begin
            ifu_state <= BUS_TRANSACTION;
          end
        end

        UPDATE_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else begin
            ifu_state <= CHECK_CACHE;
          end
        end

        BUS_INVALID: begin
          if(is_jmp) begin
            if(ifu_req_ready & ifu_req_finish) begin
              ifu_state <= UPDATE_PC;
            end else begin
              ifu_state <= BUS_INVALID;
            end
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else if(ifu_req_ready & ifu_req_finish) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= BUS_INVALID;
          end
        end

        UPDATE_PC: begin
          if (is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if (fence_active || fence_commit) begin
            ifu_state <= FENCE_WAIT;
          end else begin
            ifu_state <= CHECK_CACHE;
          end
        end

        // Hold the front end while FENCE.I drains through WBU.  Responses
        // accepted in this state are discarded rather than installed.
        FENCE_WAIT: begin
          // A redirect from an older instruction has priority over a younger
          // fence that is still in flight.  Drain an outstanding IFU response
          // first, then use the normal redirect PC update path.
          if (is_jmp) begin
            if (ifu_req_finish && ifu_req_ready) begin
              ifu_state <= UPDATE_PC;
            end else if (fence_bus_pending) begin
              ifu_state <= BUS_INVALID;
            end else begin
              ifu_state <= UPDATE_PC;
            end
          end else if (!fence_active && !fence_commit && !fence_bus_pending) begin
            ifu_state <= CHECK_CACHE;
          end else begin
            ifu_state <= FENCE_WAIT;
          end
        end

        default: begin
          // synopsys translate_off
          $error("ifu state machine Invalid state error");
          // synopsys translate_on
          ifu_state <= INIT;
        end
      endcase
    end
  end

  assign ifu_addr     = pcbridge;
  assign ifu_read_req = (ifu_state == BUS_HANDSHAKE) &&
                        !fence_active && !fence_commit;
  assign ifu_req_ready = (ifu_state == UPDATE_CACHE) |
                         (ifu_state == BUS_INVALID) |
                         ((ifu_state == FENCE_WAIT) && fence_bus_pending);

  // ------------------------------------
  // INST UPDATE LOGIC
  // ------------------------------------
  wire icache_hit = (ifu_state == CHECK_CACHE) && hit;
  always @(posedge clk) begin
    if(rst) begin
      inst_reg <= 32'b0;
    end else begin
      if (fence_active || fence_commit) begin
        inst_reg <= 32'b0;
      end else if(icache_hit) begin
        inst_reg <= cache_rdata;
      end else if(ifu_state == VALID && ready) begin
        inst_reg <= 32'b0;
      end 
    end
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = (ifu_state == VALID) && !fence_active && !fence_commit;

  // Remember an IFU request that was already in flight when the fence blocked
  // the front end.  Its response is consumed in FENCE_WAIT but never refills
  // the cache with pre-fence data.
  always @(posedge clk) begin
    if (rst) begin
      fence_bus_pending <= 1'b0;
    end else if (ifu_req_finish && ifu_req_ready) begin
      fence_bus_pending <= 1'b0;
    end else if ((fence_active || fence_commit) &&
                 ((ifu_state == BUS_TRANSACTION) ||
                  (ifu_state == BUS_INVALID) ||
                  ((ifu_state == BUS_HANDSHAKE) && ifu_req_acp))) begin
      fence_bus_pending <= 1'b1;
    end else if (!fence_active && !fence_commit &&
                 (ifu_state != FENCE_WAIT) &&
                 (ifu_state != BUS_INVALID)) begin
      fence_bus_pending <= 1'b0;
    end
  end
endmodule
