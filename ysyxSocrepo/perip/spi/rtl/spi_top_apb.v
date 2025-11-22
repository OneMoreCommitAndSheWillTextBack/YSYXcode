// define this macro to enable fast behavior simulation
// for flash by skipping SPI transfers
// `define FAST_FLASH

module spi_top_apb #(
  parameter flash_addr_start = 32'h30000000,
  parameter flash_addr_end   = 32'h3fffffff,
  parameter spi_ss_num       = 8
) (
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  output                  spi_sck,
  output [spi_ss_num-1:0] spi_ss,
  output                  spi_mosi,
  input                   spi_miso,
  output                  spi_irq_out
);

`ifdef FAST_FLASH

wire [31:0] data;
parameter invalid_cmd = 8'h0;
flash_cmd flash_cmd_i(
  .clock(clock),
  .valid(in_psel && !in_penable),
  .cmd(in_pwrite ? invalid_cmd : 8'h03),
  .addr({8'b0, in_paddr[23:2], 2'b0}),
  .data(data)
);
assign spi_sck    = 1'b0;
assign spi_ss     = 8'b0;
assign spi_mosi   = 1'b1;
assign spi_irq_out= 1'b0;
assign in_pslverr = 1'b0;
assign in_pready  = in_penable && in_psel && !in_pwrite;
assign in_prdata  = data[31:0];

`else

typedef enum logic [2:0] {
  NON_XIP_,
  WRITE_TX_,
  WRITE_SS_,
  WRITE_DIVIDER_,
  WRITE_CTRL_,
  POLLING_,
  READ_DATA_,
  RESET
} state_t;

reg [2:0] state;
reg penable;

wire is_xip_access = (in_paddr >= 32'h3000_0000) && 
                     (in_paddr <= 32'h3fff_ffff);
// wire is_spi_reg_access = (in_paddr >= 32'h1000_1000) && 
//                          (in_paddr <= 32'h1000_1fff);

wire [4:0] xip_paddr;
wire [31:0] xip_pwdata;
wire [3:0] xip_pstrb;
wire xip_pwirte;
always @(posedge clock) begin
  if (reset) begin
    state <= NON_XIP_;
    penable <= 0;
  end else begin
      case(state)
        NON_XIP_: begin
          if(in_psel && is_xip_access) begin
            state <= WRITE_TX_;
            penable <= 0;
          end
        end
        
        WRITE_TX_: begin
          if(apb_pready) begin
            state <= WRITE_SS_;
            penable <= 0;
          end
        end

        WRITE_SS_: begin
          if(apb_pready) begin
            state <= WRITE_DIVIDER_;
            penable <= 0;
          end
        end

        WRITE_DIVIDER_: begin
          if(apb_pready) begin
            state <= WRITE_CTRL_;
            penable <= 0;
          end
        end

        WRITE_CTRL_: begin
          if(apb_pready) begin
            state <= POLLING_;
            penable <= 0;
          end
        end

        POLLING_: begin
          if(in_prdata[8] == 0 && apb_pready) begin
            state <= READ_DATA_;
            penable <= 0;
          end
        end

        READ_DATA_: begin
          if(apb_pready) begin
            state <= RESET;
            penable <= 0;
          end
        end
        
        RESET: begin
          if(apb_pready) begin
            if(in_psel & is_xip_access)
              state <= WRITE_TX_;
            else
              state <= NON_XIP_;
          end
        end
      endcase
    end
  end

// when the data is ready ,we should tell the 
// subpart the data is ready, and when the subpart
// tells you that he is finished(in_pready is high),
// you should change it to zero
always @(posedge clock) begin
  if(state != NON_XIP_)
    penable <= 1;
end

always @(posedge clock) begin
  if(in_pwrite && is_xip_access) 
    $stop();
end

assign xip_paddr = (state == WRITE_TX_) ? 5'b00100 :
                   (state == WRITE_SS_) ? 5'b11000 :
                   (state == WRITE_CTRL_) ? 5'b10000 :
                   (state == WRITE_DIVIDER_) ? 5'b10100 :
                   (state == POLLING_) ? 5'b10000 :
                   (state == RESET) ? 5'b11000 :
                   5'b00000;

assign in_pready = (state == NON_XIP_) ? apb_pready :
                   (state == READ_DATA_) ? apb_pready :
                   0;

assign in_prdata = (state == READ_DATA_) ? {apb_prdata[7:0], apb_prdata[15:8],
                                            apb_prdata[23:16], apb_prdata[31:24]} :
                    apb_prdata;

assign xip_pwdata = (state == WRITE_TX_) ? {8'h03, in_paddr[23:0]} :
                    (state == WRITE_SS_) ? 32'h00000001 :
                    (state == WRITE_CTRL_) ? 32'h0000140 :
                    (state == WRITE_DIVIDER_) ? 1 :
                    (state == RESET) ? 32'h00000000 :
                    in_pwdata;

assign xip_pstrb = (state == WRITE_TX_) ? 4'hf :
                   (state == WRITE_SS_) ? 4'hf :
                   (state == WRITE_CTRL_) ? 4'hf :
                   (state == WRITE_DIVIDER_) ? 4'hf :
                   (state == RESET) ? 4'hf :
                   in_pstrb;

assign xip_pwirte = (state == WRITE_TX_) ? 1 :
                    (state == WRITE_SS_) ? 1 :
                    (state == WRITE_CTRL_) ? 1 :
                    (state == WRITE_DIVIDER_) ? 1 :
                    (state == RESET) ? 1 :
                    0;

wire apb_pready;
wire [4:0] apb_addr = (state == NON_XIP_) ? in_paddr[4:0] :
                      xip_paddr;
wire [31:0] apb_pwdata = (state == NON_XIP_) ? in_pwdata :
                      xip_pwdata;
wire [3:0] apb_pstrb = xip_pstrb;
wire apb_penable = (state == NON_XIP_) ? in_penable :
                   penable;
wire apb_psel = in_psel;
wire apb_pwrite = (state == NON_XIP_) ? in_pwrite : xip_pwirte;
wire [31:0] apb_prdata;

spi_top u0_spi_top (
  .wb_clk_i(clock),
  .wb_rst_i(reset),
  .wb_adr_i(apb_addr),
  .wb_dat_i(apb_pwdata),
  .wb_dat_o(apb_prdata),
  .wb_sel_i(apb_pstrb),
  .wb_we_i (apb_pwrite),
  .wb_stb_i(apb_psel),
  .wb_cyc_i(apb_penable),
  .wb_ack_o(apb_pready),
  .wb_err_o(in_pslverr),
  .wb_int_o(spi_irq_out),

  .ss_pad_o(spi_ss),
  .sclk_pad_o(spi_sck),
  .mosi_pad_o(spi_mosi),
  .miso_pad_i(spi_miso)
);

`endif // FAST_FLASH

endmodule
