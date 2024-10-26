module branchcontrol(
  input btypebranch,
  input [2:0] func3,
  input zero,
  input signal,
  input [31:0] res,
  input [31:0] pcadd4,
  input [31:0] pcaddimm,
  input jalsig,
  input jalrsig,

  output [31:0] npc,
  output reg [31:0] pcwritereg
);
  reg [31:0] npc_tmp;
  always @(*) begin
    if(jalsig) begin
      pcwritereg = pcadd4;
      npc_tmp = pcaddimm; 
    end else if(jalrsig) begin
      pcwritereg = pcadd4;
      npc_tmp = {res[31:1], 1'b0};
    end else if(btypebranch) begin
      case(func3)
        3'b000:
          begin
              if(zero)
                npc_tmp = pcaddimm;
              else
                npc_tmp = pcadd4;
          end
        3'b001:
          begin
            if(!zero)
              npc_tmp = pcaddimm;
            else
              npc_tmp = pcadd4;
          end
        default:
          $display("meet a unknown B type inst");
      endcase
    end else 
      npc_tmp = pcadd4;
  end
  assign npc = npc_tmp;

endmodule
