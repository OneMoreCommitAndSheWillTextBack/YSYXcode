package top.backend.csr

import chisel3._
import top.config.BackendConfig
import top.dpi.NpcContextDpi

class CsrDpiBridge(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val state = Input(new CsrDpiState(cfg))
  })

  private val dpi = Module(new NpcContextDpi)
  dpi.suggestName("contextDpi")

  dpi.contextValid := true.B
  dpi.pc           := io.state.pc
  dpi.privMode     := io.state.priv.mode.pad(32)
  dpi.mstatus      := io.state.mstatus
  dpi.mtvec        := io.state.mtvec
  dpi.mepc         := io.state.mepc
  dpi.mcause       := io.state.mcause
  dpi.mtval        := io.state.mtval
  dpi.mie          := 0.U
  dpi.mip          := 0.U
  dpi.mscratch     := 0.U
  dpi.mcycle       := 0.U
  dpi.minstret     := 0.U
}
