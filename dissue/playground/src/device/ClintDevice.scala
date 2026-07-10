package top.device

import chisel3._
import chisel3.util.{log2Ceil, Cat}
import top.config.MemConfig

class ClintDevice(cfg: MemConfig = MemConfig()) extends Module {
  val io = IO(new Bundle {
    val req        = Input(new DeviceReq(cfg.addrWidth, cfg.axiDataWidth))
    val writeValid = Input(Bool())
    val readData   = Output(UInt(cfg.axiDataWidth.W))

    val msip  = Output(Bool())
    val mtip  = Output(Bool())
    val mtime = Output(UInt(64.W))
  })

  private val mtimeTickWidth = math.max(log2Ceil(DeviceConst.mtimeTickCycles), 1)
  private val mtimeTick      = RegInit(0.U(mtimeTickWidth.W))
  private val mtimeReg       = RegInit(0.U(64.W))
  private val msipReg        = RegInit(false.B)
  private val mtimecmpReg    = RegInit("hffffffffffffffff".U(64.W))

  private val advanceMtime = mtimeTick === (DeviceConst.mtimeTickCycles - 1).U
  when(advanceMtime) {
    mtimeTick := 0.U
  }.otherwise {
    mtimeTick := mtimeTick + 1.U
  }

  private val clintOffset = io.req.addr - DeviceConst.clintBase.U(cfg.addrWidth.W)
  private val rtcOffset   = io.req.addr - DeviceConst.rtcBase.U(cfg.addrWidth.W)

  private def writeMasked(old: UInt): UInt = {
    val bytes = Wire(Vec(cfg.axiDataWidth / 8, UInt(8.W)))
    for (i <- 0 until cfg.axiDataWidth / 8) {
      bytes(i) := Mux(io.req.wmask(i), io.req.wdata(8 * i + 7, 8 * i), old(8 * i + 7, 8 * i))
    }
    bytes.asUInt
  }

  private val msipHit        = clintOffset === DeviceConst.clintMsipBase.U
  private val mtimecmpLoHit  = clintOffset === DeviceConst.clintMtimecmpBase.U
  private val mtimecmpHiHit  = clintOffset === (DeviceConst.clintMtimecmpBase + 4).U
  private val mtimeLoHit     = clintOffset === DeviceConst.clintMtimeBase.U
  private val mtimeHiHit     = clintOffset === (DeviceConst.clintMtimeBase + 4).U
  private val rtcLoHit       = rtcOffset === 0.U
  private val rtcHiHit       = rtcOffset === 4.U
  private val mtimeWrite     = io.writeValid && (mtimeLoHit || mtimeHiHit)
  private val mtimeWriteData = WireDefault(mtimeReg)

  when(mtimeLoHit) {
    mtimeWriteData := Cat(mtimeReg(63, 32), writeMasked(mtimeReg(31, 0)))
  }.elsewhen(mtimeHiHit) {
    mtimeWriteData := Cat(writeMasked(mtimeReg(63, 32)), mtimeReg(31, 0))
  }

  when(mtimeWrite) {
    mtimeReg := mtimeWriteData
  }.elsewhen(advanceMtime) {
    mtimeReg := mtimeReg + 1.U
  }

  when(io.writeValid) {
    when(msipHit) {
      when(io.req.wmask(0)) {
        msipReg := io.req.wdata(0)
      }
    }.elsewhen(mtimecmpLoHit) {
      mtimecmpReg := Cat(mtimecmpReg(63, 32), writeMasked(mtimecmpReg(31, 0)))
    }.elsewhen(mtimecmpHiHit) {
      mtimecmpReg := Cat(writeMasked(mtimecmpReg(63, 32)), mtimecmpReg(31, 0))
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
    io.readData := mtimeReg(31, 0)
  }.elsewhen(mtimeHiHit || rtcHiHit) {
    io.readData := mtimeReg(63, 32)
  }

  io.msip  := msipReg
  io.mtip  := mtimeReg >= mtimecmpReg
  io.mtime := mtimeReg
}
