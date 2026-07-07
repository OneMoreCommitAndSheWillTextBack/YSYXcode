package top.device

import chisel3._
import chisel3.util.{Cat, Decoupled, Enum, Fill}
import top.backend.csr.CsrInterruptPending
import top.backend.decoder.MemSize
import top.bundle.{DataMemReq, DataMemResp}
import top.config.MemConfig

class DeviceBus(cfg: MemConfig = MemConfig()) extends Module {
  val io = IO(new Bundle {
    val coreReq  = Flipped(Decoupled(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth)))
    val coreResp = Decoupled(new DataMemResp(cfg.axiDataWidth))

    val memReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))
    val memResp = Flipped(Decoupled(new DataMemResp(cfg.axiDataWidth)))

    val externalInterrupt = Input(Bool())
    val interrupt         = Output(new CsrInterruptPending)
  })

  private val sIdle :: sMemReq :: sMemResp :: sDeviceResp :: Nil = Enum(4)
  private val state = RegInit(sIdle)

  private val reqReg = Reg(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))

  private def inRange(addr: UInt, base: BigInt, size: BigInt): Bool =
    addr >= base.U(cfg.addrWidth.W) && addr < (base + size).U(cfg.addrWidth.W)

  private def isClint(addr: UInt): Bool =
    inRange(addr, DeviceConst.clintBase, DeviceConst.clintSize) || inRange(addr, DeviceConst.rtcBase, DeviceConst.rtcSize)

  private def isPlic(addr: UInt): Bool =
    inRange(addr, DeviceConst.plicBase, DeviceConst.plicSize)

  private def deviceReq(req: DataMemReq): DataMemReq = {
    val out        = Wire(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))
    val byteOffset = req.addr(1, 0)
    val bitOffset  = byteOffset << 3

    out          := req
    out.addr     := req.addr & "hfffffffc".U(cfg.addrWidth.W)
    out.wdata    := (req.wdata << bitOffset)(cfg.axiDataWidth - 1, 0)
    out.wmask    := (req.wmask << byteOffset)(cfg.axiDataWidth / 8 - 1, 0)
    out
  }

  private def loadFromWord(word: UInt, req: DataMemReq): UInt = {
    val shifted = word >> (req.addr(1, 0) << 3)
    val byte    = shifted(7, 0)
    val half    = shifted(15, 0)

    Mux(
      req.size === MemSize.byte.U,
      Mux(req.unsigned, Cat(0.U((cfg.axiDataWidth - 8).W), byte), Cat(Fill(cfg.axiDataWidth - 8, byte(7)), byte)),
      Mux(
        req.size === MemSize.half.U,
        Mux(req.unsigned, Cat(0.U((cfg.axiDataWidth - 16).W), half), Cat(Fill(cfg.axiDataWidth - 16, half(15)), half)),
        word
      )
    )
  }

  private val clint = Module(new ClintDevice(cfg))
  private val plic  = Module(new PlicDevice(cfg))

  private val inputHitsClint = isClint(io.coreReq.bits.addr)
  private val inputHitsPlic  = isPlic(io.coreReq.bits.addr)
  private val reqHitsClint   = isClint(reqReg.addr)
  private val reqHitsPlic    = isPlic(reqReg.addr)

  private val devReqFromInput = deviceReq(io.coreReq.bits)
  private val devReqFromReg   = deviceReq(reqReg)

  clint.io.req := Mux(io.coreReq.fire && inputHitsClint && io.coreReq.bits.write, devReqFromInput, devReqFromReg)
  clint.io.writeValid := io.coreReq.fire && inputHitsClint && io.coreReq.bits.write

  plic.io.req := Mux(io.coreReq.fire && inputHitsPlic && io.coreReq.bits.write, devReqFromInput, devReqFromReg)
  plic.io.writeValid        := io.coreReq.fire && inputHitsPlic && io.coreReq.bits.write
  plic.io.externalInterrupt := io.externalInterrupt

  io.interrupt.msip := clint.io.msip
  io.interrupt.mtip := clint.io.mtip
  io.interrupt.meip := plic.io.meip
  io.interrupt.seip := plic.io.seip

  io.coreReq.ready := state === sIdle

  io.memReq.valid := state === sMemReq
  io.memReq.bits  := reqReg

  io.memResp.ready := state === sMemResp && io.coreResp.ready

  io.coreResp.valid := (state === sMemResp && io.memResp.valid) || state === sDeviceResp
  io.coreResp.bits  := 0.U.asTypeOf(new DataMemResp(cfg.axiDataWidth))
  when(state === sMemResp) {
    io.coreResp.bits := io.memResp.bits
  }.elsewhen(state === sDeviceResp) {
    val readWord = Mux(reqHitsClint, clint.io.readData, Mux(reqHitsPlic, plic.io.readData, 0.U))
    io.coreResp.bits.data  := Mux(reqReg.write, 0.U, loadFromWord(readWord, reqReg))
    io.coreResp.bits.fault := false.B
  }

  when(state === sIdle) {
    when(io.coreReq.fire) {
      reqReg := io.coreReq.bits
      state  := Mux(inputHitsClint || inputHitsPlic, sDeviceResp, sMemReq)
    }
  }.elsewhen(state === sMemReq) {
    when(io.memReq.fire) {
      state := sMemResp
    }
  }.elsewhen(state === sMemResp) {
    when(io.coreResp.fire) {
      state := sIdle
    }
  }.otherwise {
    when(io.coreResp.fire) {
      state := sIdle
    }
  }
}
