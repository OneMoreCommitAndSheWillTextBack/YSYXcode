`define GENERAL 2'b00 // for the device that support Supports arbitrary byte access
`define BYTE 2'b01
`define HALFWORD 2'b10
`define WORD 2'b11

module ysyx_24100007_memwritelen(
    input [31:0] awaddr,
    input [2:0] wirtelen,
    output [3:0] wstrb,
    output reg [2:0] awsize,
    output [1:0] wdata_offset,
    output [1:0] awburst
);
    localparam device_num = 3;
    wire inuart = (awaddr >= 32'h10000000) && (awaddr <= 32'h10000fff);
    wire insram = (awaddr >= 32'h0f000000) && (awaddr <= 32'h0fffffff);
    wire inflash = (awaddr >= 32'h30000000) && (awaddr <= 32'h3fffffff);
    wire inspi = (awaddr >= 32'h10001000) && (awaddr <= 32'h10001fff);
    wire inpsram = (awaddr >= 32'h80000000) && (awaddr <= 32'h9fffffff);
    wire insdram = (awaddr >= 32'ha0000000) && (awaddr <= 32'hbfffffff);

    reg [1:0] bus_size;
    wire [2:0] awsize_general = (wirtelen == 3'b001) ? 3'b000 :
                                (wirtelen == 3'b010) ? 3'b001 :
                                (wirtelen == 3'b100) ? 3'b010 :
                                3'b000;

    always @(*) begin
        case ({insram|inspi|insdram|inpsram, 1'b0, inflash})
            3'b100:  bus_size = `WORD;
            3'b010:  bus_size = `HALFWORD;
            3'b001:  bus_size = `BYTE;
            default: bus_size = `GENERAL;
        endcase
    end

    always @(*) begin
        case (bus_size)
            `BYTE:     awsize = 3'b000;
            `HALFWORD: awsize = 3'b001;
            `WORD:     awsize = 3'b010;
            default:   awsize = awsize_general;
        endcase
    end

    // wstrb
    wire [3:0] wstrb_general;
    assign wstrb_general = (wirtelen == 3'b001) ? 4'b0001 :
                           (wirtelen == 3'b010) ? 4'b0011 :
                           (wirtelen == 3'b100) ? 4'b1111 :
                           4'b0000;

    wire [3:0] wstrb_byte;
    assign wstrb_byte = 4'b0001;

    wire [3:0] wstrb_halfword;

    wire [3:0] wstrb_word;
    wire [4:0] mux = {wirtelen, awaddr[1:0]};
    assign wstrb_word = (mux == 5'b00100) ? 4'b0001 :
                        (mux == 5'b00101) ? 4'b0010 :
                        (mux == 5'b00110) ? 4'b0100 :
                        (mux == 5'b00111) ? 4'b1000 :
                        (mux == 5'b01000) ? 4'b0011 :
                        (mux == 5'b01010) ? 4'b1100 :
                        (mux == 5'b10000) ? 4'b1111 :
                        4'b0000;

    assign wstrb = (bus_size == `GENERAL) ? wstrb_general :
                   (bus_size == `BYTE) ? wstrb_byte :
                   (bus_size == `HALFWORD) ? wstrb_halfword :
                   wstrb_word;

    assign wdata_offset = (bus_size == `WORD || bus_size == `GENERAL) ? awaddr[1:0] : 2'b0;
    assign awburst = inuart ? 2'b00 : 2'b01;

endmodule