package top.core.mem

import chisel3.simulator.EphemeralSimulator._
import top.config.{DCacheConfig, MemConfig}

object DCacheWritebackTurnoverSpec {
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
      def driveStore(valid: Boolean, addr: BigInt = 0): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.request.addr.poke(addr)
        dut.io.req.bits.request.write.poke(true)
        dut.io.req.bits.request.size.poke(2)
        dut.io.req.bits.request.unsigned.poke(true)
        dut.io.req.bits.request.wdata.poke(0xdeadbeefL)
        dut.io.req.bits.request.wmask.poke(0xf)
        dut.io.req.bits.request.txnId.poke(4)
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

      driveStore(valid = false)
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
      dut.io.axiWriteResp.bits.id.poke(2)
      dut.io.axiWriteResp.bits.resp.poke(0)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // Refill a store miss, then retire its waiter to leave a dirty cache line.
      driveStore(valid = true, addr = 0x1000)
      dut.io.req.ready.expect(true)
      dut.clock.step()
      driveStore(valid = false)

      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x1000)
      dut.clock.step()
      driveReadBeat(valid = true, data = 0x11112222L, last = false)
      dut.clock.step()
      driveReadBeat(valid = true, data = 0x33334444L, last = true)
      dut.clock.step()
      driveReadBeat(valid = false)

      dut.io.resp.valid.expect(true)
      dut.clock.step()

      // A line clean wins over a simultaneous clean-all request. This prevents
      // a PTW maintenance request from deadlocking with fence.i.
      dut.io.cleanInvalidate.valid.poke(true)
      dut.io.cleanInvalidate.bits.poke(0x1000)
      dut.io.cleanAll.valid.poke(true)
      dut.io.cleanAll.bits.poke(true)
      dut.io.cleanInvalidate.ready.expect(false)
      dut.io.cleanAll.ready.expect(false)
      dut.clock.step()

      dut.io.axiWriteReq.valid.expect(true)
      dut.io.axiWriteReq.bits.addr.expect(0x1000)
      dut.io.axiWriteReq.bits.data.expect(0xdeadbeefL)
      dut.clock.step()

      // The B response for beat 0 submits beat 1 without returning to an idle writeback cycle.
      dut.io.axiWriteResp.valid.poke(true)
      dut.io.axiWriteResp.ready.expect(true)
      dut.io.axiWriteReq.valid.expect(true)
      dut.io.axiWriteReq.bits.addr.expect(0x1004)
      dut.io.axiWriteReq.bits.data.expect(0x33334444L)
      dut.clock.step()

      // The final response ends maintenance and does not create another request.
      dut.io.axiWriteReq.valid.expect(false)
      dut.clock.step()
      dut.io.axiWriteResp.valid.poke(false)
      dut.clock.step()
      dut.io.cleanInvalidate.ready.expect(true)
      dut.io.cleanAll.ready.expect(false)
      dut.clock.step()
      dut.io.cleanInvalidate.valid.poke(false)

      // The held clean-all request starts immediately after the line request.
      dut.io.cleanAll.ready.expect(true)
      dut.clock.step()
      dut.io.cleanAll.valid.poke(false)

      var cleanAllCompleted = false
      for (_ <- 0 until cacheCfg.sets * cacheCfg.ways + 2) {
        if (dut.io.cleanAllDone.peek().litToBoolean) {
          cleanAllCompleted = true
        }
        dut.clock.step()
      }
      assert(cleanAllCompleted, "clean-all did not complete after the higher-priority line maintenance")
    }

    println("DCacheWritebackTurnoverSpec: PASS")
  }
}
