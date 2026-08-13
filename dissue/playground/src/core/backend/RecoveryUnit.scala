package top.core.backend

import chisel3._
import chisel3.util.{Mux1H, PopCount, Valid}
import top.config.BackendConfig
import top.core.backend.bundle.BranchResolve
import top.core.bundle.{CfiRecoveryPayload, Redirect, RobAge, RobRecovery}

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

    val recover     = Output(new RobRecovery(cfg.robIdxWidth))
    val redirect    = Output(new Redirect(cfg.addrWidth))
    val cfiRecovery = Output(Valid(new CfiRecoveryPayload(cfg.frontendPayload)))
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

  io.recover.valid     := anyGrant
  io.recover.robIdx    := Mux1H(grant, io.resolve.map(_.bits.robIdx))
  io.redirect.valid    := anyGrant
  io.redirect.target   := Mux1H(grant, io.resolve.map(_.bits.actualNpc))
  io.cfiRecovery.valid := anyGrant
  io.cfiRecovery.bits  := 0.U.asTypeOf(new CfiRecoveryPayload(cfg.frontendPayload))
  when(anyGrant) {
    io.cfiRecovery.bits.ftqTag          := Mux1H(grant, io.resolve.map(_.bits.ftqTag))
    io.cfiRecovery.bits.ftqInstOrdinal  := Mux1H(grant, io.resolve.map(_.bits.ftqInstOrdinal))
    io.cfiRecovery.bits.pc              := Mux1H(grant, io.resolve.map(_.bits.pc))
    io.cfiRecovery.bits.cfiType         := Mux1H(grant, io.resolve.map(_.bits.cfiType))
    io.cfiRecovery.bits.actualTaken     := Mux1H(grant, io.resolve.map(_.bits.taken))
    io.cfiRecovery.bits.actualTarget    := Mux1H(grant, io.resolve.map(_.bits.branchTarget))
    io.cfiRecovery.bits.actualNpc       := Mux1H(grant, io.resolve.map(_.bits.actualNpc))
    io.cfiRecovery.bits.instLen         := Mux1H(grant, io.resolve.map(_.bits.instLen))
    io.cfiRecovery.bits.rasAction       := Mux1H(grant, io.resolve.map(_.bits.rasAction))
    io.cfiRecovery.bits.canonicalReturn := Mux1H(grant, io.resolve.map(_.bits.canonicalReturn))
  }

  assert(PopCount(grant) <= 1.U)
}
