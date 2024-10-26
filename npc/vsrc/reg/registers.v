module registers(
  input clk,
  input rst,
  input ew,
  input [4:0] addr,
  input [31:0] data,
  output [31:0] out [31:0]
);
  
  reg [31:0] rf [31:0];
  integer i;

  // write op
  always @(posedge clk or posedge rst) begin 
    if(rst) begin
      for(i=0;i<32;i=i+1) begin
        rf[i] = 0;
      end
    end else if(ew) begin
      rf[addr] <= data;
    end 
  end

  // read op
  assign out = rf;
  always @(posedge clk) begin
    $display("out[1] is %d | %x", out[1], out[1]);
    $display("out[2] is %d | %x", out[2], out[2]);
  end

endmodule
