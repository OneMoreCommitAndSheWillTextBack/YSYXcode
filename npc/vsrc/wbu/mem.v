module mem(
  input clk,
  input [31:0] addr,
  input [31:0] write,
  input er,
  input ew,
  input [2:0] memmask,
  output [31:0] read,
  input valid_from,
  output ready_to
);
  reg [31:0] readreg;
  
  typedef enum logic{
    WAIT_FOT_SIG,
    VALID
  } state_m;

  reg state;
  
  always @(posedge clk) begin
    if (valid_from & (ew | er)) begin 
      case (state)
        VALID: begin
          state = WAIT_FOT_SIG;
        end
        WAIT_FOT_SIG: begin
          state = VALID;
        end
      endcase
    end
  end

  always @(posedge clk) begin
    if (state == VALID) begin
      if(ew) begin
        // $display("\033[32m guest_write 0x%08x \033[0m", addr);
        guest_write(addr, write, {{29{1'b0}},memmask});
      end

      if (er) begin
        // $display("\033[32m guest_read 0x%08x \033[0m", addr);
        readreg = guest_read(addr, {{29{1'b0}},memmask});
      end else begin
        readreg = 0;
      end
    end else 
      readreg = 0;
  end

  assign ready_to = (~(er | ew)) | state == VALID;
  assign read = readreg;

endmodule
