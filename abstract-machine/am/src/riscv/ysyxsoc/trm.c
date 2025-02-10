#include <klib-macros.h>
#include "am.h"
#define UART_BASE 0x10000000
#define UART_TX   0
#define UART_LCR 3
#define UART_LSR 5

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
extern char _srodata_lma;
extern char _bss_lma;
extern char _sdata_vma;
extern char _edata_vma;
extern char _srodata_vma;
extern char _erodata_vma;
extern char _sbss_vma;
extern char _ebss_vma;

void loader_init() {
  // 复制.data段（LMA->VMA）
  int *src_data = (int*)&_sdata_lma;  // .data段的源地址（MROM）
  int *dst_data = (int*)&_sdata_vma;  // .data段的目标地址（SRAM）
  unsigned int data_len = (uintptr_t)&_edata_vma - (uintptr_t)dst_data;  // .data段的总字节数
  unsigned int data_int_len = data_len / sizeof(int) + 1;  // 按int复制的次数

  // 按int复制.data段
  for (unsigned int i = 0; i < data_int_len; i++) {
    dst_data[i] = src_data[i];
  }

  // 复制.rodata段（LMA->VMA）
  int *src_rodata = (int*)&_srodata_lma;  // .rodata段的源地址（MROM）
  int *dst_rodata = (int*)&_srodata_vma;  // .rodata段的目标地址（SRAM）
  unsigned int rodata_len = (uintptr_t)&_erodata_vma - (uintptr_t)dst_rodata;  // .rodata段的总字节数
  unsigned int rodata_int_len = rodata_len / sizeof(int) + 1;  // 按int复制的次数

  // 按int复制.rodata段
  for (unsigned int i = 0; i < rodata_int_len; i++) {
    dst_rodata[i] = src_rodata[i];
  }

  // 清零.bss段
  char *bss_start = (char*)&_sbss_vma;
  char *bss_end = (char*)&_ebss_vma;
  for (char *p = bss_start; p <= bss_end; p++) {
    *p = 0;
  }
}

void serial_init() {
  // set the 7th bit of LCR to 1
  *(int *)(UART_BASE + UART_LCR * 8) |= (1 << 7);
  // set the band rate
  // *(int *)(UART_BASE + UART_TX * 8) = 0x01;
  // // set the 7th bit of LCR to 0
  // *(int *)(UART_BASE + UART_LCR * 8 * 4) &= ~(1 << 7);
}

void putch(char ch) {
    // while (!(*(volatile unsigned int *)(UART_BASE + UART_LSR) & (1 << 5)));
    *(volatile unsigned char *)(UART_BASE + UART_TX) = ch;
}

void halt(int code) {
  while (1)
    ;
}

void _trm_init() {
  loader_init();
  serial_init();
  int ret = main(mainargs);
  halt(ret);
}