`define GENERAL 2'b00 // for the device that support Supports arbitrary byte access
`define BYTE 2'b01
`define HALFWORD 2'b10
`define WORD 2'b11

module ysyx_24100007_memwritelen(
    input [31:0] wdata_in,
    input [31:0] awaddr,
    input [2:0] wirtelen,
    output [3:0] wstrb,
    output [2:0] awsize
);
    wire insram = (awaddr >= 32'h10000000) && (awaddr <= 32'h10000fff);
    wire [1:0] bus_size;
    ysyx_24100007_MuxKeyWithDefault #(1, 1, 2) type_mux(
        .out(bus_size),
        .key({insram}),
        .default_out(`GENERAL),
        .lut({
            1'b1 , `BYTE
        })
    );

    ysyx_24100007_MuxKeyWithDefault #(3, 2, 3) len_mux(
        .out(awsize),
        .key(bus_size),
        .default_out(wirtelen),
        .lut({
            `BYTE, 3'b001,
            `HALFWORD, 3'b010,
            `WORD, 3'b100
        })
    );

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

    ysyx_24100007_MuxKey #(4, 2, 4) wstrb_mux(
        .out(wstrb),
        .key(bus_size),
        .lut({
            `GENERAL, wstrb_general,
            `BYTE, wstrb_byte,
            `HALFWORD, wstrb_halfword,
            `WORD, wstrb_word
        })
    );

endmodule