include $(dir $(lastword $(MAKEFILE_LIST)))build.mk
include $(PRJ)/resource/difftest/difftest.mk

DIFFTEST_REF ?= nemu
SIM_ARGS ?= --difftest-ref $(DIFFTEST_REF)

run: verilator-exec difftest
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR_EXEC) $(SIM_ARGS)

sim: run

.PHONY: run sim
