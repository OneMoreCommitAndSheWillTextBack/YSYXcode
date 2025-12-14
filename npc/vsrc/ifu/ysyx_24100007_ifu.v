module ysyx_24100007_ifu(
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
  wire infetch_req = (ifu_state == VALID) && ready;

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
  localparam OFFSET_LEN = 2;
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
    .w_data(inst_reg),
    .hit(cache_hit),
    .data_r(cache_rdata)
  );
  wire hit = cache_hit && (ifu_state == CHECK_CACHE);
  assign w_valid = (ifu_state == UPDATE_CACHE);

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // divide it so it couldnot disrupt the synthetic
  // synopsys translate_off
  import "DPI-C" function void host_get_valid(int valid);
  import "DPI-C" function void host_get_ifu_start();
  import "DPI-C" function void host_get_ifu_finish();
  import "DPI-C" function void host_get_icache_hit();
  always @(posedge clk) begin
    if(ready) begin
      host_get_valid(32'd1);
    end else begin
      host_get_valid(32'd0);
    end
  end

  always @(posedge clk) begin
    if (!rst) begin
      case (ifu_state)
        INIT: begin
          if(ready) begin
            host_get_ifu_start();
          end
        end

        VALID: begin
          if(ready) begin
            host_get_ifu_start();
          end
        end

        CHECK_CACHE: begin
          if(hit) begin
            host_get_ifu_finish();
            host_get_icache_hit();
          end
        end

        UPDATE_CACHE: begin
          host_get_ifu_finish();
        end

        default: begin end
      endcase
    end
  end
  // synopsys translate_on

  // ------------------------------------
  // IFU STATE MACHINE
  // ------------------------------------
  typedef enum logic [2:0] {
    INIT, // the inst is not valid
    VALID, CHECK_CACHE, BUS_HANDSHAKE,
    BUS_TRANSACTION, UPDATE_CACHE 
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
          if(ready) begin
            ifu_state <= CHECK_CACHE;
          end
        end

        CHECK_CACHE: begin
          if(hit) begin
            ifu_state <= VALID;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_HANDSHAKE: begin
          if(axi_arready) begin
            ifu_state <= BUS_TRANSACTION;
          end
        end

        BUS_TRANSACTION: begin
          if(axi_rdata_valid) begin
            ifu_state <= UPDATE_CACHE;
          end
        end

        UPDATE_CACHE: begin
          ifu_state <= VALID;
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
  wire [31:0] axi_rdata;
  wire axi_rdata_valid, axi_rdata_ready;
  ifu_axicontroller ifu_axicontroller_u(
    .clk(clk),
    .rst(rst),
    .addr(pcbridge),

    .axi_arvalid(axi_arvalid),
    .axi_arready(axi_arready),
    .axi_rdata(axi_rdata),
    .axi_rdata_valid(axi_rdata_valid),
    .axi_rdata_ready(axi_rdata_ready),

    .arvalid(arvalid),
    .arready(arready),
    .araddr(araddr),
    .rvalid(rvalid),
    .rready(rready),
    .rdata(rdata)
  );
  assign axi_rdata_ready = (ifu_state == BUS_TRANSACTION);
  assign axi_arvalid = (ifu_state == BUS_HANDSHAKE);

  // ------------------------------------
  // INST UPDATE LOGIC
  // ------------------------------------
  reg [31:0] inst_reg;
  wire icache_hit = (ifu_state == CHECK_CACHE) && hit;
  wire bus_transaction_done = (ifu_state == BUS_TRANSACTION) && axi_rdata_valid;
  always @(posedge clk) begin
    if(rst) begin
      inst_reg <= 32'b0;
    end else begin
      if(icache_hit) begin
        inst_reg <= cache_rdata;
      end else if(bus_transaction_done) begin
        inst_reg <= axi_rdata;
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

module ifu_axicontroller(
  input clk,
  input rst,

  input [31:0] addr,
  input axi_arvalid,
  output axi_arready,
  
  output [31:0] axi_rdata,
  output axi_rdata_valid,
  input axi_rdata_ready,
  
  // AXI-Lite interface for external SRAM
  output arvalid,          // Read address valid
  input arready,           // Read address ready
  output [31:0] araddr,    // Read address
  input rvalid,            // Read data valid
  output rready,           // Read data ready
  input [31:0] rdata       // Read data
);
  typedef enum logic[1:0]{
    READY,
    WAIT_HANDSHAKE,
    WAIT_SLAVE,
    PROCESSION
  } axi_state_t;

  axi_state_t axi_state;

  reg [31:0] axi_rdata_get;
  always @(posedge clk) begin
    if(rst) begin
      axi_state <= READY;
    end else begin
      case (axi_state)
        READY: begin
          if (axi_arvalid) begin
            axi_state <= WAIT_HANDSHAKE;
            axi_rdata_get <= 0;
          end
        end

        WAIT_HANDSHAKE: begin
          if (arready) begin
            axi_state <= WAIT_SLAVE;
          end
        end

        WAIT_SLAVE: begin
          if (rvalid) begin
            axi_state <= PROCESSION;
            axi_rdata_get <= rdata;
          end
        end

        PROCESSION: begin
          if(axi_rdata_ready) begin
            axi_rdata_get <= 32'b0;
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


  assign axi_rdata = axi_rdata_get;
  assign axi_rdata_valid = (axi_state == PROCESSION);
  assign axi_arready = (axi_state == READY);

  assign araddr = addr;
  assign arvalid = (axi_state == WAIT_HANDSHAKE);
  assign rready = (axi_state == WAIT_SLAVE);

endmodule
