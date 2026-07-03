#include "test.h"

static volatile char palindrome_text[] = "level";
static volatile char non_palindrome_text[] = "riscv";

static int is_palindrome(volatile char *text) {
  int len = 0;
  while (text[len] != '\0') {
    len++;
  }

  int left = 0;
  int right = len - 1;
  while (left < right) {
    if (text[left] != text[right]) {
      return 0;
    }
    left++;
    right--;
  }

  return 1;
}

int main(void) {
  int check = expect_s32(is_palindrome(palindrome_text), 1, 1);
  if (check) return check;
  return expect_s32(is_palindrome(non_palindrome_text), 0, 2);
}
