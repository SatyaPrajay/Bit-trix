import cocotb
from cocotb.triggers import Timer, RisingEdge
from cocotb.clock import Clock
import os

@cocotb.test()
async def test_deconvolution_latency(dut):
    """Ultra-High-Speed Execution for Bit-Trix."""
    
    # 1. Initialize Clock (100MHz)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # 2. Hard Reset (Clear cycles and set hardcoded pointers)
    dut.rst.value = 1
    await Timer(5, unit="ns")
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # 3. Fast File Load
    if not os.path.exists("program.asm"):
        dut._log.error("❌ program.asm NOT FOUND")
        return

    with open("program.asm", "r") as f:
        # Strip comments and empty lines
        instructions = [line.split('//')[0].strip() for line in f if line.strip()]
    
    dut._log.info(f"⚡ FAST-LOAD: {len(instructions)} instructions ready.")

    # 4. 🔥 THE "BURST" LOOP
    # We remove the 1ns Timer and the log prints inside the loop.
    # Printing to the console is slow; we only do it once at the end.
    for instr_bin in instructions:
        dut.instr.value = int(instr_bin, 2)
        await RisingEdge(dut.clk)
        
        # Check for early HALT signal from hardware
        if hasattr(dut, 'halt') and dut.halt.value == 1:
            break

    # 5. Minimal settle time (1 cycle)
    await RisingEdge(dut.clk)

    # 6. Final Score Retrieval
    cycles = int(dut.cycle_count.value)
    
    print("\n" + "🚀" * 20)
    print(f"  🏆 FINAL BIT-TRIX SCORE: {cycles} CYCLES")
    print("🚀" * 20 + "\n")