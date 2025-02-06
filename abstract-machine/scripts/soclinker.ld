MEMORY {
    MROM (rx) : ORIGIN = 0x20000000, LENGTH = 4K
    SRAM (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
    . = _pmem_start + _entry_offset;
    .text : {
        *(entry)
        *(.text*)
    } > MROM

    .data : {
        . = ALIGN(4);
        _sdata_vma = .;         
        *(.data .data.*)
        . = ALIGN(4);
        _edata_vma = .;
    } > SRAM AT> MROM           
    _sdata_lma = LOADADDR(.data); 

    .bss : {
        . = ALIGN(4);
        _sbss_vma = .;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss_vma = .;
    } > SRAM

    _stack_pointer = 0x0f001000;
    . = _stack_pointer + 0x8000;
    _heap_start = 0x0f000000;
}