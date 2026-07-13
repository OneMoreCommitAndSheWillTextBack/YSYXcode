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

CXX ?= c++
AR ?= ar
SIM_NATIVE_LIB ?= $(abspath $(VERILATOR_BUILD_DIR)/libnpc_sim_native.a)
SIM_NATIVE_BUILD_DIR ?= $(VERILATOR_BUILD_DIR)/native
SIM_NATIVE_BRIDGE_SOURCES := $(sort $(wildcard $(SIM_CPP_DIR)/src/*.cpp))
SIM_NATIVE_RUNTIME_SOURCES := \
	$(VERILATOR_ROOT)/include/verilated.cpp \
	$(VERILATOR_ROOT)/include/verilated_dpi.cpp \
	$(VERILATOR_ROOT)/include/verilated_threads.cpp \
	$(VERILATOR_ROOT)/include/verilated_vcd_c.cpp
SIM_NATIVE_BRIDGE_OBJECTS := $(patsubst $(SIM_CPP_DIR)/src/%.cpp,$(SIM_NATIVE_BUILD_DIR)/bridge/%.o,$(SIM_NATIVE_BRIDGE_SOURCES))
SIM_NATIVE_RUNTIME_OBJECTS := $(patsubst $(VERILATOR_ROOT)/include/%.cpp,$(SIM_NATIVE_BUILD_DIR)/verilator/%.o,$(SIM_NATIVE_RUNTIME_SOURCES))
SIM_NATIVE_OBJECTS := $(SIM_NATIVE_BRIDGE_OBJECTS) $(SIM_NATIVE_RUNTIME_OBJECTS)
SIM_NATIVE_DEPFILES := $(SIM_NATIVE_OBJECTS:.o=.d)
SIM_NATIVE_CPPFLAGS := \
	-I$(SIM_CPP_DIR)/include \
	-I$(VERILATOR_OBJ_DIR) \
	-I$(VERILATOR_ROOT)/include \
	-I$(VERILATOR_ROOT)/include/vltstd
SIM_NATIVE_CXXFLAGS ?= -std=c++17 -O2 -fPIC \
	-DVM_TRACE=1 -DVM_TRACE_VCD=1 -DVM_TRACE_FST=0 \
	-DVM_COVERAGE=0 -DVM_SC=0 -DVL_DEBUG=0
VERILATOR_MODEL_HEADER := $(VERILATOR_OBJ_DIR)/V$(TOP_MODULE).h

VERILATOR_FLAGS ?= -sv --cc --trace --MMD --no-timing --timescale "1ns/1ns" \
	-Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -autoflush

verilator: verilog $(EXTRA_V)
	mkdir -p $(VERILATOR_OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) -F $(RTL_FILELIST) $(EXTRA_V) \
		--top-module $(TOP_MODULE) \
		--Mdir $(VERILATOR_OBJ_DIR)

$(VERILATOR_MODEL_HEADER): verilator
	@test -f $@

$(SIM_NATIVE_OBJECTS): | $(VERILATOR_MODEL_HEADER)

$(SIM_NATIVE_BUILD_DIR)/bridge/%.o: $(SIM_CPP_DIR)/src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(SIM_NATIVE_CXXFLAGS) $(SIM_NATIVE_CPPFLAGS) -MMD -MP -c $< -o $@

$(SIM_NATIVE_BUILD_DIR)/verilator/%.o: $(VERILATOR_ROOT)/include/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(SIM_NATIVE_CXXFLAGS) $(SIM_NATIVE_CPPFLAGS) -MMD -MP -c $< -o $@

$(SIM_NATIVE_LIB): $(SIM_NATIVE_OBJECTS)
	@mkdir -p $(dir $@)
	$(AR) crs $@ $^

verilator-exec: verilator $(SIM_NATIVE_LIB)
	@cd $(SIM_RUST_DIR) && \
		NPC_LINK_VERILATOR=1 \
		NPC_VERILATOR_TOP=$(TOP_MODULE) \
		NPC_VERILATOR_OBJ_DIR=$(abspath $(VERILATOR_OBJ_DIR)) \
		NPC_SIM_NATIVE_LIB=$(SIM_NATIVE_LIB) \
		CARGO_TARGET_DIR=$(CARGO_TARGET_DIR) \
		$(CARGO) build
	mkdir -p $(dir $(VERILATOR_EXEC))
	cp $(CARGO_BIN) $(VERILATOR_EXEC)

-include $(SIM_NATIVE_DEPFILES)

.PHONY: verilator verilator-exec
