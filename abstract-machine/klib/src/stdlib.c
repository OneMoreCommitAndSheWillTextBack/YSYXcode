#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#define LONG_MAX 2147483647L
#define LONG_MIN (-2147483647L - 1)
#define LLONG_MIN -9223372036854775807LL - 1
#define LLONG_MAX 9223372036854775807LL

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;
static unsigned long int addr = 0;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) { next = seed; }

int abs(int x) { return (x < 0 ? -x : x); }

int atoi(const char *nptr) {
  int x = 0;
  while (*nptr == ' ') {
    nptr++;
  }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  return x;
}

void *malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()
#if !(defined(__ISA_NATIVE__) && defined(__NATIVE_USE_KLIB__))
  if (addr == 0)
    addr = (unsigned long int)heap.start;
  printf("111");
  unsigned long int ret = addr;
  addr += (size - (size % sizeof(int)) + sizeof(int));
  return (void *)ret;
#endif
  return NULL;
}

void free(void *ptr) {}

static inline int isvalidbasech(int ch, int base) {
  if (base < 2 || base > 36)
    return 0;

  int val;
  if (ch >= '0' && ch <= '9') {
    val = ch - '0';
  } else if (ch >= 'A' && ch <= 'Z') {
    val = ch - 'A' + 10;
  } else if (ch >= 'a' && ch <= 'z') {
    val = ch - 'a' + 10;
  } else {
    return 0;
  }

  return val < base;
}

long strtol(const char *nptr, char **endptr, int base) {
  if ((base < 2 || base > 36) && base != 0) {
    return 0;
  }
  const char *ptr = nptr;
  while (isspace(*ptr)) {
    ptr++;
  }

  int flag = 1;
  if (*ptr == '+') {
    ptr++;
  } else if (*ptr == '-') {
    flag = -1;
    ptr++;
  }

  // handle prefix like 0x, 0b, 0o
  int prefix = *ptr;
  if (base == 0) {
    if (prefix == '0') {
      switch (*(ptr + 1)) {
      case 'X':
      case 'x':
        base = 16;
        ptr += 2;
        break;
      case 'B':
      case 'b':
        base = 2;
        ptr += 2;
        break;
      default:
        base = 8;
        ptr += 1;
      }
    } else if (prefix > '0' && prefix <= '9') {
      base = 10;
      // do not move the ptr
    } else {
      if (endptr != NULL) {
        *endptr = (char *)&(*nptr);
      }
      return 0;
    }
  } else if (base == 16) {
    if (*ptr == '0' && (*(ptr + 1) == 'x' || *(ptr + 1) == 'X')) {
      ptr += 2;
    }
  } else if (base == 8) {
    if (*ptr == '0' && (*(ptr + 1) == 'o' || *(ptr + 1) == 'O')) {
      ptr += 2;
    }
  } else if (base == 2) {
    if (*ptr == '0' && (*(ptr + 1) == 'b' || *(ptr + 1) == 'B')) {
      ptr += 2;
    }
  }

  // now the ptr should point to the first ch in the string
  unsigned long res = 0;
  unsigned long limit =
      flag == 1 ? (unsigned long)LONG_MAX : (unsigned long)LONG_MAX + 1;
  int overflow = 0;
  while (isvalidbasech(*ptr, base)) {
    int val;
    char c = *ptr;
    if (c >= '0' && c <= '9')
      val = c - '0';
    else if (c >= 'A' && c <= 'Z')
      val = c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
      val = c - 'a' + 10;

    if (!overflow) {
      if (res > (limit - (unsigned long)val) / (unsigned long)base) {
        overflow = 1;
      } else {
        res = res * (unsigned long)base + (unsigned long)val;
      }
    }
    ptr++;
  }
  if (endptr != NULL) {
    *endptr = (char *)&(*nptr);
  }
  if (overflow) {
    return flag == 1 ? LONG_MAX : LONG_MIN;
  }
  if (flag == -1) {
    if (res == (unsigned long)LONG_MAX + 1) {
      return LONG_MIN;
    }
    return -(long)res;
  }
  return (long)res;
}

long long strtoll(const char *nptr, char **endptr, int base) {
  if ((base < 2 || base > 36) && base != 0) {
    return 0;
  }
  const char *ptr = nptr;
  while (isspace(*ptr)) {
    ptr++;
  }

  int flag = 1;
  if (*ptr == '+') {
    ptr++;
  } else if (*ptr == '-') {
    flag = -1;
    ptr++;
  }

  // handle prefix like 0x, 0b, 0o
  int prefix = *ptr;
  if (base == 0) {
    if (prefix == '0') {
      switch (*(ptr + 1)) {
      case 'X':
      case 'x':
        base = 16;
        ptr += 2;
        break;
      case 'B':
      case 'b':
        base = 2;
        ptr += 2;
        break;
      default:
        base = 8;
        ptr += 1;
      }
    } else if (prefix > '0' && prefix <= '9') {
      base = 10;
      // do not move the ptr
    } else {
      if (nptr != NULL) {
        *endptr = (char *)&(*nptr);
      }
      return 0;
    }
  } else if (base == 16) {
    if (*ptr == '0' && (*(ptr + 1) == 'x' || *(ptr + 1) == 'X')) {
      ptr += 2;
    }
  } else if (base == 8) {
    if (*ptr == '0' && (*(ptr + 1) == 'o' || *(ptr + 1) == 'O')) {
      ptr += 2;
    }
  } else if (base == 2) {
    if (*ptr == '0' && (*(ptr + 1) == 'b' || *(ptr + 1) == 'B')) {
      ptr += 2;
    }
  }

  // now the ptr should point to the first ch in the string
  unsigned long long res = 0;
  unsigned long long limit = flag == 1 ? (unsigned long long)LLONG_MAX
                                       : (unsigned long long)LLONG_MAX + 1;
  int overflow = 0;
  while (isvalidbasech(*ptr, base)) {
    int val;
    char c = *ptr;
    if (c >= '0' && c <= '9')
      val = c - '0';
    else if (c >= 'A' && c <= 'Z')
      val = c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
      val = c - 'a' + 10;

    if (!overflow) {
      if (res > (limit - (unsigned long long)val) / (unsigned long long)base) {
        overflow = 1;
      } else {
        res = res * (unsigned long long)base + (unsigned long long)val;
      }
    }
    ptr++;
  }
  if (endptr != NULL) {
    *endptr = (char *)&(*nptr);
  }
  if (overflow) {
    return flag == 1 ? LLONG_MAX : LLONG_MIN;
  }
  if (flag == -1) {
    if (res == (unsigned long long)LLONG_MAX + 1) {
      return LLONG_MIN;
    }
    return -(long long)res;
  }
  return (long long)res;
}
#endif
