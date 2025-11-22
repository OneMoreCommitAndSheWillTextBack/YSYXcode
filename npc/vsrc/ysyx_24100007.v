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
    host_get_pc(pcbridge);
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
  .rdata(rdata[1]),
  .awsize(awsize[1]),
  .arsize(arsize[1]),
  .awburst(io_master_awburst)
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
wire [2:0] awsize [1:0];
wire [2:0] arsize [1:0];

assign awvalid[0] = 0;
assign awaddr[0] = 0;
assign wvalid[0] = 0;
assign wdata[0] = 0;
assign wstrb[0] = 0;
assign bready[0] = 0;
assign awsize[0] = 0;
assign arsize[0] = 3'b010;

assign arvalid[0] = ifu_arvalid;
assign ifu_arready = arready[0];
assign araddr[0] = ifu_araddr;
assign ifu_rvalid = rvalid[0];
assign rready[0] = ifu_rready;
assign ifu_rdata = rdata[0];

wire arbiter_awvalid_out, arbiter_wvalid_out, arbiter_arvalid_out;
wire arbiter_rready_out, arbiter_bready_out;
wire [31:0] arbiter_araddr_out, arbiter_awaddr_out;
wire [31:0] arbiter_wdata_out;
wire [3:0] arbiter_wstrb_out;
wire [2:0] arbiter_awsize_out, arbiter_arsize_out;

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
  .awsize(awsize),
  .arsize(arsize),

  // subordinate interface - 连接到中间信号
  .awvalid_out(arbiter_awvalid_out), 
  .wvalid_out(arbiter_wvalid_out),  
  .arvalid_out(arbiter_arvalid_out), 
  .rready_out(arbiter_rready_out),
  .bready_out(arbiter_bready_out),
  .bvalid_in(ext_bvalid_mux),
  .rvalid_in(ext_rvalid_mux),
  .awready_in(ext_awready_mux),  
  .wready_in(ext_wready_mux),   
  .arready_in(ext_arready_mux),

  .araddr_out(arbiter_araddr_out),
  .awaddr_out(arbiter_awaddr_out),
  .wdata_out(arbiter_wdata_out),
  .wstrb_out(arbiter_wstrb_out),
  .rdata_in(ext_rdata_mux),
  .bresp_in(ext_bresp_mux),
  .awsize_out(arbiter_awsize_out),
  .arsize_out(arbiter_arsize_out)
);
  assign io_master_arburst = 2'b01;
  assign io_master_arlen = 0;

  assign io_master_awburst = 2'b01;
  assign io_master_arlen = 0;

  // ---------------------------------
  // CLINT (Core Local Interruptor)
  // ---------------------------------
  // CLINT地址范围：0x02000000 - 0x0200ffff
  // 从arbiter的输出地址判断是否选中CLINT
  wire clint_ar_sel = (arbiter_araddr_out >= 32'h02000000) && (arbiter_araddr_out <= 32'h0200ffff);
  wire clint_aw_sel = (arbiter_awaddr_out >= 32'h02000000) && (arbiter_awaddr_out <= 32'h0200ffff);

  // CLINT接口信号
  wire clint_awvalid, clint_awready;
  wire clint_wvalid, clint_wready;
  wire clint_arvalid, clint_arready;
  wire clint_rvalid, clint_rready;
  wire clint_bvalid, clint_bready;
  wire [31:0] clint_araddr, clint_awaddr;
  wire [31:0] clint_wdata, clint_rdata;
  wire [3:0] clint_wstrb;
  wire [1:0] clint_bresp;
  wire [2:0] clint_awsize, clint_arsize;

  // 实例化CLINT模块
  ysyx_24100007_clint clint0(
    .clk(clock),
    .reset(reset),
    
    .awvalid(clint_awvalid),
    .awready(clint_awready),
    .awaddr(clint_awaddr),
    .awsize(clint_awsize),
    
    .wvalid(clint_wvalid),
    .wready(clint_wready),
    .wdata(clint_wdata),
    .wstrb(clint_wstrb),
    
    .arvalid(clint_arvalid),
    .arready(clint_arready),
    .araddr(clint_araddr),
    .arsize(clint_arsize),
    
    .rvalid(clint_rvalid),
    .rready(clint_rready),
    .rdata(clint_rdata),
    
    .bvalid(clint_bvalid),
    .bready(clint_bready),
    .bresp(clint_bresp)
  );

  // CLINT信号连接（从arbiter输出获取，仅在地址匹配时有效）
  assign clint_awvalid = arbiter_awvalid_out && clint_aw_sel;
  assign clint_wvalid = arbiter_wvalid_out && clint_aw_sel;
  assign clint_arvalid = arbiter_arvalid_out && clint_ar_sel;
  assign clint_rready = arbiter_rready_out && clint_ar_sel;
  assign clint_bready = arbiter_bready_out && clint_aw_sel;
  assign clint_awaddr = arbiter_awaddr_out;
  assign clint_araddr = arbiter_araddr_out;
  assign clint_wdata = arbiter_wdata_out;
  assign clint_wstrb = arbiter_wstrb_out;
  assign clint_awsize = arbiter_awsize_out;
  assign clint_arsize = arbiter_arsize_out;

  // 地址解码和响应选择：当选中CLINT时，屏蔽io_master的输出，使用CLINT的响应
  // 否则，使用外部设备的响应
  // 屏蔽io_master输出（当选中CLINT时）
  assign io_master_awvalid = arbiter_awvalid_out && ~clint_aw_sel;
  assign io_master_wvalid = arbiter_wvalid_out && ~clint_aw_sel;
  assign io_master_arvalid = arbiter_arvalid_out && ~clint_ar_sel;
  assign io_master_rready = arbiter_rready_out && ~clint_ar_sel;
  assign io_master_bready = arbiter_bready_out && ~clint_aw_sel;
  assign io_master_araddr = arbiter_araddr_out;
  assign io_master_awaddr = arbiter_awaddr_out;
  assign io_master_wdata = arbiter_wdata_out;
  assign io_master_wstrb = arbiter_wstrb_out;
  assign io_master_awsize = arbiter_awsize_out;
  assign io_master_arsize = arbiter_arsize_out;

  // 选择响应数据：CLINT或外部设备，返回给arbiter
  wire [31:0] ext_rdata_mux = clint_ar_sel ? clint_rdata : io_master_rdata;
  wire [1:0] ext_bresp_mux = clint_aw_sel ? clint_bresp : io_master_bresp;
  wire ext_rvalid_mux = clint_ar_sel ? clint_rvalid : io_master_rvalid;
  wire ext_bvalid_mux = clint_aw_sel ? clint_bvalid : io_master_bvalid;
  wire ext_awready_mux = clint_aw_sel ? clint_awready : io_master_awready;
  wire ext_wready_mux = clint_aw_sel ? clint_wready : io_master_wready;
  wire ext_arready_mux = clint_ar_sel ? clint_arready : io_master_arready;


endmodule
