package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Enum, Fill, MuxLookup, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{IssuePacket, IssueWakeup, RobWritebackPacket, StoreForwardQuery, StoreQueueUpdate}
import top.core.backend.csr.{CsrStatus, Mstatus, PrivMode}
import top.core.backend.decoder.{LsuOp, MemSize}
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.bundle.{
  DataMemExternalization,
  DataMemKind,
  DataMemOwner,
  DataMemReq,
  DataMemResp,
  DataMemTxn,
  RobAge,
  RobRecovery
}
import top.core.mmu.{MmuAccessType, MmuTranslateReq, Sv32Translator}

/** Serializes address translation and atomics while allowing translated loads to wait in LoadTxnQueue. Store forwarding
  * is evaluated only after a load has a physical address.
  */
class LSU(cfg: BackendConfig = BackendConfig()) extends Module {
  private val dataBytes = cfg.dataWidth / 8

  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IssuePacket(cfg)))

    val dmemReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val dmemResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val dmemReqRobIdx = Output(UInt(cfg.robIdxWidth.W))

    val storeQuery  = Flipped(new StoreForwardQuery(cfg))
    val storeUpdate = Valid(new StoreQueueUpdate(cfg))

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
    val busy      = Output(Bool())
    val flush     = Input(Bool())
    val recover   = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead   = Input(UInt(cfg.robIdxWidth.W))
    val unresolvedCfi = Input(Vec(cfg.robEntries, Bool()))
    val cancel    = Input(Vec(cfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))
    val csrStatus = Input(new CsrStatus(cfg))

    val loadTxnOccupancy            = Output(UInt(math.max(chisel3.util.log2Ceil(cfg.loadTxnEntries + 1), 1).W))
    val loadTxnFullStall            = Output(Bool())
    val forwardFull                 = Output(Bool())
    val forwardPartial              = Output(Bool())
    val forwardUnresolvedStoreStall = Output(Bool())
  })

  private val sIdle :: sTranslate :: sLoadReq :: sAmoReadReq :: sAmoReadResp :: sAmoWriteReq :: sAmoWriteResp :: Nil =
    Enum(7)
  private val state                                                                                                  = RegInit(sIdle)

  private val reqReg           = Reg(new IssuePacket(cfg))
  private val vaddrReg         = Reg(UInt(cfg.addrWidth.W))
  private val paddrReg         = Reg(UInt(cfg.addrWidth.W))
  private val forwardMaskReg   = Reg(UInt(dataBytes.W))
  private val forwardDataReg   = Reg(UInt(cfg.dataWidth.W))
  private val amoOldReg        = Reg(UInt(cfg.dataWidth.W))
  private val reservationValid = RegInit(false.B)
  private val reservationAddr  = Reg(UInt(cfg.addrWidth.W))

  private val translator = Module(new Sv32Translator(cfg))
  private val loadTxns   = Module(new LoadTxnQueue(cfg))

  private val currentRequestKilled = io.recover.valid && state =/= sIdle &&
    RobAge.isYounger(reqReg.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  private val currentRequestActive = !io.flush && !currentRequestKilled

  private def asAddr(value: UInt): UInt =
    value.pad(cfg.addrWidth)(cfg.addrWidth - 1, 0)

  private def maskFor(size: UInt): UInt =
    MuxLookup(size, 0.U(dataBytes.W))(
      Seq(
        MemSize.byte.U -> 1.U(dataBytes.W),
        MemSize.half.U -> 3.U(dataBytes.W),
        MemSize.word.U -> ((1 << dataBytes) - 1).U(dataBytes.W)
      )
    )

  private def extendLoad(data: UInt, loadSize: UInt, loadUnsigned: Bool): UInt = {
    val byte = data(7, 0)
    val half = data(15, 0)
    MuxLookup(loadSize, data)(
      Seq(
        MemSize.byte.U -> Mux(
          loadUnsigned,
          Cat(0.U((cfg.dataWidth - 8).W), byte),
          Cat(Fill(cfg.dataWidth - 8, byte(7)), byte)
        ),
        MemSize.half.U -> Mux(
          loadUnsigned,
          Cat(0.U((cfg.dataWidth - 16).W), half),
          Cat(Fill(cfg.dataWidth - 16, half(15)), half)
        )
      )
    )
  }

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

  private val inputAddr       = asAddr(io.in.bits.src1.data + io.in.bits.imm)
  private val inputMisaligned = MuxLookup(io.in.bits.memSize, false.B)(
    Seq(
      MemSize.half.U -> inputAddr(0),
      MemSize.word.U -> inputAddr(1, 0).orR
    )
  )
  private val inputStoreMask  = maskFor(io.in.bits.memSize)
  private val reqStoreMask    = maskFor(reqReg.memSize)

  private val inputIsLoad         = isLoadOp(io.in.bits)
  private val inputIsStore        = isStoreOp(io.in.bits)
  private val inputIsAtomic       = io.in.bits.isAmo
  private val inputNeedsTranslate = (inputIsLoad || inputIsStore || inputIsAtomic) && !inputMisaligned
  private val inputOwner          = Wire(new DataMemOwner(cfg.robIdxWidth))
  inputOwner.squashable := true.B
  inputOwner.robIdx     := io.in.bits.robIdx

  // A younger memory operation must not occupy the request FIFO while it is
  // waiting behind an unresolved branch. Otherwise it can hide an older load
  // that is needed to resolve that branch, creating a FIFO head-of-line
  // deadlock. DCache repeats this check at AXI issue as the final safety gate.
  private val inputMayEnterMemoryQueue = !DataMemExternalization.hasOlderUnresolvedCfi(
    inputOwner,
    io.unresolvedCfi,
    io.robHead,
    cfg.robEntries,
    cfg.robIdxWidth
  )
  private val inputNeedsExternalMemory = inputIsLoad || inputIsAtomic
  private val inputMayStartMemory = !inputNeedsExternalMemory || inputMayEnterMemoryQueue
  private val atomicCanStart      = !inputIsAtomic || loadTxns.io.empty
  private val loadCanStart        = !inputIsLoad || loadTxns.io.alloc.ready
  private val canAcceptInput      = state === sIdle && !io.flush && !io.recover.valid &&
    inputMayStartMemory && atomicCanStart && loadCanStart

  io.busy             := state =/= sIdle
  io.loadTxnOccupancy := loadTxns.io.occupancy
  io.loadTxnFullStall := state === sIdle && !io.flush && !io.recover.valid && io.in.valid && inputIsLoad &&
    !loadTxns.io.alloc.ready

  translator.io.flush            := io.flush || currentRequestKilled
  translator.io.req.valid        := canAcceptInput && io.in.valid && inputNeedsTranslate
  translator.io.req.bits         := 0.U.asTypeOf(new MmuTranslateReq(cfg))
  translator.io.req.bits.vaddr   := inputAddr
  translator.io.req.bits.access  := translateAccess(io.in.bits)
  translator.io.req.bits.priv    := effectiveDataPriv
  translator.io.req.bits.mstatus := io.csrStatus.mstatus
  translator.io.req.bits.satp    := io.csrStatus.satp

  io.in.ready := canAcceptInput && Mux(inputNeedsTranslate, translator.io.req.ready, true.B)

  io.storeQuery.valid  := currentRequestActive && state === sTranslate && translator.io.resp.valid &&
    !translator.io.resp.bits.exception.valid && isLoadOp(reqReg)
  io.storeQuery.robIdx := reqReg.robIdx
  io.storeQuery.addr   := translator.io.resp.bits.paddr
  io.storeQuery.mask   := reqStoreMask

  private val translateLoad        = isLoadOp(reqReg)
  private val translateStore       = isStoreOp(reqReg)
  private val translateSc          = isScOp(reqReg)
  private val translateException   = translator.io.resp.bits.exception.valid
  private val scWillFail           = translateSc &&
    !(reservationValid && reservationAddr === translator.io.resp.bits.paddr)
  private val loadNeedsDcache      = translateLoad && !io.storeQuery.fullForward
  private val loadCanComplete      = !io.storeQuery.unresolved &&
    (!loadNeedsDcache || loadTxns.io.alloc.ready)
  private val translateCanComplete = translateException || translateStore || translateSc ||
    (!reqReg.isAmo && translateLoad && loadCanComplete) ||
    (reqReg.isAmo && !translateSc)

  translator.io.resp.ready := state === sTranslate && translateCanComplete && currentRequestActive

  io.forwardFull                 := state === sTranslate && translator.io.resp.fire && translateLoad && io.storeQuery.fullForward
  io.forwardPartial              := state === sTranslate && translator.io.resp.fire && translateLoad && io.storeQuery.partialForward
  io.forwardUnresolvedStoreStall := state === sTranslate && translator.io.resp.valid && translateLoad &&
    io.storeQuery.unresolved && currentRequestActive

  private val normalLoadReq = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  normalLoadReq           := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  normalLoadReq.addr      := paddrReg
  normalLoadReq.write     := false.B
  normalLoadReq.size      := reqReg.memSize
  normalLoadReq.unsigned  := reqReg.memUnsigned
  normalLoadReq.txnId     := loadTxns.io.allocTxnId
  normalLoadReq.cacheable := true.B
  normalLoadReq.kind      := DataMemKind.normal

  private val amoStoreData =
    Mux(isScOp(reqReg), reqReg.src2.data, amoWriteData(amoOldReg, reqReg.src2.data, reqReg.fuOp))

  private val amoReadReq = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoReadReq           := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoReadReq.addr      := paddrReg
  amoReadReq.write     := false.B
  amoReadReq.size      := MemSize.word.U
  amoReadReq.unsigned  := true.B
  amoReadReq.txnId     := DataMemTxn.atomic
  amoReadReq.cacheable := false.B
  amoReadReq.kind      := DataMemKind.atomic

  private val amoWriteReq = Wire(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoWriteReq           := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  amoWriteReq.addr      := paddrReg
  amoWriteReq.write     := true.B
  amoWriteReq.size      := MemSize.word.U
  amoWriteReq.unsigned  := false.B
  amoWriteReq.wdata     := amoStoreData
  amoWriteReq.wmask     := ((1 << dataBytes) - 1).U(dataBytes.W)
  amoWriteReq.txnId     := DataMemTxn.atomic
  amoWriteReq.cacheable := false.B
  amoWriteReq.kind      := DataMemKind.atomic

  private val pteRequestActive      = currentRequestActive && state === sTranslate && translator.io.memReq.valid
  private val loadRequestActive     = currentRequestActive && state === sLoadReq && loadTxns.io.alloc.ready
  private val amoReadRequestActive  = currentRequestActive && state === sAmoReadReq
  private val amoWriteRequestActive = currentRequestActive && state === sAmoWriteReq

  io.dmemReq.valid := pteRequestActive || loadRequestActive || amoReadRequestActive || amoWriteRequestActive
  io.dmemReq.bits  := Mux(
    pteRequestActive,
    translator.io.memReq.bits,
    Mux(loadRequestActive, normalLoadReq, Mux(amoReadRequestActive, amoReadReq, amoWriteReq))
  )
  io.dmemReqRobIdx := reqReg.robIdx

  translator.io.memReq.ready := pteRequestActive && io.dmemReq.ready

  loadTxns.io.alloc.valid            := state === sLoadReq && io.dmemReq.ready
  loadTxns.io.alloc.bits.robIdx      := reqReg.robIdx
  loadTxns.io.alloc.bits.vaddr       := vaddrReg
  loadTxns.io.alloc.bits.paddr       := paddrReg
  loadTxns.io.alloc.bits.size        := reqReg.memSize
  loadTxns.io.alloc.bits.unsigned    := reqReg.memUnsigned
  loadTxns.io.alloc.bits.forwardMask := forwardMaskReg
  loadTxns.io.alloc.bits.forwardData := forwardDataReg

  private val responseIsPtw          = io.dmemResp.bits.txnId === DataMemTxn.ptw
  private val responseIsAtomic       = io.dmemResp.bits.txnId === DataMemTxn.atomic
  private val responseIsLoad         = DataMemTxn.isLoad(io.dmemResp.bits.txnId)
  private val atomicResponseState    = state === sAmoReadResp || state === sAmoWriteResp
  private val atomicDirectWanted     = currentRequestActive && responseIsAtomic && atomicResponseState && io.dmemResp.valid
  private val translateDirectWanted  = currentRequestActive && state === sTranslate && translator.io.resp.valid &&
    (translateException || translateStore || (translateLoad && io.storeQuery.fullForward) || scWillFail)
  private val misalignedDirectWanted = !io.flush && !io.recover.valid && state === sIdle && io.in.valid && io.in.ready && inputMisaligned &&
    (inputIsLoad || inputIsStore || inputIsAtomic)
  private val directResultWanted     = atomicDirectWanted || translateDirectWanted || misalignedDirectWanted

  loadTxns.io.complete.valid := io.dmemResp.valid && responseIsLoad
  loadTxns.io.complete.bits  := io.dmemResp.bits
  loadTxns.io.allowComplete  := !directResultWanted && !io.flush
  loadTxns.io.flush          := io.flush
  loadTxns.io.recover        := io.recover
  loadTxns.io.robHead        := io.robHead
  loadTxns.io.cancel         := io.cancel

  translator.io.memResp.valid := io.dmemResp.valid && responseIsPtw
  translator.io.memResp.bits  := io.dmemResp.bits

  io.dmemResp.ready := Mux(
    io.flush,
    true.B,
    Mux(
      responseIsPtw,
      translator.io.memResp.ready,
      Mux(
        responseIsLoad,
        loadTxns.io.complete.ready,
        Mux(responseIsAtomic, atomicResponseState, true.B)
      )
    )
  )

  private val directWriteback = Wire(Valid(new RobWritebackPacket(cfg)))
  private val directWakeup    = Wire(new IssueWakeup(cfg))
  directWriteback := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
  directWakeup    := 0.U.asTypeOf(new IssueWakeup(cfg))
  io.storeUpdate  := 0.U.asTypeOf(Valid(new StoreQueueUpdate(cfg)))

  when(!io.flush && !io.recover.valid && state === sIdle && io.in.fire && inputMisaligned) {
    directWriteback.valid       := true.B
    directWriteback.bits.robIdx := io.in.bits.robIdx
    when(inputIsLoad || isLrOp(io.in.bits)) {
      directWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAddrMisaligned, inputAddr, cfg)
    }.otherwise {
      directWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAddrMisaligned, inputAddr, cfg)
    }
  }

  when(currentRequestActive && state === sTranslate && translator.io.resp.fire) {
    when(translateException) {
      directWriteback.valid          := true.B
      directWriteback.bits.robIdx    := reqReg.robIdx
      directWriteback.bits.exception := translator.io.resp.bits.exception
    }.elsewhen(translateLoad && io.storeQuery.fullForward) {
      val result = extendLoad(io.storeQuery.forwardData, reqReg.memSize, reqReg.memUnsigned)
      directWriteback.valid          := true.B
      directWriteback.bits.robIdx    := reqReg.robIdx
      directWriteback.bits.result    := result
      directWriteback.bits.storeAddr := translator.io.resp.bits.paddr
      directWakeup.valid             := true.B
      directWakeup.robIdx            := reqReg.robIdx
      directWakeup.data              := result
    }.elsewhen(translateStore) {
      directWriteback.valid          := true.B
      directWriteback.bits.robIdx    := reqReg.robIdx
      directWriteback.bits.storeAddr := translator.io.resp.bits.paddr
      directWriteback.bits.storeData := reqReg.src2.data
      directWriteback.bits.storeMask := reqStoreMask

      io.storeUpdate.valid       := true.B
      io.storeUpdate.bits.valid  := true.B
      io.storeUpdate.bits.robIdx := reqReg.robIdx
      io.storeUpdate.bits.addr   := translator.io.resp.bits.paddr
      io.storeUpdate.bits.data   := reqReg.src2.data
      io.storeUpdate.bits.mask   := reqStoreMask
    }.elsewhen(scWillFail) {
      directWriteback.valid          := true.B
      directWriteback.bits.robIdx    := reqReg.robIdx
      directWriteback.bits.result    := 1.U
      directWriteback.bits.storeAddr := translator.io.resp.bits.paddr
      directWakeup.valid             := true.B
      directWakeup.robIdx            := reqReg.robIdx
      directWakeup.data              := 1.U
    }
  }

  when(currentRequestActive && responseIsAtomic && io.dmemResp.fire && state === sAmoReadResp) {
    when(io.dmemResp.bits.fault) {
      directWriteback.valid          := true.B
      directWriteback.bits.robIdx    := reqReg.robIdx
      directWriteback.bits.storeAddr := paddrReg
      directWriteback.bits.exception := ExceptionInfo.raise(accessFaultCause(reqReg), vaddrReg, cfg)
    }.elsewhen(isLrOp(reqReg)) {
      directWriteback.valid          := true.B
      directWriteback.bits.robIdx    := reqReg.robIdx
      directWriteback.bits.result    := io.dmemResp.bits.data
      directWriteback.bits.storeAddr := paddrReg
      directWakeup.valid             := true.B
      directWakeup.robIdx            := reqReg.robIdx
      directWakeup.data              := io.dmemResp.bits.data
    }
  }

  when(currentRequestActive && responseIsAtomic && io.dmemResp.fire && state === sAmoWriteResp) {
    directWriteback.valid          := true.B
    directWriteback.bits.robIdx    := reqReg.robIdx
    directWriteback.bits.result    := Mux(isScOp(reqReg), 0.U, amoOldReg)
    directWriteback.bits.storeAddr := paddrReg
    directWriteback.bits.storeData := amoStoreData
    directWriteback.bits.storeMask := ((1 << dataBytes) - 1).U(dataBytes.W)
    when(io.dmemResp.bits.fault) {
      directWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAccessFault, vaddrReg, cfg)
    }
    directWakeup.valid             := !io.dmemResp.bits.fault
    directWakeup.robIdx            := reqReg.robIdx
    directWakeup.data              := Mux(isScOp(reqReg), 0.U, amoOldReg)
  }

  io.writeback := Mux(directWriteback.valid, directWriteback, loadTxns.io.writeback)
  io.wakeup    := Mux(directWriteback.valid, directWakeup, loadTxns.io.wakeup)

  when(io.flush || currentRequestKilled) {
    state := sIdle
  }.otherwise {
    when(state === sIdle) {
      when(io.in.fire && inputNeedsTranslate) {
        reqReg   := io.in.bits
        vaddrReg := inputAddr
        state    := sTranslate
      }
    }.elsewhen(state === sTranslate) {
      when(translator.io.resp.fire) {
        paddrReg := translator.io.resp.bits.paddr
        when(translateException || translateStore || (translateLoad && io.storeQuery.fullForward) || scWillFail) {
          when(scWillFail) {
            reservationValid := false.B
          }
          state := sIdle
        }.elsewhen(translateLoad) {
          forwardMaskReg := io.storeQuery.forwardMask
          forwardDataReg := io.storeQuery.forwardData
          state          := sLoadReq
        }.elsewhen(isScOp(reqReg)) {
          state := sAmoWriteReq
        }.otherwise {
          state := sAmoReadReq
        }
      }
    }.elsewhen(state === sLoadReq) {
      when(io.dmemReq.fire) {
        state := sIdle
      }
    }.elsewhen(state === sAmoReadReq) {
      when(io.dmemReq.fire) {
        state := sAmoReadResp
      }
    }.elsewhen(state === sAmoReadResp) {
      when(responseIsAtomic && io.dmemResp.fire) {
        when(io.dmemResp.bits.fault) {
          state := sIdle
        }.elsewhen(isLrOp(reqReg)) {
          reservationValid := true.B
          reservationAddr  := paddrReg
          state            := sIdle
        }.otherwise {
          amoOldReg := io.dmemResp.bits.data
          state     := sAmoWriteReq
        }
      }
    }.elsewhen(state === sAmoWriteReq) {
      when(io.dmemReq.fire) {
        state := sAmoWriteResp
      }
    }.otherwise {
      when(responseIsAtomic && io.dmemResp.fire) {
        reservationValid := false.B
        state            := sIdle
      }
    }
  }
}
