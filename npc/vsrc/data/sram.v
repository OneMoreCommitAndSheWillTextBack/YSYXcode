import "DPI-C" function void guest_write(int addr, int data, int len);
import "DPI-C" function int guest_read(int addr, int len);
// change the model to axt-lite module

module sram(
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
  input [3:0] wstrb,  // indicate the lenth
  
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
  typedef enum logic [1:0]{
    WAIT_FOR_SIG,
    READ_VALID,
    WRITE_VALID
  } state_t;

  reg [1:0] state;

`define need_lfsr_test
`ifdef need_lfsr_test
  // need to change here
  wire [3:0] random_delay;
  reg busy;
  lfsr#(4) lsfr0(
    .clk(clk),
    .reset(0),
    .out(random_delay)
  );

  reg [3:0] random_count;
  always @(posedge clk) begin
    case (state)
      READ_VALID:begin
        if(rready) begin
          busy = 0;
          state = WAIT_FOR_SIG;
          random_count = random_delay;
        end
      end 
      WRITE_VALID:begin
        if(wvalid & awvalid) begin
          busy = 0;
          state = WAIT_FOR_SIG;
          random_count = random_delay;
        end
      end
      WAIT_FOR_SIG:begin
        if((arvalid) | (wvalid & awvalid)) begin
          busy = 1;
          if(random_count == 0) begin
            if(arvalid) begin
              state = READ_VALID;
            end

            if(wvalid & awvalid) begin
              state = WRITE_VALID;
            end
          end else begin
            random_count = random_count - 1;
          end
        end
      end
      default:
        state = WAIT_FOR_SIG;
    endcase
  end
  
`else
  always @(posedge clk) begin
    if ((arvalid) | (wvalid & awvalid)) begin 
      case (state)
        WAIT_FOR_SIG: begin
          if(arvalid) begin
            state = READ_VALID;
          end 

          if(awvalid & wvalid) begin
            state = WRITE_VALID;
          end
        end

        READ_VALID: begin
          state = WAIT_FOR_SIG;
        end
        WRITE_VALID:begin
          state = WAIT_FOR_SIG;
        end
        default:begin
          state = WAIT_FOR_SIG;
        end
      endcase
    end
  end

`endif
  wire [2:0] memmask;
  MuxKey#(4, 4, 3) muxpc(memmask, wstrb,{
    4'b0001, 3'b001,
    4'b0010, 3'b010,
    4'b0100, 3'b011,
    4'b1000, 3'b100
  });
  
  reg [31:0] rdatareg;
  always @(posedge clk) begin
    if (state == WRITE_VALID) begin
      guest_write(awaddr, wdata, {{29{1'b0}},memmask});
    end

    if (state == READ_VALID) begin
      rdatareg = guest_read(araddr, 4);
    end else begin
      rdatareg = 0;
    end
  end

  assign awready = (state == WAIT_FOR_SIG) & ~busy;
  assign wready = (state == WAIT_FOR_SIG) & ~busy;
  assign arready = (state == WAIT_FOR_SIG) & ~busy;

  assign bresp = state == WRITE_VALID;
  assign rvalid = state == READ_VALID;

  assign rdata = rdatareg;
endmodule
