package top.core.mmu

import chisel3.simulator.EphemeralSimulator._
import top.core.backend.csr.PrivMode

object Sv32TranslatorTurnoverSpec {
  private val firstVaddr  = BigInt("00403004", 16)
  private val secondVaddr = BigInt("00805008", 16)
  private val leafPpn     = BigInt("12345", 16)
  private val nonLeafPte  = (BigInt(2) << 10) | 1
  private val leafPte     = (leafPpn << 10) | (1 << 6) | (1 << 1) | 1

  def main(args: Array[String]): Unit = {
    simulate(new Sv32Translator()) { dut =>
      def driveRequest(valid: Boolean, vaddr: BigInt = 0, satpPpn: BigInt = 1): Unit = {
        dut.io.req.valid.poke(valid)
        dut.io.req.bits.vaddr.poke(vaddr)
        dut.io.req.bits.access.poke(MmuAccessType.load)
        dut.io.req.bits.priv.poke(PrivMode.S)
        dut.io.req.bits.mstatus.poke(0)
        dut.io.req.bits.satp.poke((BigInt(1) << 31) | satpPpn)
      }

      def driveMemResponse(valid: Boolean, data: BigInt = 0, fault: Boolean = false): Unit = {
        dut.io.memResp.valid.poke(valid)
        dut.io.memResp.bits.data.poke(data)
        dut.io.memResp.bits.fault.poke(fault)
        dut.io.memResp.bits.txnId.poke(8)
      }

      driveRequest(valid = false)
      driveMemResponse(valid = false)
      dut.io.flush.poke(false)
      dut.io.resp.ready.poke(true)
      dut.io.memReq.ready.poke(true)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // The level-1 PTE request launches with the translation request.
      driveRequest(valid = true, vaddr = firstVaddr, satpPpn = 1)
      dut.io.req.ready.expect(true)
      dut.io.memReq.valid.expect(true)
      dut.io.memReq.bits.addr.expect(0x1004)
      dut.clock.step()
      driveRequest(valid = false)

      // A valid non-leaf PTE launches the level-0 read on its response edge.
      driveMemResponse(valid = true, data = nonLeafPte)
      dut.io.memResp.ready.expect(true)
      dut.io.memReq.valid.expect(true)
      dut.io.memReq.bits.addr.expect(0x200c)
      dut.clock.step()

      // The final PTE response bypasses; if the consumer stalls it is retained.
      dut.io.resp.ready.poke(false)
      driveMemResponse(valid = true, data = leafPte)
      driveRequest(valid = true, vaddr = secondVaddr, satpPpn = 3)
      dut.io.memResp.ready.expect(true)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.paddr.expect((leafPpn << 12) | 4)
      dut.io.req.ready.expect(false)
      dut.io.memReq.valid.expect(false)
      dut.clock.step()
      driveMemResponse(valid = false)

      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.paddr.expect((leafPpn << 12) | 4)

      // Consuming the skid response launches the next level-1 request on the same edge.
      dut.io.resp.ready.poke(true)
      dut.io.req.ready.expect(true)
      dut.io.memReq.valid.expect(true)
      dut.io.memReq.bits.addr.expect(0x3008)
      dut.clock.step()
      driveRequest(valid = false)

      dut.io.flush.poke(true)
      dut.clock.step()
      dut.io.flush.poke(false)

      // Disabled translation keeps the existing registered response behavior.
      driveRequest(valid = true, vaddr = 0x80001234L, satpPpn = 0)
      dut.io.req.bits.satp.poke(0)
      dut.io.req.bits.priv.poke(PrivMode.M)
      dut.io.req.ready.expect(true)
      dut.io.memReq.valid.expect(false)
      dut.clock.step()
      driveRequest(valid = false)
      dut.io.resp.valid.expect(true)
      dut.io.resp.bits.paddr.expect(0x80001234L)
      dut.clock.step()
    }

    println("Sv32TranslatorTurnoverSpec: PASS")
  }
}
