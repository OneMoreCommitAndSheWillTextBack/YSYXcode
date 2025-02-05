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

extern char _sdata_lma;
extern char _bss_lma;
extern char _sdata_vma;
extern char _edata_vma;
extern char _sbss_vma;
extern char _ebss_vma;

void loader_init() {
  //复制.data段（LMA->VMA）
  char *src = (char*)&_sdata_lma;  // MROM中的源地址
  char *dst = (char*)&_sdata_vma;  // SRAM中的目标地址
  unsigned int len = (uintptr_t)&_edata_vma - (uintptr_t)dst;

  while (len--) {
    *dst++ = *src++;
  }

  for (char *p = (char*)&_sbss_vma; p < (char*)&_ebss_vma; p++) {
    *p = 0;
  }
}

void putch(char ch) { *(char *)0x10000000 = ch; }

void halt(int code) {
  while (1)
    ;
}

void _trm_init() {
  loader_init();
  int ret = main(mainargs);
  halt(ret);
}