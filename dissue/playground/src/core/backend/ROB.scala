package top.core.backend.rob

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, PopCount, Valid}
import top.core.backend.bundle.{RobAllocPacket, RobCommitPacket, RobProducerEntry, RobWritebackPacket}
import top.core.backend.csr.CsrAddr
import top.core.backend.exception.ExceptionInfo
import top.core.bundle.{CfiType, FetchInstPayload, RobAge, RobRecovery}
import top.config.BackendConfig

private class RobEntry(cfg: BackendConfig) extends Bundle {
  val valid          = Bool()
  val done           = Bool()
  val fetch          = new FetchInstPayload(cfg.addrWidth)
  val rd             = UInt(5.W)
  val rfWen          = Bool()
  val isLoad         = Bool()
  val isStore        = Bool()
  val isAmo          = Bool()
  val cfi            = UInt(CfiType.width.W)
  val memSize        = UInt(3.W)
  val memUnsigned    = Bool()
  val isEbreak       = Bool()
  val isEcall        = Bool()
  val isMret         = Bool()
  val isSret         = Bool()
  val isFence        = Bool()
  val isFenceI       = Bool()
  val isSfence       = Bool()
  val result         = UInt(cfg.dataWidth.W)
  val storeAddr      = UInt(cfg.addrWidth.W)
  val storeData      = UInt(cfg.dataWidth.W)
  val storeMask      = UInt((cfg.dataWidth / 8).W)
  val redirectValid  = Bool()
  val redirectTarget = UInt(cfg.addrWidth.W)
  val branchTaken    = Bool()
  val branchTarget   = UInt(cfg.addrWidth.W)
  val isCsr          = Bool()
  val csrAddr        = UInt(CsrAddr.width.W)
  val csrWen         = Bool()
  val csrWdata       = UInt(cfg.dataWidth.W)
  val exception      = new ExceptionInfo(cfg)
}

class ROB(cfg: BackendConfig = BackendConfig()) extends Module {
  private val countWidth = math.max(log2Ceil(cfg.robEntries + cfg.dispatchWidth + 1), 1)

  val io = IO(new Bundle {
    val alloc    = Vec(cfg.dispatchWidth, Flipped(Decoupled(new RobAllocPacket(cfg))))
    val allocIdx = Output(Vec(cfg.dispatchWidth, UInt(cfg.robIdxWidth.W)))

    val writeback = Input(Vec(cfg.writebackWidth, Valid(new RobWritebackPacket(cfg))))

    val commit = Vec(cfg.commitWidth, Decoupled(new RobCommitPacket(cfg)))

    val head  = Output(UInt(cfg.robIdxWidth.W))
    val tail  = Output(UInt(cfg.robIdxWidth.W))
    val full  = Output(Bool())
    val empty = Output(Bool())
    val flush = Input(Bool())
    val recover = Input(new RobRecovery(cfg.robIdxWidth))

    val producerEntries = Output(Vec(cfg.robEntries, new RobProducerEntry(cfg)))
    // A memory request may leave the core only after every older CFI has
    // produced its execution result. The memory hierarchy compares this bitmap
    // with the request owner using ROB-ring age ordering.
    val unresolvedCfi = Output(Vec(cfg.robEntries, Bool()))
    // Younger LSU operations must not pass an older AMO. The AMO bypasses the
    // DCache, so a cacheable load could otherwise observe the line before the
    // AMO write has reached memory.
    val unresolvedAmo = Output(Vec(cfg.robEntries, Bool()))
  })

  private val entries = RegInit(VecInit(Seq.fill(cfg.robEntries)(0.U.asTypeOf(new RobEntry(cfg)))))
  private val head    = RegInit(0.U(cfg.robIdxWidth.W))
  private val tail    = RegInit(0.U(cfg.robIdxWidth.W))
  private val count   = RegInit(0.U(countWidth.W))

  private val ptrExtWidth = cfg.robIdxWidth + 1

  private def wrapAdd(ptr: UInt, step: UInt): UInt = {
    val sum = Wire(UInt(ptrExtWidth.W))
    sum := ptr +& step

    Mux(
      sum >= cfg.robEntries.U(ptrExtWidth.W),
      sum - cfg.robEntries.U(ptrExtWidth.W),
      sum
    )(cfg.robIdxWidth - 1, 0)
  }

  private val allocFire  = Wire(Vec(cfg.dispatchWidth, Bool()))
  private val commitFire = Wire(Vec(cfg.commitWidth, Bool()))

  private val freeCount = cfg.robEntries.U(countWidth.W) - count
  for (i <- 0 until cfg.dispatchWidth) {
    val prevValid = if (i == 0) true.B else io.alloc.take(i).map(_.valid).reduce(_ && _)

    io.allocIdx(i)    := wrapAdd(tail, i.U)
    io.alloc(i).ready := freeCount > i.U && prevValid
    allocFire(i)      := io.alloc(i).fire
  }

  for (i <- 0 until cfg.commitWidth) {
    val commitIdx   = wrapAdd(head, i.U)
    val entry       = entries(commitIdx)
    val prevDone    = if (i == 0) {
      true.B
    } else {
      (0 until i).map { j =>
        val prevIdx = wrapAdd(head, j.U)
        entries(prevIdx).valid && entries(prevIdx).done
      }.reduce(_ && _)
    }
    val commitValid = prevDone && entry.valid && entry.done

    io.commit(i).valid := commitValid
    commitFire(i)      := io.commit(i).fire

    io.commit(i).bits.robIdx         := commitIdx
    io.commit(i).bits.fetch          := entry.fetch
    io.commit(i).bits.rd             := entry.rd
    io.commit(i).bits.rfWen          := entry.rfWen
    io.commit(i).bits.isLoad         := entry.isLoad
    io.commit(i).bits.isStore        := entry.isStore
    io.commit(i).bits.isAmo          := entry.isAmo
    io.commit(i).bits.cfi            := entry.cfi
    io.commit(i).bits.memSize        := entry.memSize
    io.commit(i).bits.memUnsigned    := entry.memUnsigned
    io.commit(i).bits.isEbreak       := entry.isEbreak
    io.commit(i).bits.isEcall        := entry.isEcall
    io.commit(i).bits.isMret         := entry.isMret
    io.commit(i).bits.isSret         := entry.isSret
    io.commit(i).bits.isFence        := entry.isFence
    io.commit(i).bits.isFenceI       := entry.isFenceI
    io.commit(i).bits.isSfence       := entry.isSfence
    io.commit(i).bits.result         := entry.result
    io.commit(i).bits.storeAddr      := entry.storeAddr
    io.commit(i).bits.storeData      := entry.storeData
    io.commit(i).bits.storeMask      := entry.storeMask
    io.commit(i).bits.redirectValid  := entry.redirectValid
    io.commit(i).bits.redirectTarget := entry.redirectTarget
    io.commit(i).bits.branchTaken    := entry.branchTaken
    io.commit(i).bits.branchTarget   := entry.branchTarget
    io.commit(i).bits.isCsr          := entry.isCsr
    io.commit(i).bits.csrAddr        := entry.csrAddr
    io.commit(i).bits.csrWen         := entry.csrWen
    io.commit(i).bits.csrWdata       := entry.csrWdata
    io.commit(i).bits.exception      := entry.exception
  }

  io.head  := head
  io.tail  := tail
  io.full  := count === cfg.robEntries.U
  io.empty := count === 0.U

  for (index <- 0 until cfg.robEntries) {
    io.producerEntries(index).valid  := entries(index).valid
    io.producerEntries(index).robIdx := index.U(cfg.robIdxWidth.W)
    io.producerEntries(index).rd     := entries(index).rd
    io.producerEntries(index).rfWen  := entries(index).rfWen
    io.unresolvedCfi(index) := entries(index).valid && entries(index).cfi =/= CfiType.none && !entries(index).done
    io.unresolvedAmo(index) := entries(index).valid && entries(index).isAmo && !entries(index).done
  }

  private val allocCount  = PopCount(allocFire)
  private val commitCount = PopCount(commitFire)

  private def applyWriteback(wb: Valid[RobWritebackPacket], enabled: Bool): Unit = {
    when(wb.valid && enabled) {
      entries(wb.bits.robIdx).done           := true.B
      entries(wb.bits.robIdx).result         := wb.bits.result
      entries(wb.bits.robIdx).storeAddr      := wb.bits.storeAddr
      entries(wb.bits.robIdx).storeData      := wb.bits.storeData
      entries(wb.bits.robIdx).storeMask      := wb.bits.storeMask
      entries(wb.bits.robIdx).redirectValid  := wb.bits.redirectValid
      entries(wb.bits.robIdx).redirectTarget := wb.bits.redirectTarget
      entries(wb.bits.robIdx).branchTaken    := wb.bits.branchTaken
      entries(wb.bits.robIdx).branchTarget   := wb.bits.branchTarget
      entries(wb.bits.robIdx).csrWen         := wb.bits.csrWen
      entries(wb.bits.robIdx).csrWdata       := wb.bits.csrWdata
      entries(wb.bits.robIdx).exception      := ExceptionInfo.keepFirst(
        entries(wb.bits.robIdx).exception,
        wb.bits.exception,
        cfg
      )
    }
  }

  private val recoveryCount = Wire(UInt(countWidth.W))
  recoveryCount := RobAge.fromHead(io.recover.robIdx, head, cfg.robEntries, cfg.robIdxWidth) + 1.U

  when(io.flush) {
    for (entry <- entries) {
      entry.valid := false.B
      entry.done  := false.B
    }
    head := 0.U
    tail  := 0.U
    count := 0.U
  }.elsewhen(io.recover.valid) {
    for (wb <- io.writeback) {
      applyWriteback(
        wb,
        !RobAge.isYounger(wb.bits.robIdx, io.recover.robIdx, head, cfg.robEntries, cfg.robIdxWidth)
      )
    }
    for (index <- 0 until cfg.robEntries) {
      when(RobAge.isYounger(index.U(cfg.robIdxWidth.W), io.recover.robIdx, head, cfg.robEntries, cfg.robIdxWidth)) {
        entries(index).valid := false.B
        entries(index).done  := false.B
      }
    }
    tail  := wrapAdd(io.recover.robIdx, 1.U)
    count := recoveryCount
  }.otherwise {
    for (wb <- io.writeback) {
      applyWriteback(wb, true.B)
    }

    for (i <- 0 until cfg.commitWidth) {
      when(commitFire(i)) {
        val commitIdx = wrapAdd(head, i.U)
        entries(commitIdx).valid := false.B
        entries(commitIdx).done  := false.B
      }
    }

    for (i <- 0 until cfg.dispatchWidth) {
      when(allocFire(i)) {
        val allocIdx = io.allocIdx(i)
        val decode   = io.alloc(i).bits.decode

        entries(allocIdx).valid          := true.B
        entries(allocIdx).done           := !decode.needsIssue
        entries(allocIdx).fetch          := decode.fetch
        entries(allocIdx).rd             := decode.rd
        entries(allocIdx).rfWen          := decode.rfWen
        entries(allocIdx).isLoad         := decode.isLoad
        entries(allocIdx).isStore        := decode.isStore
        entries(allocIdx).isAmo          := decode.isAmo
        entries(allocIdx).cfi            := decode.cfi
        entries(allocIdx).memSize        := decode.memSize
        entries(allocIdx).memUnsigned    := decode.memUnsigned
        entries(allocIdx).isEbreak       := decode.isEbreak
        entries(allocIdx).isEcall        := decode.isEcall
        entries(allocIdx).isMret         := decode.isMret
        entries(allocIdx).isSret         := decode.isSret
        entries(allocIdx).isFence        := decode.isFence
        entries(allocIdx).isFenceI       := decode.isFenceI
        entries(allocIdx).isSfence       := decode.isSfence
        entries(allocIdx).isCsr          := decode.isCsr
        entries(allocIdx).csrAddr        := decode.csrAddr
        entries(allocIdx).csrWen         := decode.csrWen
        entries(allocIdx).exception      := decode.exception
        entries(allocIdx).csrWdata       := 0.U
        entries(allocIdx).result         := 0.U
        entries(allocIdx).storeAddr      := 0.U
        entries(allocIdx).storeData      := 0.U
        entries(allocIdx).storeMask      := 0.U
        entries(allocIdx).redirectValid  := false.B
        entries(allocIdx).redirectTarget := 0.U
        entries(allocIdx).branchTaken    := false.B
        entries(allocIdx).branchTarget   := 0.U
      }
    }

    head  := wrapAdd(head, commitCount)
    tail  := wrapAdd(tail, allocCount)
    count := count + allocCount - commitCount
  }

  when(io.recover.valid) {
    assert(entries(io.recover.robIdx).valid, "recovery must retain a live ROB boundary")
  }
}
