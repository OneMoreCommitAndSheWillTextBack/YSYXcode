module ps2_top_apb(
  input         clock,
  input         reset,
  input  [31:0] in_paddr,
  input         in_psel,
  input         in_penable,
  input  [2:0]  in_pprot,
  input         in_pwrite,
  input  [31:0] in_pwdata,
  input  [3:0]  in_pstrb,
  output        in_pready,
  output [31:0] in_prdata,
  output        in_pslverr,

  input         ps2_clk,
  input         ps2_data
);

	typedef enum [1:0] {ST_IDLE, ST_WAIT_ACCEPT, ST_WAIT_ACK} state_t;
	reg [1:0] state;

	always @(posedge clock) begin
		if(reset) begin
			state <= ST_IDLE;
		end else begin
			case(state) 
				ST_IDLE: state <= ((is_read) ? (req_accept ? ST_WAIT_ACK : ST_WAIT_ACCEPT) : ST_IDLE);
				ST_WAIT_ACCEPT: state <= (req_accept ? ST_WAIT_ACK : ST_WAIT_ACCEPT);
				ST_WAIT_ACK: if (in_pready) state <= ST_IDLE;
				default: state <= state;
			endcase
		end
	end

	wire is_read = ((in_psel && !in_penable) || (state == ST_WAIT_ACCEPT)) && !in_pwrite;
	wire req_accept;

	ps2_core ps2_ctrl_core (
		.clk_i(clock),
		.rst_i(reset),
		
		.inport_rd_i(is_read),
		.inport_wr_i(4'b0),  // 写操作时传递字节使能
		.inport_addr_i(in_paddr),
		.inport_write_data_i(32'b0),
		.inport_len_i(1'b0),  // 根据您的需求设置，这里设为0表示单次传输
		.inport_penable(in_penable),
		
		.inport_accept_o(req_accept),  // 连接到APB的pready
		.inport_read_data_o(in_prdata),  // 连接到APB的prdata
		.inport_ack_o(in_pready),  // 连接到状态机的req_accept
		
		.ps2_clk(ps2_clk),
		.ps2_data(ps2_data)
	);

endmodule

module ps2_core (
	input clk_i,
	input rst_i,

	input inport_rd_i,
	input [3:0] inport_wr_i,
	input [31:0] inport_addr_i,
	input [31:0] inport_write_data_i,
	input inport_len_i,
	input inport_penable,

	output inport_accept_o,
	output [31:0] inport_read_data_o,
	output inport_ack_o,

	input ps2_clk,
	input ps2_data
);
	reg [2:0] ps2_clk_sync;
	reg [3:0] count;
	reg [9:0] buffer;

	reg [7:0] buffer_out;
	// ------------------------------
	// SYNC SAMPLING
	// ------------------------------
	// due to the clk is faster zhan zhe ps2_clk
	// so here syn as the clk
	always @(posedge clk_i) begin
		ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
	end

	wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

	reg buffer_out_valid;
	always @(posedge clk_i) begin
		if(rst_i) begin
			count <= 4'b0;
			buffer_out <= 8'b0;
		end else begin
			if(buffer_out_valid == 1'b1) begin
				buffer_out_valid <= 1'b0;
				buffer_out <= 8'b0;
			end

			if(sampling) begin
				if(count == 4'd10) begin
					if ((buffer[0] == 0) &&   // start bit
                    (ps2_data)       &&       // stop bit
                    (^buffer[9:1]) 		      // odd  parity
					) begin      
                    	buffer_out <= buffer[8:1];
						buffer_out_valid <= 1'b1;
						count <= 4'b0;
               		end
				end else begin
					buffer[count] <= ps2_data;
					count <= count + 1;
				end
			end 
		end
	end

	// ---------------------------
	// STATE MACHINE
	// ---------------------------

	localparam ST_IDLE = 0;
	localparam ST_READ = 1;

	reg state;

	always @(posedge clk_i) begin
		case(state)
		ST_IDLE: begin
			if(inport_rd_i)
				state <= ST_READ;
			else
				state <= ST_IDLE;
		end

		ST_READ: begin
			state <= ST_IDLE;
		end
		endcase
	end

	assign inport_accept_o = (state == ST_READ);

	reg idle_ack_q;
	always @(posedge clk_i) begin
		if(state == ST_READ)
			idle_ack_q <= 1'b1;
		else
			idle_ack_q <= 'b0;
	end

	assign inport_ack_o = idle_ack_q;

	// ---------------------------
	// FIFO
	// ---------------------------
	// Design Reference: https://zhuanlan.zhihu.com/p/551351794

	localparam DATA_WIDTH = 8;
	localparam DATA_DEPTH_BASE = 3;
	localparam DATA_DEPTH = 8;
	localparam PTR_WIDTH = DATA_DEPTH_BASE + 1;

	wire w_clk = clk_i;
	wire r_clk = clk_i;
	wire w_en = buffer_out_valid;
	wire r_en = inport_rd_i & ~(state == ST_READ);
	wire [DATA_WIDTH-1:0] w_data = buffer_out;
	reg full, empty;
	reg [7:0] r_data;
	reg r_data_valid;

	reg     [DATA_WIDTH-1:0]    mem_array   [0:DATA_DEPTH-1];
    reg     [PTR_WIDTH-1 :0]    w_ptr, r_ptr;
    reg     [PTR_WIDTH-1 :0]    i;
    reg     [PTR_WIDTH-1 :0]    w_ptr_gray_d1, w_ptr_gray_d2, r_ptr_gray_d1, r_ptr_gray_d2;
    wire    [PTR_WIDTH-1 :0]    w_ptr_gray, r_ptr_gray;

	// w_ptr control
	always @(posedge w_clk) begin
        if(rst_i)
            w_ptr <= 4'b0;
        else if(w_en && !full)
            w_ptr <= w_ptr + 4'b1;
    end

	always @(posedge r_clk) begin
		if(rst_i)
			r_ptr <= 4'b0;
		else if(r_en && !empty)
			r_ptr <= r_ptr + 4'b1;
	end

	assign w_ptr_gray = w_ptr ^ (w_ptr >> 1);
    assign r_ptr_gray = r_ptr ^ (r_ptr >> 1);

	// sync gray code
    always @(posedge r_clk) begin
        if(rst_i) begin
            w_ptr_gray_d1 <= 4'b0;
            w_ptr_gray_d2 <= 4'b0;
        end else begin
            w_ptr_gray_d1 <= w_ptr_gray;
            w_ptr_gray_d2 <= w_ptr_gray_d1;
        end
    end

    always @(posedge w_clk) begin
        if(rst_i) begin
            r_ptr_gray_d1 <= 4'b0;
            r_ptr_gray_d2 <= 4'b0;
        end else begin
            r_ptr_gray_d1 <= r_ptr_gray;
            r_ptr_gray_d2 <= r_ptr_gray_d1;
        end
    end

	always @(*) begin
        if(rst_i)
            full = 1'b0;
        else if(w_ptr_gray == {~r_ptr_gray_d2[PTR_WIDTH-1:PTR_WIDTH-2], r_ptr_gray_d2[PTR_WIDTH-3:0]})
            full = 1'b1;
        else
            full = 1'b0;
    end

    always @(*) begin
        if(rst_i)
            empty = 1'b0;
        else if(r_ptr_gray == w_ptr_gray_d2)
            empty = 1'b1;
        else
            empty = 1'b0;
    end

	always @(posedge w_clk) begin
        if(rst_i) begin
            for(i = 0; i < DATA_DEPTH; i = i + 1) begin
                mem_array[i[2:0]] <= 8'b0;
            end
        end else if(w_en && !full) begin
            mem_array[w_ptr[PTR_WIDTH-2:0]] <= w_data;
			// $display("memwrite a data %x", w_data);
			// $fflush();
		end
    end

    always @(posedge r_clk) begin
        if(rst_i)
            r_data <= 8'b0;
        else if(r_en && !empty && !r_data_valid) begin
            r_data <= mem_array[r_ptr[PTR_WIDTH-2:0]];
			// $display("memread a data %x", mem_array[r_ptr[PTR_WIDTH-2:0]]);
			// $fflush();
		end else if(idle_ack_q) 
			r_data <= 8'b0;
    end

	always @(posedge r_clk) begin
		if(rst_i)
			r_data_valid <= 1'b0;
		else if(r_en && !empty) begin
			r_data_valid <= 1'b1;
		end if(idle_ack_q) 
			r_data_valid <= 1'b0;
	end

	assign inport_read_data_o = {24'b0, r_data};	
endmodule
