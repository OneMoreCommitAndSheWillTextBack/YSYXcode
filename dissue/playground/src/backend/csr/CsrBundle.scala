package top.backend.csr

import chisel3._
import chisel3.util.Valid
import top.config.BackendConfig

class CsrReadPort(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val addr = Output(UInt(CsrAddr.width.W))
  val data = Input(UInt(cfg.dataWidth.W))
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
  val valid = Bool()
  val epc   = UInt(cfg.addrWidth.W)
  val cause = UInt(cfg.dataWidth.W)
  val tval  = UInt(cfg.dataWidth.W)
}

class CsrMretCommit(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val valid = Bool()
}

class CsrStatus(cfg: BackendConfig = BackendConfig()) extends Bundle {
  val priv       = new PrivState
  val trapVector = UInt(cfg.addrWidth.W)
  val mretTarget = UInt(cfg.addrWidth.W)
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
  val read   = Flipped(new CsrReadPort(cfg))
  val commit = Input(Vec(cfg.commitWidth, Valid(new CsrCommit(cfg))))
  val trap   = Input(new CsrTrapCommit(cfg))
  val mret   = Input(new CsrMretCommit(cfg))
  val status = Output(new CsrStatus(cfg))
}
