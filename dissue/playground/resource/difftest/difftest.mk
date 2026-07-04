ifndef YSYX_HOME
ifdef NEMU_HOME
YSYX_HOME := $(abspath $(NEMU_HOME)/..)
else
YSYX_HOME := $(abspath $(CURDIR)/..)
endif
endif

NEMU_HOME ?= $(YSYX_HOME)/nemu

DIFFTEST_RESOURCE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
DIFFTEST_NEMU_SRC := $(NEMU_HOME)/build/riscv32-nemu-interpreter-so
DIFFTEST_SPIKE_SRC := $(NEMU_HOME)/tools/spike-diff/build/riscv32-spike-so
DIFFTEST_NEMU_LINK := $(DIFFTEST_RESOURCE_DIR)nemu/ref.so
DIFFTEST_SPIKE_LINK := $(DIFFTEST_RESOURCE_DIR)spike/ref.so

define check_difftest_env
	@if [ -z "$(YSYX_HOME)" ] || [ ! -d "$(YSYX_HOME)" ]; then \
		echo "[Error] YSYX_HOME is not set to a valid ysyx-workbench path"; \
		exit 1; \
	fi
	@if [ ! -d "$(NEMU_HOME)" ]; then \
		echo "[Error] NEMU_HOME=$(NEMU_HOME) is not a NEMU repo"; \
		exit 1; \
	fi
endef

difftest: $(DIFFTEST_NEMU_LINK) $(DIFFTEST_SPIKE_LINK)

$(DIFFTEST_NEMU_LINK): $(DIFFTEST_NEMU_SRC)
	$(call check_difftest_env)
	@mkdir -p $(dir $@)
	@ln -sfn $(abspath $<) $@
	@echo "linked $@ -> $(abspath $<)"

$(DIFFTEST_SPIKE_LINK): $(DIFFTEST_SPIKE_SRC)
	$(call check_difftest_env)
	@mkdir -p $(dir $@)
	@ln -sfn $(abspath $<) $@
	@echo "linked $@ -> $(abspath $<)"

.PHONY: difftest
