module psram(
  input sck,
  input ce_n,
  inout [3:0] dio
);
  typedef enum logic [3:0] {
    LEISURE,
    READ_INST,
    GET_ADDR,
    WAIT_CYCLES,
    EXECUTE
  } state_t;
  reg [3:0] state;
  reg [7:0] inst_buffer;
  reg [23:0] addr_buffer;
  reg [2:0] inst_counter;
  reg [2:0] addr_counter;
  reg [2:0] wait_counter;
  reg [7:0] data;
  reg finish;
  reg [3:0] dio_out_reg;
  reg dio_en;

  reg qpi_mode;
  always @(posedge sck or posedge reset) begin
    if(reset) begin
      if(inst_buffer == 8'h38)
        psram_write({8'b0,addr_buffer}, data);
      state <= LEISURE;
      inst_counter <= 3'b000;
      addr_counter <= 3'b000;
      wait_counter <= 3'b000;
      inst_buffer <= 0;
      addr_buffer <= 0;
      finish <= 0;
      data <= 0;
      dio_en <= 0;
      dio_out_reg <= 0;
    end else begin
      case(state) 
        LEISURE: begin
          state <= READ_INST;
          if(qpi_mode) begin
            inst_buffer[7:4] <= dio;
          end else begin
            inst_buffer[7] <= dio[0];
          end
          inst_counter <= 3'b001;
        end

        READ_INST: begin
          if(qpi_mode) begin
            if(inst_counter == 3'b010) begin
              state <= GET_ADDR;
              addr_buffer[23:20] <= dio[3:0];
              addr_counter <= 3'b001;
            end else begin
              inst_buffer[3:0] <= dio;
              inst_counter <= inst_counter + 1;
            end
          end else begin
            if(inst_counter == 3'b000) begin
              if(inst_buffer == 8'h35) begin
                state <= LEISURE;
                qpi_mode <= 1;
              end
              state <= GET_ADDR;
              addr_buffer[23:20] <= dio[3:0];
              addr_counter <= 3'b001;
            end else begin
              inst_buffer[7-inst_counter] <= dio[0];
              inst_counter <= inst_counter + 1;
            end
          end
        end

        GET_ADDR: begin
          if(addr_counter == 3'b110) begin
            case(inst_buffer)
            8'h38: begin
              state <= EXECUTE;
              data[7:4] <= dio[3:0];
              finish <= 1;
            end

            8'heb:begin
              state <= WAIT_CYCLES;
              wait_counter <= 3'b001;
              data <= psram_read({8'h00, addr_buffer});
            end

            default:begin
              $fwrite(32'h80000002, "Assertion failed: Unsupport command `%xh`\n", inst_buffer);
              $fatal();
            end
            endcase
          end else begin
            addr_buffer[20-4*addr_counter +: 4] <= dio[3:0];
            addr_counter <= addr_counter + 1;
          end
        end

        WAIT_CYCLES: begin
          if(wait_counter == 3'b110) begin
            state <= EXECUTE;
            addr_buffer <= addr_buffer + 1;
            dio_out_reg <= data[7:4];
            dio_en <= 1;
            finish <= 1;
          end else begin
            wait_counter <= wait_counter + 1;
          end
        end

        EXECUTE: begin
          case(inst_buffer)
            8'h38:begin
              if(finish == 0) begin
                data[7:4] <= dio[3:0];
                psram_write({8'b0,addr_buffer}, data);
                addr_buffer <= addr_buffer + 1;
                finish <= 1;
              end else begin
                data[3:0] <= dio[3:0];
                finish <= 0;
              end
            end
            8'heb:begin
              if(finish == 0) begin
                dio_out_reg <= data[7:4];
                dio_en <= 1;
                finish <= 1;
              end else begin
                data <= psram_read({8'h00, addr_buffer});
                addr_buffer <= addr_buffer + 1;
                dio_out_reg <= data[3:0];
                dio_en <= 1;
                finish <= 0;
              end
            end
            
            default: begin
              $fwrite(32'h80000002, "Assertion failed: Unsupport command `%xh`\n", inst_buffer);
              $fatal();
            end
          endcase
        end
        default: begin end
      endcase
    end 
  end

  wire reset = ce_n;

  assign dio = dio_en ? dio_out_reg : 4'bz;

  import "DPI-C" function void psram_write(input int addr, input byte data);
  import "DPI-C" function byte psram_read(input int addr);
endmodule