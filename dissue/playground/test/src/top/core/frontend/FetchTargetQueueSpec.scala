package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.bundle.CfiType
import top.core.frontend.bundle._
import top.core.frontend.ifetch.FetchTargetQueue

object FetchTargetQueueSpec {
  private val cfg = FrontendConfig(fetchTargetEntries = 4, ftqGenerationBits = 3)
  private case class Token(index: Int, generation: Int, epoch: Int)

  def main(args: Array[String]): Unit = {
    simulate(new FetchTargetQueue(cfg)) { dut =>
      def pokeToken(port: FetchToken, token: Token): Unit = {
        port.tag.index.poke(token.index)
        port.tag.generation.poke(token.generation)
        port.streamEpoch.poke(token.epoch)
      }

      def pokeTag(port: FetchTargetTag, token: Token): Unit = {
        port.index.poke(token.index)
        port.generation.poke(token.generation)
      }

      def idle(): Unit = {
        dut.io.reserve.valid.poke(false)
        dut.io.writeFast.valid.poke(false)
        dut.io.writeFinal.valid.poke(false)
        dut.io.fetchTarget.ready.poke(false)
        dut.io.fetchComplete.valid.poke(false)
        dut.io.recovery.valid.poke(false)
        for (lane <- dut.io.ifuEmission.indices) dut.io.ifuEmission(lane).valid.poke(false)
        dut.io.backendLookupTag.index.poke(0)
        dut.io.backendLookupTag.generation.poke(0)
        for (lane <- dut.io.retire.indices) {
          dut.io.retire(lane).valid.poke(false)
          dut.io.retire(lane).bits.cfiValid.poke(false)
          dut.io.retire(lane).bits.pc.poke(0)
          dut.io.retire(lane).bits.cfiType.poke(CfiType.none)
          dut.io.retire(lane).bits.taken.poke(false)
          dut.io.retire(lane).bits.target.poke(0)
          dut.io.retire(lane).bits.instLen.poke(0)
          dut.io.retire(lane).bits.rasAction.poke(RasAction.none)
          dut.io.retire(lane).bits.canonicalReturn.poke(false)
        }
      }

      def reserve(token: Token, pc: BigInt): Unit = {
        dut.io.reserve.valid.poke(true)
        dut.io.reserve.bits.startPc.poke(pc)
        dut.io.reserve.ready.expect(true)
        dut.io.reserveToken.tag.index.expect(token.index)
        dut.io.reserveToken.tag.generation.expect(token.generation)
        dut.io.reserveToken.streamEpoch.expect(token.epoch)
        dut.clock.step()
        dut.io.reserve.valid.poke(false)
      }

      def fast(token: Token, pc: BigInt, nextPc: BigInt): Unit = {
        dut.io.writeFast.valid.poke(true)
        pokeToken(dut.io.writeFast.bits.token, token)
        dut.io.writeFast.bits.startPc.poke(pc)
        dut.io.writeFast.bits.predictedNextPc.poke(nextPc)
        dut.io.writeFast.bits.blockCount.poke(cfg.fetchGroupBlocks)
        dut.io.writeFast.bits.historyCheckpoint.poke(0x12)
        dut.io.writeFast.bits.pathCheckpoint.poke(0x34)
        dut.io.writeFast.bits.rasCheckpoint.count.poke(0)
        for (entry <- dut.io.writeFast.bits.rasCheckpoint.entries.indices) {
          dut.io.writeFast.bits.rasCheckpoint.entries(entry).poke(0)
        }
        for (block <- 0 until cfg.fetchGroupBlocks) {
          dut.io.writeFast.bits.blockPred(block).valid.poke(false)
          dut.io.writeFast.bits.blockPred(block).cfiOffset.poke(0)
          dut.io.writeFast.bits.blockPred(block).cfiType.poke(CfiType.none)
          dut.io.writeFast.bits.blockPred(block).target.poke(0)
          dut.io.writeFast.bits.blockPred(block).rasAction.poke(RasAction.none)
          dut.io.writeFast.bits.blockTaken(block).poke(false)
        }
        dut.clock.step()
        dut.io.writeFast.valid.poke(false)
      }

      def driveFinal(token: Token, pc: BigInt, nextPc: BigInt, valid: Boolean = true, multiCfi: Boolean = false)
        : Unit = {
        dut.io.writeFinal.valid.poke(valid)
        pokeToken(dut.io.writeFinal.bits.token, token)
        dut.io.writeFinal.bits.startPc.poke(pc)
        dut.io.writeFinal.bits.fastNextPc.poke(nextPc)
        dut.io.writeFinal.bits.finalNextPc.poke(nextPc)
        dut.io.writeFinal.bits.blockCount.poke(cfg.fetchGroupBlocks)
        dut.io.writeFinal.bits.overrideFastPath.poke(false)
        dut.io.writeFinal.bits.finalPrediction.predictedNextPc.poke(nextPc)
        for (block <- 0 until cfg.fetchGroupBlocks) {
          dut.io.writeFinal.bits.finalPrediction.blockPred(block).valid.poke(false)
          dut.io.writeFinal.bits.finalPrediction.blockPred(block).cfiOffset.poke(0)
          dut.io.writeFinal.bits.finalPrediction.blockPred(block).cfiType.poke(CfiType.none)
          dut.io.writeFinal.bits.finalPrediction.blockPred(block).target.poke(0)
          dut.io.writeFinal.bits.finalPrediction.blockPred(block).rasAction.poke(RasAction.none)
        }
        for (slot  <- 0 until cfg.maxConditionalCandidatesPerGroup) {
          val enabled = multiCfi && slot < 2
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).valid.poke(enabled)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.blockIndex.poke(slot % cfg.fetchGroupBlocks)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.cfiOffset.poke(slot)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.taken.poke(slot == 1)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.provider.poke(PredictorProvider.tageBase)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.alternate.poke(PredictorProvider.none)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.confidence.poke(1)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.alternateTaken.poke(false)
          dut.io.writeFinal.bits.trainMeta(slot).valid.poke(enabled)
          dut.io.writeFinal.bits.trainMeta(slot).bits.blockIndex.poke(slot                       % cfg.fetchGroupBlocks)
          dut.io.writeFinal.bits.trainMeta(slot).bits.cfiOffset.poke(slot)
          val context = dut.io.writeFinal.bits.trainMeta(slot).bits.context
          context.provider.poke(PredictorProvider.tageBase)
          context.alternate.poke(PredictorProvider.none)
          context.confidence.poke(1)
          context.providerUseful.poke(0)
          context.allocationMask.poke(0x3f)
          context.predictedTarget.poke(nextPc)
          context.rasUsed.poke(false)
          context.lateQueried.poke(enabled)
          context.lateValid.poke(enabled)
          context.lateTaken.poke(slot == 1)
          context.alternateTaken.poke(false)
          context.lateTarget.poke(nextPc)
          context.alternateTarget.poke(0)
          context.historyCheckpoint.poke(slot + 1)
          context.pathCheckpoint.poke(slot + 3)
        }
        for (slot  <- 0 until cfg.maxIndirectCandidatesPerGroup) {
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).valid.poke(false)
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).bits.blockIndex.poke(0)
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).bits.cfiOffset.poke(0)
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).bits.target.poke(0)
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).bits.provider.poke(PredictorProvider.none)
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).bits.alternate.poke(PredictorProvider.none)
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).bits.confidence.poke(0)
        }
      }

      def finishFinal(token: Token, pc: BigInt, nextPc: BigInt, multiCfi: Boolean = false): Unit = {
        driveFinal(token, pc, nextPc, valid = true, multiCfi)
        dut.clock.step()
        dut.io.writeFinal.valid.poke(false)
      }

      def fetch(token: Token): Unit = {
        dut.io.fetchTarget.valid.expect(true)
        dut.io.fetchTarget.bits.token.tag.index.expect(token.index)
        dut.io.fetchTarget.bits.token.tag.generation.expect(token.generation)
        dut.io.fetchTarget.bits.token.streamEpoch.expect(token.epoch)
        dut.io.fetchTarget.ready.poke(true)
        dut.clock.step()
        dut.io.fetchTarget.ready.poke(false)
      }

      def complete(token: Token): Unit = {
        dut.io.fetchComplete.valid.poke(true)
        pokeToken(dut.io.fetchComplete.bits.token, token)
        dut.clock.step()
        dut.io.fetchComplete.valid.poke(false)
      }

      def emit(token: Token, count: Int, terminal: Boolean): Unit = {
        for (lane <- 0 until cfg.frontendWidth) {
          dut.io.ifuEmission(lane).valid.poke(lane < count)
          pokeToken(dut.io.ifuEmission(lane).bits.token, token)
          dut.io.ifuEmission(lane).bits.instOrdinal.poke(lane)
          dut.io.ifuEmission(lane).bits.terminatesEntry.poke(terminal && lane == count - 1)
        }
        dut.clock.step()
        for (lane <- 0 until cfg.frontendWidth) dut.io.ifuEmission(lane).valid.poke(false)
      }

      def retire(token: Token, ordinal: Int, trap: Boolean = false): Unit = {
        dut.io.retire(0).valid.poke(true)
        pokeTag(dut.io.retire(0).bits.tag, token)
        dut.io.retire(0).bits.instOrdinal.poke(ordinal)
        dut.io.retire(0).bits.retired.poke(!trap)
        dut.io.retire(0).bits.trap.poke(trap)
        dut.clock.step()
        dut.io.retire(0).valid.poke(false)
      }

      def lifecycle(token: Token, pc: BigInt): Unit = {
        reserve(token, pc)
        fast(token, pc, pc + cfg.fetchGroupBytes)
        finishFinal(token, pc, pc + cfg.fetchGroupBytes)
        fetch(token)
        complete(token)
        emit(token, count = 1, terminal = true)
        retire(token, ordinal = 0)
        dut.clock.step()
      }

      idle()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      lifecycle(Token(0, 1, 0), 0x1000)
      lifecycle(Token(1, 1, 0), 0x2000)
      lifecycle(Token(2, 1, 0), 0x3000)
      lifecycle(Token(3, 1, 0), 0x4000)
      dut.io.count.expect(0)

      // Ring reuse changes generation without changing stream epoch.
      reserve(Token(0, 2, 0), 0x5000)
      driveFinal(Token(0, 1, 0), 0x1000, 0x1010)
      dut.io.staleFinalDrop.expect(true)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)

      // A tokenless recovery clears the partial entry; four reserves then exercise full backpressure.
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.reset)
      dut.io.recovery.bits.tokenValid.poke(false)
      dut.io.recovery.bits.targetPc.poke(0x8000)
      dut.clock.step()
      dut.io.recovery.valid.poke(false)
      for (index <- 0 until cfg.ftqEntries) {
        val generation = if (index == 0) 3 else 2
        reserve(Token(index, generation, 1), 0x8000 + index * cfg.fetchGroupBytes)
      }
      dut.io.full.expect(true)
      dut.io.empty.expect(false)

      // A same-generation S3 result from the previous stream cannot finalize the live entry.
      val currentStreamEntry = Token(0, 3, 1)
      fast(currentStreamEntry, 0x8000, 0x8010)
      driveFinal(Token(0, 3, 0), 0x8000, 0x8010)
      dut.io.staleFinalDrop.expect(true)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)

      dut.io.reserve.valid.poke(true)
      dut.io.reserve.bits.startPc.poke(0x9000)
      dut.io.reserve.ready.expect(false)
    }

    simulate(new FetchTargetQueue(cfg)) { dut =>
      def pokeToken(port: FetchToken, token: Token): Unit = {
        port.tag.index.poke(token.index)
        port.tag.generation.poke(token.generation)
        port.streamEpoch.poke(token.epoch)
      }

      def pokeTag(port: FetchTargetTag, token: Token): Unit = {
        port.index.poke(token.index)
        port.generation.poke(token.generation)
      }

      def clearInputs(): Unit = {
        dut.io.reserve.valid.poke(false)
        dut.io.writeFast.valid.poke(false)
        dut.io.writeFinal.valid.poke(false)
        dut.io.fetchTarget.ready.poke(false)
        dut.io.fetchComplete.valid.poke(false)
        dut.io.recovery.valid.poke(false)
        for (lane <- dut.io.ifuEmission.indices) dut.io.ifuEmission(lane).valid.poke(false)
        dut.io.backendLookupTag.index.poke(0)
        dut.io.backendLookupTag.generation.poke(0)
        for (lane <- dut.io.retire.indices) {
          dut.io.retire(lane).valid.poke(false)
          dut.io.retire(lane).bits.cfiValid.poke(false)
          dut.io.retire(lane).bits.pc.poke(0)
          dut.io.retire(lane).bits.cfiType.poke(CfiType.none)
          dut.io.retire(lane).bits.taken.poke(false)
          dut.io.retire(lane).bits.target.poke(0)
          dut.io.retire(lane).bits.instLen.poke(0)
          dut.io.retire(lane).bits.rasAction.poke(RasAction.none)
          dut.io.retire(lane).bits.canonicalReturn.poke(false)
        }
      }

      def reserve(token: Token, pc: BigInt): Unit = {
        dut.io.reserve.valid.poke(true)
        dut.io.reserve.bits.startPc.poke(pc)
        dut.io.reserveToken.tag.index.expect(token.index)
        dut.io.reserveToken.tag.generation.expect(token.generation)
        dut.io.reserveToken.streamEpoch.expect(token.epoch)
        dut.clock.step()
        dut.io.reserve.valid.poke(false)
      }

      def fast(token: Token, pc: BigInt): Unit = {
        dut.io.writeFast.valid.poke(true)
        pokeToken(dut.io.writeFast.bits.token, token)
        dut.io.writeFast.bits.startPc.poke(pc)
        dut.io.writeFast.bits.predictedNextPc.poke(pc + cfg.fetchGroupBytes)
        dut.io.writeFast.bits.blockCount.poke(2)
        dut.io.writeFast.bits.historyCheckpoint.poke(0xaa)
        dut.io.writeFast.bits.pathCheckpoint.poke(0x55)
        dut.io.writeFast.bits.rasCheckpoint.count.poke(0)
        for (entry <- dut.io.writeFast.bits.rasCheckpoint.entries.indices) {
          dut.io.writeFast.bits.rasCheckpoint.entries(entry).poke(0)
        }
        for (block <- 0 until cfg.fetchGroupBlocks) {
          dut.io.writeFast.bits.blockPred(block).valid.poke(false)
          dut.io.writeFast.bits.blockTaken(block).poke(false)
        }
        dut.clock.step()
        dut.io.writeFast.valid.poke(false)
      }

      def finalBits(token: Token, pc: BigInt, multiCfi: Boolean): Unit = {
        dut.io.writeFinal.valid.poke(true)
        pokeToken(dut.io.writeFinal.bits.token, token)
        dut.io.writeFinal.bits.startPc.poke(pc)
        dut.io.writeFinal.bits.fastNextPc.poke(pc + cfg.fetchGroupBytes)
        dut.io.writeFinal.bits.finalNextPc.poke(pc + cfg.fetchGroupBytes)
        dut.io.writeFinal.bits.blockCount.poke(cfg.fetchGroupBlocks)
        dut.io.writeFinal.bits.overrideFastPath.poke(false)
        dut.io.writeFinal.bits.finalPrediction.predictedNextPc.poke(pc + cfg.fetchGroupBytes)
        for (block <- 0 until cfg.fetchGroupBlocks) {
          dut.io.writeFinal.bits.finalPrediction.blockPred(block).valid.poke(false)
        }
        for (slot  <- 0 until cfg.maxConditionalCandidatesPerGroup) {
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).valid.poke(multiCfi)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.blockIndex.poke(slot)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.cfiOffset.poke(slot + 1)
          dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot).bits.taken.poke(slot == 1)
          dut.io.writeFinal.bits.trainMeta(slot).valid.poke(multiCfi)
          dut.io.writeFinal.bits.trainMeta(slot).bits.blockIndex.poke(slot)
          dut.io.writeFinal.bits.trainMeta(slot).bits.cfiOffset.poke(slot + 1)
          val context = dut.io.writeFinal.bits.trainMeta(slot).bits.context
          context.provider.poke(PredictorProvider.tageBase)
          context.alternate.poke(PredictorProvider.none)
          context.confidence.poke(1)
          context.providerUseful.poke(0)
          context.allocationMask.poke(0x3f)
          context.predictedTarget.poke(pc + cfg.fetchGroupBytes)
          context.rasUsed.poke(false)
          context.lateQueried.poke(multiCfi)
          context.lateValid.poke(multiCfi)
          context.lateTaken.poke(slot == 1)
          context.alternateTaken.poke(false)
          context.lateTarget.poke(pc + cfg.fetchGroupBytes)
          context.alternateTarget.poke(0)
          context.historyCheckpoint.poke(slot + 1)
          context.pathCheckpoint.poke(slot + 3)
        }
        for (slot  <- 0 until cfg.maxIndirectCandidatesPerGroup) {
          dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).valid.poke(false)
        }
      }

      clearInputs()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      val anchor  = Token(0, 1, 0)
      val younger = Token(1, 1, 0)
      reserve(anchor, 0x1000)
      fast(anchor, 0x1000)
      finalBits(anchor, 0x1000, multiCfi = true)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)
      dut.io.fetchTarget.valid.expect(true)
      dut.io.fetchTarget.bits.prediction.conditionalPred(0).valid.expect(true)
      dut.io.fetchTarget.bits.prediction.conditionalPred(0).bits.blockIndex.expect(0)
      dut.io.fetchTarget.bits.prediction.conditionalPred(1).valid.expect(true)
      dut.io.fetchTarget.bits.prediction.conditionalPred(1).bits.blockIndex.expect(1)
      dut.io.fetchTarget.ready.poke(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)
      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, anchor)
      dut.clock.step()
      dut.io.fetchComplete.valid.poke(false)
      for (lane <- 0 until 2) {
        dut.io.ifuEmission(lane).valid.poke(true)
        pokeToken(dut.io.ifuEmission(lane).bits.token, anchor)
        dut.io.ifuEmission(lane).bits.instOrdinal.poke(lane)
        dut.io.ifuEmission(lane).bits.terminatesEntry.poke(false)
      }
      dut.clock.step()
      dut.io.ifuEmission(0).valid.poke(false)
      dut.io.ifuEmission(1).valid.poke(false)

      reserve(younger, 0x2000)
      fast(younger, 0x2000)
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.backend)
      dut.io.recovery.bits.tokenValid.poke(true)
      pokeToken(dut.io.recovery.bits.token, anchor)
      dut.io.recovery.bits.targetPc.poke(0x1800)
      dut.io.recovery.bits.survivingInsts.poke(1)
      dut.io.recovery.bits.dropTargetEntry.poke(false)
      dut.io.bpuRecover.valid.expect(true)
      dut.io.bpuRecover.bits.historyCheckpoint.expect(0xaa)
      dut.clock.step()
      dut.io.recovery.valid.poke(false)
      dut.io.count.expect(1)
      dut.io.currentStreamEpoch.expect(1)

      dut.io.retire(0).valid.poke(true)
      pokeTag(dut.io.retire(0).bits.tag, anchor)
      dut.io.retire(0).bits.instOrdinal.poke(0)
      dut.io.retire(0).bits.retired.poke(true)
      dut.io.retire(0).bits.trap.poke(false)
      dut.clock.step()
      dut.io.retire(0).valid.poke(false)
      dut.clock.step()
      dut.io.count.expect(0)

      // Reusing the younger slot rejects its old generation's S3 update.
      val reused = Token(1, 2, 1)
      reserve(reused, 0x3000)
      finalBits(younger, 0x2000, multiCfi = false)
      dut.io.staleFinalDrop.expect(true)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)

      // S3 finalization and BPU override recovery are atomic: the anchor survives with a refreshed data epoch.
      fast(reused, 0x3000)
      finalBits(reused, 0x3000, multiCfi = false)
      dut.io.writeFinal.bits.finalNextPc.poke(0x3800)
      dut.io.writeFinal.bits.overrideFastPath.poke(true)
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.bpuOverride)
      dut.io.recovery.bits.tokenValid.poke(true)
      pokeToken(dut.io.recovery.bits.token, reused)
      dut.io.recovery.bits.targetPc.poke(0x3800)
      dut.io.recovery.bits.dropTargetEntry.poke(false)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)
      dut.io.recovery.valid.poke(false)
      dut.io.fetchTarget.valid.expect(true)
      dut.io.fetchTarget.bits.token.tag.index.expect(reused.index)
      dut.io.fetchTarget.bits.token.tag.generation.expect(reused.generation)
      dut.io.fetchTarget.bits.token.streamEpoch.expect(2)
      dut.io.fetchTarget.bits.finalNextPc.expect(0x3800)

      // A trap can terminate an entry without a normal retire and cannot leak the slot.
      val refreshed = Token(reused.index, reused.generation, 2)
      dut.io.fetchTarget.ready.poke(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)
      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, refreshed)
      dut.clock.step()
      dut.io.fetchComplete.valid.poke(false)
      dut.io.ifuEmission(0).valid.poke(true)
      pokeToken(dut.io.ifuEmission(0).bits.token, refreshed)
      dut.io.ifuEmission(0).bits.instOrdinal.poke(0)
      dut.io.ifuEmission(0).bits.terminatesEntry.poke(true)
      dut.clock.step()
      dut.io.ifuEmission(0).valid.poke(false)
      dut.io.retire(0).valid.poke(true)
      pokeTag(dut.io.retire(0).bits.tag, refreshed)
      dut.io.retire(0).bits.instOrdinal.poke(0)
      dut.io.retire(0).bits.retired.poke(false)
      dut.io.retire(0).bits.trap.poke(true)
      dut.clock.step()
      dut.io.retire(0).valid.poke(false)
      dut.clock.step()
      dut.io.count.expect(0)

      // Reserve, S3 finalize, and retire may update three different entries in the same cycle.
      val retiringEntry   = Token(2, 1, 2)
      val finalizingEntry = Token(3, 1, 2)
      val reservingEntry  = Token(0, 2, 2)
      reserve(retiringEntry, 0x4000)
      fast(retiringEntry, 0x4000)
      finalBits(retiringEntry, 0x4000, multiCfi = false)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)
      dut.io.fetchTarget.ready.poke(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)
      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, retiringEntry)
      dut.clock.step()
      dut.io.fetchComplete.valid.poke(false)
      dut.io.ifuEmission(0).valid.poke(true)
      pokeToken(dut.io.ifuEmission(0).bits.token, retiringEntry)
      dut.io.ifuEmission(0).bits.instOrdinal.poke(0)
      dut.io.ifuEmission(0).bits.terminatesEntry.poke(true)
      dut.clock.step()
      dut.io.ifuEmission(0).valid.poke(false)

      reserve(finalizingEntry, 0x5000)
      fast(finalizingEntry, 0x5000)
      dut.io.retire(0).valid.poke(true)
      pokeTag(dut.io.retire(0).bits.tag, retiringEntry)
      dut.io.retire(0).bits.instOrdinal.poke(0)
      dut.io.retire(0).bits.retired.poke(true)
      dut.io.retire(0).bits.trap.poke(false)
      finalBits(finalizingEntry, 0x5000, multiCfi = false)
      dut.io.reserve.valid.poke(true)
      dut.io.reserve.bits.startPc.poke(0x6000)
      dut.io.reserveToken.tag.index.expect(reservingEntry.index)
      dut.io.reserveToken.tag.generation.expect(reservingEntry.generation)
      dut.io.reserveToken.streamEpoch.expect(reservingEntry.epoch)
      dut.clock.step()
      dut.io.retire(0).valid.poke(false)
      dut.io.writeFinal.valid.poke(false)
      dut.io.reserve.valid.poke(false)
      dut.clock.step()
      dut.io.count.expect(2)

      // A younger S3 override must not suppress the backend's unbackpressured retirement of an older entry.
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.reset)
      dut.io.recovery.bits.tokenValid.poke(false)
      dut.io.recovery.bits.targetPc.poke(0x7000)
      dut.clock.step()
      clearInputs()
      dut.io.count.expect(0)
      dut.io.currentStreamEpoch.expect(3)

      val olderThanOverride = Token(0, 3, 3)
      val overrideAnchor    = Token(1, 3, 3)
      reserve(olderThanOverride, 0x7000)
      fast(olderThanOverride, 0x7000)
      finalBits(olderThanOverride, 0x7000, multiCfi = false)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)
      dut.io.fetchTarget.ready.poke(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)
      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, olderThanOverride)
      dut.clock.step()
      dut.io.fetchComplete.valid.poke(false)
      for (lane <- dut.io.ifuEmission.indices) {
        dut.io.ifuEmission(lane).valid.poke(lane < 2)
        pokeToken(dut.io.ifuEmission(lane).bits.token, olderThanOverride)
        dut.io.ifuEmission(lane).bits.instOrdinal.poke(lane)
        dut.io.ifuEmission(lane).bits.terminatesEntry.poke(lane == 1)
      }
      dut.clock.step()
      for (lane <- dut.io.ifuEmission.indices) dut.io.ifuEmission(lane).valid.poke(false)

      reserve(overrideAnchor, 0x8000)
      fast(overrideAnchor, 0x8000)
      finalBits(overrideAnchor, 0x8000, multiCfi = false)
      dut.io.writeFinal.bits.overrideFastPath.poke(true)
      dut.io.writeFinal.bits.finalNextPc.poke(0x8800)
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.bpuOverride)
      dut.io.recovery.bits.tokenValid.poke(true)
      pokeToken(dut.io.recovery.bits.token, overrideAnchor)
      dut.io.recovery.bits.targetPc.poke(0x8800)
      dut.io.recovery.bits.dropTargetEntry.poke(false)
      for (lane <- dut.io.retire.indices) {
        dut.io.retire(lane).valid.poke(true)
        pokeTag(dut.io.retire(lane).bits.tag, olderThanOverride)
        dut.io.retire(lane).bits.instOrdinal.poke(lane)
        dut.io.retire(lane).bits.retired.poke(true)
        dut.io.retire(lane).bits.trap.poke(false)
      }
      dut.clock.step()
      clearInputs()
      dut.clock.step()
      dut.io.count.expect(1)
      dut.io.fetchTarget.valid.expect(true)
      dut.io.fetchTarget.bits.token.tag.index.expect(overrideAnchor.index)
      dut.io.fetchTarget.bits.token.tag.generation.expect(overrideAnchor.generation)
      dut.io.fetchTarget.bits.token.streamEpoch.expect(4)

      // An older cache completion that overlaps a younger S3 override remains eligible for IFU emission.
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.reset)
      dut.io.recovery.bits.tokenValid.poke(false)
      dut.io.recovery.bits.targetPc.poke(0x9000)
      dut.clock.step()
      clearInputs()

      val completingOlder  = Token(0, 4, 5)
      val completingAnchor = Token(1, 4, 5)
      reserve(completingOlder, 0x9000)
      fast(completingOlder, 0x9000)
      finalBits(completingOlder, 0x9000, multiCfi = false)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)
      dut.io.fetchTarget.ready.poke(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)

      reserve(completingAnchor, 0xa000)
      fast(completingAnchor, 0xa000)
      finalBits(completingAnchor, 0xa000, multiCfi = false)
      dut.io.writeFinal.bits.overrideFastPath.poke(true)
      dut.io.writeFinal.bits.finalNextPc.poke(0xa800)
      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, completingOlder)
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.bpuOverride)
      dut.io.recovery.bits.tokenValid.poke(true)
      pokeToken(dut.io.recovery.bits.token, completingAnchor)
      dut.io.recovery.bits.targetPc.poke(0xa800)
      dut.io.recovery.bits.dropTargetEntry.poke(false)
      dut.io.staleCompleteDrop.expect(false)
      dut.clock.step()
      clearInputs()

      dut.io.ifuEmission(0).valid.poke(true)
      pokeToken(dut.io.ifuEmission(0).bits.token, completingOlder)
      dut.io.ifuEmission(0).bits.instOrdinal.poke(0)
      dut.io.ifuEmission(0).bits.terminatesEntry.poke(true)
      dut.io.staleIfuDrop.expect(false)
      dut.clock.step()
      dut.io.ifuEmission(0).valid.poke(false)
      dut.io.retire(0).valid.poke(true)
      pokeTag(dut.io.retire(0).bits.tag, completingOlder)
      dut.io.retire(0).bits.instOrdinal.poke(0)
      dut.io.retire(0).bits.retired.poke(true)
      dut.io.retire(0).bits.trap.poke(false)
      dut.clock.step()
      dut.io.retire(0).valid.poke(false)
      dut.clock.step()
      dut.io.count.expect(1)
      dut.io.fetchTarget.valid.expect(true)
      dut.io.fetchTarget.bits.token.tag.index.expect(completingAnchor.index)
      dut.io.fetchTarget.bits.token.tag.generation.expect(completingAnchor.generation)
      dut.io.fetchTarget.bits.token.streamEpoch.expect(6)

      // IFU correction holds its not-yet-emitted packet across recovery. The anchor remains emission-open, and
      // normal accounting completes when that packet arrives in the following cycle.
      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.reset)
      dut.io.recovery.bits.tokenValid.poke(false)
      dut.io.recovery.bits.targetPc.poke(0xb000)
      dut.clock.step()
      clearInputs()

      val correctionAnchor = Token(0, 5, 7)
      reserve(correctionAnchor, 0xb000)
      fast(correctionAnchor, 0xb000)
      finalBits(correctionAnchor, 0xb000, multiCfi = false)
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)
      dut.io.fetchTarget.ready.poke(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)
      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, correctionAnchor)
      dut.clock.step()
      dut.io.fetchComplete.valid.poke(false)

      for (lane <- 0 until 2) {
        dut.io.ifuEmission(lane).valid.poke(true)
        pokeToken(dut.io.ifuEmission(lane).bits.token, correctionAnchor)
        dut.io.ifuEmission(lane).bits.instOrdinal.poke(lane)
        dut.io.ifuEmission(lane).bits.terminatesEntry.poke(false)
      }
      dut.clock.step()
      for (lane <- dut.io.ifuEmission.indices) dut.io.ifuEmission(lane).valid.poke(false)

      dut.io.recovery.valid.poke(true)
      dut.io.recovery.bits.kind.poke(FrontendRecoveryKind.ifuCorrection)
      dut.io.recovery.bits.tokenValid.poke(true)
      pokeToken(dut.io.recovery.bits.token, correctionAnchor)
      dut.io.recovery.bits.targetPc.poke(0xb100)
      dut.io.recovery.bits.survivingInsts.poke(4)
      dut.io.recovery.bits.dropTargetEntry.poke(false)
      dut.clock.step()
      clearInputs()
      dut.io.count.expect(1)
      dut.io.currentStreamEpoch.expect(8)

      for (lane <- 0 until 2) {
        dut.io.ifuEmission(lane).valid.poke(true)
        pokeToken(dut.io.ifuEmission(lane).bits.token, correctionAnchor)
        dut.io.ifuEmission(lane).bits.instOrdinal.poke(lane + 2)
        dut.io.ifuEmission(lane).bits.terminatesEntry.poke(lane == 1)
      }
      dut.io.staleIfuDrop.expect(false)
      dut.clock.step()
      for (lane <- dut.io.ifuEmission.indices) dut.io.ifuEmission(lane).valid.poke(false)

      for (base <- Seq(0, 2)) {
        for (lane <- dut.io.retire.indices) {
          dut.io.retire(lane).valid.poke(true)
          pokeTag(dut.io.retire(lane).bits.tag, correctionAnchor)
          dut.io.retire(lane).bits.instOrdinal.poke(base + lane)
          dut.io.retire(lane).bits.retired.poke(true)
          dut.io.retire(lane).bits.trap.poke(false)
        }
        dut.clock.step()
        for (lane <- dut.io.retire.indices) dut.io.retire(lane).valid.poke(false)
      }
      dut.clock.step()
      dut.io.count.expect(0)
    }

    println("FetchTargetQueueSpec: PASS")
  }
}
