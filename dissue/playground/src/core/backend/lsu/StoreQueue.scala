package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, PopCount}
import top.config.BackendConfig
import top.core.bundle.{RobAge, RobRecovery}
import top.core.backend.bundle.{
  StoreForwardQuery,
  StoreQueueAlloc,
  StoreQueueCommit,
  StoreQueueDrain,
  StoreQueuePerf,
  StoreQueueUpdate,
  StoreTrackerQuery
}

/** Tracks speculative stores until their write-through request has completed.
  *
  * Loads query this queue after address translation. The query is conservative for unresolved older stores and forwards
  * the youngest matching store per byte for resolved entries.
  */
class StoreQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount = cfg.robEntries
  private val dataBytes  = cfg.dataWidth / 8
  private val ageWidth   = cfg.robIdxWidth + 1

  val io = IO(new Bundle {
    val alloc      = Input(Vec(cfg.dispatchWidth, new StoreQueueAlloc(cfg)))
    val update     = Input(new StoreQueueUpdate(cfg))
    val commit     = Input(Vec(cfg.commitWidth, new StoreQueueCommit(cfg)))
    val drain      = Input(new StoreQueueDrain(cfg))
    val issueQuery = Vec(cfg.issueQueueEntries, new StoreTrackerQuery(cfg))
    val query      = new StoreForwardQuery(cfg)
    val robHead    = Input(UInt(cfg.robIdxWidth.W))
    val flush      = Input(Bool())
    val recover    = Input(new RobRecovery(cfg.robIdxWidth))
    val occupancy  = Output(UInt(math.max(chisel3.util.log2Ceil(entryCount + 1), 1).W))
    val perf       = Output(new StoreQueuePerf(cfg))
  })

  private val valid     = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val committed = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val addrReady = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val dataReady = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val robIdx    = Reg(Vec(entryCount, UInt(cfg.robIdxWidth.W)))
  private val addr      = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val data      = Reg(Vec(entryCount, UInt(cfg.dataWidth.W)))
  private val mask      = Reg(Vec(entryCount, UInt(dataBytes.W)))

  private def ageFromHead(index: UInt): UInt = {
    val indexExt = index.pad(ageWidth)
    val headExt  = io.robHead.pad(ageWidth)
    Mux(
      index >= io.robHead,
      indexExt - headExt,
      indexExt + entryCount.U(ageWidth.W) - headExt
    )
  }

  for (query <- io.issueQuery) {
    val loadAge                 = ageFromHead(query.robIdx)
    val hasOlderUnresolvedStore = VecInit((0 until entryCount).map { entry =>
      valid(entry) && ageFromHead(robIdx(entry)) < loadAge && (!addrReady(entry) || !dataReady(entry))
    }).asUInt.orR
    query.hasOlderStore := query.valid && hasOlderUnresolvedStore
  }

  private val drainHit = Wire(Vec(entryCount, Bool()))
  private val free     = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    drainHit(entry) := io.drain.valid && valid(entry) && robIdx(entry) === io.drain.robIdx
    free(entry)     := !valid(entry) || drainHit(entry)
  }

  private val allocOH = Wire(Vec(cfg.dispatchWidth, Vec(entryCount, Bool())))
  for (lane <- 0 until cfg.dispatchWidth) {
    for (entry <- 0 until entryCount) {
      val usedByEarlierLane =
        if (lane == 0) false.B else (0 until lane).map(previous => allocOH(previous)(entry)).reduce(_ || _)
      val available         = free(entry) && !usedByEarlierLane
      val earlierAvailable  =
        if (entry == 0) false.B
        else {
          (0 until entry).map { previous =>
            val usedEarlier =
              if (lane == 0) false.B
              else (0 until lane).map(previousLane => allocOH(previousLane)(previous)).reduce(_ || _)
            free(previous) && !usedEarlier
          }.reduce(_ || _)
        }
      allocOH(lane)(entry) := io.alloc(lane).valid && available && !earlierAvailable
    }
  }

  private val loadAge       = ageFromHead(io.query.robIdx)
  private val queryWordAddr = io.query.addr & ~((dataBytes - 1).U(cfg.addrWidth.W))
  private val queryMaskWord = (io.query.mask << io.query.addr(1, 0))(dataBytes - 1, 0)

  // Once a store has committed, it has passed the ROB head and is necessarily
  // older than every load still in flight. Its wrapped ROB index cannot be
  // compared directly against the current head anymore.
  private def olderThanLoad(entry: Int): Bool =
    committed(entry) || ageFromHead(robIdx(entry)) < loadAge

  private val unresolvedOlderStore = VecInit((0 until entryCount).map { entry =>
    valid(entry) && olderThanLoad(entry) && (!addrReady(entry) || !dataReady(entry))
  }).asUInt.orR

  private var selectedValid = Seq.fill(dataBytes)(false.B)
  private var selectedAge   = Seq.fill(dataBytes)(0.U(ageWidth.W))
  private var selectedData  = Seq.fill(dataBytes)(0.U(8.W))

  for (entry <- 0 until entryCount) {
    val entryAge      = ageFromHead(robIdx(entry))
    val entryWordAddr = addr(entry) & ~((dataBytes - 1).U(cfg.addrWidth.W))
    val entryMaskWord = (mask(entry) << addr(entry)(1, 0))(dataBytes - 1, 0)
    val entryDataWord = (data(entry) << (addr(entry)(1, 0) << 3))(cfg.dataWidth - 1, 0)
    val usable        = valid(entry) && addrReady(entry) && dataReady(entry) && olderThanLoad(entry) &&
      entryWordAddr === queryWordAddr

    val previousValid = selectedValid
    val previousAge   = selectedAge
    val previousData  = selectedData
    val selectByte    = (0 until dataBytes).map { byte =>
      usable && queryMaskWord(byte) && entryMaskWord(byte) &&
      (!previousValid(byte) || entryAge > previousAge(byte))
    }

    selectedValid = (0 until dataBytes).map(byte => Mux(selectByte(byte), true.B, previousValid(byte)))
    selectedAge = (0 until dataBytes).map(byte => Mux(selectByte(byte), entryAge, previousAge(byte)))
    selectedData = (0 until dataBytes).map { byte =>
      Mux(selectByte(byte), entryDataWord(8 * byte + 7, 8 * byte), previousData(byte))
    }
  }

  private val selectedMaskWord = VecInit(selectedValid).asUInt
  private val selectedDataWord = Cat(selectedData.reverse)
  private val forwardMask      = (selectedMaskWord >> io.query.addr(1, 0))(dataBytes - 1, 0)
  private val forwardData      = (selectedDataWord >> (io.query.addr(1, 0) << 3))(cfg.dataWidth - 1, 0)
  private val fullForward      = (forwardMask & io.query.mask) === io.query.mask

  io.query.unresolved     := io.query.valid && unresolvedOlderStore
  io.query.forwardMask    := forwardMask
  io.query.forwardData    := forwardData
  io.query.fullForward    := io.query.valid && !unresolvedOlderStore && fullForward
  io.query.partialForward := io.query.valid && !unresolvedOlderStore && forwardMask.orR && !fullForward
  io.occupancy            := PopCount(valid)
  io.perf.alloc           := VecInit(allocOH.flatten).asUInt.orR
  io.perf.fullStall       := PopCount(io.alloc.map(_.valid)) > PopCount(allocOH.flatten)
  io.perf.drain           := io.drain.valid
  io.perf.occupancy       := PopCount(valid)

  for (entry <- 0 until entryCount) {
    val commitHit =
      io.commit.map(commit => commit.valid && valid(entry) && commit.robIdx === robIdx(entry)).reduce(_ || _)
    val updateHit = io.update.valid && valid(entry) && io.update.robIdx === robIdx(entry)

    when(io.flush) {
      when(!committed(entry) || drainHit(entry)) {
        valid(entry) := false.B
      }
    }.elsewhen(io.recover.valid) {
      when(drainHit(entry) || (!committed(entry) &&
        RobAge.isYounger(robIdx(entry), io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth))) {
        valid(entry) := false.B
      }
    }.otherwise {
      when(drainHit(entry)) {
        valid(entry) := false.B
      }
      when(commitHit) {
        committed(entry) := true.B
      }
      when(updateHit) {
        addr(entry)      := io.update.addr
        data(entry)      := io.update.data
        mask(entry)      := io.update.mask
        addrReady(entry) := true.B
        dataReady(entry) := true.B
      }
      for (lane <- 0 until cfg.dispatchWidth) {
        when(allocOH(lane)(entry)) {
          valid(entry)     := true.B
          committed(entry) := false.B
          addrReady(entry) := false.B
          dataReady(entry) := false.B
          robIdx(entry)    := io.alloc(lane).robIdx
          addr(entry)      := 0.U
          data(entry)      := 0.U
          mask(entry)      := 0.U
        }
      }
    }
  }
}
