package top.core.frontend

import chisel3._
import chisel3.util.{Decoupled, Enum}
import top.core.backend.csr.{CsrStatus, PrivMode}
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.{DataMemReq, DataMemResp}
import top.config.{BackendConfig, ICacheConfig}
import top.core.frontend.bundle.{ICacheRefillReq, ICacheRefillResp}
import top.core.mmu.{MmuAccessType, MmuTranslateReq, Sv32Translator}

class ICacheRefillMmu(
  cacheCfg:   ICacheConfig = ICacheConfig(),
  backendCfg: BackendConfig = BackendConfig())
    extends Module {
  val io = IO(new Bundle {
    val csrStatus = Input(new CsrStatus(backendCfg))

    val refillReq  = Flipped(Decoupled(new ICacheRefillReq(cacheCfg.addrWidth)))
    val refillResp = Decoupled(new ICacheRefillResp(cacheCfg.lineBytes))

    val physReq  = Decoupled(new ICacheRefillReq(cacheCfg.addrWidth))
    val physResp = Flipped(Decoupled(new ICacheRefillResp(cacheCfg.lineBytes)))

    val ptwReq  = Decoupled(new DataMemReq(backendCfg.addrWidth, backendCfg.dataWidth))
    val ptwResp = Flipped(Decoupled(new DataMemResp(backendCfg.dataWidth)))
  })

  private val sIdle :: sBareReq :: sBareResp :: sTranslate :: sRefillReq :: sRefillResp :: sFaultResp :: Nil = Enum(7)
  private val state                                                                                          = RegInit(sIdle)

  private val bareReqReg   = Reg(new ICacheRefillReq(cacheCfg.addrWidth))
  private val paddrReg     = Reg(UInt(cacheCfg.addrWidth.W))
  private val exceptionReg = Reg(new top.core.bundle.FetchException(cacheCfg.addrWidth))

  private val translator = Module(new Sv32Translator(backendCfg))

  private val bareMode = io.csrStatus.priv.mode === PrivMode.M || io.csrStatus.satp(31) === 0.U
  private val bareReq  = state === sIdle && io.refillReq.valid && bareMode

  translator.io.flush            := false.B
  translator.io.req.valid        := state === sIdle && io.refillReq.valid && !bareMode
  translator.io.req.bits         := 0.U.asTypeOf(new MmuTranslateReq(backendCfg))
  translator.io.req.bits.vaddr   := io.refillReq.bits.addr
  translator.io.req.bits.access  := MmuAccessType.fetch
  translator.io.req.bits.priv    := io.csrStatus.priv.mode
  translator.io.req.bits.mstatus := io.csrStatus.mstatus
  translator.io.req.bits.satp    := io.csrStatus.satp
  translator.io.resp.ready       := state === sTranslate

  io.refillReq.ready := state === sIdle && Mux(bareMode, true.B, translator.io.req.ready)

  io.ptwReq.valid             := translator.io.memReq.valid
  io.ptwReq.bits              := translator.io.memReq.bits
  translator.io.memReq.ready  := io.ptwReq.ready
  translator.io.memResp.valid := io.ptwResp.valid
  translator.io.memResp.bits  := io.ptwResp.bits
  io.ptwResp.ready            := translator.io.memResp.ready

  io.physReq.valid     := state === sBareReq || state === sRefillReq || bareReq
  io.physReq.bits.addr := Mux(
    bareReq,
    io.refillReq.bits.addr,
    Mux(state === sBareReq, bareReqReg.addr, paddrReg)
  )

  io.physResp.ready := (state === sBareResp || state === sRefillResp) && io.refillResp.ready

  io.refillResp.valid          := state === sFaultResp || ((state === sBareResp || state === sRefillResp) && io.physResp.valid)
  io.refillResp.bits.data      := Mux(state === sFaultResp, 0.U, io.physResp.bits.data)
  io.refillResp.bits.exception := exceptionReg
  when(state === sBareResp || state === sRefillResp) {
    io.refillResp.bits.exception := io.physResp.bits.exception
  }

  private def toFetchException(info: ExceptionInfo): top.core.bundle.FetchException = {
    val out = Wire(new top.core.bundle.FetchException(cacheCfg.addrWidth))
    out.valid := info.valid
    out.cause := info.cause
    out.tval  := info.tval(cacheCfg.addrWidth - 1, 0)
    out
  }

  when(state === sIdle) {
    when(io.refillReq.fire) {
      when(bareMode) {
        when(io.physReq.fire) {
          state := sBareResp
        }.otherwise {
          bareReqReg := io.refillReq.bits
          state      := sBareReq
        }
      }.otherwise {
        state := sTranslate
      }
    }
  }.elsewhen(state === sBareReq) {
    when(io.physReq.fire) {
      state := sBareResp
    }
  }.elsewhen(state === sBareResp) {
    when(io.refillResp.fire) {
      state := sIdle
    }
  }.elsewhen(state === sTranslate) {
    when(translator.io.resp.fire) {
      when(translator.io.resp.bits.exception.valid) {
        exceptionReg := toFetchException(translator.io.resp.bits.exception)
        state        := sFaultResp
      }.otherwise {
        paddrReg := translator.io.resp.bits.paddr
        state    := sRefillReq
      }
    }
  }.elsewhen(state === sRefillReq) {
    when(io.physReq.fire) {
      state := sRefillResp
    }
  }.elsewhen(state === sRefillResp) {
    when(io.refillResp.fire) {
      state := sIdle
    }
  }.otherwise {
    when(io.refillResp.fire) {
      state := sIdle
    }
  }

  private val refillOwned             = RegInit(false.B)
  private val bareAcceptedWithoutPhys = state === sIdle && io.refillReq.fire && bareMode && !io.physReq.fire
  private val bareBufferedAfterAccept = RegNext(bareAcceptedWithoutPhys, false.B)

  when(io.refillReq.fire) {
    assert(!refillOwned)
  }
  when(io.refillResp.fire) {
    assert(refillOwned)
  }
  refillOwned := (refillOwned || io.refillReq.fire) && !io.refillResp.fire

  when(bareBufferedAfterAccept) {
    assert(state === sBareReq)
  }
  when(io.physReq.fire) {
    assert(bareReq || state === sBareReq || state === sRefillReq)
  }
  when(io.physResp.valid) {
    assert(state === sBareResp || state === sRefillResp)
  }
  when(state === sIdle && io.refillReq.fire && bareMode) {
    assert(io.physReq.valid)
  }
}
