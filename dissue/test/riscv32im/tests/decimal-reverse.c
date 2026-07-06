#include "test.h"

static volatile u32 values[] = {1u, 1200u, 12345u, 4007u, 987654321u};
static volatile u32 decimal_base = 10u;

static const u32 expected_reverse[] = {1u, 21u, 54321u, 7004u, 123456789u};
static const u32 expected_digit_sum[] = {1u, 3u, 15u, 11u, 45u};

static u32 reverse_digits(u32 value, u32 *digit_sum) {
  u32 reversed = 0u;
  u32 sum = 0u;
  u32 base = decimal_base;

  do {
    u32 digit = value % base;
    reversed = reversed * base + digit;
    sum += digit;
    value /= base;
  } while (value != 0u);

  *digit_sum = sum;
  return reversed;
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    u32 digit_sum = 0u;
    u32 reversed = reverse_digits(values[i], &digit_sum);

    int check = expect_u32(reversed, expected_reverse[i], i + 1);
    if (check) return check;

    check = expect_u32(digit_sum, expected_digit_sum[i], i + 11);
    if (check) return check;
  }

  return 0;
}
