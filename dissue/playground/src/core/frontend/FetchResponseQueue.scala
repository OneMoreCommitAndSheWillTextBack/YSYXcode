package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{Decoupled, Mux1H, PopCount, PriorityEncoderOH, Valid, log2Ceil}
import top.config.ICacheConfig
import top.core.frontend.bundle.{FetchControlMeta, ICacheFetchGroupResp}

class FetchResponseQueue(
  cacheCfg: ICacheConfig = ICacheConfig(),
  depth:    Int = 4)
    extends Module {
  require(depth >= 2, "FetchResponseQueue must retain multiple resolved groups")

  private val groupWidth = cacheCfg.fetchGroupBlocks
  private val countWidth = log2Ceil(depth + 1)

  val io = IO(new Bundle {
    val flush        = Input(Bool())
    val currentEpoch = Input(UInt(cacheCfg.fetchEpochBits.W))
    val oldest       = Input(Valid(new FetchControlMeta(cacheCfg)))
    val insert       = Flipped(Decoupled(new ICacheFetchGroupResp(cacheCfg)))
    val out          = Decoupled(new ICacheFetchGroupResp(cacheCfg))

    val occupancy = Output(UInt(countWidth.W))
    val empty     = Output(Bool())
    val full      = Output(Bool())
    val staleDrop = Output(Bool())
  })

  private def sameKey(left: FetchControlMeta, right: FetchControlMeta): Bool =
    left.sequence === right.sequence && left.epoch === right.epoch

  private val entries = Reg(Vec(depth, new ICacheFetchGroupResp(cacheCfg)))
  private val valid   = RegInit(VecInit(Seq.fill(depth)(false.B)))

  private val occupancy = PopCount(valid)
  private val oldestLive = io.oldest.valid && io.oldest.bits.epoch === io.currentEpoch
  private val stale = VecInit((0 until depth).map { slot =>
    valid(slot) && entries(slot).blocks(0).bits.meta.control.epoch =/= io.currentEpoch
  }).asUInt
  private val matching = VecInit((0 until depth).map { slot =>
    valid(slot) && oldestLive &&
      entries(slot).blocks(0).bits.meta.control.epoch === io.currentEpoch &&
      sameKey(entries(slot).blocks(0).bits.meta.control, io.oldest.bits)
  }).asUInt

  private val responseReady = matching.orR
  private val selected = Mux1H((0 until depth).map { slot =>
    matching(slot) -> entries(slot)
  })
  private val incomingMeta    = io.insert.bits.blocks(0).bits.meta.control
  private val incomingStale   = io.insert.bits.blocks(0).valid && incomingMeta.epoch =/= io.currentEpoch
  private val bypassCandidate = !io.flush && io.insert.valid && io.insert.bits.blocks(0).valid &&
    !incomingStale && oldestLive &&
    sameKey(incomingMeta, io.oldest.bits) && !responseReady
  private val bypassFire = !io.flush && bypassCandidate && io.out.ready

  io.out.valid := !io.flush && (responseReady || bypassCandidate)
  io.out.bits  := 0.U.asTypeOf(new ICacheFetchGroupResp(cacheCfg))
  when(responseReady) {
    io.out.bits := selected
  }.elsewhen(bypassCandidate) {
    io.out.bits := io.insert.bits
  }

  private val releaseOH = PriorityEncoderOH(matching)
  private val staleOH   = PriorityEncoderOH(stale)
  private val release   = io.out.fire && responseReady
  private val dropStale = !io.flush && !release && stale.orR
  private val removeOH  = Mux(release, releaseOH, Mux(dropStale, staleOH, 0.U(depth.W)))

  private val validAfterRemove = Wire(Vec(depth, Bool()))
  for (slot <- 0 until depth) {
    validAfterRemove(slot) := valid(slot) && !removeOH(slot)
  }
  private val freeAfterRemove = VecInit(validAfterRemove.map(value => !value)).asUInt
  private val storeIncoming   = io.insert.fire && !incomingStale && !bypassFire
  private val writeOH         = PriorityEncoderOH(freeAfterRemove)

  io.insert.ready := !io.flush && (incomingStale || bypassFire || freeAfterRemove.orR)

  io.occupancy := occupancy
  io.empty     := occupancy === 0.U
  io.full      := occupancy === depth.U
  io.staleDrop := dropStale || (io.insert.fire && incomingStale)

  when(io.insert.fire) {
    assert(io.insert.bits.blocks(0).valid)
    for (lane <- 0 until groupWidth) {
      when(io.insert.bits.blocks(lane).valid) {
        assert(io.insert.bits.blocks(lane).bits.meta.control.epoch === incomingMeta.epoch)
        assert(io.insert.bits.blocks(lane).bits.meta.control.sequence === incomingMeta.sequence + lane.U)
        assert(io.insert.bits.blocks(lane).bits.meta.blockAddr ===
          io.insert.bits.blocks(0).bits.meta.blockAddr + (lane * cacheCfg.fetchBytes).U)
      }
      if (lane > 0) {
        when(io.insert.bits.blocks(lane).valid) {
          assert(io.insert.bits.blocks(lane - 1).valid)
        }
      }
    }
  }

  when(storeIncoming) {
    assert(freeAfterRemove.orR)
    for (slot <- 0 until depth) {
      when(valid(slot)) {
        assert(!sameKey(entries(slot).blocks(0).bits.meta.control, incomingMeta))
      }
    }
  }

  for (slot <- 0 until depth) {
    when(valid(slot)) {
      assert(entries(slot).blocks(0).valid)
      for (lane <- 1 until groupWidth) {
        when(entries(slot).blocks(lane).valid) {
          assert(entries(slot).blocks(lane - 1).valid)
          assert(entries(slot).blocks(lane).bits.meta.control.epoch ===
            entries(slot).blocks(0).bits.meta.control.epoch)
          assert(entries(slot).blocks(lane).bits.meta.control.sequence ===
            entries(slot).blocks(0).bits.meta.control.sequence + lane.U)
        }
      }
    }
  }

  when(io.out.fire) {
    assert(oldestLive)
    when(responseReady) {
      assert(PopCount(matching) === 1.U)
    }.otherwise {
      assert(bypassCandidate)
    }
    when(!responseReady) {
      assert(io.insert.fire)
      assert(!storeIncoming)
      assert(!release)
    }
    assert(io.out.bits.blocks(0).valid)
    assert(sameKey(io.out.bits.blocks(0).bits.meta.control, io.oldest.bits))
  }
  when(bypassCandidate && !io.out.ready && io.insert.fire) {
    assert(storeIncoming)
    assert(freeAfterRemove.orR)
  }

  when(io.flush) {
    valid := VecInit(Seq.fill(depth)(false.B))
  }.otherwise {
    for (slot <- 0 until depth) {
      val writeSlot = storeIncoming && writeOH(slot)
      valid(slot) := (valid(slot) && !removeOH(slot)) || writeSlot
      when(writeSlot) {
        entries(slot) := io.insert.bits
      }
    }
  }

  assert(occupancy <= depth.U)
  assert(PopCount(removeOH) <= 1.U)
  assert(PopCount(writeOH) <= 1.U)
  when(io.out.valid) {
    assert(oldestLive)
    assert(io.out.bits.blocks(0).valid)
    assert(io.out.bits.blocks(0).bits.meta.control.epoch === io.currentEpoch)
    assert(sameKey(io.out.bits.blocks(0).bits.meta.control, io.oldest.bits))
  }
}
