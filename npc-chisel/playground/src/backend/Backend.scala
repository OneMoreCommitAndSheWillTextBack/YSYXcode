package top.backend

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, Enum, PopCount, Valid}
import top.bundle._
import top.config.BackendConfig

import top.backend.bundle.{DecodePacket, IssuePortStatus, IssueWakeup, RetireGroup, RobWritebackPacket}
import top.backend.decoder._
import top.backend.dispatch.{Dispatch, Scoreboard}
import top.backend.exu.{ExecuteBlock, ExuRequest}
import top.backend.issue.IssueQueue
import top.backend.lsu.{LSU, StoreTracker}
import top.backend.regfile._
import top.backend.retire.RetireUnit
import top.backend.rob.ROB

class Backend(cfg: BackendConfig = BackendConfig()) extends Module {
  require(cfg.issueWidth > 0, "Backend requires at least one frontend slot")
  require(cfg.writebackWidth >= cfg.intIssueWidth + 1, "Backend reserves writeback ports for integer EXUs and LSU")

  val io = IO(new Bundle {
    val frontend = Flipped(Decoupled(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
    val redirect = Output(new BackendToFrontend(cfg.addrWidth))

    val dmemReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val dmemResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))

    val retire = Output(new RetireGroup(cfg))

    val contextValid = Output(Bool())
    val contextPc    = Output(UInt(cfg.addrWidth.W))
  })

  private val slotIdxWidth   = math.max(log2Ceil(cfg.issueWidth), 1)
  private val slotCountWidth = math.max(log2Ceil(cfg.issueWidth + 1), 1)

  val gpr          = Module(new RegFile(cfg))
  val decoder      = Seq.fill(cfg.dispatchWidth)(Module(new Decoder(cfg)))
  val dispatch     = Module(new Dispatch(cfg))
  val scoreboard   = Module(new Scoreboard(cfg))
  val rob          = Module(new ROB(cfg))
  val issueQueue   = Module(new IssueQueue(cfg))
  val execute      = Module(new ExecuteBlock(cfg))
  val lsu          = Module(new LSU(cfg))
  val storeTracker = Module(new StoreTracker(cfg))
  val retire       = Module(new RetireUnit(cfg))

  io.redirect := retire.io.redirect

  private val flush =
    retire.io.redirect.trapRedirect.valid ||
      retire.io.redirect.branchRedirect.valid ||
      retire.io.redirect.predRedirect.valid

  private val fetchReg = RegInit(0.U.asTypeOf(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
  private val pending  = RegInit(false.B)
  private val slotIdx  = RegInit(0.U(slotIdxWidth.W))

  io.frontend.ready := !pending

  val dispatchFetch  = Wire(Vec(cfg.dispatchWidth, Valid(new FetchInstPayload(cfg.addrWidth))))
  val dispatchDecode = Wire(Vec(cfg.dispatchWidth, new DecodePacket(cfg.addrWidth)))
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

    decoder(lane).io.in        := dispatchFetch(lane).bits
    dispatchDecode(lane)       := decoder(lane).io.out
    dispatchDecode(lane).legal := pending && laneInRange(lane) && dispatchFetch(lane).valid && decoder(
      lane
    ).io.out.legal

    dispatch.io.in(lane)     := dispatchDecode(lane)
    dispatch.io.robIdx(lane) := rob.io.allocIdx(lane)

    dispatch.io.out(lane).ready := rob.io.alloc(lane).ready && issueQueue.io.enq(lane).ready

    rob.io.alloc(lane).valid       := dispatch.io.out(lane).valid && issueQueue.io.enq(lane).ready
    rob.io.alloc(lane).bits.decode := dispatchDecode(lane)

    issueQueue.io.enq(lane).valid := dispatch.io.out(lane).valid && rob.io.alloc(lane).ready
    issueQueue.io.enq(lane).bits  := dispatch.io.out(lane).bits
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

  when(flush) {
    pending := false.B
    slotIdx := 0.U
  }.elsewhen(!pending && io.frontend.fire) {
    fetchReg := io.frontend.bits
    pending  := true.B
    slotIdx  := 0.U
  }.elsewhen(pending && (consumedCount =/= 0.U)) {
    when(packetDone) {
      pending := false.B
      slotIdx := 0.U
    }.otherwise {
      slotIdx := nextSlotIdx(slotIdxWidth - 1, 0)
    }
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
    scoreboard.io.alloc(i)          := dispatch.io.scoreboardAlloc(i)
    storeTracker.io.alloc(i).valid  := dispatch.io.out(i).fire && dispatchDecode(i).isStore
    storeTracker.io.alloc(i).robIdx := rob.io.allocIdx(i)
  }

  for (i <- 0 until cfg.commitWidth) {
    retire.io.rob(i) <> rob.io.commit(i)
  }

  scoreboard.io.commit    := retire.io.scoreboardCommit
  storeTracker.io.commit  := retire.io.storeCommit
  storeTracker.io.robHead := rob.io.head
  rob.io.flush            := flush
  scoreboard.io.flush     := flush
  storeTracker.io.flush   := flush
  issueQueue.io.flush     := flush
  lsu.io.flush            := flush

  issueQueue.io.robHead := rob.io.head
  for (port <- 0 until cfg.intIssueWidth) {
    issueQueue.io.intStatus(port) := execute.io.status(port)
  }
  issueQueue.io.memStatus := 0.U.asTypeOf(new IssuePortStatus)
  issueQueue.io.memStatus.lsu := !lsu.io.busy
  issueQueue.io.storeQuery <> storeTracker.io.query

  execute.io.flush := flush
  for (port <- 0 until cfg.intIssueWidth) {
    issueQueue.io.intIssue(port).ready := execute.io.in(port).ready
    execute.io.in(port).valid          := issueQueue.io.intIssue(port).valid
    execute.io.in(port).bits           := ExuRequest.fromIssue(issueQueue.io.intIssue(port).bits, cfg)
  }

  issueQueue.io.memIssue.ready := lsu.io.in.ready
  lsu.io.in.valid              := issueQueue.io.memIssue.valid
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

  io.retire       := retire.io.retire
  io.contextValid := retire.io.contextValid
  io.contextPc    := retire.io.contextPc

  private val dmemIdle :: dmemLoadResp :: dmemStoreResp :: Nil = Enum(3)
  private val dmemState                                        = RegInit(dmemIdle)
  private val dropLoadResp                                     = RegInit(false.B)

  val dmemCanAcceptReq     = dmemState === dmemIdle
  val loadRespOutstanding  = dmemState === dmemLoadResp
  val storeRespOutstanding = dmemState === dmemStoreResp

  val lsuReqSelected    = dmemCanAcceptReq && !flush && lsu.io.dmemReq.valid
  // Keep retire store arbitration independent from flush; flush is produced by retire.
  val retireReqSelected = dmemCanAcceptReq && !lsu.io.dmemReq.valid && retire.io.dmemReq.valid

  io.dmemReq.valid := lsuReqSelected || retireReqSelected
  io.dmemReq.bits  := Mux(lsuReqSelected, lsu.io.dmemReq.bits, retire.io.dmemReq.bits)

  lsu.io.dmemReq.ready    := lsuReqSelected && io.dmemReq.ready
  retire.io.dmemReq.ready := retireReqSelected && io.dmemReq.ready

  val loadRespMustDrop = dropLoadResp || (flush && loadRespOutstanding)

  lsu.io.dmemResp.valid := loadRespOutstanding && io.dmemResp.valid && !loadRespMustDrop
  lsu.io.dmemResp.bits  := io.dmemResp.bits
  io.dmemResp.ready     := Mux(
    loadRespOutstanding,
    Mux(loadRespMustDrop, true.B, lsu.io.dmemResp.ready),
    storeRespOutstanding
  )

  when(io.dmemReq.fire) {
    dmemState := Mux(io.dmemReq.bits.write, dmemStoreResp, dmemLoadResp)
  }.elsewhen((loadRespOutstanding || storeRespOutstanding) && io.dmemResp.fire) {
    dmemState := dmemIdle
  }

  when(io.dmemResp.fire) {
    dropLoadResp := false.B
  }.elsewhen(flush && loadRespOutstanding) {
    dropLoadResp := true.B
  }
}
