package top.core.mem

import chisel3._
import chisel3.util.{log2Ceil, Cat, Decoupled, Enum, Fill, Valid}
import top.bus.axi.{AxiBurst, AxiResp}
import top.core.bundle.{DataMemReq, DataMemResp, DataMemTxn}
import top.config.MemConfig
import top.core.mem.bundle._

class AxiDataAccess(
  cfg:                 MemConfig = MemConfig(),
  allowDirectIncoming: Boolean = false)
    extends Module {
  private val dataBytes  = cfg.axiDataWidth / 8
  private val offsetBits = math.max(log2Ceil(dataBytes), 1)

  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth)))
    val resp = Decoupled(new DataMemResp(cfg.axiDataWidth))

    /** Permission sampled while this accessor is waiting to launch AXI. */
    val issuePermit = Input(Bool())

    /** Permission for the request currently presented on `req`. */
    val incomingIssuePermit = Input(Bool())

    /** Drops a request that has not yet become externally visible. */
    val abort  = Input(Bool())
    val cancel = Output(Valid(UInt(DataMemTxn.width.W)))

    val axiReadReq   = Decoupled(new AxiMasterReadReq(cfg.addrWidth, cfg.axiIdWidth))
    val axiReadResp  = Flipped(Decoupled(new AxiMasterReadResp(cfg.axiDataWidth, cfg.axiIdWidth)))
    val axiWriteReq  = Decoupled(new AxiMasterWriteReq(cfg.addrWidth, cfg.axiDataWidth, cfg.axiIdWidth))
    val axiWriteResp = Flipped(Decoupled(new AxiMasterWriteResp(cfg.axiIdWidth)))
  })

  val sIdle :: sReadReq :: sReadResp :: sWriteReq :: sWriteResp :: sResp :: Nil =
    Enum(6)

  val state   = RegInit(sIdle)
  val reqReg  = Reg(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth))
  val respReg = Reg(new DataMemResp(cfg.axiDataWidth))

  val byteOffset               = reqReg.addr(offsetBits - 1, 0)
  val bitOffset                = byteOffset << 3
  val shiftedWriteData         = (reqReg.wdata << bitOffset)(cfg.axiDataWidth - 1, 0)
  val shiftedWriteMask         = (reqReg.wmask << byteOffset)(dataBytes - 1, 0)
  val incomingByteOffset       = io.req.bits.addr(offsetBits - 1, 0)
  val incomingBitOffset        = incomingByteOffset << 3
  val incomingShiftedWriteData = (io.req.bits.wdata << incomingBitOffset)(cfg.axiDataWidth - 1, 0)
  val incomingShiftedWriteMask = (io.req.bits.wmask << incomingByteOffset)(dataBytes - 1, 0)
  val shiftedReadData          = io.axiReadResp.bits.data >> bitOffset

  val byteLoad = shiftedReadData(7, 0)
  val halfLoad = shiftedReadData(15, 0)
  val wordLoad = shiftedReadData(31, 0)

  val loadData = Wire(UInt(cfg.axiDataWidth.W))
  loadData := wordLoad
  when(reqReg.size === 0.U) {
    loadData := Mux(
      reqReg.unsigned,
      Cat(0.U((cfg.axiDataWidth - 8).W), byteLoad),
      Cat(Fill(cfg.axiDataWidth - 8, byteLoad(7)), byteLoad)
    )
  }.elsewhen(reqReg.size === 1.U) {
    loadData := Mux(
      reqReg.unsigned,
      Cat(0.U((cfg.axiDataWidth - 16).W), halfLoad),
      Cat(Fill(cfg.axiDataWidth - 16, halfLoad(15)), halfLoad)
    )
  }

  val readResponseBypass  = state === sReadResp && io.axiReadResp.valid
  val writeResponseBypass = state === sWriteResp && io.axiWriteResp.valid
  val bypassResponse      = Wire(new DataMemResp(cfg.axiDataWidth))
  bypassResponse.data  := Mux(readResponseBypass, loadData, 0.U)
  bypassResponse.fault := Mux(
    readResponseBypass,
    io.axiReadResp.bits.resp =/= AxiResp.okay,
    io.axiWriteResp.bits.resp =/= AxiResp.okay
  )
  bypassResponse.txnId := reqReg.txnId

  io.resp.valid := state === sResp || readResponseBypass || writeResponseBypass
  io.resp.bits  := Mux(state === sResp, respReg, bypassResponse)

  val responseTurnover      = io.resp.fire
  val requestWindow         = state === sIdle || responseTurnover
  // Direct input-to-AXI forwarding is only safe when the producer's bits are
  // already registered. LSU and PTW requests may be derived from the current
  // AXI response, so Mem deliberately leaves this disabled for those paths.
  val directIncomingRequest = if (allowDirectIncoming) state === sIdle && io.req.valid else false.B
  val incomingRead          = directIncomingRequest && !io.req.bits.write && io.incomingIssuePermit
  val incomingWrite         = directIncomingRequest && io.req.bits.write && io.incomingIssuePermit

  io.req.ready := requestWindow

  // Once an address request has fired, the AXI transaction must drain. Before
  // that point, recovery can safely discard the request and release its load
  // transaction tag to the backend.
  io.cancel.valid := io.abort && (state === sReadReq || state === sWriteReq)
  io.cancel.bits  := reqReg.txnId

  io.axiReadReq.valid      := (state === sReadReq && io.issuePermit && !io.abort) || incomingRead
  io.axiReadReq.bits.addr  := Mux(incomingRead, io.req.bits.addr, reqReg.addr)
  io.axiReadReq.bits.id    := 1.U(cfg.axiIdWidth.W)
  io.axiReadReq.bits.len   := 0.U(8.W)
  io.axiReadReq.bits.size  := Mux(incomingRead, io.req.bits.size, reqReg.size)
  io.axiReadReq.bits.burst := AxiBurst.incr
  io.axiReadResp.ready     := state === sReadResp

  io.axiWriteReq.valid      := (state === sWriteReq && io.issuePermit && !io.abort) || incomingWrite
  io.axiWriteReq.bits.addr  := Mux(incomingWrite, io.req.bits.addr, reqReg.addr)
  io.axiWriteReq.bits.id    := 1.U(cfg.axiIdWidth.W)
  io.axiWriteReq.bits.len   := 0.U(8.W)
  io.axiWriteReq.bits.size  := Mux(incomingWrite, io.req.bits.size, reqReg.size)
  io.axiWriteReq.bits.burst := AxiBurst.incr
  io.axiWriteReq.bits.data  := Mux(incomingWrite, incomingShiftedWriteData, shiftedWriteData)
  io.axiWriteReq.bits.strb  := Mux(incomingWrite, incomingShiftedWriteMask, shiftedWriteMask)
  io.axiWriteReq.bits.last  := true.B
  io.axiWriteResp.ready     := state === sWriteResp

  private def acceptIncomingRequest(): Unit = {
    reqReg := io.req.bits
    when(io.req.bits.write) {
      state := Mux(io.axiWriteReq.fire, sWriteResp, sWriteReq)
    }.otherwise {
      state := Mux(io.axiReadReq.fire, sReadResp, sReadReq)
    }
  }

  when(state === sIdle) {
    when(io.req.fire) {
      acceptIncomingRequest()
    }
  }.elsewhen(state === sReadReq) {
    when(io.abort) {
      state := sIdle
    }.elsewhen(io.axiReadReq.fire) {
      state := sReadResp
    }
  }.elsewhen(state === sReadResp) {
    when(io.axiReadResp.fire) {
      when(io.resp.fire) {
        when(io.req.fire) {
          acceptIncomingRequest()
        }.otherwise {
          state := sIdle
        }
      }.otherwise {
        respReg := bypassResponse
        state   := sResp
      }
    }
  }.elsewhen(state === sWriteReq) {
    when(io.abort) {
      state := sIdle
    }.elsewhen(io.axiWriteReq.fire) {
      state := sWriteResp
    }
  }.elsewhen(state === sWriteResp) {
    when(io.axiWriteResp.fire) {
      when(io.resp.fire) {
        when(io.req.fire) {
          acceptIncomingRequest()
        }.otherwise {
          state := sIdle
        }
      }.otherwise {
        respReg := bypassResponse
        state   := sResp
      }
    }
  }.otherwise {
    when(io.resp.fire) {
      when(io.req.fire) {
        acceptIncomingRequest()
      }.otherwise {
        state := sIdle
      }
    }
  }

  val requestOwned = RegInit(false.B)
  when(io.req.fire) {
    assert(!requestOwned || io.resp.fire)
  }
  when(io.resp.fire) {
    assert(requestOwned)
  }
  requestOwned := (requestOwned && !io.resp.fire && !io.cancel.valid) || io.req.fire
}
