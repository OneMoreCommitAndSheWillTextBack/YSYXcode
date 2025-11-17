TOPNAME = ysyxSoCFull
VERILATOR = verilator
VERILATOR_FLAGS = --trace --prof-exec --cc --MMD --exe --build --autoflush
SOCPATH = /home/ysyx/project/ysyx-workbench/ysyxSoC
INCLUDE_PATH = $(abspath ./include/)
VERILATOR_INCLUDE_PATH = $(abspath ./vsrc/include/)

VSRC = $(shell find $(abspath ./vsrc/) -name "*.v")
CSRC = $(shell find $(abspath ./csrc/) -name "*.cpp")
HEADFILE = $(shell find $(INCLUDE_PATH) -name "*.h")

LLVMFLAGS = $(subst -D__STDC_FORMAT_MACROS,,$(shell llvm-config --cxxflags))

NXDC_FILES = constr/$(TOPNAME).nxdc
SRC_AUTO_BIND = $(abspath ./constr/auto_bind.cpp)

# 构建模式选择
NVBOARD_ENABLE ?= 1

BUILDDIR = ./build
OBJDIR = $(BUILDDIR)/obj_dir
BIN = $(BUILDDIR)/$(TOPNAME)

$(shell mkdir -p $(BUILDDIR))

# 基础编译标志
BASE_CFLAGS = $(patsubst %, --CFLAGS "-I%", $(INCLUDE_PATH)) \
              $(patsubst %, --CFLAGS "%", $(LLVMFLAGS)) \
              $(patsubst %, --LDFLAGS "%", $(shell llvm-config --libs))

VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
VSRC += $(SOCPATH)/build/ysyxSoCFull.v

VERILATOR_INCLUDE = $(patsubst %, -I%, $(VERILATOR_INCLUDE_PATH))

# NVBoard特定设置
ifeq ($(NVBOARD_ENABLE),1)
	CSRC += $(SRC_AUTO_BIND)
	BASE_CFLAGS += --CFLAGS -D__NVBOARD__
	BASE_CFLAGS += $(patsubst %, --CFLAGS "-I%", $(INC_PATH))
	LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
endif

NVBOARD_ENABLE = 1

$(BIN): $(VSRC) $(CSRC) $(HEADFILE) $(if $(filter 1,$(NVBOARD_ENABLE)),$(NVBOARD_ARCHIVE) $(SRC_AUTO_BIND))
	$(VERILATOR) $(VERILATOR_FLAGS) \
		$(VSRC) $(CSRC) \
		$(if $(filter 1,$(NVBOARD_ENABLE)),$(NVBOARD_ARCHIVE)) \
		$(BASE_CFLAGS) \
		$(VERILATOR_INCLUDE) \
		--top-module $(TOPNAME) \
		--Mdir $(OBJDIR) --exe -o $(abspath $(BIN)) \
		$(if $(filter 1,$(NVBOARD_ENABLE)),$(patsubst %, --LDFLAGS %, $(LDFLAGS)))

include $(NVBOARD_HOME)/scripts/nvboard.mk

# 自动生成引脚绑定文件
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# 目标别名
nvboard: NVBOARD_ENABLE = 1
nvboard: $(BIN)

without-nvboard: NVBOARD_ENABLE = 0
without-nvboard: $(BIN)

run: $(BIN)
	$(BIN) $(ARGS)

clean:
	rm -rf $(BUILDDIR)

sim:
	gtkwave ./wave.vcd

.PHONY: run clean sim nvboard normal