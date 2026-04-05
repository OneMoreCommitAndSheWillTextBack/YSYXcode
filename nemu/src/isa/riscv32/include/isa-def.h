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

#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>
#include <stdint.h>

typedef struct {
  uint32_t mepc;
  uint32_t mstatus;
  uint32_t mcause;
  uint32_t mtvec;
  uint32_t satp;
} riscv32_CPU_csr;

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  riscv32_CPU_csr csr;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

// #define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)
#define MMP_USER 0x0
#define MMP_SUPR 0x1
#define MMP_MACH 0x3

#define MSTATUS_MPP_SHIFT 11

#define MSTATUS_MPP_MASK 0x2

#define MSTATUS_SET(mstatus, mode)                                             \
  (mstatus & ~(MSTATUS_MPP_MASK << MSTATUS_MPP_SHIFT)) |                       \
      ((mode & MSTATUS_MPP_MASK) << MSTATUS_MPP_SHIFT)

#define MSTATUS_GET(mstatus) (mstatus >> MSTATUS_MPP_SHIFT) & MSTATUS_MPP_MASK

#endif
