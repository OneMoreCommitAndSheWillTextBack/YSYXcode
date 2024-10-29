#include "common.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

static char *rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

int cmd_help();
int cmd_c();
int cmd_q();
int cmd_si();
int cmd_info();
int cmd_x();
int cmd_b();
int cmd_d();

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},

    /* TODO: Add more commands */
    {"si", "run the program N steps, default is 1", cmd_si},
    {"info", "r:print reg  w:print watchpoint", cmd_info},
    {"x", "scan the memory", cmd_x},
    // {"p", "evaluate the expr", cmd_p},
    {"b", "create a watchpoint", cmd_b},
    {"d", "delete a watchpoint", cmd_d}};

int sdb_main() {
  while () {
  }
}
