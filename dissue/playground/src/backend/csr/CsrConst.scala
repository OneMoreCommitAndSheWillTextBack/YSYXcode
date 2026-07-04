package top.backend.csr

import chisel3._
import chisel3.util.MuxLookup

object PrivMode {
  val width = 2

  val U = 0.U(width.W)
  val S = 1.U(width.W)
  val M = 3.U(width.W)

  def legal(mode: UInt): Bool =
    mode === U || mode === S || mode === M
}

class PrivState extends Bundle {
  val mode = UInt(PrivMode.width.W)

  def isU: Bool = mode === PrivMode.U
  def isS: Bool = mode === PrivMode.S
  def isM: Bool = mode === PrivMode.M
}

object CsrAddr {
  val width = 12

  val mstatus = 0x300
  val mtvec   = 0x305
  val mepc    = 0x341
  val mcause  = 0x342
  val mtval   = 0x343

  def apply(addr: Int): UInt =
    addr.U(width.W)
}

object CsrOp {
  val width = 4

  val none = 0.U(width.W)
  val rw   = 1.U(width.W)
  val rs   = 2.U(width.W)
}

object Mstatus {
  private def bit(pos: Int): BigInt =
    BigInt(1) << pos

  private def mask(msb: Int, lsb: Int): BigInt =
    ((BigInt(1) << (msb - lsb + 1)) - 1) << lsb

  val mieBit  = 3
  val mpieBit = 7
  val mppMsb  = 12
  val mppLsb  = 11

  val firstWriteMask: BigInt =
    bit(mieBit) | bit(mpieBit) | mask(mppMsb, mppLsb)
}

object ExceptionCause {
  val ecallFromU = 8
  val ecallFromS = 9
  val ecallFromM = 11

  def ecallFrom(mode: UInt): UInt =
    MuxLookup(mode, ecallFromM.U(4.W))(
      Seq(
        PrivMode.U -> ecallFromU.U(4.W),
        PrivMode.S -> ecallFromS.U(4.W),
        PrivMode.M -> ecallFromM.U(4.W)
      )
    )
}
