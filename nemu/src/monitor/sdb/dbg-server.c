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
    uint32_t *dst = (uint32_t *)buf;
    for (size_t i = 0; i < n; i++) {
        word_t data = paddr_read(addr + i * len, (int)len);
        dst[i] = data;
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

void dbg_quit() {
    set_state_quit();
}

// socket
typedef bool (*dbg_cmd_handler_t)(char *args, char *reply);

typedef struct {
    const char *name;
    dbg_cmd_handler_t handler;
    bool not_probe;
} dbg_command_t;

static bool cmd_set_mode(char *args, char *reply);
static bool cmd_step(char *args, char *reply);
static bool cmd_is_over(char *args, char *reply);
static bool cmd_quit(char *args, char *reply);
static bool cmd_read_mem(char *args, char *reply);

static const dbg_command_t dbg_cmd_table[] = {
    // execution control
    { "step", cmd_step, true},
    { "continue", NULL, true},
    // registers/memory
    { "read_reg", NULL, false},
    { "read_mem", cmd_read_mem, false },
    { "write_mem", NULL, false }, // allow probe_only to change memory
    // state control
    { "is_over", cmd_is_over, false},
    { "quit", cmd_quit, true},
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

static bool cmd_set_mode(char *args, char *reply) {
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

static bool cmd_step(char *args, char *reply) {
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

static bool cmd_is_over(char *args, char *reply) {
    bool is_over = dbg_is_over();
    sprintf(reply, "OK:%s", is_over ? "true" : "false");
    return true;
}

static bool cmd_quit(char *args, char *reply) {
    dbg_quit();
    set_dbg_mode(DBG_QUIT);
    return true;
}

// read_mem 0x80000000 3 4 -> 从0x80000000 开始读3个四字节
// reply format "OK:[data1,data2,data3]"
static bool cmd_read_mem(char *args, char *reply) {
    char *save = NULL;
    char *str_addr = strtok_r(args, " ", &save);
    char *str_n = strtok_r( NULL, " ", &save);
    char *str_len = strtok_r(NULL, " ", &save);

    if(str_addr == NULL || str_n == NULL || str_len == NULL) {
        sprintf(reply, "ERR:arguments missing");
        return false;
    }

    char *endptr = NULL;
    uint32_t addr = (uint32_t)strtoul(str_addr, &endptr, 0);
    if(*endptr != '\0') {
        sprintf(reply, "ERR:invalid address format");
        return false;
    }

    int n = (int)strtol(str_n, &endptr, 10);
    if (*endptr != '\0' || n <= 0) {
        sprintf(reply, "ERR:invalid count (must be positive integer)");
        return false;
    }

    int len = (int)strtol(str_len, &endptr, 10);
    if (*endptr != '\0' || (len != 1 && len != 2 && len != 4)) {
        sprintf(reply, "ERR:invalid length (must be 1, 2, or 4)");
        return false;
    }


    uint32_t *buffer = (uint32_t*)malloc(n * sizeof(uint32_t));
    dbg_read_mem(addr, (void *)buffer, n, len);

    char *p = reply;
    p += sprintf(p, "OK:[");
    
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            p += sprintf(p, ",");
        }
        
        if (len == 4) {
            p += sprintf(p, "0x%08x", buffer[i]);
        } else if (len == 2) {
            p += sprintf(p, "0x%04x", (uint16_t)buffer[i]);
        } else { // len == 1
            p += sprintf(p, "0x%02x", (uint8_t)buffer[i]);
        }
    }
    
    sprintf(p, "]");

    printf("[dbg-server] reply = %s\n", reply);
    free(buffer);
    return true;
}   

// static bool cmd_write_mem(const char *args, char *reply) {

// }

// static bool cmd_write_reg(const char *args, char *reply) {

// }

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

