VERILATOR ?= verilator
CARGO ?= cargo
TOP_MODULE ?= npc

SIM_RESOURCE_DIR ?= $(PRJ)/resource/sim-verilator
SIM_VERILOG_DIR ?= $(SIM_RESOURCE_DIR)/verilog
SIM_CPP_DIR ?= $(SIM_RESOURCE_DIR)/cpp
SIM_RUST_DIR ?= $(SIM_RESOURCE_DIR)/rust

EXTRA_V ?= $(sort $(wildcard $(SIM_VERILOG_DIR)/*.v))
RTL_V ?= $(BUILD_DIR)/ysyx_24100007.sv
RTL_FILELIST ?= $(BUILD_DIR)/filelist.f

VERILATOR_ROOT ?= $(shell $(VERILATOR) --getenv VERILATOR_ROOT)
VERILATOR_BUILD_DIR ?= $(BUILD_DIR)/verilator
VERILATOR_OBJ_DIR ?= $(VERILATOR_BUILD_DIR)/obj_dir
VERILATOR_EXEC ?= $(abspath $(BUILD_DIR)/verilator-exec)
CARGO_TARGET_DIR ?= $(abspath $(VERILATOR_BUILD_DIR)/cargo-target)
CARGO_BIN ?= $(CARGO_TARGET_DIR)/debug/npc-chisel-sim

VERILATOR_FLAGS ?= -sv --cc --trace --MMD --no-timing --timescale "1ns/1ns" \
	-Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -autoflush

verilator: verilog $(EXTRA_V)
	mkdir -p $(VERILATOR_OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) -F $(RTL_FILELIST) $(EXTRA_V) \
		--top-module $(TOP_MODULE) \
		--Mdir $(VERILATOR_OBJ_DIR)

verilator-exec: verilator
	@cd $(SIM_RUST_DIR) && \
		NPC_LINK_VERILATOR=1 \
		NPC_VERILATOR_TOP=$(TOP_MODULE) \
		NPC_VERILATOR_OBJ_DIR=$(abspath $(VERILATOR_OBJ_DIR)) \
		NPC_SIM_CPP_DIR=$(abspath $(SIM_CPP_DIR)) \
		VERILATOR_ROOT=$(VERILATOR_ROOT) \
		CARGO_TARGET_DIR=$(CARGO_TARGET_DIR) \
		$(CARGO) build
	mkdir -p $(dir $(VERILATOR_EXEC))
	cp $(CARGO_BIN) $(VERILATOR_EXEC)

.PHONY: verilator verilator-exec
