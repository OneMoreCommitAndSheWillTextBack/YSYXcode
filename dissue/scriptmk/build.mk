SCRIPT_MK_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

include $(SCRIPT_MK_DIR)/config.mk
include $(SCRIPT_MK_DIR)/signature.mk
include $(SCRIPT_MK_DIR)/chisel.mk
include $(SCRIPT_MK_DIR)/verilator.mk
include $(SCRIPT_MK_DIR)/native.mk
include $(SCRIPT_MK_DIR)/simulator.mk
include $(SCRIPT_MK_DIR)/clangd.mk

.PHONY: simulator-bin verilator-sim-bin verilator-exec clangd

simulator-bin: $(CARGO_DONE_STAMP)

# Compatibility alias for the old internal target name.
verilator-sim-bin: simulator-bin

# The clangd database rides along: it is cheap to regenerate and always in sync
# with the flags the model is actually built with.
verilator-exec: $(VERILATOR_EXEC) $(CLANGD_DB)

clangd: $(CLANGD_DB)
