#include "common.h"
#include "cpu/cpu.h"
#include "cpu/difftest.h"
#include "difftest-def.h"
#include "isa.h"
#include "memory/paddr.h"
#include "memory/vaddr.h"
#include <stdint.h>
#include <stdio.h>

typedef struct memguarder {
  vaddr_t addr;
  struct memguarder *next;
} memguarder_t;

static memguarder_t *guard_list = NULL;

int add_memguard(vaddr_t addr) {
  if (!isa_difftest_is_attach()) {
    printf("[error] the memguarder rely on the difftest\n");
    return -1;
  }

  if (!in_pmem(addr)) {
    printf("[error] invalid addr 0x%x\n", addr);
    return -1;
  }

  uint32_t ref_data = 0;
  uint32_t dut_data = 0;
  if (ref_difftest_memcpy == NULL) {
    printf("[error] the ref_difftest_memcpy handle should not be NULL\n");
    return -1;
  }

  ref_difftest_memcpy(addr, &ref_data, 4, DIFFTEST_TO_DUT);
  dut_data = vaddr_read(addr, 4);
  if (dut_data != ref_data) {
    printf("[error] ref(0x%x) != dut(0x%x)\n", ref_data, dut_data);
    printf("\t consider the diffinit sync or here is a bug\n");
    return -1;
  }

  memguarder_t **cur = &guard_list;
  memguarder_t *new_node = NULL;
  while (*cur) {
    if ((*cur)->addr == addr)
      return 0;
    cur = &(*cur)->next;
  }

  new_node = (memguarder_t *)malloc(sizeof(memguarder_t));
  if (!new_node) {
    printf("[error] malloc failed\n");
    return -1;
  }
  new_node->addr = addr;
  new_node->next = NULL;
  *cur = new_node;

  return 0;
}

void info_memguard() {
  memguarder_t *cur = guard_list;
  int i = 0;
  while (cur != NULL) {
    uint32_t data = vaddr_read(cur->addr, 4);
    printf("memguard[%d] watching the addr 0x%x value is 0x%x %d\n", i,
           cur->addr, data, data);
  }

  return;
}

void del_memguard(int idx) {
  int counter = 0;
  memguarder_t **cur = &guard_list;
  while (*cur != NULL) {
    if (counter == idx) {
      vaddr_t addr = (*cur)->addr;
      memguarder_t *to_del = *cur;
      *cur = (*cur)->next;
      free(to_del);
      printf("delete memguard[%d] watching on addr 0x%x successfully\n", idx,
             addr);
      return;
    }

    counter++;
    cur = &(*cur)->next;
  }

  printf("cannot found memguard[%d]\n", idx);
  return;
}

void exec_memguard() {
  memguarder_t *cur = guard_list;
  bool failed = false;
  while (cur != NULL) {
    uint32_t ref_data = 0;
    uint32_t dut_data = 0;
    ref_difftest_memcpy(cur->addr, &ref_data, 4, DIFFTEST_TO_DUT);
    dut_data = vaddr_read(cur->addr, 4);

    if (ref_data != dut_data) {
      failed = true;
      printf("[memguard failed] dut(0x%x) != ref(0x%x)\n", dut_data, ref_data);
    }

    cur = cur->next;
  }

  if (failed) {
    set_state_stop();
  }

  return;
}
