AM_SRCS := riscv/ysyxsoc/start.S \
           riscv/ysyxsoc/trm.c \
		   riscv/ysyxsoc/boot.c \
		   riscv/ysyxsoc/ioe.c \
		   riscv/ysyxsoc/input.c \
		   riscv/ysyxsoc/gpu.c \
		   riscv/ysyxsoc/timer.c \
		   riscv/ysyxsoc/cte.c \
           riscv/nemu/trap.S \
           riscv/ysyxsoc/mpe.c \
           riscv/ysyxsoc/vme.c

CFLAGS    += -fdata-sections -ffunction-sections -O2
CFLAGS += -I$(AM_HOME)/am/src/riscv/ysyxsoc/include
LDFLAGS   += -T $(AM_HOME)/scripts/soclinker.ld \
			 --defsym=_pmem_start=0x0f000000 --defsym=_entry_offset=0x0 

LDFLAGS   += --gc-sections -e_start 
# LDFLAGS += --print-map # print the link map
CFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

NPC_HOME = /home/ysyx/project/ysyx-workbench/npc

ARGS = -f$(IMAGE).bin
ARGS += -b
ARGS += -r 2470534
# ARGS += -i 1000000
# ARGS += -d 1926100
# ARGS += -e
# ARGS += "-w\$$$$pc==0x100027b7"

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(NPC_HOME) ARGS='$(ARGS)' run

sim:
	$(MAKE) -C $(NPC_HOME) sim