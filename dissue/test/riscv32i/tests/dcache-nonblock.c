#include "test.h"

static volatile u32 hot_line[2] __attribute__((aligned(8))) = {
    0x13579bdfu,
    0x2468ace0u,
};

static volatile u32 miss_line[2] __attribute__((aligned(8))) = {
    0x0badf00du,
    0xc001d00du,
};

static volatile u32 merge_line[2] __attribute__((aligned(8))) = {
    0x55aa55aau,
    0xaa55aa55u,
};

static inline void load_pair(const volatile u32 *first, const volatile u32 *second,
                             u32 *first_value, u32 *second_value) {
  u32 first_result;
  u32 second_result;

  // Keep both loads in one ICache block so a data miss cannot delay fetching
  // the second instruction through the single AXI port.
  asm volatile(
      ".balign 8\n"
      "lw %0, 0(%2)\n"
      "lw %1, 0(%3)\n"
      : "=&r"(first_result), "=&r"(second_result)
      : "r"(first), "r"(second)
      : "memory");

  *first_value = first_result;
  *second_value = second_result;
}

int main(void) {
  u32 warm = hot_line[0];
  if (warm != 0x13579bdfu) return 10;

  u32 miss;
  u32 hit_under_miss;
  load_pair(&miss_line[0], &hot_line[1], &miss, &hit_under_miss);
  if (miss != 0x0badf00du) return 11;
  if (hit_under_miss != 0x2468ace0u) return 12;

  // Adjacent words share a 64-bit line, producing two waiters on one MSHR.
  u32 merged0;
  u32 merged1;
  load_pair(&merge_line[0], &merge_line[1], &merged0, &merged1);
  if (merged0 != 0x55aa55aau) return 13;
  if (merged1 != 0xaa55aa55u) return 14;

  if (merge_line[0] != 0x55aa55aau) return 15;
  if (merge_line[1] != 0xaa55aa55u) return 16;
  return 0;
}
