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

private object TaggedCounter {
  def increment(value: UInt): UInt =
    Mux(value.andR, value, value +% 1.U)

  def decrement(value: UInt): UInt =
    Mux(!value.orR, value, value -% 1.U)

  def direction(value: UInt, taken: Bool): UInt =
    Mux(taken, increment(value), decrement(value))
}

private class TageSramEntry(cfg: BpuConfig, epochBits: Int) extends Bundle {
  val tag      = UInt(cfg.tageTagBits.W)
  val counter  = UInt(2.W)
  val useful   = UInt(2.W)
  val ageEpoch = UInt(epochBits.W)
}

/** TAGE tagged tables with one registered SRAM read stage.
  *
  * Each history table is an independent memory bank. Query metadata and valid bits advance beside the synchronous
  * reads, so provider selection occurs entirely in BPU S2. Invalid bits remain resettable flops because generic SRAMs
  * do not provide a portable reset value; no tag/counter data is selected through those flops.
  */
class Tage(cfg: BpuConfig, queryWidth: Int) extends Module {
  require(
    cfg.predictorHistoryBits == PredictorConstants.historyBits,
    "Prediction metadata and TAGE history widths must match"
  )
  require(queryWidth > 0, "TAGE query width must be positive")
  require(cfg.tageHistoryLengths.length <= PredictorConstants.maxTaggedTables, "TAGE table metadata width is too small")

  private val cacheCfg       = ICacheConfig(addrWidth = cfg.addrWidth, fetchBytes = cfg.fetchBytes)
  private val tableCount     = cfg.tageHistoryLengths.length
  private val tableIndexBits = math.max(log2Ceil(tableCount), 1)
  private val ageCounterBits = 5

  val io = IO(new Bundle {
    val query      = Input(Vec(queryWidth, new LatePredictQuery(cacheCfg)))
    val prediction = Output(Vec(queryWidth, new LatePrediction(cacheCfg)))
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

  private def tableIndex(pc: UInt, history: UInt, table: Int): UInt =
    pc(cfg.tageIndexBits + 1, 2) ^ foldHistory(history, cfg.tageIndexBits, cfg.tageHistoryLengths(table))

  private def tableTag(pc: UInt, history: UInt, table: Int): UInt =
    pc(cfg.tageIndexBits + cfg.tageTagBits + 1, cfg.tageIndexBits + 2) ^
      foldHistory(history, cfg.tageTagBits, cfg.tageHistoryLengths(table)) ^
      (table + 1).U(cfg.tageTagBits.W)

  private def providerTable(provider: UInt): UInt =
    MuxLookup(provider, 0.U((tableIndexBits + 1).W))(
      (0 until tableCount).map { table =>
        PredictorProvider.tageTable(table) -> (table + 1).U((tableIndexBits + 1).W)
      }
    )

  private val tables      = Seq.fill(tableCount)(SyncReadMem(cfg.tageEntries, new TageSramEntry(cfg, ageCounterBits)))
  private val validTables = Seq.fill(tableCount)(RegInit(VecInit(Seq.fill(cfg.tageEntries)(false.B))))
  private val ageCounter  = RegInit(0.U(ageCounterBits.W))
  private val ageEpoch    = RegInit(0.U(ageCounterBits.W))

  private val queryReg    = Reg(Vec(queryWidth, new LatePredictQuery(cacheCfg)))
  private val queryEnable = RegInit(VecInit(Seq.fill(queryWidth)(false.B)))
  private val readValid   = RegInit(
    VecInit(Seq.fill(queryWidth)(VecInit(Seq.fill(tableCount)(false.B))))
  )
  private val readEntry   = Wire(Vec(queryWidth, Vec(tableCount, new TageSramEntry(cfg, ageCounterBits))))

  queryReg := io.query
  for (lane <- 0 until queryWidth) {
    queryEnable(lane) := io.query(lane).valid
    for (table <- 0 until tableCount) {
      val index = tableIndex(io.query(lane).pc, io.query(lane).history, table)
      readEntry(lane)(table) := tables(table).read(index, io.query(lane).valid)
      readValid(lane)(table) := io.query(lane).valid && validTables(table)(index)
    }
  }

  private val taggedProvider   = Wire(Vec(queryWidth, Bool()))
  private val alternateDiffers = Wire(Vec(queryWidth, Bool()))

  for (lane <- 0 until queryWidth) {
    val query           = queryReg(lane)
    val tags            = Wire(Vec(tableCount, UInt(cfg.tageTagBits.W)))
    val hits            = Wire(Vec(tableCount, Bool()))
    val effectiveUseful = Wire(Vec(tableCount, UInt(2.W)))
    for (table <- 0 until tableCount) {
      tags(table)            := tableTag(query.pc, query.history, table)
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

    val baseCounter      = Mux(query.fastTaken, 2.U(2.W), 1.U(2.W))
    val providerCounter  = Mux(hasProvider, Mux1H(providerOH, readEntry(lane).map(_.counter)), baseCounter)
    val alternateCounter = Mux(
      hasAlternate,
      Mux1H(alternateOH, readEntry(lane).map(_.counter)),
      baseCounter
    )
    val providerUseful   = Mux(hasProvider, Mux1H(providerOH, effectiveUseful), 0.U)
    val providerId       = Wire(UInt(PredictorConstants.providerBits.W))
    val alternateId      = Wire(UInt(PredictorConstants.providerBits.W))
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

    val allocationMask = Wire(Vec(PredictorConstants.maxTaggedTables, Bool()))
    allocationMask := VecInit(Seq.fill(PredictorConstants.maxTaggedTables)(false.B))
    for (table <- 0 until tableCount) {
      allocationMask(table) := !readValid(lane)(table) || effectiveUseful(table) === 0.U
    }

    val providerTaken  = providerCounter(1)
    val alternateTaken = alternateCounter(1)
    val active         = queryEnable(lane) && query.cfiType === CfiType.branch

    io.prediction(lane)                   := 0.U.asTypeOf(new LatePrediction(cacheCfg))
    io.prediction(lane).queried           := active
    io.prediction(lane).valid             := active
    io.prediction(lane).taken             := providerTaken
    io.prediction(lane).provider          := providerId
    io.prediction(lane).alternate         := alternateId
    io.prediction(lane).confidence        := providerCounter
    io.prediction(lane).providerUseful    := providerUseful
    io.prediction(lane).allocationMask    := allocationMask.asUInt
    io.prediction(lane).alternateTaken    := alternateTaken
    io.prediction(lane).alternateTarget   := 0.U
    io.prediction(lane).historyCheckpoint := query.history
    io.prediction(lane).pathCheckpoint    := query.pathHistory

    taggedProvider(lane)   := active && hasProvider
    alternateDiffers(lane) := active && providerTaken =/= alternateTaken
  }

  private val allocationValid    = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))
  private val allocationTable    = Wire(Vec(PredictorConstants.commitUpdateWidth, UInt(tableIndexBits.W)))
  private val allocationPressure = Wire(Vec(PredictorConstants.commitUpdateWidth, Bool()))

  for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
    val update     = io.update(lane)
    val active     = update.valid && update.bits.cfiType === CfiType.branch
    val provider   = providerTable(update.bits.context.provider)
    val mispredict = active && update.bits.context.lateQueried &&
      update.bits.context.lateTaken =/= update.bits.taken
    val eligible   = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      eligible(table) := update.bits.context.allocationMask(table) && (table + 1).U > provider
    }
    val allocationOH = Wire(Vec(tableCount, Bool()))
    for (table <- 0 until tableCount) {
      val lowerEligible = if (table == 0) false.B else VecInit((0 until table).map(eligible)).asUInt.orR
      allocationOH(table) := eligible(table) && !lowerEligible
    }

    allocationValid(lane)    := mispredict && eligible.asUInt.orR
    allocationTable(lane)    := Mux1H(allocationOH, (0 until tableCount).map(_.U(tableIndexBits.W)))
    allocationPressure(lane) := mispredict && !eligible.asUInt.orR
  }

  for (table <- 0 until tableCount) {
    val writeValid = Wire(Vec(PredictorConstants.commitUpdateWidth * 2, Bool()))
    val writeIndex = Wire(Vec(PredictorConstants.commitUpdateWidth * 2, UInt(cfg.tageIndexBits.W)))
    val writeEntry = Wire(
      Vec(PredictorConstants.commitUpdateWidth * 2, new TageSramEntry(cfg, ageCounterBits))
    )
    writeValid := VecInit(Seq.fill(PredictorConstants.commitUpdateWidth * 2)(false.B))
    writeIndex := 0.U.asTypeOf(writeIndex)
    writeEntry := 0.U.asTypeOf(writeEntry)

    for (lane <- 0 until PredictorConstants.commitUpdateWidth) {
      val update        = io.update(lane)
      val active        = update.valid && update.bits.cfiType === CfiType.branch
      val providerWrite = active && update.bits.context.provider === PredictorProvider.tageTable(table)
      val index         = tableIndex(update.bits.pc, update.bits.context.historyCheckpoint, table)
      val providerEntry = Wire(new TageSramEntry(cfg, ageCounterBits))
      val correct       = update.bits.context.lateTaken === update.bits.taken
      val differs       = update.bits.context.lateTaken =/= update.bits.context.alternateTaken
      providerEntry.tag      := tableTag(update.bits.pc, update.bits.context.historyCheckpoint, table)
      providerEntry.counter  := TaggedCounter.direction(update.bits.context.confidence, update.bits.taken)
      providerEntry.useful   := Mux(
        differs,
        Mux(
          correct,
          TaggedCounter.increment(update.bits.context.providerUseful),
          TaggedCounter.decrement(update.bits.context.providerUseful)
        ),
        update.bits.context.providerUseful
      )
      providerEntry.ageEpoch := ageEpoch
      writeValid(lane * 2)   := providerWrite
      writeIndex(lane * 2)   := index
      writeEntry(lane * 2)   := providerEntry

      val allocationWrite = allocationValid(lane) && allocationTable(lane) === table.U
      val allocationEntry = Wire(new TageSramEntry(cfg, ageCounterBits))
      allocationEntry.tag      := tableTag(update.bits.pc, update.bits.context.historyCheckpoint, table)
      allocationEntry.counter  := Mux(update.bits.taken, 2.U, 1.U)
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
