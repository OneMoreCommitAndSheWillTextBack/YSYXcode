package top.core.backend

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, Enum, PopCount, Valid}
import top.core.bundle._
import top.config.BackendConfig

import top.core.backend.bundle.{
  BackendMemPerf,
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
import top.core.backend.lsu.{LSU, StoreQueue}
import top.core.backend.regfile._
import top.core.backend.retire.RetireUnit
import top.core.backend.rob.ROB
import top.sim.DifftestMonitor

class Backend(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         BackendConfig = BackendConfig())
    extends Module {
  require(cfg.issueWidth > 0, "Backend requires at least one frontend slot")
  require(cfg.writebackWidth >= cfg.intIssueWidth + 1, "Backend reserves writeback ports for integer EXUs and LSU")

  val io = IO(new Bundle {
    val frontend = Flipped(Decoupled(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
    val redirect = Output(new BackendToFrontend(cfg.addrWidth, cfg.commitWidth))

    val dmemReq    = Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
    val dmemResp   = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val dmemCancel = Input(Vec(cfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))

    val fenceIReq  = Decoupled(Bool())
    val fenceIDone = Input(Bool())

    val recover       = Output(new RobRecovery(cfg.robIdxWidth))
    val globalFlush   = Output(Bool())
    val robHead       = Output(UInt(cfg.robIdxWidth.W))
    val unresolvedCfi = Output(Vec(cfg.robEntries, Bool()))

    val retire    = Output(new RetireGroup(cfg))
    val csrStatus = Output(new CsrStatus(cfg))
    val memPerf   = Output(new BackendMemPerf(cfg))
    val interrupt = Input(new CsrInterruptPending)
    val mtime     = Input(UInt(64.W))
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
  val storeQueue = Module(new StoreQueue(cfg))
  val csrFile    = Module(new CsrFile(resetVector, cfg))
  val csrTracker = Module(new CsrTracker(cfg))
  val retire     = Module(new RetireUnit(cfg))
  val difftest   = Module(new DifftestMonitor(resetVector, cfg))
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
  io.redirect.predictorRecovery := recovery.io.predictorRecovery

  private val fetchReg = RegInit(0.U.asTypeOf(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
  private val pending  = RegInit(false.B)
  private val slotIdx  = RegInit(0.U(slotIdxWidth.W))

  val dispatchFetch  = Wire(Vec(cfg.dispatchWidth, Valid(new FetchInstPayload(cfg.addrWidth))))
  val dispatchDecode = Wire(Vec(cfg.dispatchWidth, new DecodePacket(cfg)))
  val laneInRange    = Wire(Vec(cfg.dispatchWidth, Bool()))

  for (lane <- 0 until cfg.dispatchWidth) {
    val laneSlot = Wire(UInt(slotCountWidth.W))
    laneSlot          := slotIdx + lane.U(slotCountWidth.W)
    laneInRange(lane) := laneSlot < cfg.issueWidth.U

    dispatchFetch(lane) := 0.U.asTypeOf(Valid(new FetchInstPayload(cfg.addrWidth)))
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

    val needsIssue = dispatchDecode(lane).needsIssue

    dispatch.io.out(lane).ready := !backendBlocked && rob.io.alloc(lane).ready &&
      (!needsIssue || issueQueue.io.enq(lane).ready)

    rob.io.alloc(lane).valid       := !backendBlocked && dispatch.io.out(lane).valid &&
      (!needsIssue || issueQueue.io.enq(lane).ready)
    rob.io.alloc(lane).bits.decode := dispatchDecode(lane)

    issueQueue.io
      .enq(lane)
      .valid                     := !backendBlocked && dispatch.io.out(lane).valid && rob.io.alloc(lane).ready && needsIssue
    issueQueue.io.enq(lane).bits := dispatch.io.out(lane).bits
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
    scoreboard.io.query(i).valid            := dispatch.io.scoreboardQuery(i).valid
    scoreboard.io.query(i).rs               := dispatch.io.scoreboardQuery(i).rs
    dispatch.io.scoreboardQuery(i).ready    := scoreboard.io.query(i).ready
    dispatch.io.scoreboardQuery(i).producer := scoreboard.io.query(i).producer
  }

  for (i <- 0 until cfg.dispatchWidth) {
    scoreboard.io.alloc(i)        := dispatch.io.scoreboardAlloc(i)
    storeQueue.io.alloc(i).valid  := dispatch.io.out(i).fire && dispatchDecode(i).isStore
    storeQueue.io.alloc(i).robIdx := rob.io.allocIdx(i)
    csrTracker.io.alloc(i).valid  := dispatch.io.out(i).fire && dispatchDecode(i).isCsr && dispatchDecode(i).csrWen
    csrTracker.io.alloc(i).robIdx := rob.io.allocIdx(i)
    csrTracker.io.alloc(i).addr   := dispatchDecode(i).csrAddr
  }

  for (i <- 0 until cfg.commitWidth) {
    retire.io.rob(i) <> rob.io.commit(i)
  }

  scoreboard.io.commit          := retire.io.scoreboardCommit
  storeQueue.io.commit          := retire.io.storeCommit
  csrFile.io.commit             := retire.io.csrCommit
  csrFile.io.trap               := retire.io.csrTrap
  csrFile.io.mret               := retire.io.csrMret
  csrFile.io.sret               := retire.io.csrSret
  csrFile.io.interrupt          := io.interrupt
  csrFile.io.mtime              := io.mtime
  csrFile.io.retireCount        := PopCount(retire.io.retire.validMask)
  retire.io.csrStatus           := csrFile.io.status
  retire.io.hold                := selectiveRecovery.valid
  io.fenceIReq.valid            := retire.io.fenceIReq.valid
  io.fenceIReq.bits             := retire.io.fenceIReq.bits
  retire.io.fenceIReq.ready     := io.fenceIReq.ready
  retire.io.fenceIDone          := io.fenceIDone
  csrTracker.io.commit          := retire.io.csrTrackerCommit
  storeQueue.io.robHead         := rob.io.head
  csrTracker.io.robHead         := rob.io.head
  rob.io.flush                  := globalFlush
  rob.io.recover                := selectiveRecovery
  scoreboard.io.flush           := globalFlush
  scoreboard.io.recover         := selectiveRecovery
  scoreboard.io.robHead         := rob.io.head
  scoreboard.io.producerEntries := rob.io.producerEntries
  storeQueue.io.flush           := globalFlush
  storeQueue.io.recover         := selectiveRecovery
  csrTracker.io.flush           := globalFlush
  csrTracker.io.recover         := selectiveRecovery
  issueQueue.io.flush           := globalFlush
  issueQueue.io.recover         := selectiveRecovery
  issueQueue.io.hold            := retire.io.fenceIActive
  lsu.io.flush                  := globalFlush
  lsu.io.recover                := selectiveRecovery
  lsu.io.robHead                := rob.io.head
  lsu.io.unresolvedCfi          := rob.io.unresolvedCfi
  lsu.io.cancel                 := io.dmemCancel
  lsu.io.csrStatus              := csrFile.io.status

  difftest.io.retire    := retire.io.retire
  difftest.io.regWrite  := retire.io.regWrite
  difftest.io.csrCommit := retire.io.csrCommit
  difftest.io.csrTrap   := retire.io.csrTrap
  difftest.io.csrMret   := retire.io.csrMret
  difftest.io.csrSret   := retire.io.csrSret
  difftest.io.interrupt := io.interrupt
  difftest.io.context   := retire.io.context

  issueQueue.io.robHead       := rob.io.head
  issueQueue.io.unresolvedAmo := rob.io.unresolvedAmo
  for (port <- 0 until cfg.intIssueWidth) {
    issueQueue.io.intStatus(port) := execute.io.status(port)
  }
  issueQueue.io.memStatus := 0.U.asTypeOf(new IssuePortStatus)
  issueQueue.io.memStatus.lsu := !lsu.io.busy
  issueQueue.io.storeQuery <> storeQueue.io.issueQuery
  issueQueue.io.csrQuery <> csrTracker.io.query

  storeQueue.io.query <> lsu.io.storeQuery
  storeQueue.io.update        := 0.U.asTypeOf(new top.core.backend.bundle.StoreQueueUpdate(cfg))
  storeQueue.io.update.valid  := lsu.io.storeUpdate.valid
  storeQueue.io.update.robIdx := lsu.io.storeUpdate.bits.robIdx
  storeQueue.io.update.addr   := lsu.io.storeUpdate.bits.addr
  storeQueue.io.update.data   := lsu.io.storeUpdate.bits.data
  storeQueue.io.update.mask   := lsu.io.storeUpdate.bits.mask

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

  for (i    <- 0 until cfg.writebackWidth) {
    rob.io.writeback(i)     := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
    issueQueue.io.wakeup(i) := 0.U.asTypeOf(new IssueWakeup(cfg))
  }
  for (port <- 0 until cfg.intIssueWidth) {
    rob.io.writeback(port)     := execute.io.writeback(port)
    issueQueue.io.wakeup(port) := execute.io.wakeup(port)
  }

  private val lsuWritebackPort = cfg.intIssueWidth
  rob.io.writeback(lsuWritebackPort)     := lsu.io.writeback
  issueQueue.io.wakeup(lsuWritebackPort) := lsu.io.wakeup

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

  private val storeRespRobIdx         = Reg(UInt(cfg.robIdxWidth.W))
  private val storeRequestOutstanding = RegInit(false.B)
  retire.io.storesDrained             :=
    !storeQueue.io.committedPending && !storeRequestOutstanding && !retire.io.dmemReq.valid
  // A flush may arrive while a previously issued LSU request is still visible.
  // Let it complete and let LSU discard the tagged response; suppressing this
  // combinationally would feed the retire redirect back into its own store path.
  // Retire stores have priority. Their request path feeds retire readiness and
  // therefore must not depend on LSU flush state in the same cycle.
  // Store responses use one fixed transaction tag, so retain the owning ROB
  // index until that response returns before accepting another store request.
  private val retireReqSelected       = retire.io.dmemReq.valid && !storeRequestOutstanding
  private val lsuReqSelected          = !globalFlush && !retire.io.fenceIActive && !retire.io.dmemReq.valid && lsu.io.dmemReq.valid

  io.dmemReq.valid                 := lsuReqSelected || retireReqSelected
  io.dmemReq.bits                  := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  io.dmemReq.bits.request          := Mux(lsuReqSelected, lsu.io.dmemReq.bits, retire.io.dmemReq.bits)
  io.dmemReq.bits.owner.squashable := lsuReqSelected
  io.dmemReq.bits.owner.robIdx     := lsu.io.dmemReqRobIdx

  lsu.io.dmemReq.ready    := lsuReqSelected && io.dmemReq.ready
  retire.io.dmemReq.ready := retireReqSelected && io.dmemReq.ready

  private val storeResponse = io.dmemResp.bits.txnId === DataMemTxn.store

  lsu.io.dmemResp.valid := io.dmemResp.valid && !storeResponse
  lsu.io.dmemResp.bits  := io.dmemResp.bits
  io.dmemResp.ready     := Mux(storeResponse, true.B, lsu.io.dmemResp.ready)

  when(io.dmemReq.fire && retireReqSelected) {
    storeRespRobIdx         := retire.io.storeReqRobIdx
    storeRequestOutstanding := true.B
  }
  when(io.dmemResp.fire && storeResponse) {
    storeRequestOutstanding := false.B
  }

  storeQueue.io.drain.valid  := io.dmemResp.fire && storeResponse
  storeQueue.io.drain.robIdx := storeRespRobIdx

  io.memPerf.sqAlloc                     := storeQueue.io.perf.alloc
  io.memPerf.sqFullStall                 := storeQueue.io.perf.fullStall
  io.memPerf.forwardFull                 := lsu.io.forwardFull
  io.memPerf.forwardPartial              := lsu.io.forwardPartial
  io.memPerf.forwardUnresolvedStoreStall := lsu.io.forwardUnresolvedStoreStall
  io.memPerf.storeDrain                  := storeQueue.io.perf.drain
  io.memPerf.loadTxnFullStall            := lsu.io.loadTxnFullStall
  io.memPerf.sqOccupancy                 := storeQueue.io.perf.occupancy
  io.memPerf.loadTxnOccupancy            := lsu.io.loadTxnOccupancy
}
