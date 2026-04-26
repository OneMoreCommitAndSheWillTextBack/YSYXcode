# 公共配置
VERILATOR = verilator
VERILATOR_FLAGS = --trace --prof-exec --cc --MMD --exe --build --autoflush 
SOCPATH = $(YSYXSOC_HOME)
INCLUDE_PATH = $(abspath ./include/)
VERILATOR_INCLUDE_PATH = $(abspath ./vsrc/include/)

VSRC = $(shell find $(abspath ./vsrc/) -name "*.v")
CSRC = $(shell find $(abspath ./csrc/) -name "*.cpp")
HEADFILE = $(shell find $(INCLUDE_PATH) -name "*.h")
LLVMFLAGS = $(subst -D__STDC_FORMAT_MACROS,,$(shell llvm-config --cxxflags))

BASE_CFLAGS = $(patsubst %, --CFLAGS "-I%", $(INCLUDE_PATH)) \
              $(patsubst %, --CFLAGS "%", $(LLVMFLAGS)) \
              $(patsubst %, --LDFLAGS "%", $(shell llvm-config --libs))

VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing

# 目标配置
# BUILD_MODE: npc / ysyxsoc / ysyxsoc_nvboard
# 默认第三种：ysyxsoc + nvboard
BUILD_MODE ?= ysyxsoc_nvboard

# 检查 BUILD_MODE 合法性
VALID_BUILD_MODES := npc ysyxsoc ysyxsoc_nvboard release
ifeq ($(filter $(BUILD_MODE),$(VALID_BUILD_MODES)),)
	$(error Invalid BUILD_MODE '$(BUILD_MODE)'. \
	Valid values: npc, ysyxsoc, ysyxsoc_nvboard. \
	Usage: make BUILD_MODE=npc run  or  make BUILD_MODE=ysyxsoc run  or  make BUILD_MODE=ysyxsoc_nvboard run)
endif

ifeq ($(BUILD_MODE),npc)
  TOPNAME = npc
  NVBOARD_ENABLE = 0
	VERILATOR_FLAGS += -D__NPC__
	BASE_CFLAGS += --CFLAGS -D__NPC__
	VSRC += ./vsrc-extra/npc.v
endif

ifeq ($(BUILD_MODE),ysyxsoc)
  TOPNAME = ysyxSoCFull
  NVBOARD_ENABLE = 0

	VERILATOR_FLAGS += -D__YSYXSOC__
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v
endif

# nvboard 部分
NXDC_FILES = $(NPC_HOME)/constr/ysyxSoCFull.nxdc
SRC_AUTO_BIND = $(NPC_HOME)/constr/auto_bind.cpp

ifeq ($(BUILD_MODE),ysyxsoc_nvboard)
  TOPNAME = ysyxSoCFull
  NVBOARD_ENABLE = 1

	VERILATOR_FLAGS += -D__YSYXSOC__
  	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v

	CSRC += $(SRC_AUTO_BIND)
	BASE_CFLAGS += --CFLAGS -D__NVBOARD__
	BASE_CFLAGS += $(patsubst %, --CFLAGS "-I%", $(INC_PATH))
	LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
endif

ifeq ($(BUILD_MODE),release)
  TOPNAME = ysyxSoCFull 
  NVBOARD_ENABLE = 1

	VERILATOR_FLAGS += -D__YSYXSOC__
  	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC = ./build/ysyx_24100007.v
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v

	CSRC += $(SRC_AUTO_BIND)
	BASE_CFLAGS += --CFLAGS -D__NVBOARD__
	BASE_CFLAGS += $(patsubst %, --CFLAGS "-I%", $(INC_PATH))
	LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
endif

BUILDDIR = ./build/$(BUILD_MODE)
OBJDIR = $(BUILDDIR)/obj_dir
BIN = $(BUILDDIR)/$(TOPNAME)

$(shell mkdir -p $(BUILDDIR))

VERILATOR_INCLUDE = $(patsubst %, -I%, $(VERILATOR_INCLUDE_PATH))

$(BIN): $(VSRC) $(CSRC) $(HEADFILE) $(if $(filter 1,$(NVBOARD_ENABLE)),$(NVBOARD_ARCHIVE) $(SRC_AUTO_BIND))
	$(VERILATOR) $(VERILATOR_FLAGS) \
		$(VSRC) $(CSRC) \
		$(if $(filter 1,$(NVBOARD_ENABLE)),$(NVBOARD_ARCHIVE)) \
		$(BASE_CFLAGS) \
		$(VERILATOR_INCLUDE) \
		--top-module $(TOPNAME) \
		--Mdir $(OBJDIR) --exe -o $(abspath $(BIN)) \
		$(if $(filter 1,$(NVBOARD_ENABLE)),$(patsubst %, --LDFLAGS %, $(LDFLAGS)))

-include $(NVBOARD_HOME)/scripts/nvboard.mk

# 自动生成引脚绑定文件
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

run: $(BIN)
	$(BIN) $(ARGS)

clean:
	rm -rf ./build/$(CLEAN_MODE)

sim:
	@if [ -f ./gtkwave.tcl ]; then \
		gtkwave ./wave.vcd --tcl_init ./gtkwave.tcl & \
	else \
		gtkwave ./wave.vcd & \
	fi

VERILOG_OUT = $(abspath ./build/ysyx_24100007.v)
VERILOG_ORDER = \
	vsrc/ysyx_24100007.v \
	vsrc/exu/ysyx_24100007_alucontrol.v \
	vsrc/exu/ysyx_24100007_alu.v \
	vsrc/exu/ysyx_24100007_brachcontrol.v \
	vsrc/exu/ysyx_24100007_exu.v \
	vsrc/idu/ysyx_24100007_control_unit.v \
	vsrc/idu/ysyx_24100007_decoder.v \
	vsrc/idu/ysyx_24100007_idu.v \
	vsrc/idu/ysyx_24100007_transmit.v \
	vsrc/ifu/ysyx_24100007_icache.v \
	vsrc/ifu/ysyx_24100007_ifu.v \
	vsrc/ifu/ysyx_24100007_pcreg.v \
	vsrc/lsu/ysyx_24100007_ifucfg.v \
	vsrc/lsu/ysyx_24100007_lsu.v \
	vsrc/lsu/ysyx_24100007_memreadlen.v \
	vsrc/lsu/ysyx_24100007_memwritelen.v \
	vsrc/lsu/ysyx_24100007_wbucfg.v \
	vsrc/reg/ysyx_24100007_regheap.v \
	vsrc/reg/ysyx_24100007_registers.v \
	vsrc/tools/sext/ysyx_24100007_sext.v \
	vsrc/tools/ysyx_24100007_arbiter.v \
	vsrc/tools/ysyx_24100007_clint.v \
	vsrc/wbu/ysyx_24100007_wbu.v \
	vsrc/ysyx_24100007_core.v
verilog:
	@mkdir -p build
	@echo + Merging vsrc/*.v into $(VERILOG_OUT)
	@( for f in $(VERILOG_ORDER); do cat "$$f"; echo; done ) > $(VERILOG_OUT)

ivg:
	@if [ -n "$(IVG)" ]; then \
		ln -sf $(IVG) /home/cinder/Code/project/ysyx-workbench/npc/bin.ivg; \
	fi
	iverilog -D__NPC__ -o /home/cinder/Code/project/ysyx-workbench/npc/build/npc_ivg -g2012 \
		/home/cinder/Code/project/ysyx-workbench/npc/build/ysyx_24100007.v \
		/home/cinder/Code/project/ysyx-workbench/npc/vsrc-extra/ivg_top.v \
		/home/cinder/Code/project/ysyx-workbench/npc/vsrc-extra/npc.v 
	vvp /home/cinder/Code/project/ysyx-workbench/npc/build/npc_ivg

BIN_IVG = /home/cinder/Code/project/ysyx-workbench/npc/bin.ivg

$(BIN_IVG): $(IMG)
	@if [ -z "$(IMG)" ]; then echo "Error: IMG=xxx.bin required"; exit 1; fi
	@echo Converting $(IMG) to readmemh format
	@(echo "@0"; xxd -p -c 0 $(IMG) | sed 's/\(..\)/\1 /g') > $(BIN_IVG)

sim-iverilog: $(IMG) $(BIN_IVG)
	iverilog -D__NPC__ -o $(abspath ./build/npc_ivg) -g2012 \
		$(VERILOG_OUT) \
		./vsrc-extra/ivg_top.v \
		./vsrc-extra/npc.v
	vvp ./build/npc_ivg

CELLS_V = $(if $(CELLS),$(shell find $(CELLS) -name "*.v" 2>/dev/null),)
sim-iverilog-netlist: $(IMG) $(BIN_IVG) $(NETLIST)
	iverilog -o $(abspath ./build/npc_ivg) -g2012 \
		$(CELLS_V) \
		$(NETLIST) \
		./vsrc-extra/ivg_top.v \
		./vsrc-extra/npc.v
	vvp ./build/npc_ivg

# Verilator 网表仿真：使用 NETLIST 替代 RTL，npc 为顶层，无需 ivg_top
# 用法: make sim-verilator-netlist NETLIST=path/to/ysyx_24100007.netlist.v.sim [CELLS=path/to/cells]
# 可选 CELLS: 工艺库路径，用于门级网表
BUILDDIR_NETLIST = ./build/netlist
OBJDIR_NETLIST = $(BUILDDIR_NETLIST)/obj_dir
BIN_NETLIST = $(BUILDDIR_NETLIST)/npc

$(shell mkdir -p $(BUILDDIR_NETLIST))

sim-verilator-netlist: $(BIN_NETLIST) $(IMG)
	@if [ -z "$(IMG)" ]; then echo "Error: IMG=xxx.bin required"; exit 1; fi
	$(BIN_NETLIST) $(ARGS) -f $(IMG)

$(BIN_NETLIST): $(NETLIST) $(CSRC) $(HEADFILE)
	@if [ -z "$(NETLIST)" ]; then echo "Error: NETLIST=path/to/netlist.v required"; exit 1; fi
	rm -rf $(OBJDIR_NETLIST)
	mkdir -p $(OBJDIR_NETLIST)
	$(VERILATOR) $(VERILATOR_FLAGS) -Wno-UNOPTFLAT -fno-inline \
		$(CELLS_V) \
		$(NETLIST) \
		./vsrc-extra/npc.v \
		$(CSRC) \
		$(BASE_CFLAGS) \
		$(VERILATOR_INCLUDE) \
		--CFLAGS -D__NPC__ \
		--top-module npc \
		--Mdir $(OBJDIR_NETLIST) --exe -o $(abspath $(BIN_NETLIST))
	

check:
	$(VERILATOR) --lint-only --top-module ysyx_24100007 -Wall -Wno-UNUSEDSIGNAL -Wno-DECLFILENAME /home/cinder/Code/project/ysyx-workbench/npc/release/ysyx_24100007.v 

perf:
	python3 show-perf-table.py ./performance.txt

.PHONY: run clean sim npc ysyxsocys yxsoc-nvboard check release sim-verilator-netlist sim-iverilog-netlist
