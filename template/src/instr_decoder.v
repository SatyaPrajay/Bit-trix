module instr_decoder (
    input  [7:0] instr,
    output reg [3:0] opcode,
    output reg [1:0] rd,
    output reg [1:0] rs1,
    output reg [1:0] rs2,
    output reg reg_wr_en,      // 1 to write result back to a register
    output reg ram_wr_en,      // 1 to write data to RAM
    output reg [1:0] alu_op,   // Matches your_unit.v opcodes
    output reg sel_mem_to_reg, // 1 for LOAD (RAM -> Reg), 0 for ALU result
    output reg halt            // 1 to stop the cycle counter/execution
);

    always @(*) begin
        // Bit Splitting: [7:4] Opcode, [3:2] RD/RS1, [1:0] RS2
        opcode = instr[7:4];
        rd     = instr[3:2]; 
        rs1    = instr[3:2]; 
        rs2    = instr[1:0];

        // Default Control Signals (Prevents Latches)
        reg_wr_en      = 0;
        ram_wr_en      = 0;
        alu_op         = 2'b00; 
        sel_mem_to_reg = 0;
        halt           = 0;

        case (opcode)
            // 0000: LOAD_RAM (Reg[rd] = RAM[Reg[rs2]])
            4'b0000: begin 
                reg_wr_en      = 1;
                sel_mem_to_reg = 1;
            end

            // 0001: STORE_RAM (RAM[Reg[rs1]] = Reg[rs2])
            4'b0001: begin 
                ram_wr_en      = 1;
            end

            // 0010: ADD (Reg[rd] = Reg[rs1] + Reg[rs2])
            4'b0010: begin
                reg_wr_en      = 1;
                alu_op         = 2'b00; // ADD in your_unit.v
            end

            // 0011: SMAC (Reg[rd] = Reg[rd] - (Reg[rs1] * Reg[rs2]))
            // This matches the opcode 2'b10 we set in your_unit.v
            4'b0011: begin
                reg_wr_en      = 1;
                alu_op         = 2'b10; // SMAC in your_unit.v
            end

            // 0100: DIV (Reg[rd] = Reg[rs1] / Reg[rs2])
            // This matches opcode 2'b01 we set in your_unit.v
            4'b0100: begin
                reg_wr_en      = 1;
                alu_op         = 2'b01; // DIV in your_unit.v
            end

            // 0101: SUB (Reg[rd] = Reg[rs1] - Reg[rs2])
            4'b0101: begin
                reg_wr_en      = 1;
                alu_op         = 2'b11; // SUB in your_unit.v
            end

            // 1111: HALT
            4'b1111: begin
                halt           = 1;
            end

            default: begin
                halt           = 0;
            end
        endcase
    end
endmodule

