package top.frontend.icache

import chisel3._
import chisel3.util._
import top.config.ICacheConfig
import top.frontend.bundle.{ICacheRefillReq, ICacheRefillResp, ICacheReq, ICacheResp}

class ICacheIO(cfg: ICacheConfig) extends Bundle {
  val req        = Flipped(Decoupled(new ICacheReq(cfg.addrWidth, cfg.fetchBytes)))
  val resp       = Decoupled(new ICacheResp(cfg.addrWidth, cfg.fetchBytes))
  val refillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
  val refillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))
}

object ICacheState extends ChiselEnum {
  val SIdle, SRefillReq, SRefillResp = Value
}

class ICache(cfg: ICacheConfig = ICacheConfig()) extends Module {
  val io = IO(new ICacheIO(cfg))

  private def setIndex(addr: UInt): UInt = {
    if (cfg.indexBits == 0) {
      0.U(cfg.setIdxBits.W)
    } else {
      addr(cfg.offsetBits + cfg.indexBits - 1, cfg.offsetBits)
    }
  }

  private def tag(addr: UInt): UInt = {
    addr(cfg.addrWidth - 1, cfg.offsetBits + cfg.indexBits)
  }

  private def nextWay(way: UInt): UInt = {
    if (cfg.ways == 1) {
      0.U(cfg.wayIdxBits.W)
    } else {
      Mux(way === (cfg.ways - 1).U, 0.U(cfg.wayIdxBits.W), (way + 1.U)(cfg.wayIdxBits - 1, 0))
    }
  }

  val validArray = RegInit(VecInit(Seq.fill(cfg.sets)(VecInit(Seq.fill(cfg.ways)(false.B)))))
  val tagArray   = Reg(Vec(cfg.sets, Vec(cfg.ways, UInt(cfg.tagBits.W))))
  val dataArray  = Reg(Vec(cfg.sets, Vec(cfg.ways, UInt(cfg.blockBits.W))))
  val replaceWay = RegInit(VecInit(Seq.fill(cfg.sets)(0.U(cfg.wayIdxBits.W))))

  val state = RegInit(ICacheState.SIdle)

  val missReq = Reg(new ICacheReq(cfg.addrWidth, cfg.fetchBytes))
  val missSet = Reg(UInt(cfg.setIdxBits.W))
  val missTag = Reg(UInt(cfg.tagBits.W))
  val missWay = Reg(UInt(cfg.wayIdxBits.W))

  val respValid = RegInit(false.B)
  val respReg   = Reg(new ICacheResp(cfg.addrWidth, cfg.fetchBytes))

  val reqSet = setIndex(io.req.bits.blockAddr)
  val reqTag = tag(io.req.bits.blockAddr)

  val wayHits = Wire(Vec(cfg.ways, Bool()))
  for (way <- 0 until cfg.ways) {
    wayHits(way) := validArray(reqSet)(way) && tagArray(reqSet)(way) === reqTag
  }

  val hit     = wayHits.asUInt.orR
  val hitData = Mux1H((0 until cfg.ways).map(way => wayHits(way) -> dataArray(reqSet)(way)))

  val invalidWays = Wire(Vec(cfg.ways, Bool()))
  for (way <- 0 until cfg.ways) {
    invalidWays(way) := !validArray(reqSet)(way)
  }

  val hasInvalid = invalidWays.asUInt.orR
  val victimWay  = Wire(UInt(cfg.wayIdxBits.W))
  if (cfg.ways == 1) {
    victimWay := 0.U
  } else {
    victimWay := Mux(hasInvalid, PriorityEncoder(invalidWays), replaceWay(reqSet))
  }

  io.req.ready           := state === ICacheState.SIdle && !respValid
  io.resp.valid          := respValid
  io.resp.bits           := respReg
  io.refillReq.valid     := state === ICacheState.SRefillReq
  io.refillReq.bits.addr := missReq.blockAddr
  io.refillResp.ready    := state === ICacheState.SRefillResp && !respValid

  when(io.resp.fire) {
    respValid := false.B
  }

  when(io.req.fire) {
    when(hit) {
      respReg.pc        := io.req.bits.pc
      respReg.blockAddr := io.req.bits.blockAddr
      respReg.data      := hitData
      respReg.hit       := true.B
      respValid         := true.B
    }.otherwise {
      missReq := io.req.bits
      missSet := reqSet
      missTag := reqTag
      missWay := victimWay
      state   := ICacheState.SRefillReq
    }
  }

  when(io.refillReq.fire) {
    state := ICacheState.SRefillResp
  }

  when(io.refillResp.fire) {
    validArray(missSet)(missWay) := true.B
    tagArray(missSet)(missWay)   := missTag
    dataArray(missSet)(missWay)  := io.refillResp.bits.data

    if (cfg.ways > 1) {
      replaceWay(missSet) := nextWay(missWay)
    }

    respReg.pc        := missReq.pc
    respReg.blockAddr := missReq.blockAddr
    respReg.data      := io.refillResp.bits.data
    respReg.hit       := false.B
    respValid         := true.B
    state             := ICacheState.SIdle
  }
}
