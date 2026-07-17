include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/dissue.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32ima_zicsr_zifencei -mabi=ilp32   # overwrite
LDFLAGS       += -melf32lriscv --no-relax               # overwrite

AM_SRCS += riscv/npc/libgcc/div.S \
           riscv/npc/libgcc/muldi3.S \
           riscv/npc/libgcc/multi3.c \
           riscv/npc/libgcc/ashldi3.c \
           riscv/npc/libgcc/unused.c
