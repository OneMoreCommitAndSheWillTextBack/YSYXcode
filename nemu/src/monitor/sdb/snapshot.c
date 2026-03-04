#include "isa.h"
#include "stdio.h"
#include "memory/paddr.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "sdb.h"

const char* default_file_name = "nemu-snapshot";

static char *get_fin_filename(const char *filename) {
    if (filename == NULL || *filename == '\0') {
        char *buf = malloc(strlen(default_file_name) + 4);
        return buf ? sprintf(buf, "./%s", default_file_name), buf : NULL;
    }

    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("stat");
        return NULL;
    }

    if (S_ISDIR(st.st_mode)) {
        size_t n = strlen(filename) + strlen(default_file_name) + 3;
        char *buf = malloc(n);
        return buf && snprintf(buf, n, "%s/%s", filename, default_file_name) > 0
               ? buf : (free(buf), NULL);
    }
    if (S_ISREG(st.st_mode)) {
        return strdup(filename);
    }

    fprintf(stderr, "[Error] %s: neither file nor directory\n", filename);
    return NULL;
}

int snap_store(const char *filename) {
    char *final_name = get_fin_filename(filename);
    if(final_name == NULL) {
        printf("[Error] snap store cannot get the final name\n");
        return 1;
    }
    printf("Snapshot file name: %s\n", final_name);

    FILE *fd = fopen(final_name, "wb");
    if(fd == NULL) {
        printf("[Error] snapshot cannot open file %s\n", final_name);
        return 1;
    }

    if (fwrite(&cpu, sizeof(CPU_state), 1, fd) != 1) {
        printf("[Error] snapshot: failed to write CPU state\n");
        fclose(fd);
        free(final_name);
        return 1;
    }

    if (fwrite(guest_to_host(RESET_VECTOR), 1, CONFIG_MSIZE, fd) != CONFIG_MSIZE) {
        printf("[Error] snapshot: failed to write memory\n");
        fclose(fd);
        free(final_name);
        return 1;
    }

    fclose(fd);
    free(final_name);
    return 0;
}

int snap_load(const char *filename) {
    char *final_name = get_fin_filename(filename);
    if(filename == NULL) {
        printf("[Error] snap load cannot get the final name\n");
        return 1;
    }

    FILE *fd = fopen(final_name, "rb");
    if (fd == NULL) {
        fprintf(stderr, "[Error] snap_load: cannot open file %s\n", final_name);
        free(final_name);
        return 1;
    }

    /* 1. 读入 CPU 状态 */
    if (fread(&cpu, sizeof(CPU_state), 1, fd) != 1) {
        printf("[Error] snap_load: failed to read CPU state\n");
        fclose(fd);
        free(final_name);
        return 1;
    }

    /* 2. 读入内存 */
    if (fread(guest_to_host(CONFIG_MBASE), 1, CONFIG_MSIZE, fd) != CONFIG_MSIZE) {
        printf("[Error] snap_load: failed to read memory\n");
        fclose(fd);
        free(final_name);
        return 1;
    }

    fclose(fd);
    free(final_name);
    return 0;
}