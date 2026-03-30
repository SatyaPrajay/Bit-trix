module top (
    input clk,
    input rst,
    input [7:0] instr,
    output reg [255:0] cycle_count
);
    // Internal Wires
    wire [3:0] opcode;
    wire [1:0] rd, rs1, rs2;
    wire reg_wr_en, ram_wr_en, sel_mem_to_reg;
    wire [1:0] alu_op;
    
    wire [7:0] rs1_data, rs2_data, alu_out, ram_rd_data;
    wire [7:0] write_back_data;

    // 1. Instruction Decoder
instr_decoder decoder (
        .instr(instr),
        .opcode(opcode), .rd(rd), .rs1(rs1), .rs2(rs2),
        .reg_wr_en(reg_wr_en), .ram_wr_en(ram_wr_en),
        .alu_op(alu_op), .sel_mem_to_reg(sel_mem_to_reg),
        .halt() // Add this empty pin here!
    );

    // 2. Register File
    register rf (
        .clk(clk), .rst(rst),
        .wr_en(reg_wr_en), .rd_addr(rd),
        .rs1_addr(rs1), .rs2_addr(rs2),
        .wr_data(write_back_data),
        .rs1_data(rs1_data), .rs2_data(rs2_data)
    );

    // 3. ALU (Your Unit)
    // We pass rs1_data as 'c' for MAC operations (Acc = Acc + A*B)
    your_unit #(8) alu (
        .clk(clk), .rst(rst),
        .opcode(alu_op),
        .a(rs1_data), .b(rs2_data), .c(rs1_data), 
        .out(alu_out)
    );

    // 4. RAM
    // Using rs1_data as the address for simplicity in this 8-bit ISA
    ram #(64, 8) data_mem (
        .clk(clk),
        .wr_en(ram_wr_en),
        .addr(rs1_data), 
        .wr_data(rs2_data),
        .rd_data(ram_rd_data)
    );

    // Mux: Choose between RAM data or ALU data to write back to registers
    assign write_back_data = sel_mem_to_reg ? ram_rd_data : alu_out;

    // ===================== CYCLE COUNTER =====================
    always @(posedge clk or posedge rst) begin
        if (rst)
            cycle_count <= 256'b0;
        else
            cycle_count <= cycle_count + 1;
    end
endmodule

