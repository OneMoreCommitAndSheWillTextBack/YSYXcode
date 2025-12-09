# 公共配置
VERILATOR = verilator
VERILATOR_FLAGS = --trace --prof-exec --cc --MMD --exe --build --autoflush 
SOCPATH = /home/ysyx/project/ysyx-workbench/ysyxSoC
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
VALID_BUILD_MODES := npc ysyxsoc ysyxsoc_nvboard
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

	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
	VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
	VSRC += $(SOCPATH)/build/ysyxSoCFull.v
endif

# nvboard 部分
NXDC_FILES = constr/$(TOPNAME).nxdc
SRC_AUTO_BIND = $(abspath ./constr/auto_bind.cpp)

ifeq ($(BUILD_MODE),ysyxsoc_nvboard)
  	TOPNAME = ysyxSoCFull
  	NVBOARD_ENABLE = 1

  	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
	VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
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
	gtkwave ./wave.vcd

perf:
	python3 show-perf-table.py ./performance.txt

.PHONY: run clean sim npc ysyxsocys yxsoc-nvboard