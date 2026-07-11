package top.core.backend.csr

import chisel3._
import chisel3.util.{log2Ceil, Valid}
import top.config.BackendConfig

class CsrReadPort(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val addr       = Output(UInt(CsrAddr.width.W))
  val data       = Input(UInt(cfg.dataWidth.W))
  val readLegal  = Input(Bool())
  val writeLegal = Input(Bool())
}

class CsrCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val addr  = UInt(CsrAddr.width.W)
  val wdata = UInt(cfg.dataWidth.W)
}

class CsrContextUpdate(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
  val pc    = UInt(cfg.addrWidth.W)
}

class CsrTrapCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid        = Bool()
  val toSupervisor = Bool()
  val epc          = UInt(cfg.addrWidth.W)
  val cause        = UInt(cfg.dataWidth.W)
  val tval         = UInt(cfg.dataWidth.W)
}

class CsrMretCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
}

class CsrSretCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
}

class CsrStatus(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val priv       = new PrivState
  val mretTarget = UInt(cfg.addrWidth.W)
  val sretTarget = UInt(cfg.addrWidth.W)
  val mstatus    = UInt(cfg.dataWidth.W)
  val satp       = UInt(cfg.dataWidth.W)
  val mtvec      = UInt(cfg.dataWidth.W)
  val stvec      = UInt(cfg.dataWidth.W)
  val medeleg    = UInt(cfg.dataWidth.W)
  val mideleg    = UInt(cfg.dataWidth.W)
  val mie        = UInt(cfg.dataWidth.W)
  val mip        = UInt(cfg.dataWidth.W)
}

class CsrInterruptPending extends Bundle {
  val msip = Bool()
  val mtip = Bool()
  val meip = Bool()
  val seip = Bool()
}

class CsrTrackerAlloc(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
  val addr   = UInt(CsrAddr.width.W)
}

class CsrTrackerCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid  = Bool()
  val robIdx = UInt(cfg.robIdxWidth.W)
}

class CsrTrackerQuery(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid                  = Input(Bool())
  val robIdx                 = Input(UInt(cfg.robIdxWidth.W))
  val addr                   = Input(UInt(CsrAddr.width.W))
  val hasOlderSameAddrWriter = Output(Bool())
}

class CsrFileIO(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val read        = Flipped(new CsrReadPort(cfg))
  val commit      = Input(Vec(cfg.commitWidth, Valid(new CsrCommit(cfg))))
  val trap        = Input(new CsrTrapCommit(cfg))
  val mret        = Input(new CsrMretCommit(cfg))
  val sret        = Input(new CsrSretCommit(cfg))
  val interrupt   = Input(new CsrInterruptPending)
  val mtime       = Input(UInt(64.W))
  val retireCount = Input(UInt(log2Ceil(cfg.commitWidth + 1).W))
  val status      = Output(new CsrStatus(cfg))
}
