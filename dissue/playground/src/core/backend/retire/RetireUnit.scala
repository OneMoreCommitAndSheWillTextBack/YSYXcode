package top.core.backend.retire

import chisel3._
import chisel3.util.{Decoupled, Enum, Mux1H, PopCount, PriorityEncoderOH, Valid}
import top.core.backend.bundle.{CommitRegWrite, RetireGroup, RobCommitPacket, ScoreboardCommit, StoreQueueCommit}
import top.core.backend.csr.{
  CsrArch,
  CsrAddr,
  CsrCommit,
  CsrContextUpdate,
  CsrInterrupt,
  CsrMretCommit,
  CsrSretCommit,
  CsrStatus,
  CsrTrackerCommit,
  CsrTrapCommit,
  Mstatus,
  PrivMode
}
import top.core.backend.exception.{ExceptionCause, ExceptionInfo, TrapLane, TrapUnit}
import top.core.bundle.{BackendToFrontend, CfiType, DataMemKind, DataMemReq, DataMemTxn}
import top.config.BackendConfig
import top.sim.BpuPerfBridge

class RetireUnit(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val rob = Vec(cfg.commitWidth, Flipped(Decoupled(new RobCommitPacket(cfg))))

    val regWrite         = Output(Vec(cfg.commitWidth, new CommitRegWrite(cfg)))
    val scoreboardCommit = Output(Vec(cfg.commitWidth, new ScoreboardCommit(cfg)))
    val storeCommit      = Output(Vec(cfg.commitWidth, new StoreQueueCommit(cfg)))
    val csrCommit        = Output(Vec(cfg.commitWidth, Valid(new CsrCommit(cfg))))
    val csrTrackerCommit = Output(Vec(cfg.commitWidth, new CsrTrackerCommit(cfg)))
    val csrTrap          = Output(new CsrTrapCommit(cfg))
    val csrMret          = Output(new CsrMretCommit(cfg))
    val csrSret          = Output(new CsrSretCommit(cfg))
    val csrStatus        = Input(new CsrStatus(cfg))
    val hold             = Input(Bool())
    val storesDrained    = Input(Bool())
    val retire           = Output(new RetireGroup(cfg))
    val redirect         = Output(new BackendToFrontend(cfg.addrWidth))

    val fenceIReq    = Decoupled(Bool())
    val fenceIDone   = Input(Bool())
    val fenceIActive = Output(Bool())

    val dmemReq        = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val storeReqRobIdx = Output(UInt(cfg.robIdxWidth.W))

    val context = Output(new CsrContextUpdate(cfg))
  })

  private def orReduce(values: Seq[Bool]): Bool =
    if (values.isEmpty) false.B else values.reduce(_ || _)

  private def andReduce(values: Seq[Bool]): Bool =
    if (values.isEmpty) true.B else values.reduce(_ && _)

  private val redirectCandidate = Wire(Vec(cfg.commitWidth, Bool()))
  private val trapCandidate     = Wire(Vec(cfg.commitWidth, Bool()))
  private val laneBoundary      = Wire(Vec(cfg.commitWidth, Bool()))
  private val preRetire         = Wire(Vec(cfg.commitWidth, Bool()))
  private val storeCandidate    = Wire(Vec(cfg.commitWidth, Bool()))
  private val canRetire         = Wire(Vec(cfg.commitWidth, Bool()))
  private val nextPc            = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))

  private val fenceIIdle :: fenceIWait :: fenceIComplete :: Nil = Enum(3)
  private val fenceIState = RegInit(fenceIIdle)
  private val fenceIHead  = io.rob(0).valid && io.rob(0).bits.isFenceI

  io.fenceIReq.valid := fenceIHead && !io.hold && fenceIState === fenceIIdle && io.storesDrained
  io.fenceIReq.bits  := true.B
  io.fenceIActive    := fenceIHead && fenceIState =/= fenceIIdle

  when(!fenceIHead) {
    fenceIState := fenceIIdle
  }.elsewhen(fenceIState === fenceIIdle && io.fenceIReq.fire) {
    fenceIState := fenceIWait
  }.elsewhen(fenceIState === fenceIWait && io.fenceIDone) {
    fenceIState := fenceIComplete
  }

  for (i <- 0 until cfg.commitWidth) {
    redirectCandidate(i) :=
      io.rob(i).valid &&
        io.rob(i).bits.redirectValid &&
        io.rob(i).bits.fetch.predNpc =/= io.rob(i).bits.redirectTarget

    trapCandidate(i) := io.rob(i).valid && io.rob(i).bits.hasTrapAtRetire

    // Serializing instructions still form a retirement boundary. Branch recovery is handled by the execution-stage
    // RecoveryUnit, so a resolved CFI no longer waits here before frontend redirect.
    laneBoundary(i) :=
      trapCandidate(i) || io.rob(i).bits.isMret || io.rob(i).bits.isSret ||
        io.rob(i).bits.isFence || (io.rob(i).bits.isCsr && io.rob(i).bits.csrWen)

    // can retire: rob.valid && preinst could retire
    preRetire(i) :=
      !io.hold && io.rob(i).valid &&
        (if (i == 0) true.B else preRetire(i - 1) && !laneBoundary(i - 1))

    val olderStore = orReduce((0 until i).map(j => preRetire(j) && io.rob(j).bits.isStore && !trapCandidate(j)))
    storeCandidate(i) := preRetire(i) && io.rob(i).bits.isStore && !trapCandidate(i) && !olderStore

    nextPc(i) := Mux(
      io.rob(i).bits.redirectValid,
      io.rob(i).bits.redirectTarget,
      io.rob(i).bits.fetch.pc +% io.rob(i).bits.fetch.instLen
    )
  }

  private val storeReq = Wire(Vec(cfg.commitWidth, new DataMemReq(cfg.addrWidth, cfg.dataWidth)))
  for (i <- 0 until cfg.commitWidth) {
    storeReq(i)           := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    storeReq(i).addr      := io.rob(i).bits.storeAddr
    storeReq(i).write     := true.B
    storeReq(i).size      := io.rob(i).bits.memSize
    storeReq(i).unsigned  := false.B
    storeReq(i).wdata     := io.rob(i).bits.storeData
    storeReq(i).wmask     := io.rob(i).bits.storeMask
    storeReq(i).txnId     := DataMemTxn.store
    storeReq(i).cacheable := true.B
    storeReq(i).kind      := DataMemKind.normal
  }

  private val storeGrantOH = PriorityEncoderOH(storeCandidate.asUInt).asBools
  io.dmemReq.valid  := storeCandidate.asUInt.orR
  io.dmemReq.bits   := Mux1H(storeGrantOH, storeReq)
  io.storeReqRobIdx := Mux1H(storeGrantOH, io.rob.map(_.bits.robIdx))

  for (i <- 0 until cfg.commitWidth) {
    val olderRetired = andReduce((0 until i).map(j => canRetire(j)))
    val storeReady   = !io.rob(i).bits.isStore || trapCandidate(i) || (storeCandidate(i) && io.dmemReq.ready)

    val fenceReady = !io.rob(i).bits.isFenceI || (if (i == 0) fenceIState === fenceIComplete else false.B)
    canRetire(i)    := preRetire(i) && olderRetired && storeReady && fenceReady
    io.rob(i).ready := canRetire(i)
  }

  io.redirect := 0.U.asTypeOf(new BackendToFrontend(cfg.addrWidth))

  private val trapUnit = Module(new TrapUnit(cfg))
  trapUnit.io.csrStatus := io.csrStatus
  for (i <- 0 until cfg.commitWidth) {
    trapUnit.io.lanes(i)           := 0.U.asTypeOf(new TrapLane(cfg))
    trapUnit.io.lanes(i).valid     := canRetire(i)
    trapUnit.io.lanes(i).pc        := io.rob(i).bits.fetch.pc
    trapUnit.io.lanes(i).inst      := io.rob(i).bits.fetch.rawInst
    trapUnit.io.lanes(i).exception := io.rob(i).bits.exception
    trapUnit.io.lanes(i).isEcall   := io.rob(i).bits.isEcall
    trapUnit.io.lanes(i).isMret    := io.rob(i).bits.isMret
    trapUnit.io.lanes(i).isSret    := io.rob(i).bits.isSret
    trapUnit.io.lanes(i).isSfence  := io.rob(i).bits.isSfence
  }

  private val trapRetire = trapUnit.io.trapMask.asBools
  private val mretRetire = trapUnit.io.mretMask.asBools
  private val sretRetire = trapUnit.io.sretMask.asBools

  // no priv change
  private val normalCommit = Wire(Vec(cfg.commitWidth, Bool()))
  for (i <- 0 until cfg.commitWidth) {
    normalCommit(i) := canRetire(i) && !trapRetire(i) && !mretRetire(i) && !sretRetire(i)
  }

  private val bpuPerf = Seq.fill(cfg.commitWidth)(Module(new BpuPerfBridge))
  for (i <- 0 until cfg.commitWidth) {
    bpuPerf(i).io.valid   := !reset.asBool && normalCommit(i) && (io.rob(i).bits.cfi =/= CfiType.none)
    bpuPerf(i).io.correct := io.rob(i).bits.fetch.predNpc === nextPc(i)
  }

  private val barrierCommit = Wire(Vec(cfg.commitWidth, Bool()))
  for (i <- 0 until cfg.commitWidth) {
    barrierCommit(i) := normalCommit(i) && (io.rob(i).bits.isFence || (io.rob(i).bits.isCsr && io.rob(i).bits.csrWen))
  }

  private val frontendRedirectCommit = VecInit((0 until cfg.commitWidth).map(i => barrierCommit(i)))
  private val frontendRedirectTarget = VecInit((0 until cfg.commitWidth).map(i => nextPc(i)))

  private def csrBit(bit: Int): UInt =
    (1.U(cfg.dataWidth.W) << bit)(cfg.dataWidth - 1, 0)

  private def bitPending(bits: UInt, bit: Int): Bool =
    (bits & csrBit(bit)).orR

  private val pendingEnabled    = io.csrStatus.mip & io.csrStatus.mie
  private val machinePending    = pendingEnabled & ~io.csrStatus.mideleg
  private val supervisorPending = pendingEnabled & io.csrStatus.mideleg

  private val machineGlobal    =
    io.csrStatus.priv.mode =/= PrivMode.M || io.csrStatus.mstatus(Mstatus.mieBit)
  private val supervisorGlobal =
    io.csrStatus.priv.mode === PrivMode.U ||
      (io.csrStatus.priv.mode === PrivMode.S && io.csrStatus.mstatus(Mstatus.sieBit))

  private val mMeip = bitPending(machinePending, CsrInterrupt.meipBit)
  private val mMsip = bitPending(machinePending, CsrInterrupt.msipBit)
  private val mMtip = bitPending(machinePending, CsrInterrupt.mtipBit)
  private val mSeip = bitPending(machinePending, CsrInterrupt.seipBit)
  private val mSsip = bitPending(machinePending, CsrInterrupt.ssipBit)
  private val mStip = bitPending(machinePending, CsrInterrupt.stipBit)

  private val sSeip = bitPending(supervisorPending, CsrInterrupt.seipBit)
  private val sSsip = bitPending(supervisorPending, CsrInterrupt.ssipBit)
  private val sStip = bitPending(supervisorPending, CsrInterrupt.stipBit)

  private val machineInterruptValid    =
    machineGlobal && (mMeip || mMsip || mMtip || mSeip || mSsip || mStip)
  private val supervisorInterruptValid =
    supervisorGlobal && (sSeip || sSsip || sStip)

  private val machineInterruptCause = Mux(
    mMeip,
    ExceptionCause.machineExternalInterrupt,
    Mux(
      mMsip,
      ExceptionCause.machineSoftwareInterrupt,
      Mux(
        mMtip,
        ExceptionCause.machineTimerInterrupt,
        Mux(
          mSeip,
          ExceptionCause.supervisorExternalInterrupt,
          Mux(mSsip, ExceptionCause.supervisorSoftwareInterrupt, ExceptionCause.supervisorTimerInterrupt)
        )
      )
    )
  )

  private val supervisorInterruptCause = Mux(
    sSeip,
    ExceptionCause.supervisorExternalInterrupt,
    Mux(sSsip, ExceptionCause.supervisorSoftwareInterrupt, ExceptionCause.supervisorTimerInterrupt)
  )

  private val interruptToSupervisor = !machineInterruptValid && supervisorInterruptValid
  private val interruptCause        = Mux(machineInterruptValid, machineInterruptCause, supervisorInterruptCause)
  private val interruptInfo         = ExceptionInfo.interrupt(interruptCause, cfg)

  // no priv change && no redir && at least one commit (for mepc)
  private val canTakeInterrupt =
    !trapUnit.io.redirect.valid &&
      !frontendRedirectCommit.asUInt.orR &&
      canRetire.asUInt.orR &&
      (machineInterruptValid || supervisorInterruptValid)

  private val interruptTarget = CsrArch.trapVector(
    interruptToSupervisor,
    io.csrStatus.mtvec,
    io.csrStatus.stvec,
    interruptInfo.cause,
    true.B,
    cfg
  )

  io.csrTrap.valid        := trapUnit.io.trap.valid || canTakeInterrupt
  io.csrTrap.toSupervisor := Mux(trapUnit.io.trap.valid, trapUnit.io.trap.toSupervisor, interruptToSupervisor)
  io.csrTrap.epc          := Mux(trapUnit.io.trap.valid, trapUnit.io.trap.epc, io.retire.finalPc)
  io.csrTrap.cause        := Mux(trapUnit.io.trap.valid, trapUnit.io.trap.cause, interruptInfo.csrCause)
  io.csrTrap.tval         := Mux(trapUnit.io.trap.valid, trapUnit.io.trap.tval, 0.U)
  io.csrMret              := trapUnit.io.mret
  io.csrSret              := trapUnit.io.sret

  io.redirect.trapRedirect.valid  := trapUnit.io.redirect.valid || canTakeInterrupt
  io.redirect.trapRedirect.target := Mux(trapUnit.io.redirect.valid, trapUnit.io.redirect.target, interruptTarget)

  private val redirectGrantOH = PriorityEncoderOH(frontendRedirectCommit.asUInt).asBools
  io.redirect.branchRedirect.valid  := frontendRedirectCommit.asUInt.orR
  io.redirect.branchRedirect.target := Mux1H(
    redirectGrantOH,
    frontendRedirectTarget
  )

  private val fenceICommit = VecInit((0 until cfg.commitWidth).map { i =>
    normalCommit(i) && io.rob(i).bits.isFenceI
  }).asUInt.orR
  private val sfenceCommit = VecInit((0 until cfg.commitWidth).map { i =>
    normalCommit(i) && io.rob(i).bits.isSfence
  }).asUInt.orR
  private val satpWriteCommit = VecInit((0 until cfg.commitWidth).map { i =>
    normalCommit(i) && io.rob(i).bits.isCsr && io.rob(i).bits.csrWen &&
      io.rob(i).bits.csrAddr === CsrAddr("satp")
  }).asUInt.orR
  private val privilegeTransition = io.redirect.trapRedirect.valid || io.csrMret.valid || io.csrSret.valid

  io.redirect.icacheInvalidate := fenceICommit || sfenceCommit || satpWriteCommit || privilegeTransition

  private val bpuUpdateValid   = Wire(Vec(cfg.commitWidth, Bool()))
  private val bpuUpdatePc      = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))
  private val bpuUpdateType    = Wire(Vec(cfg.commitWidth, UInt(CfiType.width.W)))
  private val bpuUpdateTaken   = Wire(Vec(cfg.commitWidth, Bool()))
  private val bpuUpdateTarget  = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))
  private val bpuUpdateInstLen = Wire(Vec(cfg.commitWidth, UInt(3.W)))

  io.retire := 0.U.asTypeOf(new RetireGroup(cfg))

  for (i <- 0 until cfg.commitWidth) {
    io.regWrite(i).enable := normalCommit(i) && io.rob(i).bits.rfWen
    io.regWrite(i).addr   := io.rob(i).bits.rd
    io.regWrite(i).data   := io.rob(i).bits.result

    io.scoreboardCommit(i).valid  := normalCommit(i)
    io.scoreboardCommit(i).rd     := io.rob(i).bits.rd
    io.scoreboardCommit(i).rfWen  := io.rob(i).bits.rfWen
    io.scoreboardCommit(i).robIdx := io.rob(i).bits.robIdx

    io.storeCommit(i).valid  := normalCommit(i) && io.rob(i).bits.isStore
    io.storeCommit(i).robIdx := io.rob(i).bits.robIdx

    io.csrCommit(i).valid      := normalCommit(i) && io.rob(i).bits.isCsr && io.rob(i).bits.csrWen
    io.csrCommit(i).bits.addr  := io.rob(i).bits.csrAddr
    io.csrCommit(i).bits.wdata := io.rob(i).bits.csrWdata

    io.csrTrackerCommit(i).valid  := normalCommit(i) && io.rob(i).bits.isCsr && io.rob(i).bits.csrWen
    io.csrTrackerCommit(i).robIdx := io.rob(i).bits.robIdx

    io.retire.lanes(i).valid       := canRetire(i)
    io.retire.lanes(i).robIdx      := io.rob(i).bits.robIdx
    io.retire.lanes(i).fetch       := io.rob(i).bits.fetch
    io.retire.lanes(i).nextPc      := nextPc(i)
    io.retire.lanes(i).rf          := io.regWrite(i)
    io.retire.lanes(i).store.valid := normalCommit(i) && io.rob(i).bits.isStore
    io.retire.lanes(i).store.addr  := io.rob(i).bits.storeAddr
    io.retire.lanes(i).store.data  := io.rob(i).bits.storeData
    io.retire.lanes(i).store.mask  := io.rob(i).bits.storeMask
    io.retire.lanes(i).store.size  := io.rob(i).bits.memSize
    val isLr            = io.rob(i).bits.isAmo && io.rob(i).bits.fetch.rawInst(31, 27) === "b00010".U
    val isSc            = io.rob(i).bits.isAmo && io.rob(i).bits.fetch.rawInst(31, 27) === "b00011".U
    val amoWritesMemory = io.rob(i).bits.isAmo && !isLr && !(isSc && io.rob(i).bits.result =/= 0.U)
    io.retire.lanes(i).memory.valid            :=
      normalCommit(i) && (io.rob(i).bits.isLoad || io.rob(i).bits.isStore || io.rob(i).bits.isAmo)
    io.retire.lanes(i).memory.write            := normalCommit(i) && (io.rob(i).bits.isStore || amoWritesMemory)
    io.retire.lanes(i).memory.addr             := io.rob(i).bits.storeAddr
    io.retire.lanes(i).memory.size             := io.rob(i).bits.memSize
    io.retire.lanes(i).control.redirectValid   := normalCommit(i) && redirectCandidate(i)
    io.retire.lanes(i).control.redirectTarget  := io.rob(i).bits.redirectTarget
    io.retire.lanes(i).control.branchTaken     := io.rob(i).bits.branchTaken
    io.retire.lanes(i).control.branchTarget    := io.rob(i).bits.branchTarget
    io.retire.lanes(i).exception.valid         := trapRetire(i)
    io.retire.lanes(i).exception.interrupt     := trapUnit.io.laneException(i).interrupt
    io.retire.lanes(i).exception.cause         := trapUnit.io.laneException(i).cause
    io.retire.lanes(i).exception.tval          := trapUnit.io.laneException(i).tval
    io.retire.lanes(i).exception.blocksYounger := trapRetire(i)
    io.retire.lanes(i).finish                  := canRetire(i) && io.rob(i).bits.isEbreak

    bpuUpdateValid(i)   := normalCommit(i) && (io.rob(i).bits.cfi =/= CfiType.none)
    bpuUpdatePc(i)      := io.rob(i).bits.fetch.pc
    bpuUpdateType(i)    := io.rob(i).bits.cfi
    bpuUpdateTaken(i)   := io.rob(i).bits.branchTaken
    bpuUpdateTarget(i)  := io.rob(i).bits.branchTarget
    bpuUpdateInstLen(i) := io.rob(i).bits.fetch.instLen
  }

  io.retire.validMask  := canRetire.asUInt
  io.retire.finishMask := VecInit((0 until cfg.commitWidth).map(i => canRetire(i) && io.rob(i).bits.isEbreak)).asUInt

  private val latestRetireOH = VecInit((0 until cfg.commitWidth).map { i =>
    val noYoungerRetire = !orReduce(((i + 1) until cfg.commitWidth).map(j => canRetire(j)))
    canRetire(i) && noYoungerRetire
  })

  io.retire.finalPc := Mux(
    io.retire.validMask.orR,
    Mux1H(latestRetireOH, nextPc),
    0.U
  )

  private val bpuUpdateGrantOH = PriorityEncoderOH(bpuUpdateValid.asUInt).asBools
  io.redirect.bpuUpdate.valid        := bpuUpdateValid.asUInt.orR
  io.redirect.bpuUpdate.bits.pc      := Mux1H(bpuUpdateGrantOH, bpuUpdatePc)
  io.redirect.bpuUpdate.bits.cfiType := Mux1H(bpuUpdateGrantOH, bpuUpdateType)
  io.redirect.bpuUpdate.bits.taken   := Mux1H(bpuUpdateGrantOH, bpuUpdateTaken)
  io.redirect.bpuUpdate.bits.target  := Mux1H(bpuUpdateGrantOH, bpuUpdateTarget)
  io.redirect.bpuUpdate.bits.instLen := Mux1H(bpuUpdateGrantOH, bpuUpdateInstLen)

  io.context.valid := io.retire.validMask.orR
  io.context.pc    := Mux(
    io.redirect.trapRedirect.valid,
    io.redirect.trapRedirect.target,
    Mux(trapUnit.io.mret.valid || trapUnit.io.sret.valid, trapUnit.io.redirect.target, io.retire.finalPc)
  )

  if (cfg.commitWidth > 1) {
    assert(!canRetire.asUInt(cfg.commitWidth - 1, 1).orR || canRetire(0))
  }
  assert(PopCount((0 until cfg.commitWidth).map(i => canRetire(i) && io.rob(i).bits.isStore)) <= 1.U)
  for (i <- 1 until cfg.commitWidth) {
    assert(!(canRetire(i) && orReduce((0 until i).map(j => canRetire(j) && laneBoundary(j)))))
  }
  for (i <- 0 until cfg.commitWidth) {
    assert(!(trapRetire(i) && normalCommit(i)))
    assert(!(mretRetire(i) && normalCommit(i)))
    assert(!(sretRetire(i) && normalCommit(i)))
    assert(!(trapRetire(i) && io.regWrite(i).enable))
    assert(!(trapRetire(i) && io.storeCommit(i).valid))
    assert(!(trapRetire(i) && io.csrCommit(i).valid))
    assert(!(mretRetire(i) && io.regWrite(i).enable))
    assert(!(mretRetire(i) && io.storeCommit(i).valid))
    assert(!(mretRetire(i) && io.csrCommit(i).valid))
    assert(!(sretRetire(i) && io.regWrite(i).enable))
    assert(!(sretRetire(i) && io.storeCommit(i).valid))
    assert(!(sretRetire(i) && io.csrCommit(i).valid))
  }
  assert(PopCount(trapRetire) <= 1.U)
  assert(PopCount(mretRetire) <= 1.U)
  assert(PopCount(sretRetire) <= 1.U)
  assert(PopCount(VecInit(Seq(io.csrTrap.valid, trapUnit.io.mret.valid, trapUnit.io.sret.valid))) <= 1.U)
  assert(!(io.redirect.trapRedirect.valid && io.redirect.branchRedirect.valid))
}
