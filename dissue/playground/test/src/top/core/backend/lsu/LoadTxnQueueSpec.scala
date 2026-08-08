package top.core.backend.lsu

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig

object LoadTxnQueueSpec {
  private val cfg = BackendConfig(
    robEntries = 8,
    issueQueueEntries = 2,
    loadTxnEntries = 2,
    dmemQueueEntries = 1,
    recoveryCancelPorts = 1
  )

  def main(args: Array[String]): Unit = {
    simulate(new LoadTxnQueue(cfg)) { dut =>
      def clearInputs(): Unit = {
        dut.io.alloc.valid.poke(false)
        dut.io.alloc.bits.robIdx.poke(0)
        dut.io.alloc.bits.vaddr.poke(0)
        dut.io.alloc.bits.paddr.poke(0)
        dut.io.alloc.bits.size.poke(0)
        dut.io.alloc.bits.unsigned.poke(false)
        dut.io.alloc.bits.forwardMask.poke(0)
        dut.io.alloc.bits.forwardData.poke(0)
        dut.io.markIssued.valid.poke(false)
        dut.io.markIssued.bits.poke(0)
        dut.io.abort.valid.poke(false)
        dut.io.abort.bits.poke(0)
        dut.io.complete.valid.poke(false)
        dut.io.complete.bits.data.poke(0)
        dut.io.complete.bits.fault.poke(false)
        dut.io.complete.bits.txnId.poke(0)
        dut.io.allowComplete.poke(true)
        dut.io.flush.poke(false)
        dut.io.recover.valid.poke(false)
        dut.io.recover.robIdx.poke(0)
        dut.io.robHead.poke(0)
        for (port <- dut.io.cancel.indices) {
          dut.io.cancel(port).valid.poke(false)
          dut.io.cancel(port).bits.poke(0)
        }
      }

      def allocate(
        robIdx:      Int,
        vaddr:       BigInt,
        paddr:       BigInt,
        forwardMask: Int = 0,
        forwardData: BigInt = 0
      ): Int = {
        val tag = dut.io.allocTxnId.peek().litValue.toInt
        dut.io.alloc.valid.poke(true)
        dut.io.alloc.bits.robIdx.poke(robIdx)
        dut.io.alloc.bits.vaddr.poke(vaddr)
        dut.io.alloc.bits.paddr.poke(paddr)
        dut.io.alloc.bits.size.poke(2)
        dut.io.alloc.bits.unsigned.poke(true)
        dut.io.alloc.bits.forwardMask.poke(forwardMask)
        dut.io.alloc.bits.forwardData.poke(forwardData)
        dut.io.alloc.ready.expect(true)
        dut.clock.step()
        dut.io.alloc.valid.poke(false)
        tag
      }

      def markIssued(tag: Int): Unit = {
        dut.io.markIssued.valid.poke(true)
        dut.io.markIssued.bits.poke(tag)
        dut.clock.step()
        dut.io.markIssued.valid.poke(false)
      }

      clearInputs()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // A normal response merges the saved younger-store byte before writeback.
      val mergedTag = allocate(
        robIdx = 1,
        vaddr = 0x1000,
        paddr = 0x2000,
        forwardMask = 0x2,
        forwardData = 0x0000aa00
      )
      assert(mergedTag == 0)
      markIssued(mergedTag)
      dut.io.complete.valid.poke(true)
      dut.io.complete.bits.data.poke(0x11223344)
      dut.io.complete.bits.txnId.poke(mergedTag)
      dut.io.complete.ready.expect(true)
      dut.io.writeback.valid.expect(true)
      dut.io.writeback.bits.robIdx.expect(1)
      dut.io.writeback.bits.result.expect(0x1122aa44)
      dut.io.wakeup.valid.expect(true)
      dut.io.wakeup.robIdx.expect(1)
      dut.clock.step()
      dut.io.complete.valid.poke(false)
      dut.io.occupancy.expect(0)

      // A killed issued tag remains occupied until its stale response arrives.
      val killedTag = allocate(robIdx = 3, vaddr = 0x3000, paddr = 0x4000)
      assert(killedTag == 0)
      markIssued(killedTag)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(2)
      dut.clock.step()
      dut.io.recover.valid.poke(false)
      dut.io.occupancy.expect(1)
      dut.io.allocTxnId.expect(1)
      dut.io.complete.valid.poke(true)
      dut.io.complete.bits.data.poke(0xdeadbeefL)
      dut.io.complete.bits.txnId.poke(killedTag)
      dut.io.complete.ready.expect(true)
      dut.io.responseMatch.expect(true)
      dut.io.writeback.valid.expect(false)
      dut.io.wakeup.valid.expect(false)
      dut.clock.step()
      dut.io.complete.valid.poke(false)
      dut.io.occupancy.expect(0)

      // A lower-path cancellation is the other event that permits killed-tag reuse.
      val canceledTag = allocate(robIdx = 4, vaddr = 0x5000, paddr = 0x6000)
      assert(canceledTag == 0)
      markIssued(canceledTag)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(3)
      dut.io.cancel(0).valid.poke(true)
      dut.io.cancel(0).bits.poke(canceledTag)
      dut.clock.step()
      dut.io.recover.valid.poke(false)
      dut.io.cancel(0).valid.poke(false)
      dut.io.occupancy.expect(0)
      dut.io.allocTxnId.expect(0)

      // A live response waits when another direct completion owns the LSU writeback port.
      val stalledTag = allocate(robIdx = 5, vaddr = 0x7000, paddr = 0x8000)
      markIssued(stalledTag)
      dut.io.complete.valid.poke(true)
      dut.io.complete.bits.data.poke(0x76543210)
      dut.io.complete.bits.txnId.poke(stalledTag)
      dut.io.allowComplete.poke(false)
      dut.io.complete.ready.expect(false)
      dut.io.writeback.valid.expect(false)
      dut.clock.step()
      dut.io.complete.valid.expect(true)
      dut.io.allowComplete.poke(true)
      dut.io.complete.ready.expect(true)
      dut.io.writeback.valid.expect(true)
      dut.io.writeback.bits.result.expect(0x76543210)
      dut.clock.step()
      dut.io.complete.valid.poke(false)
      dut.io.occupancy.expect(0)
    }

    println("LoadTxnQueueSpec: PASS")
  }
}
