#include "cpu/cpu.h"
#include "isa.h"
#include <memory/paddr.h>
#include <common.h>
#include <unistd.h>
#include <string.h>

#include "sdb.h"



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

bool dbg_is_over() {
    int state = get_nemu_state();
    return (state == NEMU_END || state == NEMU_ABORT);
}

void dbg_quit(bool *result) {
    set_state_quit();
    *result = true;
}

// socket
typedef bool (*dbg_cmd_handler_t)(const char *args, char *reply);

typedef struct {
    const char *name;
    dbg_cmd_handler_t handler;
    bool not_probe;
} dbg_command_t;

static bool cmd_set_mode(const char *args, char *reply);
static bool cmd_step(const char *args, char *reply);
static bool cmd_is_over(const char *args, char *reply);

static const dbg_command_t dbg_cmd_table[] = {
    // execution control
    { "step", cmd_step, true},
    { "continue", NULL, true},
    // registers/memory
    { "read_reg", NULL, false},
    { "read_mem", false },
    { "write_mem", false }, // allow probe_only to change memory
    // state control
    { "is_over", cmd_is_over, false},
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

static bool cmd_set_mode(const char *args, char *reply) {
    dbg_mode_t dbg_mode = get_dbg_mode();
    if(args == NULL) {
        sprintf(reply, "ERR:the mode cannot be null");
        dbg_mode = INVALID;
        return false;
    }

    if (strcmp(args, "probe") == 0) {
        dbg_mode = PROBE_ONLY;
    } else if(strcmp(args, "auto") == 0) {
        dbg_mode = AUTOMATIC;
    } else {
        sprintf(reply, "ERR:invalid mode %s", args);
        dbg_mode = INVALID;
        return false;
    }
    set_dbg_mode(dbg_mode);
    sprintf(reply, "OK:mode set to %s", args);
    return true;
}

static bool cmd_step(const char *args, char *reply) {
    if (args == NULL || args[0] == '\0') {
        sprintf(reply, "ERR:step count cannot be empty");
        return false;
    }
    
    int n = atoi(args);
    if (n <= 0) {
        sprintf(reply, "ERR:step count must be positive");
        return false;
    }
    
    dbg_step(n);
    sprintf(reply, "OK:stepped %d", n);
    return true;
}

static bool cmd_is_over(const char *args, char *reply) {
    bool is_over = dbg_is_over();
    sprintf(reply, "OK:%s", is_over ? "true" : "false");
    return true;
}

bool dbg_process_one_command(char *cmd_line, char *replay, size_t replay_size) {
    dbg_mode_t dbg_mode = get_dbg_mode();
  
    if (cmd_line == NULL || strlen(cmd_line) == 0) {
        snprintf(replay, replay_size, "ERR empty_command\n");
        printf("dbg-server: empty command\n");
        return false;
    }

    // Parse "<cmd> <args>" directly from cmd_line (modified in place)
    char *save = NULL;
    char *cmd = strtok_r(cmd_line, " \t\r\n", &save);
    char *args = strtok_r(NULL, " \t\r\n", &save);

    if (cmd == NULL) {
        snprintf(replay, replay_size, "ERR empty_command\n");
        printf("dbg-server: empty command after parsing\n");
        return false;
    }

    printf("get the cmd %s\n", cmd);
    
    // Check mode validity
    if (dbg_mode == INVALID) {
        if (strcmp(cmd, "set_mode") != 0) {
        printf("dbg-server: mode invalid, only set_mode allowed as first command\n");
        snprintf(replay, replay_size, "ERR mode_invalid\n");
        return false;
        }
    }

    // Dispatch to handler
    const dbg_command_t *ent = find_command(cmd);
    if (ent == NULL) {
        set_dbg_mode(INVALID);
        printf("dbg-server: unknown command '%s', mode set to INVALID\n", cmd);
        snprintf(replay, replay_size, "ERR unknown_command\n");
        return false;
    }
    
    if (ent && ent->handler) {
        if (dbg_mode == PROBE_ONLY && ent->not_probe) {
            printf("dbg-server: command '%s' is forbidden in PROBE_ONLY mode\n", cmd);
            snprintf(replay, replay_size, "ERR forbidden_in_probe_only\n");
            return false;
        }
        
        ent->handler(args, replay);
    } else {
        snprintf(replay, replay_size, "ERR no_handler\n");
        return false;
    }

    return true;
}

