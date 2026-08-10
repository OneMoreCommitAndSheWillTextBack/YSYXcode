package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.frontend.ifetch.FetchQueue

object FetchQueueSpec {
  private val cfg = FrontendConfig(fetchQueueEntries = 32)

  def main(args: Array[String]): Unit = {
    simulate(new FetchQueue(cfg, depth = 32, enqWidth = 4)) { dut =>
      def idle(): Unit = {
        dut.io.flush.poke(false)
        dut.io.pruneFrom.valid.poke(false)
        dut.io.currentEpoch.poke(0)
        dut.io.enq.valid.poke(false)
        dut.io.out.ready.poke(false)
        for (lane <- dut.io.enq.bits.insts.indices) {
          dut.io.enq.bits.insts(lane).valid.poke(false)
        }
      }

      def enqueue(sequence: Int, basePc: BigInt): Unit = {
        dut.io.enq.valid.poke(true)
        for (lane <- dut.io.enq.bits.insts.indices) {
          val valid = lane < 2
          dut.io.enq.bits.insts(lane).valid.poke(valid)
          dut.io.enq.bits.insts(lane).bits.sequence.poke(sequence)
          dut.io.enq.bits.insts(lane).bits.epoch.poke(0)
          dut.io.enq.bits.insts(lane).bits.inst.pc.poke(basePc + lane * 2)
        }
        dut.io.enq.ready.expect(true)
        dut.clock.step()
        dut.io.enq.valid.poke(false)
        for (lane <- dut.io.enq.bits.insts.indices) {
          dut.io.enq.bits.insts(lane).valid.poke(false)
        }
      }

      idle()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      enqueue(sequence = 10, basePc = 0x1000)
      enqueue(sequence = 11, basePc = 0x1010)
      enqueue(sequence = 12, basePc = 0x1020)
      dut.io.count.expect(6)

      // A BPU override anchored at sequence 11 keeps only the strictly older prefix.
      dut.io.pruneFrom.valid.poke(true)
      dut.io.pruneFrom.bits.poke(11)
      dut.io.out.valid.expect(false)
      dut.io.enq.ready.expect(false)
      dut.clock.step()
      dut.io.pruneFrom.valid.poke(false)

      dut.io.count.expect(2)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.insts(0).bits.pc.expect(0x1000)
      dut.io.out.bits.insts(1).bits.pc.expect(0x1002)
      dut.io.out.ready.poke(true)
      dut.clock.step()
      dut.io.empty.expect(true)
    }

    println("FetchQueueSpec: PASS")
  }
}
