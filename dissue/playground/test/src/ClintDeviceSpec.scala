package top.device

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

class ClintDeviceSpec extends AnyFlatSpec with ChiselScalatestTester with Matchers {
  behavior.of("ClintDevice")

  private def idle(dut: ClintDevice): Unit = {
    dut.io.req.addr.poke(0.U)
    dut.io.req.wdata.poke(0.U)
    dut.io.req.wmask.poke(0.U)
    dut.io.writeValid.poke(false.B)
  }

  private def write(dut: ClintDevice, addr: BigInt, data: BigInt): Unit = {
    dut.io.req.addr.poke(addr.U)
    dut.io.req.wdata.poke(data.U)
    dut.io.req.wmask.poke("hf".U)
    dut.io.writeValid.poke(true.B)
    dut.clock.step()
    dut.io.writeValid.poke(false.B)
  }

  it should "advance mtime from simulated core cycles and assert MTIP at mtimecmp" in {
    test(new ClintDevice) { dut =>
      idle(dut)
      dut.reset.poke(true.B)
      dut.clock.step()
      dut.reset.poke(false.B)

      dut.clock.step(DeviceConst.mtimeTickCycles - 1)
      dut.io.mtime.expect(0.U)
      dut.clock.step()
      dut.io.mtime.expect(1.U)

      write(dut, DeviceConst.clintBase + DeviceConst.clintMtimeBase, 100)
      write(dut, DeviceConst.clintBase + DeviceConst.clintMtimecmpBase + 4, 0)
      write(dut, DeviceConst.clintBase + DeviceConst.clintMtimecmpBase, 101)
      dut.io.mtime.expect(100.U)
      dut.io.mtip.expect(false.B)

      dut.clock.step(DeviceConst.mtimeTickCycles)
      dut.io.mtime.expect(101.U)
      dut.io.mtip.expect(true.B)
    }
  }
}
