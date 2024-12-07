import "DPI-C" function void ret(int pc);

module maincontrol(
  input [6:0] opcode,
  input [2:0] func3,
  input func7,
  input ebreaksig,
  input ecallsig,
  input mretsig,

  output memew,
  output [2:0] muxsig,
  output memer,
  output regew,
  output muximm,
  output [2:0] func3_out,
  output func7_out,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs
);
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  // here need to judge load and store 
  wire load, store;
  wire regwritepc, regwritemem, luisig;
  
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
  assign regew = type_I | type_R | type_J | type_U | memer;
  assign jalsig = type_J | ecallsig;
  assign jalrsig = (opcode == 7'b1100111);
  assign muximm = load | store | type_I | jalrsig;
  assign regwritemem = load;
  assign regwritepc = jalrsig | jalsig | auipcsig;
  assign auipcsig = (opcode == 7'b0010111);
  assign luisig = (opcode == 7'b0110111);

  assign func3_out = func3;
  assign func7_out = func7;
  assign aluop[1] = type_R | type_B;
  assign aluop[0] = (type_I | type_B) & ~load;

  assign muxsig = {regwritepc, luisig, regwritemem};

  assign csrrs = (opcode == 7'b1110011) & (func3 == 3'b001);
  assign csrrw = (opcode == 7'b1110011) & (func3 == 3'b010);

  always @(*) begin
    if(ebreaksig)
      ret(0);
  end
endmodule
