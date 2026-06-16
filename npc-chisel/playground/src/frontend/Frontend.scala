package top.frontend

import chisel3._
import chisel3.util.Decoupled
import chisel3.util.MuxCase
import top.config.ICacheConfig
import top.frontend.bundle.{ICacheReq, ICacheResp, PcRedirect}
import top.frontend.ifetch.{FetchPacket, IFetch}
import top.frontend.pcgen.PCGen
import top.frontend.icache._

class Frontend(
  resetVector: BigInt = BigInt("80000000", 16),
  cfg:         ICacheConfig = ICacheConfig())
    extends Module {
  val io = IO(new Bundle {
    val trapRedirect   = Input(new PcRedirect)
    val branchRedirect = Input(new PcRedirect)
    val predRedirect   = Input(new PcRedirect)

    val pc    = Output(UInt(cfg.addrWidth.W))
    val fetch = Decoupled(new FetchPacket)
  })

  val pcGen  = Module(new PCGen(resetVector, cfg.addrWidth, cfg.fetchBytes))
  val ifetch = Module(new IFetch(cfg))
  val iCache = Module(new ICache(cfg))

  val redirect = Wire(new PcRedirect)
  redirect.valid := io.trapRedirect.valid || io.branchRedirect.valid || io.predRedirect.valid
  redirect.value := MuxCase(
    0.U(cfg.addrWidth.W),
    Seq(
      io.trapRedirect.valid   -> io.trapRedirect.value,
      io.branchRedirect.valid -> io.branchRedirect.value,
      io.predRedirect.valid   -> io.predRedirect.value
    )
  )

  pcGen.io.redirect := redirect
  pcGen.io.advance  := ifetch.io.pcAdvance

  ifetch.io.redirect := redirect
  ifetch.io.pc       := pcGen.io.pc

  io.pc := pcGen.io.pc
}
