module ysyx_24100007_exu(
  input clk,
  input rst,

  input [2:0] func3,
  input btypebranch,
  input func7,
  input [1:0] aluop,
  input jalrsig,
  input jalsig,
  input [31:0] imm,
  input muximm,
  input [31:0] regout1,
  input [31:0] regout2,
  input [31:0] pc,
  input auipcsig,
  input mretsig,
  input ecallsig,
  input [31:0] mtvec,
  input [31:0] mepc,
  input valid_get,
  input ready,

  output valid_to,
  output [31:0] res,
  output [31:0] npc,
  output [31:0] link_addr   // PC value to write to register (for JAL/JALR)
); 

  wire [31:0] res_r, npc_r, link_addr_r;
  reg [31:0] res_q, npc_q, link_addr_q;
  typedef enum logic {
    UNAVAILABLE, AVAILABLE
  } exu_state_t;
  exu_state_t exu_state;

  always @(posedge clk) begin
    if(rst) begin
      exu_state <= UNAVAILABLE;
    end else if(ready) begin
      exu_state <= UNAVAILABLE;
    end if(exu_state == UNAVAILABLE && valid_get) begin
      exu_state <= AVAILABLE;
    end
  end 

  always @(posedge clk) begin
    if(rst) begin
      res_q <= 32'b0;
      npc_q <= 32'b0;
      link_addr_q <= 32'b0;
    end else if(ready) begin
      res_q <= 32'b0;
      npc_q <= 32'b0;
      link_addr_q <= 32'b0;
    end else if(exu_state == AVAILABLE) begin
      res_q <= res_r;
      npc_q <= npc_r;
      link_addr_q <= link_addr_r;
    end
  end
  assign npc = npc_q;
  assign res = res_q;
  assign link_addr = link_addr_q;

  assign valid_to = (exu_state == AVAILABLE);

  wire [31:0] pc_plus_4, pc_plus_imm;
  assign pc_plus_4 = pc + 32'd4;
  assign pc_plus_imm = pc + imm;

  wire [4:0] alu_opcode;
  ysyx_24100007_alucontrol alucontrol0(
    .func3(func3),
    .func7(func7),
    .aluop(aluop),
    .jalrsig(jalrsig),
    .aluopcode(alu_opcode)
  );

  wire [31:0] alu_arg2;
  ysyx_24100007_MuxKey#(2, 1, 32) chosmuximm(alu_arg2, muximm, {
      1'b0, regout2,
      1'b1, imm
    }
  );
  
  wire zero_flag, sign_flag, carry_flag;
  ysyx_24100007_alu alu0(
    .A(regout1),
    .B(alu_arg2),
    .op(alu_opcode),
    .res(res_r),
    .zero(zero_flag),
    .signal(sign_flag),
    .carry(carry_flag)
  );

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

    .npc(npc_r),
    .pcwritereg(link_addr_r)
  );
  
  // synopsys translate_off
  import "DPI-C" function void host_get_exu_valid();
  always @(posedge valid_to) begin
    host_get_exu_valid();
  end
  // synopsys translate_on

endmodule
