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
  uint32_t mscratch;
  uint32_t satp;

  uint32_t medeleg;

  uint32_t mhartid;
} riscv32_CPU_csr;

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  riscv32_CPU_csr csr;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

typedef enum { S_MODE, M_MODE, U_MODE } CPU_MODE;

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

// #define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)

// mstatus 寄存器位定义 (RV32)
#define MSTATUS_UIE (1 << 0)         // User Interrupt Enable
#define MSTATUS_SIE (1 << 1)         // Supervisor Interrupt Enable
#define MSTATUS_MIE (1 << 3)         // Machine Interrupt Enable
#define MSTATUS_UPIE (1 << 4)        // User Previous Interrupt Enable
#define MSTATUS_SPIE (1 << 5)        // Supervisor Previous Interrupt Enable
#define MSTATUS_MPIE (1 << 7)        // Machine Previous Interrupt Enable
#define MSTATUS_SPP (1 << 8)         // Supervisor Previous Privilege
#define MSTATUS_MPP_HIGH (1 << 11)   // Machine Previous Privilege high bit
#define MSTATUS_MPP_LOW (1 << 12)    // Machine Previous Privilege low bit
#define MSTATUS_MPP_MASK (3 << 11)   // MPP field mask
#define MSTATUS_MPP_U (0 << 11)      // MPP = User mode
#define MSTATUS_MPP_S (1 << 11)      // MPP = Supervisor mode
#define MSTATUS_MPP_M (3 << 11)      // MPP = Machine mode
#define MSTATUS_FS (3 << 13)         // Floating-point Status
#define MSTATUS_FS_OFF (0 << 13)     // FPU off
#define MSTATUS_FS_INITIAL (1 << 13) // FPU initial
#define MSTATUS_FS_CLEAN (2 << 13)   // FPU clean
#define MSTATUS_FS_DIRTY (3 << 13)   // FPU dirty
#define MSTATUS_XS (3 << 15)         // User Extension Status
#define MSTATUS_MPRV (1 << 17)       // Modify Privilege
#define MSTATUS_SUM (1 << 18)        // Supervisor User Memory Access
#define MSTATUS_MXR (1 << 19)        // Make eXecutable Readable
#define MSTATUS_TVM (1 << 20)        // Trap Virtual Memory
#define MSTATUS_TW (1 << 21)         // Timeout Wait
#define MSTATUS_TSR (1 << 22)        // Trap SRET
#define MSTATUS_UXL (3 << 32)        // User XLEN (RV32 中保留)
#define MSTATUS_SXL (3 << 34)        // Supervisor XLEN (RV32 中保留)
#endif
