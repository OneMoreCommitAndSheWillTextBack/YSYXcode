ifndef EXT
$(error EXT must be set before including test/mk/extension.mk)
endif

TEST_MK_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
TEST_ROOT := $(abspath $(TEST_MK_DIR)/..)
include $(TEST_MK_DIR)/extensions.mk

TEST_EXT_DIR := $(abspath $(TEST_ROOT)/$(EXT))

ifeq ($(filter $(EXT),$(SUPPORTED_EXTENSIONS)),)
$(error unsupported EXT=$(EXT); supported extensions: $(SUPPORTED_EXTENSIONS))
endif

ifeq ($(wildcard $(TEST_EXT_DIR)),)
$(error extension directory for EXT=$(EXT) was not found: $(TEST_EXT_DIR))
endif

ifeq ($(wildcard $(TEST_EXT_DIR)/Makefile),)
$(error extension directory for EXT=$(EXT) is incomplete; missing $(TEST_EXT_DIR)/Makefile)
endif

ifneq ($(abspath $(CURDIR)),$(TEST_EXT_DIR))
$(error EXT=$(EXT) must be built from $(TEST_EXT_DIR), but current directory is $(abspath $(CURDIR)))
endif

ifneq ($(origin NPC_HOME),command line)
NPC_HOME := $(abspath $(TEST_ROOT)/..)
endif

TEST_DIR := $(TEST_EXT_DIR)/tests
TEST_BUILD_DIR ?= $(TEST_ROOT)/build/$(EXT)
LOG_DIR := $(TEST_BUILD_DIR)/logs
RESULT := $(TEST_BUILD_DIR)/result.txt

CRT0 := $(TEST_ROOT)/mk/crt0.S
LINKER_SCRIPT := $(TEST_ROOT)/mk/linker.ld
TEST_HEADERS := $(wildcard $(TEST_ROOT)/mk/*.h)

CROSS_COMPILE ?= riscv64-linux-gnu-

ifeq ($(origin CC),default)
CC := $(CROSS_COMPILE)gcc
endif
ifeq ($(origin OBJCOPY),undefined)
OBJCOPY := $(CROSS_COMPILE)objcopy
endif
ifeq ($(origin OBJDUMP),undefined)
OBJDUMP := $(CROSS_COMPILE)objdump
endif

MARCH ?= rv32i
MABI ?= ilp32

ARCH_FLAGS := -march=$(MARCH) -mabi=$(MABI) -mcmodel=medany -mstrict-align
CPPFLAGS += -I$(TEST_ROOT)/mk
CFLAGS += $(ARCH_FLAGS) -std=gnu11 -O2 -Wall -Wextra \
	-ffreestanding -fno-builtin -fno-pic -fno-pie \
	-fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables \
	-ffunction-sections -fdata-sections
ASFLAGS += $(ARCH_FLAGS) -x assembler-with-cpp
LDFLAGS += $(ARCH_FLAGS) -nostdlib -nostartfiles -static \
	-Wl,-T,$(LINKER_SCRIPT) -Wl,-m,elf32lriscv -Wl,--no-relax \
	-Wl,--gc-sections -Wl,--build-id=none

DEFAULT_SIM := $(abspath $(NPC_HOME)/build/verilator-exec)
DEFAULT_WAVE_PATH := $(abspath $(NPC_HOME)/wave.vcd)
SIM ?= $(DEFAULT_SIM)
SIM_BASE_ARGS ?= --batch
DIFF = nemu
# SIM_BASE_ARGS += --wave
SIM_BASE_ARGS += --wave-path $(DEFAULT_WAVE_PATH)

ifneq ($(strip $(DIFF)),)
SIM_BASE_ARGS += --difftest-ref $(DIFF)
endif

C_TEST_SOURCES := $(sort $(wildcard $(TEST_DIR)/*.c))
ASM_TEST_SOURCES := $(sort $(wildcard $(TEST_DIR)/*.S))
C_TESTS := $(basename $(notdir $(C_TEST_SOURCES)))
ASM_TESTS := $(basename $(notdir $(ASM_TEST_SOURCES)))
DISCOVERED_TESTS := $(sort $(C_TESTS) $(ASM_TESTS))
SELECTED_TESTS := $(if $(strip $(ALL)),$(strip $(ALL)),$(DISCOVERED_TESTS))
UNKNOWN_TESTS := $(filter-out $(DISCOVERED_TESTS),$(SELECTED_TESTS))

TEST_BIN = $(TEST_BUILD_DIR)/$(TEST).bin
TEST_LOG = $(LOG_DIR)/$(TEST).log
TEST_WAVE_ARGS = $(if $(filter 1 yes true,$(WAVE)),--wave --wave-path $(abspath $(LOG_DIR)/$(TEST).vcd),)

COLOR_RED := \033[1;31m
COLOR_GREEN := \033[1;32m
COLOR_NONE := \033[0m

.PHONY: all run run-one build list clean check-tests
.PRECIOUS: $(TEST_BUILD_DIR)/%.elf

all: run

run: check-tests $(SIM)
	@mkdir -p "$(TEST_BUILD_DIR)" "$(LOG_DIR)"
	@: > "$(RESULT)"
	@printf "extension: %s\n" "$(EXT)"
	@printf "isa/abi:   %s / %s\n" "$(MARCH)" "$(MABI)"
	@printf "test list [%s item(s)]: %s\n\n" "$(words $(SELECTED_TESTS))" "$(SELECTED_TESTS)"
	@failed=0; passed=0; total=0; \
	for test in $(SELECTED_TESTS); do \
		total=$$((total + 1)); \
		printf "running %-24s" "$$test"; \
		if $(MAKE) -s --no-print-directory run-one TEST=$$test >/dev/null 2>&1; then \
			passed=$$((passed + 1)); \
			printf "$(COLOR_GREEN)PASS$(COLOR_NONE)\n"; \
			printf "[%-24s] $(COLOR_GREEN)PASS$(COLOR_NONE)\n" "$$test" >> "$(RESULT)"; \
		else \
			failed=$$((failed + 1)); \
			printf "$(COLOR_RED)***FAIL***$(COLOR_NONE) log: %s\n" "$(LOG_DIR)/$$test.log"; \
			printf "[%-24s] $(COLOR_RED)***FAIL***$(COLOR_NONE)\n" "$$test" >> "$(RESULT)"; \
		fi; \
	done; \
	printf "\n"; \
	cat "$(RESULT)"; \
	printf "\nsummary: %d passed, %d failed, %d total\n" "$$passed" "$$failed" "$$total"; \
	exit $$failed

run-one:
	@if [ -z "$(TEST)" ]; then \
		echo "[Error] TEST is required"; \
		exit 1; \
	fi
	@mkdir -p "$(LOG_DIR)"
	@{ \
		echo "+ build $(TEST)"; \
		$(MAKE) -s --no-print-directory "$(TEST_BIN)" && \
		echo "+ run $(TEST)" && \
		$(SIM) $(SIM_BASE_ARGS) $(TEST_WAVE_ARGS) --image "$(abspath $(TEST_BIN))" $(SIM_ARGS); \
	} > "$(TEST_LOG)" 2>&1

build: check-tests $(addprefix $(TEST_BUILD_DIR)/,$(addsuffix .bin,$(SELECTED_TESTS)))

list:
	@printf "extension: %s\n" "$(EXT)"
	@printf "isa/abi:   %s / %s\n" "$(MARCH)" "$(MABI)"
	@printf "tests [%s item(s)]: %s\n" "$(words $(DISCOVERED_TESTS))" "$(DISCOVERED_TESTS)"

check-tests:
	@if [ -z "$(DISCOVERED_TESTS)" ]; then \
		echo "[Error] no tests found under $(TEST_DIR)"; \
		exit 1; \
	fi
	@if [ -n "$(UNKNOWN_TESTS)" ]; then \
		echo "[Error] unknown test(s): $(UNKNOWN_TESTS)"; \
		echo "available tests: $(DISCOVERED_TESTS)"; \
		exit 1; \
	fi

$(DEFAULT_SIM):
	@$(MAKE) --no-print-directory -C "$(NPC_HOME)" verilator-exec

$(TEST_BUILD_DIR)/%.elf: $(TEST_DIR)/%.c $(CRT0) $(LINKER_SCRIPT) $(TEST_HEADERS)
	@mkdir -p "$(dir $@)"
	$(CC) $(CPPFLAGS) $(CFLAGS) $(CRT0) $< $(LDFLAGS) -Wl,-Map,$(TEST_BUILD_DIR)/$*.map -o $@

$(TEST_BUILD_DIR)/%.elf: $(TEST_DIR)/%.S $(CRT0) $(LINKER_SCRIPT) $(TEST_HEADERS)
	@mkdir -p "$(dir $@)"
	$(CC) $(CPPFLAGS) $(ASFLAGS) $(CRT0) $< $(LDFLAGS) -Wl,-Map,$(TEST_BUILD_DIR)/$*.map -o $@

$(TEST_BUILD_DIR)/%.bin: $(TEST_BUILD_DIR)/%.elf
	$(OBJCOPY) -O binary $< $@
	$(OBJDUMP) -d -S $< > $(TEST_BUILD_DIR)/$*.txt

clean:
	rm -rf "$(TEST_BUILD_DIR)" "$(TEST_EXT_DIR)/wave.vcd"
