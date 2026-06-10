package top.config

import chisel3.util.log2Ceil

final case class ICacheConfig(
  addrWidth:  Int = 32,
  fetchBytes: Int = 8,
  sets:       Int = 64,
  ways: Int = 1) {
  private def isPow2(value: Int): Boolean =
    value > 0 && (value & (value - 1)) == 0

  require(isPow2(fetchBytes), "fetchBytes must be a power of two")
  require(isPow2(sets), "sets must be a power of two")
  require(ways > 0, "ways must be positive")
  require(ways == 1, "not support the group Set-associative")

  val offsetBits: Int = log2Ceil(fetchBytes)
  val indexBits:  Int = log2Ceil(sets)
  val tagBits:    Int = addrWidth - offsetBits - indexBits
  val blockBits:  Int = fetchBytes * 8

  require(tagBits > 0, "addrWidth must cover tag, index, and block offset")

  val setIdxBits: Int = math.max(indexBits, 1)
  val wayIdxBits: Int = math.max(log2Ceil(ways), 1)
}
