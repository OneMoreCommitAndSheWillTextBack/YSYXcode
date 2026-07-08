package top.core.frontend.ifetch

import chisel3._
import chisel3.util._

// Source: adapted from Rocket Chip RVC.scala:
// /home/cinder/Code/project/ysyx-workbench/ysyxSoC/rocket-chip/src/main/scala/rocket/RVC.scala
// Original package: freechips.rocketchip.rocket
// This local version removes Rocket Chip parameter/tile dependencies and keeps the RV32C expander used by IFetch.
// Agent: Codex (GPT-5). User-requested marker: "agent create by gpt-5.5".

class ExpandedInstruction extends Bundle {
  val bits = UInt(32.W)
  val rd   = UInt(5.W)
  val rs1  = UInt(5.W)
  val rs2  = UInt(5.W)
  val rs3  = UInt(5.W)
}

class RVCDecoder(x: UInt, xLen: Int = 32, fLen: Int = 0, useAddiForMv: Boolean = false) {
  private def inst(
    bits: UInt,
    rd:   UInt = x(11, 7),
    rs1:  UInt = x(19, 15),
    rs2:  UInt = x(24, 20),
    rs3:  UInt = x(31, 27)
  ) = {
    val res = Wire(new ExpandedInstruction)
    res.bits := bits
    res.rd   := rd
    res.rs1  := rs1
    res.rs2  := rs2
    res.rs3  := rs3
    res
  }

  private def rs1p        = Cat(1.U(2.W), x(9, 7))
  private def rs2p        = Cat(1.U(2.W), x(4, 2))
  private def rs2         = x(6, 2)
  private def rd          = x(11, 7)
  private def addi4spnImm = Cat(x(10, 7), x(12, 11), x(5), x(6), 0.U(2.W))
  private def lwImm       = Cat(x(5), x(12, 10), x(6), 0.U(2.W))
  private def ldImm       = Cat(x(6, 5), x(12, 10), 0.U(3.W))
  private def lwspImm     = Cat(x(3, 2), x(12), x(6, 4), 0.U(2.W))
  private def ldspImm     = Cat(x(4, 2), x(12), x(6, 5), 0.U(3.W))
  private def swspImm     = Cat(x(8, 7), x(12, 9), 0.U(2.W))
  private def sdspImm     = Cat(x(9, 7), x(12, 10), 0.U(3.W))
  private def luiImm      = Cat(Fill(15, x(12)), x(6, 2), 0.U(12.W))
  private def addi16spImm = Cat(Fill(3, x(12)), x(4, 3), x(5), x(2), x(6), 0.U(4.W))
  private def addiImm     = Cat(Fill(7, x(12)), x(6, 2))
  private def jImm        = Cat(Fill(10, x(12)), x(8), x(10, 9), x(6), x(7), x(2), x(11), x(5, 3), 0.U(1.W))
  private def bImm        = Cat(Fill(5, x(12)), x(6, 5), x(2), x(11, 10), x(4, 3), 0.U(1.W))
  private def shamt       = Cat(x(12), x(6, 2))
  private def x0          = 0.U(5.W)
  private def ra          = 1.U(5.W)
  private def sp          = 2.U(5.W)

  private def q0 = {
    def addi4spn = {
      val opc = Mux(x(12, 5).orR, 0x13.U(7.W), 0x1f.U(7.W))
      inst(Cat(addi4spnImm, sp, 0.U(3.W), rs2p, opc), rs2p, sp, rs2p)
    }
    def ld       = inst(Cat(ldImm, rs1p, 3.U(3.W), rs2p, 0x03.U(7.W)), rs2p, rs1p, rs2p)
    def lw       = inst(Cat(lwImm, rs1p, 2.U(3.W), rs2p, 0x03.U(7.W)), rs2p, rs1p, rs2p)
    def fld      = inst(Cat(ldImm, rs1p, 3.U(3.W), rs2p, 0x07.U(7.W)), rs2p, rs1p, rs2p)
    def flw      = if (xLen == 32) inst(Cat(lwImm, rs1p, 2.U(3.W), rs2p, 0x07.U(7.W)), rs2p, rs1p, rs2p) else ld
    def unimp    = inst(Cat(lwImm >> 5, rs2p, rs1p, 2.U(3.W), lwImm(4, 0), 0x3f.U(7.W)), rs2p, rs1p, rs2p)
    def sd       = inst(Cat(ldImm >> 5, rs2p, rs1p, 3.U(3.W), ldImm(4, 0), 0x23.U(7.W)), rs2p, rs1p, rs2p)
    def sw       = inst(Cat(lwImm >> 5, rs2p, rs1p, 2.U(3.W), lwImm(4, 0), 0x23.U(7.W)), rs2p, rs1p, rs2p)
    def fsd      = inst(Cat(ldImm >> 5, rs2p, rs1p, 3.U(3.W), ldImm(4, 0), 0x27.U(7.W)), rs2p, rs1p, rs2p)
    def fsw      =
      if (xLen == 32) inst(Cat(lwImm >> 5, rs2p, rs1p, 2.U(3.W), lwImm(4, 0), 0x27.U(7.W)), rs2p, rs1p, rs2p)
      else sd
    VecInit(Seq(addi4spn, fld, lw, flw, unimp, fsd, sw, fsw))
  }

  private def q1 = {
    def addi     = inst(Cat(addiImm, rd, 0.U(3.W), rd, 0x13.U(7.W)), rd, rd, rs2p)
    def addiw    = {
      val opc = Mux(rd.orR, 0x1b.U(7.W), 0x1f.U(7.W))
      inst(Cat(addiImm, rd, 0.U(3.W), rd, opc), rd, rd, rs2p)
    }
    def jal      = {
      if (xLen == 32) inst(Cat(jImm(20), jImm(10, 1), jImm(11), jImm(19, 12), ra, 0x6f.U(7.W)), ra, rd, rs2p)
      else addiw
    }
    def li       = inst(Cat(addiImm, x0, 0.U(3.W), rd, 0x13.U(7.W)), rd, x0, rs2p)
    def addi16sp = inst(Cat(addi16spImm, rd, 0.U(3.W), rd, Mux(addiImm.orR, 0x13.U(7.W), 0x1f.U(7.W))), rd, rd, rs2p)
    def lui      = {
      val expanded = inst(Cat(luiImm(31, 12), rd, Mux(addiImm.orR, 0x37.U(7.W), 0x3f.U(7.W))), rd, rd, rs2p)
      Mux(rd === x0 || rd === sp, addi16sp, expanded)
    }
    def j        = inst(Cat(jImm(20), jImm(10, 1), jImm(11), jImm(19, 12), x0, 0x6f.U(7.W)), x0, rs1p, rs2p)
    def beqz     = inst(Cat(bImm(12), bImm(10, 5), x0, rs1p, 0.U(3.W), bImm(4, 1), bImm(11), 0x63.U(7.W)), rs1p, rs1p, x0)
    def bnez     = inst(Cat(bImm(12), bImm(10, 5), x0, rs1p, 1.U(3.W), bImm(4, 1), bImm(11), 0x63.U(7.W)), x0, rs1p, x0)
    def arith    = {
      def srli  = Cat(shamt, rs1p, 5.U(3.W), rs1p, 0x13.U(7.W))
      def srai  = srli | (1 << 30).U
      def andi  = Cat(addiImm, rs1p, 7.U(3.W), rs1p, 0x13.U(7.W))
      def rtype = {
        val funct = VecInit(Seq(0.U, 4.U, 6.U, 7.U, 0.U, 0.U, 2.U, 3.U))(Cat(x(12), x(6, 5)))
        val sub   = Mux(x(6, 5) === 0.U, (1 << 30).U, 0.U)
        val opc   = Mux(x(12), 0x3b.U(7.W), 0x33.U(7.W))
        Cat(rs2p, rs1p, funct, rs1p, opc) | sub
      }
      inst(VecInit(Seq(srli, srai, andi, rtype))(x(11, 10)), rs1p, rs1p, rs2p)
    }
    VecInit(Seq(addi, jal, li, lui, arith, j, beqz, bnez))
  }

  private def q2 = {
    val loadOpc = Mux(rd.orR, 0x03.U(7.W), 0x1f.U(7.W))
    def slli    = inst(Cat(shamt, rd, 1.U(3.W), rd, 0x13.U(7.W)), rd, rd, rs2)
    def ldsp    = inst(Cat(ldspImm, sp, 3.U(3.W), rd, loadOpc), rd, sp, rs2)
    def lwsp    = inst(Cat(lwspImm, sp, 2.U(3.W), rd, loadOpc), rd, sp, rs2)
    def fldsp   = inst(Cat(ldspImm, sp, 3.U(3.W), rd, 0x07.U(7.W)), rd, sp, rs2)
    def flwsp   = if (xLen == 32) inst(Cat(lwspImm, sp, 2.U(3.W), rd, 0x07.U(7.W)), rd, sp, rs2) else ldsp
    def sdsp    = inst(Cat(sdspImm >> 5, rs2, sp, 3.U(3.W), sdspImm(4, 0), 0x23.U(7.W)), rd, sp, rs2)
    def swsp    = inst(Cat(swspImm >> 5, rs2, sp, 2.U(3.W), swspImm(4, 0), 0x23.U(7.W)), rd, sp, rs2)
    def fsdsp   = inst(Cat(sdspImm >> 5, rs2, sp, 3.U(3.W), sdspImm(4, 0), 0x27.U(7.W)), rd, sp, rs2)
    def fswsp   =
      if (xLen == 32) inst(Cat(swspImm >> 5, rs2, sp, 2.U(3.W), swspImm(4, 0), 0x27.U(7.W)), rd, sp, rs2)
      else sdsp
    def jalr    = {
      val mv        =
        if (useAddiForMv) inst(Cat(rs2, 0.U(3.W), rd, 0x13.U(7.W)), rd, rs2, x0)
        else inst(Cat(rs2, x0, 0.U(3.W), rd, 0x33.U(7.W)), rd, x0, rs2)
      val add       = inst(Cat(rs2, rd, 0.U(3.W), rd, 0x33.U(7.W)), rd, rd, rs2)
      val jr        = Cat(rs2, rd, 0.U(3.W), x0, 0x67.U(7.W))
      val reserved  = Cat(jr >> 7, 0x1f.U(7.W))
      val jrOrRes   = inst(Mux(rd.orR, jr, reserved), x0, rd, rs2)
      val jrOrMv    = Mux(rs2.orR, mv, jrOrRes)
      val jalrInst  = Cat(rs2, rd, 0.U(3.W), ra, 0x67.U(7.W))
      val ebreak    = Cat(jr >> 7, 0x73.U(7.W)) | (1 << 20).U
      val jalrOrEbr = inst(Mux(rd.orR, jalrInst, ebreak), ra, rd, rs2)
      Mux(x(12), Mux(rs2.orR, add, jalrOrEbr), jrOrMv)
    }
    VecInit(Seq(slli, fldsp, lwsp, flwsp, jalr, fsdsp, swsp, fswsp))
  }

  private def passthrough = inst(x)

  def decode = {
    val quadrants = VecInit(q0, q1, q2, VecInit(Seq.fill(8)(passthrough)))
    quadrants(x(1, 0))(x(15, 13))
  }

  private def q0Ill = {
    def addi4spn = !x(12, 2).orR
    def fld      = if (fLen >= 64) false.B else true.B
    def flw      = if (xLen == 64 || fLen >= 32) false.B else true.B
    def fsd      = if (fLen >= 64) false.B else true.B
    def fsw      = if (xLen == 64 || fLen >= 32) false.B else true.B
    VecInit(Seq(addi4spn, fld, false.B, flw, true.B, fsd, false.B, fsw))
  }

  private def q1Ill = {
    def jalOrAddiw = if (xLen == 32) false.B else rd === 0.U
    def lui        = !addiImm.orR
    def arith      = x(12, 10).andR && (if (xLen == 32) true.B else x(6) === 1.U)
    VecInit(Seq(false.B, jalOrAddiw, false.B, lui, arith, false.B, false.B, false.B))
  }

  private def q2Ill = {
    def fldsp = if (fLen >= 64) false.B else true.B
    def lwsp  = rd === 0.U
    def flwsp = if (xLen == 64) rd === 0.U else if (fLen >= 32) false.B else true.B
    def jalr  = !x(12, 2).orR
    def fsdsp = if (fLen >= 64) false.B else true.B
    def fswsp = if (xLen == 64) false.B else if (fLen >= 32) false.B else true.B
    VecInit(Seq(false.B, fldsp, lwsp, flwsp, jalr, fsdsp, false.B, fswsp))
  }

  def ill = {
    val quadrants = VecInit(q0Ill, q1Ill, q2Ill, VecInit(Seq.fill(8)(false.B)))
    quadrants(x(1, 0))(x(15, 13))
  }
}

class RvcExpander(
  xLen:         Int = 32,
  fLen:         Int = 0,
  useAddiForMv: Boolean = false)
    extends Module {
  val io = IO(new Bundle {
    val in  = Input(UInt(32.W))
    val out = Output(new ExpandedInstruction)
    val rvc = Output(Bool())
    val ill = Output(Bool())
  })

  val decoder = new RVCDecoder(io.in, xLen, fLen, useAddiForMv)

  io.rvc := io.in(1, 0) =/= 3.U
  io.out := decoder.decode
  io.ill := decoder.ill
}
