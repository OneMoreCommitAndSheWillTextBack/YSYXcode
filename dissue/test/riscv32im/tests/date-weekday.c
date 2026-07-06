#include "test.h"

static volatile u32 years[] = {2000u, 2024u, 2026u, 1970u, 1999u};
static volatile u32 months[] = {1u, 2u, 7u, 1u, 12u};
static volatile u32 days[] = {1u, 29u, 5u, 1u, 31u};
static volatile u32 div4 = 4u;
static volatile u32 div5 = 5u;
static volatile u32 div7 = 7u;
static volatile u32 div100 = 100u;

static const u32 expected[] = {0u, 5u, 1u, 5u, 6u};

static u32 zeller_weekday(u32 year, u32 month, u32 day) {
  if (month < 3u) {
    month += 12u;
    year--;
  }

  u32 k = year % div100;
  u32 j = year / div100;

  return (day + (13u * (month + 1u)) / div5 + k + k / div4 + j / div4 +
          5u * j) %
         div7;
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    int check =
        expect_u32(zeller_weekday(years[i], months[i], days[i]), expected[i],
                   i + 1);
    if (check) return check;
  }

  return 0;
}
