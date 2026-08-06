# npc-chisel

`npc-chisel` 是一个用 Chisel 编写 RISC-V 处理器的学习项目。长期目标是完成一个结构清晰、便于扩展的双发射处理器，并最终能够在仿真环境中成功 boot Linux。

项目不是为了追求最小代码量，而是把实现过程中的结构边界、接口语义和关键不变式直接写进代码与文档中。当前主线可以概括为：

```text
双路取指/译码/派发
+ ROB 顺序提交
+ scoreboard 依赖跟踪
+ issue queue 乱序发射
+ 多执行端口写回
```

架构状态只允许在 commit 边界改变。这条规则是后续支持异常、trap、difftest、store 提交和 Linux boot 的基础。

## 流水线可视化

仿真器可以输出 Konata v4 流水线日志。该功能默认关闭：

```bash
./build/verilator-exec --batch --image <program.bin> --konata
./build/verilator-exec --batch --image <program.bin> --konata-path <output.log>
```

`--konata` 默认写入 `run/konata.log`。指令在进入 FetchQueue 时使用 `(prediction.epoch, prediction.sequence, pc)` 建立身份，dispatch 时再绑定 `robIdx`；映射一直保留到 retire 或 flush，因此长时间停留在 ROB 以及 ROB 槽回绕都不会丢失指令。selective recovery 按全局指令序清除 boundary 之后的指令，而不是直接比较环形 ROB 编号。

当前 lane 定义为：

```text
lane 0: FQ -> DC -> IQ -> X-* -> RT
lane 1: ROB-N -> ROB-D
lane 2: SQ-U -> SQ-R / LTQ / ATQ
lane 3: XLAT -> DMQ-*
```

追踪实现保持三层边界：RTL 的 `PipelineTrace.scala` 只产生不反压的语义事件；C++ 只转发固定 `NpcPipelineEvent`；Rust 的 `checker/kanata.rs` 集中负责同拍排序、ID 映射、lane、stage 和 Kanata 文本。修改显示策略只需要改 Rust writer，移动流水阶段通常只需要改一个 RTL 观察器；只有现有事件字段无法表达新语义时才扩展 DPI ABI。

lane 3 的 `DMQ-*` 表示请求已经进入 backend dmem queue，不代表 DCache 内部 MSHR/refill 的完整状态。store retire 后的外部响应也不延长指令行；这些信息继续由 memory performance trace 记录。

## 未来实现

当前双发射主干已经基本接通，但距离可 boot Linux 还需要补齐下面这些部分。

后端执行侧：

- 将 ALU/BRU/JMP 从当前组合完成模型改成统一 latency 的 pipeline FU。
- MUL 当前已拆成固定 2 周期乘法单元；DIV/REM 已拆成独立非流水 FU，内部使用 radix-2 restoring 迭代除法器，RV32 普通路径每次推进 1 个商 bit。
- 加入 CSR FU，但 CSR 真正写入仍应放在 commit。
- 增加 execute-stage redirect，并按 `robIdx` 做 oldest-first redirect 仲裁。
- 完善多 CFI 场景下的 BPU update/redirect 规则。

乱序能力：

- 当前没有 rename，因此双 dispatch 需要保守处理 RAW/WAW/control boundary。
- 后续如果要提升真实 OoO 能力，需要加入 rename、physical register file 和 freelist。
- issue queue 需要继续扩展为按端口能力选择，并支持更多 FU latency 的 wakeup 规则。

内存系统：

- 当前 store 在 commit 侧产生外部写内存副作用，这是正确但保守的第一版。
- 后续需要 StoreQueue/LoadQueue、store-to-load forwarding、load violation replay。
- Linux boot 需要更完整的 AXI/memory map、CSR/trap/interrupt、CLINT/PLIC、timer、privilege 和可能的 MMU 支持。

验证：

- 增加双发射专项测试：ALU+ALU、ALU+LSU、ALU+BRU/JMP、load wait 时 younger ALU 发射。
- 增加 dispatch 组内 RAW/WAW/control boundary 测试。
- 扩展 difftest report，从当前 GPR 逐步加入 CSR/privilege/memory event。

## 当前设计

### 顶层原则

第一版后端目标不是完整乱序处理器，而是：

```text
顺序 dispatch
+ 资源并行执行
+ 结果允许乱序完成
+ ROB 顺序提交
```

也就是说，指令可以因为不同 FU latency 乱序完成，但 GPR、CSR、privilege、store、difftest commit event 只能从 ROB head 顺序对外可见。

### 前端

前端以 fetch block 为基本访问粒度，目标结构是：

```text
PCGen + BPU
  -> ICache request
  -> ICache response
  -> halfword split / RVC expand / predecode
  -> FetchPacket
  -> Backend
```

需要明确区分三个 PC 概念：

- `startPc`：当前 fetch stream 实际开始的 PC。
- `blockAddr`：访问 ICache 使用的对齐 cache block 地址。
- `nextPc`：当前 cache block 之后的顺序取指地址。

当 `fetchBytes = 8` 且 `startPc = 0x80000006` 时：

```text
blockAddr = 0x80000000
nextPc    = 0x80000008
```

因此顺序推进应使用：

```text
blockAddr + fetchBytes
```

而不是：

```text
startPc + fetchBytes
```

ICache 只负责对齐 block 访问和 metadata 透传；splitter 根据 `startPc` 丢弃 block 内旧 halfword，并保持输出 PC 递增。

### BPU 与 Predecode

BPU 应靠近 PCGen 做早预测。predecode 不负责第一次预测，而是负责：

- 展开 RVC，形成统一 32-bit 指令。
- 识别 branch/jal/jalr/call/ret 等控制流类型。
- 校验 fetch block 携带的预测信息。
- 如果 slot0 是 predicted taken 控制流，则 mask 掉 slot1。
- 生成 `FetchInst.predTaken/predNpc/predTarget`，供后端执行结果校验。

BPU 第一版保持简单：

```text
BTB: 小容量 direct-mapped
BHT: 2-bit saturating counter
RAS/GHR/indirect predictor: 暂不实现
```

后端最终提交 BPU update：

```text
pc
cfiType
taken
target
instLen
```

### 后端

当前后端主路径：

```text
Frontend FetchPacket
  -> Decode0/Decode1
  -> Dispatch
       allocate ROB
       query scoreboard
       build IssuePacket
  -> IssueQueue
       wait operands
       select ready FU port
  -> ExecuteBlock / LSU
       IntExeUnit0: ALU
       IntExeUnit1: ALU + BRU + JMP
       LSU: load/store address/data path
  -> Writeback
       ROB done/result
       wakeup dependent IQ entries
  -> Commit
       retire from ROB head, up to 2 instructions
```

`IssueQueue` 现在有多个 int issue port。每个 port 暴露自己的 `IssuePortStatus`，issue select 只有在 entry 的 `FuType` 被该 port 支持时才会 grant。这是借鉴 BOOM `fu_types` 思路后的简化版。

执行端现在拆成：

```text
backend/exu/
  ExuBundle.scala    # ExuRequest / ExuResult
  ExuConfig.scala    # FuPipeConfig / IntExeUnitConfig
  IntExeUnit.scala   # ALU/BRU/JMP route and writeback
  ExecuteBlock.scala # integer execution-unit container
```

当前默认端口：

```text
int port0: ALU only
int port1: ALU + BRU + JMP
mem port : LSU
```

port0 保持 ALU-only，是为了让 oldest-first issue select 下的普通 ALU 不抢占唯一支持 BRU/JMP 的端口。后续如果支持多控制流完成、execute redirect 仲裁和多 BPU update，再把两个 int port 都扩成 ALU/BRU/JMP。

### ROB

ROB 保存程序顺序和统一退休点。执行单元完成时只写 ROB entry：

```text
robIdx
result
storeAddr/storeData/storeMask
redirectValid/redirectTarget
branchTaken/branchTarget
```

commit 只从 head 开始：

```text
while head.valid && head.done && commitWidth not full:
  retire head
```

如果 head 发生 redirect、trap 或异常，commit 阶段负责 flush younger 指令，并让前端重定向。older 指令已经提交，younger 指令还没有改变架构状态，因此可以保持精确异常。

### Scoreboard

第一版 scoreboard 使用 ROB index 作为 producer tag：

```text
busy[32]
producer[32] = robIdx
```

dispatch 时：

```text
src ready = !busy[rs]
src tag   = producer[rs] when busy[rs]

if rd != 0 && rfWen:
  busy[rd] := true
  producer[rd] := allocatedRobIdx
```

commit 清 scoreboard 时必须检查 producer：

```text
if commit.rfWen && producer[commit.rd] === commit.robIdx:
  busy[commit.rd] := false
```

这避免 WAW 情况下 older producer 提交时错误清掉 younger producer。

### Issue Queue

Issue queue 保存已 dispatch、未 issue 的指令。entry 需要保存：

```text
valid
robIdx
fetch pc/inst metadata
fuType/fuOp
src ready/value/tag
rd/rfWen
imm
memSize/memUnsigned
```

writeback broadcast 到达时，如果源操作数等待该 `robIdx`，entry 填入 result 并置 ready。

第一版 issue 策略保持保守：

```text
每个 int issue port 每周期最多发 1 条
mem issue port 每周期最多发 1 条
同一条 entry 只能被一个 port grant
load 在存在 older unresolved store 时阻塞
```

### LSU 和内存副作用

load 可以在 execute 阶段发 dmem read，resp 返回后写 ROB result 并 wakeup 依赖者。

store 不能在 execute 阶段直接写内存。store 的 execute 结果只写入 ROB：

```text
storeAddr
storeData
storeMask
```

当 store 到达 ROB head 并 commit 时，才向 dmem 发 write。commit 可以在 store write response 返回前阻塞，这个方案性能一般，但语义简单且保持精确异常。

### Commit

Commit 是唯一改变架构状态的地方。每周期最多提交 `commitWidth` 条，当前为 2 条，但必须满足：

```text
head 未 done 时 younger 不能提交
head 发生 redirect/trap/exception 时 younger 不能提交
store 必须等外部写内存完成后才退休
```

Commit 负责：

- 写 GPR。
- 后续写 CSR/privilege。
- 提交 store。
- 发 BPU update。
- 发 redirect。
- 产生 difftest commit event。
- 释放 ROB entry。
- 清 scoreboard producer。

### 构建与运行

常用命令：

```bash
mill -i playground.compile
mill -i playground.runMain Elaborate --ysyx-target npc --target-dir ./build/
make run
```

`make run` 会生成 Verilog、构建 Verilator 仿真器，并用 NEMU 做 difftest。
