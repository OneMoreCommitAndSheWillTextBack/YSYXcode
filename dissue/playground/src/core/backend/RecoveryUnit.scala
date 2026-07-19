package top.core.backend

import chisel3._
import chisel3.util.{Mux1H, PopCount, Valid}
import top.config.{BackendConfig, ICacheConfig}
import top.core.backend.bundle.BranchResolve
import top.core.bundle.{Redirect, RobAge, RobRecovery}
import top.core.frontend.bundle.PredictionMeta

/** Converts registered EXU control-flow outcomes into one selective recovery request.
  *
  * Execution units may resolve more than one CFI in a configurable machine. Recovery always chooses the oldest
  * misprediction relative to the current ROB head, so an older redirect cannot be overwritten by an independently
  * resolved younger path.
  */
class RecoveryUnit(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val resolve = Input(Vec(cfg.intIssueWidth, Valid(new BranchResolve(cfg))))
    val robHead = Input(UInt(cfg.robIdxWidth.W))

    val recover  = Output(new RobRecovery(cfg.robIdxWidth))
    val redirect = Output(new Redirect(cfg.addrWidth))
    val predictorRecovery = Output(Valid(new PredictionMeta(ICacheConfig(addrWidth = cfg.addrWidth))))
  })

  private val mispredict = Wire(Vec(cfg.intIssueWidth, Bool()))
  private val age        = Wire(Vec(cfg.intIssueWidth, UInt((cfg.robIdxWidth + 1).W)))
  private val grant      = Wire(Vec(cfg.intIssueWidth, Bool()))

  for (port <- 0 until cfg.intIssueWidth) {
    val resolve = io.resolve(port)
    mispredict(port) := resolve.valid && resolve.bits.actualNpc =/= resolve.bits.predNpc
    age(port)        := RobAge.fromHead(resolve.bits.robIdx, io.robHead, cfg.robEntries, cfg.robIdxWidth)

    val hasOlder = (0 until cfg.intIssueWidth).map { other =>
      val olderAge = age(other) < age(port)
      val tieBreak = if (other < port) age(other) === age(port) else false.B
      mispredict(other) && (olderAge || tieBreak)
    }.reduce(_ || _)
    grant(port) := mispredict(port) && !hasOlder
  }

  private val anyGrant = grant.asUInt.orR

  io.recover.valid  := anyGrant
  io.recover.robIdx := Mux1H(grant, io.resolve.map(_.bits.robIdx))
  io.redirect.valid := anyGrant
  io.redirect.target := Mux1H(grant, io.resolve.map(_.bits.actualNpc))
  io.predictorRecovery.valid := anyGrant
  io.predictorRecovery.bits := 0.U.asTypeOf(new PredictionMeta(ICacheConfig(addrWidth = cfg.addrWidth)))
  when(anyGrant) {
    io.predictorRecovery.bits := Mux1H(grant, io.resolve.map(_.bits.prediction))
  }

  assert(PopCount(grant) <= 1.U)
}
