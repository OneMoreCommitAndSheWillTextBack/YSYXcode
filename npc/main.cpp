#include "Vtop.h"
#include "verilated.h"
#include <cstdint>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t img[] = {0x00a90533, 0x00440413, 0x004a8a93, 0x03010113, 0x00100073};
uint8_t pmem[256] = {};
const unsigned int mbase = 0x80000000;

void init() {
  memcpy(pmem, img, sizeof(img));
  printf("\033[0m\033[1;32mfinish load memory\033[0m\n");
}

extern "C" void ret() { exit(0); }

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
