#include <proc.h>
#include <elf.h>
#include <stdio.h>
#include "common.h"
#include "debug.h"
#include "fs.h"

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

static uintptr_t loader(PCB *pcb, const char *filename) {
  int fd = fs_open(filename, 0, 0);

  Elf32_Ehdr ehdr;
  size_t size = fs_read(fd, &ehdr, sizeof(Elf32_Ehdr));
  if(size < sizeof(Elf32_Ehdr)) {
    panic("loader read szie not equ to size of ehdr");
  }

  // Check ELF magic number: 0x7f 'E' 'L' 'F'
  if(ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || 
     ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F' || 
     ehdr.e_type != ET_EXEC) {
    panic("the file format isnot elf execuable file");
  }

  Elf32_Phdr phdr;
  uint32_t e_phoff = ehdr.e_phoff;
  uint32_t e_phnum = ehdr.e_phnum;
  uint32_t e_entry = ehdr.e_entry;

  Log("ELF header: e_phoff = 0x%x, e_phnum = %d, e_entry = 0x%x", e_phoff, e_phnum, e_entry);

  for(int i=0;i<e_phnum;i++) {
    uint32_t offset = i * sizeof(Elf32_Phdr);
    size = fs_lseek(fd, e_phoff + offset, SEEK_SET);
    size = fs_read(fd, &phdr, sizeof(Elf32_Phdr));
    if(size != sizeof(Elf32_Phdr)) {
      panic("loader read size not equ to size of phdr");
    }

    if(phdr.p_type == PT_LOAD) {
      size_t filesize = phdr.p_filesz;
      size_t memsize = phdr.p_memsz;
      uint32_t paddr = phdr.p_paddr;

      Log("Loading segment: p_type = 0x%x, p_offset = 0x%x, p_vaddr = 0x%x, p_paddr = 0x%x, p_filesz = 0x%x, p_memsz = 0x%x, p_flags = 0x%x", 
          phdr.p_type, phdr.p_offset, phdr.p_vaddr, phdr.p_paddr, phdr.p_filesz, phdr.p_memsz, phdr.p_flags);
      
      size = fs_lseek(fd, phdr.p_offset, SEEK_SET);
      size = fs_read(fd, (char *)paddr, filesize);
      assert(size == filesize);
      assert(memsize >= filesize);
      memset((char *)(paddr + filesize), 0, memsize - filesize);
    }
  }

  return e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %d", entry);
  ((void(*)())entry) ();
}

