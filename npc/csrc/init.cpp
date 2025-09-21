#include "VysyxSoCFull.h"
#include "map.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <string.h>

#include "common.h"

#define RESET_TIME 15

void init_disasm(const char *triple);

uint32_t img[] = {0x00000413, 0x00009117, 0xffc10113, 0x00c000ef, 0x00000513,
                  0x00008067, 0xff410113, 0x00000517, 0x01450513, 0x00112423,
                  0xfe9ff0ef, 0x00050513, 0x00100073};

long init_default() {
  memcpy(guest_to_host(MBASE), img, sizeof(img));
  printf("\033[0m\033[1;32mfinish load memory\033[0m\n");
  return sizeof(img);
}

long init_build(char *filepath) {
  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("failed to read the file\n");
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(FBASE), size, 1, fp);

  fclose(fp);
  return size;
}

extern Npc *npc;
extern Cpu *cpu;
#ifdef TRACE
bool fork_interval_on = false;
unsigned int fork_interval = 0;
bool record_enable = false;

unsigned int record_after = 0;
extern Trace *trace;
#endif

char *filepath = NULL;
char diff_ref[] = "/home/ysyx/project/ysyx-workbench/nemu/build/"
                  "riscv32-nemu-interpreter-so";
int port = 0;
bool batch_mode_on = false;

void parse_args(int argc, char *argv[]) {
  const struct option table[] = {
      {"diff", required_argument, NULL, 'd'},
      {"port", required_argument, NULL, 'p'},
      {"file", required_argument, NULL, 'f'},
      {"batch", no_argument, NULL, 'b'},
      {"fork-interval", required_argument, NULL, 'i'},
      {"record-after", required_argument, NULL, 'r'},
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-d:p:f:bi:r:", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      batch_mode_on = true;
      break;
    case 'f':
      filepath = optarg;
      break;
    case 'd':
      break;
    case 'i':
      #ifdef TRACE
      fork_interval = std::strtol(optarg, NULL, 10);
      fork_interval_on = true;
      #else 
      printf("fork-interval is only supported in trace mode\n");
      #endif
      break;
    case 'r':
      #ifdef TRACE
      record_after = std::stoul(optarg);
      #else
      printf("record-after is only supported in trace mode\n");
      #endif
      break;
    case 'p':
      break;
    }
  }
}

void init_trace() {
#ifdef TRACE
  Verilated::traceEverOn(true);
  trace = new Trace;
  trace->tfp = new VerilatedVcdC;
  trace->context = new VerilatedContext;
  trace->context->traceEverOn(true);
  npc->top->trace(trace->tfp, 0);
  trace->tfp->open("/home/ysyx/project/ysyx-workbench/npc/wave.vcd");
#endif
  return;
}

void init(int argc, char *argv[]) {
  long img_size = 0;
  parse_args(argc, argv);

  if (filepath == NULL) {
    img_size = init_default();
  } else {
    img_size = init_build(filepath);
  }
#ifdef ITRACE
  init_disasm("riscv32-pc-linux-gnu");
#endif
  init_regex();
  init_wp_pool();
  device_init();

  npc = new Npc;
  cpu = new Cpu;
  cpu->con.pc = MBASE - 8;
  npc->top = new VysyxSoCFull;
  npc->cycs = 0;

  npc->state = STOP;
  npc->top->reset = 1;
  init_trace();
  for (int i=0;i<RESET_TIME-1;i++){
    npc->top->clock = 1;
    npc->top->eval();
    demp_wave();
    npc->top->clock = 0;
    npc->top->eval();
    demp_wave();
    npc->cycs += 2;
  }
  npc->top->reset = 0;
  npc->top->clock = 1;
  npc->top->eval();
  demp_wave();
  npc->top->clock = 0;
  npc->top->eval();
  demp_wave();
  npc->cycs += 2;
#ifdef DIFFTEST
  init_difftest(diff_ref, img_size, port);
#endif
}

bool batch_mode() { return batch_mode_on; }
#ifdef TRACE
bool fork_interval_is_on() { return fork_interval_on; }
int fork_interval_val() { return fork_interval; }
bool record_isenable() { return record_enable; }
void set_record_enable() { record_enable = true; }
unsigned int record_after_val() { return record_after; }
#endif
