module instr_decoder (
    input  [7:0] instr,
    output reg [3:0] opcode,
    output reg [1:0] rd,
    output reg [1:0] rs1,
    output reg [1:0] rs2,

    // control signals
    output reg reg_wr_en,
    output reg ram_wr_en,
    output reg use_mac
);

    always @(*) begin
        opcode = instr[7:4];
        rd     = instr[3:2];
        rs1    = instr[3:2];
        rs2    = instr[1:0];

        // default
        reg_wr_en = 0;
        ram_wr_en = 0;
        use_mac   = 0;

        case (opcode)
            4'b0000: begin // NOP
            end

            4'b0001: begin // MAC
                reg_wr_en = 1;
                use_mac   = 1;
            end

            4'b0010: begin // LOAD_RAM
                reg_wr_en = 1;
            end

            4'b0011: begin // STORE_RAM
                ram_wr_en = 1;
            end

            4'b0100: begin // LOAD_REG
                reg_wr_en = 1;
            end

            4'b0101: begin // STORE_REG
                reg_wr_en = 1;
            end
        endcase
    end
endmodule