# compile_commands.json for clangd.
#
# clangd cannot guess how the build compiles these files. Without a database it
# walks up to ../build/compile_commands.json, which holds riscv64 cross-compile
# commands from someone else's machine, and then reports errors the real build
# does not have (missing "svdpi.h" is the visible one: it lives in
# $(VERILATOR_ROOT)/include/vltstd, which only the real flags point at).
#
# The database is generated from the same variables the build uses, so the
# editor always sees exactly what $(CXX) sees. Regenerate with `make clangd`.

CLANGD_MK_DIR ?= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CLANGD_HOME ?= $(patsubst %/,%,$(CLANGD_MK_DIR)/..)
CLANGD_DB ?= $(CLANGD_HOME)/compile_commands.json

CLANGD_SIM_DIR ?= $(abspath $(SIM_CPP_DIR))
CLANGD_TB_DIR ?= $(abspath $(VSOC_DIR)/sim/tb)

CLANGD_SIM_SRCS ?= $(sort $(wildcard $(SIM_CPP_DIR)/src/*.cpp))
CLANGD_TB_SRCS ?= $(sort $(wildcard $(VSOC_DIR)/sim/tb/*.cpp))

# The bridge is compiled by scriptmk/native.mk; the smoke testbench is built by
# its own standalone Makefile with Verilator driving the C++ compile.
CLANGD_SIM_FLAGS ?= $(SIM_NATIVE_CXXFLAGS) $(SIM_NATIVE_CPPFLAGS)
CLANGD_TB_FLAGS ?= -std=c++17 \
	-I$(abspath $(VSOC_DIR)/sim/tb/obj) \
	-I$(VERILATOR_ROOT)/include \
	-I$(VERILATOR_ROOT)/include/vltstd

.PHONY: clangd compile-commands
clangd compile-commands: $(CLANGD_DB)

$(CLANGD_DB): FORCE
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf '[\n'; \
		sep=''; \
		for src in $(CLANGD_SIM_SRCS); do \
			printf '%s' "$$sep"; sep=','; \
			printf '{"directory": "%s", "file": "%s", "arguments": ["%s"' \
				"$(CLANGD_SIM_DIR)" "$$src" "$(CXX)"; \
			for flag in $(CLANGD_SIM_FLAGS); do printf ', "%s"' "$$flag"; done; \
			printf ', "-c", "%s"]}' "$$src"; \
		done; \
		for src in $(CLANGD_TB_SRCS); do \
			printf '%s' "$$sep"; sep=','; \
			printf '{"directory": "%s", "file": "%s", "arguments": ["%s"' \
				"$(CLANGD_TB_DIR)" "$$src" "$(CXX)"; \
			for flag in $(CLANGD_TB_FLAGS); do printf ', "%s"' "$$flag"; done; \
			printf ', "-c", "%s"]}' "$$src"; \
		done; \
		printf '\n]\n'; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)
