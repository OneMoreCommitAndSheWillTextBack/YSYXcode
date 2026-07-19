package top.core.frontend.Bpu

import chisel3._
import chisel3.util._

import top.core.frontend.bundle._
import top.config._
import top.core.bundle.CfiType

class BtbResp(cfg: BpuConfig) extends Bundle {
  val hit       = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
}

class BtbUpdate(cfg: BpuConfig) extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
}

class BtbBundle(cfg: BpuConfig) extends Bundle {
  val lookupPc = Input(Vec(2, UInt(cfg.addrWidth.W)))
  val resp     = Output(Vec(2, new BtbResp(cfg)))
  val update   = Input(Vec(PredictorConstants.commitUpdateWidth, Valid(new BtbUpdate(cfg))))
}

class Btb(cfg: BpuConfig) extends Module {
  val io = IO(new BtbBundle(cfg))

  private val idxWidth    = cfg.btbIndexBits
  private val tagWidth    = cfg.btbTagBits
  private val offsetWidth = cfg.offsetBits

  private def tag(pc: UInt) =
    pc(cfg.addrWidth - 1, idxWidth + offsetWidth)

  private def index(pc: UInt) =
    pc(idxWidth + offsetWidth - 1, offsetWidth)

  val validArray  = RegInit(VecInit(Seq.fill(cfg.btbEntries)(false.B)))
  val tagArray    = Reg(Vec(cfg.btbEntries, UInt(tagWidth.W)))
  val targetArray = Reg(Vec(cfg.btbEntries, UInt(cfg.addrWidth.W)))
  val cfitpArray  = Reg(Vec(cfg.btbEntries, UInt(CfiType.width.W)))
  val cfioffArray = Reg(Vec(cfg.btbEntries, UInt(cfg.cfiOffsetBits.W)))

  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    val updateSet = index(io.update(lane).bits.pc)
    val updateTag = tag(io.update(lane).bits.pc)

    when(io.update(lane).valid) {
      validArray(updateSet)  := true.B
      tagArray(updateSet)    := updateTag
      targetArray(updateSet) := io.update(lane).bits.target
      cfitpArray(updateSet)  := io.update(lane).bits.cfiType
      cfioffArray(updateSet) := io.update(lane).bits.cfiOffset
    }
  }

  for (lane <- 0 until 2) {
    val reqSet = index(io.lookupPc(lane))
    val reqTag = tag(io.lookupPc(lane))
    val hit    = validArray(reqSet) && tagArray(reqSet) === reqTag

    io.resp(lane).hit       := hit
    io.resp(lane).target    := Mux(hit, targetArray(reqSet), 0.U)
    io.resp(lane).cfiOffset := Mux(hit, cfioffArray(reqSet), 0.U)
    io.resp(lane).cfiType   := Mux(hit, cfitpArray(reqSet), CfiType.none)
  }
}

class BhtUpdate(cfg: BpuConfig) extends Bundle {
  val pc    = UInt(cfg.addrWidth.W)
  val taken = Bool()
}

class BhtBundle(cfg: BpuConfig) extends Bundle {
  val lookupPc = Input(Vec(2, UInt(cfg.addrWidth.W)))
  val taken    = Output(Vec(2, Bool()))
  val update   = Input(Vec(PredictorConstants.commitUpdateWidth, Valid(new BhtUpdate(cfg))))
}

object TakenState extends ChiselEnum {
  val strongNotTaken, weakNotTaken, weakTaken, strongTaken = Value
}

class Bht(cfg: BpuConfig) extends Module {
  val io = IO(new BhtBundle(cfg))

  private val offsetWidth = cfg.offsetBits
  private val idxWidth    = cfg.bhtIndexBits

  private def idx(pc: UInt) =
    pc(idxWidth + offsetWidth - 1, offsetWidth)

  private def nextTakenState(state: TakenState.Type, taken: Bool) = {
    val next = WireDefault(state)

    switch(state) {
      is(TakenState.strongNotTaken) {
        next := Mux(taken, TakenState.weakNotTaken, TakenState.strongNotTaken)
      }
      is(TakenState.weakNotTaken) {
        next := Mux(taken, TakenState.weakTaken, TakenState.strongNotTaken)
      }
      is(TakenState.weakTaken) {
        next := Mux(taken, TakenState.strongTaken, TakenState.weakNotTaken)
      }
      is(TakenState.strongTaken) {
        next := Mux(taken, TakenState.strongTaken, TakenState.weakTaken)
      }
    }

    next
  }

  private def predictTaken(state: TakenState.Type) =
    state === TakenState.weakTaken || state === TakenState.strongTaken

  val validArray = RegInit(VecInit(Seq.fill(cfg.bhtEntries)(false.B)))
  val takenArray = Reg(Vec(cfg.bhtEntries, TakenState()))

  private def initialTakenState(taken: Bool): TakenState.Type =
    Mux(taken, TakenState.weakTaken, TakenState.weakNotTaken)

  private val firstUpdateSet   = idx(io.update(0).bits.pc)
  private val firstUpdateState = Mux(
    validArray(firstUpdateSet),
    nextTakenState(takenArray(firstUpdateSet), io.update(0).bits.taken),
    initialTakenState(io.update(0).bits.taken)
  )

  when(io.update(0).valid) {
    validArray(firstUpdateSet) := true.B
    takenArray(firstUpdateSet) := firstUpdateState
  }

  private val secondUpdateSet  = idx(io.update(1).bits.pc)
  private val secondMatchesFirst = io.update(0).valid && firstUpdateSet === secondUpdateSet
  private val secondPriorValid = Mux(secondMatchesFirst, true.B, validArray(secondUpdateSet))
  private val secondPriorState = Mux(secondMatchesFirst, firstUpdateState, takenArray(secondUpdateSet))
  private val secondUpdateState = Mux(
    secondPriorValid,
    nextTakenState(secondPriorState, io.update(1).bits.taken),
    initialTakenState(io.update(1).bits.taken)
  )

  when(io.update(1).valid) {
    validArray(secondUpdateSet) := true.B
    takenArray(secondUpdateSet) := secondUpdateState
  }

  for (lane <- 0 until 2) {
    val reqIdx   = idx(io.lookupPc(lane))
    val reqTaken = takenArray(reqIdx)

    io.taken(lane) := validArray(reqIdx) && predictTaken(reqTaken)
  }
}

class Bpu(cfg: BpuConfig = BpuConfig()) extends Module {
  require(cfg.predictorHistoryBits == PredictorConstants.historyBits, "Prediction metadata and BPU history widths must match")

  val io = IO(new BpuBundle(cfg))

  private val cacheCfg = ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes)
  val btb  = Module(new Btb(cfg))
  val bht  = Module(new Bht(cfg))
  val tage = Module(new Tage(cfg))

  btb.io.lookupPc(0) := io.lookup.bits.pc
  btb.io.lookupPc(1) := io.lookupSecondary.bits.pc
  bht.io.lookupPc(0) := io.lookup.bits.pc
  bht.io.lookupPc(1) := io.lookupSecondary.bits.pc

  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    btb.io.update(lane).valid          := io.update(lane).valid && io.update(lane).bits.taken
    btb.io.update(lane).bits.pc        := io.update(lane).bits.pc
    btb.io.update(lane).bits.target    := io.update(lane).bits.target
    btb.io.update(lane).bits.cfiOffset := io.update(lane).bits.pc(cfg.offsetBits - 1, 1)
    btb.io.update(lane).bits.cfiType   := io.update(lane).bits.cfiType

    bht.io.update(lane).valid      := io.update(lane).valid && io.update(lane).bits.cfiType === CfiType.branch
    bht.io.update(lane).bits.pc    := io.update(lane).bits.pc
    bht.io.update(lane).bits.taken := io.update(lane).bits.taken
  }
  tage.io.update := io.update

  private def advanceConditionalHistory(history: UInt, cfiType: UInt, taken: Bool): UInt =
    Mux(cfiType === CfiType.branch, Cat(history(PredictorConstants.historyBits - 2, 0), taken), history)

  private def isGenericIndirect(cfiType: UInt, canonicalReturn: Bool): Bool =
    cfiType === CfiType.jalr && !canonicalReturn

  private def advancePathHistory(
    history:         UInt,
    cfiType:         UInt,
    canonicalReturn: Bool,
    pc:              UInt,
    target:          UInt): UInt = {
    val pathBits = pc(5, 2) ^ target(5, 2)
    Mux(
      isGenericIndirect(cfiType, canonicalReturn),
      Cat(history(PredictorConstants.historyBits - 5, 0), pathBits),
      history
    )
  }

  private def applyRas(
    checkpoint: RasCheckpoint,
    action:     UInt,
    pc:         UInt,
    instLen:    UInt): (RasCheckpoint, Bool, Bool) = {
    val next       = Wire(new RasCheckpoint(cfg.addrWidth))
    val nonEmpty   = checkpoint.count =/= 0.U
    val full       = checkpoint.count === PredictorConstants.rasEntries.U
    val pushIndex  = checkpoint.count(PredictorConstants.rasIndexBits - 1, 0)
    val popIndex   = (checkpoint.count - 1.U)(PredictorConstants.rasIndexBits - 1, 0)
    val returnAddr = pc +% instLen

    next := checkpoint
    switch(action) {
      is(RasAction.push) {
        when(!full) {
          next.entries(pushIndex) := returnAddr
          next.count              := checkpoint.count + 1.U
        }
      }
      is(RasAction.pop) {
        when(nonEmpty) {
          next.count := checkpoint.count - 1.U
        }
      }
      is(RasAction.popThenPush) {
        when(nonEmpty) {
          next.entries(popIndex) := returnAddr
        }.otherwise {
          next.entries(0) := returnAddr
          next.count      := 1.U
        }
      }
    }

    (
      next,
      (action === RasAction.pop || action === RasAction.popThenPush) && !nonEmpty,
      action === RasAction.push && full
    )
  }

  private val architecturalRas     = RegInit(0.U.asTypeOf(new RasCheckpoint(cfg.addrWidth)))
  private val speculativeRas       = RegInit(0.U.asTypeOf(new RasCheckpoint(cfg.addrWidth)))
  private val architecturalHistory = RegInit(0.U(PredictorConstants.historyBits.W))
  private val speculativeHistory   = RegInit(0.U(PredictorConstants.historyBits.W))
  private val architecturalPath    = RegInit(0.U(PredictorConstants.historyBits.W))
  private val speculativePath      = RegInit(0.U(PredictorConstants.historyBits.W))

  private val tageQueries = Wire(Vec(PredictorConstants.latePredictionWidth, new LatePredictQuery(cacheCfg)))
  var queryHistory: UInt = speculativeHistory
  var queryPath: UInt = speculativePath
  for (lane <- 0 until PredictorConstants.latePredictionWidth) {
    val query = io.lateQuery(lane)
    val historyBefore = queryHistory
    val pathBefore    = queryPath

    tageQueries(lane) := query
    tageQueries(lane).history     := historyBefore
    tageQueries(lane).pathHistory := pathBefore

    val tageValid = cfg.enableTage.B && tage.io.prediction(lane).valid
    val selectedTaken = Mux(cfg.enableLateOverride.B && tageValid, tage.io.prediction(lane).taken, query.fastTaken)

    io.latePrediction(lane) := tage.io.prediction(lane)
    io.latePrediction(lane).valid             := tageValid
    io.latePrediction(lane).historyCheckpoint := historyBefore
    io.latePrediction(lane).pathCheckpoint    := pathBefore

    queryHistory = Mux(
      query.valid && query.cfiType === CfiType.branch,
      advanceConditionalHistory(historyBefore, query.cfiType, selectedTaken),
      historyBefore
    )
    queryPath = Mux(
      query.valid,
      advancePathHistory(pathBefore, query.cfiType, query.canonicalReturn, query.pc, query.fastTarget),
      pathBefore
    )
  }
  tage.io.query := tageQueries

  private val firstCommitAction = Mux(io.update(0).valid, io.update(0).bits.rasAction, RasAction.none)
  private val firstCommitRas = applyRas(
    architecturalRas,
    firstCommitAction,
    io.update(0).bits.pc,
    io.update(0).bits.instLen
  )
  private val secondCommitAction = Mux(io.update(1).valid, io.update(1).bits.rasAction, RasAction.none)
  private val secondCommitRas = applyRas(
    firstCommitRas._1,
    secondCommitAction,
    io.update(1).bits.pc,
    io.update(1).bits.instLen
  )
  architecturalRas := secondCommitRas._1

  var committedHistory: UInt = architecturalHistory
  var committedPath: UInt = architecturalPath
  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    val update = io.update(lane)
    committedHistory = Mux(
      update.valid,
      advanceConditionalHistory(committedHistory, update.bits.cfiType, update.bits.taken),
      committedHistory
    )
    committedPath = Mux(
      update.valid,
      advancePathHistory(
        committedPath,
        update.bits.cfiType,
        update.bits.prediction.canonicalReturn,
        update.bits.pc,
        update.bits.target
      ),
      committedPath
    )
  }
  architecturalHistory := committedHistory
  architecturalPath    := committedPath

  private val speculativeAction = Mux(io.rasSpecUpdate.valid, io.rasSpecUpdate.bits.rasAction, RasAction.none)
  private val speculativeNext = applyRas(
    speculativeRas,
    speculativeAction,
    io.rasSpecUpdate.bits.cfiPc,
    io.rasSpecUpdate.bits.instLen
  )
  private val recoveryNext = applyRas(
    io.rasRecovery.bits.prediction.rasCheckpoint,
    io.rasRecovery.bits.prediction.rasAction,
    io.rasRecovery.bits.prediction.cfiPc,
    io.rasRecovery.bits.prediction.instLen
  )

  var speculativeHistoryNext: UInt = speculativeHistory
  var speculativePathNext: UInt = speculativePath
  for (lane <- 0 until PredictorConstants.latePredictionWidth) {
    val update = io.lateSpecUpdate(lane)
    speculativeHistoryNext = Mux(
      update.valid,
      advanceConditionalHistory(speculativeHistoryNext, update.bits.cfiType, update.bits.specTaken),
      speculativeHistoryNext
    )
    speculativePathNext = Mux(
      update.valid,
      advancePathHistory(
        speculativePathNext,
        update.bits.cfiType,
        update.bits.canonicalReturn,
        update.bits.cfiPc,
        update.bits.predictedTarget
      ),
      speculativePathNext
    )
  }
  private val recoveredHistory = advanceConditionalHistory(
    io.rasRecovery.bits.prediction.historyCheckpoint,
    io.rasRecovery.bits.cfiType,
    io.rasRecovery.bits.actualTaken
  )
  private val recoveredPath = advancePathHistory(
    io.rasRecovery.bits.prediction.pathCheckpoint,
    io.rasRecovery.bits.cfiType,
    io.rasRecovery.bits.prediction.canonicalReturn,
    io.rasRecovery.bits.prediction.cfiPc,
    io.rasRecovery.bits.actualTarget
  )

  when(io.rasRecovery.valid) {
    speculativeRas := recoveryNext._1
    speculativeHistory := recoveredHistory
    speculativePath := recoveredPath
  }.elsewhen(io.rasFlush) {
    speculativeRas := secondCommitRas._1
    speculativeHistory := committedHistory
    speculativePath := committedPath
  }.otherwise {
    speculativeRas := speculativeNext._1
    speculativeHistory := speculativeHistoryNext
    speculativePath := speculativePathNext
  }

  io.rasTop        := Mux(speculativeRas.count =/= 0.U, speculativeRas.entries((speculativeRas.count - 1.U)(PredictorConstants.rasIndexBits - 1, 0)), 0.U)
  io.rasValid      := speculativeRas.count =/= 0.U
  io.rasCheckpoint := speculativeRas

  private val rasUse = VecInit((0 until PredictorConstants.commitUpdateWidth).map { lane =>
    io.update(lane).valid && io.update(lane).bits.prediction.rasUsed
  }).asUInt.orR
  private val rasHit = VecInit((0 until PredictorConstants.commitUpdateWidth).map { lane =>
    io.update(lane).valid && io.update(lane).bits.prediction.rasUsed &&
      io.update(lane).bits.target === io.update(lane).bits.prediction.predictedTarget
  }).asUInt.orR
  private def committedAction(action: UInt): Bool =
    VecInit((0 until PredictorConstants.commitUpdateWidth).map { lane =>
      io.update(lane).valid && io.update(lane).bits.rasAction === action
    }).asUInt.orR

  io.perf := 0.U.asTypeOf(new RasPerf)
  io.perf.push              := committedAction(RasAction.push)
  io.perf.pop               := committedAction(RasAction.pop)
  io.perf.popThenPush       := committedAction(RasAction.popThenPush)
  io.perf.use               := rasUse
  io.perf.hit               := rasHit
  io.perf.miss              := rasUse && !rasHit
  io.perf.underflow         := firstCommitRas._2 || secondCommitRas._2 || recoveryNext._2
  io.perf.overflow          := firstCommitRas._3 || secondCommitRas._3 || recoveryNext._3
  io.perf.checkpointRestore := io.rasRecovery.valid
  io.perf.recoveryDiscard   := io.rasRecovery.valid || io.rasFlush
  io.perf.taggedProvider    := tage.io.perf.provider
  io.perf.alternateDisagree := tage.io.perf.alternateDisagree
  io.perf.allocation        := tage.io.perf.allocation
  io.perf.usefulnessAging   := tage.io.perf.usefulnessAging
  io.perf.lateOverride      := VecInit((0 until PredictorConstants.latePredictionWidth).map { lane =>
    io.lateSpecUpdate(lane).valid && io.lateSpecUpdate(lane).bits.lateOverride
  }).asUInt.orR

  when(io.rasSpecUpdate.valid) {
    assert(io.rasSpecUpdate.bits.checkpointValid)
  }
  when(io.rasRecovery.valid) {
    assert(io.rasRecovery.bits.prediction.checkpointValid)
  }

  private def predictionFor(lookupValid: Bool, lookupPc: UInt, lane: Int): BpuPred = {
    val lookupOffset = lookupPc(cfg.offsetBits - 1, 1)
    val isBranch     = btb.io.resp(lane).cfiType === CfiType.branch
    val hasCfi       = btb.io.resp(lane).cfiType =/= CfiType.none
    val btbHit       = lookupValid && btb.io.resp(lane).hit && hasCfi
    val cfiInWindow  = btbHit && btb.io.resp(lane).cfiOffset >= lookupOffset
    val predTaken    = cfiInWindow && Mux(isBranch, bht.io.taken(lane), true.B)
    val prediction   = Wire(new BpuPred(cfg))

    prediction.valid     := cfiInWindow
    prediction.taken     := predTaken
    prediction.target    := Mux(predTaken, btb.io.resp(lane).target, 0.U)
    prediction.cfiOffset := Mux(cfiInWindow, btb.io.resp(lane).cfiOffset, 0.U)
    prediction.cfiType   := Mux(cfiInWindow, btb.io.resp(lane).cfiType, CfiType.none)
    prediction
  }

  io.pred          := predictionFor(io.lookup.valid, io.lookup.bits.pc, 0)
  io.predSecondary := predictionFor(io.lookupSecondary.valid, io.lookupSecondary.bits.pc, 1)
}
