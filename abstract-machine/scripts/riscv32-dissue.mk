include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/dissue.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"
COMMON_CFLAGS += -march=rv32imac_zicsr_zifencei -mabi=ilp32   # overwrite
LDFLAGS       += -melf32lriscv --no-relax               # overwrite

