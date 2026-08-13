package top.core.mem

import chisel3._
import chisel3.util.{is, switch, Decoupled, Enum}
import top.bus.axi.{AxiBurst, AxiPort}
import top.config.MemConfig
import top.core.mem.bundle._

object AxiMasterState extends ChiselEnum {
  val SIdle, STransfer, SResp = Value
}

class AxiMaster(
  cfg:              MemConfig = MemConfig(),
  allowDirectWrite: Boolean = false)
    extends Module {
  val io = IO(new Bundle {
    val readReq  = Flipped(Decoupled(new AxiMasterReadReq(cfg.addrWidth, cfg.axiIdWidth)))
    val readResp = Decoupled(new AxiMasterReadResp(cfg.axiDataWidth, cfg.axiIdWidth))

    val writeReq  = Flipped(Decoupled(new AxiMasterWriteReq(cfg.addrWidth, cfg.axiDataWidth, cfg.axiIdWidth)))
    val writeResp = Decoupled(new AxiMasterWriteResp(cfg.axiIdWidth))

    val axi = new AxiPort
  })

  val state   = RegInit(AxiMasterState.SIdle)
  val isWrite = Reg(Bool())

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

  val readReqSizeBytes              = (1.U(cfg.addrWidth.W) << io.readReq.bits.size)(cfg.addrWidth - 1, 0)
  val readReqAlignedAddr            = io.readReq.bits.addr & ~(readReqSizeBytes - 1.U)
  val writeReqSizeBytes             = (1.U(cfg.addrWidth.W) << io.writeReq.bits.size)(cfg.addrWidth - 1, 0)
  val writeReqAlignedAddr           = io.writeReq.bits.addr & ~(writeReqSizeBytes - 1.U)
  val directWriteIsAlign            = io.writeReq.bits.addr === writeReqAlignedAddr
  val directWriteDataBase           = io.writeReq.bits.addr & ~(dataBytes - 1.U)
  val directWriteLowerLane          = io.writeReq.bits.addr - directWriteDataBase
  val directWriteAlignedUpperLane   = directWriteLowerLane + writeReqSizeBytes - 1.U
  val directWriteUnalignedUpperLane = writeReqAlignedAddr + writeReqSizeBytes - 1.U - directWriteDataBase
  val directWriteUpperLane          = Mux(directWriteIsAlign, directWriteAlignedUpperLane, directWriteUnalignedUpperLane)
  val directWriteLaneMask           = VecInit(Seq.tabulate(cfg.axiDataWidth / 8) { lane =>
    val laneIdx = lane.U(cfg.addrWidth.W)
    laneIdx >= directWriteLowerLane && laneIdx <= directWriteUpperLane
  }).asUInt
  val directWriteBurstLength        = io.writeReq.bits.len +& 1.U
  val directWriteContainerSize      = (directWriteBurstLength << io.writeReq.bits.size).pad(cfg.addrWidth)
  val directWriteLowerWrapBoundary  = io.writeReq.bits.addr & ~(directWriteContainerSize - 1.U)
  val directWriteUpperWrapBoundary  = directWriteLowerWrapBoundary + directWriteContainerSize
  val directWriteNextIncrAddr       = Mux(
    directWriteIsAlign,
    io.writeReq.bits.addr + writeReqSizeBytes,
    writeReqAlignedAddr + writeReqSizeBytes
  )
  val directWriteNextWrapAddr       = Mux(
    directWriteNextIncrAddr >= directWriteUpperWrapBoundary,
    directWriteLowerWrapBoundary,
    directWriteNextIncrAddr
  )
  val directWriteNextAddr           = Mux(
    io.writeReq.bits.burst === AxiBurst.fixed,
    io.writeReq.bits.addr,
    Mux(io.writeReq.bits.burst === AxiBurst.wrap, directWriteNextWrapAddr, directWriteNextIncrAddr)
  )

  val transferActive        = state === AxiMasterState.STransfer
  val readResponseComplete  = state === AxiMasterState.SResp && !isWrite && io.axi.rvalid &&
    io.axi.rlast && io.readResp.ready
  val writeResponseComplete = state === AxiMasterState.SResp && isWrite && io.axi.bvalid && io.writeResp.ready
  val responseComplete      = readResponseComplete || writeResponseComplete
  val requestWindow         = (state === AxiMasterState.SIdle || responseComplete) && transferState === transferIdle
  val directRequestWindow   = state === AxiMasterState.SIdle && transferState === transferIdle
  val acceptReadReq         = requestWindow
  val acceptWriteReq        = requestWindow && !io.readReq.valid

  val directArValid     = directRequestWindow && io.readReq.valid
  // A write address may ultimately be derived from the current read response
  // (for example through LSU control). Keep production AW/W registered to
  // avoid a response -> request -> crossbar response combinational cycle.
  val directWriteValid  = if (allowDirectWrite) {
    directRequestWindow && !io.readReq.valid && io.writeReq.valid
  } else {
    false.B
  }
  val registeredArValid = transferActive && transferState === transferReadAddr
  val axiArValid        = directArValid || registeredArValid
  val registeredAwValid = transferActive && transferState === transferWrite && !awDone
  val registeredWValid  =
    transferActive && transferState === transferWrite && !wDone && (writeBeatValid || io.writeReq.valid)
  val axiAwValid        = directWriteValid || registeredAwValid
  val axiWValid         = directWriteValid || registeredWValid
  val axiArFire         = axiArValid && io.axi.arready
  val directArFire      = directArValid && io.axi.arready
  val axiAwFire         = axiAwValid && io.axi.awready
  val axiWFire          = axiWValid && io.axi.wready
  val directAwFire      = directWriteValid && io.axi.awready
  val directWFire       = directWriteValid && io.axi.wready
  val directWriteLast   = io.writeReq.bits.len === 0.U
  val lastBeat          = beatCount === length
  val awDoneNext        = awDone || axiAwFire
  val wDoneNext         = wDone || (axiWFire && lastBeat)

  val currentWriteData = Mux(writeBeatValid, writeDataReg, io.writeReq.bits.data)
  val currentWriteStrb = Mux(writeBeatValid, writeStrbReg, io.writeReq.bits.strb)

  private def beginRead(): Unit = {
    isWrite        := false.B
    length         := io.readReq.bits.len
    startAddr      := io.readReq.bits.addr
    size           := io.readReq.bits.size
    burstType      := io.readReq.bits.burst
    reqId          := io.readReq.bits.id
    addrReg        := io.readReq.bits.addr
    alignedReg     := io.readReq.bits.addr === readReqAlignedAddr
    beatCount      := 0.U
    writeBeatValid := false.B
    awDone         := false.B
    wDone          := false.B
    when(directArFire) {
      transferState := transferIdle
      state         := AxiMasterState.SResp
    }.otherwise {
      transferState := transferReadAddr
      state         := AxiMasterState.STransfer
    }
  }

  private def beginWrite(): Unit = {
    isWrite        := true.B
    length         := io.writeReq.bits.len
    startAddr      := io.writeReq.bits.addr
    size           := io.writeReq.bits.size
    burstType      := io.writeReq.bits.burst
    reqId          := io.writeReq.bits.id
    transferState  := Mux(directAwFire && directWFire && directWriteLast, transferIdle, transferWrite)
    addrReg        := Mux(directWFire && !directWriteLast, directWriteNextAddr, io.writeReq.bits.addr)
    alignedReg     := io.writeReq.bits.addr === writeReqAlignedAddr
    beatCount      := Mux(directWFire && !directWriteLast, 1.U, 0.U)
    writeDataReg   := io.writeReq.bits.data
    writeStrbReg   := io.writeReq.bits.strb
    writeBeatValid := !directWFire
    awDone         := directAwFire
    wDone          := directWFire && directWriteLast
    when(directAwFire && directWFire && directWriteLast) {
      writeBeatValid := false.B
      awDone         := false.B
      wDone          := false.B
      state          := AxiMasterState.SResp
    }.otherwise {
      state := AxiMasterState.STransfer
    }
  }

  when(state === AxiMasterState.SIdle) {
    when(io.readReq.fire) {
      beginRead()
    }.elsewhen(io.writeReq.fire) {
      beginWrite()
    }
  }.elsewhen(transferActive) {
    switch(transferState) {
      is(transferReadAddr) {
        when(axiArFire) {
          transferState := transferIdle
          state         := AxiMasterState.SResp
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
          state          := AxiMasterState.SResp
        }
      }
    }
  }.otherwise {
    assert(state === AxiMasterState.SResp)
    when(responseComplete) {
      when(io.readReq.fire) {
        beginRead()
      }.elsewhen(io.writeReq.fire) {
        beginWrite()
      }.otherwise {
        state := AxiMasterState.SIdle
      }
    }
  }

  io.readReq.ready := acceptReadReq

  io.axi.arvalid := axiArValid
  io.axi.araddr  := Mux(directArValid, io.readReq.bits.addr, startAddr)
  io.axi.arid    := Mux(directArValid, io.readReq.bits.id, reqId)
  io.axi.arlen   := Mux(directArValid, io.readReq.bits.len, length)
  io.axi.arsize  := Mux(directArValid, io.readReq.bits.size, size)
  io.axi.arburst := Mux(directArValid, io.readReq.bits.burst, burstType)

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
  io.axi.awaddr  := Mux(directWriteValid, io.writeReq.bits.addr, startAddr)
  io.axi.awid    := Mux(directWriteValid, io.writeReq.bits.id, reqId)
  io.axi.awlen   := Mux(directWriteValid, io.writeReq.bits.len, length)
  io.axi.awsize  := Mux(directWriteValid, io.writeReq.bits.size, size)
  io.axi.awburst := Mux(directWriteValid, io.writeReq.bits.burst, burstType)

  io.axi.wvalid := axiWValid
  io.axi.wdata  := Mux(directWriteValid, io.writeReq.bits.data, currentWriteData)
  io.axi.wstrb  := Mux(
    directWriteValid,
    io.writeReq.bits.strb & directWriteLaneMask,
    currentWriteStrb & writeLaneMask
  )
  io.axi.wlast  := Mux(directWriteValid, directWriteLast, lastBeat)

  io.axi.bready := state === AxiMasterState.SResp && isWrite && io.writeResp.ready
  io.axi.rready := state === AxiMasterState.SResp && !isWrite && io.readResp.ready
}
