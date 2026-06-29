package top.backend

import chisel3._
import chisel3.util.{Decoupled, Valid}
import top.bundle._
import top.config.BackendConfig

import top.backend.regfile._
import top.backend.decoder._

class Backend(cfg: BackendConfig = BackendConfig()) extends Module {
  val io = IO(new Bundle {
    val frontend = Flipped(Decoupled(new FrontendToBackend(cfg.issueWidth, cfg.addrWidth)))
    val redirect = Output(new BackendToFrontend(cfg.addrWidth))

    val dmemReq  = Decoupled(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
    val dmemResp = Flipped(Decoupled(new DataMemResp(cfg.dataWidth)))

    val commit = Output(Vec(cfg.issueWidth, Valid(new CommitPayload(cfg.addrWidth))))
  })

  val gpr     = Module(new RegFile(cfg))
  val decoder = Module(new Decoder(cfg))

  io.frontend.ready := true.B
  io.redirect       := 0.U.asTypeOf(new BackendToFrontend(cfg.addrWidth))

  io.dmemReq.valid  := false.B
  io.dmemReq.bits   := 0.U.asTypeOf(new DataMemReq(cfg.addrWidth, cfg.dataWidth))
  io.dmemResp.ready := true.B

  for (commit <- io.commit) {
    commit.valid := false.B
    commit.bits  := 0.U.asTypeOf(new CommitPayload(cfg.addrWidth))
  }
}
