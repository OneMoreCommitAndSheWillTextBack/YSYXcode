package top.core.backend.decoder.rvi

import chisel3._
import chisel3.util.BitPat
import top.core.backend.decoder._

private[decoder] object RviMemDecode extends DecodeGroup {
  import DecodeDsl._
  import RviPatterns._

  val table: Seq[(BitPat, List[UInt])] = Seq(
    LB        -> load(size = MemSize.byte),
    LH        -> load(size = MemSize.half),
    LW        -> load(size = MemSize.word),
    LBU       -> load(size = MemSize.byte, unsigned = true),
    LHU       -> load(size = MemSize.half, unsigned = true),
    SB        -> store(size = MemSize.byte),
    SH        -> store(size = MemSize.half),
    SW        -> store(size = MemSize.word),
    LR_W      -> atomic(LsuOp.lr, readsRs2 = false),
    SC_W      -> atomic(LsuOp.sc),
    AMOSWAP_W -> atomic(LsuOp.amoSwap),
    AMOADD_W  -> atomic(LsuOp.amoAdd),
    AMOXOR_W  -> atomic(LsuOp.amoXor),
    AMOAND_W  -> atomic(LsuOp.amoAnd),
    AMOOR_W   -> atomic(LsuOp.amoOr),
    AMOMIN_W  -> atomic(LsuOp.amoMin),
    AMOMAX_W  -> atomic(LsuOp.amoMax),
    AMOMINU_W -> atomic(LsuOp.amoMinu),
    AMOMAXU_W -> atomic(LsuOp.amoMaxu)
  )
}
