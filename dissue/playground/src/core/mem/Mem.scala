package top.core.mem

import chisel3._
import chisel3.util.Decoupled
import top.bus.axi.AxiPort
import top.core.bundle._
import top.config.MemConfig

class Mem(cfg: MemConfig = MemConfig()) extends Module {
  val io = IO(new Bundle {
    val imemReq  = Flipped(Decoupled(new InstMemReq(cfg.addrWidth)))
    val imemResp = Decoupled(new InstMemResp(cfg.fetchBytes))

    val dmemReq  = Flipped(Decoupled(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth)))
    val dmemResp = Decoupled(new DataMemResp(cfg.axiDataWidth))

    val axi = new AxiPort
  })

  val refill     = Module(new AxiReadRefill(cfg))
  val axiMaster  = Module(new AxiMaster(cfg))
  val dataAccess = Module(new AxiDataAccess(cfg))

  refill.io.req <> io.imemReq
  io.imemResp <> refill.io.resp

  dataAccess.io.req <> io.dmemReq
  io.dmemResp <> dataAccess.io.resp

  val dataReadSelected = dataAccess.io.axiReadReq.valid
  val instReadSelected =
    !dataReadSelected && !dataAccess.io.axiWriteReq.valid && refill.io.axiReadReq.valid

  axiMaster.io.readReq.valid     := dataReadSelected || instReadSelected
  axiMaster.io.readReq.bits      := Mux(
    dataReadSelected,
    dataAccess.io.axiReadReq.bits,
    refill.io.axiReadReq.bits
  )
  dataAccess.io.axiReadReq.ready := axiMaster.io.readReq.ready && dataReadSelected
  refill.io.axiReadReq.ready     := axiMaster.io.readReq.ready && instReadSelected

  val readRespToData = RegInit(false.B)
  when(axiMaster.io.readReq.fire) {
    readRespToData := dataReadSelected
  }

  dataAccess.io.axiReadResp.valid := axiMaster.io.readResp.valid && readRespToData
  dataAccess.io.axiReadResp.bits  := axiMaster.io.readResp.bits
  refill.io.axiReadResp.valid     := axiMaster.io.readResp.valid && !readRespToData
  refill.io.axiReadResp.bits      := axiMaster.io.readResp.bits
  axiMaster.io.readResp.ready     := Mux(
    readRespToData,
    dataAccess.io.axiReadResp.ready,
    refill.io.axiReadResp.ready
  )

  axiMaster.io.writeReq <> dataAccess.io.axiWriteReq
  dataAccess.io.axiWriteResp <> axiMaster.io.writeResp

  io.axi.awvalid           := axiMaster.io.axi.awvalid
  io.axi.awaddr            := axiMaster.io.axi.awaddr
  io.axi.awid              := axiMaster.io.axi.awid
  io.axi.awlen             := axiMaster.io.axi.awlen
  io.axi.awsize            := axiMaster.io.axi.awsize
  io.axi.awburst           := axiMaster.io.axi.awburst
  axiMaster.io.axi.awready := io.axi.awready

  io.axi.wvalid           := axiMaster.io.axi.wvalid
  io.axi.wdata            := axiMaster.io.axi.wdata
  io.axi.wstrb            := axiMaster.io.axi.wstrb
  io.axi.wlast            := axiMaster.io.axi.wlast
  axiMaster.io.axi.wready := io.axi.wready

  io.axi.bready           := axiMaster.io.axi.bready
  axiMaster.io.axi.bvalid := io.axi.bvalid
  axiMaster.io.axi.bresp  := io.axi.bresp
  axiMaster.io.axi.bid    := io.axi.bid

  io.axi.arvalid           := axiMaster.io.axi.arvalid
  io.axi.araddr            := axiMaster.io.axi.araddr
  io.axi.arid              := axiMaster.io.axi.arid
  io.axi.arlen             := axiMaster.io.axi.arlen
  io.axi.arsize            := axiMaster.io.axi.arsize
  io.axi.arburst           := axiMaster.io.axi.arburst
  axiMaster.io.axi.arready := io.axi.arready

  io.axi.rready           := axiMaster.io.axi.rready
  axiMaster.io.axi.rvalid := io.axi.rvalid
  axiMaster.io.axi.rresp  := io.axi.rresp
  axiMaster.io.axi.rdata  := io.axi.rdata
  axiMaster.io.axi.rlast  := io.axi.rlast
  axiMaster.io.axi.rid    := io.axi.rid

}
