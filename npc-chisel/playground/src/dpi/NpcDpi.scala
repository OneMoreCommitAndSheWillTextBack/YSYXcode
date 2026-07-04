package top.dpi

import chisel3._
import chisel3.util.circt.dpi._

object NpcCommitGroup extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_commit_group"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "validMask",
      "finishMask",
      "pc0",
      "inst0",
      "pc1",
      "inst1"
    )
  )
}

object NpcCacheHit extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_cache_hit"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "hit"
    )
  )
}

object NpcIssueQueuePerf extends DPIClockedVoidFunctionImport {
  override def functionName: String              = "npc_issue_queue_perf"
  override def inputNames:   Option[Seq[String]] = Some(
    Seq(
      "issueCount",
      "occupancy",
      "blockReady",
      "blockOperand"
    )
  )
}

class NpcContextDpi extends ExtModule {
  val contextValid = IO(Input(Bool()))
  val pc           = IO(Input(UInt(32.W)))
  val privMode     = IO(Input(UInt(32.W)))
  val mstatus      = IO(Input(UInt(32.W)))
  val mtvec        = IO(Input(UInt(32.W)))
  val mepc         = IO(Input(UInt(32.W)))
  val mcause       = IO(Input(UInt(32.W)))
  val mtval        = IO(Input(UInt(32.W)))
  val mie          = IO(Input(UInt(32.W)))
  val mip          = IO(Input(UInt(32.W)))
  val mscratch     = IO(Input(UInt(32.W)))
  val mcycle       = IO(Input(UInt(32.W)))
  val minstret     = IO(Input(UInt(32.W)))

  setInline(
    "NpcContextDpi.sv",
    """module NpcContextDpi(
      |  input         contextValid,
      |  input  [31:0] pc,
      |  input  [31:0] privMode,
      |  input  [31:0] mstatus,
      |  input  [31:0] mtvec,
      |  input  [31:0] mepc,
      |  input  [31:0] mcause,
      |  input  [31:0] mtval,
      |  input  [31:0] mie,
      |  input  [31:0] mip,
      |  input  [31:0] mscratch,
      |  input  [31:0] mcycle,
      |  input  [31:0] minstret
      |);
      |
      |  export "DPI-C" function npc_dpi_context_valid;
      |  function byte unsigned npc_dpi_context_valid();
      |    npc_dpi_context_valid = {7'b0, contextValid};
      |  endfunction
      |
      |  export "DPI-C" function npc_dpi_get_pc;
      |  function int unsigned npc_dpi_get_pc();
      |    npc_dpi_get_pc = pc;
      |  endfunction
      |
      |  export "DPI-C" function npc_dpi_get_priv;
      |  function int unsigned npc_dpi_get_priv();
      |    npc_dpi_get_priv = privMode;
      |  endfunction
      |
      |  export "DPI-C" function npc_dpi_get_csr;
      |  function int unsigned npc_dpi_get_csr(input int unsigned addr);
      |    case (addr)
      |      32'h300: npc_dpi_get_csr = mstatus;
      |      32'h304: npc_dpi_get_csr = mie;
      |      32'h305: npc_dpi_get_csr = mtvec;
      |      32'h340: npc_dpi_get_csr = mscratch;
      |      32'h341: npc_dpi_get_csr = mepc;
      |      32'h342: npc_dpi_get_csr = mcause;
      |      32'h343: npc_dpi_get_csr = mtval;
      |      32'h344: npc_dpi_get_csr = mip;
      |      32'hb00: npc_dpi_get_csr = mcycle;
      |      32'hb02: npc_dpi_get_csr = minstret;
      |      default: npc_dpi_get_csr = 32'b0;
      |    endcase
      |  endfunction
      |
      |endmodule
      |""".stripMargin
  )
}

class NpcGprDpi extends ExtModule {
  val gpr = IO(Input(UInt((32 * 32).W)))

  setInline(
    "NpcGprDpi.sv",
    """module NpcGprDpi(
      |  input [1023:0] gpr
      |);
      |
      |  export "DPI-C" function npc_dpi_get_gpr;
      |  function int unsigned npc_dpi_get_gpr(input int unsigned idx);
      |    if (idx < 32)
      |      npc_dpi_get_gpr = gpr[idx * 32 +: 32];
      |    else
      |      npc_dpi_get_gpr = 32'b0;
      |  endfunction
      |
      |endmodule
      |""".stripMargin
  )
}
