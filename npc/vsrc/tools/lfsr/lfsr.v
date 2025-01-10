module lfsr #(parameter WIDTH = 8) (
    input wire clk,
    input wire reset,
    output wire [WIDTH-1:0] out
);

    // LFSR的反馈多项式，这里使用的是一个8位的LFSR，反馈多项式为 x^8 + x^6 + x^5 + x^4 + 1
    // 你可以根据需要选择不同的反馈多项式
    reg [7:0] random_num;
    wire feedback = random_num[7] ^ random_num[5] ^ random_num[4] ^ random_num[3];

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            // 初始化LFSR的种子值，不能全为0
            random_num = 8'b10101010;
        end else begin
            // 移位并更新LFSR
            random_num = {random_num[6:0], feedback};
        end
    end

    assign out = random_num[WIDTH-1:0];

endmodule
