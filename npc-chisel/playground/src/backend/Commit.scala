package top.backend.commit

import chisel3._
import chisel3.util.{Decoupled, Mux1H, PriorityEncoderOH, Valid}
import top.backend.bundle.{CommitRegWrite, RobCommitPacket, ScoreboardCommit, StoreTrackerCommit}
import top.bundle.{BackendToFrontend, CommitPayload, DataMemReq}
import top.config.BackendConfig
import top.dpi.NpcCommit

class Commit(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val rob = Vec(cfg.commitWidth, Flipped(Decoupled(new RobCommitPacket(cfg))))

    val regWrite         = Output(Vec(cfg.commitWidth, new CommitRegWrite(cfg)))
    val scoreboardCommit = Output(Vec(cfg.commitWidth, new ScoreboardCommit(cfg)))
    val storeCommit      = Output(Vec(cfg.commitWidth, new StoreTrackerCommit(cfg)))
    val commit           = Output(Vec(cfg.commitWidth, Valid(new CommitPayload(cfg.addrWidth))))
    val redirect         = Output(new BackendToFrontend(cfg.addrWidth))

    val dmemReq = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))

    val contextValid = Output(Bool())
    val contextPc    = Output(UInt(cfg.addrWidth.W))
  })

  private val redirectCandidate      = Wire(Vec(cfg.commitWidth, Bool()))
  private val blockedByOlderRedirect = Wire(Vec(cfg.commitWidth, Bool()))

  for (i <- 0 until cfg.commitWidth) {
    blockedByOlderRedirect(i) := {
      if (i == 0) {
        false.B
      } else {
        redirectCandidate.take(i).reduce(_ || _)
      }
    }

    redirectCandidate(i) :=
      io.rob(i).valid &&
        !blockedByOlderRedirect(i) &&
        io.rob(i).bits.redirectValid &&
        io.rob(i).bits.fetch.predNpc =/= io.rob(i).bits.redirectTarget
  }

  private val storeValid = Wire(Vec(cfg.commitWidth, Bool()))
  private val storeReq   = Wire(Vec(cfg.commitWidth, new DataMemReq(cfg.addrWidth, cfg.dataWidth)))

  for (i <- 0 until cfg.commitWidth) {
    storeValid(i) := io.rob(i).valid && !blockedByOlderRedirect(i) && io.rob(i).bits.isStore

    storeReq(i)          := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    storeReq(i).addr     := io.rob(i).bits.storeAddr
    storeReq(i).write    := true.B
    storeReq(i).size     := io.rob(i).bits.memSize
    storeReq(i).unsigned := false.B
    storeReq(i).wdata    := io.rob(i).bits.storeData
    storeReq(i).wmask    := io.rob(i).bits.storeMask
  }

  private val storeGrantOH = PriorityEncoderOH(storeValid.asUInt).asBools

  io.dmemReq.valid := storeValid.asUInt.orR
  io.dmemReq.bits  := Mux1H(storeGrantOH, storeReq)
  io.redirect      := 0.U.asTypeOf(new BackendToFrontend(cfg.addrWidth))

  private val redirectGrantOH = PriorityEncoderOH(redirectCandidate.asUInt).asBools
  io.redirect.branchRedirect.valid  := redirectCandidate.asUInt.orR
  io.redirect.branchRedirect.target := Mux1H(
    redirectGrantOH,
    io.rob.map(_.bits.redirectTarget)
  )

  private val bpuUpdateValid   = Wire(Vec(cfg.commitWidth, Bool()))
  private val bpuUpdatePc      = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))
  private val bpuUpdateType    = Wire(Vec(cfg.commitWidth, UInt(3.W)))
  private val bpuUpdateTaken   = Wire(Vec(cfg.commitWidth, Bool()))
  private val bpuUpdateTarget  = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))
  private val bpuUpdateInstLen = Wire(Vec(cfg.commitWidth, UInt(3.W)))
  private val contextNextPc    = Wire(Vec(cfg.commitWidth, UInt(cfg.addrWidth.W)))

  for (i <- 0 until cfg.commitWidth) {
    val selectedStore  = storeGrantOH(i)
    val olderCommitted = if (i == 0) {
      true.B
    } else {
      io.rob.take(i).map(_.fire).reduce(_ && _)
    }
    io.rob(i).ready :=
      olderCommitted &&
        !blockedByOlderRedirect(i) &&
        (!io.rob(i).bits.isStore || (selectedStore && io.dmemReq.ready))

    io.regWrite(i).enable := io.rob(i).fire && io.rob(i).bits.rfWen
    io.regWrite(i).addr   := io.rob(i).bits.rd
    io.regWrite(i).data   := io.rob(i).bits.result

    io.scoreboardCommit(i).valid  := io.rob(i).fire
    io.scoreboardCommit(i).rd     := io.rob(i).bits.rd
    io.scoreboardCommit(i).rfWen  := io.rob(i).bits.rfWen
    io.scoreboardCommit(i).robIdx := io.rob(i).bits.robIdx

    io.storeCommit(i).valid  := io.rob(i).fire && io.rob(i).bits.isStore
    io.storeCommit(i).robIdx := io.rob(i).bits.robIdx

    io.commit(i).valid     := io.rob(i).fire
    io.commit(i).bits.pc   := io.rob(i).bits.fetch.pc
    io.commit(i).bits.inst := io.rob(i).bits.fetch.inst

    bpuUpdateValid(i)   := io.rob(i).fire && (io.rob(i).bits.isBranch || io.rob(i).bits.isJal)
    bpuUpdatePc(i)      := io.rob(i).bits.fetch.pc
    bpuUpdateType(i)    := Mux(io.rob(i).bits.isJal, 2.U(3.W), 1.U(3.W))
    bpuUpdateTaken(i)   := io.rob(i).bits.branchTaken
    bpuUpdateTarget(i)  := io.rob(i).bits.branchTarget
    bpuUpdateInstLen(i) := io.rob(i).bits.fetch.instLen

    contextNextPc(i) := Mux(
      io.rob(i).bits.redirectValid,
      io.rob(i).bits.redirectTarget,
      io.rob(i).bits.fetch.pc +% io.rob(i).bits.fetch.instLen
    )

    NpcCommit.callWithEnable(
      io.commit(i).valid,
      1.U(32.W),
      io.rob(i).bits.isEcall,
      io.commit(i).bits.pc,
      io.commit(i).bits.inst
    )
  }

  private val bpuUpdateGrantOH = PriorityEncoderOH(bpuUpdateValid.asUInt).asBools
  io.redirect.bpuUpdate.valid        := bpuUpdateValid.asUInt.orR
  io.redirect.bpuUpdate.bits.pc      := Mux1H(bpuUpdateGrantOH, bpuUpdatePc)
  io.redirect.bpuUpdate.bits.cfiType := Mux1H(bpuUpdateGrantOH, bpuUpdateType)
  io.redirect.bpuUpdate.bits.taken   := Mux1H(bpuUpdateGrantOH, bpuUpdateTaken)
  io.redirect.bpuUpdate.bits.target  := Mux1H(bpuUpdateGrantOH, bpuUpdateTarget)
  io.redirect.bpuUpdate.bits.instLen := Mux1H(bpuUpdateGrantOH, bpuUpdateInstLen)

  private val contextFire     = VecInit((0 until cfg.commitWidth).map(i => io.rob(i).fire))
  private val latestContextOH = VecInit((0 until cfg.commitWidth).map { i =>
    val noYoungerFire =
      if (i == cfg.commitWidth - 1) {
        true.B
      } else {
        !contextFire.drop(i + 1).reduce(_ || _)
      }

    contextFire(i) && noYoungerFire
  })

  io.contextValid := contextFire.asUInt.orR
  io.contextPc    := Mux(io.contextValid, Mux1H(latestContextOH, contextNextPc), 0.U)
}
