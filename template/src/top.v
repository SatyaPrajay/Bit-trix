module top (
    input clk,
    input rst,
    input [7:0] instr,
    output reg [255:0] cycle_count
);

    // decoder wires
    wire [3:0] opcode;
    wire [1:0] rd, rs1, rs2;
    wire reg_wr_en, ram_wr_en, use_mac;

    instr_decoder decoder (
        .instr(instr),
        .opcode(opcode),
        .rd(rd),
        .rs1(rs1),
        .rs2(rs2),
        .reg_wr_en(reg_wr_en),
        .ram_wr_en(ram_wr_en),
        .use_mac(use_mac)
    );

    // register file
    wire [7:0] rs1_data, rs2_data;
    reg  [7:0] wr_data;

    reg_file rf (
        .clk(clk),
        .rst(rst),
        .wr_en(reg_wr_en),
        .rd_addr(rd),
        .rs1_addr(rs1),
        .rs2_addr(rs2),
        .wr_data(wr_data),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    );

    // RAM
    wire [7:0] ram_out;

    ram mem (
        .clk(clk),
        .wr_en(ram_wr_en),
        .addr(rs1_data),       // using rs1 as address
        .wr_data(rs2_data),
        .rd_data(ram_out)
    );

    // MAC unit
    wire [15:0] mac_out;

    your_some_unit mac_unit (
        .clk(clk),
        .rst(rst),
        .a(rs1_data),
        .b(rs2_data),
        .out(mac_out)
    );

    // WRITEBACK LOGIC
    always @(*) begin
        wr_data = 8'b0;

        case (opcode)
            4'b0001: wr_data = mac_out[7:0];  // MAC
            4'b0010: wr_data = ram_out;       // LOAD_RAM
            4'b0100: wr_data = rs1_data;      // LOAD_REG
            4'b0101: wr_data = rs2_data;      // STORE_REG
            default: wr_data = 8'b0;
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