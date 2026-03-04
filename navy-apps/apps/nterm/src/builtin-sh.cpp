#include <nterm.h>
#include <stdarg.h>
#include <unistd.h>
#include <SDL.h>
#include "assert.h"

char handle_key(SDL_Event *ev);

static void sh_printf(const char *format, ...) {
  static char buf[256] = {};
  va_list ap;
  va_start(ap, format);
  int len = vsnprintf(buf, 256, format, ap);
  va_end(ap);
  term->write(buf, len);
}

static void sh_banner() {
  sh_printf("Built-in Shell in NTerm (NJU Terminal)\n\n");
}

static void sh_prompt() {
  sh_printf("sh> ");
}

#define ARGMAX 5
#define ARGLEN 36
static int sh_tokenize(const char *cmd, char argv[][ARGLEN]) {
  int cur_argv_idx = 0;
  int cur_len = 0;
  int cmd_idx = 0;
  
  while (cmd[cmd_idx] != '\0') {
    if (cmd[cmd_idx] == ' ' || cmd[cmd_idx] == '\n') {
      if (cur_len > 0) {
        argv[cur_argv_idx][cur_len] = '\0';
        cur_argv_idx++;
        cur_len = 0;
        assert(cur_argv_idx < ARGMAX && "cur_argv_idx out of range");
      }
      while (cmd[cmd_idx] == ' ' || cmd[cmd_idx] == '\n') cmd_idx++;
    } else {
      assert(cur_len < ARGLEN - 1 && "cur_len out of range");
      argv[cur_argv_idx][cur_len++] = cmd[cmd_idx++];
    }
  }
  if (cur_len > 0) {
    argv[cur_argv_idx][cur_len] = '\0';
    cur_argv_idx++;
  }
  return cur_argv_idx;
}

static void sh_handle_cmd(const char *cmd) {
  char buf[ARGMAX][ARGLEN];
  char *argv[ARGMAX + 1];
  int n = sh_tokenize(cmd, buf);
  
  for (int i = 0; i < n; i++) argv[i] = buf[i];
  argv[n] = NULL;
  
  if (execve(argv[0], argv, NULL) == -1) {
    sh_printf("invalid cmd %s\n", cmd);
  }
}

void builtin_sh_run() {
  sh_banner();
  sh_prompt();

  while (1) {
    SDL_Event ev;
    if (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_KEYUP || ev.type == SDL_KEYDOWN) {
        const char *res = term->keypress(handle_key(&ev));
        if (res) {
          sh_handle_cmd(res);
          sh_prompt();
        }
      }
    }
    refresh_terminal();
  }
}
