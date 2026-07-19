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

  io.req.ready  := state === sIdle
  io.resp.valid := state === sDone
  io.resp.bits  := respReg

  val pte1Addr = pteAddr(satpPpn(reqReg.satp), vpn1(reqReg.vaddr))
  val pte0Addr = pteAddr(ptePpn(pte1Reg), vpn0(reqReg.vaddr))

  io.memReq.valid := state === sPte1Req || state === sPte0Req
  io.memReq.bits  := Mux(state === sPte1Req, MmuMemReq.pteRead(pte1Addr, cfg), MmuMemReq.pteRead(pte0Addr, cfg))

  io.memResp.ready := state === sPte1Resp || state === sPte0Resp

  when(io.flush) {
    state := sIdle
  }.elsewhen(state === sIdle) {
    when(io.req.fire) {
      reqReg            := io.req.bits
      respReg.paddr     := io.req.bits.vaddr
      respReg.exception := ExceptionInfo.none(cfg)
      when(translateDisabled) {
        state := sDone
      }.otherwise {
        state := sPte1Req
      }
    }
  }.elsewhen(state === sPte1Req) {
    when(io.memReq.fire) {
      state := sPte1Resp
    }
  }.elsewhen(state === sPte1Resp) {
    when(io.memResp.fire) {
      val pte = io.memResp.bits.data
      pte1Reg := pte

      when(io.memResp.bits.fault) {
        respReg.exception := ExceptionInfo.raise(accessFaultCause(reqReg.access), reqReg.vaddr, cfg)
        state             := sDone
      }.elsewhen(invalidPte(pte)) {
        respReg.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
        state             := sDone
      }.elsewhen(isLeaf(pte)) {
        when(ptePpn0(pte).orR || permissionFault(pte, reqReg.access, reqReg.priv, reqReg.mstatus)) {
          respReg.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
        }.otherwise {
          respReg.paddr := pagePaddr(pte, true.B, reqReg.vaddr)
        }
        state := sDone
      }.elsewhen(invalidNonLeafPte(pte)) {
        respReg.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
        state             := sDone
      }.otherwise {
        state := sPte0Req
      }
    }
  }.elsewhen(state === sPte0Req) {
    when(io.memReq.fire) {
      state := sPte0Resp
    }
  }.elsewhen(state === sPte0Resp) {
    when(io.memResp.fire) {
      val pte = io.memResp.bits.data

      when(io.memResp.bits.fault) {
        respReg.exception := ExceptionInfo.raise(accessFaultCause(reqReg.access), reqReg.vaddr, cfg)
      }.elsewhen(invalidPte(pte) || !isLeaf(pte) || permissionFault(pte, reqReg.access, reqReg.priv, reqReg.mstatus)) {
        respReg.exception := ExceptionInfo.raise(pageFaultCause(reqReg.access), reqReg.vaddr, cfg)
      }.otherwise {
        respReg.paddr := pagePaddr(pte, false.B, reqReg.vaddr)
      }
      state := sDone
    }
  }.otherwise {
    when(io.resp.fire) {
      state := sIdle
    }
  }
}
