#include "Vtop.h"
#include "map.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <string.h>

#include "common.h"

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
  int ret = fread(guest_to_host(MBASE), size, 1, fp);

  fclose(fp);
  return size;
}

extern Npc *npc;
extern Cpu *cpu;
#ifdef TRACE
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
      {0, 0, NULL, 0},
  };
  int o;
  while ((o = getopt_long(argc, argv, "-d:p:f:b", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      batch_mode_on = true;
      break;
    case 'f':
      filepath = optarg;
      break;
    case 'd':
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
  cpu->con.pc = MBASE;
  npc->top = new Vtop;

  init_trace();
  npc->state = STOP;
  npc->top->rst = 1;
  npc->top->eval();
  demp_wave();
  npc->top->rst = 0;
  npc->top->eval();
  demp_wave();
#ifdef DIFFTEST
  init_difftest(diff_ref, img_size, port);
#endif
}

bool batch_mode() { return batch_mode_on; }
