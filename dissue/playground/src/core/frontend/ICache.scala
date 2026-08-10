package top.core.frontend.icache

import chisel3._
import chisel3.util.{log2Ceil, Cat, Decoupled, Mux1H, OHToUInt, PriorityEncoderOH, Valid}
import top.config.FrontendConfig
import top.core.frontend.bundle.{
  FrontendRecovery,
  ICacheBlockData,
  ICacheFetchReq,
  ICacheFetchResp,
  ICacheLookupResult,
  ICacheRefillReq,
  ICacheRefillResp
}

class ICacheIO(cfg: FrontendConfig) extends Bundle {
  val req        = Flipped(Decoupled(new ICacheFetchReq(cfg)))
  val resp       = Decoupled(new ICacheFetchResp(cfg))
  val refillReq  = Decoupled(new ICacheRefillReq(cfg.addrWidth))
  val refillResp = Flipped(Decoupled(new ICacheRefillResp(cfg.icacheLineBytes)))
  val invalidate = Input(Bool())
  val recovery   = Flipped(Valid(new FrontendRecovery(cfg)))

  val lookup = Output(Valid(new ICacheLookupResult(cfg)))
}

object ICacheMissState extends ChiselEnum {
  val idle, refillRequest, refillResponse = Value
}

/** Pipelined-on-hit instruction cache with one blocking miss group.
  *
  * Fetch blocks and cache lines are independent sizes. A miss group refills each distinct line once, then extracts all
  * requested fetch blocks from the returned line before producing its single in-order response. The registered R0/R1
  * lookup still accepts and returns one hit group per cycle for both direct-mapped and two-way configurations.
  */
class ICache(cfg: FrontendConfig = FrontendConfig()) extends Module {
  private val cacheCfg   = cfg.icache
  private val groupWidth = cfg.fetchGroupBlocks
  private val slotWidth  = math.max(log2Ceil(groupWidth), 1)

  val io = IO(new ICacheIO(cfg))

  private def lineAddress(addr: UInt): UInt =
    Cat(addr(cacheCfg.addrWidth - 1, cacheCfg.lineOffsetBits), 0.U(cacheCfg.lineOffsetBits.W))

  private def globalSetIndex(addr: UInt): UInt = {
    if (cacheCfg.indexBits == 0) 0.U(cacheCfg.setIdxBits.W)
    else addr(cacheCfg.lineOffsetBits + cacheCfg.indexBits - 1, cacheCfg.lineOffsetBits)
  }

  private def bankIndex(addr: UInt): UInt =
    globalSetIndex(addr)(cacheCfg.bankBits - 1, 0)

  private def localSetIndex(addr: UInt): UInt = {
    if (cacheCfg.bankIndexBits == 0) 0.U(cacheCfg.bankIdxBits.W)
    else globalSetIndex(addr)(cacheCfg.indexBits - 1, cacheCfg.bankBits)
  }

  private def tag(addr: UInt): UInt =
    addr(cacheCfg.addrWidth - 1, cacheCfg.lineOffsetBits + cacheCfg.indexBits)

  private def blockSelect(addr: UInt): UInt = {
    if (cacheCfg.blocksPerLine == 1) 0.U(cacheCfg.blockSelectBits.W)
    else addr(cacheCfg.lineOffsetBits - 1, cacheCfg.offsetBits)
  }

  private def fetchBlock(line: UInt, addr: UInt): UInt = {
    if (cacheCfg.blocksPerLine == 1) line(cacheCfg.fetchBytes * 8 - 1, 0)
    else {
      val bitOffset = blockSelect(addr) << log2Ceil(cacheCfg.fetchBytes * 8)
      (line >> bitOffset)(cacheCfg.fetchBytes * 8 - 1, 0)
    }
  }

  val validArray     = RegInit(
    VecInit(
      Seq.fill(cacheCfg.bankCount)(
        VecInit(Seq.fill(cacheCfg.bankSets)(VecInit(Seq.fill(cacheCfg.ways)(false.B))))
      )
    )
  )
  val tagArray       = Reg(
    Vec(cacheCfg.bankCount, Vec(cacheCfg.bankSets, Vec(cacheCfg.ways, UInt(cacheCfg.tagBits.W))))
  )
  val dataArray      = Reg(
    Vec(cacheCfg.bankCount, Vec(cacheCfg.bankSets, Vec(cacheCfg.ways, UInt(cacheCfg.lineBits.W))))
  )
  val replacementWay = RegInit(
    VecInit(Seq.fill(cacheCfg.bankCount)(VecInit(Seq.fill(cacheCfg.bankSets)(0.U(cacheCfg.wayIdxBits.W)))))
  )

  val responseValid = RegInit(false.B)
  val responseReg   = Reg(new ICacheFetchResp(cfg))

  val r1Valid = RegInit(false.B)
  val r1Req   = Reg(new ICacheFetchReq(cfg))

  val replayValid = RegInit(false.B)
  val replayReq   = Reg(new ICacheFetchReq(cfg))

  val missState                = RegInit(ICacheMissState.idle)
  val missReq                  = Reg(new ICacheFetchReq(cfg))
  val missBlocks               = Reg(Vec(groupWidth, new ICacheBlockData(cfg)))
  val missingMask              = RegInit(0.U(groupWidth.W))
  val refillSlot               = RegInit(0.U(slotWidth.W))
  val missKilled               = RegInit(false.B)
  val invalidateGeneration     = RegInit(0.U(cfg.fetchEpochBits.W))
  val missInvalidateGeneration = Reg(UInt(cfg.fetchEpochBits.W))

  // These are resolved by the refill path below and feed completion-cycle request turnover.
  val refillCompletesGroup = Wire(Bool())
  val turnoverProbeMiss    = Wire(Bool())

  val r1Bank   = Wire(Vec(groupWidth, UInt(cacheCfg.bankBits.W)))
  val r1Set    = Wire(Vec(groupWidth, UInt(cacheCfg.bankIdxBits.W)))
  val r1Tag    = Wire(Vec(groupWidth, UInt(cacheCfg.tagBits.W)))
  val r1WayHit = Wire(Vec(groupWidth, Vec(cacheCfg.ways, Bool())))
  val r1HitWay = Wire(Vec(groupWidth, UInt(cacheCfg.wayIdxBits.W)))
  val r1Hit    = Wire(Vec(groupWidth, Bool()))
  val r1Data   = Wire(Vec(groupWidth, UInt((cacheCfg.fetchBytes * 8).W)))
  for (lane <- 0 until groupWidth) {
    r1Bank(lane) := bankIndex(r1Req.blockAddr(lane))
    r1Set(lane)  := localSetIndex(r1Req.blockAddr(lane))
    r1Tag(lane)  := tag(r1Req.blockAddr(lane))
    for (way <- 0 until cacheCfg.ways) {
      r1WayHit(lane)(way) := r1Req.blockValid(lane) && validArray(r1Bank(lane))(r1Set(lane))(way) &&
        tagArray(r1Bank(lane))(r1Set(lane))(way) === r1Tag(lane)
    }
    r1Hit(lane) := r1WayHit(lane).asUInt.orR
    r1HitWay(lane) := OHToUInt(r1WayHit(lane))
    val lineData = Mux1H(r1WayHit(lane), dataArray(r1Bank(lane))(r1Set(lane)))
    r1Data(lane) := Mux(r1Hit(lane), fetchBlock(lineData, r1Req.blockAddr(lane)), 0.U)
  }

  val r1HitMask     = r1Hit.asUInt
  val r1MissingMask = VecInit((0 until groupWidth).map(lane => r1Req.blockValid(lane) && !r1Hit(lane))).asUInt
  val r1HasMiss     = r1MissingMask.orR

  val r1Response = Wire(new ICacheFetchResp(cfg))
  r1Response       := 0.U.asTypeOf(new ICacheFetchResp(cfg))
  r1Response.token := r1Req.token
  for (lane <- 0 until groupWidth) {
    r1Response.blocks(lane).valid                := r1Req.blockValid(lane)
    r1Response.blocks(lane).bits.data            := r1Data(lane)
    r1Response.blocks(lane).bits.hit             := r1Hit(lane)
    r1Response.blocks(lane).bits.exception.valid := false.B
    r1Response.blocks(lane).bits.exception.cause := 0.U
    r1Response.blocks(lane).bits.exception.tval  := 0.U
  }

  io.resp.valid := responseValid && !io.invalidate && !io.recovery.valid
  io.resp.bits  := responseReg
  val responseFire      = io.resp.fire
  val responseAvailable = !responseValid || responseFire

  val r1CanAdvance          = r1Valid && missState === ICacheMissState.idle && (r1HasMiss || responseAvailable)
  val canAcceptR0           = missState === ICacheMissState.idle && !replayValid && (!r1Valid || r1CanAdvance)
  val completionCanAcceptR0 = refillCompletesGroup && (!replayValid || turnoverProbeMiss)
  io.req.ready := (canAcceptR0 || completionCanAcceptR0) && !io.invalidate && !io.recovery.valid

  io.lookup.valid            := r1CanAdvance && !io.invalidate && !io.recovery.valid
  io.lookup.bits.token       := r1Req.token
  io.lookup.bits.blockAddr   := r1Req.blockAddr
  io.lookup.bits.blockValid  := r1Req.blockValid
  io.lookup.bits.hitMask     := r1HitMask
  io.lookup.bits.missingMask := r1MissingMask

  val refillAddress  = lineAddress(missReq.blockAddr(refillSlot))
  val refillLineMask = VecInit((0 until groupWidth).map { lane =>
    missingMask(lane) && lineAddress(missReq.blockAddr(lane)) === refillAddress
  }).asUInt

  val remainingMask            = missingMask & ~refillLineMask
  val nextRefillSlot           = OHToUInt(PriorityEncoderOH(remainingMask))
  val nextRefillAddress        = lineAddress(missReq.blockAddr(nextRefillSlot))
  val missGenerationLive       = missInvalidateGeneration === invalidateGeneration
  val functionalMissLive       = !missKilled && missGenerationLive && !io.invalidate && !io.recovery.valid
  val finalRefillNeedsResponse = !remainingMask.orR && functionalMissLive

  io.refillResp.ready := missState === ICacheMissState.refillResponse &&
    !io.invalidate && !io.recovery.valid && (!finalRefillNeedsResponse || responseAvailable)

  val intermediateRefillTurnover = io.refillResp.fire && remainingMask.orR && functionalMissLive
  io.refillReq.valid     := (missState === ICacheMissState.refillRequest || intermediateRefillTurnover) &&
    !missKilled && !io.invalidate && !io.recovery.valid
  io.refillReq.bits.addr := Mux(intermediateRefillTurnover, nextRefillAddress, refillAddress)

  refillCompletesGroup := io.refillResp.fire && (!remainingMask.orR || !functionalMissLive)

  val completedResponse = Wire(new ICacheFetchResp(cfg))
  completedResponse       := 0.U.asTypeOf(new ICacheFetchResp(cfg))
  completedResponse.token := missReq.token
  for (lane <- 0 until groupWidth) {
    completedResponse.blocks(lane).valid := missReq.blockValid(lane)
    completedResponse.blocks(lane).bits  := missBlocks(lane)
    when(refillLineMask(lane)) {
      completedResponse.blocks(lane).bits.data      := fetchBlock(io.refillResp.bits.data, missReq.blockAddr(lane))
      completedResponse.blocks(lane).bits.hit       := false.B
      completedResponse.blocks(lane).bits.exception := io.refillResp.bits.exception
      when(io.refillResp.bits.exception.valid) {
        completedResponse.blocks(lane).bits.exception.tval := missReq.blockAddr(lane)
      }
    }
  }

  val refillBank       = bankIndex(refillAddress)
  val refillSet        = localSetIndex(refillAddress)
  val refillTag        = tag(refillAddress)
  val refillWayHit     = Wire(Vec(cacheCfg.ways, Bool()))
  val refillInvalidWay = Wire(Vec(cacheCfg.ways, Bool()))
  for (way <- 0 until cacheCfg.ways) {
    refillWayHit(way)     := validArray(refillBank)(refillSet)(way) && tagArray(refillBank)(refillSet)(way) === refillTag
    refillInvalidWay(way) := !validArray(refillBank)(refillSet)(way)
  }
  val refillHasHit = refillWayHit.asUInt.orR
  val refillHasInvalid = refillInvalidWay.asUInt.orR
  val refillWay        = if (cacheCfg.ways == 1) {
    0.U(cacheCfg.wayIdxBits.W)
  } else {
    Mux(
      refillHasHit,
      OHToUInt(refillWayHit),
      Mux(refillHasInvalid, OHToUInt(PriorityEncoderOH(refillInvalidWay.asUInt)), replacementWay(refillBank)(refillSet))
    )
  }

  val turnoverReq = Wire(new ICacheFetchReq(cfg))
  turnoverReq := Mux(replayValid, replayReq, io.req.bits)

  val turnoverBank   = Wire(Vec(groupWidth, UInt(cacheCfg.bankBits.W)))
  val turnoverSet    = Wire(Vec(groupWidth, UInt(cacheCfg.bankIdxBits.W)))
  val turnoverWayHit = Wire(Vec(groupWidth, Vec(cacheCfg.ways, Bool())))
  val turnoverHitWay = Wire(Vec(groupWidth, UInt(cacheCfg.wayIdxBits.W)))
  val turnoverHit    = Wire(Vec(groupWidth, Bool()))
  val turnoverData   = Wire(Vec(groupWidth, UInt((cacheCfg.fetchBytes * 8).W)))
  for (lane <- 0 until groupWidth) {
    turnoverBank(lane) := bankIndex(turnoverReq.blockAddr(lane))
    turnoverSet(lane)  := localSetIndex(turnoverReq.blockAddr(lane))
    val requestTag = tag(turnoverReq.blockAddr(lane))
    for (way <- 0 until cacheCfg.ways) {
      turnoverWayHit(lane)(way) := turnoverReq.blockValid(lane) &&
        validArray(turnoverBank(lane))(turnoverSet(lane))(way) &&
        tagArray(turnoverBank(lane))(turnoverSet(lane))(way) === requestTag
    }
    val refillBypassHit = turnoverReq.blockValid(lane) && io.refillResp.fire && missGenerationLive &&
      !io.refillResp.bits.exception.valid && lineAddress(turnoverReq.blockAddr(lane)) === refillAddress
    val arrayHitData = Mux1H(turnoverWayHit(lane), dataArray(turnoverBank(lane))(turnoverSet(lane)))
    turnoverHitWay(lane) := OHToUInt(turnoverWayHit(lane))
    turnoverHit(lane)    := turnoverWayHit(lane).asUInt.orR || refillBypassHit
    turnoverData(lane)   := Mux(
      refillBypassHit,
      fetchBlock(io.refillResp.bits.data, turnoverReq.blockAddr(lane)),
      Mux(turnoverWayHit(lane).asUInt.orR, fetchBlock(arrayHitData, turnoverReq.blockAddr(lane)), 0.U)
    )
  }

  val turnoverCandidateValid    = replayValid || io.req.valid
  val turnoverCandidateAccepted = refillCompletesGroup && (replayValid || io.req.fire)
  val turnoverHitMask           = turnoverHit.asUInt
  val turnoverMissingMask       = VecInit(
    (0 until groupWidth).map(lane => turnoverReq.blockValid(lane) && !turnoverHit(lane))
  ).asUInt
  turnoverProbeMiss := refillCompletesGroup && turnoverCandidateValid && turnoverMissingMask.orR
  val turnoverMissAction = turnoverCandidateAccepted && turnoverMissingMask.orR

  val turnoverResponse = Wire(new ICacheFetchResp(cfg))
  turnoverResponse       := 0.U.asTypeOf(new ICacheFetchResp(cfg))
  turnoverResponse.token := turnoverReq.token
  for (lane <- 0 until groupWidth) {
    turnoverResponse.blocks(lane).valid                := turnoverReq.blockValid(lane)
    turnoverResponse.blocks(lane).bits.data            := turnoverData(lane)
    turnoverResponse.blocks(lane).bits.hit             := turnoverHit(lane)
    turnoverResponse.blocks(lane).bits.exception.valid := false.B
    turnoverResponse.blocks(lane).bits.exception.cause := 0.U
    turnoverResponse.blocks(lane).bits.exception.tval  := 0.U
  }

  when(turnoverMissAction) {
    io.lookup.valid            := true.B
    io.lookup.bits.token       := turnoverReq.token
    io.lookup.bits.blockAddr   := turnoverReq.blockAddr
    io.lookup.bits.blockValid  := turnoverReq.blockValid
    io.lookup.bits.hitMask     := turnoverHitMask
    io.lookup.bits.missingMask := turnoverMissingMask
  }

  when(io.invalidate) {
    validArray           := VecInit(
      Seq.fill(cacheCfg.bankCount)(
        VecInit(Seq.fill(cacheCfg.bankSets)(VecInit(Seq.fill(cacheCfg.ways)(false.B))))
      )
    )
    invalidateGeneration := invalidateGeneration +% 1.U
    responseValid        := false.B
    r1Valid              := false.B
    replayValid          := false.B
    when(missState === ICacheMissState.refillResponse) {
      missKilled := true.B
    }.otherwise {
      missState  := ICacheMissState.idle
      missKilled := false.B
    }
  }.elsewhen(io.recovery.valid) {
    responseValid := false.B
    r1Valid       := false.B
    replayValid   := false.B
    when(missState === ICacheMissState.refillResponse) {
      missKilled := true.B
    }.otherwise {
      missState  := ICacheMissState.idle
      missKilled := false.B
    }
  }.otherwise {
    when(responseFire) {
      responseValid := false.B
    }

    if (cacheCfg.ways == 2) {
      when(r1CanAdvance) {
        for (lane <- 0 until groupWidth) {
          when(r1Hit(lane)) {
            replacementWay(r1Bank(lane))(r1Set(lane)) := ~r1HitWay(lane)
          }
        }
      }
    }

    when(missState === ICacheMissState.idle) {
      when(r1CanAdvance) {
        when(r1HasMiss) {
          missReq                  := r1Req
          missingMask              := r1MissingMask
          refillSlot               := OHToUInt(PriorityEncoderOH(r1MissingMask))
          missKilled               := false.B
          missInvalidateGeneration := invalidateGeneration
          missState                := ICacheMissState.refillRequest
          for (lane <- 0 until groupWidth) {
            missBlocks(lane)                 := r1Response.blocks(lane).bits
            missBlocks(lane).hit             := r1Hit(lane)
            missBlocks(lane).exception.valid := false.B
            missBlocks(lane).exception.cause := 0.U
            missBlocks(lane).exception.tval  := 0.U
          }
          r1Valid := false.B
          when(io.req.fire) {
            replayReq   := io.req.bits
            replayValid := true.B
          }
        }.otherwise {
          responseReg   := r1Response
          responseValid := true.B
          when(io.req.fire) {
            r1Req   := io.req.bits
            r1Valid := true.B
          }.otherwise {
            r1Valid := false.B
          }
        }
      }.elsewhen(io.req.fire) {
        r1Req   := io.req.bits
        r1Valid := true.B
      }
    }

    when(io.refillReq.fire) {
      missState := ICacheMissState.refillResponse
    }

    when(io.refillResp.fire) {
      when(missGenerationLive && !io.refillResp.bits.exception.valid) {
        validArray(refillBank)(refillSet)(refillWay) := true.B
        tagArray(refillBank)(refillSet)(refillWay)   := refillTag
        dataArray(refillBank)(refillSet)(refillWay)  := io.refillResp.bits.data
        if (cacheCfg.ways == 2) {
          replacementWay(refillBank)(refillSet) := ~refillWay
        }
      }

      for (lane <- 0 until groupWidth) {
        when(refillLineMask(lane)) {
          missBlocks(lane) := completedResponse.blocks(lane).bits
        }
      }
      missingMask := remainingMask

      when(remainingMask.orR && functionalMissLive) {
        refillSlot := nextRefillSlot
        missState  := Mux(io.refillReq.fire, ICacheMissState.refillResponse, ICacheMissState.refillRequest)
      }.otherwise {
        missState  := ICacheMissState.idle
        missKilled := false.B
        when(functionalMissLive) {
          responseReg   := completedResponse
          responseValid := true.B
        }

        when(turnoverMissAction) {
          missReq                  := turnoverReq
          missingMask              := turnoverMissingMask
          refillSlot               := OHToUInt(PriorityEncoderOH(turnoverMissingMask))
          missKilled               := false.B
          missInvalidateGeneration := invalidateGeneration
          missState                := ICacheMissState.refillRequest
          r1Valid                  := false.B
          for (lane <- 0 until groupWidth) {
            missBlocks(lane) := turnoverResponse.blocks(lane).bits
          }
          when(replayValid && io.req.fire) {
            replayReq   := io.req.bits
            replayValid := true.B
          }.otherwise {
            replayValid := false.B
          }
          if (cacheCfg.ways == 2) {
            for (lane <- 0 until groupWidth) {
              when(turnoverWayHit(lane).asUInt.orR) {
                replacementWay(turnoverBank(lane))(turnoverSet(lane)) := ~turnoverHitWay(lane)
              }
            }
          }
        }.elsewhen(turnoverCandidateAccepted) {
          r1Req       := turnoverReq
          r1Valid     := true.B
          replayValid := false.B
        }.otherwise {
          r1Valid     := false.B
          replayValid := false.B
        }
      }
    }
  }

  when(io.req.fire) {
    assert(io.req.bits.blockValid(0))
    for (lane <- 0 until groupWidth) {
      when(io.req.bits.blockValid(lane)) {
        assert(io.req.bits.blockAddr(lane)(cacheCfg.offsetBits - 1, 0) === 0.U)
      }
      if (lane > 0) {
        when(io.req.bits.blockValid(lane)) {
          assert(io.req.bits.blockValid(lane - 1))
        }
      }
    }
  }
  when(io.lookup.valid) {
    assert((io.lookup.bits.hitMask & io.lookup.bits.missingMask) === 0.U)
    assert((io.lookup.bits.hitMask | io.lookup.bits.missingMask) === io.lookup.bits.blockValid.asUInt)
  }
  when(missState =/= ICacheMissState.idle) {
    assert(missingMask.orR)
  }
  when(replayValid) {
    assert(missState =/= ICacheMissState.idle)
  }
}
