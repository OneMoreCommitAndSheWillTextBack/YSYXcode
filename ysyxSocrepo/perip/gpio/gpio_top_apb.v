module gpio_top_apb(
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

  output [15:0] gpio_out,
  input  [15:0] gpio_in,
  output [7:0]  gpio_seg_0,
  output [7:0]  gpio_seg_1,
  output [7:0]  gpio_seg_2,
  output [7:0]  gpio_seg_3,
  output [7:0]  gpio_seg_4,
  output [7:0]  gpio_seg_5,
  output [7:0]  gpio_seg_6,
  output [7:0]  gpio_seg_7
);

  typedef enum [1:0] { ST_IDLE, ST_WAIT_ACCEPT, ST_WAIT_ACK } state_t;
  reg [1:0] state;

  always @(posedge clock) begin
    if(reset) begin
      state <= ST_IDLE;
    end else begin
      // the state change logic
     case (state)
        ST_IDLE: state <= (is_read || is_write ? (req_accept ? ST_WAIT_ACK : ST_WAIT_ACCEPT) : ST_IDLE);
        ST_WAIT_ACCEPT: state <= req_accept ? ST_WAIT_ACK : ST_WAIT_ACCEPT;
        ST_WAIT_ACK: if (in_pready) state <= ST_IDLE;
        default: state <= state;
      endcase
    end
  end

  wire is_read  = ((in_psel && !in_penable) || (state == ST_WAIT_ACCEPT)) && !in_pwrite;
  wire is_write = ((in_psel && !in_penable) || (state == ST_WAIT_ACCEPT)) &&  in_pwrite;

  wire [31:0] segment_reg_q;
  wire req_accept;

  gpio_axi_core gpio_urt_core (
  .clk_i(clock),
  .rst_i(reset),
  
  // APB 接口信号
  .inport_rd_i(is_read),
  .inport_wr_i(in_pstrb&{4{is_write}}),
  .inport_addr_i(in_paddr),
  .inport_write_data_i(in_pwdata),
  .inport_len_i(1'b0),     // 根据您的设计需要设置
  .inport_penable(in_penable),
  
  // 输出响应
  .inport_ack_o(in_pready),
  .inport_accept_o(req_accept),  // 需要在顶层定义这个信号
  .gpio_rdata_o(in_prdata),      // 连接到 APB 读数据
  
  // GPIO 输出
  .gpio_out_o(gpio_out),
  .gpio_in_o(gpio_in),
  .gpio_led_o(segment_reg_q)    
  );

  function automatic [7:0] digit_to_segments;
    input [3:0] digit;
    begin
      case (digit)
        4'h0: digit_to_segments = 8'b00000001; // 0
        4'h1: digit_to_segments = 8'b01001111; // 1
        4'h2: digit_to_segments = 8'b00010010; // 2
        4'h3: digit_to_segments = 8'b00000110; // 3
        4'h4: digit_to_segments = 8'b01001100; // 4
        4'h5: digit_to_segments = 8'b00100100; // 5
        4'h6: digit_to_segments = 8'b00100000; // 6
        4'h7: digit_to_segments = 8'b00001111; // 7
        4'h8: digit_to_segments = 8'b01111111; // 8
        4'h9: digit_to_segments = 8'b00000100; // 9
        4'hA: digit_to_segments = 8'b00001000; // A
        4'hB: digit_to_segments = 8'b01100000; // b
        4'hC: digit_to_segments = 8'b00110001; // C
        4'hD: digit_to_segments = 8'b01000010; // d
        4'hE: digit_to_segments = 8'b00110000; // E
        4'hF: digit_to_segments = 8'b00111000; // F
        default: digit_to_segments = 8'b00111111;
      endcase
    end
  endfunction

  assign gpio_seg_0 = digit_to_segments(segment_reg_q[3:0]);
  assign gpio_seg_1 = digit_to_segments(segment_reg_q[7:4]);
  assign gpio_seg_2 = digit_to_segments(segment_reg_q[11:8]);
  assign gpio_seg_3 = digit_to_segments(segment_reg_q[15:12]);
  assign gpio_seg_4 = digit_to_segments(segment_reg_q[19:16]);
  assign gpio_seg_5 = digit_to_segments(segment_reg_q[23:20]);
  assign gpio_seg_6 = digit_to_segments(segment_reg_q[27:24]);
  assign gpio_seg_7 = digit_to_segments(segment_reg_q[31:28]);

endmodule

module gpio_axi_core(
  input clk_i,
  input rst_i,
  input inport_rd_i,
  input [3:0] inport_wr_i,
  input [31:0] inport_addr_i,
  input [31:0] inport_write_data_i,
  input inport_len_i,
  input inport_penable,

  output inport_accept_o,
  output [31:0] gpio_rdata_o,
  output inport_ack_o,

  output [15:0] gpio_out_o,
  input  [15:0] gpio_in_o,
  output [31:0] gpio_led_o
);

  wire read  = inport_rd_i;
  wire write = (inport_wr_i != 4'b0);

  // 地址解码
  wire addr_led     = (inport_addr_i[3:0] == 4'h0);  // LED 寄存器
  wire addr_switch  = (inport_addr_i[3:0] == 4'h4);  // 开关输入寄存器  
  wire addr_segment = (inport_addr_i[3:0] == 4'h8);  // 数码管寄存器
  wire addr_reserved= (inport_addr_i[3:0] == 4'hc);  // 保留地址

  // 字节使能解码
  wire [3:0] byte_enable = inport_wr_i;

  // -------------------------
  // GLOBAL REGISTER
  // -------------------------
  reg [15:0] gpio_out_light_q;
  reg [15:0] gpio_int_sw_q;
  reg [31:0] gpio_out_num;

  assign gpio_out_o = gpio_out_light_q;
  
  // 开关存储状态更新逻辑
  always @(posedge clk_i) begin
    if(rst_i) begin
      gpio_int_sw_q <= 16'b0;
    end else begin
      gpio_int_sw_q <= gpio_in_o;
    end
  end

  // -------------------------
  // STATE MACHINE
  // -------------------------

  typedef enum [1:0] {ST_IDLE, ST_READ, ST_WRITE} state;
  reg [1:0] state_current_q;
  reg [1:0] state_next_r;

  always @(posedge clk_i) begin
    if(rst_i) begin
      state_current_q <= ST_IDLE;
    end else begin 
      state_current_q <= state_next_r;
    end
  end

  always @(*) begin
    state_next_r = 2'b00;
    case(state_current_q) 
      ST_IDLE: begin
        if(read) begin
          state_next_r = ST_READ;
        end else if(write) begin
          state_next_r = ST_WRITE;
        end
      end

      ST_WRITE: begin
        if(write)
          state_next_r = ST_READ;
        else
          state_next_r = ST_IDLE;
      end

      ST_READ: begin
        if(read)
          state_next_r = ST_READ;
        else
          state_next_r = ST_IDLE;
      end

      default:
        $error("invalid state gpio_top_apb");
    endcase
  end

  reg write_enable_r;
  reg idle_ack_r;
  always @(*) begin
    // next state output logic
    write_enable_r = 1'b0;
    idle_ack_r = 1'b0;

    case(state_current_q)
      ST_IDLE: begin
        if(read) begin
          // do nothing
        end else if(write) begin
          write_enable_r = 1'b1;
        end
      end

      ST_WRITE: begin
        if(write) begin
          // do nothing 
        end else begin
          // high pready
          idle_ack_r = 1'b1;
        end
      end

      ST_READ: begin
        if(read) begin
          // do nothing 
        end else begin
          // high pready
          idle_ack_r = 1'b1;
        end
      end

      default:
        $error("invalid state gpio_top_apb");
    endcase
  end

  reg write_enable_q;
  reg accept_o;
  always @(posedge clk_i) begin
    write_enable_q <= write_enable_r;
    if(state_current_q == ST_READ || state_current_q == ST_WRITE)
      accept_o <= 1'b1;
    else 
      accept_o <= 1'b0;
  end

  assign inport_accept_o = accept_o;

  reg ack_q;
  reg idle_ack_q;
  always @(posedge clk_i) begin
    idle_ack_q <= idle_ack_r;
  end

  assign inport_ack_o = idle_ack_q;

  // -------------------------
  // WRITE LOGIC
  // -------------------------
  wire write_enable = write_enable_q;

  // LED 寄存器写逻辑 (16位 @ 0x0)
  always @(posedge clk_i) begin
    if (rst_i) begin
      gpio_out_light_q <= 16'b0;
    end else if (write_enable && addr_led) begin
      // 根据字节使能更新相应字节
      if (byte_enable[0]) gpio_out_light_q[7:0]  <= inport_write_data_i[7:0];
      if (byte_enable[1]) gpio_out_light_q[15:8] <= inport_write_data_i[15:8];
    end
  end

  // 数码管寄存器写逻辑 (32位 @ 0x8)
  reg [31:0] segment_reg_q;

  always @(posedge clk_i) begin
    if (rst_i) begin
      segment_reg_q <= 32'b0;
    end else if (write_enable && addr_segment) begin
      // 32位寄存器，支持任意字节组合写入
      if (byte_enable[0]) segment_reg_q[7:0]   <= inport_write_data_i[7:0];
      if (byte_enable[1]) segment_reg_q[15:8]  <= inport_write_data_i[15:8];
      if (byte_enable[2]) segment_reg_q[23:16] <= inport_write_data_i[23:16];
      if (byte_enable[3]) segment_reg_q[31:24] <= inport_write_data_i[31:24];
    end
  end

  assign gpio_led_o = segment_reg_q;

  // -------------------------
  // READ LOGIC
  // -------------------------
  reg [31:0] read_data_r;

  always @(*) begin
    read_data_r = 32'b0;
    case (inport_addr_i[3:0])
      4'h0: read_data_r = {16'b0, gpio_out_light_q};        // LED 状态
      4'h4: read_data_r = {16'b0, gpio_in_o};               // 开关输入
      4'h8: read_data_r = segment_reg_q;                    // 数码管寄存器
      4'hc: read_data_r = 32'b0;                            // 保留地址
      default: read_data_r = 32'b0;
    endcase
  end

  assign gpio_rdata_o = read_data_r;

endmodule
