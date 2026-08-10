package top.core.frontend.ifetch

import chisel3._
import chisel3.util.{Decoupled, Valid}
import top.config.{FrontendConfig, FrontendPayloadConfig}
import top.core.bundle.FetchInstPayload
import top.core.frontend.bundle._

object FetchWidth {
  val backend                 = 2
  val frontend                = 4
  val maxInstructionHalfwords = 2
}

class FetchPacket(cfg: FrontendPayloadConfig) extends Bundle {
  val insts = Vec(FetchWidth.backend, Valid(new FetchInstPayload(cfg)))
}

/** Phase 5 IFU composition. Prediction is consulted only after the registered align boundary. */
class IFetch(cfg: FrontendConfig = FrontendConfig()) extends Module {
  require(cfg.frontendWidth == FetchWidth.frontend, "IFetch output width must match FetchWidth.frontend")

  val io = IO(new Bundle {
    val flush            = Input(Bool())
    val acceptCorrection = Input(Bool())
    val icacheResp       = Flipped(Decoupled(new ICacheFetchResp(cfg)))

    val blockLookupToken   = Output(new FetchToken(cfg))
    val blockLookup        = Input(Valid(new FtqIfuView(cfg)))
    val alignLookupToken   = Output(new FetchToken(cfg))
    val alignLookup        = Input(Valid(new FtqIfuView(cfg)))
    val checkerLookupToken = Output(new FetchToken(cfg))
    val checkerLookup      = Input(Valid(new FtqIfuView(cfg)))

    val correction   = Valid(new IfuControlResult(cfg))
    val fetchEnqueue = Decoupled(new FetchQueueEnqueue(cfg, FetchWidth.frontend))
    val emission     = Output(Vec(cfg.frontendWidth, Valid(new FtqIfuEmission(cfg))))

    val staleResponseDrop = Output(Bool())
  })

  val blockBuffer = Module(new FetchBlockBuffer(cfg, cfg.ftqEntries))
  val aligner     = Module(new InstructionAligner(cfg, cfg.ifetch.halfwordEntries))
  val predecode   = Module(new PredecodeStage(cfg))
  val checker     = Module(new PredictionChecker(cfg))

  blockBuffer.io.flush    := io.flush
  blockBuffer.io.in <> io.icacheResp
  io.blockLookupToken     := blockBuffer.io.out.bits.token
  blockBuffer.io.headLive := io.blockLookup.valid

  aligner.io.flush         := io.flush
  aligner.io.in.valid      := blockBuffer.io.out.valid && io.blockLookup.valid
  aligner.io.in.bits       := blockBuffer.io.out.bits
  aligner.io.context       := io.blockLookup
  blockBuffer.io.out.ready := aligner.io.in.ready && io.blockLookup.valid

  io.alignLookupToken := aligner.io.headToken
  aligner.io.headLive := io.alignLookup.valid

  val alignedValid      = RegInit(false.B)
  val alignedBits       = Reg(new AlignedInstructionGroup(cfg))
  val correctionApplied = RegInit(false.B)

  predecode.io.in       := alignedBits
  io.checkerLookupToken := alignedBits.insts(0).bits.token
  checker.io.in         := predecode.io.out
  checker.io.view       := io.checkerLookup

  val stageStale      = alignedValid && !io.checkerLookup.valid
  val stageCorrection = alignedValid && io.checkerLookup.valid && checker.io.out.control.redirectValid
  val enqueueAllowed  = alignedValid && io.checkerLookup.valid && (!stageCorrection || correctionApplied)

  io.fetchEnqueue.valid := enqueueAllowed && checker.io.out.insts(0).valid
  io.fetchEnqueue.bits  := 0.U.asTypeOf(new FetchQueueEnqueue(cfg, FetchWidth.frontend))
  for (lane <- 0 until cfg.frontendWidth) {
    val checked    = checker.io.out.insts(lane)
    val aligned    = checked.bits.predecoded.aligned
    val predecoded = checked.bits.predecoded
    val decision   = checked.bits.prediction

    io.fetchEnqueue.bits.insts(lane).valid                    := checked.valid
    io.fetchEnqueue.bits.insts(lane).bits.sequence            := aligned.sequence
    io.fetchEnqueue.bits.insts(lane).bits.epoch               := aligned.token.streamEpoch
    io.fetchEnqueue.bits.insts(lane).bits.inst.pc             := aligned.pc
    io.fetchEnqueue.bits.insts(lane).bits.inst.inst           := predecoded.inst
    io.fetchEnqueue.bits.insts(lane).bits.inst.rawInst        := aligned.rawInst
    io.fetchEnqueue.bits.insts(lane).bits.inst.isRVC          := aligned.isRvc
    io.fetchEnqueue.bits.insts(lane).bits.inst.instLen        := aligned.instLen
    io.fetchEnqueue.bits.insts(lane).bits.inst.predHit        := decision.hit
    io.fetchEnqueue.bits.insts(lane).bits.inst.predTaken      := decision.taken
    io.fetchEnqueue.bits.insts(lane).bits.inst.predNpc        := decision.npc
    io.fetchEnqueue.bits.insts(lane).bits.inst.predTarget     := decision.target
    io.fetchEnqueue.bits.insts(lane).bits.inst.ftqTag         := aligned.token.tag
    io.fetchEnqueue.bits.insts(lane).bits.inst.ftqInstOrdinal := aligned.instOrdinal
    io.fetchEnqueue.bits.insts(lane).bits.inst.exception      := aligned.exception
  }

  io.correction.valid := stageCorrection && !correctionApplied
  io.correction.bits  := checker.io.out.control

  val stageConsumed  = io.fetchEnqueue.fire || stageStale
  val stageCanAccept = !alignedValid || stageConsumed
  aligner.io.out.ready := !io.flush && stageCanAccept

  aligner.io.kill.valid := io.fetchEnqueue.fire && checker.io.out.control.emissionDone
  aligner.io.kill.bits  := checker.io.out.control.token

  for (lane <- 0 until cfg.frontendWidth) {
    val checked        = checker.io.out.insts(lane)
    val aligned        = checked.bits.predecoded.aligned
    val correctionLane = checker.io.out.control.redirectValid &&
      aligned.instOrdinal === checker.io.out.control.cfiOrdinal

    io.emission(lane)                      := 0.U.asTypeOf(io.emission(lane))
    io.emission(lane).valid                := io.fetchEnqueue.fire && checked.valid
    io.emission(lane).bits.token           := aligned.token
    io.emission(lane).bits.instOrdinal     := aligned.instOrdinal
    io.emission(lane).bits.terminatesEntry := aligned.lastInFtqEntry ||
      checked.bits.prediction.taken || aligned.exception.valid || correctionLane
  }

  when(io.flush) {
    when(io.acceptCorrection && alignedValid && stageCorrection) {
      alignedValid      := true.B
      correctionApplied := true.B
    }.otherwise {
      alignedValid      := false.B
      correctionApplied := false.B
    }
  }.elsewhen(stageCanAccept) {
    when(aligner.io.out.fire) {
      alignedValid      := true.B
      alignedBits       := aligner.io.out.bits
      correctionApplied := false.B
    }.otherwise {
      alignedValid      := false.B
      correctionApplied := false.B
    }
  }

  io.staleResponseDrop := blockBuffer.io.staleDrop || aligner.io.staleDrop || stageStale

  when(io.acceptCorrection) {
    assert(io.flush)
    assert(io.correction.valid)
  }
  when(io.fetchEnqueue.fire) {
    assert(checker.io.out.insts(0).valid)
  }
}
