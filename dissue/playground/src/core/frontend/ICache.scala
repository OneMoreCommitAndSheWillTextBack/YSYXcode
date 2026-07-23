package top.core.frontend.icache

import chisel3._
import chisel3.util._
import top.config.ICacheConfig
import top.core.frontend.bundle.{
  ICacheFetchGroupReq,
  ICacheFetchGroupResp,
  ICacheRefillReq,
  ICacheRefillResp,
  ICacheReq,
  ICacheResp
}

class ICachePerf extends Bundle {
  val request           = Bool()
  val hit               = Bool()
  val miss              = Bool()
  val missWait          = Bool()
  val mshrActive        = Bool()
  val hitUnderMiss      = Bool()
  val sameLineWait      = Bool()
  val queuedMiss        = Bool()
  val staleResponseDrop = Bool()
}

class ICacheIO(cfg: ICacheConfig) extends Bundle {
  val req            = Flipped(Decoupled(new ICacheFetchGroupReq(cfg)))
  val acceptedBlocks = Output(UInt(log2Ceil(cfg.fetchGroupBlocks + 1).W))
  val resp           = Decoupled(new ICacheFetchGroupResp(cfg))
  val refillReq      = Decoupled(new ICacheRefillReq(cfg.addrWidth))
  val refillResp     = Flipped(Decoupled(new ICacheRefillResp(cfg.fetchBytes)))
  val invalidate     = Input(Bool())
  val redirect       = Input(Bool())
  val perf           = Output(new ICachePerf)
}

object ICacheMshrState extends ChiselEnum {
  val SIdle, SRefillReq, SRefillResp = Value
}

class ICache(cfg: ICacheConfig = ICacheConfig()) extends Module {
  private val groupWidth      = cfg.fetchGroupBlocks
  private val groupCountWidth = log2Ceil(groupWidth + 1)
  private val slotWidth       = math.max(log2Ceil(groupWidth), 1)

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

  private def responseForRequest(
    request: ICacheFetchGroupReq,
    count:   UInt,
    hit:     Vec[Bool],
    data:    Vec[UInt]
  ): ICacheFetchGroupResp = {
    val response = Wire(new ICacheFetchGroupResp(cfg))
    response := 0.U.asTypeOf(new ICacheFetchGroupResp(cfg))
    for (lane <- 0 until groupWidth) {
      response.blocks(lane).valid                := lane.U < count
      response.blocks(lane).bits.meta            := request.blocks(lane).bits.meta
      response.blocks(lane).bits.data            := data(lane)
      response.blocks(lane).bits.hit             := hit(lane)
      response.blocks(lane).bits.exception.valid := false.B
      response.blocks(lane).bits.exception.cause := 0.U
      response.blocks(lane).bits.exception.tval  := 0.U
    }
    response
  }

  private def refillResponse(request: ICacheReq, refill: ICacheRefillResp): ICacheResp = {
    val response = Wire(new ICacheResp(cfg))
    response.meta      := request.meta
    response.data      := refill.data
    response.hit       := false.B
    response.exception := refill.exception
    when(refill.exception.valid) {
      response.exception.tval := request.meta.control.pc
    }
    response
  }

  val validArray = RegInit(
    VecInit(Seq.fill(cfg.bankCount)(VecInit(Seq.fill(cfg.bankSets)(false.B))))
  )
  val tagArray   = Reg(Vec(cfg.bankCount, Vec(cfg.bankSets, UInt(cfg.tagBits.W))))
  val dataArray  = Reg(Vec(cfg.bankCount, Vec(cfg.bankSets, UInt(cfg.blockBits.W))))

  val mshrState   = RegInit(ICacheMshrState.SIdle)
  val mshrKilled  = RegInit(false.B)
  val mshrStale   = RegInit(false.B)
  val mshrCount   = RegInit(0.U(groupCountWidth.W))
  val mshrReq     = Reg(Vec(groupWidth, new ICacheReq(cfg)))
  val mshrResp    = Reg(Vec(groupWidth, new ICacheResp(cfg)))
  val mshrPending = RegInit(VecInit(Seq.fill(groupWidth)(false.B)))
  val mshrSlot    = RegInit(0.U(slotWidth.W))
  val mshrRefill  = Reg(new ICacheReq(cfg))

  val queuedValid = RegInit(false.B)
  val queuedCount = RegInit(0.U(groupCountWidth.W))
  val queuedReq   = Reg(new ICacheFetchGroupReq(cfg))

  val responseValid = RegInit(false.B)
  val responseReg   = Reg(new ICacheFetchGroupResp(cfg))

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
  val requestActive   = Wire(Vec(groupWidth, Bool()))
  val requestMiss     = Wire(Vec(groupWidth, Bool()))
  for (lane <- 0 until groupWidth) {
    requestActive(lane) := lane.U < acceptedBlocks
    requestMiss(lane)   := requestActive(lane) && !requestHit(lane)
  }
  val requestMissOH = requestMiss.asUInt
  val requestHasMiss = requestMissOH.orR
  val incomingResp   = responseForRequest(io.req.bits, acceptedBlocks, requestHit, requestData)

  val queuedBank = Wire(Vec(groupWidth, UInt(cfg.bankBits.W)))
  val queuedSet  = Wire(Vec(groupWidth, UInt(cfg.bankIdxBits.W)))
  val queuedTag  = Wire(Vec(groupWidth, UInt(cfg.tagBits.W)))
  val queuedHit  = Wire(Vec(groupWidth, Bool()))
  val queuedData = Wire(Vec(groupWidth, UInt(cfg.blockBits.W)))
  val queuedMiss = Wire(Vec(groupWidth, Bool()))
  for (lane <- 0 until groupWidth) {
    val blockAddr = queuedReq.blocks(lane).bits.meta.blockAddr
    queuedBank(lane) := bankIndex(blockAddr)
    queuedSet(lane)  := localSetIndex(blockAddr)
    queuedTag(lane)  := tag(blockAddr)
    queuedHit(lane)  := validArray(queuedBank(lane))(queuedSet(lane)) &&
      tagArray(queuedBank(lane))(queuedSet(lane)) === queuedTag(lane)
    queuedData(lane) := dataArray(queuedBank(lane))(queuedSet(lane))
    queuedMiss(lane) := lane.U < queuedCount && !queuedHit(lane)
  }
  val queuedMissOH = queuedMiss.asUInt
  val queuedHasMiss = queuedMissOH.orR
  val queuedResp    = responseForRequest(queuedReq, queuedCount, queuedHit, queuedData)

  // mshrActive 当前是否有未完成 miss
  val mshrActive               = mshrState =/= ICacheMshrState.SIdle
  val requestSharesMshr        = VecInit((0 until groupWidth).map { requestLane =>
    requestActive(requestLane) && requestMiss(requestLane) &&
    VecInit((0 until groupWidth).map { mshrLane =>
      mshrPending(mshrLane) &&
      io.req.bits.blocks(requestLane).bits.meta.blockAddr === mshrReq(mshrLane).meta.blockAddr
    }).asUInt.orR
  }).asUInt.orR
  val requestSharesQueued      = queuedValid && VecInit((0 until groupWidth).map { requestLane =>
    requestActive(requestLane) && requestMiss(requestLane) &&
    VecInit((0 until groupWidth).map { queuedLane =>
      queuedMiss(queuedLane) &&
      io.req.bits.blocks(requestLane).bits.meta.blockAddr === queuedReq.blocks(queuedLane).bits.meta.blockAddr
    }).asUInt.orR
  }).asUInt.orR
  val requestSharesOutstanding = requestSharesMshr || requestSharesQueued

  val responseFire      = io.resp.fire
  val responseAvailable = !responseValid || responseFire
  val queuedLaunch      = !mshrActive && queuedValid

  io.resp.valid     := responseValid
  io.resp.bits      := responseReg
  io.acceptedBlocks := acceptedBlocks

  // 当前 MSHR 正在等回包，而且回包已经到 ICache 门口。本拍优先处理它，不再同时接收一个
  // hit group，避免争同一个 responseReg 和状态更新路径。
  val refillResponsePending = mshrState === ICacheMshrState.SRefillResp && io.refillResp.valid

  //  当前有 miss 在飞，但新 group 全命中，可以直接返回。这就是 hit-under-miss。
  val acceptHitUnderMiss = mshrActive && !requestHasMiss && !refillResponsePending && responseAvailable

  //  当前有一个 MSHR正在工作，新 group 也 miss，但不是同一条正在等待的 cache block，
  //  且 queued slot 为空，所以先把新 group 暂存进 queuedReq。
  val acceptQueuedMiss = mshrActive && requestHasMiss && !requestSharesMshr && !queuedValid

  //  当前没有未完成 miss，新 group miss，可以直接分配 MSHR。
  val acceptFreshMiss = !mshrActive && !queuedValid && requestHasMiss

  //  当前空闲，新 group 全命中，且 response 槽能放下，直接接收。
  val acceptFreshHit = !mshrActive && !queuedValid && !requestHasMiss && responseAvailable

  io.req.ready := !io.invalidate && !io.redirect && !queuedLaunch &&
    (acceptHitUnderMiss || acceptQueuedMiss || acceptFreshMiss || acceptFreshHit)
  val acceptGroup = io.req.fire

  val nextMissOH  = VecInit((0 until groupWidth).map { lane =>
    mshrPending(lane) && mshrSlot =/= lane.U(slotWidth.W)
  }).asUInt
  val hasNextMiss = nextMissOH.orR
  val nextMissIdx = OHToUInt(PriorityEncoderOH(nextMissOH))

  val currentRefillResp = refillResponse(mshrRefill, io.refillResp.bits)
  val completedMshrResp = Wire(new ICacheFetchGroupResp(cfg))
  completedMshrResp := 0.U.asTypeOf(new ICacheFetchGroupResp(cfg))
  for (lane <- 0 until groupWidth) {
    val laneResp = Wire(new ICacheResp(cfg))
    laneResp                             := mshrResp(lane)
    when(mshrSlot === lane.U(slotWidth.W)) {
      laneResp := currentRefillResp
    }
    completedMshrResp.blocks(lane).valid := lane.U < mshrCount
    completedMshrResp.blocks(lane).bits  := laneResp
  }

  val refillBlockAddr = mshrRefill.meta.blockAddr
  val refillBank      = bankIndex(refillBlockAddr)
  val refillSet       = localSetIndex(refillBlockAddr)
  val refillTag       = tag(refillBlockAddr)

  val discardMshrResponse = mshrKilled || mshrStale || io.redirect

  io.refillReq.valid     := mshrState === ICacheMshrState.SRefillReq && !mshrKilled && !io.invalidate && !io.redirect
  io.refillReq.bits.addr := refillBlockAddr
  io.refillResp.ready    := mshrState === ICacheMshrState.SRefillResp && !io.invalidate &&
    (discardMshrResponse || hasNextMiss || responseAvailable)

  io.perf.request           := acceptGroup
  io.perf.hit               := acceptGroup && !requestHasMiss
  io.perf.miss              := acceptGroup && requestHasMiss
  // Keep miss-wait stall-oriented; raw MSHR occupancy is reported separately.
  io.perf.missWait          := mshrActive && !acceptHitUnderMiss && !responseFire
  io.perf.mshrActive        := mshrActive
  io.perf.hitUnderMiss      := acceptGroup && mshrActive && !requestHasMiss
  io.perf.sameLineWait      := io.req.valid && mshrActive && requestHasMiss && requestSharesOutstanding &&
    !io.invalidate && !io.redirect
  io.perf.queuedMiss        := acceptGroup && mshrActive && requestHasMiss
  io.perf.staleResponseDrop := io.refillResp.fire && discardMshrResponse

  when(io.invalidate) {
    validArray    := VecInit(Seq.fill(cfg.bankCount)(VecInit(Seq.fill(cfg.bankSets)(false.B))))
    responseValid := false.B
    queuedValid   := false.B
    mshrStale     := false.B
    when(mshrState === ICacheMshrState.SRefillReq) {
      mshrState   := ICacheMshrState.SIdle
      mshrKilled  := false.B
      mshrPending := VecInit(Seq.fill(groupWidth)(false.B))
    }.elsewhen(mshrState === ICacheMshrState.SRefillResp) {
      mshrKilled := true.B
    }
  }.otherwise {
    when(io.redirect) {
      responseValid := false.B
      queuedValid   := false.B
      when(mshrState === ICacheMshrState.SRefillReq) {
        mshrState   := ICacheMshrState.SIdle
        mshrStale   := false.B
        mshrPending := VecInit(Seq.fill(groupWidth)(false.B))
      }.elsewhen(mshrState === ICacheMshrState.SRefillResp) {
        mshrStale := true.B
      }
    }.otherwise {
      when(responseFire) {
        responseValid := false.B
      }

      when(queuedLaunch) {
        when(queuedHasMiss) {
          mshrCount := queuedCount
          for (lane <- 0 until groupWidth) {
            mshrReq(lane)     := queuedReq.blocks(lane).bits
            mshrResp(lane)    := queuedResp.blocks(lane).bits
            mshrPending(lane) := queuedMiss(lane)
          }
          mshrSlot := OHToUInt(PriorityEncoderOH(queuedMissOH))
          mshrRefill  := Mux1H(PriorityEncoderOH(queuedMissOH).asBools, queuedReq.blocks.map(_.bits))
          mshrKilled  := false.B
          mshrStale   := false.B
          mshrState   := ICacheMshrState.SRefillReq
          queuedValid := false.B
        }.elsewhen(responseAvailable) {
          responseReg   := queuedResp
          responseValid := true.B
          queuedValid   := false.B
        }
      }

      // A cache request can arrive in the cycle the scalar refill request or
      // response handshakes. Keep those state transitions independent: otherwise
      // a queued group can leave the MSHR waiting for a response it never enables.
      when(acceptGroup) {
        when(mshrActive && requestHasMiss) {
          queuedReq   := io.req.bits
          queuedCount := acceptedBlocks
          queuedValid := true.B
        }.elsewhen(requestHasMiss) {
          mshrCount := acceptedBlocks
          for (lane <- 0 until groupWidth) {
            mshrReq(lane)     := io.req.bits.blocks(lane).bits
            mshrResp(lane)    := incomingResp.blocks(lane).bits
            mshrPending(lane) := requestMiss(lane)
          }
          mshrSlot := OHToUInt(PriorityEncoderOH(requestMissOH))
          mshrRefill := Mux1H(PriorityEncoderOH(requestMissOH).asBools, io.req.bits.blocks.map(_.bits))
          mshrKilled := false.B
          mshrStale  := false.B
          mshrState  := ICacheMshrState.SRefillReq
        }.otherwise {
          responseReg   := incomingResp
          responseValid := true.B
        }
      }
    }

    when(mshrState === ICacheMshrState.SRefillReq) {
      when(io.refillReq.fire) {
        mshrState := ICacheMshrState.SRefillResp
      }
    }

    when(mshrState === ICacheMshrState.SRefillResp && io.refillResp.fire) {
      for (lane <- 0 until groupWidth) {
        when(mshrSlot === lane.U(slotWidth.W)) {
          mshrResp(lane)    := currentRefillResp
          mshrPending(lane) := false.B
        }
      }

      // Redirected refills may warm the cache, while fence-killed refills must not repopulate it.
      when(!io.refillResp.bits.exception.valid && !mshrKilled) {
        validArray(refillBank)(refillSet) := true.B
        tagArray(refillBank)(refillSet)   := refillTag
        dataArray(refillBank)(refillSet)  := io.refillResp.bits.data
      }

      when(discardMshrResponse) {
        mshrState   := ICacheMshrState.SIdle
        mshrKilled  := false.B
        mshrStale   := false.B
        mshrPending := VecInit(Seq.fill(groupWidth)(false.B))
      }.elsewhen(hasNextMiss) {
        mshrSlot   := nextMissIdx
        mshrRefill := mshrReq(nextMissIdx)
        mshrState  := ICacheMshrState.SRefillReq
      }.otherwise {
        responseReg   := completedMshrResp
        responseValid := true.B
        mshrState     := ICacheMshrState.SIdle
      }
    }
  }

  when(io.req.fire) {
    assert(io.req.bits.blocks(0).valid)
    when(acceptedBlocks === groupWidth.U) {
      assert(
        io.req.bits.blocks(1).bits.meta.blockAddr ===
          io.req.bits.blocks(0).bits.meta.blockAddr + cfg.fetchBytes.U
      )
      assert(
        io.req.bits.blocks(1).bits.meta.control.epoch ===
          io.req.bits.blocks(0).bits.meta.control.epoch
      )
      assert(
        io.req.bits.blocks(1).bits.meta.control.sequence ===
          io.req.bits.blocks(0).bits.meta.control.sequence + 1.U
      )
      assert(
        io.req.bits.blocks(1).bits.meta.control.ftqIndex ===
          io.req.bits.blocks(0).bits.meta.control.ftqIndex + 1.U
      )
    }
    when(mshrActive && requestHasMiss) {
      assert(!requestSharesMshr)
      assert(!queuedValid)
    }
  }

  when(
    io.req.valid && mshrActive && requestHasMiss && requestSharesOutstanding &&
      !io.invalidate && !io.redirect
  ) {
    assert(!io.req.ready)
  }

  when(io.resp.valid) {
    assert(io.resp.bits.blocks(0).valid)
    when(io.resp.bits.blocks(1).valid) {
      assert(
        io.resp.bits.blocks(1).bits.meta.blockAddr ===
          io.resp.bits.blocks(0).bits.meta.blockAddr + cfg.fetchBytes.U
      )
      assert(
        io.resp.bits.blocks(1).bits.meta.control.epoch ===
          io.resp.bits.blocks(0).bits.meta.control.epoch
      )
      assert(
        io.resp.bits.blocks(1).bits.meta.control.sequence ===
          io.resp.bits.blocks(0).bits.meta.control.sequence + 1.U
      )
    }
  }

  when(io.refillReq.fire) {
    assert(mshrState === ICacheMshrState.SRefillReq)
    assert(mshrPending(mshrSlot))
  }
  when(io.refillResp.fire) {
    assert(mshrState === ICacheMshrState.SRefillResp)
    assert(mshrPending(mshrSlot))
  }
  when(mshrActive) {
    assert(PopCount(mshrPending) =/= 0.U)
    assert(mshrPending(mshrSlot))
  }
  assert(
    PopCount(
      Seq(
        mshrState === ICacheMshrState.SRefillReq,
        mshrState === ICacheMshrState.SRefillResp
      )
    ) <= 1.U
  )
}
