package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.bundle.CfiType
import top.core.frontend.bundle._
import top.core.frontend.ifetch.FetchTargetQueue

object FtqTrainingSpec {
  private val cfg = FrontendConfig(fetchTargetEntries = 4, ftqGenerationBits = 3)

  def main(args: Array[String]): Unit = {
    simulate(new FetchTargetQueue(cfg)) { dut =>
      def pokeToken(port: FetchToken, index: Int, generation: Int, epoch: Int): Unit = {
        port.tag.index.poke(index)
        port.tag.generation.poke(generation)
        port.streamEpoch.poke(epoch)
      }

      def pokeRetireTag(index: Int, generation: Int): Unit = {
        dut.io.retire(0).bits.tag.index.poke(index)
        dut.io.retire(0).bits.tag.generation.poke(generation)
      }

      dut.io.reserve.valid.poke(false)
      dut.io.writeFast.valid.poke(false)
      dut.io.writeFinal.valid.poke(false)
      dut.io.fetchTarget.ready.poke(false)
      dut.io.fetchComplete.valid.poke(false)
      dut.io.recovery.valid.poke(false)
      dut.io.backendLookupTag.index.poke(0)
      dut.io.backendLookupTag.generation.poke(0)
      for (lookup <- Seq(dut.io.blockLookupToken, dut.io.alignLookupToken, dut.io.checkerLookupToken)) {
        pokeToken(lookup, 0, 0, 0)
      }
      for (lane   <- dut.io.ifuEmission.indices) dut.io.ifuEmission(lane).valid.poke(false)
      for (lane   <- dut.io.retire.indices) dut.io.retire(lane).valid.poke(false)

      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      val startPc = BigInt(0x1002)
      dut.io.reserve.valid.poke(true)
      dut.io.reserve.bits.startPc.poke(startPc)
      dut.io.reserve.ready.expect(true)
      dut.io.reserveToken.tag.index.expect(0)
      dut.io.reserveToken.tag.generation.expect(1)
      dut.clock.step()
      dut.io.reserve.valid.poke(false)

      dut.io.writeFast.valid.poke(true)
      pokeToken(dut.io.writeFast.bits.token, 0, 1, 0)
      dut.io.writeFast.bits.startPc.poke(startPc)
      dut.io.writeFast.bits.predictedNextPc.poke(0x2000)
      dut.io.writeFast.bits.blockCount.poke(cfg.fetchGroupBlocks)
      dut.io.writeFast.bits.historyCheckpoint.poke(0x12)
      dut.io.writeFast.bits.pathCheckpoint.poke(0x34)
      dut.io.writeFast.bits.rasCheckpoint.count.poke(0)
      for (entry <- dut.io.writeFast.bits.rasCheckpoint.entries.indices) {
        dut.io.writeFast.bits.rasCheckpoint.entries(entry).poke(0)
      }
      for (block <- 0 until cfg.fetchGroupBlocks) {
        val meta = dut.io.writeFast.bits.blockPred(block)
        meta.valid.poke(block == 0)
        meta.cfiOffset.poke(if (block == 0) 1 else 0)
        meta.cfiType.poke(if (block == 0) CfiType.branch.litValue else CfiType.none.litValue)
        meta.target.poke(if (block == 0) 0x2000 else 0)
        meta.rasAction.poke(RasAction.none)
        dut.io.writeFast.bits.blockTaken(block).poke(block == 0)
      }
      dut.clock.step()
      dut.io.writeFast.valid.poke(false)

      dut.io.writeFinal.valid.poke(true)
      pokeToken(dut.io.writeFinal.bits.token, 0, 1, 0)
      dut.io.writeFinal.bits.startPc.poke(startPc)
      dut.io.writeFinal.bits.fastNextPc.poke(0x2000)
      dut.io.writeFinal.bits.finalNextPc.poke(0x2000)
      dut.io.writeFinal.bits.blockCount.poke(1)
      dut.io.writeFinal.bits.overrideFastPath.poke(false)
      dut.io.writeFinal.bits.finalPrediction.predictedNextPc.poke(0x2000)
      for (block <- 0 until cfg.fetchGroupBlocks) {
        val meta = dut.io.writeFinal.bits.finalPrediction.blockPred(block)
        meta.valid.poke(block == 0)
        meta.cfiOffset.poke(if (block == 0) 1 else 0)
        meta.cfiType.poke(if (block == 0) CfiType.branch.litValue else CfiType.none.litValue)
        meta.target.poke(if (block == 0) 0x2000 else 0)
        meta.rasAction.poke(RasAction.none)

        val train = dut.io.writeFinal.bits.trainMeta(block)
        train.valid.poke(true)
        train.bits.blockIndex.poke(block)
        train.bits.cfiOffset.poke(if (block == 0) 1 else 2)
        train.bits.context.provider
          .poke(if (block == 0) PredictorProvider.tageTable(0).litValue else PredictorProvider.fastBtb.litValue)
        train.bits.context.alternate.poke(PredictorProvider.tageBase)
        train.bits.context.confidence.poke(block + 1)
        train.bits.context.providerUseful.poke(block)
        train.bits.context.allocationMask.poke(if (block == 0) 0x15 else 0x2a)
        train.bits.context.predictedTarget.poke(if (block == 0) 0x2000 else 0x3000)
        train.bits.context.rasUsed.poke(false)
        train.bits.context.lateQueried.poke(block == 0)
        train.bits.context.lateValid.poke(block == 0)
        train.bits.context.lateTaken.poke(block == 0)
        train.bits.context.alternateTaken.poke(false)
        train.bits.context.lateTarget.poke(if (block == 0) 0x2000 else 0)
        train.bits.context.alternateTarget.poke(0)
        train.bits.context.historyCheckpoint.poke(if (block == 0) 0x55 else 0x66)
        train.bits.context.pathCheckpoint.poke(if (block == 0) 0x77 else 0x88)
      }
      for (slot  <- 0 until cfg.maxConditionalCandidatesPerGroup) {
        val candidate = dut.io.writeFinal.bits.finalPrediction.conditionalPred(slot)
        candidate.valid.poke(slot == 0)
        candidate.bits.blockIndex.poke(0)
        candidate.bits.cfiOffset.poke(1)
        candidate.bits.taken.poke(true)
        candidate.bits.provider.poke(PredictorProvider.tageTable(0))
        candidate.bits.alternate.poke(PredictorProvider.tageBase)
        candidate.bits.confidence.poke(2)
        candidate.bits.alternateTaken.poke(false)
      }
      for (slot  <- 0 until cfg.maxIndirectCandidatesPerGroup) {
        dut.io.writeFinal.bits.finalPrediction.indirectPred(slot).valid.poke(false)
      }
      dut.clock.step()
      dut.io.writeFinal.valid.poke(false)

      dut.io.fetchTarget.ready.poke(true)
      dut.io.fetchTarget.valid.expect(true)
      dut.clock.step()
      dut.io.fetchTarget.ready.poke(false)

      dut.io.fetchComplete.valid.poke(true)
      pokeToken(dut.io.fetchComplete.bits.token, 0, 1, 0)
      dut.clock.step()
      dut.io.fetchComplete.valid.poke(false)

      dut.io.ifuEmission(0).valid.poke(true)
      pokeToken(dut.io.ifuEmission(0).bits.token, 0, 1, 0)
      dut.io.ifuEmission(0).bits.instOrdinal.poke(0)
      dut.io.ifuEmission(0).bits.terminatesEntry.poke(true)
      dut.clock.step()
      dut.io.ifuEmission(0).valid.poke(false)

      dut.io.backendLookupTag.index.poke(0)
      dut.io.backendLookupTag.generation.poke(1)
      dut.io.backendLookup.valid.expect(true)
      dut.io.backendLookup.bits.streamEpoch.expect(0)
      dut.io.backendLookupTag.generation.poke(2)
      dut.io.backendLookup.valid.expect(false)

      dut.io.retire(0).valid.poke(true)
      pokeRetireTag(0, 2)
      dut.io.retire(0).bits.instOrdinal.poke(0)
      dut.io.retire(0).bits.retired.poke(true)
      dut.io.retire(0).bits.trap.poke(false)
      dut.io.retire(0).bits.cfiValid.poke(true)
      dut.io.retire(0).bits.pc.poke(startPc)
      dut.io.retire(0).bits.cfiType.poke(CfiType.branch)
      dut.io.retire(0).bits.taken.poke(true)
      dut.io.retire(0).bits.target.poke(0x2000)
      dut.io.retire(0).bits.instLen.poke(2)
      dut.io.retire(0).bits.rasAction.poke(RasAction.none)
      dut.io.retire(0).bits.canonicalReturn.poke(false)
      dut.io.staleRetireDrop.expect(true)
      dut.io.train(0).valid.expect(false)
      dut.clock.step()

      pokeRetireTag(0, 1)
      dut.io.staleRetireDrop.expect(false)
      dut.io.train(0).valid.expect(true)
      dut.io.train(0).bits.pc.expect(startPc)
      dut.io.train(0).bits.cfiType.expect(CfiType.branch)
      dut.io.train(0).bits.context.provider.expect(PredictorProvider.tageTable(0))
      dut.io.train(0).bits.context.providerUseful.expect(0)
      dut.io.train(0).bits.context.allocationMask.expect(0x15)
      dut.io.train(0).bits.context.historyCheckpoint.expect(0x55)
      dut.io.train(0).bits.context.pathCheckpoint.expect(0x77)
      dut.io.train(0).bits.context.predictedTarget.expect(0x2000)
      dut.clock.step()
      dut.io.retire(0).valid.poke(false)
      dut.clock.step()
      dut.io.count.expect(0)
    }

    println("FtqTrainingSpec: PASS")
  }
}
