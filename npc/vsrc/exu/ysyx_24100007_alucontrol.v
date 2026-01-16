`define   ADD       4'b0001
`define   SUB       4'b0011
`define   SLL       4'b1100
`define   SLT       4'b1001
`define   SLTU      4'b1000
`define   XOR       4'b0110
`define   SRL       4'b1101
`define   SRA       4'b1110
`define   OR        4'b0101
`define   AND       4'b0100

module ysyx_24100007_alucontrol(
  input [2:0] func3,
  input func7,
  input [1:0] aluop,
  input jalrsig,
  input is_csr,
  
  output [4:0] aluopcode
);
  wire type_I, type_B, type_R;
  wire [3:0] branchop;
  reg [3:0] IRop;
  assign type_I = (aluop == 2'b01);
  assign type_B = (aluop == 2'b11);
  assign type_R = (aluop == 2'b10);
  
  assign branchop=(func3[2] & func3[1])? `SLTU : (func3[2] ^ func3[1])? `SLT : `SUB;

  always @(*) begin
    case(func3)
    3'b000: begin
    if(type_R & func7) begin
      IRop = `SUB;
    end else begin
      IRop = `ADD;
    end
    end
    3'b001: IRop=`SLL;
    3'b010: begin
      if(jalrsig)
        IRop = `ADD;
      else
        IRop=`SLT;
    end
		3'b011: IRop=`SLTU;
		3'b100: IRop=`XOR;
		3'b101: begin
    if(func7) begin
			IRop=`SRA;
    end else
			IRop=`SRL;
    end
		3'b110: IRop=`OR;
		3'b111: IRop=`AND;
		default:IRop=`ADD;
    endcase
  end

  wire [4:0] aluopcode_I = {(type_I)? 1'b1:1'b0,(type_B==1)?branchop:(type_R|type_I == 1)?IRop:`ADD};
  wire [4:0] aluopcode_csr = {1'b0, `ADD};
  assign aluopcode = (is_csr) ? aluopcode_csr : aluopcode_I;
endmodule



        

