package top.core.backend

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, Enum, PopCount, Valid}
import top.core.bundle._
import top.config.BackendConfig

import top.core.backend.bundle.{
  BackendMemPerf,
  BackendMonitor,
  DecodePacket,
  IssuePortStatus,
  IssueWakeup,
  RetireGroup,
  RobWritebackPacket
}
import top.core.backend.csr.{CsrFile, CsrInterruptPending, CsrStatus, CsrTracker}
import top.core.backend.decoder._
import top.core.backend.dispatch.{Dispatch, Scoreboard}
import top.core.backend.exception.ExceptionInfo
import top.core.backend.exu.{ExecuteBlock, ExuRequest}
import top.core.backend.issue.IssueQueue
import top.core.backend.lsu.LSU
import top.core.backend.regfile._
import top.core.backend.retire.RetireUnit
import top.core.backend.rob.ROB
import top.sim.{BackendPerfBridge, DifftestMonitor}

class Backend(
  resetVector:    BigInt = BigInt("80000000", 16),
  cfg:            BackendConfig = BackendConfig(),
  enableMonitor:  Boolean = true,
  enableDifftest: Boolean = true,
  enablePerf:     Boolean = true)
    extends Module {
  require(cfg.issueWidth > 0, "Backend requires at least one frontend slot")
  require(cfg.writebackWidth >= cfg.intIssueWidth + 1, "Backend reserves writeback ports for integer EXUs and LSU")

  val io = IO(new Bundle {
    val frontend = Flipped(Decoupled(new FrontendToBackend(cfg.issueWidth, cfg.frontendPayload)))
    val redirect = Output(new BackendToFrontend(cfg.frontendPayload))

    val dmemReq    = Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
    val dmemResp   = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val dmemCancel = Input(Vec(cfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))

    val fenceIReq  = Decoupled(Bool())
    val fenceIDone = Input(Bool())

    val recover       = Output(new RobRecovery(cfg.robIdxWidth))
    val globalFlush   = Output(Bool())
    val robHead       = Output(UInt(cfg.robIdxWidth.W))
    val unresolvedCfi = Output(Vec(cfg.robEntries, Bool()))
    val storesDrained = Output(Bool())
    val memoryIdle    = Output(Bool())

    val retire    = Output(new RetireGroup(cfg))
    val csrStatus = Output(new CsrStatus(cfg))
    val memPerf   = Output(new BackendMemPerf(cfg))
    val interrupt = Input(new CsrInterruptPending)
    val mtime     = Input(UInt(64.W))
    val monitor   = Output(new BackendMonitor(cfg))
  })

  private val slotIdxWidth   = math.max(log2Ceil(cfg.issueWidth), 1)
  private val slotCountWidth = math.max(log2Ceil(cfg.issueWidth + 1), 1)

  val gpr        = Module(new RegFile(cfg))
  val decoder    = Seq.fill(cfg.dispatchWidth)(Module(new Decoder(cfg)))
  val dispatch   = Module(new Dispatch(cfg))
  val scoreboard = Module(new Scoreboard(cfg))
  val rob        = Module(new ROB(cfg))
  val issueQueue = Module(new IssueQueue(cfg))
  val execute    = Module(new ExecuteBlock(cfg))
  val lsu        = Module(new LSU(cfg))
  val csrFile    = Module(new CsrFile(resetVector, cfg))
  val csrTracker = Module(new CsrTracker(cfg))
  val retire     = Module(new RetireUnit(cfg))
  val recovery   = Module(new RecoveryUnit(cfg))

  io.csrStatus := csrFile.io.status

  private val globalFlush =
    retire.io.redirect.trapRedirect.valid ||
      retire.io.redirect.branchRedirect.valid ||
      retire.io.redirect.predRedirect.valid

  recovery.io.resolve := execute.io.resolve
  recovery.io.robHead := rob.io.head

  private val selectiveRecovery = Wire(new RobRecovery(cfg.robIdxWidth))
  selectiveRecovery.valid  := recovery.io.recover.valid
  selectiveRecovery.robIdx := recovery.io.recover.robIdx

  private val backendBlocked = globalFlush || selectiveRecovery.valid || retire.io.fenceIActive

  io.recover                        := selectiveRecovery
  io.globalFlush                    := globalFlush
  io.robHead                        := rob.io.head
  io.unresolvedCfi                  := rob.io.unresolvedCfi
  io.redirect                       := retire.io.redirect
  io.redirect.branchRedirect.valid  := retire.io.redirect.branchRedirect.valid || selectiveRecovery.valid
  io.redirect.branchRedirect.target := Mux(
    retire.io.redirect.branchRedirect.valid,
    retire.io.redirect.branchRedirect.target,
    recovery.io.redirect.target
  )
  io.redirect.cfiRecovery           := recovery.io.cfiRecovery

  private val fetchReg = RegInit(0.U.asTypeOf(new FrontendToBackend(cfg.issueWidth, cfg.frontendPayload)))
  private val pending  = RegInit(false.B)
  private val slotIdx  = RegInit(0.U(slotIdxWidth.W))

  val dispatchFetch  = Wire(Vec(cfg.dispatchWidth, Valid(new FetchInstPayload(cfg.frontendPayload))))
  val dispatchDecode = Wire(Vec(cfg.dispatchWidth, new DecodePacket(cfg)))
  val laneInRange    = Wire(Vec(cfg.dispatchWidth, Bool()))

  for (lane <- 0 until cfg.dispatchWidth) {
    val laneSlot = Wire(UInt(slotCountWidth.W))
    laneSlot          := slotIdx + lane.U(slotCountWidth.W)
    laneInRange(lane) := laneSlot < cfg.issueWidth.U

    dispatchFetch(lane) := 0.U.asTypeOf(Valid(new FetchInstPayload(cfg.frontendPayload)))
    for (slot <- 0 until cfg.issueWidth) {
      when(laneSlot === slot.U) {
        dispatchFetch(lane) := fetchReg.insts(slot)
      }
    }

    decoder(lane).io.in := dispatchFetch(lane).bits
    val slotValid        = pending && !backendBlocked && laneInRange(lane) && dispatchFetch(lane).valid
    val decodedException = Wire(new ExceptionInfo(cfg))
    decodedException       := decoder(lane).io.out.exception
    decodedException.valid := slotValid && decoder(lane).io.out.exception.valid

    dispatchDecode(lane)           := decoder(lane).io.out
    dispatchDecode(lane).valid     := slotValid
    dispatchDecode(lane).exception := decodedException

    dispatch.io.in(lane)     := dispatchDecode(lane)
    dispatch.io.robIdx(lane) := rob.io.allocIdx(lane)
    dispatch.io.sqIdx(lane)  := Mux(dispatchDecode(lane).isStore, lsu.io.storeAllocSqIdx(lane), 0.U)

    val needsIssue      = dispatchDecode(lane).needsIssue
    val needsStoreQueue = needsIssue && dispatchDecode(lane).isStore
    val issueReady      = !needsIssue || issueQueue.io.enq(lane).ready
    val storeQueueReady = !needsStoreQueue || lsu.io.storeAllocReady(lane)

    dispatch.io.out(lane).ready := !backendBlocked && rob.io.alloc(lane).ready && issueReady && storeQueueReady

    rob.io.alloc(lane).valid       := !backendBlocked && dispatch.io.out(lane).valid &&
      issueReady && storeQueueReady
    rob.io.alloc(lane).bits.decode := dispatchDecode(lane)
    rob.io.alloc(lane).bits.sqIdx  := dispatch.io.out(lane).bits.sqIdx

    issueQueue.io
      .enq(lane)
      .valid                     := !backendBlocked && dispatch.io.out(lane).valid && rob.io.alloc(lane).ready &&
      needsIssue && storeQueueReady
    issueQueue.io.enq(lane).bits := dispatch.io.out(lane).bits

    lsu.io.storeAlloc(lane).valid  := !backendBlocked && dispatch.io.out(lane).valid && rob.io.alloc(lane).ready &&
      issueReady && needsStoreQueue
    lsu.io.storeAlloc(lane).robIdx := rob.io.allocIdx(lane)

    val storeAllocFire = lsu.io.storeAlloc(lane).valid && lsu.io.storeAllocReady(lane)
    when(!reset.asBool && needsStoreQueue && dispatch.io.out(lane).valid) {
      assert(dispatch.io.out(lane).fire === rob.io.alloc(lane).fire)
      assert(dispatch.io.out(lane).fire === issueQueue.io.enq(lane).fire)
      assert(dispatch.io.out(lane).fire === storeAllocFire)
    }
  }

  val laneConsumed = Wire(Vec(cfg.dispatchWidth, Bool()))
  for (lane <- 0 until cfg.dispatchWidth) {
    val skippedEmptySlot = pending && laneInRange(lane) && !dispatchFetch(lane).valid
    val consumedThisLane = skippedEmptySlot || dispatch.io.out(lane).fire
    laneConsumed(lane) := consumedThisLane && (if (lane == 0) true.B else laneConsumed(lane - 1))
  }

  val consumedCount = PopCount(laneConsumed)
  val nextSlotIdx   = slotIdx + consumedCount
  val packetDone    = (consumedCount =/= 0.U) && (nextSlotIdx >= cfg.issueWidth.U)

  // The buffer can accept a replacement when this cycle retires its final slot.
  io.frontend.ready := !backendBlocked && (!pending || packetDone)

  when(backendBlocked) {
    pending := false.B
    slotIdx := 0.U
  }.elsewhen(packetDone && io.frontend.fire) {
    fetchReg := io.frontend.bits
    pending  := true.B
    slotIdx  := 0.U
  }.elsewhen(packetDone) {
    pending := false.B
    slotIdx := 0.U
  }.elsewhen(pending && (consumedCount =/= 0.U)) {
    slotIdx := nextSlotIdx(slotIdxWidth - 1, 0)
  }.elsewhen(!pending && io.frontend.fire) {
    fetchReg := io.frontend.bits
    pending  := true.B
    slotIdx  := 0.U
  }

  for (i <- 0 until cfg.regfileReadPorts) {
    gpr.io.read(i).enable      := dispatch.io.rfRead(i).enable
    gpr.io.read(i).addr        := dispatch.io.rfRead(i).addr
    dispatch.io.rfRead(i).data := gpr.io.read(i).data
  }

  for (i <- 0 until cfg.scoreboardQueries) {
    scoreboard.io.query(i).valid := false.B
    scoreboard.io.query(i).rs    := 0.U
  }

  for (i <- 0 until cfg.scoreboardQueries) {
    scoreboard.io.query(i).valid                := dispatch.io.scoreboardQuery(i).valid
    scoreboard.io.query(i).rs                   := dispatch.io.scoreboardQuery(i).rs
    dispatch.io.scoreboardQuery(i).ready        := scoreboard.io.query(i).ready
    dispatch.io.scoreboardQuery(i).producer     := scoreboard.io.query(i).producer
    dispatch.io.scoreboardQuery(i).producerDone := scoreboard.io.query(i).producerDone
    dispatch.io.scoreboardQuery(i).producerData := scoreboard.io.query(i).producerData
  }

  for (i <- 0 until cfg.dispatchWidth) {
    scoreboard.io.alloc(i)        := dispatch.io.scoreboardAlloc(i)
    csrTracker.io.alloc(i).valid  := dispatch.io.out(i).fire && dispatchDecode(i).isCsr && dispatchDecode(i).csrWen
    csrTracker.io.alloc(i).robIdx := rob.io.allocIdx(i)
    csrTracker.io.alloc(i).addr   := dispatchDecode(i).csrAddr
  }

  for (i <- 0 until cfg.commitWidth) {
    retire.io.rob(i) <> rob.io.commit(i)
  }

  scoreboard.io.commit              := retire.io.scoreboardCommit
  lsu.io.storeCommit                := retire.io.storeCommit
  lsu.io.serializedStore            := retire.io.serializedStore
  retire.io.serializedStoreSuccess  := lsu.io.serializedStoreSuccess
  retire.io.storesDrained           := lsu.io.storesDrainedBeforeCommit
  csrFile.io.commit                 := retire.io.csrCommit
  csrFile.io.trap                   := retire.io.csrTrap
  csrFile.io.mret                   := retire.io.csrMret
  csrFile.io.sret                   := retire.io.csrSret
  csrFile.io.interrupt              := io.interrupt
  csrFile.io.mtime                  := io.mtime
  csrFile.io.retireCount            := PopCount(retire.io.retire.validMask)
  retire.io.csrStatus               := csrFile.io.status
  retire.io.hold                    := selectiveRecovery.valid
  io.fenceIReq.valid                := retire.io.fenceIReq.valid
  io.fenceIReq.bits                 := retire.io.fenceIReq.bits
  retire.io.fenceIReq.ready         := io.fenceIReq.ready
  retire.io.fenceIDone              := io.fenceIDone
  csrTracker.io.commit              := retire.io.csrTrackerCommit
  csrTracker.io.robHead             := rob.io.head
  rob.io.flush                      := globalFlush
  rob.io.recover                    := selectiveRecovery
  scoreboard.io.flush               := globalFlush
  scoreboard.io.recover             := selectiveRecovery
  scoreboard.io.robHead             := rob.io.head
  scoreboard.io.producerEntries     := rob.io.producerEntries
  csrTracker.io.flush               := globalFlush
  csrTracker.io.recover             := selectiveRecovery
  issueQueue.io.flush               := globalFlush
  issueQueue.io.recover             := selectiveRecovery
  issueQueue.io.hold                := retire.io.fenceIActive
  issueQueue.io.robDoneOperandCount := dispatch.io.robDoneOperandCount
  lsu.io.flush                      := globalFlush
  lsu.io.recover                    := selectiveRecovery
  lsu.io.robHead                    := rob.io.head
  lsu.io.unresolvedCfi              := rob.io.unresolvedCfi
  lsu.io.dmemCancel                 := io.dmemCancel
  lsu.io.csrStatus                  := csrFile.io.status
  io.storesDrained                  := lsu.io.storesDrained
  io.memoryIdle                     := lsu.io.memoryIdle

  val perfBridge = Module(new BackendPerfBridge(enablePerf))
  perfBridge.io.issueQueue <> issueQueue.io.perf
  perfBridge.io.div <> execute.io.divPerf

  if (enableDifftest) {
    val difftest = Module(new DifftestMonitor(resetVector, cfg, enableDpi = enableDifftest))
    difftest.io.retire    := retire.io.retire
    difftest.io.regWrite  := retire.io.regWrite
    difftest.io.csrCommit := retire.io.csrCommit
    difftest.io.csrTrap   := retire.io.csrTrap
    difftest.io.csrMret   := retire.io.csrMret
    difftest.io.csrSret   := retire.io.csrSret
    difftest.io.interrupt := io.interrupt
    difftest.io.context   := retire.io.context
  }

  issueQueue.io.robHead       := rob.io.head
  issueQueue.io.unresolvedAmo := rob.io.unresolvedAmo
  issueQueue.io.unresolvedCfi := rob.io.unresolvedCfi
  for (port <- 0 until cfg.intIssueWidth) {
    issueQueue.io.intStatus(port) := execute.io.status(port)
  }
  issueQueue.io.memStatus := 0.U.asTypeOf(new IssuePortStatus)
  issueQueue.io.memStatus.lsu    := true.B
  issueQueue.io.memStatus.load   := lsu.io.loadReady
  issueQueue.io.memStatus.store  := lsu.io.storeReady
  issueQueue.io.memStatus.atomic := lsu.io.atomicReady
  issueQueue.io.storeQuery <> lsu.io.storeIssueQuery
  issueQueue.io.csrQuery <> csrTracker.io.query

  execute.io.flush   := globalFlush
  execute.io.recover := selectiveRecovery
  execute.io.robHead := rob.io.head
  execute.io.csrRead <> csrFile.io.read
  for (port <- 0 until cfg.intIssueWidth) {
    issueQueue.io.intIssue(port).ready := execute.io.in(port).ready && !backendBlocked
    execute.io.in(port).valid          := issueQueue.io.intIssue(port).valid && !backendBlocked
    execute.io.in(port).bits           := ExuRequest.fromIssue(issueQueue.io.intIssue(port).bits, cfg)
  }

  issueQueue.io.memIssue.ready := lsu.io.in.ready && !backendBlocked
  lsu.io.in.valid              := issueQueue.io.memIssue.valid && !backendBlocked
  lsu.io.in.bits               := issueQueue.io.memIssue.bits

  private val writeback = Wire(Vec(cfg.writebackWidth, Valid(new RobWritebackPacket(cfg))))
  for (i    <- 0 until cfg.writebackWidth) {
    writeback(i)            := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
    issueQueue.io.wakeup(i) := 0.U.asTypeOf(new IssueWakeup(cfg))
  }
  for (port <- 0 until cfg.intIssueWidth) {
    writeback(port)            := execute.io.writeback(port)
    issueQueue.io.wakeup(port) := execute.io.wakeup(port)
  }

  private val lsuWritebackPort = cfg.intIssueWidth
  writeback(lsuWritebackPort)            := lsu.io.writeback
  issueQueue.io.wakeup(lsuWritebackPort) := lsu.io.wakeup
  rob.io.writeback                       := writeback

  for (i <- 0 until cfg.commitWidth) {
    issueQueue.io.commitWakeup(i).valid  := retire.io.scoreboardCommit(i).valid && retire.io.scoreboardCommit(i).rfWen
    issueQueue.io.commitWakeup(i).robIdx := retire.io.scoreboardCommit(i).robIdx
    issueQueue.io.commitWakeup(i).data   := retire.io.regWrite(i).data
  }

  for (i <- 0 until cfg.regfileWritePorts) {
    gpr.io.write(i).enable := false.B
    gpr.io.write(i).addr   := 0.U
    gpr.io.write(i).data   := 0.U
  }

  for (i <- 0 until cfg.commitWidth) {
    gpr.io.write(i).enable := retire.io.regWrite(i).enable
    gpr.io.write(i).addr   := retire.io.regWrite(i).addr
    gpr.io.write(i).data   := retire.io.regWrite(i).data
  }

  io.retire := retire.io.retire

  io.dmemReq <> lsu.io.dmemReq
  lsu.io.dmemResp <> io.dmemResp

  io.memPerf.sqAlloc                     := lsu.io.sqPerf.alloc
  io.memPerf.sqFullStall                 := lsu.io.sqPerf.fullStall
  io.memPerf.forwardFull                 := lsu.io.forwardFull
  io.memPerf.forwardPartial              := lsu.io.forwardPartial
  io.memPerf.forwardUnresolvedStoreStall := lsu.io.forwardUnresolvedStoreStall
  io.memPerf.storeCommit                 := lsu.io.sqPerf.commit
  io.memPerf.storeDrain                  := lsu.io.sqPerf.request
  io.memPerf.storeResponse               := lsu.io.sqPerf.response
  io.memPerf.loadTxnFullStall            := lsu.io.loadTxnFullStall
  io.memPerf.sqOccupancy                 := lsu.io.sqPerf.occupancy
  io.memPerf.loadTxnOccupancy            := lsu.io.loadTxnOccupancy

  io.monitor := 0.U.asTypeOf(new BackendMonitor(cfg))
  if (enableMonitor) {
    io.monitor.frontendFire := io.frontend.fire
    io.monitor.frontend     := io.frontend.bits
    for (lane <- 0 until cfg.dispatchWidth) {
      io.monitor.dispatchFire(lane)   := dispatch.io.out(lane).fire
      io.monitor.dispatchDecode(lane) := dispatchDecode(lane)
      io.monitor.dispatchIssue(lane)  := dispatch.io.out(lane).bits
    }
    for (port <- 0 until cfg.intIssueWidth) {
      io.monitor.intIssueFire(port) := issueQueue.io.intIssue(port).fire
      io.monitor.intIssue(port)     := issueQueue.io.intIssue(port).bits
    }
    io.monitor.memIssueFire := issueQueue.io.memIssue.fire
    io.monitor.memIssue            := issueQueue.io.memIssue.bits
    io.monitor.writeback           := writeback
    io.monitor.retire              := retire.io.retire
    io.monitor.bpuPerf             := retire.io.bpuPerf
    io.monitor.storeReady          := lsu.io.storeUpdate
    io.monitor.storeCommit         := retire.io.storeCommit
    io.monitor.storeRequest        := lsu.io.storeRequest
    io.monitor.storeResponse       := lsu.io.storeResponse
    io.monitor.memoryRequestFire   := io.dmemReq.fire
    io.monitor.memoryRequestRobIdx := io.dmemReq.bits.owner.robIdx
    io.monitor.memoryRequestKind   := io.dmemReq.bits.request.kind
    io.monitor.memoryRequestWrite  := io.dmemReq.bits.request.write
    io.monitor.memoryRequestTxnId  := io.dmemReq.bits.request.txnId
    io.monitor.robHead             := rob.io.head
    io.monitor.recover             := selectiveRecovery
    io.monitor.globalFlush         := globalFlush
  }
}
