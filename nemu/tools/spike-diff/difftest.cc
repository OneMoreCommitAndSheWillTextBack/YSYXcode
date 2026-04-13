/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the
 * Mulan PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

// #include "../../include/common.h"
#include "mmu.h"
#include "sim.h"
#include <cstdint>
#include <difftest-def.h>

#define NR_GPR MUXDEF(CONFIG_RVE, 16, 32)

static std::vector<std::pair<reg_t, abstract_device_t *>>
    difftest_plugin_devices;
static std::vector<std::string> difftest_htif_args;
static std::vector<std::pair<reg_t, mem_t *>>
    difftest_mem(1, std::make_pair(reg_t(DRAM_BASE), new mem_t(CONFIG_MSIZE)));
static debug_module_config_t difftest_dm_config = {
    .progbufsize = 2,
    .max_sba_data_width = 0,
    .require_authentication = false,
    .abstract_rti = 0,
    .support_hasel = true,
    .support_abstract_csr_access = true,
    .support_abstract_fpr_access = true,
    .support_haltgroups = true,
    .support_impebreak = true};

struct diff_csr {
  uint32_t mepc;
  uint32_t mstatus;
  uint32_t mcause;
  uint32_t mtvec;
  uint32_t satp;
};

struct diff_context_t {
  uint32_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  uint32_t pc;
  diff_csr csr;
};

static sim_t *s = NULL;
static processor_t *p = NULL;
static state_t *state = NULL;

void sim_t::diff_init(int port) {
  p = get_core("0");
  state = p->get_state();
}

void sim_t::diff_step(uint64_t n) { step(n); }

void sim_t::diff_get_regs(void *diff_context) {
  struct diff_context_t *ctx = (struct diff_context_t *)diff_context;
  for (int i = 0; i < NR_GPR; i++) {
    ctx->gpr[i] = state->XPR[i];
  }
  ctx->pc = state->pc;

  // get csr from spike
  ctx->csr.mcause = state->mcause->read();
  ctx->csr.mepc = state->mepc->read();
  ctx->csr.mstatus = state->mstatus->read();
  ctx->csr.mtvec = state->mtvec->read();
  ctx->csr.satp = state->satp->read();
}

#define rv32_csr_syn(csrname) state->csrname->write(ctx->csr.csrname)
void sim_t::diff_set_regs(void *diff_context) {
  struct diff_context_t *ctx = (struct diff_context_t *)diff_context;
  for (int i = 0; i < NR_GPR; i++) {
    state->XPR.write(i, (int32_t)ctx->gpr[i]);
  }
  state->pc = ctx->pc;
  rv32_csr_syn(mstatus);
  rv32_csr_syn(mcause);
  rv32_csr_syn(mepc);
  rv32_csr_syn(mtvec);
  rv32_csr_syn(satp);
}

void sim_t::diff_memcpy_to_ref(reg_t dest, void *src, size_t n) {
  mmu_t *mmu = p->get_mmu();
  for (size_t i = 0; i < n; i++) {
    mmu->store<uint8_t>(dest + i, *((uint8_t *)src + i));
  }
}

void sim_t::diff_memcpy_to_dut(reg_t src, void *dest, size_t n) {
  mmu_t *mmu = p->get_mmu();
  for (size_t i = 0; i < n; i++) {
    *((uint8_t *)dest + i) = mmu->load<uint8_t>(src + i);
  }
}

extern "C" {

__EXPORT void difftest_memcpy(uint32_t addr, void *buf, size_t n,
                              int direction) {
  if (direction == DIFFTEST_TO_REF) {
    s->diff_memcpy_to_ref(addr, buf, n);
  } else if (direction == DIFFTEST_TO_DUT) {
    s->diff_memcpy_to_dut(addr, buf, n);
  }
}

__EXPORT void difftest_regcpy(void *dut, int direction) {
  if (direction == DIFFTEST_TO_REF) {
    s->diff_set_regs(dut);
  } else {
    s->diff_get_regs(dut);
  }
}

__EXPORT void difftest_exec(uint64_t n) { s->diff_step(n); }

__EXPORT void difftest_init(int port) {
  difftest_htif_args.push_back("");
  const char *isa =
      "RV" MUXDEF(CONFIG_RV64, "64", "32") MUXDEF(CONFIG_RVE, "E", "I") "MAFDC";
  cfg_t cfg(/*default_initrd_bounds=*/std::make_pair((reg_t)0, (reg_t)0),
            /*default_bootargs=*/nullptr,
            /*default_isa=*/isa,
            /*default_priv=*/DEFAULT_PRIV,
            /*default_varch=*/DEFAULT_VARCH,
            /*default_misaligned=*/false,
            /*default_endianness*/ endianness_little,
            /*default_pmpregions=*/16,
            /*default_mem_layout=*/std::vector<mem_cfg_t>(),
            /*default_hartids=*/std::vector<size_t>(1),
            /*default_real_time_clint=*/false,
            /*default_trigger_count=*/4);
  s = new sim_t(&cfg, false, difftest_mem, difftest_plugin_devices,
                difftest_htif_args, difftest_dm_config, nullptr, false, NULL,
                false, NULL, true);
  s->diff_init(port);
}

__EXPORT void difftest_raise_intr(uint64_t NO) {
  trap_t t(NO);
  p->take_trap_public(t, state->pc);
}
}
