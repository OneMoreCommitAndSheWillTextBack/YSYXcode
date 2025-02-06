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
  // 复制.data段（LMA->VMA）
  int *src = (int*)&_sdata_lma;  // 源地址（按int对齐）
  int *dst = (int*)&_sdata_vma;  // 目标地址（按int对齐）
  unsigned int len = (uintptr_t)&_edata_vma - (uintptr_t)dst;  // 总字节数
  unsigned int int_len = len / sizeof(int);  // 按int复制的次数

  for (unsigned int i = 0; i < int_len; i++) {
    dst[i] = src[i];
  }

  unsigned int remaining = len % sizeof(int);
  if (remaining != 0) {
    char *src_remain = (char*)src + int_len * sizeof(int);  // 正确偏移量
    char *dst_remain = (char*)dst + int_len * sizeof(int);  // 正确偏移量
    for (unsigned int i = 0; i < remaining; i++) {
      dst_remain[i] = src_remain[i];
    }
  }

  char *bss_start = (char*)&_sbss_vma;
  char *bss_end = (char*)&_ebss_vma;
  for (char *p = bss_start; p < bss_end; p++) {
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