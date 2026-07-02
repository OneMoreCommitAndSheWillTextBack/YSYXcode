package top.backend.exu

import chisel3._
import chisel3.util.{Decoupled, MuxLookup, Valid}
import top.backend.bundle.{IssuePortStatus, IssueWakeup, RobWritebackPacket}
import top.backend.decoder.FuType
import top.backend.fu.{ALU, BRU, JMP}
import top.config.BackendConfig

class IntExeUnit(
  cfg:    BackendConfig = BackendConfig(),
  params: IntExeUnitConfig = IntExeUnitConfig.aluBju)
    extends Module {
  val io = IO(new Bundle {
    val in     = Flipped(Decoupled(new ExuRequest(cfg)))
    val flush  = Input(Bool())
    val status = Output(new IssuePortStatus)

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
  })

  private def has(kind: ExuFuKind): Boolean =
    params.supports(kind)

  private def supports(fuType: UInt): Bool =
    MuxLookup(fuType, false.B)(
      params.pipes.map(pipe => pipe.kind.fuType -> true.B)
    )

  private val alu = Option.when(has(ExuFuKind.Alu))(Module(new ALU(cfg.dataWidth)))
  private val bru = Option.when(has(ExuFuKind.Bru))(Module(new BRU(cfg.addrWidth, cfg.dataWidth)))
  private val jmp = Option.when(has(ExuFuKind.Jmp))(Module(new JMP(cfg.addrWidth, cfg.dataWidth)))

  io.status     := 0.U.asTypeOf(new IssuePortStatus)
  io.status.alu := has(ExuFuKind.Alu).B
  io.status.bru := has(ExuFuKind.Bru).B
  io.status.jmp := has(ExuFuKind.Jmp).B

  io.in.ready := supports(io.in.bits.fuType)

  alu.foreach { unit =>
    unit.io.src1 := io.in.bits.src1
    unit.io.src2 := io.in.bits.src2
    unit.io.op   := io.in.bits.fuOp
  }

  bru.foreach { unit =>
    unit.io.src1    := io.in.bits.src1
    unit.io.src2    := io.in.bits.src2
    unit.io.pc      := io.in.bits.fetch.pc
    unit.io.imm     := io.in.bits.imm
    unit.io.instLen := io.in.bits.fetch.instLen
    unit.io.op      := io.in.bits.fuOp
  }

  jmp.foreach { unit =>
    unit.io.src1    := io.in.bits.src1
    unit.io.pc      := io.in.bits.fetch.pc
    unit.io.imm     := io.in.bits.imm
    unit.io.instLen := io.in.bits.fetch.instLen
    unit.io.op      := io.in.bits.fuOp
  }

  private val exuResult = Wire(Valid(new ExuResult(cfg)))
  exuResult.valid := io.in.fire && !io.flush
  exuResult.bits  := 0.U.asTypeOf(new ExuResult(cfg))

  exuResult.bits.robIdx := io.in.bits.robIdx
  exuResult.bits.rd     := io.in.bits.rd
  exuResult.bits.rfWen  := io.in.bits.rfWen
  exuResult.bits.result := MuxLookup(io.in.bits.fuType, alu.map(_.io.out).getOrElse(0.U(cfg.dataWidth.W)))(
    Seq(
      Option.when(has(ExuFuKind.Bru))(FuType.bru -> 0.U(cfg.dataWidth.W)),
      jmp.map(unit => FuType.jmp -> unit.io.link)
    ).flatten
  )

  exuResult.bits.redirectValid  := MuxLookup(io.in.bits.fuType, false.B)(
    Seq(
      Option.when(has(ExuFuKind.Bru))(FuType.bru -> true.B),
      Option.when(has(ExuFuKind.Jmp))(FuType.jmp -> true.B)
    ).flatten
  )
  exuResult.bits.redirectTarget := MuxLookup(io.in.bits.fuType, 0.U(cfg.addrWidth.W))(
    Seq(
      bru.map(unit => FuType.bru -> unit.io.redirectTarget),
      jmp.map(unit => FuType.jmp -> unit.io.redirectTarget)
    ).flatten
  )
  exuResult.bits.branchTaken    := MuxLookup(io.in.bits.fuType, false.B)(
    Seq(
      bru.map(unit => FuType.bru -> unit.io.taken),
      Option.when(has(ExuFuKind.Jmp))(FuType.jmp -> true.B)
    ).flatten
  )
  exuResult.bits.branchTarget   := MuxLookup(io.in.bits.fuType, 0.U(cfg.addrWidth.W))(
    Seq(
      bru.map(unit => FuType.bru -> unit.io.target),
      jmp.map(unit => FuType.jmp -> unit.io.target)
    ).flatten
  )

  io.writeback.valid               := exuResult.valid
  io.writeback.bits                := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.robIdx         := exuResult.bits.robIdx
  io.writeback.bits.result         := exuResult.bits.result
  io.writeback.bits.storeAddr      := exuResult.bits.storeAddr
  io.writeback.bits.storeData      := exuResult.bits.storeData
  io.writeback.bits.storeMask      := exuResult.bits.storeMask
  io.writeback.bits.redirectValid  := exuResult.bits.redirectValid
  io.writeback.bits.redirectTarget := exuResult.bits.redirectTarget
  io.writeback.bits.branchTaken    := exuResult.bits.branchTaken
  io.writeback.bits.branchTarget   := exuResult.bits.branchTarget

  io.wakeup.valid  := exuResult.valid && exuResult.bits.rfWen
  io.wakeup.robIdx := exuResult.bits.robIdx
  io.wakeup.data   := exuResult.bits.result

  assert(!io.in.fire || supports(io.in.bits.fuType), s"${params.name} accepted an unsupported FU type")
}
