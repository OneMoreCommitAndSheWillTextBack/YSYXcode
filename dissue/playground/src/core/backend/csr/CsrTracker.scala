package top.core.backend.csr

import chisel3._
import top.config.BackendConfig

class CsrTracker(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val alloc   = Input(Vec(cfg.dispatchWidth, new CsrTrackerAlloc(cfg)))
    val commit  = Input(Vec(cfg.commitWidth, new CsrTrackerCommit(cfg)))
    val query   = Vec(cfg.issueQueueEntries, new CsrTrackerQuery(cfg))
    val robHead = Input(UInt(cfg.robIdxWidth.W))
    val flush   = Input(Bool())
  })

  private val valid  = RegInit(VecInit(Seq.fill(cfg.robEntries)(false.B)))
  private val robIdx = Reg(Vec(cfg.robEntries, UInt(cfg.robIdxWidth.W)))
  private val addr   = Reg(Vec(cfg.robEntries, UInt(CsrAddr.width.W)))

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

  private val commitHit = Wire(Vec(cfg.robEntries, Bool()))
  for (entry <- 0 until cfg.robEntries) {
    commitHit(entry) := io.commit.map(commit => commit.valid && commit.robIdx === robIdx(entry)).reduce(_ || _)
  }

  for (query <- io.query) {
    val queryAge = ageFromHead(query.robIdx)
    val hasOlder = (0 until cfg.robEntries).map { entry =>
      valid(entry) &&
      CsrAddr.sameHazardDomain(addr(entry), query.addr) &&
      ageFromHead(robIdx(entry)) < queryAge
    }.reduce(_ || _)

    query.hasOlderSameAddrWriter := query.valid && hasOlder
  }

  private val free = Wire(Vec(cfg.robEntries, Bool()))
  for (entry <- 0 until cfg.robEntries) {
    free(entry) := !valid(entry) || commitHit(entry)
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
        }.reduce(_ || _)
      }

      allocOH(allocIdx)(entryIdx) := io.alloc(allocIdx).valid && entryAvailable && !earlierEntryAvailable
    }
  }

  for (entry <- 0 until cfg.robEntries) {
    when(io.flush) {
      valid(entry) := false.B
    }.otherwise {
      when(commitHit(entry)) {
        valid(entry) := false.B
      }

      for (allocIdx <- 0 until cfg.dispatchWidth) {
        when(allocOH(allocIdx)(entry)) {
          valid(entry)  := true.B
          robIdx(entry) := io.alloc(allocIdx).robIdx
          addr(entry)   := io.alloc(allocIdx).addr
        }
      }
    }
  }
}
