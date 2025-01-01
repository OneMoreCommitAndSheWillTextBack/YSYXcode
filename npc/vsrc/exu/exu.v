module exu(
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
  input valid_from,
  input ready_from,
  
  output [31:0] res,
  output [31:0] npc,
  output [31:0] pcwritereg,
  output valid_to,
  output ready_to
);
  wire [31:0] pcadd4bridge, pcaddimmbridge;
  pcadd4 pcadd40(
    .pc(pc),
    .npc(pcadd4bridge)
  );

  pcaddimm pcaddimm0(
    .pc(pc),
    .imm(imm),
    .npc(pcaddimmbridge)
  );

  wire [4:0] aluopcode;
  alucontrol alucontrol0(
    .func3(func3),
    .func7(func7),
    .aluop(aluop),
    .jalrsig(jalrsig),
    .aluopcode(aluopcode)
  );

  wire [31:0] aluarg2;
  MuxKey#(2, 1, 32) chosmuximm(aluarg2, muximm, {
      1'b0, regout2,
      1'b1, imm
    });
  
  wire zero, signal, carry;
  alu alu0(
    .A(regout1),
    .B(aluarg2),
    .op(aluopcode),
    .res(res),
    .zero(zero),
    .signal(signal),
    .carry(carry)
  );

  branchcontrol branchcontrol0(
    .btypebranch(btypebranch),
    .func3(func3),
    .zero(zero),
    .signal(signal),
    .carry(carry),
    .res(res),
    .pcadd4(pcadd4bridge),
    .pcaddimm(pcaddimmbridge),
    .jalsig(jalsig),
    .jalrsig(jalrsig),
    .auipcsig(auipcsig),
    .mretsig(mretsig),
    .ecallsig(ecallsig),
    .mtvec(mtvec),
    .mepc(mepc),

    .npc(npc),
    .pcwritereg(pcwritereg)
  );

  assign valid_to = valid_from;
  assign ready_to = ready_from;

endmodule
