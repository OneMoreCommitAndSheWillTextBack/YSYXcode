import "DPI-C" function void host_get_pc(int pc);
import "DPI-C" function void host_get_inst(int inst);

module top(
  input clk,
  input rst
);
  always @(*) begin
     host_get_pc(pcbridge);
    host_get_inst(inst);
    if(inst != 0)
      $display("pc: 0x%08x %08x", pcbridge, inst);
  end
  //
  
  wire ready_idu_to_ifu;
  wire [31:0] npc, pcbridge;
  wire [31:0] inst;
  wire ifu_valid;
  wire ifu_arvalid, ifu_arready;
  wire [31:0] ifu_araddr;
  wire ifu_rvalid, ifu_rready;
  wire [31:0] ifu_rdata;

  ifu ifu0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .ready(ready_idu_to_ifu),
    .pc(pcbridge),
    .inst(inst),
    .valid(ifu_valid),

    .arvalid(ifu_arvalid),
    .arready(ifu_arready),
    .araddr(ifu_araddr),
    .rvalid(ifu_rvalid),
    .rready(ifu_rready),
    .rdata(ifu_rdata)
  );


  wire [4:0] src1, src2, rd;
  wire [31:0] imm;
  wire ebreaksig, mretsig, ecallsig;
  wire regew, memew, memer, muximm;
  wire [2:0] func3, muxsig;
  wire func7;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  wire csrrw, csrrs;
  wire idu_valid;
  wire [2:0] memmask;
  wire memsextsig;
  idu idu0(
  .inst(inst),
  .valid_from(ifu_valid),
  .ready_from(ready_exu_to_idu),
  
  .ebreaksig(ebreaksig),
  .ecallsig(ecallsig),
  .mretsig(mretsig),
  .imm(imm),
  .func3(func3),
  .func7(func7),
  .src1(src1),
  .src2(src2),
  .rd(rd),
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
  .csrrw(csrrw),
  .csrrs(csrrs),
  .memmask(memmask),
  .memsextsig(memsextsig),
  .valid_to(idu_valid),
  .ready_to(ready_idu_to_ifu)
);

  wire [31:0] regwrite, regout1, regout2;
  wire [31:0] mepc, mtvec;
  wire ready_exu_to_idu;
  regheap regfile(
    .clk(clk),
    .rst(rst),
    .ew(regew & memvalid),
    .addr(rd),
    .src1(src1),
    .src2(src2),
    .data(regwrite),
    .csr(inst[31:20]),
    .csrrw(csrrw),
    .csrrs(csrrs),
    .ecallsig(ecallsig),
    .valid(ifu_valid),
    .regout1(regout1),
    .regout2(regout2),
    .mepc(mepc),
    .mtvec(mtvec)
  ); 
  
  wire [31:0] res;
  wire [31:0] pcwritereg;
  wire exu_valid;
  exu exu0(
  .func3(func3),
  .func7(func7),
  .aluop(aluop),
  .btypebranch(btypebranch),
  .jalrsig(jalrsig),
  .jalsig(jalsig),
  .imm(imm),
  .muximm(muximm),
  .regout1(regout1),
  .regout2(regout2),
  .auipcsig(auipcsig),
  .mretsig(mretsig),
  .ecallsig(ecallsig),
  .mtvec(mtvec),
  .mepc(mepc),
  .pc(pcbridge),
  .valid_from(idu_valid),
  .ready_from(ready_wbu_to_exu),
  
  .res(res),
  .npc(npc),
  .pcwritereg(pcwritereg),
  .valid_to(exu_valid),
  .ready_to(ready_exu_to_idu)
);
  
  wire ready_wbu_to_exu;
/*
  wire wbu_valid;
  wire wbu_arvalid, wbu_arready;
  wire [31:0] wbu_araddr;
  wire wbu_rvalid, wbu_rready;
  wire [31:0] wbu_rdata;
  wire wbu_awvalid, wbu_awready;
  wire [31:0] wbu_awaddr;
  wire wbu_wvalid, wbu_wready;
  wire [31:0] wbu_wdata;
  wire [3:0] wbu_wstrb;
  wire wbu_bvalid, wbu_bready;
  wire wbu_bresp;
*/


  wire memvalid;
  wbu wbu0(
  .res(res),
  .regout2(regout2),
  .memew(memew),
  .memer(memer),
  .imm(imm),
  .pcwritereg(pcwritereg),
  .muxsig(muxsig),
  .valid_from(exu_valid),
  .memsextsig(memsextsig),
  .memmask(memmask),

  .regwrite(regwrite),
  .ready_to(ready_wbu_to_exu),
  .memvalid(memvalid),

  // axi-lite interface
  .awvalid(awvalid[1]),
  .awready(awready[1]),
  .awaddr(awaddr[1]),

  .wvalid(wvalid[1]),
  .wready(wready[1]),
  .wdata(wdata[1]),
  .wstrb(wstrb[1]),

  .bvalid(bvalid[1]),
  .bready(bready[1]),
  .bresp(bresp[1]),

  .arvalid(arvalid[1]),
  .arready(arready[1]),
  .araddr(araddr[1]),

  .rvalid(rvalid[1]),
  .rready(rready[1]),
  .rdata(rdata[1])
);

wire [1:0] 
  awvalid, wvalid,
  arvalid, rready,
  bready, bvalid,
  rvalid, awready,
  wready, arready;

wire [31:0] araddr [1:0];
wire [31:0] rdata [1:0];
wire [31:0] awaddr [1:0];
wire [31:0] wdata [1:0];
wire [3:0] wstrb [1:0];
wire bresp [1:0];

assign awvalid[0] = 0;
assign awaddr[0] = 0;
assign wvalid[0] = 0;
assign wdata[0] = 0;
assign wstrb[0] = 0;
assign bready[0] = 0;

assign arvalid[0] = ifu_arvalid;
assign ifu_arready = arready[0];
assign araddr[0] = ifu_araddr;
assign ifu_rvalid = rvalid[0];
assign rready[0] = ifu_rready;
assign ifu_rdata = rdata[0];

data #(2) data0(
  .clk(clk),
  
  .awvalid(awvalid),
  .wvalid(wvalid),
  .arvalid(arvalid),
  .rready(rready),
  .bready(bready),
  .bvalid(bvalid),
  .rvalid(rvalid),
  .awready(awready),
  .wready(wready),
  .arready(arready),

  .araddr(araddr),
  .rdata(rdata),
  .awaddr(awaddr),
  .wdata(wdata),
  .wstrb(wstrb),
  .bresp(bresp)
);
endmodule
