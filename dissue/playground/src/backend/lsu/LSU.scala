package top.backend.lsu

import chisel3._
import chisel3.util.{Decoupled, Enum, MuxLookup, Valid}
import top.backend.bundle.{IssuePacket, IssueWakeup, RobWritebackPacket}
import top.backend.csr.{CsrStatus, Mstatus, PrivMode}
import top.backend.decoder.{LsuOp, MemSize}
import top.backend.exception.{ExceptionCause, ExceptionInfo}
import top.bundle.{DataMemReq, DataMemResp}
import top.config.BackendConfig
import top.mmu.{MmuAccessType, MmuTranslateReq, Sv32Translator}

class LSU(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IssuePacket(cfg)))

    val dmemReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val dmemResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
    val busy      = Output(Bool())
    val flush     = Input(Bool())
    val csrStatus = Input(new CsrStatus(cfg))
  })

  private val sIdle :: sTranslate :: sLoadReq :: sLoadResp :: sAmoReadReq :: sAmoReadResp :: sAmoWriteReq :: sAmoWriteResp :: Nil =
    Enum(8)
  private val state = RegInit(sIdle)

  private val reqReg     = Reg(new IssuePacket(cfg))
  private val vaddrReg   = Reg(UInt(cfg.addrWidth.W))
  private val paddrReg   = Reg(UInt(cfg.addrWidth.W))
  private val amoOldReg  = Reg(UInt(cfg.dataWidth.W))
  private val reservationValid = RegInit(false.B)
  private val reservationAddr  = Reg(UInt(cfg.addrWidth.W))

  private val translator = Module(new Sv32Translator(cfg))

  private val dataBytes = cfg.dataWidth / 8
  private def asAddr(value: UInt): UInt =
    value.pad(cfg.addrWidth)(cfg.addrWidth - 1, 0)

  private val addr       = asAddr(io.in.bits.src1.data + io.in.bits.imm)
  private val misaligned = MuxLookup(io.in.bits.memSize, false.B)(
    Seq(
      MemSize.half.U -> addr(0),
      MemSize.word.U -> addr(1, 0).orR
    )
  )
  private def maskFor(size: UInt): UInt =
    MuxLookup(size, 0.U(dataBytes.W))(
      Seq(
        MemSize.byte.U -> 1.U(dataBytes.W),
        MemSize.half.U -> 3.U(dataBytes.W),
        MemSize.word.U -> ((1 << dataBytes) - 1).U(dataBytes.W)
      )
    )

  private val storeMask  = maskFor(io.in.bits.memSize)
  private val reqStoreMask = maskFor(reqReg.memSize)

  private def isLoadOp(packet: IssuePacket): Bool =
    packet.fuOp === LsuOp.load

  private def isStoreOp(packet: IssuePacket): Bool =
    packet.fuOp === LsuOp.store

  private def isLrOp(packet: IssuePacket): Bool =
    packet.fuOp === LsuOp.lr

  private def isScOp(packet: IssuePacket): Bool =
    packet.fuOp === LsuOp.sc

  private def isAmoRmwOp(packet: IssuePacket): Bool =
    packet.isAmo && !isLrOp(packet) && !isScOp(packet)

  private def effectiveDataPriv: UInt = {
    val mprv = io.csrStatus.mstatus(Mstatus.mprvBit)
    val mpp  = io.csrStatus.mstatus(Mstatus.mppMsb, Mstatus.mppLsb)
    Mux(io.csrStatus.priv.mode === PrivMode.M && mprv, mpp, io.csrStatus.priv.mode)
  }

  private def translateAccess(packet: IssuePacket): UInt =
    Mux(
      isLoadOp(packet) || isLrOp(packet),
      MmuAccessType.load,
      Mux(isAmoRmwOp(packet), MmuAccessType.amo, MmuAccessType.store)
    )

  private def accessFaultCause(packet: IssuePacket): UInt =
    Mux(
      isLoadOp(packet) || isLrOp(packet),
      ExceptionCause.loadAccessFault,
      ExceptionCause.storeAccessFault
    )

  private def amoWriteData(old: UInt, rhs: UInt, op: UInt): UInt =
    MuxLookup(op, rhs)(
      Seq(
        LsuOp.amoSwap -> rhs,
        LsuOp.amoAdd  -> (old + rhs),
        LsuOp.amoXor  -> (old ^ rhs),
        LsuOp.amoAnd  -> (old & rhs),
        LsuOp.amoOr   -> (old | rhs),
        LsuOp.amoMin  -> Mux(old.asSInt < rhs.asSInt, old, rhs),
        LsuOp.amoMax  -> Mux(old.asSInt < rhs.asSInt, rhs, old),
        LsuOp.amoMinu -> Mux(old < rhs, old, rhs),
        LsuOp.amoMaxu -> Mux(old < rhs, rhs, old)
      )
    )

  val isLoad         = io.in.bits.fuOp === LsuOp.load
  val isStore        = io.in.bits.fuOp === LsuOp.store
  val isAtomic       = io.in.bits.isAmo
  val needsTranslate = (isLoad || isStore || isAtomic) && !misaligned
  val canAcceptInput = !io.flush && state === sIdle

  io.busy := state =/= sIdle

  translator.io.req.valid         := canAcceptInput && io.in.valid && needsTranslate
  translator.io.req.bits          := 0.U.asTypeOf(new MmuTranslateReq(cfg))
  translator.io.req.bits.vaddr    := addr
  translator.io.req.bits.access   := translateAccess(io.in.bits)
  translator.io.req.bits.priv     := effectiveDataPriv
  translator.io.req.bits.mstatus  := io.csrStatus.mstatus
  translator.io.req.bits.satp     := io.csrStatus.satp
  translator.io.resp.ready        := state === sTranslate

  val amoStoreData = Mux(isScOp(reqReg), reqReg.src2.data, amoWriteData(amoOldReg, reqReg.src2.data, reqReg.fuOp))

  val loadReq = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  loadReq          := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  loadReq.addr     := paddrReg
  loadReq.write    := false.B
  loadReq.size     := reqReg.memSize
  loadReq.unsigned := reqReg.memUnsigned

  val amoReadReq = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoReadReq          := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoReadReq.addr     := paddrReg
  amoReadReq.write    := false.B
  amoReadReq.size     := MemSize.word.U
  amoReadReq.unsigned := true.B

  val amoWriteReq = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoWriteReq          := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoWriteReq.addr     := paddrReg
  amoWriteReq.write    := true.B
  amoWriteReq.size     := MemSize.word.U
  amoWriteReq.unsigned := false.B
  amoWriteReq.wdata    := amoStoreData
  amoWriteReq.wmask    := ((1 << dataBytes) - 1).U(dataBytes.W)

  io.dmemReq.valid := (state === sTranslate && translator.io.memReq.valid) ||
    state === sLoadReq ||
    state === sAmoReadReq ||
    state === sAmoWriteReq
  io.dmemReq.bits := Mux(
    state === sTranslate,
    translator.io.memReq.bits,
    Mux(state === sLoadReq, loadReq, Mux(state === sAmoReadReq, amoReadReq, amoWriteReq))
  )

  translator.io.memReq.ready  := state === sTranslate && io.dmemReq.ready
  translator.io.memResp.valid := state === sTranslate && io.dmemResp.valid
  translator.io.memResp.bits  := io.dmemResp.bits

  io.in.ready := canAcceptInput && Mux(needsTranslate, translator.io.req.ready, true.B)

  io.dmemResp.ready := Mux(
    state === sTranslate,
    translator.io.memResp.ready,
    state === sLoadResp || state === sAmoReadResp || state === sAmoWriteResp
  )

  io.writeback.valid          := false.B
  io.writeback.bits           := 0.U.asTypeOf(new RobWritebackPacket(cfg))

  io.wakeup := 0.U.asTypeOf(new IssueWakeup(cfg))

  when(io.flush) {
    state := sIdle
  }.otherwise {
    when(state === sIdle) {
      when(io.in.fire && isLoad) {
        when(misaligned) {
          io.writeback.valid          := true.B
          io.writeback.bits.robIdx    := io.in.bits.robIdx
          io.writeback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAddrMisaligned, addr, cfg)
        }.otherwise {
          reqReg   := io.in.bits
          vaddrReg := addr
          state    := sTranslate
        }
      }.elsewhen(io.in.fire && isStore) {
        io.writeback.valid          := true.B
        io.writeback.bits.robIdx    := io.in.bits.robIdx
        io.writeback.bits.result    := 0.U
        io.writeback.bits.storeData := io.in.bits.src2.data
        io.writeback.bits.storeMask := storeMask
        when(misaligned) {
          io.writeback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAddrMisaligned, addr, cfg)
        }.otherwise {
          io.writeback.valid := false.B
          reqReg             := io.in.bits
          vaddrReg           := addr
          state              := sTranslate
        }
      }.elsewhen(io.in.fire && isAtomic) {
        when(misaligned) {
          io.writeback.valid       := true.B
          io.writeback.bits.robIdx := io.in.bits.robIdx
          io.writeback.bits.exception := ExceptionInfo.raise(
            Mux(isLrOp(io.in.bits), ExceptionCause.loadAddrMisaligned, ExceptionCause.storeAddrMisaligned),
            addr,
            cfg
          )
        }.otherwise {
          reqReg   := io.in.bits
          vaddrReg := addr
          state    := sTranslate
        }
      }
    }.elsewhen(state === sTranslate) {
      when(translator.io.resp.fire) {
        paddrReg := translator.io.resp.bits.paddr
        when(translator.io.resp.bits.exception.valid) {
          io.writeback.valid          := true.B
          io.writeback.bits.robIdx    := reqReg.robIdx
          io.writeback.bits.exception := translator.io.resp.bits.exception
          state                       := sIdle
        }.elsewhen(isLoadOp(reqReg)) {
          state := sLoadReq
        }.elsewhen(isStoreOp(reqReg)) {
          io.writeback.valid          := true.B
          io.writeback.bits.robIdx    := reqReg.robIdx
          io.writeback.bits.result    := 0.U
          io.writeback.bits.storeAddr := translator.io.resp.bits.paddr
          io.writeback.bits.storeData := reqReg.src2.data
          io.writeback.bits.storeMask := reqStoreMask
          state                       := sIdle
        }.elsewhen(isScOp(reqReg)) {
          val scSuccessNow = reservationValid && reservationAddr === translator.io.resp.bits.paddr
          when(scSuccessNow) {
            state := sAmoWriteReq
          }.otherwise {
            io.writeback.valid       := true.B
            io.writeback.bits.robIdx := reqReg.robIdx
            io.writeback.bits.result := 1.U
            io.wakeup.valid          := true.B
            io.wakeup.robIdx         := reqReg.robIdx
            io.wakeup.data           := 1.U
            reservationValid         := false.B
            state                    := sIdle
          }
        }.otherwise {
          state := sAmoReadReq
        }
      }
    }.elsewhen(state === sLoadReq) {
      when(io.dmemReq.fire) {
        state := sLoadResp
      }
    }.elsewhen(state === sLoadResp) {
      when(io.dmemResp.fire) {
        io.writeback.valid       := true.B
        io.writeback.bits.robIdx := reqReg.robIdx
        io.writeback.bits.result := io.dmemResp.bits.data
        io.writeback.bits.storeAddr := paddrReg
        when(io.dmemResp.bits.fault) {
          io.writeback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAccessFault, vaddrReg, cfg)
        }

        io.wakeup.valid  := !io.dmemResp.bits.fault
        io.wakeup.robIdx := reqReg.robIdx
        io.wakeup.data   := io.dmemResp.bits.data

        state := sIdle
      }
    }.elsewhen(state === sAmoReadReq) {
      when(io.dmemReq.fire) {
        state := sAmoReadResp
      }
    }.elsewhen(state === sAmoReadResp) {
      when(io.dmemResp.fire) {
        when(io.dmemResp.bits.fault) {
          io.writeback.valid          := true.B
          io.writeback.bits.robIdx    := reqReg.robIdx
          io.writeback.bits.exception := ExceptionInfo.raise(accessFaultCause(reqReg), vaddrReg, cfg)
          state                       := sIdle
        }.elsewhen(isLrOp(reqReg)) {
          io.writeback.valid       := true.B
          io.writeback.bits.robIdx := reqReg.robIdx
          io.writeback.bits.result := io.dmemResp.bits.data
          io.wakeup.valid          := true.B
          io.wakeup.robIdx         := reqReg.robIdx
          io.wakeup.data           := io.dmemResp.bits.data
          reservationValid         := true.B
          reservationAddr          := paddrReg
          state                    := sIdle
        }.otherwise {
          amoOldReg := io.dmemResp.bits.data
          state     := sAmoWriteReq
        }
      }
    }.elsewhen(state === sAmoWriteReq) {
      when(io.dmemReq.fire) {
        state := sAmoWriteResp
      }
    }.elsewhen(state === sAmoWriteResp) {
      when(io.dmemResp.fire) {
        io.writeback.valid       := true.B
        io.writeback.bits.robIdx := reqReg.robIdx
        io.writeback.bits.result := Mux(isScOp(reqReg), 0.U, amoOldReg)
        when(io.dmemResp.bits.fault) {
          io.writeback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAccessFault, vaddrReg, cfg)
        }

        io.wakeup.valid  := !io.dmemResp.bits.fault
        io.wakeup.robIdx := reqReg.robIdx
        io.wakeup.data   := Mux(isScOp(reqReg), 0.U, amoOldReg)
        reservationValid := false.B
        state            := sIdle
      }
    }
  }
}
