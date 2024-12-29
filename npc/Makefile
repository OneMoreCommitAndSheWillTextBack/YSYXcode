TOPNAME=top
VERILATOR=verilator
VERILATOR_CFLAGS = --trace --prof-exec --cc --exe --build
INCLUDE_PATH = $(abspath ./include/)

VSRC=$(shell find $(abspath ./vsrc/) -name "*.v")
CSRC=$(shell find $(abspath ./csrc/) -name "*.cpp")
HFILE = $(shell find $(abspath ./include/) -name "*.h")

LLVMFLAGS = $(subst -D__STDC_FORMAT_MACROS,,$(shell llvm-config --cxxflags))

CFLAGS = $(patsubst %, --CFLAGS "-I%", $(INCLUDE_PATH))
CFLAGS += $(patsubst %, --CFLAGS "%", $(LLVMFLAGS) -fPIE)
CFLAGS += $(patsubst %, --LDFLAGS "%", $(shell llvm-config --libs))

BUILDDIR = ./build
OBJDIR = $(BUILDDIR)/obj_dir
BIN = $(BUILDDIR)/$(TOPNAME)

$(shell mkdir -p $(BUILDDIR))

$(BIN): $(VSRC) $(CSRC) $(HFILE)
	@rm -rf $(OBJDIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) $^ \
		$(CFLAGS) \
		-I./vsrc/include/ \
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

