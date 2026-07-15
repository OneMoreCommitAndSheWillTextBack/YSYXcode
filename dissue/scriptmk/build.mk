SCRIPT_MK_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(SCRIPT_MK_DIR)/config.mk
include $(SCRIPT_MK_DIR)/signature.mk
include $(SCRIPT_MK_DIR)/chisel.mk
include $(SCRIPT_MK_DIR)/verilator.mk
include $(SCRIPT_MK_DIR)/native.mk
include $(SCRIPT_MK_DIR)/simulator.mk

.PHONY: simulator-bin verilator-sim-bin verilator-exec

simulator-bin: $(CARGO_DONE_STAMP)

# Compatibility alias for the old internal target name.
verilator-sim-bin: simulator-bin

verilator-exec: $(VERILATOR_EXEC)
