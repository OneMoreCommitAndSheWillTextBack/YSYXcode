package top.frontend.Bpu

import chisel3._
import chisel3.util._

import top.frontend.bundle._
import top.config._
import top.bundle.CfiType

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
  val lookupPc = Input(UInt(cfg.addrWidth.W))
  val resp     = Output(new BtbResp(cfg))
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

  val reqSet = index(io.lookupPc)
  val reqTag = tag(io.lookupPc)
  val hit    = validArray(reqSet) === true.B && tagArray(reqSet) === reqTag

  io.resp.hit       := hit
  io.resp.target    := Mux(hit, targetArray(reqSet), 0.U)
  io.resp.cfiOffset := Mux(hit, cfioffArray(reqSet), 0.U)
  io.resp.cfiType   := Mux(hit, cfitpArray(reqSet), CfiType.none)
}

class BhtUpdate(cfg: BpuConfig) extends Bundle {
  val pc    = UInt(cfg.addrWidth.W)
  val taken = Bool()
}

class BhtBundle(cfg: BpuConfig) extends Bundle {
  val lookupPc = Input(UInt(cfg.addrWidth.W))
  val taken    = Output(Bool())
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

  val reqIdx   = idx(io.lookupPc)
  val reqTaken = takenArray(reqIdx)

  io.taken := validArray(reqIdx) && predictTaken(reqTaken)
}

class Bpu(cfg: BpuConfig = BpuConfig()) extends Module {
  val io = IO(new BpuBundle(cfg))

  val btb = Module(new Btb(cfg))
  val bht = Module(new Bht(cfg))

  btb.io.lookupPc := io.lookup.bits.pc
  bht.io.lookupPc := io.lookup.bits.pc

  btb.io.update.valid          := io.update.valid && io.update.bits.taken
  btb.io.update.bits.pc        := io.update.bits.pc
  btb.io.update.bits.target    := io.update.bits.target
  btb.io.update.bits.cfiOffset := io.update.bits.pc(cfg.offsetBits - 1, 1)
  btb.io.update.bits.cfiType   := io.update.bits.cfiType

  bht.io.update.valid      := io.update.valid && io.update.bits.cfiType === CfiType.branch
  bht.io.update.bits.pc    := io.update.bits.pc
  bht.io.update.bits.taken := io.update.bits.taken

  val lookupOffset = io.lookup.bits.pc(cfg.offsetBits - 1, 1)
  val isBranch     = btb.io.resp.cfiType === CfiType.branch
  val hasCfi       = btb.io.resp.cfiType =/= CfiType.none
  val btbHit       = io.lookup.valid && btb.io.resp.hit && hasCfi
  val cfiInWindow  = btbHit && btb.io.resp.cfiOffset >= lookupOffset
  val predTaken    = cfiInWindow && Mux(isBranch, bht.io.taken, true.B)

  io.pred.valid     := cfiInWindow
  io.pred.taken     := predTaken
  io.pred.target    := Mux(predTaken, btb.io.resp.target, 0.U)
  io.pred.cfiOffset := Mux(cfiInWindow, btb.io.resp.cfiOffset, 0.U)
  io.pred.cfiType   := Mux(cfiInWindow, btb.io.resp.cfiType, CfiType.none)
}
