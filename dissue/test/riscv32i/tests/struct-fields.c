#include "test.h"

struct Node {
  s32 key;
  u32 flags;
  u8 level;
  u8 pad[3];
  s32 next;
};

static volatile struct Node nodes[4] = {
    {10, 1u, 2u, {0, 0, 0}, 1},
    {-4, 0u, 5u, {0, 0, 0}, 2},
    {7, 3u, 1u, {0, 0, 0}, 3},
    {12, 2u, 4u, {0, 0, 0}, -1},
};

int main(void) {
  s32 score = 0;
  u32 level_sum = 0;

  for (int i = 0; i < 4; i++) {
    if ((nodes[i].flags & 1u) != 0) {
      score += nodes[i].key;
    } else {
      score -= nodes[i].key;
    }
    level_sum += nodes[i].level;
  }

  int check = expect_s32(score, 9, 1);
  if (check) return check;
  check = expect_u32(level_sum, 12u, 2);
  if (check) return check;

  s32 chain_sum = 0;
  int index = 0;
  int hops = 0;
  while (index >= 0 && hops < 5) {
    chain_sum += nodes[index].key;
    index = nodes[index].next;
    hops++;
  }

  check = expect_s32(chain_sum, 25, 3);
  if (check) return check;
  return expect_s32(hops, 4, 4);
}
