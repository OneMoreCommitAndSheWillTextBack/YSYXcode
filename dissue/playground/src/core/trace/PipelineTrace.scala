package top.core.trace

import chisel3._
import chisel3.util.{MuxLookup, Valid}
import top.config.{BackendConfig, ICacheConfig}
import top.core.backend.bundle.{DecodePacket, IssuePacket, RetireGroup, RobWritebackPacket, StoreQueueUpdate}
import top.core.backend.decoder.FuType
import top.core.bundle.{DataMemKind, FrontendToBackend, RobAge, RobRecovery}
import top.core.frontend.ifetch.FetchQueueEnqueue

/** Stable semantic events exported by the RTL pipeline observer.
  *
  * These values form a language boundary with `npc_sim_types.h` and Rust's Kanata writer. Pipeline modules report
  * architectural events only; visualization lanes, stage names, and same-cycle ordering remain host policy.
  */
object PipelineTraceKind {
  val fetchQueueEnqueue = 1.U(32.W)
  val backendReceive    = 2.U(32.W)
  val dispatch          = 3.U(32.W)
  val issue             = 4.U(32.W)
  val memoryRequest     = 5.U(32.W)
  val storeReady        = 6.U(32.W)
  val writeback         = 7.U(32.W)
  val retire            = 8.U(32.W)
  val recover           = 9.U(32.W)
  val flush             = 10.U(32.W)
}

/** Instruction properties whose meaning is independent of the current pipeline shape. */
object PipelineTraceFlag {
  val needsIssue     = 0
  val src1Dependency = 1
  val src2Dependency = 2
  val load           = 3
  val store          = 4
  val atomic         = 5
  val trap           = 6

  def bit(index: Int, enabled: Bool): UInt =
    Mux(enabled, (1.U(32.W) << index)(31, 0), 0.U(32.W))
}

/** Semantic execution resources. Rust owns their displayed Kanata stage names. */
object PipelineTraceResource {
  val none        = 0.U(32.W)
  val alu         = 1.U(32.W)
  val mul         = 2.U(32.W)
  val div         = 3.U(32.W)
  val bru         = 4.U(32.W)
  val jmp         = 5.U(32.W)
  val csr         = 6.U(32.W)
  val lsu         = 7.U(32.W)
  val fence       = 8.U(32.W)
  val load        = 9.U(32.W)
  val ptw         = 10.U(32.W)
  val atomicRead  = 11.U(32.W)
  val atomicWrite = 12.U(32.W)
  val unknown     = 15.U(32.W)

  def fromFuType(fuType: UInt): UInt =
    MuxLookup(fuType, unknown)(
      Seq(
        FuType.alu   -> alu,
        FuType.mul   -> mul,
        FuType.div   -> div,
        FuType.bru   -> bru,
        FuType.jmp   -> jmp,
        FuType.csr   -> csr,
        FuType.lsu   -> lsu,
        FuType.fence -> fence
      )
    )

  def fromMemory(kind: UInt, write: Bool): UInt =
    MuxLookup(kind, load)(
      Seq(
        DataMemKind.ptw    -> ptw,
        DataMemKind.atomic -> Mux(write, atomicWrite, atomicRead)
      )
    )
}

/** Fixed-width event payload used by every trace producer and the DPI bridge. */
class PipelineTraceEvent extends Bundle {
  val kind      = UInt(32.W)
  val flags     = UInt(32.W)
  val slot      = UInt(32.W)
  val robIdx    = UInt(32.W)
  val producer0 = UInt(32.W)
  val producer1 = UInt(32.W)
  val pc        = UInt(32.W)
  val inst      = UInt(32.W)
  val rawInst   = UInt(32.W)
  val sequence  = UInt(32.W)
  val epoch     = UInt(32.W)
  val resource  = UInt(32.W)
  val txnId     = UInt(32.W)
}

private object PipelineTraceEventBuilder {
  def blank(kind: UInt, slot: Int): PipelineTraceEvent = {
    val event = Wire(new PipelineTraceEvent)
    event      := 0.U.asTypeOf(new PipelineTraceEvent)
    event.kind := kind
    event.slot := slot.U(32.W)
    event
  }

  def instruction(
    kind:     UInt,
    slot:     Int,
    pc:       UInt,
    inst:     UInt,
    rawInst:  UInt,
    sequence: UInt,
    epoch:    UInt
  ): PipelineTraceEvent = {
    val event = blank(kind, slot)
    event.pc       := pc.pad(32)
    event.inst     := inst.pad(32)
    event.rawInst  := rawInst.pad(32)
    event.sequence := sequence.pad(32)
    event.epoch    := epoch.pad(32)
    event
  }

  def rob(kind: UInt, slot: Int, robIdx: UInt): PipelineTraceEvent = {
    val event = blank(kind, slot)
    event.robIdx := robIdx.pad(32)
    event
  }
}

/** Observes the exact point where assembled instructions acquire FetchQueue lifetime. */
class FrontendPipelineTrace(cacheCfg: ICacheConfig, enqueueWidth: Int) extends Module {
  val io = IO(new Bundle {
    val enqueueFire = Input(Bool())
    val enqueue     = Input(new FetchQueueEnqueue(cacheCfg, enqueueWidth))
    val events      = Output(Vec(enqueueWidth, Valid(new PipelineTraceEvent)))
  })

  for (lane <- 0 until enqueueWidth) {
    val entry = io.enqueue.insts(lane)
    io.events(lane)       := 0.U.asTypeOf(Valid(new PipelineTraceEvent))
    io.events(lane).valid := io.enqueueFire && entry.valid
    io.events(lane).bits  := PipelineTraceEventBuilder.instruction(
      PipelineTraceKind.fetchQueueEnqueue,
      lane,
      entry.bits.inst.pc,
      entry.bits.inst.inst,
      entry.bits.inst.rawInst,
      entry.bits.inst.prediction.sequence,
      entry.bits.inst.prediction.epoch
    )
  }
}

object BackendPipelineTrace {
  private def dispatchBase(cfg:  BackendConfig): Int = cfg.issueWidth
  private def issueBase(cfg:     BackendConfig): Int = dispatchBase(cfg) + cfg.dispatchWidth
  private def writebackBase(cfg: BackendConfig): Int = issueBase(cfg) + cfg.intIssueWidth + 1
  private def retireBase(cfg:    BackendConfig): Int = writebackBase(cfg) + cfg.writebackWidth

  def storeReadyIndex(cfg:    BackendConfig): Int = retireBase(cfg) + cfg.commitWidth
  def memoryRequestIndex(cfg: BackendConfig): Int = storeReadyIndex(cfg) + 1
  def recoverIndex(cfg:       BackendConfig): Int = memoryRequestIndex(cfg) + 1
  def flushIndex(cfg:         BackendConfig): Int = recoverIndex(cfg) + 1
  def eventCount(cfg:         BackendConfig): Int = flushIndex(cfg) + 1

  def receiveIndex(lane:  Int): Int = lane
  def dispatchIndex(cfg:  BackendConfig, lane: Int): Int = dispatchBase(cfg) + lane
  def intIssueIndex(cfg:  BackendConfig, port: Int): Int = issueBase(cfg) + port
  def memIssueIndex(cfg:  BackendConfig): Int = issueBase(cfg) + cfg.intIssueWidth
  def writebackIndex(cfg: BackendConfig, port: Int): Int = writebackBase(cfg) + port
  def retireIndex(cfg:    BackendConfig, lane: Int): Int = retireBase(cfg) + lane
}

/** Collects backend handshakes without adding ready paths or changing pipeline ownership. */
class BackendPipelineTrace(cfg: BackendConfig) extends Module {
  val io = IO(new Bundle {
    val frontendFire = Input(Bool())
    val frontend     = Input(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth))

    val dispatchFire   = Input(Vec(cfg.dispatchWidth, Bool()))
    val dispatchDecode = Input(Vec(cfg.dispatchWidth, new DecodePacket(cfg)))
    val dispatchIssue  = Input(Vec(cfg.dispatchWidth, new IssuePacket(cfg)))

    val intIssueFire = Input(Vec(cfg.intIssueWidth, Bool()))
    val intIssue     = Input(Vec(cfg.intIssueWidth, new IssuePacket(cfg)))
    val memIssueFire = Input(Bool())
    val memIssue     = Input(new IssuePacket(cfg))

    val writeback  = Input(Vec(cfg.writebackWidth, Valid(new RobWritebackPacket(cfg))))
    val retire     = Input(new RetireGroup(cfg))
    val storeReady = Input(Valid(new StoreQueueUpdate(cfg)))

    val memoryRequestFire   = Input(Bool())
    val memoryRequestRobIdx = Input(UInt(cfg.robIdxWidth.W))
    val memoryRequestKind   = Input(UInt(DataMemKind.width.W))
    val memoryRequestWrite  = Input(Bool())
    val memoryRequestTxnId  = Input(UInt(4.W))

    val robHead     = Input(UInt(cfg.robIdxWidth.W))
    val recover     = Input(new RobRecovery(cfg.robIdxWidth))
    val globalFlush = Input(Bool())

    val events = Output(Vec(BackendPipelineTrace.eventCount(cfg), Valid(new PipelineTraceEvent)))
  })

  for (event <- io.events) {
    event := 0.U.asTypeOf(Valid(new PipelineTraceEvent))
  }

  for (lane <- 0 until cfg.issueWidth) {
    val fetch = io.frontend.insts(lane)
    val event = io.events(BackendPipelineTrace.receiveIndex(lane))
    event.valid := io.frontendFire && fetch.valid
    event.bits  := PipelineTraceEventBuilder.instruction(
      PipelineTraceKind.backendReceive,
      lane,
      fetch.bits.pc,
      fetch.bits.inst,
      fetch.bits.rawInst,
      fetch.bits.prediction.sequence,
      fetch.bits.prediction.epoch
    )
  }

  for (lane <- 0 until cfg.dispatchWidth) {
    val decode = io.dispatchDecode(lane)
    val issue  = io.dispatchIssue(lane)
    val event  = io.events(BackendPipelineTrace.dispatchIndex(cfg, lane))

    event.valid          := io.dispatchFire(lane)
    event.bits           := PipelineTraceEventBuilder.instruction(
      PipelineTraceKind.dispatch,
      lane,
      decode.fetch.pc,
      decode.fetch.inst,
      decode.fetch.rawInst,
      decode.fetch.prediction.sequence,
      decode.fetch.prediction.epoch
    )
    event.bits.robIdx    := issue.robIdx.pad(32)
    event.bits.producer0 := issue.src1.tag.pad(32)
    event.bits.producer1 := issue.src2.tag.pad(32)
    event.bits.resource  := PipelineTraceResource.fromFuType(issue.fuType)
    event.bits.flags     := Seq(
      PipelineTraceFlag.bit(PipelineTraceFlag.needsIssue, decode.needsIssue),
      PipelineTraceFlag.bit(PipelineTraceFlag.src1Dependency, decode.needsIssue && !issue.src1.ready),
      PipelineTraceFlag.bit(PipelineTraceFlag.src2Dependency, decode.needsIssue && !issue.src2.ready),
      PipelineTraceFlag.bit(PipelineTraceFlag.load, decode.isLoad),
      PipelineTraceFlag.bit(PipelineTraceFlag.store, decode.isStore),
      PipelineTraceFlag.bit(PipelineTraceFlag.atomic, decode.isAmo),
      PipelineTraceFlag.bit(PipelineTraceFlag.trap, decode.hasTrapAtRetire)
    ).reduce(_ | _)
  }

  for (port <- 0 until cfg.intIssueWidth) {
    val issue = io.intIssue(port)
    val event = io.events(BackendPipelineTrace.intIssueIndex(cfg, port))
    event.valid         := io.intIssueFire(port)
    event.bits          := PipelineTraceEventBuilder.rob(PipelineTraceKind.issue, port, issue.robIdx)
    event.bits.resource := PipelineTraceResource.fromFuType(issue.fuType)
  }

  private val memIssueEvent = io.events(BackendPipelineTrace.memIssueIndex(cfg))
  memIssueEvent.valid         := io.memIssueFire
  memIssueEvent.bits          := PipelineTraceEventBuilder.rob(PipelineTraceKind.issue, cfg.intIssueWidth, io.memIssue.robIdx)
  memIssueEvent.bits.resource := PipelineTraceResource.fromFuType(io.memIssue.fuType)

  for (port <- 0 until cfg.writebackWidth) {
    val writeback        = io.writeback(port)
    val killedByRecovery = io.recover.valid && RobAge.isYounger(
      writeback.bits.robIdx,
      io.recover.robIdx,
      io.robHead,
      cfg.robEntries,
      cfg.robIdxWidth
    )
    val event            = io.events(BackendPipelineTrace.writebackIndex(cfg, port))
    event.valid := writeback.valid && !io.globalFlush && !killedByRecovery
    event.bits  := PipelineTraceEventBuilder.rob(PipelineTraceKind.writeback, port, writeback.bits.robIdx)
  }

  for (lane <- 0 until cfg.commitWidth) {
    val retire = io.retire.lanes(lane)
    val event  = io.events(BackendPipelineTrace.retireIndex(cfg, lane))
    event.valid      := io.retire.validMask(lane)
    event.bits       := PipelineTraceEventBuilder.rob(PipelineTraceKind.retire, lane, retire.robIdx)
    event.bits.flags := PipelineTraceFlag.bit(PipelineTraceFlag.trap, retire.exception.valid)
  }

  private val storeReadyEvent = io.events(BackendPipelineTrace.storeReadyIndex(cfg))
  storeReadyEvent.valid := io.storeReady.valid
  storeReadyEvent.bits  := PipelineTraceEventBuilder.rob(PipelineTraceKind.storeReady, 0, io.storeReady.bits.robIdx)

  private val memoryRequestEvent = io.events(BackendPipelineTrace.memoryRequestIndex(cfg))
  memoryRequestEvent.valid         := io.memoryRequestFire
  memoryRequestEvent.bits          := PipelineTraceEventBuilder.rob(
    PipelineTraceKind.memoryRequest,
    0,
    io.memoryRequestRobIdx
  )
  memoryRequestEvent.bits.resource := PipelineTraceResource.fromMemory(io.memoryRequestKind, io.memoryRequestWrite)
  memoryRequestEvent.bits.txnId    := io.memoryRequestTxnId.pad(32)

  private val recoverEvent = io.events(BackendPipelineTrace.recoverIndex(cfg))
  recoverEvent.valid := io.recover.valid
  recoverEvent.bits  := PipelineTraceEventBuilder.rob(PipelineTraceKind.recover, 0, io.recover.robIdx)

  private val flushEvent = io.events(BackendPipelineTrace.flushIndex(cfg))
  flushEvent.valid := io.globalFlush
  flushEvent.bits  := PipelineTraceEventBuilder.blank(PipelineTraceKind.flush, 0)
}
