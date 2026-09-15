# Standalone vsoc smoke test: no core, no difftest, no project build system.
#
#   make -C playground/resource/vsoc/sim/tb run
#
# It elaborates u_soc with the Verilator flags the project build uses, so a
# clean lint here means the modules are ready to be wired into sim_top.
SHELL     := /bin/bash
VERILATOR ?= verilator
CXX       ?= c++

TB_DIR   := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
VSOC_DIR := $(abspath $(TB_DIR)/../..)
RTL_DIR  := $(VSOC_DIR)/rtl
OBJ_DIR  ?= $(TB_DIR)/obj
LOG      ?= $(TB_DIR)/smoke.log

SRCS := \
	$(RTL_DIR)/u_soc/pkg/vsoc_pkg.sv \
	$(RTL_DIR)/u_soc/pkg/vsoc_axi_if.sv \
	$(TB_DIR)/axi4_smoke_tb.sv \
	$(RTL_DIR)/u_soc/u_soc.sv \
	$(RTL_DIR)/u_soc/fabric/axi4_demux.sv \
	$(RTL_DIR)/u_soc/fabric/axi4_default_slave.sv \
	$(RTL_DIR)/u_soc/mem/axi4_ram_dpi.sv \
	$(RTL_DIR)/u_soc/periph/axi4_uart.sv \
	$(RTL_DIR)/u_soc/misc/axi4_delay.sv \
	$(VSOC_DIR)/sim/axi4_protocol_checker.sv

VFLAGS := -sv --cc --exe --build --timing \
	-Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN \
	--top-module axi4_smoke_tb --Mdir $(OBJ_DIR) -o smoke \
	--timescale "1ns/1ns"

.PHONY: all lint run clean

all: run

$(OBJ_DIR)/smoke: $(SRCS) $(TB_DIR)/axi4_smoke_main.cpp
	$(VERILATOR) $(VFLAGS) $(SRCS) $(TB_DIR)/axi4_smoke_main.cpp

lint:
	$(VERILATOR) -sv --lint-only --timing -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN \
		--top-module axi4_smoke_tb --timescale "1ns/1ns" $(SRCS)

run: $(OBJ_DIR)/smoke
	@set -o pipefail; $(OBJ_DIR)/smoke 2>&1 | tee $(LOG)
	@grep -q "\[smoke\] PASS" $(LOG)
	@grep -A1 "uart-char-follows" $(LOG) | grep -q "^U" \
		&& echo "[make] uart character observed" \
		|| { echo "[make] MISSING uart character"; exit 1; }

clean:
	rm -rf $(OBJ_DIR) $(LOG)
