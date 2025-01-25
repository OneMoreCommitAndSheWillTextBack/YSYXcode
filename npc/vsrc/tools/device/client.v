module client(
  input clk;
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
      
    endcase
  end

endmodule
