BUILD_DIR ?= ./build/
PRJ ?= playground
TARGET ?= npc

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i $(PRJ).runMain Elaborate --ysyx-target $(TARGET) --target-dir $(BUILD_DIR)

test:
	mill -i $(PRJ).test

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

.PHONY: verilog test help reformat checkformat bsp idea clean

include scriptmk/naive.mk

-include ../Makefile
