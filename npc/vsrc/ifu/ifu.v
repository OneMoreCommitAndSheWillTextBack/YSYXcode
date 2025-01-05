module ifu(
  input clk,
  input rst,
  input [31:0] npc,
  input ready,

  output [31:0] pc,
  output [31:0] inst,
  output valid
);
  wire [31:0] pcbridge;
  wire [31:0] instbridge;
  wire infetch_ready;

  pcreg pcreg0(
    .clk(clk),
    .rst(rst),
    .npc(npc),
    .pcout(pcbridge),
    
    .ready_from(infetch_ready)
  );
  
  wire arready, rready;
  wire arvalid, rvalid;
  wire awready, wready;
  wire bvalid, bresp;
  sram infetch(
  .clk(clk),
  .awvalid(0),
  .awready(awready),
  .awaddr(0),
  .wvalid(0),
  .wready(wready),
  .wdata(0),
  .wstrb(0),  
  .bvalid(bvalid),
  .bready(0),
  .bresp(bresp),
  .arvalid(ready),
  .arready(arready),
  .araddr(pc),
  .rvalid(ready),
  .rready(rready),
  .rdata(instbridge)
  );

  assign pc = pcbridge;
  assign valid = instbridge != 0;
  assign infetch_ready = ready & valid;
endmodule
