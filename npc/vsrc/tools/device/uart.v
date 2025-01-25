module uart(
  // global
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
  typedef enum logic {
      WAITING,
      OUTPUT
  } state_t;

  reg state;

  always @(posedge clk) begin
    case (state)
      WAITING: begin
        if(awvalid & wvalid) begin
          state <= OUTPUT;
        end
      end
      
      OUTPUT: begin
        if(awvalid & wvalid) begin
          state <= WAITING;
        end
      end
    endcase
  end

  always @(*) begin
    if (state == OUTPUT) begin
      // $display("reagh here");
      $write("%s", wdata[7:0]);
    end
  end

  assign awready = (state == WAITING);
  assign wready = (state == WAITING);
  assign arready = (state == WAITING);

  assign bresp = state == OUTPUT;
  assign rvalid = 0;

  assign rdata = 0;
  
endmodule
