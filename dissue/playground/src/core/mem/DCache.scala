package top.core.mem

import chisel3._
import chisel3.util.{Cat, Decoupled, Fill, Mux1H, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.bus.axi.{AxiBurst, AxiResp}
import top.config.{DCacheConfig, MemConfig}
import top.core.bundle.{DataMemOwner, DataMemReq, DataMemResp, DataMemTxn, OwnedDataMemReq, RobAge, RobRecovery}
import top.core.mem.bundle.{AxiMasterReadReq, AxiMasterReadResp, AxiMasterWriteReq, AxiMasterWriteResp}

class DCacheWaiter(cfg: DCacheConfig, robIdxWidth: Int) extends Bundle {
  val valid      = Bool()
  val txnId      = UInt(top.core.bundle.DataMemTxn.width.W)
  val byteOffset = UInt(cfg.offsetBits.W)
  val size       = UInt(3.W)
  val unsigned   = Bool()
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

/** A write-through, no-write-allocate data cache.
  *
  * One AXI refill can be active at a time. MSHRs still retain a second miss so tag hits can complete while the active
  * refill waits for memory.
  */
class DCache(
  cfg:        DCacheConfig = DCacheConfig(),
  memCfg:     MemConfig = MemConfig(),
  robEntries: Int = 16)
    extends Module {
  require(cfg.addrWidth == memCfg.addrWidth, "DCache and memory address widths must match")
  require(cfg.dataWidth == memCfg.axiDataWidth, "DCache and AXI data widths must match")

  private val robIdxWidth = math.max(chisel3.util.log2Ceil(robEntries), 1)

  private val dataBytes        = cfg.dataWidth / 8
  private val beats            = cfg.beatCount
  private val beatIdxWidth     = math.max(chisel3.util.log2Ceil(beats), 1)
  private val waiterIdxWidth   = math.max(chisel3.util.log2Ceil(cfg.waitersPerMshr), 1)
  private val waiterCountWidth = math.max(chisel3.util.log2Ceil(cfg.waitersPerMshr + 1), 1)
  private val mshrIdxWidth     = math.max(chisel3.util.log2Ceil(cfg.mshrEntries), 1)

  private val mshrQueued     = 0.U(2.W)
  private val mshrReceiving  = 1.U(2.W)
  private val mshrResponding = 2.U(2.W)

  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.dataWidth, robIdxWidth)))
    val resp = Decoupled(new DataMemResp(cfg.dataWidth))

    val flush   = Input(Bool())
    val recover = Input(new RobRecovery(robIdxWidth))
    val robHead = Input(UInt(robIdxWidth.W))
    val cancel  = Output(Vec(DCache.cancelPorts(cfg), Valid(UInt(DataMemTxn.width.W))))

    val axiReadReq   = Decoupled(new AxiMasterReadReq(memCfg.addrWidth, memCfg.axiIdWidth))
    val axiReadResp  = Flipped(Decoupled(new AxiMasterReadResp(memCfg.axiDataWidth, memCfg.axiIdWidth)))
    val axiWriteReq  = Decoupled(new AxiMasterWriteReq(memCfg.addrWidth, memCfg.axiDataWidth, memCfg.axiIdWidth))
    val axiWriteResp = Flipped(Decoupled(new AxiMasterWriteResp(memCfg.axiIdWidth)))

    val invalidate = Flipped(Valid(UInt(cfg.addrWidth.W)))
    val perf       = Output(new DCachePerf(cfg))
  })

  private def setIndex(addr: UInt): UInt = {
    if (cfg.indexBits == 0) 0.U(cfg.setIdxBits.W)
    else addr(cfg.offsetBits + cfg.indexBits - 1, cfg.offsetBits)
  }

  private def tag(addr: UInt): UInt =
    addr(cfg.addrWidth - 1, cfg.offsetBits + cfg.indexBits)

  private def blockAddr(addr: UInt): UInt =
    addr & ~((cfg.lineBytes - 1).U(cfg.addrWidth.W))

  private def lineDataAt(data: UInt, byteOffset: UInt): UInt =
    (data >> (byteOffset << 3))(cfg.dataWidth - 1, 0)

  private val validArray = RegInit(VecInit(Seq.fill(cfg.sets)(VecInit(Seq.fill(cfg.ways)(false.B)))))
  private val tagArray   = Reg(Vec(cfg.sets, Vec(cfg.ways, UInt(cfg.tagBits.W))))
  private val dataArray  = Reg(Vec(cfg.sets, Vec(cfg.ways, UInt(cfg.blockBits.W))))
  private val rrWay      = RegInit(VecInit(Seq.fill(cfg.sets)(0.U(cfg.wayIdxBits.W))))

  private val mshrValid       = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))
  private val mshrState       = Reg(Vec(cfg.mshrEntries, UInt(2.W)))
  private val mshrBlockAddr   = Reg(Vec(cfg.mshrEntries, UInt(cfg.addrWidth.W)))
  private val mshrSet         = Reg(Vec(cfg.mshrEntries, UInt(cfg.setIdxBits.W)))
  private val mshrWay         = Reg(Vec(cfg.mshrEntries, UInt(cfg.wayIdxBits.W)))
  private val mshrBeatIndex   = Reg(Vec(cfg.mshrEntries, UInt(beatIdxWidth.W)))
  private val mshrBeatMask    = Reg(Vec(cfg.mshrEntries, UInt(beats.W)))
  private val mshrFault       = RegInit(VecInit(Seq.fill(cfg.mshrEntries)(false.B)))
  private val mshrBeats       = Reg(Vec(cfg.mshrEntries, Vec(beats, UInt(cfg.dataWidth.W))))
  private val mshrWaiters     = Reg(Vec(cfg.mshrEntries, Vec(cfg.waitersPerMshr, new DCacheWaiter(cfg, robIdxWidth))))
  private val mshrWaiterCount = Reg(Vec(cfg.mshrEntries, UInt(waiterCountWidth.W)))
  private val mshrResponseIdx = Reg(Vec(cfg.mshrEntries, UInt(waiterIdxWidth.W)))

  private val hitRespValid = RegInit(false.B)
  private val hitResp      = Reg(new DataMemResp(cfg.dataWidth))
  private val hitRespOwner = Reg(new DataMemOwner(robIdxWidth))

  private val storePending = RegInit(false.B)
  private val storeSent    = RegInit(false.B)
  private val storeReq     = Reg(new DataMemReq(cfg.addrWidth, cfg.dataWidth))

  private def ownerKilled(owner: DataMemOwner): Bool =
    owner.squashable && (io.flush ||
      (io.recover.valid && RobAge.isYounger(owner.robIdx, io.recover.robIdx, io.robHead, robEntries, robIdxWidth)))

  io.cancel(0).valid := hitRespValid && ownerKilled(hitRespOwner) && DataMemTxn.isLoad(hitResp.txnId)
  io.cancel(0).bits  := hitResp.txnId
  for (entry <- 0 until cfg.mshrEntries) {
    for (waiter <- 0 until cfg.waitersPerMshr) {
      val cancelPort = 1 + entry * cfg.waitersPerMshr + waiter
      val canceledWaiter = mshrWaiters(entry)(waiter)
      val waiterLive = mshrValid(entry) && waiter.U < mshrWaiterCount(entry) && canceledWaiter.valid
      io.cancel(cancelPort).valid := waiterLive && ownerKilled(canceledWaiter.owner) &&
        DataMemTxn.isLoad(canceledWaiter.txnId)
      io.cancel(cancelPort).bits := canceledWaiter.txnId
    }
  }

  private val retainedWaiterCount = Wire(Vec(cfg.mshrEntries, UInt(waiterCountWidth.W)))
  private val retainedWaiters = Wire(
    Vec(cfg.mshrEntries, Vec(cfg.waitersPerMshr, new DCacheWaiter(cfg, robIdxWidth)))
  )

  for (entry <- 0 until cfg.mshrEntries) {
    val keep = Wire(Vec(cfg.waitersPerMshr, Bool()))
    for (waiter <- 0 until cfg.waitersPerMshr) {
      val waiterLive = mshrValid(entry) && waiter.U < mshrWaiterCount(entry) && mshrWaiters(entry)(waiter).valid
      keep(waiter) := waiterLive && !ownerKilled(mshrWaiters(entry)(waiter).owner)
    }
    retainedWaiterCount(entry) := PopCount(keep)

    for (destination <- 0 until cfg.waitersPerMshr) {
      val sourceOH = Wire(Vec(cfg.waitersPerMshr, Bool()))
      for (source <- 0 until cfg.waitersPerMshr) {
        val earlierCount = if (source == 0) 0.U else PopCount(keep.take(source))
        sourceOH(source) := keep(source) && earlierCount === destination.U
      }
      retainedWaiters(entry)(destination) := Mux1H(sourceOH, mshrWaiters(entry))
    }
  }

  private val reqSet       = setIndex(io.req.bits.request.addr)
  private val reqTag       = tag(io.req.bits.request.addr)
  private val reqBlockAddr = blockAddr(io.req.bits.request.addr)
  private val wayHits      = VecInit((0 until cfg.ways).map { way =>
    validArray(reqSet)(way) && tagArray(reqSet)(way) === reqTag
  })
  private val hitOH        = wayHits.asUInt
  private val hit          = hitOH.orR
  private val hitWay       = OHToUInt(hitOH)
  private val hitLineData  = Mux1H(wayHits, dataArray(reqSet))

  private val mshrMatchOH      = VecInit((0 until cfg.mshrEntries).map { entry =>
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

  private val invalidWayOH = VecInit((0 until cfg.ways).map { way =>
    !reservedWay(way) && !validArray(reqSet)(way)
  }).asUInt
  private val rrWayOH      = VecInit((0 until cfg.ways).map { way =>
    !reservedWay(way) && rrWay(reqSet) === way.U
  }).asUInt
  private val anyWayOH     = VecInit((0 until cfg.ways).map(way => !reservedWay(way))).asUInt
  private val victimOH     = Mux(
    invalidWayOH.orR,
    PriorityEncoderOH(invalidWayOH),
    Mux(rrWayOH.orR, rrWayOH, PriorityEncoderOH(anyWayOH))
  )
  private val hasVictim    = victimOH.orR
  private val victimWay    = OHToUInt(victimOH)

  private val freeMshrOH  = VecInit(mshrValid.map(!_)).asUInt
  private val hasFreeMshr = freeMshrOH.orR
  private val freeMshrIdx = OHToUInt(freeMshrOH)

  private val respondingOH     = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrResponding && mshrWaiterCount(entry) =/= 0.U
  }).asUInt
  private val hasResponding    = respondingOH.orR
  private val respondingIdx    = OHToUInt(respondingOH)
  private val respondingWaiter = mshrWaiters(respondingIdx)(mshrResponseIdx(respondingIdx))
  private val respondingLine   = mshrBeats(respondingIdx).asUInt

  private val storeResponseReady = storePending && storeSent && io.axiWriteResp.valid
  private val hitResponseVisible = hitRespValid && !io.flush && !io.recover.valid && !ownerKilled(hitRespOwner)
  private val mshrResponseVisible = hasResponding && !io.flush && !io.recover.valid && !ownerKilled(respondingWaiter.owner)
  private val storeResponseVisible = storeResponseReady && !hitResponseVisible && !mshrResponseVisible
  private val responseBusy       = hitRespValid || hasResponding || storeResponseReady
  private val readCanAllocate    = hasFreeMshr && hasVictim
  private val readReady          = Mux(hit, true.B, Mux(mshrMatch, matchWaiterSpace, readCanAllocate))
  private val writeReady         = !storePending && !mshrMatch
  io.req.ready := !io.flush && !io.recover.valid && !responseBusy && Mux(io.req.bits.request.write, writeReady, readReady)

  private val requestFire     = io.req.fire
  private val requestLoad     = requestFire && !io.req.bits.request.write
  private val requestMiss     = requestLoad && !hit
  private val requestMerge    = requestLoad && !hit && mshrMatch
  private val requestAllocate = requestLoad && !hit && !mshrMatch
  private val activeMshr      = mshrValid.asUInt.orR

  io.resp.valid := hitResponseVisible || mshrResponseVisible || storeResponseVisible
  io.resp.bits  := 0.U.asTypeOf(new DataMemResp(cfg.dataWidth))
  when(hitResponseVisible) {
    io.resp.bits := hitResp
  }.elsewhen(mshrResponseVisible) {
    io.resp.bits.data  := Mux(
      mshrFault(respondingIdx),
      0.U,
      lineDataAt(respondingLine, respondingWaiter.byteOffset)
    )
    io.resp.bits.fault := mshrFault(respondingIdx)
    io.resp.bits.txnId := respondingWaiter.txnId
  }.otherwise {
    io.resp.bits.data  := 0.U
    io.resp.bits.fault := io.axiWriteResp.bits.resp =/= AxiResp.okay
    io.resp.bits.txnId := storeReq.txnId
  }

  private val queuedOH     = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrQueued
  }).asUInt
  private val hasQueued    = queuedOH.orR
  private val queuedIdx    = OHToUInt(queuedOH)
  private val receivingOH  = VecInit((0 until cfg.mshrEntries).map { entry =>
    mshrValid(entry) && mshrState(entry) === mshrReceiving
  }).asUInt
  private val hasReceiving = receivingOH.orR
  private val receivingIdx = OHToUInt(receivingOH)

  io.axiReadReq.valid      := hasQueued && !hasReceiving && !io.flush && !io.recover.valid
  io.axiReadReq.bits.addr  := mshrBlockAddr(queuedIdx)
  io.axiReadReq.bits.id    := 2.U(memCfg.axiIdWidth.W)
  io.axiReadReq.bits.len   := (beats - 1).U
  io.axiReadReq.bits.size  := chisel3.util.log2Ceil(dataBytes).U
  io.axiReadReq.bits.burst := AxiBurst.incr

  io.axiReadResp.ready := hasReceiving

  private val storeOffset      = storeReq.addr(math.max(chisel3.util.log2Ceil(dataBytes), 1) - 1, 0)
  private val shiftedStoreData = (storeReq.wdata << (storeOffset << 3))(cfg.dataWidth - 1, 0)
  private val shiftedStoreMask = (storeReq.wmask << storeOffset)(dataBytes - 1, 0)

  io.axiWriteReq.valid      := storePending && !storeSent
  io.axiWriteReq.bits.addr  := storeReq.addr
  io.axiWriteReq.bits.id    := 2.U(memCfg.axiIdWidth.W)
  io.axiWriteReq.bits.len   := 0.U
  io.axiWriteReq.bits.size  := storeReq.size
  io.axiWriteReq.bits.burst := AxiBurst.incr
  io.axiWriteReq.bits.data  := shiftedStoreData
  io.axiWriteReq.bits.strb  := shiftedStoreMask
  io.axiWriteReq.bits.last  := true.B
  io.axiWriteResp.ready     := storeResponseVisible && io.resp.ready

  private val refillFault    = mshrFault(receivingIdx) || io.axiReadResp.bits.resp =/= AxiResp.okay
  private val refillLast     = io.axiReadResp.bits.last || mshrBeatIndex(receivingIdx) === (beats - 1).U
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
  io.perf.mshrFullStall  := io.req.valid && !io.req.bits.request.write && !hit && !mshrMatch && !readCanAllocate
  io.perf.hitUnderMiss   := requestFire && hit && activeMshr
  io.perf.queuedMiss     := requestAllocate && activeMshr
  io.perf.refillStart    := io.axiReadReq.fire
  io.perf.refillComplete := io.axiReadResp.fire && refillLast
  io.perf.refillFault    := io.axiReadResp.fire && refillLast && refillFault
  io.perf.mshrOccupancy  := PopCount(mshrValid)

  when(io.invalidate.valid) {
    val invalidateSet = setIndex(io.invalidate.bits)
    val invalidateTag = tag(io.invalidate.bits)
    for (way <- 0 until cfg.ways) {
      when(validArray(invalidateSet)(way) && tagArray(invalidateSet)(way) === invalidateTag) {
        validArray(invalidateSet)(way) := false.B
      }
    }
  }

  when(requestFire && hit && !io.req.bits.request.write) {
    hitRespValid  := true.B
    hitResp.data  := lineDataAt(hitLineData, io.req.bits.request.addr(cfg.offsetBits - 1, 0))
    hitResp.fault := false.B
    hitResp.txnId := io.req.bits.request.txnId
    hitRespOwner  := io.req.bits.owner
  }

  when(requestFire && io.req.bits.request.write) {
    storePending := true.B
    storeSent    := false.B
    storeReq     := io.req.bits.request

    when(hit) {
      val lineOffset   = io.req.bits.request.addr(cfg.offsetBits - 1, 0)
      val lineMask     = (io.req.bits.request.wmask << lineOffset)(cfg.lineBytes - 1, 0)
      val lineData     = (io.req.bits.request.wdata << (lineOffset << 3))(cfg.blockBits - 1, 0)
      val expandedMask = Cat((0 until cfg.lineBytes).reverse.map(byte => Fill(8, lineMask(byte))))
      dataArray(reqSet)(hitWay) := (hitLineData & ~expandedMask) | (lineData & expandedMask)
    }
  }

  when(requestAllocate) {
    mshrValid(freeMshrIdx)                 := true.B
    mshrState(freeMshrIdx)                 := mshrQueued
    mshrBlockAddr(freeMshrIdx)             := reqBlockAddr
    mshrSet(freeMshrIdx)                   := reqSet
    mshrWay(freeMshrIdx)                   := victimWay
    mshrBeatIndex(freeMshrIdx)             := 0.U
    mshrBeatMask(freeMshrIdx)              := 0.U
    mshrFault(freeMshrIdx)                 := false.B
    mshrWaiterCount(freeMshrIdx)           := 1.U
    mshrResponseIdx(freeMshrIdx)           := 0.U
    mshrWaiters(freeMshrIdx)(0).valid      := true.B
    mshrWaiters(freeMshrIdx)(0).txnId      := io.req.bits.request.txnId
    mshrWaiters(freeMshrIdx)(0).byteOffset := io.req.bits.request.addr(cfg.offsetBits - 1, 0)
    mshrWaiters(freeMshrIdx)(0).size       := io.req.bits.request.size
    mshrWaiters(freeMshrIdx)(0).unsigned   := io.req.bits.request.unsigned
    mshrWaiters(freeMshrIdx)(0).owner      := io.req.bits.owner
    validArray(reqSet)(victimWay)          := false.B
  }

  when(requestMerge) {
    val waiterIndex = mshrWaiterCount(mshrMatchIdx)(waiterIdxWidth - 1, 0)
    mshrWaiterCount(mshrMatchIdx)                     := mshrWaiterCount(mshrMatchIdx) + 1.U
    mshrWaiters(mshrMatchIdx)(waiterIndex).valid      := true.B
    mshrWaiters(mshrMatchIdx)(waiterIndex).txnId      := io.req.bits.request.txnId
    mshrWaiters(mshrMatchIdx)(waiterIndex).byteOffset := io.req.bits.request.addr(cfg.offsetBits - 1, 0)
    mshrWaiters(mshrMatchIdx)(waiterIndex).size       := io.req.bits.request.size
    mshrWaiters(mshrMatchIdx)(waiterIndex).unsigned   := io.req.bits.request.unsigned
    mshrWaiters(mshrMatchIdx)(waiterIndex).owner      := io.req.bits.owner
  }

  when(io.axiReadReq.fire) {
    mshrState(queuedIdx)     := mshrReceiving
    mshrBeatIndex(queuedIdx) := 0.U
  }

  when(io.axiReadResp.fire) {
    mshrBeats(receivingIdx)(mshrBeatIndex(receivingIdx)) := io.axiReadResp.bits.data
    mshrBeatMask(receivingIdx)                           := mshrBeatMask(receivingIdx) | (1.U(beats.W) << mshrBeatIndex(receivingIdx))
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
        tagArray(mshrSet(receivingIdx))(mshrWay(receivingIdx))   := tag(mshrBlockAddr(receivingIdx))
        dataArray(mshrSet(receivingIdx))(mshrWay(receivingIdx))  := completedLine
        rrWay(mshrSet(receivingIdx))                             := Mux(
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
      val nextResponse = mshrResponseIdx(respondingIdx) +& 1.U
      when(nextResponse === mshrWaiterCount(respondingIdx)) {
        mshrValid(respondingIdx) := false.B
      }.otherwise {
        mshrResponseIdx(respondingIdx) := nextResponse(waiterIdxWidth - 1, 0)
      }
    }.otherwise {
      storePending := false.B
      storeSent    := false.B
    }
  }

  when(io.axiWriteReq.fire) {
    storeSent := true.B
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
}
