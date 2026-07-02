package top.backend.decoder

import chisel3._
import chisel3.util.BitPat

private[decoder] case class NpcDecode(
  legal:    Boolean = true,
  src1:     UInt = SrcType.none,
  src2:     UInt = SrcType.none,
  immSel:   UInt = ImmSel.none,
  fu:       UInt = FuType.none,
  op:       UInt = FuOp.none,
  rfWen:    Boolean = false,
  isLoad:   Boolean = false,
  isStore:  Boolean = false,
  isBranch: Boolean = false,
  isJal:    Boolean = false,
  isEbreak: Boolean = false,
  memSize:  Int = 0,
  memUnsigned: Boolean = false) {

  def signals: List[UInt] = List(
    bool(legal),
    src1,
    src2,
    immSel,
    fu,
    op,
    bool(rfWen),
    bool(isLoad),
    bool(isStore),
    bool(isBranch),
    bool(isJal),
    memSize.U(3.W),
    bool(memUnsigned),
    bool(isEbreak)
  )

  private def bool(value: Boolean): UInt =
    (if (value) 1 else 0).U(1.W)
}

private[decoder] object DecodeIndex {
  val legal       = 0
  val src1Type    = 1
  val src2Type    = 2
  val immSel      = 3
  val fuType      = 4
  val fuOp        = 5
  val rfWen       = 6
  val isLoad      = 7
  val isStore     = 8
  val isBranch    = 9
  val isJal       = 10
  val memSize     = 11
  val memUnsigned = 12
  val isEbreak    = 13
}

private[decoder] trait DecodeGroup {
  def table: Seq[(BitPat, List[UInt])]
}

private[decoder] object DecodeDsl {
  def aluReg(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      fu = FuType.alu,
      op = op,
      rfWen = true
    ).signals

  def aluImm(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.imm,
      immSel = ImmSel.i,
      fu = FuType.alu,
      op = op,
      rfWen = true
    ).signals

  def upper(src1: UInt): List[UInt] =
    NpcDecode(
      src1 = src1,
      src2 = SrcType.imm,
      immSel = ImmSel.u,
      fu = FuType.alu,
      op = AluOp.add,
      rfWen = true
    ).signals

  def load(size: Int, unsigned: Boolean = false): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.none,
      immSel = ImmSel.i,
      fu = FuType.lsu,
      op = LsuOp.load,
      rfWen = true,
      isLoad = true,
      memSize = size,
      memUnsigned = unsigned
    ).signals

  def store(size: Int): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      immSel = ImmSel.s,
      fu = FuType.lsu,
      op = LsuOp.store,
      isStore = true,
      memSize = size
    ).signals

  def branch(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      immSel = ImmSel.b,
      fu = FuType.bru,
      op = op,
      isBranch = true
    ).signals

  def jump(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.pc,
      src2 = SrcType.none,
      immSel = ImmSel.j,
      fu = FuType.jmp,
      op = op,
      rfWen = true,
      isJal = true
    ).signals

  def ebreak: List[UInt] =
    NpcDecode(
      fu = FuType.alu,
      op = AluOp.add,
      isEbreak = true
    ).signals
}
