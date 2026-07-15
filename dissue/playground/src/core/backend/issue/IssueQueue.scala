package top.core.backend.issue

import chisel3._
import chisel3.util.{Decoupled, Mux1H, MuxLookup, PopCount}
import top.core.backend.bundle.{IssuePacket, IssuePortStatus, IssueWakeup, StoreTrackerQuery}
import top.core.backend.csr.CsrTrackerQuery
import top.core.backend.decoder.FuType
import top.core.bundle.{CfiType, RobAge, RobRecovery}
import top.config.BackendConfig
import top.dpi.NpcIssueQueuePerf

class IssueQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val enq          = Vec(cfg.dispatchWidth, Flipped(Decoupled(new IssuePacket(cfg))))
    val wakeup       = Input(Vec(cfg.writebackWidth, new IssueWakeup(cfg)))
    val commitWakeup = Input(Vec(cfg.commitWidth, new IssueWakeup(cfg)))
    val intStatus    = Input(Vec(cfg.intIssueWidth, new IssuePortStatus))
    val memStatus    = Input(new IssuePortStatus)
    val robHead      = Input(UInt(cfg.robIdxWidth.W))
    val unresolvedAmo = Input(Vec(cfg.robEntries, Bool()))
    val storeQuery   = Vec(cfg.issueQueueEntries, Flipped(new StoreTrackerQuery(cfg)))
    val csrQuery     = Vec(cfg.issueQueueEntries, Flipped(new CsrTrackerQuery(cfg)))
    val intIssue     = Vec(cfg.intIssueWidth, Decoupled(new IssuePacket(cfg)))
    val memIssue     = Decoupled(new IssuePacket(cfg))
    val flush        = Input(Bool())
    val recover      = Input(new RobRecovery(cfg.robIdxWidth))
  })

  private val entries    = Reg(Vec(cfg.issueQueueEntries, new IssuePacket(cfg)))
  private val valid      = RegInit(VecInit(Seq.fill(cfg.issueQueueEntries)(false.B)))
  private val intSelect  = Seq.fill(cfg.intIssueWidth)(Module(new IssueSelect(cfg)))
  private val memSelect  = Module(new IssueSelect(cfg))
  private val allWakeups = io.wakeup ++ io.commitWakeup

  intSelect.foreach(_.io.robHead := io.robHead)
  memSelect.io.robHead := io.robHead

  private def fuAvailable(status: IssuePortStatus, fuType: UInt): Bool =
    MuxLookup(fuType, false.B)(
      Seq(
        FuType.alu   -> status.alu,
        FuType.mul   -> status.mul,
        FuType.div   -> status.div,
        FuType.lsu   -> status.lsu,
        FuType.bru   -> status.bru,
        FuType.jmp   -> status.jmp,
        FuType.csr   -> status.csr,
        FuType.fence -> status.fence
      )
    )

  for (i <- 0 until cfg.issueQueueEntries) {
    val ready                  = entries(i).src1.ready && entries(i).src2.ready
    val hasOlderUnresolvedAmo = VecInit((0 until cfg.robEntries).map { amoRobIdx =>
      io.unresolvedAmo(amoRobIdx) && RobAge.isYounger(
        entries(i).robIdx,
        amoRobIdx.U(cfg.robIdxWidth.W),
        io.robHead,
        cfg.robEntries,
        cfg.robIdxWidth
      )
    }).asUInt.orR
    val memPipe         = entries(i).fuType === FuType.lsu
    val loadBlocked     = entries(i).isLoad && io.storeQuery(i).hasOlderStore
    val amoOrderBlocked = memPipe && hasOlderUnresolvedAmo
    val amoBlocked      = entries(i).isAmo && entries(i).robIdx =/= io.robHead
    val csrBlocked      = entries(i).isCsr && io.csrQuery(i).hasOlderSameAddrWriter
    val cfiAge = RobAge.fromHead(entries(i).robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
    val cfiBlocked = entries(i).cfi =/= CfiType.none && VecInit((0 until cfg.issueQueueEntries).map { other =>
      valid(other) && entries(other).cfi =/= CfiType.none &&
        RobAge.fromHead(entries(other).robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth) < cfiAge
    }).asUInt.orR
    val request = valid(i) && entries(i).needsExecution && ready && !loadBlocked && !amoOrderBlocked && !amoBlocked && !csrBlocked &&
      !cfiBlocked && !io.flush && !io.recover.valid

    io.storeQuery(i).valid  := valid(i) && entries(i).needsExecution && entries(i).isLoad
    io.storeQuery(i).robIdx := entries(i).robIdx
    io.csrQuery(i).valid    := valid(i) && entries(i).needsExecution && entries(i).isCsr
    io.csrQuery(i).robIdx   := entries(i).robIdx
    io.csrQuery(i).addr     := entries(i).csrAddr

    for (port <- 0 until cfg.intIssueWidth) {
      val usedByEarlierPort =
        if (port == 0) false.B else (0 until port).map(p => intSelect(p).io.grantOH(i)).reduce(_ || _)

      intSelect(port).io.request(i) := request &&
        !memPipe &&
        !usedByEarlierPort &&
        fuAvailable(io.intStatus(port), entries(i).fuType)
      intSelect(port).io.robIdx(i)  := entries(i).robIdx
    }

    memSelect.io.request(i) := request && memPipe && fuAvailable(io.memStatus, entries(i).fuType)
    memSelect.io.robIdx(i)  := entries(i).robIdx
  }

  for (port <- 0 until cfg.intIssueWidth) {
    io.intIssue(port).valid := intSelect(port).io.grantOH.asUInt.orR
    io.intIssue(port).bits  := Mux1H(
      intSelect(port).io.grantOH,
      entries
    )
  }
  io.memIssue.valid := memSelect.io.grantOH.asUInt.orR
  io.memIssue.bits := Mux1H(
    memSelect.io.grantOH,
    entries
  )

  private val issueFire = Wire(Vec(cfg.issueQueueEntries, Bool()))
  private val free      = Wire(Vec(cfg.issueQueueEntries, Bool()))
  for (i <- 0 until cfg.issueQueueEntries) {
    issueFire(i) :=
      (0 until cfg.intIssueWidth).map(port => io.intIssue(port).fire && intSelect(port).io.grantOH(i)).reduce(_ || _) ||
        (io.memIssue.fire && memSelect.io.grantOH(i))
    free(i)      := !valid(i) || issueFire(i)
  }

  private val issueCountThisCycle = PopCount(io.intIssue.map(_.fire) :+ io.memIssue.fire)
  private val occupancy           = PopCount(valid)
  private val hasReadyEntry       = VecInit(
    (0 until cfg.issueQueueEntries).map(i =>
      valid(i) && entries(i).needsExecution && entries(i).src1.ready && entries(i).src2.ready
    )
  ).asUInt.orR
  private val hasOperandBlocked   = VecInit(
    (0 until cfg.issueQueueEntries).map(i =>
      valid(i) && entries(i).needsExecution && (!entries(i).src1.ready || !entries(i).src2.ready)
    )
  ).asUInt.orR
  private val noIssue             = issueCountThisCycle === 0.U

  NpcIssueQueuePerf.callWithEnable(
    !reset.asBool && !io.flush && !io.recover.valid,
    issueCountThisCycle.pad(32),
    occupancy.pad(32),
    noIssue && hasReadyEntry,
    noIssue && !hasReadyEntry && hasOperandBlocked
  )

  private val freeCount = PopCount(free)
  for (enqIdx <- 0 until cfg.dispatchWidth) {
    val previousEnqsValid =
      if (enqIdx == 0) true.B else io.enq.take(enqIdx).map(_.valid).reduce(_ && _)
    io.enq(enqIdx).ready := !io.flush && !io.recover.valid && (freeCount > enqIdx.U) && previousEnqsValid
  }

  private val enqOH = Wire(Vec(cfg.dispatchWidth, Vec(cfg.issueQueueEntries, Bool())))
  for (enqIdx <- 0 until cfg.dispatchWidth) {
    for (entryIdx <- 0 until cfg.issueQueueEntries) {
      val usedByEarlierEnq      = if (enqIdx == 0) {
        false.B
      } else {
        (0 until enqIdx).map(earlierEnq => enqOH(earlierEnq)(entryIdx)).reduce(_ || _)
      }
      val entryAvailable        = free(entryIdx) && !usedByEarlierEnq
      val earlierEntryAvailable = if (entryIdx == 0) {
        false.B
      } else {
        (0 until entryIdx).map { earlierEntry =>
          val earlierEntryUsed = if (enqIdx == 0) {
            false.B
          } else {
            (0 until enqIdx).map(earlierEnq => enqOH(earlierEnq)(earlierEntry)).reduce(_ || _)
          }
          free(earlierEntry) && !earlierEntryUsed
        }.reduce(_ || _)
      }

      enqOH(enqIdx)(entryIdx) := io.enq(enqIdx).fire && entryAvailable && !earlierEntryAvailable
    }
  }

  private val enqBits = Wire(Vec(cfg.dispatchWidth, new IssuePacket(cfg)))
  for (enqIdx <- 0 until cfg.dispatchWidth) {
    enqBits(enqIdx) := io.enq(enqIdx).bits

    val src1WakeupHits = VecInit(
      allWakeups.map(wakeup =>
        wakeup.valid && !io.enq(enqIdx).bits.src1.ready && (io.enq(enqIdx).bits.src1.tag === wakeup.robIdx)
      )
    )
    val src2WakeupHits = VecInit(
      allWakeups.map(wakeup =>
        wakeup.valid && !io.enq(enqIdx).bits.src2.ready && (io.enq(enqIdx).bits.src2.tag === wakeup.robIdx)
      )
    )
    val src1WakeupHit  = src1WakeupHits.asUInt.orR
    val src2WakeupHit  = src2WakeupHits.asUInt.orR

    enqBits(enqIdx).src1.ready := io.enq(enqIdx).bits.src1.ready || src1WakeupHit
    enqBits(enqIdx).src1.data  := Mux(
      src1WakeupHit,
      Mux1H(src1WakeupHits, allWakeups.map(_.data)),
      io.enq(enqIdx).bits.src1.data
    )
    enqBits(enqIdx).src2.ready := io.enq(enqIdx).bits.src2.ready || src2WakeupHit
    enqBits(enqIdx).src2.data  := Mux(
      src2WakeupHit,
      Mux1H(src2WakeupHits, allWakeups.map(_.data)),
      io.enq(enqIdx).bits.src2.data
    )
  }

  for (i <- 0 until cfg.issueQueueEntries) {
    when(io.flush) {
      valid(i) := false.B
    }.elsewhen(io.recover.valid) {
      when(RobAge.isYounger(entries(i).robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)) {
        valid(i) := false.B
      }
    }.otherwise {
      for (wakeup <- allWakeups) {
        when(valid(i) && wakeup.valid) {
          when(!entries(i).src1.ready && (entries(i).src1.tag === wakeup.robIdx)) {
            entries(i).src1.ready := true.B
            entries(i).src1.data  := wakeup.data
          }
          when(!entries(i).src2.ready && (entries(i).src2.tag === wakeup.robIdx)) {
            entries(i).src2.ready := true.B
            entries(i).src2.data  := wakeup.data
          }
        }
      }

      when(issueFire(i)) {
        valid(i) := false.B
      }

      for (enqIdx <- 0 until cfg.dispatchWidth) {
        when(enqOH(enqIdx)(i)) {
          entries(i) := enqBits(enqIdx)
          valid(i)   := true.B
        }
      }
    }
  }
}
