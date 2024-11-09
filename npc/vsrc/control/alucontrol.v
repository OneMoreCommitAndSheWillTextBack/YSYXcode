`include "symdef.v"

module alucontrol(
  input [2:0] func3,
  input func7,
  input [1:0] aluop,
  input jalrsig,
  
  output [4:0] aluopcode
);
  // addsig is the sb instr
  wire type_I, type_B, type_R, addsig;
  wire [3:0] branchop;
  reg [3:0] IRop;
  assign type_I = (aluop == 2'b01);
  assign type_B = (aluop == 2'b11);
  assign type_R = (aluop == 2'b10);
  assign addsig = (aluop == 2'b00);
  
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

  assign aluopcode = {(type_I)? 1'b1:1'b0,(type_B==1)?branchop:(type_R|type_I == 1)?IRop:`ADD};

endmodule



        

