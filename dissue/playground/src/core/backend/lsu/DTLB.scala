package top.core.backend.lsu

import chisel3._
import chisel3.util.{Cat, Decoupled, Mux1H, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.config.BackendConfig
import top.core.backend.bundle._
import top.core.backend.exception.ExceptionInfo
import top.core.mmu.{MmuTranslateReq, MmuTranslateResp}
import top.core.monitor.TlbMonitor
import top.core.bundle.{RobAge, RobRecovery}

class DtlbIO(cfg: BackendConfig = BackendConfig()) extends Bundle {
  // LSU side: one pipelined lookup per cycle. A miss is answered with
  // `deferred` and its final translation arrives on `complete` later.
  val req  = Flipped(Decoupled(new MmuTranslateReq(cfg)))
  val resp = Decoupled(new MmuTranslateResp(cfg))

  // Asynchronous completion for a deferred lookup. The replay queue in the LSU
  // owns the matching entry; unmatched completions are protocol bugs.
  val complete = Valid(new MmuTranslateResp(cfg))

  // walker side
  val missReq    = Decoupled(new MmuTranslateReq(cfg))
  val refill     = Flipped(Decoupled(new TlbRefill(cfg)))
  val walkFlush  = Output(Bool())
  val walkRobIdx = Output(UInt(cfg.robIdxWidth.W))
  val idle       = Output(Bool())

  // invalidation / control
  val sfence  = Input(Valid(new TlbSfence(cfg)))
  val flush   = Input(Bool())
  val recover = Input(new RobRecovery(cfg.robIdxWidth))
  val robHead = Input(UInt(cfg.robIdxWidth.W))

  // read-only performance observation
  val monitor = Output(new TlbMonitor(cfg))
}

/** One deferred lookup waiting for the single Sv32 walker. */
class DtlbMissEntry(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val req    = new MmuTranslateReq(cfg)
  val victim = UInt(cfg.dtlbIdxWidth.W)
}

/** Data TLB with a pipelined hit path and a non-blocking miss queue.
  *
  * Lookups are always answered on the next cycle: a hit carries the physical address, a miss carries `deferred`. The
  * miss queue holds the original request plus a reserved victim entry; the single walker drains it in order and returns
  * the final translation on `complete`, tagged with the request identity. Hits keep flowing while misses are walking.
  * Duplicate misses for the same VPN are allowed: the fill path evicts overlapping entries, so two walks can never
  * leave two matching tags in the array.
  */
class DTLB(cfg: BackendConfig = BackendConfig(), enableMonitor: Boolean = false) extends Module {
  private val idxWidth       = cfg.dtlbIdxWidth
  private val missCount      = cfg.dtlbMissQueueEntries
  private val missIdxWidth   = cfg.dtlbMissQueueIdxWidth
  private val missCountWidth = cfg.dtlbMissQueueCountWidth

  val io = IO(new DtlbIO(cfg))

  private val array      = Module(new DtlbArray(cfg))
  private val permission = Module(new DtlbPermissionCheck(cfg))

  private val walkPending = RegInit(false.B)
  private val walkEntry   = RegInit(0.U.asTypeOf(new DtlbMissEntry(cfg)))

  // ---------------------------------------------------------------- data path

  array.io.lookupVaddr := io.req.bits.vaddr

  private val fillEntry = Wire(new DtlbEntry(cfg))
  fillEntry       := 0.U.asTypeOf(new DtlbEntry(cfg))
  fillEntry.valid := true.B
  fillEntry.vpn   := walkEntry.req.vaddr(cfg.addrWidth - 1, 12)
  fillEntry.ppn   := io.refill.bits.pte(31, 10)
  fillEntry.level := io.refill.bits.level
  fillEntry.r     := io.refill.bits.pte(1)
  fillEntry.w     := io.refill.bits.pte(2)
  fillEntry.x     := io.refill.bits.pte(3)
  fillEntry.u     := io.refill.bits.pte(4)
  fillEntry.g     := io.refill.bits.pte(5)
  fillEntry.a     := io.refill.bits.pte(6)
  fillEntry.d     := io.refill.bits.pte(7)

  // The same checker serves lookup hits and the refill path. On refill it validates the PTE that is about to be
  // installed, so a malformed walker response cannot turn into a permission-faulting hit.
  permission.io.entry   := Mux(io.refill.valid, fillEntry, array.io.lookupEntry)
  permission.io.access  := Mux(io.refill.valid, walkEntry.req.access, io.req.bits.access)
  permission.io.priv    := Mux(io.refill.valid, walkEntry.req.priv, io.req.bits.priv)
  permission.io.mstatus := Mux(io.refill.valid, walkEntry.req.mstatus, io.req.bits.mstatus)
  permission.io.vaddr   := Mux(io.refill.valid, walkEntry.req.vaddr, io.req.bits.vaddr)

  private val hitPaddr        = DtlbAddress(array.io.lookupEntry, io.req.bits.vaddr, cfg.addrWidth)
  private val hitException    = permission.io.exception
  private val refillException = Mux(
    io.refill.bits.fill,
    ExceptionInfo.keepFirst(io.refill.bits.exception, permission.io.exception, cfg),
    io.refill.bits.exception
  )

  // ---- miss queue -----------------------------------------------------------

  private val missEntries   = Reg(Vec(missCount, new DtlbMissEntry(cfg)))
  private val missHead      = RegInit(0.U(missIdxWidth.W))
  private val missTail      = RegInit(0.U(missIdxWidth.W))
  private val missOccupancy = RegInit(0.U(missCountWidth.W))

  private def idxPlus(base: UInt, offset: UInt): UInt = {
    val width = math.max(base.getWidth, offset.getWidth) + 1
    val sum   = base.pad(width) + offset.pad(width)
    Mux(sum >= missCount.U, sum - missCount.U, sum)(missIdxWidth - 1, 0)
  }

  private def logicalIdx(offset: UInt): UInt = idxPlus(missHead, offset)

  private val headValid  = missOccupancy =/= 0.U
  private val headEntry  = missEntries(missHead)
  private val lookupMiss = !array.io.lookupHit || array.io.lookupMultiple

  // Each queued miss owns a distinct victim, so multiple walks can complete in
  // any order without two fills targeting the same entry.
  private val reservedVictims = RegInit(VecInit(Seq.fill(cfg.dtlbEntries)(false.B)))
  private val freeVictimOH    = PriorityEncoderOH(~reservedVictims.asUInt)
  private val chosenVictim    = Mux(!reservedVictims(array.io.victim), array.io.victim, OHToUInt(freeVictimOH))

  // ------------------------------------------------------------ lookup response

  private val respValid = RegInit(false.B)
  private val respReg   = Reg(new MmuTranslateResp(cfg))
  private val respFire  = respValid && io.resp.ready

  // A fill completes in this cycle and frees a queue slot, so a miss lookup may
  // be accepted even when the queue is otherwise full.
  private val missPopFire = walkPending && io.refill.ready && io.refill.valid

  private val canEnqueueMiss =
    (missOccupancy < missCount.U || missPopFire) && freeVictimOH.orR

  io.req.ready := !io.flush && !io.sfence.valid && !io.recover.valid &&
    (!respValid || respFire) && (!lookupMiss || canEnqueueMiss)

  io.resp.valid := respValid
  io.resp.bits  := respReg

  // The walker can accept a new request in the same cycle it returns the final
  // response. Deassert missReq during a refill so the walker cannot re-accept
  // the same request and leave a stale response for the next miss.
  io.missReq.valid := !walkPending && headValid && !io.flush && !io.sfence.valid && !io.recover.valid
  io.missReq.bits  := headEntry.req

  io.refill.ready := walkPending && !io.flush && !io.sfence.valid && !io.recover.valid
  io.walkRobIdx   := Mux(walkPending, walkEntry.req.robIdx, headEntry.req.robIdx)
  io.idle         := !walkPending && !headValid && !respValid
  io.walkFlush    := io.flush || io.sfence.valid ||
    (io.recover.valid && walkPending &&
      RobAge.isYounger(walkEntry.req.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth))

  // Invalidate is one event channel: `valid` means an invalidation happens this cycle, while `bits` carries its
  // architectural scope (all, by VPN, or by ASID). A bare Bool cannot express a selective SFENCE.VMA.
  private val invalidateAll = Wire(new TlbSfence(cfg))
  invalidateAll.useVaddr := false.B
  invalidateAll.useAsid  := false.B
  invalidateAll.vaddr    := 0.U

  private val arrayInvalidate = Wire(Valid(new TlbSfence(cfg)))
  arrayInvalidate.valid := io.sfence.valid || (io.req.fire && array.io.lookupMultiple)
  arrayInvalidate.bits  := Mux(io.sfence.valid, io.sfence.bits, invalidateAll)

  private val refillFill = io.refill.fire && io.refill.bits.fill && !refillException.valid

  array.io.invalidate  := arrayInvalidate
  array.io.write.valid := refillFill
  array.io.write.bits  := fillEntry
  array.io.writeIndex  := walkEntry.victim

  // ------------------------------------------------------------ recover/control

  // The queue is program ordered, so a recover boundary always removes a
  // suffix; no compaction is needed.
  private val younger = Wire(Vec(missCount, Bool()))
  for (position <- 0 until missCount) {
    val entry = missEntries(logicalIdx(position.U(missCountWidth.W)))
    younger(position) := position.U < missOccupancy &&
      RobAge.isYounger(entry.req.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  }
  private val anyYounger = younger.asUInt.orR
  private val firstYounger = OHToUInt(PriorityEncoderOH(younger.asUInt))
  private val recoverKeep  = Mux(anyYounger, firstYounger, missOccupancy)
  private val walkKilled   = walkPending &&
    RobAge.isYounger(walkEntry.req.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

  when(io.flush || io.sfence.valid) {
    missHead      := 0.U
    missTail      := 0.U
    missOccupancy := 0.U
    walkPending   := false.B
    respValid     := false.B
    for (entry <- 0 until cfg.dtlbEntries) {
      reservedVictims(entry) := false.B
    }
  }.elsewhen(io.recover.valid) {
    for (position <- 0 until missCount) {
      when(position.U >= recoverKeep) {
        reservedVictims(missEntries(logicalIdx(position.U(missCountWidth.W))).victim) := false.B
      }
    }
    when(walkKilled) {
      walkPending := false.B
    }
    // A response consumed in this cycle must still be retired from the
    // response register; otherwise the LSU and DTLB disagree about ownership
    // and the held response blocks every later lookup.
    when(respFire) {
      respValid := false.B
    }
    missTail := idxPlus(missHead, recoverKeep)
    missOccupancy := recoverKeep
  }.otherwise {
    val enqueueMiss = io.req.fire && lookupMiss
    val popMiss     = io.refill.fire

    // Lookup response and miss enqueue.
    when(io.req.fire) {
      respValid         := true.B
      respReg.paddr     := hitPaddr
      respReg.exception := Mux(lookupMiss, 0.U.asTypeOf(new ExceptionInfo(cfg)), hitException)
      respReg.vaddr     := io.req.bits.vaddr
      respReg.pte       := 0.U
      respReg.level     := 0.U
      respReg.fill      := false.B
      respReg.id        := io.req.bits.id
      respReg.robIdx    := io.req.bits.robIdx
      respReg.deferred  := lookupMiss
    }.elsewhen(respFire) {
      respValid := false.B
    }

    when(enqueueMiss) {
      missEntries(missTail).req    := io.req.bits
      missEntries(missTail).victim := chosenVictim
    }
    for (entry <- 0 until cfg.dtlbEntries) {
      when(enqueueMiss && chosenVictim === entry.U) {
        reservedVictims(entry) := true.B
      }
      when(popMiss && walkEntry.victim === entry.U) {
        reservedVictims(entry) := false.B
      }
    }

    when(io.missReq.fire) {
      walkPending      := true.B
      walkEntry        := 0.U.asTypeOf(new DtlbMissEntry(cfg))
      walkEntry.req    := headEntry.req
      walkEntry.victim := headEntry.victim
    }.elsewhen(popMiss) {
      walkPending := false.B
    }

    missHead      := Mux(popMiss, idxPlus(missHead, 1.U), missHead)
    missTail      := Mux(enqueueMiss, idxPlus(missTail, 1.U), missTail)
    missOccupancy := missOccupancy + enqueueMiss.asUInt - popMiss.asUInt
  }

  // -------------------------------------------------------------- completion

  val completion = Wire(new MmuTranslateResp(cfg))
  completion.paddr     := io.refill.bits.paddr
  completion.exception := refillException
  completion.vaddr     := io.refill.bits.vaddr
  completion.pte       := io.refill.bits.pte
  completion.level     := io.refill.bits.level
  completion.fill      := refillFill
  completion.id        := walkEntry.req.id
  completion.robIdx    := walkEntry.req.robIdx
  completion.deferred  := false.B

  io.complete.valid := io.refill.fire && !io.flush && !io.sfence.valid && !io.recover.valid
  io.complete.bits  := completion

  when(io.refill.fire) {
    assert(io.refill.bits.vaddr === walkEntry.req.vaddr, "DTLB refill must match the walking request")
  }
  when(refillFill) {
    assert(io.refill.bits.pte(0), "DTLB fill requires a valid PTE")
  }
  when(refillFill && io.refill.bits.level === 1.U) {
    assert(io.refill.bits.pte(19, 10) === 0.U, "4MB DTLB entry must have PPN[0] zero")
  }
  when(io.missReq.fire) {
    assert(headValid, "DTLB walker started without a queued miss")
  }
  when(io.req.ready && io.req.valid && lookupMiss) {
    assert(canEnqueueMiss, "DTLB accepted a miss without queue space or a free victim")
  }

  // --------------------------------------------------------------- monitoring

  io.monitor := 0.U.asTypeOf(new TlbMonitor(cfg))
  if (enableMonitor) {
    io.monitor.request       := io.req.fire
    io.monitor.hit           := io.req.fire && array.io.lookupHit && !array.io.lookupMultiple
    io.monitor.miss          := io.req.fire && lookupMiss
    io.monitor.superpageHit  := io.req.fire && array.io.lookupHit && !array.io.lookupMultiple &&
      array.io.lookupEntry.level === 1.U
    io.monitor.response      := io.resp.fire
    io.monitor.complete      := io.complete.valid
    io.monitor.walkStart     := io.missReq.fire
    io.monitor.refill        := refillFill
    io.monitor.refillFault   := io.refill.fire && refillException.valid
    io.monitor.sfence        := io.sfence.valid
    io.monitor.flush         := io.flush
    io.monitor.reqStall      := io.req.valid && !io.req.ready
    io.monitor.refillStall   := io.refill.valid && !io.refill.ready
    io.monitor.occupancy     := array.io.occupancy
    io.monitor.missOccupancy := missOccupancy
  }
}

object DtlbAddress {
  def apply(entry: DtlbEntry, vaddr: UInt, addrWidth: Int): UInt = {
    val offset = vaddr(11, 0)
    val paddr  = Mux(
      entry.level === 0.U,
      Cat(entry.ppn, offset),
      Cat(entry.ppn(21, 10), vaddr(21, 12), offset)
    )
    paddr(addrWidth - 1, 0)
  }
}
