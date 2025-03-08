CROSS_COMPILE := riscv64-linux-gnu-
COMMON_CFLAGS := -fno-pic -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O2
LDFLAGS       += -melf32lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h
