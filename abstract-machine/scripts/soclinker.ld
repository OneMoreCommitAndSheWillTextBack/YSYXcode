/* 定义MROM起始地址 */
MEMORY {
    MROM (rx) : ORIGIN = 0x20000000, LENGTH = 64K
    RAM (rwx) : ORIGIN = 0x0f000000, LENGTH = 8K
}

/* 指定入口点为_start */
ENTRY(_start)

SECTIONS {
    . = _pmem_start + _entry_offset;
    .text : {
        *(.text.init)      /* 包含启动代码 */
        *(.text*)          /* 其他代码段 */
    } > MROM
    _stack_pointer = .;
}