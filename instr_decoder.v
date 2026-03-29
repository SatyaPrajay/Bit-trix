module instr_decoder (
    input [7:0] instr,
    output reg [3:0] opcode,
    output reg [1:0] rd,
    output reg [1:0] rs1,
    output reg [1:0] rs2,
    output reg reg_wr_en,
    output reg ram_wr_en,
    output reg mac_en,
    output reg load_en,
    output reg store_en
);
    always @(*) begin
        // Decode fields
        opcode = instr[7:4];
        rd     = instr[3:2];
        rs1    = instr[3:2]; // same bits, dual role
        rs2    = instr[1:0];
 
        // Default control signals
        reg_wr_en = 0;
        ram_wr_en = 0;
        mac_en    = 0;
        load_en   = 0;
        store_en  = 0;
 
        case (opcode)
            4'b0000: begin // NOP - do nothing
            end
            4'b0001: begin // MAC
                mac_en    = 1;
                reg_wr_en = 1; // write result back to Rd
            end
            4'b0010: begin // LOAD: Rd = RAM[rs2]
                load_en   = 1;
                reg_wr_en = 1;
            end
            4'b0011: begin // STORE: RAM[rs2] = Rs1
                store_en  = 1;
                ram_wr_en = 1;
            end
            default: begin // unknown opcode = NOP
            end
        endcase
    end
endmodule
