package top.core.backend.lsu

import chisel3._
import top.core.backend.bundle.{StoreTrackerAlloc, StoreTrackerCommit, StoreTrackerQuery}
import top.config.BackendConfig

class StoreTracker(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val alloc   = Input(Vec(cfg.dispatchWidth, new StoreTrackerAlloc(cfg)))
    val commit  = Input(Vec(cfg.commitWidth, new StoreTrackerCommit(cfg)))
    val query   = Vec(cfg.issueQueueEntries, new StoreTrackerQuery(cfg))
    val robHead = Input(UInt(cfg.robIdxWidth.W))
    val flush   = Input(Bool())
  })

  private val valid  = RegInit(VecInit(Seq.fill(cfg.robEntries)(false.B)))
  private val robIdx = Reg(Vec(cfg.robEntries, UInt(cfg.robIdxWidth.W)))

  private val ageWidth = cfg.robIdxWidth + 1

  private def extendRobIdx(idx: UInt): UInt = {
    val extended = Wire(UInt(ageWidth.W))
    extended := idx
    extended
  }

  private def ageFromHead(idx: UInt): UInt = {
    val idxExt  = extendRobIdx(idx)
    val headExt = extendRobIdx(io.robHead)

    Mux(
      idx >= io.robHead,
      idxExt - headExt,
      idxExt + cfg.robEntries.U(ageWidth.W) - headExt
    )
  }

  for (query <- io.query) {
    val loadAge  = ageFromHead(query.robIdx)
    val hasOlder = (0 until cfg.robEntries).map { i =>
      valid(i) && ageFromHead(robIdx(i)) < loadAge
    }.reduce(_ || _)

    query.hasOlderStore := query.valid && hasOlder
  }

  private val free = Wire(Vec(cfg.robEntries, Bool()))
  for (i <- 0 until cfg.robEntries) {
    val commitHit = io.commit.map(commit => commit.valid && commit.robIdx === robIdx(i)).reduce(_ || _)
    free(i) := !valid(i) || commitHit
  }

  private val allocOH = Wire(Vec(cfg.dispatchWidth, Vec(cfg.robEntries, Bool())))
  for (allocIdx <- 0 until cfg.dispatchWidth) {
    for (entryIdx <- 0 until cfg.robEntries) {
      val usedByEarlierAlloc    = if (allocIdx == 0) {
        false.B
      } else {
        (0 until allocIdx).map(earlierAllocIdx => allocOH(earlierAllocIdx)(entryIdx)).reduce(_ || _)
      }
      val entryAvailable        = free(entryIdx) && !usedByEarlierAlloc
      val earlierEntryAvailable = if (entryIdx == 0) {
        false.B
      } else {
        (0 until entryIdx).map { earlierEntryIdx =>
          val earlierEntryUsed = if (allocIdx == 0) {
            false.B
          } else {
            (0 until allocIdx).map(earlierAllocIdx => allocOH(earlierAllocIdx)(earlierEntryIdx)).reduce(_ || _)
          }
          free(earlierEntryIdx) && !earlierEntryUsed
        }
          .reduce(_ || _)
      }

      allocOH(allocIdx)(entryIdx) := io.alloc(allocIdx).valid && entryAvailable && !earlierEntryAvailable
    }
  }

  for (i <- 0 until cfg.robEntries) {
    when(io.flush) {
      valid(i) := false.B
    }.otherwise {
      for (commit <- io.commit) {
        when(commit.valid && valid(i) && robIdx(i) === commit.robIdx) {
          valid(i) := false.B
        }
      }

      for (allocIdx <- 0 until cfg.dispatchWidth) {
        val alloc = io.alloc(allocIdx)
        when(allocOH(allocIdx)(i)) {
          valid(i)  := true.B
          robIdx(i) := alloc.robIdx
        }
      }
    }
  }
}
