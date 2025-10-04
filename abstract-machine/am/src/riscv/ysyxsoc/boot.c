#include <am.h>

extern char _sdata_lma;
extern char _srodata_lma;
extern char _bss_lma;
extern char _stext_lma;

extern char _sdata_vma;
extern char _edata_vma;
extern char _srodata_vma;
extern char _erodata_vma;
extern char _sbss_vma;
extern char _ebss_vma;
extern char _stext_vma;
extern char _etext_vma;

// #ifdef __RTTHREAD__

// DECLARE_WEAK_SYMBOL(char, __fsymtab_start)
// DECLARE_WEAK_SYMBOL(char, __fsymtab_end)
// DECLARE_WEAK_SYMBOL(char, __vsymtab_start)
// DECLARE_WEAK_SYMBOL(char, __vsymtab_end)
// DECLARE_WEAK_SYMBOL(char, __rt_init_start)
// DECLARE_WEAK_SYMBOL(char, __rt_init_end)
// DECLARE_WEAK_SYMBOL(char, __rt_utest_tc_tab_start)
// DECLARE_WEAK_SYMBOL(char, __rt_utest_tc_tab_end)
// DECLARE_WEAK_SYMBOL(char, __am_apps_data_start)
// DECLARE_WEAK_SYMBOL(char, __am_apps_data_end)
DECLARE_WEAK_SYMBOL(char, __am_apps_bss_start)
DECLARE_WEAK_SYMBOL(char, __am_apps_bss_end)

DECLARE_WEAK_SYMBOL(char, _sdata_extra_vma)
DECLARE_WEAK_SYMBOL(char, _edata_extra_vma)
DECLARE_WEAK_SYMBOL(char, _data_extra_lma)

__attribute__((section(".bootloader")))
void extra_lode() {
    char *lma_start = _data_extra_lma;
    
    /* 加载finsh符号表 */
    COPY_OPTIONAL_SECTION(lma_start, _sdata_extra_vma, _edata_extra_vma, char, "FSymTab");
    
    if (CHECK_SECTION_EXISTS(__am_apps_bss_start, __am_apps_bss_end)) {
        CLEAR_BSS(__am_apps_bss_start, __am_apps_bss_end);
    }
}
// #else 
// __attribute__((section(".bootloader")))
// void extra_lode() {}
// #endif


__attribute__((section(".bootloader")))
void loader_init() {
    COPY_SECTION(_sdata_lma, _sdata_vma, _edata_vma, int);
    COPY_SECTION(_srodata_lma, _srodata_vma, _erodata_vma, int);
    CLEAR_BSS(_sbss_vma, _ebss_vma);
    COPY_SECTION(_stext_lma, _stext_vma, _etext_vma, char);

    extra_lode();
}