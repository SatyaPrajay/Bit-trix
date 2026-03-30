import cocotb
from cocotb.triggers import RisingEdge, Timer

# OPCODES
ADD  = 0b0000
SUB  = 0b0001
MUL  = 0b0010
DIV  = 0b0100

def instr(op, rd, rs):
    return (op << 4) | (rd << 2) | rs


# CLOCK
async def clock_gen(dut):
    while True:
        dut.clk.value = 0
        await Timer(5, units="ns")
        dut.clk.value = 1
        await Timer(5, units="ns")


# RESET
async def reset(dut):
    dut.rst.value = 1
    dut.instr.value = 0
    await Timer(20, units="ns")
    dut.rst.value = 0


# EXECUTE
async def execute(dut, instruction):
    dut.instr.value = instruction
    await RisingEdge(dut.clk)


@cocotb.test()
async def test_deconv(dut):

    cocotb.start_soon(clock_gen(dut))
    await reset(dut)

    # ================= INPUT =================
    x = [1, 2, 3]
    y = [2, 7, 16]
    N = len(x)

    # ================= LOAD RAM =================
    for i in range(N):
        dut.data_mem.mem[i].value = x[i]
        dut.data_mem.mem[20+i].value = y[i]

    await Timer(10, units="ns")

    h = [0]*N

    # ================= MAIN ALGORITHM =================
    for n in range(N):

        y_val = int(dut.data_mem.mem[20+n].value)

        sum_val = 0

        for k in range(n):

            # load into registers
            dut.regfile.regs[1].value = dut.data_mem.mem[n-k].value
            dut.regfile.regs[2].value = h[k]

            # MUL
            await execute(dut, instr(MUL, 1, 2))

            mul_res = int(dut.regfile.regs[1].value)

            sum_val += mul_res

        num = y_val - sum_val

        # DIV
        dut.regfile.regs[1].value = num
        dut.regfile.regs[2].value = x[0]

        await execute(dut, instr(DIV, 1, 2))

        h[n] = int(dut.regfile.regs[1].value)

        # store in RAM
        dut.data_mem.mem[40+n].value = h[n]

    await Timer(20, units="ns")

    print("Computed h[n]:", h)
