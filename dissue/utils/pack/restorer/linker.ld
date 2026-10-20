/* The restorer is position independent, so it links at offset 0 and the flat
 * binary it produces is a byte-for-byte image of the reserved page start.
 * The explicit PHDRS block is what keeps ld from complaining about a program
 * header segment that no load segment covers. */
OUTPUT_ARCH(riscv)
ENTRY(_restorer_start)

PHDRS {
  text PT_LOAD FLAGS(5);
}

SECTIONS
{
  . = 0;

  .text : {
    KEEP(*(.text.start))
    *(.text*)
  } : text

  .rodata : ALIGN(4) {
    *(.srodata*)
    *(.rodata*)
  } : text

  .data : ALIGN(4) {
    *(.sdata*)
    *(.data*)
  } : text

  .bss (NOLOAD) : ALIGN(4) {
    *(.sbss*)
    *(.bss*)
    *(COMMON)
  } : text

  /DISCARD/ : {
    *(.comment)
    *(.note*)
    *(.eh_frame*)
    *(.riscv.attributes)
  }
}
