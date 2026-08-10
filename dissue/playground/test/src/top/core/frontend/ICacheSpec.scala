package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.frontend.icache.ICache

object ICacheSpec {
  private val cfg = FrontendConfig(
    icacheSets = 4,
    icacheBanks = 2,
    fetchTargetEntries = 4
  )

  private val line0 = BigInt("0123456789abcdef", 16)
  private val line1 = BigInt("fedcba9876543210", 16)

  def main(args: Array[String]): Unit = {
    simulate(new ICache(cfg)) { dut =>
      def driveRequest(valid: Boolean, token: Int = 0, addr: BigInt = 0, twoBlocks: Boolean = false): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.token.tag.index.poke(token % cfg.ftqEntries)
        dut.io.req.bits.token.tag.generation.poke(token / cfg.ftqEntries + 1)
        dut.io.req.bits.token.streamEpoch.poke(0)
        dut.io.req.bits.startPc.poke(addr)
        dut.io.req.bits.blockValid(0).poke(valid)
        dut.io.req.bits.blockAddr(0).poke(addr)
        dut.io.req.bits.blockValid(1).poke(valid && twoBlocks)
        dut.io.req.bits.blockAddr(1).poke(addr + cfg.fetchBytes)
      }

      def driveRefill(valid: Boolean, data: BigInt = 0, fault: Boolean = false): Unit = {
        dut.io.refillResp.valid.poke(valid)
        dut.io.refillResp.bits.data.poke(data)
        dut.io.refillResp.bits.exception.valid.poke(fault)
        dut.io.refillResp.bits.exception.cause.poke(1)
        dut.io.refillResp.bits.exception.tval.poke(0)
      }

      driveRequest(valid = false)
      driveRefill(valid = false)
      dut.io.resp.ready.poke(true)
      dut.io.refillReq.ready.poke(true)
      dut.io.invalidate.poke(false)
      dut.io.recovery.valid.poke(false)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // R0 accepts the first miss group. In its R1 miss cycle, a younger request is accepted into the replay slot.
      driveRequest(valid = true, token = 0, addr = 0x1000, twoBlocks = true)
      dut.io.req.ready.expect(true)
      dut.clock.step()

      driveRequest(valid = true, token = 1, addr = 0x1000, twoBlocks = true)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.missingMask.expect(3)
      dut.io.req.ready.expect(true)
      dut.clock.step()
      driveRequest(valid = false)

      // Both missing blocks refill in deterministic lane order while preserving one group response.
      dut.io.refillReq.valid.expect(true)
      dut.io.refillReq.bits.addr.expect(0x1000)
      dut.clock.step()
      driveRefill(valid = true, data = line0)
      dut.io.refillResp.ready.expect(true)
      dut.clock.step()
      driveRefill(valid = false)

      dut.io.refillReq.valid.expect(true)
      dut.io.refillReq.bits.addr.expect(0x1008)
      dut.clock.step()
      driveRefill(valid = true, data = line1)
      dut.io.refillResp.ready.expect(true)
      dut.clock.step()
      driveRefill(valid = false)

      // The older miss response retires first. The replayed request simultaneously hits the freshly written lines.
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.token.tag.index.expect(0)
      dut.io.resp.bits.blocks(0).bits.data.expect(line0)
      dut.io.resp.bits.blocks(1).bits.data.expect(line1)
      dut.io.resp.bits.blocks(0).bits.hit.expect(false)
      dut.io.resp.bits.blocks(1).bits.hit.expect(false)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.hitMask.expect(3)
      dut.clock.step()

      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.token.tag.index.expect(1)
      dut.io.resp.bits.blocks(0).bits.hit.expect(true)
      dut.io.resp.bits.blocks(1).bits.hit.expect(true)
      dut.clock.step()

      // Once warm, R0/R1 accepts and returns one hit group every cycle.
      driveRequest(valid = true, token = 2, addr = 0x1000, twoBlocks = true)
      dut.io.req.ready.expect(true)
      dut.clock.step()
      driveRequest(valid = true, token = 3, addr = 0x1000, twoBlocks = true)
      dut.io.req.ready.expect(true)
      dut.io.lookup.valid.expect(true)
      dut.clock.step()
      driveRequest(valid = true, token = 4, addr = 0x1000, twoBlocks = true)
      dut.io.req.ready.expect(true)
      dut.io.lookup.valid.expect(true)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.token.tag.index.expect(2)
      dut.clock.step()
      driveRequest(valid = false)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.token.tag.index.expect(3)
      dut.clock.step()
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.token.tag.index.expect(0)
      dut.clock.step()

      // Recovery kills the functional miss response, but an already-issued refill may still warm the cache.
      driveRequest(valid = true, token = 5, addr = 0x2000)
      dut.clock.step()
      driveRequest(valid = false)
      dut.io.lookup.bits.missingMask.expect(1)
      dut.clock.step()
      dut.io.refillReq.valid.expect(true)
      dut.io.refillReq.bits.addr.expect(0x2000)
      dut.clock.step()

      dut.io.recovery.valid.poke(true)
      dut.io.refillResp.ready.expect(false)
      dut.clock.step()
      dut.io.recovery.valid.poke(false)
      driveRefill(valid = true, data = line0)
      dut.io.refillResp.ready.expect(true)
      dut.clock.step()
      driveRefill(valid = false)
      dut.io.resp.valid.expect(false)

      driveRequest(valid = true, token = 6, addr = 0x2000)
      dut.clock.step()
      driveRequest(valid = false)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.hitMask.expect(1)
      dut.clock.step()
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.token.tag.index.expect(2)
      dut.io.resp.bits.blocks(0).bits.hit.expect(true)
      dut.clock.step()

      // Invalidate changes the cache generation; a late bus response cannot repopulate the invalidated line.
      driveRequest(valid = true, token = 7, addr = 0x3000)
      dut.clock.step()
      driveRequest(valid = false)
      dut.clock.step()
      dut.io.refillReq.valid.expect(true)
      dut.io.refillReq.bits.addr.expect(0x3000)
      dut.clock.step()

      dut.io.invalidate.poke(true)
      dut.io.refillResp.ready.expect(false)
      dut.clock.step()
      dut.io.invalidate.poke(false)
      driveRefill(valid = true, data = line1)
      dut.io.refillResp.ready.expect(true)
      dut.clock.step()
      driveRefill(valid = false)
      dut.io.resp.valid.expect(false)

      driveRequest(valid = true, token = 8, addr = 0x3000)
      dut.clock.step()
      driveRequest(valid = false)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.missingMask.expect(1)
    }

    println("ICacheSpec: PASS")
  }
}
