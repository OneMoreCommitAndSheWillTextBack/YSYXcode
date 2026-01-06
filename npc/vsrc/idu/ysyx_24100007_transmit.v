module ysyx_24100007_transmit(
    input clk,
    input rst,

    input [4:0] src1_addr_in,
    input [4:0] src2_addr_in,
    input [4:0] exu_rd,
    input [4:0] wbu_rd,

    input exu_res_valid,
    input wbu_res_valid,

    input [31:0] regout1_in,
    input [31:0] regout2_in,
    input [31:0] exu_transmit_data,
    input [31:0] wbu_transmit_data,

    output [31:0] src1,
    output [31:0] src2,
    output alu_arg_valid
);  

    wire src1_need_wbu = 
    wire src1_need = is_same_src1 & prev_regew;
    assign src1 = (src1_need) ? transmit_data : regout1_in;

    wire is_same_src2 = (src2_addr_in == prev_rd);
    wire src2_need = is_same_src2 & prev_regew;
    assign src2 = (src2_need) ? transmit_data : regout2_in;

    wire need_transmit = src1_need | src2_need;
    assign alu_arg_valid = (need_transmit & transmit_data_valid) | (!need_transmit);
endmodule