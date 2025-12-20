module ysyx_24100007_core #(
  parameter PORT_NUM=2  // 连接到arbiter的端口数量（IFU和WBU）
)(
  input clock,
  input reset,
  input io_interrupt,

  // AXI接口 - 连接到arbiter的master接口
  output [PORT_NUM-1:0] awvalid, 
  output [PORT_NUM-1:0] wvalid,  
  output [PORT_NUM-1:0] arvalid, 
  output [PORT_NUM-1:0] rready,
  output [PORT_NUM-1:0] bready,
  input [PORT_NUM-1:0] bvalid,
  input [PORT_NUM-1:0] rvalid,
  input [PORT_NUM-1:0] awready, 
  input [PORT_NUM-1:0] wready,  
  input [PORT_NUM-1:0] arready, 

  // AXI data channel
  output [PORT_NUM-1:0][31:0] araddr,
  output [PORT_NUM-1:0][31:0] awaddr,
  output [PORT_NUM-1:0][31:0] wdata,
  output [PORT_NUM-1:0][3:0] wstrb,
  input [PORT_NUM-1:0][31:0] rdata,
  input [PORT_NUM-1:0][1:0] bresp,
  output [PORT_NUM-1:0][2:0] awsize,
  output [PORT_NUM-1:0][2:0] arsize,
  
  // AXI burst transfer signals
  output [PORT_NUM-1:0][7:0] awlen,
  output [PORT_NUM-1:0][7:0] arlen,
  output [PORT_NUM-1:0][1:0] awburst,
  output [PORT_NUM-1:0][1:0] arburst,
  output [PORT_NUM-1:0] wlast,
  input [PORT_NUM-1:0] rlast,
  input [PORT_NUM-1:0][1:0]  rresp,
  
  // Transaction start/end signals
  output [PORT_NUM-1:0] trans_start,
  output [PORT_NUM-1:0] trans_end
);

    // synopsys translate_off
    import "DPI-C" function void host_get_pc(int pc);
    import "DPI-C" function void host_get_inst(int inst);
    always @(*) begin
        host_get_pc(pcbridge);
        host_get_inst(inst);
    end
    // synopsys translate_on

  wire inst_cycle_end;
  
  wire [31:0] npc, pcbridge;
  wire [31:0] inst;
  wire ifu_valid;

  ysyx_24100007_ifu ifu0(
    .clk(clock),
    .rst(reset),
    .npc(npc),
    .ready(inst_cycle_end),
    .pc(pcbridge),
    .inst(inst),
    .valid(ifu_valid),

    .trans_start(trans_start[0]),
    .trans_end(trans_end[0]),

    .arvalid(arvalid[0]),
    .arready(arready[0]),
    .araddr(araddr[0]),
    .rvalid(rvalid[0]),
    .rready(rready[0]),
    .rdata(rdata[0]),

    .arlen(arlen[0]),
    .arsize(arsize[0]),
    .arburst(arburst[0]),
    .rresp(rresp[0]),
    .rlast(rlast[0])
  );

  // not used channel set to 0
  assign awvalid[0] = 1'b0;
  assign wvalid[0] = 1'b0;
  assign awaddr[0] = 32'b0;
  assign wdata[0] = 32'b0;
  assign wstrb[0] = 4'b0;
  assign bready[0] = 1'b0;
  assign awsize[0] = 3'b0;
  assign awlen[0] = 8'b0;
  assign awburst[0] = 2'b0;
  assign wlast[0] = 1'b0;


  wire [4:0] src1, src2, rd;
  wire [31:0] imm;
  wire ebreaksig, mretsig, ecallsig;
  wire memew, memer, muximm;
  wire [2:0] func3, muxsig;
  wire func7;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  wire csrrw, csrrs;
  wire idu_valid;
  wire [2:0] memmask;
  wire memsextsig;
  wire regew_control;
  ysyx_24100007_idu idu0(
  .inst(inst),
  .valid_get(ifu_valid),
  
  .ebreaksig(ebreaksig),
  .ecallsig(ecallsig),
  .mretsig(mretsig),
  .imm(imm),
  .func3(func3),
  .func7(func7),
  .src1(src1),
  .src2(src2),
  .rd(rd),
  .regew_control(regew_control),
  .memew(memew),
  .muxsig(muxsig),
  .memer(memer),
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
  .valid_to(idu_valid)
);

  wire [31:0] regwrite, regout1, regout2;
  wire [31:0] mepc, mtvec;
  ysyx_24100007_regheap regfile(
    .clk(clock),
    .rst(reset),
    .ew(regew),
    .addr(rd),
    .src1(src1),
    .src2(src2),
    .data(regwrite),
    .csr(inst[31:20]),
    .csrrw(csrrw),
    .csrrs(csrrs),
    .ecallsig(ecallsig),
    .regout1(regout1),
    .regout2(regout2),
    .mepc(mepc),
    .mtvec(mtvec)
  ); 
  
  wire [31:0] res;
  wire [31:0] link_addr;
  wire exu_valid;
  ysyx_24100007_exu exu0(
  .clk(clock),
  .rst(reset),
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
  .valid_get(idu_valid),
  .ready(inst_cycle_end),
  
  .valid_to(exu_valid),
  .res(res),
  .npc(npc),
  .link_addr(link_addr)
);

  wire regew;
  ysyx_24100007_wbu wbu0(
  .clk(clock),
  .rst(reset),
  .res(res),
  .regout2(regout2),
  .memew(memew),
  .memer(memer),
  .imm(imm),
  .link_addr(link_addr),
  .muxsig(muxsig),
  .valid_get(exu_valid),
  .memsextsig(memsextsig),
  .memmask(memmask),

  .regwrite(regwrite),
  .ready(inst_cycle_end),
  .regew_control(regew_control),
  .regew(regew),

  .trans_start(trans_start[1]),
  .trans_end(trans_end[1]),

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
  .rdata(rdata[1]),
  .awsize(awsize[1]),
  .arsize(arsize[1]),
  .awburst(awburst[1])
);

// 暂时不实现突发传输，将没有使用的部分设置为0
assign awlen[1] = 8'b0;      // 写地址长度（单次传输，len=0）
assign arlen[1] = 8'b0;      // 读地址长度（单次传输，len=0）
assign arburst[1] = 2'b0;   // 读burst类型（FIXED，单次传输）
assign wlast[1] = wvalid[1];

endmodule