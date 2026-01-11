module ysyx_24100007_transmit(
    input clk,
    input rst,

    input [4:0] src1_addr_in,
    input [4:0] src2_addr_in,
    input [4:0] exu_rd,
    input [4:0] wbu_rd,

    input exu_res_valid,
    input exu_regew,
    input wbu_res_valid,
    input wbu_regew,
    input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

    input [31:0] regout1_in,
    input [31:0] regout2_in,
    input [31:0] exu_transmit_data,
    input [31:0] wbu_transmit_data,

    output [31:0] src1,
    output [31:0] src2,
    output valid
);  
  wire src1_valid, src2_valid;

  // 实例化两次旁路选择模块，分别用于 src1 和 src2
  ysyx_24100007_bypass_sel bypass_src1 (
    .clk(clk),
    .rst(rst),
    .src_addr_in           (src1_addr_in),
    .reg_data_in           (regout1_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src1),
    .src_valid             (src1_valid)
  );

  ysyx_24100007_bypass_sel bypass_src2 (
    .clk(clk),
    .rst(rst),
    .src_addr_in           (src2_addr_in),
    .reg_data_in           (regout2_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src2),
    .src_valid             (src2_valid)
  );

  // 整体有效信号：两个源都有效时才有效
  assign valid = src1_valid && src2_valid;
endmodule

module ysyx_24100007_bypass_sel(
  input clk,
  input rst,
  input [4:0] src_addr_in,          // 源寄存器地址（src1 或 src2）
  input [31:0] reg_data_in,          // 从寄存器堆读出的数据

  // WBU 旁路接口
  input [4:0] wbu_rd,
  input wbu_regew,
  input [31:0] wbu_transmit_data,
  input wbu_transmit_data_valid,

  // EXU 旁路接口
  input [4:0] exu_rd,
  input exu_regew,
  input [31:0] exu_transmit_data,
  input exu_transmit_data_valid,
  input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

  output [31:0] src_data_out,        // 选择后的数据
  output src_valid                   // 数据有效信号
);

  // 首先检查是否需要转发：比较 src_addr 和两个 rd
  // 注意：需要检查 rd 是否为 0（x0 寄存器不需要转发）
  // 优先级：EXU > WBU（EXU是上一级指令，更接近当前指令）
  wire need_exu_forward = (src_addr_in != 5'b0) && (src_addr_in == exu_rd) && exu_regew;
  wire need_wbu_forward = (src_addr_in != 5'b0) && (src_addr_in == wbu_rd) && wbu_regew && !need_exu_forward;

  // 检测 load-use 冲突：需要从 EXU 转发，但 EXU 是 load 指令
  // load 指令的结果需要等到 WBU 阶段才能获得
  wire load_use_hazard_detect = need_exu_forward && exu_memer_bypass;

  // 时序逻辑：锁存 load-use 冲突等待状态
  reg load_use_wait;

  always @(posedge clk) begin
    if(rst) begin
      load_use_wait <= 1'b0;
    end else begin
      if(load_use_hazard_detect) begin
        // 检测到 load-use 冲突，设置等待标志
        load_use_wait <= 1'b1;
      end else if(match_wbu_load_use) begin
        // WBU 数据有效且匹配当前 src_addr，清除等待状态
        load_use_wait <= 1'b0;
      end
    end
  end

  // 判断匹配（需要转发且数据有效）
  wire match_exu = need_exu_forward && exu_transmit_data_valid;
  wire match_wbu = need_wbu_forward && wbu_transmit_data_valid;
  wire match_wbu_load_use = load_use_wait && wbu_transmit_data_valid && (wbu_rd == src_addr_in);

  // 当前数据选择：优先级 EXU > WBU > 寄存器堆
  wire [31:0] src_data_raw = match_exu ? exu_transmit_data :
                             match_wbu_load_use ? wbu_transmit_data :
                             match_wbu ? wbu_transmit_data :
                             reg_data_in;

  // 当前有效信号：
  // - 如果正在等待 load-use 冲突解决，则无效（阻塞）
  // - 如果需要 EXU 转发但数据无效或 EXU 是 load 指令，则无效
  // - 如果需要 WBU 转发但数据无效，则无效
  // - 如果不需要转发（使用寄存器堆），则直接有效
  wire src_valid_raw = load_use_wait ? 1'b0 :  // 正在等待 load-use 冲突，阻塞
                       need_exu_forward && !exu_memer_bypass ? exu_transmit_data_valid :
                       need_wbu_forward ? wbu_transmit_data_valid :
                       1'b1;

  // 寄存器锁存数据，处理依赖两条指令的情况
  // 当数据有效时锁存，当数据无效时使用锁存的数据（如果地址匹配）
  reg [4:0] src_addr_reg;
  reg [31:0] src_data_reg;
  reg src_reg_valid;

  always @(posedge clk) begin
    if(rst) begin
      src_addr_reg <= 5'b0;
      src_data_reg <= 32'b0;
      src_reg_valid <= 1'b0;
    end else begin
      if(src_valid_raw && !load_use_wait) begin
        // 数据有效且不在等待 load-use 冲突，更新锁存
        src_data_reg <= src_data_raw;
        src_addr_reg <= src_addr_in;
        src_reg_valid <= 1'b1;
      end else if(src_addr_in != src_addr_reg) begin
        // 地址改变且数据无效，清除锁存
        src_reg_valid <= 1'b0;
      end
    end
  end

  // 输出：如果当前数据有效，使用当前数据；否则如果锁存数据有效且地址匹配，使用锁存数据
  assign src_data_out = src_valid_raw ? src_data_raw : 
                        (src_reg_valid && (src_addr_in == src_addr_reg)) ? src_data_reg : src_data_raw;

  // 有效信号：当前数据有效，或者锁存数据有效且地址匹配
  // 注意：如果正在等待 load-use 冲突，则无效（阻塞）
  assign src_valid = load_use_wait ? 1'b0 :
                     src_valid_raw || (src_reg_valid && (src_addr_in == src_addr_reg));

endmodule