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

  // Pipeline handshake signals
  wire ifu_to_idu_valid;
  wire idu_to_exu_valid;
  wire exu_to_wbu_valid;
  
  wire idu_to_ifu_ready;
  wire exu_to_idu_ready;
  wire wbu_to_exu_ready;

  wire [31:0] npc, pcbridge;
  wire [31:0] inst;

  ysyx_24100007_ifu ifu0(
    .clk(clock),
    .rst(reset),
    .exu_npc(npc),
    .ready(idu_to_ifu_ready), // IDU to IFU ready
    .pc(pcbridge),
    .inst(inst),
    .valid(ifu_to_idu_valid),
    .icahce_flush(icahce_flush),
    .icahce_flush_addr(res),
    .is_jmp(is_jmp),

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


  wire [4:0] src1, src2, idu_rd;
  wire [31:0] imm;
  wire ebreaksig, mretsig, ecallsig;
  wire memew, memer, muximm;
  wire [2:0] func3, muxsig;
  wire func7;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  wire csrrw, csrrs;
  wire [2:0] memmask;
  wire memsextsig;
  wire regew_control;
  ysyx_24100007_idu idu0(
  .clk(clock),
  .rst(reset),
  .inst_in(inst),
  .in_valid(ifu_to_idu_valid),
  .in_ready(idu_to_ifu_ready), 
  .out_valid(idu_to_exu_valid),
  .out_ready(exu_to_idu_ready), // IDU to IFU ready
  .is_jmp(is_jmp),

  .ebreaksig(ebreaksig),
  .ecallsig(ecallsig),
  .mretsig(mretsig),
  .imm(imm),
  .func3(func3),
  .func7(func7),
  .src1(src1),
  .src2(src2),
  .rd(idu_rd),
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
  .memsextsig(memsextsig)
);

  wire [31:0] regwrite, regout1, regout2;
  wire [31:0] mepc, mtvec;
  ysyx_24100007_regheap regfile(
    .clk(clock),
    .rst(reset),
    .ew(regew),
    .addr(wbu_reg_rd),
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
  wire is_jmp;
  wire [4:0] exu_rd;

  // Signals from EXU to WBU
  wire exu_memew, exu_memer, exu_memsextsig, exu_regew_control;
  wire [2:0] exu_muxsig, exu_memmask;
  ysyx_24100007_exu exu0(
  .clk(clock),
  .rst(reset),

  .in_valid(idu_to_exu_valid),
  .in_ready(exu_to_idu_ready),  // WBU to EXU ready
  .out_ready(wbu_to_exu_ready), // EXU to IDU ready
  .out_valid(exu_to_wbu_valid),

  .func3_in(func3),
  .btypebranch_in(btypebranch),
  .func7_in(func7),
  .aluop_in(aluop),
  .jalrsig_in(jalrsig),
  .jalsig_in(jalsig),
  .imm_in(imm),
  .muximm_in(muximm),
  .src1_addr_in(src1),
  .src2_addr_in(src2),
  .pc_in(pcbridge),
  .auipcsig_in(auipcsig),
  .mretsig_in(mretsig),
  .ecallsig_in(ecallsig),
  .mtvec_in(mtvec),
  .mepc_in(mepc),

  .memew_in(memew),
  .memer_in(memer),
  .muxsig_in(muxsig),
  .memmask_in(memmask),
  .memsextsig_in(memsextsig),
  .regew_control_in(regew_control),
  .rd_in(idu_rd),

  .regout1_in(regout1),
  .regout2_in(regout2),
  .prev_rd(wbu_rd),          // from WBU stage for hazard detection
  .prev_regew(wbu_regew),    // from WBU stage for hazard detection
  .transmit_data(transmit_data),    // from WBU for forwarding
  .transmit_data_valid(transmit_data_valid), // from WBU for forwarding

  .res(res),
  .npc(npc),
  .link_addr(link_addr),
  .is_jmp(is_jmp),

  .memew_out(exu_memew),             // to WBU
  .memer_out(exu_memer),             // to WBU
  .muxsig_out(exu_muxsig),            // to WBU
  .memmask_out(exu_memmask),           // to WBU
  .memsextsig_out(exu_memsextsig),        // to WBU
  .regew_control_out(exu_regew_control),     // to WBU
  .rd_out(exu_rd)
);

  wire regew;
  wire icahce_flush;
  wire [4:0] wbu_rd;
  wire wbu_regew;
  wire [31:0] transmit_data;
  wire transmit_data_valid;
  wire [4:0] wbu_reg_rd;
  wire wbu_commit;
  ysyx_24100007_wbu wbu0(
  .clk(clock),
  .rst(reset),
  .res_in(res),
  .regout2_in(regout2),
  .memew_in(exu_memew),
  .memer_in(exu_memer),
  .imm_in(imm),
  .link_addr_in(link_addr),
  .muxsig_in(exu_muxsig),
  .memsextsig_in(exu_memsextsig),
  .memmask_in(exu_memmask),
  .regew_control_in(exu_regew_control),
  .rd_in(exu_rd),

  .regwrite_out(regwrite),
  .regew_out(regew),
  .rd_out(wbu_reg_rd),

  .in_valid(exu_to_wbu_valid),
  .in_ready(wbu_to_exu_ready), // WBU to EXU ready

  .icahce_flush(icahce_flush),
  .wbu_commit(wbu_commit),

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
  .awburst(awburst[1]),

  .wbu_rd(wbu_rd),      // for hazard detection in EXU
  .wbu_regew(wbu_regew),   // for hazard detection in EXU
  .transmit_data(transmit_data),     // for data forwarding to EXU
  .transmit_data_valid(transmit_data_valid) // for data forwarding to EXU
);

  pipline_tracer tracer0(
    .clk(clock), 
    
    .ifu_to_idu_valid(ifu_to_idu_valid),
    .idu_to_exu_valid(idu_to_exu_valid),
    .exu_to_wbu_valid(exu_to_wbu_valid),
    
    .idu_to_ifu_ready(idu_to_ifu_ready),
    .exu_to_idu_ready(exu_to_idu_ready),
    .wbu_to_exu_ready(wbu_to_exu_ready),
    
    .is_jmp(is_jmp),
    .wbu_commit(wbu_commit), 
    
    .pc(pcbridge),
    .inst(inst)
  );

// 暂时不实现突发传输，将没有使用的部分设置为0
assign awlen[1] = 8'b0;      // 写地址长度（单次传输，len=0）
assign arlen[1] = 8'b0;      // 读地址长度（单次传输，len=0）
assign arburst[1] = 2'b0;   // 读burst类型（FIXED，单次传输）
assign wlast[1] = wvalid[1];

endmodule

module pipline_tracer(
  input clk,

  input ifu_to_idu_valid,
  input idu_to_exu_valid,
  input exu_to_wbu_valid,
  
  input idu_to_ifu_ready,
  input exu_to_idu_ready,
  input wbu_to_exu_ready,

  input is_jmp,
  input wbu_commit,

  input [31:0] pc,
  input [31:0] inst
);

  reg [31:0] idu_pc, idu_inst;
  reg [31:0] exu_pc, exu_inst;
  reg [31:0] wbu_pc, wbu_inst;

  always @(posedge clk) begin
    if(is_jmp) begin
      idu_pc <= 32'b0;
      idu_inst <= 32'b0;
    end else if(ifu_to_idu_valid && idu_to_ifu_ready) begin
      idu_pc <= pc;
      idu_inst <= inst;
    end

    if(idu_to_exu_valid && exu_to_idu_ready) begin
      exu_pc <= idu_pc;
      exu_inst <= idu_inst;
    end 

    if(exu_to_wbu_valid && wbu_to_exu_ready) begin
      wbu_pc <= exu_pc;
      wbu_inst <= exu_inst;
    end 
  end 

  import "DPI-C" function void npc_commit_inst(int valid, int pc, int inst);
  import "DPI-C" function void get_predict_miss(int is_jmp);
  always @(posedge clk) begin
    npc_commit_inst({31'b0, wbu_commit}, wbu_pc, wbu_inst);  
    get_predict_miss({31'b0, is_jmp});
  end
endmodule