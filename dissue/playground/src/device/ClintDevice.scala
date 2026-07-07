package top.device

import chisel3._
import chisel3.util.Cat
import top.bundle.DataMemReq
import top.config.MemConfig

class ClintDevice(cfg: MemConfig = MemConfig()) extends Module {
  val io = IO(new Bundle {
    val req        = Input(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))
    val writeValid = Input(Bool())
    val readData   = Output(UInt(cfg.axiDataWidth.W))

    val msip = Output(Bool())
    val mtip = Output(Bool())
  })

  private val timeDpi = Module(new DeviceTimeDpi)
  timeDpi.io.clock := clock

  private val msipReg      = RegInit(false.B)
  private val mtimecmpReg  = RegInit("hffffffffffffffff".U(64.W))
  private val mtimeBaseReg = RegInit(0.U(64.W))
  private val rawBaseReg   = RegInit(0.U(64.W))

  private val rawTime = timeDpi.io.value
  private val mtime   = mtimeBaseReg + (rawTime - rawBaseReg)

  private val clintOffset = io.req.addr - DeviceConst.clintBase.U(cfg.addrWidth.W)
  private val rtcOffset   = io.req.addr - DeviceConst.rtcBase.U(cfg.addrWidth.W)

  private def writeMasked(old: UInt): UInt = {
    val bytes = Wire(Vec(cfg.axiDataWidth / 8, UInt(8.W)))
    for (i <- 0 until cfg.axiDataWidth / 8) {
      bytes(i) := Mux(io.req.wmask(i), io.req.wdata(8 * i + 7, 8 * i), old(8 * i + 7, 8 * i))
    }
    bytes.asUInt
  }

  private val msipHit      = clintOffset === DeviceConst.clintMsipBase.U
  private val mtimecmpLoHit = clintOffset === DeviceConst.clintMtimecmpBase.U
  private val mtimecmpHiHit = clintOffset === (DeviceConst.clintMtimecmpBase + 4).U
  private val mtimeLoHit    = clintOffset === DeviceConst.clintMtimeBase.U
  private val mtimeHiHit    = clintOffset === (DeviceConst.clintMtimeBase + 4).U
  private val rtcLoHit      = rtcOffset === 0.U
  private val rtcHiHit      = rtcOffset === 4.U

  when(io.writeValid) {
    when(msipHit) {
      when(io.req.wmask(0)) {
        msipReg := io.req.wdata(0)
      }
    }.elsewhen(mtimecmpLoHit) {
      mtimecmpReg := Cat(mtimecmpReg(63, 32), writeMasked(mtimecmpReg(31, 0)))
    }.elsewhen(mtimecmpHiHit) {
      mtimecmpReg := Cat(writeMasked(mtimecmpReg(63, 32)), mtimecmpReg(31, 0))
    }.elsewhen(mtimeLoHit) {
      mtimeBaseReg := Cat(mtime(63, 32), writeMasked(mtime(31, 0)))
      rawBaseReg   := rawTime
    }.elsewhen(mtimeHiHit) {
      mtimeBaseReg := Cat(writeMasked(mtime(63, 32)), mtime(31, 0))
      rawBaseReg   := rawTime
    }
  }

  io.readData := 0.U
  when(msipHit) {
    io.readData := msipReg.asUInt
  }.elsewhen(mtimecmpLoHit) {
    io.readData := mtimecmpReg(31, 0)
  }.elsewhen(mtimecmpHiHit) {
    io.readData := mtimecmpReg(63, 32)
  }.elsewhen(mtimeLoHit || rtcLoHit) {
    io.readData := mtime(31, 0)
  }.elsewhen(mtimeHiHit || rtcHiHit) {
    io.readData := mtime(63, 32)
  }

  io.msip := msipReg
  io.mtip := mtime >= mtimecmpReg
}
