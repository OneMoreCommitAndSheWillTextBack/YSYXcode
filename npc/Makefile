TOPNAME = ysyxSoCFull
VERILATOR=verilator
VERILATOR_FLAGS = --trace --prof-exec --cc --MMD  --exe --build --autoflush
SOCPATH = /home/ysyx/project/ysyx-workbench/ysyxSoC
INCLUDE_PATH = $(abspath ./include/)
VERILATOR_INCLUDE_PATH = $(abspath ./vsrc/include/)

VSRC=$(shell find $(abspath ./vsrc/) -name "*.v")
CSRC=$(shell find $(abspath ./csrc/) -name "*.cpp")

LLVMFLAGS = $(subst -D__STDC_FORMAT_MACROS,,$(shell llvm-config --cxxflags))

CFLAGS = $(patsubst %, --CFLAGS "-I%", $(INCLUDE_PATH))
CFLAGS += $(patsubst %, --CFLAGS "%", $(LLVMFLAGS))
CFLAGS += $(patsubst %, --LDFLAGS "%", $(shell llvm-config --libs))

VERILATOR_FLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/uart16550/rtl
VERILATOR_INCLUDE_PATH += $(SOCPATH)/perip/spi/rtl
VSRC += $(shell find $(SOCPATH)/perip -name "*.v")
VSRC += $(SOCPATH)/build/ysyxSoCFull.v

VERILATOR_INCLUDE = $(patsubst %, -I%, $(VERILATOR_INCLUDE_PATH))

BUILDDIR = ./build
OBJDIR = $(BUILDDIR)/obj_dir
BIN = $(BUILDDIR)/$(TOPNAME)

$(shell mkdir -p $(BUILDDIR))

$(BIN): $(VSRC) $(CSRC)
	$(VERILATOR) $(VERILATOR_FLAGS) $^ \
		$(CFLAGS) \
		$(VERILATOR_INCLUDE) \
		--top-module $(TOPNAME) \
		--Mdir $(OBJDIR) --exe -o $(abspath $(BIN))

run:$(BIN)
	# $(call git_commit, "run npc")
	$(BIN) $(ARGS)

clean:
	rm -rf $(BUILDDIR)

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	gtkwave ./wave.vcd
	

include ../Makefile

