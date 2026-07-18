package top.core.frontend.icache

import chisel3._
import chisel3.util._
import top.config.ICacheConfig
import top.core.frontend.bundle.{ICacheFetchGroupReq, ICacheFetchGroupResp, ICacheRefillReq, ICacheRefillResp, ICacheReq, ICacheResp}

class ICachePerf extends Bundle {
  val request  = Bool()
  val hit      = Bool()
  val miss     = Bool()
  val missWait = Bool()
}

class ICacheIO(cfg: ICacheConfig) extends Bundle {
  val req            = Flipped(Decoupled(new ICacheFetchGroupReq(cfg)))
  val acceptedBlocks = Output(UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W))
  val resp           = Decoupled(new ICacheFetchGroupResp(cfg))
  val refillReq      = Decoupled(new ICacheRefillReq(cfg.addrWidth))
  val refillResp     = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))
  val invalidate     = Input(Bool())
  val perf           = Output(new ICachePerf)
}

object ICacheState extends ChiselEnum {
  val SIdle, SRefillReq, SRefillResp, SResp = Value
}

class ICache(cfg: ICacheConfig = ICacheConfig()) extends Module {
  private val groupWidth      = cfg.fetchGroupBlocks
  private val groupCountWidth = log2Ceil(groupWidth + 1)

  val io = IO(new ICacheIO(cfg))

  private def globalSetIndex(addr: UInt): UInt = {
    if (cfg.indexBits == 0) {
      0.U(cfg.setIdxBits.W)
    } else {
      addr(cfg.offsetBits + cfg.indexBits - 1, cfg.offsetBits)
    }
  }

  private def bankIndex(addr: UInt): UInt =
    globalSetIndex(addr)(cfg.bankBits - 1, 0)

  private def localSetIndex(addr: UInt): UInt = {
    if (cfg.bankIndexBits == 0) {
      0.U(cfg.bankIdxBits.W)
    } else {
      globalSetIndex(addr)(cfg.indexBits - 1, cfg.bankBits)
    }
  }

  private def tag(addr: UInt): UInt =
    addr(cfg.addrWidth - 1, cfg.offsetBits + cfg.indexBits)

  val validArray = RegInit(
    VecInit(Seq.fill(cfg.bankCount)(VecInit(Seq.fill(cfg.bankSets)(false.B))))
  )
  val tagArray  = Reg(Vec(cfg.bankCount, Vec(cfg.bankSets, UInt(cfg.tagBits.W))))
  val dataArray = Reg(Vec(cfg.bankCount, Vec(cfg.bankSets, UInt(cfg.blockBits.W))))

  val state       = RegInit(ICacheState.SIdle)
  val killGroup   = RegInit(false.B)
  val groupCount  = RegInit(0.U(groupCountWidth.W))
  val groupReq    = Reg(Vec(groupWidth, new ICacheReq(cfg)))
  val groupResp   = Reg(Vec(groupWidth, new ICacheResp(cfg)))
  val pendingMiss = RegInit(VecInit(Seq.fill(groupWidth)(false.B)))
  val missSlot    = RegInit(0.U(log2Ceil(groupWidth).W))
  val missReq     = Reg(new ICacheReq(cfg))

  val requestBank = Wire(Vec(groupWidth, UInt(cfg.bankBits.W)))
  val requestSet  = Wire(Vec(groupWidth, UInt(cfg.bankIdxBits.W)))
  val requestTag  = Wire(Vec(groupWidth, UInt(cfg.tagBits.W)))
  val requestHit  = Wire(Vec(groupWidth, Bool()))
  val requestData = Wire(Vec(groupWidth, UInt(cfg.blockBits.W)))

  for (lane <- 0 until groupWidth) {
    val blockAddr = io.req.bits.blocks(lane).bits.meta.blockAddr
    requestBank(lane) := bankIndex(blockAddr)
    requestSet(lane)  := localSetIndex(blockAddr)
    requestTag(lane)  := tag(blockAddr)
    requestHit(lane)  := validArray(requestBank(lane))(requestSet(lane)) &&
      tagArray(requestBank(lane))(requestSet(lane)) === requestTag(lane)
    requestData(lane) := dataArray(requestBank(lane))(requestSet(lane))
  }

  val secondRequested = io.req.bits.blocks(1).valid
  val secondEligible  = secondRequested && requestBank(0) =/= requestBank(1)
  val acceptedBlocks  = Mux(
    io.req.bits.blocks(0).valid,
    Mux(secondEligible, groupWidth.U(groupCountWidth.W), 1.U(groupCountWidth.W)),
    0.U(groupCountWidth.W)
  )
  val requestActive = Wire(Vec(groupWidth, Bool()))
  val requestMiss   = Wire(Vec(groupWidth, Bool()))
  for (lane <- 0 until groupWidth) {
    requestActive(lane) := lane.U < acceptedBlocks
    requestMiss(lane)   := requestActive(lane) && !requestHit(lane)
  }

  val requestMissOH  = requestMiss.asUInt
  val requestHasMiss = requestMissOH.orR
  val firstMissIdx   = OHToUInt(PriorityEncoderOH(requestMissOH))

  io.resp.valid := state === ICacheState.SResp
  io.resp.bits  := 0.U.asTypeOf(new ICacheFetchGroupResp(cfg))
  for (lane <- 0 until groupWidth) {
    io.resp.bits.blocks(lane).valid := lane.U < groupCount
    io.resp.bits.blocks(lane).bits  := groupResp(lane)
  }

  val responseFire    = io.resp.fire
  val canAcceptGroup  = state === ICacheState.SIdle || (state === ICacheState.SResp && responseFire)
  io.req.ready        := canAcceptGroup && !io.invalidate
  io.acceptedBlocks   := acceptedBlocks

  val acceptGroup = io.req.fire

  val missBlockAddr = missReq.meta.blockAddr
  val missBank      = bankIndex(missBlockAddr)
  val missSet       = localSetIndex(missBlockAddr)
  val missTag       = tag(missBlockAddr)

  io.refillReq.valid     := state === ICacheState.SRefillReq && !killGroup && !io.invalidate
  io.refillReq.bits.addr := missBlockAddr
  io.refillResp.ready    := state === ICacheState.SRefillResp

  io.perf.request  := acceptGroup
  io.perf.hit      := acceptGroup && !requestHasMiss
  io.perf.miss     := acceptGroup && requestHasMiss
  io.perf.missWait := state === ICacheState.SRefillReq || state === ICacheState.SRefillResp

  val nextMissOH = VecInit((0 until groupWidth).map { lane =>
    pendingMiss(lane) && missSlot =/= lane.U
  }).asUInt
  val hasNextMiss = nextMissOH.orR
  val nextMissIdx = OHToUInt(PriorityEncoderOH(nextMissOH))

  when(io.invalidate) {
    validArray := VecInit(Seq.fill(cfg.bankCount)(VecInit(Seq.fill(cfg.bankSets)(false.B))))
    killGroup  := true.B
  }

  when(acceptGroup) {
    killGroup  := false.B
    groupCount := acceptedBlocks
    for (lane <- 0 until groupWidth) {
      groupReq(lane)    := io.req.bits.blocks(lane).bits
      pendingMiss(lane) := requestMiss(lane)
      groupResp(lane).meta            := io.req.bits.blocks(lane).bits.meta
      groupResp(lane).data            := requestData(lane)
      groupResp(lane).hit             := requestHit(lane)
      groupResp(lane).exception.valid := false.B
      groupResp(lane).exception.cause := 0.U
      groupResp(lane).exception.tval  := 0.U
    }
    when(requestHasMiss) {
      missSlot := firstMissIdx
      missReq  := Mux1H(PriorityEncoderOH(requestMissOH).asBools, io.req.bits.blocks.map(_.bits))
      state    := ICacheState.SRefillReq
    }.otherwise {
      state := ICacheState.SResp
    }
  }.elsewhen(state === ICacheState.SRefillReq) {
    when(io.invalidate) {
      state := ICacheState.SResp
    }.elsewhen(io.refillReq.fire) {
      state := ICacheState.SRefillResp
    }
  }.elsewhen(state === ICacheState.SRefillResp) {
    when(io.refillResp.fire) {
      groupResp(missSlot).data      := io.refillResp.bits.data
      groupResp(missSlot).meta      := missReq.meta
      groupResp(missSlot).hit       := false.B
      groupResp(missSlot).exception := io.refillResp.bits.exception
      when(io.refillResp.bits.exception.valid) {
        groupResp(missSlot).exception.tval := missReq.meta.control.pc
      }
      pendingMiss(missSlot) := false.B

      when(!io.refillResp.bits.exception.valid && !killGroup && !io.invalidate) {
        validArray(missBank)(missSet) := true.B
        tagArray(missBank)(missSet)   := missTag
        dataArray(missBank)(missSet)  := io.refillResp.bits.data
      }

      when(killGroup || io.invalidate || !hasNextMiss) {
        state := ICacheState.SResp
      }.otherwise {
        missSlot := nextMissIdx
        missReq  := groupReq(nextMissIdx)
        state    := ICacheState.SRefillReq
      }
    }
  }.elsewhen(state === ICacheState.SResp && responseFire) {
    state := ICacheState.SIdle
  }

  when(io.req.fire) {
    assert(io.req.bits.blocks(0).valid)
    when(acceptedBlocks === groupWidth.U) {
      assert(io.req.bits.blocks(1).bits.meta.blockAddr ===
        io.req.bits.blocks(0).bits.meta.blockAddr + cfg.fetchBytes.U)
      assert(io.req.bits.blocks(1).bits.meta.control.epoch ===
        io.req.bits.blocks(0).bits.meta.control.epoch)
      assert(io.req.bits.blocks(1).bits.meta.control.sequence ===
        io.req.bits.blocks(0).bits.meta.control.sequence + 1.U)
    }
  }
  when(io.resp.fire && groupCount === groupWidth.U) {
    assert(io.resp.bits.blocks(0).valid && io.resp.bits.blocks(1).valid)
    assert(io.resp.bits.blocks(1).bits.meta.blockAddr ===
      io.resp.bits.blocks(0).bits.meta.blockAddr + cfg.fetchBytes.U)
  }
  assert(PopCount(Seq(state === ICacheState.SRefillReq, state === ICacheState.SRefillResp)) <= 1.U)
}
