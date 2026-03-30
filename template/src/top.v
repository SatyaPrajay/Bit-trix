module top (
    input clk,
    input rst,
    input [7:0] instr,
    output reg [255:0] cycle_count
);

// ===================== INTERNAL SIGNALS =====================

// instruction fields
wire [3:0] opcode;
wire [1:0] rd, rs1, rs2;

// register file signals
wire [7:0] reg_out1, reg_out2;
reg  [7:0] write_data;
reg        reg_write;

// ALU (16-bit internal)
wire [15:0] alu_out;

// RAM
wire [7:0] ram_out;
reg        mem_write;


// ===================== INSTRUCTION DECODE =====================
assign opcode = instr[7:4];
assign rd     = instr[3:2];
assign rs1    = instr[1:0];
assign rs2    = instr[1:0];


// ===================== REGISTER FILE =====================
reg_file regfile (
    .clk(clk),
    .rst(rst),
    .wr_en(reg_write),
    .rd_addr(rd),
    .rs1_addr(rs1),
    .rs2_addr(rs2),
    .wr_data(write_data),
    .rs1_data(reg_out1),
    .rs2_data(reg_out2)
);


// ===================== ALU =====================
your_some_unit alu (
    .clk(clk),
    .rst(rst),
    .opcode(opcode),
    .a(reg_out1),
    .b(reg_out2),
    .out(alu_out)
);


// ===================== DATA MEMORY =====================
ram data_mem (
    .clk(clk),
    .wr_en(mem_write),        // FIXED
    .addr({2'b00,reg_out2[5:0]}),          // address
    .wr_data(reg_out1),       // data in
    .rd_data(ram_out)         // data out
);


// ===================== CONTROL LOGIC =====================
always @(*) begin
    reg_write = 0;
    mem_write = 0;
    write_data = 0;

    case(opcode)

        4'b0000: begin // ADD
            write_data = alu_out[7:0];   // FIXED (truncate)
            reg_write = 1;
        end

        4'b0001: begin // SUB
            write_data = alu_out[7:0];
            reg_write = 1;
        end

        4'b0010: begin // MUL
            write_data = alu_out[7:0];
            reg_write = 1;
        end

        4'b0011: begin // MAC
            write_data = alu_out[7:0];
            reg_write = 1;
        end

        4'b0100: begin // DIV
            write_data = alu_out[7:0];
            reg_write = 1;
        end

        4'b0101: begin // LOAD
            write_data = ram_out;
            reg_write = 1;
        end

        4'b0110: begin // STORE
            mem_write = 1;
        end

        default: begin
            reg_write = 0;
            mem_write = 0;
        end

    endcase
end


// ===================== CYCLE COUNTER =====================
always @(posedge clk or posedge rst) begin
    if (rst)
        cycle_count <= 256'b0;
    else
        cycle_count <= cycle_count + 1;
end

endmodule