# AXI4 入门导读（写给只会"用过的通道"的你）

> 目的：把"总线 = 通信协议"这个认知补全成**分层模型**，然后告诉你**手册该读哪几章、哪些可以先跳过**，
> 最后把五条通道的**时序关系**讲清楚。读完这一份，`interfaces.md` / `timing.md` 里的规则你就能自己推出来了。

## 1. 先纠正一个认知：总线不只是"协议"

你说"总线就是通信协议"——这句话只对了 1/6。一条总线（互连）由下面几层叠起来，**协议只是第 1 层**：

| 层 | 回答什么问题 | 本项目的例子 |
| --- | --- | --- |
| ① 协议（protocol） | 线上怎么握手、字段什么含义 | AXI4：VALID/READY、len/size/burst、四种响应码 |
| ② 拓扑（topology） | 谁连谁，1 对 1 还是 1 对多还是多对多 | 现在：1 个 master（核）→ N 个 slave；`u_demux` 就是拓扑 |
| ③ 地址译码（address decode） | 每个地址归谁管 | `vsoc_pkg` 的地址表 + 兜底从设备 |
| ④ 仲裁（arbitration） | 多个 master 同时抢同一个 slave 时谁赢 | **现在不需要**（只有一个 master）；将来加 DMA 才需要 |
| ⑤ 缓冲/流水（buffering / pipelining） | 怎么解耦时序、怎么提高频率、怎么隐藏延迟 | `axi4_delay`；寄存器切片（register slice） |
| ⑥ 顺序与错误模型（ordering / error） | 哪些事务必须保序；出错了怎么办 | 同 ID 保序；DECERR/SLVERR；投机访存不挂死 |

**为什么要这么分**：你现在的痛点（"访问非法地址会挂死"）**不是协议问题**（协议里明明有 DECERR），而是**⑥ 错误模型 + ③ 译码**没做。分清层次以后，就不会再出现"我要优化总线，那就把协议改好一点"这种错位的判断。

顺带一句：在 AMBA 家族里，

| 协议 | 定位 | 你要不要学 |
| --- | --- | --- |
| **AXI4** | 高性能、有地址、5 通道、支持 burst 和乱序 | ✅ 就是它 |
| AXI4-Lite | AXI4 的阉割版：无 burst、每笔 1 拍 | 以后接 GPIO/SPI 简单外设时看一眼 |
| AXI4-Stream | **没有地址**，纯数据流（视频/DSP/网络） | 完全不用，是另一个规范（IHI 0051） |
| AHB / APB | 老一代 / 低带宽外设总线 | 不用 |
| ACE / CHI | 带 cache 一致性 | 不用（多核才要） |

## 2. 五条通道：你全都会用，不是只用一部分

你的核当前**已经在用全部 5 条通道**（读 2 条 + 写 3 条），只是你平时只盯着 AR/R 看。新 SoC 里五条全部要写对。

| 通道 | 谁产生 | 携带 | 生命周期 |
| --- | --- | --- | --- |
| **AW** | master | `awaddr` `awid` `awlen` `awsize` `awburst` | 握手 1 次即结束 |
| **W** | master | `wdata` `wstrb` `wlast` | `len+1` 拍，最后一拍 `wlast=1` |
| **B** | slave | `bresp` `bid` | 1 拍 |
| **AR** | master | `araddr` `arid` `arlen` `arsize` `arburst` | 握手 1 次即结束 |
| **R** | slave | `rdata` `rresp` `rlast` | `len+1` 拍，最后一拍 `rlast=1`（读错误可以提前结束） |

外加两个**全局信号**：

- `ACLK`：时钟。AXI 是**同步**协议，所有信号都在时钟沿采样。
- `ARESETn`：**低有效**、异步断言/同步释放的复位。
  ⚠️ 本项目用的是**高有效同步复位** `reset`（因为核就是这么定义的）。这是**内部约定**，不是 AXI 的规定。将来若直接挂别人的 AXI IP，需要在这里做一次转换（`aresetn = ~reset` 这种极性转换还不够，还要处理释放同步）。

**一条重要的对称性**：五个通道各自独立握手，**不存在"总线的 ready"**这种东西。所以你的从设备里每一路都要自己算自己的 `*ready`。

## 3. 通道之间的时序关系（核心）

### 3.1 依赖图

```
写事务：  AW ──┐
               ├──► [slave 收完地址 + 收完所有 W beats] ──► B      （单拍）
          W  ──┘

读事务：  AR ──────► [slave 拿到地址] ──► R R R ... R              （len+1 拍）

两条事务之间：没有关系。B 和 R 可以同时在飞。
```

**只有四条依赖，记住它们就够了：**

| # | 依赖 | 说明 |
| --- | --- | --- |
| D1 | AW 和 W 之间**没有**依赖 | 谁先到都合法；从设备不能要求"同拍" |
| D2 | B 必须在"AW 已握手"**且**"最后一个 W beat 已握手"之后 | 从设备不能提前回 B |
| D3 | R 必须在"AR 已握手"之后 | 一拍都不能提前 |
| D4 | B 与 R 完全独立 | 读写可以同时进行（你的核现在没做到，见 `timing.md` §3） |

### 3.2 VALID/READY 规则（手册第 3 章的全部精华）

对每条通道、每一侧，只有三条：

```
R1  VALID 不得依赖 READY。          ← 99% 的死锁都出在这条
R2  VALID 拉起后，握手前不得落下。
R3  VALID 拉起后，握手前 payload 不得变化。
```

从这三条能推出一堆实践结论：

- **READY 可以依赖 VALID**（`ready := f(valid)`），反过来不行。所以"组合逻辑译码地址 → 选中 slave 的 ready → 送给 master"是合法且常见的（你的 `axi4_demux` 就这么干）。
- ❌ 绝对不能写成 `assign rvalid = (state==READ) && rready;` —— 这就是旧 `npc.v` 里 `axi_memory` 的写法，它让从设备的 VALID 依赖 master 的 READY，一旦 master 因为别的原因暂时不 ready，两边就互相等。
- 判据：**"握手的唯一标志是 `valid && ready` 同拍为 1"**；`valid` 和 `ready` 单独出现都不表示任何事情在发生。

### 3.3 六个必须能画出来的时序图

**S1 最简读（你的核现在的样子：AR 一拍，R 四拍）**
```
cycle   : T0   T1   T2   T3   T4
arvalid : 1    -    -    -    -
arready : 1    -    -    -    -
araddr  : A
rvalid  : 0    1    1    1    1
rready  : 0    1    1    1    1
rdata   : x    D0   D1   D2   D3
rlast   : x    0    0    0    1
```

**S2 从设备慢：rvalid 晚来（加上延迟注入后的样子）**
```
cycle   : T0   T1   T2   T3   T4
arvalid : 1
arready : 1
rvalid  : 0    0    0    1    1
rready  : 1    1    1    1    1     ← master 一直 ready 地等
```
推论：**master 必须能无限期地等 R**，所以 master 的 `rready` 不能依赖"我猜你快好了"。延迟注入（`axi4_delay`）就靠这个性质成立。

**S3 master 慢：rready 晚来，rvalid 保持**
```
cycle   : T0   T1   T2   T3
rvalid  : 1    1    1    -
rready  : 0    0    1    -
rdata   : D0   D0   D0   -      ← 数据保持不变，直到握手
```
推论：从设备**不能**因为 `rready=0` 就把 `rvalid` 落下或换数据（R2/R3）。

**S4 单笔写（AW/W 同拍，你的核的写法）**
```
cycle   : T0   T1   T2   T3
awvalid : 1
awready : 1
wvalid  : 1    1    -
wready  : 1    1    -
wdata   : D0   D1
wlast   : 0    1
bvalid  : 0    0    1
bresp   : -    -    0(OKAY)
```

**S5 AW 先到、W 后到**（合法）
```
cycle   : T0   T1   T2
awvalid : 1    -    -
awready : 1    -    -
wvalid  : 0    0    1
wready  : 1    1    1
```

**S6 W 先到、AW 后到**（**也合法**，从设备必须不卡）
```
cycle   : T0   T1   T2   T3
awvalid : 0    0    1    -
awready : 1    1    1    -      ← 从设备一直 ready 等 AW
wvalid  : 1    1    1    -
wready  : 0    0    1    -      ← 从设备可以 back-pressure W，等 AW 到了再放行
```
**这就是你必须写对新从设备的理由**：旧 `axi_memory` 在 `IDLE` 里要求 `awvalid && wvalid` 同拍才肯走状态机，遇到 S5 就死。写从设备时要么缓冲先到的那个，要么像上图那样 back-pressure。
（手册细节：AW/W 顺序规则见 **Ch2 写数据通道 / Ch3 通道握手** 的原文，以手册为准。）

**S7 读 DECERR（错误响应）**
```
cycle   : T0   T1
arvalid : 1
arready : 1
rvalid  : 0    1
rresp   : x    3 (DECERR)
rlast   : x    1        ← 错误响应自带 rlast，可以提前终止 burst
rdata   : x    0        ← 内容无意义
```

**S8 写 DECERR（必须收完全部 W beats 再回 B）**
```
cycle   : T0   T1   T2
awvalid : 1
awready : 1              ← 地址非法也要先把 AW 收下
wvalid  : 1    1    -
wready  : 1    1    -    ← 全部 W beats 都要收完，一个都不能漏
wlast   : 0    1    -
bvalid  : 0    0    1
bresp   : -    -    3 (DECERR)
```

## 4. 手册怎么读：读哪本、读哪几章

### 4.1 读哪本

- **《AMBA AXI and ACE Protocol Specification》ARM IHI 0022**（ARM 官网 developer.arm.com 免费下载，需注册）。
- AXI4 是这份规范里的一节，同时还有 AXI5/ACE 的内容。**只看 AXI4 的部分**，AXI5/ACE 的特性（QoS、Poison、Atomic、DVM、coherency）全部跳过。
- 注意术语版本差异：新版本用 **manager / subordinate** 替代 master / slave，别被吓到，是同一件事。

### 4.2 阅读清单

| 章节（按名称找，编号随版本略有差异） | 怎么读 | 对应你要写的东西 |
| --- | --- | --- |
| **Ch1 Introduction**（架构总览、术语、通道概念） | 精读 | 建立心智模型；把本文 §2 和它对上 |
| **Ch2 Signal Descriptions** | **只精读你用到的那 25 根**（列在 `interfaces.md` §2），其余（lock/cache/prot/qos/region/user、low-power Q 通道）扫一眼知道存在即可 | `vsoc_axi_if` |
| **Ch3 Channel Handshakes**（VALID/READY 依赖、通道间关系） | **读三遍**。这是全篇最重要的一章 | 所有模块的时序基础；`timing.md` §2 |
| **Ch4 Addressing**（地址结构、burst 类型、对齐、4KB 边界、地址译码） | 精读 | `axi4_demux` 的译码；`axi4_ram_dpi` 的 beat 地址计算 |
| **Ch5 Transaction Attributes**（AxCACHE/AxPROT/AxREGION/AxQOS） | 略读，知道每个字段管什么 | 现在不用（你的核没这些信号）；将来做 cache/权限再看 |
| **Ch6 Transaction Identifiers / Ordering** | 精读"ordering model"那一节 | 现在只需"ID 原样回传"；P4 多 outstanding 时是核心 |
| **Ch7 Atomic / Exclusive Accesses** | **跳过**（你的核的 `AxiPort` 连 `awlock` 都没有，AMO/LR-SC 都在 cache 里做） | — |
| **Ch8 Response Signalling**（OKAY/EXOKAY/SLVERR/DECERR、错误规则） | 精读 | DECERR 通路；`timing.md` §6 |
| **Interconnect / Additional Functions 一章**（Address decoding、Data routing、**Register slices**） | 精读 | `axi4_demux` + `axi4_delay`（这章就是"总线"的定义） |
| **Low-power interface（Q 通道）** | 跳过 | — |
| **AXI4-Lite 一节** | 跳过 | 以后接 GPIO/SPI 再看 |
| **附录：事务示例（transaction examples）** | 精读，最好自己画一遍 | 最好的时序练习 |

### 4.3 三遍读 Ch3 的方法

1. 第一遍：只记三条规则（R1/R2/R3），然后自己画 S1–S6。
2. 第二遍：看它怎么定义"通道之间的依赖"，回答："为什么 B 不能早于最后一个 W beat？"（提示：从设备需要知道整笔写是否成功，而写成功的前提是数据都到齐了）。
3. 第三遍：带着你的 `axi4_demux` 去读，问自己"我这根 ready 是从哪儿来的？它会不会组合地依赖上游 valid？"

## 5. 手册概念 ↔ 仓库里的代码（照着抄思路，不要抄代码）

`ysyxSoC/rocket-chip/src/main/scala/amba/axi4/` 下有一整套工业级 AXI4 实现，正好和你的任务一一对应：

| 概念 | rocket-chip 文件 | 你要写的模块 |
| --- | --- | --- |
| 1→N 地址译码 + 响应选路 + **W 通道按 AW 的路由转发** | `Xbar.scala`（搜注释 `Record who won AW arbitration to select W`） | `axi4_demux` |
| 寄存器切片 / skid 缓冲 | `Buffer.scala` | `axi4_delay` 参数 > 0 的分支 |
| 延迟注入（看它怎么保证 valid 不落下） | `Delayer.scala`（`hold` 寄存器那几行） | `axi4_delay` |
| burst 拆分 / 4KB 边界处理 | `Fragmenter.scala` | 只写断言，不实现 |
| 协议常量与字段位宽 | `Protocol.scala` | `vsoc_pkg` 的 `RESP_*` / `BURST_*` |
| 一个合规的从设备存储器 | `SRAM.scala` | `axi4_ram_dpi` |
| ID 交织与保序恢复 | `Deinterleaver.scala` | P4 之后（多 outstanding） |
| ID 位宽压缩 | `IdIndexer.scala` | 将来多 master 时 |
| 寄存器访问外设 | `RegisterRouter.scala` | `axi4_uart` 的思路 |

注意：rocket-chip 用的是 diplomacy + `IrrevocableIO`，**不要照抄结构**，只抄"某个问题它怎么解"。

## 6. 常见误解清单（逐条自查）

| # | 误解 | 事实 |
| --- | --- | --- |
| 1 | "总线就是通信协议" | 协议只是 6 层里的第 1 层（见 §1） |
| 2 | "`len` 是字节数" | `len` 是 **beat 数 - 1** |
| 3 | "`size` 是字节数" | `size` 是 **log2(字节数)**；`size=2` 才是 4 字节 |
| 4 | "rvalid 要等 rready" | 反了。rvalid 不得依赖任何 master 信号 |
| 5 | "AW 和 W 必须同拍" | 两者无依赖，谁先都合法（S5/S6） |
| 6 | "没被任何从设备认领 = 没有响应" | 协议要求**每个事务都有响应**，必须挂兜底从设备回 DECERR |
| 7 | "报了错的写可以直接回 B" | 必须先把 `len+1` 个 W beat 全收完（S8），否则 master 的 W 通道永久卡住 |
| 8 | "burst 可以随便跨 4KB" | 不允许跨 4 KB；响应的 4 KB 边界是硬规定 |
| 9 | "读错误也要凑满 len+1 拍" | 可以提前终止，但至少一拍且该拍 `rlast=1` |
| 10 | "窄传输（size<总线宽度）时数据随便放 lane" | 数据必须出现在**地址对应的 lane**上 |
| 11 | "握手可以晚一拍/早一拍" | 唯一前进点是 `valid && ready` **同拍** |
| 12 | "`bresp`/`rresp` 只有 OKAY" | 四种码，DECERR 是"没人认领"，SLVERR 是"认领了但访问方式不合法" |

## 7. 自测题（能全答上就可以开始写 RTL）

1. `awlen = 3`、`awsize = 2`，这一笔写多少个字节？在总线上占几拍？
2. 为什么 `assign rvalid = rready && data_ready;` 会导致死锁？
3. 从设备在什么条件下才可以拉高 `bvalid`？
4. 一笔读到未映射地址的 AR，从设备应该回几拍 R？`rlast` 和 `rresp` 分别是什么？
5. 一笔到未映射地址的写，如果不接收 W beats 直接回 B，会发生什么？
6. 为什么"给 R 通道加 10 拍延迟"不会破坏协议，但"给 R 通道少发一拍"会破坏协议？
7. 你的 `axi4_demux` 里，`s_axi.rready` 应该送给几个从设备？
8. 如果两个从设备同时拉高 `rvalid`，而 `s_axi.rready=1`，会发生什么？（答：数据被两个设备同时消费 → 必须保证只有一个设备被选中）

## 8. 下一步

- 先读 **Ch3 + Ch4 + Ch8**，画会 §3.3 的 8 张图；
- 然后照着 `modules.md` 从 `axi4_ram_dpi`（最简单、最容易测）开始写；
- 写完立刻挂 `axi4_protocol_checker`，别等挂死了才回头查。
