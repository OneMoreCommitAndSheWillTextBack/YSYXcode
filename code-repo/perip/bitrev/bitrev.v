module bitrev (
  input  sck,
  input  ss,
  input  mosi,
  output miso
);
  typedef enum logic [1:0] {
    INPUT,
    WAIT,
    OUTPUT
  } state_t;

  reg [7:0] buffer;
  reg [2:0] count;
  reg [1:0] state;

  initial begin
    count = 0;
  end

  always @(posedge sck or posedge ss) begin
    if(ss) begin
      buffer <= 8'h00;
      state <= INPUT;
      count <= 3'b000;
    end else begin
      case(state[1:0])
        WAIT:
          state <= OUTPUT;

        INPUT: begin
          buffer[count] <= mosi;
          count <= count + 1;
          if(count == 3'b111) begin
            state <= WAIT;
            count <= 3'b000;
          end
        end
        
        OUTPUT: begin
          count <= count + 1;
          if(count == 3'b111) begin
            state <= INPUT;
            count <= 3'b000;
          end
        end

        default: begin
          $stop();
        end
      endcase
    end
  end

  wire buffer_out = buffer[7 - count];
  assign miso = (ss == 1) ? 1 : 
                (state == OUTPUT) ? buffer_out :
                1;
endmodule
