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

class ICache(cfg: ICacheConfig = ICacheConfig()) extends Module {
  val io = IO(new ICacheIO(cfg))

  private def setIndex(addr: UInt): UInt = {
    if (cfg.setIndex == 0) {
      0.UInt(cfg.setIndex.W)
    } else {
      addr(cfg.offsetBits + cfg.indexBits - 1, cfg.offsetBits)
    }
  }

  private def tag(addr: UInt): UInt = {
    return addr(cfg.addrWidth - 1, cfg.offsetBits + cfg.indexBits)
  }

  private def nextWay(way: UInt): UInt = {
    if (cfg.ways == 1) {
      0.U(cfg.wayIndexBits.W)
    } else {
      Mux(way === (cfg.ways - 1).U, 0.U, 1.U)
    }
  }

  val validArray = RegInit(VecInit(Seq.fill(cfg.sets)(VecInit(Seq.fill(cfg.ways)(false.B)))))
}
