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
  output [PORT_NUM*32-1:0] araddr,
  output [PORT_NUM*32-1:0] awaddr,
  output [PORT_NUM*32-1:0] wdata,
  output [PORT_NUM*4-1:0] wstrb,
  input  [PORT_NUM*32-1:0] rdata,
  input  [PORT_NUM*2-1:0] bresp,
  output [PORT_NUM*3-1:0] awsize,
  output [PORT_NUM*3-1:0] arsize,
  
  // AXI burst transfer signals
  output [PORT_NUM*8-1:0] awlen,
  output [PORT_NUM*8-1:0] arlen,
  output [PORT_NUM*2-1:0] awburst,
  output [PORT_NUM*2-1:0] arburst,
  output [PORT_NUM-1:0] wlast,
  input [PORT_NUM-1:0] rlast,
  input [PORT_NUM*2-1:0]  rresp
);

  // Pipeline handshake signals
  wire ifu_to_idu_valid;
  wire idu_to_exu_valid;
  wire exu_to_wbu_valid;
  
  wire idu_to_ifu_ready;
  wire exu_to_idu_ready;
  wire wbu_to_exu_ready;

  wire [31:0] npc, ifu_pc;
  wire [31:0] inst;

  wire ifu_read_req;
  wire ifu_req_acp;
  wire ifu_req_finish;
  wire ifu_req_ready;
  wire [31:0] ifu_addr;
  wire [127:0] lsu_data_read;

  ysyx_24100007_ifu ifu0(
    .clk(clock),
    .rst(reset),
    .exu_npc(npc),
    .ready(idu_to_ifu_ready), // IDU to IFU ready
    .pc(ifu_pc),
    .inst(inst),
    .valid(ifu_to_idu_valid),
    .is_jmp(is_jmp),

    .ifu_read_req (ifu_read_req),
    .ifu_req_acp  (ifu_req_acp),
    .ifu_req_finish(ifu_req_finish),
    .ifu_req_ready(ifu_req_ready),
    .ifu_addr     (ifu_addr),
    .ifu_line_data(lsu_data_read)
  );

  wire [4:0] src1_addr, src2_addr, idu_rd;
  wire [31:0] imm;
  wire ebreaksig, mretsig, ecallsig;
  wire memew, memer, muximm;
  wire [2:0] func3, muxsig;
  wire func7;
  wire btypebranch, jalsig, jalrsig, auipcsig;
  wire [1:0] aluop;
  wire csrrw, csrrs;
  wire [11:0] csr_addr;
  wire [2:0] memmask;
  wire memsextsig;
  wire regew_control;
  wire [31:0] idu_pc;
  wire [31:0] src1_data, src2_data;
  ysyx_24100007_idu idu0(
  .clk(clock),
  .rst(reset),
  .inst_in(inst),
  .in_valid(ifu_to_idu_valid),
  .in_ready(idu_to_ifu_ready), 
  .out_valid(idu_to_exu_valid),
  .out_ready(exu_to_idu_ready), // IDU to IFU ready
  .is_jmp(is_jmp),
  .pc_in(ifu_pc),

  .regout1(regout1),              // 从寄存器堆读出的数据
  .regout2(regout2),              // 从寄存器堆读出的数据

  .wbu_rd(wbu_rd_bypass),                // WBU 旁路接口
  .wbu_regew(wbu_regew_bypass),          // WBU 旁路接口
  .wbu_transmit_data(wbu_transmit_data),      // WBU 旁路接口
  .wbu_transmit_data_valid(wbu_transmit_data_valid), // WBU 旁路接口

  .exu_rd(exu_rd_bypass),                // EXU 旁路接口
  .exu_regew(exu_regew_bypass),          // EXU 旁路接口
  .exu_transmit_data(exu_transmit_data), // EXU 旁路接口
  .exu_transmit_data_valid(exu_transmit_data_valid), // EXU 旁路接口
  .exu_memer_bypass(exu_memer_bypass),  // EXU 是否是 load 指令（用于处理 load-use 冲突）

  .src1_data(src1_data),          // 经过旁路选择后的数据
  .src2_data(src2_data),          // 经过旁路选择后的数据

  .ebreaksig(ebreaksig),
  .ecallsig(ecallsig),
  .mretsig(mretsig),
  .imm(imm),
  .func3(func3),
  .func7(func7),
  .src1_addr(src1_addr),
  .src2_addr(src2_addr),
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
  .csr_addr(csr_addr),
  .memmask(memmask),
  .memsextsig(memsextsig),
  .pc_out(idu_pc)
);

  wire [31:0] regwrite, regout1, regout2;
  wire [31:0] mepc, mtvec;
  ysyx_24100007_regheap regfile(
    .clk(clock),
    .rst(reset),
    .ew(regew),
    .addr(wbu_reg_rd),
    .src1(src1_addr),             // 使用 IDU 输出的源寄存器地址
    .src2(src2_addr),             // 使用 IDU 输出的源寄存器地址
    .data(regwrite),
    .csr(wbu_csr_addr_out),       // 使用 WBU 阶段的 CSR 地址
    .csrrw(wbu_csrrw_out),        // 使用 WBU 阶段的 csrrw 信号
    .csrrs(wbu_csrrs_out),        // 使用 WBU 阶段的 csrrs 信号
    .ecallsig(wbu_ecallsig_out),  // 使用 WBU 阶段的 ecallsig 信号
    .regout1(regout1),            // 寄存器堆输出连接到 IDU
    .regout2(regout2),            // 寄存器堆输出连接到 IDU
    .mepc(mepc),
    .mtvec(mtvec)
  ); 
  
  wire [31:0] res;
  wire [31:0] link_addr;
  wire is_jmp;
  wire [4:0] exu_rd;  // EXU 的 rd_out（用于 WBU）

  // Signals from EXU to WBU
  wire exu_memew, exu_memer, exu_regew_control;
  wire [2:0] exu_muxsig, exu_func3;
  wire [31:0] exu_src2_out;  // src2 from EXU to WBU
  wire [31:0] exu_imm_out;   // imm from EXU to WBU
  wire exu_csrrw_out, exu_csrrs_out;
  wire [11:0] exu_csr_addr_out;
  wire exu_ecallsig_out;

  // EXU 向 IDU 转发的旁路信号
  wire [4:0] exu_rd_bypass;               // EXU 阶段的 rd（用于旁路）
  wire exu_regew_bypass;                  // EXU 阶段的写使能（用于旁路）
  wire [31:0] exu_transmit_data;          // EXU 阶段的计算结果（用于旁路）
  wire exu_transmit_data_valid;           // EXU 阶段的旁路数据有效信号
  wire exu_memer_bypass;                  // EXU 阶段是否是 load 指令（用于处理 load-use 冲突）
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
  .pc_in(idu_pc),
  .auipcsig_in(auipcsig),

  .mretsig_in(mretsig),
  .ecallsig_in(ecallsig),
  .mtvec_in(mtvec),
  .mepc_in(mepc),

  .memew_in(memew),
  .memer_in(memer),
  .muxsig_in(muxsig),
  .regew_control_in(regew_control),
  .rd_in(idu_rd),
  .csrrw_in(csrrw),
  .csrrs_in(csrrs),
  .csr_addr_in(csr_addr),
  .wbu_write_csr(wbu_write_csr),

  .src1_in(src1_data),         // 使用 IDU 经过旁路选择后的数据
  .src2_in(src2_data),         // 使用 IDU 经过旁路选择后的数据

  .res(res),
  .npc(npc),
  .link_addr(link_addr),
  .src2_out(exu_src2_out),           // to WBU
  .imm_out(exu_imm_out),             // to WBU
  .is_jmp(is_jmp),

  .memew_out(exu_memew),             // to WBU
  .memer_out(exu_memer),             // to WBU
  .muxsig_out(exu_muxsig),            // to WBU
  .func3_out(exu_func3),             // to WBU
  .regew_control_out(exu_regew_control),     // to WBU
  .rd_out(exu_rd),
  .csrrw_out(exu_csrrw_out),            // to WBU
  .csrrs_out(exu_csrrs_out),            // to WBU
  .csr_addr_out(exu_csr_addr_out),      // to WBU
  .ecallsig_out(exu_ecallsig_out),      // to WBU

  // EXU 向 IDU 转发的旁路信号
  .exu_rd(exu_rd_bypass),
  .exu_regew(exu_regew_bypass),
  .exu_transmit_data(exu_transmit_data),
  .exu_transmit_data_valid(exu_transmit_data_valid),
  .exu_memer_bypass(exu_memer_bypass)
);

  wire regew;

  // WBU 向 IDU 转发的旁路信号
  wire [4:0] wbu_rd_bypass;               // WBU 阶段的 rd（用于旁路）
  wire wbu_regew_bypass;                  // WBU 阶段的写使能（用于旁路）
  wire [31:0] wbu_transmit_data;          // WBU 阶段的写回数据（用于旁路）
  wire wbu_transmit_data_valid;           // WBU 阶段的旁路数据有效信号
  wire [4:0] wbu_reg_rd;
  wire wbu_commit;
  wire wbu_csrrw_out, wbu_csrrs_out;
  wire [11:0] wbu_csr_addr_out;
  wire wbu_ecallsig_out;
  wire wbu_write_csr;

  wire wbu_read_req, wbu_write_req;
  wire wbu_req_acp, wbu_req_finish, wbu_req_ready;
  wire lsu_mem_we;
  wire [31:0] lsu_mem_addr, lsu_mem_wdata;
  wire [2:0] lsu_mem_mask;
  wire lsu_mem_sext;
  ysyx_24100007_wbu wbu0(
  .clk(clock),
  .rst(reset),
  .res_in(res),
  .regout2_in(exu_src2_out),  // 使用从EXU传递的src2（已通过旁路选择）
  .memew_in(exu_memew),
  .memer_in(exu_memer),
  .imm_in(exu_imm_out),        // 使用从EXU传递的imm（已通过流水线寄存器）
  .link_addr_in(link_addr),
  
  .muxsig_in(exu_muxsig),
  .func3_in(exu_func3),
  .regew_control_in(exu_regew_control),
  .rd_in(exu_rd),
  .csrrw_in(exu_csrrw_out),
  .csrrs_in(exu_csrrs_out),
  .csr_addr_in(exu_csr_addr_out),
  .ecallsig_in(exu_ecallsig_out),

  .regwrite_out(regwrite),
  .regew_out(regew),
  .rd_out(wbu_reg_rd),
  .csrrw_out(wbu_csrrw_out),
  .csrrs_out(wbu_csrrs_out),
  .csr_addr_out(wbu_csr_addr_out),
  .ecallsig_out(wbu_ecallsig_out),
  .wbu_write_csr(wbu_write_csr),

  .in_valid(exu_to_wbu_valid),
  .in_ready(wbu_to_exu_ready), // WBU to EXU ready

  .wbu_commit(wbu_commit),

  .wbu_read_req (wbu_read_req),
  .wbu_write_req(wbu_write_req),
  .wbu_req_acp  (wbu_req_acp),
  .wbu_req_finish(wbu_req_finish),
  .wbu_req_ready(wbu_req_ready),
  .wbu_data_read(lsu_data_read[31:0]),

  .lsu_mem_we   (lsu_mem_we),
  .lsu_mem_addr (lsu_mem_addr),
  .lsu_mem_wdata(lsu_mem_wdata),
  .lsu_mem_mask (lsu_mem_mask),
  .lsu_mem_sext (lsu_mem_sext),

  .wbu_rd(wbu_rd_bypass),      // for data forwarding to IDU
  .wbu_regew(wbu_regew_bypass),   // for data forwarding to IDU
  .transmit_data(wbu_transmit_data),     // for data forwarding to IDU
  .transmit_data_valid(wbu_transmit_data_valid) // for data forwarding to IDU
);

ysyx_24100007_lsu lsu0 (
  .clk   (clock),
  .rst   (reset),

  .ifu_read_req (ifu_read_req),
  .ifu_req_acp  (ifu_req_acp),
  .ifu_addr_in  (ifu_addr),

  .wbu_read_req (wbu_read_req),
  .wbu_write_req(wbu_write_req),
  .wbu_req_acp  (wbu_req_acp),

  .ifu_req_ready (ifu_req_ready),
  .ifu_req_finish(ifu_req_finish),
  .wbu_req_ready (wbu_req_ready),
  .wbu_req_finish(wbu_req_finish),

  .mem_we_in    (lsu_mem_we),
  .mem_addr_in  (lsu_mem_addr),
  .mem_wdata_in (lsu_mem_wdata),
  .mem_mask_in  (lsu_mem_mask),
  .mem_sext_in  (lsu_mem_sext),

  .data_read (lsu_data_read),

  // AXI master 接到 core port[1]
  .arvalid (arvalid),
  .arready (arready),
  .araddr  (araddr),
  .arlen   (arlen),
  .arsize  (arsize),
  .arburst (arburst),

  .awvalid (awvalid),
  .awready (awready),
  .awaddr  (awaddr),
  .awlen   (awlen),
  .awsize  (awsize),
  .awburst (awburst),

  .wvalid (wvalid),
  .wready (wready),
  .wdata  (wdata),
  .wstrb  (wstrb),
  .wlast  (wlast),

  .rvalid (rvalid),
  .rready (rready),
  .rdata  (rdata),
  .rlast  (rlast),

  .bvalid (bvalid),
  .bready (bready),
  .bresp  (bresp)
);


// synopsys translate_off
  ysyx_24100007_pipline_tracer tracer0(
    .clk(clock), 
    
    .ifu_to_idu_valid(ifu_to_idu_valid),
    .idu_to_exu_valid(idu_to_exu_valid),
    .exu_to_wbu_valid(exu_to_wbu_valid),
    
    .idu_to_ifu_ready(idu_to_ifu_ready),
    .exu_to_idu_ready(exu_to_idu_ready),
    .wbu_to_exu_ready(wbu_to_exu_ready),
    
    .is_jmp(is_jmp),
    .wbu_commit(wbu_commit), 
    
    .pc(ifu_pc),
    .inst(inst)
  );

// synopsys translate_on

endmodule

// synopsys translate_off
module ysyx_24100007_pipline_tracer(
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
  import "DPI-C" function void npc_get_current_pc(int pc);

  reg commit_sys;
  reg [31:0] commit_pc_sys;
  reg [31:0] commit_inst_sys;

  always @(posedge clk) begin
    commit_sys <= wbu_commit;
    commit_pc_sys <= wbu_pc;
    commit_inst_sys <= wbu_inst;
  end

  always @(posedge clk) begin
    npc_get_current_pc(pc);
    get_predict_miss({31'b0, is_jmp});
    npc_commit_inst({31'b0, commit_sys}, commit_pc_sys, commit_inst_sys); 
  end

  wire dead_cyc = (wbu_inst == 32'h0000006f);
  always @(posedge clk) begin
    if(dead_cyc & wbu_commit) begin
      ret(0);
    end
  end
endmodule
// synopsys translate_on