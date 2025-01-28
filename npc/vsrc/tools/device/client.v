module client(
  input clk,

  // write address channel
  input awvalid,
  output awready,
  input [31:0] awaddr,

  // write data channel
  input wvalid,
  output wready,
  input [31:0] wdata,
  input [3:0] wstrb,
  
  // write response channel
  output bvalid,
  input bready,
  output bresp,

  // read address channel
  input arvalid,
  output arready,
  input [31:0] araddr,

  // read data channel
  input rready,
  output rvalid,
  output [31:0] rdata
);
  
  // the mtime has two part
  // mtime[0] is lower 32 bit
  // mtime[1] is upper 32 bit
  reg [31:0] mtime_reg [1:0];

  always @(posedge clk) begin
    mtime_reg[0] <= mtime_reg[0] + 1;
    if (mtime_reg[0] == 32'hFFFFFFFF) begin
      mtime_reg[1] <= mtime_reg[1] + 1;
    end
  end

  typedef enum logic {
    WAITING,
    OUTPUT
  } state_t;

  reg state;
  
  always @(posedge clk) begin
    case(state) 
      WAITING: begin
        if (arvalid) begin
          state <= OUTPUT;
        end
      end

      OUTPUT: begin
        if (arvalid & rready) begin
          state <= WAITING;
        end
      end
    endcase
  end

  assign rdata = (state == WAITING) ? 0 :
                 (araddr == 32'ha0000048) ? mtime_reg[0] :
                 (araddr == 32'ha000004f) ? mtime_reg[1] :
                 0;

  assign arready = (state == WAITING);

  assign bresp = 0;
  assign rvalid = state == OUTPUT;

endmodule
