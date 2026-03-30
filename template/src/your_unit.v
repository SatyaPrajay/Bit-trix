module your_unit #(parameter WIDTH = 8) (
    input clk,
    input rst,
    input [1:0] opcode,      // 00: ADD, 01: DIV, 10: SMAC (Sub-MAC), 11: SUB
    input [WIDTH-1:0] a,     // Operand A (e.g., y[n])
    input [WIDTH-1:0] b,     // Operand B (e.g., h[k])
    input [WIDTH-1:0] c,     // Operand C (e.g., x[n-k] or divisor x[0])
    output reg [WIDTH-1:0] out // 8-bit output with saturation
);

    // Intermediate wires for high-precision math before clamping
    wire [15:0] mult_res = b * c;
    wire [8:0]  add_res  = a + b;
    
    // Subtractive MAC: result = a - (b * c)
    // We use a signed-capable wire to check for underflow
wire signed [16:0] smac_res = {9'b0, a} - {1'b0, mult_res};

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            out <= 8'h00;
        end else begin
            case(opcode)
                // 00: SATURATING ADD
                2'b00: out <= (add_res > 255) ? 8'hFF : add_res[7:0];

                // 01: DIVISION (a / c) -> h[n] = (Accumulator) / x[0]
                2'b01: out <= (c == 0) ? 8'hFF : (a / c);

                // 10: SUBTRACTIVE MAC (a - (b * c)) 
                // This is the core of deconvolution!
                2'b10: begin
                    if (smac_res < 0) 
                        out <= 8'h00; // Underflow to zero
                    else
                        out <= smac_res[7:0];
                end

                // 11: SATURATING SUBTRACT (a - b)
                2'b11: out <= (a > b) ? (a - b) : 8'h00;

                default: out <= 8'h00;
            endcase
        end
    end
endmodule

