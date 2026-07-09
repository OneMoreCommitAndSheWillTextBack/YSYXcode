package top.core.backend.exception

import chisel3._
import chisel3.util.{Cat, MuxLookup}
import top.core.backend.csr.PrivMode
import top.config.BackendConfig

object ExceptionCause {
  val width = 5

  val instrAddrMisaligned = 0.U(width.W)
  val instrAccessFault    = 1.U(width.W)
  val illegalInstr        = 2.U(width.W)
  val breakpoint          = 3.U(width.W)
  val loadAddrMisaligned  = 4.U(width.W)
  val loadAccessFault     = 5.U(width.W)
  val storeAddrMisaligned = 6.U(width.W)
  val storeAccessFault    = 7.U(width.W)
  val ecallFromU          = 8.U(width.W)
  val ecallFromS          = 9.U(width.W)
  val ecallFromM          = 11.U(width.W)
  val instrPageFault      = 12.U(width.W)
  val loadPageFault       = 13.U(width.W)
  val storePageFault      = 15.U(width.W)

  val supervisorSoftwareInterrupt = 1.U(width.W)
  val machineSoftwareInterrupt    = 3.U(width.W)
  val supervisorTimerInterrupt    = 5.U(width.W)
  val machineTimerInterrupt       = 7.U(width.W)
  val supervisorExternalInterrupt = 9.U(width.W)
  val machineExternalInterrupt    = 11.U(width.W)

  def ecallFrom(mode: UInt): UInt =
    MuxLookup(mode, ecallFromM)(
      Seq(
        PrivMode.U -> ecallFromU,
        PrivMode.S -> ecallFromS,
        PrivMode.M -> ecallFromM
      )
    )

  def toCsrCause(cause: UInt, interrupt: Bool, cfg: BackendConfig): UInt =
    Cat(interrupt, 0.U((cfg.dataWidth - width - 1).W), cause)
}
