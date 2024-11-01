#include "Vtop.h"
#include <cstdint>
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

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
} Cpu;

#endif

// memory.cpp
uint8_t *guest_to_host(uint32_t addr);
uint32_t pmem_read(uint32_t address, uint32_t len);
void pmem_write(uint32_t address, uint32_t len, uint32_t data);

// init.cpp
void init(char *filepath);

// cpu.cpp
void cpu_exec(int n);
void set_npc_end();
void set_npc_quit();
void set_npc_stop();

// sdb.cpp
void sdb_main();

// reg.cpp
void display_reg();
uint32_t npc_reg_str2val(char *regname, bool *success);

// expr.cpp
uint32_t expr(char *e, bool *success);
void init_regex();

// watchpoint.cpp
void init_wp_pool();
void exe_wp();
void new_wp(char *exp);
void free_wp(int wp_num);
void info_wp();
