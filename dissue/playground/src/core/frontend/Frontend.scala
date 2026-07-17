package top.core.frontend

import chisel3._
import chisel3.util.{Decoupled, MuxCase, Valid}
import top.core.backend.csr.CsrStatus
import top.core.bundle.{DataMemReq, DataMemResp}
import top.config.{BackendConfig, FrontendConfig}
import top.core.frontend.Bpu.Bpu
import top.core.frontend.bundle.{BpuUpdate, ICacheRefillReq, ICacheRefillResp, PcRedirect}
import top.core.frontend.ifetch.{FetchPacket, IFetch}
import top.core.frontend.pcgen.PCGen
import top.core.frontend.icache._

class Frontend(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         FrontendConfig = FrontendConfig())
    extends Module {
  private val backendCfg = BackendConfig(addrWidth = cfg.addrWidth)

  val io = IO(new Bundle {
    val trapRedirect   = Input(new PcRedirect)
    val branchRedirect = Input(new PcRedirect)
    val predRedirect   = Input(new PcRedirect)
    val bpuUpdate      = Flipped(Valid(new BpuUpdate(cfg.bpu)))

    val pc    = Output(UInt(cfg.addrWidth.W))
    val fetch = Decoupled(new FetchPacket)

    val cacheRefillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
    val cacheRefillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))

    val ptwReq    = Decoupled(new DataMemReq(backendCfg.addrWidth, backendCfg.dataWidth))
    val ptwResp   = Flipped(Decoupled(new DataMemResp(backendCfg.dataWidth)))
    val csrStatus = Input(new CsrStatus(backendCfg))
  })

  val pcGen     = Module(
    new PCGen(
      resetVector = resetVector,
      addrWidth = cfg.addrWidth,
      fetchBytes = cfg.fetchBytes
    )
  )
  val ifetch    = Module(new IFetch(cfg.icache, cfg.ifetch))
  val iCache    = Module(new ICache(cfg.icache))
  val refillMmu = Module(new ICacheRefillMmu(cfg.icache, backendCfg))
  val bpu       = Module(new Bpu(cfg.bpu))

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
  pcRedirect.valid := redirect.valid || ifetch.io.predRedirect.valid
  pcRedirect.value := Mux(redirect.valid, redirect.value, ifetch.io.predRedirect.value)

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
  // 我绷不住了
  iCache.io.flush := redirect.valid

  refillMmu.io.csrStatus     := io.csrStatus
  iCache.io.refillReq <> refillMmu.io.refillReq
  iCache.io.refillResp <> refillMmu.io.refillResp
  io.cacheRefillReq <> refillMmu.io.physReq
  refillMmu.io.physResp <> io.cacheRefillResp
  io.ptwReq.valid            := refillMmu.io.ptwReq.valid
  io.ptwReq.bits             := refillMmu.io.ptwReq.bits
  refillMmu.io.ptwReq.ready  := io.ptwReq.ready
  refillMmu.io.ptwResp.valid := io.ptwResp.valid
  refillMmu.io.ptwResp.bits  := io.ptwResp.bits
  io.ptwResp.ready           := refillMmu.io.ptwResp.ready

  io.pc := pcGen.io.pc
  io.fetch <> ifetch.io.fetch
}
