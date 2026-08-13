package top.core.frontend.Bpu

import chisel3._
import chisel3.util.{log2Ceil, Mux1H, MuxLookup, PriorityEncoderOH, Valid}
import top.config.{BpuConfig, ICacheConfig}
import top.core.bundle.CfiType
import top.core.frontend.bundle.{
  BpuUpdate,
  LatePredictQuery,
  LatePrediction,
  PredictorConstants,
  PredictorProvider,
  TaggedPredictorPerf
}

private object IttageCounter {
  def increment(value: UInt): UInt =
    Mux(value.andR, value, value +% 1.U)

  def decrement(value: UInt): UInt =
    Mux(!value.orR, value, value -% 1.U)
}

private class IttageSramEntry(cfg: BpuConfig, epochBits: Int) extends Bundle {
  val tag      = UInt(cfg.ittageTagBits.W)
  val target   = UInt(cfg.addrWidth.W)
  val counter  = UInt(2.W)
  val useful   = UInt(2.W)
  val ageEpoch = UInt(epochBits.W)
}

/** ITTAGE target banks with a registered SRAM read stage aligned to BPU S2. */
class Ittage(cfg: BpuConfig, queryWidth: Int) extends Module {
  require(
    cfg.predictorHistoryBits == PredictorConstants.historyBits,
    "Prediction metadata and ITTAGE history widths must match"
  )
  require(cfg.ittageIndexBits + cfg.ittageTagBits + 2 <= cfg.addrWidth, "ITTAGE index and tag must fit the PC")
  require(queryWidth > 0, "ITTAGE query width must be positive")
  require(
    cfg.ittageHistoryLengths.length <= PredictorConstants.maxTaggedTables,
    "ITTAGE table metadata width is too small"
  )

  private val cacheCfg       = ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes)
  private val tableCount     = cfg.ittageHistoryLengths.length
  private val tableIndexBits = math.max(log2Ceil(tableCount), 1)
  private val entryIndexBits = math.max(cfg.ittageIndexBits, 1)
  private val ageCounterBits = 5

  val io = IO(new Bundle {
    val query      = Input(Vec(queryWidth, new LatePredictQuery(cacheCfg)))
    val prediction = Output(Vec(queryWidth, new LatePrediction(cacheCfg)))
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

  private val tables      = Seq.fill(tableCount)(
    SyncReadMem(cfg.ittageEntries, new IttageSramEntry(cfg, ageCounterBits))
  )
  private val validTables = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.ittageEntries)(false.B))))
  private val ageCounter  = RegInit(0.U(ageCounterBits.W))
  private val ageEpoch    = RegInit(0.U(ageCounterBits.W))

  private val queryReg    = Reg(Vec(queryWidth, new LatePredictQuery(cacheCfg)))
  private val queryEnable = RegInit(VecInit(Seq.fill(queryWidth)(false.B)))
  private val readValid   = RegInit(
    VecInit(Seq.fill(queryWidth)(VecInit(Seq.fill(tableCount)(false.B))))
  )
  private val readEntry   = Wire(Vec(queryWidth, Vec(tableCount, new IttageSramEntry(cfg, ageCounterBits))))

  queryReg := io.query
  for (lane <- 0 until queryWidth) {
    queryEnable(lane) := io.query(lane).valid
    for (table <- 0 until tableCount) {
      val index = tableIndex(io.query(lane).pc, io.query(lane).pathHistory, table)
      readEntry(lane)(table) := tables(table).read(index, io.query(lane).valid)
      readValid(lane)(table) := io.query(lane).valid && validTables(table)(index)
    }
  }

  private val taggedProvider   = Wire(Vec(queryWidth, Bool()))
  private val alternateDiffers = Wire(Vec(queryWidth, Bool()))

  for (lane <- 0 until queryWidth) {
    val query           = queryReg(lane)
    val tags            = Wire(Vec(tableCount, UInt(cfg.ittageTagBits.W)))
    val hits            = Wire(Vec(tableCount, Bool()))
    val effectiveUseful = Wire(Vec(tableCount, UInt(2.W)))
    for (table <- 0 until tableCount) {
      tags(table)            := tableTag(query.pc, query.pathHistory, table)
      hits(table)            := readValid(lane)(table) && readEntry(lane)(table).tag === tags(table)
      effectiveUseful(table) := Mux(
        readValid(lane)(table) && readEntry(lane)(table).ageEpoch === ageEpoch,
        readEntry(lane)(table).useful,
        0.U
      )
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
        else
          VecInit(((table + 1) until tableCount).map { higher =>
            hits(higher) && !providerOH(higher)
          }).asUInt.orR
      alternateOH(table) := hits(table) && !providerOH(table) && !higherBelowProvider
    }
    val hasAlternate = alternateOH.asUInt.orR

    val providerTarget  = Mux(
      hasProvider,
      Mux1H(providerOH, readEntry(lane).map(_.target)),
      query.fastTarget
    )
    val providerCounter = Mux(
      hasProvider,
      Mux1H(providerOH, readEntry(lane).map(_.counter)),
      Mux(query.fastValid, 2.U(2.W), 0.U(2.W))
    )
    val alternateTarget = Mux(
      hasAlternate,
      Mux1H(alternateOH, readEntry(lane).map(_.target)),
      query.fastTarget
    )
    val providerUseful  = Mux(hasProvider, Mux1H(providerOH, effectiveUseful), 0.U)

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

    val allocationMask = Wire(Vec(PredictorConstants.maxTaggedTables, Bool()))
    allocationMask := VecInit(Seq.fill(PredictorConstants.maxTaggedTables)(false.B))
    for (table <- 0 until tableCount) {
      allocationMask(table) := !readValid(lane)(table) || effectiveUseful(table) === 0.U
    }

    val active         = queryEnable(lane) && isGenericIndirect(query.cfiType, query.canonicalReturn)
    val valid          = active && (hasProvider || query.fastValid)
    val alternateValid = active && (hasAlternate || query.fastValid)

    io.prediction(lane)                   := 0.U.asTypeOf(new LatePrediction(cacheCfg))
    io.prediction(lane).queried           := active
    io.prediction(lane).valid             := valid
    io.prediction(lane).taken             := valid
    io.prediction(lane).target            := providerTarget
    io.prediction(lane).provider          := providerId
    io.prediction(lane).alternate         := alternateId
    io.prediction(lane).confidence        := providerCounter
    io.prediction(lane).providerUseful    := providerUseful
    io.prediction(lane).allocationMask    := allocationMask.asUInt
    io.prediction(lane).alternateTaken    := alternateValid
    io.prediction(lane).alternateTarget   := alternateTarget
    io.prediction(lane).historyCheckpoint := query.history
    io.prediction(lane).pathCheckpoint    := query.pathHistory

    taggedProvider(lane) := valid && hasProvider
    alternateDiffers(
      lane
    )                    := valid && hasProvider && (hasAlternate || query.fastValid) && providerTarget =/= alternateTarget
  }

  private val updateActive       = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))
  private val allocationValid    = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))
  private val allocationTable    = Wire(Vec(PredictorConstants.commitUpdateWidth, UInt(tableIndexBits.W)))
  private val allocationPressure = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))

  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    val update           = io.update(lane)
    val active           = update.valid && update.bits.context.lateQueried &&
      isGenericIndirect(update.bits.cfiType, update.bits.canonicalReturn)
    val provider         = providerTable(update.bits.context.provider)
    val targetMispredict = active &&
      (!update.bits.context.lateValid || update.bits.context.lateTarget =/= update.bits.target)
    val eligible         = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      eligible(table) := update.bits.context.allocationMask(table) && (table + 1).U > provider
    }
    val allocationOH = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val lowerEligible = if (table == 0) false.B else VecInit((0 until table).map(eligible)).asUInt.orR
      allocationOH(table) := eligible(table) && !lowerEligible
    }

    updateActive(lane)       := active
    allocationValid(lane)    := targetMispredict && eligible.asUInt.orR
    allocationTable(lane)    := Mux1H(allocationOH, (0 until tableCount).map(_.U(tableIndexBits.W)))
    allocationPressure(lane) := targetMispredict && !eligible.asUInt.orR
  }

  for (table <- 0 until tableCount) {
    val writeValid = Wire(Vec(PredictorConstants.commitUpdateWidth * 2, Bool()))
    val writeIndex = Wire(Vec(PredictorConstants.commitUpdateWidth * 2, UInt(cfg.ittageIndexBits.W)))
    val writeEntry = Wire(
      Vec(PredictorConstants.commitUpdateWidth * 2, new IttageSramEntry(cfg, ageCounterBits))
    )
    writeValid := VecInit(Seq.fill(PredictorConstants.commitUpdateWidth * 2)(false.B))
    writeIndex := 0.U.asTypeOf(writeIndex)
    writeEntry := 0.U.asTypeOf(writeEntry)

    for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
      val update        = io.update(lane).bits
      val providerWrite = updateActive(lane) && update.context.provider === PredictorProvider.ittageTable(table)
      val index         = tableIndex(update.pc, update.context.pathCheckpoint, table)
      val targetMatches = update.context.lateTarget === update.target
      val replaceTarget = !targetMatches && update.context.confidence <= 1.U
      val nextCounter   = Mux(
        replaceTarget,
        2.U(2.W),
        Mux(
          targetMatches,
          IttageCounter.increment(update.context.confidence),
          IttageCounter.decrement(update.context.confidence)
        )
      )
      val nextTarget    = Mux(replaceTarget, update.target, update.context.lateTarget)
      val nextUseful    = Mux(
        update.context.alternateTaken && update.context.lateTarget =/= update.context.alternateTarget,
        Mux(
          targetMatches,
          IttageCounter.increment(update.context.providerUseful),
          IttageCounter.decrement(update.context.providerUseful)
        ),
        update.context.providerUseful
      )
      val providerEntry = Wire(new IttageSramEntry(cfg, ageCounterBits))
      providerEntry.tag      := tableTag(update.pc, update.context.pathCheckpoint, table)
      providerEntry.target   := nextTarget
      providerEntry.counter  := nextCounter
      providerEntry.useful   := nextUseful
      providerEntry.ageEpoch := ageEpoch
      writeValid(lane * 2)   := providerWrite
      writeIndex(lane * 2)   := index
      writeEntry(lane * 2)   := providerEntry

      val allocationWrite = allocationValid(lane) && allocationTable(lane) === table.U
      val allocationEntry = Wire(new IttageSramEntry(cfg, ageCounterBits))
      allocationEntry.tag      := tableTag(update.pc, update.context.pathCheckpoint, table)
      allocationEntry.target   := update.target
      allocationEntry.counter  := 2.U
      allocationEntry.useful   := 0.U
      allocationEntry.ageEpoch := ageEpoch
      writeValid(lane * 2 + 1) := allocationWrite
      writeIndex(lane * 2 + 1) := index
      writeEntry(lane * 2 + 1) := allocationEntry
    }

    val selectedWrite = PriorityEncoderOH(writeValid.asUInt)
    when(writeValid.asUInt.orR) {
      val selectedIndex = Mux1H(selectedWrite, writeIndex)
      tables(table).write(selectedIndex, Mux1H(selectedWrite, writeEntry))
      validTables(table)(selectedIndex) := true.B
    }
  }

  private val ageNow = allocationPressure.asUInt.orR && ageCounter.andR
  when(ageNow) {
    ageCounter := 0.U
    ageEpoch   := ageEpoch +% 1.U
  }.elsewhen(allocationPressure.asUInt.orR) {
    ageCounter := ageCounter + 1.U
  }

  io.perf.provider          := taggedProvider.asUInt.orR
  io.perf.alternateDisagree := alternateDiffers.asUInt.orR
  io.perf.allocation        := allocationValid.asUInt.orR
  io.perf.usefulnessAging   := ageNow
}
