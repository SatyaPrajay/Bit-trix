module your_some_unit #(parameter WIDTH = 8) (
    input clk,
    input rst,
    input [3:0] opcode,
    input [WIDTH-1:0] a,
    input [WIDTH-1:0] b,
    output reg [2*WIDTH-1:0] out
);

    // ===================== ACCUMULATOR =====================
    reg [2*WIDTH-1:0] acc;

    // zero-extended inputs
    wire [2*WIDTH-1:0] a_ext = {{WIDTH{1'b0}}, a};
    wire [2*WIDTH-1:0] b_ext = {{WIDTH{1'b0}}, b};

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            acc <= 0;
            out <= 0;
        end
        else begin
            case(opcode)

                // ================= ADD =================
                4'b0000: begin
                    out <= a_ext + b_ext;
                end

                // ================= SUB =================
                4'b0001: begin
                    out <= a_ext - b_ext;
                end

                // ================= MUL =================
                4'b0010: begin
                    out <= a_ext * b_ext;
                end

                // ================= MAC =================
                4'b0011: begin
                    acc <= acc + (a_ext * b_ext);
                    out <= acc;
                end

                // ================= DIV =================
                4'b0100: begin
                    if (b != 0)
                        out <= a_ext / b_ext;
                    else
                        out <= 0;
                end

                default: begin
                    out <= 0;
                end

            endcase
        end
    end

endmodule