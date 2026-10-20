package top.core.monitor

import chisel3._
import chisel3.util.Valid
import top.config.BackendConfig
import top.core.backend.bundle.CommitRegWrite
import top.core.backend.csr.{CsrCommit, CsrContextUpdate, CsrMretCommit, CsrSretCommit, CsrTrapCommit}

/** Sim-only retirement-side state consumed by the difftest shadow model. */
class DifftestSample(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val regWrite  = Vec(cfg.commitWidth, new CommitRegWrite(cfg))
  val csrCommit = Vec(cfg.commitWidth, Valid(new CsrCommit(cfg)))
  val csrTrap   = new CsrTrapCommit(cfg)
  val csrMret   = new CsrMretCommit(cfg)
  val csrSret   = new CsrSretCommit(cfg)
  val context   = new CsrContextUpdate(cfg)
}
