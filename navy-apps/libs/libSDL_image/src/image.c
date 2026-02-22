#define SDL_malloc malloc
#define SDL_free free
#define SDL_realloc realloc

#define SDL_STBIMAGE_IMPLEMENTATION
#include "SDL_stbimage.h"

SDL_Surface *IMG_Load_RW(SDL_RWops *src, int freesrc) {
  assert(src->type == RW_TYPE_MEM);
  assert(freesrc == 0);
  return NULL;
}

SDL_Surface *IMG_Load(const char *filename) {
  FILE *fd = fopen(filename, "r");

  if (fd == NULL) {
    assert(false && "IMG load fopen failed");
  }

  fseek(fd, 0, SEEK_END);
  unsigned int size = ftell(fd);

  uint32_t *buf = malloc(size);
  uin32t_t readn = fread(buf, size, 1, fd);
  assert(readn == size && buf != NULL);

  SDL_Surface *res = STBIMG_LoadFromMemory(buf, size);
  if(res == NULL) {
    assert(false && "STBIMG_LoadFromMemory failed");
  }
  free(buf); 
  fclose(fd);

  return res;
}

int IMG_isPNG(SDL_RWops *src) { return 0; }

SDL_Surface *IMG_LoadJPG_RW(SDL_RWops *src) { return IMG_Load_RW(src, 0); }

char *IMG_GetError() { return "Navy does not support IMG_GetError()"; }
