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
  char buf[64]; // 增加了缓冲区大小，以容纳更大的整数转换
  int zerofill = 0;
  int width = 0;       // 用于存储字段宽度
  int is_negative = 0; // 标记数字是否为负数
  int i = 0;

  while (outn < n - 1) { // 保留一个字符的空间给终止符
    char ch = fmt[fmtn];
    if (ch == '\0') {
      break;
    }

    if (ch == '%') {
      fmtn++;
      ch = fmt[fmtn];

      if (ch == '0') {
        zerofill = 1;
        fmtn++;
        ch = fmt[fmtn];

        // 处理字段宽度
        while (fmt[fmtn] >= '0' && fmt[fmtn] <= '9') {
          width = width * 10 + (fmt[fmtn] - '0');
          fmtn++;
          ch = fmt[fmtn];
        }
      } else {
        // 重置宽度和零填充标志，因为不是以0开头的宽度
        width = 0;
        zerofill = 0;
      }

      switch (ch) {
      case 'd':
        intarg = va_arg(ap, int);
        is_negative = intarg < 0;
        if (is_negative) {
          intarg = -intarg;
          if (outn < n - 1) {
            out[outn++] = '-';
          }
        }

        // 将整数转换为字符串，考虑宽度和零填充
        i = 0;
        while (intarg > 0) {
          buf[i++] = (intarg % 10) + '0';
          intarg /= 10;
        }
        if (is_negative) {
          // 如果原数字是负数，宽度应包括负号
          width++;
        }
        while (i < width) {
          if (zerofill && (i < (is_negative ? 1 : 0) || intarg > 0)) {
            if (outn < n - 1) {
              out[outn++] = '0';
            }
          } else if (outn < n - 1) {
            out[outn++] = ' '; // 或者可以选择不填充
          }
          i++;
        }
        for (i--; i >= 0; i--) {
          if (outn < n - 1) {
            out[outn++] = buf[i];
          }
        }
        fmtn++;
        break;

      case 's':
        chararg = va_arg(ap, char *);
        while (*chararg != '\0' && outn < n - 1) {
          out[outn++] = *chararg++;
        }
        fmtn++;
        break;

      default:
        // 对于不支持的格式说明符，直接复制到输出（可能导致错误）
        if (outn < n - 1) {
          out[outn++] = '%';
        }
        if (outn < n - 1) {
          out[outn++] = ch;
        }
        fmtn++;
        break;
      }

      // 重置宽度和零填充标志
      width = 0;
      zerofill = 0;
    } else {
      if (outn < n - 1) {
        out[outn++] = ch;
      }
      fmtn++;
    }
  }

  if (outn < n - 1)
    out[outn] = '\0'; // 确保字符串以null终止
  else
    out[n] = '\0';
  return outn;
}

#endif

/*
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
          if (intarg == 0)
            buf[i++] = '0';
          for (i = 0; intarg > 0; intarg = intarg / 10)
            buf[i++] = (intarg % 10) + '0';
        } else {
          if (intarg == 0) {
            buf[i++] = '0';
            i = 1;
          } else {
            i = 0;
          }
          for (; i < input_lenth; intarg = intarg / 10) {
            if (intarg == 0)
              buf[i++] = (zerofill) ? '0' : ' ';
            else
              buf[i++] = (intarg % 10) + '0';
          }
        }
        for (i = i - 1; i >= 0; i--)
          out[outn++] = buf[i];
        fmtn++;
        input_lenth = 0;
        zerofill = 0;
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
 */
