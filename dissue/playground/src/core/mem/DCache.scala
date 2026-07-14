package top.core.mem

import chisel3._
import chisel3.util.{Cat, Decoupled, Fill, Mux1H, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.bus.axi.{AxiBurst, AxiResp}
import top.config.{DCacheConfig, MemConfig}
import top.core.bundle.{
  DataMemExternalization,
  DataMemOwner,
  DataMemResp,
  DataMemTxn,
  OwnedDataMemReq,
  RobAge,
  RobRecovery
}
import top.core.mem.bundle.{AxiMasterReadReq, AxiMasterReadResp, AxiMasterWriteReq, AxiMasterWriteResp}

/** One request waiting on a cache-line refill.
  *
  * Stores use the same queue as loads. This lets a store miss write-allocate
  * after refill and preserves the order in which accesses reached the cache.
  */
class DCacheWaiter(cfg: DCacheConfig, robIdxWidth: Int) extends Bundle {
  val valid      = Bool()
  val write      = Bool()
  val txnId      = UInt(DataMemTxn.width.W)
  val byteOffset = UInt(cfg.offsetBits.W)
  val size       = UInt(3.W)
  val unsigned   = Bool()
  val wdata      = UInt(cfg.dataWidth.W)
  val wmask      = UInt((cfg.dataWidth / 8).W)
  val owner      = new DataMemOwner(robIdxWidth)
}

class DCachePerf(cfg: DCacheConfig) extends Bundle {
  val access         = Bool()
  val hit            = Bool()
  val miss           = Bool()
  val bypass         = Bool()
  val mshrAlloc      = Bool()
  val mshrMerge      = Bool()
  val mshrFullStall  = Bool()
  val hitUnderMiss   = Bool()
  val queuedMiss     = Bool()
  val refillStart    = Bool()
  val refillComplete = Bool()
  val refillFault    = Bool()
  val mshrOccupancy  = UInt(math.max(chisel3.util.log2Ceil(cfg.mshrEntries + 1), 1).W)
}

object DCache {
  def cancelPorts(cfg: DCacheConfig): Int = 1 + cfg.mshrEntries * cfg.waitersPerMshr
}

/** Write-back, write-allocate data cache.
  *
  * The cache accepts speculative cache hits and merges into an already
  * authorized miss. A new miss is allocated only when its ROB owner may make
  * an external request. Each MSHR then owns an irrevocable refill or dirty
  * victim writeback and must drain any AXI transaction it has started.
  */
class DCache(
  cfg:        DCacheConfig = DCacheConfig(),
  memCfg:     MemConfig = MemConfig(),
  robEntries: Int = 16)
    extends Module {
  require(cfg.addrWidth == memCfg.addrWidth, "DCache and memory address widths must match")
  require(cfg.dataWidth == memCfg.axiDataWidth, "DCache and AXI data widths must match")

  private val robIdxWidth       = math.max(chisel3.util.log2Ceil(robEntries), 1)
  private val dataBytes         = cfg.dataWidth / 8
  private val beats             = cfg.beatCount
  private val beatIdxWidth      = math.max(chisel3.util.log2Ceil(beats), 1)
  private val waiterIdxWidth    = math.max(chisel3.util.log2Ceil(cfg.waitersPerMshr), 1)
  private val waiterCountWidth  = math.max(chisel3.util.log2Ceil(cfg.waitersPerMshr + 1), 1)
  private val byteBeatShift     = chisel3.util.log2Ceil(dataBytes)
  private val bitBeatShift      = chisel3.util.log2Ceil(cfg.dataWidth)
  private val lastBeat          = (beats - 1).U(beatIdxWidth.W)
  private val fullWriteMask     = ((BigInt(1) << dataBytes) - 1).U(dataBytes.W)

  private val mshrQueued     = 0.U(2.W)
  private val mshrEvicting  = 1.U(2.W)
  private val mshrReceiving = 2.U(2.W)
  private val mshrResponding = 3.U(2.W)

  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, robIdxWidth)))
    val resp = Decoupled(new DataMemResp(cfg.dataWidth))

    val flush         = Input(Bool())
    val recover       = Input(new RobRecovery(robIdxWidth))
    val robHead       = Input(UInt(robIdxWidth.W))
    val unresolvedCfi = Input(Vec(robEntries, Bool()))
    val cancel        = Output(Vec(DCache.cancelPorts(cfg), Valid(UInt(DataMemTxn.width.W))))

    /** Clean and invalidate one line before an uncached coherent access. */
    val cleanInvalidate = Flipped(Decoupled(UInt(cfg.addrWidth.W)))

    val axiReadReq   = Decoupled(new AxiMasterReadReq(memCfg.addrWidth, memCfg.axiIdWidth))
    val axiReadResp  = Flipped(Decoupled(new AxiMasterReadResp(memCfg.axiDataWidth, memCfg.axiIdWidth)))
    val axiWriteReq  = Decoupled(new AxiMasterWriteReq(memCfg.addrWidth, memCfg.axiDataWidth, memCfg.axiIdWidth))
    val axiWriteResp = Flipped(Decoupled(new AxiMasterWriteResp(memCfg.axiIdWidth)))

    val perf = Output(new DCachePerf(cfg))
  })

  private def setIndex(addr: UInt): UInt = {
    if (cfg.indexBits == 0) 0.U(cfg.setIdxBits.W)
    else addr(cfg.offsetBits + cfg.indexBits - 1, cfg.offsetBits)
  }

  private def tag(addr: UInt): UInt =
    addr(cfg.addrWidth - 1, cfg.offsetBits + cfg.indexBits)

  private def blockAddr(addr: UInt): UInt =
    addr & ~((cfg.lineBytes - 1).U(cfg.addrWidth.W))

  private def lineAddr(lineTag: UInt, set: UInt): UInt = {
    if (cfg.indexBits == 0) Cat(lineTag, 0.U(cfg.offsetBits.W))
    else Cat(lineTag, set(cfg.indexBits - 1, 0), 0.U(cfg.offsetBits.W))
  }

  private def lineDataAt(line: UInt, byteOffset: UInt): UInt =
    (line >> (byteOffset << 3))(cfg.dataWidth - 1, 0)

  private def lineBeatAt(line: UInt, beat: UInt): UInt =
    (line >> (beat << bitBeatShift))(cfg.dataWidth - 1, 0)

  private def mergeStore(line: UInt, byteOffset: UInt, wdata: UInt, wmask: UInt): UInt = {
    val lineMask     = (wmask << byteOffset)(cfg.lineBytes - 1, 0)
    val lineData     = (wdata << (byteOffset << 3))(cfg.blockBits - 1, 0)
    val expandedMask = Cat((0 until cfg.lineBytes).reverse.map(byte => Fill(8, lineMask(byte))))
    (line & ~expandedMask) | (lineData & expandedMask)
  }

  private def ownerKilled(owner: DataMemOwner): Bool =
    owner.squashable && (io.flush ||
      (io.recover.valid && RobAge.isYounger(owner.robIdx, io.recover.robIdx, io.robHead, robEntries, robIdxWidth)))

  private def mayIssueAxi(owner: DataMemOwner): Bool =
    DataMemExternalization.mayIssueAxi(
      owner,
      io.unresolvedCfi,
      io.robHead,
      robEntries,
      robIdxWidth,
      io.flush,
      io.recover
    )

  private val validArray = RegInit(VecInit(Seq.fill(cfg.sets)(VecInit(Seq.fill(cfg.ways)(false.B)))))
  private val dirtyArray = RegInit(VecInit(Seq.fill(cfg.sets)(VecInit(Seq.fill(cfg.ways)(false.B)))))
  private val tagArray   = Reg(Vec(cfg.sets, Vec(cfg.ways, UInt(cfg.tagBits.W))))
  private val dataArray  = Reg(Vec(cfg.sets, Vec(cfg.ways, UInt(cfg.blockBits.W))))
  private val rrWay      = RegInit(VecInit(Seq.fill(cfg.sets)(0.U(cfg.wayIdxBits.W))))

  private val mshrValid          = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))
  private val mshrState          = Reg(Vec(cfg.mshrEntries, UInt(2.W)))
  private val mshrBlockAddr      = Reg(Vec(cfg.mshrEntries, UInt(cfg.addrWidth.W)))
  private val mshrSet            = Reg(Vec(cfg.mshrEntries, UInt(cfg.setIdxBits.W)))
  private val mshrWay            = Reg(Vec(cfg.mshrEntries, UInt(cfg.wayIdxBits.W)))
  private val mshrAxiAuthorized  = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))
  private val mshrBeatIndex      = Reg(Vec(cfg.mshrEntries, UInt(beatIdxWidth.W)))
  private val mshrFault          = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))
  private val mshrBeats          = Reg(Vec(cfg.mshrEntries, Vec(beats, UInt(cfg.dataWidth.W))))
  private val mshrWaiters        = Reg(Vec(cfg.mshrEntries, Vec(cfg.waitersPerMshr, new DCacheWaiter(cfg, robIdxWidth))))
  private val mshrWaiterCount    = Reg(Vec(cfg.mshrEntries, UInt(waiterCountWidth.W)))
  private val mshrResponseIdx    = Reg(Vec(cfg.mshrEntries, UInt(waiterIdxWidth.W)))
  private val mshrEvictAddr      = Reg(Vec(cfg.mshrEntries, UInt(cfg.addrWidth.W)))
  private val mshrEvictData      = Reg(Vec(cfg.mshrEntries, UInt(cfg.blockBits.W)))
  private val mshrWriteBeat      = Reg(Vec(cfg.mshrEntries, UInt(beatIdxWidth.W)))
  private val mshrWriteAwaitResp = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))
  private val mshrWritebackStarted = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))

  private val hitRespValid = RegInit(false.B)
  private val hitResp      = Reg(new DataMemResp(cfg.dataWidth))
  private val hitRespOwner = Reg(new DataMemOwner(robIdxWidth))

  private val maintenanceWriteActive    = RegInit(false.B)
  private val maintenanceWriteAddr      = Reg(UInt(cfg.addrWidth.W))
  private val maintenanceWriteData      = Reg(UInt(cfg.blockBits.W))
  private val maintenanceWriteBeat      = RegInit(0.U(beatIdxWidth.W))
  private val maintenanceWriteAwaitResp = RegInit(false.B)

  private def waiterLive(entry: Int, waiter: Int): Bool =
    mshrValid(entry) && waiter.U < mshrWaiterCount(entry) && mshrWaiters(entry)(waiter).valid

  private val retainedWaiterCount = Wire(Vec(cfg.mshrEntries, UInt(waiterCountWidth.W)))
  private val retainedWaiters = Wire(Vec(cfg.mshrEntries, Vec(cfg.waitersPerMshr, new DCacheWaiter(cfg, robIdxWidth))))

  for (entry <- 0 until cfg.mshrEntries) {
    val keep = Wire(Vec(cfg.waitersPerMshr, Bool()))
    for (waiter <- 0 until cfg.waitersPerMshr) {
      val live = waiterLive(entry, waiter)
      keep(waiter) := live && !ownerKilled(mshrWaiters(entry)(waiter).owner)

      val cancelPort = 1 + entry * cfg.waitersPerMshr + waiter
      io.cancel(cancelPort).valid := live && ownerKilled(mshrWaiters(entry)(waiter).owner) &&
        DataMemTxn.isLoad(mshrWaiters(entry)(waiter).txnId)
      io.cancel(cancelPort).bits := mshrWaiters(entry)(waiter).txnId
    }
    retainedWaiterCount(entry) := PopCount(keep)

    for (destination <- 0 until cfg.waitersPerMshr) {
      val sourceOH = Wire(Vec(cfg.waitersPerMshr, Bool()))
      for (source <- 0 until cfg.waitersPerMshr) {
        val priorKept = if (source == 0) 0.U else PopCount(keep.take(source))
        sourceOH(source) := keep(source) && priorKept === destination.U
      }
      retainedWaiters(entry)(destination) := 0.U.asTypeOf(new DCacheWaiter(cfg, robIdxWidth))
      when(sourceOH.asUInt.orR) {
        retainedWaiters(entry)(destination) := Mux1H(sourceOH, mshrWaiters(entry))
      }
    }
  }

  io.cancel(0).valid := hitRespValid && ownerKilled(hitRespOwner) && DataMemTxn.isLoad(hitResp.txnId)
  io.cancel(0).bits  := hitResp.txnId

  private val reqSet       = setIndex(io.req.bits.request.addr)
  private val reqTag       = tag(io.req.bits.request.addr)
  private val reqBlockAddr = blockAddr(io.req.bits.request.addr)
  private val wayHits      = VecInit((0 until cfg.ways).map { way =>
    validArray(reqSet)(way) && tagArray(reqSet)(way) === reqTag
  })
  private val hitOH        = wayHits.asUInt
  private val hit          = hitOH.orR
  private val hitWay       = OHToUInt(hitOH)
  private val hitLine      = Mux1H(wayHits, dataArray(reqSet))

  private val mshrMatchOH = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrBlockAddr(entry) === reqBlockAddr && mshrState(entry) =/= mshrResponding
  }).asUInt
  private val mshrMatch        = mshrMatchOH.orR
  private val mshrMatchIdx     = OHToUInt(mshrMatchOH)
  private val matchWaiterSpace = mshrMatch && mshrWaiterCount(mshrMatchIdx) < cfg.waitersPerMshr.U

  private val reservedWay = Wire(Vec(cfg.ways, Bool()))
  for (way <- 0 until cfg.ways) {
    reservedWay(way) := VecInit((0 until cfg.mshrEntries).map { entry =>
      mshrValid(entry) && mshrSet(entry) === reqSet && mshrWay(entry) === way.U
    }).asUInt.orR
  }

  private val invalidWayOH = VecInit((0 until cfg.ways).map(way => !reservedWay(way) && !validArray(reqSet)(way))).asUInt
  private val rrWayOH      = VecInit((0 until cfg.ways).map(way => !reservedWay(way) && rrWay(reqSet) === way.U)).asUInt
  private val anyWayOH     = VecInit((0 until cfg.ways).map(way => !reservedWay(way))).asUInt
  private val victimOH     = Mux(
    invalidWayOH.orR,
    PriorityEncoderOH(invalidWayOH),
    Mux(rrWayOH.orR, rrWayOH, PriorityEncoderOH(anyWayOH))
  )
  private val hasVictim = victimOH.orR
  private val victimWay = OHToUInt(victimOH)
  private val victimDirty = validArray(reqSet)(victimWay) && dirtyArray(reqSet)(victimWay)

  private val freeMshrOH  = VecInit(mshrValid.map(!_)).asUInt
  private val hasFreeMshr = freeMshrOH.orR
  private val freeMshrIdx = OHToUInt(freeMshrOH)

  private val respondingOH = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrResponding && mshrWaiterCount(entry) =/= 0.U
  }).asUInt
  private val hasResponding    = respondingOH.orR
  private val respondingIdx    = OHToUInt(respondingOH)
  private val respondingWaiter = mshrWaiters(respondingIdx)(mshrResponseIdx(respondingIdx))
  private val respondingLine   = mshrBeats(respondingIdx).asUInt

  private val hasEvicting = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrEvicting
  }).asUInt.orR

  private val maintenanceSet = setIndex(io.cleanInvalidate.bits)
  private val maintenanceTag = tag(io.cleanInvalidate.bits)
  private val maintenanceWayHits = VecInit((0 until cfg.ways).map { way =>
    validArray(maintenanceSet)(way) && tagArray(maintenanceSet)(way) === maintenanceTag
  })
  private val maintenanceHit    = maintenanceWayHits.asUInt.orR
  private val maintenanceWay    = OHToUInt(maintenanceWayHits.asUInt)
  private val maintenanceDirty  = maintenanceHit && dirtyArray(maintenanceSet)(maintenanceWay)
  private val maintenanceCanInspect = !maintenanceWriteActive && !mshrValid.asUInt.orR && !hitRespValid

  // A maintenance request stays valid while a dirty line is written back. It
  // handshakes only after the line is clean and invalidated.
  io.cleanInvalidate.ready := maintenanceCanInspect && (!maintenanceHit || !maintenanceDirty)

  private val hitResponseVisible = hitRespValid && !io.flush && !io.recover.valid && !ownerKilled(hitRespOwner)
  private val mshrResponseVisible = hasResponding && !io.flush && !io.recover.valid && !ownerKilled(respondingWaiter.owner)
  private val responseBusy = hitRespValid || hasResponding
  private val requestCanAllocate = hasFreeMshr && hasVictim && mayIssueAxi(io.req.bits.owner)
  private val requestReady = Mux(hit, true.B, Mux(mshrMatch, matchWaiterSpace, requestCanAllocate))

  // An eviction owns the single AXI writer until all of its beats are durable.
  // Blocking new requests here keeps the selected victim stable throughout the
  // writeback transaction sequence.
  io.req.ready := !io.flush && !io.recover.valid && !responseBusy && !hasEvicting &&
    !maintenanceWriteActive && !io.cleanInvalidate.valid && requestReady

  private val requestFire     = io.req.fire
  private val requestMiss     = requestFire && !hit
  private val requestMerge    = requestMiss && mshrMatch
  private val requestAllocate = requestMiss && !mshrMatch
  private val activeMshr      = mshrValid.asUInt.orR

  private val incomingWaiter = Wire(new DCacheWaiter(cfg, robIdxWidth))
  incomingWaiter.valid      := true.B
  incomingWaiter.write      := io.req.bits.request.write
  incomingWaiter.txnId      := io.req.bits.request.txnId
  incomingWaiter.byteOffset := io.req.bits.request.addr(cfg.offsetBits - 1, 0)
  incomingWaiter.size       := io.req.bits.request.size
  incomingWaiter.unsigned   := io.req.bits.request.unsigned
  incomingWaiter.wdata      := io.req.bits.request.wdata
  incomingWaiter.wmask      := io.req.bits.request.wmask
  incomingWaiter.owner      := io.req.bits.owner

  io.resp.valid := hitResponseVisible || mshrResponseVisible
  io.resp.bits  := 0.U.asTypeOf(new DataMemResp(cfg.dataWidth))
  when(hitResponseVisible) {
    io.resp.bits := hitResp
  }.elsewhen(mshrResponseVisible) {
    io.resp.bits.data  := Mux(
      respondingWaiter.write || mshrFault(respondingIdx),
      0.U,
      lineDataAt(respondingLine, respondingWaiter.byteOffset)
    )
    io.resp.bits.fault := mshrFault(respondingIdx)
    io.resp.bits.txnId := respondingWaiter.txnId
  }

  private val queuedOH = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrQueued && mshrAxiAuthorized(entry) &&
      mshrWaiterCount(entry) =/= 0.U
  }).asUInt
  private val hasQueued = queuedOH.orR
  private val queuedIdx = OHToUInt(queuedOH)

  private val receivingOH = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrReceiving
  }).asUInt
  private val hasReceiving = receivingOH.orR
  private val receivingIdx = OHToUInt(receivingOH)

  io.axiReadReq.valid      := hasQueued && !hasReceiving && !io.flush && !io.recover.valid
  io.axiReadReq.bits.addr  := mshrBlockAddr(queuedIdx)
  io.axiReadReq.bits.id    := 2.U(memCfg.axiIdWidth.W)
  io.axiReadReq.bits.len   := (beats - 1).U
  io.axiReadReq.bits.size  := byteBeatShift.U
  io.axiReadReq.bits.burst := AxiBurst.incr
  io.axiReadResp.ready     := hasReceiving

  private val evictWriteOH = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrEvicting
  }).asUInt
  private val hasEvictWrite = evictWriteOH.orR
  private val evictWriteIdx = OHToUInt(evictWriteOH)
  private val evictAwaitOH = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrEvicting && mshrWriteAwaitResp(entry)
  }).asUInt
  private val hasEvictAwait = evictAwaitOH.orR
  private val evictAwaitIdx = OHToUInt(evictAwaitOH)

  private val writebackFromMaintenance = maintenanceWriteActive
  private val writebackFromEviction    = !maintenanceWriteActive && hasEvictWrite
  private val writebackActive          = writebackFromMaintenance || writebackFromEviction
  private val writebackAwaitResp = Mux(
    writebackFromMaintenance,
    maintenanceWriteAwaitResp,
    Mux(hasEvictWrite, mshrWriteAwaitResp(evictWriteIdx), false.B)
  )
  private val writebackAddr = Mux(
    writebackFromMaintenance,
    maintenanceWriteAddr,
    mshrEvictAddr(evictWriteIdx)
  )
  private val writebackLine = Mux(
    writebackFromMaintenance,
    maintenanceWriteData,
    mshrEvictData(evictWriteIdx)
  )
  private val writebackBeat = Mux(
    writebackFromMaintenance,
    maintenanceWriteBeat,
    mshrWriteBeat(evictWriteIdx)
  )

  // Write back one line beat per AXI transaction. This is valid AXI for every
  // target, and it keeps the cache independent of a target's burst-write
  // buffering policy. `writebackBeat` only advances after the corresponding B
  // response, so the selected line remains recoverable until it is durable.
  io.axiWriteReq.valid      := writebackActive && !writebackAwaitResp && !io.flush && !io.recover.valid
  io.axiWriteReq.bits.addr  := writebackAddr + (writebackBeat << byteBeatShift)
  io.axiWriteReq.bits.id    := 2.U(memCfg.axiIdWidth.W)
  io.axiWriteReq.bits.len   := 0.U
  io.axiWriteReq.bits.size  := byteBeatShift.U
  io.axiWriteReq.bits.burst := AxiBurst.incr
  io.axiWriteReq.bits.data  := lineBeatAt(writebackLine, writebackBeat)
  io.axiWriteReq.bits.strb  := fullWriteMask
  io.axiWriteReq.bits.last  := true.B
  io.axiWriteResp.ready     := maintenanceWriteAwaitResp || hasEvictAwait

  private val refillFault    = mshrFault(receivingIdx) || io.axiReadResp.bits.resp =/= AxiResp.okay
  private val refillLast     = io.axiReadResp.bits.last || mshrBeatIndex(receivingIdx) === lastBeat
  private val completedBeats = Wire(Vec(beats, UInt(cfg.dataWidth.W)))
  for (beat <- 0 until beats) {
    completedBeats(beat) := Mux(
      mshrBeatIndex(receivingIdx) === beat.U,
      io.axiReadResp.bits.data,
      mshrBeats(receivingIdx)(beat)
    )
  }
  private val completedLine = completedBeats.asUInt

  io.perf.access         := requestFire
  io.perf.hit            := requestFire && hit
  io.perf.miss           := requestFire && !hit
  io.perf.bypass         := false.B
  io.perf.mshrAlloc      := requestAllocate
  io.perf.mshrMerge      := requestMerge
  io.perf.mshrFullStall  := io.req.valid && !hit && !mshrMatch && !requestCanAllocate
  io.perf.hitUnderMiss   := requestFire && hit && activeMshr
  io.perf.queuedMiss     := requestAllocate && activeMshr
  io.perf.refillStart    := io.axiReadReq.fire
  io.perf.refillComplete := io.axiReadResp.fire && refillLast
  io.perf.refillFault    := io.axiReadResp.fire && refillLast && refillFault
  io.perf.mshrOccupancy  := PopCount(mshrValid)

  when(requestFire && hit) {
    hitRespValid  := true.B
    hitResp.data  := Mux(io.req.bits.request.write, 0.U, lineDataAt(hitLine, incomingWaiter.byteOffset))
    hitResp.fault := false.B
    hitResp.txnId := io.req.bits.request.txnId
    hitRespOwner  := io.req.bits.owner

    when(io.req.bits.request.write) {
      dataArray(reqSet)(hitWay)  := mergeStore(hitLine, incomingWaiter.byteOffset, incomingWaiter.wdata, incomingWaiter.wmask)
      dirtyArray(reqSet)(hitWay) := true.B
    }
  }

  when(requestAllocate) {
    mshrValid(freeMshrIdx)         := true.B
    mshrState(freeMshrIdx)         := Mux(victimDirty, mshrEvicting, mshrQueued)
    mshrBlockAddr(freeMshrIdx)     := reqBlockAddr
    mshrSet(freeMshrIdx)           := reqSet
    mshrWay(freeMshrIdx)           := victimWay
    mshrAxiAuthorized(freeMshrIdx) := mayIssueAxi(io.req.bits.owner)
    mshrBeatIndex(freeMshrIdx)     := 0.U
    mshrFault(freeMshrIdx)         := false.B
    mshrWaiterCount(freeMshrIdx)   := 1.U
    mshrResponseIdx(freeMshrIdx)   := 0.U
    mshrEvictAddr(freeMshrIdx)     := lineAddr(tagArray(reqSet)(victimWay), reqSet)
    mshrEvictData(freeMshrIdx)     := dataArray(reqSet)(victimWay)
    mshrWriteBeat(freeMshrIdx)     := 0.U
    mshrWriteAwaitResp(freeMshrIdx) := false.B
    mshrWritebackStarted(freeMshrIdx) := false.B

    for (waiter <- 0 until cfg.waitersPerMshr) {
      mshrWaiters(freeMshrIdx)(waiter) := 0.U.asTypeOf(new DCacheWaiter(cfg, robIdxWidth))
    }
    mshrWaiters(freeMshrIdx)(0) := incomingWaiter

    validArray(reqSet)(victimWay) := false.B
    dirtyArray(reqSet)(victimWay) := false.B
  }

  when(requestMerge) {
    val waiterIndex = mshrWaiterCount(mshrMatchIdx)(waiterIdxWidth - 1, 0)
    mshrWaiterCount(mshrMatchIdx)           := mshrWaiterCount(mshrMatchIdx) + 1.U
    mshrWaiters(mshrMatchIdx)(waiterIndex)  := incomingWaiter
  }

  when(io.axiReadReq.fire) {
    mshrState(queuedIdx)     := mshrReceiving
    mshrBeatIndex(queuedIdx) := 0.U
  }

  when(io.axiReadResp.fire) {
    mshrBeats(receivingIdx)(mshrBeatIndex(receivingIdx)) := io.axiReadResp.bits.data
    mshrFault(receivingIdx)                              := refillFault

    when(refillLast) {
      val discardRefill = mshrWaiterCount(receivingIdx) === 0.U ||
        ((io.flush || io.recover.valid) && retainedWaiterCount(receivingIdx) === 0.U)
      when(discardRefill) {
        mshrValid(receivingIdx) := false.B
      }.otherwise {
        mshrState(receivingIdx)       := mshrResponding
        mshrResponseIdx(receivingIdx) := 0.U
      }
      when(!refillFault) {
        validArray(mshrSet(receivingIdx))(mshrWay(receivingIdx)) := true.B
        dirtyArray(mshrSet(receivingIdx))(mshrWay(receivingIdx)) := false.B
        tagArray(mshrSet(receivingIdx))(mshrWay(receivingIdx))   := tag(mshrBlockAddr(receivingIdx))
        dataArray(mshrSet(receivingIdx))(mshrWay(receivingIdx))  := completedLine
        rrWay(mshrSet(receivingIdx)) := Mux(
          mshrWay(receivingIdx) === (cfg.ways - 1).U,
          0.U,
          mshrWay(receivingIdx) + 1.U
        )
      }
    }.otherwise {
      mshrBeatIndex(receivingIdx) := mshrBeatIndex(receivingIdx) + 1.U
    }
  }

  when(io.resp.fire) {
    when(hitResponseVisible) {
      hitRespValid := false.B
    }.elsewhen(mshrResponseVisible) {
      when(respondingWaiter.write && !mshrFault(respondingIdx)) {
        val updatedLine = mergeStore(
          respondingLine,
          respondingWaiter.byteOffset,
          respondingWaiter.wdata,
          respondingWaiter.wmask
        )
        dataArray(mshrSet(respondingIdx))(mshrWay(respondingIdx))  := updatedLine
        dirtyArray(mshrSet(respondingIdx))(mshrWay(respondingIdx)) := true.B
        for (beat <- 0 until beats) {
          mshrBeats(respondingIdx)(beat) := updatedLine((beat + 1) * cfg.dataWidth - 1, beat * cfg.dataWidth)
        }
      }

      val nextResponse = mshrResponseIdx(respondingIdx) +& 1.U
      when(nextResponse === mshrWaiterCount(respondingIdx)) {
        mshrValid(respondingIdx) := false.B
      }.otherwise {
        mshrResponseIdx(respondingIdx) := nextResponse(waiterIdxWidth - 1, 0)
      }
    }
  }

  when(io.axiWriteReq.fire) {
    when(writebackFromMaintenance) {
      maintenanceWriteAwaitResp := true.B
    }.elsewhen(writebackFromEviction) {
      mshrWriteAwaitResp(evictWriteIdx) := true.B
      mshrWritebackStarted(evictWriteIdx) := true.B
    }
  }

  when(io.axiWriteResp.fire) {
    when(maintenanceWriteAwaitResp) {
      maintenanceWriteAwaitResp := false.B
      when(maintenanceWriteBeat === lastBeat) {
        maintenanceWriteActive := false.B
        maintenanceWriteBeat   := 0.U
      }.otherwise {
        maintenanceWriteBeat := maintenanceWriteBeat + 1.U
      }
    }.elsewhen(hasEvictAwait) {
      mshrWriteAwaitResp(evictAwaitIdx) := false.B
      when(io.axiWriteResp.bits.resp =/= AxiResp.okay) {
        mshrFault(evictAwaitIdx) := true.B
      }
      when(mshrWriteBeat(evictAwaitIdx) === lastBeat) {
        val noWaitersAfterControl =
          (io.flush || io.recover.valid) && retainedWaiterCount(evictAwaitIdx) === 0.U
        when(mshrWaiterCount(evictAwaitIdx) === 0.U || noWaitersAfterControl) {
          mshrValid(evictAwaitIdx) := false.B
        }.otherwise {
          mshrState(evictAwaitIdx)     := mshrQueued
          mshrWriteBeat(evictAwaitIdx) := 0.U
        }
      }.otherwise {
        mshrWriteBeat(evictAwaitIdx) := mshrWriteBeat(evictAwaitIdx) + 1.U
      }
    }
  }

  when(io.cleanInvalidate.valid && maintenanceCanInspect && maintenanceHit && maintenanceDirty) {
    maintenanceWriteActive    := true.B
    maintenanceWriteAddr      := lineAddr(tagArray(maintenanceSet)(maintenanceWay), maintenanceSet)
    maintenanceWriteData      := dataArray(maintenanceSet)(maintenanceWay)
    maintenanceWriteBeat      := 0.U
    maintenanceWriteAwaitResp := false.B
    validArray(maintenanceSet)(maintenanceWay) := false.B
    dirtyArray(maintenanceSet)(maintenanceWay) := false.B
  }.elsewhen(io.cleanInvalidate.fire && maintenanceHit) {
    validArray(maintenanceSet)(maintenanceWay) := false.B
    dirtyArray(maintenanceSet)(maintenanceWay) := false.B
  }

  when(io.flush || io.recover.valid) {
    when(hitRespValid && ownerKilled(hitRespOwner)) {
      hitRespValid := false.B
    }

    for (entry <- 0 until cfg.mshrEntries) {
      for (waiter <- 0 until cfg.waitersPerMshr) {
        mshrWaiters(entry)(waiter) := retainedWaiters(entry)(waiter)
      }
      mshrWaiterCount(entry) := retainedWaiterCount(entry)
      mshrResponseIdx(entry) := 0.U

      val noRetainedWaiters = retainedWaiterCount(entry) === 0.U
      val restoreUnstartedEviction = mshrValid(entry) && noRetainedWaiters &&
        mshrState(entry) === mshrEvicting && !mshrWritebackStarted(entry)

      // The victim has been removed from the arrays, but no writeback beat has
      // reached AXI yet. A recovered request can therefore restore it exactly
      // and leave no externally visible effect.
      when(restoreUnstartedEviction) {
        validArray(mshrSet(entry))(mshrWay(entry)) := true.B
        dirtyArray(mshrSet(entry))(mshrWay(entry)) := true.B
        tagArray(mshrSet(entry))(mshrWay(entry))   := tag(mshrEvictAddr(entry))
        dataArray(mshrSet(entry))(mshrWay(entry))  := mshrEvictData(entry)
        mshrValid(entry) := false.B
      }
      when(mshrValid(entry) && noRetainedWaiters &&
        (mshrState(entry) === mshrQueued || mshrState(entry) === mshrResponding)) {
        mshrValid(entry) := false.B
      }
      when(mshrValid(entry) && noRetainedWaiters && mshrState(entry) === mshrReceiving &&
        io.axiReadResp.fire && receivingIdx === entry.U && refillLast) {
        mshrValid(entry) := false.B
      }
    }
  }

  when(io.axiReadReq.fire) {
    assert(mshrAxiAuthorized(queuedIdx), "DCache refill must originate from an authorized request")
    assert(mshrWaiterCount(queuedIdx) =/= 0.U, "DCache refill requires a live waiter")
    assert(!io.flush && !io.recover.valid, "DCache refill must not launch during recovery")
  }
  when(io.req.fire && io.req.bits.request.write) {
    assert(!io.req.bits.owner.squashable, "speculative stores must not update the DCache")
  }
  assert(PopCount(mshrWriteAwaitResp) <= 1.U, "only one DCache writeback may await a response")
}
