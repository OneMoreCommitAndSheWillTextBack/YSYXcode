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
// clang-format off

#include <cpu/cpu.h>
#include <difftest-def.h>
#include <isa.h>
#include <memory/paddr.h>
#include <stdint.h>

typedef struct {
  uint32_t mstatus;
  uint32_t mtvec;
  uint32_t mepc;
  uint32_t mcause;
} Csr;

typedef struct diff_context {
  uint32_t gpr[32];
  uint32_t pc;
  Csr csr;
}diff_context;

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    for (int i = 0; i < n; i++){
      paddr_write(addr + i, 2, *((uint8_t *)buf + i));
      printf("difftest_memcpy: 0x%x <- %x\n", addr + i, paddr_read(addr + i, 4));
    }
  } else {
    assert(0);
  }
}

// get DIFFTEST_TO_REF means init the nemu, input the state of 
// npc and set the npc state to nemu
// get DIFFTEST_TO_DUT means the npc instance a diffcontext and
// trans it to nemu, nemu cpy its state to the diffcontext, then
// npc used the diffcontext to check its state
__EXPORT void difftest_regcpy(void *dut, bool direction) { 
  if(direction == DIFFTEST_TO_REF){
    // get the dur state to nemu to init
    diff_context *diff_ptr = (diff_context*)dut;
    for(int i=0;i<32;i++){
      cpu.gpr[i] = diff_ptr->gpr[i];
    }
    cpu.csr.mcause = diff_ptr->csr.mcause;
    cpu.csr.mepc = diff_ptr->csr.mepc;
    cpu.csr.mstatus = diff_ptr->csr.mstatus;
    cpu.csr.mtvec = diff_ptr->csr.mtvec;
    cpu.pc = diff_ptr->pc;
  } else {
    diff_context *diff_ptr = (diff_context*)dut;
    for(int i=0;i<32;i++){
      diff_ptr->gpr[i] = cpu.gpr[i];
    }
    diff_ptr->csr.mepc = cpu.csr.mepc;
    diff_ptr->csr.mtvec = cpu.csr.mtvec;
    diff_ptr->csr.mstatus = cpu.csr.mstatus;
    diff_ptr->csr.mcause = cpu.csr.mcause;
    diff_ptr->pc = cpu.pc;
  }
}

__EXPORT void difftest_exec(uint64_t n) { cpu_exec(n); }

__EXPORT void difftest_raise_intr(word_t NO) { assert(0); }

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}

// clang-format on
