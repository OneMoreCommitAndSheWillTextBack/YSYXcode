#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>
#include <stdio.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buffer[1024];
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

size_t printf_str(void *buf, const char *src, size_t limit) {
  size_t counter = 0;
  const char *p = src;
  char *dst = buf;
  while(*p != '\0' && limit-- > 0){
    *dst = *p;
    p++;
    dst++;
    counter++;
  }
  return counter;
}

size_t printf_hex(void *buf, unsigned int num, size_t width, char fill, size_t limit) {
  static char trantb[] = "0123456789abcdef";
  char buffer[10];
  int counter = 0;

  // 处理 num == 0 的情况
  if(num == 0) {
    counter = 1;
    buffer[7] = '0';
  } else {
    while(num > 0) {
      buffer[7-counter] = trantb[num % 16];
      num = num >> 4;
      counter++;
    }
  }

  if(width != 0) {
    if(width < counter) {
      width = counter;
    }

    size_t remin = width - counter;
    limit = limit - counter;

    if(fill == 0) {
      fill = ' ';
    }

    // 填充应该在数字之前（左侧填充）
    // 数字当前存储在 buffer[7-counter+1] 到 buffer[7] 的位置（从右往左）
    // 例如：counter=2时，数字在 buffer[6] 和 buffer[7]
    // 如果 width=4，需要在 buffer[4] 和 buffer[5] 填充
    // 填充位置：buffer[7-width+1] 到 buffer[7-width+remin]
    if(remin > 0) {
      // 填充左侧
      for(int i = 0; i < remin; i++) {
        buffer[7-width+1+i] = fill;
      }
      counter = width;
    }
  }

  size_t res = counter;
  // 复制：从 buffer[7-width+1] 开始复制到 buffer[7]（如果width>0）
  // 或者从 buffer[7-counter+1] 开始复制到 buffer[7]（如果width==0）
  int start_idx = (width > 0) ? (7 - width + 1) : (7 - counter + 1);
  for(int i = 0; i < counter; i++) {
    ((char*)buf)[i] = buffer[start_idx + i];
  }

  return res;
}

size_t printf_int32(char *buf, unsigned int num, int is_sign, char fill, size_t width){
  char buffer[16]; // 足够存储32位整数的十进制表示（最多10位数字+符号）
  int counter = 0;
  int is_negative = 0;
  unsigned int abs_num = num;

  // 如果是有符号数，转换为有符号数判断是否为负数
  if(is_sign) {
    int signed_num = (int)num;
    if(signed_num < 0) {
      is_negative = 1;
      abs_num = (unsigned int)(-signed_num); // 取绝对值
    }
  }

  // 处理 abs_num == 0 的情况
  if(abs_num == 0) {
    counter = 1;
    buffer[15] = '0';
  } else {
    while(abs_num > 0) {
      buffer[15-counter] = (abs_num % 10) + '0';
      abs_num = abs_num / 10;
      counter++;
    }
  }

  // 计算总字符数（包括符号）
  int total_chars = counter;
  int has_sign = 0;
  if(is_negative) {
    has_sign = 1;
    total_chars++;
  }

  if(width != 0) {
    if(total_chars > width) {
      width = total_chars; // 如果数字本身超过宽度，使用数字长度
    }

    size_t remin = width - total_chars;
    if(fill == 0) {
      fill = ' ';
    }

    // 填充逻辑：
    // - 零填充：符号在填充之前（如 %05d 和 -123 → "-0123"）
    // - 空格填充：符号在填充之后（如 %5d 和 -123 → " -123"）
    if(remin > 0) {
      // 计算数字的最终位置
      int num_start = 15 - width + 1 + remin + has_sign;
      // 移动数字到最终位置（如果需要）
      if(num_start != 15 - counter + 1) {
        for(int i = 0; i < counter; i++) {
          buffer[num_start + i] = buffer[15 - counter + 1 + i];
        }
      }
      
      if(has_sign && fill == '0') {
        // 零填充：符号在第一位
        buffer[15 - width + 1] = '-';
        // 填充0
        for(int i = 0; i < remin; i++) {
          buffer[15 - width + 1 + 1 + i] = fill;
        }
      } else {
        // 填充空格（或无符号数的零填充）
        for(int i = 0; i < remin; i++) {
          buffer[15 - width + 1 + i] = fill;
        }
        // 放符号（如果有，且是空格填充）
        if(has_sign) {
          buffer[15 - width + 1 + remin] = '-';
        }
      }
      counter = width;
    } else if(has_sign) {
      // 不需要填充，但需要添加符号
      // 移动数字，为符号腾出空间
      for(int i = 0; i < counter; i++) {
        buffer[15 - counter + i] = buffer[15 - counter + 1 + i];
      }
      buffer[15 - counter] = '-';
      counter++;
    }
  } else if(has_sign) {
    // 没有指定宽度，但需要添加符号
    buffer[15-counter] = '-';
    counter++;
  }

  // 复制到输出缓冲区
  // 从 buffer[15-width+1] 开始复制到 buffer[15]（如果width>0）
  // 或者从 buffer[15-counter+1] 开始复制到 buffer[15]（如果width==0）
  int start_idx = (width > 0) ? (15 - width + 1) : (15 - counter + 1);
  for(int i = 0; i < counter; i++) {
    buf[i] = buffer[start_idx + i];
  }
  buf[counter] = '\0'; // 添加字符串结束符
  
  return counter; // 返回写入的字符数
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t outn = 0;
  size_t fmtn = 0;
  int intarg = 0;
  char *chararg = NULL;
  char buf[64]; // 增加了缓冲区大小，以容纳更大的整数转换
  int zerofill = 0;
  int width = 0;       // 用于存储字段宽度
  int i = 0;
  int utype = 0;

  while (outn < n - 1) { // 保留一个字符的空间给终止符
    char ch = fmt[fmtn];
    if (ch == '\0') {
      break;
    }

    if (ch == '%') {
      fmtn++;
      ch = fmt[fmtn];

      // 重置宽度和零填充标志
      width = 0;
      zerofill = 0;

      // 检查零填充标志
      if (ch == '0') {
        zerofill = 1;
        fmtn++;
        ch = fmt[fmtn];
      }

      // 解析字段宽度（数字）
      while (ch >= '0' && ch <= '9') {
        width = width * 10 + (ch - '0');
        fmtn++;
        ch = fmt[fmtn];
      }

      switch (ch) {
      case 'c':
        if (outn < n - 1) {
          out[outn++] = (char)va_arg(ap, int);
        }
        fmtn++;
        break;

      case 'u':
        utype = 1;
      case 'd':
        intarg = va_arg(ap, int);
        {
          char fill_char = zerofill ? '0' : 0;
          size_t int_len = printf_int32(buf, (unsigned int)intarg, utype ? 0 : 1, fill_char, width);
          for (i = 0; i < int_len && outn < n - 1; i++) {
            out[outn++] = buf[i];
          }
        }
        utype = 0;
        fmtn++;
        break;

      case 's':
        chararg = va_arg(ap, char *);
        outn = outn + printf_str(out + outn, chararg, n - outn - 1);
        fmtn++;
        break;

      case 'x':
        intarg = va_arg(ap, int);
        char fill_char = zerofill ? '0' : 0;
        size_t hex_len = printf_hex(buf, (unsigned int)intarg, width, fill_char, n - outn - 1);
        for (i = 0; i < hex_len && outn < n - 1; i++) {
          out[outn++] = buf[i];
        }
        fmtn++;
        break;

      case 'p':
        intarg = va_arg(ap, int);
        size_t pin_len = printf_hex(buf, (unsigned int)intarg, 8, '0', n - outn - 1);
        for (i = 0; i < pin_len && outn < n - 1; i++) {
          out[outn++] = buf[i];
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
