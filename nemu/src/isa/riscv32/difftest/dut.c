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

#include "../local-include/reg.h"
#include <cpu/difftest.h>
#include <isa.h>
#include <stdio.h>

#define riscv_check_csr(csrname)                                               \
  do {                                                                         \
    if (ref_r->csr.csrname != cpu.csr.csrname) {                               \
      printf("the difftest encounter a error at pc:%x\n", pc);                 \
      printf("nemu[" #csrname "] %08x spike[" #csrname "] %08x \n",            \
             cpu.csr.csrname, ref_r->csr.csrname);                             \
      return false;                                                            \
    }                                                                          \
  } while (0);

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for (int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("the difftest encounter a error at pc:%x\n", pc);
      printf("nemu[%2d] %08x spike[%2d] %08x \n", i, cpu.gpr[i], i,
             ref_r->gpr[i]);
      return false;
    }

    riscv_check_csr(mcause);
    riscv_check_csr(mepc);
    riscv_check_csr(mstatus);
    riscv_check_csr(mtvec);
    riscv_check_csr(satp);
  }
  return true;
}

void isa_difftest_attach() { difftest_attach(); }

void isa_difftest_detach() { difftest_detach(); }

bool isa_difftest_is_attach() { return difftest_is_attach(); }
