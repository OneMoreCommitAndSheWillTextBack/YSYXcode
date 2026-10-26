package top.core.backend.lsu

import chisel3._
import chisel3.util.MuxLookup
import top.config.BackendConfig
import top.core.backend.bundle.DtlbEntry
import top.core.backend.csr.{Mstatus, PrivMode}
import top.core.backend.exception.{ExceptionCause, ExceptionInfo}
import top.core.mmu.MmuAccessType

/** Combinational permission and page-fault check for a DTLB hit.
  *
  * The entry stores PTE permission bits, not the result of a previous access. Privilege, SUM, and MXR are sampled from
  * the current request so that a cached translation cannot bypass a later permission change.
  */
class DtlbPermissionCheck(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val entry     = Input(new DtlbEntry(cfg))
    val access    = Input(UInt(MmuAccessType.width.W))
    val priv      = Input(UInt(PrivMode.width.W))
    val mstatus   = Input(UInt(cfg.dataWidth.W))
    val vaddr     = Input(UInt(cfg.addrWidth.W))
    val exception = Output(new ExceptionInfo(cfg))
  })

  private val isLoad  = io.access === MmuAccessType.load
  private val isStore = io.access === MmuAccessType.store
  private val isAmo   = io.access === MmuAccessType.amo

  private val sum = io.mstatus(Mstatus.sumBit)
  private val mxr = io.mstatus(Mstatus.mxrBit)

  private val readOk  = io.entry.r || (mxr && io.entry.x)
  private val writeOk = io.entry.r && io.entry.w
  private val execOk  = io.entry.x

  private val accessOk = MuxLookup(io.access, readOk)(
    Seq(
      MmuAccessType.fetch -> execOk,
      MmuAccessType.load  -> readOk,
      MmuAccessType.store -> writeOk,
      MmuAccessType.amo   -> (readOk && writeOk)
    )
  )

  private val privOk = Mux(
    io.priv === PrivMode.U,
    io.entry.u,
    Mux(
      io.priv === PrivMode.S,
      !io.entry.u || (sum && (isLoad || isStore || isAmo)),
      true.B
    )
  )

  private val adOk = io.entry.a && (!(isStore || isAmo) || io.entry.d)

  private val fault = !(io.entry.valid && accessOk && privOk && adOk)

  private val cause = MuxLookup(io.access, ExceptionCause.loadPageFault)(
    Seq(
      MmuAccessType.fetch -> ExceptionCause.instrPageFault,
      MmuAccessType.load  -> ExceptionCause.loadPageFault,
      MmuAccessType.store -> ExceptionCause.storePageFault,
      MmuAccessType.amo   -> ExceptionCause.storePageFault
    )
  )

  io.exception := ExceptionInfo.none(cfg)
  when(fault) {
    io.exception := ExceptionInfo.raise(cause, io.vaddr, cfg)
  }
}
