#include "riscv-test.h"

.option arch, +zicsr

.equ CASE_M_ECALL, 1
.equ CASE_S_ECALL_M, 2
.equ CASE_U_ECALL_M, 3
.equ CASE_S_ECALL_S, 4
.equ CASE_S_ILLEGAL_CSR, 5
.equ CASE_U_ECALL_S, 6
.equ CASE_U_ILLEGAL_CSR, 7
.equ CASE_M_SRET_TO_S, 8
.equ CASE_S_MRET_ILLEGAL, 9
.equ CASE_S_CYCLE_ILLEGAL, 10
.equ CASE_S_CYCLE_ALLOWED, 11
.equ CASE_U_CYCLE_ILLEGAL, 12
.equ CASE_U_CYCLE_ALLOWED, 13

.equ PRV_U, 0
.equ PRV_S, 1
.equ PRV_M, 3

.macro FAIL code
  li a0, \code
  ret
.endm

.macro CHECK_IMM reg, imm, code
  li t6, \imm
  beq \reg, t6, 1f
  FAIL \code
1:
.endm

.macro CHECK_ZERO reg, code
  beqz \reg, 1f
  FAIL \code
1:
.endm

.macro CHECK_LABEL reg, label, code
  la t6, \label
  beq \reg, t6, 1f
  FAIL \code
1:
.endm

.macro SET_CASE id
  la t0, case_id
  li t1, \id
  sw t1, 0(t0)
.endm

.macro SET_MPP mode
  csrr t5, mstatus
  li t6, 0x1800
  not t6, t6
  and t5, t5, t6
  li t6, ((\mode) << 11)
  or t5, t5, t6
  csrw mstatus, t5
.endm

.macro SET_SPP_S
  csrr t5, mstatus
  li t6, 0x100
  or t5, t5, t6
  csrw mstatus, t5
.endm

.macro ENTER_PRIV label, mode
  la t0, \label
  csrw mepc, t0
  SET_MPP \mode
  mret
.endm

.macro RETURN_M label
  la t0, \label
  csrw mepc, t0
  SET_MPP PRV_M
  mret
.endm

.macro ADVANCE_MRET
  csrr t0, mepc
  addi t0, t0, 4
  csrw mepc, t0
  mret
.endm

.section .text
.globl main
.type main, @function
main:
  la t0, m_trap_handler
  ori t0, t0, 1
  csrw mtvec, t0
  la t0, s_trap_handler
  ori t0, t0, 1
  csrw stvec, t0
  csrw medeleg, zero
  csrw mcounteren, zero
  csrw scounteren, zero

  li t0, 0x000c0122
  csrw sstatus, t0
  csrr t1, mstatus
  and t1, t1, t0
  CHECK_IMM t1, 0x000c0122, 20
  csrr t1, sstatus
  CHECK_IMM t1, 0x000c0122, 21
  csrw sstatus, zero

  li t0, 0x12345
  csrw satp, t0
  csrr t1, satp
  CHECK_IMM t1, 0x12345, 22
  csrw satp, zero

  SET_CASE CASE_M_ECALL
m_ecall_site:
  ecall
m_after_ecall:

  csrw medeleg, zero
  SET_CASE CASE_S_ECALL_M
  ENTER_PRIV s_ecall_m_site, PRV_S
s_ecall_m_site:
  ecall
s_after_ecall_m:

  csrw medeleg, zero
  SET_CASE CASE_U_ECALL_M
  ENTER_PRIV u_ecall_m_site, PRV_U
u_ecall_m_site:
  ecall
u_after_ecall_m:

  li t0, (1 << 9)
  csrw medeleg, t0
  SET_CASE CASE_S_ECALL_S
  ENTER_PRIV s_ecall_s_site, PRV_S
s_ecall_s_site:
  ecall
s_after_ecall_s:
  SET_CASE CASE_S_ILLEGAL_CSR
s_illegal_csr_site:
  csrr t0, mstatus
  FAIL 23
s_after_illegal_csr:

  li t0, (1 << 8)
  csrw medeleg, t0
  SET_CASE CASE_U_ECALL_S
  ENTER_PRIV u_ecall_s_site, PRV_U
u_ecall_s_site:
  ecall
u_after_ecall_s:
u_illegal_csr_site:
  csrr t0, sstatus
  FAIL 24
u_after_illegal_csr:

  csrw medeleg, zero
  SET_CASE CASE_M_SRET_TO_S
  la t0, m_sret_target_s
  csrw sepc, t0
  SET_SPP_S
  sret
m_sret_target_s:
  csrr t0, mstatus
  FAIL 25
m_after_sret_to_s:

  csrw medeleg, zero
  SET_CASE CASE_S_MRET_ILLEGAL
  ENTER_PRIV s_mret_illegal_site, PRV_S
s_mret_illegal_site:
  mret
  FAIL 26
s_after_mret_illegal:

  csrw medeleg, zero
  csrw mcounteren, zero
  csrw scounteren, zero
  SET_CASE CASE_S_CYCLE_ILLEGAL
  ENTER_PRIV s_cycle_illegal_site, PRV_S
s_cycle_illegal_site:
  csrr t0, cycle
  FAIL 27
s_after_cycle_illegal:

  li t0, 1
  csrw mcounteren, t0
  csrw scounteren, zero
  SET_CASE CASE_S_CYCLE_ALLOWED
  ENTER_PRIV s_cycle_allowed_site, PRV_S
s_cycle_allowed_site:
  csrr t0, cycle
s_cycle_allowed_ecall:
  ecall
s_after_cycle_allowed:

  li t0, 1
  csrw mcounteren, t0
  csrw scounteren, zero
  SET_CASE CASE_U_CYCLE_ILLEGAL
  ENTER_PRIV u_cycle_illegal_site, PRV_U
u_cycle_illegal_site:
  csrr t0, cycle
  FAIL 28
u_after_cycle_illegal:

  li t0, 1
  csrw mcounteren, t0
  csrw scounteren, t0
  SET_CASE CASE_U_CYCLE_ALLOWED
  ENTER_PRIV u_cycle_allowed_site, PRV_U
u_cycle_allowed_site:
  csrr t0, cycle
u_cycle_allowed_ecall:
  ecall
u_after_cycle_allowed:

  csrw mcounteren, zero
  csrw scounteren, zero
  TEST_PASS

.align 2
m_trap_handler:
  csrr t0, mcause
  la t1, case_id
  lw t1, 0(t1)

  li t2, CASE_M_ECALL
  beq t1, t2, m_case_m_ecall
  li t2, CASE_S_ECALL_M
  beq t1, t2, m_case_s_ecall_m
  li t2, CASE_U_ECALL_M
  beq t1, t2, m_case_u_ecall_m
  li t2, CASE_S_ILLEGAL_CSR
  beq t1, t2, m_case_s_illegal_csr
  li t2, CASE_U_ILLEGAL_CSR
  beq t1, t2, m_case_u_illegal_csr
  li t2, CASE_M_SRET_TO_S
  beq t1, t2, m_case_m_sret_to_s
  li t2, CASE_S_MRET_ILLEGAL
  beq t1, t2, m_case_s_mret_illegal
  li t2, CASE_S_CYCLE_ILLEGAL
  beq t1, t2, m_case_s_cycle_illegal
  li t2, CASE_S_CYCLE_ALLOWED
  beq t1, t2, m_case_s_cycle_allowed
  li t2, CASE_U_CYCLE_ILLEGAL
  beq t1, t2, m_case_u_cycle_illegal
  li t2, CASE_U_CYCLE_ALLOWED
  beq t1, t2, m_case_u_cycle_allowed
  FAIL 90

m_case_m_ecall:
  CHECK_IMM t0, 11, 30
  csrr t3, mepc
  CHECK_LABEL t3, m_ecall_site, 31
  csrr t3, mtval
  CHECK_ZERO t3, 32
  RETURN_M m_after_ecall

m_case_s_ecall_m:
  CHECK_IMM t0, 9, 33
  csrr t3, mepc
  CHECK_LABEL t3, s_ecall_m_site, 34
  csrr t3, mtval
  CHECK_ZERO t3, 35
  RETURN_M s_after_ecall_m

m_case_u_ecall_m:
  CHECK_IMM t0, 8, 36
  csrr t3, mepc
  CHECK_LABEL t3, u_ecall_m_site, 37
  csrr t3, mtval
  CHECK_ZERO t3, 38
  RETURN_M u_after_ecall_m

m_case_s_illegal_csr:
  CHECK_IMM t0, 2, 39
  csrr t3, mepc
  CHECK_LABEL t3, s_illegal_csr_site, 40
  RETURN_M s_after_illegal_csr

m_case_u_illegal_csr:
  CHECK_IMM t0, 2, 41
  csrr t3, mepc
  CHECK_LABEL t3, u_illegal_csr_site, 42
  RETURN_M u_after_illegal_csr

m_case_m_sret_to_s:
  CHECK_IMM t0, 2, 43
  csrr t3, mepc
  CHECK_LABEL t3, m_sret_target_s, 44
  RETURN_M m_after_sret_to_s

m_case_s_mret_illegal:
  CHECK_IMM t0, 2, 45
  csrr t3, mepc
  CHECK_LABEL t3, s_mret_illegal_site, 46
  RETURN_M s_after_mret_illegal

m_case_s_cycle_illegal:
  CHECK_IMM t0, 2, 47
  csrr t3, mepc
  CHECK_LABEL t3, s_cycle_illegal_site, 48
  RETURN_M s_after_cycle_illegal

m_case_s_cycle_allowed:
  CHECK_IMM t0, 9, 49
  csrr t3, mepc
  CHECK_LABEL t3, s_cycle_allowed_ecall, 50
  RETURN_M s_after_cycle_allowed

m_case_u_cycle_illegal:
  CHECK_IMM t0, 2, 51
  csrr t3, mepc
  CHECK_LABEL t3, u_cycle_illegal_site, 52
  RETURN_M u_after_cycle_illegal

m_case_u_cycle_allowed:
  CHECK_IMM t0, 8, 53
  csrr t3, mepc
  CHECK_LABEL t3, u_cycle_allowed_ecall, 54
  RETURN_M u_after_cycle_allowed

.align 2
s_trap_handler:
  csrr t0, scause
  la t1, case_id
  lw t1, 0(t1)

  li t2, CASE_S_ECALL_S
  beq t1, t2, s_case_s_ecall_s
  li t2, CASE_U_ECALL_S
  beq t1, t2, s_case_u_ecall_s
  FAIL 91

s_case_s_ecall_s:
  CHECK_IMM t0, 9, 60
  csrr t3, sepc
  CHECK_LABEL t3, s_ecall_s_site, 61
  csrr t3, stval
  CHECK_ZERO t3, 62
  la t3, s_after_ecall_s
  csrw sepc, t3
  sret

s_case_u_ecall_s:
  CHECK_IMM t0, 8, 63
  csrr t3, sepc
  CHECK_LABEL t3, u_ecall_s_site, 64
  csrr t3, stval
  CHECK_ZERO t3, 65
  SET_CASE CASE_U_ILLEGAL_CSR
  la t3, u_after_ecall_s
  csrw sepc, t3
  sret

.section .bss
.align 2
case_id:
  .word 0
