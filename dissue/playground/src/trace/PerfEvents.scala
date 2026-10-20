package top.trace

import chisel3._

object MemPerfEvent {
  val dcacheAccess                = 0
  val dcacheHit                   = 1
  val dcacheMiss                  = 2
  val dcacheBypass                = 3
  val mshrAlloc                   = 4
  val mshrMerge                   = 5
  val mshrFullStallCycle          = 6
  val hitUnderMiss                = 7
  val queuedMiss                  = 8
  val refillStart                 = 9
  val refillComplete              = 10
  val refillFault                 = 11
  val loadTxnFullStallCycle       = 12
  val sqAlloc                     = 13
  val sqFullStallCycle            = 14
  val forwardFull                 = 15
  val forwardPartial              = 16
  val forwardUnresolvedStallCycle = 17
  val storeDrain                  = 18
  val storeCommit                 = 19
  val storeResponse               = 20
  val width                       = 21

  def bit(index: Int, enabled: Bool): UInt =
    Mux(enabled, (1.U(width.W) << index)(width - 1, 0), 0.U(width.W))
}

object FrontendPerfEvent {
  val icacheRequest                   = 0
  val icacheHit                       = 1
  val icacheMiss                      = 2
  val icacheMissWaitCycle             = 3
  val backendRedirect                 = 4
  val icacheInvalidate                = 5
  val frontendEmpty                   = 6
  val axiRequestWait                  = 7
  val fetchQueueEmptyWithBackendReady = 8
  val fetchQueueFull                  = 9
  val icacheMshrActiveCycle           = 10
  val icacheHitUnderMiss              = 11
  val icacheSameLineWaitCycle         = 12
  val icacheQueuedMiss                = 13
  val redirectDuringMshr              = 14
  val redirectDuringMshrTargetHit     = 15
  val staleResponseDrop               = 16
  val rasPush                         = 17
  val rasPop                          = 18
  val rasPopThenPush                  = 19
  val rasUse                          = 20
  val rasHit                          = 21
  val rasMiss                         = 22
  val rasUnderflow                    = 23
  val rasOverflow                     = 24
  val rasCheckpointRestore            = 25
  val rasRecoveryDiscard              = 26
  val tageTaggedProvider              = 27
  val tageAlternateDisagree           = 28
  val tageAllocation                  = 29
  val tageUsefulnessAging             = 30
  val lateOverride                    = 31
  val width                           = 32

  def bit(index: Int, enabled: Bool): UInt =
    Mux(enabled, (1.U(width.W) << index)(width - 1, 0), 0.U(width.W))
}

/** Handshake-level frontend pressure events. Events are sampled independently and may overlap when pressure propagates
  * through multiple buffered stages in the same cycle.
  */
object FrontendStallEvent {
  val backendBackpressure                     = 0
  val backendBackpressureFetchQueueFull       = 1
  val fetchQueueEnqueueBackpressure           = 2
  val fetchQueueFullBackpressure              = 3
  val fetchQueuePartialBackpressure           = 4
  val alignerOutputBackpressure               = 5
  val blockBufferOutputBackpressure           = 6
  val icacheResponseBackpressure              = 7
  val icacheRequestBackpressure               = 8
  val icacheRequestMissBackpressure           = 9
  val icacheRequestNonMissBackpressure        = 10
  val ftqReserveBackpressure                  = 11
  val recoveryHold                            = 12
  val fetchQueueStarvedWithIncomingEnqueue    = 13
  val fetchQueueStarvedWithoutIncomingEnqueue = 14
  val fetchQueueStarvedByIcacheMiss           = 15
  val fetchQueueStarvedByRecoveryRefill       = 16
  val fetchQueueStarvedByFtqReserve           = 17
  val fetchQueueStarvedByPipelineBubble       = 18
  val recoveryHoldBackend                     = 19
  val recoveryHoldIfuCorrection               = 20
  val recoveryHoldBpuOverride                 = 21
  val fetchQueueStarvedAfterBackendRecovery   = 22
  val fetchQueueStarvedAfterIfuCorrection     = 23
  val fetchQueueStarvedAfterBpuOverride       = 24
  val width                                   = 32

  def bit(index: Int, enabled: Bool): UInt =
    Mux(enabled, (1.U(width.W) << index)(width - 1, 0), 0.U(width.W))
}
