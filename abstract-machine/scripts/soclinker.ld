MEMORY {
    MROM (rx) : ORIGIN = 0x20000000, LENGTH = 64K
    RAM (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
}

SECTIONS {
    . = _pmem_start + _entry_offset;
    .text : {
        *(entry)
        *(.text*)
    } > MROM
    _stack_pointer = _pmem_start;
}