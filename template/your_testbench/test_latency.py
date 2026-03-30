import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import os

CLK_PERIOD_NS = 10
PROGRAM_FILE = "../opcode_gen/program.asm"
L = 10

X_START = 0
Y_START = L
H_START = 2 * L
CONST_TABLE_BASE = 3 * L

# Test data
x = [1, 2, 1, 3, 2, 1, 1, 2, 1, 1]
y = [2, 5, 4, 9, 8, 5, 4, 7, 5, 4]

def compute_expected_h(x, y):
    h = [0] * len(x)
    h[0] = y[0] // x[0]
    for n in range(1, len(x)):
        s = sum(x[k] * h[n - k] for k in range(1, n+1))
        h[n] = (y[n] - s) // x[0]
    return h

expected_h = compute_expected_h(x, y)

async def reset_dut(dut):
    dut.rst.value = 1
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

async def init_ram(dut):
    # Write x[n]
    for i, val in enumerate(x):
        dut.data_ram.mem[X_START + i] = val
    # Write y[n]
    for i, val in enumerate(y):
        dut.data_ram.mem[Y_START + i] = val
    # Write constant table: absolute addresses
    # Table at CONST_TABLE_BASE: stores addresses of x[0..L-1], y[0..L-1], h[0..L-1]
    for i in range(L):
        dut.data_ram.mem[CONST_TABLE_BASE + i] = X_START + i               # address of x[i]
        dut.data_ram.mem[CONST_TABLE_BASE + L + i] = Y_START + i          # address of y[i]
        dut.data_ram.mem[CONST_TABLE_BASE + 2*L + i] = H_START + i        # address of h[i]
    # Store constant 1 at end of table
    dut.data_ram.mem[CONST_TABLE_BASE + 3*L] = 1

async def preload_registers(dut):
    # Set registers directly via cocotb (simulation only)
    # R0 = 0 (x base), R1 = L (y base), R2 = 2*L (h base), R3 = CONST_TABLE_BASE
    dut.regs.regs[0] = X_START
    dut.regs.regs[1] = Y_START
    dut.regs.regs[2] = H_START
    dut.regs.regs[3] = CONST_TABLE_BASE

async def read_h(dut):
    h = []
    for i in range(L):
        h.append(dut.data_ram.mem[H_START + i])
    return h

async def run_program(dut, instr_list):
    for instr in instr_list:
        dut.instr.value = int(instr, 2)
        await RisingEdge(dut.clk)
    for _ in range(5):
        dut.instr.value = 0
        await RisingEdge(dut.clk)

@cocotb.test()
async def test_impulse_response(dut):
    cocotb.start_soon(Clock(dut.clk, CLK_PERIOD_NS, units="ns").start())
    await reset_dut(dut)
    await init_ram(dut)
    await preload_registers(dut)
    dut._log.info("RAM initialised, registers preloaded.")

    if not os.path.exists(PROGRAM_FILE):
        raise FileNotFoundError(f"Program file not found: {PROGRAM_FILE}")
    with open(PROGRAM_FILE, "r") as f:
        instr_list = [line.strip() for line in f if line.strip()]
    dut._log.info(f"Loaded {len(instr_list)} instructions from {PROGRAM_FILE}")

    await run_program(dut, instr_list)

    h_computed = await read_h(dut)

    dut._log.info("=" * 50)
    dut._log.info("IMPULSE RESPONSE RESULTS")
    dut._log.info("=" * 50)
    dut._log.info(f"{'n':<4} {'Expected':<10} {'Computed':<10} {'Match?'}")
    all_match = True
    for i in range(L):
        match = "✓" if h_computed[i] == expected_h[i] else "✗"
        dut._log.info(f"{i:<4} {expected_h[i]:<10} {h_computed[i]:<10} {match}")
        if h_computed[i] != expected_h[i]:
            all_match = False

    if all_match:
        dut._log.info("✓ All values match!")
    else:
        dut._log.error("✗ Mismatch detected!")

    total_cycles = int(dut.cycle_count.value)
    total_time_ns = total_cycles * CLK_PERIOD_NS
    dut._log.info("=" * 50)
    dut._log.info("⏱️  SIMULATION SUMMARY")
    dut._log.info("=" * 50)
    dut._log.info(f"Total Cycles   : {total_cycles}")
    dut._log.info(f"Clock Period   : {CLK_PERIOD_NS} ns")
    dut._log.info(f"Total Time     : {total_time_ns} ns")
    dut._log.info(f"Instructions   : {len(instr_list)}")
    dut._log.info("=" * 50)

    assert all_match, "Impulse response computation failed"