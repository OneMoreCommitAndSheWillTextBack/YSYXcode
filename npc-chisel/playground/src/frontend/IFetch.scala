package top.frontend.ifetch

import chisel3._
import chisel3.util._
import top.config.ICacheConfig
import top.frontend.bundle.{FetchInst, ICacheReq, ICacheResp, PcRedirect}

// two stage pipline
// cache block -> 16bits block -> inst buffer

class FetchPacket extends Bundle {
  val insts = Vec(2, Valid(new FetchInst))
}

class HalfwordEntry extends Bundle {
  val pc   = UInt(32.W)
  val bits = UInt(16.W)
}

class HalfwordSplitter(cfg: ICacheConfig) extends Module {
  require(cfg.fetchBytes == 8, "HalfwordSplitter currently assumes a 64-bit ICache fetch block")

  private val fetchHalfwords = cfg.fetchBytes / 2
  private val countWidth     = log2Ceil(fetchHalfwords + 1)

  val io = IO(new Bundle {
    val resp    = Input(new ICacheResp(cfg))
    val entries = Output(Vec(fetchHalfwords, new HalfwordEntry))
    val count   = Output(UInt(countWidth.W))
  })

  val rawHalfwords = Wire(Vec(fetchHalfwords, UInt(16.W)))
  for (i <- 0 until fetchHalfwords) {
    rawHalfwords(i) := io.resp.data(16 * (i + 1) - 1, 16 * i)
  }

  val startHalfword = io.resp.meta.pc(cfg.offsetBits - 1, 1)
  val startCount    = Wire(UInt(countWidth.W))
  startCount := startHalfword

  io.count := fetchHalfwords.U(countWidth.W) - startCount

  for (i <- 0 until fetchHalfwords) {
    val srcIdx     = startCount + i.U(countWidth.W)
    val byteOffset = Wire(UInt(cfg.addrWidth.W))
    byteOffset := srcIdx << 1

    io.entries(i).pc   := io.resp.meta.blockAddr +% byteOffset
    io.entries(i).bits := MuxLookup(
      srcIdx,
      0.U(16.W)
    )((0 until fetchHalfwords).map(j => j.U(countWidth.W) -> rawHalfwords(j)))
  }
}

class HalfwordBuffer(depth: Int, enqWidth: Int, peekWidth: Int) extends Module {
  require(depth > enqWidth, "HalfwordBuffer must hold at least one full fetch block")
  require(depth > 0 && (depth & (depth - 1)) == 0, "HalfwordBuffer depth must be a power of two")

  private val ptrWidth      = log2Ceil(depth)
  private val countWidth    = log2Ceil(depth + 1)
  private val enqCountWidth = log2Ceil(enqWidth + 1)
  private val deqCountWidth = log2Ceil(peekWidth + 1)

  val io = IO(new Bundle {
    val flush     = Input(Bool())
    val freeCount = Output(UInt(countWidth.W))

    val enqValid = Input(Bool())
    val enqReady = Output(Bool())
    val enqCount = Input(UInt(enqCountWidth.W))
    val enqBits  = Input(Vec(enqWidth, new HalfwordEntry))

    val peek  = Output(Vec(peekWidth, new HalfwordEntry))
    val count = Output(UInt(countWidth.W))
    val deq   = Input(UInt(deqCountWidth.W))
  })

  private def ptrAdd(ptr: UInt, inc: UInt): UInt =
    (ptr + inc)(ptrWidth - 1, 0)

  val entries  = Reg(Vec(depth, new HalfwordEntry))
  val readPtr  = RegInit(0.U(ptrWidth.W))
  val writePtr = RegInit(0.U(ptrWidth.W))
  val count    = RegInit(0.U(countWidth.W))

  val freeCount = depth.U(countWidth.W) - count
  val enqFire   = io.enqValid && io.enqReady
  val enqCount  = Mux(enqFire, io.enqCount, 0.U(enqCountWidth.W))

  val enqCountWide = Wire(UInt(countWidth.W))
  val deqCountWide = Wire(UInt(countWidth.W))
  enqCountWide := enqCount
  deqCountWide := io.deq

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

    count := (count +& enqCountWide - deqCountWide)(countWidth - 1, 0)
  }
}

class DualInstAssembler(bufferDepth: Int) extends Module {
  private val peekWidth     = 4
  private val countWidth    = log2Ceil(bufferDepth + 1)
  private val deqCountWidth = log2Ceil(peekWidth + 1)

  val io = IO(new Bundle {
    val flush = Input(Bool())
    val peek  = Input(Vec(peekWidth, new HalfwordEntry))
    val count = Input(UInt(countWidth.W))
    val out   = Decoupled(new FetchPacket)
    val deq   = Output(UInt(deqCountWidth.W))
  })

  private def instLen(isRVC: Bool): UInt =
    Mux(isRVC, 2.U(3.W), 4.U(3.W))

  val h0 = io.peek(0)
  val h1 = io.peek(1)
  val h2 = io.peek(2)
  val h3 = io.peek(3)

  val firstIsRVC = h0.bits(1, 0) =/= 3.U
  val firstNeed  = Mux(firstIsRVC, 1.U(deqCountWidth.W), 2.U(deqCountWidth.W))
  val firstReady = io.count >= firstNeed
  val firstRaw   = Mux(firstIsRVC, Cat(0.U(16.W), h0.bits), Cat(h1.bits, h0.bits))

  val secondLow   = Mux(firstIsRVC, h1.bits, h2.bits)
  val secondHigh  = Mux(firstIsRVC, h2.bits, h3.bits)
  val secondPc    = Mux(firstIsRVC, h1.pc, h2.pc)
  val secondIsRVC = secondLow(1, 0) =/= 3.U
  val secondNeed  = Mux(secondIsRVC, 1.U(deqCountWidth.W), 2.U(deqCountWidth.W))
  val totalNeed   = firstNeed + secondNeed
  val secondReady = firstReady && io.count >= totalNeed
  val secondRaw   = Mux(secondIsRVC, Cat(0.U(16.W), secondLow), Cat(secondHigh, secondLow))

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
  io.out.bits.insts(0).bits.predTaken  := false.B
  io.out.bits.insts(0).bits.predNpc    := 0.U
  io.out.bits.insts(0).bits.predTarget := 0.U

  io.out.bits.insts(1).valid           := secondOutValid
  io.out.bits.insts(1).bits.pc         := secondPc
  io.out.bits.insts(1).bits.inst       := secondExpander.io.out.bits
  io.out.bits.insts(1).bits.rawInst    := secondRaw
  io.out.bits.insts(1).bits.isRVC      := secondIsRVC
  io.out.bits.insts(1).bits.instLen    := instLen(secondIsRVC)
  io.out.bits.insts(1).bits.predTaken  := false.B
  io.out.bits.insts(1).bits.predNpc    := 0.U
  io.out.bits.insts(1).bits.predTarget := 0.U

  io.deq := Mux(
    io.out.fire,
    Mux(secondReady, totalNeed, firstNeed),
    0.U(deqCountWidth.W)
  )
}

class IFetch(
  cfg:             ICacheConfig = ICacheConfig(),
  halfwordEntries: Int = 16)
    extends Module {
  require(cfg.fetchBytes == 8, "IFetch currently assumes a 64-bit ICache fetch block")

  private val fetchHalfwords = cfg.fetchBytes / 2
  private val peekHalfwords  = 4

  val io = IO(new Bundle {
    val redirect   = Input(new PcRedirect)
    val pc         = Input(UInt(cfg.addrWidth.W))
    val pcAdvance  = Output(Bool())
    val icacheReq  = Decoupled(new ICacheReq(cfg))
    val icacheResp = Flipped(Decoupled(new ICacheResp(cfg)))
    val fetch      = Decoupled(new FetchPacket)
  })

  val splitter  = Module(new HalfwordSplitter(cfg))
  val buffer    = Module(new HalfwordBuffer(halfwordEntries, fetchHalfwords, peekHalfwords))
  val assembler = Module(new DualInstAssembler(halfwordEntries))

  val reqOutstanding = RegInit(false.B)
  val dropResp       = RegInit(false.B)

  val req                 = ICacheReq.fromPc(io.pc, cfg)
  val enoughSpaceForBlock = buffer.io.freeCount >= fetchHalfwords.U
  val canReq              = !reqOutstanding && !dropResp && enoughSpaceForBlock && !io.redirect.valid

  io.icacheReq.valid := canReq
  io.icacheReq.bits  := req
  io.pcAdvance       := io.icacheReq.fire

  splitter.io.resp := io.icacheResp.bits

  val discardResp = dropResp || io.redirect.valid
  buffer.io.flush    := io.redirect.valid
  buffer.io.enqValid := io.icacheResp.fire && !discardResp
  buffer.io.enqCount := splitter.io.count
  buffer.io.enqBits  := splitter.io.entries

  io.icacheResp.ready := discardResp || buffer.io.enqReady

  assembler.io.flush := io.redirect.valid
  assembler.io.peek  := buffer.io.peek
  assembler.io.count := buffer.io.count
  buffer.io.deq      := assembler.io.deq
  io.fetch <> assembler.io.out

  when(io.redirect.valid) {
    dropResp       := (dropResp || reqOutstanding) && !io.icacheResp.fire
    reqOutstanding := false.B
  }.otherwise {
    when(io.icacheResp.fire) {
      reqOutstanding := false.B
      dropResp       := false.B
    }

    when(io.icacheReq.fire) {
      reqOutstanding := true.B
    }
  }
}
