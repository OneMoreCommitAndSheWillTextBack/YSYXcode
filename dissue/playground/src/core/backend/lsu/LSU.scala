package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Enum, Fill, MuxLookup, OHToUInt, PriorityEncoderOH, RegEnable, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{
  IssuePacket,
  IssueWakeup,
  RobWritebackPacket,
  StoreQueueAlloc,
  StoreQueueCommit,
  StoreQueueEvent,
  StoreQueueUpdate,
  StoreResponseEvent,
  StoreTrackerQuery,
  TlbSfence
}
import top.core.monitor.StoreQueueMonitor
import top.core.backend.csr.{CsrStatus, Mstatus, PrivMode}
import top.core.backend.decoder.{LsuOp, MemSize}
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.bundle.{DataMemKind, DataMemReq, DataMemResp, DataMemTxn, OwnedDataMemReq, RobAge, RobRecovery}
import top.core.mem.{MemAddress, RecoverableDmemQueue}
import top.core.mmu.{MmuAccessType, MmuTranslateReq, MmuTranslateResp}

/** One S3-dispatched memory request waiting for the S4 outbound stage. */
class LsuS4Entry(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val packet    = new IssuePacket(cfg)
  val vaddr     = UInt(cfg.addrWidth.W)
  val paddr     = UInt(cfg.addrWidth.W)
  val loadTxnId = UInt(DataMemTxn.width.W)
}

/** Complete backend load/store transaction owner.
  *
  * P3 pipeline: S0 accept/AGU/CSR snapshot -> TranslationQueue -> S2 non-blocking DTLB -> TranslationReplayQueue -> S3
  * dispatch -> S4 outbound/atomic -> WB.
  *
  * TQ lookups and S3 dispatch are fully decoupled. A DTLB miss is answered with `deferred`, enters the DTLB miss queue,
  * and its completion is matched by `translationId` in the replay queue while younger lookups keep flowing. S3 picks
  * the oldest *dispatchable* translated replay entry; a load is not dispatchable while any older store is still
  * untranslated, which preserves store-to-load ordering without forcing program-order completion.
  */
class LSU(cfg: BackendConfig = BackendConfig(), enableMonitor: Boolean = false) extends Module {
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

    val dmemReq    = Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
    val dmemResp   = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))
    val dmemCancel = Input(Vec(cfg.recoveryCancelPorts, Valid(UInt(DataMemTxn.width.W))))

    val writeback   = Valid(new RobWritebackPacket(cfg))
    val wakeup      = Output(new IssueWakeup(cfg))
    val busy        = Output(Bool())
    val loadReady   = Output(Bool())
    val storeReady  = Output(Bool())
    val atomicReady = Output(Bool())

    val flush     = Input(Bool())
    val recover   = Input(new RobRecovery(cfg.robIdxWidth))
    val robHead   = Input(UInt(cfg.robIdxWidth.W))
    val csrStatus = Input(new CsrStatus(cfg))
    val sfence    = Input(Valid(new TlbSfence(cfg)))

    val storesDrained             = Output(Bool())
    val storesDrainedBeforeCommit = Output(Bool())
    val memoryIdle                = Output(Bool())
    val storeUpdate               = Output(Valid(new StoreQueueUpdate(cfg)))
    val storeRequest              = Output(Valid(new StoreQueueEvent(cfg)))
    val storeResponse             = Output(Valid(new StoreResponseEvent(cfg)))
    val monitor                   = Output(new StoreQueueMonitor(cfg))

    val loadTxnOccupancy            = Output(UInt(math.max(chisel3.util.log2Ceil(cfg.loadTxnEntries + 1), 1).W))
    val loadTxnFullStall            = Output(Bool())
    val forwardFull                 = Output(Bool())
    val forwardPartial              = Output(Bool())
    val forwardUnresolvedStoreStall = Output(Bool())
  })

  private val mIdle :: mLoadReq :: mAmoReadReq :: mAmoReadResp :: mAmoWriteReq :: mAmoWriteResp :: Nil =
    Enum(6)
  private val mState                                                                                   = RegInit(mIdle)

  // S3 dispatch register: filled from a translated replay entry.
  private val tReq   = Reg(new IssuePacket(cfg))
  private val tVaddr = Reg(UInt(cfg.addrWidth.W))
  private val tResp  = Reg(new MmuTranslateResp(cfg))
  private val tValid = RegInit(false.B)

  // S2 lookup state. Only one lookup is in flight, but it is issued every cycle
  // by accepting the response in the same cycle the next request fires.
  private val nextTranslationId = RegInit(0.U(cfg.translationIdWidth.W))
  private val lupPending        = RegInit(false.B)
  private val lupReq            = Reg(new TranslationRequest(cfg))
  private val hitFastPath       = WireDefault(false.B)

  // S3 -> S4 queue.
  private val s4Bits  = Reg(new LsuS4Entry(cfg))
  private val s4Valid = RegInit(false.B)

  // S4 memory/atomic state.
  private val mReq       = Reg(new IssuePacket(cfg))
  private val mVaddr     = Reg(UInt(cfg.addrWidth.W))
  private val mPaddr     = Reg(UInt(cfg.addrWidth.W))
  private val mLoadTxnId = Reg(UInt(DataMemTxn.width.W))
  private val mAmoOld    = Reg(UInt(cfg.dataWidth.W))

  private val reservationValid = RegInit(false.B)
  private val reservationAddr  = Reg(UInt(cfg.addrWidth.W))

  private val tq         = Module(new TranslationQueue(cfg))
  private val mmu        = Module(new LsuMmu(cfg, enableMonitor))
  private val replay     = Module(new TranslationReplayQueue(cfg))
  private val storeQueue = Module(new StoreQueue(cfg, enableMonitor))
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

  storeDrain.io.normal <> storeQueue.io.normalDrain
  storeQueue.io.reserve  := storeDrain.io.reserve
  storeQueue.io.issue    := storeDrain.io.issue
  storeQueue.io.response := storeDrain.io.complete
  io.storeRequest        := storeDrain.io.issue
  io.storeResponse       := storeDrain.io.complete
  io.monitor             := storeQueue.io.monitor

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

  private def isLoadOp(packet:  IssuePacket): Bool = packet.fuOp === LsuOp.load
  private def isStoreOp(packet: IssuePacket): Bool = packet.fuOp === LsuOp.store
  private def isLrOp(packet:    IssuePacket): Bool = packet.fuOp === LsuOp.lr
  private def isScOp(packet:    IssuePacket): Bool = packet.fuOp === LsuOp.sc
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

  // ------------------------------------------------------------------ S0

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

  private val storesDrained      = Wire(Bool())
  // `serializedPending` blocks younger memory operations and holds memoryIdle
  // low; it deliberately includes the head store itself. The drain engine,
  // however, must start for that very store, so its start condition only
  // excludes an *already in-flight* serialized store.
  private val serializedInFlight = storeDrain.io.serializedOutstanding || serializedSuccessPending
  private val serializedPending  =
    io.serializedStore.valid || serializedInFlight

  private def deviceLoadOrderingReadyFor(robIdx: UInt): Bool =
    robIdx === io.robHead && storesDrained && loadTxns.io.empty &&
      !ptwBusy && !atomicBusy && !serializedPending

  private val baseS0 = !io.flush && !io.recover.valid && !serializedPending

  tq.io.enq.valid              := io.in.valid && inputNeedsTranslate
  tq.io.enq.bits.packet        := io.in.bits
  tq.io.enq.bits.vaddr         := inputAddr
  tq.io.enq.bits.access        := translateAccess(io.in.bits)
  tq.io.enq.bits.priv          := effectiveDataPriv
  tq.io.enq.bits.mstatus       := io.csrStatus.mstatus
  tq.io.enq.bits.satp          := io.csrStatus.satp
  tq.io.enq.bits.translationId := nextTranslationId
  when(tq.io.enq.fire) {
    nextTranslationId := nextTranslationId + 1.U
  }
  tq.io.flush                  := io.flush
  tq.io.recover                := io.recover
  tq.io.robHead                := io.robHead

  io.in.ready := baseS0 && (inputMisaligned || tq.io.enq.ready)

  io.loadReady   := baseS0 && tq.io.enq.ready
  io.storeReady  := baseS0 && tq.io.enq.ready
  io.atomicReady := baseS0 && tq.io.empty && tq.io.enq.ready && replay.io.empty && !lupPending && !tValid &&
    loadTxns.io.empty && storesDrained && !ptwBusy && !atomicBusy && mState === mIdle && !s4Valid

  // S0 handles misalignment without entering the queue.
  private val frontendWriteback = Wire(Valid(new RobWritebackPacket(cfg)))
  frontendWriteback             := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
  frontendWriteback.valid       := !io.flush && !io.recover.valid && io.in.fire && inputMisaligned
  frontendWriteback.bits.robIdx := io.in.bits.robIdx
  when(inputIsLoad || isLrOp(io.in.bits)) {
    frontendWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.loadAddrMisaligned, inputAddr, cfg)
  }.otherwise {
    frontendWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAddrMisaligned, inputAddr, cfg)
  }

  // ------------------------------------------------------------- S2 / replay

  mmu.io.flush   := io.flush
  mmu.io.recover := io.recover
  mmu.io.robHead := io.robHead
  mmu.io.sfence  := io.sfence

  // A lookup reserves a replay slot up front so a deferred response always has
  // a home. The TQ head is popped when the lookup is accepted.
  private val lupCanIssue = tq.io.headValid && replay.io.reserveReady && (!lupPending || mmu.io.resp.fire) &&
    !io.flush && !io.recover.valid

  mmu.io.req.valid        := lupCanIssue
  mmu.io.req.bits         := 0.U.asTypeOf(new MmuTranslateReq(cfg))
  mmu.io.req.bits.vaddr   := tq.io.head.vaddr
  mmu.io.req.bits.access  := tq.io.head.access
  mmu.io.req.bits.priv    := tq.io.head.priv
  mmu.io.req.bits.mstatus := tq.io.head.mstatus
  mmu.io.req.bits.satp    := tq.io.head.satp
  mmu.io.req.bits.id      := tq.io.head.translationId
  mmu.io.req.bits.robIdx  := tq.io.head.packet.robIdx

  tq.io.pop               := mmu.io.req.fire
  replay.io.reserve.valid := mmu.io.req.fire
  replay.io.reserve.bits  := tq.io.head
  when(mmu.io.req.fire) {
    lupReq := tq.io.head
  }

  mmu.io.resp.ready := lupPending && !io.flush

  when(io.flush) {
    lupPending := false.B
  }.elsewhen(mmu.io.resp.fire) {
    lupPending := mmu.io.req.fire
  }.elsewhen(mmu.io.req.fire) {
    lupPending := true.B
  }

  replay.io.park.valid    := mmu.io.resp.fire && mmu.io.resp.bits.deferred
  replay.io.park.bits     := mmu.io.resp.bits.id
  replay.io.resolve.valid := mmu.io.resp.fire && !mmu.io.resp.bits.deferred && !hitFastPath
  replay.io.resolve.bits  := mmu.io.resp.bits
  replay.io.release.valid := hitFastPath
  replay.io.release.bits  := mmu.io.resp.bits.id
  replay.io.complete      := mmu.io.complete
  replay.io.recover       := io.recover
  replay.io.robHead       := io.robHead
  replay.io.flush         := io.flush

  // ------------------------------------------------------------- S3 dispatch

  private val replayView = replay.io.view

  private val translateKilled = io.recover.valid && tValid &&
    RobAge.isYounger(tReq.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

  // Resource checks shared by eligibility and completion.
  private val s4RecoverKill = io.recover.valid && s4Valid &&
    RobAge.isYounger(s4Bits.packet.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  private val s4DeqFire     = s4Valid && mState === mIdle && !s4RecoverKill
  private val s4EnqReady    = !s4Valid || s4DeqFire || s4RecoverKill

  // Shared by replay dispatch and the hit fast path. A request may only enter
  // S3 when its ordering and downstream resources are already satisfied, so
  // S3 never stalls behind a younger request waiting for an older one.
  private def dispatchable(packet: IssuePacket, paddr: UInt, exception: Bool, olderStore: Bool): Bool = {
    val isLoad          = isLoadOp(packet)
    val isSc            = isScOp(packet)
    val scFail          = isSc && !(reservationValid && reservationAddr === paddr)
    val isDevice        = isLoad && !exception && MemAddress.isDevice(paddr, cfg.addrWidth)
    val loadResources   = !olderStore && !serializedPending &&
      loadTxns.io.alloc.ready && s4EnqReady &&
      (!isDevice || deviceLoadOrderingReadyFor(packet.robIdx))
    val atomicResources = packet.robIdx === io.robHead && tq.io.empty && loadTxns.io.empty && storesDrained &&
      !ptwBusy && !atomicBusy && !serializedPending && mState === mIdle && !s4Valid
    Mux(
      packet.isAmo,
      Mux(scFail, true.B, atomicResources),
      Mux(isLoad, Mux(exception, true.B, loadResources), true.B)
    )
  }

  for (entry <- 0 until cfg.translationReplayEntries) {
    val view            = replayView(entry)
    val packet          = view.req.packet
    val exception       = view.resp.exception.valid
    val olderStore      = storeQueue.io.replayQuery(entry).hasOlderStore
    val killedByRecover = io.recover.valid &&
      RobAge.isYounger(packet.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

    replay.io.eligible(entry) := view.translated && !killedByRecover && !io.flush &&
      dispatchable(packet, view.resp.paddr, exception, olderStore)

    storeQueue.io.replayQuery(entry).valid  := view.translated && isLoadOp(packet) && !exception
    storeQueue.io.replayQuery(entry).robIdx := packet.robIdx
  }

  // ------------------------------------------------------------- S3 execute
  private val reqStoreMask = maskFor(tReq.memSize)

  storeQueue.io.query.valid  := tValid && !translateKilled && !tResp.exception.valid && isLoadOp(tReq)
  storeQueue.io.query.robIdx := tReq.robIdx
  storeQueue.io.query.addr   := tResp.paddr
  storeQueue.io.query.mask   := reqStoreMask

  // Age-only probe for the current lookup, used by the hit fast path before
  // the request enters the replay queue.
  storeQueue.io.lookupQuery.valid  := lupPending
  storeQueue.io.lookupQuery.robIdx := lupReq.packet.robIdx

  private val translateLoad           = isLoadOp(tReq)
  private val translateStore          = isStoreOp(tReq)
  private val translateSc             = isScOp(tReq)
  private val translateScFail         = translateSc &&
    !(reservationValid && reservationAddr === tResp.paddr)
  private val translateException      = tResp.exception.valid
  private val translateDeviceLoad     = translateLoad && !translateException &&
    MemAddress.isDevice(tResp.paddr, cfg.addrWidth)
  private val deviceLoadOrderingReady = deviceLoadOrderingReadyFor(tReq.robIdx)
  private val loadNeedsMemory         = translateLoad && (translateDeviceLoad || !storeQueue.io.query.fullForward)

  private val loadCanComplete      = !storeQueue.io.query.unresolved &&
    (!loadNeedsMemory ||
      (loadTxns.io.alloc.ready && s4EnqReady && (!translateDeviceLoad || deviceLoadOrderingReady)))
  private val translateCanComplete = translateException || translateStore || translateScFail ||
    (!tReq.isAmo && translateLoad && loadCanComplete) ||
    (tReq.isAmo && !translateScFail && s4EnqReady)
  private val directWritebackType  = translateException || translateStore || translateScFail ||
    (translateLoad && !translateDeviceLoad && storeQueue.io.query.fullForward)
  private val s3CanComplete        = tValid && !translateKilled && !io.flush &&
    translateCanComplete && (!directWritebackType || !frontendWriteback.valid)

  private val s4Enq = Wire(Valid(new LsuS4Entry(cfg)))
  s4Enq                := 0.U.asTypeOf(Valid(new LsuS4Entry(cfg)))
  s4Enq.valid          := s3CanComplete && !translateException &&
    ((translateLoad && loadNeedsMemory) || (tReq.isAmo && !translateScFail))
  s4Enq.bits.packet    := tReq
  s4Enq.bits.vaddr     := tVaddr
  s4Enq.bits.paddr     := tResp.paddr
  s4Enq.bits.loadTxnId := loadTxns.io.allocTxnId

  private val normalLoadAlloc = s3CanComplete && !translateException && translateLoad &&
    loadNeedsMemory && (!translateDeviceLoad || deviceLoadOrderingReady)
  loadTxns.io.alloc.valid            := normalLoadAlloc
  loadTxns.io.alloc.bits.robIdx      := tReq.robIdx
  loadTxns.io.alloc.bits.vaddr       := tVaddr
  loadTxns.io.alloc.bits.paddr       := tResp.paddr
  loadTxns.io.alloc.bits.size        := tReq.memSize
  loadTxns.io.alloc.bits.unsigned    := tReq.memUnsigned
  loadTxns.io.alloc.bits.forwardMask := Mux(translateDeviceLoad, 0.U, storeQueue.io.query.forwardMask)
  loadTxns.io.alloc.bits.forwardData := Mux(translateDeviceLoad, 0.U, storeQueue.io.query.forwardData)

  private val s3Free        = !tValid || s3CanComplete
  private val replayDeqFire = replay.io.deq.valid && s3Free && !io.flush
  replay.io.deq.ready := replayDeqFire

  // Hit fast path: if S3 is free and no older replay entry is ready, consume
  // the hit response directly instead of paying the replay-queue round trip.
  private val lookupKilled       = io.recover.valid &&
    RobAge.isYounger(lupReq.packet.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  private val lookupDispatchable = dispatchable(
    lupReq.packet,
    mmu.io.resp.bits.paddr,
    mmu.io.resp.bits.exception.valid,
    storeQueue.io.lookupQuery.hasOlderStore
  )
  hitFastPath := mmu.io.resp.fire && !mmu.io.resp.bits.deferred && !lookupKilled &&
    s3Free && !replay.io.deq.valid && lookupDispatchable

  when(io.flush || translateKilled) {
    tValid := false.B
  }.otherwise {
    when(hitFastPath) {
      tValid := true.B
      tReq   := lupReq.packet
      tVaddr := lupReq.vaddr
      tResp  := mmu.io.resp.bits
    }.elsewhen(replayDeqFire) {
      tValid := true.B
      tReq   := replay.io.deq.bits.req.packet
      tVaddr := replay.io.deq.bits.req.vaddr
      tResp  := replay.io.deq.bits.resp
    }.elsewhen(s3CanComplete) {
      tValid := false.B
    }
  }

  io.forwardFull                 := tValid && s3CanComplete && translateLoad && !translateDeviceLoad &&
    storeQueue.io.query.fullForward
  io.forwardPartial              := tValid && s3CanComplete && translateLoad && !translateDeviceLoad &&
    storeQueue.io.query.partialForward
  io.forwardUnresolvedStoreStall := VecInit((0 until cfg.translationReplayEntries).map { entry =>
    replayView(entry).translated && isLoadOp(replayView(entry).req.packet) &&
    !replayView(entry).resp.exception.valid && storeQueue.io.replayQuery(entry).hasOlderStore
  }).asUInt.orR

  // S3 direct writeback / store update.
  private val pipeWriteback = Wire(Valid(new RobWritebackPacket(cfg)))
  private val pipeWakeup    = Wire(new IssueWakeup(cfg))
  private val storeUpdate   = Wire(Valid(new StoreQueueUpdate(cfg)))
  pipeWriteback := 0.U.asTypeOf(Valid(new RobWritebackPacket(cfg)))
  pipeWakeup    := 0.U.asTypeOf(new IssueWakeup(cfg))
  storeUpdate   := 0.U.asTypeOf(Valid(new StoreQueueUpdate(cfg)))

  when(s3CanComplete) {
    when(translateException) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := tReq.robIdx
      pipeWriteback.bits.exception := tResp.exception
    }.elsewhen(translateLoad && !translateDeviceLoad && storeQueue.io.query.fullForward) {
      val result = extendLoad(storeQueue.io.query.forwardData, tReq.memSize, tReq.memUnsigned)
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := tReq.robIdx
      pipeWriteback.bits.result    := result
      pipeWriteback.bits.storeAddr := tResp.paddr
      pipeWakeup.valid             := true.B
      pipeWakeup.robIdx            := tReq.robIdx
      pipeWakeup.data              := result
    }.elsewhen(translateStore) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := tReq.robIdx
      pipeWriteback.bits.storeAddr := tResp.paddr
      pipeWriteback.bits.storeData := tReq.src2.data
      pipeWriteback.bits.storeMask := reqStoreMask

      storeUpdate.valid       := true.B
      storeUpdate.bits.sqIdx  := tReq.sqIdx
      storeUpdate.bits.robIdx := tReq.robIdx
      storeUpdate.bits.vaddr  := tVaddr
      storeUpdate.bits.addr   := tResp.paddr
      storeUpdate.bits.data   := tReq.src2.data
      storeUpdate.bits.mask   := reqStoreMask
      storeUpdate.bits.size   := tReq.memSize
      storeUpdate.bits.mmio   := MemAddress.isDevice(tResp.paddr, cfg.addrWidth)
    }.elsewhen(translateScFail) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := tReq.robIdx
      pipeWriteback.bits.result    := 1.U
      pipeWriteback.bits.storeAddr := tResp.paddr
      pipeWakeup.valid             := true.B
      pipeWakeup.robIdx            := tReq.robIdx
      pipeWakeup.data              := 1.U
    }
  }

  // --------------------------------------------------------------- S4

  private val memKilled = io.recover.valid && mState =/= mIdle &&
    RobAge.isYounger(mReq.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  private val memActive = !io.flush && !memKilled && mState =/= mIdle

  private val normalLoadReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  normalLoadReq                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  normalLoadReq.request.addr      := mPaddr
  normalLoadReq.request.write     := false.B
  normalLoadReq.request.size      := mReq.memSize
  normalLoadReq.request.unsigned  := mReq.memUnsigned
  normalLoadReq.request.txnId     := mLoadTxnId
  normalLoadReq.request.cacheable := !MemAddress.isDevice(mPaddr, cfg.addrWidth)
  normalLoadReq.request.kind      := DataMemKind.normal
  normalLoadReq.owner.squashable  := true.B
  normalLoadReq.owner.robIdx      := mReq.robIdx

  private val amoStoreData =
    Mux(isScOp(mReq), mReq.src2.data, amoWriteData(mAmoOld, mReq.src2.data, mReq.fuOp))

  private val amoReadReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoReadReq                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoReadReq.request.addr      := mPaddr
  amoReadReq.request.write     := false.B
  amoReadReq.request.size      := MemSize.word.U
  amoReadReq.request.unsigned  := true.B
  amoReadReq.request.txnId     := DataMemTxn.atomicTag
  amoReadReq.request.cacheable := false.B
  amoReadReq.request.kind      := DataMemKind.atomic
  amoReadReq.owner.squashable  := true.B
  amoReadReq.owner.robIdx      := mReq.robIdx

  private val amoWriteReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoWriteReq                   := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  amoWriteReq.request.addr      := mPaddr
  amoWriteReq.request.write     := true.B
  amoWriteReq.request.size      := MemSize.word.U
  amoWriteReq.request.unsigned  := false.B
  amoWriteReq.request.wdata     := amoStoreData
  amoWriteReq.request.wmask     := ((1 << dataBytes) - 1).U(dataBytes.W)
  amoWriteReq.request.txnId     := DataMemTxn.atomicTag
  amoWriteReq.request.cacheable := false.B
  amoWriteReq.request.kind      := DataMemKind.atomic
  amoWriteReq.owner.squashable  := true.B
  amoWriteReq.owner.robIdx      := mReq.robIdx

  private val pteOwnedReq = Wire(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  pteOwnedReq                  := 0.U.asTypeOf(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, cfg.robIdxWidth))
  pteOwnedReq.request          := mmu.io.ptwReq.bits
  pteOwnedReq.owner.squashable := true.B
  pteOwnedReq.owner.robIdx     := mmu.io.ptwRobIdx

  private val atomicCandidate      = !io.flush && !memKilled && !atomicBusy &&
    (mState === mAmoReadReq || mState === mAmoWriteReq)
  private val ptwCandidate         = !io.flush && !mmu.io.walkAbort && mmu.io.ptwReq.valid && !ptwBusy
  private val loadCandidate        = !io.flush && !memKilled && mState === mLoadReq
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
      arbAtomic     -> Mux(mState === mAmoReadReq, amoReadReq, amoWriteReq),
      arbPtw        -> pteOwnedReq,
      arbSerialized -> storeDrain.io.request.bits,
      arbLoad       -> normalLoadReq,
      arbStore      -> storeDrain.io.request.bits
    )
  )

  outbound.io.enq.valid       := selectedValid
  outbound.io.enq.bits        := selectedBits
  mmu.io.ptwReq.ready         := selectedSource === arbPtw && selectedValid && outbound.io.enq.ready
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
  loadTxns.io.markIssued.bits  := mLoadTxnId
  loadTxns.io.abort.valid      := mState === mLoadReq && (io.flush || memKilled)
  loadTxns.io.abort.bits       := mLoadTxnId

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
  storeDrain.io.allowFaultWriteback := !frontendWriteback.valid && !pipeWriteback.valid

  private val ptwResponseMatch = ptwBusy && io.dmemResp.bits.txnId === DataMemTxn.ptwTag
  private val ptwResponseStale = ptwKilled || io.flush
  mmu.io.ptwResp.valid := io.dmemResp.valid && responseIsPtw && ptwResponseMatch && !ptwResponseStale
  mmu.io.ptwResp.bits  := io.dmemResp.bits
  private val ptwResponseReady = !ptwResponseMatch || ptwResponseStale || mmu.io.ptwResp.ready

  private val atomicResponseState = mState === mAmoReadResp || mState === mAmoWriteResp
  private val atomicResponseMatch = atomicBusy && io.dmemResp.bits.txnId === DataMemTxn.atomicTag
  private val atomicResponseStale = atomicKilled || io.flush || memKilled
  private val atomicResponseReady = !atomicResponseMatch || atomicResponseStale || atomicResponseState

  io.dmemResp.ready := MuxLookup(DataMemTxn.txnClass(io.dmemResp.bits.txnId), true.B)(
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
  when((io.flush || mmu.io.walkAbort) && ptwBusy) {
    ptwKilled := true.B
  }
  when((io.flush || memKilled) && atomicBusy) {
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

  when(activeAtomicResponseWanted && mState === mAmoReadResp) {
    when(io.dmemResp.bits.fault) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := mReq.robIdx
      pipeWriteback.bits.storeAddr := mPaddr
      pipeWriteback.bits.exception := ExceptionInfo.raise(accessFaultCause(mReq), mVaddr, cfg)
    }.elsewhen(isLrOp(mReq)) {
      pipeWriteback.valid          := true.B
      pipeWriteback.bits.robIdx    := mReq.robIdx
      pipeWriteback.bits.result    := io.dmemResp.bits.data
      pipeWriteback.bits.storeAddr := mPaddr
      pipeWakeup.valid             := true.B
      pipeWakeup.robIdx            := mReq.robIdx
      pipeWakeup.data              := io.dmemResp.bits.data
    }
  }

  when(activeAtomicResponseWanted && mState === mAmoWriteResp) {
    pipeWriteback.valid          := true.B
    pipeWriteback.bits.robIdx    := mReq.robIdx
    pipeWriteback.bits.result    := Mux(isScOp(mReq), 0.U, mAmoOld)
    pipeWriteback.bits.storeAddr := mPaddr
    pipeWriteback.bits.storeData := amoStoreData
    pipeWriteback.bits.storeMask := ((1 << dataBytes) - 1).U(dataBytes.W)
    when(io.dmemResp.bits.fault) {
      pipeWriteback.bits.exception := ExceptionInfo.raise(ExceptionCause.storeAccessFault, mVaddr, cfg)
    }
    pipeWakeup.valid             := !io.dmemResp.bits.fault
    pipeWakeup.robIdx            := mReq.robIdx
    pipeWakeup.data              := Mux(isScOp(mReq), 0.U, mAmoOld)
  }

  loadTxns.io.allowComplete := !pipeWriteback.valid && !frontendWriteback.valid

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

  private val directWriteback =
    Mux(frontendWriteback.valid, frontendWriteback, Mux(pipeWriteback.valid, pipeWriteback, serializedFaultWriteback))
  private val directWakeup    = Mux(
    frontendWriteback.valid,
    0.U.asTypeOf(new IssueWakeup(cfg)),
    Mux(pipeWriteback.valid, pipeWakeup, 0.U.asTypeOf(new IssueWakeup(cfg)))
  )
  io.writeback := Mux(directWriteback.valid, directWriteback, loadTxns.io.writeback)
  io.wakeup    := Mux(directWriteback.valid, directWakeup, loadTxns.io.wakeup)

  storeQueue.io.update := storeUpdate
  io.storeUpdate       := storeUpdate

  // --------------------------------------------------------- S4 queue/state

  when(io.flush) {
    s4Valid := false.B
  }.elsewhen(s4RecoverKill) {
    s4Valid := false.B
  }.otherwise {
    when(s4DeqFire) {
      s4Valid := false.B
    }
    when(s4Enq.valid && s4EnqReady) {
      s4Bits  := s4Enq.bits
      s4Valid := true.B
    }
  }

  when(io.flush) {
    mState := mIdle
  }.elsewhen(memKilled) {
    mState := mIdle
  }.otherwise {
    when(mState === mIdle) {
      when(s4DeqFire) {
        mReq       := s4Bits.packet
        mVaddr     := s4Bits.vaddr
        mPaddr     := s4Bits.paddr
        mLoadTxnId := s4Bits.loadTxnId
        mState     := Mux(
          isLoadOp(s4Bits.packet),
          mLoadReq,
          Mux(isScOp(s4Bits.packet), mAmoWriteReq, mAmoReadReq)
        )
      }
    }.elsewhen(mState === mLoadReq) {
      when(rawLoadFire) {
        mState := mIdle
      }
    }.elsewhen(mState === mAmoReadReq) {
      when(rawAtomicFire) {
        mState := mAmoReadResp
      }
    }.elsewhen(mState === mAmoReadResp) {
      when(activeAtomicResponse) {
        when(io.dmemResp.bits.fault || isLrOp(mReq)) {
          mState := mIdle
        }.otherwise {
          mAmoOld := io.dmemResp.bits.data
          mState  := mAmoWriteReq
        }
      }
    }.elsewhen(mState === mAmoWriteReq) {
      when(rawAtomicFire) {
        mState := mAmoWriteResp
      }
    }.otherwise {
      when(activeAtomicResponse) {
        mState := mIdle
      }
    }
  }

  when(activeAtomicResponse && mState === mAmoReadResp && !io.dmemResp.bits.fault && isLrOp(mReq)) {
    reservationValid := true.B
    reservationAddr  := mPaddr
  }
  private val committedStore = io.storeCommit.map(_.valid).reduce(_ || _)
  when(
    io.flush || committedStore || storeDrain.io.serializedSuccess ||
      (s3CanComplete && translateScFail) || (rawAtomicFire && mState === mAmoWriteReq)
  ) {
    reservationValid := false.B
  }

  storesDrained                    := !storeQueue.io.committedPending && !storeDrain.io.normalOutstanding
  io.storesDrainedBeforeCommit     := storesDrained
  io.storesDrained                 := storesDrained && !committedStore
  storeDrain.io.serializedCanStart := io.serializedStore.valid && !serializedInFlight &&
    mState === mIdle && !s4Valid && loadTxns.io.empty &&
    storesDrained && !ptwBusy && !atomicBusy

  io.memoryIdle       := tq.io.empty && replay.io.empty && !lupPending && !tValid && mmu.io.idle &&
    mState === mIdle && !s4Valid && loadTxns.io.empty && storeDrain.io.idle && outbound.io.empty &&
    !ptwBusy && !atomicBusy && !arbLocked && !serializedPending
  io.busy             := !tq.io.empty || !replay.io.empty || lupPending || !mmu.io.idle || tValid ||
    mState =/= mIdle || s4Valid || serializedPending
  io.loadTxnOccupancy := loadTxns.io.occupancy
  io.loadTxnFullStall := VecInit((0 until cfg.translationReplayEntries).map { entry =>
    replayView(entry).translated && isLoadOp(replayView(entry).req.packet) &&
    !replayView(entry).resp.exception.valid &&
    !(loadTxns.io.alloc.ready && s4EnqReady)
  }).asUInt.orR

  when(io.in.fire && inputIsAtomic) {
    assert(io.in.bits.robIdx === io.robHead, "atomic operations must start at the ROB head")
    assert(loadTxns.io.empty && storesDrained, "atomic operations require drained older memory state")
  }
  when(s4Enq.valid) {
    assert(!translateException, "translated exceptions must not enter S4")
    when(translateLoad) {
      assert(loadTxns.io.alloc.fire, "an S4 load must own a newly allocated load transaction")
    }
  }
  when(loadTxns.io.alloc.fire && translateDeviceLoad) {
    assert(tReq.robIdx === io.robHead, "device loads may allocate a transaction only at the ROB head")
    assert(storesDrained && loadTxns.io.empty, "device loads require drained older stores and loads")
    assert(loadTxns.io.alloc.bits.forwardMask === 0.U, "device loads must not consume store-queue forwarding")
  }
  when(rawLoadFire && MemAddress.isDevice(normalLoadReq.request.addr, cfg.addrWidth)) {
    assert(mReq.robIdx === io.robHead, "device loads may externalize only at the ROB head")
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
  when(mmu.io.req.fire) {
    assert(replay.io.reserveReady, "translation lookup without a replay slot")
  }
  when(mmu.io.complete.valid) {
    assert(replay.io.completeMatched, "translation completion must match a pending replay entry")
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
