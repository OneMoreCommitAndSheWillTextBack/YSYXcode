package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.bundle.CfiType
import top.core.frontend.Bpu.Bpu
import top.core.frontend.bundle.{FrontendRecoveryKind, PredictorConstants, PredictorProvider, RasAction}

object BpuPipelineSpec {
  private val cfg = FrontendConfig(fetchTargetEntries = 8)

  private def initialize(dut: Bpu): Unit = {
    dut.io.req.valid.poke(false)
    dut.io.recover.valid.poke(false)
    for (lane <- dut.io.train.indices) {
      dut.io.train(lane).valid.poke(false)
    }
    dut.reset.poke(true)
    dut.clock.step(2)
    dut.reset.poke(false)
  }

  private def train(
    dut:         Bpu,
    pc:          BigInt,
    cfiType:     BigInt,
    taken:       Boolean,
    target:      BigInt,
    lateQueried: Boolean = false,
    lateValid:   Boolean = false,
    lateTaken:   Boolean = false,
    lateTarget:  BigInt = 0,
    provider:    BigInt = 0
  ): Unit = {
    dut.io.train(0).valid.poke(true)
    dut.io.train(0).bits.pc.poke(pc)
    dut.io.train(0).bits.cfiType.poke(cfiType)
    dut.io.train(0).bits.taken.poke(taken)
    dut.io.train(0).bits.target.poke(target)
    dut.io.train(0).bits.instLen.poke(4)
    dut.io.train(0).bits.rasAction.poke(RasAction.none.litValue)
    dut.io.train(0).bits.canonicalReturn.poke(false)
    dut.io.train(0).bits.context.provider.poke(provider)
    dut.io.train(0).bits.context.alternate.poke(PredictorProvider.none.litValue)
    dut.io.train(0).bits.context.confidence.poke(0)
    dut.io.train(0).bits.context.providerUseful.poke(0)
    dut.io.train(0).bits.context.allocationMask.poke((1 << PredictorConstants.maxTaggedTables) - 1)
    dut.io.train(0).bits.context.predictedTarget.poke(target)
    dut.io.train(0).bits.context.rasUsed.poke(false)
    dut.io.train(0).bits.context.lateQueried.poke(lateQueried)
    dut.io.train(0).bits.context.lateValid.poke(lateValid)
    dut.io.train(0).bits.context.lateTaken.poke(lateTaken)
    dut.io.train(0).bits.context.alternateTaken.poke(false)
    dut.io.train(0).bits.context.lateTarget.poke(lateTarget)
    dut.io.train(0).bits.context.alternateTarget.poke(0)
    dut.io.train(0).bits.context.pathCheckpoint.poke(0)
    dut.io.train(0).bits.context.historyCheckpoint.poke(0)
    dut.clock.step()
    dut.io.train(0).valid.poke(false)
  }

  private def request(dut: Bpu, token: Int, pc: BigInt): Unit = {
    dut.io.req.valid.poke(true)
    dut.io.req.bits.token.tag.index.poke(token % cfg.ftqEntries)
    dut.io.req.bits.token.tag.generation.poke(token / cfg.ftqEntries + 1)
    dut.io.req.bits.token.streamEpoch.poke(0)
    dut.io.req.bits.startPc.poke(pc)
    dut.io.req.ready.expect(true)
    dut.clock.step()
    dut.io.req.valid.poke(false)
  }

  private def expectFinal(
    dut:             Bpu,
    tokenIndex:      Int,
    fastNpc:         BigInt,
    finalNpc:        BigInt,
    finalBlockCount: Int,
    overridePath:    Boolean
  ): Unit = {
    dut.io.fastResult.valid.expect(true)
    dut.io.fastResult.bits.token.tag.index.expect(tokenIndex)
    dut.io.fastResult.bits.predictedNextPc.expect(fastNpc)
    dut.io.finalResult.valid.expect(false)
    dut.clock.step()
    dut.io.finalResult.valid.expect(false)
    dut.clock.step()
    dut.io.finalResult.valid.expect(true)
    dut.io.finalResult.bits.token.tag.index.expect(tokenIndex)
    dut.io.finalResult.bits.fastNextPc.expect(fastNpc)
    dut.io.finalResult.bits.finalNextPc.expect(finalNpc)
    dut.io.finalResult.bits.blockCount.expect(finalBlockCount)
    dut.io.finalResult.bits.overrideFastPath.expect(overridePath)
    dut.clock.step()
  }

  def main(args: Array[String]): Unit = {
    simulate(new Bpu(cfg)) { dut =>
      initialize(dut)

      // BTB miss: S1 selects the two-block sequential target and S3 preserves it.
      request(dut, token = 0, pc = 0x8000)
      dut.io.fastResult.bits.blockPred(0).valid.expect(false)
      dut.io.fastResult.bits.blockPred(1).valid.expect(false)
      expectFinal(dut, tokenIndex = 0, fastNpc = 0x8010, finalNpc = 0x8010, finalBlockCount = 2, overridePath = false)

      // A block-0 conditional prediction fetches one block and immediately drives the target PC.
      train(dut, pc = 0x1000, cfiType = CfiType.branch.litValue, taken = true, target = 0x2000)
      request(dut, token = 1, pc = 0x1000)
      dut.io.fastResult.bits.blockTaken(0).expect(true)
      dut.io.fastResult.bits.blockCount.expect(1)
      expectFinal(dut, tokenIndex = 1, fastNpc = 0x2000, finalNpc = 0x2000, finalBlockCount = 1, overridePath = false)

      // A block-1 prediction is considered only after block 0 falls through.
      train(dut, pc = 0x3008, cfiType = CfiType.branch.litValue, taken = true, target = 0x3800)
      request(dut, token = 2, pc = 0x3000)
      dut.io.fastResult.bits.blockTaken(0).expect(false)
      dut.io.fastResult.bits.blockTaken(1).expect(true)
      dut.io.fastResult.bits.blockCount.expect(2)
      expectFinal(dut, tokenIndex = 2, fastNpc = 0x3800, finalNpc = 0x3800, finalBlockCount = 2, overridePath = false)

      // Both BTB entries remain resident while their BHT counters move to not-taken.
      train(dut, pc = 0x4000, cfiType = CfiType.branch.litValue, taken = true, target = 0x5000)
      train(dut, pc = 0x4000, cfiType = CfiType.branch.litValue, taken = false, target = 0x4004)
      train(dut, pc = 0x4000, cfiType = CfiType.branch.litValue, taken = false, target = 0x4004)
      train(dut, pc = 0x4008, cfiType = CfiType.branch.litValue, taken = true, target = 0x6000)
      train(dut, pc = 0x4008, cfiType = CfiType.branch.litValue, taken = false, target = 0x400c)
      train(dut, pc = 0x4008, cfiType = CfiType.branch.litValue, taken = false, target = 0x400c)
      request(dut, token = 3, pc = 0x4000)
      dut.io.fastResult.bits.blockTaken(0).expect(false)
      dut.io.fastResult.bits.blockTaken(1).expect(false)
      expectFinal(dut, tokenIndex = 3, fastNpc = 0x4010, finalNpc = 0x4010, finalBlockCount = 2, overridePath = false)
    }

    simulate(new Bpu(cfg)) { dut =>
      initialize(dut)

      // Allocate a not-taken tagged entry, then restore only the fast BHT to taken. S3 must overturn the fast result.
      train(dut, pc = 0x1000, cfiType = CfiType.branch.litValue, taken = true, target = 0x2000)
      train(
        dut,
        pc = 0x1000,
        cfiType = CfiType.branch.litValue,
        taken = false,
        target = 0x1004,
        lateQueried = true,
        lateValid = true,
        lateTaken = true,
        provider = PredictorProvider.tageBase.litValue
      )
      train(dut, pc = 0x1000, cfiType = CfiType.branch.litValue, taken = true, target = 0x2000)
      request(dut, token = 0, pc = 0x1000)
      dut.io.fastResult.bits.blockTaken(0).expect(true)
      expectFinal(dut, tokenIndex = 0, fastNpc = 0x2000, finalNpc = 0x1010, finalBlockCount = 2, overridePath = true)
    }

    simulate(new Bpu(cfg)) { dut =>
      initialize(dut)

      // Allocate an ITTAGE target B, then restore only the fast BTB target A. S3 must select B.
      train(
        dut,
        pc = 0x6000,
        cfiType = CfiType.jalr.litValue,
        taken = true,
        target = 0x7000,
        lateQueried = true,
        lateValid = false,
        provider = PredictorProvider.ittageBase.litValue
      )
      train(dut, pc = 0x6000, cfiType = CfiType.jalr.litValue, taken = true, target = 0x6800)
      request(dut, token = 0, pc = 0x6000)
      dut.io.fastResult.bits.predictedNextPc.expect(0x6800)
      expectFinal(dut, tokenIndex = 0, fastNpc = 0x6800, finalNpc = 0x7000, finalBlockCount = 1, overridePath = true)
    }

    println("BpuPipelineSpec: PASS")
  }
}
