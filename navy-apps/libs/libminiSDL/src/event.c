#include <NDL.h>
#include <SDL.h>

#include "assert.h"

#define keyname(k) #k,

static const char *keyname[] = {"NONE", _KEYS(keyname)};

int SDL_PushEvent(SDL_Event *ev) { return 0; }

int SDL_PollEvent(SDL_Event *ev) { return 0; }

int sdl_strcmp(const char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i])
      return 0;
  }

  return str1[i] == str2[i];
}

int SDL_WaitEvent(SDL_Event *event) {
  char buf[16];
  int res;
  while ((res = NDL_PollEvent(buf, 16)) == 0) {
    // busy wait until an event occurs
  }
  char *keystate = buf;
  char *keyn = buf + 3;
  buf[2] = '\0';

  if (sdl_strcmp(keystate, "kd")) {
    event->key.type = SDL_KEYDOWN;
  } else if (sdl_strcmp(keystate, "ku")) {
    event->key.type = SDL_KEYUP;
  } else {
    assert(0);
  }

  for(int i = 0; i < sizeof(keyname) / sizeof(keyname[0]); i++) {
    if(sdl_strcmp(keyname[i], keyn)) {
      event->key.keysym.sym = i;
    }
  }

  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  return 0;
}

uint8_t *SDL_GetKeyState(int *numkeys) { return NULL; }
