package top.core.backend.exu

import chisel3._
import chisel3.util.{Decoupled, MuxLookup, Valid}
import top.core.backend.bundle.{BranchResolve, IssuePortStatus, IssueWakeup, RobWritebackPacket}
import top.core.backend.csr.{CsrOp, CsrReadPort}
import top.core.backend.decoder.FuType
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.backend.fu.{ALU, BRU, CSR, DIV, JMP, MUL}
import top.core.bundle.{CfiType, RobAge, RobRecovery}
import top.core.trace.DivPerfTrace
import top.config.BackendConfig

class IntExeUnit(
  cfg:    BackendConfig = BackendConfig(),
  params: IntExeUnitConfig = IntExeUnitConfig.aluBjuCsr)
    extends Module {
  val io = IO(new Bundle {
    val in      = Flipped(Decoupled(new ExuRequest(cfg)))
    val flush   = Input(Bool())
    val recover = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead = Input(UInt(cfg.robIdxWidth.W))
    val status  = Output(new IssuePortStatus)
    val csrRead = new CsrReadPort(cfg)

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
    val resolve   = Output(Valid(new BranchResolve(cfg)))
    val divPerf   = Output(new DivPerfTrace)
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
  private val mulOutValid = mul.map(_.io.out.valid).getOrElse(false.B)
  private val mulInReady  = mul.map(_.io.in.ready).getOrElse(false.B)
  private val divOutValid = div.map(_.io.out.valid).getOrElse(false.B)
  private val divInReady  = div.map(_.io.in.ready).getOrElse(false.B)

  // Immediate (ALU/BJU/CSR) results are combinational with issue and cannot wait for the single
  // writeback port. When a MUL/DIV result owns the port, an immediate result parks in a one-deep
  // skid register and immediate issue blocks only while the skid is occupied. MUL/DIV results are
  // already registered and wait in a one-deep hold instead, so neither blocks the other's issue.
  private val skidValid        = RegInit(false.B)
  private val skidBits         = RegInit(0.U.asTypeOf(new ExuResult(cfg)))
  private val mulHoldValid     = RegInit(false.B)
  private val mulHoldBits      = RegInit(0.U.asTypeOf(new ExuResult(cfg)))
  private val immediateFuReady = !skidValid

  private val mulMeta0 = RegInit(0.U.asTypeOf(Valid(new ExuResult(cfg))))
  private val mulMeta1 = RegInit(0.U.asTypeOf(Valid(new ExuResult(cfg))))
  private val divMeta  = RegInit(0.U.asTypeOf(Valid(new ExuResult(cfg))))

  private def killedByRecovery(robIdx: UInt): Bool =
    io.recover.valid && RobAge.isYounger(robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

  io.divPerf := 0.U.asTypeOf(new DivPerfTrace)
  div.foreach { unit => io.divPerf := unit.io.perf }

  io.status.alu := has(ExuFuKind.Alu).B && immediateFuReady
  io.status.mul := has(ExuFuKind.Mul).B && mulInReady
  io.status.div := has(ExuFuKind.Div).B && divInReady
  io.status.bru := has(ExuFuKind.Bru).B && immediateFuReady
  io.status.jmp := has(ExuFuKind.Jmp).B && immediateFuReady
  io.status.csr := has(ExuFuKind.Csr).B && immediateFuReady

  io.csrRead.addr := Mux(io.in.valid && io.in.bits.fuType === FuType.csr, io.in.bits.csrAddr, 0.U)

  private val isMulReq        = io.in.bits.fuType === FuType.mul
  private val isDivReq        = io.in.bits.fuType === FuType.div
  private val selectedFuReady = Mux(isMulReq, mulInReady, Mux(isDivReq, divInReady, immediateFuReady))
  io.in.ready := supports(io.in.bits.fuType) && selectedFuReady

  alu.foreach { unit =>
    unit.io.src1 := io.in.bits.src1
    unit.io.src2 := io.in.bits.src2
    unit.io.op   := io.in.bits.fuOp
  }

  mul.foreach { unit =>
    unit.io.flush        := io.flush
    unit.io.in.valid     := io.in.fire && isMulReq && !io.flush && !io.recover.valid
    unit.io.in.bits.src1 := io.in.bits.src1
    unit.io.in.bits.src2 := io.in.bits.src2
    unit.io.in.bits.op   := io.in.bits.fuOp
  }

  div.foreach { unit =>
    unit.io.flush        := io.flush || (divMeta.valid && killedByRecovery(divMeta.bits.robIdx))
    unit.io.in.valid     := io.in.fire && isDivReq && !io.flush && !io.recover.valid
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

  private val mulIssue = io.in.fire && isMulReq && !io.flush && !io.recover.valid
  private val divIssue = io.in.fire && isDivReq && !io.flush && !io.recover.valid

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
    mulMeta1.valid := mulMeta0.valid && !killedByRecovery(mulMeta0.bits.robIdx)
    mulMeta1.bits  := mulMeta0.bits

    mulMeta0.valid := mulIssue
    mulMeta0.bits  := mulIssueResult

    when(divIssue) {
      divMeta.valid := true.B
      divMeta.bits  := divIssueResult
    }.elsewhen(divOutValid || (divMeta.valid && killedByRecovery(divMeta.bits.robIdx))) {
      divMeta.valid := false.B
    }
  }

  private val exuResult = Wire(Valid(new ExuResult(cfg)))
  exuResult.valid := io.in.fire && !io.flush && !io.recover.valid && !isMulReq && !isDivReq
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

  private val liveDivResult = divResult.valid && !killedByRecovery(divResult.bits.robIdx)
  private val liveMulResult = mulResult.valid && !killedByRecovery(mulResult.bits.robIdx)
  private val liveExuResult = exuResult.valid && !killedByRecovery(exuResult.bits.robIdx)
  private val liveMulHold   = mulHoldValid && !killedByRecovery(mulHoldBits.robIdx)
  private val liveSkid      = skidValid && !killedByRecovery(skidBits.robIdx)

  // Single writeback port arbitration: DIV > held MUL > fresh MUL > skidded immediate > fresh immediate.
  private val wbDiv     = liveDivResult
  private val wbMulHold = !wbDiv && liveMulHold
  private val wbMul     = !wbDiv && !wbMulHold && liveMulResult
  private val wbSkid    = !wbDiv && !wbMulHold && !wbMul && liveSkid
  private val wbAlu     = !wbDiv && !wbMulHold && !wbMul && !wbSkid && liveExuResult

  // A fresh MUL result is blocked only by a DIV writeback or by an older held MUL draining this
  // cycle. DIV results pulse at most once per division (33+ cycles apart), so the one-deep hold
  // can never overflow.
  private val mulResultBlocked = liveMulResult && (wbDiv || wbMulHold)
  private val aluResultBlocked = liveExuResult && (wbDiv || wbMulHold || wbMul)
  when(io.flush) {
    mulHoldValid := false.B
    skidValid    := false.B
  }.otherwise {
    when(mulResultBlocked) {
      mulHoldValid := true.B
      mulHoldBits  := mulResult.bits
    }.elsewhen(wbMulHold || killedByRecovery(mulHoldBits.robIdx)) {
      mulHoldValid := false.B
    }
    when(aluResultBlocked) {
      skidValid := true.B
      skidBits  := exuResult.bits
    }.elsewhen(wbSkid || killedByRecovery(skidBits.robIdx)) {
      skidValid := false.B
    }
  }

  private val writebackResult = Wire(Valid(new ExuResult(cfg)))
  writebackResult.valid := wbDiv || wbMulHold || wbMul || wbSkid || wbAlu
  writebackResult.bits  := Mux(
    wbDiv,
    divResult.bits,
    Mux(wbMulHold, mulHoldBits, Mux(wbMul, mulResult.bits, Mux(wbSkid, skidBits, exuResult.bits)))
  )

  private val resolveInput = Wire(Valid(new BranchResolve(cfg)))
  resolveInput                      := 0.U.asTypeOf(Valid(new BranchResolve(cfg)))
  resolveInput.valid                := liveExuResult && io.in.bits.cfi =/= CfiType.none
  resolveInput.bits.robIdx          := io.in.bits.robIdx
  resolveInput.bits.pc              := io.in.bits.fetch.pc
  resolveInput.bits.cfiType         := io.in.bits.cfi
  resolveInput.bits.predNpc         := io.in.bits.fetch.predNpc
  resolveInput.bits.actualNpc       := exuResult.bits.redirectTarget
  resolveInput.bits.taken           := exuResult.bits.branchTaken
  resolveInput.bits.branchTarget    := exuResult.bits.branchTarget
  resolveInput.bits.instLen         := io.in.bits.fetch.instLen
  resolveInput.bits.ftqTag          := io.in.bits.fetch.ftqTag
  resolveInput.bits.ftqInstOrdinal  := io.in.bits.fetch.ftqInstOrdinal
  resolveInput.bits.rasAction       := top.core.frontend.bundle.RasAction.action(io.in.bits.fetch.inst)
  resolveInput.bits.canonicalReturn := top.core.frontend.bundle.RasAction.isCanonicalReturn(io.in.bits.fetch.inst)

  private val resolveReg = RegInit(0.U.asTypeOf(Valid(new BranchResolve(cfg))))
  when(io.flush) {
    resolveReg.valid := false.B
  }.otherwise {
    resolveReg := resolveInput
  }

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
  io.resolve       := resolveReg

  assert(!io.in.fire || supports(io.in.bits.fuType), s"${params.name} accepted an unsupported FU type")
}
