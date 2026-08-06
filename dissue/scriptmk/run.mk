RUN_MK_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(RUN_MK_DIR)/build.mk
include $(PRJ)/resource/difftest/difftest.mk

DIFFTEST_REF ?= nemu
DIFFTEST_ARGS ?= --difftest-ref $(DIFFTEST_REF)

DEFAULT_ARGS += --batch

WAVE_PATH ?= $(DISSUE_HOME)/run/wave.vcd
KONATA_PATH ?= $(DISSUE_HOME)/run/konata.log

TRACE_ARGS += --wave-path $(WAVE_PATH) --konata-path $(KONATA_PATH)
DEFAULT_ARGS += $(TRACE_ARGS) ${DIFFTEST_ARGS}

ARGS ?= $(DIFFTEST_ARGS)

run: verilator-exec difftest
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR_EXEC) $(ARGS)

sim: $(WAVE_PATH)
	gtkwave $(WAVE_PATH)

.PHONY: run sim
