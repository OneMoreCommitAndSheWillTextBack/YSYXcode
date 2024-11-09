module alu(
  input [31:0] A,
  input [31:0] B,
  input [3:0] op,
  output reg [31:0] res,
  output zero,
  output signal,
  output carry
);
  wire addsig, logsig, shfsig, sltsig;
  reg carry_tmp;

  assign addsig = !(op[3]|op[2]);
  assign logsig = (op[3] == 0) & (op[2] == 1);
  assign shfsig = (op[3]&op[2]);
  assign sltsig = (op[3] == 1) & (op[2] == 0);
  
  // logic part
  reg [31:0] logres;
  always @(*) begin
    case(op[1:0])
      2'b00: logres = A & B;
      2'b01: logres = A | B;
      2'b10: logres = A ^ B;
      2'b11: logres = ~(A | B);
    endcase
  end

  // add part
  reg [31:0] addres;
  wire addzero, addsig;
  always @(*) begin
    case(op[0] ^ op[1])
      1'b1: {carry_tmp, addres} = {1'b0,A} + {1'b0,B};
      1'b0: {carry_tmp, addres} = {1'b0,A} + {1'b0,(~B)} + 1;
    endcase
    // $display("%x + %x = %x", A, B, addres);
  end
  assign addzero = (addres == 0);
  assign addsig = (addres[31]);

  // shift part
  reg [31:0] shfres;
  always @(*) begin
    case(op[1:0])
      2'b00: shfres = A << B;
      2'b01: shfres = A >> B;
      2'b10: shfres = {{32{A[31]}} << B} | (A >> B);
      default: shfres = 32'b0;
    endcase
  end

  // stl part
  reg [31:0] sltres;
  wire signed [31:0] A_s = A;
  wire signed [31:0] B_s = B;
  always @(*) begin
    case(op[0]) 
      1'b0: sltres = (A<B) ? 32'b1 : 32'b0;
      1'b1: sltres = (A_s<B_s) ? 32'b1 : 32'b0;
    endcase
  end

  assign res = addsig ? addres :
               logsig ? logres :
               shfsig ? shfres :
               sltsig ? sltres :
               32'b0;
  assign zero = (res == 0);
  assign signal = res[31];
  assign carry = carry_tmp;

endmodule
