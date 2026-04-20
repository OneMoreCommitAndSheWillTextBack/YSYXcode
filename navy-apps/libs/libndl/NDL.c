#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "sys/time.h"
#include "sys/stat.h"

#include "assert.h"

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

uint32_t NDL_GetTicks() {
  struct timeval tv;
  struct timezone tz;

  gettimeofday(&tv, &tz);
  return (uint32_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int NDL_PollEvent(char *buf, int len) {
  int fd = open("/dev/events", 0, 0);
  int res =  read(fd, buf, len);
  close(fd);

  return res;
}

static size_t canvas_width = 0;
static size_t canvas_height = 0;
static size_t canvas_x = 0;
static size_t canvas_y = 0;

static void read_dispinfo(int *w, int *h) {
  int fd = open("/proc/dispinfo", 0, 0);
  assert(fd >= 0);

  char buf[128];
  int readn = read(fd, buf, sizeof(buf) - 1);
  close(fd);
  assert(readn > 0);
  buf[readn] = '\0';

  // Be tolerant to spaces around ':' because different backends may format
  // dispinfo slightly differently.
  int ok = sscanf(buf, "WIDTH : %d\nHEIGHT : %d", w, h);
  if (ok != 2) {
    ok = sscanf(buf, "WIDTH:%d\nHEIGHT:%d", w, h);
  }
  assert(ok == 2);
}

void NDL_OpenCanvas(int *w, int *h) {
  int max_height = 0, max_width = 0;
  read_dispinfo(&max_width, &max_height);
  if (*w == 0) *w = max_width;
  if (*h == 0) *h = max_height;

  assert(*w <= max_width);
  assert(*h <= max_height);

  screen_w = max_width;
  screen_h = max_height;
  canvas_width = *w;
  canvas_height = *h;
  return;
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  if (screen_w == 0 || screen_h == 0) {
    read_dispinfo(&screen_w, &screen_h);
  }

  int frame_buffer_x = canvas_x + x;
  int frame_buffer_y = canvas_y + y;

  if (h == 0) h = canvas_height;
  if (w == 0) w = canvas_width;

  int fd_fb = open("/dev/fb", 0, 0);
  for (int i = 0; i < h; i++) {
    lseek(fd_fb, sizeof(uint32_t) * ((frame_buffer_y + i) * screen_w + frame_buffer_x), SEEK_SET);
    write(fd_fb, (pixels + i * w), sizeof(uint32_t) * w);
  }
  close(fd_fb);
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }
  return 0;
}

void NDL_Quit() {
}
