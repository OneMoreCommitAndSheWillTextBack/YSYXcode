package top.core.backend.lsu

import chisel3._
import chisel3.util.{Decoupled, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{TlbRefill, TlbSfence}
import top.core.backend.csr.PrivMode
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.{DataMemReq, DataMemResp, RobRecovery}
import top.core.mmu.{MmuTranslateReq, MmuTranslateResp, Sv32Translator}
import top.core.monitor.TlbMonitor

/** LSU/MMU boundary: DTLB in front of the shared Sv32 walker.
  *
  * Translation-disabled requests (M mode or satp.MODE = 0) bypass the DTLB and return identity one cycle after the
  * request fires, matching the walker's bare-mode latency. A miss is answered immediately with `deferred` and its final
  * translation arrives on `complete`; the walker and miss queue therefore never block younger lookups. `flush`
  * (trap/global recovery) kills in-flight lookups and queued walks; `recover` additionally drops queued or walking
  * requests younger than the recovery boundary; `sfence` also invalidates entries.
  */
class LsuMmu(cfg: BackendConfig = BackendConfig(), enableMonitor: Boolean = false) extends Module {
  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new MmuTranslateReq(cfg)))
    val resp = Decoupled(new MmuTranslateResp(cfg))

    val complete = Valid(new MmuTranslateResp(cfg))

    val ptwReq    = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val ptwResp   = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val ptwRobIdx = Output(UInt(cfg.robIdxWidth.W))

    val sfence    = Input(Valid(new TlbSfence(cfg)))
    val flush     = Input(Bool())
    val recover   = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead   = Input(UInt(cfg.robIdxWidth.W))
    val walkAbort = Output(Bool())
    val idle      = Output(Bool())

    val monitor = Output(new TlbMonitor(cfg))
  })

  private val dtlb       = Module(new DTLB(cfg, enableMonitor))
  private val translator = Module(new Sv32Translator(cfg))

  // A request is translation-disabled when Sv32 is off or the effective data
  // privilege is M (MPRV has already been folded into req.bits.priv by the LSU).
  private val translateDisabled =
    io.req.bits.satp(31) === 0.U || io.req.bits.priv === PrivMode.M

  private val bypassValid = RegInit(false.B)
  private val bypassResp  = Reg(new MmuTranslateResp(cfg))

  // The bypass path is a one-entry response pipeline, but it accepts the next
  // request in the cycle the previous response is consumed, so bare-M mode also
  // sustains one lookup per cycle.
  private val bypassCanAccept = !bypassValid || io.resp.fire

  io.req.ready := Mux(translateDisabled, bypassCanAccept, dtlb.io.req.ready)

  when(io.flush) {
    bypassValid := false.B
  }.elsewhen(io.req.fire && translateDisabled) {
    bypassValid          := true.B
    bypassResp.paddr     := io.req.bits.vaddr
    bypassResp.exception := 0.U.asTypeOf(new ExceptionInfo(cfg))
    bypassResp.vaddr     := io.req.bits.vaddr
    bypassResp.pte       := 0.U
    bypassResp.level     := 0.U
    bypassResp.fill      := false.B
    bypassResp.id        := io.req.bits.id
    bypassResp.robIdx    := io.req.bits.robIdx
    bypassResp.deferred  := false.B
  }.elsewhen(io.resp.fire && bypassValid) {
    bypassValid := false.B
  }

  dtlb.io.req.valid := io.req.valid && !translateDisabled
  dtlb.io.req.bits  := io.req.bits

  io.resp.valid      := bypassValid || dtlb.io.resp.valid
  io.resp.bits       := Mux(bypassValid, bypassResp, dtlb.io.resp.bits)
  dtlb.io.resp.ready := io.resp.ready && !bypassValid

  io.complete := dtlb.io.complete

  dtlb.io.sfence  := io.sfence
  dtlb.io.flush   := io.flush
  dtlb.io.recover := io.recover
  dtlb.io.robHead := io.robHead
  io.walkAbort    := dtlb.io.walkFlush
  io.idle         := dtlb.io.idle

  // DTLB miss -> walker. The DTLB deasserts missReq in a refill cycle so the
  // walker cannot re-accept the same request while returning its response.
  translator.io.req.valid := dtlb.io.missReq.valid
  translator.io.req.bits  := dtlb.io.missReq.bits
  dtlb.io.missReq.ready   := translator.io.req.ready

  translator.io.flush := dtlb.io.walkFlush

  private val refill = Wire(new TlbRefill(cfg))
  refill.vaddr     := translator.io.resp.bits.vaddr
  refill.pte       := translator.io.resp.bits.pte
  refill.level     := translator.io.resp.bits.level
  refill.paddr     := translator.io.resp.bits.paddr
  refill.fill      := translator.io.resp.bits.fill
  refill.exception := translator.io.resp.bits.exception

  dtlb.io.refill.valid     := translator.io.resp.valid
  dtlb.io.refill.bits      := refill
  translator.io.resp.ready := dtlb.io.refill.ready

  io.ptwReq.valid            := translator.io.memReq.valid
  io.ptwReq.bits             := translator.io.memReq.bits
  translator.io.memReq.ready := io.ptwReq.ready

  translator.io.memResp.valid := io.ptwResp.valid
  translator.io.memResp.bits  := io.ptwResp.bits
  io.ptwResp.ready            := translator.io.memResp.ready

  // PTW ownership follows the walking request, not the S3 stage, because the
  // walker is decoupled from dispatch.
  io.ptwRobIdx := dtlb.io.walkRobIdx

  io.monitor := dtlb.io.monitor
}
