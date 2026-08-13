package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.frontend.ifetch.FetchBlockBuffer

object FetchBlockBufferSpec {
  private val cfg = FrontendConfig(fetchTargetEntries = 4)

  def main(args: Array[String]): Unit = {
    simulate(new FetchBlockBuffer(cfg, depth = 4)) { dut =>
      def drive(valid: Boolean, index: Int = 0, data: BigInt = 0): Unit = {
        dut.io.in.valid.poke(valid)
        dut.io.in.bits.token.tag.index.poke(index)
        dut.io.in.bits.token.tag.generation.poke(1)
        dut.io.in.bits.token.streamEpoch.poke(0)
        for (block <- dut.io.in.bits.blocks.indices) {
          dut.io.in.bits.blocks(block).valid.poke(valid)
          dut.io.in.bits.blocks(block).bits.data.poke(data + block)
          dut.io.in.bits.blocks(block).bits.hit.poke(true)
          dut.io.in.bits.blocks(block).bits.exception.valid.poke(false)
          dut.io.in.bits.blocks(block).bits.exception.cause.poke(0)
          dut.io.in.bits.blocks(block).bits.exception.tval.poke(0)
        }
      }

      drive(valid = false)
      dut.io.flush.poke(false)
      dut.io.headLive.poke(true)
      dut.io.out.ready.poke(false)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      drive(valid = true, index = 0, data = 0x100)
      dut.io.in.ready.expect(true)
      dut.clock.step()

      dut.io.out.valid.expect(true)
      dut.io.out.bits.token.tag.index.expect(0)
      dut.io.out.bits.blocks(0).bits.data.expect(0x100)

      // Backpressure keeps the oldest group stable while a younger response is absorbed.
      drive(valid = true, index = 1, data = 0x200)
      dut.io.in.ready.expect(true)
      dut.clock.step()
      drive(valid = false)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.token.tag.index.expect(0)
      dut.io.out.bits.blocks(0).bits.data.expect(0x100)
      dut.io.count.expect(2)

      // A dead head is silently discarded; the following live token remains ordered.
      dut.io.headLive.poke(false)
      dut.io.staleDrop.expect(true)
      dut.io.out.valid.expect(false)
      dut.clock.step()
      dut.io.headLive.poke(true)
      dut.io.out.valid.expect(true)
      dut.io.out.bits.token.tag.index.expect(1)
      dut.io.out.bits.blocks(0).bits.data.expect(0x200)

      dut.io.out.ready.poke(true)
      dut.clock.step()
      dut.io.empty.expect(true)

      drive(valid = true, index = 2, data = 0x300)
      dut.clock.step()
      drive(valid = false)
      dut.io.flush.poke(true)
      dut.clock.step()
      dut.io.flush.poke(false)
      dut.io.empty.expect(true)
    }

    println("FetchBlockBufferSpec: PASS")
  }
}
