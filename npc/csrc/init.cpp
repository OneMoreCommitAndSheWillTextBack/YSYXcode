#include "Vtop.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string.h>

#include "common.h"

uint32_t img[] = {0x00000413, 0x00009117, 0xffc10113, 0x00c000ef, 0x00000513,
                  0x00008067, 0xff410113, 0x00000517, 0x01450513, 0x00112423,
                  0xfe9ff0ef, 0x00050513, 0x00100073};

void init_default() {
  memcpy(guest_to_host(MBASE), img, sizeof(img));
  printf("\033[0m\033[1;32mfinish load memory\033[0m\n");
}

void init_build(char *filepath) {
  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("failed to read the file\n");
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(MBASE), size, 1, fp);

  fclose(fp);
}

extern Npc *npc;

void init(char *filepath) {
  if (filepath == NULL) {
    init_default();
  } else {
    init_build(filepath);
  }

  npc = new Npc;
  npc->top = new Vtop;
  npc->state = STOP;
  npc->top->rst = 1;
  npc->top->eval();
  npc->top->rst = 0;
  npc->top->eval();
}
