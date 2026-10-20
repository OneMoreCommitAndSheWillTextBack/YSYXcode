# pack: NEMU snapshot -> dissue memory image
#
# Point NEMU at the tree that produced the snapshots; pack includes its headers
# so the CPU state layout can never drift.

NEMU ?= ../../../nemu

CC ?= cc
CFLAGS ?= -O2 -g -Wall -Wextra
CPPFLAGS += -D_FILE_OFFSET_BITS=64 -D_POSIX_C_SOURCE=200809L \
            -I$(NEMU)/include -I$(NEMU)/src/isa/riscv32/include
LDLIBS += -lzstd

OBJS = pack.o pack_snapshot.o pack_image.o pack_meta.o pack_restore.o

all: pack

pack: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJS): pack_snapshot.h pack_image.h pack_meta.h pack_restore.h pack_log.h npc_csr_list.h

# Needs a riscv toolchain, so it is not part of the default target.
restorer:
	$(MAKE) -C restorer

clean:
	rm -f pack $(OBJS)
	$(MAKE) -C restorer clean

.PHONY: all clean restorer
