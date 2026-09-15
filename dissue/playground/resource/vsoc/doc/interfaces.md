# 接口定义（v0.1）

> 本文档定义"线"长什么样，不定义"线背后的逻辑"。所有宽度、名字、方向以本文档为准。
> 单一事实源：`rtl/u_soc/pkg/vsoc_pkg.sv` 与 `rtl/u_soc/pkg/vsoc_axi_if.sv`。

## 1. 参数（全局）

| 参数 | 值 | 说明 |
| --- | --- | --- |
| `ADDR_W` | 32 | 与核的 `MemConfig.addrWidth` 一致 |
| `DATA_W` | 32 | 与核的 `MemConfig.axiDataWidth` 一致（4 B/beat） |
| `STRB_W` | 4 | `DATA_W/8`，由 `DATA_W` 推导，不要手写 |
| `ID_W` | 4 | 与核的 `MemConfig.axiIdWidth` 一致 |
| `LEN_W` | 8 | AXI4 固定 8 bit（最多 256 beat） |
| `SIZE_W` | 3 | AXI4 固定 |
| `BURST_W` | 2 | AXI4 固定 |

改 `DATA_W`（例如将来上 64 bit）时，只需要改这一处 + 核的 `MemConfig`，其余全部由推导得到。

## 2. AXI4 是什么：五条独立通道

AXI4 的本质是**五个互相独立、各自握手的通道**，不是一根总线。理解这一点，后面所有时序规则都是自然推论。

| 通道 | 方向 | 携带什么 | 握手信号 | 本设计 |
| --- | --- | --- | --- | --- |
| AW (Write Address) | master→slave | `awaddr/awid/awlen/awsize/awburst` | `awvalid`/`awready` | ✅ |
| W (Write Data) | master→slave | `wdata/wstrb/wlast` | `wvalid`/`wready` | ✅ |
| B (Write Response) | slave→master | `bresp/bid` | `bvalid`/`bready` | ✅ |
| AR (Read Address) | master→slave | `araddr/arid/arlen/arsize/arburst` | `arvalid`/`arready` | ✅ |
| R (Read Data) | slave→master | `rdata/rresp/rlast/rid` | `rvalid`/`rready` | ✅ |

关键性质：

- **AW 和 W 之间没有任何顺序约束**。从设备必须能先收 W 后收 AW（缓冲），也必须能先收 AW 后收 W。任何"要求两者同拍有效"的实现都是 bug（旧 `axi_memory` 就是这么写的）。
- **B 只和 AW/W 有关，和 AR/R 无关**。读写的响应通道完全独立。
- 一次读 = AR 一拍 + R 若干拍（`rlast` 收尾）；一次写 = AW 一拍 + W 若干拍（`wlast` 收尾）+ B 一拍。
- `arid`/`awid` 是 master 打的标签，从设备必须在 `rid`/`bid` 上**原样回传**。单笔 outstanding 时它是常量，但仍然要回传。

### 本设计用到的信号子集

核输出的 `AxiPort` **不含**以下 AXI4 可选信号，因此 SoC 侧也不定义、不检查、不驱动：

`awprot` / `awcache` / `awlock` / `awqos` / `awregion` / `awuser`、`wuser`、`buser`、
`arprot` / `arcache` / `arlock` / `arqos` / `arregion` / `aruser`、`ruser`。

将来要做 cache 一致性 / 内存属性区分时，第一个要补的就是 `awcache`/`arcache` 和 `awprot`（共享性/权限），届时在 `vsoc_axi_if` 里加线即可，模块骨架不用动。

## 3. `vsoc_axi_if` 定义草案

```systemverilog
// rtl/u_soc/pkg/vsoc_axi_if.sv
interface vsoc_axi_if #(
    parameter int unsigned ADDR_W = 32,
    parameter int unsigned DATA_W = 32,
    parameter int unsigned ID_W   = 4
);
  localparam int unsigned STRB_W = DATA_W / 8;

  // AW
  logic              awvalid;
  logic              awready;
  logic [ADDR_W-1:0] awaddr;
  logic [ID_W-1:0]   awid;
  logic [7:0]        awlen;
  logic [2:0]        awsize;
  logic [1:0]        awburst;

  // W
  logic              wvalid;
  logic              wready;
  logic [DATA_W-1:0] wdata;
  logic [STRB_W-1:0] wstrb;
  logic              wlast;

  // B
  logic              bvalid;
  logic              bready;
  logic [1:0]        bresp;
  logic [ID_W-1:0]   bid;

  // AR
  logic              arvalid;
  logic              arready;
  logic [ADDR_W-1:0] araddr;
  logic [ID_W-1:0]   arid;
  logic [7:0]        arlen;
  logic [2:0]        arsize;
  logic [1:0]        arburst;

  // R
  logic              rvalid;
  logic              rready;
  logic [1:0]        rresp;
  logic [DATA_W-1:0] rdata;
  logic              rlast;
  logic [ID_W-1:0]   rid;

  modport master  (output awvalid, awaddr, awid, awlen, awsize, awburst,
                   input  awready,
                   output wvalid, wdata, wstrb, wlast,
                   input  wready,
                   input  bvalid, bresp, bid,
                   output bready,
                   output arvalid, araddr, arid, arlen, arsize, arburst,
                   input  arready,
                   input  rvalid, rresp, rdata, rlast, rid,
                   output rready);

  modport slave   (input  awvalid, awaddr, awid, awlen, awsize, awburst,
                   output awready,
                   input  wvalid, wdata, wstrb, wlast,
                   output wready,
                   output bvalid, bresp, bid,
                   input  bready,
                   input  arvalid, araddr, arid, arlen, arsize, arburst,
                   output arready,
                   output rvalid, rresp, rdata, rlast, rid,
                   input  rready);

  // 协议检查器专用：只读，任何方向都当输入
  modport monitor (input awvalid, awready, awaddr, awid, awlen, awsize, awburst,
                   input wvalid, wready, wdata, wstrb, wlast,
                   input bvalid, bready, bresp, bid,
                   input arvalid, arready, araddr, arid, arlen, arsize, arburst,
                   input rvalid, rready, rresp, rdata, rlast, rid);
endinterface
```

使用约定：

- **SoC 内部**统一用 `vsoc_axi_if`（`modport master` / `modport slave`）。核的边界见 §4。
- 从设备一律只有一个 AXI4 slave 口（`u_pmem`、`u_uart`、`u_default_slave`），**不区分读写子口**。
- `u_demux` 的 `N` 个下行口是**静态展开**的：`generate for (genvar i = 0; i < NUM_SLAVES; i++)`，每个从设备一根独立的 interface 实例。不用 interface 数组（Verilator 对 interface 数组支持不如展开稳）。
- 兜底方案：若 Verilator 对 interface 有问题，退化成全扁平端口 + 命名约定 `s_axi_*` / `m_axi_*`；**这只是接线方式的变化，模块划分和层次不变**。

## 4. 核边界：`u_core`（扁平口，唯一一次适配）

Chisel 生成的核（模块名 `ysyx_24100007`）是**纯扁平端口**。`u_core.sv` 是唯一的适配层，职责只有三件事，**不含任何逻辑**：

1. 把核的 `io_master_*` 扁平信号 ↔ `vsoc_axi_if`（master 口）；
2. 把核的 `io_slave_*` 从端口 tie 成"永远无事务"（见下）；
3. 把 `io_interrupt` tie 成 `1'b0`（PLIC 在核内，外部中断源暂时没有）。

核的真实端口（以生成的 `ysyx_24100007.v` 为准，来自 `Top.scala` 的 `IO`）：

```
input  clock, reset
input  io_interrupt

// io.master : AxiPort（核是 master）
output io_master_awvalid          input  io_master_awready
output [31:0] io_master_awaddr    output [3:0] io_master_awid
output [7:0]  io_master_awlen     output [2:0] io_master_awsize
output [1:0]  io_master_awburst
output io_master_wvalid           input  io_master_wready
output [31:0] io_master_wdata     output [3:0] io_master_wstrb
output io_master_wlast
input  io_master_bvalid           output io_master_bready
input  [1:0]  io_master_bresp     input  [3:0] io_master_bid
output io_master_arvalid          input  io_master_arready
output [31:0] io_master_araddr    output [3:0] io_master_arid
output [7:0]  io_master_arlen     output [2:0] io_master_arsize
output [1:0]  io_master_arburst
input  io_master_rvalid           output io_master_rready
input  [1:0]  io_master_rresp     input  [31:0] io_master_rdata
input  io_master_rlast            input  [3:0] io_master_rid

// io.slave : Flipped(AxiPort)（核是 slave；方向全部相反）
input  io_slave_awvalid           output io_slave_awready
... 同构 ...
```

`io_slave_*` 的处理：

- 本设计里**没有任何外部 master**，所以按"永远没有事务"处理：所有给核的 slave 输入（`awvalid/wvalid/bready/arvalid/rready` 等）恒 `0`。
- 核输出的 `awready/wready/bvalid/bresp/arready/rvalid/...` 悬空不接（Verilator 会报 unused，用 `/* verilator lint_off UNUSEDSIGNAL */` 局部关掉）。
- **不要**为了"好看"给它挂一个永远回 DECERR 的从设备：那会引入一个真实的应答机，白白多一个状态机；等真有外部 master（DMA/调试器）时再接 `axi4_default_slave`。

## 5. `u_soc` 与各模块端口模板

所有 SoC 内部模块遵循同一模板（只是数量不同）：

```systemverilog
module axi4_xxx #(
    parameter int unsigned ADDR_W = 32,
    parameter int unsigned DATA_W = 32,
    parameter int unsigned ID_W   = 4,
    parameter bit          SIM_ONLY = 1
) (
    input  logic clk,
    input  logic rst,          // 同步、高有效、单时钟域
    vsoc_axi_if.slave  s_axi   // 朝向上游（面向 core / demux）
);
```

- `u_demux` 是唯一例外：它有一个 `s_axi`（upstream）+ `NUM_SLAVES` 个 `m_axi`（downstream）。
- 命名：上游口叫 `s_axi`，下游口叫 `m_axi`。**从从设备的角度看，它的口永远是 `s_axi`**。
- `u_soc.sv` 除了实例化和连线，**不允许有逻辑**（地址表来自 `vsoc_pkg`）。

`sim_top.sv` 的完整端口（就这么多）：

```systemverilog
module sim_top (
    input logic clock,
    input logic reset
);
```

> 端口名沿用 `clock`/`reset`（不是 `clk`/`rst`）：host 侧 C++ 直接写 `top.clock = 1` / `top.reset = 0`，改名会牵动 `cpp/src/npc_cpu.cpp`。见 `README.md` A2。

## 6. 时钟 / 复位

| 项 | 约定 |
| --- | --- |
| 时钟域 | **单一** `clock`，全设计同频。不出现第二个时钟，不出现 `negedge` |
| 复位 | `reset`，**高有效、同步**（`always_ff @(posedge clk) if (rst)`），低有效/异步复位一律不用 |
| 复位释放 | host 连续拉高 `reset` 若干拍（当前 30 拍）再释放；RTL 侧不产生复位 |
| RTL 里的 `initial` | **禁止**（唯一例外：将来若在 RTL 里做行为 RAM，用 `initial` 做仿真预载并加 `ifndef SYNTHESIS`） |
| 复位期间的总线 | 所有 `*valid` 拉 0，所有 `*ready` 拉 0；不复位 `rdata` 等 payload（避免无谓面积/复位树） |
| 复位期间被 master 拉起的请求 | 核侧会保持 `valid` 直到握手，所以从设备复位释放后必须能接受已经有效的事务 |

## 7. DPI 契约（host ↔ RTL 的唯一硬接口）

**这些符号名和签名是契约，不要改**（改了就要同步改 Rust 侧 `ffi.rs` / `npc_dpi.cpp`）。

| 符号 | SV 侧声明 | 现在由谁调用 | 新设计里由谁调用 |
| --- | --- | --- | --- |
| `npc_pmem_read` | `import "DPI-C" function void npc_pmem_read(input int addr, input int len, output int data);` | `axi_memory`（旧） | `axi4_ram_dpi`（新） |
| `npc_pmem_write` | `import "DPI-C" function void npc_pmem_write(input int addr, input int len, input int data);` | `axi_memory`（旧） | `axi4_ram_dpi`（新） |
| `npc_time_read` | `import "DPI-C" function longint unsigned npc_time_read();` | 核内 `DeviceTimeDpi` | **不变**（还在核内） |
| `npc_difftest_*` / `npc_*_perf` / `npc_pipeline_trace` | 见 `cpp/include/npc_dpi.h` | 核内 | **不变**（还在核内） |

调用语义（必须与旧实现一致，否则 host 行为会变）：

- `npc_pmem_read(addr, len, data)`：`len ∈ {1,2,4}`，读到 `data`（小端）。
- `npc_pmem_write(addr, len, data)`：`len ∈ {1,2,4}`，写 `len` 个字节。
- 调用时机无所谓（组合/时序都行），但**同一拍不要重复调用同一地址**（host 侧是纯函数 + 写副作用，重复写会重复生效）。
- **越界不要靠 host 报错**：`axi4_ram_dpi` 必须在 RTL 里先把地址范围判掉，越界直接回 DECERR、**不调用 DPI**。host 侧的越界检测是"兜底断言"，一旦触发会记录 machine error 并终止仿真，不是正常控制流。

新增 DPI（可选，后做）：UART 若要走 host 输出，加 `vsoc_uart_tx(input byte ch)`，并用 `` `ifdef VSOC_UART_DPI `` 包起来，这样 host 没提供实现也不会链接失败。

## 8. `vsoc_pkg.sv` 内容草案

```systemverilog
package vsoc_pkg;
  // ---- 宽度 ----
  localparam int unsigned ADDR_W = 32;
  localparam int unsigned DATA_W = 32;
  localparam int unsigned ID_W   = 4;
  localparam int unsigned STRB_W = DATA_W / 8;

  // ---- AXI 响应码 ----
  localparam logic [1:0] RESP_OKAY   = 2'b00;
  localparam logic [1:0] RESP_EXOKAY = 2'b01;
  localparam logic [1:0] RESP_SLVERR = 2'b10;
  localparam logic [1:0] RESP_DECERR = 2'b11;

  // ---- burst 类型 ----
  localparam logic [1:0] BURST_FIXED = 2'b00;
  localparam logic [1:0] BURST_INCR  = 2'b01;
  localparam logic [1:0] BURST_WRAP  = 2'b10;

  // ---- 地址表（SoC 侧，唯一事实源）----
  localparam logic [31:0] PMEM_BASE = 32'h8000_0000;
  localparam logic [31:0] PMEM_SIZE = 32'h2000_0000;   // 512 MiB，与 host DEFAULT_PMEM_SIZE 一致

  localparam logic [31:0] UART_BASE = 32'hA000_03F8;
  localparam logic [31:0] UART_SIZE = 32'h0000_0004;

  // ---- 设备编号（用于 route tag 的位宽推导）----
  localparam int unsigned DEV_PMEM    = 0;
  localparam int unsigned DEV_UART    = 1;
  localparam int unsigned DEV_DEFAULT = 2;
  localparam int unsigned NUM_SLAVES  = 3;   // 加外设时改这里

  // ---- 时延默认值（0 = 直通；见 timing.md §7）----
  localparam int unsigned PMEM_AR_LATENCY = 0;
  localparam int unsigned PMEM_R_LATENCY  = 0;
  localparam int unsigned PMEM_AW_LATENCY = 0;
  localparam int unsigned PMEM_W_LATENCY  = 0;
  localparam int unsigned PMEM_B_LATENCY  = 0;

  // 核内区域：SoC 永远看不到，但列在这里做重叠检查
  localparam logic [31:0] CLINT_BASE = 32'h0200_0000;
  localparam logic [31:0] CLINT_SIZE = 32'h0001_0000;
  localparam logic [31:0] RTC_BASE   = 32'hA000_0048;
  localparam logic [31:0] RTC_SIZE   = 32'h0000_0008;
  localparam logic [31:0] PLIC_BASE  = 32'h0C00_0000;
  localparam logic [31:0] PLIC_SIZE  = 32'h0400_0000;
endpackage
```

> `UART_BASE`（`0xa000_03f8`，4 B）与核内 `RTC_BASE`（`0xa000_0048`，8 B）同页但不重叠，这是允许的；`vsoc_pkg` 里加编译期检查：
> `initial assert (UART_BASE + UART_SIZE <= RTC_BASE || RTC_BASE + RTC_SIZE <= UART_BASE);`
> （用 `$error`+`$fatal` 或 generate 里的静态 `initial`，Verilator 支持在 `initial` 里做静态断言。）
