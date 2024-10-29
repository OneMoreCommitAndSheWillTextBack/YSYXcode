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
    {"q", "Exit NPC", cmd_q},

    /* TODO: Add more commands */
    {"si", "run the program N steps, default is 1", cmd_si},
    // {"info", "r:print reg  w:print watchpoint", cmd_info},
    // {"x", "scan the memory", cmd_x},
    // {"p", "evaluate the expr", cmd_p},
    // {"b", "create a watchpoint", cmd_b},
    // {"d", "delete a watchpoint", cmd_d},
};

#define NR_CMD sizeof(cmd_table) / sizeof(cmd_table[0])

void sdb_main() {
  for (char *str; (str = rl_gets()) != NULL;) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}
