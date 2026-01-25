#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "sys/time.h"
#include "sys/stat.h"

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;

uint32_t NDL_GetTicks() {
  struct timeval tv;
  struct timezone tz;

  int res = gettimeofday(&tv, &tz);
  return tv.tv_usec / 1000;
}

int NDL_PollEvent(char *buf, int len) {
  int fd = open("/dev/events", 0, 0);
  int res =  read(fd, buf, len);
  close(fd);

  return res;
}

static size_t canvas_width = 0;
static size_t canvas_height = 0;

void NDL_OpenCanvas(int *w, int *h) {
  int fd = open("/proc/dispinfo", 0, 0);
  char buf[128];
  int readn = read(fd, buf, sizeof(buf));
  if(readn == 0) {
    *w = 0; *h = 0; return ;
  }
  int max_height, max_width;

  sscanf(buf, "WIDTH : %d\nHEIGHT:%d", &max_width, &max_height);
  if(*w == 0) *w = max_width;
  if(*h == 0) *h = max_height;

  canvas_width = *w;
  canvas_height = *h;
  return ;
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
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
