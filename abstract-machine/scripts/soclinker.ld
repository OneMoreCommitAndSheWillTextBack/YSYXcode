MEMORY {
    MROM (rx) : ORIGIN = 0x20000000, LENGTH = 4K
    FLASH (rwx) : ORIGIN = 0x30000000, LENGTH = 32M
    SRAM (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
    PSRAM (rwx) : ORIGIN = 0x80000000, LENGTH = 4M
}

SECTIONS {
    . = _pmem_start + _entry_offset;
    .boot : {
        *(entry)         
        *(.stage1*) 
    } > FLASH

    .stage2 : {
        . = ALIGN(4);
        _sstage2_vma = .;
        *(.stage2*);
        _estage2_vma = .;
    } > PSRAM AT > FLASH
    _sstage2_lma = LOADADDR(.stage2);

    .text : {
        _stext_vma = .;
        *(.text*)
    } > PSRAM AT > FLASH
    _etext_vma =.;
    _stext_lma = LOADADDR(.text);

    .data : ALIGN(4) {
        . = ALIGN(4);
        _sdata_vma = .;         
        *(.data*)
        *(.sdata.*)
        *(.data.extra)
        . = ALIGN(4);
    } > PSRAM AT> FLASH
    _edata_vma = .;     
    _sdata_lma = LOADADDR(.data); 

    .rodata : ALIGN(4) {
        _srodata_vma = .;
        *(.rodata*)
        *(.srodata*)
        _erodata_vma = .;
    } > PSRAM AT> FLASH
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
    } > PSRAM

    _stack_pointer = 0x0f002000;
    _heap_start = _ebss_vma;
}