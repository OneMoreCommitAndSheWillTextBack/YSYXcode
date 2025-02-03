module ysyx_24100007_compare #(parameter NR_KEY = 2,parameter KEY_LEN = 32)(
    input [NR_KEY * 2 * KEY_LEN - 1 : 0] tbl, 
    input [KEY_LEN - 1 : 0] data,
    output [NR_KEY - 1 : 0] out
);

  genvar i;
  generate
    for (i = 0; i < NR_KEY; i = i + 1) begin : compare_loop
      wire [KEY_LEN - 1 : 0] upper_bound = tbl[(2 * i + 1) * KEY_LEN - 1 : 2 * i * KEY_LEN];
      wire [KEY_LEN - 1 : 0] lower_bound = tbl[(2 * i + 2) * KEY_LEN - 1 : (2 * i + 1) * KEY_LEN];
      assign out[i] = (data >= lower_bound && data <= upper_bound) ? 1'b1 : 1'b0;
    end
  endgenerate

endmodule
