package top.core.frontend

import chisel3.simulator.EphemeralSimulator._
import top.core.backend.csr.PrivMode

object IRefillMmuSpec {
  private val line0 = BigInt("0123456789abcdef", 16)
  private val line1 = BigInt("fedcba9876543210", 16)

  def main(args: Array[String]): Unit = {
    simulate(new ICacheRefillMmu()) { dut =>
      def driveRefillRequest(valid: Boolean, address: BigInt = 0): Unit = {
        dut.io.refillReq.valid.poke(valid)
        dut.io.refillReq.bits.addr.poke(address)
      }

      def drivePhysicalResponse(valid: Boolean, data: BigInt = 0): Unit = {
        dut.io.physResp.valid.poke(valid)
        dut.io.physResp.bits.data.poke(data)
        dut.io.physResp.bits.exception.valid.poke(false)
        dut.io.physResp.bits.exception.cause.poke(0)
        dut.io.physResp.bits.exception.tval.poke(0)
      }

      driveRefillRequest(valid = false)
      drivePhysicalResponse(valid = false)
      dut.io.refillResp.ready.poke(true)
      dut.io.physReq.ready.poke(true)
      dut.io.ptwReq.ready.poke(true)
      dut.io.ptwResp.valid.poke(false)
      dut.io.ptwResp.bits.data.poke(0)
      dut.io.ptwResp.bits.fault.poke(false)
      dut.io.ptwResp.bits.txnId.poke(0)
      dut.io.csrStatus.priv.mode.poke(PrivMode.M)
      dut.io.csrStatus.mretTarget.poke(0)
      dut.io.csrStatus.sretTarget.poke(0)
      dut.io.csrStatus.mstatus.poke(0)
      dut.io.csrStatus.satp.poke(0)
      dut.io.csrStatus.mtvec.poke(0)
      dut.io.csrStatus.stvec.poke(0)
      dut.io.csrStatus.medeleg.poke(0)
      dut.io.csrStatus.mideleg.poke(0)
      dut.io.csrStatus.mie.poke(0)
      dut.io.csrStatus.mip.poke(0)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // The first request passes straight through in bare mode.
      driveRefillRequest(valid = true, address = 0x1000)
      dut.io.refillReq.ready.expect(true)
      dut.io.physReq.valid.expect(true)
      dut.io.physReq.bits.addr.expect(0x1000)
      dut.clock.step()
      driveRefillRequest(valid = false)

      // Retire the old response and launch the next physical request in the same cycle.
      drivePhysicalResponse(valid = true, data = line0)
      driveRefillRequest(valid = true, address = 0x2000)
      dut.io.refillResp.valid.expect(true)
      dut.io.refillReq.ready.expect(true)
      dut.io.physReq.valid.expect(true)
      dut.io.physReq.bits.addr.expect(0x2000)
      dut.clock.step()
      drivePhysicalResponse(valid = false)
      driveRefillRequest(valid = false)

      drivePhysicalResponse(valid = true, data = line1)
      dut.io.refillResp.valid.expect(true)
      dut.io.refillResp.bits.data.expect(line1)
      dut.clock.step()
      drivePhysicalResponse(valid = false)

      // Turnover still accepts the next refill when the physical request port stalls, then replays it from its buffer.
      driveRefillRequest(valid = true, address = 0x3000)
      dut.io.refillReq.ready.expect(true)
      dut.io.physReq.valid.expect(true)
      dut.clock.step()
      driveRefillRequest(valid = false)

      dut.io.physReq.ready.poke(false)
      drivePhysicalResponse(valid = true, data = line0)
      driveRefillRequest(valid = true, address = 0x4000)
      dut.io.refillResp.valid.expect(true)
      dut.io.refillReq.ready.expect(true)
      dut.io.physReq.valid.expect(true)
      dut.io.physReq.bits.addr.expect(0x4000)
      dut.clock.step()
      drivePhysicalResponse(valid = false)
      driveRefillRequest(valid = false)

      dut.io.physReq.ready.poke(true)
      dut.io.physReq.valid.expect(true)
      dut.io.physReq.bits.addr.expect(0x4000)
      dut.clock.step()

      drivePhysicalResponse(valid = true, data = line1)
      dut.io.refillResp.valid.expect(true)
      dut.clock.step()
    }

    println("IRefillMmuSpec: PASS")
  }
}
