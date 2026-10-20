/*
 * restorer - rebuild a checkpointed architectural state on a freshly reset core.
 *
 * It is entered by the 8-byte trampoline that pack writes at the memory base,
 * runs in M mode with the MMU off, and never returns: it finishes with mret,
 * which lands on the checkpoint's PC with the checkpoint's privilege.
 *
 * Reserved page layout (see pack_restore.h):
 *   0x000  this program
 *   0x7F8  8 bytes: the original content of the memory base
 *   0x800  state table
 *
 * The program is position independent: it derives the page base from its own
 * PC, and it addresses the state table by re-materialising that base into t6
 * whenever it needs it. That matters because every general-purpose register
 * eventually has to hold a guest value, so none of them can be reserved as a
 * long-lived pointer.
 *
 * Only the CLINT addresses below are platform constants.
 */
    .set CLINT_MTIMECMP, 0x02004000
    .set CLINT_MTIME,    0x0200BFF8
    .set UART_TX,        0xa00003f8

/* The base register holds the table base, so these are plain struct offsets
 * from npc_state_table_t. The bytes the trampoline displaced sit just below. */
    .set PAGE_OFF_TABLE, 0x800
    .set T_PATCH_SAVE,  -8

    .set T_MAGIC,      0x00
    .set T_PATCH_ADDR, 0x08
    .set T_RESUME_PC,  0x0c
    .set T_PRIV,       0x10
    .set T_FLAGS,      0x14
    .set T_CSR,        0x18
    .set T_GPR,        0x60
    .set T_MTIME,      0xe0
    .set T_MTIMECMP,   0xe8
    .set T_MAGIC_VAL,  0x5243504e      /* 'N','P','C','R' */

/* CSR slots, in npc_csr_list.h order */
    .set C_SATP,       T_CSR + 4 * 0
    .set C_MSTATUS,    T_CSR + 4 * 1
    .set C_MSTATUSH,   T_CSR + 4 * 2
    .set C_MIE,        T_CSR + 4 * 3
    .set C_MTVEC,      T_CSR + 4 * 4
    .set C_MSCRATCH,   T_CSR + 4 * 5
    .set C_MEPC,       T_CSR + 4 * 6
    .set C_MCAUSE,     T_CSR + 4 * 7
    .set C_MTVAL,      T_CSR + 4 * 8
    .set C_MEDELEG,    T_CSR + 4 * 9
    .set C_MIDELEG,    T_CSR + 4 * 10
    .set C_MCOUNTEREN, T_CSR + 4 * 11
    .set C_SCOUNTEREN, T_CSR + 4 * 12
    .set C_STVEC,      T_CSR + 4 * 13
    .set C_SSCRATCH,   T_CSR + 4 * 14
    .set C_SEPC,       T_CSR + 4 * 15
    .set C_SCAUSE,     T_CSR + 4 * 16
    .set C_STVAL,      T_CSR + 4 * 17

    .set CSR_MSTATUS,   0x300
    .set CSR_MSTATUSH,  0x310
    .set CSR_MIE,       0x304
    .set CSR_MTVEC,     0x305
    .set CSR_MSCRATCH,  0x340
    .set CSR_MEPC,      0x341
    .set CSR_MCAUSE,    0x342
    .set CSR_MTVAL,     0x343
    .set CSR_MEDELEG,   0x302
    .set CSR_MIDELEG,   0x303
    .set CSR_MCOUNTEREN,0x306
    .set CSR_SCOUNTEREN,0x106
    .set CSR_STVEC,     0x105
    .set CSR_SSCRATCH,  0x140
    .set CSR_SEPC,      0x141
    .set CSR_SCAUSE,    0x142
    .set CSR_STVAL,     0x143
    .set CSR_SATP,      0x180

    .set MSTATUS_MPRV,  17             /* csrsi immediate for mstatus.MPRV */

/* Materialise the table base into \reg without borrowing another register. */
    .macro NPC_BASE reg
9:  auipc \reg, %pcrel_hi(npc_page_base + PAGE_OFF_TABLE)
    addi  \reg, \reg, %pcrel_lo(9b)
    .endm

    .section .text.start, "ax", @progbits
    .globl npc_page_base
npc_page_base:
    .globl _restorer_start
_restorer_start:
    NPC_BASE s0

    /* A wrong magic means the image and this program disagree about the page
     * layout; shout on the console rather than corrupting the guest. */
    lw      t0, T_MAGIC(s0)
    li      t1, T_MAGIC_VAL
    bne     t0, t1, npc_bad_table

    /* Put back the bytes the trampoline displaced. Nothing jumps there again
     * on our platform, but firmware entry points are not ours to keep. */
    lw      t2, T_PATCH_ADDR(s0)
    lw      t0, T_PATCH_SAVE + 0(s0)
    lw      t1, T_PATCH_SAVE + 4(s0)
    sw      t0, 0(t2)
    sw      t1, 4(t2)

    /* Timebase: mtimecmp first, so the restored mtime can never look already
     * expired and fire a tick before the window starts. */
    lw      t0, T_MTIMECMP + 0(s0)
    lw      t1, T_MTIMECMP + 4(s0)
    li      t2, CLINT_MTIMECMP
    sw      t0, 0(t2)
    sw      t1, 4(t2)
    lw      t0, T_MTIME + 0(s0)
    lw      t1, T_MTIME + 4(s0)
    li      t2, CLINT_MTIME
    sw      t0, 0(t2)
    sw      t1, 4(t2)

    /* Machine and supervisor CSRs. mstatus is deliberately not here: writing
     * it turns on MPRV, which would translate the loads further down. */
    lw      t0, C_MSTATUSH(s0)
    csrw    CSR_MSTATUSH, t0
    lw      t0, C_MIE(s0)
    csrw    CSR_MIE, t0
    lw      t0, C_MTVEC(s0)
    csrw    CSR_MTVEC, t0
    lw      t0, C_MSCRATCH(s0)
    csrw    CSR_MSCRATCH, t0
    lw      t0, C_MCAUSE(s0)
    csrw    CSR_MCAUSE, t0
    lw      t0, C_MTVAL(s0)
    csrw    CSR_MTVAL, t0
    lw      t0, C_MEDELEG(s0)
    csrw    CSR_MEDELEG, t0
    lw      t0, C_MIDELEG(s0)
    csrw    CSR_MIDELEG, t0
    lw      t0, C_MCOUNTEREN(s0)
    csrw    CSR_MCOUNTEREN, t0
    lw      t0, C_SCOUNTEREN(s0)
    csrw    CSR_SCOUNTEREN, t0
    lw      t0, C_STVEC(s0)
    csrw    CSR_STVEC, t0
    lw      t0, C_SSCRATCH(s0)
    csrw    CSR_SSCRATCH, t0
    lw      t0, C_SEPC(s0)
    csrw    CSR_SEPC, t0
    lw      t0, C_SCAUSE(s0)
    csrw    CSR_SCAUSE, t0
    lw      t0, C_STVAL(s0)
    csrw    CSR_STVAL, t0
    lw      t0, C_SATP(s0)
    csrw    CSR_SATP, t0
    sfence.vma

    /* General purpose registers: x1..x30 first, x31 last, because x31 (t6) is
     * the register this loop borrows as an address. */
    .irp idx, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30
    NPC_BASE t6
    lw      x\idx, T_GPR + 4 * \idx(t6)
    .endr

    /* mret needs mepc to be the checkpoint PC. The saved mepc CSR is dead state
     * at a checkpoint taken outside a trap, so it is overwritten here - the same
     * thing XiangShan's serializer does when it prepares a checkpoint. */
    NPC_BASE t6
    lw      t6, T_RESUME_PC(t6)
    csrw    CSR_MEPC, t6

    /* mstatus, prepared by the packer: MPP is the checkpoint's privilege, MPIE
     * carries its MIE, and MPRV is cleared so the remaining loads are physical.
     * mret restores MIE from MPIE, so the guest ends up with its own IE state. */
    NPC_BASE t6
    lw      t6, C_MSTATUS(t6)
    csrw    CSR_MSTATUS, t6

    NPC_BASE t6
    lw      t6, T_FLAGS(t6)
    andi    t6, t6, 1
    bnez    t6, npc_tail_mprv

    NPC_BASE t6
    lw      t6, T_GPR + 4 * 31(t6)
    mret

npc_tail_mprv:
    NPC_BASE t6
    lw      t6, T_GPR + 4 * 31(t6)
    csrsi   CSR_MSTATUS, MSTATUS_MPRV
    mret

    /* Loud failure: name it on the console, then take an illegal instruction
     * with mtvec still at its reset value. */
npc_bad_table:
    li      t0, UART_TX
    li      t1, 'B'
    sb      t1, 0(t0)
    li      t1, 'A'
    sb      t1, 0(t0)
    li      t1, 'D'
    sb      t1, 0(t0)
    li      t1, 'T'
    sb      t1, 0(t0)
    li      t1, 'B'
    sb      t1, 0(t0)
    li      t1, 'L'
    sb      t1, 0(t0)
    li      t1, '\n'
    sb      t1, 0(t0)
    .word   0

    .section .text.end, "a", @progbits
    .globl npc_restorer_end
npc_restorer_end:
