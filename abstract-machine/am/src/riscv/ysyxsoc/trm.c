#include <klib-macros.h>
#include "am.h"

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (8 * 1024 * 1024)
#define PMEM_END ((uintptr_t) & _pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) { *(char *)0x10000000 = ch; }

void halt(int code) {
  while (1)
    ;
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}