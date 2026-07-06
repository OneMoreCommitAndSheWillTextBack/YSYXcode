#include "test.h"

static volatile s32 sa = -37;
static volatile s32 sb = 5;
static volatile u32 ua = 0xfffffff1u;
static volatile u32 ub = 7u;

int main(void) {
  int check = expect_s32(sa * sb, -185, 1);
  if (check) return check;

  check = expect_s32(sa / sb, -7, 2);
  if (check) return check;

  check = expect_s32(sa % sb, -2, 3);
  if (check) return check;

  check = expect_u32(ua / ub, 0x24924922u, 4);
  if (check) return check;

  return expect_u32(ua % ub, 3u, 5);
}
