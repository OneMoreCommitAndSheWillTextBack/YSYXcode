package top.backend

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, Enum, Valid}
import top.bundle._
import top.config.BackendConfig

import top.backend.bundle.{DecodePacket, IssueWakeup, RobWritebackPacket, ScoreboardAlloc, StoreTrackerAlloc}
import top.backend.commit.Commit
import top.backend.decoder._
import top.backend.dispatch.{Dispatch, Scoreboard}
import top.backend.execute.Execute
import top.backend.issue.IssueQueue
import top.backend.lsu.{LSU, StoreTracker}
import top.backend.regfile._
import top.backend.rob.ROB

class Backend(cfg: BackendConfig = BackendConfig()) extends Module {
  require(cfg.issueWidth > 0, "Backend requires at least one frontend slot")
  require(cfg.writebackWidth >= 2, "Backend currently reserves writeback ports for execute and lsu")

  val io = IO(new Bundle {
    val frontend = Flipped(Decoupled(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
    val redirect = Output(new BackendToFrontend(cfg.addrWidth))

    val dmemReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val dmemResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))

    val commit = Output(Vec(cfg.issueWidth, Valid(new CommitPayload(cfg.addrWidth))))

    val contextValid = Output(Bool())
    val contextPc    = Output(UInt(cfg.addrWidth.W))
  })

  private val slotIdxWidth = math.max(log2Ceil(cfg.issueWidth), 1)

  val gpr          = Module(new RegFile(cfg))
  val decoder      = Module(new Decoder(cfg))
  val dispatch     = Module(new Dispatch(cfg))
  val scoreboard   = Module(new Scoreboard(cfg))
  val rob          = Module(new ROB(cfg))
  val issueQueue   = Module(new IssueQueue(cfg))
  val execute      = Module(new Execute(cfg))
  val lsu          = Module(new LSU(cfg))
  val storeTracker = Module(new StoreTracker(cfg))
  val commit       = Module(new Commit(cfg))

  io.redirect := commit.io.redirect

  private val flush =
    commit.io.redirect.trapRedirect.valid ||
      commit.io.redirect.branchRedirect.valid ||
      commit.io.redirect.predRedirect.valid

  private val fetchReg = RegInit(0.U.asTypeOf(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
  private val pending  = RegInit(false.B)
  private val slotIdx  = RegInit(0.U(slotIdxWidth.W))

  io.frontend.ready := !pending

  val currentFetch = fetchReg.insts(slotIdx)
  decoder.io.in := currentFetch.bits

  val dispatchDecode = Wire(new DecodePacket(cfg.addrWidth))
  dispatchDecode       := decoder.io.out
  dispatchDecode.legal := pending && currentFetch.valid && decoder.io.out.legal

  dispatch.io.in     := dispatchDecode
  dispatch.io.robIdx := rob.io.allocIdx(0)

  dispatch.io.out.ready       := rob.io.alloc(0).ready && issueQueue.io.enq.ready
  rob.io.alloc(0).valid       := dispatch.io.out.valid && issueQueue.io.enq.ready
  rob.io.alloc(0).bits.decode := dispatchDecode
  issueQueue.io.enq.valid     := dispatch.io.out.valid && rob.io.alloc(0).ready
  issueQueue.io.enq.bits      := dispatch.io.out.bits

  for (i <- 1 until cfg.dispatchWidth) {
    rob.io.alloc(i).valid       := false.B
    rob.io.alloc(i).bits.decode := 0.U.asTypeOf(new DecodePacket(cfg.addrWidth))
  }

  val currentSlotDone = pending && (!currentFetch.valid || dispatch.io.out.fire)
  val lastSlot        = slotIdx === (cfg.issueWidth - 1).U

  when(flush) {
    pending := false.B
    slotIdx := 0.U
  }.elsewhen(!pending && io.frontend.fire) {
    fetchReg := io.frontend.bits
    pending  := true.B
    slotIdx  := 0.U
  }.elsewhen(currentSlotDone) {
    when(lastSlot) {
      pending := false.B
      slotIdx := 0.U
    }.otherwise {
      slotIdx := slotIdx + 1.U
    }
  }

  for (i <- 0 until cfg.regfileReadPorts) {
    gpr.io.read(i).enable := false.B
    gpr.io.read(i).addr   := 0.U
  }

  for (i <- 0 until cfg.operandsPerInst) {
    gpr.io.read(i).enable      := dispatch.io.rfRead(i).enable
    gpr.io.read(i).addr        := dispatch.io.rfRead(i).addr
    dispatch.io.rfRead(i).data := gpr.io.read(i).data
  }

  for (i <- 0 until cfg.scoreboardQueries) {
    scoreboard.io.query(i).valid := false.B
    scoreboard.io.query(i).rs    := 0.U
  }

  for (i <- 0 until cfg.operandsPerInst) {
    scoreboard.io.query(i).valid            := dispatch.io.scoreboardQuery(i).valid
    scoreboard.io.query(i).rs               := dispatch.io.scoreboardQuery(i).rs
    dispatch.io.scoreboardQuery(i).ready    := scoreboard.io.query(i).ready
    dispatch.io.scoreboardQuery(i).producer := scoreboard.io.query(i).producer
  }

  for (i <- 0 until cfg.dispatchWidth) {
    scoreboard.io.alloc(i)   := 0.U.asTypeOf(new ScoreboardAlloc(cfg))
    storeTracker.io.alloc(i) := 0.U.asTypeOf(new StoreTrackerAlloc(cfg))
  }
  scoreboard.io.alloc(0) := dispatch.io.scoreboardAlloc
  storeTracker.io.alloc(0).valid  := dispatch.io.out.fire && dispatchDecode.isStore
  storeTracker.io.alloc(0).robIdx := rob.io.allocIdx(0)

  for (i <- 0 until cfg.commitWidth) {
    commit.io.rob(i) <> rob.io.commit(i)
  }

  scoreboard.io.commit    := commit.io.scoreboardCommit
  storeTracker.io.commit  := commit.io.storeCommit
  storeTracker.io.robHead := rob.io.head
  rob.io.flush            := flush
  scoreboard.io.flush     := flush
  storeTracker.io.flush   := flush
  issueQueue.io.flush     := flush
  lsu.io.flush            := flush

  issueQueue.io.robHead       := rob.io.head
  issueQueue.io.fuReady.alu   := true.B
  issueQueue.io.fuReady.lsu   := !lsu.io.busy
  issueQueue.io.fuReady.bru   := true.B
  issueQueue.io.fuReady.jmp   := true.B
  issueQueue.io.fuReady.csr   := false.B
  issueQueue.io.fuReady.fence := false.B
  issueQueue.io.storeQuery <> storeTracker.io.query

  val issuedIsLsu = issueQueue.io.issue.bits.fuType === FuType.lsu
  issueQueue.io.issue.ready := Mux(issuedIsLsu, lsu.io.in.ready, execute.io.in.ready)

  execute.io.in.valid := issueQueue.io.issue.valid && !issuedIsLsu
  execute.io.in.bits  := issueQueue.io.issue.bits

  lsu.io.in.valid := issueQueue.io.issue.valid && issuedIsLsu
  lsu.io.in.bits  := issueQueue.io.issue.bits

  for (i <- 0 until cfg.writebackWidth) {
    rob.io.writeback(i)     := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
    issueQueue.io.wakeup(i) := 0.U.asTypeOf(new IssueWakeup(cfg))
  }
  rob.io.writeback(0) := execute.io.writeback
  rob.io.writeback(1)     := lsu.io.writeback
  issueQueue.io.wakeup(0) := execute.io.wakeup
  issueQueue.io.wakeup(1) := lsu.io.wakeup

  for (i <- 0 until cfg.regfileWritePorts) {
    gpr.io.write(i).enable := false.B
    gpr.io.write(i).addr   := 0.U
    gpr.io.write(i).data   := 0.U
  }

  for (i <- 0 until cfg.commitWidth) {
    gpr.io.write(i).enable := commit.io.regWrite(i).enable
    gpr.io.write(i).addr   := commit.io.regWrite(i).addr
    gpr.io.write(i).data   := commit.io.regWrite(i).data
  }

  io.commit       := commit.io.commit
  io.contextValid := commit.io.contextValid
  io.contextPc    := commit.io.contextPc

  private val dmemIdle :: dmemLoadResp :: dmemStoreResp :: Nil = Enum(3)
  private val dmemState                                        = RegInit(dmemIdle)
  private val dropLoadResp                                     = RegInit(false.B)

  val lsuReqSelected    = dmemState === dmemIdle && lsu.io.dmemReq.valid
  val commitReqSelected = dmemState === dmemIdle && !lsu.io.dmemReq.valid && commit.io.dmemReq.valid

  io.dmemReq.valid := lsuReqSelected || commitReqSelected
  io.dmemReq.bits  := Mux(lsuReqSelected, lsu.io.dmemReq.bits, commit.io.dmemReq.bits)

  lsu.io.dmemReq.ready    := dmemState === dmemIdle && io.dmemReq.ready
  commit.io.dmemReq.ready := dmemState === dmemIdle && !lsu.io.dmemReq.valid && io.dmemReq.ready

  lsu.io.dmemResp.valid := dmemState === dmemLoadResp && io.dmemResp.valid && !dropLoadResp
  lsu.io.dmemResp.bits  := io.dmemResp.bits
  io.dmemResp.ready     := Mux(
    dmemState === dmemLoadResp,
    Mux(dropLoadResp, true.B, lsu.io.dmemResp.ready),
    dmemState === dmemStoreResp
  )

  when(flush && dmemState === dmemLoadResp) {
    dropLoadResp := true.B
  }

  when(io.dmemReq.fire) {
    dmemState := Mux(io.dmemReq.bits.write, dmemStoreResp, dmemLoadResp)
  }.elsewhen(dmemState =/= dmemIdle && io.dmemResp.fire) {
    dmemState    := dmemIdle
    dropLoadResp := false.B
  }
}
