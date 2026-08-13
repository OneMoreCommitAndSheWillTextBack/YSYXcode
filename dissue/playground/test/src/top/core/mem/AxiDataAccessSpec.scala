package top.core.mem

import chisel3.simulator.EphemeralSimulator._

object AxiDataAccessSpec {
  def main(args: Array[String]): Unit = {
    simulate(new AxiDataAccess(allowDirectIncoming = true)) { dut =>
      def driveRequest(
        valid:    Boolean,
        addr:     BigInt = 0,
        write:    Boolean = false,
        size:     Int = 2,
        unsigned: Boolean = true,
        data:     BigInt = 0,
        mask:     Int = 0,
        txnId:    Int = 0
      ): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.addr.poke(addr)
        dut.io.req.bits.write.poke(write)
        dut.io.req.bits.size.poke(size)
        dut.io.req.bits.unsigned.poke(unsigned)
        dut.io.req.bits.wdata.poke(data)
        dut.io.req.bits.wmask.poke(mask)
        dut.io.req.bits.txnId.poke(txnId)
        dut.io.req.bits.cacheable.poke(false)
        dut.io.req.bits.kind.poke(0)
      }

      def driveReadResponse(valid: Boolean, data: BigInt = 0, resp: Int = 0): Unit = {
        dut.io.axiReadResp.valid.poke(valid)
        dut.io.axiReadResp.bits.data.poke(data)
        dut.io.axiReadResp.bits.id.poke(1)
        dut.io.axiReadResp.bits.resp.poke(resp)
        dut.io.axiReadResp.bits.last.poke(true)
      }

      driveRequest(valid = false)
      driveReadResponse(valid = false)
      dut.io.resp.ready.poke(true)
      dut.io.incomingIssuePermit.poke(true)
      dut.io.issuePermit.poke(true)
      dut.io.abort.poke(false)
      dut.io.axiReadReq.ready.poke(true)
      dut.io.axiWriteReq.ready.poke(true)
      dut.io.axiWriteResp.valid.poke(false)
      dut.io.axiWriteResp.bits.id.poke(1)
      dut.io.axiWriteResp.bits.resp.poke(0)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // An authorized input request launches directly onto AXI.
      driveRequest(valid = true, addr = 0x1001, size = 0, unsigned = true, txnId = 1)
      dut.io.req.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x1001)
      dut.clock.step()
      driveRequest(valid = false)

      // The AXI response bypasses to the consumer; backpressure retains it in respReg.
      dut.io.resp.ready.poke(false)
      driveReadResponse(valid = true, data = 0x44332211L)
      dut.io.axiReadResp.ready.expect(true)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.data.expect(0x22)
      dut.io.resp.bits.txnId.expect(1)
      dut.clock.step()
      driveReadResponse(valid = false)

      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.data.expect(0x22)

      // Response turnover accepts a write without feeding the response back
      // into AXI combinationally; the buffered request remains cancellable.
      dut.io.resp.ready.poke(true)
      dut.io.axiWriteReq.ready.poke(false)
      driveRequest(valid = true, addr = 0x2001, write = true, size = 0, data = 0xaa, mask = 1, txnId = 2)
      dut.io.req.ready.expect(true)
      dut.io.axiWriteReq.valid.expect(false)
      dut.clock.step()
      driveRequest(valid = false)

      dut.io.axiWriteReq.valid.expect(true)
      dut.io.axiWriteReq.bits.data.expect(0xaa00)
      dut.io.axiWriteReq.bits.strb.expect(2)

      dut.io.issuePermit.poke(false)
      dut.io.abort.poke(true)
      dut.io.axiWriteReq.valid.expect(false)
      dut.io.cancel.valid.expect(true)
      dut.io.cancel.bits.expect(2)
      dut.clock.step()
      dut.io.abort.poke(false)
      dut.io.issuePermit.poke(true)

      // Direct writes use the incoming address to shift data and strobes.
      dut.io.axiWriteReq.ready.poke(true)
      driveRequest(valid = true, addr = 0x3002, write = true, size = 1, data = 0xbeef, mask = 3, txnId = 3)
      dut.io.req.ready.expect(true)
      dut.io.axiWriteReq.valid.expect(true)
      dut.io.axiWriteReq.bits.addr.expect(0x3002)
      dut.io.axiWriteReq.bits.data.expect(0xbeef0000L)
      dut.io.axiWriteReq.bits.strb.expect(0xc)
      dut.clock.step()
      driveRequest(valid = false)

      // A completed write can hand off a new, initially unpermitted read in the same cycle.
      dut.io.axiWriteResp.valid.poke(true)
      dut.io.incomingIssuePermit.poke(false)
      driveRequest(valid = true, addr = 0x4000, txnId = 4)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.txnId.expect(3)
      dut.io.req.ready.expect(true)
      dut.io.axiReadReq.valid.expect(false)
      dut.clock.step()
      dut.io.axiWriteResp.valid.poke(false)
      driveRequest(valid = false)

      dut.io.incomingIssuePermit.poke(true)
      dut.io.issuePermit.poke(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x4000)
      dut.clock.step()
    }

    println("AxiDataAccessSpec: PASS")
  }
}
