package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Mux1H, OHToUInt, PopCount, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{
  StoreDrainRequest,
  StoreForwardQuery,
  StoreQueueAlloc,
  StoreQueueCommit,
  StoreQueueEvent,
  StoreQueuePerf,
  StoreQueueUpdate,
  StoreResponseEvent,
  StoreTrackerQuery
}
import top.core.bundle.{RobAge, RobRecovery}

object StoreQueueState {
  val width = 3

  val free      = 0.U(width.W)
  val allocated = 1.U(width.W)
  val resolved  = 2.U(width.W)
  val committed = 3.U(width.W)
  val issued    = 4.U(width.W)
}

/** Owns store identity, speculative resolution, forwarding, retirement state, and drain order.
  *
  * `sqIdx` selects the durable entry. ROB indices remain metadata used only for speculative age checks and assertions;
  * they are never used to find a committed store after retirement.
  */
class StoreQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount = cfg.storeQueueEntries
  private val dataBytes  = cfg.dataWidth / 8
  private val countWidth = math.max(chisel3.util.log2Ceil(entryCount + 1), 1)

  val io = IO(new Bundle {
    val alloc      = Input(Vec(cfg.dispatchWidth, new StoreQueueAlloc(cfg)))
    val allocReady = Output(Vec(cfg.dispatchWidth, Bool()))
    val allocSqIdx = Output(Vec(cfg.dispatchWidth, UInt(cfg.sqIdxWidth.W)))

    val update   = Input(Valid(new StoreQueueUpdate(cfg)))
    val commit   = Input(Vec(cfg.commitWidth, new StoreQueueCommit(cfg)))
    val reserve  = Input(Valid(new StoreQueueEvent(cfg)))
    val issue    = Input(Valid(new StoreQueueEvent(cfg)))
    val response = Input(Valid(new StoreResponseEvent(cfg)))

    val normalDrain       = Decoupled(new StoreDrainRequest(cfg))
    val serializedSelect  = Input(Valid(new StoreQueueEvent(cfg)))
    val serializedRequest = Output(Valid(new StoreDrainRequest(cfg)))

    val issueQuery = Vec(cfg.issueQueueEntries, new StoreTrackerQuery(cfg))
    val query      = new StoreForwardQuery(cfg)
    val robHead    = Input(UInt(cfg.robIdxWidth.W))
    val flush      = Input(Bool())
    val recover    = Input(new RobRecovery(cfg.robIdxWidth))

    val occupancy        = Output(UInt(countWidth.W))
    val committedPending = Output(Bool())
    val perf             = Output(new StoreQueuePerf(cfg))
  })

  private val state    = RegInit(VecInit(Seq.fill(entryCount)(StoreQueueState.free)))
  private val reserved = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val robIdx   = Reg(Vec(entryCount, UInt(cfg.robIdxWidth.W)))
  private val vaddr    = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val addr     = Reg(Vec(entryCount, UInt(cfg.addrWidth.W)))
  private val data     = Reg(Vec(entryCount, UInt(cfg.dataWidth.W)))
  private val mask     = Reg(Vec(entryCount, UInt(dataBytes.W)))
  private val size     = Reg(Vec(entryCount, UInt(3.W)))
  private val mmio     = RegInit(VecInit(Seq.fill(entryCount)(false.B)))

  // This compact list is the authoritative program order. Arbitrary response completion can leave entry indices free
  // out of order, so numeric sqIdx ordering is intentionally never used as age.
  private val order      = Reg(Vec(entryCount, UInt(cfg.sqIdxWidth.W)))
  private val orderCount = RegInit(0.U(countWidth.W))

  private def live(entry: Int): Bool =
    state(entry) =/= StoreQueueState.free

  private def committedOrIssued(entry: UInt): Bool =
    state(entry) === StoreQueueState.committed || state(entry) === StoreQueueState.issued || reserved(entry)

  private def fillRequest(entry: UInt, request: StoreDrainRequest): Unit = {
    request.sqIdx  := entry
    request.robIdx := robIdx(entry)
    request.vaddr  := vaddr(entry)
    request.addr   := addr(entry)
    request.data   := data(entry)
    request.mask   := mask(entry)
    request.size   := size(entry)
    request.mmio   := mmio(entry)
  }

  private val responseHit = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    responseHit(entry) := io.response.valid && live(entry) &&
      io.response.bits.sqIdx === entry.U && io.response.bits.robIdx === robIdx(entry)
  }

  // A matching response may release and reallocate an SQ entry in the same cycle.
  private val freeForAlloc = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    freeForAlloc(entry) := !live(entry) || responseHit(entry)
  }

  private val allocSelectOH = Wire(Vec(cfg.dispatchWidth, Vec(entryCount, Bool())))
  private val allocFire     = Wire(Vec(cfg.dispatchWidth, Bool()))
  for (lane <- 0 until cfg.dispatchWidth) {
    for (entry <- 0 until entryCount) {
      val usedByEarlierLane =
        if (lane == 0) false.B
        else (0 until lane).map(previous => io.alloc(previous).valid && allocSelectOH(previous)(entry)).reduce(_ || _)
      val available         = freeForAlloc(entry) && !usedByEarlierLane
      val earlierAvailable  =
        if (entry == 0) false.B
        else {
          (0 until entry).map { previousEntry =>
            val usedEarlier =
              if (lane == 0) false.B
              else
                (0 until lane)
                  .map(previousLane => io.alloc(previousLane).valid && allocSelectOH(previousLane)(previousEntry))
                  .reduce(_ || _)
            freeForAlloc(previousEntry) && !usedEarlier
          }.reduce(_ || _)
        }
      allocSelectOH(lane)(entry) := available && !earlierAvailable
    }

    io.allocReady(lane) := allocSelectOH(lane).asUInt.orR && !io.flush && !io.recover.valid
    io.allocSqIdx(lane) := OHToUInt(allocSelectOH(lane))
    allocFire(lane)     := io.alloc(lane).valid && io.allocReady(lane)
  }

  for (query <- io.issueQuery) {
    val loadAge                 = RobAge.fromHead(query.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
    val hasOlderUnresolvedStore = VecInit((0 until entryCount).map { entry =>
      live(entry) && state(entry) === StoreQueueState.allocated &&
      RobAge.fromHead(robIdx(entry), io.robHead, cfg.robEntries, cfg.robIdxWidth) < loadAge
    }).asUInt.orR
    query.hasOlderStore := query.valid && hasOlderUnresolvedStore
  }

  private val loadAge       = RobAge.fromHead(io.query.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  private val queryWordAddr = io.query.addr & ~((dataBytes - 1).U(cfg.addrWidth.W))
  private val queryMaskWord = (io.query.mask << io.query.addr(1, 0))(dataBytes - 1, 0)

  private var selectedValid = Seq.fill(dataBytes)(false.B)
  private var selectedData  = Seq.fill(dataBytes)(0.U(8.W))

  // Walk oldest to youngest and overwrite each matching byte. The final value is therefore from the youngest older
  // store independently for every byte.
  for (position <- 0 until entryCount) {
    val entry         = order(position)
    val positionLive  = position.U < orderCount
    val entryWordAddr = addr(entry) & ~((dataBytes - 1).U(cfg.addrWidth.W))
    val entryMaskWord = (mask(entry) << addr(entry)(1, 0))(dataBytes - 1, 0)
    val entryDataWord = (data(entry) << (addr(entry)(1, 0) << 3))(cfg.dataWidth - 1, 0)
    val olderThanLoad = committedOrIssued(entry) ||
      RobAge.fromHead(robIdx(entry), io.robHead, cfg.robEntries, cfg.robIdxWidth) < loadAge
    val usable        = positionLive && state(entry) =/= StoreQueueState.allocated && olderThanLoad &&
      entryWordAddr === queryWordAddr

    val previousValid = selectedValid
    val previousData  = selectedData
    val selectByte    = (0 until dataBytes).map { byte =>
      usable && queryMaskWord(byte) && entryMaskWord(byte)
    }

    selectedValid = (0 until dataBytes).map(byte => Mux(selectByte(byte), true.B, previousValid(byte)))
    selectedData = (0 until dataBytes).map { byte =>
      Mux(selectByte(byte), entryDataWord(8 * byte + 7, 8 * byte), previousData(byte))
    }
  }

  private val unresolvedOlderStore = VecInit((0 until entryCount).map { entry =>
    val olderThanLoad = committedOrIssued(entry.U) ||
      RobAge.fromHead(robIdx(entry), io.robHead, cfg.robEntries, cfg.robIdxWidth) < loadAge
    live(entry) && state(entry) === StoreQueueState.allocated && olderThanLoad
  }).asUInt.orR
  private val selectedMaskWord     = VecInit(selectedValid).asUInt
  private val selectedDataWord     = Cat(selectedData.reverse)
  private val forwardMask          = (selectedMaskWord >> io.query.addr(1, 0))(dataBytes - 1, 0)
  private val forwardData          = (selectedDataWord >> (io.query.addr(1, 0) << 3))(cfg.dataWidth - 1, 0)
  private val fullForward          = (forwardMask & io.query.mask) === io.query.mask

  io.query.unresolved     := io.query.valid && unresolvedOlderStore
  io.query.forwardMask    := forwardMask
  io.query.forwardData    := forwardData
  io.query.fullForward    := io.query.valid && !unresolvedOlderStore && fullForward
  io.query.partialForward := io.query.valid && !unresolvedOlderStore && forwardMask.orR && !fullForward

  // Issued or already-reserved stores no longer block the next request. The first remaining entry in program order must
  // be committed before the drain engine may reserve it.
  private val pendingPosition = Wire(Vec(entryCount, Bool()))
  private val drainPositionOH = Wire(Vec(entryCount, Bool()))
  for (position <- 0 until entryCount) {
    val entry = order(position)
    pendingPosition(position) := position.U < orderCount && state(entry) =/= StoreQueueState.issued && !reserved(entry)
    val earlierPending =
      if (position == 0) false.B else pendingPosition.take(position).reduce(_ || _)
    drainPositionOH(position) := pendingPosition(position) && !earlierPending &&
      state(entry) === StoreQueueState.committed && !mmio(entry)
  }

  private val drainRequests = Wire(Vec(entryCount, new StoreDrainRequest(cfg)))
  for (position <- 0 until entryCount) {
    drainRequests(position) := 0.U.asTypeOf(new StoreDrainRequest(cfg))
    fillRequest(order(position), drainRequests(position))
  }
  io.normalDrain.valid := drainPositionOH.asUInt.orR
  io.normalDrain.bits := Mux1H(drainPositionOH, drainRequests)

  private val serializedHit      = Wire(Vec(entryCount, Bool()))
  private val serializedOwned    = Wire(Vec(entryCount, Bool()))
  private val serializedRequests = Wire(Vec(entryCount, new StoreDrainRequest(cfg)))
  for (entry <- 0 until entryCount) {
    serializedHit(entry)      := io.serializedSelect.valid && live(entry) &&
      io.serializedSelect.bits.sqIdx === entry.U && io.serializedSelect.bits.robIdx === robIdx(entry) &&
      state(entry) === StoreQueueState.resolved && mmio(entry) && !reserved(entry)
    serializedOwned(entry)    := io.serializedSelect.valid && live(entry) &&
      io.serializedSelect.bits.sqIdx === entry.U && io.serializedSelect.bits.robIdx === robIdx(entry) &&
      mmio(entry) && reserved(entry)
    serializedRequests(entry) := 0.U.asTypeOf(new StoreDrainRequest(cfg))
    fillRequest(entry.U, serializedRequests(entry))
  }
  io.serializedRequest.valid := serializedHit.asUInt.orR
  io.serializedRequest.bits := Mux1H(serializedHit, serializedRequests)

  private val updateHit = VecInit((0 until entryCount).map { entry =>
    io.update.valid && live(entry) && io.update.bits.sqIdx === entry.U &&
    io.update.bits.robIdx === robIdx(entry) && state(entry) === StoreQueueState.allocated
  })
  private val commitHit = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    commitHit(entry) := io.commit.map { commit =>
      commit.valid && live(entry) && commit.sqIdx === entry.U && commit.robIdx === robIdx(entry) &&
      state(entry) === StoreQueueState.resolved && !mmio(entry)
    }.reduce(_ || _)
  }
  private val reserveHit = VecInit((0 until entryCount).map { entry =>
    io.reserve.valid && live(entry) && io.reserve.bits.sqIdx === entry.U &&
    io.reserve.bits.robIdx === robIdx(entry) && !reserved(entry) &&
    (state(entry) === StoreQueueState.committed || (state(entry) === StoreQueueState.resolved && mmio(entry)))
  })
  private val issueHit = VecInit((0 until entryCount).map { entry =>
    io.issue.valid && live(entry) && io.issue.bits.sqIdx === entry.U &&
    io.issue.bits.robIdx === robIdx(entry) && reserved(entry) &&
    (state(entry) === StoreQueueState.committed || state(entry) === StoreQueueState.resolved)
  })

  private val killed = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    val speculative      = state(entry) === StoreQueueState.allocated ||
      (state(entry) === StoreQueueState.resolved && !reserved(entry))
    val killedByRecovery = io.recover.valid &&
      RobAge.isYounger(robIdx(entry), io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
    killed(entry) := live(entry) && speculative && !commitHit(entry) && (io.flush || killedByRecovery)
  }

  private val removeEntry = Wire(Vec(entryCount, Bool()))
  for (entry <- 0 until entryCount) {
    removeEntry(entry) := responseHit(entry) || killed(entry)
  }

  private val keepOrder = Wire(Vec(entryCount, Bool()))
  for (position <- 0 until entryCount) {
    keepOrder(position) := position.U < orderCount && !removeEntry(order(position))
  }
  private val retainedCount = PopCount(keepOrder)
  private val nextOrder = Wire(Vec(entryCount, UInt(cfg.sqIdxWidth.W)))
  for (destination <- 0 until entryCount) {
    val sourceOH = Wire(Vec(entryCount, Bool()))
    for (source <- 0 until entryCount) {
      val priorKept = if (source == 0) 0.U else PopCount(keepOrder.take(source))
      sourceOH(source) := keepOrder(source) && priorKept === destination.U
    }
    nextOrder(destination) := Mux(sourceOH.asUInt.orR, Mux1H(sourceOH, order), 0.U)
  }
  for (lane        <- 0 until cfg.dispatchWidth) {
    val priorAllocations = if (lane == 0) 0.U else PopCount(allocFire.take(lane))
    val destination      = retainedCount + priorAllocations
    for (position <- 0 until entryCount) {
      when(allocFire(lane) && destination === position.U) {
        nextOrder(position) := io.allocSqIdx(lane)
      }
    }
  }

  order      := nextOrder
  orderCount := retainedCount + PopCount(allocFire)

  for (entry <- 0 until entryCount) {
    when(killed(entry)) {
      state(entry)    := StoreQueueState.free
      reserved(entry) := false.B
      mmio(entry)     := false.B
    }
    when(commitHit(entry)) {
      state(entry) := StoreQueueState.committed
    }
    when(responseHit(entry)) {
      state(entry)    := StoreQueueState.free
      reserved(entry) := false.B
      mmio(entry)     := false.B
    }
    when(updateHit(entry)) {
      state(entry) := StoreQueueState.resolved
      vaddr(entry) := io.update.bits.vaddr
      addr(entry)  := io.update.bits.addr
      data(entry)  := io.update.bits.data
      mask(entry)  := io.update.bits.mask
      size(entry)  := io.update.bits.size
      mmio(entry)  := io.update.bits.mmio
    }
    when(reserveHit(entry)) {
      reserved(entry) := true.B
    }
    when(issueHit(entry)) {
      state(entry) := StoreQueueState.issued
    }
    for (lane <- 0 until cfg.dispatchWidth) {
      when(allocFire(lane) && io.allocSqIdx(lane) === entry.U) {
        state(entry)    := StoreQueueState.allocated
        reserved(entry) := false.B
        robIdx(entry)   := io.alloc(lane).robIdx
        vaddr(entry)    := 0.U
        addr(entry)     := 0.U
        data(entry)     := 0.U
        mask(entry)     := 0.U
        size(entry)     := 0.U
        mmio(entry)     := false.B
      }
    }
  }

  io.occupancy        := PopCount(state.map(_ =/= StoreQueueState.free))
  io.committedPending := VecInit((0 until entryCount).map { entry =>
    live(entry) && (state(entry) === StoreQueueState.committed || state(entry) === StoreQueueState.issued || reserved(
      entry
    ))
  }).asUInt.orR
  io.perf.alloc       := allocFire.asUInt.orR
  io.perf.fullStall   := VecInit(
    (0 until cfg.dispatchWidth).map(lane => io.alloc(lane).valid && !io.allocReady(lane))
  ).asUInt.orR
  io.perf.commit      := commitHit.asUInt.orR
  io.perf.request     := io.issue.valid
  io.perf.response    := io.response.valid
  io.perf.occupancy   := io.occupancy

  for (left  <- 0 until cfg.dispatchWidth) {
    for (right <- left + 1 until cfg.dispatchWidth) {
      assert(!(allocFire(left) && allocFire(right)) || io.allocSqIdx(left) =/= io.allocSqIdx(right))
    }
  }
  when(io.update.valid) {
    assert(PopCount(updateHit) === 1.U, "store update must reference exactly one allocated sqIdx")
  }
  for (lane  <- 0 until cfg.commitWidth) {
    val laneHits = VecInit((0 until entryCount).map { entry =>
      io.commit(lane).valid && live(entry) && io.commit(lane).sqIdx === entry.U &&
      io.commit(lane).robIdx === robIdx(entry) && state(entry) === StoreQueueState.resolved && !mmio(entry)
    })
    when(io.commit(lane).valid) {
      assert(PopCount(laneHits) === 1.U, "store commit must reference exactly one resolved sqIdx")
    }
  }
  for (left  <- 0 until cfg.commitWidth) {
    for (right <- left + 1 until cfg.commitWidth) {
      assert(!(io.commit(left).valid && io.commit(right).valid) || io.commit(left).sqIdx =/= io.commit(right).sqIdx)
    }
  }
  when(io.reserve.valid) {
    assert(PopCount(reserveHit) === 1.U, "store drain reservation must reference exactly one eligible sqIdx")
  }
  when(io.issue.valid) {
    assert(PopCount(issueHit) === 1.U, "store request must reference exactly one reserved sqIdx")
    for (position <- 0 until entryCount) {
      when(position.U < orderCount && order(position) === io.issue.bits.sqIdx) {
        for (older <- 0 until position) {
          when(older.U < orderCount) {
            assert(
              state(order(older)) === StoreQueueState.issued,
              "store drain requests must externalize in program order"
            )
          }
        }
      }
    }
  }
  when(io.response.valid) {
    assert(PopCount(responseHit) === 1.U, "store response must reference exactly one issued sqIdx")
  }
  when(io.serializedSelect.valid) {
    assert(
      PopCount(serializedHit) + PopCount(serializedOwned) === 1.U,
      "serialized store must reference exactly one resolved or active MMIO sqIdx"
    )
  }
  for (entry <- 0 until entryCount) {
    when(
      live(entry) && (state(entry) === StoreQueueState.committed || state(entry) === StoreQueueState.issued || reserved(
        entry
      ))
    ) {
      assert(!killed(entry), "committed or irreversible stores must survive recovery")
    }
  }
}
