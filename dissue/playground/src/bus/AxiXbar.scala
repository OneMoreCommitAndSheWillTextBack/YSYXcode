package top.bus

import chisel3._
import top.bus.axi.{AxiBurst, AxiPort, AxiResp}
import top.config.MemConfig
import top.core.backend.csr.CsrInterruptPending
import top.device.{ClintDevice, DeviceConst, DeviceReq, PlicDevice}

class AxiXbar(cfg: MemConfig = MemConfig()) extends Module {
  private val dataBytes = cfg.axiDataWidth / 8

  val io = IO(new Bundle {
    val core = Flipped(new AxiPort)
    val mem  = new AxiPort

    val externalInterrupt = Input(Bool())
    val interrupt         = Output(new CsrInterruptPending)
  })

  private def inRange(addr: UInt, base: BigInt, size: BigInt): Bool =
    addr >= base.U(cfg.addrWidth.W) && addr < (base + size).U(cfg.addrWidth.W)

  private def hitsClint(addr: UInt): Bool =
    inRange(addr, DeviceConst.clintBase, DeviceConst.clintSize) ||
      inRange(addr, DeviceConst.rtcBase, DeviceConst.rtcSize)

  private def hitsPlic(addr: UInt): Bool =
    inRange(addr, DeviceConst.plicBase, DeviceConst.plicSize)

  private def hitsDevice(addr: UInt): Bool =
    hitsClint(addr) || hitsPlic(addr)

  private def alignToBeat(addr: UInt): UInt =
    addr & ~(dataBytes - 1).U(cfg.addrWidth.W)

  private def deviceReq(addr: UInt, data: UInt, strb: UInt): DeviceReq = {
    val req = Wire(new DeviceReq(cfg.addrWidth, cfg.axiDataWidth))
    req       := 0.U.asTypeOf(new DeviceReq(cfg.addrWidth, cfg.axiDataWidth))
    req.addr  := alignToBeat(addr)
    req.wdata := data
    req.wmask := strb
    req
  }

  private def nextBurstAddr(addr: UInt, size: UInt, burst: UInt): UInt = {
    val step = (1.U(cfg.addrWidth.W) << size)(cfg.addrWidth - 1, 0)
    Mux(burst === AxiBurst.fixed, addr, addr + step)
  }

  private val clint = Module(new ClintDevice(cfg))
  private val plic  = Module(new PlicDevice(cfg))

  plic.io.externalInterrupt := io.externalInterrupt

  io.interrupt.msip := clint.io.msip
  io.interrupt.mtip := clint.io.mtip
  io.interrupt.meip := plic.io.meip
  io.interrupt.seip := plic.io.seip

  private val readRouteValid  = RegInit(false.B)
  private val readRouteDevice = RegInit(false.B)

  private val devReadValid = RegInit(false.B)
  private val devReadAddr  = Reg(UInt(cfg.addrWidth.W))
  private val devReadId    = Reg(UInt(cfg.axiIdWidth.W))
  private val devReadLen   = Reg(UInt(8.W))
  private val devReadSize  = Reg(UInt(3.W))
  private val devReadBurst = Reg(UInt(2.W))
  private val devReadBeat  = Reg(UInt(8.W))

  private val arToDevice = hitsDevice(io.core.araddr)
  io.core.arready := Mux(arToDevice, !readRouteValid && !devReadValid, !readRouteValid && io.mem.arready)

  io.mem.arvalid := io.core.arvalid && !arToDevice && !readRouteValid
  io.mem.araddr  := io.core.araddr
  io.mem.arid    := io.core.arid
  io.mem.arlen   := io.core.arlen
  io.mem.arsize  := io.core.arsize
  io.mem.arburst := io.core.arburst

  private val coreArFire = io.core.arvalid && io.core.arready
  when(coreArFire) {
    readRouteValid  := true.B
    readRouteDevice := arToDevice
    when(arToDevice) {
      devReadValid := true.B
      devReadAddr  := io.core.araddr
      devReadId    := io.core.arid
      devReadLen   := io.core.arlen
      devReadSize  := io.core.arsize
      devReadBurst := io.core.arburst
      devReadBeat  := 0.U
    }
  }

  private val devReadLast    = devReadBeat === devReadLen
  private val readFromDevice = readRouteValid && readRouteDevice
  private val selectedRValid = Mux(readFromDevice, devReadValid, readRouteValid && io.mem.rvalid)
  private val selectedRData  = Wire(UInt(cfg.axiDataWidth.W))
  private val selectedRResp  = Mux(readFromDevice, AxiResp.okay, io.mem.rresp)
  private val selectedRLast  = Mux(readFromDevice, devReadLast, io.mem.rlast)
  private val selectedRId    = Mux(readFromDevice, devReadId, io.mem.rid)

  io.core.rvalid := selectedRValid
  io.core.rdata  := selectedRData
  io.core.rresp  := selectedRResp
  io.core.rlast  := selectedRLast
  io.core.rid    := selectedRId
  io.mem.rready  := readRouteValid && !readRouteDevice && io.core.rready

  private val coreRFire = io.core.rvalid && io.core.rready
  when(coreRFire && selectedRLast) {
    readRouteValid := false.B
  }
  when(coreRFire && readFromDevice) {
    when(devReadLast) {
      devReadValid := false.B
    }.otherwise {
      devReadBeat := devReadBeat + 1.U
      devReadAddr := nextBurstAddr(devReadAddr, devReadSize, devReadBurst)
    }
  }

  private val writeRouteValid  = RegInit(false.B)
  private val writeRouteDevice = RegInit(false.B)

  private val devAwValid = RegInit(false.B)
  private val devAwAddr  = Reg(UInt(cfg.addrWidth.W))
  private val devAwId    = Reg(UInt(cfg.axiIdWidth.W))
  private val devAwSize  = Reg(UInt(3.W))

  private val devWValid = RegInit(false.B)
  private val devWData  = Reg(UInt(cfg.axiDataWidth.W))
  private val devWStrb  = Reg(UInt(dataBytes.W))

  private val devBValid = RegInit(false.B)
  private val devBId    = Reg(UInt(cfg.axiIdWidth.W))

  private val awToDevice = hitsDevice(io.core.awaddr)
  io.core.awready := Mux(awToDevice, !writeRouteValid && !devAwValid && !devBValid, !writeRouteValid && io.mem.awready)

  io.mem.awvalid := io.core.awvalid && !awToDevice && !writeRouteValid
  io.mem.awaddr  := io.core.awaddr
  io.mem.awid    := io.core.awid
  io.mem.awlen   := io.core.awlen
  io.mem.awsize  := io.core.awsize
  io.mem.awburst := io.core.awburst

  private val coreAwFire = io.core.awvalid && io.core.awready
  private val devAwFire  = coreAwFire && awToDevice

  when(coreAwFire) {
    writeRouteValid  := true.B
    writeRouteDevice := awToDevice
  }

  private val currentWriteDevice = Mux(writeRouteValid, writeRouteDevice, awToDevice)
  private val writeRouteKnown    = writeRouteValid || io.core.awvalid
  private val devCanAcceptW      = !devWValid && !devBValid && (devAwValid || devAwFire)

  io.core.wready := Mux(
    currentWriteDevice,
    devCanAcceptW,
    writeRouteKnown && !currentWriteDevice && io.mem.wready
  )

  io.mem.wvalid := io.core.wvalid && writeRouteKnown && !currentWriteDevice
  io.mem.wdata  := io.core.wdata
  io.mem.wstrb  := io.core.wstrb
  io.mem.wlast  := io.core.wlast

  private val coreWFire = io.core.wvalid && io.core.wready
  private val devWFire  = coreWFire && currentWriteDevice

  private val devWriteAddr   = Mux(devAwValid, devAwAddr, io.core.awaddr)
  private val devWriteId     = Mux(devAwValid, devAwId, io.core.awid)
  private val devWriteSize   = Mux(devAwValid, devAwSize, io.core.awsize)
  private val devWriteData   = Mux(devWValid, devWData, io.core.wdata)
  private val devWriteStrb   = Mux(devWValid, devWStrb, io.core.wstrb)
  private val devWriteCommit = !devBValid && (devAwValid || devAwFire) && (devWValid || devWFire)

  when(devAwFire && !devWriteCommit) {
    devAwValid := true.B
    devAwAddr  := io.core.awaddr
    devAwId    := io.core.awid
    devAwSize  := io.core.awsize
  }

  when(devWFire && !devWriteCommit) {
    devWValid := true.B
    devWData  := io.core.wdata
    devWStrb  := io.core.wstrb
  }

  when(devWriteCommit) {
    devAwValid := false.B
    devWValid  := false.B
    devBValid  := true.B
    devBId     := devWriteId
  }

  private val writeFromDevice = writeRouteValid && writeRouteDevice
  private val selectedBValid  = Mux(writeFromDevice, devBValid, writeRouteValid && io.mem.bvalid)
  private val selectedBResp   = Mux(writeFromDevice, AxiResp.okay, io.mem.bresp)
  private val selectedBId     = Mux(writeFromDevice, devBId, io.mem.bid)

  io.core.bvalid := selectedBValid
  io.core.bresp  := selectedBResp
  io.core.bid    := selectedBId
  io.mem.bready  := writeRouteValid && !writeRouteDevice && io.core.bready

  private val coreBFire = io.core.bvalid && io.core.bready
  when(coreBFire) {
    writeRouteValid := false.B
    when(writeFromDevice) {
      devBValid := false.B
    }
  }

  private val zeroReq         = 0.U.asTypeOf(new DeviceReq(cfg.addrWidth, cfg.axiDataWidth))
  private val readReq         = deviceReq(devReadAddr, 0.U(cfg.axiDataWidth.W), 0.U(dataBytes.W))
  private val writeReq        = deviceReq(devWriteAddr, devWriteData, devWriteStrb)
  private val activeDeviceReq = Mux(devWriteCommit, writeReq, Mux(devReadValid, readReq, zeroReq))

  clint.io.req        := activeDeviceReq
  clint.io.writeValid := devWriteCommit && hitsClint(devWriteAddr)

  plic.io.req        := activeDeviceReq
  plic.io.writeValid := devWriteCommit && hitsPlic(devWriteAddr)

  private val deviceRData = Mux(
    hitsClint(devReadAddr),
    clint.io.readData,
    Mux(hitsPlic(devReadAddr), plic.io.readData, 0.U(cfg.axiDataWidth.W))
  )
  selectedRData := Mux(readFromDevice, deviceRData, io.mem.rdata)
}
