# Checkpoint regression suite.
#
#   make checkpoint     prep -> pack -> run, a few minutes end to end
#   make clean          drop the artifacts
#
# Everything big lands in ARTIFACTS, which defaults to tmpfs: the snapshots are
# half a gigabyte each and are always regenerable from plans/.

PYTHON    ?= python3
ARTIFACTS ?= /dev/shm/dissue-checkpoint
PLANS     ?= plans

NEMU_HOME ?= ../../nemu
NEMU      ?= $(NEMU_HOME)/build/riscv32-nemu-interpreter
NEMU_REF  ?= $(NEMU_HOME)/tools/spike-diff/build/riscv32-spike-so
CKPT_GEN  ?= $(NEMU_HOME)/pyscript/ckpt_gen.py

PACK      ?= ../utils/pack/pack
RESTORER  ?= ../utils/pack/restorer/restorer.bin
SIM       ?= ../build/verilator-exec

checkpoint:
	$(PYTHON) runner/suite.py \
	    --plans $(PLANS) --artifacts $(ARTIFACTS) \
	    --nemu $(NEMU) --ref $(NEMU_REF) --ckpt-gen $(CKPT_GEN) \
	    --pack $(PACK) --restorer $(RESTORER) --sim $(SIM)

clean:
	rm -rf $(ARTIFACTS)

.PHONY: checkpoint clean
