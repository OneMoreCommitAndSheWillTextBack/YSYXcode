#include "Vtop.h"
#include <stdint.h>
#include <stdio.h>

#ifndef COMMON_H
#define COMMON_H
#define MBASE 0x80000000

enum npcstate { STOP, RUNNING, END, ABORT, QUIT };

typedef struct {
  Vtop *top;
  enum npcstate state;
} Npc;

#endif

// memory.cpp
uint8_t *guest_to_host(uint32_t addr);

// init.cpp
void init(char *filepath);

// cpu.cpp
void cpu_exec(int n);
void set_npc_end();
void set_npc_quit();

// sdb.cpp
void sdb_main();
