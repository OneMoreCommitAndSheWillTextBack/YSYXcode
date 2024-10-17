#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>
#include <stdio.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buffer[512];
  va_list ap;
  va_start(ap, fmt);
  int size = vsprintf(buffer, fmt, ap);
  va_end(ap);
  return size;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, 512, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int size = vsnprintf(out, 512, fmt, ap);
  va_end(ap);
  return size;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int size = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return size;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t outn = 0;
  size_t fmtn = 0;
  int intarg = 0;
  char *chararg = NULL;
  int i = 0;
  char buf[32];
  while (outn < n) {
    switch (fmt[fmtn]) {
    case '%':
      fmtn++;
      switch (fmt[fmtn]) {
      case 'd':
        intarg = va_arg(ap, int);
        if (intarg < 0) {
          intarg = -intarg;
          out[outn++] = '-';
        }
        for (i = 0; intarg > 0; intarg = intarg / 10)
          buf[i++] = (intarg % 10) + '0';
        for (i = i - 1; i >= 0; i--)
          out[outn++] = buf[i];
        fmtn++;
        break;
      case 's':
        chararg = va_arg(ap, char *);
        i = 0;
        while (chararg[i] != '\0')
          out[outn++] = chararg[i++];
        fmtn++;
        break;
      default:
        return -1;
      }
      break;
    case '\0':
      out[outn] = fmt[fmtn];
      return outn;
    default:
      out[outn++] = fmt[fmtn++];
    }
  }
  out[outn] = '\0';
  return outn;
}

#endif
