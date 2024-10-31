#include "common.h"
#include <iomanip>
#include <iostream>

const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

#define REGNUM 32

extern Npc *npc;
void display_reg() {
  for (int i = 0; i < REGNUM; i++) {
    std::cout << std::setfill(' ') << std::setw(3) << regs[i];
    std::cout << " 0x" << std::hex << std::setfill('0') << std::setw(8)
              << npc->top->reg_out[i];

    std::cout << " " << std::dec << npc->top->reg_out[i];
    std::cout << std::endl;
  }
}
