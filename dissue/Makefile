BUILD_DIR ?= ./build/
PRJ ?= playground
TARGET ?= npc

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i $(PRJ).runMain Elaborate --ysyx-target $(TARGET) --target-dir $(BUILD_DIR)

test: test-riscv32i test-riscv32im test-riscv32ima

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
	mill -i $(PRJ).runMain Elaborate --help

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

.PHONY: verilog test test-riscv32i test-riscv32im test-riscv32ima tb testbench tb-list testbench-list tb-clean testbench-clean help reformat checkformat bsp idea clean

include scriptmk/naive.mk

-include ../Makefile
