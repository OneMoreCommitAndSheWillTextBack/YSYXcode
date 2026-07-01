package top.backend.decoder

import chisel3._
import chisel3.util.BitPat
import top.backend.decoder.DecodeIndex.{src1Type => src1Type}
import top.backend.decoder.DecodeIndex.{memSize => memSize}

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
  isEcall:  Boolean = false,
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
    bool(isEcall)
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
  val isEcall     = 13
}

private[decoder] object DecodeTable {
  val default: List[UInt] = NpcDecode(legal = false).signals

  private val ADD   = BitPat("b0000000??????????000?????0110011")
  private val ADDI  = BitPat("b?????????????????000?????0010011")
  private val LUI   = BitPat("b?????????????????????????0110111")
  private val AUIPC = BitPat("b?????????????????????????0010111")
  private val LW    = BitPat("b?????????????????010?????0000011")
  private val SW    = BitPat("b?????????????????010?????0100011")
  private val BEQ   = BitPat("b?????????????????000?????1100011")
  private val JAL   = BitPat("b?????????????????????????1101111")
  private val ECALL = BitPat("b00000000000000000000000001110011")
  private val SB    = BitPat("b?????????????????000?????0100011")

  val table: Array[(BitPat, List[UInt])] = Array(
    ADD   -> NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      fu = FuType.alu,
      op = AluOp.add,
      rfWen = true
    ).signals,
    ADDI  -> NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.imm,
      immSel = ImmSel.i,
      fu = FuType.alu,
      op = AluOp.add,
      rfWen = true
    ).signals,
    LUI   -> NpcDecode(
      src1 = SrcType.none,
      src2 = SrcType.imm,
      immSel = ImmSel.u,
      fu = FuType.alu,
      op = AluOp.add,
      rfWen = true
    ).signals,
    AUIPC -> NpcDecode(
      src1 = SrcType.pc,
      src2 = SrcType.imm,
      immSel = ImmSel.u,
      fu = FuType.alu,
      op = AluOp.add,
      rfWen = true
    ).signals,
    LW    -> NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.none,
      immSel = ImmSel.i,
      fu = FuType.lsu,
      op = LsuOp.load,
      rfWen = true,
      isLoad = true,
      memSize = 2
    ).signals,
    SW    -> NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      immSel = ImmSel.s,
      fu = FuType.lsu,
      op = LsuOp.store,
      isStore = true,
      memSize = 2
    ).signals,
    SB    -> NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      immSel = ImmSel.s,
      fu = FuType.lsu,
      op = LsuOp.store,
      isStore = true,
      memSize = 0
    ).signals,
    BEQ   -> NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      immSel = ImmSel.b,
      fu = FuType.bru,
      op = BruOp.beq,
      isBranch = true
    ).signals,
    JAL   -> NpcDecode(
      src1 = SrcType.pc,
      src2 = SrcType.none,
      immSel = ImmSel.j,
      fu = FuType.jmp,
      op = JmpOp.jal,
      rfWen = true,
      isJal = true
    ).signals,
    ECALL -> NpcDecode(
      isEcall = true
    ).signals
  )
}
