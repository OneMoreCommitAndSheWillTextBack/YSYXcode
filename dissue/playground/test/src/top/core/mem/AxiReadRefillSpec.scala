package top.core.mem

import chisel3.simulator.EphemeralSimulator._

object AxiReadRefillSpec {
  private val beat0 = BigInt("11223344", 16)
  private val beat1 = BigInt("55667788", 16)
  private val line  = (beat1 << 32) | beat0

  def main(args: Array[String]): Unit = {
    simulate(new AxiReadRefill()) { dut =>
      def driveRequest(valid: Boolean, addr: BigInt = 0): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.addr.poke(addr)
      }

      def driveReadBeat(valid: Boolean, data: BigInt = 0, last: Boolean = false): Unit = {
        dut.io.axiReadResp.valid.poke(valid)
        dut.io.axiReadResp.bits.data.poke(data)
        dut.io.axiReadResp.bits.id.poke(0)
        dut.io.axiReadResp.bits.resp.poke(0)
        dut.io.axiReadResp.bits.last.poke(last)
      }

      driveRequest(valid = false)
      driveReadBeat(valid = false)
      dut.io.resp.ready.poke(true)
      dut.io.axiReadReq.ready.poke(true)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // Launch the first line request.
      driveRequest(valid = true, addr = 0x1000)
      dut.io.req.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x1000)
      dut.io.axiReadReq.bits.len.expect(1)
      dut.clock.step()
      driveRequest(valid = false)

      driveReadBeat(valid = true, data = beat0, last = false)
      dut.io.axiReadResp.ready.expect(true)
      dut.io.resp.valid.expect(false)
      dut.clock.step()

      // The final beat is the response payload and the next request launches on the same edge.
      driveReadBeat(valid = true, data = beat1, last = true)
      driveRequest(valid = true, addr = 0x2000)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.data.expect(line)
      dut.io.req.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x2000)
      dut.clock.step()
      driveReadBeat(valid = false)
      driveRequest(valid = false)

      driveReadBeat(valid = true, data = beat0, last = false)
      dut.clock.step()

      // If the cache response stalls, the accepted final beat is retained in the response skid register.
      dut.io.resp.ready.poke(false)
      driveReadBeat(valid = true, data = beat1, last = true)
      driveRequest(valid = true, addr = 0x3000)
      dut.io.axiReadResp.ready.expect(true)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.data.expect(line)
      dut.io.req.ready.expect(false)
      dut.clock.step()
      driveReadBeat(valid = false)

      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.data.expect(line)
      dut.io.req.ready.expect(false)
      dut.clock.step()

      // Consuming the skid entry opens a same-cycle request window as well.
      dut.io.resp.ready.poke(true)
      dut.io.resp.valid.expect(true)
      dut.io.req.ready.expect(true)
      dut.io.axiReadReq.valid.expect(true)
      dut.io.axiReadReq.bits.addr.expect(0x3000)
      dut.clock.step()
      driveRequest(valid = false)

      dut.io.axiReadResp.ready.expect(true)
      dut.io.resp.valid.expect(false)
    }

    println("AxiReadRefillSpec: PASS")
  }
}
