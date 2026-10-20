#ifndef NPC_PACK_LOG_H
#define NPC_PACK_LOG_H

#include <stdarg.h>
#include <stdio.h>

/* Every diagnostic goes to stderr: in --stdout mode stdout carries image bytes
 * and nothing else. */
__attribute__((unused)) static void npc_error(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  fputs("pack: ", stderr);
  vfprintf(stderr, fmt, args);
  fputc('\n', stderr);
  va_end(args);
}

#endif
