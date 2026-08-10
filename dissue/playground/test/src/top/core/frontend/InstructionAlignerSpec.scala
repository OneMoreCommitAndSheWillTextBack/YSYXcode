package top.core.frontend

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import chisel3.util.PopCount
import top.config.FrontendConfig
import top.core.frontend.ifetch.{FetchWidth, InstructionAligner}

private class InstructionAlignerHarness extends Module {
  val cfg = FrontendConfig(fetchTargetEntries = 4, halfwordEntries = 16)

  val io = IO(new Bundle {
    val flush           = Input(Bool())
    val inValid         = Input(Bool())
    val inReady         = Output(Bool())
    val tokenIndex      = Input(UInt(cfg.ftqIndexBits.W))
    val tokenGeneration = Input(UInt(cfg.ftqGenerationBits.W))
    val tokenEpoch      = Input(UInt(cfg.fetchEpochBits.W))
    val sequence        = Input(UInt(cfg.ftqSequenceBits.W))
    val startPc         = Input(UInt(cfg.addrWidth.W))
    val blockValid      = Input(Vec(cfg.fetchGroupBlocks, Bool()))
    val blockData       = Input(Vec(cfg.fetchGroupBlocks, UInt((cfg.fetchBytes * 8).W)))
    val blockException  = Input(Vec(cfg.fetchGroupBlocks, Bool()))
    val headLive        = Input(Bool())
    val killValid       = Input(Bool())
    val killIndex       = Input(UInt(cfg.ftqIndexBits.W))
    val outReady        = Input(Bool())

    val outValid      = Output(Bool())
    val laneValid     = Output(Vec(FetchWidth.frontend, Bool()))
    val laneToken     = Output(Vec(FetchWidth.frontend, UInt(cfg.ftqIndexBits.W)))
    val lanePc        = Output(Vec(FetchWidth.frontend, UInt(cfg.addrWidth.W)))
    val laneRaw       = Output(Vec(FetchWidth.frontend, UInt(32.W)))
    val laneOrdinal   = Output(Vec(FetchWidth.frontend, UInt(cfg.ftqInstCountBits.W)))
    val laneLast      = Output(Vec(FetchWidth.frontend, Bool()))
    val laneException = Output(Vec(FetchWidth.frontend, Bool()))
    val laneTval      = Output(Vec(FetchWidth.frontend, UInt(cfg.addrWidth.W)))
    val staleDrop     = Output(Bool())
  })

  val aligner = Module(new InstructionAligner(cfg, depth = 16))
  aligner.io.flush                        := io.flush
  aligner.io.in.valid                     := io.inValid
  aligner.io.in.bits                      := 0.U.asTypeOf(aligner.io.in.bits)
  aligner.io.in.bits.token.tag.index      := io.tokenIndex
  aligner.io.in.bits.token.tag.generation := io.tokenGeneration
  aligner.io.in.bits.token.streamEpoch    := io.tokenEpoch
  for (block <- 0 until cfg.fetchGroupBlocks) {
    aligner.io.in.bits.blocks(block).valid                := io.blockValid(block)
    aligner.io.in.bits.blocks(block).bits.data            := io.blockData(block)
    aligner.io.in.bits.blocks(block).bits.hit             := true.B
    aligner.io.in.bits.blocks(block).bits.exception.valid := io.blockException(block)
    aligner.io.in.bits.blocks(block).bits.exception.cause := block.U
    aligner.io.in.bits.blocks(block).bits.exception.tval  := 0.U
  }
  aligner.io.context.valid := io.inValid
  aligner.io.context.bits            := 0.U.asTypeOf(aligner.io.context.bits)
  aligner.io.context.bits.token      := aligner.io.in.bits.token
  aligner.io.context.bits.sequence   := io.sequence
  aligner.io.context.bits.startPc    := io.startPc
  aligner.io.context.bits.blockCount := PopCount(io.blockValid)
  aligner.io.headLive                := io.headLive
  aligner.io.kill.valid              := io.killValid
  aligner.io.kill.bits               := aligner.io.in.bits.token
  aligner.io.kill.bits.tag.index     := io.killIndex
  aligner.io.out.ready               := io.outReady

  io.inReady   := aligner.io.in.ready
  io.outValid  := aligner.io.out.valid
  io.staleDrop := aligner.io.staleDrop
  for (lane <- 0 until FetchWidth.frontend) {
    val inst = aligner.io.out.bits.insts(lane)
    io.laneValid(lane)     := inst.valid
    io.laneToken(lane)     := inst.bits.token.tag.index
    io.lanePc(lane)        := inst.bits.pc
    io.laneRaw(lane)       := inst.bits.rawInst
    io.laneOrdinal(lane)   := inst.bits.instOrdinal
    io.laneLast(lane)      := inst.bits.lastInFtqEntry
    io.laneException(lane) := inst.bits.exception.valid
    io.laneTval(lane)      := inst.bits.exception.tval
  }
}

object InstructionAlignerSpec {
  private def pack(halfwords: Int*): BigInt =
    halfwords.zipWithIndex.foldLeft(BigInt(0)) { case (value, (halfword, index)) =>
      value | (BigInt(halfword & 0xffff) << (index * 16))
    }

  def main(args: Array[String]): Unit = {
    simulate(new InstructionAlignerHarness) { dut =>
      def idle(): Unit = {
        dut.io.inValid.poke(false)
        dut.io.flush.poke(false)
        dut.io.headLive.poke(true)
        dut.io.killValid.poke(false)
        dut.io.killIndex.poke(0)
        dut.io.outReady.poke(false)
        for (block <- dut.io.blockValid.indices) {
          dut.io.blockValid(block).poke(false)
          dut.io.blockData(block).poke(0)
          dut.io.blockException(block).poke(false)
        }
      }

      def send(
        token:       Int,
        sequence:    Int,
        startPc:     BigInt,
        first:       BigInt,
        second:      BigInt,
        secondFault: Boolean = false
      ): Unit = {
        dut.io.inValid.poke(true)
        dut.io.tokenIndex.poke(token)
        dut.io.tokenGeneration.poke(1)
        dut.io.tokenEpoch.poke(0)
        dut.io.sequence.poke(sequence)
        dut.io.startPc.poke(startPc)
        dut.io.blockValid(0).poke(true)
        dut.io.blockValid(1).poke(true)
        dut.io.blockData(0).poke(first)
        dut.io.blockData(1).poke(second)
        dut.io.blockException(0).poke(false)
        dut.io.blockException(1).poke(secondFault)
        dut.io.inReady.expect(true)
        dut.clock.step()
        dut.io.inValid.poke(false)
      }

      idle()
      dut.reset.poke(true)
      dut.clock.step(2)
      dut.reset.poke(false)

      // startPc discards three leading halfwords. The first 32-bit instruction spans blocks and inherits the
      // exception from its high halfword.
      send(
        token = 0,
        sequence = 10,
        startPc = 0x1006,
        first = pack(0x1111, 0x2222, 0x3333, 0x00f3),
        second = pack(0x1234, 0x0001, 0x0001, 0x0001),
        secondFault = true
      )
      dut.io.outValid.expect(true)
      dut.io.laneValid(0).expect(true)
      dut.io.lanePc(0).expect(0x1006)
      dut.io.laneRaw(0).expect(BigInt("123400f3", 16))
      dut.io.laneException(0).expect(true)
      dut.io.laneTval(0).expect(0x1008)

      dut.io.flush.poke(true)
      dut.clock.step()
      dut.io.flush.poke(false)
      dut.io.outReady.poke(true)

      // Seven RVC instructions are emitted while the final 32-bit low halfword waits for the next FTQ group.
      send(
        token = 0,
        sequence = 20,
        startPc = 0x2000,
        first = pack(0x0001, 0x0001, 0x0001, 0x0001),
        second = pack(0x0001, 0x0001, 0x0001, 0x00f3)
      )
      for (lane <- 0 until FetchWidth.frontend) {
        dut.io.laneValid(lane).expect(true)
        dut.io.lanePc(lane).expect(0x2000 + lane * 2)
        dut.io.laneOrdinal(lane).expect(lane)
      }
      dut.clock.step()

      for (lane <- 0 until 3) {
        dut.io.laneValid(lane).expect(true)
        dut.io.lanePc(lane).expect(0x2008 + lane * 2)
        dut.io.laneOrdinal(lane).expect(4 + lane)
      }
      dut.io.laneValid(3).expect(false)
      dut.clock.step()
      dut.io.outValid.expect(false)

      send(
        token = 1,
        sequence = 21,
        startPc = 0x2010,
        first = pack(0x1234, 0x0001, 0x0001, 0x0001),
        second = pack(0x0001, 0x0001, 0x0001, 0x0001)
      )
      dut.io.outValid.expect(true)
      dut.io.laneValid(0).expect(true)
      dut.io.laneToken(0).expect(0)
      dut.io.lanePc(0).expect(0x200e)
      dut.io.laneRaw(0).expect(BigInt("123400f3", 16))
      dut.io.laneOrdinal(0).expect(7)
      dut.io.laneLast(0).expect(true)
      dut.io.laneValid(1).expect(false)
      dut.clock.step()

      // The continuation halfword was consumed by token 0; token 1 starts at the following instruction.
      dut.io.outValid.expect(true)
      dut.io.laneToken(0).expect(1)
      dut.io.lanePc(0).expect(0x2012)
      dut.io.laneOrdinal(0).expect(0)
    }

    println("InstructionAlignerSpec: PASS")
  }
}
