package top.core.frontend.ifetch

import chisel3._
import top.config.FrontendConfig
import top.core.bundle.CfiType
import top.core.frontend.bundle.{AlignedInstructionGroup, CfiTarget, PredecodedInstructionGroup, RasAction}

/** RVC expansion and static CFI decode. This stage has no predictor or FTQ access. */
class PredecodeStage(cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val in  = Input(new AlignedInstructionGroup(cfg))
    val out = Output(new PredecodedInstructionGroup(cfg))
  })

  val expanders  = Seq.fill(cfg.frontendWidth)(Module(new RvcExpander))
  val stopBefore = Wire(Vec(cfg.frontendWidth, Bool()))
  stopBefore(0) := false.B
  io.out        := 0.U.asTypeOf(new PredecodedInstructionGroup(cfg))

  for (lane <- 0 until cfg.frontendWidth) {
    val aligned = io.in.insts(lane).bits
    expanders(lane).io.in := aligned.rawInst
    val inst     = expanders(lane).io.out.bits
    val cfiType  = RasAction.cfiType(inst)
    val cfiValid = cfiType =/= CfiType.none && !aligned.exception.valid
    val isBranch = cfiType === CfiType.branch
    val isJal    = cfiType === CfiType.jal

    io.out.insts(lane).valid                      := io.in.insts(lane).valid && !stopBefore(lane)
    io.out.insts(lane).bits.aligned               := aligned
    io.out.insts(lane).bits.inst                  := inst
    io.out.insts(lane).bits.fallThrough           := aligned.pc +% aligned.instLen
    io.out.insts(lane).bits.cfi.valid             := cfiValid
    io.out.insts(lane).bits.cfi.cfiType           := cfiType
    io.out.insts(lane).bits.cfi.rasAction         := RasAction.action(inst)
    io.out.insts(lane).bits.cfi.canonicalReturn   := RasAction.isCanonicalReturn(inst)
    io.out.insts(lane).bits.cfi.directTargetValid := isBranch || isJal
    io.out.insts(lane).bits.cfi.directTarget      := Mux(
      isBranch,
      CfiTarget.branch(aligned.pc, inst),
      Mux(isJal, CfiTarget.jal(aligned.pc, inst), 0.U)
    )

    if (lane + 1 < cfg.frontendWidth) {
      stopBefore(lane + 1) := stopBefore(lane) ||
        (io.in.insts(lane).valid && aligned.exception.valid)
    }

    if (lane > 0) {
      when(io.out.insts(lane).valid) {
        assert(io.out.insts(lane - 1).valid)
        assert(
          aligned.pc === io.out.insts(lane - 1).bits.aligned.pc +
            io.out.insts(lane - 1).bits.aligned.instLen
        )
      }
    }
  }
}
