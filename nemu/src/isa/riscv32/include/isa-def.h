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

#include "csr-xmacro.h"

typedef uint32_t (*virt_csr_read_t)(void);
typedef void (*virt_csr_write_t)(uint32_t data);

typedef struct {
  uint16_t csr_num;
  virt_csr_read_t read;
  virt_csr_write_t write;
} virt_csr_entry_t;

// 定义结构体
typedef struct {
#define DEFINE_CSR_MEMBER(name, idx) uint32_t name;
  EACH_RAW_CSR(DEFINE_CSR_MEMBER)
#undef DEFINE_CSR_MEMBER
} riscv32_CPU_csr;

typedef struct {
#define DEFINE_VIRTUAL_CSR_MEMBER(name, idx) virt_csr_entry_t name;
  EACH_VIRTUAL_CSR(DEFINE_VIRTUAL_CSR_MEMBER)
#undef DEFINE_VIRTUAL_CSR_MEMBER
} riscv32_CPU_virt_csr;

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  riscv32_CPU_csr csr;
  riscv32_CPU_virt_csr virt_csr;
  bool INTR;
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

typedef enum { S_MODE, M_MODE, U_MODE } CPU_MODE;

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

// #define isa_mmu_check(vaddr, len, type) (MMU_DIRECT)
#include "csr/mie.h"
#include "csr/mstatus.h"

#endif
