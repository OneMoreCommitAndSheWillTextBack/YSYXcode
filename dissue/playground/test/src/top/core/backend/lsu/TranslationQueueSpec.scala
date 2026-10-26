package top.core.backend.lsu

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.backend.csr.PrivMode
import top.core.mmu.MmuAccessType

object TranslationQueueSpec {
  private val cfg = BackendConfig(
    robEntries = 8,
    translationQueueEntries = 4
  )

  def main(args: Array[String]): Unit = {
    simulate(new TranslationQueue(cfg)) { dut =>
      def clearInputs(): Unit = {
        dut.io.enq.valid.poke(false)
        dut.io.enq.bits.packet.robIdx.poke(0)
        dut.io.enq.bits.vaddr.poke(0)
        dut.io.enq.bits.access.poke(MmuAccessType.load)
        dut.io.enq.bits.priv.poke(PrivMode.S)
        dut.io.enq.bits.mstatus.poke(0)
        dut.io.enq.bits.satp.poke(0)
        dut.io.pop.poke(false)
        dut.io.flush.poke(false)
        dut.io.recover.valid.poke(false)
        dut.io.recover.robIdx.poke(0)
        dut.io.robHead.poke(0)
      }

      def enqueue(robIdx: Int, ready: Boolean = true): Unit = {
        dut.io.enq.valid.poke(true)
        dut.io.enq.bits.packet.robIdx.poke(robIdx)
        dut.io.enq.ready.expect(ready)
        if (ready) {
          dut.clock.step()
        }
        dut.io.enq.valid.poke(false)
      }
      def pop():                                       Unit = {
        dut.io.pop.poke(true)
        dut.clock.step()
        dut.io.pop.poke(false)
      }

      def reset(): Unit = {
        clearInputs()
        dut.reset.poke(true)
        dut.clock.step(2)
        dut.reset.poke(false)
      }

      reset()

      // Program order and head lookahead.
      enqueue(0)
      enqueue(1)
      dut.io.headValid.expect(true)
      dut.io.head.packet.robIdx.expect(0)
      dut.io.occupancy.expect(2)
      pop()
      dut.io.head.packet.robIdx.expect(1)
      pop()
      dut.io.empty.expect(true)
      dut.io.headValid.expect(false)

      // Regression: a single live entry with a simultaneous pop and enqueue must
      // deliver the newly enqueued entry next, not the entry being popped.
      enqueue(2)
      dut.io.head.packet.robIdx.expect(2)
      dut.io.pop.poke(true)
      dut.io.enq.valid.poke(true)
      dut.io.enq.bits.packet.robIdx.poke(3)
      dut.io.enq.ready.expect(true)
      dut.clock.step()
      dut.io.pop.poke(false)
      dut.io.enq.valid.poke(false)
      dut.io.occupancy.expect(1)
      dut.io.headValid.expect(true)
      dut.io.head.packet.robIdx.expect(3)
      pop()
      dut.io.empty.expect(true)

      // Full queue backpressures until a pop frees a slot.
      for (rob <- 4 until 8) { enqueue(rob) }
      dut.io.full.expect(true)
      enqueue(0, ready = false)
      pop()
      dut.io.full.expect(false)
      enqueue(0)

      // Recover keeps the prefix at or older than the boundary.
      reset()
      enqueue(1)
      enqueue(2)
      enqueue(3)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(2)
      dut.clock.step()
      dut.io.recover.valid.poke(false)
      dut.io.occupancy.expect(2)
      dut.io.head.packet.robIdx.expect(1)
      pop()
      dut.io.head.packet.robIdx.expect(2)
      pop()
      dut.io.empty.expect(true)

      // Flush drops every entry.
      enqueue(5)
      enqueue(6)
      dut.io.flush.poke(true)
      dut.clock.step()
      dut.io.flush.poke(false)
      dut.io.empty.expect(true)
      dut.io.occupancy.expect(0)
    }

    println("TranslationQueueSpec: PASS")
  }
}
