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
  input [31:0] rdata
);

  typedef enum logic [1:0]{
    READY,
    WAIT_HAMDSHAKE,
    WAIT_SLAVE,
    FINISH
  } state_t;
  reg [1:0] state;

  wire [31:0] memread;

  assign wstrb = (memmask == 3'b001) ? 4'b0001 :
                 (memmask == 3'b010) ? 4'b0011 :
                 (memmask == 3'b011) ? 4'b0111 :
                 (memmask == 3'b100) ? 4'b1111 :
                 4'b1111;

	assign awvalid = memew & (state == WAIT_HAMDSHAKE);
  assign awaddr = res;
  assign wvalid = memew & (state == WAIT_HAMDSHAKE);
  assign wdata = regout2;
  assign bready = memew;
  assign arvalid = memer & (state == WAIT_HAMDSHAKE);
  assign araddr = res;
  assign rready = memer; 

  ysyx_24100007_memreadlen memreadlen0(
    .data(rdata),
    .memsextsig(memsextsig),
    .memmask(memmask),
    .read(memread)
  );

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
        if(rvalid | (bvalid & bresp == 2'b00))
          state <= FINISH;
      end

      FINISH: begin
        
      end
    endcase
  end
endmodule
