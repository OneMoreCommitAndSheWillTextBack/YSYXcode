package top.mem

import chisel3._
import chisel3.util.{log2Ceil, Cat, Decoupled, Enum, Fill}
import top.bundle.{DataMemReq, DataMemResp}
import top.config.MemConfig
import top.mem.bundle._

class AxiDataAccess(cfg: MemConfig = MemConfig()) extends Module {
  private val dataBytes  = cfg.axiDataWidth / 8
  private val offsetBits = math.max(log2Ceil(dataBytes), 1)

  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth)))
    val resp = Decoupled(new DataMemResp(cfg.axiDataWidth))

    val axiReadReq   = Decoupled(new AxiMasterReadReq(cfg.addrWidth, cfg.axiIdWidth))
    val axiReadResp  = Flipped(Decoupled(new AxiMasterReadResp(cfg.axiDataWidth, cfg.axiIdWidth)))
    val axiWriteReq  = Decoupled(new AxiMasterWriteReq(cfg.addrWidth, cfg.axiDataWidth, cfg.axiIdWidth))
    val axiWriteResp = Flipped(Decoupled(new AxiMasterWriteResp(cfg.axiIdWidth)))
  })

  val sIdle :: sReadReq :: sReadResp :: sWriteReq :: sWriteResp :: sResp :: Nil =
    Enum(6)

  val state   = RegInit(sIdle)
  val reqReg  = Reg(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))
  val respReg = Reg(new DataMemResp(cfg.axiDataWidth))

  val byteOffset       = reqReg.addr(offsetBits - 1, 0)
  val bitOffset        = byteOffset << 3
  val shiftedWriteData = (reqReg.wdata << bitOffset)(cfg.axiDataWidth - 1, 0)
  val shiftedWriteMask = (reqReg.wmask << byteOffset)(dataBytes - 1, 0)
  val shiftedReadData  = io.axiReadResp.bits.data >> bitOffset

  val byteLoad = shiftedReadData(7, 0)
  val halfLoad = shiftedReadData(15, 0)
  val wordLoad = shiftedReadData(31, 0)

  val loadData = Wire(UInt(cfg.axiDataWidth.W))
  loadData := wordLoad
  when(reqReg.size === 0.U) {
    loadData := Mux(
      reqReg.unsigned,
      Cat(0.U((cfg.axiDataWidth - 8).W), byteLoad),
      Cat(Fill(cfg.axiDataWidth - 8, byteLoad(7)), byteLoad)
    )
  }.elsewhen(reqReg.size === 1.U) {
    loadData := Mux(
      reqReg.unsigned,
      Cat(0.U((cfg.axiDataWidth - 16).W), halfLoad),
      Cat(Fill(cfg.axiDataWidth - 16, halfLoad(15)), halfLoad)
    )
  }

  io.req.ready := state === sIdle

  io.resp.valid := state === sResp
  io.resp.bits  := respReg

  io.axiReadReq.valid      := state === sReadReq
  io.axiReadReq.bits.addr  := reqReg.addr
  io.axiReadReq.bits.id    := 1.U(cfg.axiIdWidth.W)
  io.axiReadReq.bits.len   := 0.U(8.W)
  io.axiReadReq.bits.size  := reqReg.size
  io.axiReadReq.bits.burst := AxiBurst.incr
  io.axiReadResp.ready     := state === sReadResp

  io.axiWriteReq.valid      := state === sWriteReq
  io.axiWriteReq.bits.addr  := reqReg.addr
  io.axiWriteReq.bits.id    := 1.U(cfg.axiIdWidth.W)
  io.axiWriteReq.bits.len   := 0.U(8.W)
  io.axiWriteReq.bits.size  := reqReg.size
  io.axiWriteReq.bits.burst := AxiBurst.incr
  io.axiWriteReq.bits.data  := shiftedWriteData
  io.axiWriteReq.bits.strb  := shiftedWriteMask
  io.axiWriteReq.bits.last  := true.B
  io.axiWriteResp.ready     := state === sWriteResp

  when(state === sIdle) {
    when(io.req.fire) {
      reqReg := io.req.bits
      state  := Mux(io.req.bits.write, sWriteReq, sReadReq)
    }
  }.elsewhen(state === sReadReq) {
    when(io.axiReadReq.fire) {
      state := sReadResp
    }
  }.elsewhen(state === sReadResp) {
    when(io.axiReadResp.fire) {
      respReg.data  := loadData
      respReg.fault := io.axiReadResp.bits.resp =/= AxiResp.okay
      state         := sResp
    }
  }.elsewhen(state === sWriteReq) {
    when(io.axiWriteReq.fire) {
      state := sWriteResp
    }
  }.elsewhen(state === sWriteResp) {
    when(io.axiWriteResp.fire) {
      respReg.data  := 0.U
      respReg.fault := io.axiWriteResp.bits.resp =/= AxiResp.okay
      state         := sResp
    }
  }.otherwise {
    when(io.resp.fire) {
      state := sIdle
    }
  }
}
