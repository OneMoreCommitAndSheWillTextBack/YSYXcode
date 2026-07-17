package top.core.backend.decoder

import chisel3._
import chisel3.util.BitPat
import top.core.backend.csr.CsrOp
import top.core.bundle.CfiType
import top.core.backend.decoder.DecodeIndex.{cfi => cfi}
import top.core.backend.decoder.DecodeIndex.{rfWen => rfWen}

private[decoder] case class NpcDecode(
  legal:    Boolean = true,
  src1:     UInt = SrcType.none,
  src2:     UInt = SrcType.none,
  immSel:   UInt = ImmSel.none,
  fu:       UInt = FuType.none,
  op:       UInt = FuOp.none,
  cfi:      UInt = CfiType.none,
  rfWen:    Boolean = false,
  isLoad:   Boolean = false,
  isStore:  Boolean = false,
  isAmo:    Boolean = false,
  isEbreak: Boolean = false,
  isEcall:  Boolean = false,
  isMret:   Boolean = false,
  isSret:   Boolean = false,
  isFence:  Boolean = false,
  isFenceI: Boolean = false,
  isSfence: Boolean = false,
  isCsr:    Boolean = false,
  memSize:  Int = 0,
  memUnsigned: Boolean = false) {

  def signals: List[UInt] = List(
    bool(legal),
    src1,
    src2,
    immSel,
    fu,
    op,
    cfi,
    bool(rfWen),
    bool(isLoad),
    bool(isStore),
    bool(isAmo),
    memSize.U(3.W),
    bool(memUnsigned),
    bool(isEbreak),
    bool(isEcall),
    bool(isMret),
    bool(isSret),
    bool(isFence),
    bool(isFenceI),
    bool(isSfence),
    bool(isCsr)
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
  val cfi         = 6
  val rfWen       = 7
  val isLoad      = 8
  val isStore     = 9
  val isAmo       = 10
  val memSize     = 11
  val memUnsigned = 12
  val isEbreak    = 13
  val isEcall     = 14
  val isMret      = 15
  val isSret      = 16
  val isFence     = 17
  val isFenceI    = 18
  val isSfence    = 19
  val isCsr       = 20
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

  def mulReg(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      fu = FuType.mul,
      op = op,
      rfWen = true
    ).signals

  def divReg(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      fu = FuType.div,
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

  def atomic(op: UInt, readsRs2: Boolean = true): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = if (readsRs2) SrcType.reg else SrcType.none,
      fu = FuType.lsu,
      op = op,
      rfWen = true,
      isAmo = true,
      memSize = MemSize.word
    ).signals

  def branch(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.reg,
      immSel = ImmSel.b,
      fu = FuType.bru,
      op = op,
      cfi = CfiType.branch
    ).signals

  def jal(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.pc,
      src2 = SrcType.imm,
      immSel = ImmSel.j,
      fu = FuType.jmp,
      op = op,
      rfWen = true,
      cfi = CfiType.jal
    ).signals

  def jalr(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      src2 = SrcType.imm,
      immSel = ImmSel.i,
      fu = FuType.jmp,
      op = op,
      rfWen = true,
      cfi = CfiType.jalr
    ).signals

  def ebreak: List[UInt] =
    NpcDecode(
      fu = FuType.alu,
      op = AluOp.add,
      isEbreak = true
    ).signals

  def ecall: List[UInt] =
    NpcDecode(
      fu = FuType.alu,
      op = AluOp.add,
      isEcall = true
    ).signals

  def mret: List[UInt] =
    NpcDecode(
      fu = FuType.alu,
      op = AluOp.add,
      isMret = true
    ).signals

  def sret: List[UInt] =
    NpcDecode(
      fu = FuType.alu,
      op = AluOp.add,
      isSret = true
    ).signals

  def fence(fenceI: Boolean = false, sfence: Boolean = false): List[UInt] =
    NpcDecode(
      fu = FuType.alu,
      op = AluOp.add,
      isFence = true,
      isFenceI = fenceI,
      isSfence = sfence
    ).signals

  def csr(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.reg,
      fu = FuType.csr,
      op = op,
      rfWen = true,
      isCsr = true
    ).signals

  def csrImm(op: UInt): List[UInt] =
    NpcDecode(
      src1 = SrcType.imm,
      immSel = ImmSel.z,
      fu = FuType.csr,
      op = op,
      rfWen = true,
      isCsr = true
    ).signals
}
