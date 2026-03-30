module register (
    input wire clk,           
    input wire rst,           
    input wire wr_en,         
    input wire [1:0] rd_addr, 
    input wire [1:0] rs1_addr,
input wire auto_inc,
    input wire [1:0] rs2_addr,
    input wire [7:0] wr_data, 
    output reg [7:0] rs1_data,
    output reg [7:0] rs2_data 
);

    reg [7:0] regs [0:3];
    integer i;

    // --- SEQUENTIAL BLOCK: Optimized with Pre-Set Pointers ---
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            regs[0] <= 8'd0;   // Accumulator
            regs[1] <= 8'd0;   // X-Pointer
            regs[2] <= 8'd10;  // Y-Pointer
            regs[3] <= 8'd20;  // H-Pointer
        end else begin
            if (wr_en) begin
                regs[rd_addr] <= wr_data;
            end
            
            // AUTO-INCREMENT LOGIC
            if (auto_inc) begin
                // If we used RS1 as a pointer, increment it
                regs[rs1_addr] <= regs[rs1_addr] + 1;
            end
        end
    end

    // --- COMBINATIONAL BLOCK: Keeping Internal Forwarding ---
       // --- SIMPLE COMBINATIONAL READ (No Forwarding) ---
    // This breaks the infinite loop and lets Verilator converge.
    always @(*) begin
        rs1_data = regs[rs1_addr];
        rs2_data = regs[rs2_addr];
    end

endmodule