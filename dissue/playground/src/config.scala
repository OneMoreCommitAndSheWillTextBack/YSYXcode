package top.config

import chisel3.util.log2Ceil

final case class DCacheConfig(
  addrWidth:   Int = 32,
  dataWidth:   Int = 32,
  lineBytes:   Int = 16,
  sets:        Int = 32,
  ways:        Int = 2,
  mshrEntries: Int = 2,
  waitersPerMshr: Int = 4) {
  private def isPow2(value: Int): Boolean =
    value > 0 && (value & (value - 1)) == 0

  require(addrWidth > 0, "addrWidth must be positive")
  require(dataWidth > 0 && dataWidth % 8 == 0, "dataWidth must be byte-aligned")
  require(isPow2(lineBytes), "lineBytes must be a power of two")
  require(lineBytes >= dataWidth / 8, "lineBytes must cover one data beat")
  require(lineBytes                  % (dataWidth / 8) == 0, "lineBytes must be an integer number of data beats")
  require(isPow2(sets), "sets must be a power of two")
  require(ways > 0, "ways must be positive")
  require(mshrEntries > 0, "mshrEntries must be positive")
  require(waitersPerMshr > 0, "waitersPerMshr must be positive")

  val offsetBits: Int = log2Ceil(lineBytes)
  val indexBits:  Int = log2Ceil(sets)
  val tagBits:    Int = addrWidth - offsetBits - indexBits
  val blockBits:  Int = lineBytes * 8
  val beatCount:  Int = lineBytes / (dataWidth / 8)
  val setIdxBits: Int = math.max(indexBits, 1)
  val wayIdxBits: Int = math.max(log2Ceil(ways), 1)

  require(tagBits > 0, "addrWidth must cover tag, index, and block offset")
}

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

final case class BpuConfig(
  addrWidth:  Int = 32,
  fetchBytes: Int = 8,
  btbEntries: Int = 64,
  bhtEntries: Int = 128,
  btbWays: Int = 1) {
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
  halfwordEntries: Int = 16,
  instBufferEntries: Int = 8) {
  private def isPow2(value: Int): Boolean =
    value > 0 && (value & (value - 1)) == 0

  require(isPow2(halfwordEntries), "halfwordEntries must be a power of two")
  require(halfwordEntries > 4, "halfwordEntries must hold more than one fetch block")
  require(isPow2(instBufferEntries), "instBufferEntries must be a power of two")
  require(instBufferEntries > 1, "instBufferEntries must have at least two entries")
}

final case class FrontendConfig(
  addrWidth:       Int = 32,
  fetchBytes:      Int = 8,
  icacheSets:      Int = 64,
  icacheWays:      Int = 1,
  btbEntries:      Int = 64,
  bhtEntries:      Int = 128,
  btbWays:         Int = 1,
  halfwordEntries: Int = 16,
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

final case class BackendConfig(
  issueWidth:        Int = 2,
  commitWidth:       Int = 2,
  addrWidth:         Int = 32,
  dataWidth:         Int = 32,
  robEntries:        Int = 16,
  intIssueWidth:     Int = 2,
  writebackWidth:    Int = 3,
  issueQueueEntries: Int = 8,
  loadTxnEntries: Int = 2,
  recoveryCancelPorts: Int = 16) {
  require(issueWidth > 0, "issueWidth must be positive")
  require(commitWidth > 0, "commitWidth must be positive")
  require(addrWidth > 0, "addrWidth must be positive")
  require(dataWidth > 0, "dataWidth must be positive")
  require(robEntries > 1, "robEntries must contain more than one entry")
  require(intIssueWidth > 0, "intIssueWidth must be positive")
  require(writebackWidth > 0, "writebackWidth must be positive")
  require(writebackWidth >= intIssueWidth + 1, "writebackWidth must cover all integer execute ports and LSU")
  require(issueQueueEntries > 0, "issueQueueEntries must be positive")
  require(loadTxnEntries > 0, "loadTxnEntries must be positive")
  require(recoveryCancelPorts > 0, "recoveryCancelPorts must be positive")

  val dispatchWidth:      Int = issueWidth
  val operandsPerInst:    Int = 2
  val scoreboardQueries:  Int = dispatchWidth * operandsPerInst
  val regfileReadPorts:   Int = scoreboardQueries
  val regfileWritePorts:  Int = commitWidth
  val robIdxWidth:        Int = math.max(log2Ceil(robEntries), 1)
  val issueQueueIdxWidth: Int = math.max(log2Ceil(issueQueueEntries), 1)
}

final case class MemConfig(
  addrWidth:    Int = 32,
  axiDataWidth: Int = 32,
  fetchBytes:   Int = 8,
  axiIdWidth:   Int = 4,
  dcache: DCacheConfig = DCacheConfig()) {
  private def isPow2(value: Int): Boolean =
    value > 0 && (value & (value - 1)) == 0

  require(addrWidth > 0, "addrWidth must be positive")
  require(axiDataWidth > 0 && axiDataWidth % 8 == 0, "axiDataWidth must be byte-aligned")
  require(isPow2(fetchBytes), "fetchBytes must be a power of two")
  require(fetchBytes * 8 >= axiDataWidth, "fetchBytes must cover at least one AXI beat")
  require((fetchBytes * 8)                 % axiDataWidth == 0, "fetchBytes must be an integer number of AXI beats")
  require(axiIdWidth > 0, "axiIdWidth must be positive")
  require(dcache.addrWidth == addrWidth, "DCache addrWidth must match memory addrWidth")
  require(dcache.dataWidth == axiDataWidth, "DCache dataWidth must match AXI data width")
}
