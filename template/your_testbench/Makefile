TOPLEVEL_LANG = verilog
SIM = verilator

TOPLEVEL = top
MODULE = test_latency

VERILOG_SOURCES = $(wildcard $(PWD)/../src/*.v)

EXTRA_ARGS += --trace
VERILATOR_FLAGS += -Wall

include $(shell cocotb-config --makefiles)/Makefile.sim

# Ensure program.asm exists (generate if missing)
program.asm:
	python ../opcode_gen/opcode_gen.py

# Add dependency to ensure program.asm is generated before simulation
$(SIM_BUILD)/sim: program.asm