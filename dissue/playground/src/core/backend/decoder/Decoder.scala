package top.core.backend.decoder

import chisel3._
import chisel3.util.{Cat, Fill, ListLookup, MuxLookup}
import top.core.backend.bundle._
import top.core.backend.csr.CsrOp
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.bundle.FetchInstPayload
import top.config.BackendConfig

class Decoder(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in  = Input(new FetchInstPayload(cfg.addrWidth))
    val out = Output(new DecodePacket(cfg))
  })

  private val inst = io.in.inst

  private val rd  = inst(11, 7)
  private val rs1 = inst(19, 15)
  private val rs2 = inst(24, 20)

  private val decoded = ListLookup(inst, DecodeTable.default, DecodeTable.table)
  private val immSel  = decoded(DecodeIndex.immSel)
  private val legal   = decoded(DecodeIndex.legal).asBool
  private val isCsr   = decoded(DecodeIndex.isCsr).asBool

  private val immI = Cat(Fill(20, inst(31)), inst(31, 20))
  private val immS = Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7))
  private val immB = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W))
  private val immJ = Cat(Fill(11, inst(31)), inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))
  private val immU = Cat(inst(31, 12), 0.U(12.W))
  private val immZ = Cat(0.U(27.W), inst(19, 15))

  io.out             := 0.U.asTypeOf(new DecodePacket(cfg))
  io.out.valid       := true.B
  io.out.fetch       := io.in
  io.out.legal       := legal
  io.out.rs1         := rs1
  io.out.rs2         := rs2
  io.out.rd          := rd
  io.out.imm         := MuxLookup(
    immSel,
    0.U(32.W)
  )(
    Seq(
      ImmSel.i -> immI,
      ImmSel.s -> immS,
      ImmSel.b -> immB,
      ImmSel.j -> immJ,
      ImmSel.u -> immU,
      ImmSel.z -> immZ
    )
  )
  io.out.src1Type    := decoded(DecodeIndex.src1Type)
  io.out.src2Type    := decoded(DecodeIndex.src2Type)
  io.out.fuType      := decoded(DecodeIndex.fuType)
  io.out.fuOp        := decoded(DecodeIndex.fuOp)
  io.out.rfWen       := decoded(DecodeIndex.rfWen).asBool && rd =/= 0.U
  io.out.isLoad      := decoded(DecodeIndex.isLoad).asBool
  io.out.isStore     := decoded(DecodeIndex.isStore).asBool
  io.out.isAmo       := decoded(DecodeIndex.isAmo).asBool
  io.out.cfi         := decoded(DecodeIndex.cfi)
  io.out.memSize     := decoded(DecodeIndex.memSize)
  io.out.memUnsigned := decoded(DecodeIndex.memUnsigned).asBool
  io.out.isEbreak    := decoded(DecodeIndex.isEbreak).asBool
  io.out.isEcall     := decoded(DecodeIndex.isEcall).asBool
  io.out.isMret      := decoded(DecodeIndex.isMret).asBool
  io.out.isSret      := decoded(DecodeIndex.isSret).asBool
  io.out.isFence     := decoded(DecodeIndex.isFence).asBool
  io.out.isFenceI    := decoded(DecodeIndex.isFenceI).asBool
  io.out.isSfence    := decoded(DecodeIndex.isSfence).asBool
  io.out.isCsr       := isCsr
  io.out.csrAddr     := inst(31, 20)
  private val csrUsesZimm  = decoded(DecodeIndex.src1Type) === SrcType.imm
  private val csrSetClear  = decoded(DecodeIndex.fuOp) === CsrOp.rs || decoded(DecodeIndex.fuOp) === CsrOp.rc
  private val csrScWriteEn = Mux(csrUsesZimm, immZ =/= 0.U, rs1 =/= 0.U)
  io.out.csrWen      := isCsr && (
    decoded(DecodeIndex.fuOp) === CsrOp.rw ||
      (csrSetClear && csrScWriteEn)
  )
  val fetchException = Wire(new ExceptionInfo(cfg))
  fetchException.valid     := io.in.exception.valid
  fetchException.interrupt := false.B
  fetchException.cause     := io.in.exception.cause
  fetchException.tval      := io.in.exception.tval

  io.out.exception   := fetchException
  when(!legal) {
    io.out.exception := ExceptionInfo.keepFirst(
      fetchException,
      ExceptionInfo.raise(ExceptionCause.illegalInstr, io.in.rawInst, cfg),
      cfg
    )
  }
}
