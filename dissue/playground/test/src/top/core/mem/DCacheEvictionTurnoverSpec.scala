package top.core.mem

import chisel3.simulator.EphemeralSimulator._
import top.config.{DCacheConfig, MemConfig}

object DCacheEvictionTurnoverSpec {
  private val cacheCfg = DCacheConfig(
    lineBytes = 4,
    sets = 2,
    ways = 2,
    mshrEntries = 2,
    waitersPerMshr = 2
  )
  private val memCfg   = MemConfig(dcache = cacheCfg)

  def main(args: Array[String]): Unit = {
    simulate(new DCache(cacheCfg, memCfg, robEntries = 8)) { dut =>
      def driveStore(valid: Boolean, addr: BigInt = 0, txnId: Int = 4, data: BigInt = 0): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.request.addr.poke(addr)
        dut.io.req.bits.request.write.poke(true)
        dut.io.req.bits.request.size.poke(2)
        dut.io.req.bits.request.unsigned.poke(true)
        dut.io.req.bits.request.wdata.poke(data)
        dut.io.req.bits.request.wmask.poke(0xf)
        dut.io.req.bits.request.txnId.poke(txnId)
        dut.io.req.bits.request.cacheable.poke(true)
        dut.io.req.bits.request.kind.poke(0)
        dut.io.req.bits.owner.squashable.poke(false)
        dut.io.req.bits.owner.robIdx.poke(0)
      }

      def driveReadResponse(valid: Boolean, data: BigInt = 0): Unit = {
        dut.io.axiReadResp.valid.poke(valid)
        dut.io.axiReadResp.bits.data.poke(data)
        dut.io.axiReadResp.bits.id.poke(2)
        dut.io.axiReadResp.bits.resp.poke(0)
        dut.io.axiReadResp.bits.last.poke(true)
      }

      def fillDirtyLine(addr: BigInt, txnId: Int, data: BigInt): Unit = {
        driveStore(valid = true, addr = addr, txnId = txnId, data = data)
        dut.io.req.ready.expect(true)
        dut.clock.step()
        driveStore(valid = false)

        dut.io.axiReadReq.valid.expect(true)
        dut.io.axiReadReq.bits.addr.expect(addr)
        dut.clock.step()

        driveReadResponse(valid = true, data = 0)
        dut.clock.step()
        driveReadResponse(valid = false)
        dut.io.resp.valid.expect(true)
        dut.clock.step()
      }

      driveStore(valid = false)
      driveReadResponse(valid = false)
      dut.io.resp.ready.poke(true)
      dut.io.flush.poke(false)
      dut.io.recover.valid.poke(false)
      dut.io.recover.robIdx.poke(0)
      dut.io.robHead.poke(0)
      for (cfi <- dut.io.unresolvedCfi) {
        cfi.poke(false)
      }
      dut.io.cleanInvalidate.valid.poke(false)
      dut.io.cleanInvalidate.bits.poke(0)
      dut.io.cleanAll.valid.poke(false)
      dut.io.cleanAll.bits.poke(false)
      dut.io.axiReadReq.ready.poke(true)
      dut.io.axiWriteReq.ready.poke(true)
      dut.io.axiWriteResp.valid.poke(false)
      dut.io.axiWriteResp.bits.id.poke(2)
      dut.io.axiWriteResp.bits.resp.poke(0)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // Fill both ways of one set with dirty lines; replacement returns to way 0.
      fillDirtyLine(addr = 0x1000, txnId = 4, data = 0x11112222L)
      fillDirtyLine(addr = 0x1008, txnId = 5, data = 0x33334444L)

      // A third same-set miss first writes back the dirty way-0 victim.
      driveStore(valid = true, addr = 0x1010, txnId = 6, data = 0x55556666L)
      dut.io.req.ready.expect(true)
      dut.clock.step()
      driveStore(valid = false)

      dut.io.axiWriteReq.valid.expect(true)
      dut.io.axiWriteReq.bits.addr.expect(0x1000)
      dut.io.axiWriteReq.bits.data.expect(0x11112222L)
      dut.clock.step()

      // The final B response hands the same MSHR directly to the refill read channel.
      dut.io.axiWriteResp.valid.poke(true)
      dut.io.axiWriteResp.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x1010)
      dut.clock.step()
      dut.io.axiWriteResp.valid.poke(false)

      driveReadResponse(valid = true, data = 0)
      dut.io.axiReadResp.ready.expect(true)
      dut.clock.step()
      driveReadResponse(valid = false)
      dut.io.resp.valid.expect(true)
      dut.clock.step()
    }

    println("DCacheEvictionTurnoverSpec: PASS")
  }
}
