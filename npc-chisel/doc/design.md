# 前端取指设计

本文档记录前端取指流水线的设计方向，以及 PC 生成、ICache、halfword 切分和指令缓冲之间的接口语义。

## 流水线结构

前端计划设计成一个较小的取指流水线：

1. 生成取指请求，并用 cache block 地址访问 ICache。
2. 将 ICache 返回的 cache block 转换成有序的 16-bit halfword entry。
3. 将 halfword 扩展或组合成完整指令，再放入 instruction buffer，等待后续发射。

只要下游 halfword buffer 还有足够空间容纳下一个 cache block，ICache 就应该尽量继续工作，保证指令流顺畅。

需要注意的是，前端取指是 speculative 的：取到了一个完整 cache block，并不代表这个 block 里的所有指令最终都会被执行。

## 地址语义

前端应该明确区分下面几个地址概念：

- `startPc`：当前 fetch stream 真正开始的 PC。
- `blockAddr`：访问 ICache 时使用的对齐 cache block 地址。
- `nextPc`：当前 cache block 之后的下一个顺序取指地址。

例如，当 `fetchBytes = 8` 时：

```text
startPc   = 0x80000006
blockAddr = 0x80000000
nextPc    = 0x80000008
```

这说明 `pc + fetchBytes` 不总是正确的下一个顺序 PC。如果当前取指从 cache block 中间开始，正确的下一个顺序取指地址应该是：

```scala
nextPc = blockAddr + cfg.fetchBytes.U
```

ICache 请求和响应应该保留原始的 `startPc`，因为 splitter 需要根据它判断返回的 cache block 中哪些 halfword 属于当前指令流。

## 建议的 ICache 元信息

比较清晰的接口方式是携带一个 block 级别的 metadata：

```scala
class IFetchBlockMeta(cfg: ICacheConfig) extends Bundle {
  val startPc   = UInt(cfg.addrWidth.W)
  val blockAddr = UInt(cfg.addrWidth.W)
  val pred      = new FetchPred(cfg)
}

class ICacheReq(cfg: ICacheConfig) extends Bundle {
  val meta = new IFetchBlockMeta(cfg)
}

class ICacheResp(cfg: ICacheConfig) extends Bundle {
  val meta = new IFetchBlockMeta(cfg)
  val data = UInt((cfg.fetchBytes * 8).W)
  val hit  = Bool()
}
```

这种写法里，`blockAddr` 没有重复。ICache 使用：

```scala
req.bits.meta.blockAddr
```

来做 tag/index 查找。IFetch 使用：

```scala
resp.bits.meta.startPc
resp.bits.meta.blockAddr
```

来把返回的 cache block 切成正确的 16-bit 指令流。

如果以后支持多个 outstanding ICache 请求，可以再加入 `epoch` 或 sequence id。当前如果只允许一个 outstanding request，那么类似 `dropResp` 的标志就足够。

这里的 `pred` 是随 fetch block 透传的预测元信息。ICache 不理解预测语义，只需要把 request metadata 原样保存到 response：

```scala
respReg.meta := io.req.bits.meta
```

BPU 自身可以使用 `BpuConfig`，但进入 ICache metadata 后使用轻量的 `FetchPred(ICacheConfig)`。这样 ICache bundle 只依赖 ICache 相关宽度，同时因为 `FrontendConfig` 统一生成 `ICacheConfig` 和 `BpuConfig`，`addrWidth` / `fetchBytes` 保持一致。

## Halfword Entry

16-bit buffer 里最好给每个 halfword 保存 PC：

```scala
class HalfwordEntry extends Bundle {
  val pc        = UInt(cfg.addrWidth.W)
  val bits      = UInt(16.W)
  val blockAddr = UInt(cfg.addrWidth.W)
  val pred      = new FetchPred(cfg)
}
```

这样做是因为 RVC 指令长度是可变的：

- 16-bit 指令消耗一个 halfword。
- 32-bit 指令消耗两个 halfword。

最终指令的 PC 应该是它第一个 halfword 的 PC。例如第一条指令是 32-bit 时：

```text
inst.pc  = halfword0.pc
inst.raw = Cat(halfword1.bits, halfword0.bits)
```

如果 halfword buffer 已经用 `count` 管理有效 entry 数量，那么每个 entry 不一定需要额外的 `valid` 位。当前实现把 block-level prediction 复制到每个 halfword entry 中，代价是每个 halfword 重复保存一份 `pred`，好处是 assembler 在组合 16-bit / 32-bit 指令时可以直接从指令首 halfword 取预测信息。

## 处理非对齐取指起点

如果 redirect target 或 reset PC 不是 `fetchBytes` 对齐的，ICache 仍然应该访问对齐后的 cache block。然后由 splitter 丢弃 `startPc` 之前的 halfword。

例如：

```text
fetchBytes = 8
startPc    = 0x80000006
blockAddr  = 0x80000000

block halfwords:
0x80000000 drop
0x80000002 drop
0x80000004 drop
0x80000006 keep
```

下一个顺序请求应该从这里开始：

```text
0x80000008
```

这样 halfword buffer 里的顺序仍然是严格递增的 PC：

```text
0x80000006, 0x80000008, 0x8000000a, ...
```

## 在 Cache Block 中间发生 Redirect

按 cache block 取指是 speculative 的。如果分支、异常或其他控制流变化发生在 cache block 中间，正确做法不是让 ICache 特殊处理，而是 flush 前端中已经进入错误路径的内容。

处理流程应该是：

1. PCGen 重定向到 redirect target。
2. flush halfword buffer。
3. flush instruction buffer。
4. 如果旧路径上还有未返回的 ICache response，接收它，但不要写入 buffer。
5. 从 redirect target 重新开始取指。

例如：

```text
0x80000000 inst0
0x80000002 inst1
0x80000004 branch taken
0x80000006 wrong path
```

如果 `0x80000004` 的分支跳转成立，那么 `0x80000006` 以及之后已经进入 halfword buffer 或 instruction buffer 的内容都属于 wrong path，必须被 flush。

ICache 不需要知道这个跳转发生在 cache block 中间。它只负责返回对齐的 cache block。

## 丢弃旧 ICache Response

只 flush buffer 还不够。因为旧路径的 ICache response 可能在 flush 之后才回来：

```text
cycle 10: 发送旧路径请求 A
cycle 12: 发生 redirect，flush frontend buffers
cycle 20: 请求 A 的 response 返回
```

在 cycle 20，请求 A 的 response 必须被握手接收，但不能写入 halfword buffer。否则它会在 flush 之后污染新路径。

如果只允许一个 outstanding request，可以使用：

```text
reqOutstanding
dropResp
```

redirect 时：

```text
if reqOutstanding:
  dropResp := true
flush halfword buffer
flush instruction buffer
```

旧 response 返回时：

```text
icacheResp.ready := true
enqueueToHalfwordBuffer := false
dropResp := false
```

`epoch` 是同一个思想的更通用版本。请求带上当前 epoch，redirect 时翻转 epoch，response 回来时如果 epoch 和当前 epoch 不一致，就丢弃。这个方案在支持多个 outstanding request 时更有价值。

当前阶段如果设计上保证只有一个 outstanding ICache 请求，`dropResp` 方案更简单，也足够使用。

## Splitter 丢弃 vs ICache 重排序

更推荐的方案是：在 splitter 阶段丢弃不需要的 halfword，而不是让 ICache 对 cache block 内部重新排序。

ICache 应该始终返回普通的对齐 cache block：

```text
blockAddr = 0x80000000
data      = bytes [0x80000000, 0x80000008)
```

splitter 根据 `startPc` 选择第一个有效 halfword。这样 ICache 逻辑简单，halfword stream 也保持真实程序顺序。

不要把 cache block 重排成类似下面的顺序：

```text
0x80000006, 0x80000000, 0x80000002, 0x80000004
```

这个顺序不是指令流顺序。`0x80000006` 之后的顺序地址应该是 `0x80000008`，而不是绕回 `0x80000000`。

因此推荐策略是：

```text
ICache: 只负责对齐 block 访问
Splitter: 丢弃 startPc 之前的 halfword
Buffers: 保持 PC 递增顺序
Redirect: flush speculative frontend state，并丢弃旧 response
```

## 配置结构

前端配置统一从 `FrontendConfig` 进入。公共参数只在 `FrontendConfig` 中出现一次，然后派生给 ICache、BPU 和 IFetch，避免多个模块分别保存一份 `addrWidth` / `fetchBytes` 后出现不一致。

当前配置结构：

```scala
final case class ICacheConfig(
  addrWidth:  Int = 32,
  fetchBytes: Int = 8,
  sets:       Int = 64,
  ways:       Int = 1)

final case class BpuConfig(
  addrWidth:   Int = 32,
  fetchBytes:  Int = 8,
  btbEntries: Int = 64,
  bhtEntries: Int = 128,
  btbWays:    Int = 1)

final case class IFetchConfig(
  halfwordEntries:   Int = 16,
  instBufferEntries: Int = 8)

final case class FrontendConfig(
  addrWidth:         Int = 32,
  fetchBytes:        Int = 8,
  icacheSets:        Int = 64,
  icacheWays:        Int = 1,
  btbEntries:        Int = 64,
  bhtEntries:        Int = 128,
  btbWays:           Int = 1,
  halfwordEntries:   Int = 16,
  instBufferEntries: Int = 8) {
  val icache = ICacheConfig(...)
  val bpu    = BpuConfig(...)
  val ifetch = IFetchConfig(...)
}
```

模块实例化时：

```scala
val pcGen  = Module(new PCGen(resetVector, cfg.addrWidth, cfg.fetchBytes))
val ifetch = Module(new IFetch(cfg.icache, cfg.ifetch))
val iCache = Module(new ICache(cfg.icache))
val bpu    = Module(new Bpu(cfg.bpu))
```

这样 buffer depth、BTB/BHT entry 数、ICache set/way 都可以通过同一个前端配置入口调整。

## 后续接口方向

更清晰的前端接口应该逐步从松散的 `pc` / `pcAdvance` 信号，转向 request/response stream。

概念上可以理解为：

```text
PCGen -> fetch request -> ICache -> block response -> splitter -> halfword buffer
```

fetch request 只有在下游路径有能力容纳返回的 block 时才 fire。请求 fire 后，PCGen 对于顺序取指前进到：

```text
blockAddr + fetchBytes
```

如果发生 redirect，则 PCGen 改为 redirect target。

这样 `"advance"` 的语义会更明确：它表示一个取指请求已经被接受，而不是某个原始 PC 信号被观察到。

## BPU 设计目标

BPU 应该放在 PCGen 附近做早预测，而不是等 predecode 之后才第一次预测。predecode 仍然需要识别真实指令、校验预测、生成错误预测 redirect，并把真实分支信息反馈给 BPU 更新。

推荐的前端阶段划分是：

```text
F0: PCGen + BPU
    生成 fetch startPc / blockAddr / predicted nextPc

F1: ICache request
    用 blockAddr 访问 ICache

F2: ICache response + align/split/predecode
    切 halfword，识别 16/32-bit，生成最多两条 FetchInst
    校验 BPU 预测，必要时 redirect

F3: FetchQueue / InstBuffer
    缓冲 FetchPacket，供后端双发射/译码
```

这样做的核心原因是：BPU 预测时不依赖当前周期重新 predecode 出来的指令 PC，而是依赖历史训练得到的 BTB/BHT 信息。predecode 的职责是确认这次预测是否正确，以及把后端最终执行结果更新回 BPU。

第一版 BPU 可以保持简单：

```text
BTB: direct-mapped 或小容量 set-associative
BHT: 2-bit saturating counter
RAS: 暂时不做
Global history: 暂时不做
Indirect predictor: 暂时不做
```

但接口应该从一开始就保持可扩展，不要把 BPU 简化成一个单独的 `predRedirect` 信号。

## BPU 预测接口

BPU 的预测输出以 fetch block 为粒度。它回答的是：“当前 fetch block 内是否有一条预测会改变 next PC 的控制流指令，以及它的位置和目标地址是什么。”

建议的预测 bundle：

```scala
object CfiType extends ChiselEnum {
  val none, branch, jal, jalr, call, ret = Value
}

class BpuPred(cfg: BpuConfig) extends Bundle {
  val valid     = Bool()
  val taken     = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val cfiType   = CfiType()
}
```

字段语义：

- `valid`：BTB 命中，说明当前 block 中存在已知控制流指令。
- `taken`：最终方向预测。对于 `jal` 这类无条件跳转，通常等于 true。
- `target`：预测 taken 时的 next PC。
- `cfiOffset`：控制流指令在 fetch block 内的 halfword offset。
- `cfiType`：控制流类型，例如 branch、jal、jalr、call、ret。

例如：

```text
fetchBytes = 8
blockAddr  = 0x80000000

0x80000000 inst0
0x80000002 inst1
0x80000004 branch predicted taken
0x80000006 wrong path if taken
```

BPU 可以输出：

```text
valid     = true
taken     = true
target    = 0x80000120
cfiOffset = 2
```

其中 `cfiOffset = 2` 表示控制流指令位于 block 内第 2 个 halfword，也就是 `0x80000004`。

## 预测元信息随 Fetch Block 流动

预测结果应该放入 fetch request 的 metadata，并随着 ICache response 一路传到 splitter、predecode 和 assembler。ICache 不理解预测字段，只负责透传。

概念接口：

```scala
class FetchPred(cfg: ICacheConfig) extends Bundle {
  val valid     = Bool()
  val taken     = Bool()
  val target    = UInt(cfg.addrWidth.W)
  val cfiOffset = UInt(log2Ceil(cfg.fetchBytes / 2).W)
  val cfiType   = CfiType()
}

class IFetchBlockMeta(cfg: ICacheConfig) extends Bundle {
  val startPc   = UInt(cfg.addrWidth.W)
  val blockAddr = UInt(cfg.addrWidth.W)
  val pred      = new FetchPred(cfg)
}

class ICacheReq(cfg: ICacheConfig) extends Bundle {
  val meta = new IFetchBlockMeta(cfg)
}

class ICacheResp(cfg: ICacheConfig) extends Bundle {
  val meta = new IFetchBlockMeta(cfg)
  val data = UInt((cfg.fetchBytes * 8).W)
  val hit  = Bool()
}
```

这样做的好处是：

```text
PCGen/BPU: 决定 predicted nextPc
ICache:    只使用 blockAddr 查 cache，并透传 meta
IFetch:    使用 startPc/blockAddr 切 halfword，使用 pred 做 lane mask 和 FetchInst 标记
Backend:   使用 FetchInst.pred* 字段检测错误预测
```

`BpuPred` 和 `FetchPred` 字段语义相同，但配置来源不同：`BpuPred` 属于 BPU 顶层接口，使用 `BpuConfig`；`FetchPred` 属于 ICache/IFetch metadata，使用 `ICacheConfig`。`Frontend` 负责逐字段连接二者。

当前如果只支持一个 outstanding ICache 请求，这个 metadata 已经足够。以后如果支持多个 outstanding request，应在 metadata 中加入 `epoch` 或 sequence id，用来丢弃 redirect 前的旧 response。

## PCGen 与 BPU 的关系

PCGen 的 next PC 选择优先级应该是：

```text
trap/exception redirect
> branch/jalr resolved redirect
> BPU predicted taken target
> sequential blockAddr + fetchBytes
```

`advance` 的含义仍然是 fetch request 被 ICache 接受。PCGen 内部保留顺序自增逻辑，`advance` 时走 `blockAddr + fetchBytes`。Frontend 在 PCGen 外部合并真实 redirect 和 BPU predicted target，并作为 PCGen 的 redirect 输入。

概念上：

```text
frontendRedirect =
  trap/exception redirect
  or branch/jalr resolved redirect
  or predRedirect

bpuRedirect.valid = fetchReq.fire && bpuPred.taken
bpuRedirect.value = bpuPred.target

pcGen.redirect = frontendRedirect has priority over bpuRedirect

PCGen:
  when redirect.valid:
    pc := redirect.value
  elsewhen advance:
    pc := blockAddr + fetchBytes
```

注意顺序地址仍然应该使用：

```scala
blockAddr + cfg.fetchBytes.U
```

而不是：

```scala
startPc + cfg.fetchBytes.U
```

这保证从非对齐 PC 开始取指时仍然跳到下一个 fetch block。

## Predecode 的职责

predecode 不应该承担“第一次预测”的职责。它位于 ICache response 之后，负责处理真实取回来的指令信息：

1. 根据 halfword stream 组出 16-bit 或 32-bit 指令。
2. 展开 RVC，得到统一的 32-bit 指令形式。
3. 识别 `branch`、`jal`、`jalr`、`call`、`ret` 等控制流类型。
4. 根据 `meta.pred.cfiOffset` 判断预测命中的具体 lane。
5. 如果 predicted taken 的控制流指令位于 slot0，则 mask 掉 slot1。
6. 给 `FetchInst` 填入 `predTaken`、`predNpc`、`predTarget`。
7. 如果发现预测和 predecode 能确认的信息冲突，生成前端 redirect。

对双发射来说，lane mask 很重要：

```text
slot0: predicted taken branch
slot1: wrong path, should be invalid
```

如果不 mask slot1，后端可能会看到同一个 fetch packet 中位于 taken branch 之后的错误路径指令。

当前 assembler 使用指令首 halfword 的 PC 来判断预测是否命中：

```scala
val predHit = pred.valid && pred.cfiOffset === pc(cfg.offsetBits - 1, 1)
```

命中后填充 `FetchInst` 预测字段：

```scala
inst.predTaken  := predHit && pred.taken
inst.predTarget := Mux(predHit, pred.target, 0.U)
inst.predNpc    := Mux(inst.predTaken, pred.target, pc + instLen)
```

slot mask 的第一版规则是：

```scala
slot1.valid := secondOutValid && !slot0.predTaken
```

也就是说，只有 slot0 命中预测且 predicted taken 时才屏蔽 slot1。slot1 的 bits 不需要清零，因为 `valid=false` 时 bits 不应该被后端使用。

## BPU 更新接口

BPU 的最终更新应该来自后端分支执行结果，而不是只来自 predecode。predecode 能识别控制流类型和静态目标，但条件分支是否 taken 必须等执行阶段确定。

建议的更新 bundle：

```scala
class BpuUpdate(cfg: BpuConfig) extends Bundle {
  val pc      = UInt(cfg.addrWidth.W)
  val cfiType = CfiType()
  val taken   = Bool()
  val target  = UInt(cfg.addrWidth.W)
  val instLen = UInt(3.W)
}
```

更新规则可以先保持简单：

```text
actual taken:
  分配或更新 BTB entry
  BHT counter +1

actual not taken:
  BHT counter -1
  BTB entry 可以保留，不必立即清除
```

BTB entry 至少保存：

```scala
class BtbEntry(cfg: BpuConfig) extends Bundle {
  val valid     = Bool()
  val tag       = UInt(cfg.btbTagBits.W)
  val cfiOffset = UInt(cfg.cfiOffsetBits.W)
  val target    = UInt(cfg.addrWidth.W)
  val cfiType   = CfiType()
}
```

BHT 使用 2-bit 饱和计数器：

```text
00 strongly not taken
01 weakly not taken
10 weakly taken
11 strongly taken
```

第一版可以用 blockAddr 的 index 访问 BTB/BHT。后续如果需要降低 alias，可以替换成 set-associative BTB、GShare、局部历史或 TAGE-like 结构，但外部 `BpuPred` / `BpuUpdate` 接口不需要大改。

## 后续扩展路径

推荐按下面顺序演进：

```text
v1: BTB + 2-bit BHT
v2: 加 RAS，优化 call/ret
v3: BHT 改 GShare，引入 global history
v4: BTB 从 direct-mapped 改成 set-associative
v5: 支持更复杂的 multi-CFI per fetch block 和更细的 lane mask
```

为了保持可扩展性，PCGen、IFetch 和后端都应该只依赖稳定接口：

```text
PCGen: 只关心 predicted nextPc
IFetch: 只关心 IFetchBlockMeta 和 lane mask
Backend: 只提交 BpuUpdate
BPU: 内部自由替换 BTB/BHT/RAS/GHR 等实现
```

这样第一版实现可以很简单，但后续优化不会要求推翻前端主干结构。

# 后端 v1 设计目标

后端第一版目标不是阻塞式的“处理完一批再处理下一批”，也不是完整乱序处理器。目标定义为：

```text
顺序 dispatch
+ 资源并行执行
+ 结果允许乱序完成
+ ROB 顺序提交
```

这里的“乱序”只发生在完成顺序上，不发生在提交顺序上。架构状态必须始终按程序顺序更新：

```text
GPR/CSR/priv/store/commit event 只在 ROB head 退休时对外可见
```

这样可以在第一版就充分利用 ALU、LSU、MUL、DIV 等执行资源，同时仍然保持精确异常、精确 trap、difftest 对齐和可回滚的分支错误处理。

## 后端流水线视图

推荐第一版后端结构：

```text
Frontend FetchPacket
  -> Decode0/Decode1
  -> Dispatch
       分配 ROB entry
       建立源操作数依赖
       写 scoreboard producer
  -> IssueQueue / IssueSelect
       源操作数 ready
       FU 资源 ready
       选择可发射指令
  -> Execute Cluster
       ALU
       LSU
       MUL
       DIV
       BRU/JMP
       CSR
  -> Writeback
       写 ROB result/done
       wakeup 依赖该 ROB entry 的指令
  -> Commit
       从 ROB head 顺序退休
       更新 GPR/CSR/priv/store/redirect/difftest
```

Fetch 和 decode 仍然按程序顺序提供最多两条指令。Dispatch 也必须保持顺序：如果 slot0 不能进入 ROB，slot1 不能单独越过 slot0 dispatch。

Issue 可以比 dispatch 更灵活：只要源操作数 ready，且对应 FU 空闲，后面的无关指令可以先发射到 ALU/MUL/DIV/LSU。这会带来乱序完成，因此需要 ROB 保存原始程序顺序，并把提交点统一收敛到 ROB head。

## ROB 的职责

ROB 的目的不是实现乱序提交，而是保存程序顺序和提供统一退休点。

ROB entry 至少包含：

```text
valid
done
pc
inst
rawInst
isRVC
instLen

rd
rfWen
result

isLoad
isStore
storeAddr
storeData
storeMask

isBranch
isJump
redirectValid
redirectTarget
bpuUpdate

exceptionValid
exceptionCause
exceptionTval

csrWriteValid
csrWriteAddr
csrWriteData
```

ROB 接收所有执行单元的完成结果：

```text
FU done -> robIdx + result/exception/redirect/store-info
```

ROB 只允许从 head 开始提交：

```text
while head.valid && head.done && commitWidth not full:
  commit head
  pop head
```

如果 head 发生异常、trap、mret 或分支错误，ROB 负责让 commit 阶段发出 redirect，并清空所有 younger 指令。older 指令已经提交，younger 指令还没有改变架构状态，因此可以保持精确异常。

## Scoreboard 的职责

依赖识别不应该主要放在 ROB 中。ROB 记录顺序和结果；scoreboard/issue queue 负责判断指令什么时候可以发射。

第一版 scoreboard 可以采用 ROB tag 作为 producer：

```text
busy[32]
producer[32] = robIdx
```

Dispatch 时：

```text
src ready = !busy[rs]
src tag   = producer[rs] when busy[rs]

if rd != 0 && rfWen:
  busy[rd] := true
  producer[rd] := allocatedRobIdx
```

Writeback 时：

```text
broadcast robIdx + result
IssueQueue 中等待该 robIdx 的源操作数被唤醒
ROB[robIdx].done := true
ROB[robIdx].result := result
```

Commit 时清 scoreboard 需要检查 producer 是否仍然指向当前提交的 ROB entry：

```text
if commit.rfWen && producer[commit.rd] === commit.robIdx:
  busy[commit.rd] := false
```

这个检查很重要。否则下面这种 WAW 会错误清 busy：

```text
inst0: add x1, ...
inst1: add x1, ...
```

当 inst0 提交时，如果 `producer[x1]` 已经被 inst1 改写，就不能清掉 x1 的 busy。

## Issue Queue 的职责

Issue queue 保存已经 dispatch 但还没有发射的指令。每条 entry 至少需要：

```text
valid
robIdx
pc
inst
fuType
fuOp

src1Ready
src1Value
src1Tag
src2Ready
src2Value
src2Tag

rd
rfWen
imm
memSize
memUnsigned
```

收到 writeback broadcast 时，如果某个源操作数等待该 `robIdx`，就填入 result 并置 ready。

第一版可以先做保守选择策略：

```text
每个周期最多向每类 FU 发射 1 条 ready 指令
ALU/MUL/DIV/LSU 各自独立仲裁
同一条指令只能被一个 FU 接收
```

如果暂时不想做复杂 issue queue，可以先做一个很小的队列，例如 4 到 8 项。只要它允许无关 ALU 在 DIV/LSU 等待时继续发射，就已经达成 v1 的资源利用目标。

## 执行单元边界

所有执行单元都应使用统一完成接口：

```text
valid
robIdx
result
exceptionValid
exceptionCause
exceptionTval
redirectValid
redirectTarget
```

不同 FU 的语义：

- ALU：通常 1-cycle，完成后写 ROB result。
- MUL：可多周期，完成后写 ROB result。
- DIV：多周期，完成后写 ROB result。
- BRU/JMP：计算真实 next PC，发现 mispredict 时写 redirect 信息到 ROB。
- CSR：CSR 指令可以先计算读旧值和待写值，但 CSR 真正写入建议放到 commit。
- LSU：load 可以执行阶段发读请求，store 不能执行阶段直接写内存。

## LSU 和内存副作用

第一版 LSU 允许 load/store 地址早计算，但 store 对外写内存必须在 commit 时发生。

load 流程：

```text
Issue load
  -> LSU 计算 addr
  -> 发 dmem read
  -> resp 返回
  -> 写 ROB result/done 或 exception
  -> wakeup dependent instructions
  -> commit 时写 GPR
```

store 流程：

```text
Issue store
  -> LSU 计算 addr/data/mask
  -> 写 ROB storeAddr/storeData/storeMask/done
  -> 不立即写 dmem
  -> store 到 ROB head commit
  -> commit 阶段发 dmem write
  -> write resp 完成后该 store 才算退休
```

这样做的原因是 store 是不可轻易回滚的外部副作用。如果 store 在 execute 阶段已经写出，而 older 指令后来产生异常，就无法保持精确异常。

第一版可以让 commit 在 store write resp 返回前阻塞 ROB head。这样简单、正确，虽然性能一般。以后再引入 store buffer，让 committed store 离开 ROB 后异步写内存。

## Load/Store 依赖的第一版策略

为了降低第一版复杂度，建议先采用保守内存依赖策略：

```text
load 可以在没有 older unresolved store 时发射
store 可以早算地址/数据，但必须等 commit 才写内存
如果存在 older store 地址未知，则 younger load 不发射
如果存在 older store 地址已知但未提交，第一版也可以保守阻塞 younger load
```

这个策略会牺牲一些性能，但能避免第一版实现复杂的 store-to-load forwarding 和 memory dependence prediction。

更激进的实现可以在后续加入：

```text
StoreQueue
LoadQueue
store-to-load forwarding
load violation replay
```

这些不是后端 v1 的必需目标。

## Commit 的职责

Commit 是唯一改变架构状态的地方。

每个周期最多提交 `commitWidth` 条。第一版可以等于 `issueWidth = 2`，但必须遵守：

```text
slot0/head 先提交
slot0/head 未 done 时 slot1 不能提交
slot0/head 发生异常或 redirect 时 slot1 不能提交
```

Commit 执行动作：

```text
写 GPR
写 CSR
更新 priv
提交 store 写内存
发 bpuUpdate
发 redirect
发 difftest commit event
更新 minstret
释放 ROB entry
释放 scoreboard producer
```

Commit 对 difftest 很关键。仿真侧 reference 每次执行 1 条后会比较 DUT 的架构状态，因此 DUT 的 `commit event`、GPR/CSR/priv 可见状态必须都来自同一个退休边界。

## 分支和异常处理

BRU/JMP 可以在 execute 阶段计算真实跳转目标，但不要立即让 younger 指令提交。推荐流程：

```text
branch execute:
  if mispredict:
    ROB[robIdx].redirectValid := true
    ROB[robIdx].redirectTarget := realTarget
  ROB[robIdx].done := true

commit branch:
  if redirectValid:
    flush frontend
    flush issue queue
    flush younger ROB entries
    clear scoreboard entries produced by younger instructions
```

异常同理：

```text
execute detects exception:
  ROB[robIdx].exceptionValid := true
  ROB[robIdx].exceptionCause := cause
  ROB[robIdx].exceptionTval := tval
  ROB[robIdx].done := true

commit exception:
  update CSR trap state
  redirect to trap vector
  flush younger instructions
```

这保证异常精确：异常指令之前的指令都已经提交，异常指令之后的指令都没有提交。

## v1 实现顺序

推荐按下面顺序推进：

1. 定义 ROB、IssueQueue、Scoreboard、Writeback、Commit 的 bundle。
2. 实现 ROB 分配、完成写回、head 顺序提交。
3. 用 ALU 单执行单元打通 `dispatch -> issue -> execute -> writeback -> commit`。
4. 接入 scoreboard，支持 RAW/WAW producer 跟踪和 wakeup。
5. 打开双路 decode/dispatch，并处理 slot0/slot1 内部依赖。
6. 加入第二个 ALU 或独立 BRU，验证多个 FU 并行写回 ROB。
7. 加入 LSU load，load 返回后写 ROB，commit 写 GPR。
8. 加入 store：execute 生成 store info，commit 才真正写 dmem。
9. 加入 MUL/DIV 多周期 FU，验证后续无关 ALU 能继续执行但不能越过提交。
10. 接入 CSR/trap/branch redirect 的 commit 侧处理。

每一步都保持一个不变式：

```text
架构状态只在 commit 改变，commit 只从 ROB head 顺序发生。
```
