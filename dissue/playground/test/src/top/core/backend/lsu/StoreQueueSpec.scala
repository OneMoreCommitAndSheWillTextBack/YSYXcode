package top.core.backend.lsu

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig

object StoreQueueSpec {
  private val cfg = BackendConfig(
    robEntries = 8,
    issueQueueEntries = 2,
    storeQueueEntries = 2
  )

  def main(args: Array[String]): Unit = {
    simulate(new StoreQueue(cfg)) { dut =>
      def clearEvents(): Unit = {
        for (lane  <- 0 until cfg.dispatchWidth) {
          dut.io.alloc(lane).valid.poke(false)
          dut.io.alloc(lane).robIdx.poke(0)
        }
        dut.io.update.valid.poke(false)
        dut.io.update.bits.sqIdx.poke(0)
        dut.io.update.bits.robIdx.poke(0)
        dut.io.update.bits.vaddr.poke(0)
        dut.io.update.bits.addr.poke(0)
        dut.io.update.bits.data.poke(0)
        dut.io.update.bits.mask.poke(0)
        dut.io.update.bits.size.poke(0)
        dut.io.update.bits.mmio.poke(false)
        for (lane  <- 0 until cfg.commitWidth) {
          dut.io.commit(lane).valid.poke(false)
          dut.io.commit(lane).sqIdx.poke(0)
          dut.io.commit(lane).robIdx.poke(0)
        }
        dut.io.reserve.valid.poke(false)
        dut.io.reserve.bits.sqIdx.poke(0)
        dut.io.reserve.bits.robIdx.poke(0)
        dut.io.issue.valid.poke(false)
        dut.io.issue.bits.sqIdx.poke(0)
        dut.io.issue.bits.robIdx.poke(0)
        dut.io.response.valid.poke(false)
        dut.io.response.bits.sqIdx.poke(0)
        dut.io.response.bits.robIdx.poke(0)
        dut.io.response.bits.fault.poke(false)
        dut.io.response.bits.mmio.poke(false)
        dut.io.serializedSelect.valid.poke(false)
        dut.io.serializedSelect.bits.sqIdx.poke(0)
        dut.io.serializedSelect.bits.robIdx.poke(0)
        dut.io.query.valid.poke(false)
        dut.io.query.robIdx.poke(0)
        dut.io.query.addr.poke(0)
        dut.io.query.mask.poke(0)
        for (query <- 0 until cfg.issueQueueEntries) {
          dut.io.issueQuery(query).valid.poke(false)
          dut.io.issueQuery(query).robIdx.poke(0)
        }
        dut.io.normalDrain.ready.poke(false)
        dut.io.robHead.poke(0)
        dut.io.flush.poke(false)
        dut.io.recover.valid.poke(false)
        dut.io.recover.robIdx.poke(0)
      }

      def update(sqIdx: Int, robIdx: Int, addr: BigInt, data: BigInt, mask: Int): Unit = {
        dut.io.update.valid.poke(true)
        dut.io.update.bits.sqIdx.poke(sqIdx)
        dut.io.update.bits.robIdx.poke(robIdx)
        dut.io.update.bits.vaddr.poke(addr)
        dut.io.update.bits.addr.poke(addr)
        dut.io.update.bits.data.poke(data)
        dut.io.update.bits.mask.poke(mask)
        dut.io.update.bits.size.poke(2)
        dut.clock.step()
        dut.io.update.valid.poke(false)
      }

      def event(port: chisel3.util.ValidIO[top.core.backend.bundle.StoreQueueEvent], sqIdx: Int, robIdx: Int): Unit = {
        port.valid.poke(true)
        port.bits.sqIdx.poke(sqIdx)
        port.bits.robIdx.poke(robIdx)
        dut.clock.step()
        port.valid.poke(false)
      }

      clearEvents()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // Both dispatch lanes allocate distinct entries in one cycle.
      dut.io.alloc(0).valid.poke(true)
      dut.io.alloc(0).robIdx.poke(0)
      dut.io.alloc(1).valid.poke(true)
      dut.io.alloc(1).robIdx.poke(1)
      dut.io.allocReady(0).expect(true)
      dut.io.allocReady(1).expect(true)
      dut.io.allocSqIdx(0).expect(0)
      dut.io.allocSqIdx(1).expect(1)
      dut.clock.step()
      dut.io.alloc(0).valid.poke(false)
      dut.io.alloc(1).valid.poke(false)
      dut.io.occupancy.expect(2)

      // A third store is explicitly backpressured while the two-entry SQ is full.
      dut.io.alloc(0).valid.poke(true)
      dut.io.alloc(0).robIdx.poke(2)
      dut.io.allocReady(0).expect(false)
      dut.io.perf.fullStall.expect(true)
      dut.clock.step()
      dut.io.alloc(0).valid.poke(false)

      update(sqIdx = 0, robIdx = 0, addr = 0x1000, data = 0x11223344, mask = 0xf)
      update(sqIdx = 1, robIdx = 1, addr = 0x1001, data = 0xaa, mask = 0x1)

      // The younger byte store overrides only byte one of the older word store.
      dut.io.query.valid.poke(true)
      dut.io.query.robIdx.poke(2)
      dut.io.query.addr.poke(0x1000)
      dut.io.query.mask.poke(0xf)
      dut.io.query.unresolved.expect(false)
      dut.io.query.fullForward.expect(true)
      dut.io.query.forwardMask.expect(0xf)
      dut.io.query.forwardData.expect(0x1122aa44)
      dut.io.query.valid.poke(false)

      // Both resolved stores commit together, but drain externalization remains ordered.
      dut.io.commit(0).valid.poke(true)
      dut.io.commit(0).sqIdx.poke(0)
      dut.io.commit(0).robIdx.poke(0)
      dut.io.commit(1).valid.poke(true)
      dut.io.commit(1).sqIdx.poke(1)
      dut.io.commit(1).robIdx.poke(1)
      dut.clock.step()
      dut.io.commit(0).valid.poke(false)
      dut.io.commit(1).valid.poke(false)
      dut.io.normalDrain.valid.expect(true)
      dut.io.normalDrain.bits.sqIdx.expect(0)

      event(dut.io.reserve, sqIdx = 0, robIdx = 0)
      event(dut.io.issue, sqIdx = 0, robIdx = 0)
      dut.io.normalDrain.valid.expect(true)
      dut.io.normalDrain.bits.sqIdx.expect(1)
      event(dut.io.reserve, sqIdx = 1, robIdx = 1)
      event(dut.io.issue, sqIdx = 1, robIdx = 1)

      // The younger response may complete first, and its entry is reusable in the same cycle.
      dut.io.response.valid.poke(true)
      dut.io.response.bits.sqIdx.poke(1)
      dut.io.response.bits.robIdx.poke(1)
      dut.io.alloc(0).valid.poke(true)
      // The ROB has already reused index zero while the older sqIdx zero remains live.
      dut.io.alloc(0).robIdx.poke(0)
      dut.io.allocReady(0).expect(true)
      dut.io.allocSqIdx(0).expect(1)
      dut.clock.step()
      dut.io.response.valid.poke(false)
      dut.io.alloc(0).valid.poke(false)
      dut.io.occupancy.expect(2)

      // Selective recovery kills the speculative replacement but preserves the issued store.
      dut.io.robHead.poke(7)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(7)
      dut.clock.step()
      dut.io.recover.valid.poke(false)
      dut.io.robHead.poke(0)
      dut.io.occupancy.expect(1)

      dut.io.response.valid.poke(true)
      dut.io.response.bits.sqIdx.poke(0)
      dut.io.response.bits.robIdx.poke(0)
      dut.clock.step()
      dut.io.response.valid.poke(false)
      dut.io.occupancy.expect(0)

      // A same-cycle commit and global flush preserves the committing entry and kills its sibling.
      dut.io.alloc(0).valid.poke(true)
      dut.io.alloc(0).robIdx.poke(3)
      dut.io.alloc(1).valid.poke(true)
      dut.io.alloc(1).robIdx.poke(4)
      dut.clock.step()
      dut.io.alloc(0).valid.poke(false)
      dut.io.alloc(1).valid.poke(false)
      update(sqIdx = 0, robIdx = 3, addr = 0x2000, data = 0x55667788, mask = 0xf)
      update(sqIdx = 1, robIdx = 4, addr = 0x2004, data = 0x99aabbccL, mask = 0xf)
      dut.io.commit(0).valid.poke(true)
      dut.io.commit(0).sqIdx.poke(0)
      dut.io.commit(0).robIdx.poke(3)
      dut.io.flush.poke(true)
      dut.clock.step()
      dut.io.commit(0).valid.poke(false)
      dut.io.flush.poke(false)
      dut.io.occupancy.expect(1)
      dut.io.normalDrain.valid.expect(true)
      dut.io.normalDrain.bits.sqIdx.expect(0)

      event(dut.io.reserve, sqIdx = 0, robIdx = 3)
      event(dut.io.issue, sqIdx = 0, robIdx = 3)
      dut.io.response.valid.poke(true)
      dut.io.response.bits.sqIdx.poke(0)
      dut.io.response.bits.robIdx.poke(3)
      dut.clock.step()
      dut.io.response.valid.poke(false)
      dut.io.occupancy.expect(0)
    }

    println("StoreQueueSpec: PASS")
  }
}
