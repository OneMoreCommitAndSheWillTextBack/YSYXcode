package top.core.frontend.ifetch

import chisel3._
import chisel3.util._
import top.config.{ICacheConfig, IFetchConfig}
import top.core.frontend.bundle.{FetchInst, FetchPred, ICacheReq, ICacheResp, PcRedirect}

// two stage pipline
// cache block -> 16bits block -> inst buffer

class FetchPacket extends Bundle {
  val insts = Vec(2, Valid(new FetchInst))
}

class HalfwordEntry(cfg: ICacheConfig) extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val bits      = UInt(16.W)
  val blockAddr = UInt(cfg.addrWidth.W)
  val pred      = new FetchPred(cfg)
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

  val startHalfword = io.resp.meta.pc(cfg.offsetBits - 1, 1)
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
    io.entries(i).pred      := io.resp.meta.pred
    io.entries(i).exception := io.resp.exception
    when(io.resp.exception.valid) {
      io.entries(i).exception.tval := io.entries(i).pc
    }
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

class DualInstAssembler(cfg: ICacheConfig, bufferDepth: Int) extends Module {
  private val peekWidth  = 4
  private val countWidth = log2Ceil(bufferDepth + 1)
  private val needWidth  = log2Ceil(peekWidth + 1)

  val io = IO(new Bundle {
    val flush        = Input(Bool())
    val peek         = Input(Vec(peekWidth, new HalfwordEntry(cfg)))
    val count        = Input(UInt(countWidth.W))
    val out          = Decoupled(new FetchPacket)
    val deq          = Output(UInt(countWidth.W))
    val predRedirect = Output(new PcRedirect)
  })

  private def instLen(isRVC: Bool): UInt =
    Mux(isRVC, 2.U(3.W), 4.U(3.W))

  private def cfiOffset(pc: UInt): UInt =
    pc(cfg.offsetBits - 1, 1)

  val h0 = io.peek(0)
  val h1 = io.peek(1)
  val h2 = io.peek(2)
  val h3 = io.peek(3)

  val firstIsRVC = h0.bits(1, 0) =/= 3.U
  val firstNeed  = Mux(firstIsRVC, 1.U(needWidth.W), 2.U(needWidth.W))
  val firstReady = io.count >= firstNeed
  val firstRaw   = Mux(firstIsRVC, Cat(0.U(16.W), h0.bits), Cat(h1.bits, h0.bits))
  val firstException = Wire(new top.core.bundle.FetchException(cfg.addrWidth))
  firstException := h0.exception
  when(!firstIsRVC && h1.exception.valid) {
    firstException := h1.exception
  }

  val secondLow  = Mux(firstIsRVC, h1.bits, h2.bits)
  val secondHigh = Mux(firstIsRVC, h2.bits, h3.bits)
  val secondPc   = Mux(firstIsRVC, h1.pc, h2.pc)
  val secondPred = Wire(new FetchPred(cfg))
  secondPred := Mux(firstIsRVC, h1.pred, h2.pred)
  val secondIsRVC = secondLow(1, 0) =/= 3.U
  val secondNeed  = Mux(secondIsRVC, 1.U(needWidth.W), 2.U(needWidth.W))
  val totalNeed   = firstNeed + secondNeed
  val secondReady = firstReady && io.count >= totalNeed
  val secondRaw   = Mux(secondIsRVC, Cat(0.U(16.W), secondLow), Cat(secondHigh, secondLow))
  val secondException = Wire(new top.core.bundle.FetchException(cfg.addrWidth))
  secondException := Mux(firstIsRVC, h1.exception, h2.exception)
  when(!secondIsRVC) {
    val highException = Mux(firstIsRVC, h2.exception, h3.exception)
    when(highException.valid) {
      secondException := highException
    }
  }

  val firstPredHit  = h0.pred.valid && h0.pred.cfiOffset === cfiOffset(h0.pc)
  val secondPredHit = secondPred.valid && secondPred.cfiOffset === cfiOffset(secondPc)

  val firstPredTaken    = firstPredHit && h0.pred.taken
  val secondPredTaken   = secondPredHit && secondPred.taken
  val firstFallThrough  = h0.pc +% instLen(firstIsRVC)
  val secondFallThrough = secondPc +% instLen(secondIsRVC)

  val firstExpander  = Module(new RvcExpander)
  val secondExpander = Module(new RvcExpander)
  firstExpander.io.in  := firstRaw
  secondExpander.io.in := secondRaw

  val firstOutValid  = firstReady && !io.flush
  val secondOutValid = secondReady && !io.flush

  io.out.valid := firstOutValid
  io.out.bits  := 0.U.asTypeOf(new FetchPacket)

  io.out.bits.insts(0).valid           := firstOutValid
  io.out.bits.insts(0).bits.pc         := h0.pc
  io.out.bits.insts(0).bits.inst       := firstExpander.io.out.bits
  io.out.bits.insts(0).bits.rawInst    := firstRaw
  io.out.bits.insts(0).bits.isRVC      := firstIsRVC
  io.out.bits.insts(0).bits.instLen    := instLen(firstIsRVC)
  io.out.bits.insts(0).bits.predTaken  := firstPredTaken
  io.out.bits.insts(0).bits.predNpc    := Mux(firstPredTaken, h0.pred.target, firstFallThrough)
  io.out.bits.insts(0).bits.predTarget := Mux(firstPredHit, h0.pred.target, 0.U)
  io.out.bits.insts(0).bits.exception  := firstException

  io.out.bits.insts(1).valid           := secondOutValid && !firstPredTaken && !firstException.valid
  io.out.bits.insts(1).bits.pc         := secondPc
  io.out.bits.insts(1).bits.inst       := secondExpander.io.out.bits
  io.out.bits.insts(1).bits.rawInst    := secondRaw
  io.out.bits.insts(1).bits.isRVC      := secondIsRVC
  io.out.bits.insts(1).bits.instLen    := instLen(secondIsRVC)
  io.out.bits.insts(1).bits.predTaken  := secondPredTaken
  io.out.bits.insts(1).bits.predNpc    := Mux(secondPredTaken, secondPred.target, secondFallThrough)
  io.out.bits.insts(1).bits.predTarget := Mux(secondPredHit, secondPred.target, 0.U)
  io.out.bits.insts(1).bits.exception  := secondException

  val packetPredTaken =
    (io.out.bits.insts(0).valid && firstPredTaken) ||
      (io.out.bits.insts(1).valid && secondPredTaken)
  val normalDeq       = Wire(UInt(countWidth.W))
  normalDeq := Mux(secondReady, totalNeed, firstNeed)

  io.predRedirect.valid := io.out.fire && packetPredTaken
  io.predRedirect.value := Mux(firstPredTaken, h0.pred.target, secondPred.target)

  // A predicted-taken CFI changes the fetch stream at this packet boundary.
  // Discard all currently buffered fall-through halfwords; target fetch starts
  // only after the redirect is accepted by PCGen.
  io.deq := Mux(
    io.out.fire,
    Mux(packetPredTaken, io.count, normalDeq),
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

  private val fetchHalfwords = cacheCfg.fetchBytes / 2
  private val peekHalfwords  = 4

  val io = IO(new Bundle {
    val redirect     = Input(new PcRedirect)
    val pc           = Input(UInt(cacheCfg.addrWidth.W))
    val pred         = Input(new FetchPred(cacheCfg))
    val predRedirect = Output(new PcRedirect)
    val pcAdvance    = Output(Bool())
    val icacheReq    = Decoupled(new ICacheReq(cacheCfg))
    val icacheResp   = Flipped(Decoupled(new ICacheResp(cacheCfg)))
    val fetch        = Decoupled(new FetchPacket)
  })

  val splitter       = Module(new HalfwordSplitter(cacheCfg))
  val halfwordBuffer = Module(new HalfwordBuffer(cacheCfg, cfg.halfwordEntries, fetchHalfwords, peekHalfwords))
  val assembler      = Module(new DualInstAssembler(cacheCfg, cfg.halfwordEntries))
  val instBuffer     = Module(new InstBuffer(cfg.instBufferEntries))

  val reqOutstanding = RegInit(false.B)
  val dropResp       = RegInit(false.B)

  val req                 = ICacheReq.fromPc(io.pc, cacheCfg, io.pred)
  val enoughSpaceForBlock = halfwordBuffer.io.freeCount >= fetchHalfwords.U
  val localPredRedirect   = assembler.io.predRedirect
  val frontendRedirect    = io.redirect.valid || localPredRedirect.valid
  val responseFire        = io.icacheResp.fire
  // A response retires the sole outstanding request before the clock edge, so
  // a new request may reuse that slot in the same cycle.
  val canReq              = (!reqOutstanding || responseFire) && !dropResp && enoughSpaceForBlock && !frontendRedirect

  io.icacheReq.valid := canReq
  io.icacheReq.bits  := req
  io.pcAdvance       := io.icacheReq.fire
  io.predRedirect    := localPredRedirect

  val requestFire = io.icacheReq.fire

  splitter.io.resp := io.icacheResp.bits

  // Backend redirects flush every queued frontend stage. A local prediction
  // redirect keeps older packets in the instruction buffer, but discards any
  // fall-through cache response that has not reached the halfword FIFO yet.
  val discardResp = dropResp || frontendRedirect
  halfwordBuffer.io.flush    := io.redirect.valid
  halfwordBuffer.io.enqValid := io.icacheResp.fire && !discardResp
  halfwordBuffer.io.enqCount := splitter.io.count
  halfwordBuffer.io.enqBits  := splitter.io.entries

  io.icacheResp.ready := discardResp || halfwordBuffer.io.enqReady

  assembler.io.flush    := io.redirect.valid
  assembler.io.peek     := halfwordBuffer.io.peek
  assembler.io.count    := halfwordBuffer.io.count
  halfwordBuffer.io.deq := assembler.io.deq

  instBuffer.io.flush := io.redirect.valid
  instBuffer.io.in <> assembler.io.out
  io.fetch <> instBuffer.io.out

  when(frontendRedirect) {
    dropResp       := (dropResp || reqOutstanding) && !responseFire
    reqOutstanding := false.B
  }.otherwise {
    reqOutstanding := (reqOutstanding && !responseFire) || requestFire
    dropResp       := dropResp && !responseFire
  }
}
