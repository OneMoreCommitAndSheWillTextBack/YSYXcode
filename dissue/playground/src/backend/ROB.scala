package top.backend.rob

import chisel3._
import chisel3.util.{log2Ceil, Decoupled, PopCount, Valid}
import top.backend.bundle.{RobAllocPacket, RobCommitPacket, RobWritebackPacket}
import top.backend.csr.CsrAddr
import top.bundle.FetchInstPayload
import top.config.BackendConfig
import top.bundle.CfiType

private class RobEntry(cfg: BackendConfig) extends Bundle {
  val valid          = Bool()
  val done           = Bool()
  val fetch          = new FetchInstPayload(cfg.addrWidth)
  val rd             = UInt(5.W)
  val rfWen          = Bool()
  val isLoad         = Bool()
  val isStore        = Bool()
  val cfi            = UInt(CfiType.width.W)
  val memSize        = UInt(3.W)
  val memUnsigned    = Bool()
  val isEbreak       = Bool()
  val isEcall        = Bool()
  val isMret         = Bool()
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
    io.commit(i).bits.cfi            := entry.cfi
    io.commit(i).bits.memSize        := entry.memSize
    io.commit(i).bits.memUnsigned    := entry.memUnsigned
    io.commit(i).bits.isEbreak       := entry.isEbreak
    io.commit(i).bits.isEcall        := entry.isEcall
    io.commit(i).bits.isMret         := entry.isMret
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
  }

  io.head  := head
  io.tail  := tail
  io.full  := count === cfg.robEntries.U
  io.empty := count === 0.U

  private val allocCount  = PopCount(allocFire)
  private val commitCount = PopCount(commitFire)

  when(io.flush) {
    for (entry <- entries) {
      entry.valid := false.B
      entry.done  := false.B
    }
    head := 0.U
    tail  := 0.U
    count := 0.U
  }.otherwise {
    for (wb <- io.writeback) {
      when(wb.valid) {
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
      }
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
        entries(allocIdx).done           := false.B
        entries(allocIdx).fetch          := decode.fetch
        entries(allocIdx).rd             := decode.rd
        entries(allocIdx).rfWen          := decode.rfWen
        entries(allocIdx).isLoad         := decode.isLoad
        entries(allocIdx).isStore        := decode.isStore
        entries(allocIdx).cfi            := decode.cfi
        entries(allocIdx).memSize        := decode.memSize
        entries(allocIdx).memUnsigned    := decode.memUnsigned
        entries(allocIdx).isEbreak       := decode.isEbreak
        entries(allocIdx).isEcall        := decode.isEcall
        entries(allocIdx).isMret         := decode.isMret
        entries(allocIdx).isCsr          := decode.isCsr
        entries(allocIdx).csrAddr        := decode.csrAddr
        entries(allocIdx).csrWen         := decode.csrWen
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
}
