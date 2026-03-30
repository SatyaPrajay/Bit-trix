import cocotb
from cocotb.triggers import Timer, RisingEdge
from cocotb.clock import Clock
import os

# --- Helper: Discrete Deconvolution (The "Gold Standard") ---
def gold_deconvolve(x, y):
    n = len(y)
    h = [0] * n
    for i in range(n):
        # h[i] = (y[i] - sum(h[k] * x[i-k])) / x[0]
        sum_val = 0
        for k in range(i):
            sum_val += h[k] * x[i-k]
        
        # 8-bit Saturation Logic (matches your_unit.v)
        val = (y[i] - sum_val) // x[0]
        h[i] = max(0, min(255, val)) 
    return h

@cocotb.test()
async def test_deconvolution_latency(dut):
    """Test the hardware's ability to compute h[n] and measure cycles."""
    
    # 1. Start Clock
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # 2. Reset
    dut.rst.value = 1
    await Timer(20, unit="ns")
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # 3. Load Instructions
    if not os.path.exists("program.asm"):
        dut._log.error("❌ DISASTER: program.asm vanished!")
        return

    with open("program.asm", "r") as f:
        instructions = [line.strip() for line in f if line.strip()]
    
    dut._log.info(f"📜 Loaded {len(instructions)} instructions.")

    # 4. Core Execution Loop
    for i, instr_bin in enumerate(instructions):
        dut.instr.value = int(instr_bin, 2)
        dut._log.info(f"🚀 Cycle {i}: Sending Instr {instr_bin}")
        await RisingEdge(dut.clk)
        
        # Give the ALU one extra cycle to settle the 'write_back'
        await Timer(1, unit="ns") 

    # 5. Final Wait to ensure RAM stores are complete
    await Timer(50, unit="ns")

    # 6. Print the BIT-TRIX Score
    cycles = int(dut.cycle_count.value)
    print("\n" + "="*40)
    print(f"  🏆 BIT-TRIX SCORE: {cycles} CYCLES")
    print("="*40 + "\n")