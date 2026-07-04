// Simulation-only memory mapped peripherals.
//
// The AXI memory model talks to this file through a tiny byte-lane device bus:
// - *_addr is the aligned 32-bit bus beat address.
// - *_strb marks the byte lanes touched by this beat.
// - *_lane_hit tells the memory model which lanes belong to MMIO and must not
//   fall through to npc_pmem_read/npc_pmem_write.
//
// To add another peripheral:
// 1. Give it a BASE/SIZE entry in sim_mmio.
// 2. Instantiate the device below.
// 3. OR its lane_hit into the aggregate hit bus and OR/mux its read_data.
module sim_mmio (
    input clk,
    input rst,

    input         read_valid,
    input  [31:0] read_addr,
    input  [ 3:0] read_strb,
    output [ 3:0] read_lane_hit,
    output [31:0] read_data,

    input         write_valid,
    input  [31:0] write_addr,
    input  [31:0] write_data,
    input  [ 3:0] write_strb,
    output [ 3:0] write_lane_hit
);

  // NEMU/AM serial port. Only offset 0 has transmit side effect; the whole
  // 32-bit word is reserved by the device so accidental word writes do not
  // update simulated RAM at offsets 1..3.
  localparam [31:0] UART0_BASE = 32'ha000_03f8;
  localparam [31:0] UART0_SIZE = 32'd4;

  wire [ 3:0] uart0_read_lane_hit;
  wire [ 3:0] uart0_write_lane_hit;
  wire [31:0] uart0_read_data;

  sim_uart #(
      .BASE_ADDR(UART0_BASE),
      .ADDR_SIZE(UART0_SIZE)
  ) u_uart0 (
      .clk           (clk),
      .rst           (rst),
      .read_valid    (read_valid),
      .read_addr     (read_addr),
      .read_strb     (read_strb),
      .read_lane_hit (uart0_read_lane_hit),
      .read_data     (uart0_read_data),
      .write_valid   (write_valid),
      .write_addr    (write_addr),
      .write_data    (write_data),
      .write_strb    (write_strb),
      .write_lane_hit(uart0_write_lane_hit)
  );

  assign read_lane_hit  = uart0_read_lane_hit;
  assign write_lane_hit = uart0_write_lane_hit;

  // With one device this is just a pass-through. Keep the mask form so adding
  // a second read-only/read-write peripheral is a local edit.
  assign read_data = ({32{|uart0_read_lane_hit}} & uart0_read_data);
endmodule

module sim_uart #(
    parameter [31:0] BASE_ADDR = 32'ha000_03f8,
    parameter [31:0] ADDR_SIZE = 32'd4
) (
    input clk,
    input rst,

    input         read_valid,
    input  [31:0] read_addr,
    input  [ 3:0] read_strb,
    output [ 3:0] read_lane_hit,
    output [31:0] read_data,

    input         write_valid,
    input  [31:0] write_addr,
    input  [31:0] write_data,
    input  [ 3:0] write_strb,
    output [ 3:0] write_lane_hit
);

  localparam [31:0] TXDATA_ADDR = BASE_ADDR;

  function automatic in_uart_range(input [31:0] byte_addr);
    begin
      in_uart_range = (byte_addr >= BASE_ADDR) && (byte_addr < (BASE_ADDR + ADDR_SIZE));
    end
  endfunction

  wire [31:0] read_addr_lane0  = read_addr;
  wire [31:0] read_addr_lane1  = read_addr + 32'd1;
  wire [31:0] read_addr_lane2  = read_addr + 32'd2;
  wire [31:0] read_addr_lane3  = read_addr + 32'd3;
  wire [31:0] write_addr_lane0 = write_addr;
  wire [31:0] write_addr_lane1 = write_addr + 32'd1;
  wire [31:0] write_addr_lane2 = write_addr + 32'd2;
  wire [31:0] write_addr_lane3 = write_addr + 32'd3;

  assign read_lane_hit[0] = read_valid && read_strb[0] && in_uart_range(read_addr_lane0);
  assign read_lane_hit[1] = read_valid && read_strb[1] && in_uart_range(read_addr_lane1);
  assign read_lane_hit[2] = read_valid && read_strb[2] && in_uart_range(read_addr_lane2);
  assign read_lane_hit[3] = read_valid && read_strb[3] && in_uart_range(read_addr_lane3);

  assign write_lane_hit[0] = write_valid && write_strb[0] && in_uart_range(write_addr_lane0);
  assign write_lane_hit[1] = write_valid && write_strb[1] && in_uart_range(write_addr_lane1);
  assign write_lane_hit[2] = write_valid && write_strb[2] && in_uart_range(write_addr_lane2);
  assign write_lane_hit[3] = write_valid && write_strb[3] && in_uart_range(write_addr_lane3);

  wire tx_lane0 = write_valid && write_strb[0] && (write_addr_lane0 == TXDATA_ADDR);
  wire tx_lane1 = write_valid && write_strb[1] && (write_addr_lane1 == TXDATA_ADDR);
  wire tx_lane2 = write_valid && write_strb[2] && (write_addr_lane2 == TXDATA_ADDR);
  wire tx_lane3 = write_valid && write_strb[3] && (write_addr_lane3 == TXDATA_ADDR);
  wire tx_valid = tx_lane0 || tx_lane1 || tx_lane2 || tx_lane3;

  wire [7:0] tx_data = tx_lane0 ? write_data[7:0] :
                       tx_lane1 ? write_data[15:8] :
                       tx_lane2 ? write_data[23:16] :
                                  write_data[31:24];

  // Reads are intentionally side-effect free for now. Returning 0 mirrors a
  // permanently-ready transmit holding/status register well enough for tests
  // that probe the serial MMIO word.
  assign read_data = 32'b0;

  reg write_inflight;
  always @(negedge clk) begin
    if (rst) begin
      write_inflight <= 1'b0;
    end else if (write_valid && (|write_lane_hit)) begin
      if (!write_inflight && tx_valid) begin
        $write("%c", tx_data);
        $fflush;
      end
      write_inflight <= 1'b1;
    end else begin
      write_inflight <= 1'b0;
    end
  end
endmodule
