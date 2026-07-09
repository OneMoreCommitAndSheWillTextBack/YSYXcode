package top.core.backend.dispatch

import chisel3._
import top.core.backend.bundle.{ScoreboardAlloc, ScoreboardCommit, ScoreboardQuery}
import top.config.BackendConfig

class Scoreboard(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val query  = Vec(cfg.scoreboardQueries, new ScoreboardQuery(cfg))
    val alloc  = Input(Vec(cfg.dispatchWidth, new ScoreboardAlloc(cfg)))
    val commit = Input(Vec(cfg.commitWidth, new ScoreboardCommit(cfg)))
    val flush  = Input(Bool())
  })

  private val busy     = RegInit(VecInit(Seq.fill(32)(false.B)))
  private val producer = Reg(Vec(32, UInt(cfg.robIdxWidth.W)))

  for ((query, queryIdx) <- io.query.zipWithIndex) {
    val dispatchSlot = queryIdx / cfg.operandsPerInst
    val ready        = WireDefault(!query.valid || query.rs === 0.U || !busy(query.rs))
    val tag          = WireDefault(producer(query.rs))

    for (allocIdx <- 0 until dispatchSlot) {
      val alloc = io.alloc(allocIdx)
      when(query.valid && query.rs =/= 0.U && alloc.valid && alloc.rfWen && alloc.rd =/= 0.U && alloc.rd === query.rs) {
        ready := false.B
        tag   := alloc.robIdx
      }
    }

    query.ready    := ready
    query.producer := tag
  }

  when(io.flush) {
    for (idx <- 0 until 32) {
      busy(idx) := false.B
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

    for (alloc <- io.alloc) {
      when(alloc.valid && alloc.rfWen && alloc.rd =/= 0.U) {
        busy(alloc.rd)     := true.B
        producer(alloc.rd) := alloc.robIdx
      }
    }
  }
}
