# 时序与握手规则（v0.1）

> 这一章是**规则**，不是建议。任何一条被破坏都会导致整机挂死，而不是"少几个 cycle"。

## 1. 时钟与复位

```
clock  ─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─┐ ┌─
        └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘ └─┘
reset  ─────────────────┐
                        └────────────────────
        ↑ 拉高 N 拍（host 控制，当前 30）    ↑ 释放后第一个时钟沿开始工作
```

| 项 | 规则 |
| --- | --- |
| 时钟 | 只有 `clock`，全设计单时钟域；不允许 `negedge`、不允许第二个时钟、不允许门控时钟 |
| 复位 | `reset` 高有效、**同步**；`always_ff @(posedge clk) if (rst)` |
| 复位期间 | 所有 `*valid = 0`；从设备的 `*ready` 建议 0（不是必须，但避免给核"假握手"） |
| 复位释放 | 核的 `arvalid`/`awvalid` 可能在复位释放后立刻有效；从设备必须在**释放后的第一个时钟沿**就能正常握手 |
| payload | 不需要复位（面积/复位树都是浪费），但**valid 为 1 时 payload 必须稳定** |
| `initial` | 禁止（DPI 模型除外 + `ifndef SYNTHESIS`） |

## 2. 五条握手铁律

对**每一条**通道（AW/W/B/AR/R），两侧都要满足：

| # | 规则 | 谁必须遵守 |
| --- | --- | --- |
| **R1** | **VALID 不得依赖 READY**。源端只能在"本轮握手完成"后决定是否落下 VALID，不能因为"对面 READY=0"就撤销或拉起 VALID | 双方（master 和 slave 都要） |
| **R2** | VALID 拉起后、在握手（`valid && ready`）发生前，**不得落下** | 双方 |
| **R3** | VALID 拉起后、握手发生前，**payload 不得变化** | 双方 |
| **R4** | READY 可以等 VALID（`ready := f(valid)` 合法），但 READY 一旦拉起，不必等握手就可以落下（或保持） | 双方 |
| **R5** | **一旦接受了一笔事务，就必须把它做完**：接受 AR 就必须给出全 `len+1` 拍 R；接受 AW/W 就必须给出 B。中途"忘了"= 永久挂死 | slave |

补充（容易被忽略的三条）：

- **R6**：一次 burst 的拍数由 AW/AR 的 `len+1` 决定，`wlast`/`rlast` 必须**恰好**出现在第 `len+1` 拍，不能早不能晚。
- **R7**：一个 burst 不得跨越 4 KB 地址边界（AXI 硬性规定，从设备可以不支持）。核当前的 burst 都是"cache line 对齐、≤ 64 B"，天然满足；**从设备只做断言，不修**。
- **R8**：写事务即使要回错误，也**必须收完全部 W beats** 再回 B。

## 3. 通道独立性与合法并发

- **五条通道互相独立**：AW 与 W 谁先谁后都合法；B 与 R 完全无关；AR 与 AW 可以在同一拍出现。
- **唯一的顺序约束**来自 master 自己的语义：一笔读 = AR→R；一笔写 = AW/W→B。不同事务之间如果用了相同的 ID，则响应必须按序返回；不同 ID 之间无顺序要求。

### 核当前的并发能力（重要事实）

`AxiMaster` 的 `requestWindow = (state === SIdle || responseComplete) && transferState === transferIdle`，也就是说：

- **同一时刻最多 1 笔读 + 0 笔写，或 0 笔读 + 1 笔写**：读写之间也不并发；
- 单笔 outstanding（`AxiXbar` 的 `readRouteValid`/`writeRouteValid` 各 1 bit）。

所以 SoC 侧 M0–M3 只需要"每方向 1 bit 路由记录"。但**接口按标准 AXI4 定义**（带 `id`、带 `len`），这样 P4 把核侧放开成多笔时，SoC 不用重写，只把 1 bit 记录换成 ID 表。

### 反过来，SoC 不能假设 master 的行为

从设备**不允许**依赖以下任何一条（它们都不是 AXI 协议的一部分）：

- ❌ "AW 和 W 一定同拍到达"
- ❌ "AR 一定在 R 之前、且中间不会插别的 AR"
- ❌ "`awlen` 一定 ≤ 某个值"
- ❌ "`awsize` 一定是 2（4 字节）"

当前核恰好都满足，但把这些假设写进从设备 = 埋雷。

## 4. 读事务时序（4 beat INCR burst）

```
cycle   : T0   T1   T2   T3   T4   T5
arvalid : 1    -    -    -    -    -
arready : 1    -    -    -    -    -
araddr  : A    -    -    -    -    -
rvalid  : 0    1    1    1    1    0
rready  : 0    1    0    1    1    -
rdata   : x    D0   D0   D1   D2   -
rlast   : x    0    0    0    1    -
```

要点：

- **T1–T2：`rvalid=1` 但 `rready=0`** —— 从设备保持数据不変，等 master 取走。这是 R1 的正当行为，**不是** bug。反向（`rvalid` 因为 `rready=0` 而落下）才是 bug。
- 从设备可以在 AR 握手后的**下一拍**就返回第一拍数据（延迟 1），也可以等 N 拍（见 §7）。
- `rready` 只在被选中的从设备上为 1（`axi4_demux` 的责任）。

## 5. 写事务时序（AW 与 W 独立）

```
cycle   : T0   T1   T2   T3   T4
awvalid : 1    -    -    -    -
awready : 1    -    -    -    -
wvalid  : 1    1    1    1    -
wready  : 1    1    0    1    -      // T2 从设备忙
wdata   : D0   D1   D1   D2   -
wlast   : 0    0    0    1    -
bvalid  : 0    0    0    0    1
bresp   : -    -    -    -    0(OKAY)
```

要点：

- AW 和 W **不需要同拍**。合法写法有二：① 先收 W 进门（skid 缓冲）等 AW；② back-pressure W 直到 AW 的记录存在。
  **非法**写法：`awready := awvalid && wvalid`（老 `axi_memory` 的写法，一旦 master 先给 AW 就死）。
- 写响应只有**一拍**，`bid` 必须回传 `awid`。
- 写数据 beat 计数必须由 AW 的 `awlen` 决定；如果 W 的拍数与 `awlen+1` 不符，是 master 违约（断言报警，不要尝试"自愈"）。

## 6. 错误响应时序

### 读错误（`axi4_ram_dpi` 越界、`axi4_default_slave` 未映射地址）

```
cycle   : T0   T1
arvalid : 1    -
arready : 1    -
rvalid  : 0    1
rresp   : x    3 (DECERR)
rlast   : x    1        // 错误响应必须自带 rlast=1，提前终止 burst
```

- 读错误可以**提前终止** burst（不必凑满 `len+1` 拍），但必须**至少返回一拍**且该拍 `rlast=1`。
- `rdata` 内容无意义（填 0）。

### 写错误

```
cycle   : T0   T1   T2   T3
awvalid : 1    -    -    -
awready : 1    -    -    -      // 即使地址非法也要接受 AW
wvalid  : 1    1    1    -
wready  : 1    1    1    -      // 必须收完全部 W beats
bvalid  : 0    0    0    1
bresp   : -    -    -    3 (DECERR)
```

### 响应码语义（谁的错谁负责）

| 码 | 含义 | 在本设计里谁产生 |
| --- | --- | --- |
| `OKAY` (0) | 正常 | 所有正常的 pmem / uart 访问 |
| `EXOKAY` (1) | 独占访问成功 | **不用**（没有 exclusive 支持） |
| `SLVERR` (2) | 地址合法但访问方式错（非法 size / WRAP / 越界但同页） | `axi4_ram_dpi`、`axi4_uart` |
| `DECERR` (3) | 地址没有被任何从设备认领 | `axi4_default_slave`、`axi4_ram_dpi` 的越界判断 |

### 核侧怎么消费错误（已经实现，不用改）

`rresp/bresp != OKAY` → `AxiDataAccess` 置 `DataMemResp.fault` → 经 `AxiReadRefill`/DCache 的 `mshrFault` → LSU 产生 `loadAccessFault` / `storeAccessFault` 异常。DCache 对 fault 的 refill **不会写进 cache**（`mshrFault` 参与 refill 完成条件）。所以：**SoC 只要诚实回报响应码，投机访存打到非法地址就会变成一次精确异常，而不是挂死** —— 这正是这次改造的核心收益。

## 7. 时延模型

**两个独立旋钮，不要混为一谈：**

| 旋钮 | 含义 | 典型值 | 影响什么 |
| --- | --- | --- | --- |
| **latency（首拍延迟）** | 发出请求 → 收到第一拍响应之间的 cycle 数 | {0, 4, 16, 40, 100} | 单笔访存的等待时间；乱序核能否用其他指令掩盖 |
| **throughput（每拍间隔）** | 相邻两拍响应之间的 cycle 数 | 0 = 每拍 1 个 beat | 带宽；突发长度 × 间隔 = 一次 cache line 填充的时间 |

实现方式（见 `modules.md` §8）：通道级寄存器级联 + 参数为 0 时 `generate` 成直通。**延迟只加在 `u_demux` → 从设备之间**，不改变协议语义。

**为什么"只加延迟"是安全的**：因为 AXI 的所有通道都是握手协议，任何一拍都可以被 back-pressure 无限期延长 —— 只要不加环、不减少拍数，系统就只是变慢，不会挂死。**这一条就是"时延可配置"能成立的根本原因。**

**校准建议**：

1. 固定 `PMEM_R_LATENCY = 0`，扫 `AR_LATENCY ∈ {0,4,16,40,100}`，记录 IPC 与未提交周期数 → 得到"访存延迟敏感度曲线"。
2. 固定 `AR_LATENCY = 40`，扫 `R_LATENCY ∈ {0,1,4}` 的每拍间隔 → 得到"带宽敏感度"。
3. 敏感度曲线的斜率 ≈ 未被隐藏的访存停顿占比；斜率越大，越说明 MSHR/load 队列（MLP）不足。
4. 曲线形状决定 P4/P5 的优化顺序。

## 8. 死锁剖析：旧模型为什么挂死

三个独立缺陷叠加，任何一个都足以让整机永久沉默：

| # | 缺陷 | 位置 | 后果 |
| --- | --- | --- | --- |
| D1 | `rvalid` 依赖 `rready`：`assign io_rvalid = (state == READ) && read_valid;`，而 `read_valid` 只在 `io_rready` 有效时才被拉起 | 旧 `axi_memory` | 严格说这是 R1 违规；更致命的是下面两条 |
| D2 | 未映射地址没有任何从设备 → 没有响应；且 `IDLE` 状态需要 `awvalid && wvalid` 同拍才肯前进 | 旧 `axi_memory` 状态机 | 一旦有一笔访问落在未映射地址，状态机原地打转，`rready` 恒 0 → host 侧 DPI 永不被调用 → 核永久等待 |
| D3 | DCache 的 MSHR 索引 bug（`OHToUInt` 对 multi-hot 向量按位或）导致新 miss 覆盖在飞的 MSHR，refill 响应失去 owner | 已在 `core/mem/DCache.scala` 修复 | 表现为 `REACH MAX NO COMMIT CYCLES` |

**新设计用五条规则封死同类问题**：

1. 每个地址都必须有人认领（`default_slave` 兜底），**"没人认领" ≠ "没有响应"**。
2. 每个合法的 `valid` 都必须在有限拍内被响应（活性断言，见 §9）。
3. 报错的写事务也必须吞完 W beats。
4. `*valid` 不得组合依赖 `*ready`。
5. 每个从设备的状态只由自己决定（不允许"因为另一个从设备忙所以我不响应"）。

**排查手册**（挂死时按顺序看）：

1. 看是否所有 `*valid` 都停了、`*ready` 卡在哪一条通道 → 定位到是哪个从设备；
2. 用协议检查器的"事务超时"断言看是哪一笔 AR/AW 没有响应；
3. 检查 `rvalid` 是否曾经依赖 `rready`；
4. 检查是否有一笔 W 的 beat 数与 `awlen+1` 不符（导致状态机等不到 `wlast` 或提前出发）；
5. 检查 `axi4_demux` 的 `rready` 是否只送到了被选中的从设备。

## 9. 协议检查器断言清单

`sim/axi4_protocol_checker.sv`（`vsoc_axi_if.monitor`，默认开启）：

| # | 断言 | 类型 |
| --- | --- | --- |
| C1 | `valid && !ready` 时 payload 不变 | 安全（R3） |
| C2 | `valid` 在握手前不落下 | 安全（R2） |
| C3 | `wlast` 恰好是第 `awlen+1` 拍 | 安全（R6） |
| C4 | `rlast` 恰好终止读 burst（错误响应允许提前） | 安全（R6） |
| C5 | burst 不跨 4 KB 边界 | 安全（R7） |
| C6 | 请求地址落在**恰好一个**区域内（不含兜底） | 安全（地址表） |
| C7 | `awsize/arsize ≤ $clog2(STRB_W)` | 安全 |
| C8 | 每笔 AR/AW 在 `TIMEOUT` 拍内收到响应 | **活性**（防挂死，最重要） |
| C9 | 读/写期间 `rvalid`/`bvalid` 不得在握手前撤下 | 安全 |
| C10 | `bresp`/`rresp` ∈ {OKAY, SLVERR, DECERR}（EXOKAY 从设备不得使用） | 安全 |
| C11 | 一笔写事务的 W 拍数 == `awlen+1`（即使报错） | 安全（R8） |
| C12 | 复位释放后 N 拍内若有请求，必须能被响应 | 活性 |

> 活性断言用"计数到阈值 + `$error`"实现，**不要**用 `$fatal` 直接终止：先报错定位，再由 host 的 watchdog 决定是否退出。
