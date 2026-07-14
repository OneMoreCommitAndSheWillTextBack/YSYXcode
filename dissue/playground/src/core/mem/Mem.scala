package top.core.mem

import chisel3._
import chisel3.util.{Decoupled, Enum, MuxCase, Valid}
import top.bus.axi.AxiPort
import top.config.MemConfig
import top.core.bundle.{DataMemExternalization, DataMemKind, DataMemReq, DataMemResp, DataMemTxn, InstMemReq, InstMemResp, OwnedDataMemReq, RobRecovery}
import top.device.DeviceConst

/** Owns the physical memory hierarchy below Core.
  *
  * Cacheable backend data accesses use DCache. Page-table walks, atomics, and device accesses bypass it through scalar
  * AXI accessors. The AXI master is deliberately single-outstanding, so response routing only needs one owner register
  * for reads and one for writes.
  */
class Mem(cfg: MemConfig = MemConfig(), robEntries: Int = 16) extends Module {
  private val readOwnerInst :: readOwnerDcache :: readOwnerBypass :: readOwnerPtw :: Nil = Enum(4)
  private val robIdxWidth = math.max(chisel3.util.log2Ceil(robEntries), 1)

  val io = IO(new Bundle {
    val imemReq  = Flipped(Decoupled(new InstMemReq(cfg.addrWidth)))
    val imemResp = Decoupled(new InstMemResp(cfg.fetchBytes))

    val dmemReq  = Flipped(Decoupled(new OwnedDataMemReq(cfg.addrWidth, cfg.axiDataWidth, robIdxWidth)))
    val dmemResp = Decoupled(new DataMemResp(cfg.axiDataWidth))

    val flush   = Input(Bool())
    val recover = Input(new RobRecovery(robIdxWidth))
    val robHead = Input(UInt(robIdxWidth.W))
    val unresolvedCfi = Input(Vec(robEntries, Bool()))
    val dmemCancel = Output(Vec(DCache.cancelPorts(cfg.dcache), Valid(UInt(DataMemTxn.width.W))))

    val ptwReq  = Flipped(Decoupled(new DataMemReq(cfg.addrWidth, cfg.axiDataWidth)))
    val ptwResp = Decoupled(new DataMemResp(cfg.axiDataWidth))

    val perf = Output(new DCachePerf(cfg.dcache))

    val axi = new AxiPort
  })

  private def inRange(addr: UInt, base: BigInt, size: BigInt): Bool =
    addr >= base.U(cfg.addrWidth.W) && addr < (base + size).U(cfg.addrWidth.W)

  private def isDevice(addr: UInt): Bool =
    inRange(addr, DeviceConst.clintBase, DeviceConst.clintSize) ||
      inRange(addr, DeviceConst.rtcBase, DeviceConst.rtcSize) ||
      inRange(addr, DeviceConst.plicBase, DeviceConst.plicSize)

  private def mayIssueAxi(owner: top.core.bundle.DataMemOwner): Bool =
    DataMemExternalization.mayIssueAxi(
      owner,
      io.unresolvedCfi,
      io.robHead,
      robEntries,
      robIdxWidth,
      io.flush,
      io.recover
    )

  val refill       = Module(new AxiReadRefill(cfg))
  val dcache       = Module(new DCache(cfg.dcache, cfg, robEntries))
  val bypassAccess = Module(new AxiDataAccess(cfg))
  val ptwAccess    = Module(new AxiDataAccess(cfg))
  val axiMaster    = Module(new AxiMaster(cfg))

  refill.io.req <> io.imemReq
  io.imemResp <> refill.io.resp

  private val routeToDcache = io.dmemReq.bits.request.cacheable && io.dmemReq.bits.request.kind === DataMemKind.normal &&
    !isDevice(io.dmemReq.bits.request.addr)

  dcache.io.req.valid       := io.dmemReq.valid && routeToDcache
  dcache.io.req.bits        := io.dmemReq.bits
  private val isArchitecturallyVisibleBypass = isDevice(io.dmemReq.bits.request.addr) ||
    io.dmemReq.bits.request.kind === DataMemKind.atomic
  private val bypassAtRobHead = !io.dmemReq.bits.owner.squashable || io.dmemReq.bits.owner.robIdx === io.robHead
  private val bypassMayIssue = mayIssueAxi(io.dmemReq.bits.owner) &&
    (!isArchitecturallyVisibleBypass || bypassAtRobHead)
  private val needsAtomicCacheMaintenance = io.dmemReq.bits.request.kind === DataMemKind.atomic
  private val bypassCanAccept = bypassMayIssue &&
    (!needsAtomicCacheMaintenance || dcache.io.cleanInvalidate.ready)

  // MMIO and atomics can have side effects even for reads, so they wait for
  // ROB-head ownership in addition to the branch-resolution permit.
  bypassAccess.io.req.valid := io.dmemReq.valid && !routeToDcache && bypassCanAccept
  bypassAccess.io.req.bits  := io.dmemReq.bits.request
  io.dmemReq.ready          := Mux(
    routeToDcache,
    dcache.io.req.ready,
    bypassAccess.io.req.ready && bypassCanAccept
  )

  dcache.io.flush   := io.flush
  dcache.io.recover := io.recover
  dcache.io.robHead := io.robHead
  dcache.io.unresolvedCfi := io.unresolvedCfi
  dcache.io.cleanInvalidate.valid := io.dmemReq.valid && !routeToDcache && bypassMayIssue &&
    needsAtomicCacheMaintenance
  dcache.io.cleanInvalidate.bits := io.dmemReq.bits.request.addr
  io.dmemCancel     := dcache.io.cancel

  ptwAccess.io.req <> io.ptwReq
  io.ptwResp <> ptwAccess.io.resp

  private val dcacheResponse = dcache.io.resp.valid
  io.dmemResp.valid          := dcacheResponse || bypassAccess.io.resp.valid
  io.dmemResp.bits           := Mux(dcacheResponse, dcache.io.resp.bits, bypassAccess.io.resp.bits)
  dcache.io.resp.ready       := io.dmemResp.ready && dcacheResponse
  bypassAccess.io.resp.ready := io.dmemResp.ready && !dcacheResponse

  io.perf.access         := dcache.io.perf.access
  io.perf.hit            := dcache.io.perf.hit
  io.perf.miss           := dcache.io.perf.miss
  io.perf.bypass         := io.dmemReq.fire && !routeToDcache
  io.perf.mshrAlloc      := dcache.io.perf.mshrAlloc
  io.perf.mshrMerge      := dcache.io.perf.mshrMerge
  io.perf.mshrFullStall  := dcache.io.perf.mshrFullStall
  io.perf.hitUnderMiss   := dcache.io.perf.hitUnderMiss
  io.perf.queuedMiss     := dcache.io.perf.queuedMiss
  io.perf.refillStart    := dcache.io.perf.refillStart
  io.perf.refillComplete := dcache.io.perf.refillComplete
  io.perf.refillFault    := dcache.io.perf.refillFault
  io.perf.mshrOccupancy  := dcache.io.perf.mshrOccupancy

  private val dcacheWriteSelected = dcache.io.axiWriteReq.valid
  private val bypassWriteSelected = !dcacheWriteSelected && bypassAccess.io.axiWriteReq.valid
  private val writeSelected       = dcacheWriteSelected || bypassWriteSelected

  axiMaster.io.writeReq.valid       := writeSelected
  axiMaster.io.writeReq.bits        := Mux(dcacheWriteSelected, dcache.io.axiWriteReq.bits, bypassAccess.io.axiWriteReq.bits)
  dcache.io.axiWriteReq.ready       := axiMaster.io.writeReq.ready && dcacheWriteSelected
  bypassAccess.io.axiWriteReq.ready := axiMaster.io.writeReq.ready && bypassWriteSelected
  ptwAccess.io.axiWriteReq.ready    := false.B

  private val readOwner        = RegInit(readOwnerInst)
  private val writeOwnerDcache = RegInit(false.B)

  private val bypassReadSelected = !writeSelected && bypassAccess.io.axiReadReq.valid
  private val ptwReadSelected    = !writeSelected && !bypassAccess.io.axiReadReq.valid && ptwAccess.io.axiReadReq.valid
  private val dcacheReadSelected = !writeSelected && !bypassAccess.io.axiReadReq.valid &&
    !ptwAccess.io.axiReadReq.valid && dcache.io.axiReadReq.valid
  private val instReadSelected   =
    !writeSelected && !bypassAccess.io.axiReadReq.valid && !ptwAccess.io.axiReadReq.valid &&
      !dcache.io.axiReadReq.valid && refill.io.axiReadReq.valid

  axiMaster.io.readReq.valid       := bypassReadSelected || ptwReadSelected || dcacheReadSelected || instReadSelected
  axiMaster.io.readReq.bits        := MuxCase(
    refill.io.axiReadReq.bits,
    Seq(
      bypassReadSelected -> bypassAccess.io.axiReadReq.bits,
      ptwReadSelected    -> ptwAccess.io.axiReadReq.bits,
      dcacheReadSelected -> dcache.io.axiReadReq.bits,
      instReadSelected   -> refill.io.axiReadReq.bits
    )
  )
  bypassAccess.io.axiReadReq.ready := axiMaster.io.readReq.ready && bypassReadSelected
  ptwAccess.io.axiReadReq.ready    := axiMaster.io.readReq.ready && ptwReadSelected
  dcache.io.axiReadReq.ready       := axiMaster.io.readReq.ready && dcacheReadSelected
  refill.io.axiReadReq.ready       := axiMaster.io.readReq.ready && instReadSelected

  when(axiMaster.io.readReq.fire) {
    readOwner := MuxCase(
      readOwnerInst,
      Seq(
        bypassReadSelected -> readOwnerBypass,
        ptwReadSelected    -> readOwnerPtw,
        dcacheReadSelected -> readOwnerDcache,
        instReadSelected   -> readOwnerInst
      )
    )
  }
  when(axiMaster.io.writeReq.fire) {
    writeOwnerDcache := dcacheWriteSelected
  }

  dcache.io.axiReadResp.valid       := axiMaster.io.readResp.valid && readOwner === readOwnerDcache
  dcache.io.axiReadResp.bits        := axiMaster.io.readResp.bits
  bypassAccess.io.axiReadResp.valid := axiMaster.io.readResp.valid && readOwner === readOwnerBypass
  bypassAccess.io.axiReadResp.bits  := axiMaster.io.readResp.bits
  ptwAccess.io.axiReadResp.valid    := axiMaster.io.readResp.valid && readOwner === readOwnerPtw
  ptwAccess.io.axiReadResp.bits     := axiMaster.io.readResp.bits
  refill.io.axiReadResp.valid       := axiMaster.io.readResp.valid && readOwner === readOwnerInst
  refill.io.axiReadResp.bits        := axiMaster.io.readResp.bits
  axiMaster.io.readResp.ready       := MuxCase(
    refill.io.axiReadResp.ready,
    Seq(
      (readOwner === readOwnerDcache) -> dcache.io.axiReadResp.ready,
      (readOwner === readOwnerBypass) -> bypassAccess.io.axiReadResp.ready,
      (readOwner === readOwnerPtw)    -> ptwAccess.io.axiReadResp.ready,
      (readOwner === readOwnerInst)   -> refill.io.axiReadResp.ready
    )
  )

  dcache.io.axiWriteResp.valid       := axiMaster.io.writeResp.valid && writeOwnerDcache
  dcache.io.axiWriteResp.bits        := axiMaster.io.writeResp.bits
  bypassAccess.io.axiWriteResp.valid := axiMaster.io.writeResp.valid && !writeOwnerDcache
  bypassAccess.io.axiWriteResp.bits  := axiMaster.io.writeResp.bits
  ptwAccess.io.axiWriteResp.valid    := false.B
  ptwAccess.io.axiWriteResp.bits     := axiMaster.io.writeResp.bits
  axiMaster.io.writeResp.ready       := Mux(
    writeOwnerDcache,
    dcache.io.axiWriteResp.ready,
    bypassAccess.io.axiWriteResp.ready
  )

  io.axi.awvalid           := axiMaster.io.axi.awvalid
  io.axi.awaddr            := axiMaster.io.axi.awaddr
  io.axi.awid              := axiMaster.io.axi.awid
  io.axi.awlen             := axiMaster.io.axi.awlen
  io.axi.awsize            := axiMaster.io.axi.awsize
  io.axi.awburst           := axiMaster.io.axi.awburst
  axiMaster.io.axi.awready := io.axi.awready

  io.axi.wvalid           := axiMaster.io.axi.wvalid
  io.axi.wdata            := axiMaster.io.axi.wdata
  io.axi.wstrb            := axiMaster.io.axi.wstrb
  io.axi.wlast            := axiMaster.io.axi.wlast
  axiMaster.io.axi.wready := io.axi.wready

  io.axi.bready           := axiMaster.io.axi.bready
  axiMaster.io.axi.bvalid := io.axi.bvalid
  axiMaster.io.axi.bresp  := io.axi.bresp
  axiMaster.io.axi.bid    := io.axi.bid

  io.axi.arvalid           := axiMaster.io.axi.arvalid
  io.axi.araddr            := axiMaster.io.axi.araddr
  io.axi.arid              := axiMaster.io.axi.arid
  io.axi.arlen             := axiMaster.io.axi.arlen
  io.axi.arsize            := axiMaster.io.axi.arsize
  io.axi.arburst           := axiMaster.io.axi.arburst
  axiMaster.io.axi.arready := io.axi.arready

  io.axi.rready           := axiMaster.io.axi.rready
  axiMaster.io.axi.rvalid := io.axi.rvalid
  axiMaster.io.axi.rresp  := io.axi.rresp
  axiMaster.io.axi.rdata  := io.axi.rdata
  axiMaster.io.axi.rlast  := io.axi.rlast
  axiMaster.io.axi.rid    := io.axi.rid
}
