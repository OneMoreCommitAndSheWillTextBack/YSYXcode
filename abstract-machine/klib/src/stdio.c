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
  for (int i = 0; buffer[i] != '\0'; i++) {
    putch(buffer[i]);
  }
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
  char enoptbl[] = {"ds"};
  int input_lenth = -1;
  int zerofill = 0;
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
        if (input_lenth == -1) {
          for (i = 0; intarg > 0; intarg = intarg / 10)
            buf[i++] = (intarg % 10) + '0';
        } else {
          for (i = 0; i < input_lenth; intarg = intarg / 10) {
            if (intarg == 0)
              buf[i++] = (zerofill) ? '0' : ' ';
            else
              buf[i++] = (intarg % 10) + '0';
          }
        }
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
        if (fmt[fmtn] == '0')
          zerofill = 1;
        i = 0;
        input_lenth = 0;
        while (fmt[fmtn + i] - '0' >= 0 && fmt[fmtn + i] - '0' <= 9) {
          buf[i] = fmt[fmtn + i];
          i++;
        }
        fmtn = fmtn + i;
        for (i--; i >= 0; i--)
          input_lenth = input_lenth * 10 + fmt[fmtn + i] - '0';
        char *tmp = NULL;
        for (tmp = enoptbl; *tmp != '\0'; tmp++) {
          if (*tmp == fmt[fmtn])
            break;
        }
        if (*tmp == '\0')
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
