module ysyx_24100007_icache #(
    parameter INDEX_LEN = 3,
    parameter OFFSET_LEN = 2
)(  
    input clk,
    input rst,
    input [31:0] addr,
    input w_valid,
    input [DATABLOCK_SIZE-1:0] w_data,
    output hit,
    output [31:0] data_r,
    
    input icahce_flush,
    input [31:0] icahce_flush_addr
);
    localparam LINE_NUM = 2 ** INDEX_LEN;
    localparam TAG_LEN = 32 - INDEX_LEN - OFFSET_LEN;
    localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;

    wire [OFFSET_LEN-1:0] offset = addr[OFFSET_LEN-1:0];
    wire [INDEX_LEN-1:0] index = addr[OFFSET_LEN+INDEX_LEN-1:OFFSET_LEN];
    wire [TAG_LEN-1:0] tag = addr[31:OFFSET_LEN+INDEX_LEN];

    wire [INDEX_LEN-1:0] flush_index = icahce_flush_addr[OFFSET_LEN+INDEX_LEN-1:OFFSET_LEN];
    wire [TAG_LEN-1:0] flush_tag = icahce_flush_addr[31:OFFSET_LEN+INDEX_LEN];

    wire [LINE_NUM-1:0] line_hit;
    wire [LINE_NUM-1:0][31:0] line_data_r;
    wire [LINE_NUM-1:0] line_w_valid;
    wire [LINE_NUM-1:0] line_set_invalid;
    wire [LINE_NUM-1:0][DATABLOCK_SIZE-1:0] line_data_w;

    genvar i;
    generate
      for (i = 0; i < LINE_NUM; i = i + 1) begin : gen_cacheline
        assign line_w_valid[i] = w_valid && (index == i);
        assign line_data_w[i] = w_data;
      end
    endgenerate

    assign line_set_invalid[flush_index] = 1'b1;
 
    generate
        genvar i;
        for(i=0;i<LINE_NUM;i=i+1) begin
            ysyx_24100007_icahce_line #(
                .TAG_LEN(TAG_LEN),
                .INDEX_LEN(INDEX_LEN),
                .OFFSET_LEN(OFFSET_LEN)
            ) u_cacheline (
                .clk(clk),
                .rst(rst),
                .tag(tag),
                .offset(offset),
                .w_valid(line_w_valid[i]),
                .data_w(line_data_w[i]),
                .hit(line_hit[i]),
                .set_invalid(line_set_invalid[i]),
                .flush_tag(flush_tag),
                .data_r(line_data_r[i])
            );
        end
    endgenerate

    assign hit = line_hit[index];
    assign data_r = line_data_r[index];
endmodule

module ysyx_24100007_icahce_line #( 
    parameter TAG_LEN = 27,
    parameter INDEX_LEN = 3,
    parameter OFFSET_LEN = 2
)(  
    input clk,
    input rst,
    input [TAG_LEN-1:0] tag,
    input [OFFSET_LEN-1:0] offset,
    input w_valid,
    input [DATABLOCK_SIZE-1:0] data_w,
    input set_invalid,
    input [TAG_LEN-1:0] flush_tag,
    output hit,
    output [31:0] data_r
);
    localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
    localparam DATABLOCK_NUMB = DATABLOCK_SIZE / 32;

    reg [DATABLOCK_NUMB-1:0][31:0] data_block;
    reg valid_r;
    reg [TAG_LEN-1:0] tag_r;

    wire [OFFSET_LEN-3:0] word_idx = offset[OFFSET_LEN-1:2];
    assign data_r = data_block[word_idx];
    assign hit = (valid_r && (tag == tag_r));
    wire flush = set_invalid & (tag_r == flush_tag);

    always @(posedge clk) begin
        if(rst) begin
            valid_r <= 1'b0;
            tag_r <= {TAG_LEN{1'b0}};
            data_block <= {DATABLOCK_SIZE{1'b0}};
        end else begin
            if(w_valid) begin
                valid_r <= 1'b1;
                tag_r <= tag;
                data_block <= data_w;
            end else if(flush) begin
                valid_r <= 1'b0;
            end
        end
    end
    
endmodule