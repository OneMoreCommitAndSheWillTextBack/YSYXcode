import "DPI-C" function void host_get_pc(int pc);
import "DPI-C" function void host_get_inst(int inst);

module ysyx_24100007(
    input clock,
    input reset,
    input io_interrupt,

    input               io_master_awready,
    output              io_master_awvalid,
    output [31:0]       io_master_awaddr,
    output [3:0]        io_master_awid,
    output [7:0]        io_master_awlen,
    output [2:0]        io_master_awsize,
    output [1:0]        io_master_awburst,

    input               io_master_wready,
    output              io_master_wvalid,
    output [31:0]       io_master_wdata,
    output [3:0]        io_master_wstrb,
    output              io_master_wlast,

    output              io_master_bready,
    input               io_master_bvalid,
    input  [1:0]        io_master_bresp,
    input  [3:0]        io_master_bid,

    input               io_master_arready,
    output              io_master_arvalid,
    output [31:0]       io_master_araddr,
    output [3:0]        io_master_arid,
    output [7:0]        io_master_arlen,
    output [2:0]        io_master_arsize,
    output [1:0]        io_master_arburst,

    output              io_master_rready,
    input               io_master_rvalid,
    input  [1:0]        io_master_rresp,
    input  [31:0]       io_master_rdata,
    input               io_master_rlast,
    input  [3:0]        io_master_rid,

    // the signal below not used
    output              io_slave_awready,
    input               io_slave_awvalid,
    input  [31:0]       io_slave_awaddr,
    input  [3:0]        io_slave_awid,
    input  [7:0]        io_slave_awlen,
    input  [2:0]        io_slave_awsize,
    input  [1:0]        io_slave_awburst,

    output              io_slave_wready,
    input               io_slave_wvalid,
    input  [31:0]       io_slave_wdata,
    input  [3:0]        io_slave_wstrb,
    input               io_slave_wlast,

    input               io_slave_bready,
    output              io_slave_bvalid,
    output [1:0]        io_slave_bresp,
    output [3:0]        io_slave_bid,

    output              io_slave_arready,
    input               io_slave_arvalid,
    input  [31:0]       io_slave_araddr,
    input  [3:0]        io_slave_arid,
    input  [7:0]        io_slave_arlen,
    input  [2:0]        io_slave_arsize,
    input  [1:0]        io_slave_arburst,

    input               io_slave_rready,
    output              io_slave_rvalid,
    output [1:0]        io_slave_rresp,
    output [31:0]       io_slave_rdata,
    output              io_slave_rlast,
    output [3:0]        io_slave_rid
);

  always @(*) begin
    host_get_pc(npc);
    host_get_inst(inst);
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
  wire reg_process;

  ysyx_24100007_ifu ifu0(
    .clk(clock),
    .rst(reset),
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
    .rdata(ifu_rdata),
    .regprocess(reg_process)
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
  ysyx_24100007_idu idu0(
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
  ysyx_24100007_regheap regfile(
    .clk(clock),
    .rst(reset),
    .ew((regew & reg_process) | memvalid),
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
  ysyx_24100007_exu exu0(
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

  wire memvalid;
  ysyx_24100007_wbu wbu0(
  .clk(clock),
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
wire [1:0] bresp [1:0];

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

ysyx_24100007_arbiter #(2) arviter0(
  .clk(clock), //input
  .reset(reset),

  // master interface
  .awvalid(awvalid),   //input
  .wvalid(wvalid),     //input
  .arvalid(arvalid),   //input
  .rready(rready),     //input
  .bready(bready),     //input
  .bvalid(bvalid),     //ouptut
  .rvalid(rvalid),    //output
  .awready(awready),  //output
  .wready(wready),	  //output  
  .arready(arready),  //output 

  // master data channel
  .araddr(araddr),
  .awaddr(awaddr),
  .wdata(wdata),
  .rdata(rdata),
  .wstrb(wstrb),
  .bresp(bresp),

  // subordinate interface
  .awvalid_out(io_master_awvalid), 
  .wvalid_out(io_master_wvalid),  
  .arvalid_out(io_master_arvalid), 
  .rready_out(io_master_rready),
  .bready_out(io_master_bready),
  .bvalid_in(io_master_bvalid),
  .rvalid_in(io_master_rvalid),
  .awready_in(io_master_wready),  
  .wready_in(io_master_wready),   
  .arready_in(io_master_arready),

  .araddr_out(io_master_araddr),
  .awaddr_out(io_master_awaddr),
  .wdata_out(io_master_wdata),
  .wstrb_out(io_master_wstrb),
  .rdata_in(io_master_rdata),
  .bresp_in(io_master_bresp)
);

  assign io_master_arsize = 3'b100;
  assign io_master_arid = 4'b0001;
  assign io_master_arburst = 2'b01;
  assign io_master_arlen = 0;


endmodule
