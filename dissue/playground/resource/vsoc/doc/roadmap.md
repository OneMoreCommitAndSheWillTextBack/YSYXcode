# 里程碑、验收与扩展（v0.1）

## 1. 里程碑

每个里程碑都以"能跑既定回归"为验收，不允许"写完再说"。

| # | 内容 | 产物 | 验收标准 |
| --- | --- | --- | --- |
| **M0** | 契约定稿 | 本文档集 | 结构/接口/时序三方不再变动（改动要回到文档） |
| **M1** | 骨架 + 构建迁移 | `vsoc_pkg` `vsoc_axi_if` `axi4_ram_dpi` `axi4_default_slave` `axi4_demux` `u_soc` `u_core` `sim_top` | `make verilator-exec` 通过；`make -C test run EXT=riscv32i` difftest 全过；跑分与旧 `npc.v` 基线**偏差 < 1%** |
| **M2** | UART 接入 | `axi4_uart` | `EXT=riscv32i` 用例的串口输出与旧 `sim_mmio.v` 完全一致（字符级比对） |
| **M3** | 错误语义 + 协议检查器 | `axi4_protocol_checker` + 全部 DECERR 路径 | 注入一笔"未映射地址的投机 load"后仿真**不挂死**，核收到 `loadAccessFault`；检查器 C1–C12 全绿 |
| **M4** | 时延注入 + 校准 | `axi4_delay` + 扫描脚本 | 参数为 0 时性能与 M3 完全一致；参数 > 0 时能画出 IPC–延迟曲线 |
| **M5** | 清理 | 删除旧 RTL | `sim-verilator/verilog/npc.v`、`sim_mmio.v`、`vsoc/simtop.v` 删除；仓库里只剩一条 SoC 实现路径 |
| **P4/P5**（另一条线） | 核侧放开投机访存与 CFI 顺序 | 改 `playground/src/` | 见 §4 与 `deferred.md` |

### M1 的构建迁移步骤（照做即可）

1. `scriptmk/config.mk`：`TOP_MODULE ?= sim_top`，并放开 `ifeq ($(TOP_MODULE),npc)` 那个硬检查。
2. 让 vsoc 的 RTL 进 Verilator：
   - 简单做法：新增 `VSOC_RTL_DIR ?= $(PRJ)/resource/vsoc/rtl`，`EXTRA_V += $(shell find $(VSOC_RTL_DIR) -name '*.sv')`；
   - 注意**编译顺序**：`vsoc_pkg.sv` 和 `vsoc_axi_if.sv` 必须先于使用者；用 `-F filelist` 显式列顺序最稳，别依赖 `find` 的字典序（`axi4_*` 会排在 `vsoc_*` 前面，可能炸）。
3. `cpp/src/npc_sim.cpp`：`#include "Vnpc.h"` → `#include "Vsim_top.h"`，`std::make_unique<Vnpc>` → `Vsim_top`。
4. `cpp/src/npc_cpu.cpp` + `cpp/include/npc_cpu.h`：`Vnpc &` → `Vsim_top &`；端口名 `clock`/`reset` 不变。
5. Rust 侧**不改**（只依赖 DPI 符号名）。
6. 先让新 SoC 与旧 `npc.v` **同时存在**、通过切换 `TOP_MODULE` 二选一，回归对比通过后再删除旧文件（M5）。

## 2. 每步的验证手段

| 手段 | 命令/方式 | 看什么 |
| --- | --- | --- |
| 构建 | `make verilator-exec` | 编译错误、Verilator 警告（unused / width） |
| 功能 | `make -C test run EXT=riscv32i\|riscv32im\|riscv32ima` | difftest 与 NEMU 逐指令一致 |
| 串口 | 用例输出 | 字符级一致 |
| 性能 | `archbench` + `run/perf/<tag>/` | IPC、未提交周期数、DCache/ICache 命中率 |
| 协议 | 检查器断言 | C1–C12 |
| 时延 | M4 扫描脚本 | IPC–延迟曲线 |

**回归纪律**：每个里程碑都要留下一次完整跑分（`run/perf/<milestone>/`），否则性能优化没有可比基线。

## 3. 扩展指南

### 3.1 加一个外设（目标：只改 3 个地方）

1. `vsoc_pkg.sv`：加 `XXX_BASE` / `XXX_SIZE`，`DEV_XXX`，`NUM_SLAVES += 1`；
2. 写 `axi4_xxx.sv`（`vsoc_axi_if.slave`，别再定义第二套接口）；
3. `u_soc.sv`：加一个 `axi4_delay` + 一个 `axi4_xxx` 实例，接到 `u_demux` 的下行口。

约束：区域不重叠、大小为 2 的幂（小设备可破例）、必须有越界 → DECERR 的路径。

### 3.2 加第二个 master（DMA / 调试器）

那时才需要真正的 crossbar（多对多 + 仲裁），现在的 `axi4_demux` 会被替换成 `axi4_crossbar`，**但下游从设备和地址表不变**。这是把地址表做成单一事实源的最大回报。

### 3.3 多 outstanding + ID 路由（P4 之后）

1. `axi4_demux` 的路由记录从"1 bit 方向标志"升级成"按 `arid`/`awid` 索引的小表"（表深 = 核的最大 outstanding 数）；
2. 响应通道按 `rid`/`bid` 查表选路，而不是按当前在飞的事务选路；
3. 加一条规则：**同一个 ID 的响应必须按序返回**（表项里带顺序号）；
4. 从设备（pmem）需要支持多笔并发：至少一个小的请求队列 + 每笔独立的 beat 计数。
   建议顺序：先让 pmem 支持多笔读（写可以晚一步），因为读是瓶颈。

### 3.4 中断

现在核的 `io_interrupt` 接 0。将来有多个中断源时，新增 `irq_aggregator`（把各外设的中断源 OR / 编号），**不要**把中断逻辑塞进 `u_core` 或 `u_soc`。核内的 PLIC / CLINT 保持不变。

### 3.5 与可综合 SoC（ysyxSoC）对齐

- 本项目走的是"自己写 AXI4 SoC"路线，`ysyxSoC/`（rocket-chip diplomacy）是另一条路线；
- 若将来要把核塞进 `ysyxSoC`：注意 `ysyxSoC/src/CPU.scala` 里的 blackbox 名是 `ysyx_00000000`，与本核的 `ysyx_24100007` 不一致，需要统一；
- 还要注意 rocket-chip `AXI4Xbar` 对未映射地址会**悬空 ready**（挂死风险），必须显式挂一个 default slave —— 这正是本设计 `axi4_default_slave` 存在的原因。

## 4. 与"多分支在飞"的关系（不要弄错因果）

| 事实 | 说明 |
| --- | --- |
| 总线 DECERR **不会**让多条分支同时在飞 | 它只保证"投机的访存不会把整机挂死" |
| 真正的闸门在核侧 | `DataMemExternalization.hasOlderUnresolvedCfi`（有更老的未决 CFI 时禁止发投机访存）+ `IssueQueue.cfiBlocked`（CFI 之间按序执行） |
| 按下葫芦浮起瓢 | 一旦允许"有更老未决 CFI 时也发访存"，就必须能处理"响应回来时 owner 已经被 squash"：需要一个**响应接收器（sink）**把无主响应用掉，否则会卡在 `AxiDataAccess` 的 `assert(!requestOwned \|\| io.resp.fire)` 上 |

所以 P4/P5 的正确顺序是：

1. **P4a**：`AxiDataAccess` / DCache 加"无主响应丢弃"通路（先不改策略，只加能力）；
2. **P4b**：`AxiXbar` 的单 bit 路由 → 按 ID 的小表（支持多笔在飞）；
3. **P4c**：MSHR / load 队列深度检查（MLP 是吃掉延迟的关键）；
4. **P5**：放开 `hasOlderUnresolvedCfi` 与 `cfiBlocked`，做一次完整回归。
   时刻记录：**每放开一条限制，都必须能用 difftest 证明语义没变**（异常优先级、CSR 副作用、AMO 顺序是最容易破的三处）。

## 5. 风险

| 风险 | 影响 | 对策 |
| --- | --- | --- |
| Verilator 对 interface/modport 的兼容问题 | M1 卡住 | 回退方案：全扁平端口 + `s_axi_*`/`m_axi_*` 命名（结构不变，只改接线） |
| 编译顺序（pkg/interface 在后） | 编译报错 | 用 `-F filelist` 显式排序 |
| `Vnpc` → `Vsim_top` 改名漏改 | 链接失败 | 用 `rg "Vnpc" cpp/` 全量搜一遍 |
| 误改 DPI 签名 | host 侧静默失效 | `interfaces.md` §6 的表是契约；改必须同时改 `ffi.rs` |
| 把"未映射地址"做成悬空 | 挂死复现 | `axi4_default_slave` 必须存在；检查器 C6/C8 |
| 从设备写成"要求 AW/W 同拍" | 挂死 | 检查器 C11 + code review |
| 时延注入引入组合环 | 挂死 | 参数为 0 走直通；检查器 C1/C2 |
| 单笔 outstanding 是性能天花板 | 提不上去 | 靠 M4 的曲线量化，再决定 P4 的优先级 |
