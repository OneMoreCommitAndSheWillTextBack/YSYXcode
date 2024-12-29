import "DPI-C" function int get_inst(int pc);
import "DPI-C" function void host_get_pc(int pc);
import "DPI-C" function void host_get_inst(int inst);

module infetch(
  input clk,
  input [31:0] pc,
  output reg [31:0] inst,
  
  output valid_to,
  input valid_from,
  output ready_to,
  input ready_from
  
);
  typedef enum logic{
    WAIT_FOR_INST,
    HAVE_INST
  } state_t;

  reg state;
  
  always @(posedge clk) begin
    if (ready_from == 1) begin
      case (state)
        WAIT_FOR_INST: begin
          inst = get_inst(pc);
          state <= HAVE_INST;
        end
        HAVE_INST: begin  
          state <= WAIT_FOR_INST;
          inst = 0;
        end
      endcase
    end
  end

  assign valid_to = inst != 0;
  assign ready_to = state == WAIT_FOR_INST;
endmodule
