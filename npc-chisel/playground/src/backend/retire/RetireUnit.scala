package top.backend.retire

import chisel3._
import chisel3.util.{Decoupled, Mux1H, PopCount, PriorityEncoderOH}
import top.backend.bundle.{CommitRegWrite, RetireGroup, RobCommitPacket, ScoreboardCommit, StoreTrackerCommit}
import top.bundle.{BackendToFrontend, CfiType, DataMemReq}
import top.config.BackendConfig

class RetireUnit(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val rob = Vec(cfg.commitWidth, Flipped(Decoupled(new RobCommitPacket(cfg))))

    val regWrite         = Output(Vec(cfg.commitWidth, new CommitRegWrite(cfg)))
    val scoreboardCommit = Output(Vec(cfg.commitWidth, new ScoreboardCommit(cfg)))
    val storeCommit      = Output(Vec(cfg.commitWidth, new StoreTrackerCommit(cfg)))
    val retire           = Output(new RetireGroup(cfg))
    val redirect         = Output(new BackendToFrontend(cfg.addrWidth))

    val dmemReq = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))

    val contextValid = Output(Bool())
    val contextPc    = Output(UInt(cfg.addrWidth.W))
  })

  private def orReduce(values: Seq[Bool]): Bool =
    if (values.isEmpty) false.B else values.reduce(_ || _)

  private def andReduce(values: Seq[Bool]): Bool =
    if (values.isEmpty) true.B else values.reduce(_ && _)

  private val redirectCandidate = Wire(Vec(cfg.commitWidth, Bool()))
  private val laneBoundary      = Wire(Vec(cfg.commitWidth, Bool()))
  private val preRetire         = Wire(Vec(cfg.commitWidth, Bool()))
  private val storeCandidate    = Wire(Vec(cfg.commitWidth, Bool()))
  private val canRetire         = Wire(Vec(cfg.commitWidth, Bool()))
  private val nextPc            = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))

  for (i <- 0 until cfg.commitWidth) {
    redirectCandidate(i) :=
      io.rob(i).valid &&
        io.rob(i).bits.redirectValid &&
        io.rob(i).bits.fetch.predNpc =/= io.rob(i).bits.redirectTarget

    laneBoundary(i) := redirectCandidate(i) || io.rob(i).bits.isEbreak

    preRetire(i) :=
      io.rob(i).valid &&
        (if (i == 0) true.B else preRetire(i - 1) && !laneBoundary(i - 1))

    val olderStore = orReduce((0 until i).map(j => preRetire(j) && io.rob(j).bits.isStore))
    storeCandidate(i) := preRetire(i) && io.rob(i).bits.isStore && !olderStore

    nextPc(i) := Mux(
      io.rob(i).bits.redirectValid,
      io.rob(i).bits.redirectTarget,
      io.rob(i).bits.fetch.pc +% io.rob(i).bits.fetch.instLen
    )
  }

  private val storeReq = Wire(Vec(cfg.commitWidth, new DataMemReq(cfg.addrWidth, cfg.dataWidth)))
  for (i <- 0 until cfg.commitWidth) {
    storeReq(i)          := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    storeReq(i).addr     := io.rob(i).bits.storeAddr
    storeReq(i).write    := true.B
    storeReq(i).size     := io.rob(i).bits.memSize
    storeReq(i).unsigned := false.B
    storeReq(i).wdata    := io.rob(i).bits.storeData
    storeReq(i).wmask    := io.rob(i).bits.storeMask
  }

  private val storeGrantOH = PriorityEncoderOH(storeCandidate.asUInt).asBools
  io.dmemReq.valid := storeCandidate.asUInt.orR
  io.dmemReq.bits  := Mux1H(storeGrantOH, storeReq)

  for (i <- 0 until cfg.commitWidth) {
    val olderRetired = andReduce((0 until i).map(j => canRetire(j)))
    val storeReady   = !io.rob(i).bits.isStore || (storeCandidate(i) && io.dmemReq.ready)

    canRetire(i)    := preRetire(i) && olderRetired && storeReady
    io.rob(i).ready := canRetire(i)
  }

  io.redirect := 0.U.asTypeOf(new BackendToFrontend(cfg.addrWidth))

  private val redirectCommit = Wire(Vec(cfg.commitWidth, Bool()))
  for (i <- 0 until cfg.commitWidth) {
    redirectCommit(i) := canRetire(i) && redirectCandidate(i)
  }

  private val redirectGrantOH = PriorityEncoderOH(redirectCommit.asUInt).asBools
  io.redirect.branchRedirect.valid  := redirectCommit.asUInt.orR
  io.redirect.branchRedirect.target := Mux1H(
    redirectGrantOH,
    io.rob.map(_.bits.redirectTarget)
  )

  private val bpuUpdateValid   = Wire(Vec(cfg.commitWidth, Bool()))
  private val bpuUpdatePc      = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))
  private val bpuUpdateType    = Wire(Vec(cfg.commitWidth, UInt(CfiType.width.W)))
  private val bpuUpdateTaken   = Wire(Vec(cfg.commitWidth, Bool()))
  private val bpuUpdateTarget  = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))
  private val bpuUpdateInstLen = Wire(Vec(cfg.commitWidth, UInt(3.W)))

  io.retire := 0.U.asTypeOf(new RetireGroup(cfg))

  for (i <- 0 until cfg.commitWidth) {
    io.regWrite(i).enable := canRetire(i) && io.rob(i).bits.rfWen
    io.regWrite(i).addr   := io.rob(i).bits.rd
    io.regWrite(i).data   := io.rob(i).bits.result

    io.scoreboardCommit(i).valid  := canRetire(i)
    io.scoreboardCommit(i).rd     := io.rob(i).bits.rd
    io.scoreboardCommit(i).rfWen  := io.rob(i).bits.rfWen
    io.scoreboardCommit(i).robIdx := io.rob(i).bits.robIdx

    io.storeCommit(i).valid  := canRetire(i) && io.rob(i).bits.isStore
    io.storeCommit(i).robIdx := io.rob(i).bits.robIdx

    io.retire.lanes(i).valid                   := canRetire(i)
    io.retire.lanes(i).robIdx                  := io.rob(i).bits.robIdx
    io.retire.lanes(i).fetch                   := io.rob(i).bits.fetch
    io.retire.lanes(i).nextPc                  := nextPc(i)
    io.retire.lanes(i).rf                      := io.regWrite(i)
    io.retire.lanes(i).store.valid             := canRetire(i) && io.rob(i).bits.isStore
    io.retire.lanes(i).store.addr              := io.rob(i).bits.storeAddr
    io.retire.lanes(i).store.data              := io.rob(i).bits.storeData
    io.retire.lanes(i).store.mask              := io.rob(i).bits.storeMask
    io.retire.lanes(i).store.size              := io.rob(i).bits.memSize
    io.retire.lanes(i).control.redirectValid   := redirectCandidate(i)
    io.retire.lanes(i).control.redirectTarget  := io.rob(i).bits.redirectTarget
    io.retire.lanes(i).control.branchTaken     := io.rob(i).bits.branchTaken
    io.retire.lanes(i).control.branchTarget    := io.rob(i).bits.branchTarget
    io.retire.lanes(i).exception.valid         := false.B
    io.retire.lanes(i).exception.cause         := 0.U
    io.retire.lanes(i).exception.tval          := 0.U
    io.retire.lanes(i).exception.blocksYounger := false.B
    io.retire.lanes(i).finish                  := canRetire(i) && io.rob(i).bits.isEbreak

    bpuUpdateValid(i)   := canRetire(i) && (io.rob(i).bits.cfi =/= CfiType.none)
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

  io.contextValid := io.retire.validMask.orR
  io.contextPc    := io.retire.finalPc

  if (cfg.commitWidth > 1) {
    assert(!canRetire.asUInt(cfg.commitWidth - 1, 1).orR || canRetire(0))
  }
  assert(PopCount((0 until cfg.commitWidth).map(i => canRetire(i) && io.rob(i).bits.isStore)) <= 1.U)
  for (i <- 1 until cfg.commitWidth) {
    assert(!(canRetire(i) && orReduce((0 until i).map(j => canRetire(j) && laneBoundary(j)))))
  }
}
