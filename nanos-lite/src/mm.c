#include "klib-macros.h"
#include <memory.h>
#include <string.h>

static void *pf = NULL;

void *new_page(size_t nr_page) {
  uint8_t *old_pf = (uint8_t *)pf;
  pf = (void *)ROUNDUP(pf + nr_page * PGSIZE, PGSIZE);
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

/* The brk() system call handler. */
int mm_brk(uintptr_t brk) { return 0; }

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
