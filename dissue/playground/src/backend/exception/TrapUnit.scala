package top.backend.exception

import chisel3._
import chisel3.util.{Mux1H, PopCount, PriorityEncoderOH}
import top.backend.csr.{CsrMretCommit, CsrStatus, CsrTrapCommit}
import top.bundle.Redirect
import top.config.BackendConfig

class TrapLane(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid     = Bool()
  val pc        = UInt(cfg.addrWidth.W)
  val exception = new ExceptionInfo(cfg)
  val isEcall   = Bool()
  val isMret    = Bool()
}

class TrapUnit(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val lanes     = Input(Vec(cfg.commitWidth, new TrapLane(cfg)))
    val csrStatus = Input(new CsrStatus(cfg))

    val laneException = Output(Vec(cfg.commitWidth, new ExceptionInfo(cfg)))
    val trapMask      = Output(UInt(cfg.commitWidth.W))
    val mretMask      = Output(UInt(cfg.commitWidth.W))
    val trap          = Output(new CsrTrapCommit(cfg))
    val mret          = Output(new CsrMretCommit(cfg))
    val redirect      = Output(new Redirect(cfg.addrWidth))
  })

  private val laneTrap = Wire(Vec(cfg.commitWidth, Bool()))
  private val laneMret = Wire(Vec(cfg.commitWidth, Bool()))

  for (i <- 0 until cfg.commitWidth) {
    val ecallException = ExceptionInfo.raise(ExceptionCause.ecallFrom(io.csrStatus.priv.mode), 0.U, cfg)

    io.laneException(i)       := Mux(io.lanes(i).exception.valid, io.lanes(i).exception, ecallException)
    io.laneException(i).valid := io.lanes(i).valid && (io.lanes(i).exception.valid || io.lanes(i).isEcall)

    laneTrap(i) := io.laneException(i).valid
    laneMret(i) := io.lanes(i).valid && io.lanes(i).isMret
  }

  io.trapMask := laneTrap.asUInt
  io.mretMask := laneMret.asUInt

  private val trapGrantOH = PriorityEncoderOH(io.trapMask).asBools
  private val mretGrantOH = PriorityEncoderOH(io.mretMask).asBools

  io.trap.valid := io.trapMask.orR
  io.trap.epc   := Mux1H(trapGrantOH, io.lanes.map(_.pc))
  io.trap.cause := Mux1H(trapGrantOH, io.laneException.map(_.csrCause))
  io.trap.tval  := Mux1H(trapGrantOH, io.laneException.map(_.tval))

  io.mret.valid := io.mretMask.orR

  io.redirect.valid  := io.trap.valid || io.mret.valid
  io.redirect.target := Mux(io.trap.valid, io.csrStatus.trapVector, io.csrStatus.mretTarget)

  assert(PopCount(laneTrap) <= 1.U)
  assert(PopCount(laneMret) <= 1.U)
  assert(!(io.trap.valid && io.mret.valid))
}
