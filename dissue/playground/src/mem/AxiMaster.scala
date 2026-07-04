package top.mem

import chisel3._
import chisel3.util.{is, switch, Decoupled, Enum}
import top.AxiPort
import top.config.MemConfig
import top.mem.bundle._
import java.rmi.server.UID

object AxiMasterState extends ChiselEnum {
  val SIdle, STransfer, SResp = Value
}

class AxiMaster(cfg: MemConfig = MemConfig()) extends Module {
  val io = IO(new Bundle {
    val readReq  = Flipped(Decoupled(new AxiMasterReadReq(cfg.addrWidth, cfg.axiIdWidth)))
    val readResp = Decoupled(new AxiMasterReadResp(cfg.axiDataWidth, cfg.axiIdWidth))

    val writeReq  = Flipped(Decoupled(new AxiMasterWriteReq(cfg.addrWidth, cfg.axiDataWidth, cfg.axiIdWidth)))
    val writeResp = Decoupled(new AxiMasterWriteResp(cfg.axiIdWidth))

    val axi = new AxiPort
  })

  val state   = RegInit(AxiMasterState.SIdle)
  val isWrite = Reg(Bool())
  val finish  = Wire(Bool())

  val length    = Reg(UInt(8.W))
  val startAddr = Reg(UInt(cfg.addrWidth.W))
  val size      = Reg(UInt(3.W))
  val burstType = Reg(UInt(2.W))
  val reqId     = Reg(UInt(cfg.axiIdWidth.W))

  val transferIdle :: transferReadAddr :: transferWrite :: Nil =
    Enum(3)
  val transferState                                            = RegInit(transferIdle)
  val addrReg                                                  = Reg(UInt(cfg.addrWidth.W))
  val alignedReg                                               = Reg(Bool())
  val beatCount                                                = Reg(UInt(8.W))

  val writeDataReg   = Reg(UInt(cfg.axiDataWidth.W))
  val writeStrbReg   = Reg(UInt((cfg.axiDataWidth / 8).W))
  val writeBeatValid = RegInit(false.B)
  val awDone         = RegInit(false.B)
  val wDone          = RegInit(false.B)

  when(state === AxiMasterState.SIdle) {
    when(io.readReq.fire) {
      isWrite   := false.B
      length    := io.readReq.bits.len
      startAddr := io.readReq.bits.addr
      size      := io.readReq.bits.size
      burstType := io.readReq.bits.burst
      reqId     := io.readReq.bits.id
      state     := AxiMasterState.STransfer
    }.elsewhen(io.writeReq.fire) {
      isWrite   := true.B
      length    := io.writeReq.bits.len
      startAddr := io.writeReq.bits.addr
      size      := io.writeReq.bits.size
      burstType := io.writeReq.bits.burst
      reqId     := io.writeReq.bits.id
      state     := AxiMasterState.STransfer
    }
  }.elsewhen(state === AxiMasterState.STransfer) {
    when(finish) {
      state := AxiMasterState.SResp
    }
  }.otherwise {
    assert(state === AxiMasterState.SResp)
    when(isWrite && io.writeResp.fire) {
      state := AxiMasterState.SIdle
    }.elsewhen(!isWrite && io.readResp.fire && io.readResp.bits.last) {
      state := AxiMasterState.SIdle
    }
  }

  val dataBytes     = (cfg.axiDataWidth / 8).U(cfg.addrWidth.W)
  val sizeBytes     = (1.U(cfg.addrWidth.W) << size)(cfg.addrWidth - 1, 0)
  val dataBeatBase  = addrReg & ~(dataBytes - 1.U)
  val lowerByteLane = addrReg - dataBeatBase
  val alignedAddr   = addrReg & ~(sizeBytes - 1.U)
  val isAlign       = alignedReg

  val alignedUpperByteLane   = lowerByteLane + sizeBytes - 1.U
  val unalignedUpperByteLane = alignedAddr + sizeBytes - 1.U - dataBeatBase
  val upperByteLane          = Mux(isAlign, alignedUpperByteLane, unalignedUpperByteLane)
  val burstLength            = length +& 1.U
  val containerSize          = (burstLength << size).pad(cfg.addrWidth)
  val lowerWrapBoundary      = startAddr & ~(containerSize - 1.U)
  val upperWrapBoundary      = lowerWrapBoundary + containerSize

  val nextIncrAddr = Mux(isAlign, addrReg + sizeBytes, alignedAddr + sizeBytes)
  val nextWrapAddr = Mux(nextIncrAddr >= upperWrapBoundary, lowerWrapBoundary, nextIncrAddr)
  val nextAddr     = Mux(
    burstType === AxiBurst.fixed,
    addrReg,
    Mux(burstType === AxiBurst.wrap, nextWrapAddr, nextIncrAddr)
  )

  val writeLaneMask = VecInit(Seq.tabulate(cfg.axiDataWidth / 8) { lane =>
    val laneIdx = lane.U(cfg.addrWidth.W)
    laneIdx >= lowerByteLane && laneIdx <= upperByteLane
  }).asUInt

  val readReqSizeBytes    = (1.U(cfg.addrWidth.W) << io.readReq.bits.size)(cfg.addrWidth - 1, 0)
  val readReqAlignedAddr  = io.readReq.bits.addr & ~(readReqSizeBytes - 1.U)
  val writeReqSizeBytes   = (1.U(cfg.addrWidth.W) << io.writeReq.bits.size)(cfg.addrWidth - 1, 0)
  val writeReqAlignedAddr = io.writeReq.bits.addr & ~(writeReqSizeBytes - 1.U)

  val acceptReq      = state === AxiMasterState.SIdle && transferState === transferIdle
  val acceptReadReq  = acceptReq
  val acceptWriteReq = acceptReq && !io.readReq.valid
  val transferActive = state === AxiMasterState.STransfer

  val axiArValid = transferActive && transferState === transferReadAddr
  val axiAwValid = transferActive && transferState === transferWrite && !awDone
  val axiWValid  =
    transferActive && transferState === transferWrite && !wDone && (writeBeatValid || io.writeReq.valid)
  val axiArFire  = axiArValid && io.axi.arready
  val axiAwFire  = axiAwValid && io.axi.awready
  val axiWFire   = axiWValid && io.axi.wready
  val lastBeat   = beatCount === length
  val awDoneNext = awDone || axiAwFire
  val wDoneNext  = wDone || (axiWFire && lastBeat)

  val currentWriteData = Mux(writeBeatValid, writeDataReg, io.writeReq.bits.data)
  val currentWriteStrb = Mux(writeBeatValid, writeStrbReg, io.writeReq.bits.strb)

  finish := false.B

  when(state === AxiMasterState.SIdle) {
    when(io.readReq.fire) {
      transferState  := transferReadAddr
      addrReg        := io.readReq.bits.addr
      alignedReg     := io.readReq.bits.addr === readReqAlignedAddr
      beatCount      := 0.U
      writeBeatValid := false.B
      awDone         := false.B
      wDone          := false.B
    }.elsewhen(io.writeReq.fire) {
      transferState  := transferWrite
      addrReg        := io.writeReq.bits.addr
      alignedReg     := io.writeReq.bits.addr === writeReqAlignedAddr
      beatCount      := 0.U
      writeDataReg   := io.writeReq.bits.data
      writeStrbReg   := io.writeReq.bits.strb
      writeBeatValid := true.B
      awDone         := false.B
      wDone          := false.B
    }
  }.elsewhen(transferActive) {
    switch(transferState) {
      is(transferReadAddr) {
        when(axiArFire) {
          transferState := transferIdle
          finish        := true.B
        }
      }
      is(transferWrite) {
        when(axiAwFire) {
          awDone := true.B
        }
        when(axiWFire) {
          when(writeBeatValid) {
            writeBeatValid := false.B
          }
          when(lastBeat) {
            wDone := true.B
          }.otherwise {
            beatCount  := beatCount + 1.U
            addrReg    := nextAddr
            alignedReg := true.B
          }
        }
        when(awDoneNext && wDoneNext) {
          transferState  := transferIdle
          writeBeatValid := false.B
          awDone         := false.B
          wDone          := false.B
          finish         := true.B
        }
      }
    }
  }

  io.readReq.ready := acceptReadReq

  io.axi.arvalid := axiArValid
  io.axi.araddr  := startAddr
  io.axi.arid    := reqId
  io.axi.arlen   := length
  io.axi.arsize  := size
  io.axi.arburst := burstType

  io.readResp.valid     := state === AxiMasterState.SResp && !isWrite && io.axi.rvalid
  io.readResp.bits.data := io.axi.rdata
  io.readResp.bits.id   := io.axi.rid
  io.readResp.bits.resp := io.axi.rresp
  io.readResp.bits.last := io.axi.rlast

  io.writeReq.ready      := acceptWriteReq ||
    (transferActive && transferState === transferWrite && !wDone && !writeBeatValid && io.axi.wready)
  io.writeResp.valid     := state === AxiMasterState.SResp && isWrite && io.axi.bvalid
  io.writeResp.bits.id   := io.axi.bid
  io.writeResp.bits.resp := io.axi.bresp

  io.axi.awvalid := axiAwValid
  io.axi.awaddr  := startAddr
  io.axi.awid    := reqId
  io.axi.awlen   := length
  io.axi.awsize  := size
  io.axi.awburst := burstType

  io.axi.wvalid := axiWValid
  io.axi.wdata  := currentWriteData
  io.axi.wstrb  := currentWriteStrb & writeLaneMask
  io.axi.wlast  := lastBeat

  io.axi.bready := state === AxiMasterState.SResp && isWrite && io.writeResp.ready
  io.axi.rready := state === AxiMasterState.SResp && !isWrite && io.readResp.ready
}
