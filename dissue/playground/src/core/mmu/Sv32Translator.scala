package top.core.mmu

import chisel3._
import chisel3.util.{Cat, Decoupled, Enum, MuxLookup}
import top.core.backend.csr.{Mstatus, PrivMode}
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.bundle.{DataMemReq, DataMemResp}
import top.config.BackendConfig

class Sv32Translator(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val flush = Input(Bool())

    val req  = Flipped(Decoupled(new MmuTranslateReq(cfg)))
    val resp = Decoupled(new MmuTranslateResp(cfg))

    val memReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val memResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
  })

  private val sIdle :: sPte1Req :: sPte1Resp :: sPte0Req :: sPte0Resp :: sDone :: Nil = Enum(6)
  private val state                                                                   = RegInit(sIdle)

  private val reqReg  = Reg(new MmuTranslateReq(cfg))
  private val respReg = Reg(new MmuTranslateResp(cfg))
  private val pte1Reg = Reg(UInt(cfg.dataWidth.W))

  private def satpMode(satp: UInt): UInt = satp(31)
  private def satpPpn(satp:  UInt): UInt = satp(21, 0)
  private def vpn1(vaddr:    UInt): UInt = vaddr(31, 22)
  private def vpn0(vaddr:    UInt): UInt = vaddr(21, 12)
  private def pageOff(vaddr: UInt): UInt = vaddr(11, 0)

  private def pteV(pte:    UInt): Bool = pte(0)
  private def pteR(pte:    UInt): Bool = pte(1)
  private def pteW(pte:    UInt): Bool = pte(2)
  private def pteX(pte:    UInt): Bool = pte(3)
  private def pteU(pte:    UInt): Bool = pte(4)
  private def pteA(pte:    UInt): Bool = pte(6)
  private def pteD(pte:    UInt): Bool = pte(7)
  private def ptePpn0(pte: UInt): UInt = pte(19, 10)
  private def ptePpn1(pte: UInt): UInt = pte(31, 20)
  private def ptePpn(pte:  UInt): UInt = pte(31, 10)

  private def isLeaf(pte:            UInt): Bool = pteR(pte) || pteX(pte)
  private def invalidPte(pte:        UInt): Bool = !pteV(pte) || (!pteR(pte) && pteW(pte))
  private def invalidNonLeafPte(pte: UInt): Bool = pteU(pte) || pteA(pte) || pteD(pte)

  private def pageFaultCause(access: UInt): UInt =
    MuxLookup(access, ExceptionCause.loadPageFault)(
      Seq(
        MmuAccessType.fetch -> ExceptionCause.instrPageFault,
        MmuAccessType.load  -> ExceptionCause.loadPageFault,
        MmuAccessType.store -> ExceptionCause.storePageFault,
        MmuAccessType.amo   -> ExceptionCause.storePageFault
      )
    )

  private def accessFaultCause(access: UInt): UInt =
    MuxLookup(access, ExceptionCause.loadAccessFault)(
      Seq(
        MmuAccessType.fetch -> ExceptionCause.instrAccessFault,
        MmuAccessType.load  -> ExceptionCause.loadAccessFault,
        MmuAccessType.store -> ExceptionCause.storeAccessFault,
        MmuAccessType.amo   -> ExceptionCause.storeAccessFault
      )
    )

  private def permissionFault(pte: UInt, access: UInt, priv: UInt, mstatus: UInt): Bool = {
    val mxr = mstatus(Mstatus.mxrBit)
    val sum = mstatus(Mstatus.sumBit)

    val userPage = pteU(pte)
    val userPriv = priv === PrivMode.U
    val supPriv  = priv === PrivMode.S

    val readOk  = pteR(pte) || (mxr && pteX(pte))
    val execOk  = pteX(pte)
    val writeOk = pteR(pte) && pteW(pte)
    val amoOk   = readOk && writeOk

    val accessOk = MuxLookup(access, readOk)(
      Seq(
        MmuAccessType.fetch -> execOk,
        MmuAccessType.load  -> readOk,
        MmuAccessType.store -> writeOk,
        MmuAccessType.amo   -> amoOk
      )
    )

    val privOk = Mux(
      userPriv,
      userPage,
      Mux(
        supPriv,
        !userPage || ((access === MmuAccessType.load || access === MmuAccessType.store || access === MmuAccessType.amo) && sum),
        true.B
      )
    )

    !accessOk || !privOk || !pteA(pte) || ((access === MmuAccessType.store || access === MmuAccessType.amo) && !pteD(
      pte
    ))
  }

  private def pteAddr(ppn: UInt, vpn: UInt): UInt =
    ((ppn << 12) + (vpn << 2))(cfg.addrWidth - 1, 0)

  private def pagePaddr(pte: UInt, megapage: Bool, vaddr: UInt): UInt =
    Mux(
      megapage,
      Cat(ptePpn1(pte), vpn0(vaddr), pageOff(vaddr)),
      Cat(ptePpn1(pte), ptePpn0(pte), pageOff(vaddr))
    )(cfg.addrWidth - 1, 0)

  private val translateDisabled =
    satpMode(io.req.bits.satp) === 0.U || io.req.bits.priv === PrivMode.M

  private val pte1Addr         = pteAddr(satpPpn(reqReg.satp), vpn1(reqReg.vaddr))
  private val pte0Addr         = pteAddr(ptePpn(pte1Reg), vpn0(reqReg.vaddr))
  private val incomingPte1Addr = pteAddr(satpPpn(io.req.bits.satp), vpn1(io.req.bits.vaddr))
  private val responsePte      = io.memResp.bits.data
  private val level1Terminal   = io.memResp.bits.fault || invalidPte(responsePte) || isLeaf(responsePte) ||
    invalidNonLeafPte(responsePte)

  private val terminalResponse = Wire(new MmuTranslateResp(cfg))
  terminalResponse.paddr     := reqReg.vaddr
  terminalResponse.exception := ExceptionInfo.none(cfg)
  when(state === sPte1Resp) {
    when(io.memResp.bits.fault) {
      terminalResponse.exception := ExceptionInfo.raise(accessFaultCause(reqReg.access), reqReg.vaddr, cfg)
    }.elsewhen(invalidPte(responsePte)) {
      terminalResponse.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
    }.elsewhen(isLeaf(responsePte)) {
      when(ptePpn0(responsePte).orR || permissionFault(responsePte, reqReg.access, reqReg.priv, reqReg.mstatus)) {
        terminalResponse.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
      }.otherwise {
        terminalResponse.paddr := pagePaddr(responsePte, true.B, reqReg.vaddr)
      }
    }.elsewhen(invalidNonLeafPte(responsePte)) {
      terminalResponse.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
    }
  }.elsewhen(state === sPte0Resp) {
    when(io.memResp.bits.fault) {
      terminalResponse.exception := ExceptionInfo.raise(accessFaultCause(reqReg.access), reqReg.vaddr, cfg)
    }.elsewhen(
      invalidPte(responsePte) || !isLeaf(responsePte) ||
        permissionFault(responsePte, reqReg.access, reqReg.priv, reqReg.mstatus)
    ) {
      terminalResponse.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
    }.otherwise {
      terminalResponse.paddr := pagePaddr(responsePte, false.B, reqReg.vaddr)
    }
  }

  private val terminalMemResponse = io.memResp.valid &&
    ((state === sPte1Resp && level1Terminal) || state === sPte0Resp)

  io.resp.valid := state === sDone || terminalMemResponse
  io.resp.bits  := Mux(state === sDone, respReg, terminalResponse)

  private val responseTurnover  = io.resp.fire
  private val requestWindow     = state === sIdle || responseTurnover
  private val incomingTranslate = requestWindow && io.req.valid && !translateDisabled
  private val directPte0Request = state === sPte1Resp && io.memResp.valid && !level1Terminal
  private val directPte0Addr    = pteAddr(ptePpn(responsePte), vpn0(reqReg.vaddr))

  io.req.ready := requestWindow

  io.memReq.valid := state === sPte1Req || state === sPte0Req || incomingTranslate || directPte0Request
  io.memReq.bits  := Mux(
    incomingTranslate,
    MmuMemReq.pteRead(incomingPte1Addr, cfg),
    Mux(
      directPte0Request,
      MmuMemReq.pteRead(directPte0Addr, cfg),
      Mux(state === sPte1Req, MmuMemReq.pteRead(pte1Addr, cfg), MmuMemReq.pteRead(pte0Addr, cfg))
    )
  )

  io.memResp.ready := state === sPte1Resp || state === sPte0Resp

  private def acceptTranslationRequest(): Unit = {
    reqReg            := io.req.bits
    respReg.paddr     := io.req.bits.vaddr
    respReg.exception := ExceptionInfo.none(cfg)
    when(translateDisabled) {
      state := sDone
    }.otherwise {
      state := Mux(io.memReq.fire, sPte1Resp, sPte1Req)
    }
  }

  when(io.flush) {
    state := sIdle
  }.elsewhen(state === sIdle) {
    when(io.req.fire) {
      acceptTranslationRequest()
    }
  }.elsewhen(state === sPte1Req) {
    when(io.memReq.fire) {
      state := sPte1Resp
    }
  }.elsewhen(state === sPte1Resp) {
    when(io.memResp.fire) {
      val pte = io.memResp.bits.data
      pte1Reg := pte

      when(level1Terminal) {
        when(io.resp.fire) {
          when(io.req.fire) {
            acceptTranslationRequest()
          }.otherwise {
            state := sIdle
          }
        }.otherwise {
          respReg := terminalResponse
          state   := sDone
        }
      }.otherwise {
        state := Mux(io.memReq.fire, sPte0Resp, sPte0Req)
      }
    }
  }.elsewhen(state === sPte0Req) {
    when(io.memReq.fire) {
      state := sPte0Resp
    }
  }.elsewhen(state === sPte0Resp) {
    when(io.memResp.fire) {
      when(io.resp.fire) {
        when(io.req.fire) {
          acceptTranslationRequest()
        }.otherwise {
          state := sIdle
        }
      }.otherwise {
        respReg := terminalResponse
        state   := sDone
      }
    }
  }.otherwise {
    when(io.resp.fire) {
      when(io.req.fire) {
        acceptTranslationRequest()
      }.otherwise {
        state := sIdle
      }
    }
  }

  private val translationOwned = RegInit(false.B)
  when(io.req.fire) {
    assert(!translationOwned || io.resp.fire)
  }
  when(io.resp.fire) {
    assert(translationOwned)
  }
  when(io.flush) {
    translationOwned := false.B
  }.otherwise {
    translationOwned := (translationOwned && !io.resp.fire) || io.req.fire
  }
}
