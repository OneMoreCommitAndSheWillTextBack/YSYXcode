package top.core.frontend.ifetch

import chisel3._
import chisel3.util._
import top.config.{ICacheConfig, IFetchConfig}
import top.core.frontend.bundle.{FetchControlMeta, FetchInst, FetchPred, ICacheFetchGroupReq, ICacheFetchGroupResp, ICacheReq, ICacheResp, PcRedirect}

object FetchWidth {
  val backend                = 2
  val frontend               = 4
  val maxInstructionHalfwords = 2
}

class FetchPacket extends Bundle {
  val insts = Vec(FetchWidth.backend, Valid(new FetchInst))
}

class HalfwordEntry(cfg: ICacheConfig) extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val bits      = UInt(16.W)
  val blockAddr = UInt(cfg.addrWidth.W)
  val control   = new FetchControlMeta(cfg)
  val exception = new top.core.bundle.FetchException(cfg.addrWidth)
}

class HalfwordSplitter(cfg: ICacheConfig) extends Module {
  require(cfg.fetchBytes == 8, "HalfwordSplitter currently assumes a 64-bit ICache fetch block")

  private val fetchHalfwords = cfg.fetchBytes / 2
  private val countWidth     = log2Ceil(fetchHalfwords + 1)

  val io = IO(new Bundle {
    val resp    = Input(new ICacheResp(cfg))
    val entries = Output(Vec(fetchHalfwords, new HalfwordEntry(cfg)))
    val count   = Output(UInt(countWidth.W))
  })

  val rawHalfwords = Wire(Vec(fetchHalfwords, UInt(16.W)))
  for (i <- 0 until fetchHalfwords) {
    rawHalfwords(i) := io.resp.data(16 * (i + 1) - 1, 16 * i)
  }

  val startHalfword = io.resp.meta.control.pc(cfg.offsetBits - 1, 1)
  val startCount    = Wire(UInt(countWidth.W))
  startCount := startHalfword

  val basePc = io.resp.meta.blockAddr +% (startCount << 1)

  io.count := fetchHalfwords.U(countWidth.W) - startCount

  val startOH = UIntToOH(startCount, fetchHalfwords)

  for (i <- 0 until fetchHalfwords) {
    io.entries(i).pc        := basePc +% (2 * i).U(cfg.addrWidth.W)
    io.entries(i).bits      := Mux1H((0 until fetchHalfwords).map { s =>
      val idx  = i + s
      val bits = if (idx < fetchHalfwords) rawHalfwords(idx) else 0.U(16.W)

      startOH(s) -> bits
    })
    io.entries(i).blockAddr := io.resp.meta.blockAddr
    io.entries(i).control   := io.resp.meta.control
    io.entries(i).exception := io.resp.exception
    when(io.resp.exception.valid) {
      io.entries(i).exception.tval := io.entries(i).pc
    }
  }
}

class FetchGroupSplitter(cfg: ICacheConfig) extends Module {
  require(cfg.fetchGroupBlocks == 2, "FetchGroupSplitter requires two-block groups")

  private val fetchHalfwords = cfg.fetchBytes / 2
  private val enqWidth       = fetchHalfwords * cfg.fetchGroupBlocks
  private val countWidth     = log2Ceil(enqWidth + 1)
  private val blockCountWidth = log2Ceil(fetchHalfwords + 1)
  private val parcelIndexWidth = log2Ceil(fetchHalfwords)

  val io = IO(new Bundle {
    val resp    = Input(new ICacheFetchGroupResp(cfg))
    val entries = Output(Vec(enqWidth, new HalfwordEntry(cfg)))
    val count   = Output(UInt(countWidth.W))
  })

  val firstBlock  = Module(new HalfwordSplitter(cfg))
  val secondBlock = Module(new HalfwordSplitter(cfg))
  firstBlock.io.resp  := io.resp.blocks(0).bits
  secondBlock.io.resp := io.resp.blocks(1).bits

  val secondCount = Mux(io.resp.blocks(1).valid, secondBlock.io.count, 0.U(blockCountWidth.W))
  val totalCount  = Wire(UInt(countWidth.W))
  totalCount := firstBlock.io.count +& secondCount
  io.count := totalCount

  for (parcel <- 0 until enqWidth) {
    val parcelIndex = parcel.U(countWidth.W)
    val firstIndex  = (parcel % fetchHalfwords).U(parcelIndexWidth.W)
    val secondIndex = (parcelIndex - firstBlock.io.count)(parcelIndexWidth - 1, 0)
    io.entries(parcel) := 0.U.asTypeOf(new HalfwordEntry(cfg))
    when(parcelIndex < firstBlock.io.count) {
      io.entries(parcel) := firstBlock.io.entries(firstIndex)
    }.elsewhen(parcelIndex < totalCount) {
      io.entries(parcel) := secondBlock.io.entries(secondIndex)
    }
  }

  when(io.resp.blocks(1).valid) {
    assert(io.resp.blocks(1).bits.meta.blockAddr ===
      io.resp.blocks(0).bits.meta.blockAddr + cfg.fetchBytes.U)
    assert(io.resp.blocks(1).bits.meta.control.pc === io.resp.blocks(1).bits.meta.blockAddr)
  }
}

class HalfwordBuffer(cfg: ICacheConfig, depth: Int, enqWidth: Int, peekWidth: Int) extends Module {
  require(depth > enqWidth, "HalfwordBuffer must hold at least one full fetch block")
  require(depth > 0 && (depth & (depth - 1)) == 0, "HalfwordBuffer depth must be a power of two")

  private val ptrWidth      = log2Ceil(depth)
  private val countWidth    = log2Ceil(depth + 1)
  private val enqCountWidth = log2Ceil(enqWidth + 1)

  val io = IO(new Bundle {
    val flush     = Input(Bool())
    val freeCount = Output(UInt(countWidth.W))

    val enqValid = Input(Bool())
    val enqReady = Output(Bool())
    val enqCount = Input(UInt(enqCountWidth.W))
    val enqBits  = Input(Vec(enqWidth, new HalfwordEntry(cfg)))

    val peek  = Output(Vec(peekWidth, new HalfwordEntry(cfg)))
    val count = Output(UInt(countWidth.W))
    val deq   = Input(UInt(countWidth.W))
  })

  private def ptrAdd(ptr: UInt, inc: UInt): UInt =
    (ptr + inc)(ptrWidth - 1, 0)

  val entries  = Reg(Vec(depth, new HalfwordEntry(cfg)))
  val readPtr  = RegInit(0.U(ptrWidth.W))
  val writePtr = RegInit(0.U(ptrWidth.W))
  val count    = RegInit(0.U(countWidth.W))

  val freeCount = depth.U(countWidth.W) - count
  val enqFire   = io.enqValid && io.enqReady
  val enqCount  = Mux(enqFire, io.enqCount, 0.U(enqCountWidth.W))

  val enqCountWide = Wire(UInt(countWidth.W))
  enqCountWide := enqCount

  io.freeCount := freeCount
  io.enqReady  := freeCount >= io.enqCount
  io.count     := count

  for (i <- 0 until peekWidth) {
    io.peek(i) := entries(ptrAdd(readPtr, i.U))
  }

  for (i <- 0 until enqWidth) {
    when(enqFire && i.U < io.enqCount) {
      entries(ptrAdd(writePtr, i.U)) := io.enqBits(i)
    }
  }

  when(io.flush) {
    readPtr  := 0.U
    writePtr := 0.U
    count    := 0.U
  }.otherwise {
    when(io.deq =/= 0.U) {
      readPtr := ptrAdd(readPtr, io.deq)
    }

    when(enqFire) {
      writePtr := ptrAdd(writePtr, enqCount)
    }

    count := (count +& enqCountWide - io.deq)(countWidth - 1, 0)
  }
}

class SharedInstAssembler(cfg: ICacheConfig, bufferDepth: Int) extends Module {
  private val outputWidth = FetchWidth.frontend
  private val peekWidth   = outputWidth * FetchWidth.maxInstructionHalfwords
  private val countWidth  = log2Ceil(bufferDepth + 1)
  private val parcelIndexWidth = log2Ceil(peekWidth)
  private val startWidth       = log2Ceil(peekWidth + 1)
  private val needWidth        = log2Ceil(FetchWidth.maxInstructionHalfwords + 1)

  val io = IO(new Bundle {
    val flush        = Input(Bool())
    val peek         = Input(Vec(peekWidth, new HalfwordEntry(cfg)))
    val count        = Input(UInt(countWidth.W))
    val out          = Decoupled(new FetchQueueEnqueue(cfg, outputWidth))
    val deq          = Output(UInt(countWidth.W))
    val predRedirect = Output(new PcRedirect)
  })

  private def instLen(isRVC: Bool): UInt =
    Mux(isRVC, 2.U(3.W), 4.U(3.W))

  private def cfiOffset(pc: UInt): UInt =
    pc(cfg.offsetBits - 1, 1)

  val starts = Wire(Vec(outputWidth, UInt(startWidth.W)))
  val needs  = Wire(Vec(outputWidth, UInt(needWidth.W)))
  val ready  = Wire(Vec(outputWidth, Bool()))

  starts(0) := 0.U
  for (lane <- 0 until outputWidth) {
    val low  = io.peek(starts(lane)(parcelIndexWidth - 1, 0))
    val isRVC = low.bits(1, 0) =/= 3.U
    needs(lane) := Mux(isRVC, 1.U(needWidth.W), FetchWidth.maxInstructionHalfwords.U(needWidth.W))
    ready(lane) := (if (lane == 0) true.B else ready(lane - 1)) &&
      io.count >= starts(lane) +& needs(lane)
    if (lane + 1 < outputWidth) {
      starts(lane + 1) := starts(lane) + needs(lane)
    }
  }

  val outputValid = Wire(Vec(outputWidth, Bool()))
  val stopBefore  = Wire(Vec(outputWidth, Bool()))
  val predTaken   = Wire(Vec(outputWidth, Bool()))
  val exceptions  = Wire(Vec(outputWidth, new top.core.bundle.FetchException(cfg.addrWidth)))
  val predictions = Wire(Vec(outputWidth, new FetchPred(cfg)))
  val targets     = Wire(Vec(outputWidth, UInt(cfg.addrWidth.W)))
  val expanders   = Seq.fill(outputWidth)(Module(new RvcExpander))

  stopBefore(0) := false.B
  io.out.bits   := 0.U.asTypeOf(new FetchQueueEnqueue(cfg, outputWidth))

  for (lane <- 0 until outputWidth) {
    val low       = io.peek(starts(lane)(parcelIndexWidth - 1, 0))
    val highIndex = starts(lane) + 1.U
    val high      = io.peek(highIndex(parcelIndexWidth - 1, 0))
    val isRVC     = low.bits(1, 0) =/= 3.U
    val rawInst   = Mux(isRVC, Cat(0.U(16.W), low.bits), Cat(high.bits, low.bits))
    val exception = Wire(new top.core.bundle.FetchException(cfg.addrWidth))
    exception := low.exception
    when(!isRVC && high.exception.valid) {
      exception := high.exception
    }

    predictions(lane) := low.control.fastPrediction
    val predHit = predictions(lane).valid && predictions(lane).cfiOffset === cfiOffset(low.pc)
    predTaken(lane) := predHit && predictions(lane).taken
    targets(lane)   := predictions(lane).target
    exceptions(lane) := exception
    outputValid(lane) := ready(lane) && !io.flush && !stopBefore(lane)

    expanders(lane).io.in := rawInst
    io.out.bits.insts(lane).valid           := outputValid(lane)
    io.out.bits.insts(lane).bits.inst.pc    := low.pc
    io.out.bits.insts(lane).bits.inst.inst  := expanders(lane).io.out.bits
    io.out.bits.insts(lane).bits.inst.rawInst := rawInst
    io.out.bits.insts(lane).bits.inst.isRVC := isRVC
    io.out.bits.insts(lane).bits.inst.instLen := instLen(isRVC)
    io.out.bits.insts(lane).bits.inst.predHit := predHit
    io.out.bits.insts(lane).bits.inst.predTaken := predTaken(lane)
    io.out.bits.insts(lane).bits.inst.predNpc := Mux(predTaken(lane), predictions(lane).target, low.pc +% instLen(isRVC))
    io.out.bits.insts(lane).bits.inst.predTarget := Mux(predHit, predictions(lane).target, 0.U)
    io.out.bits.insts(lane).bits.inst.exception := exception
    io.out.bits.insts(lane).bits.sequence := low.control.sequence
    io.out.bits.insts(lane).bits.epoch    := low.control.epoch

    if (lane + 1 < outputWidth) {
      stopBefore(lane + 1) := stopBefore(lane) ||
        (outputValid(lane) && (predTaken(lane) || exception.valid))
    }

    when(ready(lane) && !isRVC) {
      assert(high.pc === low.pc + 2.U)
      assert(high.control.epoch === low.control.epoch)
      when(high.blockAddr =/= low.blockAddr) {
        assert(high.control.sequence === low.control.sequence + 1.U)
      }
    }
  }

  val redirectMask  = VecInit((0 until outputWidth).map(lane => outputValid(lane) && predTaken(lane)))
  val redirectTarget = Mux1H(PriorityEncoderOH(redirectMask.asUInt).asBools, targets)
  val stopMask      = VecInit((0 until outputWidth).map { lane =>
    outputValid(lane) && (predTaken(lane) || exceptions(lane).valid)
  })
  val consumedHalfwordsRaw = (0 until outputWidth)
    .map(lane => Mux(outputValid(lane), needs(lane), 0.U(needWidth.W)))
    .reduce(_ +&_)
  val consumedHalfwords = Wire(UInt(countWidth.W))
  consumedHalfwords := consumedHalfwordsRaw

  io.out.valid          := outputValid(0)
  io.predRedirect.valid := io.out.fire && redirectMask.asUInt.orR
  io.predRedirect.value := redirectTarget
  io.deq := Mux(
    io.out.fire,
    Mux(stopMask.asUInt.orR, io.count, consumedHalfwords),
    0.U(countWidth.W)
  )

  assert(io.deq <= io.count)
}

class InstBuffer(bufferDepth: Int = 8) extends Module {
  require(bufferDepth > 1, "InstBuffer must have at least two entries")
  require(bufferDepth > 0 && (bufferDepth & (bufferDepth - 1)) == 0, "InstBuffer depth must be a power of two")

  private val ptrWidth   = log2Ceil(bufferDepth)
  private val countWidth = log2Ceil(bufferDepth + 1)

  val io = IO(new Bundle {
    val flush     = Input(Bool())
    val in        = Flipped(Decoupled(new FetchPacket))
    val out       = Decoupled(new FetchPacket)
    val count     = Output(UInt(countWidth.W))
    val freeCount = Output(UInt(countWidth.W))
  })

  private def ptrNext(ptr: UInt): UInt =
    (ptr + 1.U)(ptrWidth - 1, 0)

  val entries  = Reg(Vec(bufferDepth, new FetchPacket))
  val readPtr  = RegInit(0.U(ptrWidth.W))
  val writePtr = RegInit(0.U(ptrWidth.W))
  val count    = RegInit(0.U(countWidth.W))

  val empty = count === 0.U
  val full  = count === bufferDepth.U

  io.count     := count
  io.freeCount := bufferDepth.U(countWidth.W) - count

  io.out.valid := !io.flush && !empty
  io.out.bits  := entries(readPtr)

  io.in.ready := !io.flush && (!full || io.out.ready)

  val enqFire = io.in.fire
  val deqFire = io.out.fire

  when(io.flush) {
    readPtr  := 0.U
    writePtr := 0.U
    count    := 0.U
  }.otherwise {
    when(enqFire) {
      entries(writePtr) := io.in.bits
      writePtr          := ptrNext(writePtr)
    }

    when(deqFire) {
      readPtr := ptrNext(readPtr)
    }

    count := count + enqFire.asUInt - deqFire.asUInt
  }
}

class IFetch(
  cacheCfg: ICacheConfig = ICacheConfig(),
  cfg:      IFetchConfig = IFetchConfig())
    extends Module {
  require(cacheCfg.fetchBytes == 8, "IFetch currently assumes a 64-bit ICache fetch block")
  require(log2Ceil(cfg.fetchTargetEntries) == cacheCfg.fetchTargetIndexBits, "FetchTargetQueue index width must match configuration")

  private val fetchHalfwords = cacheCfg.fetchBytes / 2
  private val groupWidth     = cacheCfg.fetchGroupBlocks
  private val groupCountWidth = log2Ceil(groupWidth + 1)
  private val peekHalfwords  = FetchWidth.frontend * FetchWidth.maxInstructionHalfwords

  val io = IO(new Bundle {
    val redirect     = Input(new PcRedirect)
    val flush        = Input(Bool())
    val pc           = Input(UInt(cacheCfg.addrWidth.W))
    val pred         = Input(Vec(groupWidth, new FetchPred(cacheCfg)))
    val predRedirect = Output(new PcRedirect)
    val pcAdvanceBlocks = Output(UInt(groupCountWidth.W))
    val icacheAcceptedBlocks = Input(UInt(groupCountWidth.W))
    val icacheReq    = Decoupled(new ICacheFetchGroupReq(cacheCfg))
    val icacheResp   = Flipped(Decoupled(new ICacheFetchGroupResp(cacheCfg)))
    val fetch        = Decoupled(new FetchPacket)
    val fetchQueueOccupancy    = Output(UInt(log2Ceil(cfg.fetchQueueEntries + 1).W))
    val fetchQueueEnqueueWidth = Output(UInt(log2Ceil(FetchWidth.frontend + 1).W))
    val fetchQueueDequeueWidth = Output(UInt(log2Ceil(FetchWidth.backend + 1).W))
    val fetchQueueEmpty        = Output(Bool())
    val fetchQueueFull         = Output(Bool())
    val frontendRedirect       = Output(Bool())
    val staleResponseDrop      = Output(Bool())
  })

  val splitter       = Module(new FetchGroupSplitter(cacheCfg))
  val halfwordBuffer = Module(new HalfwordBuffer(cacheCfg, cfg.halfwordEntries, fetchHalfwords * groupWidth, peekHalfwords))
  val assembler      = Module(new SharedInstAssembler(cacheCfg, cfg.halfwordEntries))
  val fetchQueue     = Module(new FetchQueue(cacheCfg, cfg.fetchQueueEntries, FetchWidth.frontend))
  val ftq            = Module(new FetchTargetQueue(cacheCfg, cfg.fetchTargetEntries))
  val responseQueue  = Module(new FetchResponseQueue(cacheCfg, cfg.fetchTargetEntries))

  val enoughSpaceForBlock = halfwordBuffer.io.freeCount >= fetchHalfwords.U
  val localPredRedirect   = assembler.io.predRedirect
  val localException      = assembler.io.out.fire && assembler.io.out.bits.insts(0).bits.inst.exception.valid
  val hardFlush           = io.redirect.valid || io.flush
  val frontendRedirect    = hardFlush || localPredRedirect.valid || localException
  io.frontendRedirect := frontendRedirect
  val fetchQueueEpoch     = RegInit(0.U(cacheCfg.fetchEpochBits.W))
  ftq.io.redirect := frontendRedirect
  responseQueue.io.flush        := frontendRedirect
  responseQueue.io.currentEpoch := ftq.io.epoch
  responseQueue.io.oldest       := ftq.io.peek(0)
  for (lane <- 0 until groupWidth) {
    ftq.io.allocatePc(lane)   := 0.U
    ftq.io.allocatePred(lane) := 0.U.asTypeOf(new FetchPred(cacheCfg))
    ftq.io.releaseMeta(lane) := 0.U.asTypeOf(new FetchControlMeta(cacheCfg))
  }
  val firstBlockAddr = Cat(io.pc(cacheCfg.addrWidth - 1, cacheCfg.offsetBits), 0.U(cacheCfg.offsetBits.W))
  val secondBlockPc  = firstBlockAddr +% cacheCfg.fetchBytes.U(cacheCfg.addrWidth.W)
  ftq.io.allocatePc(0)   := io.pc
  ftq.io.allocatePc(1)   := secondBlockPc
  for (lane <- 0 until groupWidth) {
    ftq.io.allocatePred(lane) := io.pred(lane)
  }
  ftq.io.allocateCount := io.icacheAcceptedBlocks

  val req = Wire(new ICacheFetchGroupReq(cacheCfg))
  req := 0.U.asTypeOf(new ICacheFetchGroupReq(cacheCfg))
  for (lane <- 0 until groupWidth) {
    req.blocks(lane).valid := true.B
    req.blocks(lane).bits  := ICacheReq.fromControl(ftq.io.allocateMeta(lane), cacheCfg)
  }

  val incomingMeta         = io.icacheResp.bits.blocks(0).bits.meta.control
  val incomingCurrentEpoch = io.icacheResp.bits.blocks(0).valid && incomingMeta.epoch === ftq.io.epoch
  val rawStaleDrop         = io.icacheResp.fire && (frontendRedirect || !incomingCurrentEpoch)
  val bufferedStaleDrop    = frontendRedirect && !responseQueue.io.empty
  responseQueue.io.insert.valid := io.icacheResp.valid && incomingCurrentEpoch && !frontendRedirect
  responseQueue.io.insert.bits  := io.icacheResp.bits
  io.icacheResp.ready := frontendRedirect || !incomingCurrentEpoch || responseQueue.io.insert.ready

  val responseFire        = responseQueue.io.out.fire
  val responseCount       = PopCount(responseQueue.io.out.bits.blocks.map(_.valid))
  val responseMeta        = responseQueue.io.out.bits.blocks(0).bits.meta.control
  val responseCurrentEpoch = responseQueue.io.out.bits.blocks(0).valid && responseMeta.epoch === ftq.io.epoch
  val responseMatchesHead = (0 until groupWidth).map { lane =>
    !responseQueue.io.out.bits.blocks(lane).valid ||
      (ftq.io.peek(lane).valid &&
        responseQueue.io.out.bits.blocks(lane).bits.meta.control.sequence === ftq.io.peek(lane).bits.sequence &&
        responseQueue.io.out.bits.blocks(lane).bits.meta.control.epoch === ftq.io.peek(lane).bits.epoch &&
        responseQueue.io.out.bits.blocks(lane).bits.meta.control.ftqIndex === ftq.io.peek(lane).bits.ftqIndex)
  }.reduce(_ && _)
  val responseLive = responseCurrentEpoch && responseMatchesHead && !frontendRedirect
  val canReq       = ftq.io.allocateReady && enoughSpaceForBlock && !frontendRedirect

  io.icacheReq.valid := canReq
  io.icacheReq.bits  := req
  io.pcAdvanceBlocks := Mux(io.icacheReq.fire, io.icacheAcceptedBlocks, 0.U(groupCountWidth.W))
  io.predRedirect    := localPredRedirect

  val requestFire = io.icacheReq.fire
  ftq.io.allocate := requestFire
  ftq.io.release := responseFire && responseLive
  ftq.io.releaseCount := responseCount
  for (lane <- 0 until groupWidth) {
    ftq.io.releaseMeta(lane) := responseQueue.io.out.bits.blocks(lane).bits.meta.control
  }

  splitter.io.resp := responseQueue.io.out.bits

  halfwordBuffer.io.flush    := frontendRedirect
  halfwordBuffer.io.enqValid := responseFire && responseLive
  halfwordBuffer.io.enqCount := splitter.io.count
  halfwordBuffer.io.enqBits  := splitter.io.entries

  responseQueue.io.out.ready := !responseLive || halfwordBuffer.io.enqReady
  io.staleResponseDrop := rawStaleDrop || bufferedStaleDrop || responseQueue.io.staleDrop

  assembler.io.flush    := hardFlush
  assembler.io.peek     := halfwordBuffer.io.peek
  assembler.io.count    := halfwordBuffer.io.count
  halfwordBuffer.io.deq := assembler.io.deq

  fetchQueue.io.flush        := hardFlush
  fetchQueue.io.currentEpoch := fetchQueueEpoch
  fetchQueue.io.enq.valid    := assembler.io.out.valid
  fetchQueue.io.enq.bits     := assembler.io.out.bits
  for (lane <- 0 until FetchWidth.frontend) {
    fetchQueue.io.enq.bits.insts(lane).bits.epoch := fetchQueueEpoch
  }
  assembler.io.out.ready := fetchQueue.io.enq.ready
  io.fetch <> fetchQueue.io.out
  io.fetchQueueOccupancy    := fetchQueue.io.count
  io.fetchQueueEnqueueWidth := fetchQueue.io.enqueueWidth
  io.fetchQueueDequeueWidth := fetchQueue.io.dequeueWidth
  io.fetchQueueEmpty        := fetchQueue.io.empty
  io.fetchQueueFull         := fetchQueue.io.full

  when(hardFlush) {
    fetchQueueEpoch := fetchQueueEpoch + 1.U
  }

  when(responseQueue.io.out.valid && responseCurrentEpoch && !frontendRedirect) {
    assert(responseMatchesHead)
  }
  when(responseFire && responseLive) {
    assert(ftq.io.peek(0).valid)
  }
  assert(ftq.io.count <= cfg.fetchTargetEntries.U)
}
