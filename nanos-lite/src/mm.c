#include "klib-macros.h"
#include "proc.h"
#include <memory.h>
#include <string.h>

static void *pf = NULL;

void *new_page(size_t nr_page) {
  uint8_t *old_pf = (uint8_t *)pf;
  pf = (void *)ROUNDUP(pf + nr_page * PGSIZE, PGSIZE);
  // Log("new_page: nr_page=%d old_pf=%p new_pf=%p", (int)nr_page, old_pf, pf);
  return (void *)old_pf;
}

#ifdef HAS_VME
static void *pg_alloc(int n) {
  assert(n != 0);

  size_t pages = (n + PGSIZE - 1) / PGSIZE;

  uint8_t *alloc_ptr = new_page(pages);
  memset(alloc_ptr, 0, PGSIZE * pages);
  return alloc_ptr;
}
#endif

void free_page(void *p) { panic("not implement yet"); }

int mm_brk(uintptr_t brk) {
  Log("mm_brk: request=0x%x current_max_brk=0x%x", brk, current->max_brk);
  if (brk < current->max_brk)
    return 0;

  if (current->max_brk == 0) {
    current->max_brk = brk;
    Log("mm_brk: initialize current_max_brk=0x%x", current->max_brk);
    return 0;
  }

  uintptr_t va = ROUNDUP(current->max_brk, PGSIZE);
  uintptr_t brk_end = ROUNDUP(brk, PGSIZE);
  for (; va < brk_end; va += PGSIZE) {
    void *pa = new_page(1);
    Log("mm_brk: map va=%p -> pa=%p", (void *)va, pa);
    map(&current->as, (void *)va, pa, PTE_U | PTE_R | PTE_W | PTE_A | PTE_D);
  }
  current->max_brk = brk;
  Log("mm_brk: updated current_max_brk=0x%x", current->max_brk);

  return 0;
}

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
