MILL ?= mill
VERILATOR ?= verilator
CARGO ?= cargo
CXX ?= c++
AR ?= ar

BUILD_DIR ?= ./build
PRJ ?= playground
TARGET ?= npc
TOP_MODULE ?= npc
ELABORATE_ARGS ?=
CHISEL_MODE ?= sim

ifeq ($(TOP_MODULE),npc)
else
$(error TOP_MODULE=$(TOP_MODULE) is unsupported because the native bridge is built for Vnpc)
endif

SUPPORTED_RUST_PROFILES := debug release
RUST_PROFILE_LEVEL ?= release

ifeq ($(filter $(RUST_PROFILE_LEVEL),$(SUPPORTED_RUST_PROFILES)),)
$(error Unsupported RUST_PROFILE_LEVEL: $(RUST_PROFILE_LEVEL). Supported: $(SUPPORTED_RUST_PROFILES))
endif

ifeq ($(RUST_PROFILE_LEVEL),debug)
RUST_PROFILE_ARGS :=
else
RUST_PROFILE_ARGS := --release
endif

SIM_RESOURCE_DIR ?= $(PRJ)/resource/sim-verilator
SIM_VERILOG_DIR ?= $(SIM_RESOURCE_DIR)/verilog
SIM_CPP_DIR ?= $(SIM_RESOURCE_DIR)/cpp
SIM_RUST_DIR ?= $(SIM_RESOURCE_DIR)/rust

# Simulation view RTL (--mode sim); the synthesis view lives in
# $(BUILD_DIR)/synth and is consumed by scriptmk/syn.mk.
RTL_FILELIST ?= $(BUILD_DIR)/sim/filelist.f
RTL_OUTPUT_DIR ?= $(dir $(RTL_FILELIST))
EXTRA_V ?= $(sort $(wildcard $(SIM_VERILOG_DIR)/*.v))

VERILATOR_ROOT ?= $(shell $(VERILATOR) --getenv VERILATOR_ROOT)
VERILATOR_BUILD_DIR ?= $(BUILD_DIR)/verilator
VERILATOR_OBJ_DIR ?= $(VERILATOR_BUILD_DIR)/obj_dir
VERILATOR_EXEC ?= $(abspath $(BUILD_DIR)/verilator-exec)
CARGO_TARGET_DIR ?= $(abspath $(VERILATOR_BUILD_DIR)/cargo-target)
CARGO_BIN ?= $(CARGO_TARGET_DIR)/$(RUST_PROFILE_LEVEL)/npc-chisel-sim

VERILATOR_MODEL_MK := $(VERILATOR_OBJ_DIR)/V$(TOP_MODULE).mk
VERILATOR_MODEL_HEADER := $(VERILATOR_OBJ_DIR)/V$(TOP_MODULE).h
VERILATOR_MODEL_ARCHIVE := $(VERILATOR_OBJ_DIR)/V$(TOP_MODULE)__ALL.a

SIM_NATIVE_LIB ?= $(abspath $(VERILATOR_BUILD_DIR)/libnpc_sim_native.a)
SIM_NATIVE_BUILD_DIR ?= $(abspath $(VERILATOR_BUILD_DIR)/native)
SIM_NATIVE_CXXFLAGS ?= -std=c++17 -O2 -fPIC \
	-DVM_TRACE=1 -DVM_TRACE_VCD=1 -DVM_TRACE_FST=0 \
	-DVM_COVERAGE=0 -DVM_SC=0 -DVL_DEBUG=0
SIM_NATIVE_CPPFLAGS := \
	-I$(abspath $(SIM_CPP_DIR)/include) \
	-I$(abspath $(VERILATOR_OBJ_DIR)) \
	-I$(abspath $(VERILATOR_ROOT)/include) \
	-I$(abspath $(VERILATOR_ROOT)/include/vltstd)

VERILATOR_FLAGS ?= -sv --cc --trace --MMD --no-timing --timescale "1ns/1ns" \
	-Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -autoflush

BUILD_META_DIR ?= $(BUILD_DIR)/.meta
CHISEL_INPUT_SIG ?= $(BUILD_META_DIR)/chisel-inputs.sig
CHISEL_DONE_STAMP ?= $(BUILD_META_DIR)/chisel-done.stamp
RTL_OUTPUT_SIG ?= $(BUILD_META_DIR)/rtl-output.sig
VERILATOR_CONFIG_SIG ?= $(BUILD_META_DIR)/verilator-config.sig
VERILATOR_CONFIG_APPLIED_STAMP ?= $(BUILD_META_DIR)/verilator-config-applied.stamp
VERILATOR_INPUT_SIG ?= $(BUILD_META_DIR)/verilator-inputs.sig
VERILATOR_DONE_STAMP ?= $(BUILD_META_DIR)/verilator-done.stamp
VERILATOR_OUTPUT_SIG ?= $(BUILD_META_DIR)/verilator-output.sig
MODEL_DONE_STAMP ?= $(BUILD_META_DIR)/model-done.stamp
MODEL_OUTPUT_SIG ?= $(BUILD_META_DIR)/model-output.sig
NATIVE_INPUT_SIG ?= $(BUILD_META_DIR)/native-inputs.sig
NATIVE_DONE_STAMP ?= $(BUILD_META_DIR)/native-done.stamp
NATIVE_OUTPUT_SIG ?= $(BUILD_META_DIR)/native-output.sig
CARGO_INPUT_SIG ?= $(BUILD_META_DIR)/cargo-inputs.sig
CARGO_DONE_STAMP ?= $(BUILD_META_DIR)/cargo-done.stamp
CARGO_OUTPUT_SIG ?= $(BUILD_META_DIR)/cargo-output.sig

CHISEL_BUILD_INPUTS := \
	Makefile \
	build.mill \
	$(wildcard .mill-version) \
	scriptmk/build.mk \
	scriptmk/config.mk \
	scriptmk/signature.mk \
	scriptmk/chisel.mk
