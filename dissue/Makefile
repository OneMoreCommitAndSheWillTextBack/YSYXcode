BUILD_DIR ?= ./build/
PRJ ?= playground
TARGET ?= npc
PYTHON ?= python3
IPC_PROFILE_SCRIPT := $(abspath scriptpy/ipc_profile.py)

test: test-riscv32i test-riscv32im test-riscv32ima
	$(PYTHON) $(IPC_PROFILE_SCRIPT)

profile-log: test

test-riscv32i: verilator-exec
	$(MAKE) -C test run EXT=riscv32i

test-riscv32im: verilator-exec
	$(MAKE) -C test run EXT=riscv32im

test-riscv32ima: verilator-exec
	$(MAKE) -C test run EXT=riscv32ima

tb testbench: verilator-exec
	$(MAKE) -C test run

tb-list testbench-list:
	$(MAKE) -C test list

tb-clean testbench-clean:
	$(MAKE) -C test clean

help:
	$(MILL) -i $(PRJ).runMain Elaborate --help

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

bsp:
	mill -i mill.bsp.BSP/install

idea:
	mill -i mill.idea.GenIdea/idea

clean:
	-rm -rf $(BUILD_DIR)

include scriptmk/run.mk

-include ../Makefile

verilog: $(CHISEL_DONE_STAMP)

verilator: $(VERILATOR_DONE_STAMP)

.PHONY: verilog verilator test profile-log test-riscv32i test-riscv32im test-riscv32ima tb testbench tb-list testbench-list tb-clean testbench-clean help reformat checkformat bsp idea clean
