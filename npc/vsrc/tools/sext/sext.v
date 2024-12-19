module sext#(INPUT_WIDTH, OUTPUT_WIDTH) (
  input  wire signed [INPUT_WIDTH-1  : 0] input_number,
  output wire signed [OUTPUT_WIDTH-1 : 0] output_number
);
 assign output_number = {{(OUTPUT_WIDTH - INPUT_WIDTH){input_number[INPUT_WIDTH-1]}}, input_number};
endmodule
