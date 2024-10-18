#include "cpu/cpu.h"
#include "cpu/decode.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef CONFIG_FTRACE
void ftrace_init(char *elf_path) {
  FILE *fp = fopen(elf_path, "r");
  Elf32_Ehdr ehdr;
  Elf32_Shdr shdr;
  Elf32_Sym sym_sym;
  long pos = 0;
  char *content = NULL;
  char *checker = ".shstrtab";

  // find the pos of symble table
  fread(&ehdr, sizeof(ehdr), 1, fp);
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  size_t ehdr_num = ehdr.e_shnum;
  for (size_t i = 0; i < ehdr_num; i++) {
    fread(&shdr, sizeof(Elf32_Shdr), 1, fp);
    if (shdr.sh_type == SHT_SYMTAB) {
      pos = ftell(fp);
      fseek(fp, shdr.sh_offset, SEEK_SET);
      fread(&sym_sym, sizeof(Elf32_Sym), 1, fp);
      fseek(fp, pos, SEEK_SET);
    }
    if (shdr.sh_type == SHT_STRTAB && content == NULL) {
      pos = ftell(fp);
      fseek(fp, shdr.sh_offset, SEEK_SET);
      content = (char *)malloc(sizeof(char) * (shdr.sh_size) + 1);
      fread(content, shdr.sh_size, 1, fp);
      if (strcmp(content + shdr.sh_name, checker) == 0) {
        free(content);
        content = NULL;
      }
    }
  }

  // here the sym_sym is the symble section
  // and the content is the strtab
  //
  /* TODO:
      you should put the func name and addr into a linkedlist
      and init a function stack
*/
}

void dealftrace(Decode *s) {}

#endif
