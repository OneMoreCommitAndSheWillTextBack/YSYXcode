package top.core.frontend.Bpu

import chisel3._
import chisel3.util.{Mux1H, MuxLookup, Valid, log2Ceil}
import top.config.{BpuConfig, ICacheConfig}
import top.core.bundle.CfiType
import top.core.frontend.bundle.{BpuUpdate, LatePredictQuery, LatePrediction, PredictorConstants, PredictorProvider, TaggedPredictorPerf}

private object TaggedCounter {
  def increment(value: UInt): UInt =
    Mux(value.andR, value, value +% 1.U)

  def decrement(value: UInt): UInt =
    Mux(!value.orR, value, value -% 1.U)

  def direction(value: UInt, taken: Bool): UInt =
    Mux(taken, increment(value), decrement(value))
}

class Tage(cfg: BpuConfig) extends Module {
  require(cfg.predictorHistoryBits == PredictorConstants.historyBits, "Prediction metadata and TAGE history widths must match")

  private val cacheCfg       = ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes)
  private val tableCount     = cfg.tageHistoryLengths.length
  private val tableIndexBits = math.max(log2Ceil(tableCount), 1)
  private val ageCounterBits = 5

  val io = IO(new Bundle {
    val query      = Input(Vec(PredictorConstants.latePredictionWidth, new LatePredictQuery(cacheCfg)))
    val prediction = Output(Vec(PredictorConstants.latePredictionWidth, new LatePrediction(cacheCfg)))
    val update     = Input(Vec(PredictorConstants.commitUpdateWidth, Valid(new BpuUpdate(cfg))))
    val perf       = Output(new TaggedPredictorPerf)
  })

  private def foldHistory(history: UInt, width: Int, length: Int): UInt = {
    val pieces = (0 until length by width).map { start =>
      val end      = math.min(length, start + width) - 1
      val extended = Wire(UInt(width.W))
      extended := history(end, start)
      extended
    }

    pieces.reduce(_ ^ _)
  }

  private def baseIndex(pc: UInt): UInt =
    pc(cfg.bhtIndexBits + 1, 2)

  private def tableIndex(pc: UInt, history: UInt, table: Int): UInt =
    pc(cfg.tageIndexBits + 1, 2) ^ foldHistory(history, cfg.tageIndexBits, cfg.tageHistoryLengths(table))

  private def tableTag(pc: UInt, history: UInt, table: Int): UInt =
    pc(cfg.tageTagBits + 1, 2) ^
      foldHistory(history, cfg.tageTagBits, cfg.tageHistoryLengths(table)) ^
      (table + 1).U(cfg.tageTagBits.W)

  private def providerTable(provider: UInt): UInt =
    MuxLookup(provider, 0.U((tableIndexBits + 1).W))(
      (0 until tableCount).map { table =>
        PredictorProvider.tageTable(table) -> (table + 1).U((tableIndexBits + 1).W)
      }
    )

  private val baseCounters = RegInit(VecInit(Seq.fill(cfg.bhtEntries)(1.U(2.W))))
  private val validTables  = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.tageEntries)(false.B))))
  private val tagTables    = Seq.fill(tableCount)(Reg(Vec(cfg.tageEntries, UInt(cfg.tageTagBits.W))))
  private val ctrTables    = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.tageEntries)(1.U(2.W)))))
  private val usefulTables = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.tageEntries)(0.U(2.W)))))
  private val ageCounter   = RegInit(0.U(ageCounterBits.W))

  private val taggedProvider  = Wire(Vec(PredictorConstants.latePredictionWidth, Bool()))
  private val alternateDiffers = Wire(Vec(PredictorConstants.latePredictionWidth, Bool()))

  for (lane <- 0 until PredictorConstants.latePredictionWidth) {
    val query      = io.query(lane)
    val baseCounter = baseCounters(baseIndex(query.pc))
    val indices    = Wire(Vec(tableCount, UInt(cfg.tageIndexBits.W)))
    val tags       = Wire(Vec(tableCount, UInt(cfg.tageTagBits.W)))
    val hits       = Wire(Vec(tableCount, Bool()))

    for (table <- 0 until tableCount) {
      indices(table) := tableIndex(query.pc, query.history, table)
      tags(table)    := tableTag(query.pc, query.history, table)
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

    val providerCounter = Mux1H(providerOH, (0 until tableCount).map(table => ctrTables(table)(indices(table))))
    val alternateCounter = Mux(
      hasAlternate,
      Mux1H(alternateOH, (0 until tableCount).map(table => ctrTables(table)(indices(table)))),
      baseCounter
    )
    val providerId = Wire(UInt(PredictorConstants.providerBits.W))
    val alternateId = Wire(UInt(PredictorConstants.providerBits.W))
    providerId  := PredictorProvider.tageBase
    alternateId := PredictorProvider.tageBase
    for (table <- 0 until tableCount) {
      when(providerOH(table)) {
        providerId := PredictorProvider.tageTable(table)
      }
      when(alternateOH(table)) {
        alternateId := PredictorProvider.tageTable(table)
      }
    }

    val providerTaken  = Mux(hasProvider, providerCounter(1), baseCounter(1))
    val alternateTaken = alternateCounter(1)
    val active         = query.valid && query.cfiType === CfiType.branch

    io.prediction(lane) := 0.U.asTypeOf(new LatePrediction(cacheCfg))
    io.prediction(lane).valid             := active
    io.prediction(lane).taken             := providerTaken
    io.prediction(lane).provider          := providerId
    io.prediction(lane).alternate         := alternateId
    io.prediction(lane).confidence        := Mux(hasProvider, providerCounter, baseCounter)
    io.prediction(lane).alternateTaken    := alternateTaken
    io.prediction(lane).historyCheckpoint := query.history
    io.prediction(lane).pathCheckpoint    := query.pathHistory

    taggedProvider(lane)  := active && hasProvider
    alternateDiffers(lane) := active && providerTaken =/= alternateTaken
  }

  private val update0Active = io.update(0).valid && io.update(0).bits.cfiType === CfiType.branch
  private val update0BaseIndex = baseIndex(io.update(0).bits.pc)
  private val update0BaseNext = TaggedCounter.direction(baseCounters(update0BaseIndex), io.update(0).bits.taken)
  when(update0Active) {
    baseCounters(update0BaseIndex) := update0BaseNext
  }

  private val update1Active = io.update(1).valid && io.update(1).bits.cfiType === CfiType.branch
  private val update1BaseIndex = baseIndex(io.update(1).bits.pc)
  private val update1Matches0 = update0Active && update0BaseIndex === update1BaseIndex
  private val update1BasePrior = Mux(update1Matches0, update0BaseNext, baseCounters(update1BaseIndex))
  when(update1Active) {
    baseCounters(update1BaseIndex) := TaggedCounter.direction(update1BasePrior, io.update(1).bits.taken)
  }

  private val allocationValid = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))
  private val allocationTable = Wire(Vec(PredictorConstants.commitUpdateWidth, UInt(tableIndexBits.W)))
  private val allocationPressure = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))

  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    val update = io.update(lane)
    val active = update.valid && update.bits.cfiType === CfiType.branch
    val provider = providerTable(update.bits.prediction.provider)
    val mispredict = active && update.bits.prediction.lateValid &&
      update.bits.prediction.lateTaken =/= update.bits.taken
    val eligible = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val index = tableIndex(update.bits.pc, update.bits.prediction.historyCheckpoint, table)
      eligible(table) := (table + 1).U > provider && usefulTables(table)(index) === 0.U
    }
    val allocationOH = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val lowerEligible = if (table == 0) false.B else VecInit((0 until table).map(eligible)).asUInt.orR
      allocationOH(table) := eligible(table) && !lowerEligible
    }

    allocationValid(lane) := mispredict && eligible.asUInt.orR
    allocationTable(lane) := Mux1H(allocationOH, (0 until tableCount).map(_.U(tableIndexBits.W)))
    allocationPressure(lane) := mispredict && !eligible.asUInt.orR
  }

  for (table <- 0 until tableCount) {
    val update0Provider = update0Active && io.update(0).bits.prediction.provider === PredictorProvider.tageTable(table)
    val update0Index = tableIndex(io.update(0).bits.pc, io.update(0).bits.prediction.historyCheckpoint, table)
    val update0Ctr = TaggedCounter.direction(ctrTables(table)(update0Index), io.update(0).bits.taken)
    val update0Useful = {
      val correct = io.update(0).bits.prediction.lateTaken === io.update(0).bits.taken
      val differs = io.update(0).bits.prediction.lateTaken =/= io.update(0).bits.prediction.alternateTaken
      Mux(
        differs,
        Mux(correct, TaggedCounter.increment(usefulTables(table)(update0Index)), TaggedCounter.decrement(usefulTables(table)(update0Index))),
        usefulTables(table)(update0Index)
      )
    }
    when(update0Provider) {
      ctrTables(table)(update0Index)    := update0Ctr
      usefulTables(table)(update0Index) := update0Useful
    }

    val update1Provider = update1Active && io.update(1).bits.prediction.provider === PredictorProvider.tageTable(table)
    val update1Index = tableIndex(io.update(1).bits.pc, io.update(1).bits.prediction.historyCheckpoint, table)
    val update1Matches0 = update0Provider && update0Index === update1Index
    val update1CtrPrior = Mux(update1Matches0, update0Ctr, ctrTables(table)(update1Index))
    val update1UsefulPrior = Mux(update1Matches0, update0Useful, usefulTables(table)(update1Index))
    val update1Useful = {
      val correct = io.update(1).bits.prediction.lateTaken === io.update(1).bits.taken
      val differs = io.update(1).bits.prediction.lateTaken =/= io.update(1).bits.prediction.alternateTaken
      Mux(
        differs,
        Mux(correct, TaggedCounter.increment(update1UsefulPrior), TaggedCounter.decrement(update1UsefulPrior)),
        update1UsefulPrior
      )
    }
    when(update1Provider) {
      ctrTables(table)(update1Index)    := TaggedCounter.direction(update1CtrPrior, io.update(1).bits.taken)
      usefulTables(table)(update1Index) := update1Useful
    }

    for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
      when(allocationValid(lane) && allocationTable(lane) === table.U) {
        val update = io.update(lane)
        val index  = tableIndex(update.bits.pc, update.bits.prediction.historyCheckpoint, table)
        validTables(table)(index)  := true.B
        tagTables(table)(index)    := tableTag(update.bits.pc, update.bits.prediction.historyCheckpoint, table)
        ctrTables(table)(index)    := Mux(update.bits.taken, 2.U, 1.U)
        usefulTables(table)(index) := 0.U
      }
    }
  }

  private val ageNow = allocationPressure.asUInt.orR && ageCounter.andR
  when(ageNow) {
    ageCounter := 0.U
    for (table <- 0 until tableCount) {
      for (entry <- 0 until cfg.tageEntries) {
        usefulTables(table)(entry) := TaggedCounter.decrement(usefulTables(table)(entry))
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
