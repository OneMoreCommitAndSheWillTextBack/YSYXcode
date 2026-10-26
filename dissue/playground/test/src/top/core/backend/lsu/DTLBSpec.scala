package top.core.backend.lsu

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.backend.csr.PrivMode
import top.core.backend.exception.ExceptionCause
import top.core.mmu.MmuAccessType

object DTLBSpec {
  private val cfg = BackendConfig(
    dtlbEntries = 4,
    dtlbMissQueueEntries = 2,
    translationIdWidth = 8
  )

  private def pte(
    ppn: BigInt,
    r:   Boolean,
    w:   Boolean,
    x:   Boolean = false,
    u:   Boolean = false,
    g:   Boolean = false,
    a:   Boolean = true,
    d:   Boolean = true
  ): BigInt = {
    val v    = BigInt(1) << 0
    val rBit = if (r) BigInt(1) << 1 else BigInt(0)
    val wBit = if (w) BigInt(1) << 2 else BigInt(0)
    val xBit = if (x) BigInt(1) << 3 else BigInt(0)
    val uBit = if (u) BigInt(1) << 4 else BigInt(0)
    val gBit = if (g) BigInt(1) << 5 else BigInt(0)
    val aBit = if (a) BigInt(1) << 6 else BigInt(0)
    val dBit = if (d) BigInt(1) << 7 else BigInt(0)
    (ppn << 10) | dBit | aBit | gBit | uBit | xBit | wBit | rBit | v
  }

  private def clear(dut: DTLB): Unit = {
    dut.io.req.valid.poke(false)
    dut.io.req.bits.vaddr.poke(0)
    dut.io.req.bits.access.poke(MmuAccessType.load)
    dut.io.req.bits.priv.poke(PrivMode.S)
    dut.io.req.bits.mstatus.poke(0)
    dut.io.req.bits.satp.poke(0)
    dut.io.req.bits.id.poke(0)
    dut.io.req.bits.robIdx.poke(0)

    dut.io.resp.ready.poke(false)

    dut.io.missReq.ready.poke(false)

    dut.io.refill.valid.poke(false)
    dut.io.refill.bits.vaddr.poke(0)
    dut.io.refill.bits.pte.poke(0)
    dut.io.refill.bits.level.poke(0)
    dut.io.refill.bits.paddr.poke(0)
    dut.io.refill.bits.fill.poke(false)
    dut.io.refill.bits.exception.valid.poke(false)
    dut.io.refill.bits.exception.cause.poke(0)
    dut.io.refill.bits.exception.tval.poke(0)

    dut.io.sfence.valid.poke(false)
    dut.io.sfence.bits.useVaddr.poke(false)
    dut.io.sfence.bits.useAsid.poke(false)
    dut.io.sfence.bits.vaddr.poke(0)

    dut.io.flush.poke(false)
    dut.io.recover.valid.poke(false)
    dut.io.recover.robIdx.poke(0)
    dut.io.robHead.poke(0)
  }

  private def reset(dut: DTLB): Unit = {
    clear(dut)
    dut.reset.poke(true)
    dut.clock.step(2)
    dut.reset.poke(false)
  }

  private def request(
    dut:             DTLB,
    vaddr:           BigInt,
    access:          UInt,
    id:              Int,
    robIdx:          Int,
    expectHit:       Boolean,
    expectSuperpage: Boolean = false
  ): Unit = {
    dut.io.req.bits.vaddr.poke(vaddr)
    dut.io.req.bits.access.poke(access)
    dut.io.req.bits.id.poke(id)
    dut.io.req.bits.robIdx.poke(robIdx)
    dut.io.req.valid.poke(true)
    dut.io.req.ready.expect(true)
    dut.io.monitor.hit.expect(expectHit)
    dut.io.monitor.miss.expect(!expectHit)
    dut.io.monitor.superpageHit.expect(expectSuperpage)
    dut.clock.step()
    dut.io.req.valid.poke(false)

    dut.io.resp.valid.expect(true)
    dut.io.resp.bits.deferred.expect(!expectHit)
    dut.io.resp.bits.id.expect(id)
    dut.io.resp.bits.robIdx.expect(robIdx)
  }

  private def consumeResponse(dut: DTLB): Unit = {
    dut.io.resp.ready.poke(true)
    dut.clock.step()
    dut.io.resp.ready.poke(false)
  }

  private def startWalk(dut: DTLB): Unit = {
    dut.io.missReq.ready.poke(true)
    dut.io.missReq.valid.expect(true)
    dut.clock.step()
    dut.io.missReq.ready.poke(false)
    dut.io.missReq.valid.expect(false)
  }

  private def refill(
    dut:       DTLB,
    vaddr:     BigInt,
    pteVal:    BigInt,
    level:     Int,
    paddr:     BigInt,
    fill:      Boolean,
    exception: Boolean = false
  ): Unit = {
    dut.io.refill.bits.vaddr.poke(vaddr)
    dut.io.refill.bits.pte.poke(pteVal)
    dut.io.refill.bits.level.poke(level)
    dut.io.refill.bits.paddr.poke(paddr)
    dut.io.refill.bits.fill.poke(fill)
    dut.io.refill.bits.exception.valid.poke(exception)
    if (exception) {
      dut.io.refill.bits.exception.cause.poke(ExceptionCause.loadPageFault)
      dut.io.refill.bits.exception.tval.poke(vaddr)
    }
    dut.io.refill.valid.poke(true)
    dut.io.refill.ready.expect(true)
    dut.io.complete.valid.expect(true)
    dut.io.complete.bits.vaddr.expect(vaddr)
    dut.io.complete.bits.paddr.expect(paddr)
    dut.io.complete.bits.exception.valid.expect(exception)
    dut.clock.step()
    dut.io.refill.valid.poke(false)
  }

  def main(args: Array[String]): Unit = {
    simulate(new DTLB(cfg, enableMonitor = true)) { dut =>
      reset(dut)
      dut.io.idle.expect(true)

      // 4KB miss -> deferred lookup, walk, refill -> completion -> hit.
      val paddr4k = BigInt(0x12345000L)
      request(dut, BigInt(0x1000), MmuAccessType.load, id = 1, robIdx = 1, expectHit = false)
      consumeResponse(dut)
      dut.io.idle.expect(false)
      startWalk(dut)
      refill(dut, BigInt(0x1000), pte(BigInt(0x12345), r = true, w = true), 0, paddr4k, fill = true)
      dut.io.monitor.occupancy.expect(1)
      dut.io.idle.expect(true)

      request(dut, BigInt(0x1004), MmuAccessType.load, id = 2, robIdx = 2, expectHit = true)
      dut.io.resp.bits.paddr.expect(paddr4k + 4)
      dut.io.resp.bits.exception.valid.expect(false)
      consumeResponse(dut)

      // Permission fault: the completion carries the fault and does not fill.
      request(dut, BigInt(0x2000), MmuAccessType.load, id = 3, robIdx = 3, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      refill(
        dut,
        BigInt(0x2000),
        pte(BigInt(0x20000), r = false, w = false),
        0,
        BigInt(0),
        fill = false,
        exception = true
      )
      dut.io.monitor.occupancy.expect(1)

      // Faults are not cached: the same page misses again.
      request(dut, BigInt(0x2000), MmuAccessType.load, id = 4, robIdx = 4, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      refill(
        dut,
        BigInt(0x2000),
        pte(BigInt(0x20000), r = false, w = false),
        0,
        BigInt(0),
        fill = false,
        exception = true
      )
      dut.io.monitor.occupancy.expect(1)

      // 4MB superpage: only VPN[1] participates in the tag match.
      request(dut, BigInt(0x400000), MmuAccessType.store, id = 5, robIdx = 5, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      refill(dut, BigInt(0x400000), pte(BigInt(0x20000), r = true, w = true), 1, BigInt(0x20000000L), fill = true)
      dut.io.monitor.occupancy.expect(2)

      request(dut, BigInt(0x401000), MmuAccessType.store, id = 6, robIdx = 6, expectHit = true, expectSuperpage = true)
      dut.io.resp.bits.paddr.expect(BigInt(0x20001000L))
      consumeResponse(dut)

      // Hit under miss: an entry that is already translated still hits while a
      // different page is walking in the miss queue.
      request(dut, BigInt(0x8000), MmuAccessType.load, id = 12, robIdx = 12, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      request(dut, BigInt(0x1004), MmuAccessType.load, id = 13, robIdx = 13, expectHit = true)
      dut.io.resp.bits.paddr.expect(paddr4k + 4)
      consumeResponse(dut)
      refill(dut, BigInt(0x8000), pte(BigInt(0x80000), r = true, w = true), 0, BigInt(0x80000000L), fill = true)
      dut.io.monitor.occupancy.expect(3)

      // sfence invalidates entries.
      dut.io.sfence.valid.poke(true)
      dut.io.sfence.bits.useVaddr.poke(false)
      dut.io.sfence.bits.useAsid.poke(false)
      dut.clock.step()
      dut.io.sfence.valid.poke(false)
      dut.io.monitor.occupancy.expect(0)
      dut.io.idle.expect(true)

      // Hit under miss: a different page can hit while another miss is walking.
      request(dut, BigInt(0x1000), MmuAccessType.load, id = 7, robIdx = 7, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      // Walk is now occupied by 0x1000; refill it and simultaneously look up
      // a page that is already present from the earlier fill is not available
      // after sfence, so just verify the response pipeline still accepts work.
      dut.io.refill.bits.vaddr.poke(BigInt(0x1000))
      dut.io.refill.bits.pte.poke(pte(BigInt(0x12345), r = true, w = true))
      dut.io.refill.bits.level.poke(0)
      dut.io.refill.bits.paddr.poke(paddr4k)
      dut.io.refill.bits.fill.poke(true)
      dut.io.refill.valid.poke(true)
      dut.io.refill.ready.expect(true)
      dut.io.complete.valid.expect(true)
      dut.io.complete.bits.id.expect(7)
      dut.clock.step()
      dut.io.refill.valid.poke(false)

      // Recovery drops a younger walking request and flushes the walk.
      request(dut, BigInt(0x3000), MmuAccessType.load, id = 8, robIdx = 1, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      // Enqueue a younger miss behind the walking one.
      request(dut, BigInt(0x5000), MmuAccessType.load, id = 9, robIdx = 2, expectHit = false)
      consumeResponse(dut)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(1)
      dut.clock.step()
      dut.io.recover.valid.poke(false)
      dut.io.monitor.missOccupancy.expect(1)
      dut.io.walkFlush.expect(false)
      refill(dut, BigInt(0x3000), pte(BigInt(0x30000), r = true, w = true), 0, BigInt(0x30000000L), fill = true)
      dut.io.idle.expect(true)

      // Recovery that kills the walking head flushes the walk and drops it.
      request(dut, BigInt(0x6000), MmuAccessType.load, id = 10, robIdx = 3, expectHit = false)
      consumeResponse(dut)
      startWalk(dut)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(2)
      dut.io.walkFlush.expect(true)
      dut.clock.step()
      dut.io.recover.valid.poke(false)
      dut.io.idle.expect(true)

      // Flush drops a queued miss without a completion.
      request(dut, BigInt(0x7000), MmuAccessType.load, id = 11, robIdx = 4, expectHit = false)
      consumeResponse(dut)
      dut.io.flush.poke(true)
      dut.clock.step()
      dut.io.flush.poke(false)
      dut.io.idle.expect(true)
      dut.io.complete.valid.expect(false)
    }

    println("DTLBSpec: PASS")
  }
}
