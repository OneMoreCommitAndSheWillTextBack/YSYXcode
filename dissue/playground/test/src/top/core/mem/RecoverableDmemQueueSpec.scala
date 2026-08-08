package top.core.mem

import chisel3._
import chisel3.simulator.EphemeralSimulator._

object RecoverableDmemQueueSpec {
  private val addrWidth   = 32
  private val dataWidth   = 32
  private val robIdxWidth = 3
  private val robEntries  = 8
  private val depth       = 3

  private val loadTag0  = 0
  private val loadTag1  = 1
  private val storeTag0 = 4
  private val storeTag1 = 5

  def main(args: Array[String]): Unit = {
    simulate(new RecoverableDmemQueue(addrWidth, dataWidth, robIdxWidth, robEntries, depth)) { dut =>
      def clearRecovery(): Unit = {
        dut.io.flush.poke(false)
        dut.io.recover.valid.poke(false)
        dut.io.recover.robIdx.poke(0)
        dut.io.robHead.poke(0)
      }

      def driveEnqueue(
        valid:      Boolean,
        txnId:      Int = 0,
        robIdx:     Int = 0,
        squashable: Boolean = true,
        addr:       BigInt = 0
      ): Unit = {
        dut.io.enq.valid.poke(valid)
        dut.io.enq.bits.request.addr.poke(addr)
        dut.io.enq.bits.request.write.poke(false)
        dut.io.enq.bits.request.size.poke(2)
        dut.io.enq.bits.request.unsigned.poke(false)
        dut.io.enq.bits.request.wdata.poke(0)
        dut.io.enq.bits.request.wmask.poke(0)
        dut.io.enq.bits.request.txnId.poke(txnId)
        dut.io.enq.bits.request.cacheable.poke(true)
        dut.io.enq.bits.request.kind.poke(0)
        dut.io.enq.bits.owner.squashable.poke(squashable)
        dut.io.enq.bits.owner.robIdx.poke(robIdx)
      }

      def enqueue(txnId: Int, robIdx: Int, squashable: Boolean, addr: BigInt): Unit = {
        driveEnqueue(valid = true, txnId = txnId, robIdx = robIdx, squashable = squashable, addr = addr)
        dut.io.enq.ready.expect(true)
        dut.clock.step()
        driveEnqueue(valid = false)
      }

      def expectNoCancel(): Unit = {
        for (port <- dut.io.cancel.indices) {
          dut.io.cancel(port).valid.expect(false)
        }
      }

      driveEnqueue(valid = false)
      dut.io.deq.ready.poke(false)
      clearRecovery()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // A stalled speculative head killed by selective recovery is revoked and canceled. A retained committed entry
      // behind it becomes the next visible request after compaction.
      enqueue(loadTag0, robIdx = 6, squashable = true, addr = 0x1000)
      enqueue(storeTag0, robIdx = 3, squashable = false, addr = 0x2000)
      dut.io.deq.valid.expect(true)
      dut.io.deq.bits.request.txnId.expect(loadTag0)

      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(4)
      dut.io.deq.valid.expect(false)
      dut.io.cancel(0).valid.expect(true)
      dut.io.cancel(0).bits.expect(loadTag0)
      dut.io.cancel(1).valid.expect(false)
      dut.clock.step()

      clearRecovery()
      expectNoCancel()
      dut.io.deq.valid.expect(true)
      dut.io.deq.bits.request.txnId.expect(storeTag0)
      dut.io.deq.bits.request.addr.expect(0x2000)
      dut.io.deq.ready.poke(true)
      dut.clock.step()
      dut.io.deq.ready.poke(false)
      dut.io.empty.expect(true)

      // Global flush has the same revocation semantics for a stalled squashable request.
      enqueue(loadTag1, robIdx = 7, squashable = true, addr = 0x3000)
      dut.clock.step()
      dut.io.deq.valid.expect(true)
      dut.io.flush.poke(true)
      dut.io.deq.valid.expect(false)
      dut.io.cancel(0).valid.expect(true)
      dut.io.cancel(0).bits.expect(loadTag1)
      dut.clock.step()
      dut.io.flush.poke(false)
      expectNoCancel()
      dut.io.empty.expect(true)

      // A committed request is irreversible: it remains valid and bit-stable while stalled across both forms of
      // recovery, and never emits cancellation.
      enqueue(storeTag1, robIdx = 2, squashable = false, addr = 0x4000)
      dut.clock.step()
      dut.io.deq.valid.expect(true)
      dut.io.deq.bits.request.txnId.expect(storeTag1)
      dut.io.flush.poke(true)
      dut.io.deq.valid.expect(true)
      dut.io.deq.bits.request.txnId.expect(storeTag1)
      expectNoCancel()
      dut.clock.step()

      dut.io.flush.poke(false)
      dut.io.recover.valid.poke(true)
      dut.io.recover.robIdx.poke(0)
      dut.io.deq.valid.expect(true)
      dut.io.deq.bits.request.txnId.expect(storeTag1)
      expectNoCancel()
      dut.clock.step()

      clearRecovery()
      dut.io.deq.valid.expect(true)
      dut.io.deq.bits.request.txnId.expect(storeTag1)
      dut.io.deq.ready.poke(true)
      dut.clock.step()
      dut.io.empty.expect(true)
    }

    println("RecoverableDmemQueueSpec: PASS")
  }
}
