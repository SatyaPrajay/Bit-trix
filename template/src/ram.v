module ram #(
    parameter DEPTH = 64,
    parameter ADDR_WIDTH = 6
)(
    input clk,
    input wr_en,
    input  [ADDR_WIDTH-1:0] addr,
    input  [7:0] wr_data,
    output [7:0] rd_data   // ⚠️ remove reg
);

    // MEMORY
    reg [7:0] mem [0:DEPTH-1];

    integer i;

    // INIT
    initial begin
        for (i = 0; i < DEPTH; i = i + 1)
            mem[i] = 8'd0;
    end

    // WRITE (synchronous)
    always @(posedge clk) begin
        if (wr_en)
            mem[addr[5:0]] <= wr_data;
    end

    // 🔥 READ (COMBINATIONAL — THIS IS THE FIX)
    assign rd_data = mem[addr];

endmodule

