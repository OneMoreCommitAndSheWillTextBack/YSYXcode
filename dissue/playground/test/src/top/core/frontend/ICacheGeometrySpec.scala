package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.config.FrontendConfig
import top.core.frontend.icache.ICache

object ICacheGeometrySpec {
  private def initialize(dut: ICache): Unit = {
    dut.io.req.valid.poke(false)
    dut.io.resp.ready.poke(true)
    dut.io.refillReq.ready.poke(true)
    dut.io.refillResp.valid.poke(false)
    dut.io.invalidate.poke(false)
    dut.io.recovery.valid.poke(false)
    dut.reset.poke(true)
    dut.clock.step(2)
    dut.reset.poke(false)
  }

  private def request(dut: ICache, cfg: FrontendConfig, token: Int, addr: BigInt, twoBlocks: Boolean): Unit = {
    dut.io.req.valid.poke(true)
    dut.io.req.bits.token.tag.index.poke(token % cfg.ftqEntries)
    dut.io.req.bits.token.tag.generation.poke(token / cfg.ftqEntries + 1)
    dut.io.req.bits.token.streamEpoch.poke(0)
    dut.io.req.bits.startPc.poke(addr)
    dut.io.req.bits.blockValid(0).poke(true)
    dut.io.req.bits.blockAddr(0).poke(addr)
    dut.io.req.bits.blockValid(1).poke(twoBlocks)
    dut.io.req.bits.blockAddr(1).poke(addr + cfg.fetchBytes)
    dut.io.req.ready.expect(true)
    dut.clock.step()
    dut.io.req.valid.poke(false)
  }

  private def refill(dut: ICache, address: BigInt, data: BigInt): Unit = {
    dut.io.refillReq.valid.expect(true)
    dut.io.refillReq.bits.addr.expect(address)
    dut.clock.step()
    dut.io.refillResp.valid.poke(true)
    dut.io.refillResp.bits.data.poke(data)
    dut.io.refillResp.bits.exception.valid.poke(false)
    dut.io.refillResp.bits.exception.cause.poke(0)
    dut.io.refillResp.bits.exception.tval.poke(0)
    dut.io.refillResp.ready.expect(true)
    dut.clock.step()
    dut.io.refillResp.valid.poke(false)
  }

  private def fillSingleBlock(dut: ICache, cfg: FrontendConfig, token: Int, addr: BigInt, data: BigInt): Unit = {
    request(dut, cfg, token, addr, twoBlocks = false)
    dut.io.lookup.valid.expect(true)
    dut.io.lookup.bits.missingMask.expect(1)
    dut.clock.step()
    refill(dut, addr, data)
    dut.io.resp.valid.expect(true)
    dut.clock.step()
  }

  def main(args: Array[String]): Unit = {
    val lineCfg  = FrontendConfig(
      icacheLineBytes = 32,
      icacheSets = 4,
      icacheBanks = 2,
      fetchTargetEntries = 4
    )
    val words    = Seq(
      BigInt("0123456789abcdef", 16),
      BigInt("fedcba9876543210", 16),
      BigInt("0f1e2d3c4b5a6978", 16),
      BigInt("8877665544332211", 16)
    )
    val fullLine = words.zipWithIndex.map { case (word, index) => word << (index * 64) }.reduce(_ | _)

    simulate(new ICache(lineCfg)) { dut =>
      initialize(dut)

      // Two adjacent fetch blocks in one 32-byte line generate one aligned refill.
      request(dut, lineCfg, token = 0, addr = 0x1000, twoBlocks = true)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.missingMask.expect(3)
      dut.clock.step()
      refill(dut, address = 0x1000, data = fullLine)

      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.blocks(0).bits.data.expect(words(0))
      dut.io.resp.bits.blocks(1).bits.data.expect(words(1))
      dut.io.resp.bits.blocks(0).bits.hit.expect(false)
      dut.io.resp.bits.blocks(1).bits.hit.expect(false)
      dut.clock.step()

      request(dut, lineCfg, token = 1, addr = 0x1010, twoBlocks = true)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.hitMask.expect(3)
      dut.clock.step()
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.blocks(0).bits.data.expect(words(2))
      dut.io.resp.bits.blocks(1).bits.data.expect(words(3))
      dut.clock.step()
    }

    val twoWayCfg = FrontendConfig(
      icacheLineBytes = 8,
      icacheSets = 4,
      icacheWays = 2,
      icacheBanks = 2,
      fetchTargetEntries = 4
    )
    simulate(new ICache(twoWayCfg)) { dut =>
      initialize(dut)

      // These lines share a set. Both remain resident in the two-way organization.
      fillSingleBlock(dut, twoWayCfg, token = 0, addr = 0x1000, data = words(0))
      fillSingleBlock(dut, twoWayCfg, token = 1, addr = 0x1020, data = words(1))

      request(dut, twoWayCfg, token = 2, addr = 0x1000, twoBlocks = false)
      dut.io.lookup.valid.expect(true)
      dut.io.lookup.bits.hitMask.expect(1)
      dut.clock.step()
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.blocks(0).bits.data.expect(words(0))
      dut.clock.step()
    }

    println("ICacheGeometrySpec: PASS")
  }
}
