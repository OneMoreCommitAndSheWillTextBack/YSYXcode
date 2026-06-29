package top.backend.fu

import chisel3._
import top.backend.fubundle.AluReq
import chisel3.util.MuxLookup
import top.backend.decoder.AluOp

class ALU(dataWidth: Int) extends Module {
  val io = IO(new AluReq(dataWidth))

  io.out := MuxLookup(io.op, 0.U)(
    Seq(
      AluOp.add -> (io.src1 + io.src2)
    )
  )
}
