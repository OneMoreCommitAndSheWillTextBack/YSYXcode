package top.core.backend.csr

import chisel3._

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

  def of(name: String): Int =
    CsrSpec.addrOf(name)

  def apply(addr: Int): UInt =
    addr.U(width.W)

  def apply(name: String): UInt =
    apply(of(name))

  def sameHazardDomain(lhs: UInt, rhs: UInt): Bool = {
    def pair(a: String, b: String): Bool =
      (lhs === CsrAddr(a) && rhs === CsrAddr(b)) || (lhs === CsrAddr(b) && rhs === CsrAddr(a))

    lhs === rhs ||
    pair("sstatus", "mstatus") ||
    pair("sie", "mie") ||
    pair("sip", "mip")
  }
}

object CsrOp {
  val width = 5

  val none = 0.U(width.W)
  val rw   = 1.U(width.W)
  val rs   = 2.U(width.W)
  val rc   = 3.U(width.W)
}

object Mstatus {
  private def bit(pos: Int): BigInt =
    BigInt(1) << pos

  private def mask(msb: Int, lsb: Int): BigInt =
    ((BigInt(1) << (msb - lsb + 1)) - 1) << lsb

  val sieBit  = 1
  val mieBit  = 3
  val spieBit = 5
  val mpieBit = 7
  val sppBit  = 8
  val mppMsb  = 12
  val mppLsb  = 11
  val fsMsb   = 14
  val fsLsb   = 13
  val xsMsb   = 16
  val xsLsb   = 15
  val mprvBit = 17
  val sumBit  = 18
  val mxrBit  = 19
  val tvmBit  = 20
  val twBit   = 21
  val tsrBit  = 22

  val trapWriteMask: BigInt =
    bit(mieBit) | bit(mpieBit) | mask(mppMsb, mppLsb)

  val supervisorTrapWriteMask: BigInt =
    bit(sieBit) | bit(spieBit) | bit(sppBit)

  val mprvMask: BigInt =
    bit(mprvBit)

  val supervisorVisibleMask: BigInt =
    bit(sieBit) | bit(spieBit) | bit(sppBit) |
      mask(fsMsb, fsLsb) | mask(xsMsb, xsLsb) |
      bit(sumBit) | bit(mxrBit)

  val supervisorVisibleWriteMask: BigInt =
    bit(sieBit) | bit(spieBit) | bit(sppBit) |
      mask(fsMsb, fsLsb) | bit(sumBit) | bit(mxrBit)

  val writeMask: BigInt =
    bit(sieBit) | bit(mieBit) | bit(spieBit) | bit(mpieBit) |
      bit(sppBit) | mask(mppMsb, mppLsb) | mask(fsMsb, fsLsb) |
      bit(mprvBit) | bit(sumBit) | bit(mxrBit) |
      bit(tvmBit) | bit(twBit) | bit(tsrBit)
}

object CsrInterrupt {
  private def bit(pos: Int): BigInt =
    BigInt(1) << pos

  val ssipBit = 1
  val msipBit = 3
  val stipBit = 5
  val mtipBit = 7
  val seipBit = 9
  val meipBit = 11

  val sieMask: BigInt =
    bit(ssipBit) | bit(stipBit) | bit(seipBit)

  val writableMipMask: BigInt =
    bit(msipBit) | bit(mtipBit) | bit(ssipBit) | bit(stipBit)

  val writableSipMask: BigInt =
    bit(ssipBit)

  val writableMidelegMask: BigInt =
    bit(ssipBit) | bit(stipBit) | bit(seipBit)
}

object CsrDelegation {
  private def bit(pos: Int): BigInt =
    BigInt(1) << pos

  val writableMedelegMask: BigInt =
    bit(0) | bit(1) | bit(2) | bit(3) |
      bit(4) | bit(5) | bit(6) | bit(7) |
      bit(8) | bit(9) |
      bit(12) | bit(13) | bit(15)
}

object CsrCounter {
  val counterenMask:    BigInt = 0x7
  val countInhibitMask: BigInt = 0x5
}

object Sstatus {
  val visibleMask: BigInt =
    Mstatus.supervisorVisibleMask

  val writeMask: BigInt =
    Mstatus.supervisorVisibleWriteMask
}

object CsrId {
  val mvendorid: BigInt = BigInt("79737978", 16)
  val marchid:   BigInt = BigInt("016fbca7", 16)
  val mimpid:    BigInt = 0
  val mhartid:   BigInt = 0
}

object Misa {
  private def ext(ch: Char): BigInt =
    BigInt(1) << (ch - 'A')

  val rv32ImacSu: BigInt =
    (BigInt(1) << 30) | ext('I') | ext('M') | ext('A') | ext('C') | ext('S') | ext('U')
}
