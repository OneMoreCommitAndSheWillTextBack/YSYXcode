package top.backend.decoder

import chisel3._
import chisel3.util.{Cat, Fill, MuxCase}
import top.backend.bundle._
import top.bundle.FetchInstPayload

class Decoder(addrWidth: Int = 32) extends Module {
  val io = IO(new Bundle {
    val in  = Input(new FetchInstPayload(addrWidth))
    val out = Output(new DecodePacket(addrWidth))
  })

  private val inst = io.in.inst

  private val opcode = inst(6, 0)
  private val rd     = inst(11, 7)
  private val funct3 = inst(14, 12)
  private val rs1    = inst(19, 15)
  private val rs2    = inst(24, 20)
  private val funct7 = inst(31, 25)

  private val opcodeOp     = "b0110011".U(7.W)
  private val opcodeLoad   = "b0000011".U(7.W)
  private val opcodeStore  = "b0100011".U(7.W)
  private val opcodeBranch = "b1100011".U(7.W)
  private val opcodeJal    = "b1101111".U(7.W)

  private val isAdd = opcode === opcodeOp && funct3 === "b000".U && funct7 === "b0000000".U
  private val isLw  = opcode === opcodeLoad && funct3 === "b010".U
  private val isSw  = opcode === opcodeStore && funct3 === "b010".U
  private val isBeq = opcode === opcodeBranch && funct3 === "b000".U
  private val isJal = opcode === opcodeJal

  private val immI = Cat(Fill(20, inst(31)), inst(31, 20))
  private val immS = Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7))
  private val immB = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W))
  private val immJ = Cat(Fill(11, inst(31)), inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W))

  io.out := 0.U.asTypeOf(new DecodePacket(addrWidth))
  io.out.fetch := io.in
  io.out.legal := isAdd || isLw || isSw || isBeq || isJal
  io.out.rs1   := rs1
  io.out.rs2   := rs2
  io.out.rd    := rd
  io.out.imm := MuxCase(
    0.U(32.W),
    Seq(
      isLw  -> immI,
      isSw  -> immS,
      isBeq -> immB,
      isJal -> immJ
    )
  )

  when(isAdd) {
    io.out.src1Type := SrcType.reg
    io.out.src2Type := SrcType.reg
    io.out.fuType   := FuType.alu
    io.out.fuOp     := FuOp.add
    io.out.rfWen    := rd =/= 0.U
  }.elsewhen(isLw) {
    io.out.src1Type    := SrcType.reg
    io.out.src2Type    := SrcType.imm
    io.out.immSel      := ImmSel.i
    io.out.fuType      := FuType.lsu
    io.out.fuOp        := FuOp.lw
    io.out.rfWen       := rd =/= 0.U
    io.out.isLoad      := true.B
    io.out.memSize     := 2.U
    io.out.memUnsigned := false.B
  }.elsewhen(isSw) {
    io.out.src1Type := SrcType.reg
    io.out.src2Type := SrcType.reg
    io.out.immSel   := ImmSel.s
    io.out.fuType   := FuType.lsu
    io.out.fuOp     := FuOp.sw
    io.out.isStore  := true.B
    io.out.memSize  := 2.U
  }.elsewhen(isBeq) {
    io.out.src1Type := SrcType.reg
    io.out.src2Type := SrcType.reg
    io.out.immSel   := ImmSel.b
    io.out.fuType   := FuType.bru
    io.out.fuOp     := FuOp.beq
    io.out.isBranch := true.B
  }.elsewhen(isJal) {
    io.out.src1Type := SrcType.pc
    io.out.src2Type := SrcType.imm
    io.out.immSel   := ImmSel.j
    io.out.fuType   := FuType.jmp
    io.out.fuOp     := FuOp.jal
    io.out.rfWen    := rd =/= 0.U
    io.out.isJal    := true.B
  }
}
