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

  output [31:0] regwrite_out,
  output regew_out,
  output [4:0] rd_out,

  output trans_start,
  output trans_end,

  output icahce_flush,
  
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
  assign in_ready = (wbu_state == WAIT_VALID);
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

  wbu_pipline_connect wbu_pipeline_u(
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

  assign icahce_flush = memew & (wbu_state == WRITE_BACK);
  
  assign transmit_data = regwrite;
  assign wbu_rd = rd;
  assign wbu_regew = regew_control;
  assign transmit_data_valid = regew;

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

  axi_mem_controller mem_controller_inst(
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

module wbu_pipline_connect(
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

endmodule

module axi_mem_controller(
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
  wire [1:0] access_size_i = (mem_mask == 3'b010) ? 2'b01 :
                             (mem_mask == 3'b100) ? 2'b10 :
                             2'b00;
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
