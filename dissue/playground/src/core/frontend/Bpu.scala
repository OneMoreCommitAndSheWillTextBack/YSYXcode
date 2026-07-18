package top.core.frontend.Bpu

import chisel3._
import chisel3.util._

import top.core.frontend.bundle._
import top.config._
import top.core.bundle.CfiType

class BtbResp(cfg: BpuConfig) extends Bundle {
  val hit       = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
}

class BtbUpdate(cfg: BpuConfig) extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = UInt(CfiType.width.W)
}

class BtbBundle(cfg: BpuConfig) extends Bundle {
  val lookupPc = Input(Vec(2, UInt(cfg.addrWidth.W)))
  val resp     = Output(Vec(2, new BtbResp(cfg)))
  val update   = Flipped(Valid(new BtbUpdate(cfg)))
}

class Btb(cfg: BpuConfig) extends Module {
  val io = IO(new BtbBundle(cfg))

  private val idxWidth    = cfg.btbIndexBits
  private val tagWidth    = cfg.btbTagBits
  private val offsetWidth = cfg.offsetBits

  private def tag(pc: UInt) =
    pc(cfg.addrWidth - 1, idxWidth + offsetWidth)

  private def index(pc: UInt) =
    pc(idxWidth + offsetWidth - 1, offsetWidth)

  val validArray  = RegInit(VecInit(Seq.fill(cfg.btbEntries)(false.B)))
  val tagArray    = Reg(Vec(cfg.btbEntries, UInt(tagWidth.W)))
  val targetArray = Reg(Vec(cfg.btbEntries, UInt(cfg.addrWidth.W)))
  val cfitpArray  = Reg(Vec(cfg.btbEntries, UInt(CfiType.width.W)))
  val cfioffArray = Reg(Vec(cfg.btbEntries, UInt(cfg.cfiOffsetBits.W)))

  val updateSet = index(io.update.bits.pc)
  val updateTag = tag(io.update.bits.pc)

  when(io.update.fire) {
    validArray(updateSet)  := true.B
    tagArray(updateSet)    := updateTag
    targetArray(updateSet) := io.update.bits.target
    cfitpArray(updateSet)  := io.update.bits.cfiType
    cfioffArray(updateSet) := io.update.bits.cfiOffset
  }

  for (lane <- 0 until 2) {
    val reqSet = index(io.lookupPc(lane))
    val reqTag = tag(io.lookupPc(lane))
    val hit    = validArray(reqSet) && tagArray(reqSet) === reqTag

    io.resp(lane).hit       := hit
    io.resp(lane).target    := Mux(hit, targetArray(reqSet), 0.U)
    io.resp(lane).cfiOffset := Mux(hit, cfioffArray(reqSet), 0.U)
    io.resp(lane).cfiType   := Mux(hit, cfitpArray(reqSet), CfiType.none)
  }
}

class BhtUpdate(cfg: BpuConfig) extends Bundle {
  val pc    = UInt(cfg.addrWidth.W)
  val taken = Bool()
}

class BhtBundle(cfg: BpuConfig) extends Bundle {
  val lookupPc = Input(Vec(2, UInt(cfg.addrWidth.W)))
  val taken    = Output(Vec(2, Bool()))
  val update   = Flipped(Valid(new BhtUpdate(cfg)))
}

object TakenState extends ChiselEnum {
  val strongNotTaken, weakNotTaken, weakTaken, strongTaken = Value
}

class Bht(cfg: BpuConfig) extends Module {
  val io = IO(new BhtBundle(cfg))

  private val offsetWidth = cfg.offsetBits
  private val idxWidth    = cfg.bhtIndexBits

  private def idx(pc: UInt) =
    pc(idxWidth + offsetWidth - 1, offsetWidth)

  private def nextTakenState(state: TakenState.Type, taken: Bool) = {
    val next = WireDefault(state)

    switch(state) {
      is(TakenState.strongNotTaken) {
        next := Mux(taken, TakenState.weakNotTaken, TakenState.strongNotTaken)
      }
      is(TakenState.weakNotTaken) {
        next := Mux(taken, TakenState.weakTaken, TakenState.strongNotTaken)
      }
      is(TakenState.weakTaken) {
        next := Mux(taken, TakenState.strongTaken, TakenState.weakNotTaken)
      }
      is(TakenState.strongTaken) {
        next := Mux(taken, TakenState.strongTaken, TakenState.weakTaken)
      }
    }

    next
  }

  private def predictTaken(state: TakenState.Type) =
    state === TakenState.weakTaken || state === TakenState.strongTaken

  val validArray = RegInit(VecInit(Seq.fill(cfg.bhtEntries)(false.B)))
  val takenArray = Reg(Vec(cfg.bhtEntries, TakenState()))

  val updateSet = idx(io.update.bits.pc)
  when(io.update.fire) {
    when(validArray(updateSet)) {
      takenArray(updateSet) := nextTakenState(takenArray(updateSet), io.update.bits.taken)
    }.otherwise {
      validArray(updateSet) := true.B
      takenArray(updateSet) := Mux(io.update.bits.taken, TakenState.weakTaken, TakenState.weakNotTaken)
    }
  }

  for (lane <- 0 until 2) {
    val reqIdx   = idx(io.lookupPc(lane))
    val reqTaken = takenArray(reqIdx)

    io.taken(lane) := validArray(reqIdx) && predictTaken(reqTaken)
  }
}

class Bpu(cfg: BpuConfig = BpuConfig()) extends Module {
  val io = IO(new BpuBundle(cfg))

  val btb = Module(new Btb(cfg))
  val bht = Module(new Bht(cfg))

  btb.io.lookupPc(0) := io.lookup.bits.pc
  btb.io.lookupPc(1) := io.lookupSecondary.bits.pc
  bht.io.lookupPc(0) := io.lookup.bits.pc
  bht.io.lookupPc(1) := io.lookupSecondary.bits.pc

  btb.io.update.valid          := io.update.valid && io.update.bits.taken
  btb.io.update.bits.pc        := io.update.bits.pc
  btb.io.update.bits.target    := io.update.bits.target
  btb.io.update.bits.cfiOffset := io.update.bits.pc(cfg.offsetBits - 1, 1)
  btb.io.update.bits.cfiType   := io.update.bits.cfiType

  bht.io.update.valid      := io.update.valid && io.update.bits.cfiType === CfiType.branch
  bht.io.update.bits.pc    := io.update.bits.pc
  bht.io.update.bits.taken := io.update.bits.taken

  private def predictionFor(lookupValid: Bool, lookupPc: UInt, lane: Int): BpuPred = {
    val lookupOffset = lookupPc(cfg.offsetBits - 1, 1)
    val isBranch     = btb.io.resp(lane).cfiType === CfiType.branch
    val hasCfi       = btb.io.resp(lane).cfiType =/= CfiType.none
    val btbHit       = lookupValid && btb.io.resp(lane).hit && hasCfi
    val cfiInWindow  = btbHit && btb.io.resp(lane).cfiOffset >= lookupOffset
    val predTaken    = cfiInWindow && Mux(isBranch, bht.io.taken(lane), true.B)
    val prediction   = Wire(new BpuPred(cfg))

    prediction.valid     := cfiInWindow
    prediction.taken     := predTaken
    prediction.target    := Mux(predTaken, btb.io.resp(lane).target, 0.U)
    prediction.cfiOffset := Mux(cfiInWindow, btb.io.resp(lane).cfiOffset, 0.U)
    prediction.cfiType   := Mux(cfiInWindow, btb.io.resp(lane).cfiType, CfiType.none)
    prediction
  }

  io.pred          := predictionFor(io.lookup.valid, io.lookup.bits.pc, 0)
  io.predSecondary := predictionFor(io.lookupSecondary.valid, io.lookupSecondary.bits.pc, 1)
}
