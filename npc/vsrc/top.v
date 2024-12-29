module top(
  input clk,
  input rst
);
  always @(*) begin
     host_get_pc(pcbridge);
    host_get_inst(inst);
    //if(inst != 0)
      //$display("pc: 0x%08x %08x", pcbridge, inst);
  end
  //
  
  wire ready_idu_to_ifu;
  wire [31:0] npc, pcbridge;
  wire [31:0] inst;
  wire ifu_valid;
  ifu ifu0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pc(pcbridge),
    .inst(inst),
    .valid(ifu_valid),
    .ready(ready_idu_to_ifu)
  );

  wire [4:0] src1, src2, rd;
  wire [31:0] imm;
  wire ebreaksig, mretsig, ecallsig;
  wire regew, memew, memer, muximm;
  wire [2:0] func3, muxsig;
  wire func7;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  wire csrrw, csrrs;
  wire idu_valid;
  wire [2:0] memmask;
  wire memsextsig;
  idu idu0(
  .inst(inst),
  .valid_from_ifu(ifu_valid),
  
  .ebreaksig(ebreaksig),
  .ecallsig(ecallsig),
  .mretsig(mretsig),
  .imm(imm),
  .func3(func3),
  .func7(func7),
  .src1(src1),
  .src2(src2),
  .rd(rd),
  .memew(memew),
  .muxsig(muxsig),
  .memer(memer),
  .regew(regew),
  .muximm(muximm),
  .btypebranch(btypebranch),
  .jalrsig(jalrsig),
  .jalsig(jalsig),
  .aluop(aluop),
  .auipcsig(auipcsig),
  .csrrw(csrrw),
  .csrrs(csrrs),
  .memmask(memmask),
  .memsextsig(memsextsig),
  .valid(idu_valid),
  .ready(ready_idu_to_ifu)
);

  wire [31:0] regwrite, regout1, regout2;
  wire [31:0] mepc, mtvec;
  regheap regfile(
    .clk(clk),
    .rst(rst),
    .ew(regew),
    .addr(rd),
    .src1(src1),
    .src2(src2),
    .data(regwrite),
    .csr(inst[31:20]),
    .csrrw(csrrw),
    .csrrs(csrrs),
    .ecallsig(ecallsig),
    .valid(ifu_valid),
    .regout1(regout1),
    .regout2(regout2),
    .mepc(mepc),
    .mtvec(mtvec)
  ); 
  
  wire [31:0] res;
  wire [31:0] pcwritereg;
  wire exu_valid;
  exu exu0(
  .func3(func3),
  .func7(func7),
  .aluop(aluop),
  .btypebranch(btypebranch),
  .jalrsig(jalrsig),
  .jalsig(jalsig),
  .imm(imm),
  .muximm(muximm),
  .regout1(regout1),
  .regout2(regout2),
  .auipcsig(auipcsig),
  .mretsig(mretsig),
  .ecallsig(ecallsig),
  .mtvec(mtvec),
  .mepc(mepc),
  .pc(pcbridge),
  .valid_from_idu(idu_valid),
  
  .res(res),
  .npc(npc),
  .pcwritereg(pcwritereg),
  .valid(exu_valid)
);
  
  wbu wbu0(
  .clk(clk),
  .res(res),
  .regout2(regout2),
  .memew(memew),
  .memer(memer),
  .func3(func3),
  .imm(imm),
  .pcwritereg(pcwritereg),
  .muxsig(muxsig),
  .valid_from_exu(exu_valid),
  .memsextsig(memsextsig),
  .memmask(memmask),

  .regwrite(regwrite)
);


endmodule
