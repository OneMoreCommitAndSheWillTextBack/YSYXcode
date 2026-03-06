module ysyx_24100007_idu(
  input clk,
  input rst,
  input [31:0] inst_in,
  input [31:0] pc_in,

  output in_ready,
  input in_valid,
  output out_valid,
  input out_ready,

  input is_jmp,

  // 寄存器堆读出的数据
  input [31:0] regout1,
  input [31:0] regout2,

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

  // 经过旁路选择后的数据
  output [31:0] src1_data,
  output [31:0] src2_data,
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output [31:0] imm,
  output [2:0] func3,
  output func7,
  output [4:0] src1_addr,
  output [4:0] src2_addr,
  output [4:0] rd,
  output memew,
  output [2:0] muxsig,
  output memer,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output regew_control,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output [11:0] csr_addr,
  output [2:0] memmask,
  output memsextsig,
  output [31:0] pc_out
);

  typedef enum logic {
    IDLE, VALID
  } idu_state_t;
  idu_state_t idu_state_r;

  wire avaliable;
  always @(posedge clk) begin
    if(rst) begin
      idu_state_r <= IDLE;
    end else begin
      case(idu_state_r) 
        IDLE: begin
          if(in_valid & in_ready & ! is_jmp) begin
            idu_state_r <= VALID;
          end
        end

        VALID: begin
          if(is_jmp) begin
            idu_state_r <= IDLE;
          end else if(out_ready & out_valid) begin
            if(in_valid) 
              idu_state_r <= VALID;
            else
              idu_state_r <= IDLE;
          end
        end
      endcase
    end
  end

  wire accept = ((idu_state_r == IDLE) || (idu_state_r == VALID && out_ready)) && in_valid;
  assign out_valid = (idu_state_r == VALID) & src_data_valid & !is_jmp;
  assign in_ready = accept; 

  wire [31:0] inst;
  wire pipline_valid;
  wire flush;
  idu_pipline_connect idu_connect(
    .clk(clk),
    .rst(rst),

    .inst_in(inst_in),
    .inst_out(inst),
    .pc_in(pc_in),
    .pc_out(pc_out),

    .avaliable(avaliable),

    .valid(pipline_valid),
    .flush(flush)
  );

  assign pipline_valid = accept & !is_jmp;
  assign flush = (idu_state_r == VALID & out_ready & !in_valid) | is_jmp;
  
  wire ebreak, ecall, mret;
  wire [2:0] func3bridge;
  wire func7bridge;
  wire [6:0] opcode;
  wire [5:0] inst_type;  // 添加type信号

  ysyx_24100007_decoder decoder0(
    .inst(inst),
    .ebreaksig(ebreak),
    .mretsig(mret),
    .ecallsig(ecall),
    .imm(imm),
    .src1(src1_addr),
    .src2(src2_addr),
    .rd(rd),
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .inst_type(inst_type)  // 从decoder获取type
  );

  ysyx_24100007_control_unit control_unit0(
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .ebreaksig(ebreak),
    .ecallsig(ecall),
    .mretsig(mret),
    .inst_type(inst_type),  // 传递type给control_unit

    .memew(memew),
    .muxsig(muxsig),
    .memer(memer),
    .regew(regew_control),
    .muximm(muximm),
    .btypebranch(btypebranch),
    .jalrsig(jalrsig),
    .jalsig(jalsig),
    .aluop(aluop),
    .auipcsig(auipcsig),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .memmask(memmask),     
    .memsextsig(memsextsig)
  );

  assign ecallsig = ecall;
  assign mretsig = mret;
  assign ebreaksig = ebreak;
  assign func7 = func7bridge;
  assign func3 = func3bridge;
  assign csr_addr = inst[31:20];  // Extract CSR address from instruction

  wire src_data_valid;

  ysyx_24100007_transmit transmit0(
    .clk(clk),
    .rst(rst),
    .src1_addr_in(src1_addr),
    .src2_addr_in(src2_addr),
    .exu_rd(exu_rd),
    .wbu_rd(wbu_rd),
    .exu_res_valid(exu_transmit_data_valid),
    .exu_regew(exu_regew),
    .wbu_res_valid(wbu_transmit_data_valid),
    .wbu_regew(wbu_regew),
    .exu_memer_bypass(exu_memer_bypass),  // EXU 是否是 load 指令
    .regout1_in(regout1),
    .regout2_in(regout2),
    .exu_transmit_data(exu_transmit_data),
    .wbu_transmit_data(wbu_transmit_data),
    .src1(src1_data),
    .src2(src2_data),
    .valid(src_data_valid)
  );
  
  // synopsys translate_off
  import "DPI-C" function void get_idu_state(int state);
  always @(posedge clk) begin 
    get_idu_state({31'b0, idu_state_r == VALID});
  end
  // synopsys translate_on
endmodule

module idu_pipline_connect(
  input clk,
  input rst,

  input [31:0] inst_in,
  output [31:0] inst_out,
  input [31:0] pc_in,
  output [31:0] pc_out,

  output avaliable,

  input valid,
  input flush // 插入一个nop
);
  reg avaliable_r;
  always @(posedge clk) begin
    if(rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if(valid) begin
        avaliable_r <= 1'b1;
      end else if(flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  reg [31:0] inst_r;
  reg [31:0] pc_r;

  // 只在 valid 时更新，去掉 flush 清零，依靠 avaliable 指示有效性以节省面积
  always @(posedge clk) begin
    if(valid) begin
      inst_r <= inst_in;
      pc_r <= pc_in;
    end
  end

  assign inst_out = inst_r;
  assign pc_out = pc_r;

endmodule
