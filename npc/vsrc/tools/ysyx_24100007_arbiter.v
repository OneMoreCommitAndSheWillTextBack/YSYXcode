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
  parameter SLAVE_NUM=1             // slave设备数量（CLINT, 外部AXI等）
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
  input  [SLAVE_NUM*32-1:0] rdata_in,
  input  [SLAVE_NUM*2-1:0] bresp_in,
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
  
  // 数据信号：从扁平总线中取出各 master 的分段（兼容 MASTER_NUM=2）
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
