include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/dissue.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32i_zicsr -mabi=ilp32   # overwrite
LDFLAGS       += -melf32lriscv --no-relax               # overwrite

AM_SRCS += riscv/dissue/start.S \
           riscv/dissue/cte.c \
           riscv/dissue/trap.S \
           riscv/dissue/vme.c
