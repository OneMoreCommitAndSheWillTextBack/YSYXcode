package top.backend.issue

import chisel3._
import chisel3.util.{Decoupled, Mux1H, MuxLookup, PriorityEncoderOH}
import top.backend.bundle.{IssueFuReady, IssuePacket, IssueWakeup, StoreTrackerQuery}
import top.backend.decoder.FuType
import top.config.BackendConfig

class IssueQueue(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val enq        = Flipped(Decoupled(new IssuePacket(cfg)))
    val wakeup     = Input(Vec(cfg.writebackWidth, new IssueWakeup(cfg)))
    val fuReady    = Input(new IssueFuReady)
    val robHead    = Input(UInt(cfg.robIdxWidth.W))
    val storeQuery = Vec(cfg.issueQueueEntries, Flipped(new StoreTrackerQuery(cfg)))
    val issue      = Decoupled(new IssuePacket(cfg))
    val flush      = Input(Bool())
  })

  private val entries = Reg(Vec(cfg.issueQueueEntries, new IssuePacket(cfg)))
  private val valid   = RegInit(VecInit(Seq.fill(cfg.issueQueueEntries)(false.B)))
  private val select  = Module(new IssueSelect(cfg))

  select.io.robHead := io.robHead

  private def fuAvailable(fuType: UInt): Bool =
    MuxLookup(fuType, false.B)(
      Seq(
        FuType.alu   -> io.fuReady.alu,
        FuType.lsu   -> io.fuReady.lsu,
        FuType.bru   -> io.fuReady.bru,
        FuType.jmp   -> io.fuReady.jmp,
        FuType.csr   -> io.fuReady.csr,
        FuType.fence -> io.fuReady.fence
      )
    )

  for (i <- 0 until cfg.issueQueueEntries) {
    val ready       = entries(i).src1.ready && entries(i).src2.ready
    val loadBlocked = entries(i).isLoad && io.storeQuery(i).hasOlderStore

    io.storeQuery(i).valid  := valid(i) && entries(i).legal && entries(i).isLoad
    io.storeQuery(i).robIdx := entries(i).robIdx

    select.io.request(i) := valid(i) && entries(i).legal && ready && fuAvailable(entries(i).fuType) && !loadBlocked
    select.io.robIdx(i)  := entries(i).robIdx
  }

  io.issue.valid := select.io.grantOH.asUInt.orR
  io.issue.bits  := Mux1H(
    select.io.grantOH,
    entries
  )

  private val issueFire = io.issue.fire
  private val free      = Wire(Vec(cfg.issueQueueEntries, Bool()))
  for (i <- 0 until cfg.issueQueueEntries) {
    free(i) := !valid(i) || (issueFire && select.io.grantOH(i))
  }

  private val enqOH = PriorityEncoderOH(free.asUInt).asBools
  io.enq.ready := free.asUInt.orR

  private val enqBits = Wire(new IssuePacket(cfg))
  enqBits := io.enq.bits
  private val src1WakeupHits = VecInit(io.wakeup.map(wakeup =>
    wakeup.valid && !io.enq.bits.src1.ready && io.enq.bits.src1.tag === wakeup.robIdx
  ))
  private val src2WakeupHits = VecInit(io.wakeup.map(wakeup =>
    wakeup.valid && !io.enq.bits.src2.ready && io.enq.bits.src2.tag === wakeup.robIdx
  ))
  private val src1WakeupHit = src1WakeupHits.asUInt.orR
  private val src2WakeupHit = src2WakeupHits.asUInt.orR

  enqBits.src1.ready := io.enq.bits.src1.ready || src1WakeupHit
  enqBits.src1.data  := Mux(src1WakeupHit, Mux1H(src1WakeupHits, io.wakeup.map(_.data)), io.enq.bits.src1.data)
  enqBits.src2.ready := io.enq.bits.src2.ready || src2WakeupHit
  enqBits.src2.data  := Mux(src2WakeupHit, Mux1H(src2WakeupHits, io.wakeup.map(_.data)), io.enq.bits.src2.data)

  for (i <- 0 until cfg.issueQueueEntries) {
    when(io.flush) {
      valid(i) := false.B
    }.otherwise {
      for (wakeup <- io.wakeup) {
        when(valid(i) && wakeup.valid) {
          when(!entries(i).src1.ready && entries(i).src1.tag === wakeup.robIdx) {
            entries(i).src1.ready := true.B
            entries(i).src1.data  := wakeup.data
          }
          when(!entries(i).src2.ready && entries(i).src2.tag === wakeup.robIdx) {
            entries(i).src2.ready := true.B
            entries(i).src2.data  := wakeup.data
          }
        }
      }

      when(issueFire && select.io.grantOH(i)) {
        valid(i) := false.B
      }

      when(io.enq.fire && enqOH(i)) {
        entries(i) := enqBits
        valid(i)   := true.B
      }
    }
  }
}
