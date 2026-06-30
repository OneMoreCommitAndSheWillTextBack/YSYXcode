package top.backend.execute

import chisel3._
import chisel3.util.{Decoupled, Valid}
import top.backend.bundle.{IssuePacket, IssueWakeup, RobWritebackPacket}
import top.backend.decoder.FuType
import top.backend.fu.ALU
import top.config.BackendConfig

class Execute(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IssuePacket(cfg)))

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
  })

  val alu = Module(new ALU(cfg.dataWidth))

  private def asDataWidth(value: UInt): UInt =
    value.asTypeOf(UInt(cfg.dataWidth.W))

  private val fallThrough    = io.in.bits.fetch.pc + io.in.bits.fetch.instLen
  private val branchTarget   = io.in.bits.fetch.pc + io.in.bits.imm
  private val branchTaken    = io.in.bits.isBranch && io.in.bits.src1.data === io.in.bits.src2.data
  private val redirectTarget = Mux(
    io.in.bits.isJal || branchTaken,
    branchTarget,
    fallThrough
  )

  alu.io.src1 := io.in.bits.src1.data
  alu.io.src2 := io.in.bits.src2.data
  alu.io.op   := io.in.bits.fuOp

  io.in.ready := true.B

  io.writeback.valid               := io.in.fire
  io.writeback.bits                := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.robIdx         := io.in.bits.robIdx
  io.writeback.bits.result         := Mux(io.in.bits.fuType === FuType.jmp, asDataWidth(fallThrough), alu.io.out)
  io.writeback.bits.redirectValid  := io.in.bits.isBranch || io.in.bits.isJal
  io.writeback.bits.redirectTarget := redirectTarget
  io.writeback.bits.branchTaken    := branchTaken || io.in.bits.isJal
  io.writeback.bits.branchTarget   := branchTarget

  io.wakeup.valid  := io.in.fire && io.in.bits.rfWen
  io.wakeup.robIdx := io.in.bits.robIdx
  io.wakeup.data   := io.writeback.bits.result
}
