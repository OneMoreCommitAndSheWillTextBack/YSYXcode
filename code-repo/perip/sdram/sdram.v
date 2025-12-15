module sdram(
  input        clk, // 时钟
  input        cke, // 时钟使能
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [12:0] a,  // 地址
  input [ 1:0] ba, // 储存体地址
  input [ 1:0] dqm,// 数据掩码
  inout [15:0] dq  // dq 总线接口
);

  reg [12:0] mode_q;
  reg [12:0] row_reg [0:3];

  // ------------------------------------
  // SDRAM DECODER
  // ------------------------------------

  wire command_inhibit, no_operation;
  wire active, active, read, write, burst_terminate;
  wire precharge, auto_refresh, load_mode_register;

  sdram_command_decoder decoder (
  .cs_n(cs),
  .ras_n(ras),
  .cas_n(cas),
  .we_n(we),
  .command_inhibit(command_inhibit),
  .no_operation(no_operation),
  .active(active),
  .read(read),
  .write(write),
  .burst_terminate(burst_terminate),
  .precharge(precharge),
  .auto_refresh(auto_refresh),
  .load_mode_register(load_mode_register)
  );

  wire nop = no_operation | auto_refresh;

  // ------------------------------------
  // CAS COUNTER
  // ------------------------------------
  localparam CAS_TIMER_W = 3;
  reg [CAS_TIMER_W-1:0] cas_timer_q;
  wire cas_done;
  reg counting;
  reg cas_start;
  
  always @(posedge valclk) begin
    if (cas_start) begin
      cas_timer_q <= mode_q[6:4] - 1;
      counting <= 1'b1;
    end else if (|cas_timer_q) begin  // 如果计数器不为0
      cas_timer_q <= cas_timer_q - 1'b1;
    end else begin
      counting <= 1'b0;
    end
  end

  assign cas_done = (cas_timer_q == {CAS_TIMER_W{1'b0}}) && counting;

  // ------------------------------------
  // BL COUNTER
  // ------------------------------------
  // brust length counter
  // it should be consider as a part of state
  localparam BL_TIMER_W = 3;
  reg [BL_TIMER_W-1:0] bl_timer_q;
  reg bl_valid;
  reg bl_start_q;

  wire bl_done;

  always @(posedge valclk) begin
    if (bl_start_q) begin
      bl_timer_q <= mode_q[2:0] - 1;
      bl_valid <= 1'b1;
    end else if (|bl_timer_q) begin  // 如果计数器不为0
      bl_timer_q <= bl_timer_q - 1'b1;
    end else begin
      bl_valid <= 1'b0;
    end
  end

  assign bl_done = (bl_timer_q == {BL_TIMER_W{1'b0}}) && bl_valid;

  // ------------------------------------
  // READ PIPELINE
  // ------------------------------------
  import "DPI-C" function void sdram_read(
    input int bank,
    input int row,
    input int col,
    output shortint data
  );
  localparam MAX_PIPELINE = 6;

  reg [12:0] rd_pip_in_addr_q;
  reg        rd_pip_in_val_q;

  reg [12:0] pip_addr_q [0:MAX_PIPELINE-1];
  reg        pip_valid_q[0:MAX_PIPELINE-1];

  wire [15:0] data_output;
  wire [2:0] pipeline_cl = mode_q[6:4];

  wire [15:0] sdram_data_input_i;

  wire [2:0] cl = mode_q[6:4];

  always @(posedge valclk) begin
    for (int i = MAX_PIPELINE-1; i > 0; i = i - 1) begin
      pip_valid_q[i] <= pip_valid_q[i-1];
      pip_addr_q[i]  <= pip_addr_q[i-1];
    end
  end

  wire [1:0] select_bank = pip_addr_q[cl-2][12:11];
  wire [9:0] select_col = pip_addr_q[cl-2][9:0];
  wire select_valid = pip_valid_q[cl-2];
  reg rd_data_valid_q;

  always @(negedge valclk) begin
    if(select_valid) begin
      sdram_read({30'b0, select_bank}, {19'b0, row_reg[select_bank]}, {22'b0, select_col}, sdram_data_input_i);
      rd_data_valid_q <= 1'b1;
    end else begin
      rd_data_valid_q <= 1'b0;
    end
  end

  assign data_output = (rd_data_valid_q) ? sdram_data_input_i : 16'b0;

  // ------------------------------------
  // READ DQM PIPLINE
  // ------------------------------------
  // for the read behavor, the dqm always delayed two-cycle for read inst

  reg [3:0] dqm_pipe;
  reg [1:0] rd_dqm_out_q;
  wire read_state_r = (state_current_q == STATE_READ) || (state_current_q == STATE_READ_DATA);
  always @(posedge valclk) begin
    dqm_pipe[3:2] <= dqm_pipe[1:0];
    if(read_state_r) 
      dqm_pipe[1:0] <= dqm;
    else
      dqm_pipe[1:0] <= 2'b00;
    
    rd_dqm_out_q <= dqm_pipe[3:2];
  end

  assign dq[7:0] = (rd_data_valid_q & !rd_dqm_out_q[0]) ? data_output[7:0] : 8'bz;
  assign dq[15:8] = (rd_data_valid_q & !rd_dqm_out_q[1]) ? data_output[15:8] : 8'bz;

  // ------------------------------------
  // SDRAM WRITE 
  // ------------------------------------

  // FIXME layout the sdran data one cyc by using reg
  import "DPI-C" function void sdram_write(
    input int bank,
    input int row, 
    input int col, 
    input int data,
    input int dqm_mask
  );
  wire [15:0] sdram_data = dq;
  reg [12:0]  wr_in_addr_q;
  reg         wr_in_val_q;

  always @(negedge valclk) begin
    if(wr_in_val_r)
      sdram_write({30'b0,wr_in_addr_q[12:11]}, {19'b0, row_reg[wr_in_addr_q[12:11]]}, {22'b0, wr_in_addr_q[9:0]}, {16'b0, sdram_data}, {30'b0, dqm});
  end

  // mode reg behave
  reg [12:0] mode_val_q;
  reg mode_chg_q;
  always @(posedge valclk) begin
    if(mode_chg_q) begin
      mode_q <= mode_val_q;
    end
  end

  // avctivate behave
  reg [14:0] acti_val_q;
  reg acti_chg_q;
  always @(posedge valclk) begin
    if(acti_chg_q) begin
      row_reg[acti_val_q[14:13]] <= acti_val_q[12:0];
    end
  end

  // ------------------------------------
  // SDRAM CELL STATE MECHINE
  // ------------------------------------
  // try to use the 4-always code-style

  localparam [3:0]
    STATE_INIT      = 4'b0000,  // 初始化状态
    STATE_IDLE      = 4'b0001,  // 空闲状态
    STATE_ACTIVE    = 4'b0010,  // 行激活状态
    STATE_READ      = 4'b0011,  // 读命令状态
    STATE_READ_DATA = 4'b0100,  // 读数据状态

    STATE_PRECHARGE = 4'b0101,

    STATE_WRITE     = 4'b0110,  // 写命令
    STATE_WRITE_DATA= 4'b0111,  // 写突发
    STATE_MODE_REG  = 4'b1001;  // 模式寄存器设置状态

  reg [3:0] state_current_q;
  reg [3:0] state_next_r;

  wire valclk = clk & cke;

  reg [12:0] prev_addr_q;
  wire [12:0] cur_addr_r = {ba, a[10], a[9:0]};
  wire [12:0] cur_addr_b_r = {prev_addr_q[12:10], prev_addr_q[9:0] + 1'b1};

  always @(posedge valclk) begin
    if(command_inhibit) begin
      state_current_q <= state_current_q; // 状态机冻结
    end else begin
      state_current_q <= state_next_r;
    end
  end

  always @(*) begin
    // combinatorial logic => next state
    state_next_r = 4'b1111;

    case (state_current_q) 
      STATE_INIT: begin
        if(load_mode_register) begin
          state_next_r = STATE_MODE_REG;
        end else begin
          state_next_r = STATE_INIT; // 必须设置以后才能用
        end
      end

      STATE_IDLE: begin
        if(active) begin
          state_next_r = STATE_ACTIVE;
        end else begin
          state_next_r = STATE_IDLE;
        end
      end

      STATE_ACTIVE: begin
        if(read) begin
          state_next_r = STATE_READ;
        end else if(write) begin
          state_next_r = STATE_WRITE;
        end else if(precharge) begin
          state_next_r = STATE_PRECHARGE;
        end else begin 
          state_next_r = STATE_ACTIVE;
        end
      end

      STATE_READ: begin
        state_next_r = STATE_READ_DATA; // 如果没有其他的信号，那么进入brust

        if(read)
          state_next_r = STATE_READ;
        else if(burst_terminate)
          state_next_r = STATE_ACTIVE;
      end

      STATE_READ_DATA: begin
        state_next_r = STATE_READ_DATA;

        if(read)
          state_next_r = STATE_READ;
        else if(burst_terminate)
          state_next_r = STATE_ACTIVE;
        else if(bl_done) begin
          state_next_r = STATE_ACTIVE;
          if(prev_addr_q[10] == 1'b1)
            state_next_r = STATE_PRECHARGE;
        end
      end

      STATE_WRITE: begin
        state_next_r = STATE_WRITE_DATA;

        if(write)
          state_next_r = STATE_WRITE;
        else if(burst_terminate)
          state_next_r = STATE_ACTIVE;
      end

      STATE_WRITE_DATA: begin
        state_next_r = STATE_WRITE_DATA;

        if(write)
          state_next_r = STATE_WRITE;
        else if(read)
          state_next_r = STATE_READ;
        else if(bl_done) begin
          state_next_r = STATE_ACTIVE; // M9 只会被置为零
          if(prev_addr_q[10] == 1'b1) 
            state_next_r = STATE_PRECHARGE;
        end
      end

      STATE_PRECHARGE: begin
        state_next_r = STATE_IDLE;
      end

      STATE_MODE_REG: begin
        state_next_r = STATE_IDLE;
      end

      default:
        $error("sdram state machine meet invalid state, the state is %b", state_current_q);
    endcase
  end

  reg [12:0] rd_pip_in_addr_r;
  reg        rd_pip_in_val_r;
  reg [12:0] wr_in_addr_r;
  reg        wr_in_val_r;
  reg        bl_start_r;
  reg        mode_chg_r; // mode change signal
  reg [12:0] mode_val_r;
  reg        acti_chg_r;
  reg [14:0] acti_val_r;

  always @(*) begin
    rd_pip_in_val_r = 1'b0;
    wr_in_val_r = 1'b0;
    rd_pip_in_addr_r = 13'b0;
    wr_in_addr_r = 13'b0;
    bl_start_r = 1'b0;
    mode_val_r = 13'b0;
    mode_chg_r = 1'b0;
    acti_val_r = 15'b0;
    acti_chg_r = 1'b0;

    // combinatorial logic => next state output
    case(state_current_q)
      STATE_INIT: begin
        if(load_mode_register) begin
          // INIT -> MODE_REG
          mode_val_r = a;
          mode_chg_r = 1'b1;
        end else begin
          // INIT -> INIT
          // do nothing
        end
      end

      STATE_IDLE: begin
        if(active) begin
          // IDLE -> ACTIVE
          acti_val_r = {ba, a};
          acti_chg_r = 1'b1;
        end else begin
          // IDLE -> IDLE
          // do nothing
        end
      end

      STATE_ACTIVE: begin
        if(read) begin
          // ACTIVE -> READ
          rd_pip_in_addr_r = cur_addr_r;
          bl_start_r = 1'b1;
          rd_pip_in_val_r = 1'b1;
        end else if(write) begin
          // ACTIVE -> WRITE
          wr_in_addr_r = cur_addr_r;
          wr_in_val_r = 1'b1;
          bl_start_r = 1'b1;
        end else if(active) begin
          acti_chg_r = 1'b1;
          acti_val_r = {ba, a};
        end else if(precharge) begin
          // ACTIVE -> IDLE
          // do nothing

        end
      end

      STATE_READ: begin
        // READ -> READ_DATA
        rd_pip_in_addr_r = cur_addr_b_r;
        rd_pip_in_val_r = 1'b1;

        if(read) begin
          // READ -> READ
          rd_pip_in_addr_r = cur_addr_r;
          bl_start_r = 1'b1;
        end else if(burst_terminate) begin
          // READ -> IDLE
          rd_pip_in_val_r = 1'b0;
        end
      end

      STATE_READ_DATA: begin
        // READ_DATA -> READ_DATA
        rd_pip_in_addr_r = cur_addr_b_r;
        rd_pip_in_val_r = 1'b1;

        if(read) begin
          // READ_DATA -> READ
          rd_pip_in_addr_r = cur_addr_r;
          bl_start_r = 1'b1;
        end else if(burst_terminate) begin
          // READ_DATA -> ACTIVE
          rd_pip_in_val_r = 1'b0;
        end else if(bl_done) begin
          // READ_DATA -> ACTIVE
          rd_pip_in_val_r = 1'b0;
        end
      end

      STATE_WRITE: begin
        // WRITE -> WRITE_DATA
        wr_in_addr_r = cur_addr_b_r;
        wr_in_val_r = 1'b1;

        if(write) begin
          // WRITE_DATA -> WRITE
          wr_in_addr_r = cur_addr_r;
        end else if(burst_terminate) begin
          wr_in_val_r = 1'b0;
        end
      end

      STATE_WRITE_DATA: begin
        // WRITE_DATA -> WRITE_DATA
        wr_in_addr_r = cur_addr_b_r;
        wr_in_val_r = 1'b1;

        if(write) begin
          // WRITE_DATA -> WRITE
          wr_in_addr_r = cur_addr_r;
          bl_start_r = 1'b1;
        end else if(read) begin
          // WRITE_DATA -> READ
          rd_pip_in_addr_r = cur_addr_r;
          rd_pip_in_val_r = 1'b1;
          wr_in_val_r = 1'b0;
        end else if(bl_done || burst_terminate) begin
          // WRITE_DATA -> ACTIVE
          // do nothing
        end
      end

      STATE_PRECHARGE: begin
        // PRECHARGE -> IDLE
        // no thing 
      end

      STATE_MODE_REG: begin
        // MODE_REG -> IDLE
        // no nothing
      end

      default: begin
        $error("sdram state mechine meet unvlaid state"); 
      end
    endcase
  end

  always @(posedge valclk) begin
    pip_addr_q[0] <= rd_pip_in_addr_r;
    pip_valid_q[0] <= rd_pip_in_val_r;
    wr_in_addr_q <= wr_in_addr_r;
    wr_in_val_q <= wr_in_val_r;
    bl_start_q <= bl_start_r;
    mode_val_q <= mode_val_r;
    mode_chg_q <= mode_chg_r;
    acti_val_q <= acti_val_r;
    acti_chg_q <= acti_chg_r;
  end

  wire sig_save_addr = ((state_current_q == STATE_READ) || 
                        (state_current_q == STATE_WRITE) || 
                        (state_current_q == STATE_READ_DATA) || 
                        (state_current_q == STATE_WRITE_DATA));
  always @(posedge valclk) begin
    if(read || write)
      prev_addr_q <= cur_addr_r;
    else if(sig_save_addr)
      prev_addr_q <= cur_addr_b_r;
    else 
      prev_addr_q <= {13{1'b0}};
  end

endmodule

module sdram_command_decoder(
    input wire cs_n,
    input wire ras_n,
    input wire cas_n,
    input wire we_n,
    output wire command_inhibit,
    output wire no_operation,
    output wire active,
    output wire read,
    output wire write,
    output wire burst_terminate,
    output wire precharge,
    output wire auto_refresh,
    output wire load_mode_register
);

// 简洁的三元运算符实现
assign command_inhibit = (cs_n == 1'b1) ? 1'b1 : 1'b0;
assign no_operation = (cs_n == 1'b0 && ras_n == 1'b1 && cas_n == 1'b1 && we_n == 1'b1) ? 1'b1 : 1'b0;
assign active = (cs_n == 1'b0 && ras_n == 1'b0 && cas_n == 1'b1 && we_n == 1'b1) ? 1'b1 : 1'b0;
assign read = (cs_n == 1'b0 && ras_n == 1'b1 && cas_n == 1'b0 && we_n == 1'b1) ? 1'b1 : 1'b0;
assign write = (cs_n == 1'b0 && ras_n == 1'b1 && cas_n == 1'b0 && we_n == 1'b0) ? 1'b1 : 1'b0;
assign burst_terminate = (cs_n == 1'b0 && ras_n == 1'b1 && cas_n == 1'b1 && we_n == 1'b0) ? 1'b1 : 1'b0;
assign precharge = (cs_n == 1'b0 && ras_n == 1'b0 && cas_n == 1'b1 && we_n == 1'b0) ? 1'b1 : 1'b0;
assign auto_refresh = (cs_n == 1'b0 && ras_n == 1'b0 && cas_n == 1'b0 && we_n == 1'b1) ? 1'b1 : 1'b0;
assign load_mode_register = (cs_n == 1'b0 && ras_n == 1'b0 && cas_n == 1'b0 && we_n == 1'b0) ? 1'b1 : 1'b0;

endmodule

