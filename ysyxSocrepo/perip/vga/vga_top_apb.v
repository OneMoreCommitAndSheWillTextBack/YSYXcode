module vga_top_apb(
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

  output [7:0]  vga_r,
  output [7:0]  vga_g,
  output [7:0]  vga_b,
  output        vga_hsync,
  output        vga_vsync,
  output        vga_valid
);
  typedef enum logic [1:0] {
    ST_IDLE, ST_WAIT_ACCEPT, ST_WAIT_ACK
  } state_t;

  reg [1:0] state;

  wire req_accept;
  always @(posedge clock) begin
    if(reset) begin
      state <= ST_IDLE;
    end else begin
      case(state) 
        ST_IDLE: state <= (is_write ? (req_accept ? ST_WAIT_ACK : ST_WAIT_ACCEPT) : ST_IDLE);
        ST_WAIT_ACCEPT: state <= req_accept ? ST_WAIT_ACK : ST_WAIT_ACCEPT;
        ST_WAIT_ACK: if (in_pready) state <= ST_IDLE;
        default: state <= state;
      endcase
    end
  end

  wire is_write = ((in_psel && !in_penable) || (state == ST_WAIT_ACCEPT)) && in_pwrite;
  wire req_accept = is_write;

  vga_core vga_core_inst (
    .clk_i(clock),
    .rst_i(reset),
    .inport_rd_i(1'b0), // read not supported
    .inport_wr_i(in_pstrb&{4{is_write}}),
    .inport_addr_i(in_paddr),
    .inport_write_data_i(in_pwdata),
    .inport_len_i(1'b0),
    .inport_ack_o(in_pready),

    .vga_r(vga_r),
    .vga_g(vga_g),
    .vga_b(vga_b),
    .vga_hsync(vga_hsync),
    .vga_vsync(vga_vsync),
    .vga_valid(vga_valid)
  );


endmodule

module vgd_mem (
  input clk_i,
  input rst_i,
  input [31:0] w_addr_i,
  input [31:0] r_addr_i,
  input [3:0] strb_i,
  input is_read,
  input [31:0] data_i,
  output [23:0] vga_data,
  output ack
);
  reg [23:0] vga_mem [524287:0];

  // ------------------------------------
  // WRITE LOGIC
  // ------------------------------------
  wire [9:0] w_h_addr = w_addr_i[11:2];
  wire [8:0] w_v_addr = w_addr_i[20:12];
  wire write_enable = (strb_i != 4'b0);
  always @(posedge clk_i) begin
    if(rst_i) begin
      vga_mem[{w_h_addr, w_v_addr}] <= 0;
    end else if(write_enable) begin
      if(strb_i[0]) vga_mem[{w_h_addr, w_v_addr}][7:0] <= data_i[7:0];
      if(strb_i[1]) vga_mem[{w_h_addr, w_v_addr}][15:8] <= data_i[15:8];
      if(strb_i[2]) vga_mem[{w_h_addr, w_v_addr}][23:16] <= data_i[23:16];
    end
  end

  // ------------------------------------
  // READ LOGIC
  // ------------------------------------
  wire [9:0] r_h_addr = r_addr_i[11:2];
  wire [8:0] r_v_addr = r_addr_i[20:12];

  assign vga_data = vga_mem[{r_h_addr, r_v_addr}];

  // ACK生成 -- 读不需要确认
  reg ack_o;
  always @(posedge clk_i or posedge rst_i) begin
    if (rst_i) begin
      ack_o <= 1'b0;
    end else begin
      ack_o <= (|strb_i);
    end
  end

  assign ack = ack_o;

endmodule

module vga_core (
  input clk_i,
  input rst_i,
  input inport_rd_i,
  input [3:0] inport_wr_i,
  input [31:0] inport_addr_i,
  input [31:0] inport_write_data_i,
  input inport_len_i,
  output inport_ack_o,

  output [7:0] vga_r,
  output [7:0] vga_g,
  output [7:0] vga_b,
  output vga_hsync,
  output vga_vsync,
  output vga_valid
);

  localparam h_frontporch = 96;
  localparam h_active = 144;
  localparam h_backporch = 784;
  localparam h_total = 800;

  localparam v_frontporch = 2;
  localparam v_active = 35;
  localparam v_backporch = 515;
  localparam v_total = 525;

  reg [9:0] x_cnt;
  reg [9:0] y_cnt;

  always @(posedge clk_i) begin
    if(rst_i) begin
      x_cnt <= 1;
      y_cnt <= 1;
    end else begin
      if(x_cnt == h_total) begin
        x_cnt <= 1;
        if(y_cnt == v_total) 
          y_cnt <= 1;
        else 
          y_cnt <= y_cnt + 1;
      end else begin
        x_cnt <= x_cnt + 1;
      end
    end
  end

  wire h_valid = (x_cnt >= h_frontporch && x_cnt < h_active);
  wire v_valid = (y_cnt >= v_frontporch && y_cnt < v_active);
  assign vga_valid = h_valid & v_valid;
  wire [9:0] h_addr = h_valid ? (x_cnt - 10'd145) : 10'd0;
  wire [9:0] v_addr = v_valid ? (y_cnt - 10'd36) : 10'd0;
  assign vga_hsync = (x_cnt > h_frontporch);
  assign vga_vsync = (y_cnt > v_frontporch);
  
  wire [31:0] r_addr_i = {12'd0, v_addr, h_addr};


  wire [23:0] vga_data;
  vgd_mem vgd_mem_inst (
    .clk_i(clk_i),
    .rst_i(rst_i),
    .w_addr_i(inport_addr_i),
    .r_addr_i(r_addr_i),
    .strb_i(inport_wr_i),
    .is_read(inport_rd_i),
    .data_i(inport_write_data_i),
    .vga_data(vga_data),
    .ack(inport_ack_o)
  );

  assign vga_r = vga_data[7:0];
  assign vga_g = vga_data[15:8];
  assign vga_b = vga_data[23:16];

endmodule
