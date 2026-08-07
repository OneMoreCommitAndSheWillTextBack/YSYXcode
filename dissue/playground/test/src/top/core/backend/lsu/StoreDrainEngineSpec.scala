package top.core.backend.lsu

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.simulator.Exceptions
import top.config.BackendConfig

object StoreDrainEngineSpec {
  private val cfg = BackendConfig(
    robEntries = 8,
    issueQueueEntries = 2,
    storeQueueEntries = 4,
    storeTxnEntries = 2
  )

  private def initialize(dut: StoreDrainEngine): Unit = {
    dut.io.normal.valid.poke(false)
    dut.io.normal.bits.sqIdx.poke(0)
    dut.io.normal.bits.robIdx.poke(0)
    dut.io.normal.bits.vaddr.poke(0)
    dut.io.normal.bits.addr.poke(0)
    dut.io.normal.bits.data.poke(0)
    dut.io.normal.bits.mask.poke(0)
    dut.io.normal.bits.size.poke(0)
    dut.io.normal.bits.mmio.poke(false)
    dut.io.serialized.valid.poke(false)
    dut.io.serialized.bits.sqIdx.poke(0)
    dut.io.serialized.bits.robIdx.poke(0)
    dut.io.serialized.bits.vaddr.poke(0)
    dut.io.serialized.bits.addr.poke(0)
    dut.io.serialized.bits.data.poke(0)
    dut.io.serialized.bits.mask.poke(0)
    dut.io.serialized.bits.size.poke(0)
    dut.io.serialized.bits.mmio.poke(false)
    dut.io.serializedCanStart.poke(false)
    dut.io.request.ready.poke(false)
    dut.io.externalFire.valid.poke(false)
    dut.io.externalFire.bits.poke(0)
    dut.io.response.valid.poke(false)
    dut.io.response.bits.data.poke(0)
    dut.io.response.bits.fault.poke(false)
    dut.io.response.bits.txnId.poke(0)
    dut.io.allowFaultWriteback.poke(true)
  }

  private def reset(dut: StoreDrainEngine): Unit = {
    initialize(dut)
    dut.reset.poke(true)
    dut.clock.step(2)
    dut.reset.poke(false)
  }

  private def captureNormal(dut: StoreDrainEngine, sqIdx: Int, robIdx: Int, addr: BigInt): Unit = {
    dut.io.normal.valid.poke(true)
    dut.io.normal.bits.sqIdx.poke(sqIdx)
    dut.io.normal.bits.robIdx.poke(robIdx)
    dut.io.normal.bits.vaddr.poke(addr)
    dut.io.normal.bits.addr.poke(addr)
    dut.io.normal.bits.data.poke(0x11223344 + sqIdx)
    dut.io.normal.bits.mask.poke(0xf)
    dut.io.normal.bits.size.poke(2)
    dut.io.normal.bits.mmio.poke(false)
    dut.io.normal.ready.expect(true)
    dut.clock.step()
    dut.io.normal.valid.poke(false)
  }

  private def fireHeldRequest(dut: StoreDrainEngine, tag: Int, sqIdx: Int): Unit = {
    dut.io.request.valid.expect(true)
    dut.io.request.bits.request.txnId.expect(tag)
    dut.io.request.bits.owner.squashable.expect(false)
    dut.io.request.bits.request.write.expect(true)
    dut.io.request.ready.poke(false)
    dut.clock.step(2)
    dut.io.request.valid.expect(true)
    dut.io.request.bits.request.txnId.expect(tag)
    dut.io.request.bits.owner.squashable.expect(false)
    dut.io.request.ready.poke(true)
    dut.clock.step()
    dut.io.request.ready.poke(false)
    dut.io.externalFire.valid.poke(true)
    dut.io.externalFire.bits.poke(tag)
    dut.io.issue.valid.expect(true)
    dut.io.issue.bits.sqIdx.expect(sqIdx)
    dut.clock.step()
    dut.io.externalFire.valid.poke(false)
  }

  def main(args: Array[String]): Unit = {
    simulate(new StoreDrainEngine(cfg)) { dut =>
      reset(dut)

      captureNormal(dut, sqIdx = 0, robIdx = 0, addr = 0x1000)
      fireHeldRequest(dut, tag = 4, sqIdx = 0)
      captureNormal(dut, sqIdx = 1, robIdx = 1, addr = 0x2000)
      fireHeldRequest(dut, tag = 5, sqIdx = 1)
      dut.io.normalOutstanding.expect(true)

      // Store slots retain their sqIdx mappings even when responses return younger-first.
      dut.io.response.valid.poke(true)
      dut.io.response.bits.txnId.poke(5)
      dut.io.complete.valid.expect(true)
      dut.io.complete.bits.sqIdx.expect(1)
      dut.clock.step()
      dut.io.response.bits.txnId.poke(4)
      dut.io.complete.valid.expect(true)
      dut.io.complete.bits.sqIdx.expect(0)
      dut.clock.step()
      dut.io.response.valid.poke(false)
      dut.io.idle.expect(true)

      // An MMIO response fault is held until the precise writeback path can accept it.
      dut.io.serialized.valid.poke(true)
      dut.io.serialized.bits.sqIdx.poke(2)
      dut.io.serialized.bits.robIdx.poke(2)
      dut.io.serialized.bits.vaddr.poke(0x3000)
      dut.io.serialized.bits.addr.poke(0x3000)
      dut.io.serialized.bits.data.poke(0xaabbccddL)
      dut.io.serialized.bits.mask.poke(0xf)
      dut.io.serialized.bits.size.poke(2)
      dut.io.serialized.bits.mmio.poke(true)
      dut.io.serializedCanStart.poke(true)
      dut.clock.step()
      dut.io.serialized.valid.poke(false)
      dut.io.serializedCanStart.poke(false)
      dut.io.request.valid.expect(true)
      dut.io.request.bits.request.txnId.expect(4)
      dut.io.request.bits.request.cacheable.expect(false)
      dut.io.request.ready.poke(true)
      dut.clock.step()
      dut.io.request.ready.poke(false)
      dut.io.externalFire.valid.poke(true)
      dut.io.externalFire.bits.poke(4)
      dut.clock.step()
      dut.io.externalFire.valid.poke(false)
      dut.io.response.valid.poke(true)
      dut.io.response.bits.txnId.poke(4)
      dut.io.response.bits.fault.poke(true)
      dut.io.allowFaultWriteback.poke(false)
      dut.io.response.ready.expect(false)
      dut.io.serializedFault.valid.expect(false)
      dut.clock.step()
      dut.io.allowFaultWriteback.poke(true)
      dut.io.response.ready.expect(true)
      dut.io.serializedFault.valid.expect(true)
      dut.io.serializedFault.bits.sqIdx.expect(2)
      dut.io.complete.bits.fault.expect(true)
      dut.clock.step()
      dut.io.response.valid.poke(false)
      dut.io.response.bits.fault.poke(false)
      dut.io.idle.expect(true)
    }

    var fatalFaultObserved = false
    try {
      simulate(new StoreDrainEngine(cfg)) { dut =>
        reset(dut)
        captureNormal(dut, sqIdx = 0, robIdx = 0, addr = 0x4000)
        dut.io.request.ready.poke(true)
        dut.clock.step()
        dut.io.request.ready.poke(false)
        dut.io.externalFire.valid.poke(true)
        dut.io.externalFire.bits.poke(4)
        dut.clock.step()
        dut.io.externalFire.valid.poke(false)
        dut.io.response.valid.poke(true)
        dut.io.response.bits.txnId.poke(4)
        dut.io.response.bits.fault.poke(true)
        dut.clock.step()
      }
    } catch {
      case _: Exceptions.AssertionFailed => fatalFaultObserved = true
    }
    assert(fatalFaultObserved, "cacheable committed-store response faults must be fatal")

    println("StoreDrainEngineSpec: PASS")
  }
}
