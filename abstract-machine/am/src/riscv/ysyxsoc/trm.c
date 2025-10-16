#include <klib-macros.h>
#include "am.h"
#include <riscv/riscv.h>

#define UART_BASE 0x10000000
#define UART_TX   0
#define UART_LCR 3
#define UART_LSR 5
#define UART_DLL 0
#define UART_DLM 1
#define UART_FCR 2

extern char _heap_start;
extern char _heap_end;
int main(const char *args);

extern char _pmem_start;
// #define PMEM_SIZE (8 * 1024 * 1024)
// #define PMEM_END ((uintptr_t) & _pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, &_heap_end);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void serial_init() {
  *(volatile unsigned char *)(UART_BASE + UART_LCR) = 0b10000011;
  *(volatile unsigned char *)(UART_BASE + UART_TX) = 0xff;
  *(volatile unsigned char *)(UART_BASE + UART_LCR) = 0b00000011 ;
}

void putch(char ch) {
    while ((*(volatile unsigned char *)(UART_BASE + UART_LSR) & 0x60) == 0);
    *(volatile unsigned char *)(UART_BASE + UART_TX) = ch;
}

void halt(int code) {
  while (1)
    ;
}

void display_ysyx(){
  uint32_t ysyx_ascll;
  uint32_t ysyx_num;
  asm volatile("csrr %0, 0xf11" : "=r"(ysyx_ascll));
  asm volatile("csrr %0, 0xf12" : "=r"(ysyx_num));
  for(int i = 0; i < 8; i++){
    putch((ysyx_ascll >> ((4-i) * 8)) & 0xFF);
  }

  char buffer[10];
  int i = 0;
  while(ysyx_num > 0){
    buffer[i] = (ysyx_num % 10) + '0';
    ysyx_num /= 10;
    i++;
  }
  for(int j = i - 1; j >= 0; j--){
    putch(buffer[j]);
  }
  putch('\n');
}

__attribute__((used))
void ioe_read(int reg, void *buf){}
__attribute__((used))
bool ioe_init(){return true;};
__attribute__((used))
void ioe_write(int reg, void *buf){}

__attribute__((section(".stage1")))
void _trm_init() {
  loader_init();
  serial_init();
  // display_ysyx();
  int ret = main(mainargs);
  halt(ret);
}