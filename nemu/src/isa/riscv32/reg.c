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
  // 表头
  if (ref == NULL) {
    printf("  %-4s %-10s %-12s\n", "reg", "hex", "dec");
    printf("  ---------------------------------\n");
    for (int i = 0; i < 32; i++) {
      uint32_t val = cpu.gpr[i];
      printf("  %-4s 0x%08x %-12d\n", regs[i], val, (int32_t)val);
    }
    printf("  %-4s 0x%08x\n", "pc", cpu.pc);
  } else {
    printf("  %-4s %-10s %-10s %-12s\n", "reg", "DUT", "REF", "diff");
    printf("  ---------------------------------------------\n");
    for (int i = 0; i < 32; i++) {
      uint32_t d = cpu.gpr[i];
      uint32_t r = ref->gpr[i];
      printf("  %-4s 0x%08x 0x%08x %-12d\n", regs[i], d, r, (int32_t)d - (int32_t)r);
    }
    printf("  %-4s 0x%08x 0x%08x\n", "pc", cpu.pc, ref->pc);
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
