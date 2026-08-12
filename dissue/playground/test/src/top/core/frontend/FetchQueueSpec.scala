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
        dut.io.preserveBefore.valid.poke(false)
        dut.io.currentEpoch.poke(0)
        dut.io.enq.valid.poke(false)
        dut.io.out.ready.poke(false)
        for (lane <- dut.io.enq.bits.insts.indices) {
          dut.io.enq.bits.insts(lane).valid.poke(false)
        }
      }

      def clearEnqueue(): Unit = {
        dut.io.enq.valid.poke(false)
        for (lane <- dut.io.enq.bits.insts.indices) {
          dut.io.enq.bits.insts(lane).valid.poke(false)
        }
      }

      def driveEnqueue(sequence: Int, basePc: BigInt, validCount: Int): Unit = {
        dut.io.enq.valid.poke(true)
        for (lane <- dut.io.enq.bits.insts.indices) {
          val valid = lane < validCount
          dut.io.enq.bits.insts(lane).valid.poke(valid)
          dut.io.enq.bits.insts(lane).bits.sequence.poke(sequence)
          dut.io.enq.bits.insts(lane).bits.epoch.poke(0)
          dut.io.enq.bits.insts(lane).bits.inst.pc.poke(basePc + lane * 2)
          dut.io.enq.bits.insts(lane).bits.inst.ftqInstOrdinal.poke(lane)
        }
      }

      def enqueue(sequence: Int, basePc: BigInt): Unit = {
        driveEnqueue(sequence, basePc, validCount = 2)
        dut.io.enq.ready.expect(true)
        dut.clock.step()
        clearEnqueue()
      }

      idle()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // An empty queue forwards its first two incoming instructions directly to a ready backend.
      dut.io.out.ready.poke(true)
      driveEnqueue(sequence = 1, basePc = 0x800, validCount = 4)
      dut.io.enq.ready.expect(true)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.insts(0).bits.pc.expect(0x800)
      dut.io.out.bits.insts(1).bits.pc.expect(0x802)
      dut.io.enqueueWidth.expect(4)
      dut.io.dequeueWidth.expect(2)
      dut.clock.step()
      clearEnqueue()

      // Only the two lanes not consumed by the bypass remain resident.
      dut.io.count.expect(2)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.insts(0).bits.pc.expect(0x804)
      dut.io.out.bits.insts(1).bits.pc.expect(0x806)
      dut.clock.step()
      dut.io.empty.expect(true)

      // Backpressure still captures the complete incoming group before presenting it again.
      dut.io.out.ready.poke(false)
      driveEnqueue(sequence = 2, basePc = 0x900, validCount = 2)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.insts(0).bits.pc.expect(0x900)
      dut.clock.step()
      clearEnqueue()
      dut.io.count.expect(2)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.insts(0).bits.pc.expect(0x900)
      dut.io.out.bits.insts(1).bits.pc.expect(0x902)
      dut.io.out.ready.poke(true)
      dut.clock.step()
      dut.io.empty.expect(true)

      // A single incoming instruction also bypasses without creating a queue entry.
      driveEnqueue(sequence = 3, basePc = 0xa00, validCount = 1)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.insts(0).valid.expect(true)
      dut.io.out.bits.insts(1).valid.expect(false)
      dut.clock.step()
      clearEnqueue()
      dut.io.empty.expect(true)

      // Flush suppresses both sides of the combinational bypass.
      dut.io.flush.poke(true)
      driveEnqueue(sequence = 4, basePc = 0xb00, validCount = 2)
      dut.io.enq.ready.expect(false)
      dut.io.out.valid.expect(false)
      dut.clock.step()
      dut.io.flush.poke(false)
      clearEnqueue()

      dut.io.out.ready.poke(false)
      enqueue(sequence = 10, basePc = 0x1000)
      enqueue(sequence = 11, basePc = 0x1010)

      // An IFU correction may preserve an already-enqueued prefix from the same FTQ entry.
      dut.io.preserveBefore.valid.poke(true)
      dut.io.preserveBefore.bits.sequence.poke(11)
      dut.io.preserveBefore.bits.instOrdinal.poke(2)
      dut.io.count.expect(4)
      dut.io.out.valid.expect(true)
      dut.clock.step()
      dut.io.preserveBefore.valid.poke(false)
      dut.io.count.expect(4)

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
