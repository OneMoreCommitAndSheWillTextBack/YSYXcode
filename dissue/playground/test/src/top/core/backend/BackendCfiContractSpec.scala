package top.core.backend

import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.bundle.CfiType
import top.core.frontend.bundle.RasAction

object BackendCfiContractSpec {
  private val cfg = BackendConfig()

  def main(args: Array[String]): Unit = {
    simulate(new RecoveryUnit(cfg)) { dut =>
      dut.io.robHead.poke(0)
      for (port <- dut.io.resolve.indices) {
        dut.io.resolve(port).valid.poke(false)
      }

      def resolve(
        port:       Int,
        robIdx:     Int,
        tagIndex:   Int,
        generation: Int,
        ordinal:    Int,
        pc:         BigInt,
        target:     BigInt
      ): Unit = {
        val event = dut.io.resolve(port)
        event.valid.poke(true)
        event.bits.robIdx.poke(robIdx)
        event.bits.pc.poke(pc)
        event.bits.cfiType.poke(CfiType.branch)
        event.bits.predNpc.poke(pc + 4)
        event.bits.actualNpc.poke(target)
        event.bits.taken.poke(true)
        event.bits.branchTarget.poke(target)
        event.bits.instLen.poke(4)
        event.bits.ftqTag.index.poke(tagIndex)
        event.bits.ftqTag.generation.poke(generation)
        event.bits.ftqInstOrdinal.poke(ordinal)
        event.bits.rasAction.poke(RasAction.none)
        event.bits.canonicalReturn.poke(false)
      }

      resolve(port = 0, robIdx = 3, tagIndex = 2, generation = 5, ordinal = 6, pc = 0x1000, target = 0x2000)
      resolve(port = 1, robIdx = 7, tagIndex = 4, generation = 3, ordinal = 1, pc = 0x3000, target = 0x4000)

      dut.io.recover.valid.expect(true)
      dut.io.recover.robIdx.expect(3)
      dut.io.redirect.valid.expect(true)
      dut.io.redirect.target.expect(0x2000)
      dut.io.cfiRecovery.valid.expect(true)
      dut.io.cfiRecovery.bits.ftqTag.index.expect(2)
      dut.io.cfiRecovery.bits.ftqTag.generation.expect(5)
      dut.io.cfiRecovery.bits.ftqInstOrdinal.expect(6)
      dut.io.cfiRecovery.bits.pc.expect(0x1000)
      dut.io.cfiRecovery.bits.cfiType.expect(CfiType.branch)
      dut.io.cfiRecovery.bits.actualTaken.expect(true)
      dut.io.cfiRecovery.bits.actualTarget.expect(0x2000)
      dut.io.cfiRecovery.bits.actualNpc.expect(0x2000)

      dut.io.resolve(0).valid.poke(false)
      dut.io.resolve(1).valid.poke(false)
      dut.io.cfiRecovery.valid.expect(false)
    }

    println("BackendCfiContractSpec: PASS")
  }
}
