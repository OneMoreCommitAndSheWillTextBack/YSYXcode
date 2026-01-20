#include <proc.h>
#include <elf.h>
#include "common.h"
#include "debug.h"

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

static uintptr_t loader(PCB *pcb, const char *filename) {
  Elf32_Ehdr ehdr;
  size_t size = ramdisk_read(&ehdr, 0, sizeof(Elf32_Ehdr));
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

  for(int i=0;i<e_phnum;i++) {
    uint32_t offset = i * sizeof(Elf32_Phdr);
    size = ramdisk_read(&phdr, e_phoff + offset, sizeof(Elf32_Phdr));
    if(size != sizeof(Elf32_Phdr)) {
      panic("loader read size not equ to size of phdr");
    }

    if((phdr.p_type | PT_LOAD)) {
      size_t filesize = phdr.p_filesz;
      size_t memsize = phdr.p_memsz;
      uint32_t vaddr = phdr.p_vaddr;
      
      Log("Loading segment: vaddr = 0x%x, p_offset = 0x%x, filesz = 0x%x, memsz = 0x%x", 
          phdr.p_vaddr, phdr.p_offset, phdr.p_filesz, phdr.p_memsz);

      ramdisk_read((char *)vaddr, phdr.p_offset, filesize);
      assert(memsize >= filesize);
      memset((char *)(vaddr + filesize), 0, memsize - filesize);
    }
  }

  return e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

