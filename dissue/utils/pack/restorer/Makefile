# Builds restorer.bin: the program pack places in the reserved page.
#
# It is deliberately built without libc and without the C extension: it has to
# run on a core that has just come out of reset, with nothing set up.

CROSS ?= riscv64-linux-gnu-
CC     = $(CROSS)gcc
OBJCOPY= $(CROSS)objcopy
OBJDUMP= $(CROSS)objdump

ARCH   = -march=rv32ima_zicsr_zifencei -mabi=ilp32
CFLAGS = $(ARCH) -nostdlib -nostartfiles -ffreestanding -Os -Wall -Wextra
LDFLAGS= -Wl,-T,linker.ld -Wl,--build-id=none -Wl,-Map,restorer.map

all: restorer.bin

restorer.elf: restorer.S linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ restorer.S

restorer.bin: restorer.elf
	$(OBJCOPY) -O binary $< $@
	@printf 'restorer.bin: %s bytes\n' "$$(stat -c %s $@)"

disasm: restorer.elf
	$(OBJDUMP) -d $<

size: restorer.bin
	@stat -c %s restorer.bin

clean:
	rm -f restorer.bin restorer.elf restorer.map

.PHONY: all clean disasm size
