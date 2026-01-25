#include "am.h"
#include "amdev.h"
#include <common.h>
#include <stdio.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
# define MULTIPROGRAM_YIELD() yield()
#else
# define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
  [AM_KEY_NONE] = "NONE",
  AM_KEYS(NAME)
};

size_t serial_write(const void *buf, size_t offset, size_t len) {
  int write_counter = 0;
  for(write_counter=0;write_counter<len;write_counter++){
    putch(((char *)buf)[write_counter]);
  }
  return write_counter;
}

int get_time(struct timeval *tv, struct timezone *tz) {
  AM_TIMER_UPTIME_T time;
  ioe_read(AM_TIMER_UPTIME, &time);
 
  if(tv == NULL || tz == NULL)
    return -1;
    
  tv->tv_sec = time.us / 1000;
  tv->tv_usec = time.us;

  tz->tz_minuteswest = 0;
  tz->tz_dsttime = 0;

  return 0;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  AM_INPUT_KEYBRD_T kbd;
  ioe_read(AM_INPUT_KEYBRD, &kbd);

  if(kbd.keycode == AM_KEY_NONE) {
    return 0;
  }

  char* prefix = (kbd.keydown == true) ? "kd" : "ku";
  size_t res = snprintf((char *)buf, len, "%s %s\n", prefix, keyname[kbd.keycode]);
  // Log("events_read buf: %s", buf);
  return res;
}

size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  char buffer[32];
  AM_GPU_CONFIG_T cfg;
  ioe_read(AM_GPU_CONFIG, &cfg);
  size_t size = snprintf(buffer, sizeof(buffer), "WIDTH : %d\nHEIGHT:%d", cfg.width, cfg.height);
  Log("dispinfo buffer size %d", size);
  return snprintf(buf, len, "%s", buffer);
}

size_t fb_write(const void *buf, size_t offset, size_t len) {
  return 0;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
