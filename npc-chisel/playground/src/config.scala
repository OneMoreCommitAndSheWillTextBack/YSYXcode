package top.config

import chisel3.util.log2Ceil

final case class ICacheConfig(
  addrWidth:  Int = 32,
  fetchBytes: Int = 8,
  sets:       Int = 64,
  ways:       Int = 1) {
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

final case class BpuConfig(
  addrWidth:   Int = 32,
  fetchBytes:  Int = 8,
  btbEntries: Int = 64,
  bhtEntries: Int = 128,
  btbWays:    Int = 1) {
  private def isPow2(value: Int): Boolean =
    value > 0 && (value & (value - 1)) == 0

  require(isPow2(fetchBytes), "fetchBytes must be a power of two")
  require(fetchBytes >= 2, "fetchBytes must contain at least one halfword")
  require(isPow2(btbEntries), "btbEntries must be a power of two")
  require(isPow2(bhtEntries), "bhtEntries must be a power of two")
  require(btbWays > 0, "btbWays must be positive")
  require(btbWays == 1, "set-associative BTB is not supported yet")

  val offsetBits:    Int = log2Ceil(fetchBytes)
  val cfiOffsetBits: Int = log2Ceil(fetchBytes / 2)
  val btbIndexBits:  Int = log2Ceil(btbEntries)
  val bhtIndexBits:  Int = log2Ceil(bhtEntries)
  val btbTagBits:    Int = addrWidth - offsetBits - btbIndexBits

  require(btbTagBits > 0, "addrWidth must cover BTB tag, index, and block offset")
}

final case class IFetchConfig(
  halfwordEntries:   Int = 16,
  instBufferEntries: Int = 8) {
  private def isPow2(value: Int): Boolean =
    value > 0 && (value & (value - 1)) == 0

  require(isPow2(halfwordEntries), "halfwordEntries must be a power of two")
  require(halfwordEntries > 4, "halfwordEntries must hold more than one fetch block")
  require(isPow2(instBufferEntries), "instBufferEntries must be a power of two")
  require(instBufferEntries > 1, "instBufferEntries must have at least two entries")
}

final case class FrontendConfig(
  addrWidth:         Int = 32,
  fetchBytes:        Int = 8,
  icacheSets:        Int = 64,
  icacheWays:        Int = 1,
  btbEntries:        Int = 64,
  bhtEntries:        Int = 128,
  btbWays:           Int = 1,
  halfwordEntries:   Int = 16,
  instBufferEntries: Int = 8) {
  val icache: ICacheConfig = ICacheConfig(
    addrWidth = addrWidth,
    fetchBytes = fetchBytes,
    sets = icacheSets,
    ways = icacheWays
  )

  val bpu: BpuConfig = BpuConfig(
    addrWidth = addrWidth,
    fetchBytes = fetchBytes,
    btbEntries = btbEntries,
    bhtEntries = bhtEntries,
    btbWays = btbWays
  )

  val ifetch: IFetchConfig = IFetchConfig(
    halfwordEntries = halfwordEntries,
    instBufferEntries = instBufferEntries
  )
}
