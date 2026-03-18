#include "cpu/cpu.h"
#include "isa.h"
#include <memory/paddr.h>
#include <common.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "sdb.h"

static bool dbg_is_on_ = false;
static int dbg_port = 0;
static int dbg_mode = INVALID;

void set_dbg_port(int port) {
    dbg_port = port;
    dbg_is_on_ = true;
}

int get_dbg_mode() {
    return dbg_mode;
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
    bool not_probe;
} dbg_command_t;

static bool cmd_set_mode(const char *args);

static const dbg_command_t dbg_cmd_table[] = {
    // execution control
    { "step", NULL, true},
    { "continue", NULL, true},
    // registers/memory
    { "read_reg", NULL, false},
    { "read_mem", false },
    { "write_mem", false }, // allow probe_only to change memory
    // state control
    { "is_over", NULL, false},
    { "quit", NULL, true},
    // mode
    { "set_mode", cmd_set_mode, false},
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

static void write_best_effort(int fd, const char *buf, size_t len) {
  while (len > 0) {
    ssize_t n = write(fd, buf, len);
    if (n < 0) {
      if (errno == EINTR) continue;
      return;
    }
    buf += (size_t)n;
    len -= (size_t)n;
  }
}

// ---- socket global state (minimal, single-connection) ----
static int dbg_server_fd = -1;
static int dbg_client_fd = -1;

static void dbg_socket_reset(void) {
  if (dbg_client_fd >= 0) {
    close(dbg_client_fd);
    dbg_client_fd = -1;
  }
  if (dbg_server_fd >= 0) {
    close(dbg_server_fd);
    dbg_server_fd = -1;
  }
}

// Initialize server socket and block until a client connects.
// On success: dbg_server_fd/dbg_client_fd are valid and ready for I/O.
// On failure: prints error and resets fds.
bool dbg_init_and_wait_connection(void) {
  if (!dbg_is_on()) return true;
  if (dbg_port <= 0) {
    printf("dbg-server: invalid dbg_port=%d\n", dbg_port);
    return false;
  }

  dbg_socket_reset();

  dbg_server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (dbg_server_fd < 0) {
    perror("dbg-server: socket");
    dbg_socket_reset();
    return false;
  }

  int yes = 1;
  if (setsockopt(dbg_server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
    perror("dbg-server: setsockopt(SO_REUSEADDR)");
    dbg_socket_reset();
    return false;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons((uint16_t)dbg_port);

  if (bind(dbg_server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("dbg-server: bind");
    dbg_socket_reset();
    return false;
  }
  if (listen(dbg_server_fd, 1) < 0) {
    perror("dbg-server: listen");
    dbg_socket_reset();
    return false;
  }

  struct sockaddr_in cli;
  socklen_t cli_len = sizeof(cli);
  printf("\033[34m[dbg] Waiting for the connection to port %d\033[0m\n", dbg_port);
  dbg_client_fd = accept(dbg_server_fd, (struct sockaddr *)&cli, &cli_len);
  if (dbg_client_fd < 0) {
    perror("dbg-server: accept");
    dbg_socket_reset();
    return false;
  }

  return true;
}

void dbg_listen(void) {
  if (!dbg_init_and_wait_connection()) return;

  // Read exactly one line
  char line[256];
  ssize_t n = read_line(dbg_client_fd, line, sizeof(line));
  if (n <= 0) {
    return;
  }

  // Parse "<cmd> <args>"
  char *save = NULL;
  char *cmd = strtok_r(line, " \t\r\n", &save);
  char *args = strtok_r(NULL, " \t\r\n", &save);

  if (cmd == NULL) {
    printf("dbg-server: empty command\n");
    return;
  }

  printf("get the cmd %s\n", cmd);
  if (dbg_mode == INVALID) {
    if (strcmp(cmd, "set_mode") != 0) {
      printf("dbg-server: mode invalid, only set_mode allowed as first command\n");
      return;
    }
  }

  // Dispatch to handler
  const dbg_command_t *ent = find_command(cmd);
  if (ent == NULL) {
    set_dbg_mode(INVALID);
    printf("dbg-server: unknown command '%s', mode set to INVALID\n", cmd);
    return;
  }
  bool ok = false;
  if (ent && ent->handler) {
    if (dbg_mode == PROBE_ONLY && ent->not_probe) {
      printf("dbg-server: command '%s' is forbidden in PROBE_ONLY mode\n", cmd);
      write_best_effort(dbg_client_fd, "ERR forbidden_in_probe_only\n",
                        strlen("ERR forbidden_in_probe_only\n"));
      return;
    }
    ok = ent->handler(args);
  }

  if (ok) {
    write_best_effort(dbg_client_fd, "OK\n", 3);
  } else {
    set_dbg_mode(INVALID);
    write_best_effort(dbg_client_fd, "ERR\n", 4);
  }

  return;
}
