OUTPUT_ARCH(riscv)
ENTRY(_start)

PHDRS {
  text PT_LOAD FLAGS(5);
  data PT_LOAD FLAGS(6);
}

MEMORY {
  ram (rwx) : ORIGIN = 0x80000000, LENGTH = 128M
}

SECTIONS {
  . = ORIGIN(ram);

  .text : {
    KEEP(*(.text.start))
    *(.text*)
  } > ram : text

  .rodata : ALIGN(4) {
    *(.srodata*)
    *(.rodata*)
  } > ram : text

  .data : ALIGN(4) {
    *(.sdata*)
    *(.data*)
  } > ram : data

  .bss (NOLOAD) : ALIGN(4) {
    __bss_start = .;
    *(.sbss*)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    __bss_end = .;
  } > ram : data

  PROVIDE(_stack_top = ORIGIN(ram) + LENGTH(ram));

  /DISCARD/ : {
    *(.comment)
    *(.note*)
    *(.eh_frame*)
  }
}
