MEMORY {
    MROM (rx) : ORIGIN = 0x20000000, LENGTH = 4K
    FLASH (rx) : ORIGIN = 0x30000000, LENGTH = 32M
    SRAM (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
    PSRAM (rwx) : ORIGIN = 0x80000000, LENGTH = 4M
}

SECTIONS {
    . = _pmem_start + _entry_offset;
    .text : {
        *(entry)
        *(.text*)
    } > FLASH

    .data : ALIGN(4) {
        . = ALIGN(4);
        _sdata_vma = .;         
        *(.data.*)
        *(.sdata.*)
        . = ALIGN(4);
    } > PSRAM AT> FLASH
    _edata_vma = .;     
    _sdata_lma = LOADADDR(.data); 

    .rodata : ALIGN(4) {
        _srodata_vma = .;
        *(.rodata*)
        *(.srodata*)
        _erodata_vma = .;
    } > SRAM AT> FLASH
    _srodata_lma = LOADADDR(.rodata);

    .bss : ALIGN(4) {
        . = ALIGN(4);
        _sbss_vma = .;
        *(.bss.*)
        *(.sbss*)
        *(.scommon*)
        *(COMMON)
        . = ALIGN(4);
        _ebss_vma = .;
    } > SRAM

    _stack_pointer = 0x0f001000;
    . = _stack_pointer + 0x8000;
    _heap_start = 0x80000000;
}