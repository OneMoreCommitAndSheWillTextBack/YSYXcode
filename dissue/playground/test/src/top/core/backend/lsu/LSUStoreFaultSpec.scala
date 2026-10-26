package top.core.backend.lsu

import chisel3.simulator.EphemeralSimulator._
import top.config.BackendConfig
import top.core.backend.csr.PrivMode
import top.core.backend.decoder.{LsuOp, MemSize}
import top.core.backend.exception.ExceptionCause
import top.core.bundle.DataMemKind
import top.device.DeviceConst

object LSUStoreFaultSpec {
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
    dut.io.csrStatus.priv.mode.poke(PrivMode.M)
    dut.io.csrStatus.mstatus.poke(0)
    dut.io.csrStatus.satp.poke(0)
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

  private def allocateStore(dut: LSU, robIdx: Int): Int = {
    dut.io.storeAlloc(0).valid.poke(true)
    dut.io.storeAlloc(0).robIdx.poke(robIdx)
    dut.io.storeAllocReady(0).expect(true)
    val sqIdx = dut.io.storeAllocSqIdx(0).peek().litValue.toInt
    dut.clock.step()
    dut.io.storeAlloc(0).valid.poke(false)
    sqIdx
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

  private def waitUntil(dut: LSU, maxSteps: Int = 32)(cond: => Boolean): Unit = {
    var steps = 0
    while (!cond && steps < maxSteps) {
      dut.clock.step()
      steps += 1
    }
    require(cond, s"condition not met after $maxSteps cycles")
  }

  private def resolveOlderMmioStore(dut: LSU, sqIdx: Int, addr: BigInt): Unit = {
    issueMemory(dut, robIdx = 0, sqIdx = sqIdx, op = LsuOp.store.litValue, addr = addr, data = 0x41)
    waitUntil(dut)(dut.io.storeUpdate.valid.peek().litToBoolean)
    dut.io.storeUpdate.bits.sqIdx.expect(sqIdx)
    dut.io.storeUpdate.bits.robIdx.expect(0)
    dut.io.storeUpdate.bits.mmio.expect(true)
  }

  private def selectSerializedStore(dut: LSU, sqIdx: Int): Unit = {
    dut.io.serializedStore.valid.poke(true)
    dut.io.serializedStore.bits.sqIdx.poke(sqIdx)
    dut.io.serializedStore.bits.robIdx.poke(0)
  }

  private def acceptMmioRequestAndPtw(dut: LSU, pte: BigInt): Int = {
    var storeTxnId = -1
    var ptwTxnId   = -1
    var steps      = 0
    while ((storeTxnId < 0 || ptwTxnId < 0) && steps < 32) {
      if (dut.io.dmemReq.valid.peek().litToBoolean) {
        if (dut.io.dmemReq.bits.request.write.peek().litToBoolean) {
          require(storeTxnId < 0, "duplicate MMIO store request")
          dut.io.dmemReq.bits.request.kind.expect(DataMemKind.normal)
          dut.io.dmemReq.bits.request.cacheable.expect(false)
          dut.io.dmemReq.bits.owner.robIdx.expect(0)
          storeTxnId = dut.io.dmemReq.bits.request.txnId.peek().litValue.toInt
        } else {
          require(ptwTxnId < 0, "duplicate PTW request")
          dut.io.dmemReq.bits.request.kind.expect(DataMemKind.ptw)
          dut.io.dmemReq.bits.request.addr.expect(4)
          ptwTxnId = dut.io.dmemReq.bits.request.txnId.peek().litValue.toInt
        }
      }
      dut.clock.step()
      steps += 1
    }
    require(storeTxnId >= 0, "MMIO store request was not externalized")
    require(ptwTxnId >= 0, "PTW request was not externalized")

    dut.io.dmemResp.bits.txnId.poke(ptwTxnId)
    dut.io.dmemResp.bits.data.poke(pte)
    dut.io.dmemResp.bits.fault.poke(false)
    dut.io.dmemResp.valid.poke(true)
    dut.io.dmemResp.ready.expect(true)
    dut.clock.step()
    dut.io.dmemResp.valid.poke(false)
    storeTxnId
  }

  private def checkFaultWritebackCollision(
    dut:               LSU,
    storeTxnId:        Int,
    mmioVaddr:         BigInt,
    youngerPageFault:  Boolean,
    youngerFaultVaddr: BigInt = 0
  ): Unit = {
    waitUntil(dut)(
      dut.io.writeback.valid.peek().litToBoolean && dut.io.writeback.bits.robIdx.peek().litValue == 1
    )
    dut.io.writeback.bits.exception.valid.expect(youngerPageFault)
    if (youngerPageFault) {
      dut.io.writeback.bits.exception.cause.expect(ExceptionCause.loadPageFault)
      dut.io.writeback.bits.exception.tval.expect(youngerFaultVaddr)
    }

    dut.io.dmemResp.bits.txnId.poke(storeTxnId)
    dut.io.dmemResp.bits.data.poke(0)
    dut.io.dmemResp.bits.fault.poke(true)
    dut.io.dmemResp.valid.poke(true)
    dut.io.dmemResp.ready.expect(false)
    dut.io.storeResponse.valid.expect(false)
    dut.io.writeback.valid.expect(true)
    dut.io.writeback.bits.robIdx.expect(1)
    dut.io.serializedStoreSuccess.expect(false)
    dut.clock.step()

    dut.io.dmemResp.ready.expect(true)
    dut.io.storeResponse.valid.expect(true)
    dut.io.storeResponse.bits.robIdx.expect(0)
    dut.io.storeResponse.bits.fault.expect(true)
    dut.io.storeResponse.bits.mmio.expect(true)
    dut.io.writeback.valid.expect(true)
    dut.io.writeback.bits.robIdx.expect(0)
    dut.io.writeback.bits.storeAddr.expect(mmioVaddr)
    dut.io.writeback.bits.exception.valid.expect(true)
    dut.io.writeback.bits.exception.cause.expect(ExceptionCause.storeAccessFault)
    dut.io.writeback.bits.exception.tval.expect(mmioVaddr)
    dut.io.serializedStoreSuccess.expect(false)
    dut.clock.step()

    dut.io.dmemResp.valid.poke(false)
    dut.io.dmemResp.bits.fault.poke(false)
    dut.io.serializedStore.valid.poke(false)
    dut.io.storeResponse.valid.expect(false)
    dut.io.writeback.valid.expect(false)
  }

  private def normalStoreCollision(): Unit = {
    simulate(new LSU(cfg)) { dut =>
      reset(dut)
      val mmioSqIdx    = allocateStore(dut, robIdx = 0)
      val youngerSqIdx = allocateStore(dut, robIdx = 1)
      val mmioAddr     = DeviceConst.serialBase
      resolveOlderMmioStore(dut, mmioSqIdx, mmioAddr)

      val youngerVaddr = BigInt(0x00400000L)
      dut.io.csrStatus.priv.mode.poke(PrivMode.S)
      dut.io.csrStatus.satp.poke(0x80000000L)
      issueMemory(
        dut,
        robIdx = 1,
        sqIdx = youngerSqIdx,
        op = LsuOp.store.litValue,
        addr = youngerVaddr,
        data = 0x55
      )
      selectSerializedStore(dut, mmioSqIdx)
      val storeTxnId   = acceptMmioRequestAndPtw(dut, pte = BigInt(0x200000c7L))
      checkFaultWritebackCollision(dut, storeTxnId, mmioAddr, youngerPageFault = false)
    }
  }

  private def translationExceptionCollision(): Unit = {
    simulate(new LSU(cfg)) { dut =>
      reset(dut)
      val mmioSqIdx = allocateStore(dut, robIdx = 0)
      val mmioAddr  = DeviceConst.serialBase
      resolveOlderMmioStore(dut, mmioSqIdx, mmioAddr)

      val youngerVaddr = BigInt(0x00400000L)
      dut.io.csrStatus.priv.mode.poke(PrivMode.S)
      dut.io.csrStatus.satp.poke(0x80000000L)
      issueMemory(dut, robIdx = 1, sqIdx = 0, op = LsuOp.load.litValue, addr = youngerVaddr)
      selectSerializedStore(dut, mmioSqIdx)
      val storeTxnId   = acceptMmioRequestAndPtw(dut, pte = 0)
      checkFaultWritebackCollision(
        dut,
        storeTxnId,
        mmioAddr,
        youngerPageFault = true,
        youngerFaultVaddr = youngerVaddr
      )
    }
  }

  def main(args: Array[String]): Unit = {
    normalStoreCollision()
    translationExceptionCollision()
    println("LSUStoreFaultSpec: PASS")
  }
}
