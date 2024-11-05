module top(
  input clk,
  input rst
);
  always @(posedge clk) begin
    host_get_pc(pcbridge);
    host_get_inst(inst);
    // $display("pc: 0x%08x start", pcbridge);
  end
  //

  wire [31:0] npc, pcbridge;
  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge)
  );

  wire [31:0] inst;

  infetch infetch0(
    .pc(pcbridge),
    .inst(inst)
  );

  wire [6:0] opcode;
  wire [2:0] func3_decoder;
  wire func7_decoder;
  wire [4:0] src1, src2, rd;
  wire [31:0] imm;
  decoder decoder0(
    .inst(inst),
    .imm(imm),
    .src1(src1),
    .src2(src2),
    .rd(rd),
    .opcode(opcode),
    .func3(func3_decoder),
    .func7(func7_decoder)
  );

  wire regew, memew, memer, muximm, regwritepc, regwritemem;
  wire [2:0] func3_maincontrol;
  wire func7_maincontrol;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  maincontrol maincontrol0(
    .opcode(opcode),
    .func3(func3_decoder),
    .func7(func7_decoder),

    .memew(memew),
    .memer(memer),
    .regew(regew),
    .muximm(muximm),
    .regwritemem(regwritemem),
    .regwritepc(regwritepc),
    .func3_out(func3_maincontrol),
    .func7_out(func7_maincontrol),
    .btypebranch(btypebranch),
    .jalrsig(jalrsig),
    .jalsig(jalsig),
    .aluop(aluop),
    .auipcsig(auipcsig)
  );

  wire [31:0] regwrite, regout1, regout2;
  regheap regfile(
    .clk(clk),
    .rst(rst),
    .ew(regew),
    .addr(rd),
    .src1(src1),
    .src2(src2),
    .data(regwrite),
    .regout1(regout1),
    .regout2(regout2)
  );
  
  wire [3:0] aluopcode;
  alucontrol alucontrol0(
    .func3(func3_maincontrol),
    .func7(func7_maincontrol),
    .aluop(aluop),
    .jalrsig(jalrsig),
    .aluopcode(aluopcode)
  );

  wire [31:0] pcadd4bridge, pcaddimmbridge;
  pcadd4 pcadd40(
    .pc(pcbridge),
    .npc(pcadd4bridge)
  );

  pcaddimm pcaddimm0(
    .pc(pcbridge),
    .imm(imm),
    .npc(pcaddimmbridge)
  );
  
  wire [31:0] aluarg2;
  MuxKey#(2, 1, 32) chosmuximm(aluarg2, muximm, {
      1'b0, regout2,
      1'b1, imm
    });

  // instant a alu
  wire zero, signal;
  wire [31:0] res;
  alu alu0(
    .A(regout1),
    .B(aluarg2),
    .op(aluopcode),
    .res(res),
    .zero(zero),
    .signal(signal)
  );
  
  
  wire [31:0] pcwritereg;
  branchcontrol branchcontrol0(
    .btypebranch(btypebranch),
    .func3(func3_maincontrol),
    .zero(zero),
    .signal(signal),
    .res(res),
    .pcadd4(pcadd4bridge),
    .pcaddimm(pcaddimmbridge),
    .jalsig(jalsig),
    .jalrsig(jalrsig),
    .auipcsig(auipcsig),

    .npc(npc),
    .pcwritereg(pcwritereg)
  );
  
  wire [31:0] memread;
  mem mem0(
  .clk(clk),
  .addr(res),
  .write(regout2),
  .ew(memew),
  .er(memer),
  .read(memread)
);

wire [31:0] muxregormem;
MuxKey#(2, 1, 32) regormem(muxregormem, regwritemem, {
    1'b0, res,
    1'b1, memread
});
  
MuxKey#(2, 1, 32) muxpc(regwrite, regwritepc, {
    1'b1, pcwritereg,
    1'b0, muxregormem
});

endmodule
