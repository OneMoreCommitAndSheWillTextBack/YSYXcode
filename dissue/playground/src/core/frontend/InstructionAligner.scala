package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{log2Ceil, Cat, Decoupled, PopCount, Valid}
import top.config.FrontendConfig
import top.core.bundle.FetchException
import top.core.frontend.bundle.{AlignedInstructionGroup, FetchBlockGroup, FetchToken, FtqIfuView}

class AlignedHalfword(cfg: FrontendConfig) extends Bundle {
  val token     = new FetchToken(cfg)
  val sequence  = UInt(cfg.ftqSequenceBits.W)
  val pc        = UInt(cfg.addrWidth.W)
  val bits      = UInt(16.W)
  val exception = new FetchException(cfg.addrWidth)
}

/** Halfword alignment only. This module has no prediction or control-flow inputs. */
class InstructionAligner(cfg: FrontendConfig, depth: Int) extends Module {
  require(cfg.fetchBytes == 8, "InstructionAligner currently supports 8-byte cache blocks")
  require(depth > cfg.maxInstsPerFtqEntry, "aligner FIFO must hold more than one fetch group")
  require((depth & (depth - 1)) == 0, "aligner FIFO depth must be a power of two")

  private val blockHalfwords = cfg.fetchBytes / 2
  private val enqWidth       = cfg.fetchGroupBytes / 2
  private val peekWidth      = cfg.frontendWidth * 2
  private val ptrWidth       = log2Ceil(depth)
  private val countWidth     = log2Ceil(depth + 1)
  private val enqCountWidth  = log2Ceil(enqWidth + 1)
  private val startWidth     = log2Ceil(peekWidth + 1)
  private val needWidth      = 2

  val io = IO(new Bundle {
    val flush   = Input(Bool())
    val in      = Flipped(Decoupled(new FetchBlockGroup(cfg)))
    val context = Input(Valid(new FtqIfuView(cfg)))

    val headToken = Output(new FetchToken(cfg))
    val headValid = Output(Bool())
    val headLive  = Input(Bool())
    val kill      = Input(Valid(new FetchToken(cfg)))

    val out       = Decoupled(new AlignedInstructionGroup(cfg))
    val count     = Output(UInt(countWidth.W))
    val staleDrop = Output(Bool())
  })

  private def ptrAdd(ptr: UInt, increment: UInt): UInt =
    (ptr + increment)(ptrWidth - 1, 0)

  private def tokenMatches(left: FetchToken, right: FetchToken): Bool =
    left.tag.index === right.tag.index &&
      left.tag.generation === right.tag.generation &&
      left.streamEpoch === right.streamEpoch

  val entries  = Reg(Vec(depth, new AlignedHalfword(cfg)))
  val readPtr  = RegInit(0.U(ptrWidth.W))
  val writePtr = RegInit(0.U(ptrWidth.W))
  val count    = RegInit(0.U(countWidth.W))

  val peek = Wire(Vec(peekWidth, new AlignedHalfword(cfg)))
  for (parcel <- 0 until peekWidth) {
    peek(parcel) := entries(ptrAdd(readPtr, parcel.U))
  }

  val head = entries(readPtr)
  io.headToken := head.token
  io.headValid := count =/= 0.U
  io.count     := count

  val ownerPrefix = Wire(Vec(peekWidth, Bool()))
  for (parcel <- 0 until peekWidth) {
    ownerPrefix(parcel) := parcel.U < count && tokenMatches(peek(parcel).token, head.token) &&
      (if (parcel == 0) true.B else ownerPrefix(parcel - 1))
  }
  val ownerParcels = Wire(UInt(countWidth.W))
  ownerParcels := PopCount(ownerPrefix)

  val staleHead = count =/= 0.U && !io.headLive
  val killHead  = count =/= 0.U && io.kill.valid && tokenMatches(io.kill.bits, head.token)
  io.staleDrop := !io.flush && staleHead

  val starts = Wire(Vec(cfg.frontendWidth, UInt(startWidth.W)))
  val needs  = Wire(Vec(cfg.frontendWidth, UInt(needWidth.W)))
  val ready  = Wire(Vec(cfg.frontendWidth, Bool()))
  starts(0) := 0.U

  for (lane <- 0 until cfg.frontendWidth) {
    val low        = peek(starts(lane)(log2Ceil(peekWidth) - 1, 0))
    val high       = peek((starts(lane) + 1.U)(log2Ceil(peekWidth) - 1, 0))
    val isRvc      = low.bits(1, 0) =/= 3.U
    val laneNeeds  = Mux(isRvc, 1.U(needWidth.W), 2.U(needWidth.W))
    val contiguous = isRvc || (count > starts(lane) + 1.U && high.pc === low.pc + 2.U)
    needs(lane) := laneNeeds
    ready(lane) := (if (lane == 0) true.B else ready(lane - 1)) &&
      starts(lane) < ownerParcels && count >= starts(lane) +& laneNeeds && contiguous
    if (lane + 1 < cfg.frontendWidth) {
      starts(lane + 1) := starts(lane) + laneNeeds
    }
  }

  val ordinalValid = RegInit(false.B)
  val ordinalToken = Reg(new FetchToken(cfg))
  val nextOrdinal  = RegInit(0.U(cfg.ftqInstCountBits.W))
  val ordinalBase  = Mux(ordinalValid && tokenMatches(ordinalToken, head.token), nextOrdinal, 0.U)

  io.out.bits := 0.U.asTypeOf(new AlignedInstructionGroup(cfg))
  val laneValid = Wire(Vec(cfg.frontendWidth, Bool()))
  for (lane <- 0 until cfg.frontendWidth) {
    val low       = peek(starts(lane)(log2Ceil(peekWidth) - 1, 0))
    val high      = peek((starts(lane) + 1.U)(log2Ceil(peekWidth) - 1, 0))
    val isRvc     = low.bits(1, 0) =/= 3.U
    val valid     = ready(lane) && !io.flush && io.headLive && !staleHead && !killHead
    val exception = Wire(new FetchException(cfg.addrWidth))
    exception := low.exception
    when(!low.exception.valid && !isRvc && high.exception.valid) {
      exception := high.exception
    }

    laneValid(lane)                             := valid
    io.out.bits.insts(lane).valid               := valid
    io.out.bits.insts(lane).bits.token          := low.token
    io.out.bits.insts(lane).bits.sequence       := low.sequence
    io.out.bits.insts(lane).bits.instOrdinal    := ordinalBase + lane.U
    io.out.bits.insts(lane).bits.pc             := low.pc
    io.out.bits.insts(lane).bits.rawInst        := Mux(isRvc, low.bits, Cat(high.bits, low.bits))
    io.out.bits.insts(lane).bits.isRvc          := isRvc
    io.out.bits.insts(lane).bits.instLen        := Mux(isRvc, 2.U, 4.U)
    io.out.bits.insts(lane).bits.lastInFtqEntry := starts(lane) +& needs(lane) >= ownerParcels
    io.out.bits.insts(lane).bits.exception      := exception

    when(valid && !isRvc) {
      assert(high.pc === low.pc + 2.U)
    }
    if (lane > 0) {
      when(valid) {
        assert(laneValid(lane - 1))
        assert(low.pc === io.out.bits.insts(lane - 1).bits.pc + io.out.bits.insts(lane - 1).bits.instLen)
        assert(tokenMatches(low.token, head.token))
      }
    }
  }

  io.out.valid := laneValid(0)

  val consumedRaw = (0 until cfg.frontendWidth)
    .map(lane => Mux(laneValid(lane), needs(lane), 0.U(needWidth.W)))
    .reduce(_ +& _)
  val consumed    = Wire(UInt(countWidth.W))
  consumed := consumedRaw

  val discardOwner = staleHead || killHead
  val deqCount     = Wire(UInt(countWidth.W))
  deqCount := Mux(discardOwner, ownerParcels, Mux(io.out.fire, consumed, 0.U))

  val firstBlockData  = VecInit((0 until blockHalfwords).map { i =>
    io.in.bits.blocks(0).bits.data(16 * (i + 1) - 1, 16 * i)
  })
  val secondBlockData = VecInit((0 until blockHalfwords).map { i =>
    io.in.bits.blocks(1).bits.data(16 * (i + 1) - 1, 16 * i)
  })
  val startHalfword   = io.context.bits.startPc(cfg.icache.offsetBits - 1, 1)
  val firstCount      = Mux(
    io.in.bits.blocks(0).valid,
    blockHalfwords.U(enqCountWidth.W) - startHalfword,
    0.U(enqCountWidth.W)
  )
  val secondCount     = Mux(
    io.in.bits.blocks(1).valid,
    blockHalfwords.U(enqCountWidth.W),
    0.U(enqCountWidth.W)
  )
  val enqCount        = Wire(UInt(enqCountWidth.W))
  enqCount := firstCount +& secondCount

  val firstBlockBase = Cat(
    io.context.bits.startPc(cfg.addrWidth - 1, cfg.icache.offsetBits),
    0.U(cfg.icache.offsetBits.W)
  )
  val enqEntries     = Wire(Vec(enqWidth, new AlignedHalfword(cfg)))
  for (parcel <- 0 until enqWidth) {
    val parcelIndex    = parcel.U(enqCountWidth.W)
    val firstIndex     = startHalfword + parcelIndex
    val secondIndex    = parcelIndex - firstCount
    val fromFirst      = parcelIndex < firstCount
    val pc             = Mux(
      fromFirst,
      firstBlockBase +% (firstIndex << 1),
      firstBlockBase +% cfg.fetchBytes.U +% (secondIndex << 1)
    )
    val blockException = Mux(
      fromFirst,
      io.in.bits.blocks(0).bits.exception,
      io.in.bits.blocks(1).bits.exception
    )

    enqEntries(parcel)           := 0.U.asTypeOf(new AlignedHalfword(cfg))
    enqEntries(parcel).token     := io.in.bits.token
    enqEntries(parcel).sequence  := io.context.bits.sequence
    enqEntries(parcel).pc        := pc
    enqEntries(parcel).bits      := Mux(
      fromFirst,
      firstBlockData(firstIndex(log2Ceil(blockHalfwords) - 1, 0)),
      secondBlockData(secondIndex(log2Ceil(blockHalfwords) - 1, 0))
    )
    enqEntries(parcel).exception := blockException
    when(blockException.valid) {
      enqEntries(parcel).exception.tval := pc
    }
  }

  val freeAfterDequeue = depth.U(countWidth.W) - count + deqCount
  val contextMatches   = io.context.valid && tokenMatches(io.context.bits.token, io.in.bits.token)
  io.in.ready := !io.flush && contextMatches && freeAfterDequeue >= enqCount

  when(io.flush) {
    readPtr      := 0.U
    writePtr     := 0.U
    count        := 0.U
    ordinalValid := false.B
    nextOrdinal  := 0.U
  }.otherwise {
    when(io.in.fire) {
      for (parcel <- 0 until enqWidth) {
        when(parcel.U < enqCount) {
          entries(ptrAdd(writePtr, parcel.U)) := enqEntries(parcel)
        }
      }
      writePtr := ptrAdd(writePtr, enqCount)
      assert(contextMatches)
      assert(enqCount =/= 0.U)
    }

    when(deqCount =/= 0.U) {
      readPtr := ptrAdd(readPtr, deqCount)
    }
    count := count + Mux(io.in.fire, enqCount, 0.U) - deqCount

    when(discardOwner && ordinalValid && tokenMatches(ordinalToken, head.token)) {
      ordinalValid := false.B
      nextOrdinal  := 0.U
    }.elsewhen(io.out.fire) {
      val endsEntry = VecInit((0 until cfg.frontendWidth).map { lane =>
        laneValid(lane) && io.out.bits.insts(lane).bits.lastInFtqEntry
      }).asUInt.orR
      when(endsEntry) {
        ordinalValid := false.B
        nextOrdinal  := 0.U
      }.otherwise {
        ordinalValid := true.B
        ordinalToken := head.token
        nextOrdinal  := ordinalBase + PopCount(laneValid)
      }
    }
  }

  assert(count <= depth.U)
  assert(deqCount <= count)
  when(io.out.fire) {
    assert(io.out.bits.insts(0).valid)
  }
}
