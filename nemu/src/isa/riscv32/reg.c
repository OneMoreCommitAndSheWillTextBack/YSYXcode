/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "local-include/reg.h"
#include <isa.h>

const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display(CPU_state *ref) {
  const char *C_RESET = "\033[0m";
  const char *C_HDR   = "\033[36m";  // cyan
  const char *C_NAME  = "\033[33m";  // yellow
  const char *C_VAL   = "\033[32m";  // green
  const char *C_DIFF  = "\033[31m";  // red

  if (ref == NULL) {
    // 只打印本机寄存器
    printf("%s  %-5s %-12s %-12s%s\n", C_HDR, "reg", "hex", "dec", C_RESET);
    printf("  %s%-5s %-12s %-12s%s\n", C_HDR, "-----", "------------", "------------", C_RESET);
    for (int i = 0; i < 32; i++) {
      uint32_t val = cpu.gpr[i];
      printf("  %s%-5s%s %s0x%08x%s %s%-12d%s\n",
             C_NAME, regs[i], C_RESET,
             C_VAL,  val,      C_RESET,
             C_VAL,  (int32_t)val, C_RESET);
    }
    printf("  %s%-5s%s %s0x%08x%s\n",
           C_NAME, "pc", C_RESET,
           C_VAL,  cpu.pc, C_RESET);
  } else {
    // 对比 DUT 和 REF 寄存器
    printf("%s  %-5s %-12s %-12s %-8s%s\n",
           C_HDR, "reg", "DUT", "REF", "diff", C_RESET);
    printf("  %s%-5s %-12s %-12s %-8s%s\n",
           C_HDR, "-----", "------------", "------------", "--------", C_RESET);
    for (int i = 0; i < 32; i++) {
      uint32_t d = cpu.gpr[i];
      uint32_t r = ref->gpr[i];
      const char *c = (d == r) ? C_VAL : C_DIFF;
      printf("  %s%-5s%s %s0x%08x%s %s0x%08x%s %s%-8d%s\n",
             C_NAME, regs[i], C_RESET,
             c,      d,       C_RESET,
             c,      r,       C_RESET,
             c,      (int32_t)d - (int32_t)r, C_RESET);
    }
    const char *cpc = (cpu.pc == ref->pc) ? C_VAL : C_DIFF;
    printf("  %s%-5s%s %s0x%08x%s %s0x%08x%s\n",
           C_NAME, "pc", C_RESET,
           cpc,     cpu.pc, C_RESET,
           cpc,     ref->pc, C_RESET);
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if (strcmp("pc", s + 1) == 0) {
    return cpu.pc;
  }
  for (int i = 0; i < 32; i++) {
    if (strcmp(regs[i], s + 1) == 0) {
      return cpu.gpr[i];
    }
  }
  *success = false;
  return 0;
}
