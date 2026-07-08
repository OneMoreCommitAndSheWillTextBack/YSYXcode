package top.device

import chisel3._

class DeviceReq(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val addr  = UInt(addrWidth.W)
  val wdata = UInt(dataWidth.W)
  val wmask = UInt((dataWidth / 8).W)
}
