#ifndef NPC_TEST_H
#define NPC_TEST_H

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

static inline int expect_u32(u32 actual, u32 expected, int code) {
  return actual == expected ? 0 : code;
}

static inline int expect_s32(s32 actual, s32 expected, int code) {
  return actual == expected ? 0 : code;
}

#endif
