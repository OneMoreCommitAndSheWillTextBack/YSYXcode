#include "Vtop.h"
#include "verilated.h"
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t img[] = {
    0x00000413, 0x00009117, 0xffc10113, 0x00c000ef, 0x00000513, 0x00008067,
    0xff410113, 0x00000517, 0x01450513, 0x00112423, 0xfe9ff0ef, 0x0000006f,
};
const unsigned int mbase = 0x80000000;
const unsigned int msize = 0x8000000;
const char *filepath = NULL;
uint8_t pmem[msize] = {};

void init_default() {
  memcpy(pmem, img, sizeof(img));
  printf("\033[0m\033[1;32mfinish load memory\033[0m\n");
}

void init_build() {
  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("failed to read the file\n");
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(pmem, size, 1, fp);

  fclose(fp);
}

void init() {
  if (filepath == NULL) {
    init_default();
  } else {
    init_build();
  }
}

extern "C" void ret() { exit(0); }
extern "C" int pmem_read(int addr) {
  uint32_t *data = (uint32_t *)(pmem + (uint32_t)addr - mbase);
  return *data;
}
extern "C" void pmem_write(int addr, int data) {
  printf("the write addr is %08x\n", addr);
  uint32_t *pos = (uint32_t *)(pmem + (uint32_t)addr - mbase);
  *pos = (uint32_t)data;
  return;
}

int main() {
  init();
  Vtop *top = new Vtop;
  unsigned int pc = 0;
  int i = 0;
  top->clk = 1;
  top->rst = 1;
  top->eval();
  top->rst = 0;
  while (1) {
    top->clk = 0;
    top->eval();
    top->clk = 1;
    pc = top->pc;
    printf("0x%08x\n", pc);
    uint32_t *inst = (uint32_t *)(pmem + pc - mbase);
    top->inst = *inst;
    top->eval();
    i++;
  }

  return 0;
}
