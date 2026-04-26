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

#include <isa.h>
#include <stdint.h>

extern CPU_MODE current_cpu_priv;

static inline uint32_t encode_mpp(CPU_MODE priv) {
  switch (priv) {
  case M_MODE:
    return MSTATUS_MPP_M;
  case S_MODE:
    return MSTATUS_MPP_S;
  case U_MODE:
    return MSTATUS_MPP_U;
  default:
    assert(0 && "invalid current_cpu_priv");
    return MSTATUS_MPP_U;
  }
}

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  uint32_t mstatus = cpu.csr.mstatus;
  cpu.csr.mstatus =
      (mstatus & ~(MSTATUS_MPP_MASK | MSTATUS_MPIE | MSTATUS_MIE)) |
      encode_mpp(current_cpu_priv) | ((mstatus & MSTATUS_MIE) << 4);
  // TODO: if the cause is delegated to S-mode, then switch to the S-mode
  current_cpu_priv = M_MODE;
  cpu.csr.mepc = epc;
  cpu.csr.mcause = NO;
  // printf("[DEBUG] mcause set to %d | %08x\n", cpu.csr.mcause,
  // cpu.csr.mcause);

  return cpu.csr.mtvec;
}

bool isa_enable_intr() {
  switch (current_cpu_priv) {
  case M_MODE:
    return (cpu.csr.mstatus & MSTATUS_MIE) != 0;
  case S_MODE:
    return (cpu.csr.mstatus & MSTATUS_SIE) != 0;
  case U_MODE:
    return true;
  default:
    assert(0 && "invalid current_cpu_priv");
    return false;
  }
}

#define IRQ_TIMER 0x80000007
word_t isa_query_intr() {
  bool global_intr_enable = isa_enable_intr();
  if (!global_intr_enable)
    return INTR_EMPTY;

  bool m_timer_intr_enable = cpu.csr.mie & MIE_MTIE;
  if (cpu.INTR == true && m_timer_intr_enable) {
    cpu.INTR = false;
    return IRQ_TIMER;
  }

  return INTR_EMPTY;
}
