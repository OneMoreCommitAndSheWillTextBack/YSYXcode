module ysyx_24100007_memwritelen(
    input [2:0] wirtelen,
    input [1:0] final2b,
    output [3:0] wstrb
);

    wire [4:0] mux = {wirtelen, final2b};
    assign wstrb = (mux == 5'b00100) ? 4'b0001 :
                   (mux == 5'b00101) ? 4'b0010 :
                   (mux == 5'b00110) ? 4'b0100 :
                   (mux == 5'b00111) ? 4'b1000 :
                   (mux == 5'b01000) ? 4'b0011 :
                   (mux == 5'b01010) ? 4'b1100 :
                   (mux == 5'b10000) ? 4'b1111 :
                   4'b0000;

endmodule