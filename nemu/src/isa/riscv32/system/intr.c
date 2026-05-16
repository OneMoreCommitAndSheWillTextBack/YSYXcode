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

#include "../local-include/csr-table.h"
#include "common.h"
#include "debug.h"
#include "isa-def.h"
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

inline static bool is_deleg(word_t NO) {
  bool is_intr = (NO & (1u << 31)) != 0;
  uint32_t cause = NO & ~(1u << 31);

  if (is_intr) {
    return (cpu.csr.mideleg >> cause) & 1;
  } else {
    return (cpu.csr.medeleg >> cause) & 1;
  }
}

inline static word_t get_trap_pc(word_t NO, word_t tvec) {
  uint32_t mode = tvec & 0x3u;
  uint32_t base = tvec & ~0x3u;

  uint32_t intr_bit = 1u << 31;
  bool is_intr = (NO & intr_bit) != 0;
  uint32_t cause = NO & ~intr_bit;

  if (mode == 0) {
    return base;
  } else if (mode == 1) {
    if (is_intr) {
      return base + 4 * cause;
    } else {
      return base;
    }
  } else {
    panic("invalid stvec mode");
  }
}

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  uint32_t trap_pc = 0;

  if (current_cpu_priv != M_MODE && is_deleg(NO)) {
    CPU_MODE previous_priv = current_cpu_priv;
    current_cpu_priv = S_MODE;
    uint32_t old = cpu.csr.mstatus;
    cpu.csr.mstatus = (old & ~(SSTATUS_SIE | SSTATUS_SPIE | SSTATUS_SPP)) |
                      ((old & SSTATUS_SIE) << 4) |
                      (previous_priv == S_MODE ? SSTATUS_SPP : 0);
    cpu.csr.sepc = epc;
    cpu.csr.scause = NO;
    trap_pc = get_trap_pc(NO, cpu.csr.stvec);
  } else {
    uint32_t mstatus = cpu.csr.mstatus;
    cpu.csr.mstatus =
        (mstatus & ~(MSTATUS_MPP_MASK | MSTATUS_MPIE | MSTATUS_MIE)) |
        encode_mpp(current_cpu_priv) | ((mstatus & MSTATUS_MIE) << 4);
    current_cpu_priv = M_MODE;
    cpu.csr.mepc = epc;
    cpu.csr.mcause = NO;
    trap_pc = get_trap_pc(NO, cpu.csr.mtvec);
  }

  return trap_pc;
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
#define IRQ_S_SOFTWARE 0x80000001
#define IRQ_S_TIMER 0x80000005
#define IRQ_S_EXTERNAL 0x80000009
#ifdef CONFIG_HAS_PLIC
#define IRQ_M_EXTERNAL 0x8000000b
#endif

word_t isa_query_intr() {
  bool global_intr_enable = false;

  if (current_cpu_priv == M_MODE) {
    global_intr_enable = (cpu.csr.mstatus & MSTATUS_MIE) != 0;
    if (!global_intr_enable)
      return INTR_EMPTY;

    virt_csr_entry_t *mip = get_virt_csr(0x344);
    uint32_t mip_val = mip->read();
#ifdef CONFIG_HAS_PLIC
    if ((mip_val & MIP_MEIP) && (cpu.csr.mie & MIE_MEIE)) {
      return IRQ_M_EXTERNAL;
    }
#endif
    bool m_timer_intr_enable = cpu.csr.mie & MIE_MTIE;
    if (cpu.INTR && m_timer_intr_enable) {
      cpu.INTR = false;
      return IRQ_TIMER;
    }

    if (mip_val & MIP_MTIP && m_timer_intr_enable) {
      mip->write(0);
      return IRQ_TIMER;
    }

    bool s_external_delegated = is_deleg(IRQ_S_EXTERNAL);
    bool s_external_intr_enable = cpu.csr.mie & MIE_SEIE;
    if (!s_external_delegated && s_external_intr_enable &&
        (mip_val & MIP_SEIP)) {
      return IRQ_S_EXTERNAL;
    }

    bool s_timer_delegated = is_deleg(IRQ_S_TIMER);
    bool s_timer_intr_enable = cpu.csr.mie & MIE_STIE;
    if (!s_timer_delegated && s_timer_intr_enable && (mip_val & MIP_STIP)) {
      return IRQ_S_TIMER;
    }
  } else if (current_cpu_priv == S_MODE) {
    virt_csr_entry_t *mip = get_virt_csr(0x344);
    uint32_t mip_val = mip->read();
#ifdef CONFIG_HAS_PLIC
    if ((mip_val & MIP_MEIP) && (cpu.csr.mie & MIE_MEIE)) {
      return IRQ_M_EXTERNAL;
    }
#endif
    bool m_timer_intr_enable = cpu.csr.mie & MIE_MTIE;
    if (cpu.INTR && m_timer_intr_enable) {
      cpu.INTR = false;
      return IRQ_TIMER;
    }

    bool s_external_delegated = is_deleg(IRQ_S_EXTERNAL);
    bool s_external_intr_enable = cpu.csr.mie & MIE_SEIE;
    if (s_external_intr_enable && (mip_val & MIP_SEIP)) {
      if (s_external_delegated) {
        global_intr_enable = (cpu.csr.mstatus & MSTATUS_SIE) != 0;
        if (!global_intr_enable)
          return INTR_EMPTY;
      }
      return IRQ_S_EXTERNAL;
    }

    bool s_software_delegated = is_deleg(IRQ_S_SOFTWARE);
    bool s_software_intr_enable = cpu.csr.mie & MIE_SSIE;
    if (s_software_intr_enable && (mip_val & MIP_SSIP)) {
      if (s_software_delegated) {
        global_intr_enable = (cpu.csr.mstatus & MSTATUS_SIE) != 0;
        if (!global_intr_enable)
          return INTR_EMPTY;
      }
      return IRQ_S_SOFTWARE;
    }

    bool s_timer_delegated = is_deleg(IRQ_S_TIMER);
    bool s_timer_intr_enable = cpu.csr.mie & MIE_STIE;
    if (s_timer_intr_enable && (mip_val & MIP_STIP)) {
      if (s_timer_delegated) {
        global_intr_enable = (cpu.csr.mstatus & MSTATUS_SIE) != 0;
        if (!global_intr_enable)
          return INTR_EMPTY;
      }
      return IRQ_S_TIMER;
    }
  } else {
    virt_csr_entry_t *mip = get_virt_csr(0x344);
    uint32_t mip_val = mip->read();
#ifdef CONFIG_HAS_PLIC
    if ((mip_val & MIP_MEIP) && (cpu.csr.mie & MIE_MEIE)) {
      return IRQ_M_EXTERNAL;
    }
#endif
    bool m_timer_intr_enable = cpu.csr.mie & MIE_MTIE;
    if (cpu.INTR && m_timer_intr_enable) {
      cpu.INTR = false;
      return IRQ_TIMER;
    }

    bool s_external_intr_enable = cpu.csr.mie & MIE_SEIE;
    if (s_external_intr_enable && (mip_val & MIP_SEIP)) {
      return IRQ_S_EXTERNAL;
    }

    bool s_software_intr_enable = cpu.csr.mie & MIE_SSIE;
    if (s_software_intr_enable && (mip_val & MIP_SSIP)) {
      return IRQ_S_SOFTWARE;
    }

    bool s_timer_intr_enable = cpu.csr.mie & MIE_STIE;
    if (s_timer_intr_enable && (mip_val & MIP_STIP)) {
      return IRQ_S_TIMER;
    }
  }

  return INTR_EMPTY;
}
