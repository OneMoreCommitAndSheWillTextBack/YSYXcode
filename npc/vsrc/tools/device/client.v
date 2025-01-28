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
    mtime_reg <= mtime_reg + 1;
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
        if (arvalid) begin
          state <= WAITING;
        end
      end
    endcase
  end

  always @(*) begin
    if (state == OUTPUT) begin
      if (state == OUTPUT) begin
        rdata = mtime_reg;
      end
    end
  end

  assign arready = (state == WAITING);

  assign bresp = 0;
  assign rvalid = state == OUTPUT;

endmodule
