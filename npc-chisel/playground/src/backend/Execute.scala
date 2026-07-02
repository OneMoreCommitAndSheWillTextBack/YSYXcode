package top.backend.execute

import chisel3._
import chisel3.util.{Decoupled, MuxLookup, Valid}
import top.backend.bundle.{IssuePacket, IssueWakeup, RobWritebackPacket}
import top.backend.decoder.FuType
import top.backend.fu.{ALU, BRU, JMP}
import top.config.BackendConfig

class Execute(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IssuePacket(cfg)))

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
  })

  val alu = Module(new ALU(cfg.dataWidth))
  val bru = Module(new BRU(cfg.addrWidth, cfg.dataWidth))
  val jmp = Module(new JMP(cfg.addrWidth, cfg.dataWidth))

  private def asDataWidth(value: UInt): UInt =
    value.asTypeOf(UInt(cfg.dataWidth.W))

  alu.io.src1 := io.in.bits.src1.data
  alu.io.src2 := io.in.bits.src2.data
  alu.io.op   := io.in.bits.fuOp

  bru.io.src1    := io.in.bits.src1.data
  bru.io.src2    := io.in.bits.src2.data
  bru.io.pc      := io.in.bits.fetch.pc
  bru.io.imm     := asDataWidth(io.in.bits.imm)
  bru.io.instLen := io.in.bits.fetch.instLen
  bru.io.op      := io.in.bits.fuOp

  jmp.io.src1    := io.in.bits.src1.data
  jmp.io.pc      := io.in.bits.fetch.pc
  jmp.io.imm     := asDataWidth(io.in.bits.imm)
  jmp.io.instLen := io.in.bits.fetch.instLen
  jmp.io.op      := io.in.bits.fuOp

  io.in.ready := true.B

  io.writeback.valid               := io.in.fire
  io.writeback.bits                := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.robIdx         := io.in.bits.robIdx
  io.writeback.bits.result         := MuxLookup(io.in.bits.fuType, alu.io.out)(
    Seq(
      FuType.bru -> 0.U(cfg.dataWidth.W),
      FuType.jmp -> jmp.io.link
    )
  )
  io.writeback.bits.redirectValid  := io.in.bits.fuType === FuType.bru || io.in.bits.fuType === FuType.jmp
  io.writeback.bits.redirectTarget := Mux(
    io.in.bits.fuType === FuType.bru,
    bru.io.redirectTarget,
    jmp.io.redirectTarget
  )
  io.writeback.bits.branchTaken    := Mux(io.in.bits.fuType === FuType.bru, bru.io.taken, io.in.bits.fuType === FuType.jmp)
  io.writeback.bits.branchTarget   := Mux(io.in.bits.fuType === FuType.bru, bru.io.target, jmp.io.target)

  io.wakeup.valid  := io.in.fire && io.in.bits.rfWen
  io.wakeup.robIdx := io.in.bits.robIdx
  io.wakeup.data   := io.writeback.bits.result
}
