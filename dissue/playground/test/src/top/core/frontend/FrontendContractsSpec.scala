package top.core.frontend

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.util.{log2Ceil, Valid}
import top.config.FrontendConfig
import top.core.frontend.bundle.{FrontendRecovery, FrontendRecoveryArbiter, FrontendRecoveryKind}
import top.core.frontend.ifetch.FetchTargetQueue

private class FtqIdentityHarness(cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val redirect   = Input(Bool())
    val reserve    = Input(Bool())
    val ready      = Output(Bool())
    val index      = Output(UInt(cfg.ftqIndexBits.W))
    val generation = Output(UInt(cfg.ftqGenerationBits.W))
    val epoch      = Output(UInt(cfg.fetchEpochBits.W))
  })

  val ftq = Module(new FetchTargetQueue(cfg))
  ftq.io.reserve.valid        := io.reserve
  ftq.io.reserve.bits.startPc := "h80000000".U
  ftq.io.writeFast            := 0.U.asTypeOf(ftq.io.writeFast)
  ftq.io.writeFinal           := 0.U.asTypeOf(ftq.io.writeFinal)
  ftq.io.fetchTarget.ready    := false.B
  ftq.io.fetchComplete        := 0.U.asTypeOf(ftq.io.fetchComplete)
  ftq.io.blockLookupToken     := 0.U.asTypeOf(ftq.io.blockLookupToken)
  ftq.io.alignLookupToken     := 0.U.asTypeOf(ftq.io.alignLookupToken)
  ftq.io.checkerLookupToken   := 0.U.asTypeOf(ftq.io.checkerLookupToken)
  ftq.io.backendLookupTag     := 0.U.asTypeOf(ftq.io.backendLookupTag)
  for (lane <- ftq.io.ifuEmission.indices) {
    ftq.io.ifuEmission(lane) := 0.U.asTypeOf(ftq.io.ifuEmission(lane))
  }
  for (lane <- ftq.io.retire.indices) {
    ftq.io.retire(lane) := 0.U.asTypeOf(ftq.io.retire(lane))
  }
  ftq.io.recovery := 0.U.asTypeOf(ftq.io.recovery)
  ftq.io.recovery.valid           := io.redirect
  ftq.io.recovery.bits.kind       := FrontendRecoveryKind.reset
  ftq.io.recovery.bits.tokenValid := false.B

  io.ready      := ftq.io.reserve.ready
  io.index      := ftq.io.reserveToken.tag.index
  io.generation := ftq.io.reserveToken.tag.generation
  io.epoch      := ftq.io.reserveToken.streamEpoch
}

private class RecoveryArbiterHarness(cfg: FrontendConfig) extends Module {
  val io = IO(new Bundle {
    val backendValid   = Input(Bool())
    val ifuValid       = Input(Bool())
    val bpuValid       = Input(Bool())
    val selectedValid  = Output(Bool())
    val selectedTarget = Output(UInt(cfg.addrWidth.W))
    val selectedKind   = Output(FrontendRecoveryKind())
  })

  private def recovery(valid: Bool, target: Int, kind: FrontendRecoveryKind.Type) = {
    val event = Wire(Valid(new FrontendRecovery(cfg)))
    event                 := 0.U.asTypeOf(event)
    event.valid           := valid
    event.bits.kind       := kind
    event.bits.tokenValid := kind =/= FrontendRecoveryKind.trap && kind =/= FrontendRecoveryKind.reset
    event.bits.targetPc   := target.U
    event
  }

  val backend  = recovery(io.backendValid, 0x100, FrontendRecoveryKind.backend)
  val ifu      = recovery(io.ifuValid, 0x200, FrontendRecoveryKind.ifuCorrection)
  val bpu      = recovery(io.bpuValid, 0x300, FrontendRecoveryKind.bpuOverride)
  val selected = FrontendRecoveryArbiter.select(backend, ifu, bpu, cfg)

  io.selectedValid  := selected.valid
  io.selectedTarget := selected.bits.targetPc
  io.selectedKind   := selected.bits.kind
}

object FrontendContractsSpec {
  private val cfg = FrontendConfig(fetchTargetEntries = 4, ftqGenerationBits = 3)

  def main(args: Array[String]): Unit = {
    assert(cfg.fetchGroupBytes == 16)
    assert(cfg.maxInstsPerFtqEntry == 8)
    assert(cfg.ftqInstCountBits == log2Ceil(9))
    assert((1 << cfg.ftqInstCountBits) > cfg.maxInstsPerFtqEntry)

    simulate(new FtqIdentityHarness(cfg)) { dut =>
      dut.io.redirect.poke(false)
      dut.io.reserve.poke(false)
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      dut.io.ready.expect(true)
      dut.io.index.expect(0)
      dut.io.generation.expect(1)
      dut.io.epoch.expect(0)

      dut.io.reserve.poke(true)
      dut.clock.step()
      dut.io.reserve.poke(false)

      dut.io.redirect.poke(true)
      dut.clock.step()
      dut.io.redirect.poke(false)

      dut.io.ready.expect(true)
      dut.io.index.expect(0)
      dut.io.generation.expect(2)
      dut.io.epoch.expect(1)
    }

    simulate(new RecoveryArbiterHarness(cfg)) { dut =>
      dut.io.backendValid.poke(false)
      dut.io.ifuValid.poke(false)
      dut.io.bpuValid.poke(false)
      dut.io.selectedValid.expect(false)

      dut.io.bpuValid.poke(true)
      dut.io.selectedValid.expect(true)
      dut.io.selectedTarget.expect(0x300)
      dut.io.selectedKind.expect(FrontendRecoveryKind.bpuOverride)

      dut.io.ifuValid.poke(true)
      dut.io.selectedTarget.expect(0x200)
      dut.io.selectedKind.expect(FrontendRecoveryKind.ifuCorrection)

      dut.io.backendValid.poke(true)
      dut.io.selectedTarget.expect(0x100)
      dut.io.selectedKind.expect(FrontendRecoveryKind.backend)
    }

    println("FrontendContractsSpec: PASS")
  }
}
