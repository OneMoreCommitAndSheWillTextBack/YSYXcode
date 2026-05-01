/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/
// clang-format off

#include "common.h"
#include "isa-def.h"
#include "isa.h"
#include "local-include/reg.h"
#include "local-include/csr-table.h"
#include "macro.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <stdint.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

static word_t ecall_inst();
static word_t mret_inst();

CPU_MODE current_cpu_priv = M_MODE;

#define ECALL s->dnpc = ecall_inst()
#define MRET s->dnpc = mret_inst()

enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_N, TYPE_J, TYPE_R,
  TYPE_B, 
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = SEXT(BITS(i, 31, 31), 1) << 20 | BITS(i, 30, 21) << 1 | BITS(i, 20, 20) << 11 | BITS(i, 19, 12) << 12; } while(0)
#define immB() do { *imm = SEXT(BITS(i, 31, 31), 1) << 12 | BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1 | BITS(i, 7, 7) << 11; } while(0)

static uint32_t csr_read(uint32_t csr_num);
static void csr_write(uint32_t csr_num, uint32_t data);
static void readonly_recover();

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_J:                   immJ(); break;
    case TYPE_R: src1R(); src2R();         break;
    case TYPE_B: src1R(); src2R(); immB(); break;
  }
}

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));

  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
#ifndef CONFIG_FTRACE
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc+4;s->dnpc=s->pc+imm;);
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd)=s->pc+4;s->dnpc=(src1+imm)&~1);
#else // def ftrace
  INSTPAT("??????? ????? ????? 000 ????? 11001 11",jalr,I,R(rd)=s->pc+4;s->dnpc=src1+(imm&~1);dealftrace(s));
  INSTPAT("??????? ????? ????? ??? ????? 11011 11",jal,J,R(rd) = s->pc+4;s->dnpc=s->pc+imm;dealftrace(s));
#endif
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1+imm, 4, src2));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1+imm, 4));
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = src1 < imm);
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (int)src1 / (int)src2);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((int)src1 >= (int)src2) s->dnpc = s->pc + imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << imm);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, long t1=(int)src1;long t2=(int)src2;R(rd)=(t1*t2)>>32);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = src1 < src2);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((int)src1 < (int)src2) s->dnpc = s->pc + imm);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (int)src1 < (int)src2);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (int)src1 % (int)src2);
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (int)src1 >> imm);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = src1 >> imm);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (int)src1 >> src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> src2);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1+imm, 2, (uint16_t)src2));
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = src1 % src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = src1 / src2);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = (int)src1 < (int)imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, uint64_t t = (uint64_t)src1*src2;R(rd) = t >> 32);
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  
  INSTPAT("00001?? ????? ????? 010 ????? 01111 11", amoswap.w, R, uint32_t tmp = R(src2);                   \
                                                                       R(src2) = Mr(R(src1), 4);       \
                                                                       Mw(R(src1), 4, tmp));

  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, uint32_t t=csr_read(imm);csr_write(imm, src1);R(rd)=t);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, uint32_t t=csr_read(imm);csr_write(imm, t|src1);R(rd)=t);
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, ECALL);
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , I, MRET);

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("0000000 00000 00000 001 00000 00011 11", fence.i, I, );
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0
  readonly_recover();

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}

static void readonly_recover() {
  cpu.csr.mhartid = 0; // mhartid is a readonly csr 
}

static word_t ecall_inst() {
  if (current_cpu_priv == M_MODE) {
    return isa_raise_intr(11, cpu.pc);
  } else if (current_cpu_priv == S_MODE) {
    return isa_raise_intr(9, cpu.pc);
  } else if(current_cpu_priv == U_MODE) {
    return isa_raise_intr(8, cpu.pc);
  } else {
    assert(false && "invalid current_cpu_priv");
  }
}

static word_t mret_inst() { 
  assert(current_cpu_priv == M_MODE);
  uint32_t mpp = cpu.csr.mstatus & MSTATUS_MPP_MASK;
  if(mpp == MSTATUS_MPP_M) {
    current_cpu_priv = M_MODE;
  } else if(mpp == MSTATUS_MPP_S) {
    current_cpu_priv = S_MODE;
  } else if(mpp == MSTATUS_MPP_U) {
    current_cpu_priv = U_MODE;
  } else {
    assert(false && "mpp");
  }
  // reset MSTATUS_MPP 
  cpu.csr.mstatus = cpu.csr.mstatus & ~(MSTATUS_MPP_MASK);
  // MSTATUS_MPIE -> MSTATUS_MIE
  // 1 -> MSTATUS_MPIE
  uint32_t mpie = cpu.csr.mstatus & MSTATUS_MPIE;
  cpu.csr.mstatus = (cpu.csr.mstatus & ~(MSTATUS_MIE)) | (mpie >> 4);
  cpu.csr.mstatus = cpu.csr.mstatus | MSTATUS_MPIE;

  return cpu.csr.mepc; 
}

#define CSR_MAST 0xfff
static uint32_t csr_read(uint32_t csr_num) {
  csr_num &= CSR_MAST;
  uint32_t *csr = get_raw_csr(csr_num);
  if(csr == NULL) {
    virt_csr_entry_t *virt_csr_handler = get_virt_csr(csr_num);
    if (virt_csr_handler == NULL) {
      panic("invalid csr num %x(%d)\n", csr_num, csr_num);
    }
    return virt_csr_handler->read();
  } else {
    return *csr;
  }
}

static void csr_write(uint32_t csr_num, uint32_t data) {
  csr_num &= CSR_MAST;
  uint32_t *csr = get_raw_csr(csr_num);
  if(csr == NULL) {
    virt_csr_entry_t *virt_csr_handler = get_virt_csr(csr_num);
    if (virt_csr_handler == NULL) {
      panic("invalid csr num %x(%d)\n", csr_num, csr_num);
    }
    virt_csr_handler->write(data);
  } else {
    *csr = data;
  }
  return;
}
