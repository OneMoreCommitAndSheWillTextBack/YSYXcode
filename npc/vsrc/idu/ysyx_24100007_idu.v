module ysyx_24100007_idu(
  input [31:0] inst,
  input valid_from,
  input ready_from,
  
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
  output regew,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output valid_to,
  output ready_to,
  output [2:0] memmask,
  output memsextsig
);
  
  wire ebreak, ecall, mret;
  wire [2:0] func3bridge;
  wire func7bridge;
  wire [6:0] opcode;

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
    .memsextsig(memsextsig),
    .memmask(memmask)
  );

  ysyx_24100007_maincontrol maincontrol0(
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .ebreaksig(ebreak),
    .ecallsig(ecall),
    .mretsig(mret),

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
    .csrrs(csrrs),
    .csrrw(csrrw)
  );

  assign ecallsig = ecall;
  assign mretsig = mret;
  assign ebreaksig = ebreak;
  assign func7 = func7bridge;
  assign func3 = func3bridge;
  
  assign valid_to = valid_from;
  assign ready_to = ready_from;

endmodule
