package top.backend.decoder.rvi

import chisel3._
import chisel3.util.BitPat
import top.backend.decoder._

private[decoder] object RviAluDecode extends DecodeGroup {
  import DecodeDsl._
  import RviPatterns._

  val table: Seq[(BitPat, List[UInt])] = Seq(
    ADD    -> aluReg(AluOp.add),
    SUB    -> aluReg(AluOp.sub),
    SLL    -> aluReg(AluOp.sll),
    SLT    -> aluReg(AluOp.slt),
    SLTU   -> aluReg(AluOp.sltu),
    XOR    -> aluReg(AluOp.xor),
    SRL    -> aluReg(AluOp.srl),
    SRA    -> aluReg(AluOp.sra),
    OR     -> aluReg(AluOp.or),
    AND    -> aluReg(AluOp.and),
    MUL    -> mulReg(AluOp.mul),
    MULH   -> mulReg(AluOp.mulh),
    MULHSU -> mulReg(AluOp.mulhsu),
    MULHU  -> mulReg(AluOp.mulhu),
    DIV    -> divReg(AluOp.div),
    DIVU   -> divReg(AluOp.divu),
    REM    -> divReg(AluOp.rem),
    REMU   -> divReg(AluOp.remu),
    ADDI   -> aluImm(AluOp.add),
    SLTI   -> aluImm(AluOp.slt),
    SLTIU  -> aluImm(AluOp.sltu),
    XORI   -> aluImm(AluOp.xor),
    ORI    -> aluImm(AluOp.or),
    ANDI   -> aluImm(AluOp.and),
    SLLI   -> aluImm(AluOp.sll),
    SRLI   -> aluImm(AluOp.srl),
    SRAI   -> aluImm(AluOp.sra)
  )
}
