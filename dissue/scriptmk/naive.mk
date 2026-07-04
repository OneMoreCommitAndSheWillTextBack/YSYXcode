include $(dir $(lastword $(MAKEFILE_LIST)))build.mk
include $(PRJ)/resource/difftest/difftest.mk

DIFFTEST_REF ?= nemu
DIFFTEST_ARGS ?= --difftest-ref $(DIFFTEST_REF)
DIFFTEST_ARGS += --batch
DIFFTEST_ARGS += --wave

WAVE_PATH ?= ./wave.vcd

ARGS ?= $(DIFFTEST_ARGS)

run: verilator-exec difftest
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR_EXEC) $(ARGS)

sim: $(WAVE_PATH)
	gtkwave $(WAVE_PATH)

.PHONY: run sim
