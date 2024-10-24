#include "Vtop.h"
#include "verilated.h"
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t img[] = {0x00a90533, 0x00440413, 0x004a8a93, 0x03010113, 0x00100073};
const unsigned int mbase = 0x80000000;
const unsigned int msize = 0x8000000;
const char *filepath = "~/project/ysyx-workbench/am-kernels/tests/cpu-tests/"
                       "build/dummy-riscv32e-npc.elf";
uint8_t pmem[msize] = {};

void init_default() {
  memcpy(pmem, img, sizeof(img));
  printf("\033[0m\033[1;32mfinish load memory\033[0m\n");
}

void init_build() {
  FILE *fp = fopen(filepath, "r");
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
  }
}

extern "C" void ret() { exit(0); }
extern "C" int pmem_read(int addr) {
  uint32_t *data = (uint32_t *)(pmem + (uint32_t)addr - mbase);
  return *data;
}
extern "C" void pmem_write(int addr, int data) {
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
  while (i < 5) {
    top->clk = 0;
    top->eval();
    top->clk = 1;
    pc = top->pc;
    uint32_t *inst = (uint32_t *)(pmem + pc - mbase);
    top->inst = *inst;
    top->eval();
    i++;
  }

  return 0;
}
