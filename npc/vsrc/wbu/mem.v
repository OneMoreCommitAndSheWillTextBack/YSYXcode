import "DPI-C" function void guest_write(int addr, int data, int len);
import "DPI-C" function int guest_read(int addr, int len);

module mem(
  input clk,
  input [31:0] addr,
  input [31:0] write,
  input er,
  input ew,
  input [2:0] memmask,
  input memsextsig,
  output [31:0] read,
  input valid_from,
  output ready_to
);
  reg [31:0] readreg;
  wire [31:0] read_u, read_s;
  
  typedef enum logic{
    WAIT_FOT_SIG,
    VALID
  } state_m;

  reg state;
  
  // here nned to be change
  always @(posedge clk) begin
    if (valid_from & (ew | er)) begin 
      case (state)
        VALID: begin
          state <= WAIT_FOT_SIG;
          if(ew) begin
            guest_write(addr, write, {{29{1'b0}},memmask});
          end

          if (er) begin
            readreg <= guest_read(addr, {{29{1'b0}},memmask});
          end else 
            readreg <= 0;
        end

        WAIT_FOT_SIG: begin
          state <= VALID;
          readreg <= 0;
        end
      endcase
    end
  end

  wire [31:0] read_sb, read_sh;
  sext#(8, 32) sext0(readreg[7:0], read_sb);
  sext#(16, 32) sext1(readreg[15:0], read_sh);

  assign read_s = (memmask == 3'b001) ? read_sb :
                  (memmask == 3'b010) ? read_sh :
                  readreg;
  assign read_u = readreg;
  assign read = (memsextsig == 1) ? read_s : read_u;

  assign ready_to = state == WAIT_FOT_SIG;

endmodule
