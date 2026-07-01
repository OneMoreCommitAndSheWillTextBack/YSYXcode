package top.frontend

import chisel3._
import chisel3.util.{Decoupled, MuxCase, Valid}
import top.config.FrontendConfig
import top.frontend.Bpu.Bpu
import top.frontend.bundle.{BpuUpdate, ICacheRefillReq, ICacheRefillResp, PcRedirect}
import top.frontend.ifetch.{FetchPacket, IFetch}
import top.frontend.pcgen.PCGen
import top.frontend.icache._

class Frontend(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         FrontendConfig = FrontendConfig())
    extends Module {
  val io = IO(new Bundle {
    val trapRedirect   = Input(new PcRedirect)
    val branchRedirect = Input(new PcRedirect)
    val predRedirect   = Input(new PcRedirect)
    val bpuUpdate      = Flipped(Valid(new BpuUpdate(cfg.bpu)))

    val pc    = Output(UInt(cfg.addrWidth.W))
    val fetch = Decoupled(new FetchPacket)

    val cacheRefillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
    val cacheRefillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))
  })

  val pcGen  = Module(
    new PCGen(
      resetVector = resetVector,
      addrWidth = cfg.addrWidth,
      fetchBytes = cfg.fetchBytes
    )
  )
  val ifetch = Module(new IFetch(cfg.icache, cfg.ifetch))
  val iCache = Module(new ICache(cfg.icache))
  val bpu    = Module(new Bpu(cfg.bpu))

  val redirect = Wire(new PcRedirect)
  redirect.valid := io.trapRedirect.valid || io.branchRedirect.valid || io.predRedirect.valid
  redirect.value := MuxCase(
    0.U(cfg.addrWidth.W),
    Seq(
      io.trapRedirect.valid   -> io.trapRedirect.value,
      io.branchRedirect.valid -> io.branchRedirect.value,
      io.predRedirect.valid   -> io.predRedirect.value
    )
  )

  val pcRedirect = Wire(new PcRedirect)
  pcRedirect.valid := redirect.valid || (ifetch.io.pcAdvance && bpu.io.pred.taken)
  pcRedirect.value := Mux(redirect.valid, redirect.value, bpu.io.pred.target)

  pcGen.io.redirect := pcRedirect
  pcGen.io.advance  := ifetch.io.pcAdvance

  ifetch.io.redirect       := redirect
  ifetch.io.pc             := pcGen.io.pc
  ifetch.io.pred.valid     := bpu.io.pred.valid
  ifetch.io.pred.taken     := bpu.io.pred.taken
  ifetch.io.pred.target    := bpu.io.pred.target
  ifetch.io.pred.cfiOffset := bpu.io.pred.cfiOffset
  ifetch.io.pred.cfiType   := bpu.io.pred.cfiType

  bpu.io.lookup.valid   := true.B
  bpu.io.lookup.bits.pc := pcGen.io.pc
  bpu.io.update.valid   := io.bpuUpdate.valid
  bpu.io.update.bits    := io.bpuUpdate.bits

  ifetch.io.icacheReq <> iCache.io.req
  ifetch.io.icacheResp <> iCache.io.resp

  io.pc := pcGen.io.pc
  io.fetch <> ifetch.io.fetch
  io.cacheRefillReq <> iCache.io.refillReq
  io.cacheRefillResp <> iCache.io.refillResp
}
