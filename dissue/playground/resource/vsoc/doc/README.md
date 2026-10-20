# vsoc 设计文档 · 总览

> 状态：**设计阶段（v0.1）**。本文档集只定义**结构、接口、职责、时序契约**，不写 RTL 实现。
> 代码在 `vsoc/rtl/` 下从零重写，旧的 `resource/sim-verilator/verilog/` 将逐步弃用。

## 0. 文档地图

| 文件 | 内容 | 什么时候看 |
| --- | --- | --- |
| `README.md` | 目标、层次、目录、地址映射、数据流、关键决策 | 先看这个 |
| `interfaces.md` | AXI4 信号集、interface/modport、核边界、DPI 契约 | 写接口的时候 |
| `modules.md` | 每个模块的作用/参数/端口/时序行为/不做什么 | 写某个模块前 |
| `timing.md` | 握手铁律、读写事务时序、错误响应、时延模型、断言清单 | 调时序的时候 |

## 1. 目标与非目标

### 目标

1. **唯一顶层 `simtop`**：端口只有 `clock` / `reset`，内部只有两个实例：`u_core` + `u_soc`。
2. 把"CPU ↔ 世界"的全部连接从 `sim-verilator/verilog/npc.v` 里搬出来，变成**协议合规的 AXI4**。
3. **未映射地址必须被响应**（DECERR），而不是悬空 → 投机访存打到非法地址不再挂死整个仿真。
4. 外设最小集：**pmem + uart**，但结构上留好加第三个外设的位置。
5. 访存时延**可配置**（latency/throughput 两类旋钮），当前全部配置为 **0**。
6. 仿真控制（exit / watchdog / wave / 超时）**全部留在 host 侧**（Rust/C++），RTL 里一条都不写。

### 非目标（这一轮明确不做）

- 不做 CDC / 多时钟域 / 时钟门控 / 电源域（见 `deferred.md`）。
- 不做 PLIC / RTC 的外移：它们**留在核内**（`AxiXbar` + `ClintDevice` / `PlicDevice`），将来要搬再说。
- 不做 cache 一致性、不做 DMA、不做多 master。
- 不做综合/时序收敛：当前只服务仿真性能。
- 不做 RTL 内的 exit/watchdog/wave：`$finish`、`$dumpvars`、超时判定都不属于 `sim_top`。

### 一个必须先说清楚的前提（重要）

"现在我只有一条分支在飞"这件事，**根因不在总线**。核侧有两处保守策略：

- `DataMemExternalization.hasOlderUnresolvedCfi`：只要还有更老的 CFI 未 resolve，`squashable` 的访存就**不允许发 AXI**。
- `IssueQueue.cfiBlocked`：CFI 之间强制按序执行。

总线改造（本设计）是**解除这些限制的前置条件**，不是替代品：只要"响应可能永远不回来"或"错误无法表达"，核就没有办法安全地丢弃/取消一笔投机访存，所以只能靠"不许发"来保命。总线补上 DECERR + 可取消语义后，核侧才能把闸门放开。

**实现状态（2026-10-20）**：P4/P5 已部分落地。`IssueQueue.cfiBlocked` 已删除；`hasOlderUnresolvedCfi` 不再门控 bare/cacheable 访存，DCache miss 可以直接分配 MSHR 并发 AXI refill。MMU 翻译态仍保留 LSU 输入门控：page-table walk 会占住唯一的翻译状态，必须避免年轻访存在未决分支后启动 walk。设备 load 改为 parking 后重注入（ROB head + stores drained + LTQ empty）。同时修复了 DCache 的 recovery/refill 同拍竞争：recovery 杀掉全部 waiter 的同一拍如果已经发出 AXI read，MSHR 必须保留到响应回来，否则 `rready` 会掉 0，SoC 响应悬空。AXI 仍是单 outstanding，多 outstanding/ID 路由仍属于 P4b。

因此本文档的分期是：

| 阶段 | 做什么 | 谁的问题 |
| --- | --- | --- |
| P0（本文档） | 契约定稿 | — |
| P1 | 新 SoC 上线，功能等价于旧 `npc.v` + `sim_mmio.v` | 总线 |
| P2 | DECERR / 错误语义 + 协议检查器，防挂死 | 总线 |
| P3 | 时延注入，做访存延迟敏感性扫描 | 总线 |
| P4 | 核侧：允许"响应无主丢弃" + AXI 多 outstanding | 核（后端） |
| P5 | 核侧：放开 CFI 顺序限制，真正多分支在飞 | 核（后端） |

P1–P3 在 `vsoc` 里完成，不动核；P4/P5 回到 `playground/src/` 里改 Chisel。

## 2. 层次结构

```
sim_top                       // 唯一顶层，只做实例化
├── u_core                    // 薄封装（无逻辑）：扁平口 ↔ AXI interface + tie-off
│   └── ysyx_24100007         // Chisel 生成核（build/sim 下的 RTL，不在本仓库手写）
└── u_soc                     // SoC 装配：地址译码 + 外设
    ├── u_demux               // 1→N 地址译码 + N→1 响应选择 + W 通道路由
    │   ├── u_default_slave   // 未映射地址兜底 → DECERR
    │   ├── u_delay_pmem      // 可配置时延（默认 0 = 直通）
    │   │   └── u_pmem        // axi4_ram_dpi，512 MiB，走 DPI 到 host
    │   ├── u_delay_uart      // 可配置时延（默认 0 = 直通）
    │   │   └── u_uart        // 0xa000_03f8，4 B，TX only
    │   └── (预留) u_xxx      // 第三个外设的位置
    └── (仿真) axi4_protocol_checker
```

约定：

- `simtop` 里**不允许有** `if/always/assign` 之外的任何逻辑；不要状态机、不要计数器、不要 `$display`。
- 时钟/复位只从 `simtop` 往下传，**全设计单时钟域**。
- 所有跨模块连接走 AXI4，**不允许旁路**（例如不要再出现"核直接读某个外设的裸信号"）。

## 3. 目录结构（建议）

```
playground/resource/vsoc/
├── doc/                          # 本设计文档集（当前阶段唯一产物）
├── simtop.v                      # [删除] 旧占位文件，被 rtl/simtop.sv 取代
├── sim/
│   └── axi4_protocol_checker.sv  # 仿真专用协议断言（不参与综合，默认开启）
└── rtl/
    ├── simtop.sv                # 唯一顶层
    ├── u_core/
    │   └── u_core.sv             # 核的薄封装：扁平口 ↔ vsoc_axi_if，slave 侧 tie-off
    └── u_soc/
        ├── u_soc.sv              # SoC 装配（实例化 demux + 各外设）
        ├── pkg/
        │   ├── vsoc_pkg.sv       # 地址表、宽度参数、响应码、时延默认值（单一事实源）
        │   └── vsoc_axi_if.sv    # AXI4 interface + modport master/slave
        ├── fabric/
        │   ├── axi4_demux.sv     # 地址译码 + 响应 mux
        │   └── axi4_default_slave.sv
        ├── mem/
        │   └── axi4_ram_dpi.sv   # pmem（DPI 桥）
        ├── periph/
        │   └── axi4_uart.sv      # uart（TX mock）
        └── misc/
            └── axi4_delay.sv     # 时延注入（参数为 0 时 generate 成直通）
```

与构建系统的关系（保持现状，不改）：

- 手写的 `.sv` 通过 `EXTRA_V`（`$(SIM_VERILOG_DIR)/*.v`）进 Verilator；新目录要么放进 `SIM_VERILOG_DIR` 的搜索范围，要么新增一个 `VSOC_RTL_DIR` 变量（见 `roadmap.md` 的迁移清单）。
- 核的 RTL 由 `mill ... Elaborate` 生成到 `build/sim/`，用 `--top-module sim_top` 指定顶层。

## 4. 地址映射（"宪法"，单一事实源 = `vsoc_pkg.sv`）

### 4.1 SoC 侧（`u_demux` 负责译码）

| 区域 | 基址 | 大小 | 终点 | 正常响应 | 越界/非法响应 |
| --- | --- | --- | --- | --- | --- |
| `pmem` | `0x8000_0000` | 512 MiB | `u_pmem`（DPI → host RAM） | OKAY | DECERR |
| `uart` | `0xa000_03f8` | 4 B | `u_uart` | OKAY | DECERR |
| 兜底 | 其它一切 | — | `u_default_slave` | — | DECERR |

### 4.2 核内（`AxiXbar` 截获，**SoC 永远看不到**）

| 区域 | 基址 | 大小 | 谁在管 |
| --- | --- | --- | --- |
| `clint` | `0x0200_0000` | 64 KiB | `ClintDevice`（msip/mtime/mtimecmp） |
| `rtc` | `0xa000_0048` | 8 B | `ClintDevice`（mtime 别名） |
| `plic` | `0x0c00_0000` | 64 MiB | `PlicDevice`（简化实现、单中断源；用户明确不要它的外移） |

规则（写代码时按这几条卡）：

1. **互不重叠**：SoC 地址表与核内地址表不能有交集（否则行为取决于谁先译码）。`vsoc_pkg` 里加 `assert` 做静态检查。
2. **2 的幂对齐**：区域大小必须是 2 的幂，基址按大小对齐（512 MiB / 64 KiB / 64 MiB 都满足；uart 的 4 B 是唯一小区域，允许）。
3. **必须有人认领**：任何地址落到兜底就是 DECERR，**不能悬空、不能永远不响应**。
4. **同一事务的地址边界**：一个 burst 必须整体落在同一个区域里；跨区域 = 非法（检查器断言）。
5. 新增外设 = 在 `vsoc_pkg` 加一行 + 在 `u_soc` 加一个实例 + 接进 `u_demux`，其它地方不改。

## 5. 数据流

一次 cache miss 读（`u_core` 侧视角）：

```
AR 通道:  core ──arvalid/araddr/arlen/arsize/arburst/arid──► demux ──► pmem
          demux 在这一拍记下"这笔读属于谁"（route tag）
R  通道:  core ◄──rvalid/rdata/rresp/rlast/rid─── rsp_mux ◄── pmem
          选路靠 route tag，不靠地址（R 通道上没有地址）
```

一次 MMIO 写（例如 AM 的 `putch`）：

```
AW/W 通道: core ──AW(0xa000_03f8)──► demux ──► uart
           core ──W(data,strb)──────► demux ──► uart  (W 路由同样靠 AW 记下的 tag)
B  通道:   core ◄──bvalid/bresp/bid─── rsp_mux ◄── uart (OKAY)
```

一次非法地址（投机 load 的典型场景）：

```
AR 通道:  core ──AR(0xdeadbeef)──► demux ──► default_slave
R  通道:  core ◄── R(rresp=DECERR, rlast=1) ◄── default_slave
核内结果: AxiReadRefill/DCache 把 fault 置 1 → LSU 产生 loadAccessFault 精确异常
          （核侧这条通路已经存在，SoC 只要诚实回报 DECERR 即可）
```

对比旧模型：`sim-verilator/verilog/npc.v` 的 `axi_memory` 里

```verilog
assign io_rvalid = (state_current == READ) && read_valid;  // 只在 rready 有效时才推进
```

- `rvalid` 依赖 `rready`（违反 AXI：VALID 不得依赖 READY）；
- 只有 `IDLE` 才接受新请求，且要求 `awvalid && wvalid` **同拍**；
- 没有任何错误响应路径，地址越界时状态机原地打转 → `rready` 掉 0 → host 侧的 DPI 也不再被调用 → 整机挂死（表现为 `REACH MAX NO COMMIT CYCLES`）。

这就是 P2 要修的东西。

## 6. 关键决策记录（ADR 摘要）

| # | 决策 | 理由 | 备选/否决 |
| --- | --- | --- | --- |
| A1 | 只保留一个顶层 `sim_top`，不要 `asic_top` / 双顶层 | Verilator 只需要一个 top；将来用 iverilog 就在外面再包一层 | ❌ `sim_top` + `asic_top` 双顶层（用户否决） |
| A2 | `sim_top` 端口只有 `clock` / `reset`（沿用旧信号名） | host C++ 直接写 `top.clock` / `top.reset`，改名要连带动 host 代码 | ❌ `clk`/`rst` 改名 |
| A3 | 仿真控制（exit/watchdog/wave）全在 host | RTL 里做这些无法复用、会污染可综合路径；host 侧已经有 Rust 的 step/watchdog | ❌ RTL 计数器 + `$finish` |
| A4 | 外设最小集 = pmem + uart | 够跑 AM/NEMU 与 riscv-tests；结构上留扩展位 | ❌ 一次做全 SoC |
| A5 | CLINT/RTC/PLIC 留在核内 | 已在 `AxiXbar` 里工作，搬迁是纯搬运无收益 | ❌ 这轮搬出来 |
| A6 | 内部连线用 `vsoc_axi_if`（interface + modport）；核边界保持扁平口 | 核是 Chisel 生成的扁平口，interface 只在 SoC 内部用，边界只写一次适配 | 回退方案：全扁平 + `s_axi_*`/`m_axi_*` 命名约定 |
| A7 | 未映射地址 → `default_slave` 回 DECERR | AXI 协议要求每个事务都有响应；这是"不挂死"的根 | ❌ 悬空 ready=0（rocket-chip Xbar 的默认行为，会挂死） |
| A8 | 时延用独立模块 `axi4_delay` 注入，参数 0 = 直通 | 校准是独立关注点；0 时零开销、零功能差异 | ❌ 把时延写进外设内部 |
| A9 | 先做单笔 outstanding，但接口按标准 AXI4 定义（带 ID） | 核当前单笔；接口不缩水才能无痛升级 | ❌ 现在就做 ID 路由表（无收益） |
| A10 | 主存数据放 host（DPI），不放 RTL 数组 | 512 MiB 不能在 RTL 里实例化；difftest/NEMU 也直接访问同一份内存 | ❌ RTL `reg [7:0] mem[]` |

## 7. 迁移影响面（P1 开工前必须先改的清单）

弃用 `sim-verilator/verilog/` 时，下面这些地方会被牵动，**先列出来避免漏改**：

| 位置 | 现在 | 目标 |
| --- | --- | --- |
| `scriptmk/config.mk` | `TOP_MODULE ?= npc` + `ifeq ($(TOP_MODULE),npc)` 否则报错 | `sim_top`，并放开这个检查或改成白名单 |
| `scriptmk/config.mk` `EXTRA_V` | `$(SIM_VERILOG_DIR)/*.v` | 加入 `vsoc/rtl/**/*.sv`（Verilator 支持目录+`-y`，或显式列表） |
| `cpp/src/npc_sim.cpp` | `#include "Vnpc.h"`、`std::make_unique<Vnpc>` | `Vsim_top.h` / `Vsim_top` |
| `cpp/src/npc_cpu.cpp` | `Vnpc &top`，`top.clock` / `top.reset` | `Vsim_top &top`，端口名不变（见 A2） |
| `cpp/include/npc_cpu.h` | 同上 | 同上 |
| `rust/` FFI | 只依赖 DPI 符号名，不依赖 RTL 结构 | **不改**（前提：DPI 契约不变，见 `interfaces.md` §6） |
| `sim-verilator/verilog/npc.v` | 顶层 + `axi_memory` + `sim_mmio` | **删除**，功能被 `vsoc` 覆盖 |

DPI 符号名是 host 与 RTL 之间唯一的硬契约：`npc_pmem_read` / `npc_pmem_write` / `npc_time_read` + 核内生成的那批 perf 钩子。**这些名字和签名不要改**，否则必须同步改 Rust 侧 `ffi.rs`。

## 8. 术语表

| 术语 | 含义 |
| --- | --- |
| `u_` 前缀 | 实例名（`u_core` = core 的实例），不是模块名 |
| DECERR | AXI 响应码 `0b11`：地址没有被任何从设备认领 |
| SLVERR | AXI 响应码 `0b10`：地址被认领了，但访问方式/数据不合法 |
| route tag | 请求握手时记下的"这笔事务属于哪个从设备"，用于响应通道选路 |
| outstanding | 已发出但还没收到响应的事务 |
| latency / throughput | 首拍延迟 / 稳态每拍吞吐；两个独立的旋钮，别混 |
| MLP | memory-level parallelism：同时在飞的访存数，延迟能否被隐藏取决于它 |
