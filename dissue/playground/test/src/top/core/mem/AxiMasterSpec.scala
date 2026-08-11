package top.core.mem

import chisel3.simulator.EphemeralSimulator._
import top.bus.axi.AxiBurst

object AxiMasterSpec {
  def main(args: Array[String]): Unit = {
    simulate(new AxiMaster()) { dut =>
      def driveReadRequest(
        valid: Boolean,
        addr:  BigInt = 0,
        id:    Int = 0,
        len:   Int = 0,
        size:  Int = 2
      ): Unit = {
        dut.io.readReq.valid.poke(valid)
        dut.io.readReq.bits.addr.poke(addr)
        dut.io.readReq.bits.id.poke(id)
        dut.io.readReq.bits.len.poke(len)
        dut.io.readReq.bits.size.poke(size)
        dut.io.readReq.bits.burst.poke(AxiBurst.incr)
      }

      def driveWriteRequest(valid: Boolean, addr: BigInt = 0, data: BigInt = 0): Unit = {
        dut.io.writeReq.valid.poke(valid)
        dut.io.writeReq.bits.addr.poke(addr)
        dut.io.writeReq.bits.id.poke(1)
        dut.io.writeReq.bits.len.poke(0)
        dut.io.writeReq.bits.size.poke(2)
        dut.io.writeReq.bits.burst.poke(AxiBurst.incr)
        dut.io.writeReq.bits.data.poke(data)
        dut.io.writeReq.bits.strb.poke(0xf)
        dut.io.writeReq.bits.last.poke(true)
      }

      def driveReadBeat(valid: Boolean, data: BigInt = 0, id: Int = 0, last: Boolean = false): Unit = {
        dut.io.axi.rvalid.poke(valid)
        dut.io.axi.rdata.poke(data)
        dut.io.axi.rid.poke(id)
        dut.io.axi.rresp.poke(0)
        dut.io.axi.rlast.poke(last)
      }

      driveReadRequest(valid = false)
      driveWriteRequest(valid = false)
      driveReadBeat(valid = false)
      dut.io.readResp.ready.poke(true)
      dut.io.writeResp.ready.poke(true)
      dut.io.axi.arready.poke(true)
      dut.io.axi.awready.poke(true)
      dut.io.axi.wready.poke(true)
      dut.io.axi.bvalid.poke(false)
      dut.io.axi.bresp.poke(0)
      dut.io.axi.bid.poke(0)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // An idle read request bypasses the request registers onto AR.
      driveReadRequest(valid = true, addr = 0x1004, id = 3, len = 1)
      dut.io.readReq.ready.expect(true)
      dut.io.axi.arvalid.expect(true)
      dut.io.axi.araddr.expect(0x1004)
      dut.io.axi.arid.expect(3)
      dut.io.axi.arlen.expect(1)
      dut.clock.step()
      driveReadRequest(valid = false)

      driveReadBeat(valid = true, data = 0x11112222L, id = 3, last = false)
      dut.io.readResp.valid.expect(true)
      dut.io.axi.rready.expect(true)
      dut.clock.step()

      // Retire the old burst while accepting a new request whose AR channel is stalled.
      dut.io.axi.arready.poke(false)
      driveReadBeat(valid = true, data = 0x33334444L, id = 3, last = true)
      driveReadRequest(valid = true, addr = 0x2000, id = 2)
      dut.io.readResp.valid.expect(true)
      dut.io.readResp.bits.last.expect(true)
      dut.io.readReq.ready.expect(true)
      dut.io.axi.arvalid.expect(true)
      dut.io.axi.araddr.expect(0x2000)
      dut.clock.step()

      // The bypassed request was captured, so AR remains stable after its producer withdraws valid.
      driveReadBeat(valid = false)
      driveReadRequest(valid = false)
      dut.io.axi.arvalid.expect(true)
      dut.io.axi.araddr.expect(0x2000)
      dut.clock.step()
      dut.io.axi.arready.poke(true)
      dut.io.axi.arvalid.expect(true)
      dut.io.axi.araddr.expect(0x2000)
      dut.clock.step()

      driveReadBeat(valid = true, data = 0x55556666L, id = 2, last = true)
      dut.io.readResp.valid.expect(true)
      dut.clock.step()
      driveReadBeat(valid = false)

      // Keep the existing write path intact, then turn a B response directly into a new read AR.
      driveWriteRequest(valid = true, addr = 0x3000, data = 0xdeadbeefL)
      dut.io.writeReq.ready.expect(true)
      dut.clock.step()
      driveWriteRequest(valid = false)
      dut.io.axi.awvalid.expect(true)
      dut.io.axi.awaddr.expect(0x3000)
      dut.io.axi.wvalid.expect(true)
      dut.io.axi.wdata.expect(0xdeadbeefL)
      dut.io.axi.wlast.expect(true)
      dut.clock.step()

      dut.io.axi.bvalid.poke(true)
      driveReadRequest(valid = true, addr = 0x4000, id = 1)
      dut.io.writeResp.valid.expect(true)
      dut.io.readReq.ready.expect(true)
      dut.io.axi.arvalid.expect(true)
      dut.io.axi.araddr.expect(0x4000)
      dut.clock.step()
      dut.io.axi.bvalid.poke(false)
      driveReadRequest(valid = false)

      driveReadBeat(valid = true, data = 0x77778888L, id = 1, last = true)
      dut.io.readResp.valid.expect(true)
      dut.clock.step()
    }

    println("AxiMasterSpec: PASS")
  }
}
