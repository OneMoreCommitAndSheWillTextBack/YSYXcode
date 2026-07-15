#include "test.h"

static volatile u32 words[2] __attribute__((aligned(8))) = {
    0x55667788u,
    0x11223344u,
};

static volatile u32 full_numerator = 17u;
static volatile u32 full_denominator = 31u;
static volatile u32 byte_numerator = 55u;
static volatile u32 byte_denominator = 11u;

int main(void) {
  if (words[1] != 0x11223344u) return 10;

  // The store waits for divu while the younger load reaches the SQ query.
  u32 word_index = full_numerator / full_denominator;
  words[word_index] = 0x89abcdefu;
  u32 full_forward = words[0];
  if (full_forward != 0x89abcdefu) return 11;

  volatile u8 *bytes = (volatile u8 *)words;
  u32 byte_index = byte_numerator / byte_denominator;
  bytes[byte_index] = 0xeeu;
  u32 partial_forward = words[1];
  if (partial_forward != 0x1122ee44u) return 12;

  if (words[0] != 0x89abcdefu) return 13;
  if (words[1] != 0x1122ee44u) return 14;
  return 0;
}
