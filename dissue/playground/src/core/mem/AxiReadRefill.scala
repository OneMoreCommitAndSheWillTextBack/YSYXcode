package top.core.mem

import chisel3._
import chisel3.util._
import top.bus.axi.AxiBurst
import top.core.bundle.{InstMemReq, InstMemResp}
import top.config.MemConfig
import top.core.mem.bundle.{AxiMasterReadReq, AxiMasterReadResp}

class AxiReadRefill(cfg: MemConfig = MemConfig()) extends Module {
  private val beatBytes    = cfg.axiDataWidth / 8
  private val beats        = cfg.fetchBytes / beatBytes
  private val beatIdxWidth = math.max(log2Ceil(beats), 1)

  val io = IO(new Bundle {
    val req         = Flipped(Decoupled(new InstMemReq(cfg.addrWidth)))
    val resp        = Decoupled(new InstMemResp(cfg.fetchBytes))
    val axiReadReq  = Decoupled(new AxiMasterReadReq(cfg.addrWidth, cfg.axiIdWidth))
    val axiReadResp = Flipped(Decoupled(new AxiMasterReadResp(cfg.axiDataWidth, cfg.axiIdWidth)))
  })

  val sIdle :: sRead :: sResp :: Nil = Enum(3)
  val state                          = RegInit(sIdle)
  val beatIdx                        = RegInit(0.U(beatIdxWidth.W))
  val dataReg                        = Reg(Vec(beats, UInt(cfg.axiDataWidth.W)))

  val finalBeat      = io.axiReadResp.bits.last || beatIdx === (beats - 1).U
  val bypassResponse = state === sRead && io.axiReadResp.valid && finalBeat
  val completedData  = Wire(Vec(beats, UInt(cfg.axiDataWidth.W)))
  for (beat <- 0 until beats) {
    completedData(beat) := Mux(beatIdx === beat.U, io.axiReadResp.bits.data, dataReg(beat))
  }

  // The final AXI beat can complete the line without first spending a cycle in
  // sResp. If the consumer stalls, the same beat is captured in dataReg below.
  io.resp.valid     := state === sResp || bypassResponse
  io.resp.bits.data := Mux(bypassResponse, completedData.asUInt, dataReg.asUInt)

  val responseTurnover = io.resp.fire
  val requestWindow    = state === sIdle || responseTurnover

  io.req.ready := requestWindow && io.axiReadReq.ready

  io.axiReadReq.valid      := requestWindow && io.req.valid
  io.axiReadReq.bits.addr  := io.req.bits.addr
  io.axiReadReq.bits.id    := 0.U
  io.axiReadReq.bits.len   := (beats - 1).U
  io.axiReadReq.bits.size  := log2Ceil(beatBytes).U
  io.axiReadReq.bits.burst := AxiBurst.incr

  io.axiReadResp.ready := state === sRead

  when(state === sIdle) {
    beatIdx := 0.U
    when(io.req.fire) {
      state := sRead
    }
  }.elsewhen(state === sRead) {
    when(io.axiReadResp.fire) {
      dataReg(beatIdx) := io.axiReadResp.bits.data
      when(finalBeat) {
        when(io.resp.fire) {
          beatIdx := 0.U
          state   := Mux(io.req.fire, sRead, sIdle)
        }.otherwise {
          state := sResp
        }
      }.otherwise {
        beatIdx := beatIdx + 1.U
      }
    }
  }.otherwise {
    when(io.resp.fire) {
      beatIdx := 0.U
      state   := Mux(io.req.fire, sRead, sIdle)
    }
  }
}
