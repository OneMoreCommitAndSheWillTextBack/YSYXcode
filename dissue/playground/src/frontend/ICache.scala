package top.frontend.icache

import chisel3._
import chisel3.util._
import top.config.ICacheConfig
import top.frontend.bundle.{ICacheRefillReq, ICacheRefillResp, ICacheReq, ICacheResp}
import top.sim.CacheHitBridge

class ICacheIO(cfg: ICacheConfig) extends Bundle {
  val req        = Flipped(Decoupled(new ICacheReq(cfg)))
  val resp       = Decoupled(new ICacheResp(cfg))
  val refillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
  val refillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))
  val flush      = Input(Bool())
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

  val validArray = RegInit(VecInit(Seq.fill(cfg.sets)(false.B)))
  val tagArray   = Reg(Vec(cfg.sets, UInt(cfg.tagBits.W)))
  val dataArray  = Reg(Vec(cfg.sets, UInt(cfg.blockBits.W)))

  val state    = RegInit(ICacheState.SIdle)
  val validReg = RegInit(false.B)
  val killMiss = RegInit(false.B)

  val missReq = Reg(new ICacheReq(cfg))
  val missSet = Reg(UInt(cfg.setIdxBits.W))
  val missTag = Reg(UInt(cfg.tagBits.W))

  val respReg = Reg(new ICacheResp(cfg))

  val reqSet = setIndex(io.req.bits.meta.blockAddr)
  val reqTag = tag(io.req.bits.meta.blockAddr)

  val wayHits = Wire(Bool())
  wayHits := validArray(reqSet) && tagArray(reqSet) === reqTag

  val hit     = wayHits.asUInt.orR
  val hitData = dataArray(reqSet)

  // io.req.ready 实际上是 pcAdvance
  io.req.ready           := state === ICacheState.SIdle && (!validReg || io.resp.fire)
  io.resp.valid          := state === ICacheState.SIdle && validReg
  io.resp.bits           := respReg
  io.refillReq.valid     := state === ICacheState.SRefillReq
  io.refillReq.bits.addr := missReq.meta.blockAddr
  io.refillResp.ready    := state === ICacheState.SRefillResp

  // dpi bridge
  val dpiCache = Module(new CacheHitBridge)
  dpiCache.io.cacheFire := !reset.asBool && io.req.fire
  dpiCache.io.cacheHit  := hit

  when(state === ICacheState.SIdle) {
    when(io.req.fire) {
      killMiss := false.B
      when(hit) {
        validReg := true.B
      }.otherwise {
        state    := ICacheState.SRefillReq
        validReg := false.B
      }
    }.elsewhen(io.resp.fire) {
      validReg := false.B
    }
  }.elsewhen(state === ICacheState.SRefillReq) {
    when(io.refillReq.fire) {
      state := ICacheState.SRefillResp
    }
  }.otherwise {
    assert(state === ICacheState.SRefillResp)
    when(io.refillResp.fire) {
      state    := ICacheState.SIdle
      validReg := true.B
      killMiss := false.B
    }
  }

  when(state === ICacheState.SIdle && io.req.fire) {
    when(hit) {
      respReg.data := hitData
      respReg.meta := io.req.bits.meta
      respReg.hit  := true.B
      respReg.exception.valid := false.B
      respReg.exception.cause := 0.U
      respReg.exception.tval  := 0.U
    }.otherwise {
      missReq := io.req.bits
      missSet := reqSet
      missTag := reqTag
    }
  }.elsewhen(state === ICacheState.SRefillResp && io.refillResp.fire) {
    respReg.data      := io.refillResp.bits.data
    respReg.meta      := missReq.meta
    respReg.hit       := false.B
    respReg.exception := io.refillResp.bits.exception
    when(io.refillResp.bits.exception.valid) {
      respReg.exception.tval := missReq.meta.pc
    }
  }

  when(io.flush) {
    validArray := VecInit(Seq.fill(cfg.sets)(false.B))
    when(!(state === ICacheState.SRefillResp && io.refillResp.fire)) {
      validReg := false.B
    }
    when(state =/= ICacheState.SIdle) {
      killMiss := true.B
    }
  }

  when(state === ICacheState.SRefillResp && io.refillResp.fire && !io.refillResp.bits.exception.valid && !killMiss && !io.flush) {
    validArray(missSet) := true.B
    tagArray(missSet)   := missTag
    dataArray(missSet)  := io.refillResp.bits.data
  }
}
