module ysyx_24100007_exu(
  input clk,
  input rst,

  input in_valid,
  output in_ready,
  input out_ready,
  output out_valid,

  // need sig
  input [2:0] func3_in,
  input btypebranch_in,
  input func7_in,
  input [1:0] aluop_in,
  input jalrsig_in,
  input jalsig_in,
  input [31:0] imm_in,
  input muximm_in,
  input [31:0] pc_in,
  input auipcsig_in,
  input mretsig_in,
  input ecallsig_in,
  input [31:0] mtvec_in,
  input [31:0] mepc_in,

  // pass sig
  input memew_in,               
  input memer_in,              
  input [2:0] muxsig_in,        
  input regew_control_in,
  input [4:0] rd_in,
  input csrrw_in,
  input csrrs_in,
  input [11:0] csr_addr_in,
  input wbu_write_csr, 
  
  input [31:0] src1_in,
  input [31:0] src2_in,

  output [31:0] res,
  output [31:0] npc,
  output [31:0] link_addr,   // PC value to write to register (for JAL/JALR)
  output [31:0] src2_out,    // src2 output to WBU
  output [31:0] imm_out,     // imm output to WBU

  output memew_out,              
  output memer_out,              
  output [2:0] muxsig_out,        
  output [2:0] func3_out,        
  output regew_control_out,   
  output [4:0] rd_out,
  output csrrw_out,
  output csrrs_out,
  output [11:0] csr_addr_out,
  output ecallsig_out,

  output is_jmp, // tell ifu flush the pipline

  // EXU 向 IDU 转发的旁路信号
  output [4:0] exu_rd,                // EXU 阶段的 rd（用于旁路）
  output exu_regew,                   // EXU 阶段的写使能（用于旁路）
  output [31:0] exu_transmit_data,    // EXU 阶段的计算结果（用于旁路）
  output exu_transmit_data_valid,     // EXU 阶段的旁路数据有效信号
  output exu_memer_bypass             // EXU 阶段是否是 load 指令（用于处理 load-use 冲突）
); 

  typedef enum logic{
    IDLE, VALID
  } exu_state_t;
  exu_state_t exu_state_r;

  wire exu_wbu_handshake = exu_valid_sig & out_ready;
  wire avaliable;
  always @(posedge clk) begin
    if(rst) begin
      exu_state_r <= IDLE;
    end else begin
      case(exu_state_r)
        IDLE: begin
          if(in_valid & in_ready) begin
            exu_state_r <= VALID;
          end 
        end

        VALID: begin
          if(exu_wbu_handshake) begin
            if(in_valid)
              exu_state_r <= VALID;
            else 
              exu_state_r <= IDLE;
          end
        end
      endcase
    end
  end 

  wire exu_valid_sig = (exu_state_r == VALID) & !exu_csr_delay;
  wire accept = ((exu_state_r == IDLE) || exu_wbu_handshake) && in_valid;
  wire idu_valid = in_valid & !is_jmp;

  assign out_valid = exu_valid_sig;
  assign in_ready = accept;
  
  wire pipline_valid = accept & !(exu_state_r == VALID & is_jmp);
  wire flush = (exu_wbu_handshake & !idu_valid);

  // Pipeline connect: 流水线寄存器
  wire [2:0] func3;
  wire btypebranch;
  wire func7;
  wire [1:0] aluop;
  wire jalrsig;
  wire jalsig;
  wire [31:0] imm;
  wire muximm;
  wire [31:0] src1;
  wire [31:0] src2;
  wire [31:0] pc;
  wire auipcsig;
  wire mretsig;
  wire ecallsig;
  wire [31:0] mtvec;
  wire [31:0] mepc;
  wire [2:0] muxsig;
  wire csrrs, csrrw;

  exu_pipline_connect exu_pipeline_u(
    .clk(clk),
    .rst(rst),

    // need sig inputs
    .func3_in(func3_in),
    .btypebranch_in(btypebranch_in),
    .func7_in(func7_in),
    .aluop_in(aluop_in),
    .jalrsig_in(jalrsig_in),
    .jalsig_in(jalsig_in),
    .imm_in(imm_in),
    .muximm_in(muximm_in),
    .src1_in(src1_in),
    .src2_in(src2_in),
    .pc_in(pc_in),
    .auipcsig_in(auipcsig_in),
    .mretsig_in(mretsig_in),
    .ecallsig_in(ecallsig_in),
    .mtvec_in(mtvec_in),
    .mepc_in(mepc_in),

    // pass sig inputs
    .memew_in(memew_in),
    .memer_in(memer_in),
    .muxsig_in(muxsig_in),
    .regew_control_in(regew_control_in),
    .rd_in(rd_in),
    .csrrw_in(csrrw_in),
    .csrrs_in(csrrs_in),
    .csr_addr_in(csr_addr_in),

    // need sig outputs
    .func3_out(func3),
    .btypebranch_out(btypebranch),
    .func7_out(func7),
    .aluop_out(aluop),
    .jalrsig_out(jalrsig),
    .jalsig_out(jalsig),
    .imm_out(imm),
    .muximm_out(muximm),
    .src1_out(src1),
    .src2_out(src2),
    .pc_out(pc),
    .auipcsig_out(auipcsig),
    .mretsig_out(mretsig),
    .ecallsig_out(ecallsig),
    .mtvec_out(mtvec),
    .mepc_out(mepc),
    .muxsig_out(muxsig),

    // pass sig outputs
    .memew_out(memew_out),
    .memer_out(memer_out),
    .regew_control_out(regew_control_out),
    .rd_out(rd_out),
    .csrrw_out(csrrw),
    .csrrs_out(csrrs),
    .csr_addr_out(csr_addr_out),

    .avaliable(avaliable),
    .pipline_valid(pipline_valid),
    .flush(flush)
  );

  assign csrrs_out = csrrs;
  assign csrrw_out = csrrw;
  assign ecallsig_out = ecallsig;
  assign func3_out = func3;

  wire [31:0] pc_plus_4, pc_plus_imm;
  assign pc_plus_4 = pc + 32'd4;
  assign pc_plus_imm = pc + imm;

  
  wire [4:0] alu_opcode;
  ysyx_24100007_alucontrol alucontrol0(
    .func3(func3),
    .func7(func7),
    .aluop(aluop),
    .jalrsig(jalrsig),
    .is_csr(csrrw || csrrs),
    .aluopcode(alu_opcode)
  );

  reg [31:0] alu_arg2;
  always @(*) begin
    case (muximm)
      1'b0: alu_arg2 = src2;
      1'b1: alu_arg2 = imm;
      default: alu_arg2 = src2;
    endcase
  end

  wire zero_flag, sign_flag, carry_flag;
  ysyx_24100007_alu alu0(
    .A(src1),
    .B(alu_arg2),
    .op(alu_opcode),
    .res(res_r),
    .zero(zero_flag),
    .signal(sign_flag),
    .carry(carry_flag)
  );

  // ------------------------------------
  //  BRANCH CONTROL
  // ------------------------------------
  wire is_jmp_r_1;
  wire is_jmp_r;
  wire [31:0] res_r;
  ysyx_24100007_branchcontrol branchcontrol0(
    .btypebranch(btypebranch),
    .func3(func3),
    .zero(zero_flag),
    .signal(sign_flag),
    .carry(carry_flag),
    .res(res_r),
    .pcadd4(pc_plus_4),
    .pcaddimm(pc_plus_imm),
    .jalsig(jalsig),
    .jalrsig(jalrsig),
    .auipcsig(auipcsig),
    .mretsig(mretsig),
    .ecallsig(ecallsig),
    .mtvec(mtvec),
    .mepc(mepc),

    .npc(npc),
    .pcwritereg(link_addr),
    .is_jmp(is_jmp_r_1)
  );
  reg is_jmp_mask;
  always @(posedge clk) begin
    if((in_valid & in_ready) | exu_csr_delay) begin
      is_jmp_mask <= 1'b1;
    end else begin
      is_jmp_mask <= 1'b0;
    end
  end
  assign is_jmp_r = is_jmp_r_1 & is_jmp_mask & !exu_csr_delay;
  assign is_jmp = is_jmp_r;

  assign res = (csrrw || csrrs) ? src1 : res_r;
  assign src2_out = src2;  // 将流水线的src2输出到WBU
  assign imm_out = imm;    // 将流水线的imm输出到WBU
  assign muxsig_out = muxsig;

  // EXU 向 IDU 转发的旁路信号
  assign exu_rd = rd_out;
  assign exu_regew = regew_control_out || (memew_out || memer_out);
  assign exu_transmit_data = (muxsig == 3'b010) ? imm :
                             (muxsig == 3'b100) ? link_addr :
                             res;
 // 旁路数据有效条件：输出有效 && 不是访存指令（访存指令的结果需要从 WBU 获取）
  assign exu_transmit_data_valid = out_valid && !(memew_out || memer_out);
  // EXU 是否是 load 指令（用于 IDU 处理 load-use 冲突）
  assign exu_memer_bypass = memer_out;

  wire exu_need_mepc_mtvec = ecallsig || mretsig;
  wire exu_csr_delay = wbu_write_csr & exu_need_mepc_mtvec;
  
  // synopsys translate_off
  import "DPI-C" function void get_exu_state(int state);
  always @(posedge clk) begin 
    get_exu_state({31'b0, exu_state_r == VALID});
  end
  // synopsys translate_on

endmodule

module exu_pipline_connect(
  input clk, 
  input rst,

  input [2:0] func3_in,
  input btypebranch_in,
  input func7_in,
  input [1:0] aluop_in,
  input jalrsig_in,
  input jalsig_in,
  input [31:0] imm_in,
  input muximm_in,
  input [31:0] src1_in,
  input [31:0] src2_in,
  input [31:0] pc_in,
  input auipcsig_in,
  input mretsig_in,
  input ecallsig_in,
  input [31:0] mtvec_in,
  input [31:0] mepc_in,

  input memew_in,               
  input memer_in,              
  input [2:0] muxsig_in,        
  input regew_control_in,
  input [4:0] rd_in,
  input csrrw_in,
  input csrrs_in,
  input [11:0] csr_addr_in,

  output [2:0] func3_out,
  output btypebranch_out,
  output func7_out,
  output [1:0] aluop_out,
  output jalrsig_out,
  output jalsig_out,
  output [31:0] imm_out,
  output muximm_out,
  output [31:0] src1_out,
  output [31:0] src2_out,
  output [31:0] pc_out,
  output auipcsig_out,
  output mretsig_out,
  output ecallsig_out,
  output [31:0] mtvec_out,
  output [31:0] mepc_out,

  output memew_out,               
  output memer_out,              
  output [2:0] muxsig_out,        
  output regew_control_out,
  output [4:0] rd_out,
  output csrrw_out,
  output csrrs_out,
  output [11:0] csr_addr_out,

  output avaliable,
  input pipline_valid,
  input flush
);
  reg avaliable_r;
  always @(posedge clk) begin
    if(rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if(pipline_valid) begin
        avaliable_r <= 1'b1;
      end else if(flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  // 寄存器存储所有输入信号
  reg [2:0] func3_r;
  reg btypebranch_r;
  reg func7_r;
  reg [1:0] aluop_r;
  reg jalrsig_r;
  reg jalsig_r;
  reg [31:0] imm_r;
  reg muximm_r;
  reg [31:0] src1_r;
  reg [31:0] src2_r;
  reg [31:0] pc_r;
  reg auipcsig_r;
  reg mretsig_r;
  reg ecallsig_r;
  reg [31:0] mtvec_r;
  reg [31:0] mepc_r;

  reg memew_r;
  reg memer_r;
  reg [2:0] muxsig_r;
  reg regew_control_r;
  reg [4:0] rd_r;
  reg csrrw_r;
  reg csrrs_r;
  reg [11:0] csr_addr_r;

  always @(posedge clk) begin
    if(rst) begin
      func3_r <= 3'b0;
      btypebranch_r <= 1'b0;
      func7_r <= 1'b0;
      aluop_r <= 2'b0;
      jalrsig_r <= 1'b0;
      jalsig_r <= 1'b0;
      imm_r <= 32'b0;
      muximm_r <= 1'b0;
      src1_r <= 32'b0;
      src2_r <= 32'b0;
      pc_r <= 32'b0;
      auipcsig_r <= 1'b0;
      mretsig_r <= 1'b0;
      ecallsig_r <= 1'b0;
      mtvec_r <= 32'b0;
      mepc_r <= 32'b0;
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      muxsig_r <= 3'b0;
      regew_control_r <= 1'b0;
      rd_r <= 5'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
      csr_addr_r <= 12'b0;
    end else begin
      if(pipline_valid) begin
        func3_r <= func3_in;
        btypebranch_r <= btypebranch_in;
        func7_r <= func7_in;
        aluop_r <= aluop_in;
        jalrsig_r <= jalrsig_in;
        jalsig_r <= jalsig_in;
        imm_r <= imm_in;
        muximm_r <= muximm_in;
        src1_r <= src1_in;
        src2_r <= src2_in;
        pc_r <= pc_in;
        auipcsig_r <= auipcsig_in;
        mretsig_r <= mretsig_in;
        ecallsig_r <= ecallsig_in;
        mtvec_r <= mtvec_in;
        mepc_r <= mepc_in;
        memew_r <= memew_in;
        memer_r <= memer_in;
        muxsig_r <= muxsig_in;
        regew_control_r <= regew_control_in;
        rd_r <= rd_in;
        csrrw_r <= csrrw_in;
        csrrs_r <= csrrs_in;
        csr_addr_r <= csr_addr_in;
      end else if(flush) begin
        func3_r <= 3'b0;
        btypebranch_r <= 1'b0;
        func7_r <= 1'b0;
        aluop_r <= 2'b0;
        jalrsig_r <= 1'b0;
        jalsig_r <= 1'b0;
        imm_r <= 32'b0;
        muximm_r <= 1'b0;
        src1_r <= 32'b0;
        src2_r <= 32'b0;
        pc_r <= 32'b0;
        auipcsig_r <= 1'b0;
        mretsig_r <= 1'b0;
        ecallsig_r <= 1'b0;
        mtvec_r <= 32'b0;
        mepc_r <= 32'b0;
        memew_r <= 1'b0;
        memer_r <= 1'b0;
        muxsig_r <= 3'b0;
        regew_control_r <= 1'b0;
        rd_r <= 5'b0;
        csrrw_r <= 1'b0;
        csrrs_r <= 1'b0;
        csr_addr_r <= 12'b0;
      end
    end
  end

  // 输出连接到寄存器
  assign func3_out = func3_r;
  assign btypebranch_out = btypebranch_r;
  assign func7_out = func7_r;
  assign aluop_out = aluop_r;
  assign jalrsig_out = jalrsig_r;
  assign jalsig_out = jalsig_r;
  assign imm_out = imm_r;
  assign muximm_out = muximm_r;
  assign src1_out = src1_r;
  assign src2_out = src2_r;
  assign pc_out = pc_r;
  assign auipcsig_out = auipcsig_r;
  assign mretsig_out = mretsig_r;
  assign ecallsig_out = ecallsig_r;
  assign mtvec_out = mtvec_r;
  assign mepc_out = mepc_r;
  assign memew_out = memew_r;
  assign memer_out = memer_r;
  assign muxsig_out = muxsig_r;
  assign regew_control_out = regew_control_r;
  assign rd_out = rd_r;
  assign csrrw_out = csrrw_r;
  assign csrrs_out = csrrs_r;
  assign csr_addr_out = csr_addr_r;

endmodule
