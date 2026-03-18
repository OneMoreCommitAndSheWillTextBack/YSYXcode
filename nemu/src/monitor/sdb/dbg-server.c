#include "cpu/cpu.h"
#include "isa.h"
#include <memory/paddr.h>
#include <common.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#include "sdb.h"

typedef enum {
    INVALID,
    AUTOMATIC,
    PROBE_ONLY
} dbg_mode_t;

static bool dbg_is_on_ = false;
static int dbg_port = 0;
static int dbg_mode = INVALID;

void set_dbg_port(int port) {
    dbg_port = port;
    dbg_is_on_ = true;
}

bool dbg_is_on() { 
    return dbg_is_on_;
}

// dbg command
void dbg_step(int n) {
    cpu_exec(n);
}

void dbg_continue() {
    cpu_exec(-1);
}

void dbg_read_reg(const char *regname, bool *success, word_t *result) {
    *result = isa_reg_str2val(regname, success);
}

void dbg_read_mem(paddr_t addr, void *buf, size_t n, size_t len) {
    uint8_t *dst = (uint8_t *)buf;
    for (size_t i = 0; i < n; i++) {
        word_t data = paddr_read(addr + i * len, (int)len);
        memcpy(dst + i * len, &data, len);
    }
}

void dbg_write_mem(paddr_t addr, void *buf, size_t n, size_t len) {
    uint8_t *src = (uint8_t *)buf;
    for (size_t i = 0; i < n; i++) {
        word_t data = 0;
        memcpy(&data, src + i * len, len);
        paddr_write(addr + i * len, (int)len, data);
    }
}

void dbg_is_over(bool *result) {
    int state = get_nemu_state();
    *result = (state == NEMU_END || state == NEMU_ABORT);
}

void dbg_quit(bool *result) {
    set_state_quit();
    *result = true;
}

void set_dbg_mode(dbg_mode_t mode) {
    dbg_mode = mode;
}

// socket
typedef bool (*dbg_cmd_handler_t)(const char *args);

typedef struct {
    const char *name;
    dbg_cmd_handler_t handler;
} dbg_command_t;

static bool cmd_set_mode(const char *args);

static const dbg_command_t dbg_cmd_table[] = {
    { "set_mode", cmd_set_mode },
};

static const size_t dbg_cmd_table_size = sizeof(dbg_cmd_table) / sizeof(dbg_cmd_table[0]);

static const dbg_command_t *find_command(const char *name) {
    for (size_t i = 0; i < dbg_cmd_table_size; i++) {
        if (strcmp(name, dbg_cmd_table[i].name) == 0) {
            return &dbg_cmd_table[i];
        }
    }
    return NULL;
}

static bool cmd_set_mode(const char *args) {
    if(args == NULL) {
        printf("the mode cannot be null, dbg-server quit\n");
        dbg_mode = INVALID;
        return false;
    }

    if (strcmp(args, "probe") == 0) {
        dbg_mode = PROBE_ONLY;
    } else if(strcmp(args, "auto") == 0) {
        dbg_mode = AUTOMATIC;
    } else {
        printf("invlaid mode %s, dbg-server quit\n", args);
        dbg_mode = INVALID;
        return false;
    }
    set_dbg_mode(dbg_mode);
    return true;
}

#include <errno.h>
static ssize_t read_line(int fd, char *buf, size_t cap) {
  if (cap == 0) return -1;
  size_t i = 0;
  while (i + 1 < cap) {
    char c = 0;
    ssize_t n = read(fd, &c, 1);
    if (n == 0) break;           // EOF
    if (n < 0) {
      if (errno == EINTR) continue;
      return -1;
    }
    buf[i++] = c;
    if (c == '\n') break;
  }
  buf[i] = '\0';
  return (ssize_t)i;
}

void dbg_listen(void) {
  if (!dbg_is_on()) return;
  if (dbg_port <= 0) {
    printf("dbg-server: invalid dbg_port=%d\n", dbg_port);
    return;
  }

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("dbg-server: socket");
    return;
  }

  int yes = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
    perror("dbg-server: setsockopt(SO_REUSEADDR)");
    close(server_fd);
    return;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons((uint16_t)dbg_port);

  if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("dbg-server: bind");
    close(server_fd);
    return;
  }
  if (listen(server_fd, 1) < 0) {
    perror("dbg-server: listen");
    close(server_fd);
    return;
  }

  // Block until one client connects
  struct sockaddr_in cli;
  socklen_t cli_len = sizeof(cli);
  int client_fd = accept(server_fd, (struct sockaddr *)&cli, &cli_len);
  if (client_fd < 0) {
    perror("dbg-server: accept");
    close(server_fd);
    return;
  }

  // Read exactly one line
  char line[256];
  ssize_t n = read_line(client_fd, line, sizeof(line));
  if (n <= 0) {
    // client closed or read error; just return
    close(client_fd);
    close(server_fd);
    return;
  }

  // Parse "<cmd> <args>"
  char *save = NULL;
  char *cmd = strtok_r(line, " \t\r\n", &save);
  char *args = strtok_r(NULL, " \t\r\n", &save);

  if (cmd == NULL) {
    printf("dbg-server: empty command\n");
    close(client_fd);
    close(server_fd);
    return;
  }

  if (strcmp(cmd, "set_mode") != 0) {
    printf("dbg-server: first command must be set_mode, got '%s'\n", cmd);
    close(client_fd);
    close(server_fd);
    return;
  }

  // Dispatch to handler
  const dbg_command_t *ent = find_command(cmd);
  bool ok = false;
  if (ent && ent->handler) {
    ok = ent->handler(args);
  }

  if (!ok) {
    // handler failed; just return
    close(client_fd);
    close(server_fd);
    return;
  }

  printf("test success\n");
  close(client_fd);
  close(server_fd);
  return;
}

void dbg_main() {
    dbg_listen();
}
