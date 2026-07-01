package top.backend.lsu

import chisel3._
import chisel3.util.{Decoupled, Enum, MuxLookup, Valid}
import top.backend.bundle.{IssuePacket, IssueWakeup, RobWritebackPacket}
import top.bundle.{DataMemReq, DataMemResp}
import top.config.BackendConfig

class LSU(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new IssuePacket(cfg)))

    val dmemReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val dmemResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))

    val writeback = Valid(new RobWritebackPacket(cfg))
    val wakeup    = Output(new IssueWakeup(cfg))
    val busy      = Output(Bool())
    val flush     = Input(Bool())
  })

  private val sIdle :: sLoadResp :: Nil = Enum(2)
  private val state                     = RegInit(sIdle)

  private val loadRobIdx = Reg(UInt(cfg.robIdxWidth.W))

  private val addr      = io.in.bits.src1.data + io.in.bits.imm
  private val storeMask = MuxLookup(
    io.in.bits.memSize,
    ((1 << (cfg.dataWidth / 8)) - 1).U((cfg.dataWidth / 8).W)
  )(
    Seq(
      0.U -> 1.U((cfg.dataWidth / 8).W),
      1.U -> 3.U((cfg.dataWidth / 8).W),
      2.U -> 15.U((cfg.dataWidth / 8).W)
    )
  )

  val isLoad  = io.in.bits.isLoad
  val isStore = io.in.bits.isStore

  io.busy := state =/= sIdle

  io.dmemReq.valid         := state === sIdle && io.in.valid && isLoad
  io.dmemReq.bits          := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  io.dmemReq.bits.addr     := addr
  io.dmemReq.bits.write    := false.B
  io.dmemReq.bits.size     := io.in.bits.memSize
  io.dmemReq.bits.unsigned := io.in.bits.memUnsigned
  io.dmemReq.bits.wdata    := 0.U
  io.dmemReq.bits.wmask    := 0.U

  io.in.ready := state === sIdle && Mux(isLoad, io.dmemReq.ready, true.B)

  io.dmemResp.ready := state === sLoadResp

  io.writeback.valid          := false.B
  io.writeback.bits           := 0.U.asTypeOf(new RobWritebackPacket(cfg))
  io.writeback.bits.storeMask := storeMask

  io.wakeup := 0.U.asTypeOf(new IssueWakeup(cfg))

  when(io.flush) {
    state := sIdle
  }.otherwise {
    when(state === sIdle) {
      when(io.in.fire && isLoad) {
        loadRobIdx := io.in.bits.robIdx
        state      := sLoadResp
      }.elsewhen(io.in.fire && isStore) {
        io.writeback.valid          := true.B
        io.writeback.bits.robIdx    := io.in.bits.robIdx
        io.writeback.bits.result    := 0.U
        io.writeback.bits.storeAddr := addr
        io.writeback.bits.storeData := io.in.bits.src2.data
        io.writeback.bits.storeMask := storeMask
      }
    }.elsewhen(state === sLoadResp) {
      when(io.dmemResp.fire) {
        io.writeback.valid       := true.B
        io.writeback.bits.robIdx := loadRobIdx
        io.writeback.bits.result := io.dmemResp.bits.data

        io.wakeup.valid  := true.B
        io.wakeup.robIdx := loadRobIdx
        io.wakeup.data   := io.dmemResp.bits.data

        state := sIdle
      }
    }
  }
}
