package top.core.backend.lsu

import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.backend.csr.PrivMode
import top.core.backend.decoder.{LsuOp, MemSize}
import top.device.DeviceConst

object LSUDeviceLoadSpec {
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

    for (lane  <- dut.io.storeAlloc.indices) {
      dut.io.storeAlloc(lane).valid.poke(false)
      dut.io.storeAlloc(lane).robIdx.poke(0)
    }
    for (lane  <- dut.io.storeCommit.indices) {
      dut.io.storeCommit(lane).valid.poke(false)
      dut.io.storeCommit(lane).sqIdx.poke(0)
      dut.io.storeCommit(lane).robIdx.poke(0)
    }
    dut.io.serializedStore.valid.poke(false)
    dut.io.serializedStore.bits.sqIdx.poke(0)
    dut.io.serializedStore.bits.robIdx.poke(0)
    for (query <- dut.io.storeIssueQuery) {
      query.valid.poke(false)
      query.robIdx.poke(0)
    }

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
    for (cfi <- dut.io.unresolvedCfi) {
      cfi.poke(false)
    }
    dut.io.csrStatus.priv.mode.poke(PrivMode.M)
    dut.io.csrStatus.mstatus.poke(0)
    dut.io.csrStatus.satp.poke(0)
  }

  private def issueMemory(
    dut:    LSU,
    robIdx: Int,
    sqIdx:  Int,
    op:     BigInt,
    addr:   BigInt,
    data:   BigInt = 0
  ): Unit = {
    dut.io.in.bits.robIdx.poke(robIdx)
    dut.io.in.bits.sqIdx.poke(sqIdx)
    dut.io.in.bits.src1.data.poke(addr)
    dut.io.in.bits.src2.data.poke(data)
    dut.io.in.bits.imm.poke(0)
    dut.io.in.bits.fuOp.poke(op)
    dut.io.in.bits.isAmo.poke(false)
    dut.io.in.bits.memSize.poke(MemSize.word)
    dut.io.in.bits.memUnsigned.poke(true)
    dut.io.in.valid.poke(true)
    dut.io.in.ready.expect(true)
    dut.clock.step()
    dut.io.in.valid.poke(false)
  }

  def main(args: Array[String]): Unit = {
    simulate(new LSU(cfg)) { dut =>
      initialize(dut)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // Resolve an older MMIO store so a younger load to the same word observes a full SQ-forwarding match.
      dut.io.storeAlloc(0).valid.poke(true)
      dut.io.storeAlloc(0).robIdx.poke(0)
      dut.io.storeAllocReady(0).expect(true)
      val storeSqIdx = dut.io.storeAllocSqIdx(0).peek().litValue.toInt
      dut.clock.step()
      dut.io.storeAlloc(0).valid.poke(false)

      val deviceAddr = DeviceConst.serialBase
      issueMemory(dut, robIdx = 0, sqIdx = storeSqIdx, op = LsuOp.store.litValue, addr = deviceAddr, data = 0x41)
      dut.io.storeUpdate.valid.expect(true)
      dut.io.storeUpdate.bits.mmio.expect(true)
      dut.clock.step()

      // The younger device load stays before LTQ/outbound despite the full forwarding match.
      issueMemory(dut, robIdx = 1, sqIdx = 0, op = LsuOp.load.litValue, addr = deviceAddr)
      dut.io.loadTxnOccupancy.expect(0)
      dut.io.dmemReq.valid.expect(false)
      dut.io.writeback.valid.expect(false)
      dut.clock.step(2)
      dut.io.loadTxnOccupancy.expect(0)
      dut.io.writeback.valid.expect(false)

      // Holding that translation must not prevent the older ROB-head serialized store from draining.
      dut.io.serializedStore.valid.poke(true)
      dut.io.serializedStore.bits.sqIdx.poke(storeSqIdx)
      dut.io.serializedStore.bits.robIdx.poke(0)
      dut.clock.step(2)
      dut.io.dmemReq.valid.expect(true)
      dut.io.dmemReq.bits.request.write.expect(true)
      dut.io.dmemReq.bits.request.cacheable.expect(false)
      dut.io.dmemReq.bits.owner.squashable.expect(false)
      val storeTxnId = dut.io.dmemReq.bits.request.txnId.peek().litValue.toInt
      dut.clock.step()

      dut.io.dmemResp.valid.poke(true)
      dut.io.dmemResp.bits.txnId.poke(storeTxnId)
      dut.io.dmemResp.bits.fault.poke(false)
      dut.io.dmemResp.ready.expect(true)
      dut.clock.step()
      dut.io.dmemResp.valid.poke(false)
      dut.io.serializedStoreSuccess.expect(true)

      // Model retirement of the completed store. Only now may the device load reserve a tag and externalize.
      dut.clock.step()
      dut.io.serializedStore.valid.poke(false)
      dut.io.robHead.poke(1)
      dut.clock.step()
      dut.io.loadTxnOccupancy.expect(1)
      dut.io.writeback.valid.expect(false)
      dut.clock.step()
      dut.io.dmemReq.valid.expect(true)
      dut.io.dmemReq.bits.request.addr.expect(deviceAddr)
      dut.io.dmemReq.bits.request.write.expect(false)
      dut.io.dmemReq.bits.request.cacheable.expect(false)
      dut.io.dmemReq.bits.owner.robIdx.expect(1)
      dut.io.dmemReq.bits.owner.squashable.expect(true)
      val loadTxnId = dut.io.dmemReq.bits.request.txnId.peek().litValue.toInt
      dut.clock.step()

      dut.io.dmemResp.valid.poke(true)
      dut.io.dmemResp.bits.txnId.poke(loadTxnId)
      dut.io.dmemResp.bits.data.poke(0x12345678)
      dut.io.dmemResp.ready.expect(true)
      dut.io.writeback.valid.expect(true)
      dut.io.writeback.bits.robIdx.expect(1)
      dut.io.writeback.bits.result.expect(0x12345678)
      dut.clock.step()
      dut.io.dmemResp.valid.poke(false)
      dut.io.loadTxnOccupancy.expect(0)
    }

    println("LSUDeviceLoadSpec: PASS")
  }
}
