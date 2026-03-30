TOPLEVEL_LANG = verilog
SIM = verilator

TOPLEVEL = top
MODULE = test_latency

VERILOG_SOURCES = $(wildcard $(PWD)/../src/*.v)

EXTRA_ARGS += --trace
VERILATOR_FLAGS += -Wall

include $(shell cocotb-config --makefiles)/Makefile.sim