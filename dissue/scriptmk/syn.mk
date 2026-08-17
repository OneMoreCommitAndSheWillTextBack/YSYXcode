#===============================================================================
# scriptmk/syn.mk
#
# One-shot logic synthesis (yosys) + static timing analysis (iEDA) flow for the
# dissue RISC-V processor, modeled after
#
# It reuses the yosys / iEDA binaries, the Tcl scripts and the nangate45 PDK
# shipped with the yosys-sta reference project, but consumes this repo's
# Chisel-generated RTL (build/filelist.f) and drops every report under
#   $(DISSUE_HOME)/run/<design>-<freq>MHz/
#
# Targets:
#   syn           synthesis only, produces $(DESIGN).netlist.v
#   sta           STA only, produces $(DESIGN).rpt (+ sta.log)
#   syn-sta       synthesis + STA in one shot, then prints a timing summary table
#   print-timing  re-parse the .rpt and print the timing table again (runs no tool)
#   clean-syn     remove this run's reports from run/
#
#===============================================================================

SHELL := /bin/bash

SYN_MK_DIR   := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

ifeq ($(wildcard $(DISSUE_HOME)),)
  $(error $$DISSUE_HOME must be set to the dissue repo root)
endif

# ---- toolchain: borrow the one bundled with the yosys-sta reference project --
YOSYS_STA_HOME ?= $(DISSUE_HOME)/../yosys-sta
SCRIPT_DIR     := $(YOSYS_STA_HOME)/scripts

YOSYS ?= $(YOSYS_STA_HOME)/dependency/oss-cad-suite-yosys-0.59-117/bin/yosys
ifeq ($(wildcard $(YOSYS)),)
  YOSYS = yosys
endif

IEDA ?= $(YOSYS_STA_HOME)/bin/iEDA
ifeq ($(wildcard $(IEDA)),)
  IEDA = iEDA
endif

# ---- design & timing constraints ---------------------------------------------
DESIGN        ?= ysyx_24100007
PDK           ?= nangate45
CLK_FREQ_MHZ  ?= 500
CLK_PORT_NAME ?= clock
SDC_FILE      ?= $(SCRIPT_DIR)/default.sdc
export CLK_FREQ_MHZ
export CLK_PORT_NAME

# ---- input RTL: Chisel-generated synthesis view (build/synth/filelist.f) -----
# Prefer the filelist computed by scriptmk/chisel.mk when integrated; fall back
# to the default synth directory for standalone use. Variables are prefixed
# SYN_RTL_* on purpose: config.mk's RTL_FILELIST/RTL_OUTPUT_DIR describe the
# simulation view and must stay untouched.
ifdef SYNTH_RTL_FILELIST
  SYN_RTL_FILELIST = $(SYNTH_RTL_FILELIST)
else
  SYN_RTL_FILELIST = $(DISSUE_HOME)/build/synth/filelist.f
endif
SYN_RTL_FILELIST   := $(abspath $(SYN_RTL_FILELIST))
SYN_RTL_OUTPUT_DIR := $(dir $(SYN_RTL_FILELIST))

# Simulation-only checkers excluded from synthesis: the CIRCT verification
# library emits bind modules and cross-module hierarchical references (e.g.
# `FetchTargetQueue.io_...') that yosys's Verilog frontend cannot elaborate.
# One ERE matched against filelist entries (relative to build/); may hold
# several |-separated patterns.
SYN_RTL_EXCLUDE ?= ^verification/

SYN_RTL_FILES := $(addprefix $(SYN_RTL_OUTPUT_DIR),$(shell grep -Ev '^[[:space:]]*$$' $(SYN_RTL_FILELIST) 2>/dev/null | grep -Ev '$(SYN_RTL_EXCLUDE)'))

# RTL list computed when the recipe actually runs (fresh after Chisel
# regenerates the filelist). Kept on one line: a multi-line expansion inside a
# recipe would be split into several shell commands by make.
SYN_RTL_AT_BUILD = $(shell grep -Ev '^[[:space:]]*$$' $(SYN_RTL_FILELIST) 2>/dev/null | grep -Ev '$(SYN_RTL_EXCLUDE)' | sed 's#^#$(SYN_RTL_OUTPUT_DIR)#' | tr '\n' ' ')

# ---- outputs: keep this run's reports inside dissue/run ----------------------
O           	?= $(DISSUE_HOME)/run
RESULT_DIR  	:= $(O)/$(DESIGN)-$(CLK_FREQ_MHZ)MHz
NETLIST_SYN_V 	:= $(RESULT_DIR)/$(DESIGN).netlist.v
TIMING_RPT  	:= $(RESULT_DIR)/$(DESIGN).rpt

SYN_TCL_DEPS := \
	$(SCRIPT_DIR)/yosys.tcl \
	$(SCRIPT_DIR)/common.tcl \
	$(SCRIPT_DIR)/pdk/$(PDK).tcl

# When included from the top-level Makefile (config.mk is loaded), hook the
# netlist onto the Chisel synthesis-view generation chain so that regenerated
# RTL automatically triggers re-synthesis.
SYN_RTL_PREREQ := $(SYN_RTL_FILELIST) $(SYN_RTL_FILES)
ifdef CHISEL_SYN_DONE_STAMP
  SYN_RTL_PREREQ := $(CHISEL_SYN_DONE_STAMP) $(SYNTH_RTL_OUTPUT_SIG) $(SYN_RTL_PREREQ)
endif

#===============================================================================
# Timing summary table: awk parses the iEDA $(DESIGN).rpt endpoint/TNS tables
# and prints WNS/WHS/TNS/Fmax plus the 5 worst setup paths. No external deps.
# NOTE: keep the awk program on a single line - a multi-line expansion inside
# a recipe would be split into several shell commands by make.
#===============================================================================
define TIMING_TABLE_AWK
BEGIN{FS="|";in_ep=0;in_tns=0;n_max=0;wns="";wnsn=0;whs="";whsn=0;fmax="NA";wns_ep="";whs_ep="";tns_max="NA";tns_min="NA"} function trim(s){gsub(/^[ \t]+|[ \t]+$$/,"",s);return s} function dash(n,s,i){s="";for(i=0;i<n;i++)s=s"-";return s} function hline(row){return "+"dash(length(row)-2)"+"} function short(s,n){return (length(s)>n)?substr(s,1,n-3)"...":s} /Endpoint/&&/Clock Group/{in_ep=1;in_tns=0;next} /Clock/&&/Delay Type/&&/TNS/{in_ep=0;in_tns=1;next} /Point/&&/Fanout/{in_ep=0;in_tns=0;next} /^\+[-+]*$$/{next} in_ep&&NF>=9{ep=trim($$2);cg=trim($$3);dt=trim($$4);sl=trim($$8);fq=trim($$9);if(cg~/^\*\*/)next;if(dt=="max"){n_max++;eps[n_max]=ep;sls[n_max]=sl;sln[n_max]=sl+0;frqs[n_max]=fq;if(wns==""||sl+0<wnsn){wns=sl;wnsn=sl+0;fmax=fq;wns_ep=ep}}else if(dt=="min"){if(whs==""||sl+0<whsn){whs=sl;whsn=sl+0;whs_ep=ep}}} in_tns&&NF>=4{t=trim($$3);v=trim($$4);if(t=="max")tns_max=v;else if(t=="min")tns_min=v} END{for(i=1;i<=n_max;i++)ord[i]=i;for(i=1;i<n_max;i++)for(j=i+1;j<=n_max;j++)if(sln[ord[j]]<sln[ord[i]]){t=ord[i];ord[i]=ord[j];ord[j]=t};period=(clk_mhz+0>0)?1000.0/clk_mhz:0;est="NA";if(wns!=""&&period>0&&period-wnsn>0)est=sprintf("%.3f",1000.0/(period-wnsn));print "";r=sprintf("|  %-80s |",sprintf("Timing Summary: %s @ %s MHz (%s, clk = %s)",design,clk_mhz,pdk,clk_name));h=hline(r);print h;print r;print h;r=sprintf("|  %-35s |  %-43s |","Metric","Value");h=hline(r);print h;print r;print h;printf "|  %-35s |  %-43s |\n","Clock period (constraint)",(period>0?sprintf("%.3f ns",period):"-");printf "|  %-35s |  %-43s |\n","WNS (setup / max)",(wns==""?"-":sprintf("%s ns%s",wns,(wnsn<0?" [VIOLATED]":"")));printf "|  %-35s |  %-43s |\n","WHS (hold / min)",(whs==""?"-":sprintf("%s ns%s",whs,(whsn<0?" [VIOLATED]":"")));printf "|  %-35s |  %-43s |\n","TNS (setup / max)",tns_max" ns";printf "|  %-35s |  %-43s |\n","TNS (hold / min)",tns_min" ns";printf "|  %-35s |  %-43s |\n","Fmax (worst setup path)",fmax" MHz";printf "|  %-35s |  %-43s |\n","Fmax (estimated from WNS)",est" MHz";print h;printf "|  %-35s |  %-43s |\n","Worst setup endpoint",(wns_ep==""?"-":short(wns_ep,43));printf "|  %-35s |  %-43s |\n","Worst hold endpoint",(whs_ep==""?"-":short(whs_ep,43));print h;print "";if(n_max>0){r=sprintf("|  %-6s  |  %-11s |  %-12s |  %-41s |","#","Slack(ns)","Freq(MHz)","Endpoint");h=hline(r);print h;print r;print h;n5=(n_max<5)?n_max:5;for(i=1;i<=n5;i++){k=ord[i];printf "|  %-6s  |  %-11s |  %-12s |  %-41s |\n",i,sls[k],frqs[k],short(eps[k],41)};print h;print ""}}
endef

define print_timing_table
awk -v clk_mhz=$(CLK_FREQ_MHZ) -v design=$(DESIGN) -v pdk=$(PDK) -v clk_name=$(CLK_PORT_NAME) '$(TIMING_TABLE_AWK)' $(1)
endef

#===============================================================================
# Targets
#===============================================================================
.PHONY: syn sta syn-sta print-timing clean-syn

syn: $(NETLIST_SYN_V)

sta: $(TIMING_RPT)

syn-sta: $(TIMING_RPT)
	@echo "[syn-sta] reports under: $(RESULT_DIR)"
	@$(call print_timing_table,$(TIMING_RPT))

print-timing:
	@test -f "$(TIMING_RPT)" || { echo "[print-timing] report not found: $(TIMING_RPT)"; exit 1; }
	@echo "[print-timing] parsing: $(TIMING_RPT)"
	@$(call print_timing_table,$(TIMING_RPT))

$(NETLIST_SYN_V): $(SYN_RTL_PREREQ) $(SYN_TCL_DEPS)
	@mkdir -p "$(@D)"
	@test -n "$(SYN_RTL_AT_BUILD)" || { echo "[syn] error: no RTL sources in $(SYN_RTL_FILELIST), run 'make verilog-synth' first"; exit 1; }; \
	echo "tcl $(SCRIPT_DIR)/yosys.tcl $(DESIGN) $(PDK) \"$(SYN_RTL_AT_BUILD)\" $@" | $(YOSYS) -g -l "$(@D)/yosys.log" -s -

$(TIMING_RPT): $(SCRIPT_DIR)/sta.tcl $(SDC_FILE) $(SYN_TCL_DEPS) $(NETLIST_SYN_V)
	@mkdir -p "$(RESULT_DIR)"
	@cd "$(YOSYS_STA_HOME)" && set -o pipefail && \
		$(IEDA) -script $(SCRIPT_DIR)/sta.tcl $(SDC_FILE) $(NETLIST_SYN_V) $(DESIGN) $(PDK) 2>&1 | tee "$(RESULT_DIR)/sta.log"

clean-syn:
	-rm -rf "$(RESULT_DIR)"
	@echo "[clean-syn] removed: $(RESULT_DIR)"
