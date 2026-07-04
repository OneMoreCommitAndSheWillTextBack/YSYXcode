#ifndef NPC_AM_CPU_TEST_H
#define NPC_AM_CPU_TEST_H

#include <stdarg.h>
#include "test.h"

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef unsigned int size_t;
typedef int bool;

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

#define LENGTH(a) ((int)(sizeof(a) / sizeof((a)[0])))

#define check(cond)             \
  do {                          \
    if (!(cond)) return __LINE__; \
  } while (0)

static inline uint32_t am_abs_u32(s32 value) {
  return value < 0 ? (0u - (uint32_t)value) : (uint32_t)value;
}

static inline uint32_t am_mul_u32(uint32_t a, uint32_t b) {
  uint32_t result = 0;

  while (b != 0) {
    if ((b & 1u) != 0) {
      result += a;
    }
    a <<= 1;
    b >>= 1;
  }

  return result;
}

static inline s32 am_mul_s32(s32 a, s32 b) {
  uint32_t result = am_mul_u32(am_abs_u32(a), am_abs_u32(b));
  return ((a < 0) != (b < 0)) ? -(s32)result : (s32)result;
}

static inline uint32_t am_divmod_u32(uint32_t n, uint32_t d, uint32_t *rem_out) {
  uint32_t q = 0;
  uint32_t rem = 0;

  if (d == 0) {
    if (rem_out != 0) {
      *rem_out = n;
    }
    return 0xffffffffu;
  }

  for (int i = 31; i >= 0; i--) {
    rem = (rem << 1) | ((n >> i) & 1u);
    if (rem >= d) {
      rem -= d;
      q |= 1u << i;
    }
  }

  if (rem_out != 0) {
    *rem_out = rem;
  }
  return q;
}

static inline uint32_t am_div_u32(uint32_t n, uint32_t d) {
  return am_divmod_u32(n, d, 0);
}

static inline uint32_t am_mod_u32(uint32_t n, uint32_t d) {
  uint32_t rem = 0;
  (void)am_divmod_u32(n, d, &rem);
  return rem;
}

static inline s32 am_div_s32(s32 n, s32 d) {
  uint32_t q = am_div_u32(am_abs_u32(n), am_abs_u32(d));
  return ((n < 0) != (d < 0)) ? -(s32)q : (s32)q;
}

static inline s32 am_mod_s32(s32 n, s32 d) {
  uint32_t rem = am_mod_u32(am_abs_u32(n), am_abs_u32(d));
  return n < 0 ? -(s32)rem : (s32)rem;
}

static inline uint64_t am_mul_u32_to_u64(uint32_t a, uint32_t b) {
  uint64_t result = 0;
  uint64_t addend = a;

  while (b != 0) {
    if ((b & 1u) != 0) {
      result += addend;
    }
    addend <<= 1;
    b >>= 1;
  }

  return result;
}

static inline int64_t am_mul_s32_to_s64(s32 a, s32 b) {
  uint64_t result = am_mul_u32_to_u64(am_abs_u32(a), am_abs_u32(b));
  return ((a < 0) != (b < 0)) ? -(int64_t)result : (int64_t)result;
}

static inline uint32_t am_mul_mod_u32(uint32_t a, uint32_t b, uint32_t mod) {
  uint32_t result = 0;
  a = am_mod_u32(a, mod);

  while (b != 0) {
    if ((b & 1u) != 0) {
      result += a;
      if (result >= mod) {
        result -= mod;
      }
    }
    a <<= 1;
    if (a >= mod) {
      a -= mod;
    }
    b >>= 1;
  }

  return result;
}

static inline void am_store_u32_unaligned(volatile uint8_t *dst, uint32_t value) {
  dst[0] = (uint8_t)value;
  dst[1] = (uint8_t)(value >> 8);
  dst[2] = (uint8_t)(value >> 16);
  dst[3] = (uint8_t)(value >> 24);
}

static inline uint32_t am_load_u32_unaligned(const volatile uint8_t *src) {
  return ((uint32_t)src[0]) |
         ((uint32_t)src[1] << 8) |
         ((uint32_t)src[2] << 16) |
         ((uint32_t)src[3] << 24);
}

static inline int am_strcmp(const char *a, const char *b) {
  while (*a != '\0' && *a == *b) {
    a++;
    b++;
  }
  return (uint8_t)*a - (uint8_t)*b;
}

static inline char *am_strcpy(char *dst, const char *src) {
  char *ret = dst;
  while ((*dst++ = *src++) != '\0') {
  }
  return ret;
}

static inline char *am_strcat(char *dst, const char *src) {
  char *ret = dst;
  while (*dst != '\0') {
    dst++;
  }
  while ((*dst++ = *src++) != '\0') {
  }
  return ret;
}

static inline void *am_memset(void *dst, int value, size_t count) {
  uint8_t *p = (uint8_t *)dst;
  for (size_t i = 0; i < count; i++) {
    p[i] = (uint8_t)value;
  }
  return dst;
}

static inline int am_memcmp(const void *a, const void *b, size_t count) {
  const uint8_t *pa = (const uint8_t *)a;
  const uint8_t *pb = (const uint8_t *)b;

  for (size_t i = 0; i < count; i++) {
    if (pa[i] != pb[i]) {
      return pa[i] - pb[i];
    }
  }

  return 0;
}

static inline char *am_write_s32(char *dst, s32 value) {
  char tmp[12];
  int len = 0;
  uint32_t n;

  if (value < 0) {
    *dst++ = '-';
    n = 0u - (uint32_t)value;
  } else {
    n = (uint32_t)value;
  }

  do {
    uint32_t rem = 0;
    n = am_divmod_u32(n, 10u, &rem);
    tmp[len++] = (char)('0' + rem);
  } while (n != 0);

  while (len > 0) {
    *dst++ = tmp[--len];
  }

  return dst;
}

static inline int am_sprintf(char *dst, const char *fmt, ...) {
  va_list ap;
  char *p = dst;

  va_start(ap, fmt);
  while (*fmt != '\0') {
    if (*fmt != '%') {
      *p++ = *fmt++;
      continue;
    }

    fmt++;
    if (*fmt == 's') {
      const char *s = va_arg(ap, const char *);
      while (*s != '\0') {
        *p++ = *s++;
      }
    } else if (*fmt == 'd') {
      p = am_write_s32(p, va_arg(ap, int));
    } else if (*fmt == '%') {
      *p++ = '%';
    } else {
      *p++ = '%';
      *p++ = *fmt;
    }
    fmt++;
  }
  *p = '\0';
  va_end(ap);

  return (int)(p - dst);
}

#define strcmp am_strcmp
#define strcpy am_strcpy
#define strcat am_strcat
#define memset am_memset
#define memcmp am_memcmp
#define sprintf am_sprintf

#endif
