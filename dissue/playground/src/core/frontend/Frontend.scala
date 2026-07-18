package top.core.frontend

import chisel3._
import chisel3.util.{Cat, Decoupled, MuxCase, Valid}
import top.core.backend.csr.CsrStatus
import top.core.bundle.{DataMemReq, DataMemResp, FrontendPerfEvent}
import top.config.{BackendConfig, FrontendConfig}
import top.core.frontend.Bpu.Bpu
import top.core.frontend.bundle.{BpuUpdate, ICacheRefillReq, ICacheRefillResp, PcRedirect}
import top.core.frontend.ifetch.{FetchPacket, IFetch}
import top.core.frontend.pcgen.PCGen
import top.core.frontend.icache._
import top.sim.FrontendPerfBridge

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
    val icacheInvalidate = Input(Bool())
  })

  val pcGen     = Module(
    new PCGen(
      resetVector = resetVector,
      addrWidth = cfg.addrWidth,
      fetchBytes = cfg.fetchBytes,
      maxAdvanceBlocks = cfg.icache.fetchGroupBlocks
    )
  )
  val ifetch    = Module(new IFetch(cfg.icache, cfg.ifetch))
  val iCache    = Module(new ICache(cfg.icache))
  val refillMmu = Module(new ICacheRefillMmu(cfg.icache, backendCfg))
  val bpu       = Module(new Bpu(cfg.bpu))
  val perf      = Module(new FrontendPerfBridge)

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
  pcGen.io.advanceBlocks := ifetch.io.pcAdvanceBlocks

  ifetch.io.redirect       := redirect
  ifetch.io.flush          := io.icacheInvalidate
  ifetch.io.pc             := pcGen.io.pc
  ifetch.io.pred(0).valid     := bpu.io.pred.valid
  ifetch.io.pred(0).taken     := bpu.io.pred.taken
  ifetch.io.pred(0).target    := bpu.io.pred.target
  ifetch.io.pred(0).cfiOffset := bpu.io.pred.cfiOffset
  ifetch.io.pred(0).cfiType   := bpu.io.pred.cfiType
  ifetch.io.pred(1).valid     := bpu.io.predSecondary.valid
  ifetch.io.pred(1).taken     := bpu.io.predSecondary.taken
  ifetch.io.pred(1).target    := bpu.io.predSecondary.target
  ifetch.io.pred(1).cfiOffset := bpu.io.predSecondary.cfiOffset
  ifetch.io.pred(1).cfiType   := bpu.io.predSecondary.cfiType

  val firstBlockAddr = Cat(
    pcGen.io.pc(cfg.addrWidth - 1, cfg.icache.offsetBits),
    0.U(cfg.icache.offsetBits.W)
  )
  bpu.io.lookup.valid             := true.B
  bpu.io.lookup.bits.pc           := pcGen.io.pc
  bpu.io.lookupSecondary.valid    := true.B
  bpu.io.lookupSecondary.bits.pc  := firstBlockAddr + cfg.fetchBytes.U
  bpu.io.update.valid             := io.bpuUpdate.valid
  bpu.io.update.bits              := io.bpuUpdate.bits

  ifetch.io.icacheReq <> iCache.io.req
  ifetch.io.icacheResp <> iCache.io.resp
  ifetch.io.icacheAcceptedBlocks := iCache.io.acceptedBlocks
  iCache.io.invalidate := io.icacheInvalidate
  iCache.io.redirect   := ifetch.io.frontendRedirect

  private val redirectDuringMshr = redirect.valid && iCache.io.perf.mshrActive && !io.icacheInvalidate
  private val redirectMshrPending = RegInit(false.B)
  private val redirectMshrTarget  = Reg(UInt(cfg.addrWidth.W))
  private val redirectTargetRequest = iCache.io.req.fire &&
    iCache.io.req.bits.blocks(0).bits.meta.control.pc === redirectMshrTarget
  private val redirectDuringMshrTargetHit = redirectMshrPending && redirectTargetRequest &&
    iCache.io.perf.hitUnderMiss

  when(io.icacheInvalidate) {
    redirectMshrPending := false.B
  }.elsewhen(redirect.valid) {
    redirectMshrPending := redirectDuringMshr
    redirectMshrTarget  := redirect.value
  }.elsewhen(redirectMshrPending && iCache.io.req.fire) {
    redirectMshrPending := false.B
  }

  when(redirectMshrPending && iCache.io.req.fire) {
    assert(redirectTargetRequest)
  }

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

  private val fetchQueueSupplyStarved =
    ifetch.io.fetchQueueEmpty && io.fetch.ready && !pcRedirect.valid && !io.icacheInvalidate

  private val perfEvents = Seq(
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheRequest, iCache.io.perf.request),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheHit, iCache.io.perf.hit),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMiss, iCache.io.perf.miss),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMissWaitCycle, iCache.io.perf.missWait),
    FrontendPerfEvent.bit(FrontendPerfEvent.backendRedirect, redirect.valid),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheInvalidate, io.icacheInvalidate),
    FrontendPerfEvent.bit(FrontendPerfEvent.frontendEmpty, io.fetch.ready && !io.fetch.valid),
    FrontendPerfEvent.bit(FrontendPerfEvent.axiRequestWait, refillMmu.io.physReq.valid && !io.cacheRefillReq.ready),
    FrontendPerfEvent.bit(
      FrontendPerfEvent.fetchQueueEmptyWithBackendReady,
      fetchQueueSupplyStarved
    ),
    FrontendPerfEvent.bit(FrontendPerfEvent.fetchQueueFull, ifetch.io.fetchQueueFull),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheMshrActiveCycle, iCache.io.perf.mshrActive),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheHitUnderMiss, iCache.io.perf.hitUnderMiss),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheSameLineWaitCycle, iCache.io.perf.sameLineWait),
    FrontendPerfEvent.bit(FrontendPerfEvent.icacheQueuedMiss, iCache.io.perf.queuedMiss),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshr, redirectDuringMshr),
    FrontendPerfEvent.bit(FrontendPerfEvent.redirectDuringMshrTargetHit, redirectDuringMshrTargetHit),
    FrontendPerfEvent.bit(
      FrontendPerfEvent.staleResponseDrop,
      ifetch.io.staleResponseDrop || iCache.io.perf.staleResponseDrop
    )
  ).reduce(_ | _)

  perf.io.events                 := perfEvents
  perf.io.fetchQueueOccupancy    := ifetch.io.fetchQueueOccupancy.pad(32)
  perf.io.fetchQueueEnqueueWidth := ifetch.io.fetchQueueEnqueueWidth.pad(32)
  perf.io.fetchQueueDequeueWidth := ifetch.io.fetchQueueDequeueWidth.pad(32)
}
