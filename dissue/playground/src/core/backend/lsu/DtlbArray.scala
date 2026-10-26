package top.core.backend.lsu

import chisel3._
import chisel3.util.{Mux1H, OHToUInt, PopCount, PriorityEncoderOH, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.{DtlbEntry, TlbSfence}

class DtlbArrayIO(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val lookupVaddr    = Input(UInt(cfg.addrWidth.W))
  val lookupHit      = Output(Bool())
  val lookupMultiple = Output(Bool())
  val lookupEntry    = Output(new DtlbEntry(cfg))

  val write      = Input(Valid(new DtlbEntry(cfg)))
  val writeIndex = Input(UInt(cfg.dtlbIdxWidth.W))

  val invalidate = Input(Valid(new TlbSfence(cfg)))

  val victim    = Output(UInt(cfg.dtlbIdxWidth.W))
  val occupancy = Output(UInt(cfg.dtlbCountWidth.W))
}

/** Data-path half of the DTLB.
  *
  * The array owns tags, permission bits, replacement state, and invalidation. It has no request/response handshake
  * logic; the DTLB control FSM decides when to look up, write, or invalidate.
  */
class DtlbArray(cfg: BackendConfig = BackendConfig()) extends Module {
  private val entryCount = cfg.dtlbEntries
  private val idxWidth   = cfg.dtlbIdxWidth

  val io = IO(new DtlbArrayIO(cfg))

  private val entries       = RegInit(VecInit(Seq.fill(entryCount)(0.U.asTypeOf(new DtlbEntry(cfg)))))
  private val replacement   = RegInit(0.U(idxWidth.W))
  private val lookupVpn     = io.lookupVaddr(cfg.addrWidth - 1, 12)
  private val invalidateVpn = io.invalidate.bits.vaddr(cfg.addrWidth - 1, 12)

  private def vpnMatch(entry: DtlbEntry): Bool =
    Mux(
      entry.level === 0.U,
      entry.vpn === lookupVpn,
      entry.vpn(19, 10) === lookupVpn(19, 10)
    )

  private val hitVec = VecInit(entries.map { entry =>
    entry.valid && vpnMatch(entry)
  })

  private val validVec     = VecInit(entries.map(_.valid))
  private val firstInvalid = PriorityEncoderOH(~validVec.asUInt)

  io.lookupHit      := hitVec.asUInt.orR
  io.lookupMultiple := PopCount(hitVec) > 1.U
  io.lookupEntry    := Mux1H(hitVec, entries)

  // Prefer an invalid entry; once all entries are live, replace in round-robin order.
  io.victim    := Mux(validVec.asUInt.andR, replacement, OHToUInt(firstInvalid))
  io.occupancy := PopCount(validVec)

  private def entryCovers(entry: DtlbEntry): Bool =
    Mux(
      entry.level === 0.U,
      entry.vpn === invalidateVpn,
      entry.vpn(19, 10) === invalidateVpn(19, 10)
    )

  // A 4KB entry and a 4MB superpage can cover the same virtual page, so a fill
  // must evict every overlapping entry. Otherwise a later lookup can match two
  // entries and the duplicate-resolution path thrashes the whole array.
  private def overlaps(existing: DtlbEntry, incoming: DtlbEntry): Bool = {
    val sameSuperVpn = existing.vpn(19, 10) === incoming.vpn(19, 10)
    Mux(
      incoming.level === 1.U,
      sameSuperVpn,
      Mux(existing.level === 1.U, sameSuperVpn, existing.vpn === incoming.vpn)
    )
  }

  private val invalidateAll     = !io.invalidate.bits.useVaddr && !io.invalidate.bits.useAsid
  private val invalidateByVaddr = io.invalidate.bits.useVaddr && !io.invalidate.bits.useAsid
  private val invalidateByAsid  = io.invalidate.bits.useAsid

  when(io.write.fire) {
    assert(io.write.bits.valid, "DTLB fill must write a valid entry")
    entries(io.writeIndex) := io.write.bits
    replacement            := Mux(
      io.writeIndex === (entryCount - 1).U,
      0.U,
      io.writeIndex + 1.U
    )
    for (index <- 0 until entryCount) {
      when(index.U =/= io.writeIndex && entries(index).valid && overlaps(entries(index), io.write.bits)) {
        entries(index).valid := false.B
      }
    }
  }

  when(io.invalidate.valid) {
    for (index <- 0 until entryCount) {
      val clear = invalidateAll ||
        (invalidateByVaddr && entryCovers(entries(index)) && !entries(index).g) ||
        (invalidateByAsid && !entries(index).g)
      when(clear) {
        entries(index).valid := false.B
      }
    }
  }
}
