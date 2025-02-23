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

// uint32_t flash_read(uint32_t addr){
//   // 设置相关寄存器 -》 轮询flash接口，是否传输完毕
//   // reset 相关寄存器
//   volatile int *spi_tx_0 = SPI(TX);
//   volatile int *spi_tx_1 = SPI(TX + 0x4);
//   volatile int *spi_ctrl = SPI(CTRL);
//   volatile int *spi_ss = SPI(SS);
//   volatile int *spi_divider = SPI(DIVIDER);

//   *spi_tx_1 = 0x03 << 24 | (addr - 0x30000000);
//   *spi_ss = 0b00000001;
//   *spi_divider = 0b1;
//   *spi_ctrl = 0b000100000000 | 0x40;
  
//   while ((*spi_ctrl & (1 << 8)));
//   volatile uint32_t value = *spi_tx_0;
//   *spi_ss = 0b00000000;
//   // 因为特殊的设置，要对数据做一点特殊的处理

//   return ((value & 0xFF) << 24) |        // 取最低字节放到最高位
//          ((value & 0xFF00) << 8) |       // 取次低字节左移16位
//          ((value & 0xFF0000) >> 8) |     // 取次高字节右移8位
//          ((value & 0xFF000000) >> 24);   // 取最高字节放到最低位
// }

void serial_init() {
  *(volatile unsigned char *)(UART_BASE + UART_LCR) = 0b10000011;
  *(volatile unsigned char *)(UART_BASE + UART_TX) = 0x01;
  *(volatile unsigned char *)(UART_BASE + UART_LCR) = 0b00000011 ;
}

void putch(char ch) {
    while (!(*(volatile unsigned char *)(UART_BASE + UART_LSR) & 0b00100000));
    *(volatile unsigned char *)(UART_BASE + UART_TX) = ch;
}

void halt(int code) {
  while (1)
    ;
}

void display_ysyx(){
  uint32_t ysyx_ascll;
  uint32_t ysyx_num;
  asm volatile("csrr a0, 0xf11" : "=r"(ysyx_ascll));
  asm volatile("csrr a0, 0xf12" : "=r"(ysyx_num));
  if(ysyx_ascll != 0x79737978){
    putch('E');
  }
  for(int i = 0; i < 8; i++){
    putch((ysyx_ascll >> (i * 8)) & 0xFF);
  }

  while(ysyx_num > 0){
    putch((ysyx_num % 10) + '0');
    ysyx_num /= 10;
  }
  putch('\n');
}

void _trm_init() {
  loader_init();
  serial_init();
  display_ysyx();
  int ret = main(mainargs);
  halt(ret);
}