package top.backend.exu

import chisel3._
import top.backend.decoder.FuType

sealed trait ExuFuKind {
  def name:   String
  def fuType: UInt
}

object ExuFuKind {
  case object Alu extends ExuFuKind {
    val name:   String = "alu"
    val fuType: UInt   = FuType.alu
  }

  case object Bru extends ExuFuKind {
    val name:   String = "bru"
    val fuType: UInt   = FuType.bru
  }

  case object Jmp extends ExuFuKind {
    val name:   String = "jmp"
    val fuType: UInt   = FuType.jmp
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

  val aluOnly: IntExeUnitConfig = IntExeUnitConfig(
    name = "int_alu",
    pipes = Seq(
      FuPipeConfig(Alu, latency = 0, pipelined = false, writesRf = true, redirects = false)
    )
  )

  val aluBju: IntExeUnitConfig = IntExeUnitConfig(
    name = "int_bju",
    pipes = Seq(
      FuPipeConfig(Alu, latency = 0, pipelined = false, writesRf = true, redirects = false),
      FuPipeConfig(Bru, latency = 0, pipelined = false, writesRf = false, redirects = true),
      FuPipeConfig(Jmp, latency = 0, pipelined = false, writesRf = true, redirects = true)
    )
  )

  def defaultIssuePort(port: Int, width: Int): IntExeUnitConfig = {
    require(width > 0, "integer issue width must be positive")

    if (port == width - 1) aluBju else aluOnly
  }
}
