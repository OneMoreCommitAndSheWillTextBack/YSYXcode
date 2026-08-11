package top.core.mem

import chisel3.simulator.EphemeralSimulator._
import top.config.{DCacheConfig, MemConfig}

object DCacheRefillTurnoverSpec {
  private val cacheCfg = DCacheConfig(
    lineBytes = 8,
    sets = 4,
    ways = 2,
    mshrEntries = 2,
    waitersPerMshr = 2
  )
  private val memCfg   = MemConfig(dcache = cacheCfg)

  def main(args: Array[String]): Unit = {
    simulate(new DCache(cacheCfg, memCfg, robEntries = 8)) { dut =>
      def driveRequest(valid: Boolean, addr: BigInt = 0, txnId: Int = 0): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.request.addr.poke(addr)
        dut.io.req.bits.request.write.poke(false)
        dut.io.req.bits.request.size.poke(2)
        dut.io.req.bits.request.unsigned.poke(true)
        dut.io.req.bits.request.wdata.poke(0)
        dut.io.req.bits.request.wmask.poke(0)
        dut.io.req.bits.request.txnId.poke(txnId)
        dut.io.req.bits.request.cacheable.poke(true)
        dut.io.req.bits.request.kind.poke(0)
        dut.io.req.bits.owner.squashable.poke(false)
        dut.io.req.bits.owner.robIdx.poke(0)
      }

      def driveReadBeat(valid: Boolean, data: BigInt = 0, last: Boolean = false): Unit = {
        dut.io.axiReadResp.valid.poke(valid)
        dut.io.axiReadResp.bits.data.poke(data)
        dut.io.axiReadResp.bits.id.poke(2)
        dut.io.axiReadResp.bits.resp.poke(0)
        dut.io.axiReadResp.bits.last.poke(last)
      }

      driveRequest(valid = false)
      driveReadBeat(valid = false)
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
      dut.io.axiWriteResp.bits.id.poke(0)
      dut.io.axiWriteResp.bits.resp.poke(0)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // Allocate one miss, then allocate a second MSHR while launching the first refill.
      driveRequest(valid = true, addr = 0x1000, txnId = 0)
      dut.io.req.ready.expect(true)
      dut.clock.step()

      driveRequest(valid = true, addr = 0x1008, txnId = 1)
      dut.io.req.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x1000)
      dut.clock.step()
      driveRequest(valid = false)

      driveReadBeat(valid = true, data = 0x11112222L, last = false)
      dut.io.axiReadResp.ready.expect(true)
      dut.io.axiReadReq.valid.expect(false)
      dut.clock.step()

      // Completing MSHR 0 opens the single read slot for MSHR 1 on the same edge.
      driveReadBeat(valid = true, data = 0x33334444L, last = true)
      dut.io.axiReadResp.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x1008)
      dut.clock.step()

      driveReadBeat(valid = true, data = 0x55556666L, last = false)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.txnId.expect(0)
      dut.io.resp.bits.data.expect(0x11112222L)
      dut.clock.step()

      driveReadBeat(valid = true, data = 0x77778888L, last = true)
      dut.clock.step()
      driveReadBeat(valid = false)

      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.txnId.expect(1)
      dut.io.resp.bits.data.expect(0x55556666L)
      dut.clock.step()
    }

    println("DCacheRefillTurnoverSpec: PASS")
  }
}
