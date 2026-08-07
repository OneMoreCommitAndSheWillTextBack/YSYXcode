package top.core.mem

import chisel3._
import top.device.DeviceConst

object MemAddress {
  private def inRange(addr: UInt, base: BigInt, size: BigInt, addrWidth: Int): Bool =
    addr >= base.U(addrWidth.W) && addr < (base + size).U(addrWidth.W)

  def isDevice(addr: UInt, addrWidth: Int): Bool =
    inRange(addr, DeviceConst.clintBase, DeviceConst.clintSize, addrWidth) ||
      inRange(addr, DeviceConst.rtcBase, DeviceConst.rtcSize, addrWidth) ||
      inRange(addr, DeviceConst.serialBase, DeviceConst.serialSize, addrWidth) ||
      inRange(addr, DeviceConst.plicBase, DeviceConst.plicSize, addrWidth)
}
