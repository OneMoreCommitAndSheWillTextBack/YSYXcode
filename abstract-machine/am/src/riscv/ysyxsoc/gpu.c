#include "soc-ioe.h"
#include <stdint.h>

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *fbdraw) {
   volatile uint32_t *vga_addr = (volatile uint32_t *)VGA_ADDR;
   int x = fbdraw->x;
   int y = fbdraw->y;

   // 先行后列
   for (int i = y; i < y + fbdraw->h && i < 480; i++) {
    for (int j = x; j < fbdraw->w && j < 640; j++) {
      vga_addr[j + i * 640] = ((uint32_t *)fbdraw->pixels)[j + i * 640];
    }
   }
}

void __am_gpu_memcpy(AM_GPU_MEMCPY_T *memcpy) {
  uint32_t dest = memcpy->dest;
  void *src = memcpy->src;
  for (int i = 0; i < memcpy->size; i++) {
    *((uint32_t *)(VGA_ADDR) + dest)  = *(uint32_t *)(src);
    src++;
    dest++;
  }
}