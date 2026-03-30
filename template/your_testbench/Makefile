# Simulation Settings
TOPLEVEL_LANG = verilog
SIM = verilator

# The module name of your top-level Verilog file
TOPLEVEL = top

# The name of your Python testbench file (without .py)
MODULE = test_latency

# Points to all Verilog files in your src directory
VERILOG_SOURCES = $(wildcard $(shell pwd)/../src/*.v)

# 👇 THIS ENABLES GTKWAVE (.vcd) GENERATION
EXTRA_ARGS += --trace --trace-structs

# 🛠️ FIX FOR BIT-TRIX ERRORS:
# We add these flags to ignore the linting warnings that were stopping the build.
# -Wno-UNOPTFLAT: Allows the fast "Forwarding" logic in our registers.
# -Wno-WIDTHTRUNC: Allows using 8-bit registers to address 6-bit RAM.
# -Wno-WIDTHEXPAND: Allows the 17-bit math for the MAC unit.
# -Wno-EOFNEWLINE: Ignores missing blank lines at the end of files.
EXTRA_ARGS += -Wno-UNOPTFLAT -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-EOFNEWLINE -Wno-DECLFILENAME

# Include the Cocotb simulation rules
include $(shell cocotb-config --makefiles)/Makefile.sim