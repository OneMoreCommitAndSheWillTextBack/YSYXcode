package top.core.backend.exception

import chisel3._
import chisel3.util.{Mux1H, PopCount, PriorityEncoderOH}
import top.core.backend.csr.{CsrArch, CsrMretCommit, CsrSretCommit, CsrStatus, CsrTrapCommit, Mstatus, PrivMode}
import top.core.bundle.Redirect
import top.config.BackendConfig

class TrapLane(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid     = Bool()
  val pc        = UInt(cfg.addrWidth.W)
  val inst      = UInt(cfg.dataWidth.W)
  val exception = new ExceptionInfo(cfg)
  val isEcall   = Bool()
  val isMret    = Bool()
  val isSret    = Bool()
  val isSfence  = Bool()
}

class TrapUnit(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val lanes     = Input(Vec(cfg.commitWidth, new TrapLane(cfg)))
    val csrStatus = Input(new CsrStatus(cfg))

    val laneException = Output(Vec(cfg.commitWidth, new ExceptionInfo(cfg)))
    val trapMask      = Output(UInt(cfg.commitWidth.W))
    val mretMask      = Output(UInt(cfg.commitWidth.W))
    val sretMask      = Output(UInt(cfg.commitWidth.W))
    val trap          = Output(new CsrTrapCommit(cfg))
    val mret          = Output(new CsrMretCommit(cfg))
    val sret          = Output(new CsrSretCommit(cfg))
    val redirect      = Output(new Redirect(cfg.addrWidth))
  })

  private val laneTrap = Wire(Vec(cfg.commitWidth, Bool()))
  private val laneMret = Wire(Vec(cfg.commitWidth, Bool()))
  private val laneSret = Wire(Vec(cfg.commitWidth, Bool()))

  for (i <- 0 until cfg.commitWidth) {
    val ecallException       = ExceptionInfo.raise(ExceptionCause.ecallFrom(io.csrStatus.priv.mode), 0.U, cfg)
    val illegalMretException = ExceptionInfo.raise(ExceptionCause.illegalInstr, io.lanes(i).inst, cfg)
    val mretIllegal          = io.lanes(i).isMret && io.csrStatus.priv.mode =/= PrivMode.M
    val sretIllegal          =
      io.lanes(i).isSret &&
        (io.csrStatus.priv.mode === PrivMode.U ||
          (io.csrStatus.priv.mode === PrivMode.S && io.csrStatus.mstatus(Mstatus.tsrBit)))
    val sfenceIllegal =
      io.lanes(i).isSfence &&
        (io.csrStatus.priv.mode === PrivMode.U ||
          (io.csrStatus.priv.mode === PrivMode.S && io.csrStatus.mstatus(Mstatus.tvmBit)))

    io.laneException(i)       := Mux(
      io.lanes(i).exception.valid,
      io.lanes(i).exception,
      Mux(mretIllegal || sretIllegal || sfenceIllegal, illegalMretException, ecallException)
    )
    io.laneException(i).valid :=
      io.lanes(i).valid && (io.lanes(i).exception.valid || io.lanes(i).isEcall || mretIllegal || sretIllegal || sfenceIllegal)

    laneTrap(i) := io.laneException(i).valid
    laneMret(i) := io.lanes(i).valid && io.lanes(i).isMret && !mretIllegal && !io.lanes(i).exception.valid
    laneSret(i) := io.lanes(i).valid && io.lanes(i).isSret && !sretIllegal && !io.lanes(i).exception.valid
  }

  io.trapMask := laneTrap.asUInt
  io.mretMask := laneMret.asUInt
  io.sretMask := laneSret.asUInt

  private val trapGrantOH      = PriorityEncoderOH(io.trapMask).asBools
  private val trapCause        = Mux1H(trapGrantOH, io.laneException.map(_.cause))
  private val trapIntr         = Mux1H(trapGrantOH, io.laneException.map(_.interrupt))
  private val trapToSupervisor = CsrArch.trapDelegated(
    trapCause,
    trapIntr,
    io.csrStatus.priv.mode,
    io.csrStatus.medeleg,
    io.csrStatus.mideleg,
    cfg
  )

  io.trap.valid        := io.trapMask.orR
  io.trap.toSupervisor := trapToSupervisor
  io.trap.epc          := Mux1H(trapGrantOH, io.lanes.map(_.pc))
  io.trap.cause        := Mux1H(trapGrantOH, io.laneException.map(_.csrCause))
  io.trap.tval         := Mux1H(trapGrantOH, io.laneException.map(_.tval))

  io.mret.valid := io.mretMask.orR
  io.sret.valid := io.sretMask.orR

  io.redirect.valid  := io.trap.valid || io.mret.valid || io.sret.valid
  io.redirect.target := Mux(
    io.trap.valid,
    CsrArch.trapVector(trapToSupervisor, io.csrStatus.mtvec, io.csrStatus.stvec, trapCause, trapIntr, cfg),
    Mux(io.mret.valid, io.csrStatus.mretTarget, io.csrStatus.sretTarget)
  )

  assert(PopCount(laneTrap) <= 1.U)
  assert(PopCount(laneMret) <= 1.U)
  assert(PopCount(laneSret) <= 1.U)
  assert(PopCount(VecInit(Seq(io.trap.valid, io.mret.valid, io.sret.valid))) <= 1.U)
}
