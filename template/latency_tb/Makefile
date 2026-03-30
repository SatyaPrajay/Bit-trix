TOPLEVEL_LANG = verilog

SIM = verilator

TOPLEVEL = top
MODULE = test_deconv

VERILOG_SOURCES = $(wildcard ../src/*.v)

EXTRA_ARGS += --trace

include $(shell cocotb-config --makefiles)/Makefile.sim
