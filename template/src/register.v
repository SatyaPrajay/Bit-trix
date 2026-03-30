module register (
    input wire clk,           // System Clock
    input wire rst,           // Active High Reset
    input wire wr_en,         // Write Enable signal from Decoder
    input wire [1:0] rd_addr, // Destination Register Address (0-3)
    input wire [1:0] rs1_addr,// Source Register 1 Address
    input wire [1:0] rs2_addr,// Source Register 2 Address
    input wire [7:0] wr_data, // Data to be written into rd_addr
    output reg [7:0] rs1_data,// Data output for Operand 1
    output reg [7:0] rs2_data // Data output for Operand 2
);

    // The 4 General Purpose Registers (8-bit each)
    reg [7:0] regs [0:3];
    integer i;

    // --- SEQUENTIAL BLOCK: Writing to Registers ---
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            // Initialize all 4 registers to zero on reset
            for (i = 0; i < 4; i = i + 1) begin
                regs[i] <= 8'b0;
            end
        end else if (wr_en) begin
            // Perform the write on the rising edge
            regs[rd_addr] <= wr_data;
        end
    end

    // --- COMBINATIONAL BLOCK: Reading with Internal Forwarding ---
    // This allows back-to-back instructions without "stalls"
    always @(*) begin
        // Internal Forwarding for Source 1
        if (wr_en && (rd_addr == rs1_addr)) begin
            rs1_data = wr_data; // Catch data before it even hits the flop
        end else begin
            rs1_data = regs[rs1_addr];
        end

        // Internal Forwarding for Source 2
        if (wr_en && (rd_addr == rs2_addr)) begin
            rs2_data = wr_data;
        end else begin
            rs2_data = regs[rs2_addr];
        end
    end

endmodule

