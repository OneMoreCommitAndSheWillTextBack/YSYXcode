package top.core.backend.dispatch

import chisel3._
import top.core.backend.bundle.{RobProducerEntry, ScoreboardAlloc, ScoreboardCommit, ScoreboardQuery}
import top.core.bundle.{RobAge, RobRecovery}
import top.config.BackendConfig

class Scoreboard(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val query           = Vec(cfg.scoreboardQueries, new ScoreboardQuery(cfg))
    val alloc           = Input(Vec(cfg.dispatchWidth, new ScoreboardAlloc(cfg)))
    val commit          = Input(Vec(cfg.commitWidth, new ScoreboardCommit(cfg)))
    val flush           = Input(Bool())
    val recover         = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead         = Input(UInt(cfg.robIdxWidth.W))
    val producerEntries = Input(Vec(cfg.robEntries, new RobProducerEntry(cfg)))
  })

  private val busy     = RegInit(VecInit(Seq.fill(32)(false.B)))
  private val producer = Reg(Vec(32, UInt(cfg.robIdxWidth.W)))

  private def newestAllocation(register: UInt, lanes: Range): (Bool, UInt) = {
    var hasAllocation = false.B
    var newestRobIdx  = 0.U(cfg.robIdxWidth.W)

    // Allocation lanes are in program order, so a later matching lane is younger.
    for (lane <- lanes) {
      val allocation = io.alloc(lane)
      val matches    = allocation.valid && allocation.rfWen &&
        allocation.rd =/= 0.U && allocation.rd === register

      hasAllocation = hasAllocation || matches
      newestRobIdx = Mux(matches, allocation.robIdx, newestRobIdx)
    }

    (hasAllocation, newestRobIdx)
  }

  private def recoveredProducer(register: Int): (Bool, UInt) = {
    var selectedValid = false.B
    var selectedAge   = 0.U((cfg.robIdxWidth + 1).W)
    var selectedRob   = 0.U(cfg.robIdxWidth.W)

    for (entry <- io.producerEntries) {
      val candidate    = entry.valid && entry.rfWen && entry.rd === register.U && entry.rd =/= 0.U &&
        !RobAge.isYounger(entry.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
      val candidateAge = RobAge.fromHead(entry.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
      val replace      = candidate && (!selectedValid || candidateAge > selectedAge)

      selectedValid = Mux(replace, true.B, selectedValid)
      selectedAge = Mux(replace, candidateAge, selectedAge)
      selectedRob = Mux(replace, entry.robIdx, selectedRob)
    }

    (selectedValid, selectedRob)
  }

  for ((query, queryIdx) <- io.query.zipWithIndex) {
    val dispatchSlot                            = queryIdx / cfg.operandsPerInst
    val (hasEarlierAllocation, earlierProducer) = newestAllocation(query.rs, 0 until dispatchSlot)
    val waitsForEarlierLane                     = query.valid && query.rs =/= 0.U && hasEarlierAllocation
    val queryReady                              = !query.valid || query.rs === 0.U || (!busy(query.rs) && !waitsForEarlierLane)
    val selectedProducer                        = Mux(waitsForEarlierLane, earlierProducer, producer(query.rs))
    val selectedProducerDone                    = VecInit(io.producerEntries.map { entry =>
      entry.valid && entry.robIdx === selectedProducer && entry.done
    }).asUInt.orR
    val selectedProducerCommits                 = VecInit(io.commit.map { commit =>
      commit.valid && commit.rfWen && commit.robIdx === selectedProducer
    }).asUInt.orR

    query.ready        := queryReady
    query.producer     := selectedProducer
    query.producerDone := query.valid && !queryReady && !waitsForEarlierLane && selectedProducerDone &&
      !selectedProducerCommits
  }

  when(io.flush) {
    for (idx <- 0 until 32) {
      busy(idx) := false.B
    }
  }.elsewhen(io.recover.valid) {
    for (register <- 0 until 32) {
      val (hasProducer, producerRobIdx) = recoveredProducer(register)
      busy(register)     := hasProducer
      producer(register) := producerRobIdx
    }
  }.otherwise {
    for (commit <- io.commit) {
      when(
        commit.valid &&
          commit.rfWen &&
          commit.rd =/= 0.U &&
          busy(commit.rd) &&
          producer(commit.rd) === commit.robIdx
      ) {
        busy(commit.rd) := false.B
      }
    }

    for (register <- 1 until 32) {
      val (hasAllocation, newestProducer) = newestAllocation(register.U, 0 until cfg.dispatchWidth)
      when(hasAllocation) {
        busy(register)     := true.B
        producer(register) := newestProducer
      }
    }
  }
}
