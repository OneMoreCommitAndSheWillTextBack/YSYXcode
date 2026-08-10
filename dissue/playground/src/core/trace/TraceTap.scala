package top.core.trace

import chisel3._
import chisel3.util.DecoupledIO

/** Read-only snapshot of a Decoupled boundary.
  *
  * A tap deliberately has no output that can be connected back to the observed channel. Observers count transfers only
  * through `fire`, so a stalled payload is never counted repeatedly.
  */
class DecoupledTraceTap[T <: Data](gen: T) extends Bundle {
  val valid = Bool()
  val ready = Bool()
  val bits  = gen.cloneType

  def fire: Bool = valid && ready
}

object TraceTap {
  def observe[T <: Data](channel: DecoupledIO[T]): DecoupledTraceTap[T] = {
    val tap = Wire(new DecoupledTraceTap(chiselTypeOf(channel.bits)))
    tap.valid := channel.valid
    tap.ready := channel.ready
    tap.bits  := channel.bits
    tap
  }
}
