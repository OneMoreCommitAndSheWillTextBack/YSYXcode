package top.core.backend.lsu

import chisel3._
import chisel3.util.{Decoupled, MuxLookup, OHToUInt, PriorityEncoderOH}
import top.config.BackendConfig
import top.core.backend.bundle.IssuePacket
import top.core.backend.csr.PrivMode
import top.core.bundle.RobAge
import top.core.mmu.MmuAccessType

/** One accepted LSU memory operation, after AGU and CSR snapshot. */
class TranslationRequest(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val packet        = new IssuePacket(cfg)
  val vaddr         = UInt(cfg.addrWidth.W)
  val access        = UInt(MmuAccessType.width.W)
  val priv          = UInt(PrivMode.width.W)
  val mstatus       = UInt(cfg.dataWidth.W)
  val satp          = UInt(cfg.dataWidth.W)
  val translationId = UInt(cfg.translationIdWidth.W)
}

class TranslationQueueIO(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val enq       = Flipped(Decoupled(new TranslationRequest(cfg)))
  val head      = Output(new TranslationRequest(cfg))
  val headValid = Output(Bool())
  val pop       = Input(Bool())
  val flush     = Input(Bool())
  val recover   = Input(new top.core.bundle.RobRecovery(cfg.robIdxWidth))
  val robHead   = Input(UInt(cfg.robIdxWidth.W))
  val occupancy = Output(UInt(cfg.translationQueueCountWidth.W))
  val full      = Output(Bool())
  val empty     = Output(Bool())
}

/** Program-order LSU translation queue.
  *
  * The queue is the S1 pipeline stage. S0 enqueues in program order (enforced by the issue-queue memory-order gate); S2
  * captures `head`; the queue pops on that capture, and S3 owns the captured request. `head` always points at the
  * oldest entry that has not yet been captured by S2, so a lookup blocked by the MMU cannot lose an entry.
  */
class TranslationQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount = cfg.translationQueueEntries
  private val idxWidth   = cfg.translationQueueIdxWidth
  private val countWidth = cfg.translationQueueCountWidth

  val io = IO(new TranslationQueueIO(cfg))

  private val entries = Reg(Vec(entryCount, new TranslationRequest(cfg)))
  private val valid   = RegInit(VecInit(Seq.fill(entryCount)(false.B)))
  private val head    = RegInit(0.U(idxWidth.W))
  private val tail    = RegInit(0.U(idxWidth.W))
  private val count   = RegInit(0.U(countWidth.W))

  private def idxPlus(base: UInt, offset: UInt): UInt = {
    val width = math.max(base.getWidth, offset.getWidth) + 1
    val sum   = base.pad(width) + offset.pad(width)
    Mux(sum >= entryCount.U, sum - entryCount.U, sum)(idxWidth - 1, 0)
  }

  private def logicalIdx(offset: UInt): UInt = idxPlus(head, offset)

  private val empty       = count === 0.U
  private val full        = count === entryCount.U
  private val popFire     = io.pop && !empty && !io.flush
  private val recoverFire = io.recover.valid && !io.flush
  private val enqFire     = io.enq.fire && !recoverFire

  // Recover keeps the program-order prefix at or older than the boundary.
  // Entries younger than the boundary form a suffix, so no compaction is needed.
  private val younger = Wire(Vec(entryCount, Bool()))
  for (k <- 0 until entryCount) {
    val idx = logicalIdx(k.U(countWidth.W))
    younger(k) := k.U < count && valid(idx) &&
      RobAge.isYounger(entries(idx).packet.robIdx, io.recover.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)
  }
  private val anyYounger = younger.asUInt.orR
  private val firstYounger = OHToUInt(PriorityEncoderOH(younger.asUInt))
  private val recoverKeep  = Mux(anyYounger, firstYounger, count)

  private val postRecoverCount = Mux(recoverFire, recoverKeep, count)
  private val popAfterRecover  = popFire && postRecoverCount =/= 0.U
  private val enqAfterRecover  = enqFire

  // Do not make enqueue readiness depend on the S3 pop: that creates a
  // combinational path from s3CanComplete through tq.enq.ready back into
  // s3CanComplete via the S0 misaligned writeback. A full queue takes one
  // bubble after a pop instead.
  io.enq.ready := !io.flush && !recoverFire && !full
  io.full      := full
  io.empty     := empty
  io.occupancy := count

  // `tail` is the enqueue write index, so with one live entry it already
  // points at the slot after `head`. A simultaneous pop+enqueue therefore
  // writes the new entry at head+1 and the head must advance with it; holding
  // the head would make the queue read the entry that was just invalidated
  // (duplicate translation) and orphan the new entry.
  private val popAdvancesHead = popFire

  private val nextHead  = Mux(
    recoverFire,
    Mux(popAfterRecover, idxPlus(head, 1.U), head),
    Mux(popAdvancesHead, idxPlus(head, 1.U), head)
  )
  private val nextTail  = Mux(
    recoverFire,
    idxPlus(head, recoverKeep),
    Mux(enqFire, idxPlus(tail, 1.U), tail)
  )
  private val nextCount = Mux(
    recoverFire,
    postRecoverCount - popAfterRecover,
    count - popFire + enqAfterRecover
  )

  when(io.flush) {
    head  := 0.U
    tail  := 0.U
    count := 0.U
    for (k <- 0 until entryCount) {
      valid(k) := false.B
    }
  }.otherwise {
    when(recoverFire) {
      for (k <- 0 until entryCount) {
        val idx = logicalIdx(k.U(countWidth.W))
        when(k.U >= recoverKeep) {
          valid(idx) := false.B
        }
      }
      when(popAfterRecover) {
        valid(head) := false.B
      }
    }.otherwise {
      when(popFire) {
        valid(head) := false.B
      }
      when(enqFire) {
        entries(tail) := io.enq.bits
        valid(tail)   := true.B
      }
    }

    head  := nextHead
    tail  := nextTail
    count := nextCount
  }

  // The queue entry is consumed when S2 captures it. Do not expose a post-pop
  // lookahead here: S2's request in the capture cycle must refer to the same
  // entry that `pop` removes, and a pop-dependent head would close a
  // combinational loop through mmu.req.valid/fire. A request blocked by the MMU
  // leaves the head in place and is retried next cycle.
  io.head      := entries(head)
  io.headValid := !empty
}
