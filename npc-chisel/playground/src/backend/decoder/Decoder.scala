package top.backend.decoder

import chisel3._
import chisel3.util.{Cat, Fill, ListLookup, MuxLookup}
import top.backend.bundle._
import top.bundle.FetchInstPayload
import top.config.BackendConfig

class Decoder(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in  = Input(new FetchInstPayload(cfg.addrWidth))
    val out = Output(new DecodePacket(cfg.addrWidth))
  })

  private val inst = io.in.inst

  private val rd  = inst(11, 7)
  private val rs1 = inst(19, 15)
  private val rs2 = inst(24, 20)

  private val decoded = ListLookup(inst, DecodeTable.default, DecodeTable.table)
  private val immSel  = decoded(DecodeIndex.immSel)

  private val immI = Cat(Fill(20, inst(31)), inst(31, 20))
  private val immS = Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7))
  private val immB = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W))
  private val immJ = Cat(Fill(11, inst(31)), inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))

  io.out             := 0.U.asTypeOf(new DecodePacket(cfg.addrWidth))
  io.out.fetch       := io.in
  io.out.legal       := decoded(DecodeIndex.legal).asBool
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
      ImmSel.j -> immJ
    )
  )
  io.out.src1Type    := decoded(DecodeIndex.src1Type)
  io.out.src2Type    := decoded(DecodeIndex.src2Type)
  io.out.fuType      := decoded(DecodeIndex.fuType)
  io.out.fuOp        := decoded(DecodeIndex.fuOp)
  io.out.rfWen       := decoded(DecodeIndex.rfWen).asBool && rd =/= 0.U
  io.out.isLoad      := decoded(DecodeIndex.isLoad).asBool
  io.out.isStore     := decoded(DecodeIndex.isStore).asBool
  io.out.isBranch    := decoded(DecodeIndex.isBranch).asBool
  io.out.isJal       := decoded(DecodeIndex.isJal).asBool
  io.out.memSize     := decoded(DecodeIndex.memSize)
  io.out.memUnsigned := decoded(DecodeIndex.memUnsigned).asBool
}
