package top.backend.exu

import chisel3._
import chisel3.util.{Decoupled, MuxLookup, Valid}
import top.backend.bundle.{IssuePortStatus, IssueWakeup, RobWritebackPacket}
import top.backend.csr.{CsrOp, CsrReadPort}
import top.backend.decoder.FuType
import top.backend.exception.{ExceptionCause, ExceptionInfo}
import top.backend.fu.{ALU, BRU, CSR, DIV, JMP, MUL}
import top.config.BackendConfig

class IntExeUnit(
  cfg:    BackendConfig = BackendConfig(),
  params: IntExeUnitConfig = IntExeUnitConfig.aluBjuCsr)
    extends Module {
  val io = IO(new Bundle {
    val in      = Flipped(Decoupled(new ExuRequest(cfg)))
    val flush   = Input(Bool())
    val status  = Output(new IssuePortStatus)
    val csrRead = new CsrReadPort(cfg)

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
  private val mul = Option.when(has(ExuFuKind.Mul))(Module(new MUL(cfg.dataWidth)))
  private val div = Option.when(has(ExuFuKind.Div))(Module(new DIV(cfg.dataWidth)))
  private val bru = Option.when(has(ExuFuKind.Bru))(Module(new BRU(cfg.addrWidth, cfg.dataWidth)))
  private val jmp = Option.when(has(ExuFuKind.Jmp))(Module(new JMP(cfg.addrWidth, cfg.dataWidth)))
  private val csr = Option.when(has(ExuFuKind.Csr))(Module(new CSR(cfg)))

  io.status := 0.U.asTypeOf(new IssuePortStatus)
  private val mulOutValid         = mul.map(_.io.out.valid).getOrElse(false.B)
  private val mulInReady          = mul.map(_.io.in.ready).getOrElse(false.B)
  private val divOutValid         = div.map(_.io.out.valid).getOrElse(false.B)
  private val divInReady          = div.map(_.io.in.ready).getOrElse(false.B)
  private val divBusy             = div.map(_.io.busy).getOrElse(false.B)
  private val longLatencyOutValid = mulOutValid || divOutValid
  // Keep this single-writeback port quiet while DIV owns it; MUL can still be pipelined when DIV is idle.
  private val immediateFuReady    = !longLatencyOutValid && !divBusy

  io.status.alu := has(ExuFuKind.Alu).B && immediateFuReady
  io.status.mul := has(ExuFuKind.Mul).B && mulInReady && !divBusy
  io.status.div := has(ExuFuKind.Div).B && divInReady
  io.status.bru := has(ExuFuKind.Bru).B && immediateFuReady
  io.status.jmp := has(ExuFuKind.Jmp).B && immediateFuReady
  io.status.csr := has(ExuFuKind.Csr).B && immediateFuReady

  io.csrRead.addr := Mux(io.in.valid && io.in.bits.fuType === FuType.csr, io.in.bits.csrAddr, 0.U)

  private val isMulReq        = io.in.bits.fuType === FuType.mul
  private val isDivReq        = io.in.bits.fuType === FuType.div
  private val selectedFuReady = Mux(isMulReq, mulInReady && !divBusy, Mux(isDivReq, divInReady, immediateFuReady))
  io.in.ready := supports(io.in.bits.fuType) && selectedFuReady

  alu.foreach { unit =>
    unit.io.src1 := io.in.bits.src1
    unit.io.src2 := io.in.bits.src2
    unit.io.op   := io.in.bits.fuOp
  }

  mul.foreach { unit =>
    unit.io.flush        := io.flush
    unit.io.in.valid     := io.in.fire && isMulReq && !io.flush
    unit.io.in.bits.src1 := io.in.bits.src1
    unit.io.in.bits.src2 := io.in.bits.src2
    unit.io.in.bits.op   := io.in.bits.fuOp
  }

  div.foreach { unit =>
    unit.io.flush        := io.flush
    unit.io.in.valid     := io.in.fire && isDivReq && !io.flush
    unit.io.in.bits.src1 := io.in.bits.src1
    unit.io.in.bits.src2 := io.in.bits.src2
    unit.io.in.bits.op   := io.in.bits.fuOp
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

  csr.foreach { unit =>
    unit.io.old         := io.csrRead.data
    unit.io.src         := io.in.bits.src1
    unit.io.op          := io.in.bits.fuOp
    unit.io.writeEnable := io.in.bits.csrWen
  }

  private val mulMeta0 = RegInit(0.U.asTypeOf(Valid(new ExuResult(cfg))))
  private val mulMeta1 = RegInit(0.U.asTypeOf(Valid(new ExuResult(cfg))))
  private val mulIssue = io.in.fire && isMulReq && !io.flush
  private val divMeta  = RegInit(0.U.asTypeOf(Valid(new ExuResult(cfg))))
  private val divIssue = io.in.fire && isDivReq && !io.flush

  private val mulIssueResult = Wire(new ExuResult(cfg))
  mulIssueResult               := 0.U.asTypeOf(new ExuResult(cfg))
  mulIssueResult.robIdx        := io.in.bits.robIdx
  mulIssueResult.rd            := io.in.bits.rd
  mulIssueResult.rfWen         := io.in.bits.rfWen
  mulIssueResult.csrWen        := false.B
  mulIssueResult.redirectValid := false.B
  mulIssueResult.exception     := io.in.bits.exception

  private val divIssueResult = Wire(new ExuResult(cfg))
  divIssueResult               := 0.U.asTypeOf(new ExuResult(cfg))
  divIssueResult.robIdx        := io.in.bits.robIdx
  divIssueResult.rd            := io.in.bits.rd
  divIssueResult.rfWen         := io.in.bits.rfWen
  divIssueResult.csrWen        := false.B
  divIssueResult.redirectValid := false.B
  divIssueResult.exception     := io.in.bits.exception

  when(io.flush) {
    mulMeta0.valid := false.B
    mulMeta1.valid := false.B
    divMeta.valid  := false.B
  }.otherwise {
    mulMeta1 := mulMeta0

    mulMeta0.valid := mulIssue
    mulMeta0.bits  := mulIssueResult

    when(divIssue) {
      divMeta.valid := true.B
      divMeta.bits  := divIssueResult
    }.elsewhen(divOutValid) {
      divMeta.valid := false.B
    }
  }

  private val exuResult = Wire(Valid(new ExuResult(cfg)))
  exuResult.valid := io.in.fire && !io.flush && !isMulReq && !isDivReq
  exuResult.bits  := 0.U.asTypeOf(new ExuResult(cfg))

  private val csrReadNeeded  =
    io.in.bits.fuType === FuType.csr &&
      (io.in.bits.fuOp =/= CsrOp.rw || io.in.bits.rd =/= 0.U)
  private val csrWriteNeeded =
    io.in.bits.fuType === FuType.csr && io.in.bits.csrWen
  private val csrIllegal     =
    (csrReadNeeded && !io.csrRead.readLegal) || (csrWriteNeeded && !io.csrRead.writeLegal)

  exuResult.bits.robIdx    := io.in.bits.robIdx
  exuResult.bits.rd        := io.in.bits.rd
  exuResult.bits.rfWen     := io.in.bits.rfWen
  exuResult.bits.exception := io.in.bits.exception
  when(csrIllegal) {
    exuResult.bits.exception := ExceptionInfo.raise(ExceptionCause.illegalInstr, io.in.bits.fetch.rawInst, cfg)
  }
  exuResult.bits.result    := MuxLookup(io.in.bits.fuType, alu.map(_.io.out).getOrElse(0.U(cfg.dataWidth.W)))(
    Seq(
      Option.when(has(ExuFuKind.Bru))(FuType.bru -> 0.U(cfg.dataWidth.W)),
      jmp.map(unit => FuType.jmp -> unit.io.link),
      csr.map(unit => FuType.csr -> unit.io.result)
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
  exuResult.bits.csrWen         := io.in.bits.fuType === FuType.csr && csr.map(_.io.wen).getOrElse(false.B) && !csrIllegal
  exuResult.bits.csrWdata       := csr.map(_.io.wdata).getOrElse(0.U(cfg.dataWidth.W))

  private val mulResult = Wire(Valid(new ExuResult(cfg)))
  mulResult.valid       := mulOutValid && mulMeta1.valid
  mulResult.bits        := mulMeta1.bits
  mulResult.bits.result := mul.map(_.io.out.bits).getOrElse(0.U(cfg.dataWidth.W))

  private val divResult = Wire(Valid(new ExuResult(cfg)))
  divResult.valid       := divOutValid && divMeta.valid
  divResult.bits        := divMeta.bits
  divResult.bits.result := div.map(_.io.out.bits).getOrElse(0.U(cfg.dataWidth.W))

  private val writebackResult = Wire(Valid(new ExuResult(cfg)))
  writebackResult.valid := divResult.valid || mulResult.valid || exuResult.valid
  writebackResult.bits  := Mux(divResult.valid, divResult.bits, Mux(mulResult.valid, mulResult.bits, exuResult.bits))

  io.writeback.valid               := writebackResult.valid
  io.writeback.bits                := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.robIdx         := writebackResult.bits.robIdx
  io.writeback.bits.result         := writebackResult.bits.result
  io.writeback.bits.storeAddr      := writebackResult.bits.storeAddr
  io.writeback.bits.storeData      := writebackResult.bits.storeData
  io.writeback.bits.storeMask      := writebackResult.bits.storeMask
  io.writeback.bits.redirectValid  := writebackResult.bits.redirectValid
  io.writeback.bits.redirectTarget := writebackResult.bits.redirectTarget
  io.writeback.bits.branchTaken    := writebackResult.bits.branchTaken
  io.writeback.bits.branchTarget   := writebackResult.bits.branchTarget
  io.writeback.bits.csrWen         := writebackResult.bits.csrWen
  io.writeback.bits.csrWdata       := writebackResult.bits.csrWdata
  io.writeback.bits.exception      := writebackResult.bits.exception

  io.wakeup.valid  := writebackResult.valid && writebackResult.bits.rfWen
  io.wakeup.robIdx := writebackResult.bits.robIdx
  io.wakeup.data   := writebackResult.bits.result

  assert(!io.in.fire || supports(io.in.bits.fuType), s"${params.name} accepted an unsupported FU type")
}
