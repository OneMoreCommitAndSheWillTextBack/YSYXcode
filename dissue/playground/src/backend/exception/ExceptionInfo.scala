package top.backend.exception

import chisel3._
import top.config.BackendConfig

class ExceptionInfo(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid     = Bool()
  val interrupt = Bool()
  val cause     = UInt(ExceptionCause.width.W)
  val tval      = UInt(cfg.dataWidth.W)

  def csrCause: UInt =
    ExceptionCause.toCsrCause(cause, interrupt, cfg)
}

object ExceptionInfo {
  def none(cfg: BackendConfig = BackendConfig()): ExceptionInfo = {
    val info = Wire(new ExceptionInfo(cfg))
    info.valid     := false.B
    info.interrupt := false.B
    info.cause     := 0.U
    info.tval      := 0.U
    info
  }

  def raise(cause: UInt, tval: UInt, cfg: BackendConfig = BackendConfig()): ExceptionInfo = {
    val info = none(cfg)
    info.valid := true.B
    info.cause := cause
    info.tval  := tval.pad(cfg.dataWidth)(cfg.dataWidth - 1, 0)
    info
  }

  def interrupt(cause: UInt, cfg: BackendConfig = BackendConfig()): ExceptionInfo = {
    val info = none(cfg)
    info.valid     := true.B
    info.interrupt := true.B
    info.cause     := cause
    info
  }
}
