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
  val instLen   = UInt(3.W)
  val rasAction = UInt(RasAction.width.W)
}

class BtbUpdate(cfg: BpuConfig) extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
  val instLen   = UInt(3.W)
  val rasAction = UInt(RasAction.width.W)
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

  val validArray   = RegInit(VecInit(Seq.fill(cfg.btbEntries)(false.B)))
  val tagArray     = Reg(Vec(cfg.btbEntries, UInt(tagWidth.W)))
  val targetArray  = Reg(Vec(cfg.btbEntries, UInt(cfg.addrWidth.W)))
  val cfitpArray   = Reg(Vec(cfg.btbEntries, UInt(CfiType.width.W)))
  val cfioffArray  = Reg(Vec(cfg.btbEntries, UInt(cfg.cfiOffsetBits.W)))
  val instLenArray = Reg(Vec(cfg.btbEntries, UInt(3.W)))
  val rasArray     = Reg(Vec(cfg.btbEntries, UInt(RasAction.width.W)))

  private val firstUpdateSet   = index(io.update(0).bits.pc)
  private val firstUpdateTag   = tag(io.update(0).bits.pc)
  private val secondUpdateSet  = index(io.update(1).bits.pc)
  private val secondUpdateTag  = tag(io.update(1).bits.pc)
  private val sameBlockUpdates = io.update(0).valid && io.update(1).valid &&
    firstUpdateSet === secondUpdateSet && firstUpdateTag === secondUpdateTag

  when(io.update(0).valid) {
    validArray(firstUpdateSet)   := true.B
    tagArray(firstUpdateSet)     := firstUpdateTag
    targetArray(firstUpdateSet)  := io.update(0).bits.target
    cfitpArray(firstUpdateSet)   := io.update(0).bits.cfiType
    cfioffArray(firstUpdateSet)  := io.update(0).bits.cfiOffset
    instLenArray(firstUpdateSet) := io.update(0).bits.instLen
    rasArray(firstUpdateSet)     := io.update(0).bits.rasAction
  }

  when(io.update(1).valid && !sameBlockUpdates) {
    validArray(secondUpdateSet)   := true.B
    tagArray(secondUpdateSet)     := secondUpdateTag
    targetArray(secondUpdateSet)  := io.update(1).bits.target
    cfitpArray(secondUpdateSet)   := io.update(1).bits.cfiType
    cfioffArray(secondUpdateSet)  := io.update(1).bits.cfiOffset
    instLenArray(secondUpdateSet) := io.update(1).bits.instLen
    rasArray(secondUpdateSet)     := io.update(1).bits.rasAction
  }

  when(sameBlockUpdates) {
    assert(io.update(0).bits.pc < io.update(1).bits.pc)
  }

  for (lane <- 0 until 2) {
    val reqSet = index(io.lookupPc(lane))
    val reqTag = tag(io.lookupPc(lane))
    val hit    = validArray(reqSet) && tagArray(reqSet) === reqTag

    io.resp(lane).hit       := hit
    io.resp(lane).target    := Mux(hit, targetArray(reqSet), 0.U)
    io.resp(lane).cfiOffset := Mux(hit, cfioffArray(reqSet), 0.U)
    io.resp(lane).cfiType   := Mux(hit, cfitpArray(reqSet), CfiType.none)
    io.resp(lane).instLen   := Mux(hit, instLenArray(reqSet), 0.U)
    io.resp(lane).rasAction := Mux(hit, rasArray(reqSet), RasAction.none)
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

  private val secondUpdateSet    = idx(io.update(1).bits.pc)
  private val secondMatchesFirst = io.update(0).valid && firstUpdateSet === secondUpdateSet
  private val secondPriorValid   = Mux(secondMatchesFirst, true.B, validArray(secondUpdateSet))
  private val secondPriorState   = Mux(secondMatchesFirst, firstUpdateState, takenArray(secondUpdateSet))
  private val secondUpdateState  = Mux(
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

class Bpu(frontendCfg: FrontendConfig = FrontendConfig(), commitWidth: Int = PredictorConstants.commitUpdateWidth)
    extends Module {
  private val cfg      = frontendCfg.bpu
  private val cacheCfg = frontendCfg.icache
  private val blocks   = frontendCfg.fetchGroupBlocks

  require(blocks == 2, "the current BTB has one read port per two-block fetch group lane")
  require(
    commitWidth == PredictorConstants.commitUpdateWidth,
    "legacy predictor training width must match commit width"
  )
  require(cfg.predictorHistoryBits == frontendCfg.historyBits, "BPU and frontend history widths must match")

  val io = IO(new Bundle {
    val req         = Flipped(Decoupled(new BpuRequest(frontendCfg)))
    val fastResult  = Valid(new BpuFastResult(frontendCfg))
    val finalResult = Valid(new BpuFinalResult(frontendCfg))
    val recover     = Flipped(Valid(new BpuRecover(frontendCfg)))
    val train       = Input(Vec(commitWidth, Valid(new BpuUpdate(cfg))))
    val perf        = Output(new RasPerf)
  })

  val btb    = Module(new Btb(cfg))
  val bht    = Module(new Bht(cfg))
  val tage   = Module(new Tage(cfg, blocks))
  val ittage = Module(new Ittage(cfg, blocks))

  private def blockBase(startPc: UInt, block: Int): UInt = {
    val first = Cat(startPc(cfg.addrWidth - 1, cfg.offsetBits), 0.U(cfg.offsetBits.W))
    first +% (block * cfg.fetchBytes).U(cfg.addrWidth.W)
  }

  private def cfiPc(base: UInt, response: BtbResp): UInt =
    base +% (response.cfiOffset << 1)

  private def advanceConditionalHistory(history: UInt, cfiType: UInt, taken: Bool): UInt =
    Mux(cfiType === CfiType.branch, Cat(history(frontendCfg.historyBits - 2, 0), taken), history)

  private def isCanonicalReturn(cfiType: UInt, action: UInt): Bool =
    cfiType === CfiType.jalr && (action === RasAction.pop || action === RasAction.popThenPush)

  private def isGenericIndirect(cfiType: UInt, canonicalReturn: Bool): Bool =
    cfiType === CfiType.jalr && !canonicalReturn

  private def advancePathHistory(
    history:         UInt,
    cfiType:         UInt,
    canonicalReturn: Bool,
    pc:              UInt,
    target:          UInt
  ): UInt = {
    val pathBits = pc(5, 2) ^ target(5, 2)
    Mux(
      isGenericIndirect(cfiType, canonicalReturn),
      Cat(history(frontendCfg.historyBits - 5, 0), pathBits),
      history
    )
  }

  private def applyRas(
    checkpoint: RasCheckpoint,
    action:     UInt,
    pc:         UInt,
    instLen:    UInt
  ): (RasCheckpoint, Bool, Bool) = {
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
  private val architecturalHistory = RegInit(0.U(frontendCfg.historyBits.W))
  private val speculativeHistory   = RegInit(0.U(frontendCfg.historyBits.W))
  private val architecturalPath    = RegInit(0.U(frontendCfg.historyBits.W))
  private val speculativePath      = RegInit(0.U(frontendCfg.historyBits.W))

  for (lane <- 0 until commitWidth) {
    btb.io.update(lane).valid          := io.train(lane).valid
    btb.io.update(lane).bits.pc        := io.train(lane).bits.pc
    btb.io.update(lane).bits.target    := io.train(lane).bits.target
    btb.io.update(lane).bits.cfiOffset := io.train(lane).bits.pc(cfg.offsetBits - 1, 1)
    btb.io.update(lane).bits.cfiType   := io.train(lane).bits.cfiType
    btb.io.update(lane).bits.instLen   := io.train(lane).bits.instLen
    btb.io.update(lane).bits.rasAction := io.train(lane).bits.rasAction

    bht.io.update(lane).valid      := io.train(lane).valid && io.train(lane).bits.cfiType === CfiType.branch
    bht.io.update(lane).bits.pc    := io.train(lane).bits.pc
    bht.io.update(lane).bits.taken := io.train(lane).bits.taken

    tage.io.update(lane).valid   := io.train(lane).valid && cfg.enableTage.B
    tage.io.update(lane).bits    := io.train(lane).bits
    ittage.io.update(lane).valid := io.train(lane).valid && cfg.enableIttage.B
    ittage.io.update(lane).bits  := io.train(lane).bits
  }

  var committedRas:     RasCheckpoint = architecturalRas
  var committedHistory: UInt          = architecturalHistory
  var committedPath:    UInt          = architecturalPath
  val commitUnderflow = Wire(Vec(commitWidth, Bool()))
  val commitOverflow  = Wire(Vec(commitWidth, Bool()))
  for (lane <- 0 until commitWidth) {
    val update    = io.train(lane)
    val rasUpdate = applyRas(
      committedRas,
      Mux(update.valid, update.bits.rasAction, RasAction.none),
      update.bits.pc,
      update.bits.instLen
    )
    committedRas = rasUpdate._1
    commitUnderflow(lane) := rasUpdate._2
    commitOverflow(lane)  := rasUpdate._3
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
        update.bits.canonicalReturn,
        update.bits.pc,
        update.bits.target
      ),
      committedPath
    )
  }
  architecturalRas := committedRas
  architecturalHistory := committedHistory
  architecturalPath    := committedPath

  val s1Valid   = RegInit(false.B)
  val s1Request = Reg(new BpuRequest(frontendCfg))
  val s1History = Reg(UInt(frontendCfg.historyBits.W))
  val s1Path    = Reg(UInt(frontendCfg.historyBits.W))
  val s1Ras     = Reg(new RasCheckpoint(cfg.addrWidth))

  for (block <- 0 until blocks) {
    btb.io.lookupPc(block) := blockBase(s1Request.startPc, block)
    bht.io.lookupPc(block) := cfiPc(blockBase(s1Request.startPc, block), btb.io.resp(block))
  }

  val fastMeta              = Wire(Vec(blocks, new BtbCfiMeta(frontendCfg)))
  val fastTaken             = Wire(Vec(blocks, Bool()))
  val fastNeedsContinuation = Wire(Vec(blocks, Bool()))
  val fastNeedsSplit        = Wire(Vec(blocks, Bool()))
  for (block <- 0 until blocks) {
    val response         = btb.io.resp(block)
    val lookupOffset     = if (block == 0) s1Request.startPc(cfg.offsetBits - 1, 1) else 0.U
    val crossesBlock     = response.instLen === 4.U &&
      response.cfiOffset === (frontendCfg.fetchBytes / 2 - 1).U
    val continuationFits = if (block + 1 < blocks) true.B else !crossesBlock
    val candidateInWindow = s1Valid && response.hit && response.cfiType =/= CfiType.none &&
      response.cfiOffset >= lookupOffset
    val inWindow = candidateInWindow && continuationFits
    val canonicalReturn  = isCanonicalReturn(response.cfiType, response.rasAction)
    val rasTarget        = Mux(
      s1Ras.count =/= 0.U,
      s1Ras.entries((s1Ras.count - 1.U)(PredictorConstants.rasIndexBits - 1, 0)),
      response.target
    )

    fastMeta(block)              := 0.U.asTypeOf(new BtbCfiMeta(frontendCfg))
    fastMeta(block).valid        := inWindow
    fastMeta(block).cfiOffset    := Mux(inWindow, response.cfiOffset, 0.U)
    fastMeta(block).cfiType      := Mux(inWindow, response.cfiType, CfiType.none)
    fastMeta(block).target       := Mux(canonicalReturn, rasTarget, response.target)
    fastMeta(block).rasAction    := Mux(inWindow, response.rasAction, RasAction.none)
    fastTaken(block)             := inWindow && Mux(response.cfiType === CfiType.branch, bht.io.taken(block), true.B)
    fastNeedsContinuation(block) := inWindow && crossesBlock
    fastNeedsSplit(block)        := candidateInWindow && crossesBlock && (block == blocks - 1).B
  }

  val fastTakenMask   = fastTaken.asUInt
  val fastTakenOH     = PriorityEncoderOH(fastTakenMask).asBools
  val sequentialNext  = blockBase(s1Request.startPc, 0) +% frontendCfg.fetchGroupBytes.U
  val splitNext       = blockBase(s1Request.startPc, blocks - 1)
  val fastSplitActive = fastNeedsSplit(blocks - 1) && !fastTakenMask.orR
  val fastNextPc      = Mux(
    fastTakenMask.orR,
    Mux1H(fastTakenOH, fastMeta.map(_.target)),
    Mux(fastSplitActive, splitNext, sequentialNext)
  )
  val fastBlockCount = Mux(
    fastSplitActive || (fastTaken(0) && !fastNeedsContinuation(0)),
    (blocks - 1).U,
    blocks.U
  )

  io.fastResult.valid                  := s1Valid && !io.recover.valid
  io.fastResult.bits                   := 0.U.asTypeOf(new BpuFastResult(frontendCfg))
  io.fastResult.bits.token             := s1Request.token
  io.fastResult.bits.startPc           := s1Request.startPc
  io.fastResult.bits.blockPred         := fastMeta
  io.fastResult.bits.blockTaken        := fastTaken
  io.fastResult.bits.predictedNextPc   := fastNextPc
  io.fastResult.bits.blockCount        := fastBlockCount
  io.fastResult.bits.historyCheckpoint := s1History
  io.fastResult.bits.pathCheckpoint    := s1Path
  io.fastResult.bits.rasCheckpoint     := s1Ras

  val tageQueries   = Wire(Vec(blocks, new LatePredictQuery(cacheCfg)))
  val ittageQueries = Wire(Vec(blocks, new LatePredictQuery(cacheCfg)))
  for (lane <- 0 until blocks) {
    tageQueries(lane)   := 0.U.asTypeOf(new LatePredictQuery(cacheCfg))
    ittageQueries(lane) := 0.U.asTypeOf(new LatePredictQuery(cacheCfg))
  }

  var fastHistoryAfter:      UInt          = s1History
  var fastPathAfter:         UInt          = s1Path
  var fastRasAfter:          RasCheckpoint = s1Ras
  var indirectCandidateSeen: Bool          = false.B
  val fastRasUnderflow = Wire(Vec(blocks, Bool()))
  val fastRasOverflow  = Wire(Vec(blocks, Bool()))
  for (block <- 0 until blocks) {
    val meta            = fastMeta(block)
    val blockCfiPc      = blockBase(s1Request.startPc, block) +% (meta.cfiOffset << 1)
    val canonicalReturn = isCanonicalReturn(meta.cfiType, meta.rasAction)
    val active          = meta.valid
    val historyBefore   = fastHistoryAfter
    val pathBefore      = fastPathAfter

    tageQueries(block).valid           := active && meta.cfiType === CfiType.branch
    tageQueries(block).pc              := blockCfiPc
    tageQueries(block).cfiType         := meta.cfiType
    tageQueries(block).fastValid       := active
    tageQueries(block).fastTaken       := fastTaken(block)
    tageQueries(block).fastTarget      := meta.target
    tageQueries(block).canonicalReturn := canonicalReturn
    tageQueries(block).history         := historyBefore
    tageQueries(block).pathHistory     := pathBefore

    val useIndirectCandidate = active && isGenericIndirect(meta.cfiType, canonicalReturn) && !indirectCandidateSeen
    ittageQueries(block)       := tageQueries(block)
    ittageQueries(block).valid := useIndirectCandidate
    indirectCandidateSeen = indirectCandidateSeen || useIndirectCandidate

    fastHistoryAfter = Mux(
      active,
      advanceConditionalHistory(historyBefore, meta.cfiType, fastTaken(block)),
      historyBefore
    )
    fastPathAfter = Mux(
      active && fastTaken(block),
      advancePathHistory(pathBefore, meta.cfiType, canonicalReturn, blockCfiPc, meta.target),
      pathBefore
    )
    val rasUpdate = applyRas(
      fastRasAfter,
      Mux(active && fastTaken(block), meta.rasAction, RasAction.none),
      blockCfiPc,
      4.U
    )
    fastRasAfter = rasUpdate._1
    fastRasUnderflow(block) := rasUpdate._2
    fastRasOverflow(block)  := rasUpdate._3
  }
  tage.io.query := tageQueries
  ittage.io.query := ittageQueries

  val s2Valid             = RegInit(false.B)
  val s2Fast              = Reg(new BpuFastResult(frontendCfg))
  val s2NeedsContinuation = Reg(Vec(blocks, Bool()))
  val s2NeedsSplit        = Reg(Vec(blocks, Bool()))
  val s2Tage              = tage.io.prediction
  val s2Ittage            = ittage.io.prediction

  val finalMeta   = Wire(Vec(blocks, new BtbCfiMeta(frontendCfg)))
  val finalTaken  = Wire(Vec(blocks, Bool()))
  val finalTarget = Wire(Vec(blocks, UInt(frontendCfg.addrWidth.W)))
  for (block <- 0 until blocks) {
    val meta            = s2Fast.blockPred(block)
    val canonicalReturn = isCanonicalReturn(meta.cfiType, meta.rasAction)
    val conditionalLate = cfg.enableLateOverride.B && meta.cfiType === CfiType.branch && s2Tage(block).valid
    val indirectLate    = cfg.enableLateOverride.B && isGenericIndirect(meta.cfiType, canonicalReturn) &&
      s2Ittage(block).valid

    finalTaken(block)       := Mux(conditionalLate, s2Tage(block).taken, s2Fast.blockTaken(block))
    finalTarget(block)      := Mux(indirectLate, s2Ittage(block).target, meta.target)
    finalMeta(block)        := meta
    finalMeta(block).target := finalTarget(block)
  }

  val finalTakenMask   = finalTaken.asUInt
  val finalTakenOH     = PriorityEncoderOH(finalTakenMask).asBools
  val finalSequential  = blockBase(s2Fast.startPc, 0) +% frontendCfg.fetchGroupBytes.U
  val finalSplitNext   = blockBase(s2Fast.startPc, blocks - 1)
  val finalSplitActive = s2NeedsSplit(blocks - 1) && !finalTakenMask.orR
  val finalNextPc      = Mux(
    finalTakenMask.orR,
    Mux1H(finalTakenOH, finalTarget),
    Mux(finalSplitActive, finalSplitNext, finalSequential)
  )
  val finalBlockCount = Mux(
    finalSplitActive || (finalTaken(0) && !s2NeedsContinuation(0)),
    (blocks - 1).U,
    blocks.U
  )

  val finalSummary = Wire(new PredictionSummary(frontendCfg))
  finalSummary                 := 0.U.asTypeOf(new PredictionSummary(frontendCfg))
  finalSummary.blockPred       := finalMeta
  finalSummary.predictedNextPc := finalNextPc

  val finalTrainMeta = Wire(Vec(blocks, Valid(new PredictorTrainMeta(frontendCfg))))
  for (slot <- 0 until frontendCfg.maxConditionalCandidatesPerGroup) {
    val matchBlock = Wire(Vec(blocks, Bool()))
    for (block <- 0 until blocks) {
      val earlierBranches =
        if (block == 0) 0.U
        else
          PopCount((0 until block).map { prior =>
            s2Fast.blockPred(prior).valid && s2Fast.blockPred(prior).cfiType === CfiType.branch
          })
      matchBlock(block) := s2Fast.blockPred(block).valid &&
        s2Fast.blockPred(block).cfiType === CfiType.branch && earlierBranches === slot.U
    }
    val selected = Mux1H(matchBlock, s2Tage)
    val selectedMeta  = Mux1H(matchBlock, s2Fast.blockPred)
    val selectedTaken = Mux1H(matchBlock, finalTaken)

    finalSummary.conditionalPred(slot).valid               := matchBlock.asUInt.orR
    finalSummary.conditionalPred(slot).bits.blockIndex     := OHToUInt(matchBlock)
    finalSummary.conditionalPred(slot).bits.cfiOffset      := selectedMeta.cfiOffset
    finalSummary.conditionalPred(slot).bits.taken          := selectedTaken
    finalSummary.conditionalPred(slot).bits.provider       := Mux(
      selected.valid,
      selected.provider,
      PredictorProvider.fastBtb
    )
    finalSummary.conditionalPred(slot).bits.alternate      := Mux(selected.valid, selected.alternate, PredictorProvider.none)
    finalSummary.conditionalPred(slot).bits.confidence     := Mux(selected.valid, selected.confidence, 1.U)
    finalSummary.conditionalPred(slot).bits.alternateTaken := Mux(
      selected.valid,
      selected.alternateTaken,
      selectedTaken
    )

  }

  for (slot <- 0 until frontendCfg.maxIndirectCandidatesPerGroup) {
    val matchBlock = Wire(Vec(blocks, Bool()))
    for (block <- 0 until blocks) {
      val earlierIndirects =
        if (block == 0) 0.U
        else
          PopCount((0 until block).map { prior =>
            val priorMeta = s2Fast.blockPred(prior)
            priorMeta.valid && isGenericIndirect(
              priorMeta.cfiType,
              isCanonicalReturn(priorMeta.cfiType, priorMeta.rasAction)
            )
          })
      val meta             = s2Fast.blockPred(block)
      matchBlock(block) := meta.valid && isGenericIndirect(
        meta.cfiType,
        isCanonicalReturn(meta.cfiType, meta.rasAction)
      ) &&
        earlierIndirects === slot.U
    }
    val selected = Mux1H(matchBlock, s2Ittage)
    val selectedMeta = Mux1H(matchBlock, s2Fast.blockPred)
    finalSummary.indirectPred(slot).valid           := matchBlock.asUInt.orR
    finalSummary.indirectPred(slot).bits.blockIndex := OHToUInt(matchBlock)
    finalSummary.indirectPred(slot).bits.cfiOffset  := selectedMeta.cfiOffset
    finalSummary.indirectPred(slot).bits.target     := Mux(selected.valid, selected.target, selectedMeta.target)
    finalSummary.indirectPred(slot).bits.provider   := Mux(
      selected.valid,
      selected.provider,
      PredictorProvider.ittageBase
    )
    finalSummary.indirectPred(slot).bits.alternate  := Mux(selected.valid, selected.alternate, PredictorProvider.none)
    finalSummary.indirectPred(slot).bits.confidence := Mux(selected.valid, selected.confidence, 0.U)
  }

  for (block <- 0 until blocks) {
    val meta            = s2Fast.blockPred(block)
    val canonicalReturn = isCanonicalReturn(meta.cfiType, meta.rasAction)
    val conditional     = meta.cfiType === CfiType.branch
    val indirect        = isGenericIndirect(meta.cfiType, canonicalReturn)
    val late            = Mux(conditional, s2Tage(block), s2Ittage(block))

    finalTrainMeta(block)                                := 0.U.asTypeOf(finalTrainMeta(block))
    finalTrainMeta(block).valid                          := meta.valid
    finalTrainMeta(block).bits.blockIndex                := block.U
    finalTrainMeta(block).bits.cfiOffset                 := meta.cfiOffset
    finalTrainMeta(block).bits.context.provider          := Mux(
      conditional || indirect,
      Mux(late.valid, late.provider, PredictorProvider.fastBtb),
      Mux(canonicalReturn, PredictorProvider.ras, PredictorProvider.fastBtb)
    )
    finalTrainMeta(block).bits.context.alternate         := Mux(
      (conditional || indirect) && late.valid,
      late.alternate,
      PredictorProvider.none
    )
    finalTrainMeta(block).bits.context.confidence        := Mux(late.valid, late.confidence, meta.valid.asUInt)
    finalTrainMeta(block).bits.context.providerUseful    := Mux(late.valid, late.providerUseful, 0.U)
    finalTrainMeta(block).bits.context.allocationMask    := Mux(late.valid, late.allocationMask, 0.U)
    finalTrainMeta(block).bits.context.predictedTarget   := finalTarget(block)
    finalTrainMeta(block).bits.context.rasUsed           := canonicalReturn && finalTaken(block)
    finalTrainMeta(block).bits.context.lateQueried       := late.queried
    finalTrainMeta(block).bits.context.lateValid         := late.valid
    finalTrainMeta(block).bits.context.lateTaken         := late.taken
    finalTrainMeta(block).bits.context.alternateTaken    := late.alternateTaken
    finalTrainMeta(block).bits.context.lateTarget        := late.target
    finalTrainMeta(block).bits.context.alternateTarget   := late.alternateTarget
    finalTrainMeta(block).bits.context.historyCheckpoint := s2Tage(block).historyCheckpoint
    finalTrainMeta(block).bits.context.pathCheckpoint    := s2Ittage(block).pathCheckpoint
  }

  var finalHistoryAfter: UInt          = s2Fast.historyCheckpoint
  var finalPathAfter:    UInt          = s2Fast.pathCheckpoint
  var finalRasAfter:     RasCheckpoint = s2Fast.rasCheckpoint
  for (block <- 0 until blocks) {
    val meta            = finalMeta(block)
    val active          = meta.valid
    val canonicalReturn = isCanonicalReturn(meta.cfiType, meta.rasAction)
    val blockCfiPc      = blockBase(s2Fast.startPc, block) +% (meta.cfiOffset << 1)
    finalHistoryAfter = Mux(
      active,
      advanceConditionalHistory(finalHistoryAfter, meta.cfiType, finalTaken(block)),
      finalHistoryAfter
    )
    finalPathAfter = Mux(
      active && finalTaken(block),
      advancePathHistory(finalPathAfter, meta.cfiType, canonicalReturn, blockCfiPc, finalTarget(block)),
      finalPathAfter
    )
    finalRasAfter = applyRas(
      finalRasAfter,
      Mux(active && finalTaken(block), meta.rasAction, RasAction.none),
      blockCfiPc,
      4.U
    )._1
  }

  val s3Valid        = RegInit(false.B)
  val s3Result       = Reg(new BpuFinalResult(frontendCfg))
  val s3HistoryAfter = Reg(UInt(frontendCfg.historyBits.W))
  val s3PathAfter    = Reg(UInt(frontendCfg.historyBits.W))
  val s3RasAfter     = Reg(new RasCheckpoint(cfg.addrWidth))

  io.finalResult.valid := s3Valid
  io.finalResult.bits  := s3Result

  io.req.ready := !io.recover.valid
  val checkpointHistory = Mux(s1Valid, fastHistoryAfter, speculativeHistory)
  val checkpointPath    = Mux(s1Valid, fastPathAfter, speculativePath)
  val checkpointRas     = Mux(s1Valid, fastRasAfter, speculativeRas)

  when(io.recover.valid) {
    s1Valid := false.B
    s2Valid := false.B
    s3Valid := false.B
  }.otherwise {
    s1Valid := io.req.fire
    s2Valid := s1Valid
    s3Valid := s2Valid

    when(io.req.fire) {
      s1Request := io.req.bits
      s1History := checkpointHistory
      s1Path    := checkpointPath
      s1Ras     := checkpointRas
    }
    when(s1Valid) {
      s2Fast              := io.fastResult.bits
      s2NeedsContinuation := fastNeedsContinuation
      s2NeedsSplit        := fastNeedsSplit
    }
    when(s2Valid) {
      s3Result                  := 0.U.asTypeOf(new BpuFinalResult(frontendCfg))
      s3Result.token            := s2Fast.token
      s3Result.startPc          := s2Fast.startPc
      s3Result.fastNextPc       := s2Fast.predictedNextPc
      s3Result.finalNextPc      := finalNextPc
      s3Result.blockCount       := finalBlockCount
      s3Result.finalPrediction  := finalSummary
      s3Result.overrideFastPath := finalNextPc =/= s2Fast.predictedNextPc
      s3Result.trainMeta        := finalTrainMeta
      s3HistoryAfter            := finalHistoryAfter
      s3PathAfter               := finalPathAfter
      s3RasAfter                := finalRasAfter
    }
  }

  val recoveryRasUpdate  = applyRas(
    io.recover.bits.rasCheckpoint,
    Mux(
      io.recover.bits.recovery.actualCfiValid && io.recover.bits.recovery.actualTaken,
      io.recover.bits.recovery.actualRasAction,
      RasAction.none
    ),
    io.recover.bits.recovery.actualCfiPc,
    io.recover.bits.recovery.actualInstLen
  )
  val recoveredHistory   = Mux(
    io.recover.bits.recovery.actualCfiValid,
    advanceConditionalHistory(
      io.recover.bits.historyCheckpoint,
      io.recover.bits.recovery.actualCfiType,
      io.recover.bits.recovery.actualTaken
    ),
    io.recover.bits.historyCheckpoint
  )
  val recoveredPath      = Mux(
    io.recover.bits.recovery.actualCfiValid && io.recover.bits.recovery.actualTaken,
    advancePathHistory(
      io.recover.bits.pathCheckpoint,
      io.recover.bits.recovery.actualCfiType,
      io.recover.bits.recovery.actualCanonicalReturn,
      io.recover.bits.recovery.actualCfiPc,
      io.recover.bits.recovery.actualTarget
    ),
    io.recover.bits.pathCheckpoint
  )
  val matchingS3Override = io.recover.bits.recovery.kind === FrontendRecoveryKind.bpuOverride && s3Valid &&
    io.recover.bits.recovery.token.tag.index === s3Result.token.tag.index &&
    io.recover.bits.recovery.token.tag.generation === s3Result.token.tag.generation

  when(io.recover.valid) {
    when(matchingS3Override) {
      speculativeHistory := s3HistoryAfter
      speculativePath    := s3PathAfter
      speculativeRas     := s3RasAfter
    }.elsewhen(io.recover.bits.checkpointValid) {
      speculativeHistory := recoveredHistory
      speculativePath    := recoveredPath
      speculativeRas     := recoveryRasUpdate._1
    }.otherwise {
      speculativeHistory := committedHistory
      speculativePath    := committedPath
      speculativeRas     := committedRas
    }
  }.elsewhen(s1Valid) {
    speculativeHistory := fastHistoryAfter
    speculativePath    := fastPathAfter
    speculativeRas     := fastRasAfter
  }

  private val rasUse = VecInit((0 until commitWidth).map { lane =>
    io.train(lane).valid && io.train(lane).bits.context.rasUsed
  }).asUInt.orR
  private val rasHit = VecInit((0 until commitWidth).map { lane =>
    io.train(lane).valid && io.train(lane).bits.context.rasUsed &&
    io.train(lane).bits.target === io.train(lane).bits.context.predictedTarget
  }).asUInt.orR
  private def committedAction(action: UInt): Bool =
    VecInit((0 until commitWidth).map { lane =>
      io.train(lane).valid && io.train(lane).bits.rasAction === action
    }).asUInt.orR

  io.perf                   := 0.U.asTypeOf(new RasPerf)
  io.perf.push              := committedAction(RasAction.push)
  io.perf.pop               := committedAction(RasAction.pop)
  io.perf.popThenPush       := committedAction(RasAction.popThenPush)
  io.perf.use               := rasUse
  io.perf.hit               := rasHit
  io.perf.miss              := rasUse && !rasHit
  io.perf.underflow         := commitUnderflow.asUInt.orR || fastRasUnderflow.asUInt.orR || recoveryRasUpdate._2
  io.perf.overflow          := commitOverflow.asUInt.orR || fastRasOverflow.asUInt.orR || recoveryRasUpdate._3
  io.perf.checkpointRestore := io.recover.valid && io.recover.bits.checkpointValid
  io.perf.recoveryDiscard   := io.recover.valid
  io.perf.taggedProvider    := tage.io.perf.provider || ittage.io.perf.provider
  io.perf.alternateDisagree := tage.io.perf.alternateDisagree || ittage.io.perf.alternateDisagree
  io.perf.allocation        := tage.io.perf.allocation || ittage.io.perf.allocation
  io.perf.usefulnessAging   := tage.io.perf.usefulnessAging || ittage.io.perf.usefulnessAging
  io.perf.lateOverride      := io.finalResult.valid && io.finalResult.bits.overrideFastPath

  when(io.req.fire) {
    assert(io.req.bits.token.streamEpoch === s1Request.token.streamEpoch || !s1Valid || io.fastResult.valid)
  }
  when(io.recover.valid && io.recover.bits.recovery.kind === FrontendRecoveryKind.bpuOverride) {
    assert(matchingS3Override)
  }
}
