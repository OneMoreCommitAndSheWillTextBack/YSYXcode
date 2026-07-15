CPP_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

ifndef NATIVE_BUILD_DIR
$(error NATIVE_BUILD_DIR must be supplied by the top-level build)
endif
ifndef NATIVE_LIB
$(error NATIVE_LIB must be supplied by the top-level build)
endif
ifndef VERILATOR_ROOT
$(error VERILATOR_ROOT must be supplied by the top-level build)
endif
ifndef MODEL_HEADER
$(error MODEL_HEADER must be supplied by the top-level build)
endif

CXX ?= c++
AR ?= ar
NATIVE_CXXFLAGS ?= -std=c++17 -O2 -fPIC
NATIVE_CPPFLAGS ?=
NATIVE_CONFIG_TAG ?=

BRIDGE_SOURCES := $(sort $(wildcard $(CPP_DIR)/src/*.cpp))
RUNTIME_SOURCES := \
	$(VERILATOR_ROOT)/include/verilated.cpp \
	$(VERILATOR_ROOT)/include/verilated_dpi.cpp \
	$(VERILATOR_ROOT)/include/verilated_threads.cpp \
	$(VERILATOR_ROOT)/include/verilated_vcd_c.cpp
BRIDGE_OBJECTS := $(patsubst $(CPP_DIR)/src/%.cpp,$(NATIVE_BUILD_DIR)/bridge/%.o,$(BRIDGE_SOURCES))
RUNTIME_OBJECTS := $(patsubst $(VERILATOR_ROOT)/include/%.cpp,$(NATIVE_BUILD_DIR)/verilator/%.o,$(RUNTIME_SOURCES))
NATIVE_OBJECTS := $(BRIDGE_OBJECTS) $(RUNTIME_OBJECTS)
DEPFILES := $(NATIVE_OBJECTS:.o=.d)
SOURCE_LIST_SIG := $(NATIVE_BUILD_DIR)/sources.sig
CONFIG_SIG := $(NATIVE_BUILD_DIR)/config.sig

.DEFAULT_GOAL := $(NATIVE_LIB)

.PHONY: FORCE
FORCE:

define replace_if_changed
if test -f "$(1)" && cmp -s "$(2)" "$(1)"; then \
	rm -f "$(2)"; \
else \
	mv -f "$(2)" "$(1)"; \
fi
endef

$(SOURCE_LIST_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ for file in $(BRIDGE_SOURCES) $(RUNTIME_SOURCES); do printf '%s\n' "$$file"; done; } | LC_ALL=C sort > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(CONFIG_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'cxx=%s\n' '$(CXX)'; \
		printf 'ar=%s\n' '$(AR)'; \
		printf 'model_header=%s\n' '$(MODEL_HEADER)'; \
		printf 'config_tag=%s\n' '$(NATIVE_CONFIG_TAG)'; \
		printf 'cxxflags=%s\n' '$(NATIVE_CXXFLAGS)'; \
		printf 'cppflags=%s\n' '$(NATIVE_CPPFLAGS)'; \
		"$(CXX)" --version 2>&1 || true; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(BRIDGE_OBJECTS): $(MODEL_HEADER) $(CONFIG_SIG)
$(RUNTIME_OBJECTS): $(CONFIG_SIG)

$(NATIVE_BUILD_DIR)/bridge/%.o: $(CPP_DIR)/src/%.cpp
	@mkdir -p "$(dir $@)"
	$(CXX) $(NATIVE_CXXFLAGS) $(NATIVE_CPPFLAGS) -MMD -MP -c "$<" -o "$@"

$(NATIVE_BUILD_DIR)/verilator/%.o: $(VERILATOR_ROOT)/include/%.cpp
	@mkdir -p "$(dir $@)"
	$(CXX) $(NATIVE_CXXFLAGS) $(NATIVE_CPPFLAGS) -MMD -MP -c "$<" -o "$@"

$(NATIVE_LIB): $(SOURCE_LIST_SIG) $(NATIVE_OBJECTS)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	rm -f "$$tmp"; \
	$(AR) crs "$$tmp" $(NATIVE_OBJECTS); \
	mv -f "$$tmp" "$@"

-include $(DEPFILES)
