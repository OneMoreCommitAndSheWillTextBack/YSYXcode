package top.core.trace

import chisel3._
import chisel3.util.Valid
import top.config.FrontendConfig
import top.core.frontend.bundle.{FetchTargetTag, FetchToken, FrontendRecovery}

class FtqTraceSample(commitWidth: Int) extends Bundle {
  val reserve         = Bool()
  val finalResult     = Bool()
  val fetch           = Bool()
  val complete        = Bool()
  val retire          = Vec(commitWidth, Bool())
  val recovery        = Bool()
  val staleUpdateDrop = Bool()
}

/** Passive FTQ lifecycle observer. The new FTQ connects these semantic boundary events in Phase 4. */
class FtqTrace(cfg: FrontendConfig, commitWidth: Int) extends Module {
  require(commitWidth > 0, "FTQ trace commit width must be positive")

  val io = IO(new Bundle {
    val reserve         = Input(Valid(new FetchToken(cfg)))
    val finalResult     = Input(Valid(new FetchToken(cfg)))
    val fetch           = Input(new DecoupledTraceTap(new FetchToken(cfg)))
    val complete        = Input(Valid(new FetchToken(cfg)))
    val retire          = Input(Vec(commitWidth, Valid(new FetchTargetTag(cfg.payload))))
    val recovery        = Input(Valid(new FrontendRecovery(cfg)))
    val staleUpdateDrop = Input(Bool())

    val sample = Output(new FtqTraceSample(commitWidth))
  })

  io.sample.reserve         := io.reserve.valid
  io.sample.finalResult     := io.finalResult.valid
  io.sample.fetch           := io.fetch.fire
  io.sample.complete        := io.complete.valid
  io.sample.recovery        := io.recovery.valid
  io.sample.staleUpdateDrop := io.staleUpdateDrop
  for (lane <- 0 until commitWidth) {
    io.sample.retire(lane) := io.retire(lane).valid
  }
}
