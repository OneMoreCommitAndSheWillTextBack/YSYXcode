module ysyx_24100007_ifu(
  input clk,
  input rst,
  input [31:0] exu_npc,

  output [31:0] pc,
  output [31:0] inst,
  output valid,
  input ready,

  input icahce_flush,
  input [31:0] icahce_flush_addr,

  input is_jmp,

  // AXI-Lite interface for external SRAM
  output arvalid,          // Read address valid
  input arready,           // Read address ready
  output [31:0] araddr,    // Read address
  input rvalid,            // Read data valid
  output rready,           // Read data ready
  input [31:0] rdata,      // Read data

  output [7:0]        arlen,
  output [2:0]        arsize,
  output [1:0]        arburst,
  input  [1:0]        rresp,
  input               rlast,

  output trans_start,
  output trans_end
);

  wire [31:0] pcbridge;
  wire infetch_req = is_jmp | (ready & valid); // update pc
  wire [31:0] pc_add_4 = pc + 32'd4;
  wire [31:0] npc = (is_jmp) ? exu_npc : pc_add_4;

  // PC register module
  ysyx_24100007_pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(infetch_req)
  );

  // ------------------------------------
  // ICACHE
  // ------------------------------------
  localparam INDEX_LEN = 3;
  localparam OFFSET_LEN = 4;
  localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
  localparam ARLEN = (2 ** OFFSET_LEN) / 4 - 1;
  wire w_valid, cache_hit;
  wire [31:0] cache_rdata;
  ysyx_24100007_icache #(
    .INDEX_LEN(INDEX_LEN),
    .OFFSET_LEN(OFFSET_LEN)
  ) icache_u (
    .clk(clk),
    .rst(rst),

    .addr(pcbridge),
    .w_valid(w_valid),
    .w_data(axi_rdata),
    .hit(cache_hit),
    .data_r(cache_rdata),

    .icahce_flush(icahce_flush),
    .icahce_flush_addr(icahce_flush_addr)
  );
  wire hit = cache_hit && (ifu_state == CHECK_CACHE);
  assign w_valid = (ifu_state == UPDATE_CACHE);

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // divide it so it couldnot disrupt the synthetic
  // synopsys translate_off

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
  // synopsys translate_on

  // ------------------------------------
  // IFU STATE MACHINE
  // ------------------------------------
  typedef enum logic [2:0] {
    INIT, // the inst is not valid
    VALID, CHECK_CACHE, BUS_HANDSHAKE,
    BUS_TRANSACTION, UPDATE_CACHE,
    BUS_INVALID, UPDATE_PC
  } ifu_state_t;

  ifu_state_t ifu_state;

  always @(posedge clk) begin
    if(rst) begin
      ifu_state <= INIT;
    end else begin
      case(ifu_state) 
        INIT: begin
          // 这里 reset 是0， 那么ifu要将npc驱动起来
          ifu_state <= BUS_HANDSHAKE;
        end

        VALID: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if(ready) begin
            ifu_state <= CHECK_CACHE;
          end
        end

        CHECK_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if(hit)begin
            ifu_state <= VALID;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_HANDSHAKE: begin
          if(is_jmp) begin
            ifu_state <= BUS_INVALID;
          end else if(axi_arready) begin
            ifu_state <= BUS_TRANSACTION;
          end
        end

        BUS_TRANSACTION: begin
          if(is_jmp) begin
            ifu_state <= BUS_INVALID;
          end else if(axi_rdata_valid) begin
            ifu_state <= UPDATE_CACHE;
          end
        end

        UPDATE_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= CHECK_CACHE;
          end
        end

        BUS_INVALID: begin
          if(axi_rdata_valid &  axi_rdata_ready) begin
            ifu_state <= UPDATE_PC;
          end
        end

        UPDATE_PC: begin
          ifu_state <= CHECK_CACHE;
        end

        default: begin
          // synopsys translate_off
          $error("ifu state machine Invalid state error");
          // synopsys translate_on
        end
      endcase
    end
  end

  // ------------------------------------
  // AXI CONTEOLLER
  // ------------------------------------
  wire axi_arready, axi_arvalid;
  wire [DATABLOCK_SIZE-1:0] axi_rdata;
  wire axi_rdata_valid, axi_rdata_ready;
  ifu_axicontroller #(
    .ARLEN(ARLEN),
    .BUFFER_SIZE(DATABLOCK_SIZE)
  ) ifu_axicontroller_u (
    .clk(clk),
    .rst(rst),
    .addr(pcbridge),

    .axi_arvalid(axi_arvalid),
    .axi_arready(axi_arready),
    .axi_rdata(axi_rdata),
    .axi_rdata_valid(axi_rdata_valid),
    .axi_rdata_ready(axi_rdata_ready),

    .trans_start(trans_start),
    .trans_end(trans_end),

    .arvalid(arvalid),
    .arready(arready),
    .araddr(araddr),
    .rvalid(rvalid),
    .rready(rready),
    .rdata(rdata),

    .arlen(arlen),
    .arsize(arsize),
    .arburst(arburst),
    .rresp(rresp),
    .rlast(rlast)
  );
  assign axi_rdata_ready = (ifu_state == UPDATE_CACHE) | (ifu_state == BUS_INVALID);
  assign axi_arvalid = (ifu_state == BUS_HANDSHAKE);

  // ------------------------------------
  // INST UPDATE LOGIC
  // ------------------------------------
  reg [31:0] inst_reg;
  wire icache_hit = (ifu_state == CHECK_CACHE) && hit;
  always @(posedge clk) begin
    if(rst) begin
      inst_reg <= 32'b0;
    end else begin
      if(icache_hit) begin
        inst_reg <= cache_rdata;
      end else if(ifu_state == VALID && ready) begin
        inst_reg <= 32'b0;
      end 
    end
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = (ifu_state == VALID);
endmodule

module ifu_axicontroller#(
  parameter ARLEN,
  parameter BUFFER_SIZE
)(
  input clk,
  input rst,

  input [31:0] addr,
  input axi_arvalid,
  output axi_arready,
  
  output [BUFFER_SIZE-1:0] axi_rdata,
  output axi_rdata_valid,
  input axi_rdata_ready,

  output trans_start,
  output trans_end,
  
  // AXI-Lite interface for external SRAM
  output arvalid,          // Read address valid
  input arready,           // Read address ready
  output [31:0] araddr,    // Read address
  input rvalid,            // Read data valid
  output rready,           // Read data ready
  input [31:0] rdata,      // Read data

  output [7:0]        arlen,
  output [2:0]        arsize,
  output [1:0]        arburst,
  input  [1:0]        rresp,
  input               rlast
);
  localparam BEAT_NUM = ARLEN + 1;
  typedef enum logic[1:0]{
    READY,
    WAIT_HANDSHAKE,
    WAIT_SLAVE,
    PROCESSION
  } axi_state_t;

  axi_state_t axi_state;

  // reg [BUFFER_SIZE-1:0] data_buffer;
  reg [3:0][31:0] data_buffer;
  always @(posedge clk) begin
    if(rst) begin
      axi_state <= READY;
    end else begin
      case (axi_state)
        READY: begin
          if (axi_arvalid) begin
            axi_state <= WAIT_HANDSHAKE;
          end
        end

        WAIT_HANDSHAKE: begin
          if (arready) begin
            axi_state <= WAIT_SLAVE;
          end
        end

        WAIT_SLAVE: begin
          if (rlast) begin
            axi_state <= PROCESSION;
          end
        end

        PROCESSION: begin
          if(axi_rdata_ready) begin
            axi_state <= READY;
          end
        end

        default: begin 
          // synopsys translate_off
          $error("ifu axi state machine Invalid state error");
          // synopsys translate_on
        end
      endcase
    end
  end

  localparam [1:0]
    FIXED = 2'b00,
    INCR  = 2'b01,
    WRAP  = 2'b10,
    RESERVED = 2'b11;

  // 地址和计数跟踪
  reg [31:0] current_addr;
  reg [7:0] beat_count;
  reg [1:0] burst_type;

  wire [31:0] wrap_size = ((ARLEN + 1) << 2);
  wire [31:0] wrap_boundary = current_addr & ~(wrap_size - 1);
  wire [31:0] wrap_end = wrap_boundary + wrap_size;
  wire [31:0] buffer_index_wrap = (current_addr - wrap_boundary) >> 2;

  always @(posedge clk) begin
    if(rst) begin
      current_addr <= 32'b0;
      beat_count <= 8'b0;
      burst_type <= WRAP;
    end else begin
      if(arvalid & arready) begin
        current_addr <= araddr;
      end

      if(rvalid & rready) begin
        beat_count <= beat_count + 1;
        
        if(burst_type == WRAP) begin
            if ((current_addr + 4) >= wrap_end) begin
              current_addr <= wrap_boundary;
            end else begin
              current_addr <= current_addr + 4;
            end 
        end else if(burst_type == FIXED) begin
            current_addr <= current_addr;
        end
      end
    end
  end

  always @(posedge clk) begin
    if(axi_state == WAIT_SLAVE) begin
      case(burst_type)
          INCR: begin
            case(beat_count)
              0: data_buffer[0] <= rdata;
              1: data_buffer[1] <= rdata;
              2: data_buffer[2] <= rdata;
              3: data_buffer[3] <= rdata;
              default: begin
              end
            endcase
          end
          WRAP: begin
            case(buffer_index_wrap)
              0: data_buffer[0] <= rdata;
              1: data_buffer[1] <= rdata;
              2: data_buffer[2] <= rdata;
              3: data_buffer[3] <= rdata;
              default: begin
                data_buffer[buffer_index_wrap] <= rdata;
              end
            endcase
          end
          default: begin
          end
      endcase
    end else if(axi_state == PROCESSION) begin
      if(axi_rdata_ready) begin
        data_buffer <= {(128){1'b0}};
      end
    end
  end

  assign trans_start = (axi_state == WAIT_HANDSHAKE);
  assign trans_end = (axi_state == WAIT_SLAVE) && rlast;

  assign axi_rdata = data_buffer;

  assign axi_rdata_valid = (axi_state == PROCESSION);
  assign axi_arready = (axi_state == READY);

  assign araddr = (burst_type == INCR) ? wrap_boundary : addr;
  assign arvalid = (axi_state == WAIT_HANDSHAKE);
  assign rready = (axi_state == WAIT_SLAVE);

  assign arlen = ARLEN[7:0];
  assign arsize = 3'b010;
  assign arburst = burst_type;
endmodule
