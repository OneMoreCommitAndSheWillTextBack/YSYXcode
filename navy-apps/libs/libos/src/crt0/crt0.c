#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define MAXARG 32
#define MAXENVP 32

int main(int argc, char *argv[], char *envp[]);
extern char **environ;
void call_main(uintptr_t *args) {
  char *argv[MAXARG];
  char *envp[MAXENVP];
  int argc = *(uint32_t *)args;

  char **ptr_array = (char **)(args + 1);
  int argv_count = 0;
  while (*ptr_array != NULL && argv_count < MAXARG) {
    argv[argv_count++] = *ptr_array++;
  }
  argv[argv_count] = NULL;  
  ptr_array++;              

  int envp_count = 0;
  while (*ptr_array != NULL && envp_count < MAXENVP) {
    envp[envp_count++] = *ptr_array++;
  }
  assert(envp_count != 0);
  envp[envp_count] = NULL;  

  environ = envp;
  exit(main(argc, argv, envp));
  assert(0);
}
