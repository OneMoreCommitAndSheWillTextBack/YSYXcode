/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "common.h"
#include <isa.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>

int isa_mmu_check(vaddr_t vaddr, int len, int type) {
  if (cpu.csr.stap & (0x1 << 31)) {
    return MMU_TRANSLATE;
  } else {
    return MMU_DIRECT;
  }
}

#define VPN0_SHIFT 11
#define VPN1_SHIFT 21

#define VPN1_MASK (0x3FF << VPN1_SHIFT)
#define VPN0_MASK (0x3FF << VPN0_SHIFT)
#define OFFSET_MASK 0x7FF

#define PPN_MASK (0x3FFFFF << 10)
#define PTE_PPN(pte) (pte & PPN_MASK)

#define PTE_V 0x01
#define PTE_R 0x02
#define PTE_W 0x04
#define PTE_X 0x08
#define PTE_U 0x10
#define PTE_A 0x40
#define PTE_D 0x80

static void isa_mmu_update_pte(paddr_t pte_addr, uint32_t pte, int type) {
  uint32_t new_pte = pte;
  bool need_update = false;

  // 设置访问位（A位）
  if (!(pte & PTE_A)) {
    new_pte |= PTE_A;
    need_update = true;
  }

  // 如果是写操作，设置脏位（D位）
  if (type == MEM_TYPE_WRITE && !(pte & PTE_D)) {
    new_pte |= PTE_D;
    need_update = true;
  }

  // 如果有更新，写回页表项
  if (need_update) {
    paddr_write(pte_addr, new_pte, 4);
  }
}

static bool isa_mmu_permission_check(uint32_t pte, int type) {
  if (!(pte & PTE_V)) {
    assert(false && "access page invalid");
    return false;
  }

  // if (type == MEM_TYPE_READ) {
  //   if (!(pte & PTE_R)) {
  //     assert(false && "mmu permission deny, page cannot read");
  //     return false;
  //   }
  // } else if (type == MEM_TYPE_IFETCH) {
  //   if (!(pte & PTE_X)) {
  //     assert(false && "mmu permisssion deny, page cannot exec");
  //     return false;
  //   }
  // } else if (type == MEM_TYPE_WRITE) {
  //   if (!(pte & PTE_W)) {
  //     assert(false && "mmu permisssion deny, page cannot write");
  //     return false;
  //   }
  // }

  return true;
}

static paddr_t isa_mmu_pagewalk(vaddr_t vaddr, int type) {
  paddr_t pgt1_start = cpu.csr.stap << 12;

  int vpn1_idx = (vaddr >> VPN1_SHIFT) & 0x3FF;
  int vpn0_idx = (vaddr >> VPN0_SHIFT) & 0x3FF;
  int offset = vaddr & OFFSET_MASK;

  paddr_t pte1_addr = pgt1_start + 4 * vpn1_idx;
  uint32_t pte1 = paddr_read(pte1_addr, 4);

  if (isa_mmu_permission_check(pte1, type) == false) {
    assert(0);
  }

  isa_mmu_update_pte(pte1_addr, pte1, type);

  paddr_t pgt0_start = PTE_PPN(pte1) << 2;
  paddr_t pte0_addr = pgt0_start + 4 * vpn0_idx;
  uint32_t pte0 = paddr_read(pte0_addr, 4);

  if (isa_mmu_permission_check(pte0, type) == false) {
    assert(0);
  }

  isa_mmu_update_pte(pte0_addr, pte0, type);

  paddr_t addr_res = (PTE_PPN(pte0) << 2) | offset;
  assert(addr_res == vaddr);
  return addr_res;
}

paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
  int mmu_check = isa_mmu_check(vaddr, len, type);
  if (mmu_check == MMU_TRANSLATE) {
    return isa_mmu_pagewalk(vaddr, type);
  } else if (mmu_check == MMU_DIRECT) {
    return vaddr;
  }

  assert(false && "should not reach here");
  return 0;
}
