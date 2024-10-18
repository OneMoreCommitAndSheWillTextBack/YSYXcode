#include "cpu/cpu.h"
#include "cpu/decode.h"
#ifdef CONFIG_FTRACE
void ftrace_init(char *elf_path) {}

void dealftrace(Decode *s) {}

#endif
