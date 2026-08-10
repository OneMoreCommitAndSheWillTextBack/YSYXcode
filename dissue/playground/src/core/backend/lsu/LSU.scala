package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Enum, Fill, MuxLookup, RegEnable, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{
  IssuePacket,
  IssueWakeup,
  RobWritebackPacket,
  StoreQueueAlloc,
  StoreQueueCommit,
  StoreQueueEvent,
  StoreQueuePerf,
  StoreQueueUpdate,
  StoreResponseEvent,
  StoreTrackerQuery
}
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
  OwnedDataMemReq,
  RobAge,
  RobRecovery
}
import top.core.mem.{MemAddress, RecoverableDmemQueue}
import top.core.mmu.{MmuAccessType, MmuTranslateReq, Sv32Translator}

/** Complete backend load/store transaction owner.
  *
  * Translation remains single-issue, while LTQ and store transaction slots allow accepted requests to live
  * independently. The outbound recoverable FIFO is deliberately inside this module so cancellation and tag reuse are
  * decided by the same owner that routes responses.
  */
class LSU(cfg: BackendConfig = BackendConfig()) extends Module {
  private val dataBytes   = cfg.dataWidth / 8
  private val cancelPorts = cfg.dmemQueueEntries + cfg.recoveryCancelPorts

  require(cfg.loadTxnEntries <= DataMemTxn.slotCount, "LTQ entries exceed the transaction slot encoding")
  require(cfg.storeTxnEntries <= DataMemTxn.slotCount, "store transaction entries exceed the transaction slot encoding")

  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IssuePacket(cfg)))

    val storeAlloc             = Input(Vec(cfg.dispatchWidth, new StoreQueueAlloc(cfg)))
    val storeAllocReady        = Output(Vec(cfg.dispatchWidth, Bool()))
    val storeAllocSqIdx        = Output(Vec(cfg.dispatchWidth, UInt(cfg.sqIdxWidth.W)))
    val storeCommit            = Input(Vec(cfg.commitWidth, new StoreQueueCommit(cfg)))
    val serializedStore        = Input(Valid(new StoreQueueEvent(cfg)))
    val serializedStoreSuccess = Output(Bool())
    val storeIssueQuery        = Vec(cfg.issueQueueEntries, new StoreTrackerQuery(cfg))

    val dmemReq    = Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
    val dmemResp   = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val dmemCancel = Input(Vec(cfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))

    val writeback   = Valid(new RobWritebackPacket(cfg))
    val wakeup      = Output(new IssueWakeup(cfg))
    val busy        = Output(Bool())
    val loadReady   = Output(Bool())
    val storeReady  = Output(Bool())
    val atomicReady = Output(Bool())

    val flush         = Input(Bool())
    val recover       = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead       = Input(UInt(cfg.robIdxWidth.W))
    val unresolvedCfi = Input(Vec(cfg.robEntries, Bool()))
    val csrStatus     = Input(new CsrStatus(cfg))

    val storesDrained             = Output(Bool())
    val storesDrainedBeforeCommit = Output(Bool())
    val memoryIdle                = Output(Bool())
    val storeUpdate               = Output(Valid(new StoreQueueUpdate(cfg)))
    val storeRequest              = Output(Valid(new StoreQueueEvent(cfg)))
    val storeResponse             = Output(Valid(new StoreResponseEvent(cfg)))
    val sqPerf                    = Output(new StoreQueuePerf(cfg))

    val loadTxnOccupancy            = Output(UInt(math.max(chisel3.util.log2Ceil(cfg.loadTxnEntries + 1), 1).W))
    val loadTxnFullStall            = Output(Bool())
    val forwardFull                 = Output(Bool())
    val forwardPartial              = Output(Bool())
    val forwardUnresolvedStoreStall = Output(Bool())
  })

  private val sIdle :: sTranslate :: sLoadReq :: sAmoReadReq :: sAmoReadResp :: sAmoWriteReq :: sAmoWriteResp :: Nil =
    Enum(7)
  private val state                                                                                                  = RegInit(sIdle)

  private val reqReg       = Reg(new IssuePacket(cfg))
  private val vaddrReg     = Reg(UInt(cfg.addrWidth.W))
  private val paddrReg     = Reg(UInt(cfg.addrWidth.W))
  private val loadTxnIdReg = Reg(UInt(DataMemTxn.width.W))
  private val amoOldReg    = Reg(UInt(cfg.dataWidth.W))

  private val reservationValid = RegInit(false.B)
  private val reservationAddr  = Reg(UInt(cfg.addrWidth.W))

  private val translator = Module(new Sv32Translator(cfg))
  private val storeQueue = Module(new StoreQueue(cfg))
  private val loadTxns   = Module(new LoadTxnQueue(cfg))
  private val storeDrain = Module(new StoreDrainEngine(cfg))
  private val outbound   = Module(
    new RecoverableDmemQueue(
      addrWidth = cfg.addrWidth,
      dataWidth = cfg.dataWidth,
      robIdxWidth = cfg.robIdxWidth,
      robEntries = cfg.robEntries,
      depth = cfg.dmemQueueEntries
    )
  )

  private val ptwBusy      = RegInit(false.B)
  private val ptwKilled    = RegInit(false.B)
  private val atomicBusy   = RegInit(false.B)
  private val atomicKilled = RegInit(false.B)

  storeQueue.io.alloc   := io.storeAlloc
  io.storeAllocReady    := storeQueue.io.allocReady
  io.storeAllocSqIdx    := storeQueue.io.allocSqIdx
  storeQueue.io.commit  := io.storeCommit
  storeQueue.io.flush   := io.flush
  storeQueue.io.recover := io.recover
  storeQueue.io.robHead := io.robHead
  storeQueue.io.issueQuery <> io.storeIssueQuery

  storeDrain.io.normal <> storeQueue.io.normalDrain
  storeQueue.io.reserve  := storeDrain.io.reserve
  storeQueue.io.issue    := storeDrain.io.issue
  storeQueue.io.response := storeDrain.io.complete
  io.storeRequest        := storeDrain.io.issue
  io.storeResponse       := storeDrain.io.complete
  io.sqPerf              := storeQueue.io.perf

  private val serializedSuccessPending = RegInit(false.B)
  private val serializedSuccessSqIdx   = RegInit(0.U(cfg.sqIdxWidth.W))
  private val serializedSuccessRobIdx  = RegInit(0.U(cfg.robIdxWidth.W))
  private val serializedSuccessMatch   = io.serializedStore.bits.sqIdx === serializedSuccessSqIdx &&
    io.serializedStore.bits.robIdx === serializedSuccessRobIdx
  storeQueue.io.serializedSelect.valid := io.serializedStore.valid && !serializedSuccessPending
  storeQueue.io.serializedSelect.bits  := io.serializedStore.bits
  storeDrain.io.serialized             := storeQueue.io.serializedRequest
  io.serializedStoreSuccess            := serializedSuccessPending && io.serializedStore.valid && serializedSuccessMatch

  when(storeDrain.io.serializedSuccess) {
    serializedSuccessPending := true.B
    serializedSuccessSqIdx   := storeDrain.io.complete.bits.sqIdx
    serializedSuccessRobIdx  := storeDrain.io.complete.bits.robIdx
  }.elsewhen(io.serializedStoreSuccess) {
    serializedSuccessPending := false.B
  }

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
    Mux(isLoadOp(packet) || isLrOp(packet), ExceptionCause.loadAccessFault, ExceptionCause.storeAccessFault)

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

  private val inputAddr           = asAddr(io.in.bits.src1.data + io.in.bits.imm)
  private val inputMisaligned     = MuxLookup(io.in.bits.memSize, false.B)(
    Seq(
      MemSize.half.U -> inputAddr(0),
      MemSize.word.U -> inputAddr(1, 0).orR
    )
  )
  private val inputIsLoad         = isLoadOp(io.in.bits)
  private val inputIsStore        = isStoreOp(io.in.bits)
  private val inputIsAtomic       = io.in.bits.isAmo
  private val inputNeedsTranslate = (inputIsLoad || inputIsStore || inputIsAtomic) && !inputMisaligned
  private val reqStoreMask        = maskFor(reqReg.memSize)

  private val inputOwner = Wire(new DataMemOwner(cfg.robIdxWidth))
  inputOwner.squashable := true.B
  inputOwner.robIdx     := io.in.bits.robIdx
  private val inputMayEnterMemoryQueue = !DataMemExternalization.hasOlderUnresolvedCfi(
    inputOwner,
    io.unresolvedCfi,
    io.robHead,
    cfg.robEntries,
    cfg.robIdxWidth
  )

  private val storesDrained     = Wire(Bool())
  private val serializedPending =
    io.serializedStore.valid || storeDrain.io.serializedOutstanding || serializedSuccessPending
  private val pipeIdle          = state === sIdle
  private val baseReady         = pipeIdle && !io.flush && !io.recover.valid && !serializedPending

  io.loadReady   := baseReady && loadTxns.io.alloc.ready
  io.storeReady  := baseReady
  io.atomicReady := baseReady && loadTxns.io.empty && storesDrained && !ptwBusy && !atomicBusy

  private val operationReady = Mux(inputIsAtomic, io.atomicReady, Mux(inputIsStore, io.storeReady, io.loadReady))
  private val canAcceptInput = operationReady && inputMayEnterMemoryQueue

  translator.io.flush            := io.flush || currentRequestKilled
  translator.io.req.valid        := canAcceptInput && io.in.valid && inputNeedsTranslate
  translator.io.req.bits         := 0.U.asTypeOf(new MmuTranslateReq(cfg))
  translator.io.req.bits.vaddr   := inputAddr
  translator.io.req.bits.access  := translateAccess(io.in.bits)
  translator.io.req.bits.priv    := effectiveDataPriv
  translator.io.req.bits.mstatus := io.csrStatus.mstatus
  translator.io.req.bits.satp    := io.csrStatus.satp
  io.in.ready                    := canAcceptInput && Mux(inputNeedsTranslate, translator.io.req.ready, true.B)

  storeQueue.io.query.valid  := currentRequestActive && state === sTranslate && translator.io.resp.valid &&
    !translator.io.resp.bits.exception.valid && isLoadOp(reqReg)
  storeQueue.io.query.robIdx := reqReg.robIdx
  storeQueue.io.query.addr   := translator.io.resp.bits.paddr
  storeQueue.io.query.mask   := reqStoreMask

  private val translateLoad           = isLoadOp(reqReg)
  private val translateStore          = isStoreOp(reqReg)
  private val translateSc             = isScOp(reqReg)
  private val translateException      = translator.io.resp.bits.exception.valid
  private val translateDeviceLoad     = translateLoad && !translateException &&
    MemAddress.isDevice(translator.io.resp.bits.paddr, cfg.addrWidth)
  private val scWillFail              = translateSc &&
    !(reservationValid && reservationAddr === translator.io.resp.bits.paddr)
  // Device reads can have side effects. They must neither consume SQ forwarding nor become visible below the LSU until
  // they are the precise ROB-head operation and all older stores have completed.
  private val deviceLoadOrderingReady = reqReg.robIdx === io.robHead && storesDrained && loadTxns.io.empty &&
    !ptwBusy && !atomicBusy && !serializedPending
  private val loadNeedsMemory         = translateLoad && (translateDeviceLoad || !storeQueue.io.query.fullForward)

  loadTxns.io.alloc.valid            := currentRequestActive && state === sTranslate && translator.io.resp.valid &&
    !translateException && translateLoad && !storeQueue.io.query.unresolved && loadNeedsMemory &&
    (!translateDeviceLoad || deviceLoadOrderingReady)
  loadTxns.io.alloc.bits.robIdx      := reqReg.robIdx
  loadTxns.io.alloc.bits.vaddr       := vaddrReg
  loadTxns.io.alloc.bits.paddr       := translator.io.resp.bits.paddr
  loadTxns.io.alloc.bits.size        := reqReg.memSize
  loadTxns.io.alloc.bits.unsigned    := reqReg.memUnsigned
  loadTxns.io.alloc.bits.forwardMask := Mux(translateDeviceLoad, 0.U, storeQueue.io.query.forwardMask)
  loadTxns.io.alloc.bits.forwardData := Mux(translateDeviceLoad, 0.U, storeQueue.io.query.forwardData)

  private val loadCanComplete      = !storeQueue.io.query.unresolved &&
    (!loadNeedsMemory || (loadTxns.io.alloc.ready && (!translateDeviceLoad || deviceLoadOrderingReady)))
  private val translateCanComplete = translateException || translateStore || translateSc ||
    (!reqReg.isAmo && translateLoad && loadCanComplete) || (reqReg.isAmo && !translateSc)
  translator.io.resp.ready := state === sTranslate && translateCanComplete && currentRequestActive

  io.forwardFull                 := state === sTranslate && translator.io.resp.fire && translateLoad &&
    !translateDeviceLoad &&
    storeQueue.io.query.fullForward
  io.forwardPartial              := state === sTranslate && translator.io.resp.fire && translateLoad &&
    !translateDeviceLoad &&
    storeQueue.io.query.partialForward
  io.forwardUnresolvedStoreStall := state === sTranslate && translator.io.resp.valid && translateLoad &&
    storeQueue.io.query.unresolved && currentRequestActive

  private val normalLoadReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  normalLoadReq                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  normalLoadReq.request.addr      := paddrReg
  normalLoadReq.request.write     := false.B
  normalLoadReq.request.size      := reqReg.memSize
  normalLoadReq.request.unsigned  := reqReg.memUnsigned
  normalLoadReq.request.txnId     := loadTxnIdReg
  normalLoadReq.request.cacheable := !MemAddress.isDevice(paddrReg, cfg.addrWidth)
  normalLoadReq.request.kind      := DataMemKind.normal
  normalLoadReq.owner.squashable  := true.B
  normalLoadReq.owner.robIdx      := reqReg.robIdx

  private val amoStoreData =
    Mux(isScOp(reqReg), reqReg.src2.data, amoWriteData(amoOldReg, reqReg.src2.data, reqReg.fuOp))

  private val amoReadReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoReadReq                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoReadReq.request.addr      := paddrReg
  amoReadReq.request.write     := false.B
  amoReadReq.request.size      := MemSize.word.U
  amoReadReq.request.unsigned  := true.B
  amoReadReq.request.txnId     := DataMemTxn.atomicTag
  amoReadReq.request.cacheable := false.B
  amoReadReq.request.kind      := DataMemKind.atomic
  amoReadReq.owner.squashable  := true.B
  amoReadReq.owner.robIdx      := reqReg.robIdx

  private val amoWriteReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoWriteReq                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoWriteReq.request.addr      := paddrReg
  amoWriteReq.request.write     := true.B
  amoWriteReq.request.size      := MemSize.word.U
  amoWriteReq.request.unsigned  := false.B
  amoWriteReq.request.wdata     := amoStoreData
  amoWriteReq.request.wmask     := ((1 << dataBytes) - 1).U(dataBytes.W)
  amoWriteReq.request.txnId     := DataMemTxn.atomicTag
  amoWriteReq.request.cacheable := false.B
  amoWriteReq.request.kind      := DataMemKind.atomic
  amoWriteReq.owner.squashable  := true.B
  amoWriteReq.owner.robIdx      := reqReg.robIdx

  private val pteOwnedReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  pteOwnedReq                  := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  pteOwnedReq.request          := translator.io.memReq.bits
  pteOwnedReq.owner.squashable := true.B
  pteOwnedReq.owner.robIdx     := reqReg.robIdx

  private val atomicCandidate      = currentRequestActive && !atomicBusy &&
    (state === sAmoReadReq || state === sAmoWriteReq)
  private val ptwCandidate         = currentRequestActive && state === sTranslate && translator.io.memReq.valid && !ptwBusy
  private val loadCandidate        = currentRequestActive && state === sLoadReq
  private val serializedCandidate  = storeDrain.io.request.valid && !storeDrain.io.request.bits.request.cacheable
  private val normalStoreCandidate = storeDrain.io.request.valid && storeDrain.io.request.bits.request.cacheable

  private val arbNone :: arbAtomic :: arbPtw :: arbSerialized :: arbLoad :: arbStore :: Nil = Enum(6)
  private val preferStore                                                                   = RegInit(false.B)
  private val fairSource                                                                    = Mux(
    loadCandidate && normalStoreCandidate,
    Mux(preferStore, arbStore, arbLoad),
    Mux(loadCandidate, arbLoad, Mux(normalStoreCandidate, arbStore, arbNone))
  )
  private val prioritySource                                                                = Mux(
    atomicCandidate,
    arbAtomic,
    Mux(ptwCandidate, arbPtw, Mux(serializedCandidate, arbSerialized, fairSource))
  )
  private val arbLocked                                                                     = RegInit(false.B)
  private val arbSource                                                                     = RegInit(arbNone)
  private val selectedSource                                                                = Mux(arbLocked, arbSource, prioritySource)

  private def sourceValid(source: UInt): Bool =
    MuxLookup(source, false.B)(
      Seq(
        arbAtomic     -> atomicCandidate,
        arbPtw        -> ptwCandidate,
        arbSerialized -> serializedCandidate,
        arbLoad       -> loadCandidate,
        arbStore      -> normalStoreCandidate
      )
    )

  private val selectedValid = sourceValid(selectedSource)
  private val selectedBits  = MuxLookup(selectedSource, normalLoadReq)(
    Seq(
      arbAtomic     -> Mux(state === sAmoReadReq, amoReadReq, amoWriteReq),
      arbPtw        -> pteOwnedReq,
      arbSerialized -> storeDrain.io.request.bits,
      arbLoad       -> normalLoadReq,
      arbStore      -> storeDrain.io.request.bits
    )
  )

  outbound.io.enq.valid       := selectedValid
  outbound.io.enq.bits        := selectedBits
  translator.io.memReq.ready  := selectedSource === arbPtw && selectedValid && outbound.io.enq.ready
  storeDrain.io.request.ready :=
    (selectedSource === arbSerialized || selectedSource === arbStore) && selectedValid && outbound.io.enq.ready

  private val rawRequestFire = outbound.io.enq.fire
  private val rawAtomicFire  = rawRequestFire && selectedSource === arbAtomic
  private val rawPtwFire     = rawRequestFire && selectedSource === arbPtw
  private val rawLoadFire    = rawRequestFire && selectedSource === arbLoad
  private val rawStoreFire   = rawRequestFire && selectedSource === arbStore

  when(arbLocked && !selectedValid) {
    arbLocked := false.B
    arbSource := arbNone
  }.elsewhen(rawRequestFire) {
    arbLocked := false.B
    arbSource := arbNone
  }.elsewhen(selectedValid && !outbound.io.enq.ready) {
    arbLocked := true.B
    arbSource := selectedSource
  }
  when(rawLoadFire) {
    preferStore := true.B
  }.elsewhen(rawStoreFire) {
    preferStore := false.B
  }

  loadTxns.io.markIssued.valid := rawLoadFire
  loadTxns.io.markIssued.bits  := loadTxnIdReg
  loadTxns.io.abort.valid      := state === sLoadReq && (io.flush || currentRequestKilled)
  loadTxns.io.abort.bits       := loadTxnIdReg

  outbound.io.flush   := io.flush
  outbound.io.recover := io.recover
  outbound.io.robHead := io.robHead
  io.dmemReq <> outbound.io.deq

  storeDrain.io.externalFire.valid := io.dmemReq.fire && DataMemTxn.isStore(io.dmemReq.bits.request.txnId)
  storeDrain.io.externalFire.bits  := io.dmemReq.bits.request.txnId

  private val allCancel = Wire(Vec(cancelPorts, Valid(UInt(DataMemTxn.width.W))))
  for (port <- 0 until cfg.dmemQueueEntries) {
    allCancel(port) := outbound.io.cancel(port)
  }
  for (port <- 0 until cfg.recoveryCancelPorts) {
    allCancel(cfg.dmemQueueEntries + port) := io.dmemCancel(port)
  }
  loadTxns.io.cancel := allCancel

  private val cancelPtw    = allCancel.map(cancel => cancel.valid && cancel.bits === DataMemTxn.ptwTag).reduce(_ || _)
  private val cancelAtomic =
    allCancel.map(cancel => cancel.valid && cancel.bits === DataMemTxn.atomicTag).reduce(_ || _)

  private val responseIsLoad   = DataMemTxn.isLoad(io.dmemResp.bits.txnId)
  private val responseIsStore  = DataMemTxn.isStore(io.dmemResp.bits.txnId)
  private val responseIsPtw    = DataMemTxn.isPtw(io.dmemResp.bits.txnId)
  private val responseIsAtomic = DataMemTxn.isAtomic(io.dmemResp.bits.txnId)

  loadTxns.io.complete.valid := io.dmemResp.valid && responseIsLoad
  loadTxns.io.complete.bits  := io.dmemResp.bits
  loadTxns.io.flush          := io.flush
  loadTxns.io.recover        := io.recover
  loadTxns.io.robHead        := io.robHead

  storeDrain.io.response.valid      := io.dmemResp.valid && responseIsStore
  storeDrain.io.response.bits       := io.dmemResp.bits
  // A serialized store may coexist only with a held younger device-load translation and an empty LTQ, so its precise
  // fault still owns the LSU writeback port.
  storeDrain.io.allowFaultWriteback := true.B

  private val ptwResponseMatch = ptwBusy && io.dmemResp.bits.txnId === DataMemTxn.ptwTag
  private val ptwResponseStale = ptwKilled || io.flush || currentRequestKilled
  translator.io.memResp.valid := io.dmemResp.valid && responseIsPtw && ptwResponseMatch && !ptwResponseStale
  translator.io.memResp.bits  := io.dmemResp.bits
  private val ptwResponseReady = !ptwResponseMatch || ptwResponseStale || translator.io.memResp.ready

  private val atomicResponseState = state === sAmoReadResp || state === sAmoWriteResp
  private val atomicResponseMatch = atomicBusy && io.dmemResp.bits.txnId === DataMemTxn.atomicTag
  private val atomicResponseStale = atomicKilled || io.flush || currentRequestKilled
  private val atomicResponseReady = !atomicResponseMatch || atomicResponseStale || atomicResponseState

  io.dmemResp.ready := MuxLookup(
    DataMemTxn.txnClass(io.dmemResp.bits.txnId),
    true.B
  )(
    Seq(
      0.U -> loadTxns.io.complete.ready,
      1.U -> storeDrain.io.response.ready,
      2.U -> ptwResponseReady,
      3.U -> atomicResponseReady
    )
  )

  private val ptwResponseFire            = io.dmemResp.fire && responseIsPtw && ptwResponseMatch
  private val atomicResponseFire         = io.dmemResp.fire && responseIsAtomic && atomicResponseMatch
  private val activeAtomicResponse       = atomicResponseFire && !atomicResponseStale && atomicResponseState
  private val activeAtomicResponseWanted = io.dmemResp.valid && responseIsAtomic && atomicResponseMatch &&
    !atomicResponseStale && atomicResponseState

  when(rawPtwFire) {
    ptwBusy   := true.B
    ptwKilled := false.B
  }
  when(rawAtomicFire) {
    atomicBusy   := true.B
    atomicKilled := false.B
  }
  when((io.flush || currentRequestKilled) && ptwBusy) {
    ptwKilled := true.B
  }
  when((io.flush || currentRequestKilled) && atomicBusy) {
    atomicKilled := true.B
  }
  when(cancelPtw || ptwResponseFire) {
    ptwBusy   := false.B
    ptwKilled := false.B
  }
  when(cancelAtomic || atomicResponseFire) {
    atomicBusy   := false.B
    atomicKilled := false.B
  }

  private val pipeWriteback = Wire(Valid(new RobWritebackPacket(cfg)))
  private val pipeWakeup    = Wire(new IssueWakeup(cfg))
  private val storeUpdate   = Wire(Valid(new StoreQueueUpdate(cfg)))
  pipeWriteback := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
  pipeWakeup    := 0.U.asTypeOf(new IssueWakeup(cfg))
  storeUpdate   := 0.U.asTypeOf(Valid(new StoreQueueUpdate(cfg)))

  when(!io.flush && !io.recover.valid && state === sIdle && io.in.fire && inputMisaligned) {
    pipeWriteback.valid       := true.B
    pipeWriteback.bits.robIdx := io.in.bits.robIdx
    when(inputIsLoad || isLrOp(io.in.bits)) {
      pipeWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAddrMisaligned, inputAddr, cfg)
    }.otherwise {
      pipeWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAddrMisaligned, inputAddr, cfg)
    }
  }

  when(currentRequestActive && state === sTranslate && translator.io.resp.fire) {
    when(translateException) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := reqReg.robIdx
      pipeWriteback.bits.exception := translator.io.resp.bits.exception
    }.elsewhen(translateLoad && !translateDeviceLoad && storeQueue.io.query.fullForward) {
      val result = extendLoad(storeQueue.io.query.forwardData, reqReg.memSize, reqReg.memUnsigned)
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := reqReg.robIdx
      pipeWriteback.bits.result    := result
      pipeWriteback.bits.storeAddr := translator.io.resp.bits.paddr
      pipeWakeup.valid             := true.B
      pipeWakeup.robIdx            := reqReg.robIdx
      pipeWakeup.data              := result
    }.elsewhen(translateStore) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := reqReg.robIdx
      pipeWriteback.bits.storeAddr := translator.io.resp.bits.paddr
      pipeWriteback.bits.storeData := reqReg.src2.data
      pipeWriteback.bits.storeMask := reqStoreMask

      storeUpdate.valid       := true.B
      storeUpdate.bits.sqIdx  := reqReg.sqIdx
      storeUpdate.bits.robIdx := reqReg.robIdx
      storeUpdate.bits.vaddr  := vaddrReg
      storeUpdate.bits.addr   := translator.io.resp.bits.paddr
      storeUpdate.bits.data   := reqReg.src2.data
      storeUpdate.bits.mask   := reqStoreMask
      storeUpdate.bits.size   := reqReg.memSize
      storeUpdate.bits.mmio   := MemAddress.isDevice(translator.io.resp.bits.paddr, cfg.addrWidth)
    }.elsewhen(scWillFail) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := reqReg.robIdx
      pipeWriteback.bits.result    := 1.U
      pipeWriteback.bits.storeAddr := translator.io.resp.bits.paddr
      pipeWakeup.valid             := true.B
      pipeWakeup.robIdx            := reqReg.robIdx
      pipeWakeup.data              := 1.U
    }
  }

  when(activeAtomicResponseWanted && state === sAmoReadResp) {
    when(io.dmemResp.bits.fault) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := reqReg.robIdx
      pipeWriteback.bits.storeAddr := paddrReg
      pipeWriteback.bits.exception := ExceptionInfo.raise(accessFaultCause(reqReg), vaddrReg, cfg)
    }.elsewhen(isLrOp(reqReg)) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := reqReg.robIdx
      pipeWriteback.bits.result    := io.dmemResp.bits.data
      pipeWriteback.bits.storeAddr := paddrReg
      pipeWakeup.valid             := true.B
      pipeWakeup.robIdx            := reqReg.robIdx
      pipeWakeup.data              := io.dmemResp.bits.data
    }
  }

  when(activeAtomicResponseWanted && state === sAmoWriteResp) {
    pipeWriteback.valid          := true.B
    pipeWriteback.bits.robIdx    := reqReg.robIdx
    pipeWriteback.bits.result    := Mux(isScOp(reqReg), 0.U, amoOldReg)
    pipeWriteback.bits.storeAddr := paddrReg
    pipeWriteback.bits.storeData := amoStoreData
    pipeWriteback.bits.storeMask := ((1 << dataBytes) - 1).U(dataBytes.W)
    when(io.dmemResp.bits.fault) {
      pipeWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAccessFault, vaddrReg, cfg)
    }
    pipeWakeup.valid             := !io.dmemResp.bits.fault
    pipeWakeup.robIdx            := reqReg.robIdx
    pipeWakeup.data              := Mux(isScOp(reqReg), 0.U, amoOldReg)
  }

  loadTxns.io.allowComplete := !pipeWriteback.valid

  private val serializedFaultWriteback = Wire(Valid(new RobWritebackPacket(cfg)))
  serializedFaultWriteback                := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
  serializedFaultWriteback.valid          := storeDrain.io.serializedFault.valid
  serializedFaultWriteback.bits.robIdx    := storeDrain.io.serializedFault.bits.robIdx
  serializedFaultWriteback.bits.storeAddr := storeDrain.io.serializedFault.bits.addr
  serializedFaultWriteback.bits.exception := ExceptionInfo.raise(
    ExceptionCause.storeAccessFault,
    storeDrain.io.serializedFault.bits.vaddr,
    cfg
  )

  private val directWriteback = Mux(pipeWriteback.valid, pipeWriteback, serializedFaultWriteback)
  private val directWakeup    = Mux(pipeWriteback.valid, pipeWakeup, 0.U.asTypeOf(new IssueWakeup(cfg)))
  io.writeback := Mux(directWriteback.valid, directWriteback, loadTxns.io.writeback)
  io.wakeup    := Mux(directWriteback.valid, directWakeup, loadTxns.io.wakeup)

  storeQueue.io.update := storeUpdate
  io.storeUpdate       := storeUpdate

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
        when(
          translateException || translateStore ||
            (translateLoad && !translateDeviceLoad && storeQueue.io.query.fullForward) || scWillFail
        ) {
          state := sIdle
        }.elsewhen(translateLoad) {
          loadTxnIdReg := loadTxns.io.allocTxnId
          state        := sLoadReq
        }.elsewhen(isScOp(reqReg)) {
          state := sAmoWriteReq
        }.otherwise {
          state := sAmoReadReq
        }
      }
    }.elsewhen(state === sLoadReq) {
      when(rawLoadFire) {
        state := sIdle
      }
    }.elsewhen(state === sAmoReadReq) {
      when(rawAtomicFire) {
        state := sAmoReadResp
      }
    }.elsewhen(state === sAmoReadResp) {
      when(activeAtomicResponse) {
        when(io.dmemResp.bits.fault || isLrOp(reqReg)) {
          state := sIdle
        }.otherwise {
          amoOldReg := io.dmemResp.bits.data
          state     := sAmoWriteReq
        }
      }
    }.elsewhen(state === sAmoWriteReq) {
      when(rawAtomicFire) {
        state := sAmoWriteResp
      }
    }.otherwise {
      when(activeAtomicResponse) {
        state := sIdle
      }
    }
  }

  when(activeAtomicResponse && state === sAmoReadResp && !io.dmemResp.bits.fault && isLrOp(reqReg)) {
    reservationValid := true.B
    reservationAddr  := paddrReg
  }
  private val committedStore = io.storeCommit.map(_.valid).reduce(_ || _)
  when(
    io.flush || committedStore || storeDrain.io.serializedSuccess ||
      (translator.io.resp.fire && scWillFail) || (rawAtomicFire && state === sAmoWriteReq)
  ) {
    reservationValid := false.B
  }

  storesDrained                := !storeQueue.io.committedPending && !storeDrain.io.normalOutstanding
  io.storesDrainedBeforeCommit := storesDrained
  io.storesDrained             := storesDrained && !committedStore
  private val youngerDeviceLoadHoldingTranslation = currentRequestActive && state === sTranslate &&
    translator.io.resp.valid && translateDeviceLoad && reqReg.robIdx =/= io.robHead
  storeDrain.io.serializedCanStart := io.serializedStore.valid &&
    (state === sIdle || youngerDeviceLoadHoldingTranslation) && loadTxns.io.empty && storesDrained && !ptwBusy &&
    !atomicBusy

  io.memoryIdle       := state === sIdle && loadTxns.io.empty && storeDrain.io.idle && outbound.io.empty &&
    !ptwBusy && !atomicBusy && !arbLocked && !serializedPending
  io.busy             := state =/= sIdle || serializedPending
  io.loadTxnOccupancy := loadTxns.io.occupancy
  io.loadTxnFullStall := state === sIdle && !io.flush && !io.recover.valid && io.in.valid && inputIsLoad &&
    !loadTxns.io.alloc.ready

  when(io.in.fire && inputIsAtomic) {
    assert(io.in.bits.robIdx === io.robHead, "atomic operations must start at the ROB head")
    assert(loadTxns.io.empty && storesDrained, "atomic operations require drained older memory state")
  }
  when(loadTxns.io.alloc.fire && translateDeviceLoad) {
    assert(reqReg.robIdx === io.robHead, "device loads may allocate a transaction only at the ROB head")
    assert(storesDrained && loadTxns.io.empty, "device loads require drained older stores and loads")
    assert(loadTxns.io.alloc.bits.forwardMask === 0.U, "device loads must not consume store-queue forwarding")
  }
  when(rawLoadFire && MemAddress.isDevice(normalLoadReq.request.addr, cfg.addrWidth)) {
    assert(reqReg.robIdx === io.robHead, "device loads may externalize only at the ROB head")
    assert(storesDrained && !normalLoadReq.request.cacheable, "device loads must use the drained uncached path")
  }
  when(io.dmemResp.fire && responseIsPtw) {
    assert(ptwResponseMatch, "PTW response must match a live or killed transaction")
  }
  when(io.dmemResp.fire && responseIsAtomic) {
    assert(atomicResponseMatch, "atomic response must match a live or killed transaction")
  }
  when(outbound.io.enq.fire && DataMemTxn.isStore(outbound.io.enq.bits.request.txnId)) {
    assert(!outbound.io.enq.bits.owner.squashable, "committed store requests must be irreversible")
  }
  when(serializedSuccessPending && io.serializedStore.valid) {
    assert(serializedSuccessMatch, "serialized store completion must match the waiting ROB-head store")
  }

  private val stalledExternalRequest  = RegNext(io.dmemReq.valid && !io.dmemReq.ready, false.B)
  private val stalledExternalBits     = RegEnable(io.dmemReq.bits.asUInt, io.dmemReq.valid && !io.dmemReq.ready)
  private val stalledExternalTxnId    =
    RegEnable(io.dmemReq.bits.request.txnId, io.dmemReq.valid && !io.dmemReq.ready)
  private val stalledExternalCanceled = outbound.io.cancel
    .map(cancel => cancel.valid && cancel.bits === stalledExternalTxnId)
    .reduce(_ || _)
  when(stalledExternalRequest) {
    assert(
      (io.dmemReq.valid && io.dmemReq.bits.asUInt === stalledExternalBits) || stalledExternalCanceled,
      "outbound dmem request changed while stalled without cancellation"
    )
  }
  when(io.storesDrained) {
    assert(!storeQueue.io.committedPending && !storeDrain.io.normalOutstanding)
  }
}
