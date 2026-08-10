package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{log2Ceil, Cat, Decoupled, Mux1H, PopCount, Valid}
import top.config.FrontendConfig
import top.core.frontend.bundle._

class FetchTargetEntry(cfg: FrontendConfig) extends Bundle {
  val token               = new FetchToken(cfg)
  val sequence            = UInt(cfg.ftqSequenceBits.W)
  val phase               = FtqEntryPhase()
  val startPc             = UInt(cfg.addrWidth.W)
  val blockCount          = UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W)
  val fastNextPc          = UInt(cfg.addrWidth.W)
  val finalNextPc         = UInt(cfg.addrWidth.W)
  val fastBlockPred       = Vec(cfg.fetchGroupBlocks, new BtbCfiMeta(cfg))
  val fastBlockTaken      = Vec(cfg.fetchGroupBlocks, Bool())
  val prediction          = new PredictionSummary(cfg)
  val trainMeta           = Vec(cfg.fetchGroupBlocks, Valid(new PredictorTrainMeta(cfg)))
  val historyCheckpoint   = UInt(cfg.historyBits.W)
  val pathCheckpoint      = UInt(cfg.historyBits.W)
  val rasCheckpoint       = new RasCheckpoint(cfg.addrWidth)
  val emittedInsts        = UInt(cfg.ftqInstCountBits.W)
  val expectedRetireInsts = UInt(cfg.ftqInstCountBits.W)
  val retiredInsts        = UInt(cfg.ftqInstCountBits.W)
  val emissionDone        = Bool()
}

/** Control-flow lifetime queue. Cache data and instruction parcels are intentionally not stored here. */
class FetchTargetQueue(cfg: FrontendConfig) extends Module {
  private val depth    = cfg.ftqEntries
  private val ptrWidth = cfg.ftqIndexBits

  require(depth > cfg.latePredictorStages, "FTQ must let the BPU run ahead of fetch")
  require((depth & (depth - 1)) == 0, "FTQ depth must be a power of two")
  require(cfg.ftqSequenceBits > log2Ceil(depth) + 1, "FTQ sequence must disambiguate the live ring")

  val io = IO(new Bundle {
    val reserve      = Flipped(Decoupled(new FtqReserveRequest(cfg)))
    val reserveToken = Output(new FetchToken(cfg))
    val writeFast    = Flipped(Valid(new BpuFastResult(cfg)))
    val writeFinal   = Flipped(Valid(new BpuFinalResult(cfg)))

    val fetchTarget        = Decoupled(new FtqFetchTarget(cfg))
    val fetchComplete      = Flipped(Valid(new FtqFetchComplete(cfg)))
    val blockLookupToken   = Input(new FetchToken(cfg))
    val blockLookup        = Valid(new FtqIfuView(cfg))
    val alignLookupToken   = Input(new FetchToken(cfg))
    val alignLookup        = Valid(new FtqIfuView(cfg))
    val checkerLookupToken = Input(new FetchToken(cfg))
    val checkerLookup      = Valid(new FtqIfuView(cfg))
    val ifuEmission        = Input(Vec(cfg.frontendWidth, Valid(new FtqIfuEmission(cfg))))
    val retire             = Input(Vec(cfg.backendWidth, Valid(new FtqRetire(cfg))))
    val train              = Output(Vec(cfg.backendWidth, Valid(new BpuUpdate(cfg.bpu))))
    val backendLookupTag   = Input(new FetchTargetTag(cfg.payload))
    val backendLookup      = Valid(new FetchToken(cfg))

    val recovery           = Flipped(Valid(new FrontendRecovery(cfg)))
    val bpuRecover         = Valid(new BpuRecover(cfg))
    val recoverySequence   = Valid(UInt(cfg.ftqSequenceBits.W))
    val currentStreamEpoch = Output(UInt(cfg.fetchEpochBits.W))

    val bpuWritePtr = Output(UInt(ptrWidth.W))
    val fetchPtr    = Output(UInt(ptrWidth.W))
    val commitPtr   = Output(UInt(ptrWidth.W))
    val count       = Output(UInt(log2Ceil(depth + 1).W))
    val empty       = Output(Bool())
    val full        = Output(Bool())

    val staleFastDrop     = Output(Bool())
    val staleFinalDrop    = Output(Bool())
    val staleCompleteDrop = Output(Bool())
    val staleIfuDrop      = Output(Bool())
    val staleRetireDrop   = Output(Bool())
  })

  private def ptrNext(ptr: UInt): UInt =
    (ptr + 1.U)(ptrWidth - 1, 0)

  private def tagMatches(tag: FetchTargetTag, entry: FetchTargetEntry): Bool =
    tag.index === entry.token.tag.index && tag.generation === entry.token.tag.generation

  private def tokenMatches(token: FetchToken, entry: FetchTargetEntry): Bool =
    tagMatches(token.tag, entry) && token.streamEpoch === entry.token.streamEpoch

  private def sequenceYounger(candidate: UInt, boundary: UInt): Bool = {
    val delta = candidate - boundary
    delta.orR && !delta(cfg.ftqSequenceBits - 1)
  }

  val entries              = Reg(Vec(depth, new FetchTargetEntry(cfg)))
  val valid                = RegInit(VecInit(Seq.fill(depth)(false.B)))
  val generation           = RegInit(VecInit(Seq.fill(depth)(0.U(cfg.ftqGenerationBits.W))))
  val writePtr             = RegInit(0.U(ptrWidth.W))
  val fetchPtr             = RegInit(0.U(ptrWidth.W))
  val commitPtr            = RegInit(0.U(ptrWidth.W))
  val nextSequence         = RegInit(0.U(cfg.ftqSequenceBits.W))
  val streamEpoch          = RegInit(0.U(cfg.fetchEpochBits.W))
  val priorReserveValid    = RegInit(false.B)
  val priorReserveSequence = Reg(UInt(cfg.ftqSequenceBits.W))
  val priorReserveEpoch    = Reg(UInt(cfg.fetchEpochBits.W))

  val occupancy = PopCount(valid)
  io.bpuWritePtr        := writePtr
  io.fetchPtr           := fetchPtr
  io.commitPtr          := commitPtr
  io.count              := occupancy
  io.empty              := occupancy === 0.U
  io.full               := occupancy === depth.U
  io.currentStreamEpoch := streamEpoch

  private val backendLookupIndex = io.backendLookupTag.index
  io.backendLookup.valid := valid(backendLookupIndex) &&
    tagMatches(io.backendLookupTag, entries(backendLookupIndex))
  io.backendLookup.bits  := entries(backendLookupIndex).token

  for (
    (token, lookup) <- Seq(
                         io.blockLookupToken   -> io.blockLookup,
                         io.alignLookupToken   -> io.alignLookup,
                         io.checkerLookupToken -> io.checkerLookup
                       )
  ) {
    val index = token.tag.index
    val entry = entries(index)
    lookup.valid               := valid(index) && tokenMatches(token, entry)
    lookup.bits.token          := entry.token
    lookup.bits.sequence       := entry.sequence
    lookup.bits.startPc        := entry.startPc
    lookup.bits.blockCount     := entry.blockCount
    lookup.bits.fastNextPc     := entry.fastNextPc
    lookup.bits.finalNextPc    := entry.finalNextPc
    lookup.bits.fastBlockPred  := entry.fastBlockPred
    lookup.bits.fastBlockTaken := entry.fastBlockTaken
    lookup.bits.prediction     := entry.prediction
  }

  io.reserveToken.tag.index      := writePtr
  io.reserveToken.tag.generation := generation(writePtr) +% 1.U
  io.reserveToken.streamEpoch    := streamEpoch
  io.reserve.ready               := !io.recovery.valid && !valid(writePtr)

  val fastIndex  = io.writeFast.bits.token.tag.index
  val fastHit    = valid(fastIndex) && tokenMatches(io.writeFast.bits.token, entries(fastIndex)) &&
    entries(fastIndex).phase === FtqEntryPhase.reserved
  val finalIndex = io.writeFinal.bits.token.tag.index
  val finalPhaseEligible = entries(finalIndex).phase === FtqEntryPhase.fastReady ||
    entries(finalIndex).phase === FtqEntryPhase.fetchIssued ||
    entries(finalIndex).phase === FtqEntryPhase.dataReady
  val finalHit   = valid(finalIndex) && tokenMatches(io.writeFinal.bits.token, entries(finalIndex)) &&
    finalPhaseEligible

  io.staleFastDrop  := io.writeFast.valid && !fastHit
  io.staleFinalDrop := io.writeFinal.valid && !finalHit

  val fetchEntry = entries(fetchPtr)
  io.fetchTarget.valid                  := !io.recovery.valid && valid(fetchPtr) &&
    (fetchEntry.phase === FtqEntryPhase.fastReady || fetchEntry.phase === FtqEntryPhase.finalReady)
  io.fetchTarget.bits.token             := fetchEntry.token
  io.fetchTarget.bits.sequence          := fetchEntry.sequence
  io.fetchTarget.bits.startPc           := fetchEntry.startPc
  io.fetchTarget.bits.blockCount        := fetchEntry.blockCount
  io.fetchTarget.bits.fastNextPc        := fetchEntry.fastNextPc
  io.fetchTarget.bits.finalNextPc       := fetchEntry.finalNextPc
  io.fetchTarget.bits.fastBlockPred     := fetchEntry.fastBlockPred
  io.fetchTarget.bits.fastBlockTaken    := fetchEntry.fastBlockTaken
  io.fetchTarget.bits.prediction        := fetchEntry.prediction
  io.fetchTarget.bits.trainMeta         := fetchEntry.trainMeta
  io.fetchTarget.bits.historyCheckpoint := fetchEntry.historyCheckpoint
  io.fetchTarget.bits.pathCheckpoint    := fetchEntry.pathCheckpoint
  io.fetchTarget.bits.rasCheckpoint     := fetchEntry.rasCheckpoint

  val completeIndex = io.fetchComplete.bits.token.tag.index
  val completeHit   = valid(completeIndex) && tokenMatches(io.fetchComplete.bits.token, entries(completeIndex)) &&
    entries(completeIndex).phase === FtqEntryPhase.fetchIssued
  io.staleCompleteDrop := io.fetchComplete.valid && !completeHit

  val emissionHit      = Wire(Vec(cfg.frontendWidth, Bool()))
  val emissionSequence = Wire(Vec(cfg.frontendWidth, UInt(cfg.ftqSequenceBits.W)))
  for (lane <- 0 until cfg.frontendWidth) {
    val index = io.ifuEmission(lane).bits.token.tag.index
    emissionHit(lane)      := io.ifuEmission(lane).valid && valid(index) &&
      tokenMatches(io.ifuEmission(lane).bits.token, entries(index)) &&
      entries(index).phase >= FtqEntryPhase.dataReady
    emissionSequence(lane) := entries(index).sequence
  }
  io.staleIfuDrop := VecInit((0 until cfg.frontendWidth).map { lane =>
    io.ifuEmission(lane).valid && !emissionHit(lane)
  }).asUInt.orR

  val retireHit = Wire(Vec(cfg.backendWidth, Bool()))
  for (lane <- 0 until cfg.backendWidth) {
    val index = io.retire(lane).bits.tag.index
    retireHit(lane) := io.retire(lane).valid && valid(index) &&
      tagMatches(io.retire(lane).bits.tag, entries(index))
  }
  io.staleRetireDrop := VecInit((0 until cfg.backendWidth).map { lane =>
    io.retire(lane).valid && !retireHit(lane)
  }).asUInt.orR

  val retireCountByEntry = VecInit((0 until depth).map { entry =>
    PopCount(VecInit((0 until cfg.backendWidth).map { lane =>
      retireHit(lane) && io.retire(lane).bits.tag.index === entry.U && io.retire(lane).bits.retired
    }))
  })
  val trapByEntry        = VecInit((0 until depth).map { entry =>
    VecInit((0 until cfg.backendWidth).map { lane =>
      retireHit(lane) && io.retire(lane).bits.tag.index === entry.U && io.retire(lane).bits.trap
    }).asUInt.orR
  })

  for (lane <- 0 until cfg.backendWidth) {
    val retired    = io.retire(lane).bits
    val entry      = entries(retired.tag.index)
    val firstBlock = Cat(entry.startPc(cfg.addrWidth - 1, cfg.icache.offsetBits), 0.U(cfg.icache.offsetBits.W))
    val relativePc = retired.pc - firstBlock
    val pcInEntry  = retired.pc >= firstBlock && relativePc < cfg.fetchGroupBytes.U
    val blockIndex = (relativePc >> cfg.icache.offsetBits)(math.max(log2Ceil(cfg.fetchGroupBlocks), 1) - 1, 0)
    val cfiOffset  = retired.pc(cfg.icache.offsetBits - 1, 1)
    val metaMatch  = VecInit(entry.trainMeta.map { meta =>
      pcInEntry && meta.valid && meta.bits.blockIndex === blockIndex && meta.bits.cfiOffset === cfiOffset
    })

    io.train(lane)                                := 0.U.asTypeOf(io.train(lane))
    io.train(lane).valid                          := retireHit(lane) && retired.retired && retired.cfiValid
    io.train(lane).bits.pc                        := retired.pc
    io.train(lane).bits.cfiType                   := retired.cfiType
    io.train(lane).bits.taken                     := retired.taken
    io.train(lane).bits.target                    := retired.target
    io.train(lane).bits.instLen                   := retired.instLen
    io.train(lane).bits.rasAction                 := retired.rasAction
    io.train(lane).bits.canonicalReturn           := retired.canonicalReturn
    io.train(lane).bits.context.historyCheckpoint := entry.historyCheckpoint
    io.train(lane).bits.context.pathCheckpoint    := entry.pathCheckpoint
    when(metaMatch.asUInt.orR) {
      io.train(lane).bits.context := Mux1H(metaMatch, entry.trainMeta.map(_.bits.context))
    }

    when(io.train(lane).valid) {
      assert(pcInEntry)
      assert(PopCount(metaMatch) <= 1.U)
    }
  }

  val recoveryIndex = io.recovery.bits.token.tag.index
  val recoveryHit   = io.recovery.bits.tokenValid && valid(recoveryIndex) &&
    tagMatches(io.recovery.bits.token.tag, entries(recoveryIndex))
  io.bpuRecover                        := 0.U.asTypeOf(io.bpuRecover)
  io.bpuRecover.valid                  := io.recovery.valid
  io.bpuRecover.bits.recovery          := io.recovery.bits
  io.bpuRecover.bits.checkpointValid   := recoveryHit
  io.bpuRecover.bits.historyCheckpoint := entries(recoveryIndex).historyCheckpoint
  io.bpuRecover.bits.pathCheckpoint    := entries(recoveryIndex).pathCheckpoint
  io.bpuRecover.bits.rasCheckpoint     := entries(recoveryIndex).rasCheckpoint
  io.recoverySequence.valid            := io.recovery.valid && recoveryHit
  io.recoverySequence.bits             := entries(recoveryIndex).sequence

  val headReleasable = valid(commitPtr) && entries(commitPtr).emissionDone &&
    entries(commitPtr).retiredInsts === entries(commitPtr).expectedRetireInsts

  when(io.recovery.valid) {
    priorReserveValid := false.B
    streamEpoch       := streamEpoch +% 1.U

    when(!io.recovery.bits.tokenValid) {
      for (entry <- 0 until depth) {
        valid(entry)         := false.B
        entries(entry).phase := FtqEntryPhase.free
      }
      writePtr := 0.U
      fetchPtr  := 0.U
      commitPtr := 0.U
    }.otherwise {
      assert(recoveryHit)
      val anchorSequence = entries(recoveryIndex).sequence
      val nextAnchor     = ptrNext(recoveryIndex)

      // A late predictor override does not flush cache data. An older request may therefore complete in the same
      // cycle as recovery; preserve that lifecycle transition while recovery removes only the anchor's successors.
      when(
        io.fetchComplete.valid && completeHit && completeIndex =/= recoveryIndex &&
          !sequenceYounger(entries(completeIndex).sequence, anchorSequence)
      ) {
        entries(completeIndex).phase := FtqEntryPhase.dataReady
      }

      for (entry <- 0 until depth) {
        when(valid(entry) && sequenceYounger(entries(entry).sequence, anchorSequence)) {
          valid(entry)         := false.B
          entries(entry).phase := FtqEntryPhase.free
        }
      }

      when(io.recovery.bits.dropTargetEntry) {
        valid(recoveryIndex)         := false.B
        entries(recoveryIndex).phase := FtqEntryPhase.free
        writePtr                     := recoveryIndex
        fetchPtr                     := recoveryIndex
      }.otherwise {
        writePtr := nextAnchor
        when(io.recovery.bits.kind === FrontendRecoveryKind.bpuOverride) {
          assert(io.writeFinal.valid && finalIndex === recoveryIndex && finalHit)
          val anchorWasUnissued = entries(recoveryIndex).phase === FtqEntryPhase.fastReady
          val olderFetchPending = valid(fetchPtr) &&
            sequenceYounger(anchorSequence, entries(fetchPtr).sequence)
          val canReuseIssuedRequest = entries(recoveryIndex).phase =/= FtqEntryPhase.fastReady &&
            io.writeFinal.bits.blockCount <= entries(recoveryIndex).blockCount
          entries(recoveryIndex).finalNextPc       := io.writeFinal.bits.finalNextPc
          entries(recoveryIndex).blockCount        := io.writeFinal.bits.blockCount
          entries(recoveryIndex).prediction        := io.writeFinal.bits.finalPrediction
          entries(recoveryIndex).trainMeta         := io.writeFinal.bits.trainMeta
          when(!canReuseIssuedRequest) {
            entries(recoveryIndex).token.streamEpoch := streamEpoch +% 1.U
            entries(recoveryIndex).phase             := FtqEntryPhase.finalReady
            // A blocked cache can leave an older entry unissued while the BPU reaches this anchor. Keep issuing in
            // sequence order; the refreshed anchor will be reached after that older entry.
            when(!anchorWasUnissued || !olderFetchPending) {
              fetchPtr := recoveryIndex
            }
          }.elsewhen(io.fetchComplete.valid && completeHit && completeIndex === recoveryIndex) {
            entries(recoveryIndex).phase := FtqEntryPhase.dataReady
          }
        }.elsewhen(io.recovery.bits.kind === FrontendRecoveryKind.ifuCorrection) {
          // The correcting instruction group is held at IFU's registered boundary during recovery and is emitted
          // in the next cycle. Keep the anchor live and emission-open so that packet receives normal accounting.
          assert(entries(recoveryIndex).phase >= FtqEntryPhase.dataReady)
          assert(io.recovery.bits.survivingInsts >= entries(recoveryIndex).emittedInsts)
          assert(
            io.recovery.bits.survivingInsts <= entries(recoveryIndex).emittedInsts + cfg.frontendWidth.U
          )
          entries(recoveryIndex).emissionDone := false.B
          fetchPtr                            := nextAnchor
        }.otherwise {
          assert(
            io.recovery.bits.survivingInsts >=
              entries(recoveryIndex).retiredInsts + retireCountByEntry(recoveryIndex)
          )
          assert(io.recovery.bits.survivingInsts <= entries(recoveryIndex).emittedInsts)
          entries(recoveryIndex).expectedRetireInsts := io.recovery.bits.survivingInsts
          entries(recoveryIndex).emissionDone        := true.B
          fetchPtr                                   := nextAnchor
        }
      }
    }
  }.otherwise {
    when(headReleasable) {
      valid(commitPtr)         := false.B
      entries(commitPtr).phase := FtqEntryPhase.free
      commitPtr                := ptrNext(commitPtr)
    }

    when(io.reserve.fire) {
      val token = io.reserveToken
      valid(writePtr)              := true.B
      generation(writePtr)         := token.tag.generation
      entries(writePtr)            := 0.U.asTypeOf(new FetchTargetEntry(cfg))
      entries(writePtr).token      := token
      entries(writePtr).sequence   := nextSequence
      entries(writePtr).phase      := FtqEntryPhase.reserved
      entries(writePtr).startPc    := io.reserve.bits.startPc
      entries(writePtr).blockCount := cfg.fetchGroupBlocks.U
      writePtr                     := ptrNext(writePtr)
      nextSequence                 := nextSequence +% 1.U
      priorReserveValid            := true.B
      priorReserveSequence         := nextSequence
      priorReserveEpoch            := streamEpoch
    }

    when(io.writeFast.valid && fastHit) {
      entries(fastIndex).startPc           := io.writeFast.bits.startPc
      entries(fastIndex).blockCount        := io.writeFast.bits.blockCount
      entries(fastIndex).fastNextPc        := io.writeFast.bits.predictedNextPc
      entries(fastIndex).fastBlockPred     := io.writeFast.bits.blockPred
      entries(fastIndex).fastBlockTaken    := io.writeFast.bits.blockTaken
      entries(fastIndex).historyCheckpoint := io.writeFast.bits.historyCheckpoint
      entries(fastIndex).pathCheckpoint    := io.writeFast.bits.pathCheckpoint
      entries(fastIndex).rasCheckpoint     := io.writeFast.bits.rasCheckpoint
      entries(fastIndex).phase             := FtqEntryPhase.fastReady
    }

    when(io.writeFinal.valid && finalHit) {
      entries(finalIndex).finalNextPc := io.writeFinal.bits.finalNextPc
      entries(finalIndex).blockCount  := io.writeFinal.bits.blockCount
      entries(finalIndex).prediction  := io.writeFinal.bits.finalPrediction
      entries(finalIndex).trainMeta   := io.writeFinal.bits.trainMeta
      when(entries(finalIndex).phase === FtqEntryPhase.fastReady) {
        entries(finalIndex).phase := FtqEntryPhase.finalReady
      }
    }

    when(io.fetchTarget.fire) {
      entries(fetchPtr).phase := FtqEntryPhase.fetchIssued
      fetchPtr                := ptrNext(fetchPtr)
    }

    when(io.fetchComplete.valid && completeHit) {
      entries(completeIndex).phase := FtqEntryPhase.dataReady
    }

    for (entry <- 0 until depth) {
      val emitForEntry     = VecInit((0 until cfg.frontendWidth).map { lane =>
        emissionHit(lane) && io.ifuEmission(lane).bits.token.tag.index === entry.U
      })
      val youngerEmission  = VecInit((0 until cfg.frontendWidth).map { lane =>
        emissionHit(lane) && sequenceYounger(emissionSequence(lane), entries(entry).sequence)
      }).asUInt.orR
      val terminalEmission = VecInit((0 until cfg.frontendWidth).map { lane =>
        emitForEntry(lane) && io.ifuEmission(lane).bits.terminatesEntry
      }).asUInt.orR
      val emitCount        = PopCount(emitForEntry)

      when(valid(entry) && emitCount =/= 0.U) {
        entries(entry).emittedInsts        := entries(entry).emittedInsts + emitCount
        entries(entry).expectedRetireInsts := entries(entry).expectedRetireInsts + emitCount
        entries(entry).phase               := FtqEntryPhase.resident
        for (lane <- 0 until cfg.frontendWidth) {
          val earlier = if (lane == 0) 0.U else PopCount(emitForEntry.take(lane))
          when(emitForEntry(lane)) {
            assert(io.ifuEmission(lane).bits.instOrdinal === entries(entry).emittedInsts + earlier)
          }
        }
      }
      when(valid(entry) && (terminalEmission || youngerEmission)) {
        entries(entry).emissionDone := true.B
      }
    }
  }

  // Retirement is not backpressured by frontend recovery. Account it even when a redirect owns the FTQ control update.
  for (entry <- 0 until depth) {
    when(valid(entry) && retireCountByEntry(entry) =/= 0.U) {
      entries(entry).retiredInsts := entries(entry).retiredInsts + retireCountByEntry(entry)
    }
    when(valid(entry) && trapByEntry(entry)) {
      entries(entry).expectedRetireInsts := entries(entry).retiredInsts + retireCountByEntry(entry)
      entries(entry).emissionDone        := true.B
    }
  }

  assert(occupancy <= depth.U)
  when(io.reserve.fire) {
    assert(!valid(writePtr))
    assert(io.reserveToken.tag.generation =/= generation(writePtr))
    assert(io.reserveToken.streamEpoch === streamEpoch)
    when(priorReserveValid) {
      assert(priorReserveEpoch === streamEpoch)
      assert(nextSequence === priorReserveSequence +% 1.U)
    }
  }
  when(io.fetchTarget.fire) {
    assert(valid(fetchPtr))
    assert(
      entries(fetchPtr).phase === FtqEntryPhase.fastReady ||
        entries(fetchPtr).phase === FtqEntryPhase.finalReady
    )
  }
  when(io.recovery.valid && io.recovery.bits.tokenValid) {
    assert(recoveryHit)
  }
  for (entry <- 0 until depth) {
    when(valid(entry)) {
      assert(entries(entry).retiredInsts <= entries(entry).expectedRetireInsts)
      assert(entries(entry).expectedRetireInsts <= entries(entry).emittedInsts)
      assert(entries(entry).token.tag.index === entry.U)
      assert(entries(entry).token.tag.generation === generation(entry))
    }
  }
}
