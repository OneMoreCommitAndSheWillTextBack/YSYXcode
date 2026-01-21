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

  // Core模块 - 包含CPU核心和AXI接口
  wire [1:0] core_awvalid, core_wvalid, core_arvalid;
  wire [1:0] core_rready, core_bready;
  wire [1:0] core_bvalid, core_rvalid;
  wire [1:0] core_awready, core_wready, core_arready;
  wire [63:0] core_araddr, core_awaddr;
  wire [63:0] core_wdata, core_rdata;
  wire [7:0] core_wstrb;
  wire [3:0] core_bresp;
  wire [5:0] core_awsize, core_arsize;
  wire [15:0] core_awlen, core_arlen;
  wire [3:0] core_awburst, core_arburst;
  wire [1:0] core_wlast, core_rlast;
  wire [1:0] core_trans_end, core_trans_start;
  wire [3:0] core_rresp;

  ysyx_24100007_core #(.PORT_NUM(2)) core0(
    .clock(clock),
    .reset(reset),
    .io_interrupt(io_interrupt),

    // AXI接口连接到arbiter
    .awvalid(core_awvalid),
    .wvalid(core_wvalid),
    .arvalid(core_arvalid),
    .rready(core_rready),
    .bready(core_bready),
    .bvalid(core_bvalid),
    .rvalid(core_rvalid),
    .awready(core_awready),
    .wready(core_wready),
    .arready(core_arready),
    .araddr(core_araddr),
    .awaddr(core_awaddr),
    .wdata(core_wdata),
    .rdata(core_rdata),
    .wstrb(core_wstrb),
    .bresp(core_bresp),
    .awsize(core_awsize),
    .arsize(core_arsize),
    .awlen(core_awlen),
    .arlen(core_arlen),
    .awburst(core_awburst),
    .arburst(core_arburst),
    .wlast(core_wlast),
    .rlast(core_rlast),
    .rresp(core_rresp),
    .trans_start(core_trans_start),
    .trans_end(core_trans_end)
  );

  assign core_rresp[1:0] = io_master_rresp;
  assign core_rresp[3:2] = io_master_rresp;

  // Arbiter模块
  wire [63:0] arbiter_araddr_out, arbiter_awaddr_out;
  wire [63:0] arbiter_wdata_out;
  wire [7:0] arbiter_wstrb_out;
  wire [5:0] arbiter_awsize_out, arbiter_arsize_out;
  wire [15:0] arbiter_awlen_out, arbiter_arlen_out;
  wire [3:0] arbiter_awburst_out, arbiter_arburst_out;
  wire [1:0] arbiter_wlast_out;
  wire [1:0] arbiter_awvalid_out, arbiter_wvalid_out, arbiter_arvalid_out;
  wire [1:0] arbiter_rready_out, arbiter_bready_out;
  wire [1:0] arbiter_bvalid_in, arbiter_rvalid_in;
  wire [1:0] arbiter_awready_in, arbiter_wready_in, arbiter_arready_in;
  wire [63:0] arbiter_rdata_in;
  wire [3:0] arbiter_bresp_in;
  wire [1:0] arbiter_rlast_in;

  ysyx_24100007_arbiter #(.MASTER_NUM(2), .SLAVE_NUM(2)) arbiter0(
    .clk(clock),
    .rst(reset),

    // Master接口 - 来自core
    .awvalid(core_awvalid),
    .wvalid(core_wvalid),
    .arvalid(core_arvalid),
    .rready(core_rready),
    .bready(core_bready),
    .bvalid(core_bvalid),
    .rvalid(core_rvalid),
    .awready(core_awready),
    .wready(core_wready),
    .arready(core_arready),
    .araddr(core_araddr),
    .awaddr(core_awaddr),
    .wdata(core_wdata),
    .rdata(core_rdata),
    .wstrb(core_wstrb),
    .bresp(core_bresp),
    .awsize(core_awsize),
    .arsize(core_arsize),
    .awlen(core_awlen),
    .arlen(core_arlen),
    .awburst(core_awburst),
    .arburst(core_arburst),
    .wlast(core_wlast),
    .rlast(core_rlast),
    .trans_start(core_trans_start),
    .trans_end(core_trans_end),

    // Slave接口 - 连接到CLINT和外部AXI
    .awvalid_out(arbiter_awvalid_out),
    .wvalid_out(arbiter_wvalid_out),
    .arvalid_out(arbiter_arvalid_out),
    .rready_out(arbiter_rready_out),
    .bready_out(arbiter_bready_out),
    .bvalid_in(arbiter_bvalid_in),
    .rvalid_in(arbiter_rvalid_in),
    .awready_in(arbiter_awready_in),
    .wready_in(arbiter_wready_in),
    .arready_in(arbiter_arready_in),
    .araddr_out(arbiter_araddr_out),
    .awaddr_out(arbiter_awaddr_out),
    .wdata_out(arbiter_wdata_out),
    .wstrb_out(arbiter_wstrb_out),
    .rdata_in(arbiter_rdata_in),
    .bresp_in(arbiter_bresp_in),
    .awsize_out(arbiter_awsize_out),
    .arsize_out(arbiter_arsize_out),
    .awlen_out(arbiter_awlen_out),
    .arlen_out(arbiter_arlen_out),
    .awburst_out(arbiter_awburst_out),
    .arburst_out(arbiter_arburst_out),
    .wlast_out(arbiter_wlast_out),
    .rlast_in(arbiter_rlast_in)
  );

  // ---------------------------------
  // CLINT (Core Local Interruptor)
  // ---------------------------------
  // CLINT地址范围：0x02000000 - 0x0200ffff
    ysyx_24100007_clint clint0(
    .clk(clock),
    .reset(reset),
    .awvalid(arbiter_awvalid_out[1]),
    .awready(arbiter_awready_in[1]),
    .awaddr(arbiter_awaddr_out[63:32]),
    .awsize(arbiter_awsize_out[5:3]),
    .wvalid(arbiter_wvalid_out[1]),
    .wready(arbiter_wready_in[1]),
    .wdata(arbiter_wdata_out[63:32]),
    .wstrb(arbiter_wstrb_out[7:4]),
    .arvalid(arbiter_arvalid_out[1]),
    .arready(arbiter_arready_in[1]),
    .araddr(arbiter_araddr_out[63:32]),
    .arsize(arbiter_arsize_out[5:3]),
    .rvalid(arbiter_rvalid_in[1]),
    .rready(arbiter_rready_out[1]),
    .rdata(arbiter_rdata_in[63:32]),
    .bvalid(arbiter_bvalid_in[1]),
    .bready(arbiter_bready_out[1]),
    .bresp(arbiter_bresp_in[3:2])
  );

    // 外部AXI接口直接连接到arbiter slave[0]
  assign io_master_awvalid = arbiter_awvalid_out[0];
  assign io_master_wvalid = arbiter_wvalid_out[0];
  assign io_master_arvalid = arbiter_arvalid_out[0];
  assign io_master_rready = arbiter_rready_out[0];
  assign io_master_bready = arbiter_bready_out[0];
  assign io_master_araddr = arbiter_araddr_out[31:0];
  assign io_master_awaddr = arbiter_awaddr_out[31:0];
  assign io_master_wdata = arbiter_wdata_out[31:0];
  assign io_master_wstrb = arbiter_wstrb_out[3:0];
  assign io_master_awsize = arbiter_awsize_out[2:0];
  assign io_master_arsize = arbiter_arsize_out[2:0];
  assign io_master_awlen = arbiter_awlen_out[7:0];
  assign io_master_arlen = arbiter_arlen_out[7:0];
  assign io_master_awburst = arbiter_awburst_out[1:0];
  assign io_master_arburst = arbiter_arburst_out[1:0];
  assign io_master_wlast = arbiter_wlast_out[0];

  // arbiter slave[0]输入来自外部AXI
  assign arbiter_bvalid_in[0] = io_master_bvalid;
  assign arbiter_rvalid_in[0] = io_master_rvalid;
  assign arbiter_awready_in[0] = io_master_awready;
  assign arbiter_wready_in[0] = io_master_wready;
  assign arbiter_arready_in[0] = io_master_arready;
  assign arbiter_rdata_in[31:0] = io_master_rdata;
  assign arbiter_bresp_in[1:0] = io_master_bresp;
  assign arbiter_rlast_in[0] = io_master_rlast;

  assign arbiter_rlast_in[1] = arbiter_rvalid_in[1];

  assign io_master_awid = 4'b0;
  assign io_master_arid = 4'd0;

  assign io_slave_awready = 1'b0;
  assign io_slave_wready  = 1'b0;
  assign io_slave_bvalid  = 1'b0;
  assign io_slave_bresp   = 2'b00;
  assign io_slave_bid     = 4'b0000;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid  = 1'b0;
  assign io_slave_rresp   = 2'b00;
  assign io_slave_rdata   = 32'b0;
  assign io_slave_rlast   = 1'b0;
  assign io_slave_rid     = 4'b0000;

endmodule

module ysyx_24100007_regheap(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [4:0] src1,
  input [4:0] src2,
  input [11:0] csr,
  input [31:0] data,
  input csrrw,
  input csrrs,
  input ecallsig,
  output [31:0] regout1,
  output [31:0] regout2,
  output [31:0] mepc,
  output [31:0] mtvec
);


  wire [32*32-1:0] rf_flat;
  wire [32*6-1:0] rf_csr_flat;
  wire [2:0] csr_choose;
  wire [31:0] reg_write_data;
  wire [31:0] rf_src1_word;
  wire [31:0] rf_src2_word;

  // pay attention that the src1 should not be direct use
  assign rf_src1_word = rf_flat[src1*32 +: 32];
  assign rf_src2_word = rf_flat[src2*32 +: 32];
  assign reg_write_data = data;

  ysyx_24100007_MuxKey#(6, 12, 3) muxcsr(csr_choose, csr, {
    12'h300, 3'b000, // mstatus
    12'h305, 3'b001, // mtvec
    12'h341, 3'b010, // mepc
    12'h342, 3'b011, // mcause
    12'hf11, 3'b100, // mvendorid
    12'hf12, 3'b101  // marchid
});

  ysyx_24100007_registers registers0(
    .clk(clk),
    .rst(rst),
    .ew(ew),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .ecall(ecallsig),
    .addr(addr),
    .csr_choose(csr_choose),
    .data(reg_write_data),
    .gr_flat(rf_flat),
    .csr_flat(rf_csr_flat)
  );

  assign regout1 = (src1 == 0) ? 0 : rf_src1_word;
  assign regout2 = (src2 == 0) ? 0 : rf_src2_word;

  assign mepc = rf_csr_flat[2*32 +: 32];
  assign mtvec = rf_csr_flat[1*32 +: 32];

endmodule

// synopsys translate_off
import "DPI-C" function void host_get_reg(int regval, int regnum);
import "DPI-C" function void host_get_csr(int csrval, int csrnum);
// synopsys translate_on
module ysyx_24100007_registers(
  input clk,
  input rst,
  input ew,
  input csrrw,
  input csrrs,
  input ecall,
  input [2:0]csr_choose,
  input [4:0] addr,
  input [31:0] data,
  output [32*32-1:0] gr_flat,
  output [32*6-1:0] csr_flat
);
  
  reg [31:0] gr [31:0];
  reg [31:0] csr [5:0];

  // write op
  always @(posedge clk) begin 
    if(rst) begin
      // 手动展开循环，避免综合工具误判
      gr[1] <= 0;
      gr[2] <= 0;
      gr[3] <= 0;
      gr[4] <= 0;
      gr[5] <= 0;
      gr[6] <= 0;
      gr[7] <= 0;
      gr[8] <= 0;
      gr[9] <= 0;
      gr[10] <= 0;
      gr[11] <= 0;
      gr[12] <= 0;
      gr[13] <= 0;
      gr[14] <= 0;
      gr[15] <= 0;
      gr[16] <= 0;
      gr[17] <= 0;
      gr[18] <= 0;
      gr[19] <= 0;
      gr[20] <= 0;
      gr[21] <= 0;
      gr[22] <= 0;
      gr[23] <= 0;
      gr[24] <= 0;
      gr[25] <= 0;
      gr[26] <= 0;
      gr[27] <= 0;
      gr[28] <= 0;
      gr[29] <= 0;
      gr[30] <= 0;
      gr[31] <= 0;

      csr[0] <= 0;
      csr[1] <= 0;
      csr[2] <= 0;
      csr[3] <= 0;
      csr[4] <= 32'h79737978;
      csr[5] <= 32'h016FBCA7;
    end else begin

      // 使用互斥的条件，避免多驱动
      if(csrrw) begin
        // $display("csrrw: writing data 0x%08x to csr[%0d], addr=%0d, gr[%0d]", data, csr_choose, addr, addr);
        {gr[addr], csr[csr_choose]} <= {csr[csr_choose], data};
      end else if(csrrs) begin
        {gr[addr], csr[csr_choose]} <= {csr[csr_choose], data|csr[csr_choose]};
      end else if(ew) begin
        gr[addr] <= data;
        // $display("reg[%d] write a 0x%08x", addr, data);
      end

      if(ecall) begin
        csr[2] <= data;
        csr[3] <= 1;
      end
    end
  end

  // synopsys translate_off
  always @(*) begin
    integer i;
    host_get_reg(0, 0);
    for(i=1;i<32;i=i+1) begin
      host_get_reg(gr[i], i);
    end

    for(i=0;i<4;i++) begin
      host_get_csr(csr[i], i);
    end
  end
  // synopsys translate_on

  genvar gi;
  generate
    for (gi = 0; gi < 32; gi = gi + 1) begin: PACK_GR
      assign gr_flat[gi*32 +: 32] = gr[gi];
    end
  endgenerate

  genvar ci;
  generate
    for (ci = 0; ci < 6; ci = ci + 1) begin: PACK_CSR
      assign csr_flat[ci*32 +: 32] = csr[ci];
    end
  endgenerate

endmodule

// ---------------------------------------------
// version created at 2025/12/20 sunmingyang 
// comment:
//     now, I'm not satisfied by this version of
//  design. I prepare to design a pipline control
//  of the selector, but I think that I would waste
//  one cycle, after finish this version of arbiter
//  I want to add a protocol abstract layer of
//  mem access
// ---------------------------------------------
module ysyx_24100007_arbiter #(
  parameter MASTER_NUM=2,           // master设备数量（IFU, WBU）
  parameter SLAVE_NUM=2             // slave设备数量（CLINT, 外部AXI等）
)(
  input wire clk,
  input wire rst,

  // master interface
  input [MASTER_NUM-1:0] awvalid, 
  input [MASTER_NUM-1:0] wvalid,  
  input [MASTER_NUM-1:0] arvalid, 
  input [MASTER_NUM-1:0] rready,
  input [MASTER_NUM-1:0] bready,
  output [MASTER_NUM-1:0] bvalid,
  output [MASTER_NUM-1:0] rvalid,
  output [MASTER_NUM-1:0] awready, 
  output [MASTER_NUM-1:0] wready,  
  output [MASTER_NUM-1:0] arready, 

  // master data channel
  input [MASTER_NUM*32-1:0] araddr,
  input [MASTER_NUM*32-1:0] awaddr,
  input [MASTER_NUM*32-1:0] wdata,
  input [MASTER_NUM*4-1:0] wstrb,
  output [MASTER_NUM*32-1:0] rdata,
  output [MASTER_NUM*2-1:0] bresp,
  input [MASTER_NUM*3-1:0] awsize,
  input [MASTER_NUM*3-1:0] arsize,
  
  // master burst transfer signals
  input [MASTER_NUM*8-1:0] awlen,
  input [MASTER_NUM*8-1:0] arlen,
  input [MASTER_NUM*2-1:0] awburst,
  input [MASTER_NUM*2-1:0] arburst,
  input [MASTER_NUM-1:0] wlast,
  output [MASTER_NUM-1:0] rlast,

  // slave interface (连接到CLINT和外部AXI等)
  output [SLAVE_NUM-1:0] awvalid_out, 
  output [SLAVE_NUM-1:0] wvalid_out,  
  output [SLAVE_NUM-1:0] arvalid_out, 
  output [SLAVE_NUM-1:0] rready_out,
  output [SLAVE_NUM-1:0] bready_out,
  input [SLAVE_NUM-1:0] bvalid_in,
  input [SLAVE_NUM-1:0] rvalid_in,
  input [SLAVE_NUM-1:0] awready_in,  
  input [SLAVE_NUM-1:0] wready_in,   
  input [SLAVE_NUM-1:0] arready_in,

  output [SLAVE_NUM*32-1:0] araddr_out,
  output [SLAVE_NUM*32-1:0] awaddr_out,
  output [SLAVE_NUM*32-1:0] wdata_out,
  output [SLAVE_NUM*4-1:0] wstrb_out,
  input [SLAVE_NUM*32-1:0] rdata_in,
  input [SLAVE_NUM*2-1:0] bresp_in,
  output [SLAVE_NUM*3-1:0] awsize_out,
  output [SLAVE_NUM*3-1:0] arsize_out,
  
  // slave burst transfer signals
  output [SLAVE_NUM*8-1:0] awlen_out,
  output [SLAVE_NUM*8-1:0] arlen_out,
  output [SLAVE_NUM*2-1:0] awburst_out,
  output [SLAVE_NUM*2-1:0] arburst_out,
  output [SLAVE_NUM-1:0] wlast_out,
  input [SLAVE_NUM-1:0] rlast_in,

  // master transaction start/end signals
  input [MASTER_NUM-1:0] trans_start,
  input [MASTER_NUM-1:0] trans_end
);
  typedef enum logic [1:0] {
    ST_IDLE, SLAVE_SELECT,
    ST_BUSY
  } state_t;
  state_t state;

  wire has_req_start = |trans_start;
  wire has_req_finish = |(trans_end & master_owner_one_hot);
  reg [MASTER_NUM-1:0] master_owner_one_hot;
  reg [SLAVE_NUM-1:0] slave_owner_one_hot;
  wire [MASTER_NUM-1:0] selected_master;

  genvar i;
  generate
    // 0号端口优先级最高
    assign selected_master[0] = trans_start[0];
    
    // 其他端口：只有当更高优先级的端口都没有请求时才有效
    for (i = 1; i < MASTER_NUM; i = i + 1) begin : gen_priority
      assign selected_master[i] = trans_start[i] & ~(|trans_start[i-1:0]);
    end
  endgenerate
  
  always @(posedge clk) begin
    if(rst) begin
      state <= ST_IDLE;
      master_owner_one_hot <= {MASTER_NUM{1'b0}};
      slave_owner_one_hot <= {SLAVE_NUM{1'b0}};
    end else begin
      case(state) 
        ST_IDLE: begin
         if(has_req_start) begin
          state <= SLAVE_SELECT;
          master_owner_one_hot <= selected_master;
         end 
        end

        SLAVE_SELECT: begin
          state <= ST_BUSY;
          slave_owner_one_hot <= selected_slave;
        end

        ST_BUSY: begin
          if(has_req_finish) begin
            state <= ST_IDLE;
            master_owner_one_hot <= {MASTER_NUM{1'b0}};
            slave_owner_one_hot <= {SLAVE_NUM{1'b0}};
          end
        end

        default: begin
          // synopsys translate_off
          $error("ifu axi state machine Invalid state error");
          // synopsys translate_on
        end
      endcase
    end
  end

  // ----------------------------------
  // MASTER SELECT
  // ----------------------------------
  
  // 中间wire变量：选择出的AXI信号
  wire selected_awvalid;
  wire selected_wvalid;
  wire selected_arvalid;
  wire selected_rready;
  wire selected_bready;
  
  wire [31:0] selected_awaddr;
  wire [31:0] selected_araddr;
  wire [31:0] selected_wdata;
  wire [3:0] selected_wstrb;
  wire [2:0] selected_awsize;
  wire [2:0] selected_arsize;
  wire [7:0] selected_awlen;
  wire [7:0] selected_arlen;
  wire [1:0] selected_awburst;
  wire [1:0] selected_arburst;
  wire selected_wlast;

  wire [31:0] selected_rdata;
  wire [1:0] selected_bresp;
  wire selected_rvalid;
  wire selected_bvalid;
  wire selected_rlast;
  wire selected_awready;
  wire selected_wready;
  wire selected_arready;
  
  assign selected_awvalid = |(master_owner_one_hot & awvalid);
  assign selected_wvalid  = |(master_owner_one_hot & wvalid);
  assign selected_arvalid = |(master_owner_one_hot & arvalid);
  assign selected_rready  = |(master_owner_one_hot & rready);
  assign selected_bready  = |(master_owner_one_hot & bready);
  
  // 数据信号：从扁平总线中取出各 master 的分段（兼容 MASTER_NUM=2 的快速选择）
  assign selected_awaddr  = master_owner_one_hot[0] ? awaddr[0*32 +: 32] : awaddr[1*32 +: 32];
  assign selected_araddr  = master_owner_one_hot[0] ? araddr[0*32 +: 32] : araddr[1*32 +: 32];
  assign selected_wdata   = master_owner_one_hot[0] ? wdata[0*32 +: 32] : wdata[1*32 +: 32];
  assign selected_wstrb   = master_owner_one_hot[0] ? wstrb[0*4  +: 4 ] : wstrb[1*4  +: 4 ];
  assign selected_awsize  = master_owner_one_hot[0] ? awsize[0*3 +: 3] : awsize[1*3 +: 3];
  assign selected_arsize  = master_owner_one_hot[0] ? arsize[0*3 +: 3] : arsize[1*3 +: 3];
  assign selected_awlen   = master_owner_one_hot[0] ? awlen[0*8  +: 8 ] : awlen[1*8  +: 8 ];
  assign selected_arlen   = master_owner_one_hot[0] ? arlen[0*8  +: 8 ] : arlen[1*8  +: 8 ];
  assign selected_awburst = master_owner_one_hot[0] ? awburst[0*2 +: 2] : awburst[1*2 +: 2];
  assign selected_arburst = master_owner_one_hot[0] ? arburst[0*2 +: 2] : arburst[1*2 +: 2];
  assign selected_wlast   = master_owner_one_hot[0] ? wlast[0] : wlast[1];

  genvar p;
  generate
    for (p = 0; p < MASTER_NUM; p = p + 1) begin : gen_master_response
      assign rdata[p*32 +: 32] = master_owner_one_hot[p] ? selected_rdata : 32'b0;
      assign bresp[p*2  +: 2 ] = master_owner_one_hot[p] ? selected_bresp : 2'b0;
      assign rvalid[p] = master_owner_one_hot[p] ? selected_rvalid : 1'b0;
      assign bvalid[p] = master_owner_one_hot[p] ? selected_bvalid : 1'b0;
      assign rlast[p] = master_owner_one_hot[p] ? selected_rlast : 1'b0;
      assign awready[p] = master_owner_one_hot[p] ? selected_awready : 1'b0;
      assign wready[p] = master_owner_one_hot[p] ? selected_wready : 1'b0;
      assign arready[p] = master_owner_one_hot[p] ? selected_arready : 1'b0;
    end
  endgenerate
  
  // ----------------------------------
  // SLAVE SELECT (Address Decoder)
  // ----------------------------------
  
  // 根据地址选择对应的slave
  // slave[0]: 外部AXI (默认，其他地址)
  // slave[1]: CLINT (0x02000000 - 0x0200ffff)

  // 地址解码：根据写地址或读地址选择slave
  wire [31:0] current_addr = (selected_arvalid) ? selected_araddr : selected_awaddr;
  wire is_clint_addr = (current_addr >= 32'h02000000) && (current_addr <= 32'h0200ffff);
  wire chose_default = !(is_clint_addr);
  wire [SLAVE_NUM-1:0] selected_slave = {is_clint_addr, chose_default};
  
  // 将选择的master信号路由到对应的slave
  genvar m;
  generate
    for (m = 0; m < SLAVE_NUM; m = m + 1) begin : gen_slave_route
      // 写地址通道
      assign awvalid_out[m] = slave_owner_one_hot[m] ? selected_awvalid : 1'b0;
      assign awaddr_out[m*32 +: 32]  = selected_awaddr;
      assign awsize_out[m*3  +: 3 ]  = selected_awsize;
      assign awlen_out[m*8   +: 8 ]  = selected_awlen;
      assign awburst_out[m*2 +: 2 ]  = selected_awburst;
      
      // 写数据通道
      assign wvalid_out[m]  = slave_owner_one_hot[m] ? selected_wvalid : 1'b0;
      assign wdata_out[m*32 +: 32]   = selected_wdata;
      assign wstrb_out[m*4  +: 4 ]   = selected_wstrb;
      assign wlast_out[m]   = selected_wlast;
      
      // 读地址通道
      assign arvalid_out[m] = slave_owner_one_hot[m] ? selected_arvalid : 1'b0;
      assign araddr_out[m*32 +: 32]  = selected_araddr;
      assign arsize_out[m*3  +: 3 ]  = selected_arsize;
      assign arlen_out[m*8   +: 8 ]  = selected_arlen;
      assign arburst_out[m*2 +: 2 ]  = selected_arburst;
      
      // 读数据通道和写响应通道
      assign rready_out[m]  = slave_owner_one_hot[m] ? selected_rready : 1'b0;
      assign bready_out[m]  = slave_owner_one_hot[m] ? selected_bready : 1'b0;
    end
  endgenerate
  
  assign selected_rdata   = slave_owner_one_hot[0] ? rdata_in[0*32 +: 32] : rdata_in[1*32 +: 32];
  assign selected_bresp   = slave_owner_one_hot[0] ? bresp_in[0*2  +: 2 ] : bresp_in[1*2  +: 2 ];
  assign selected_rvalid  = slave_owner_one_hot[0] ? rvalid_in[0] : rvalid_in[1];
  assign selected_bvalid  = slave_owner_one_hot[0] ? bvalid_in[0] : bvalid_in[1];
  assign selected_rlast   = slave_owner_one_hot[0] ? rlast_in[0] : rlast_in[1];
  assign selected_awready = slave_owner_one_hot[0] ? awready_in[0] : awready_in[1];
  assign selected_wready  = slave_owner_one_hot[0] ? wready_in[0] : wready_in[1];
  assign selected_arready = slave_owner_one_hot[0] ? arready_in[0] : arready_in[1];

endmodule

module ysyx_24100007_MuxKeyInternal #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1, HAS_DEFAULT = 0)(
  output reg [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [DATA_LEN-1:0] default_out,
  input [NR_KEY*(KEY_LEN+DATA_LEN)-1:0] lut
);
  localparam PAIR_LEN = KEY_LEN + DATA_LEN;
  wire [PAIR_LEN-1:0] pair_list[NR_KEY-1:0];
  wire [KEY_LEN-1:0] key_list[NR_KEY-1:0];
  wire [DATA_LEN-1:0] data_list[NR_KEY-1:0];
  
  genvar n;
  generate
    for (n = 0; n < NR_KEY; n = n + 1) begin
      assign pair_list[n] = lut[PAIR_LEN*(n+1)-1 : PAIR_LEN*n];
      assign data_list[n] = pair_list[n][DATA_LEN-1:0];
      assign key_list[n]  = pair_list[n][PAIR_LEN-1:DATA_LEN];
    end
  endgenerate

  reg [DATA_LEN-1:0] lut_out;
  reg hit;
  integer i;
  always @(*) begin
    lut_out = 0;
    hit = 0;
    for (i = 0; i < NR_KEY; i++) begin
      lut_out = lut_out | ({DATA_LEN{key == key_list[i]}} & data_list[i]);
      hit = hit | (key == key_list[i]);
    end
    if(!HAS_DEFAULT) out = lut_out;
    else out = (hit ? lut_out: default_out);
  end

endmodule

module ysyx_24100007_MuxKey #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input[NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);
  ysyx_24100007_MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 0)
    i0 (out, key, {DATA_LEN{1'b0}}, lut);
endmodule

module ysyx_24100007_MuxKeyWithDefault #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [DATA_LEN-1:0] default_out,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);
  ysyx_24100007_MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 1) i0 (out, key, default_out, lut);
endmodule

module ysyx_24100007_clint (
  input clk,
  input reset,

  input         awvalid,
  output        awready,
  input         wvalid,
  output        wready,
  input         arvalid,
  output        arready,
  input         rready,
  output        rvalid,
  input         bready,
  output        bvalid,

  input  [31:0] araddr,
  input  [31:0] awaddr,
  input  [31:0] wdata,
  output [31:0] rdata,
  input  [3:0]  wstrb,
  output [1:0]  bresp,
  input  [2:0]  awsize,
  input  [2:0]  arsize
);

    // 仅仅作为slave模块存在，返回一个mtime，代表时间的流速
    reg[63:0] mtime;
    wire is_penable = (araddr >= 32'h02000000) && (araddr <= 32'h0200ffff);

    always @(posedge clk) begin
        if(reset) begin
            mtime <= 64'b0;
        end else begin
            mtime <= mtime + 1;
        end
    end

    // ---------------------------------
    // STATE MACHINE
    // ---------------------------------
    typedef enum logic [1:0] {
        ST_IDLE, ST_ACCEPT, ST_VALID 
    } state_t;

    reg [1:0] state_next_r;
    reg [1:0] state_current_q;

    always @(posedge clk) begin
        if(reset) begin
            state_current_q <= ST_IDLE;
        end else begin
            state_current_q <= state_next_r;
        end
    end

    wire arvalid_match = is_penable & arvalid;
    wire rready_match = (state_current_q == ST_VALID) & rready;
    always @(*) begin
        state_next_r = ST_IDLE;

        case(state_current_q) 
            ST_IDLE: begin
                if(arvalid_match) 
                    state_next_r = ST_ACCEPT;
            end

            ST_ACCEPT: begin 
                state_next_r = ST_VALID;
            end

            ST_VALID: begin
                if(rready_match)
                    state_next_r = ST_IDLE;
                else
                    state_next_r = ST_VALID;
            end


            default: begin
                // synopsys translate_off
                $error("unkonw state in clint");
                // synopsys translate_on
            end
        endcase
    end

    reg [31:0] rdata_out_r;
    reg [31:0] rdata_out_q;
    reg [31:0] addr_q;
    reg addr_capture_en_r;

    // 地址捕获逻辑（组合逻辑）
    always @(*) begin
        addr_capture_en_r = 1'b0;
        rdata_out_r = 32'b0;

        // 在ST_IDLE状态且收到有效读请求时，准备捕获地址
        if(state_current_q == ST_IDLE && arvalid_match) begin
            addr_capture_en_r = 1'b1;
        end 

        // 在ST_ACCEPT状态时，根据地址选择要读取的数据
        // CLINT地址映射：
        // 0x02000000 (offset 0x0): mtime[31:0]  低32位
        // 0x02000004 (offset 0x4): mtime[63:32] 高32位
        if(state_current_q == ST_ACCEPT) begin
            // 根据地址的第2位（addr_q[2]）选择mtime的低32位或高32位
            if(addr_q[2] == 1'b0) begin
                rdata_out_r = mtime[31:0];   // 低32位
            end else begin
                rdata_out_r = mtime[63:32];  // 高32位
            end
        end
    end

    always @(posedge clk) begin
        if(reset) begin
            addr_q <= 32'b0;
        end else if(addr_capture_en_r) begin
            addr_q <= araddr;
        end
    end

    always @(posedge clk) begin
        if(reset) begin
            rdata_out_q <= 32'b0;
        end else if(state_current_q == ST_ACCEPT) begin
            rdata_out_q <= rdata_out_r;
        end
    end

    assign arready = (state_current_q == ST_ACCEPT);
    assign rvalid = (state_current_q == ST_VALID);
    assign rdata = rdata_out_q;

    assign awready = 0;
    assign wready = 0;
    assign bvalid = 0;
    assign bresp = 2'b00;
endmodule

module ysyx_24100007_sext#(INPUT_WIDTH = 32, OUTPUT_WIDTH = 32) (
  input  wire signed [INPUT_WIDTH-1  : 0] input_number,
  output wire signed [OUTPUT_WIDTH-1 : 0] output_number
);
 assign output_number = {{(OUTPUT_WIDTH - INPUT_WIDTH){input_number[INPUT_WIDTH-1]}}, input_number};
endmodule

module ysyx_24100007_ifu(
  input clk,
  input rst,
  input [31:0] exu_npc,

  output [31:0] pc,
  output [31:0] inst,
  output valid,
  input ready,

  input is_jmp,

  // AXI-Lite interface for external SRAM
  output arvalid,          // Read address valid
  input arready,           // Read address ready
  output [31:0] araddr,    // Read address
  input rvalid,            // Read data valid
  output rready,           // Read data ready
  input [31:0] rdata,      // Read data

  output [7:0]        arlen,
  output [2:0]        arsize,
  output [1:0]        arburst,
  input  [1:0]        rresp,
  input               rlast,

  output trans_start,
  output trans_end
);

  wire [31:0] pcbridge;
  wire infetch_req = is_jmp | (ready & valid); // update pc
  wire [31:0] pc_add_4 = pc + 32'd4;
  wire [31:0] npc = (is_jmp) ? exu_npc : pc_add_4;

  // PC register module
  ysyx_24100007_pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    .ready_from(infetch_req)
  );

  // ------------------------------------
  // ICACHE
  // ------------------------------------
  localparam OFFSET_LEN = 4;
  localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
  localparam ARLEN = (2 ** OFFSET_LEN) / 4 - 1;
  wire w_valid, cache_hit;
  wire [31:0] cache_rdata;
  ysyx_24100007_icache icache_u (
    .clk(clk),
    .rst(rst),

    .addr(pcbridge),
    .w_valid(w_valid),
    .w_data(axi_rdata),
    .hit(cache_hit),
    .data_r(cache_rdata)
  );
  wire hit = cache_hit && (ifu_state == CHECK_CACHE);
  assign w_valid = (ifu_state == UPDATE_CACHE);

  // ------------------------------------
  // PERFORMANCE COUNTER LOGIC
  // ------------------------------------
  // divide it so it couldnot disrupt the synthetic
  // synopsys translate_off

  import "DPI-C" function void host_get_ifu_start();
  import "DPI-C" function void host_get_ifu_finish();
  import "DPI-C" function void host_get_ifu_giveup();
  import "DPI-C" function void host_get_icache_miss();
  always @(posedge clk) begin
    if (!rst) begin
      if (is_jmp) begin
        host_get_ifu_giveup();   // 立即放弃当前取指流
      end else begin
        case (ifu_state)
          INIT: begin
            if (ready) begin
              host_get_ifu_start();
            end
          end

          VALID: begin
            if (ready) begin
              host_get_ifu_start();
            end
          end

          CHECK_CACHE: begin
            if (hit) begin
              host_get_ifu_finish();
            end
          end

          UPDATE_CACHE: begin
            host_get_icache_miss();
          end

          default: begin end
        endcase
      end
    end
  end
  // synopsys translate_on

  // ------------------------------------
  // IFU STATE MACHINE
  // ------------------------------------
  typedef enum logic [2:0] {
    INIT, // the inst is not valid
    VALID, CHECK_CACHE, BUS_HANDSHAKE,
    BUS_TRANSACTION, UPDATE_CACHE,
    BUS_INVALID, UPDATE_PC
  } ifu_state_t;

  ifu_state_t ifu_state;

  always @(posedge clk) begin
    if(rst) begin
      ifu_state <= INIT;
    end else begin
      case(ifu_state) 
        INIT: begin
          // 这里 reset 是0， 那么ifu要将npc驱动起来
          ifu_state <= BUS_HANDSHAKE;
        end

        VALID: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if(ready) begin
            ifu_state <= CHECK_CACHE;
          end
        end

        CHECK_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else if(hit)begin
            ifu_state <= VALID;
          end else begin
            ifu_state <= BUS_HANDSHAKE;
          end
        end

        BUS_HANDSHAKE: begin
          if(is_jmp) begin
            ifu_state <= BUS_INVALID;
          end else if(axi_arready) begin
            ifu_state <= BUS_TRANSACTION;
          end
        end

        BUS_TRANSACTION: begin
          if(is_jmp) begin
            ifu_state <= BUS_INVALID;
          end else if(axi_rdata_valid) begin
            ifu_state <= UPDATE_CACHE;
          end
        end

        UPDATE_CACHE: begin
          if(is_jmp) begin
            ifu_state <= UPDATE_PC;
          end else begin
            ifu_state <= CHECK_CACHE;
          end
        end

        BUS_INVALID: begin
          if(axi_rdata_valid &  axi_rdata_ready) begin
            ifu_state <= UPDATE_PC;
          end
        end

        UPDATE_PC: begin
          ifu_state <= CHECK_CACHE;
        end

        default: begin
          // synopsys translate_off
          $error("ifu state machine Invalid state error");
          // synopsys translate_on
        end
      endcase
    end
  end

  // ------------------------------------
  // AXI CONTEOLLER
  // ------------------------------------
  wire axi_arready, axi_arvalid;
  wire [DATABLOCK_SIZE-1:0] axi_rdata;
  wire axi_rdata_valid, axi_rdata_ready;
  ysyx_24100007_ifu_axicontroller #(
    .ARLEN(ARLEN),
    .BUFFER_SIZE(DATABLOCK_SIZE)
  ) ifu_axicontroller_u (
    .clk(clk),
    .rst(rst),
    .addr(pcbridge),

    .axi_arvalid(axi_arvalid),
    .axi_arready(axi_arready),
    .axi_rdata(axi_rdata),
    .axi_rdata_valid(axi_rdata_valid),
    .axi_rdata_ready(axi_rdata_ready),

    .trans_start(trans_start),
    .trans_end(trans_end),

    .arvalid(arvalid),
    .arready(arready),
    .araddr(araddr),
    .rvalid(rvalid),
    .rready(rready),
    .rdata(rdata),

    .arlen(arlen),
    .arsize(arsize),
    .arburst(arburst),
    .rresp(rresp),
    .rlast(rlast)
  );
  assign axi_rdata_ready = (ifu_state == UPDATE_CACHE) | (ifu_state == BUS_INVALID);
  assign axi_arvalid = (ifu_state == BUS_HANDSHAKE);

  // ------------------------------------
  // INST UPDATE LOGIC
  // ------------------------------------
  reg [31:0] inst_reg;
  wire icache_hit = (ifu_state == CHECK_CACHE) && hit;
  always @(posedge clk) begin
    if(rst) begin
      inst_reg <= 32'b0;
    end else begin
      if(icache_hit) begin
        inst_reg <= cache_rdata;
      end else if(ifu_state == VALID && ready) begin
        inst_reg <= 32'b0;
      end 
    end
  end

  // Assign outputs
  assign pc = pcbridge;
  assign inst = inst_reg;
  assign valid = (ifu_state == VALID);
endmodule

module ysyx_24100007_ifu_axicontroller#(
  parameter ARLEN = 4,
  parameter BUFFER_SIZE = 128
)(
  input clk,
  input rst,

  input [31:0] addr,
  input axi_arvalid,
  output axi_arready,
  
  output [BUFFER_SIZE-1:0] axi_rdata,
  output axi_rdata_valid,
  input axi_rdata_ready,

  output trans_start,
  output trans_end,
  
  // AXI-Lite interface for external SRAM
  output arvalid,          // Read address valid
  input arready,           // Read address ready
  output [31:0] araddr,    // Read address
  input rvalid,            // Read data valid
  output rready,           // Read data ready
  input [31:0] rdata,      // Read data

  output [7:0]        arlen,
  output [2:0]        arsize,
  output [1:0]        arburst,
  input  [1:0]        rresp,
  input               rlast
);
  typedef enum logic[1:0]{
    READY,
    WAIT_HANDSHAKE,
    WAIT_SLAVE,
    PROCESSION
  } axi_state_t;

  axi_state_t axi_state;

  // reg [BUFFER_SIZE-1:0] data_buffer;
  reg [127:0] data_buffer;
  always @(posedge clk) begin
    if(rst) begin
      axi_state <= READY;
    end else begin
      case (axi_state)
        READY: begin
          if (axi_arvalid) begin
            axi_state <= WAIT_HANDSHAKE;
          end
        end

        WAIT_HANDSHAKE: begin
          if (arready) begin
            axi_state <= WAIT_SLAVE;
          end
        end

        WAIT_SLAVE: begin
          if (rlast) begin
            axi_state <= PROCESSION;
          end
        end

        PROCESSION: begin
          if(axi_rdata_ready) begin
            axi_state <= READY;
          end
        end

        default: begin 
          // synopsys translate_off
          $error("ifu axi state machine Invalid state error");
          // synopsys translate_on
        end
      endcase
    end
  end

  localparam [1:0]
    FIXED = 2'b00,
    INCR  = 2'b01,
    WRAP  = 2'b10;

  // 地址和计数跟踪
  reg [31:0] current_addr;
  reg [7:0] beat_count;
  reg [1:0] burst_type;

  wire [31:0] wrap_size = ((ARLEN + 1) << 2);
  wire [31:0] wrap_boundary = current_addr & ~(wrap_size - 1);
  wire [31:0] wrap_end = wrap_boundary + wrap_size;
  wire [31:0] buffer_index_wrap = (current_addr - wrap_boundary) >> 2;

  always @(posedge clk) begin
    if(rst) begin
      current_addr <= 32'b0;
      beat_count <= 8'b0;
      burst_type <= WRAP;
    end else begin
      if(arvalid & arready) begin
        current_addr <= araddr;
      end

      if(rvalid & rready) begin
        beat_count <= beat_count + 1;
        
        if(burst_type == WRAP) begin
            if ((current_addr + 4) >= wrap_end) begin
              current_addr <= wrap_boundary;
            end else begin
              current_addr <= current_addr + 4;
            end 
        end else if(burst_type == FIXED) begin
            current_addr <= current_addr;
        end
      end
    end
  end

  always @(posedge clk) begin
    if(axi_state == WAIT_SLAVE) begin
      case(burst_type)
          INCR: begin
            case(beat_count)
              0: data_buffer[31:0] <= rdata;
              1: data_buffer[63:32] <= rdata;
              2: data_buffer[95:64] <= rdata;
              3: data_buffer[127:96] <= rdata;
              default: begin
              end
            endcase
          end
          WRAP: begin
            case(buffer_index_wrap[1:0])
              2'd0: data_buffer[31:0] <= rdata;
              2'd1: data_buffer[63:32] <= rdata;
              2'd2: data_buffer[95:64] <= rdata;
              2'd3: data_buffer[127:96] <= rdata;
              default: begin
                // 使用条件表达式处理超出范围的情况（通常不会发生）
                data_buffer <= (buffer_index_wrap[1:0] == 2'd0) ? {data_buffer[127:32], rdata} :
                               (buffer_index_wrap[1:0] == 2'd1) ? {data_buffer[127:64], rdata, data_buffer[31:0]} :
                               (buffer_index_wrap[1:0] == 2'd2) ? {data_buffer[127:96], rdata, data_buffer[63:0]} :
                               {rdata, data_buffer[95:0]};
              end
            endcase
          end
          default: begin
          end
      endcase
    end else if(axi_state == PROCESSION) begin
      if(axi_rdata_ready) begin
        data_buffer <= {(128){1'b0}};
      end
    end
  end

  assign trans_start = (axi_state == WAIT_HANDSHAKE);
  assign trans_end = (axi_state == WAIT_SLAVE) && rlast;

  assign axi_rdata = data_buffer;

  assign axi_rdata_valid = (axi_state == PROCESSION);
  assign axi_arready = (axi_state == READY);

  assign araddr = (burst_type == INCR) ? wrap_boundary : addr;
  assign arvalid = (axi_state == WAIT_HANDSHAKE);
  assign rready = (axi_state == WAIT_SLAVE);

  assign arlen = ARLEN[7:0];
  assign arsize = 3'b010;
  assign arburst = burst_type;
endmodule

module ysyx_24100007_icache (  
    input clk,
    input rst,
    input [31:0] addr,
    input w_valid,
    input [127:0] w_data,
    output hit,
    output [31:0] data_r
);
    localparam LINE_NUM = 4;
    localparam TAG_LEN = 32 - 2 - 4;
    localparam OFFSET_LEN = 4;
    localparam INDEX_LEN = 2;

    wire [OFFSET_LEN-1:0] offset = addr[OFFSET_LEN-1:0];
    wire [INDEX_LEN-1:0] index = addr[OFFSET_LEN+INDEX_LEN-1:OFFSET_LEN];
    wire [TAG_LEN-1:0] tag = addr[31:OFFSET_LEN+INDEX_LEN];

    wire [LINE_NUM-1:0] line_hit;
    wire [31:0] line_data_r [LINE_NUM-1:0];
    wire [LINE_NUM-1:0] line_w_valid;
    wire [LINE_NUM-1:0] line_set_invalid;
    wire [127:0] line_data_w [LINE_NUM-1:0];

    genvar i;
    generate
      for (i = 0; i < LINE_NUM; i = i + 1) begin : gen_cacheline
        assign line_w_valid[i] = w_valid && (index == i);
        assign line_data_w[i] = w_data;
      end
    endgenerate

    // Manually expanded cache lines (4 instances)
    ysyx_24100007_icahce_line #(
        .TAG_LEN(TAG_LEN),
        .OFFSET_LEN(OFFSET_LEN)
    ) u_cacheline_0 (
        .clk(clk),
        .rst(rst),
        .tag(tag),
        .offset(offset),
        .w_valid(line_w_valid[0]),
        .data_w(line_data_w[0]),
        .hit(line_hit[0]),
        .data_r(line_data_r[0])
    );

    ysyx_24100007_icahce_line #(
        .TAG_LEN(TAG_LEN),
        .OFFSET_LEN(OFFSET_LEN)
    ) u_cacheline_1 (
        .clk(clk),
        .rst(rst),
        .tag(tag),
        .offset(offset),
        .w_valid(line_w_valid[1]),
        .data_w(line_data_w[1]),
        .hit(line_hit[1]),
        .data_r(line_data_r[1])
    );

    ysyx_24100007_icahce_line #(
        .TAG_LEN(TAG_LEN),
        .OFFSET_LEN(OFFSET_LEN)
    ) u_cacheline_2 (
        .clk(clk),
        .rst(rst),
        .tag(tag),
        .offset(offset),
        .w_valid(line_w_valid[2]),
        .data_w(line_data_w[2]),
        .hit(line_hit[2]),
        .data_r(line_data_r[2])
    );

    ysyx_24100007_icahce_line #(
        .TAG_LEN(TAG_LEN),
        .OFFSET_LEN(OFFSET_LEN)
    ) u_cacheline_3 (
        .clk(clk),
        .rst(rst),
        .tag(tag),
        .offset(offset),
        .w_valid(line_w_valid[3]),
        .data_w(line_data_w[3]),
        .hit(line_hit[3]),
        .data_r(line_data_r[3])
    );

    assign hit = line_hit[index];
    assign data_r = line_data_r[index];
endmodule

module ysyx_24100007_icahce_line #( 
    parameter TAG_LEN = 26,
    parameter OFFSET_LEN = 4
)(  
    input clk,
    input rst,
    input [TAG_LEN-1:0] tag,
    input [OFFSET_LEN-1:0] offset,
    input w_valid,
    input [DATABLOCK_SIZE-1:0] data_w,
    output hit,
    output [31:0] data_r
);
    localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
    localparam DATABLOCK_NUMB = DATABLOCK_SIZE / 32;

    reg [DATABLOCK_NUMB-1:0][31:0] data_block;
    reg valid_r;
    reg [TAG_LEN-1:0] tag_r;

    wire [OFFSET_LEN-3:0] word_idx = offset[OFFSET_LEN-1:2];
    assign data_r = data_block[word_idx];
    assign hit = (valid_r && (tag == tag_r));

    always @(posedge clk) begin
        if(rst) begin
            valid_r <= 1'b0;
            tag_r <= {TAG_LEN{1'b0}};
            data_block <= {DATABLOCK_SIZE{1'b0}};
        end else begin
            if(w_valid) begin
                valid_r <= 1'b1;
                tag_r <= tag;
                data_block <= data_w;
            end 
        end
    end
    
endmodule
module ysyx_24100007_pcreg(
  input clk,
  input [31:0] npc,
  input rst,
  input ready_from,
  output reg [31:0] pcout
);

`ifdef __NPC__
  localparam init = 32'h80000000;
`else
  localparam init = 32'h30000000;
`endif

  initial begin 
    pcout = init;
  end
  
  always @(posedge clk) begin
    if(rst) begin
      pcout <= init;
    end else
    if (ready_from == 1) begin
      pcout <= npc;
    end
  end

endmodule
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
  output [(PORT_NUM-1)*32+31:0] araddr,
  output [(PORT_NUM-1)*32+31:0] awaddr,
  output [(PORT_NUM-1)*32+31:0] wdata,
  output [(PORT_NUM-1)*4+3:0] wstrb,
  input [(PORT_NUM-1)*32+31:0] rdata,
  input [(PORT_NUM-1)*2+1:0] bresp,
  output [(PORT_NUM-1)*3+2:0] awsize,
  output [(PORT_NUM-1)*3+2:0] arsize,
  
  // AXI burst transfer signals
  output [(PORT_NUM-1)*8+7:0] awlen,
  output [(PORT_NUM-1)*8+7:0] arlen,
  output [(PORT_NUM-1)*2+1:0] awburst,
  output [(PORT_NUM-1)*2+1:0] arburst,
  output [PORT_NUM-1:0] wlast,
  input [PORT_NUM-1:0] rlast,
  input [(PORT_NUM-1)*2+1:0]  rresp,
  
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

  wire [31:0] npc, ifu_pc;
  wire [31:0] inst;

  ysyx_24100007_ifu ifu0(
    .clk(clock),
    .rst(reset),
    .exu_npc(npc),
    .ready(idu_to_ifu_ready), // IDU to IFU ready
    .pc(ifu_pc),
    .inst(inst),
    .valid(ifu_to_idu_valid),
    .is_jmp(is_jmp),

    .trans_start(trans_start[0]),
    .trans_end(trans_end[0]),

    .arvalid(arvalid[0]),
    .arready(arready[0]),
    .araddr(araddr[31:0]),
    .rvalid(rvalid[0]),
    .rready(rready[0]),
    .rdata(rdata[31:0]),

    .arlen(arlen[7:0]),
    .arsize(arsize[2:0]),
    .arburst(arburst[1:0]),
    .rresp(rresp[1:0]),
    .rlast(rlast[0])
  );

  // not used channel set to 0
  assign awvalid[0] = 1'b0;
  assign wvalid[0] = 1'b0;
  assign awaddr[31:0] = 32'b0;
  assign wdata[31:0] = 32'b0;
  assign wstrb[3:0] = 4'b0;
  assign bready[0] = 1'b0;
  assign awsize[2:0] = 3'b0;
  assign awlen[7:0] = 8'b0;
  assign awburst[1:0] = 2'b0;
  assign wlast[0] = 1'b0;


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
  wire exu_memew, exu_memer, exu_memsextsig, exu_regew_control;
  wire [2:0] exu_muxsig, exu_memmask;
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
  .memmask_in(memmask),
  .memsextsig_in(memsextsig),
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
  .memmask_out(exu_memmask),           // to WBU
  .memsextsig_out(exu_memsextsig),        // to WBU
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
  .memsextsig_in(exu_memsextsig),
  .memmask_in(exu_memmask),
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

  .trans_start(trans_start[1]),
  .trans_end(trans_end[1]),

  // axi-lite interface
  .awvalid(awvalid[1]),
  .awready(awready[1]),
  .awaddr(awaddr[63:32]),

  .wvalid(wvalid[1]),
  .wready(wready[1]),
  .wdata(wdata[63:32]),
  .wstrb(wstrb[7:4]),

  .bvalid(bvalid[1]),
  .bready(bready[1]),
  .bresp(bresp[3:2]),

  .arvalid(arvalid[1]),
  .arready(arready[1]),
  .araddr(araddr[63:32]),

  .rvalid(rvalid[1]),
  .rready(rready[1]),
  .rdata(rdata[63:32]),
  .awsize(awsize[5:3]),
  .arsize(arsize[5:3]),
  .awburst(awburst[3:2]),

  .wbu_rd(wbu_rd_bypass),      // for data forwarding to IDU
  .wbu_regew(wbu_regew_bypass),   // for data forwarding to IDU
  .transmit_data(wbu_transmit_data),     // for data forwarding to IDU
  .transmit_data_valid(wbu_transmit_data_valid) // for data forwarding to IDU
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

// 暂时不实现突发传输，将没有使用的部分设置为0
assign awlen[15:8] = 8'b0;      // 写地址长度（单次传输，len=0）
assign arlen[15:8] = 8'b0;      // 读地址长度（单次传输，len=0）
assign arburst[3:2] = 2'b0;   // 读burst类型（FIXED，单次传输）
assign wlast[1] = wvalid[1];

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
// synopsys translate_on// synopsys translate_off
import "DPI-C" function void ret(int pc);
// synopsys translate_on
module ysyx_24100007_control_unit(
  input [6:0] opcode,
  input [2:0] func3,
  input func7,

  input ebreaksig,
  input ecallsig,
  input mretsig,
  input [5:0] inst_type,
  output memew,
  output [2:0] muxsig,
  output memer,
  output regew,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output [2:0] memmask,
  output memsextsig
);
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  assign {type_I, type_B, type_J, type_S, type_R, type_U} = inst_type;
  
  wire load, store;
  wire regwritepc, regwritemem, luisig;

  assign load = (opcode == 7'b0000011);
  assign store = (opcode == 7'b0100011);

  assign btypebranch = type_B;
  assign memew = store;
  assign memer = load;
  assign regew = (type_I | type_R | type_J | type_U);
  assign jalsig = type_J;
  assign jalrsig = (opcode == 7'b1100111);
  assign muximm = (load | store | type_I | jalrsig) & !(csrrs | csrrw);
  assign regwritemem = load;
  assign regwritepc = jalrsig | jalsig | auipcsig | ecallsig;
  assign auipcsig = (opcode == 7'b0010111);
  assign luisig = (opcode == 7'b0110111);

  assign aluop[1] = type_R | type_B;
  assign aluop[0] = (type_I | type_B) & ~load;

  assign muxsig = {regwritepc, luisig, regwritemem};

  assign csrrs = (opcode == 7'b1110011) & (func3 == 3'b010);
  assign csrrw = (opcode == 7'b1110011) & (func3 == 3'b001);

  assign memmask = (func3 == 3'b000) ? 3'b001 :
               (func3 == 3'b001) ? 3'b010 :
               (func3 == 3'b010) ? 3'b100 :
               (func3 == 3'b100) ? 3'b001 :
               (func3 == 3'b101) ? 3'b010 :
               3'b000;

  assign memsextsig = (func3 == 3'b100) ? 1'b0 :
                      (func3 == 3'b101) ? 1'b0 :
                      1'b1;
  
  // synopsys translate_off
  always @(*) begin
    if(ebreaksig)
      ret(0);
  end
  // synopsys translate_on
endmodule

module ysyx_24100007_transmit(
    input clk,
    input rst,

    input [4:0] src1_addr_in,
    input [4:0] src2_addr_in,
    input [4:0] exu_rd,
    input [4:0] wbu_rd,

    input exu_res_valid,
    input exu_regew,
    input wbu_res_valid,
    input wbu_regew,
    input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

    input [31:0] regout1_in,
    input [31:0] regout2_in,
    input [31:0] exu_transmit_data,
    input [31:0] wbu_transmit_data,

    output [31:0] src1,
    output [31:0] src2,
    output valid
);  
  wire src1_valid, src2_valid;

  // 实例化两次旁路选择模块，分别用于 src1 和 src2
  ysyx_24100007_bypass_sel bypass_src1 (
    .clk(clk),
    .rst(rst),
    .src_addr_in           (src1_addr_in),
    .reg_data_in           (regout1_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src1),
    .src_valid             (src1_valid)
  );

  ysyx_24100007_bypass_sel bypass_src2 (
    .clk(clk),
    .rst(rst),
    .src_addr_in           (src2_addr_in),
    .reg_data_in           (regout2_in),
    .wbu_rd                (wbu_rd),
    .wbu_regew             (wbu_regew),
    .wbu_transmit_data     (wbu_transmit_data),
    .wbu_transmit_data_valid(wbu_res_valid),
    .exu_rd                (exu_rd),
    .exu_regew             (exu_regew),
    .exu_transmit_data     (exu_transmit_data),
    .exu_transmit_data_valid(exu_res_valid),
    .exu_memer_bypass      (exu_memer_bypass),
    .src_data_out          (src2),
    .src_valid             (src2_valid)
  );

  // 整体有效信号：两个源都有效时才有效
  assign valid = src1_valid && src2_valid;
endmodule

module ysyx_24100007_bypass_sel(
  input clk,
  input rst,
  input [4:0] src_addr_in,          // 源寄存器地址（src1 或 src2）
  input [31:0] reg_data_in,          // 从寄存器堆读出的数据

  // WBU 旁路接口
  input [4:0] wbu_rd,
  input wbu_regew,
  input [31:0] wbu_transmit_data,
  input wbu_transmit_data_valid,

  // EXU 旁路接口
  input [4:0] exu_rd,
  input exu_regew,
  input [31:0] exu_transmit_data,
  input exu_transmit_data_valid,
  input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

  output [31:0] src_data_out,        // 选择后的数据
  output src_valid                   // 数据有效信号
);

  // 首先检查是否需要转发：比较 src_addr 和两个 rd
  // 注意：需要检查 rd 是否为 0（x0 寄存器不需要转发）
  // 优先级：EXU > WBU（EXU是上一级指令，更接近当前指令）
  wire need_exu_forward = (src_addr_in != 5'b0) && (src_addr_in == exu_rd) && exu_regew;
  wire need_wbu_forward = (src_addr_in != 5'b0) && (src_addr_in == wbu_rd) && wbu_regew && !need_exu_forward;

  // 检测 load-use 冲突：需要从 EXU 转发，但 EXU 是 load 指令
  // load 指令的结果需要等到 WBU 阶段才能获得
  wire load_use_hazard_detect = need_exu_forward && exu_memer_bypass;

  // 时序逻辑：锁存 load-use 冲突等待状态
  reg load_use_wait;

  always @(posedge clk) begin
    if(rst) begin
      load_use_wait <= 1'b0;
    end else begin
      if(load_use_hazard_detect) begin
        // 检测到 load-use 冲突，设置等待标志
        load_use_wait <= 1'b1;
      end else if(match_wbu_load_use) begin
        // WBU 数据有效且匹配当前 src_addr，清除等待状态
        load_use_wait <= 1'b0;
      end
    end
  end

  // 判断匹配（需要转发且数据有效）
  wire match_exu = need_exu_forward && exu_transmit_data_valid;
  wire match_wbu = need_wbu_forward && wbu_transmit_data_valid;
  wire match_wbu_load_use = load_use_wait && wbu_transmit_data_valid && (wbu_rd == src_addr_in);

  // 当前数据选择：优先级 EXU > WBU > 寄存器堆
  wire [31:0] src_data_raw = match_exu ? exu_transmit_data :
                             match_wbu_load_use ? wbu_transmit_data :
                             match_wbu ? wbu_transmit_data :
                             reg_data_in;

  // 当前有效信号：
  // - 如果正在等待 load-use 冲突解决，则无效（阻塞）
  // - 如果需要 EXU 转发但数据无效或 EXU 是 load 指令，则无效
  // - 如果需要 WBU 转发但数据无效，则无效
  // - 如果不需要转发（使用寄存器堆），则直接有效\
  wire load_use_src_invalid = (load_use_wait || load_use_hazard_detect);
  wire src_valid_raw = load_use_src_invalid ? 1'b0 :  // 正在等待 load-use 冲突，阻塞
                       need_exu_forward && !exu_memer_bypass ? exu_transmit_data_valid :
                       need_wbu_forward ? wbu_transmit_data_valid :
                       1'b1;

  // 寄存器锁存数据，处理依赖两条指令的情况
  // 当数据有效时锁存，当数据无效时使用锁存的数据（如果地址匹配）
  reg [4:0] src_addr_reg;
  reg [31:0] src_data_reg;
  reg src_reg_valid;

  always @(posedge clk) begin
    if(rst) begin
      src_addr_reg <= 5'b0;
      src_data_reg <= 32'b0;
      src_reg_valid <= 1'b0;
    end else begin
      if(src_valid_raw && !load_use_src_invalid) begin
        // 数据有效且不在等待 load-use 冲突，更新锁存
        src_data_reg <= src_data_raw;
        src_addr_reg <= src_addr_in;
        src_reg_valid <= 1'b1;
      end else if(src_addr_in != src_addr_reg) begin
        // 地址改变且数据无效，清除锁存
        src_reg_valid <= 1'b0;
      end
    end
  end

  // 输出：如果当前数据有效，使用当前数据；否则如果锁存数据有效且地址匹配，使用锁存数据
  assign src_data_out = src_valid_raw ? src_data_raw : 
                        (src_reg_valid && (src_addr_in == src_addr_reg)) ? src_data_reg : src_data_raw;

  // 有效信号：当前数据有效，或者锁存数据有效且地址匹配
  // 注意：如果正在等待 load-use 冲突，则无效（阻塞）
  assign src_valid = (load_use_src_invalid) ? 1'b0 : 
    src_valid_raw || (src_reg_valid && (src_addr_in == src_addr_reg));

endmodule
module ysyx_24100007_idu(
  input clk,
  input rst,
  input [31:0] inst_in,
  input [31:0] pc_in,

  output in_ready,
  input in_valid,
  output out_valid,
  input out_ready,

  input is_jmp,

  // 寄存器堆读出的数据
  input [31:0] regout1,
  input [31:0] regout2,

  // WBU 旁路接口
  input [4:0] wbu_rd,
  input wbu_regew,
  input [31:0] wbu_transmit_data,
  input wbu_transmit_data_valid,

  // EXU 旁路接口
  input [4:0] exu_rd,
  input exu_regew,
  input [31:0] exu_transmit_data,
  input exu_transmit_data_valid,
  input exu_memer_bypass,              // EXU 是否是 load 指令（用于处理 load-use 冲突）

  // 经过旁路选择后的数据
  output [31:0] src1_data,
  output [31:0] src2_data,
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output [31:0] imm,
  output [2:0] func3,
  output func7,
  output [4:0] src1_addr,
  output [4:0] src2_addr,
  output [4:0] rd,
  output memew,
  output [2:0] muxsig,
  output memer,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output regew_control,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output [11:0] csr_addr,
  output [2:0] memmask,
  output memsextsig,
  output [31:0] pc_out
);

  typedef enum logic {
    IDLE, VALID
  } idu_state_t;
  idu_state_t idu_state_r;

  always @(posedge clk) begin
    if(rst) begin
      idu_state_r <= IDLE;
    end else begin
      case(idu_state_r) 
        IDLE: begin
          if(in_valid & in_ready & ! is_jmp) begin
            idu_state_r <= VALID;
          end
        end

        VALID: begin
          if(is_jmp) begin
            idu_state_r <= IDLE;
          end else if(out_ready & out_valid) begin
            if(in_valid) 
              idu_state_r <= VALID;
            else
              idu_state_r <= IDLE;
          end
        end
      endcase
    end
  end

  wire accept = ((idu_state_r == IDLE) || (idu_state_r == VALID && out_ready)) && in_valid;
  assign out_valid = (idu_state_r == VALID) & src_data_valid & !is_jmp;
  assign in_ready = accept; 

  wire [31:0] inst;
  wire pipline_valid;
  wire flush;
  wire avaliable;
  ysyx_24100007_idu_pipline_connect idu_connect(
    .clk(clk),
    .rst(rst),

    .inst_in(inst_in),
    .inst_out(inst),
    .pc_in(pc_in),
    .pc_out(pc_out),

    .avaliable(avaliable),

    .valid(pipline_valid),
    .flush(flush)
  );

  assign pipline_valid = accept & !is_jmp;
  assign flush = (idu_state_r == VALID & out_ready & !in_valid) | is_jmp;
  
  wire ebreak, ecall, mret;
  wire [2:0] func3bridge;
  wire func7bridge;
  wire [6:0] opcode;
  wire [5:0] inst_type;  // 添加type信号

  ysyx_24100007_decoder decoder0(
    .inst(inst),
    .ebreaksig(ebreak),
    .mretsig(mret),
    .ecallsig(ecall),
    .imm(imm),
    .src1(src1_addr),
    .src2(src2_addr),
    .rd(rd),
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .inst_type(inst_type)  // 从decoder获取type
  );

  ysyx_24100007_control_unit control_unit0(
    .opcode(opcode),
    .func3(func3bridge),
    .func7(func7bridge),
    .ebreaksig(ebreak),
    .ecallsig(ecall),
    .mretsig(mret),
    .inst_type(inst_type),  // 传递type给control_unit

    .memew(memew),
    .muxsig(muxsig),
    .memer(memer),
    .regew(regew_control),
    .muximm(muximm),
    .btypebranch(btypebranch),
    .jalrsig(jalrsig),
    .jalsig(jalsig),
    .aluop(aluop),
    .auipcsig(auipcsig),
    .csrrs(csrrs),
    .csrrw(csrrw),
    .memmask(memmask),     
    .memsextsig(memsextsig)
  );

  assign ecallsig = ecall;
  assign mretsig = mret;
  assign ebreaksig = ebreak;
  assign func7 = func7bridge;
  assign func3 = func3bridge;
  assign csr_addr = inst[31:20];  // Extract CSR address from instruction

  wire src_data_valid;

  ysyx_24100007_transmit transmit0(
    .clk(clk),
    .rst(rst),
    .src1_addr_in(src1_addr),
    .src2_addr_in(src2_addr),
    .exu_rd(exu_rd),
    .wbu_rd(wbu_rd),
    .exu_res_valid(exu_transmit_data_valid),
    .exu_regew(exu_regew),
    .wbu_res_valid(wbu_transmit_data_valid),
    .wbu_regew(wbu_regew),
    .exu_memer_bypass(exu_memer_bypass),  // EXU 是否是 load 指令
    .regout1_in(regout1),
    .regout2_in(regout2),
    .exu_transmit_data(exu_transmit_data),
    .wbu_transmit_data(wbu_transmit_data),
    .src1(src1_data),
    .src2(src2_data),
    .valid(src_data_valid)
  );
  
  // synopsys translate_off
  import "DPI-C" function void get_idu_state(int state);
  always @(posedge clk) begin 
    get_idu_state({31'b0, idu_state_r == VALID});
  end
  // synopsys translate_on
endmodule

module ysyx_24100007_idu_pipline_connect(
  input clk,
  input rst,

  input [31:0] inst_in,
  output [31:0] inst_out,
  input [31:0] pc_in,
  output [31:0] pc_out,

  output avaliable,

  input valid,
  input flush // 插入一个nop
);
  reg avaliable_r;
  always @(posedge clk) begin
    if(rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if(valid) begin
        avaliable_r <= 1'b1;
      end else if(flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  reg [31:0] inst_r;
  reg [31:0] pc_r;

  always @(posedge clk) begin
    if(rst) begin
      inst_r <= 32'b0;
      pc_r <= 32'b0;
    end else begin
      if(valid) begin
        inst_r <= inst_in;
        pc_r <= pc_in;
      end else if(flush) begin
        inst_r <= 32'b0;
        pc_r <= 32'b0;
      end
    end
  end

  assign inst_out = inst_r;
  assign pc_out = pc_r;

endmodule
// `include "inst.v"
// `include "symdef.v"

// the main decoder should finish everything about type
// include imm and divide the inst

module ysyx_24100007_decoder(
  input [31:0] inst,
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output [31:0] imm,
  output [6:0] opcode,
  output [2:0] func3,
  output func7,
  output [4:0] src1,
  output [4:0] src2,
  output [4:0] rd,
  output [5:0] inst_type
);
  
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  wire [31:0] I_imm, U_imm, S_imm, J_imm, B_imm;
  
  assign opcode = inst[6:0];
  assign func3 = inst[14:12];
  assign func7 = inst[30];
  assign src1 = inst[19:15];
  assign src2 = inst[24:20];
  assign rd = inst[11:7];

  // Instruction type classification:
  // type_I: I-type instructions - immediate arithmetic/logic operations, load instructions,
  //         jump and link register (JALR), and system instructions (CSR, ECALL, EBREAK)
  //         Examples: ADDI, ANDI, LW, LB, JALR, CSRRW, CSRRW, ECALL, EBREAK
  assign type_I = (opcode == 7'b0000011) | (opcode == 7'b1100111) |
                  (opcode == 7'b0010011) | (opcode == 7'b0000111) |
                  (opcode == 7'b1110011);
  // type_B: B-type instructions - conditional branch instructions
  //         Examples: BEQ, BNE, BLT, BGE, BLTU, BGEU
  assign type_B = (opcode == 7'b1100011);
  // type_S: S-type instructions - store instructions to memory
  //         Examples: SW, SH, SB
  assign type_S = (opcode == 7'b0100011);
  // type_R: R-type instructions - register-to-register arithmetic and logic operations
  //         Examples: ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU
  assign type_R = (opcode == 7'b0110011);
  // type_U: U-type instructions - upper immediate instructions for loading constants
  //         Examples: LUI (load upper immediate), AUIPC (add upper immediate to PC)
  assign type_U = (opcode == 7'b0110111) | (opcode == 7'b0010111);
  // type_J: J-type instructions - unconditional jump instructions
  //         Examples: JAL (jump and link)
  assign type_J = (opcode == 7'b1101111);
  assign inst_type = {type_I, type_B, type_J, type_S, type_R, type_U};

  assign I_imm={{20{inst[31]}},inst[31:20]}; 
	assign U_imm={inst[31:12],{12{1'b0}}};
	assign S_imm={{20{inst[31]}},inst[31:25],inst[11:7]};
  assign J_imm={{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0};
	assign B_imm={{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0};
  
  assign imm = type_I ? I_imm :
               type_J ? J_imm :
               type_S ? S_imm :
               type_B ? B_imm :
               type_U ? U_imm :
               32'b0;

  assign ebreaksig = (inst == 32'b00000000000100000000000001110011);
  assign ecallsig = (inst == 32'b00000000000000000000000001110011);
  assign mretsig = (inst == 32'b00110000001000000000000001110011);

endmodule


module ysyx_24100007_branchcontrol(
  input btypebranch,
  input [2:0] func3,
  input zero,
  input signal,
  input carry,
  input [31:0] res,
  input [31:0] pcadd4,
  input [31:0] pcaddimm,
  input jalsig,
  input jalrsig,
  input auipcsig,
  input mretsig,
  input ecallsig,
  input [31:0] mtvec,
  input [31:0] mepc,

  output [31:0] npc,
  output [31:0] pcwritereg,
  output is_jmp
);
 assign pcwritereg = (jalsig || jalrsig) ? pcadd4 : 
                    auipcsig ? pcaddimm :
                    (ecallsig) ? pcadd4 :
                    0;

wire npc_is_pcaddimm = (jalsig) || (btypebranch && func3 == 3'b000 && zero) || 
                        (btypebranch && func3 == 3'b001 && !zero) || 
                        (btypebranch && func3 == 3'b100 && res[0]) || 
                        (btypebranch && func3 == 3'b101 && (!res[0] || zero)) || 
                        (btypebranch && func3 == 3'b110 && res[0]) || 
                        (btypebranch && func3 == 3'b111 && (!res[0] || zero));

wire npc_is_mepc = (mretsig == 1'b1);
wire npc_is_mtvec = (ecallsig == 1'b1);
wire npc_is_res = (jalrsig);
 
assign npc = (jalsig) ? pcaddimm :
             (jalrsig) ? {res[31:1], 1'b0} :
             (btypebranch && func3 == 3'b000 && zero)    ? pcaddimm :
             (btypebranch && func3 == 3'b001 && !zero)   ? pcaddimm :
             (btypebranch && func3 == 3'b100 && res[0])  ? pcaddimm :
             (btypebranch && func3 == 3'b101 && (!res[0] || zero)) ? pcaddimm :
             (btypebranch && func3 == 3'b110 && res[0])  ? pcaddimm :
             (btypebranch && func3 == 3'b111 && (!res[0] || zero))   ? pcaddimm :
             (mretsig == 1'b1) ? mepc :
             (ecallsig == 1'b1) ? mtvec:
             pcadd4;

  assign is_jmp = (npc_is_mepc) | (npc_is_mtvec) | (npc_is_pcaddimm) | (npc_is_res);
endmodule
`define   ysyx_24100007_ADD       4'b0001
`define   ysyx_24100007_SUB       4'b0011
`define   ysyx_24100007_SLL       4'b1100
`define   ysyx_24100007_SLT       4'b1001
`define   ysyx_24100007_SLTU      4'b1000
`define   ysyx_24100007_XOR       4'b0110
`define   ysyx_24100007_SRL       4'b1101
`define   ysyx_24100007_SRA       4'b1110
`define   ysyx_24100007_OR        4'b0101
`define   ysyx_24100007_AND       4'b0100

module ysyx_24100007_alucontrol(
  input [2:0] func3,
  input func7,
  input [1:0] aluop,
  input jalrsig,
  input is_csr,
  
  output [4:0] aluopcode
);
  wire type_I, type_B, type_R;
  wire [3:0] branchop;
  reg [3:0] IRop;
  assign type_I = (aluop == 2'b01);
  assign type_B = (aluop == 2'b11);
  assign type_R = (aluop == 2'b10);
  
  assign branchop=(func3[2] & func3[1])? `ysyx_24100007_SLTU : (func3[2] ^ func3[1])? `ysyx_24100007_SLT : `ysyx_24100007_SUB;

  always @(*) begin
    case(func3)
    3'b000: begin
    if(type_R & func7) begin
      IRop = `ysyx_24100007_SUB;
    end else begin
      IRop = `ysyx_24100007_ADD;
    end
    end
    3'b001: IRop=`ysyx_24100007_SLL;
    3'b010: begin
      if(jalrsig)
        IRop = `ysyx_24100007_ADD;
      else
        IRop=`ysyx_24100007_SLT;
    end
		3'b011: IRop=`ysyx_24100007_SLTU;
		3'b100: IRop=`ysyx_24100007_XOR;
		3'b101: begin
    if(func7) begin
			IRop=`ysyx_24100007_SRA;
    end else
			IRop=`ysyx_24100007_SRL;
    end
		3'b110: IRop=`ysyx_24100007_OR;
		3'b111: IRop=`ysyx_24100007_AND;
		default:IRop=`ysyx_24100007_ADD;
    endcase
  end

  wire [4:0] aluopcode_I = {(type_I)? 1'b1:1'b0,(type_B==1)?branchop:(type_R|type_I == 1)?IRop:`ysyx_24100007_ADD};
  wire [4:0] aluopcode_csr = {1'b0, `ysyx_24100007_ADD};
  assign aluopcode = (is_csr) ? aluopcode_csr : aluopcode_I;
endmodule



        

module ysyx_24100007_exu(
  input clk,
  input rst,

  input in_valid,
  output in_ready,
  input out_ready,
  output out_valid,

  // need sig
  input [2:0] func3_in,
  input btypebranch_in,
  input func7_in,
  input [1:0] aluop_in,
  input jalrsig_in,
  input jalsig_in,
  input [31:0] imm_in,
  input muximm_in,
  input [31:0] pc_in,
  input auipcsig_in,
  input mretsig_in,
  input ecallsig_in,
  input [31:0] mtvec_in,
  input [31:0] mepc_in,

  // pass sig
  input memew_in,               
  input memer_in,              
  input [2:0] muxsig_in,        
  input [2:0] memmask_in,     
  input memsextsig_in,         
  input regew_control_in,
  input [4:0] rd_in,
  input csrrw_in,
  input csrrs_in,
  input [11:0] csr_addr_in,
  input wbu_write_csr, 
  
  input [31:0] src1_in,
  input [31:0] src2_in,

  output [31:0] res,
  output [31:0] npc,
  output [31:0] link_addr,   // PC value to write to register (for JAL/JALR)
  output [31:0] src2_out,    // src2 output to WBU
  output [31:0] imm_out,     // imm output to WBU

  output memew_out,              
  output memer_out,              
  output [2:0] muxsig_out,        
  output [2:0] memmask_out,      
  output memsextsig_out,         
  output regew_control_out,   
  output [4:0] rd_out,
  output csrrw_out,
  output csrrs_out,
  output [11:0] csr_addr_out,
  output ecallsig_out,

  output is_jmp, // tell ifu flush the pipline

  // EXU 向 IDU 转发的旁路信号
  output [4:0] exu_rd,                // EXU 阶段的 rd（用于旁路）
  output exu_regew,                   // EXU 阶段的写使能（用于旁路）
  output [31:0] exu_transmit_data,    // EXU 阶段的计算结果（用于旁路）
  output exu_transmit_data_valid,     // EXU 阶段的旁路数据有效信号
  output exu_memer_bypass             // EXU 阶段是否是 load 指令（用于处理 load-use 冲突）
); 

  typedef enum logic{
    IDLE, VALID
  } exu_state_t;
  exu_state_t exu_state_r;

  wire exu_wbu_handshake = exu_valid_sig & out_ready;
  wire avaliable;
  always @(posedge clk) begin
    if(rst) begin
      exu_state_r <= IDLE;
    end else begin
      case(exu_state_r)
        IDLE: begin
          if(in_valid & in_ready) begin
            exu_state_r <= VALID;
          end 
        end

        VALID: begin
          if(exu_wbu_handshake) begin
            if(in_valid)
              exu_state_r <= VALID;
            else 
              exu_state_r <= IDLE;
          end
        end
      endcase
    end
  end 

  wire exu_valid_sig = (exu_state_r == VALID) & !exu_csr_delay;
  wire accept = ((exu_state_r == IDLE) || exu_wbu_handshake) && in_valid;
  wire idu_valid = in_valid & !is_jmp;

  assign out_valid = exu_valid_sig;
  assign in_ready = accept;
  
  wire pipline_valid = accept & !(exu_state_r == VALID & is_jmp);
  wire flush = (exu_wbu_handshake & !idu_valid);

  // Pipeline connect: 流水线寄存器
  wire [2:0] func3;
  wire btypebranch;
  wire func7;
  wire [1:0] aluop;
  wire jalrsig;
  wire jalsig;
  wire [31:0] imm;
  wire muximm;
  wire [31:0] src1;
  wire [31:0] src2;
  wire [31:0] pc;
  wire auipcsig;
  wire mretsig;
  wire ecallsig;
  wire [31:0] mtvec;
  wire [31:0] mepc;
  wire [2:0] muxsig;
  wire csrrs, csrrw;

  ysyx_24100007_exu_pipline_connect exu_pipeline_u(
    .clk(clk),
    .rst(rst),

    // need sig inputs
    .func3_in(func3_in),
    .btypebranch_in(btypebranch_in),
    .func7_in(func7_in),
    .aluop_in(aluop_in),
    .jalrsig_in(jalrsig_in),
    .jalsig_in(jalsig_in),
    .imm_in(imm_in),
    .muximm_in(muximm_in),
    .src1_in(src1_in),
    .src2_in(src2_in),
    .pc_in(pc_in),
    .auipcsig_in(auipcsig_in),
    .mretsig_in(mretsig_in),
    .ecallsig_in(ecallsig_in),
    .mtvec_in(mtvec_in),
    .mepc_in(mepc_in),

    // pass sig inputs
    .memew_in(memew_in),
    .memer_in(memer_in),
    .muxsig_in(muxsig_in),
    .memmask_in(memmask_in),
    .memsextsig_in(memsextsig_in),
    .regew_control_in(regew_control_in),
    .rd_in(rd_in),
    .csrrw_in(csrrw_in),
    .csrrs_in(csrrs_in),
    .csr_addr_in(csr_addr_in),

    // need sig outputs
    .func3_out(func3),
    .btypebranch_out(btypebranch),
    .func7_out(func7),
    .aluop_out(aluop),
    .jalrsig_out(jalrsig),
    .jalsig_out(jalsig),
    .imm_out(imm),
    .muximm_out(muximm),
    .src1_out(src1),
    .src2_out(src2),
    .pc_out(pc),
    .auipcsig_out(auipcsig),
    .mretsig_out(mretsig),
    .ecallsig_out(ecallsig),
    .mtvec_out(mtvec),
    .mepc_out(mepc),
    .muxsig_out(muxsig),

    // pass sig outputs
    .memew_out(memew_out),
    .memer_out(memer_out),
    .memmask_out(memmask_out),
    .memsextsig_out(memsextsig_out),
    .regew_control_out(regew_control_out),
    .rd_out(rd_out),
    .csrrw_out(csrrw),
    .csrrs_out(csrrs),
    .csr_addr_out(csr_addr_out),

    .avaliable(avaliable),
    .pipline_valid(pipline_valid),
    .flush(flush)
  );

  assign csrrs_out = csrrs;
  assign csrrw_out = csrrw;
  assign ecallsig_out = ecallsig;

  wire [31:0] pc_plus_4, pc_plus_imm;
  assign pc_plus_4 = pc + 32'd4;
  assign pc_plus_imm = pc + imm;

  
  wire [4:0] alu_opcode;
  ysyx_24100007_alucontrol alucontrol0(
    .func3(func3),
    .func7(func7),
    .aluop(aluop),
    .jalrsig(jalrsig),
    .is_csr(csrrw || csrrs),
    .aluopcode(alu_opcode)
  );

  wire [31:0] alu_arg2;
  ysyx_24100007_MuxKey#(2, 1, 32) chosmuximm(alu_arg2, muximm, {
      1'b0, src2,
      1'b1, imm
    }
  );
  
  wire zero_flag, sign_flag, carry_flag;
  ysyx_24100007_alu alu0(
    .A(src1),
    .B(alu_arg2),
    .op(alu_opcode),
    .res(res_r),
    .zero(zero_flag),
    .signal(sign_flag),
    .carry(carry_flag)
  );

  // ------------------------------------
  //  BRANCH CONTROL
  // ------------------------------------
  wire is_jmp_r_1;
  wire is_jmp_r;
  wire [31:0] res_r;
  ysyx_24100007_branchcontrol branchcontrol0(
    .btypebranch(btypebranch),
    .func3(func3),
    .zero(zero_flag),
    .signal(sign_flag),
    .carry(carry_flag),
    .res(res_r),
    .pcadd4(pc_plus_4),
    .pcaddimm(pc_plus_imm),
    .jalsig(jalsig),
    .jalrsig(jalrsig),
    .auipcsig(auipcsig),
    .mretsig(mretsig),
    .ecallsig(ecallsig),
    .mtvec(mtvec),
    .mepc(mepc),

    .npc(npc),
    .pcwritereg(link_addr),
    .is_jmp(is_jmp_r_1)
  );
  reg is_jmp_mask;
  always @(posedge clk) begin
    if((in_valid & in_ready) | exu_csr_delay) begin
      is_jmp_mask <= 1'b1;
    end else begin
      is_jmp_mask <= 1'b0;
    end
  end
  assign is_jmp_r = is_jmp_r_1 & is_jmp_mask & !exu_csr_delay;
  assign is_jmp = is_jmp_r;

  assign res = (csrrw || csrrs) ? src1 : res_r;
  assign src2_out = src2;  // 将流水线的src2输出到WBU
  assign imm_out = imm;    // 将流水线的imm输出到WBU
  assign muxsig_out = muxsig;

  // EXU 向 IDU 转发的旁路信号
  assign exu_rd = rd_out;
  assign exu_regew = regew_control_out || (memew_out || memer_out);
  assign exu_transmit_data = (muxsig == 3'b010) ? imm :
                             (muxsig == 3'b100) ? link_addr :
                             res;
 // 旁路数据有效条件：输出有效 && 不是访存指令（访存指令的结果需要从 WBU 获取）
  assign exu_transmit_data_valid = out_valid && !(memew_out || memer_out);
  // EXU 是否是 load 指令（用于 IDU 处理 load-use 冲突）
  assign exu_memer_bypass = memer_out;

  wire exu_need_mepc_mtvec = ecallsig || mretsig;
  wire exu_csr_delay = wbu_write_csr & exu_need_mepc_mtvec;
  
  // synopsys translate_off
  import "DPI-C" function void get_exu_state(int state);
  always @(posedge clk) begin 
    get_exu_state({31'b0, exu_state_r == VALID});
  end
  // synopsys translate_on

endmodule

module ysyx_24100007_exu_pipline_connect(
  input clk, 
  input rst,

  input [2:0] func3_in,
  input btypebranch_in,
  input func7_in,
  input [1:0] aluop_in,
  input jalrsig_in,
  input jalsig_in,
  input [31:0] imm_in,
  input muximm_in,
  input [31:0] src1_in,
  input [31:0] src2_in,
  input [31:0] pc_in,
  input auipcsig_in,
  input mretsig_in,
  input ecallsig_in,
  input [31:0] mtvec_in,
  input [31:0] mepc_in,

  input memew_in,               
  input memer_in,              
  input [2:0] muxsig_in,        
  input [2:0] memmask_in,     
  input memsextsig_in,         
  input regew_control_in,
  input [4:0] rd_in,
  input csrrw_in,
  input csrrs_in,
  input [11:0] csr_addr_in,

  output [2:0] func3_out,
  output btypebranch_out,
  output func7_out,
  output [1:0] aluop_out,
  output jalrsig_out,
  output jalsig_out,
  output [31:0] imm_out,
  output muximm_out,
  output [31:0] src1_out,
  output [31:0] src2_out,
  output [31:0] pc_out,
  output auipcsig_out,
  output mretsig_out,
  output ecallsig_out,
  output [31:0] mtvec_out,
  output [31:0] mepc_out,

  output memew_out,               
  output memer_out,              
  output [2:0] muxsig_out,        
  output [2:0] memmask_out,     
  output memsextsig_out,         
  output regew_control_out,
  output [4:0] rd_out,
  output csrrw_out,
  output csrrs_out,
  output [11:0] csr_addr_out,

  output avaliable,
  input pipline_valid,
  input flush
);
  reg avaliable_r;
  always @(posedge clk) begin
    if(rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if(pipline_valid) begin
        avaliable_r <= 1'b1;
      end else if(flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  // 寄存器存储所有输入信号
  reg [2:0] func3_r;
  reg btypebranch_r;
  reg func7_r;
  reg [1:0] aluop_r;
  reg jalrsig_r;
  reg jalsig_r;
  reg [31:0] imm_r;
  reg muximm_r;
  reg [31:0] src1_r;
  reg [31:0] src2_r;
  reg [31:0] pc_r;
  reg auipcsig_r;
  reg mretsig_r;
  reg ecallsig_r;
  reg [31:0] mtvec_r;
  reg [31:0] mepc_r;

  reg memew_r;
  reg memer_r;
  reg [2:0] muxsig_r;
  reg [2:0] memmask_r;
  reg memsextsig_r;
  reg regew_control_r;
  reg [4:0] rd_r;
  reg csrrw_r;
  reg csrrs_r;
  reg [11:0] csr_addr_r;

  always @(posedge clk) begin
    if(rst) begin
      func3_r <= 3'b0;
      btypebranch_r <= 1'b0;
      func7_r <= 1'b0;
      aluop_r <= 2'b0;
      jalrsig_r <= 1'b0;
      jalsig_r <= 1'b0;
      imm_r <= 32'b0;
      muximm_r <= 1'b0;
      src1_r <= 32'b0;
      src2_r <= 32'b0;
      pc_r <= 32'b0;
      auipcsig_r <= 1'b0;
      mretsig_r <= 1'b0;
      ecallsig_r <= 1'b0;
      mtvec_r <= 32'b0;
      mepc_r <= 32'b0;
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      muxsig_r <= 3'b0;
      memmask_r <= 3'b0;
      memsextsig_r <= 1'b0;
      regew_control_r <= 1'b0;
      rd_r <= 5'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
      csr_addr_r <= 12'b0;
    end else begin
      if(pipline_valid) begin
        func3_r <= func3_in;
        btypebranch_r <= btypebranch_in;
        func7_r <= func7_in;
        aluop_r <= aluop_in;
        jalrsig_r <= jalrsig_in;
        jalsig_r <= jalsig_in;
        imm_r <= imm_in;
        muximm_r <= muximm_in;
        src1_r <= src1_in;
        src2_r <= src2_in;
        pc_r <= pc_in;
        auipcsig_r <= auipcsig_in;
        mretsig_r <= mretsig_in;
        ecallsig_r <= ecallsig_in;
        mtvec_r <= mtvec_in;
        mepc_r <= mepc_in;
        memew_r <= memew_in;
        memer_r <= memer_in;
        muxsig_r <= muxsig_in;
        memmask_r <= memmask_in;
        memsextsig_r <= memsextsig_in;
        regew_control_r <= regew_control_in;
        rd_r <= rd_in;
        csrrw_r <= csrrw_in;
        csrrs_r <= csrrs_in;
        csr_addr_r <= csr_addr_in;
      end else if(flush) begin
        func3_r <= 3'b0;
        btypebranch_r <= 1'b0;
        func7_r <= 1'b0;
        aluop_r <= 2'b0;
        jalrsig_r <= 1'b0;
        jalsig_r <= 1'b0;
        imm_r <= 32'b0;
        muximm_r <= 1'b0;
        src1_r <= 32'b0;
        src2_r <= 32'b0;
        pc_r <= 32'b0;
        auipcsig_r <= 1'b0;
        mretsig_r <= 1'b0;
        ecallsig_r <= 1'b0;
        mtvec_r <= 32'b0;
        mepc_r <= 32'b0;
        memew_r <= 1'b0;
        memer_r <= 1'b0;
        muxsig_r <= 3'b0;
        memmask_r <= 3'b0;
        memsextsig_r <= 1'b0;
        regew_control_r <= 1'b0;
        rd_r <= 5'b0;
        csrrw_r <= 1'b0;
        csrrs_r <= 1'b0;
        csr_addr_r <= 12'b0;
      end
    end
  end

  // 输出连接到寄存器
  assign func3_out = func3_r;
  assign btypebranch_out = btypebranch_r;
  assign func7_out = func7_r;
  assign aluop_out = aluop_r;
  assign jalrsig_out = jalrsig_r;
  assign jalsig_out = jalsig_r;
  assign imm_out = imm_r;
  assign muximm_out = muximm_r;
  assign src1_out = src1_r;
  assign src2_out = src2_r;
  assign pc_out = pc_r;
  assign auipcsig_out = auipcsig_r;
  assign mretsig_out = mretsig_r;
  assign ecallsig_out = ecallsig_r;
  assign mtvec_out = mtvec_r;
  assign mepc_out = mepc_r;
  assign memew_out = memew_r;
  assign memer_out = memer_r;
  assign muxsig_out = muxsig_r;
  assign memmask_out = memmask_r;
  assign memsextsig_out = memsextsig_r;
  assign regew_control_out = regew_control_r;
  assign rd_out = rd_r;
  assign csrrw_out = csrrw_r;
  assign csrrs_out = csrrs_r;
  assign csr_addr_out = csr_addr_r;

endmodule
module ysyx_24100007_alu(
  input [31:0] A,
  input [31:0] B,
  input [4:0] op,
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
 
  wire type_I = op[4];
  // logic part
  reg [31:0] logres;
  always @(*) begin
    case(op[1:0])
      2'b00: logres = (type_I) ? A & $signed(B) : A & B;
      2'b01: logres = A | B;
      2'b10: logres = A ^ B;
      2'b11: logres = ~(A | B);
    endcase
  end

  // add part
  reg [31:0] addres;
  wire addzero;
  always @(*) begin
    case(op[0] ^ op[1])
      1'b1: {carry_tmp, addres} = {1'b0,A} + {1'b0,B};
      1'b0: {carry_tmp, addres} = {1'b0,A} + {1'b0,(~B)} + 1;
    endcase
    // $display("%x + %x = %x", A, B, addres);
  end
  assign addzero = (addres == 0);

  // shift part
  reg [31:0] shfres;
  always @(*) begin
    case(op[1:0])
      2'b00: shfres = (type_I) ? A << B[4:0] : A << B[4:0];
      2'b01: shfres = (type_I) ? A >> B[4:0] : A >> B[4:0];
      2'b10: shfres = (type_I) ? ($signed(A)) >>> B[4:0] : 
                                 ($signed(A)) >>> B[4:0];
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
module ysyx_24100007_memreadlen(
  input is_unalign,
  input [31:0] data,      // 从内存中读取的完整32位数据
  input [2:0] memmask,    // 内存掩码，用于确定读取的长度（byte, halfword, word）
  input memsextsig,       // 符号扩展信号，1表示有符号扩展，0表示无符号扩展
  input [1:0] addr_offset, // 地址的最低两位，用于确定偏移量
  output [31:0] read      // 读取并扩展后的数据
);

  wire [31:0] read_u, read_s;
  wire [31:0] read_sb, read_sh;
  wire [7:0]  byte_data;
  wire [15:0] halfword_data;

  wire [15:0] halfword_data_unalign;
  wire [7:0] byte_data_unalign;
  wire [15:0] halfword_data_align;
  wire [7:0] byte_data_align;

  assign byte_data_unalign = (addr_offset == 2'b00) ? data[7:0] :
                             (addr_offset == 2'b01) ? data[15:8] :
                             (addr_offset == 2'b10) ? data[23:16] :
                              data[31:24];
  assign byte_data_align = data[7:0];

  assign halfword_data_unalign = (addr_offset[1] == 1'b0) ? data[15:0] : data[31:16];
  assign halfword_data_align = data[15:0];

  assign byte_data = (is_unalign == 1) ? byte_data_unalign : byte_data_align;
  assign halfword_data = (is_unalign == 1) ? halfword_data_unalign : halfword_data_align;

  // 符号扩展
  ysyx_24100007_sext#(8, 32) sext0(byte_data, read_sb);
  ysyx_24100007_sext#(16, 32) sext1(halfword_data, read_sh);

  assign read_s = (memmask == 3'b001) ? read_sb :  // lb
                  (memmask == 3'b010) ? read_sh :  // lh
                  data;                            // lw

  assign read_u = (memmask == 3'b001) ? {{24{1'b0}}, byte_data} :  // lbu
                  (memmask == 3'b010) ? {{16{1'b0}}, halfword_data} :  // lhu
                  data;  // lw

  // 根据符号扩展信号选择最终的输出
  assign read = (memsextsig == 1) ? read_s : read_u;
endmodule
`define ysyx_24100007_GENERAL 2'b00 // for the device that support Supports arbitrary byte access
`define ysyx_24100007_BYTE 2'b01
`define ysyx_24100007_HALFWORD 2'b10
`define ysyx_24100007_WORD 2'b11

module ysyx_24100007_memwritelen(
    input [31:0] awaddr,
    input [2:0] wirtelen,
    output [3:0] wstrb,
    output [2:0] awsize,
    output [1:0] wdata_offset,
    output [1:0] awburst
);
    localparam device_num = 3;
    wire inuart = (awaddr >= 32'h10000000) && (awaddr <= 32'h10000fff);
    wire insram = (awaddr >= 32'h0f000000) && (awaddr <= 32'h0fffffff);
    wire inflash = (awaddr >= 32'h30000000) && (awaddr <= 32'h3fffffff);
    wire inspi = (awaddr >= 32'h10001000) && (awaddr <= 32'h10001fff);
    wire inpsram = (awaddr >= 32'h80000000) && (awaddr <= 32'h9fffffff);
    wire insdram = (awaddr >= 32'ha0000000) && (awaddr <= 32'hbfffffff);

    wire [1:0] bus_size;
    wire [2:0] awsize_general = (wirtelen == 3'b001) ? 3'b000 :     
                                (wirtelen == 3'b010) ? 3'b001 :
                                (wirtelen == 3'b100) ? 3'b010 :
                                3'b000;

    ysyx_24100007_MuxKeyWithDefault #(device_num, device_num, 2) type_mux(
        .out(bus_size),
        .key({insram|inspi|insdram|inpsram,1'b0,inflash}),
        .default_out(`ysyx_24100007_GENERAL),
        .lut({
            3'b100 , `ysyx_24100007_WORD,
            3'b010 , `ysyx_24100007_HALFWORD,
            3'b001 , `ysyx_24100007_BYTE
        })
    );

    ysyx_24100007_MuxKeyWithDefault #(3, 2, 3) len_mux(
        .out(awsize),
        .key(bus_size),
        .default_out(awsize_general),
        .lut({
            `ysyx_24100007_BYTE, 3'b000,
            `ysyx_24100007_HALFWORD, 3'b001,
            `ysyx_24100007_WORD, 3'b010
        })
    );

    // wstrb
    wire [3:0] wstrb_general;
    assign wstrb_general = (wirtelen == 3'b001) ? 4'b0001 :
                           (wirtelen == 3'b010) ? 4'b0011 :
                           (wirtelen == 3'b100) ? 4'b1111 :
                           4'b0000;

    wire [3:0] wstrb_byte;
    assign wstrb_byte = 4'b0001;

    // halfword 写掩码：根据地址 bit1 选择低/高 16bit
    wire [3:0] wstrb_halfword = awaddr[1] ? 4'b1100 : 4'b0011;

    wire [3:0] wstrb_word;
    wire [4:0] mux = {wirtelen, awaddr[1:0]};
    assign wstrb_word = (mux == 5'b00100) ? 4'b0001 :
                        (mux == 5'b00101) ? 4'b0010 :
                        (mux == 5'b00110) ? 4'b0100 :
                        (mux == 5'b00111) ? 4'b1000 :
                        (mux == 5'b01000) ? 4'b0011 :
                        (mux == 5'b01010) ? 4'b1100 :
                        (mux == 5'b10000) ? 4'b1111 :
                        4'b0000;

    ysyx_24100007_MuxKey #(4, 2, 4) wstrb_mux(
        .out(wstrb),
        .key(bus_size),
        .lut({
            `ysyx_24100007_GENERAL, wstrb_general,
            `ysyx_24100007_BYTE, wstrb_byte,
            `ysyx_24100007_HALFWORD, wstrb_halfword,
            `ysyx_24100007_WORD, wstrb_word
        })
    );

    assign wdata_offset = (bus_size == `ysyx_24100007_WORD || bus_size == `ysyx_24100007_GENERAL) ? awaddr[1:0] : 2'b0;
    assign awburst = inuart ? 2'b00 : 2'b01;

endmodule
module ysyx_24100007_wbu(
  input clk,
  input rst,
  input [31:0] res_in,
  input [31:0] regout2_in,
  input memew_in,
  input memer_in,
  input [31:0] imm_in,
  input [31:0] link_addr_in,
  input [2:0] muxsig_in,
  input [2:0] memmask_in,
  input memsextsig_in,
  input regew_control_in,
  input [4:0] rd_in,
  input csrrw_in,
  input csrrs_in,
  input [11:0] csr_addr_in,
  input ecallsig_in,

  output [31:0] regwrite_out,
  output regew_out,
  output [4:0] rd_out,
  output csrrw_out,
  output csrrs_out,
  output [11:0] csr_addr_out,
  output ecallsig_out,
  output wbu_write_csr,

  output trans_start,
  output trans_end,

  // wbu is the last model
  input in_valid,
  output in_ready,

  output wbu_commit,

  // axi-lite interface
  output awvalid,
  input awready,
  output [31:0] awaddr,
  output wvalid,
  input wready,
  output [31:0] wdata,
  output [3:0] wstrb,
  input bvalid,
  output bready,
  input [1:0] bresp,
  output arvalid,
  input arready,
  output [31:0] araddr,
  input rvalid,
  output rready,
  input [31:0] rdata,
  output [2:0] awsize,
  output [2:0] arsize,
  output [1:0] awburst,

  output [4:0] wbu_rd,
  output wbu_regew,
  output [31:0] transmit_data,
  output transmit_data_valid
);

  wire accept = ((wbu_state == WAIT_VALID) || (wbu_state == WRITE_BACK)) && in_valid;
  assign in_ready = (wbu_state == WAIT_VALID) ;
  wire pipline_valid = accept;
  wire flush = ((wbu_state == WRITE_BACK) & !in_valid);

  // Pipeline connect: 流水线寄存器
  wire [31:0] res;
  wire [31:0] regout2;
  wire memew;
  wire memer;
  wire [31:0] imm;
  wire [31:0] link_addr;
  wire [2:0] muxsig;
  wire [2:0] memmask;
  wire memsextsig;
  wire regew_control;
  wire [4:0] rd;
  wire ecallsig;
  wire csrrs, csrrw;

  ysyx_24100007_wbu_pipline_connect wbu_pipeline_u(
    .clk(clk),
    .rst(rst),

    .res_in(res_in),
    .regout2_in(regout2_in),
    .memew_in(memew_in),
    .memer_in(memer_in),
    .imm_in(imm_in),
    .link_addr_in(link_addr_in),
    .muxsig_in(muxsig_in),
    .memmask_in(memmask_in),
    .memsextsig_in(memsextsig_in),
    .regew_control_in(regew_control_in),
    .rd_in(rd_in),
    .csrrw_in(csrrw_in),
    .csrrs_in(csrrs_in),
    .csr_addr_in(csr_addr_in),
    .ecallsig_in(ecallsig_in),

    .res_out(res),
    .regout2_out(regout2),
    .memew_out(memew),
    .memer_out(memer),
    .imm_out(imm),
    .link_addr_out(link_addr),
    .muxsig_out(muxsig),
    .memmask_out(memmask),
    .memsextsig_out(memsextsig),
    .regew_control_out(regew_control),
    .rd_out(rd),
    .csrrw_out(csrrw),
    .csrrs_out(csrrs),
    .csr_addr_out(csr_addr_out),
    .ecallsig_out(ecallsig),

    .avaliable(avaliable),
    .pipline_valid(pipline_valid),
    .flush(flush)
  );

  // Memory access state machine
  typedef enum logic [1:0] {
    WAIT_VALID, BUS_HANDSHAKE, BUS_TRANSACTION, WRITE_BACK
  } wbu_state_t;
  wbu_state_t wbu_state;

  wire mem_access = memew_in | memer_in;
  wire write_handshake_done = memew & axi_xaddr_valid & axi_xaddr_ready & 
                               axi_wdata_valid & axi_wdata_ready;
  wire read_addr_handshake_done = memer & axi_xaddr_valid & axi_xaddr_ready;
  wire avaliable;
  always @(posedge clk) begin
    if(rst) begin
      wbu_state <= WAIT_VALID;
    end else begin
      case(wbu_state)
        WAIT_VALID: begin
          if(in_valid & in_ready) begin
            if(mem_access) begin
              wbu_state <= BUS_HANDSHAKE;
            end else begin
              wbu_state <= WRITE_BACK;
            end
          end 
        end

        BUS_HANDSHAKE: begin
          if(write_handshake_done) begin
            wbu_state <= BUS_TRANSACTION;
          end else if (read_addr_handshake_done) begin
            wbu_state <= BUS_TRANSACTION;
          end
        end

        BUS_TRANSACTION: begin
          if(axi_rdata_valid | axi_bresp_valid) begin
            wbu_state <= WRITE_BACK;
          end
        end

        WRITE_BACK: begin
          if(in_valid & in_ready) begin
            if(mem_access) begin
              wbu_state <= BUS_HANDSHAKE;
            end else begin
              wbu_state <= WRITE_BACK;
            end
          end else begin
            wbu_state <= WAIT_VALID;
          end
        end
      endcase
    end
  end

  assign wbu_commit = (wbu_state == WRITE_BACK);
  assign ecallsig_out = ecallsig & (wbu_state == WRITE_BACK);
  assign csrrs_out = csrrs & (wbu_state == WRITE_BACK);
  assign csrrw_out = csrrw & (wbu_state == WRITE_BACK);

  wire regew;
  assign regew = (wbu_state == WRITE_BACK) & regew_control;
  reg [31:0] memread_data_q;
  wire [31:0] memread_data_r;

  always @(posedge clk) begin
    if(axi_rdata_valid) begin
      memread_data_q <= memread_data_r;
    end else if(wbu_state == WRITE_BACK) begin
      memread_data_q <= 32'b0;
    end
  end

  wire[31:0] regwrite;
  ysyx_24100007_MuxKeyWithDefault#(4, 3, 32) muxpc(regwrite, muxsig, 0, {
    3'b000, res,
    3'b001, memread_data_q,
    3'b010, imm,
    3'b100, link_addr
  });

  assign transmit_data = regwrite;
  assign wbu_rd = rd;
  assign wbu_regew = regew_control;
  assign transmit_data_valid = regew;
  assign wbu_write_csr = csrrs_out || csrrw_out;

  // Output connections
  assign regwrite_out = regwrite;
  assign regew_out = regew;
  assign rd_out = rd;

  // AXI 内存控制器接口信号
  wire axi_xaddr_valid;   // 地址通道 valid（写地址或读地址）
  wire axi_xaddr_ready;   // 地址通道 ready
  wire axi_wdata_valid;   // 写数据通道 valid
  wire axi_wdata_ready;   // 写数据通道 ready
  wire axi_rdata_valid;   // 读数据通道 valid
  wire axi_rdata_ready;   // 读数据通道 ready
  wire axi_bresp_valid;   // 写响应通道 valid
  wire axi_bresp_ready;   // 写响应通道 ready
  
  assign axi_xaddr_valid = (wbu_state == BUS_HANDSHAKE);
  assign axi_wdata_valid = (wbu_state == BUS_HANDSHAKE) && memew;
  assign axi_rdata_ready = (wbu_state == BUS_TRANSACTION) && memer;
  assign axi_bresp_ready = (wbu_state == BUS_TRANSACTION) && memew;

  ysyx_24100007_axi_mem_controller mem_controller_inst(
    .clk(clk),
    .rst(rst),
    
    // 内存访问控制信号
    .mem_en((memer | memew) & avaliable),
    .mem_we(memew),
    .mem_addr(res),
    .mem_wdata(regout2),
    .mem_mask(memmask),
    .mem_sext(memsextsig),
    
    // AXI 握手控制信号（用于 WBU 状态机）
    .axi_xaddr_valid(axi_xaddr_valid),
    .axi_wdata_valid(axi_wdata_valid),
    .axi_xaddr_ready(axi_xaddr_ready),
    .axi_wdata_ready(axi_wdata_ready),
    .axi_rdata_ready(axi_rdata_ready),
    .axi_bresp_ready(axi_bresp_ready),
    .axi_rdata_valid(axi_rdata_valid),
    .axi_bresp_valid(axi_bresp_valid),

    .trans_start(trans_start),
    .trans_end(trans_end),
    
    // 内存访问结果
    .mem_rdata(memread_data_r),
    
    // AXI-Lite 写地址通道
    .awvalid(awvalid),
    .awready(awready),
    .awaddr(awaddr),
    .awsize(awsize),
    .awburst(awburst),
    
    // AXI-Lite 写数据通道
    .wvalid(wvalid),
    .wready(wready),
    .wdata(wdata),
    .wstrb(wstrb),
    
    // AXI-Lite 写响应通道
    .bvalid(bvalid),
    .bready(bready),
    .bresp(bresp),
    
    // AXI-Lite 读地址通道
    .arvalid(arvalid),
    .arready(arready),
    .araddr(araddr),
    .arsize(arsize),
    
    // AXI-Lite 读数据通道
    .rvalid(rvalid),
    .rready(rready),
    .rdata(rdata)
  );

endmodule

module ysyx_24100007_wbu_pipline_connect(
  input clk,
  input rst,

  input [31:0] res_in,
  input [31:0] regout2_in,
  input memew_in,
  input memer_in,
  input [31:0] imm_in,
  input [31:0] link_addr_in,
  input [2:0] muxsig_in,
  input [2:0] memmask_in,
  input memsextsig_in,
  input regew_control_in,
  input [4:0] rd_in,
  input csrrw_in,
  input csrrs_in,
  input [11:0] csr_addr_in,
  input ecallsig_in,

  output [31:0] res_out,
  output [31:0] regout2_out,
  output memew_out,
  output memer_out,
  output [31:0] imm_out,
  output [31:0] link_addr_out,
  output [2:0] muxsig_out,
  output [2:0] memmask_out,
  output memsextsig_out,
  output regew_control_out,
  output [4:0] rd_out,
  output csrrw_out,
  output csrrs_out,
  output [11:0] csr_addr_out,
  output ecallsig_out,

  output avaliable,
  input pipline_valid,
  input flush
);

  reg avaliable_r;
  always @(posedge clk) begin
    if(rst) begin
      avaliable_r <= 1'b0;
    end else begin
      if(pipline_valid) begin
        avaliable_r <= 1'b1;
      end else if(flush) begin
        avaliable_r <= 1'b0;
      end
    end
  end

  assign avaliable = avaliable_r;

  // 寄存器存储所有输入信号
  reg [31:0] res_r;
  reg [31:0] regout2_r;
  reg memew_r;
  reg memer_r;
  reg [31:0] imm_r;
  reg [31:0] link_addr_r;
  reg [2:0] muxsig_r;
  reg [2:0] memmask_r;
  reg memsextsig_r;
  reg regew_control_r;
  reg [4:0] rd_r;
  reg csrrw_r;
  reg csrrs_r;
  reg [11:0] csr_addr_r;
  reg ecallsig_r;

  always @(posedge clk) begin
    if(rst) begin
      res_r <= 32'b0;
      regout2_r <= 32'b0;
      memew_r <= 1'b0;
      memer_r <= 1'b0;
      imm_r <= 32'b0;
      link_addr_r <= 32'b0;
      muxsig_r <= 3'b0;
      memmask_r <= 3'b0;
      memsextsig_r <= 1'b0;
      regew_control_r <= 1'b0;
      rd_r <= 5'b0;
      csrrw_r <= 1'b0;
      csrrs_r <= 1'b0;
      csr_addr_r <= 12'b0;
      ecallsig_r <= 1'b0;
    end else begin
      if(pipline_valid) begin
        res_r <= res_in;
        regout2_r <= regout2_in;
        memew_r <= memew_in;
        memer_r <= memer_in;
        imm_r <= imm_in;
        link_addr_r <= link_addr_in;
        muxsig_r <= muxsig_in;
        memmask_r <= memmask_in;
        memsextsig_r <= memsextsig_in;
        regew_control_r <= regew_control_in;
        rd_r <= rd_in;
        csrrw_r <= csrrw_in;
        csrrs_r <= csrrs_in;
        csr_addr_r <= csr_addr_in;
        ecallsig_r <= ecallsig_in;
      end else if(flush) begin
        res_r <= 32'b0;
        regout2_r <= 32'b0;
        memew_r <= 1'b0;
        memer_r <= 1'b0;
        imm_r <= 32'b0;
        link_addr_r <= 32'b0;
        muxsig_r <= 3'b0;
        memmask_r <= 3'b0;
        memsextsig_r <= 1'b0;
        regew_control_r <= 1'b0;
        rd_r <= 5'b0;
        csrrw_r <= 1'b0;
        csrrs_r <= 1'b0;
        csr_addr_r <= 12'b0;
        ecallsig_r <= 1'b0;
      end
    end
  end

  // 输出连接到寄存器
  assign res_out = res_r;
  assign regout2_out = regout2_r;
  assign memew_out = memew_r;
  assign memer_out = memer_r;
  assign imm_out = imm_r;
  assign link_addr_out = link_addr_r;
  assign muxsig_out = muxsig_r;
  assign memmask_out = memmask_r;
  assign memsextsig_out = memsextsig_r;
  assign regew_control_out = regew_control_r;
  assign rd_out = rd_r;
  assign csrrw_out = csrrw_r;
  assign csrrs_out = csrrs_r;
  assign csr_addr_out = csr_addr_r;
  assign ecallsig_out = ecallsig_r;

endmodule

module ysyx_24100007_axi_mem_controller(
  input clk,
  input rst,
  
  // 内存访问控制信号
  input mem_en,              // 内存访问使能 (memer | memew)
  input mem_we,              // 内存写使能 (memew)
  input [31:0] mem_addr,     // 内存地址 (res)
  input [31:0] mem_wdata,    // 写数据 (regout2)
  input [2:0] mem_mask,      // 内存访问大小 (memmask)
  input mem_sext,            // 符号扩展标志 (memsextsig)
  
  // AXI 握手控制信号（用于 WBU 状态机）
  input axi_xaddr_valid,     // WBU 请求地址通道握手
  input axi_wdata_valid,     // WBU 请求写数据通道握手
  output axi_xaddr_ready,    // 地址通道 ready（控制器准备好接收地址）
  output axi_wdata_ready,    // 写数据通道 ready（控制器准备好接收数据）
  
  input axi_rdata_ready,     // WBU 准备好接收读数据
  input axi_bresp_ready,     // WBU 准备好接收写响应
  output axi_rdata_valid,    // 读数据 valid（数据已准备好）
  output axi_bresp_valid,    // 写响应 valid（响应已准备好）

  output trans_start,
  output trans_end,

  output reg [31:0] mem_rdata,  // 读取的数据
  
  // AXI-Lite 写地址通道
  output awvalid,
  input awready,
  output [31:0] awaddr,
  output [2:0] awsize,
  output [1:0] awburst,
  
  // AXI-Lite 写数据通道
  output wvalid,
  input wready,
  output [31:0] wdata,
  output [3:0] wstrb,
  
  // AXI-Lite 写响应通道
  input bvalid,
  output bready,
  input [1:0] bresp,
  
  // AXI-Lite 读地址通道
  output arvalid,
  input arready,
  output [31:0] araddr,
  output [2:0] arsize,
  
  // AXI-Lite 读数据通道
  input rvalid,
  output rready,
  input [31:0] rdata
);

  typedef enum logic [1:0]{
    READY,
    WAIT_HANDSHAKE,
    WAIT_SLAVE,
    PROCESSION
  } axi_state_t;
  axi_state_t state;

  // 地址范围匹配信号
  wire in_clint     = (mem_addr >= 32'h02000000) && (mem_addr <= 32'h0200ffff);
  wire in_sram      = (mem_addr >= 32'h0f000000) && (mem_addr <= 32'h0fffffff);
  wire in_uart      = (mem_addr >= 32'h10000000) && (mem_addr <= 32'h10000fff);
  wire in_spi       = (mem_addr >= 32'h10001000) && (mem_addr <= 32'h10001fff);
  wire in_gpio      = (mem_addr >= 32'h10002000) && (mem_addr <= 32'h1000200f);
  wire in_ps2       = (mem_addr >= 32'h10011000) && (mem_addr <= 32'h10011007);
  wire in_mrom      = (mem_addr >= 32'h20000000) && (mem_addr <= 32'h20000fff);
  wire in_vga       = (mem_addr >= 32'h21000000) && (mem_addr <= 32'h211fffff);
  wire in_flash     = (mem_addr >= 32'h30000000) && (mem_addr <= 32'h3fffffff);
  wire in_chiplink  = (mem_addr >= 32'h40000000) && (mem_addr <= 32'h7fffffff);
  wire in_psram     = (mem_addr >= 32'h80000000) && (mem_addr <= 32'h9fffffff);
  wire in_sdram     = (mem_addr >= 32'ha0000000) && (mem_addr <= 32'hbfffffff);

  // 内部计算的信号
  wire [1:0] wdata_offset;
  wire [31:0] memread_r;

  // AXI 信号赋值
  // 写操作：地址和数据通道 这里不管mem_en 因为mem_en 不为高的话无法离开READY状态
  assign awvalid = mem_we & (state == WAIT_HANDSHAKE);
  assign awaddr = mem_addr;
  assign wvalid = mem_we & (state == WAIT_HANDSHAKE);
  assign wdata = mem_wdata << (wdata_offset * 8);
  assign bready = mem_we & (state == WAIT_SLAVE);
  
  // 读操作：地址通道
  assign arvalid = ~mem_we & (state == WAIT_HANDSHAKE);
  assign rready = ~mem_we & mem_en & (state == WAIT_SLAVE);
  
  // 地址和数据大小
  assign arsize = (mem_mask == 3'b001) ? 3'b000 :
                  (mem_mask == 3'b010) ? 3'b001 :
                  3'b010;
  assign araddr = (in_psram|in_sdram|in_sram) ? {mem_addr[31:2], 2'b00} : mem_addr;
  
  // 写控制模块
  ysyx_24100007_memwritelen strbcontrol(
    .wirtelen(mem_mask),
    .wstrb(wstrb),
    .awsize(awsize),
    .awaddr(awaddr),
    .wdata_offset(wdata_offset),
    .awburst(awburst)
  );

  // 读数据对齐和符号扩展
  ysyx_24100007_memreadlen memreadlen0(
    .is_unalign(in_psram|in_sdram|in_sram),
    .data(rdata),
    .memsextsig(mem_sext),
    .memmask(mem_mask),
    .read(memread_r),
    .addr_offset(mem_addr[1:0])
  );

  // AXI_CONTROL & WBU 握手机制实现
  assign axi_xaddr_ready = (state == READY);
  // 写数据通道 ready：当控制器准备好接收写数据时
  assign axi_wdata_ready = (state == READY);
  // 读数据 valid：当读数据有效时
  assign axi_rdata_valid = (state == PROCESSION) && mem_en && ~mem_we;
  // 写响应 valid：当写响应有效时
  assign axi_bresp_valid = (state == PROCESSION) && mem_en && mem_we;

  wire read_req = axi_xaddr_valid & mem_en;
  wire write_req = axi_xaddr_valid & axi_wdata_ready & mem_en;

  // 状态机
  always @(posedge clk) begin
    if(rst) begin
      state <= READY;
      mem_rdata <= 32'b0;
    end else begin
      case(state)
        READY: begin
          if (read_req | write_req) begin
            // 这个 WAIT_HANDSHAKE axi传输的握手，而不是memcontrol和wbu的握手
            // 所以在 memcontrol 和 wbu握手以后才进入axi传输的握手机制里
            state <= WAIT_HANDSHAKE;
          end
        end

        WAIT_HANDSHAKE: begin
          // 写操作：地址和数据通道都握手完成
          if(awready && wready) begin
            state <= WAIT_SLAVE;
          end
          // 读操作：地址通道握手完成
          else if(arready) begin
            state <= WAIT_SLAVE;
          end
        end

        WAIT_SLAVE: begin
          if(rvalid) begin
            // 读操作：收到读数据
            state <= PROCESSION;
            mem_rdata <= memread_r;
          end else if(bvalid) begin
            // 写操作：收到写响应
            state <= PROCESSION;
          end
        end

        PROCESSION: begin
          // 当 WBU 离开 BUS_TRANSACTION 状态时，对应的 ready 信号会拉低
          // 读操作时：axi_rdata_ready 表示 WBU 已处理完读数据
          // 写操作时：axi_bresp_ready 表示 WBU 已处理完写响应
          if((axi_bresp_ready) || (axi_rdata_ready)) begin
            state <= READY;
            mem_rdata <= 32'b0;
          end
        end
      endcase
    end
  end

  assign trans_start = (state == WAIT_HANDSHAKE);
  assign trans_end = (state == WAIT_SLAVE) && (rvalid | bvalid);

    // ------------------------------------
    // PERFORMANCE COUNTER LOGIC
    // ------------------------------------
    // synopsys translate_off
    import "DPI-C" function void host_get_io_op(int addr);
    import "DPI-C" function void host_get_wbu_start();
    import "DPI-C" function void host_get_wbu_finish();
    
    always @(posedge clk) begin
      if (!rst) begin
        case (state)
          READY: begin
            if (read_req | write_req) begin
              host_get_wbu_start();
            end
          end

          WAIT_SLAVE: begin
            if(rvalid | bvalid) begin
              host_get_io_op(awaddr);
            end
          end

          PROCESSION: begin
            if ((axi_bresp_ready) || (axi_rdata_ready)) begin
              host_get_wbu_finish();
            end
          end

          default: begin end
        endcase
      end
    end
    // synopsys translate_on


endmodule
