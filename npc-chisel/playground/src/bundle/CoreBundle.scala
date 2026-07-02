package top.bundle

import chisel3._
import chisel3.util.Valid

object CfiType {
  val width = 3

  val none   = 0.U(width.W)
  val branch = 1.U(width.W)
  val jal    = 2.U(width.W)
  val jalr   = 3.U(width.W)
  val call   = 4.U(width.W)
  val ret    = 5.U(width.W)
}

class Redirect(addrWidth: Int = 32) extends Bundle {
  val valid  = Bool()
  val target = UInt(addrWidth.W)
}

class FetchInstPayload(addrWidth: Int = 32) extends Bundle {
  val pc      = UInt(addrWidth.W)
  val inst    = UInt(32.W)
  val rawInst = UInt(32.W)
  val isRVC   = Bool()
  val instLen = UInt(3.W)

  val predTaken  = Bool()
  val predNpc    = UInt(addrWidth.W)
  val predTarget = UInt(addrWidth.W)
}

class FrontendToBackend(issueWidth: Int = 2, addrWidth: Int = 32) extends Bundle {
  val insts = Vec(issueWidth, Valid(new FetchInstPayload(addrWidth)))
}

class BpuUpdatePayload(addrWidth: Int = 32) extends Bundle {
  val pc      = UInt(addrWidth.W)
  val cfiType = UInt(CfiType.width.W)
  val taken   = Bool()
  val target  = UInt(addrWidth.W)
  val instLen = UInt(3.W)
}

class BackendToFrontend(addrWidth: Int = 32) extends Bundle {
  val trapRedirect   = new Redirect(addrWidth)
  val branchRedirect = new Redirect(addrWidth)
  val predRedirect   = new Redirect(addrWidth)
  val bpuUpdate      = Valid(new BpuUpdatePayload(addrWidth))
}

class InstMemReq(addrWidth: Int = 32) extends Bundle {
  val addr = UInt(addrWidth.W)
}

class InstMemResp(fetchBytes: Int = 8) extends Bundle {
  val data = UInt((fetchBytes * 8).W)
}

class DataMemReq(addrWidth: Int = 32, dataWidth: Int = 32) extends Bundle {
  val addr     = UInt(addrWidth.W)
  val write    = Bool()
  val size     = UInt(3.W)
  val unsigned = Bool()
  val wdata    = UInt(dataWidth.W)
  val wmask    = UInt((dataWidth / 8).W)
}

class DataMemResp(dataWidth: Int = 32) extends Bundle {
  val data  = UInt(dataWidth.W)
  val fault = Bool()
}
