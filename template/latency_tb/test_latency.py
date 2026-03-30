
program = [
    0b00000000,
    0b00010110,
    0b00010011,
    0b00110100,
    0b00101100,
    0b01001001,
    0b01011110,
    0b00011110,
    0b00000000,
]

for instr in program:
    dut.instr.value = instr
    await RisingEdge(dut.clk)

# run extra cycles
for _ in range(20):
    await RisingEdge(dut.clk)