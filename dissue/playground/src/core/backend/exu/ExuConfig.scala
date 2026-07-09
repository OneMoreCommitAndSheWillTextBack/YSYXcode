package top.core.backend.exu

import chisel3._
import top.core.backend.decoder.FuType

sealed trait ExuFuKind {
  def name:   String
  def fuType: UInt
}

object ExuFuKind {
  case object Alu extends ExuFuKind {
    val name:   String = "alu"
    val fuType: UInt   = FuType.alu
  }

  case object Mul extends ExuFuKind {
    val name:   String = "mul"
    val fuType: UInt   = FuType.mul
  }

  case object Div extends ExuFuKind {
    val name:   String = "div"
    val fuType: UInt   = FuType.div
  }

  case object Bru extends ExuFuKind {
    val name:   String = "bru"
    val fuType: UInt   = FuType.bru
  }

  case object Jmp extends ExuFuKind {
    val name:   String = "jmp"
    val fuType: UInt   = FuType.jmp
  }

  case object Csr extends ExuFuKind {
    val name:   String = "csr"
    val fuType: UInt   = FuType.csr
  }
}

final case class FuPipeConfig(
  kind:      ExuFuKind,
  latency:   Int,
  pipelined: Boolean,
  writesRf:  Boolean,
  redirects: Boolean) {
  require(latency >= 0, s"${kind.name} latency must be non-negative")
}

final case class IntExeUnitConfig(name: String, pipes: Seq[FuPipeConfig]) {
  require(pipes.nonEmpty, s"$name must contain at least one FU pipe")
  require(pipes.map(_.kind).distinct.size == pipes.size, s"$name contains duplicated FU kinds")

  def supports(kind: ExuFuKind): Boolean =
    pipes.exists(_.kind == kind)
}

object IntExeUnitConfig {
  import ExuFuKind._

  // latency = 0 keeps the old Execute timing: issue and writeback happen in the same cycle.
  val aluOnly: IntExeUnitConfig = IntExeUnitConfig(
    name = "int_alu",
    pipes = Seq(
      FuPipeConfig(Alu, latency = 0, pipelined = false, writesRf = true, redirects = false)
    )
  )

  val aluMulDiv: IntExeUnitConfig = IntExeUnitConfig(
    name = "int_alu_mul_div",
    pipes = Seq(
      FuPipeConfig(Alu, latency = 0, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Mul, latency = 2, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Div, latency = 33, pipelined = false, writesRf = true, redirects = false)
    )
  )

  val aluBjuCsr: IntExeUnitConfig = IntExeUnitConfig(
    name = "int_bju_csr",
    pipes = Seq(
      FuPipeConfig(Alu, latency = 0, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Bru, latency = 0, pipelined = false, writesRf = false, redirects = true),
      FuPipeConfig(Jmp, latency = 0, pipelined = false, writesRf = true, redirects = true),
      FuPipeConfig(Csr, latency = 0, pipelined = false, writesRf = true, redirects = false)
    )
  )

  val aluMulDivBjuCsr: IntExeUnitConfig = IntExeUnitConfig(
    name = "int_alu_mul_div_bju_csr",
    pipes = Seq(
      FuPipeConfig(Alu, latency = 0, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Mul, latency = 2, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Div, latency = 33, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Bru, latency = 0, pipelined = false, writesRf = false, redirects = true),
      FuPipeConfig(Jmp, latency = 0, pipelined = false, writesRf = true, redirects = true),
      FuPipeConfig(Csr, latency = 0, pipelined = false, writesRf = true, redirects = false)
    )
  )

  def defaultIssuePort(port: Int, width: Int): IntExeUnitConfig = {
    require(width > 0, "integer issue width must be positive")

    // Narrow ports select first, so an ALU op will not steal the only BRU/JMP-capable port.
    if (width == 1) {
      aluMulDivBjuCsr
    } else if (port == 0) {
      aluMulDiv
    } else if (port == width - 1) {
      aluBjuCsr
    } else {
      aluOnly
    }
  }
}
