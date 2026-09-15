# 模块清单与职责（v0.1）

> 本文档定义**每个模块的作用、接口、时序行为、复位行为、以及"不做什么"**。
> 不写实现代码；实现细节留给编码阶段。所有模块共享 `interfaces.md` §5 的端口模板。

## 0. 清单

| 模块 | 文件 | 作用 | 预估行数 | 实现顺序 |
| --- | --- | --- | --- | --- |
| `vsoc_pkg` | `u_soc/pkg/vsoc_pkg.sv` | 宽度/地址表/响应码（单一事实源） | ~60 | 1 |
| `vsoc_axi_if` | `u_soc/pkg/vsoc_axi_if.sv` | AXI4 interface + modport | ~70 | 1 |
| `axi4_ram_dpi` | `u_soc/mem/axi4_ram_dpi.sv` | pmem：DPI 桥到 host RAM | ~200 | 2 |
| `axi4_uart` | `u_soc/periph/axi4_uart.sv` | UART TX（0xa000_03f8） | ~90 | 3 |
| `axi4_default_slave` | `u_soc/fabric/axi4_default_slave.sv` | 未映射地址 → DECERR | ~80 | 3 |
| `axi4_demux` | `u_soc/fabric/axi4_demux.sv` | 1→N 地址译码 + 响应 mux + W 路由 | ~150 | 4 |
| `axi4_delay` | `u_soc/misc/axi4_delay.sv` | 可配置时延（默认 0 = 直通） | ~120 | 4 |
| `u_soc` | `u_soc/u_soc.sv` | 装配（只有实例化与连线） | ~80 | 5 |
| `u_core` | `u_core/u_core.sv` | 核薄封装：扁平口 ↔ interface + tie-off | ~100 | 5 |
| `sim_top` | `sim_top.sv` | 唯一顶层 | ~20 | 5 |
| `axi4_protocol_checker` | `sim/axi4_protocol_checker.sv` | 仿真协议断言 | ~150 | 6 |

## 1. `sim_top`

**作用**：唯一顶层。只有 `clock` / `reset` 两个端口，只有两个实例。

```
sim_top (clock, reset)
├── u_core (clock, reset, m_axi)          // 核是 master
└── u_soc  (clock, reset, s_axi)          // SoC 是 slave
      └── u_core.m_axi ──── s_axi
```

- **时序**：无逻辑，纯连线。
- **复位**：透传。
- **不做什么**：不做 exit/watchdog/wave/`$finish`/`$dumpvars`/超时计数/打印。
  这些全在 host 侧（Rust 的 step loop、watchdog、`npc_wave.cpp`）。
- 将来换 iverilog / VCS 时，在 `sim_top` **外面**再包一层 testbench，`sim_top` 本身不动。

## 2. `u_core`

**作用**：核（Chisel 生成的 `ysyx_24100007`）与 SoC 之间的**唯一适配层，零逻辑**。

- **端口**：`clock`, `reset`, `vsoc_axi_if.master m_axi`（对外），内部接核的扁平 `io_master_*`。
- **处理的三件事**（都在 `interfaces.md` §4）：
  1. `io_master_*` 扁平口 ↔ `m_axi`（逐位连线）；
  2. `io_slave_*` 从端口 tie-off（给核的全部输入恒 0，核的输出悬空）；
  3. `io_interrupt` tie 成 `1'b0`（PLIC 在核内，暂无可屏蔽的外部中断源）。
- **时序**：纯组合连线，**一拍的延迟都不许加**（核的 AXI 时序和解码状态机假定自己直接挂在总线上）。
- **不做什么**：不做 buffering、不做 skid、不做地址译码、不做中断聚合（将来有多个中断源时另开一个 `irq_aggregator`，不要塞进这里）。
- **为什么值得单独一层**：核是生成的 RTL、名字和端口随时可能因 Chisel 改动而变；把适配收在一处后，SoC 其余部分对核的改动免疫。

## 3. `u_soc`

**作用**：SoC 装配。**只允许实例化和连线**。

```
u_soc
├── u_demux : axi4_demux           NUM_SLAVES = 3
│   ├── m_axi[DEV_PMEM]    ── u_delay_pmem ── u_pmem
│   ├── m_axi[DEV_UART]    ── u_delay_uart ── u_uart
│   └── m_axi[DEV_DEFAULT] ────────────────── u_default_slave
```

- **地址表来源**：只从 `vsoc_pkg` 取，不允许在 `u_soc` 里手写常量。
- **时序**：无。
- **不做什么**：不写译码逻辑、不写中断逻辑、不做时钟/复位生成、不做参数分支。
- **扩展方式**：加一个外设 = `vsoc_pkg` 加地址常量 + `NUM_SLAVES` 加一 + `u_soc` 加一个实例（见 `roadmap.md` §3）。

## 4. `axi4_demux`（1→N 地址译码 + 响应 mux）

**作用**：把核的单个 AXI4 master 口，按地址分发到 N 个从设备；把 N 个响应汇聚回一条 R/B 通道。

**参数**：`ADDR_W`, `DATA_W`, `ID_W`, `NUM_SLAVES`。

**端口**：

```
s_axi                : vsoc_axi_if.slave    // 上游，来自 u_core
m_axi[NUM_SLAVES]    : vsoc_axi_if.master   // 下游，每个从设备一根
```

> 端口写成 interface 数组；若 Verilator 版本对 interface 数组支持不佳，退化成显式端口 `m_axi_pmem` / `m_axi_uart` / `m_axi_default`（接线变啰嗦，结构不变）。

### 4.1 时序行为（这是整个 SoC 最容易写错的地方）

**请求路径（组合译码，不加拍）**

| 通道 | 行为 |
| --- | --- |
| AR | `sel = decode(araddr)`；`m_axi[sel].arvalid = s_axi.arvalid`；`s_axi.arready = m_axi[sel].arready` |
| AW | `sel = decode(awaddr)`；`m_axi[sel].awvalid = s_axi.awvalid`；`s_axi.awready = m_axi[sel].awready` |
| W | **按 AW 的路由转发**（W 通道上没有地址）：`m_axi[aw_route].wvalid = s_axi.wvalid`；`s_axi.wready = m_axi[aw_route].wready` |

三条铁律：

1. **`*valid` 只依赖上游 `*valid`，绝不依赖下游 `*ready`**（否则就是旧 `axi_memory` 的老毛病）。允许 `ready` 依赖 `valid`。
2. **W 通道必须路由，不能广播**。广播会让所有从设备同时消费同一笔写数据。
3. **W 必须能等 AW**：若 `s_axi.wvalid` 先到而写事务还没记录，就 back-pressure（`wready = 0`）。核当前是 AW/W 同拍发出（`AxiMaster` 的 `directWriteValid` / `registeredWValid` 都由同一个 `transferWrite` 状态门控），所以这条不会真的卡住；但**从设备合规性要求**如此，不许写成"要求 AW/W 同拍"。

**路由记录（寄存器，响应通道靠它选路）**

| 记录 | 何时写 | 何时清 | 位宽 |
| --- | --- | --- | --- |
| `ar_route` | `s_axi.arvalid && s_axi.arready`（AR 握手拍） | `s_axi.rvalid && s_axi.rready && s_axi.rlast`（读最后一拍） | `$clog2(NUM_SLAVES)` |
| `aw_route` | `s_axi.awvalid && s_axi.awready` | `s_axi.bvalid && s_axi.bready` | `$clog2(NUM_SLAVES)` |

- 核当前**读、写各只有一笔在飞**（`AxiXbar` 的 `readRouteValid` / `writeRouteValid` + `AxiMaster` 的 `requestWindow`），所以每方向各 1 bit 记录就够。
- 但接口要按"将来会多笔"来留：记录里带上 `arid`/`awid`，升级路径见 `roadmap.md` §3。
- **不要**让 `*_valid` 记录位挡住新请求：只有当"该方向已有事务在飞"时才需要（当前核保证不会发生）。

**响应路径（用记录选路，不用地址）**

```
s_axi.rvalid = m_axi[ar_route].rvalid       s_axi.bvalid = m_axi[aw_route].bvalid
s_axi.rdata  = m_axi[ar_route].rdata        s_axi.bresp  = m_axi[aw_route].bresp
s_axi.rresp  = m_axi[ar_route].rresp        s_axi.bid    = m_axi[aw_route].bid
s_axi.rlast  = m_axi[ar_route].rlast        s_axi.bready = m_axi[aw_route].bready
s_axi.rid    = m_axi[ar_route].rid          (其余下游的 bready = 0)
s_axi.rready = m_axi[ar_route].rready       (其余下游的 rready = 0)
```

**关键点**：`rready` 必须**只**送到当前选中的从设备，其余保持 0。否则会有多个从设备同时看到 `rready=1`，被选中的那个会在错误的拍前进。

**未命中地址** → `sel = DEV_DEFAULT`，由 `axi4_default_slave` 回 DECERR。**绝不允许"没有从设备被选中所以 ready=0"**（这是 rocket-chip `AXI4Xbar` 的默认行为，会挂死整机）。

### 4.2 复位行为

`ar_route` / `aw_route` / 在飞标志清零；所有下游 `*valid` = 0、`*ready` = 0。

### 4.3 不做什么

- 不做 burst 拆分（4 KB 边界、跨区域）：只断言，不修。
- 不做数据缓冲（除了 W 路由需要的必要 skid 可选）。
- 不做重排序、不做多 outstanding 仲裁（当前单笔，无需）。
- 不做地址对齐修正（`arsize`/`awsize` 原样透传）。

## 5. `axi4_default_slave`

**作用**：任何没被认领的地址的兜底应答机。**它是"投机访存不挂死"的最后一道保险，必须存在。**

**参数**：`ADDR_W`, `DATA_W`, `ID_W`, `RESP_CODE = RESP_DECERR`。

**端口**：一个 `vsoc_axi_if.slave s_axi`。

**时序行为**：

| 场景 | 行为 |
| --- | --- |
| 收到 AR | 返回**恰好一拍** R：`rresp = DECERR`, `rlast = 1`, `rdata = 0`, `rid = arid` |
| 收到 AW | 记录 `awlen`/`awid`，然后**吞掉 `len+1` 拍 W**（不写任何地方），收完后回一拍 B：`bresp = DECERR`, `bid = awid` |
| `rvalid` | **不依赖 `rready`**：可以立刻拉起并保持到握手；`rready` 不来就一直保持 |
| 复位 | 所有 valid 拉 0 |

**关键规则**：写事务即使要报错，也**必须把 W 通道的数据全部接收完**才能回 B。否则 master 的 W 通道被永久 back-pressure → 挂死。这是"报错比不报错更容易写挂"的地方。

**不做什么**：不区分地址、不做重试、不做日志（日志放协议检查器）。

## 6. `axi4_ram_dpi`（pmem）

**作用**：主存。数据不在 RTL 里，全部通过 DPI 落到 host 的 RAM（Rust 侧 `register_ram("pmem", 0x8000_0000, 512 MiB)`）。

**参数**：`ADDR_W`, `DATA_W`, `ID_W`, `BASE_ADDR = PMEM_BASE`, `SIZE = PMEM_SIZE`。

**端口**：一个 `vsoc_axi_if.slave s_axi`；DPI 调用 `npc_pmem_read` / `npc_pmem_write`（签名见 `interfaces.md` §6）。

**时序行为**

| 阶段 | 行为 |
| --- | --- |
| AR 握手拍 | 记录 `araddr/arid/arlen/arsize/arburst`；**判断整个 burst 是否落在 `[BASE, BASE+SIZE)` 内**（用首拍地址 + `(len+1)<<size` 上界判，不是只判首拍） |
| burst 合法 | 每拍返回一个 R beat：beat 地址 = 首地址 + `i<<arsize`（INCR）；`rdata` = 该 4 B 对齐字（`npc_pmem_read(beat_addr_aligned, 4, data)`）；最后一拍 `rlast=1` |
| burst 越界 | 返回**恰一拍** R：`rresp = DECERR`, `rlast = 1`，**不调用 DPI** |
| AW 握手拍 | 记录 `awaddr/awid/awlen/awsize/awburst`；同样做整 burst 的范围检查 |
| W beats | 合法时：对每个 `wstrb[i]=1` 的字节调 `npc_pmem_write(beat_addr_aligned + i, 1, wdata[8i+7:8i])`；越界时：**照样吞掉所有 W beats，不写** |
| W 结束 | `wlast` 收到（且拍数 == `awlen+1`）后回一拍 B：`bresp = OKAY`（或 `DECERR`），`bid = awid` |
| 非法 size / WRAP burst | 回 `SLVERR`（不做静默容忍） |

**读数据语义**：`rdata` 永远等于"该 beat 的 4 B 对齐字"（不管 `arsize` 是 1/2/4）。这与 AXI 规范一致（窄传输的数据出现在由地址决定的 lane 上），也和核内 `AxiDataAccess` 的提取逻辑一致。**不要**在从设备里做 byte 提取，那是 master 的事。

**`rvalid` 与 `rready`**：`rvalid` 可以在 AR 握手后的下一拍就拉起；**绝不依赖 `rready`**。若下游慢（`rready=0`），保持数据不变、等它。

**复位**：清所有状态；DPI 调用不发生在复位期间。

**不做什么**：不做 cache、不做 ECC、不做多笔重排、不做字节序转换、不做 unaligned 拆分（对齐由 master 保证）。

**综合替换**：将来要流片时，把本模块替换成 `axi4_ram`（行为 SRAM / DRAM 控制器），端口不变，`u_soc` 只改一个模块名。

## 7. `axi4_uart`

**作用**：AM / NEMU 的串口。写 `0xa000_03f8` 的 offset 0 → 输出一个字符。

**参数**：`BASE_ADDR = UART_BASE`, `ADDR_SIZE = 4`, `USE_DPI_TX = 0`。

**端口**：一个 `vsoc_axi_if.slave s_axi`；可选 DPI 输出 `vsoc_uart_tx(byte)`。

**时序行为**

| 访问 | 行为 |
| --- | --- |
| 写，地址在范围内 | 逐 lane 检查 `wstrb`，命中的 lane 中 offset==0 的那个字节作为字符输出；回 B = OKAY |
| 写，地址越界（同页但超出 4 B） | 回 B = DECERR |
| 读，任意偏移 | 返回 `32'b0`（模拟"发送保持寄存器永远 ready"），回 R = OKAY（一拍，`rlast=1`） |
| 输出方式 | `` `ifdef VSOC_UART_DPI `` → 调 `vsoc_uart_tx(ch)`；否则 `$write("%c", ch)`（仅仿真，加 `ifndef SYNTHESIS`） |
| `rvalid` | 不依赖 `rready` |

**为什么是"逐 lane 判断"而不是"按地址判断"**：AM 的 `putch` 可能是 byte 写、也可能是 word 写；逐 lane 判断能同时覆盖两种情况，逻辑更少（旧 `sim_uart` 就是这么做的，行为可以照搬，但要重新组织成合规的 AXI 从设备）。

**不做什么**：不做 RX、不做波特率/时序仿真、不产生中断、不做 FIFO 深度模拟（读取恒 0 = 永远可写）。将来要做 UART 中断或 RX，再在此模块里加状态和一根中断线（走 `irq_aggregator`，不要直接连核）。

## 8. `axi4_delay`（时延注入，参数默认 0）

**作用**：给访存注入可配置的**首拍延迟（latency）**和**每拍间隔（throughput）**，用于将来做访存延迟敏感性校准。

**参数**：

| 参数 | 含义 | 默认 |
| --- | --- | --- |
| `AR_LATENCY` | AR 从被接受 → 送到下游的额外周期数 | 0 |
| `AW_LATENCY` | AW 同上 | 0 |
| `W_LATENCY` | W 每拍之间的额外间隔 | 0 |
| `R_LATENCY` | R 首拍额外延迟 / 每拍间隔 | 0 |
| `B_LATENCY` | B 从写完成 → 可被取走的额外延迟 | 0 |

**端口**：`s_axi`（`vsoc_axi_if.slave`）+ `m_axi`（`vsoc_axi_if.master`）。

**时序行为**

- 每个参数为 0 时，`generate` 成**纯直通连线**（一行 `assign`，不实例化任何寄存器）→ 对当前功能与性能**零影响**。
- 参数 > 0 时：在该通道上插入等量的寄存器级（skid/移位），逐通道独立。
- **只加延迟，不改语义**：
  - 不丢拍、不合并、不重排；
  - 不引入 `ready` → `ready` 的组合环（VALID 依然不依赖 READY）；
  - 不改变 burst 长度、不改变 `rlast`/`wlast` 的位置；
  - 延迟期间靠 back-pressure 说明"还没轮到你"，**不是**靠"少发一拍"。
- **通道是独立的**：给 R 加延迟不影响 AR；给 AW 加延迟不影响 W。这既是 AXI 的本意，也是本模块的实现前提。

**位置**：`u_demux` 的每个下行口 → 对应从设备之间。M0–M3 全部实例化但参数为 0；做校准扫描时只改 `vsoc_pkg` 里的 `PMEM_*_LATENCY` 常量（改完要重跑 verilator）。

**校准怎么用**：把 `AR_LATENCY + R_LATENCY` 当作"内存往返延迟"总旋钮，先扫 {0, 4, 16, 40, 100} 观察 IPC/未提交周期变化；`R_LATENCY` 的"每拍间隔"旋钮用来模拟带宽受限（DRAM burst 间隔）。乱序核的 IPC 对首拍延迟的敏感度取决于 MLP（MSHR 数、load 队列深度），这正是要量化的东西。

**不做什么**：不模拟 DRAM 的 bank/row 行为、不做随机延迟（要随机性就在 host 侧用 plusarg 注入，或者后面再加 LFSR）、不做超时。

## 9. `axi4_protocol_checker`（仿真专用）

**作用**：把 AXI4 的握手规则变成断言。**这是本项目从"能跑"到"不挂死"的关键工具**，因为它能在挂死发生前就报出根因。

**接口**：`vsoc_axi_if.monitor`（只读），一页断言；用 `` `ifdef VSOC_PROTOCOL_CHECK`` 包住（默认开）。

**断言清单**（详见 `timing.md` §9）：

- VALID 拉起后到握手前不得落下；payload 在握手前不得变化；
- VALID 不得依赖 READY（结构性检查，靠 code review + 特定断言）；
- `wlast`/`rlast` 必须恰好出现在第 `len+1` 拍；
- 一个 burst 不得跨 4 KB 边界；不得跨地址区域；
- `bresp`/`rresp` 非法值时报警；
- 响应码为 DECERR 的写事务，W beats 数量必须仍等于 `len+1`；
- 每个 AR/AW 最终都必须收到响应（防挂死的"活性"断言：用计数器，超时报警而不是永远沉默）。

## 10. 复位与时钟（所有模块统一）

| 项 | 规则 |
| --- | --- |
| 复位类型 | 高有效、同步（`always_ff @(posedge clk) if (rst)`） |
| 复位期间 | 所有 `*valid = 0`；`*ready` 可以随意（但建议 0）；payload 不复位 |
| 复位释放后 | 必须能接受核已经拉起的 `arvalid`/`awvalid` |
| 时钟 | 只有 `clk`；**禁止**第二个时钟、`negedge`、`always_ff @(posedge clk or posedge rst)` |
| `initial` | 禁止（DPI 模型除外，且需 `ifndef SYNTHESIS` 保护） |
