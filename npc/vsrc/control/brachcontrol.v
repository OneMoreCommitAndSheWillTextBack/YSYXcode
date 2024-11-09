module branchcontrol(
  input btypebranch,
  input [2:0] func3,
  input zero,
  input signal,
  input carry,
  input [31:0] res,
  input [31:0] pcadd4,
  input [31:0] pcaddimm,
  input jalsig,
  input jalrsig,
  input auipcsig,

  output [31:0] npc,
  output reg [31:0] pcwritereg
);
 assign pcwritereg = (jalsig || jalrsig) ? pcadd4 : 
                    auipcsig ? pcaddimm :
                    0;
 
assign npc = (jalsig) ? pcaddimm :
             (jalrsig) ? {res[31:1], 1'b0} :
             (btypebranch && func3 == 3'b000 && zero)    ? pcaddimm :
             (btypebranch && func3 == 3'b001 && !zero)   ? pcaddimm :
             (btypebranch && func3 == 3'b100 && signal)  ? pcaddimm :
             (btypebranch && func3 == 3'b101 && !signal) ? pcaddimm :
             (btypebranch && func3 == 3'b110 && !carry)  ? pcaddimm :
             (btypebranch && func3 == 3'b111 && carry)   ? pcaddimm :
             pcadd4;
endmodule
