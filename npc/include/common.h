#include "VysyxSoCFull.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <stdint.h>
#include <stdio.h>

#ifndef COMMON_H
#define COMMON_H
// config
#include "selfconfig.h"

#define MBASE 0x20000000

enum npcstate { STOP, RUNNING, END, ABORT, QUIT };

typedef struct {
  VysyxSoCFull *top;
  enum npcstate state;
} Npc;

typedef struct {
  uint32_t mstatus;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mcause;
} Csr;

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
  Csr csr;
} context;

typedef struct {
  uint32_t inst;
  context con;
  char logbuf[128];
  int valid;
} Cpu;

#ifdef TRACE
typedef struct {
  VerilatedContext *context;
  VerilatedVcdC *tfp;
} Trace;
#endif

#endif

// memory.cpp
bool in_pmem(uint32_t addr);
uint8_t *guest_to_host(uint32_t addr);
uint32_t pmem_read(uint8_t *addr, uint32_t len);
uint32_t paddr_read(uint32_t address, uint32_t len);
void paddr_write(uint32_t address, uint32_t len, uint32_t data);

// init.cpp
void init(int argc, char *argv[]);
bool batch_mode();

// cpu.cpp
void cpu_exec(int n);
void set_npc_end();
void set_npc_quit();
void set_npc_stop();
#ifdef DIFFTEST
void npc_diff_quit();
#endif
void demp_wave();
void tfpclose();

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

// disasm.cpp
extern "C" void init_disasm(const char *triple);
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code,
                            int nbyte);

// difftest.cpp
#ifdef DIFFTEST
void init_difftest(char *ref_so_file, long img_size, int port);
void diff_step();
void set_ref_skip();
#endif
