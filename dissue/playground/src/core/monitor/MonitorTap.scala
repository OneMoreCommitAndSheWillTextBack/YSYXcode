package top.core.monitor

import chisel3._
import chisel3.util.DecoupledIO

/** Read-only snapshot of a Decoupled boundary.
  *
  * A tap deliberately has no output that can be connected back to the observed channel. Observers count transfers only
  * through `fire`, so a stalled payload is never counted repeatedly.
  */
class MonitorTap[T <: Data](gen: T) extends Bundle {
  val valid = Bool()
  val ready = Bool()
  val bits  = gen.cloneType

  def fire: Bool = valid && ready
}

object MonitorTap {
  def observe[T <: Data](channel: DecoupledIO[T]): MonitorTap[T] = {
    val tap = Wire(new MonitorTap(chiselTypeOf(channel.bits)))
    tap.valid := channel.valid
    tap.ready := channel.ready
    tap.bits  := channel.bits
    tap
  }
}
