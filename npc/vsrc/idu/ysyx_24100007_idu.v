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
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output [31:0] imm,
  output [2:0] func3,
  output func7,
  output [4:0] src1,
  output [4:0] src2,
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
          if(in_valid & in_ready) begin
            idu_state_r <= VALID;
          end
        end

        VALID: begin
          if(is_jmp) begin
            idu_state_r <= IDLE;
          end else if(out_ready) begin
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
  assign out_valid = (idu_state_r == VALID);
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
    .src1(src1),
    .src2(src2),
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

  always @(posedge clk) begin
    if(rst) begin
      inst_r <= 32'b0;
      pc_r <= 32'b0;
    end else begin
      if(valid) begin
        inst_r <= inst_in;
        pc_r <= pc_in;
      end else if(flush) begin
        inst_r <= 32'b0;
        pc_r <= 32'b0;
      end
    end
  end

  assign inst_out = inst_r;
  assign pc_out = pc_r;

endmodule
