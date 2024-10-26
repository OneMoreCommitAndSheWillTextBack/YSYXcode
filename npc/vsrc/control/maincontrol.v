import "DPI-C" function void ret();

module maincontrol(
  input [6:0] opcode,
  input [2:0] func3,
  input func7,

  output memew,
  output memer,
  output regew,
  output muximm,
  output regwritemem,
  output regwritepc,
  output [2:0] func3_out,
  output func7_out,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output [1:0] aluop
);
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  // here need to judge load and store 
  wire load, store;
  wire ebreaksig;
  
  assign type_I = (opcode == 7'b0000011) | (opcode == 7'b1100111) |
                  (opcode == 7'b0010011) | (opcode == 7'b0000111) |
                  (opcode == 7'b1110011);
  assign type_B = (opcode == 7'b1100011);
  assign type_S = (opcode == 7'b0100011);
  assign type_R = (opcode == 7'b0110011);
  assign type_U = (opcode == 7'b0110111) | (opcode == 7'b0010111);
  assign type_J = (opcode == 7'b1101111);

  assign load = (opcode == 7'b0000011);
  assign store = (opcode == 7'b0100011);

  assign btypebranch = type_B;
  assign memew = store;
  assign memer = load;
  assign regew = type_I | type_R | type_J | type_U;
  assign jalsig = type_J;
  assign jalrsig = (opcode == 7'b1100111);
  assign muximm = load | store | type_I | jalrsig;
  assign regwritemem = load;
  assign regwritepc = jalrsig | jalsig;

  assign func3_out = func3;
  assign func7_out = func7;
  assign aluop[1] = type_R | type_B;
  assign aluop[0] = type_I | type_B;

  assign ebreaksig = (opcode == 7'b1110011);
  always @(*) begin
    $display("the ebreaksig state is %b", opcode);
    if(ebreaksig)
      ret();
  end
endmodule
