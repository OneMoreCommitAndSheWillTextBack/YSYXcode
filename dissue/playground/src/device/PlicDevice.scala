package top.device

import chisel3._
import chisel3.util.Cat
import top.bundle.DataMemReq
import top.config.MemConfig

class PlicDevice(cfg: MemConfig = MemConfig()) extends Module {
  val io = IO(new Bundle {
    val req        = Input(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))
    val writeValid = Input(Bool())
    val readData   = Output(UInt(cfg.axiDataWidth.W))

    val externalInterrupt = Input(Bool())
    val meip              = Output(Bool())
    val seip              = Output(Bool())
  })

  private val priority1  = RegInit(0.U(32.W))
  private val pending1   = RegInit(false.B)
  private val enableM1   = RegInit(false.B)
  private val enableS1   = RegInit(false.B)
  private val thresholdM = RegInit(0.U(32.W))
  private val thresholdS = RegInit(0.U(32.W))

  private val offset = io.req.addr - DeviceConst.plicBase.U(cfg.addrWidth.W)

  private def writeMasked(old: UInt): UInt = {
    val bytes = Wire(Vec(cfg.axiDataWidth / 8, UInt(8.W)))
    for (i <- 0 until cfg.axiDataWidth / 8) {
      bytes(i) := Mux(io.req.wmask(i), io.req.wdata(8 * i + 7, 8 * i), old(8 * i + 7, 8 * i))
    }
    bytes.asUInt
  }

  private val priority1Hit = offset === (DeviceConst.plicPriorityBase + 4).U
  private val pendingHit   = offset === DeviceConst.plicPendingBase.U
  private val enableMHit   = offset === DeviceConst.plicEnableBase.U
  private val enableSHit   = offset === (DeviceConst.plicEnableBase + DeviceConst.plicEnableStride).U
  private val thresholdMHit = offset === DeviceConst.plicContextBase.U
  private val claimMHit     = offset === (DeviceConst.plicContextBase + 4).U
  private val thresholdSHit = offset === (DeviceConst.plicContextBase + DeviceConst.plicContextStride).U
  private val claimSHit     = offset === (DeviceConst.plicContextBase + DeviceConst.plicContextStride + 4).U

  private def irqFor(enable: Bool, threshold: UInt): Bool =
    pending1 && enable && priority1 > threshold

  private val claimM = irqFor(enableM1, thresholdM)
  private val claimS = irqFor(enableS1, thresholdS)

  when(io.externalInterrupt) {
    pending1 := true.B
  }

  when(io.writeValid) {
    when(priority1Hit) {
      priority1 := writeMasked(priority1)
    }.elsewhen(enableMHit) {
      when(io.req.wmask(0)) {
        enableM1 := io.req.wdata(1)
      }
    }.elsewhen(enableSHit) {
      when(io.req.wmask(0)) {
        enableS1 := io.req.wdata(1)
      }
    }.elsewhen(thresholdMHit) {
      thresholdM := writeMasked(thresholdM)
    }.elsewhen(thresholdSHit) {
      thresholdS := writeMasked(thresholdS)
    }
  }.otherwise {
    when(claimMHit && claimM) {
      pending1 := false.B
    }.elsewhen(claimSHit && claimS) {
      pending1 := false.B
    }
  }

  io.readData := 0.U
  when(priority1Hit) {
    io.readData := priority1
  }.elsewhen(pendingHit) {
    io.readData := Cat(0.U(30.W), pending1, 0.U(1.W))
  }.elsewhen(enableMHit) {
    io.readData := Cat(0.U(30.W), enableM1, 0.U(1.W))
  }.elsewhen(enableSHit) {
    io.readData := Cat(0.U(30.W), enableS1, 0.U(1.W))
  }.elsewhen(thresholdMHit) {
    io.readData := thresholdM
  }.elsewhen(thresholdSHit) {
    io.readData := thresholdS
  }.elsewhen(claimMHit) {
    io.readData := Mux(claimM, 1.U, 0.U)
  }.elsewhen(claimSHit) {
    io.readData := Mux(claimS, 1.U, 0.U)
  }

  io.meip := claimM
  io.seip := claimS
}
