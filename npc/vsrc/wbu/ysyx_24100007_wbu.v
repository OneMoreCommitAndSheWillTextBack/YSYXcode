import "DPI-C" function void host_get_skip(int addr);

module ysyx_24100007_wbu(
  input clk,
  input [31:0] res,
  input [31:0] regout2,
  input memew,
  input memer,
  input [31:0] imm,
  input [31:0] pcwritereg,
  input [2:0] muxsig,
  input valid_from,
  input [2:0] memmask,
  input memsextsig,

  output [31:0] regwrite,
  output ready_to,
  output memvalid,

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
  output [1:0] awburst
);

  typedef enum logic [1:0]{
    READY,
    WAIT_HAMDSHAKE,
    WAIT_SLAVE,
    FINISH
  } state_t;
  reg [1:0] state;

  wire [31:0] memread;
  wire [1:0] wdata_offset;
  ysyx_24100007_memwritelen strbcontol(
    .wirtelen(memmask),
    .wstrb(wstrb),
    .awsize(awsize),
    .awaddr(awaddr),
    .wdata_offset(wdata_offset),
    .awburst(awburst)
  );

	assign awvalid = memew & (state == WAIT_HAMDSHAKE);
  assign awaddr = res;
  assign wvalid = memew & (state == WAIT_HAMDSHAKE);
  assign wdata = regout2 << wdata_offset * 8;
  assign bready = memew;
  assign arvalid = memer & (state == WAIT_HAMDSHAKE);
  assign rready = memer;
  assign arsize = (memmask == 3'b001) ? 3'b000 :
                  (memmask == 3'b010) ? 3'b001 :
                  3'b010;

  wire [1:0] access_size_i = (memmask == 3'b010) ? 2'b01 :
                             (memmask == 3'b100) ? 2'b10 :
                             2'b00;
  wire aligned_sram;
  assign aligned_sram = (res >= 32'h0f000000) && (res <= 32'h0fffffff) ||
                        (res >= 32'h80000000) && (res <= 32'h9fffffff) ||
                        (res >= 32'ha0000000) && (res <= 32'hbfffffff);
  // when read the sram it would return align 4

  ysyx_24100007_memreadlen memreadlen0(
    .is_unalign(aligned_sram),
    .data(rdata),
    .memsextsig(memsextsig),
    .memmask(memmask),
    .read(memread),
    .addr_offset(res[1:0])
  );

  assign araddr = (aligned_sram) ? {res[31:2], 2'b00} : res; 

  ysyx_24100007_MuxKeyWithDefault#(4, 3, 32) muxpc(regwrite, muxsig, 0, {
    3'b000, res,
    3'b001, memread,
    3'b010, imm,
    3'b100, pcwritereg
  });

  wire ready = arready & wready & awready;
  assign ready_to = (state == READY & ~(memer | memew)) | state == FINISH;
  assign memvalid = rvalid & memer;

  always @(posedge clk) begin
    case(state)
      READY: begin
        if (memer | memew) 
          state <= WAIT_HAMDSHAKE;
      end

      WAIT_HAMDSHAKE: begin
        if(arready | (awready & wready))
          state <= WAIT_SLAVE;
      end

      WAIT_SLAVE: begin
        if(rvalid | (bvalid & bresp == 2'b00)) begin
          host_get_skip(awaddr);
          state <= FINISH;
        end
      end

      FINISH: begin
        if (~valid_from)
          state <= READY;
      end
    endcase
  end
endmodule
