#include "test.h"

static volatile char source[] = "riscv32i-test";
static char buffer[16];

static int copy_string(char *dst, volatile char *src) {
  int len = 0;

  while (src[len] != '\0') {
    dst[len] = src[len];
    len++;
  }
  dst[len] = '\0';

  return len;
}

int main(void) {
  int len = copy_string(buffer, source);

  int check = expect_s32(len, 13, 1);
  if (check) return check;
  if (buffer[0] != 'r') return 2;
  if (buffer[5] != '3') return 3;
  if (buffer[8] != '-') return 4;
  if (buffer[12] != 't') return 5;
  if (buffer[13] != '\0') return 6;

  return 0;
}
