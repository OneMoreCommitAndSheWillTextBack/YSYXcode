package top.backend.csr

import chisel3._
import chisel3.util.MuxLookup
import top.config.BackendConfig

class CsrFile(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         BackendConfig = BackendConfig())
    extends Module {
  val io = IO(new CsrFileIO(cfg))

  private def data(value: BigInt): UInt =
    value.U(cfg.dataWidth.W)

  private def maskWrite(old: UInt, wdata: UInt, mask: BigInt): UInt = {
    val writeMask = data(mask)
    (old & ~writeMask).asUInt | (wdata & writeMask)
  }

  private def canonicalMepc(wdata: UInt): UInt =
    wdata & ~1.U(cfg.dataWidth.W)

  private def writeMstatus(old: UInt, wdata: UInt): UInt =
    maskWrite(old, wdata, CsrSpec.byAddr(CsrAddr.mstatus).writeMask)

  private def writeMtvec(old: UInt, wdata: UInt): UInt =
    maskWrite(old, wdata, CsrSpec.byAddr(CsrAddr.mtvec).writeMask)

  private def trapBase(mtvecValue: UInt): UInt =
    mtvecValue(cfg.addrWidth - 1, 2) ## 0.U(2.W)

  private def trapMstatus(old: UInt, previousPriv: UInt): UInt = {
    val writeMask = data(Mstatus.trapWriteMask)
    val mpie      = old(Mstatus.mieBit).asUInt << Mstatus.mpieBit
    val mpp       = previousPriv.pad(cfg.dataWidth) << Mstatus.mppLsb

    (old & ~writeMask).asUInt | mpie | mpp
  }

  private val mstatus = RegInit(data(CsrSpec.byAddr(CsrAddr.mstatus).reset))
  private val mtvec   = RegInit(data(CsrSpec.byAddr(CsrAddr.mtvec).reset))
  private val mepc    = RegInit(data(CsrSpec.byAddr(CsrAddr.mepc).reset))
  private val mcause  = RegInit(data(CsrSpec.byAddr(CsrAddr.mcause).reset))
  private val mtval   = RegInit(data(CsrSpec.byAddr(CsrAddr.mtval).reset))
  private val priv    = RegInit(PrivMode.M)

  private def readValue(
    addr:         UInt,
    mstatusValue: UInt,
    mtvecValue:   UInt,
    mepcValue:    UInt,
    mcauseValue:  UInt,
    mtvalValue:   UInt
  ): UInt =
    MuxLookup(addr, 0.U(cfg.dataWidth.W))(
      Seq(
        CsrAddr(CsrAddr.mstatus) -> mstatusValue,
        CsrAddr(CsrAddr.mtvec)   -> mtvecValue,
        CsrAddr(CsrAddr.mepc)    -> mepcValue,
        CsrAddr(CsrAddr.mcause)  -> mcauseValue,
        CsrAddr(CsrAddr.mtval)   -> mtvalValue
      )
    )

  private var nextMstatus = mstatus
  private var nextMtvec   = mtvec
  private var nextMepc    = mepc
  private var nextMcause  = mcause
  private var nextMtval   = mtval

  for (lane <- 0 until cfg.commitWidth) {
    val commit = io.commit(lane)
    nextMstatus = Mux(
      commit.valid && commit.bits.addr === CsrAddr(CsrAddr.mstatus),
      writeMstatus(nextMstatus, commit.bits.wdata),
      nextMstatus
    )
    nextMtvec = Mux(
      commit.valid && commit.bits.addr === CsrAddr(CsrAddr.mtvec),
      writeMtvec(nextMtvec, commit.bits.wdata),
      nextMtvec
    )
    nextMepc = Mux(
      commit.valid && commit.bits.addr === CsrAddr(CsrAddr.mepc),
      canonicalMepc(commit.bits.wdata),
      nextMepc
    )
    nextMcause = Mux(
      commit.valid && commit.bits.addr === CsrAddr(CsrAddr.mcause),
      commit.bits.wdata,
      nextMcause
    )
    nextMtval = Mux(
      commit.valid && commit.bits.addr === CsrAddr(CsrAddr.mtval),
      commit.bits.wdata,
      nextMtval
    )
  }

  nextMstatus = Mux(io.trap.valid, trapMstatus(nextMstatus, priv), nextMstatus)
  nextMepc = Mux(io.trap.valid, canonicalMepc(io.trap.epc), nextMepc)
  nextMcause = Mux(io.trap.valid, io.trap.cause, nextMcause)
  nextMtval = Mux(io.trap.valid, io.trap.tval, nextMtval)

  io.read.data := readValue(io.read.addr, nextMstatus, nextMtvec, nextMepc, nextMcause, nextMtval)

  when(io.commit.map(_.valid).reduce(_ || _) || io.trap.valid) {
    mstatus := nextMstatus
    mtvec   := nextMtvec
    mepc    := nextMepc
    mcause  := nextMcause
    mtval   := nextMtval
  }

  when(io.trap.valid) {
    priv := PrivMode.M
  }

  io.status.priv.mode  := priv
  io.status.trapVector := trapBase(nextMtvec)

  private val contextPc = RegInit(resetVector.U(cfg.addrWidth.W))
  when(io.context.valid) {
    contextPc := io.context.pc
  }

  private val dpi = Module(new CsrDpiBridge(cfg))
  dpi.suggestName("contextDpiBridge")
  dpi.io.state.pc        := Mux(io.context.valid, io.context.pc, contextPc)
  dpi.io.state.priv.mode := Mux(io.trap.valid, PrivMode.M, priv)
  dpi.io.state.mstatus   := nextMstatus
  dpi.io.state.mtvec     := nextMtvec
  dpi.io.state.mepc      := nextMepc
  dpi.io.state.mcause    := nextMcause
  dpi.io.state.mtval     := nextMtval
}
