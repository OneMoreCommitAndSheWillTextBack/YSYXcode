package top.core.backend.issue

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.backend.bundle.{IssuePacket, IssuePortStatus, IssueWakeup}
import top.core.backend.decoder.{FuType, LsuOp}

object IssueQueueSpec {
  private val cfg = BackendConfig(
    issueWidth = 1,
    commitWidth = 1,
    robEntries = 8,
    intIssueWidth = 1,
    writebackWidth = 2,
    issueQueueEntries = 2
  )

  def main(args: Array[String]): Unit = {
    simulate(new IssueQueue(cfg)) { dut =>
      def initInputs(): Unit = {
        for (lane <- 0 until cfg.dispatchWidth) {
          dut.io.enq(lane).valid.poke(false)
          dut.io.enq(lane).bits.poke(0.U.asTypeOf(new IssuePacket(cfg)))
        }
        for (port <- 0 until cfg.writebackWidth) {
          dut.io.wakeup(port).poke(0.U.asTypeOf(new IssueWakeup(cfg)))
        }
        for (port <- 0 until cfg.commitWidth) {
          dut.io.commitWakeup(port).poke(0.U.asTypeOf(new IssueWakeup(cfg)))
        }
        for (port <- 0 until cfg.intIssueWidth) {
          dut.io.intStatus(port).poke(0.U.asTypeOf(new IssuePortStatus))
          dut.io.intIssue(port).ready.poke(false)
        }
        dut.io.memStatus.poke(0.U.asTypeOf(new IssuePortStatus))
        dut.io.memStatus.lsu.poke(true)
        dut.io.memStatus.load.poke(true)
        dut.io.robHead.poke(0)
        dut.io.unresolvedAmo.foreach(_.poke(false))
        dut.io.csrQuery.foreach(_.hasOlderSameAddrWriter.poke(false))
        dut.io.memIssue.ready.poke(false)
        dut.io.flush.poke(false)
        dut.io.recover.valid.poke(false)
        dut.io.recover.robIdx.poke(0)
        dut.io.hold.poke(false)
        dut.io.robDoneOperandCount.poke(0)
      }

      def enqueue(robIdx: Int, operandsReady: Boolean = true): Unit = {
        val enq = dut.io.enq(0)
        enq.bits.poke(0.U.asTypeOf(new IssuePacket(cfg)))
        enq.bits.legal.poke(true)
        enq.bits.robIdx.poke(robIdx)
        enq.bits.src1.ready.poke(operandsReady)
        enq.bits.src2.ready.poke(true)
        enq.bits.fuType.poke(FuType.lsu)
        enq.bits.fuOp.poke(LsuOp.load)
        enq.bits.isLoad.poke(true)
        enq.valid.poke(true)
        enq.ready.expect(true)
        dut.clock.step()
        enq.valid.poke(false)
      }

      initInputs()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      enqueue(robIdx = 2)
      dut.io.memIssue.valid.expect(true)
      dut.io.memIssue.bits.robIdx.expect(2)
      dut.io.memIssue.ready.poke(true)
      dut.clock.step()
      dut.io.memIssue.ready.poke(false)
      dut.io.memIssue.valid.expect(false)

      enqueue(robIdx = 3)
      enqueue(robIdx = 4)
      dut.io.memIssue.valid.expect(true)
      dut.io.memIssue.bits.robIdx.expect(3)
      dut.io.memIssue.ready.poke(true)
      dut.clock.step()
      dut.io.memIssue.valid.expect(true)
      dut.io.memIssue.bits.robIdx.expect(4)
      dut.clock.step()
      dut.io.memIssue.ready.poke(false)
      dut.io.memIssue.valid.expect(false)

      enqueue(robIdx = 5, operandsReady = false)
      enqueue(robIdx = 6)
      dut.io.memIssue.valid.expect(false)
    }

    println("IssueQueueSpec: PASS")
  }
}
