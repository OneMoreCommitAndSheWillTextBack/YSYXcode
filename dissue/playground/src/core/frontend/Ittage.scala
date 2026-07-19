package top.core.frontend.Bpu

import chisel3._
import chisel3.util.{Mux1H, MuxLookup, Valid, log2Ceil}
import top.config.{BpuConfig, ICacheConfig}
import top.core.bundle.CfiType
import top.core.frontend.bundle.{BpuUpdate, LatePrediction, LatePredictQuery, PredictorConstants, PredictorProvider, TaggedPredictorPerf}

private object IttageCounter {
  def increment(value: UInt): UInt =
    Mux(value.andR, value, value +% 1.U)

  def decrement(value: UInt): UInt =
    Mux(!value.orR, value, value -% 1.U)
}

class Ittage(cfg: BpuConfig) extends Module {
  require(cfg.predictorHistoryBits == PredictorConstants.historyBits, "Prediction metadata and ITTAGE history widths must match")
  require(cfg.ittageIndexBits + cfg.ittageTagBits + 2 <= cfg.addrWidth, "ITTAGE index and tag must fit the PC")

  private val cacheCfg       = ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes)
  private val tableCount     = cfg.ittageHistoryLengths.length
  private val tableIndexBits = math.max(log2Ceil(tableCount), 1)
  private val entryIndexBits = math.max(cfg.ittageIndexBits, 1)
  private val ageCounterBits = 5

  val io = IO(new Bundle {
    val query      = Input(Vec(PredictorConstants.latePredictionWidth, new LatePredictQuery(cacheCfg)))
    val prediction = Output(Vec(PredictorConstants.latePredictionWidth, new LatePrediction(cacheCfg)))
    val update     = Input(Vec(PredictorConstants.commitUpdateWidth, Valid(new BpuUpdate(cfg))))
    val perf       = Output(new TaggedPredictorPerf)
  })

  private def foldPathHistory(history: UInt, width: Int, length: Int): UInt = {
    val pieces = (0 until length by width).map { start =>
      val end      = math.min(length, start + width) - 1
      val extended = Wire(UInt(width.W))
      extended := history(end, start)
      extended
    }

    pieces.reduce(_ ^ _)
  }

  private def tableIndex(pc: UInt, pathHistory: UInt, table: Int): UInt =
    pc(entryIndexBits + 1, 2) ^
      foldPathHistory(pathHistory, entryIndexBits, cfg.ittageHistoryLengths(table))

  private def tableTag(pc: UInt, pathHistory: UInt, table: Int): UInt =
    pc(cfg.ittageIndexBits + cfg.ittageTagBits + 1, cfg.ittageIndexBits + 2) ^
      foldPathHistory(pathHistory, cfg.ittageTagBits, cfg.ittageHistoryLengths(table)) ^
      (table + 1).U(cfg.ittageTagBits.W)

  private def providerTable(provider: UInt): UInt =
    MuxLookup(provider, 0.U((tableIndexBits + 1).W))(
      (0 until tableCount).map { table =>
        PredictorProvider.ittageTable(table) -> (table + 1).U((tableIndexBits + 1).W)
      }
    )

  private def isGenericIndirect(cfiType: UInt, canonicalReturn: Bool): Bool =
    cfiType === CfiType.jalr && !canonicalReturn

  private val validTables  = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.ittageEntries)(false.B))))
  private val tagTables    = Seq.fill(tableCount)(Reg(Vec(cfg.ittageEntries, UInt(cfg.ittageTagBits.W))))
  private val targetTables = Seq.fill(tableCount)(Reg(Vec(cfg.ittageEntries, UInt(cfg.addrWidth.W))))
  private val ctrTables    = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.ittageEntries)(1.U(2.W)))))
  private val usefulTables = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.ittageEntries)(0.U(2.W)))))
  private val ageCounter   = RegInit(0.U(ageCounterBits.W))

  private val taggedProvider   = Wire(Vec(PredictorConstants.latePredictionWidth, Bool()))
  private val alternateDiffers = Wire(Vec(PredictorConstants.latePredictionWidth, Bool()))

  for (lane <- 0 until PredictorConstants.latePredictionWidth) {
    val query   = io.query(lane)
    val indices = Wire(Vec(tableCount, UInt(entryIndexBits.W)))
    val tags    = Wire(Vec(tableCount, UInt(cfg.ittageTagBits.W)))
    val hits    = Wire(Vec(tableCount, Bool()))

    for (table <- 0 until tableCount) {
      indices(table) := tableIndex(query.pc, query.pathHistory, table)
      tags(table)    := tableTag(query.pc, query.pathHistory, table)
      hits(table)    := validTables(table)(indices(table)) && tagTables(table)(indices(table)) === tags(table)
    }

    val providerOH = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val higherHit =
        if (table + 1 == tableCount) false.B else VecInit(((table + 1) until tableCount).map(hits)).asUInt.orR
      providerOH(table) := hits(table) && !higherHit
    }
    val hasProvider = hits.asUInt.orR

    val alternateOH = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val higherBelowProvider =
        if (table + 1 == tableCount) false.B
        else VecInit(((table + 1) until tableCount).map { higher =>
          hits(higher) && !providerOH(higher)
        }).asUInt.orR
      alternateOH(table) := hits(table) && !providerOH(table) && !higherBelowProvider
    }
    val hasAlternate = alternateOH.asUInt.orR

    val providerTarget = Mux(
      hasProvider,
      Mux1H(providerOH, (0 until tableCount).map(table => targetTables(table)(indices(table)))),
      query.fastTarget
    )
    val providerCounter = Mux(
      hasProvider,
      Mux1H(providerOH, (0 until tableCount).map(table => ctrTables(table)(indices(table)))),
      Mux(query.fastValid, 2.U(2.W), 0.U(2.W))
    )
    val alternateTarget = Mux(
      hasAlternate,
      Mux1H(alternateOH, (0 until tableCount).map(table => targetTables(table)(indices(table)))),
      query.fastTarget
    )

    val providerId  = Wire(UInt(PredictorConstants.providerBits.W))
    val alternateId = Wire(UInt(PredictorConstants.providerBits.W))
    providerId  := PredictorProvider.ittageBase
    alternateId := PredictorProvider.ittageBase
    for (table <- 0 until tableCount) {
      when(providerOH(table)) {
        providerId := PredictorProvider.ittageTable(table)
      }
      when(alternateOH(table)) {
        alternateId := PredictorProvider.ittageTable(table)
      }
    }

    val active = isGenericIndirect(query.cfiType, query.canonicalReturn) && query.valid
    val valid  = active && (hasProvider || query.fastValid)
    val alternateValid = active && (hasAlternate || query.fastValid)

    io.prediction(lane) := 0.U.asTypeOf(new LatePrediction(cacheCfg))
    io.prediction(lane).queried           := active
    io.prediction(lane).valid             := valid
    io.prediction(lane).taken             := valid
    io.prediction(lane).target            := providerTarget
    io.prediction(lane).provider          := providerId
    io.prediction(lane).alternate         := alternateId
    io.prediction(lane).confidence        := providerCounter
    io.prediction(lane).alternateTaken    := alternateValid
    io.prediction(lane).alternateTarget   := alternateTarget
    io.prediction(lane).historyCheckpoint := query.history
    io.prediction(lane).pathCheckpoint    := query.pathHistory

    taggedProvider(lane)   := valid && hasProvider
    alternateDiffers(lane) := valid && hasProvider && (hasAlternate || query.fastValid) && providerTarget =/= alternateTarget
  }

  private val updateActive = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))
  private val allocationValid = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))
  private val allocationTable = Wire(Vec(PredictorConstants.commitUpdateWidth, UInt(tableIndexBits.W)))
  private val allocationPressure = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))

  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    val update = io.update(lane)
    val active = update.valid && update.bits.prediction.lateQueried &&
      isGenericIndirect(update.bits.cfiType, update.bits.prediction.canonicalReturn)
    val provider = providerTable(update.bits.prediction.provider)
    val targetMispredict = active &&
      (!update.bits.prediction.lateValid || update.bits.prediction.lateTarget =/= update.bits.target)
    val eligible = Wire(Vec(tableCount, Bool()))

    for (table <- 0 until tableCount) {
      val index = tableIndex(update.bits.pc, update.bits.prediction.pathCheckpoint, table)
      eligible(table) := (table + 1).U > provider && usefulTables(table)(index) === 0.U
    }

    val allocationOH = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val lowerEligible = if (table == 0) false.B else VecInit((0 until table).map(eligible)).asUInt.orR
      allocationOH(table) := eligible(table) && !lowerEligible
    }

    updateActive(lane) := active
    allocationValid(lane) := targetMispredict && eligible.asUInt.orR
    allocationTable(lane) := Mux1H(allocationOH, (0 until tableCount).map(_.U(tableIndexBits.W)))
    allocationPressure(lane) := targetMispredict && !eligible.asUInt.orR
  }

  for (table <- 0 until tableCount) {
    val update0       = io.update(0).bits
    val update0Index  = tableIndex(update0.pc, update0.prediction.pathCheckpoint, table)
    val update0Tag    = tableTag(update0.pc, update0.prediction.pathCheckpoint, table)
    val update0Provider = updateActive(0) && update0.prediction.provider === PredictorProvider.ittageTable(table) &&
      validTables(table)(update0Index) && tagTables(table)(update0Index) === update0Tag &&
      targetTables(table)(update0Index) === update0.prediction.lateTarget
    val update0Target = targetTables(table)(update0Index)
    val update0Match  = update0Target === update0.target
    val update0ReplaceTarget = !update0Match && ctrTables(table)(update0Index) <= 1.U
    val update0Ctr = Mux(
      update0ReplaceTarget,
      2.U(2.W),
      Mux(update0Match, IttageCounter.increment(ctrTables(table)(update0Index)), IttageCounter.decrement(ctrTables(table)(update0Index)))
    )
    val update0TargetNext = Mux(update0ReplaceTarget, update0.target, update0Target)
    val update0Useful = Mux(
      update0.prediction.alternateTaken && update0Target =/= update0.prediction.alternateTarget,
      Mux(update0Match, IttageCounter.increment(usefulTables(table)(update0Index)), IttageCounter.decrement(usefulTables(table)(update0Index))),
      usefulTables(table)(update0Index)
    )

    when(update0Provider) {
      targetTables(table)(update0Index) := update0TargetNext
      ctrTables(table)(update0Index)    := update0Ctr
      usefulTables(table)(update0Index) := update0Useful
    }

    val update1       = io.update(1).bits
    val update1Index  = tableIndex(update1.pc, update1.prediction.pathCheckpoint, table)
    val update1Tag    = tableTag(update1.pc, update1.prediction.pathCheckpoint, table)
    val update1Provider = updateActive(1) && update1.prediction.provider === PredictorProvider.ittageTable(table) &&
      validTables(table)(update1Index) && tagTables(table)(update1Index) === update1Tag &&
      targetTables(table)(update1Index) === update1.prediction.lateTarget
    val update1Matches0 = update0Provider && update1Provider && update0Index === update1Index
    val update1TargetPrior = Mux(update1Matches0, update0TargetNext, targetTables(table)(update1Index))
    val update1CtrPrior = Mux(update1Matches0, update0Ctr, ctrTables(table)(update1Index))
    val update1UsefulPrior = Mux(update1Matches0, update0Useful, usefulTables(table)(update1Index))
    val update1Match = update1TargetPrior === update1.target
    val update1ReplaceTarget = !update1Match && update1CtrPrior <= 1.U
    val update1Ctr = Mux(
      update1ReplaceTarget,
      2.U(2.W),
      Mux(update1Match, IttageCounter.increment(update1CtrPrior), IttageCounter.decrement(update1CtrPrior))
    )
    val update1TargetNext = Mux(update1ReplaceTarget, update1.target, update1TargetPrior)
    val update1Useful = Mux(
      update1.prediction.alternateTaken && update1TargetPrior =/= update1.prediction.alternateTarget,
      Mux(update1Match, IttageCounter.increment(update1UsefulPrior), IttageCounter.decrement(update1UsefulPrior)),
      update1UsefulPrior
    )

    when(update1Provider) {
      targetTables(table)(update1Index) := update1TargetNext
      ctrTables(table)(update1Index)    := update1Ctr
      usefulTables(table)(update1Index) := update1Useful
    }

    for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
      when(allocationValid(lane) && allocationTable(lane) === table.U) {
        val update = io.update(lane).bits
        val index  = tableIndex(update.pc, update.prediction.pathCheckpoint, table)
        validTables(table)(index)  := true.B
        tagTables(table)(index)    := tableTag(update.pc, update.prediction.pathCheckpoint, table)
        targetTables(table)(index) := update.target
        ctrTables(table)(index)    := 2.U
        usefulTables(table)(index) := 0.U
      }
    }
  }

  private val ageNow = allocationPressure.asUInt.orR && ageCounter.andR
  when(ageNow) {
    ageCounter := 0.U
    for (table <- 0 until tableCount) {
      for (entry <- 0 until cfg.ittageEntries) {
        usefulTables(table)(entry) := IttageCounter.decrement(usefulTables(table)(entry))
      }
    }
  }.elsewhen(allocationPressure.asUInt.orR) {
    ageCounter := ageCounter + 1.U
  }

  io.perf.provider          := taggedProvider.asUInt.orR
  io.perf.alternateDisagree := alternateDiffers.asUInt.orR
  io.perf.allocation        := allocationValid.asUInt.orR
  io.perf.usefulnessAging   := ageNow
}
