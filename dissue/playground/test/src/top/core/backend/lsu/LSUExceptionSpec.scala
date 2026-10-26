package top.core.backend.lsu

import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.backend.csr.PrivMode
import top.core.backend.decoder.{LsuOp, MemSize}
import top.core.backend.exception.ExceptionCause
import top.core.bundle.DataMemKind

object LSUExceptionSpec {
  private val cfg = BackendConfig(
    robEntries = 8,
    issueQueueEntries = 2,
    loadTxnEntries = 2,
    storeQueueEntries = 4,
    storeTxnEntries = 2,
    dmemQueueEntries = 2,
    recoveryCancelPorts = 1
  )

  private def initialize(dut: LSU): Unit = {
    dut.io.in.valid.poke(false)
    dut.io.in.bits.robIdx.poke(0)
    dut.io.in.bits.sqIdx.poke(0)
    dut.io.in.bits.imm.poke(0)
    dut.io.in.bits.src1.data.poke(0)
    dut.io.in.bits.src2.data.poke(0)
    dut.io.in.bits.fuOp.poke(0)
    dut.io.in.bits.isAmo.poke(false)
    dut.io.in.bits.memSize.poke(MemSize.word)
    dut.io.in.bits.memUnsigned.poke(true)

    for (lane <- dut.io.storeAlloc.indices) {
      dut.io.storeAlloc(lane).valid.poke(false)
      dut.io.storeAlloc(lane).robIdx.poke(0)
    }
    for (lane <- dut.io.storeCommit.indices) {
      dut.io.storeCommit(lane).valid.poke(false)
      dut.io.storeCommit(lane).sqIdx.poke(0)
      dut.io.storeCommit(lane).robIdx.poke(0)
    }
    dut.io.serializedStore.valid.poke(false)
    dut.io.serializedStore.bits.sqIdx.poke(0)
    dut.io.serializedStore.bits.robIdx.poke(0)

    dut.io.dmemReq.ready.poke(true)
    dut.io.dmemResp.valid.poke(false)
    dut.io.dmemResp.bits.data.poke(0)
    dut.io.dmemResp.bits.fault.poke(false)
    dut.io.dmemResp.bits.txnId.poke(0)
    for (cancel <- dut.io.dmemCancel) {
      cancel.valid.poke(false)
      cancel.bits.poke(0)
    }

    dut.io.flush.poke(false)
    dut.io.recover.valid.poke(false)
    dut.io.recover.robIdx.poke(0)
    dut.io.robHead.poke(0)
    dut.io.csrStatus.priv.mode.poke(PrivMode.S)
    dut.io.csrStatus.mstatus.poke(0)
    dut.io.csrStatus.satp.poke(0x80000000L)
    dut.io.sfence.valid.poke(false)
    dut.io.sfence.bits.useVaddr.poke(false)
    dut.io.sfence.bits.useAsid.poke(false)
    dut.io.sfence.bits.vaddr.poke(0)
  }

  private def reset(dut: LSU): Unit = {
    initialize(dut)
    dut.reset.poke(true)
    dut.clock.step(2)
    dut.reset.poke(false)
  }

  private def issueMemory(dut: LSU, robIdx: Int, op: BigInt, addr: BigInt, atomic: Boolean): Unit = {
    dut.io.in.bits.robIdx.poke(robIdx)
    dut.io.in.bits.src1.data.poke(addr)
    dut.io.in.bits.src2.data.poke(0)
    dut.io.in.bits.imm.poke(0)
    dut.io.in.bits.fuOp.poke(op)
    dut.io.in.bits.isAmo.poke(atomic)
    dut.io.in.valid.poke(true)
    dut.io.in.ready.expect(true)
    dut.clock.step()
    dut.io.in.valid.poke(false)
  }

  private def waitUntil(dut: LSU, maxSteps: Int = 16)(cond: => Boolean): Unit = {
    var steps = 0
    while (!cond && steps < maxSteps) {
      dut.clock.step()
      steps += 1
    }
    require(cond, s"condition not met after $maxSteps cycles")
  }

  private def answerInvalidRootPte(dut: LSU, expectedAddr: BigInt): Unit = {
    waitUntil(dut)(dut.io.dmemReq.valid.peek().litToBoolean)
    dut.io.dmemReq.bits.request.kind.expect(DataMemKind.ptw)
    dut.io.dmemReq.bits.request.addr.expect(expectedAddr)
    dut.io.dmemReq.bits.request.write.expect(false)
    dut.io.dmemResp.bits.txnId.poke(dut.io.dmemReq.bits.request.txnId.peek())
    dut.io.dmemResp.bits.data.poke(0)
    dut.io.dmemResp.bits.fault.poke(false)
    dut.io.dmemResp.valid.poke(true)
    dut.io.dmemResp.ready.expect(true)
    dut.clock.step()
    dut.io.dmemResp.valid.poke(false)
  }

  private def expectException(dut: LSU, robIdx: Int, cause: BigInt, vaddr: BigInt): Unit = {
    waitUntil(dut)(dut.io.writeback.valid.peek().litToBoolean)
    dut.io.writeback.bits.robIdx.expect(robIdx)
    dut.io.writeback.bits.exception.valid.expect(true)
    dut.io.writeback.bits.exception.cause.expect(cause)
    dut.io.writeback.bits.exception.tval.expect(vaddr)
    dut.io.loadTxnOccupancy.expect(0)
  }

  private def expectNoDataRequest(dut: LSU): Unit = {
    for (_ <- 0 until 8) {
      dut.io.dmemReq.valid.expect(false)
      dut.io.loadTxnOccupancy.expect(0)
      dut.clock.step()
    }
  }

  private def pageFaultLoad(): Unit = {
    simulate(new LSU(cfg)) { dut =>
      reset(dut)
      val vaddr = BigInt(0x00400000L)
      issueMemory(dut, robIdx = 1, op = LsuOp.load.litValue, addr = vaddr, atomic = false)
      answerInvalidRootPte(dut, expectedAddr = 4)
      expectException(dut, robIdx = 1, ExceptionCause.loadPageFault.litValue, vaddr)
      expectNoDataRequest(dut)
    }
  }

  private def pageFaultAmo(): Unit = {
    simulate(new LSU(cfg)) { dut =>
      reset(dut)
      val vaddr = BigInt(0x00400000L)
      issueMemory(dut, robIdx = 0, op = LsuOp.amoAdd.litValue, addr = vaddr, atomic = true)
      answerInvalidRootPte(dut, expectedAddr = 4)
      expectException(dut, robIdx = 0, ExceptionCause.storePageFault.litValue, vaddr)
      expectNoDataRequest(dut)
    }
  }

  def main(args: Array[String]): Unit = {
    pageFaultLoad()
    pageFaultAmo()
    println("LSUExceptionSpec: PASS")
  }
}
