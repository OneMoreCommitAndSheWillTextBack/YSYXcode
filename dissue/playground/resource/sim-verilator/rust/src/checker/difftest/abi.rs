use crate::common::{CpuContext, CsrContext, PrivilegeMode};

#[repr(C)]
#[derive(Debug, Clone, Copy, Default)]
pub(super) struct RiscvDifftestContext {
    gpr: [u32; 32],
    pc: u32,
    priv_: u32,
    csr: RiscvDifftestCsr,
}

impl From<&CpuContext> for RiscvDifftestContext {
    fn from(context: &CpuContext) -> Self {
        Self {
            gpr: context.gpr,
            pc: context.pc,
            priv_: difftest_priv_from_mode(context.privilege()),
            csr: RiscvDifftestCsr::from(context.csr),
        }
    }
}

impl From<RiscvDifftestContext> for CpuContext {
    fn from(raw: RiscvDifftestContext) -> Self {
        let mut context = Self {
            valid: 1,
            pc: raw.pc,
            privilege_raw: 0,
            gpr: raw.gpr,
            csr: raw.csr.into(),
        };
        context.set_privilege(privilege_mode_from_difftest(raw.priv_));
        context
    }
}

fn difftest_priv_from_mode(mode: PrivilegeMode) -> u32 {
    match mode {
        PrivilegeMode::Supervisor => 0,
        PrivilegeMode::Machine => 1,
        PrivilegeMode::User => 2,
        PrivilegeMode::Reserved(value) => value as u32,
    }
}

fn privilege_mode_from_difftest(value: u32) -> PrivilegeMode {
    match value {
        0 => PrivilegeMode::Supervisor,
        1 => PrivilegeMode::Machine,
        2 => PrivilegeMode::User,
        other => PrivilegeMode::Reserved(other as u8),
    }
}

#[repr(C)]
#[derive(Debug, Clone, Copy, Default)]
struct RiscvDifftestCsr {
    mepc: u32,
    sepc: u32,
    misa: u32,
    mstatus: u32,
    mstatush: u32,
    mcause: u32,
    mtval: u32,
    mtvec: u32,
    mscratch: u32,
    satp: u32,
    medeleg: u32,
    mideleg: u32,
    mvendorid: u32,
    marchid: u32,
    mhartid: u32,
    mimpid: u32,
    pmpaddr0: u32,
    pmpaddr1: u32,
    pmpaddr2: u32,
    pmpaddr3: u32,
    pmpaddr4: u32,
    pmpaddr5: u32,
    pmpaddr6: u32,
    pmpaddr7: u32,
    pmpcfg0: u32,
    pmpcfg1: u32,
    scause: u32,
    stval: u32,
    sscratch: u32,
    stvec: u32,
    mie: u32,
    mcounteren: u32,
    scounteren: u32,
    mcountinhibit: u32,
}

impl From<CsrContext> for RiscvDifftestCsr {
    fn from(csr: CsrContext) -> Self {
        Self {
            mepc: csr.mepc,
            sepc: csr.sepc,
            misa: csr.misa,
            mstatus: csr.mstatus,
            mstatush: csr.mstatush,
            mcause: csr.mcause,
            mtval: csr.mtval,
            mtvec: csr.mtvec,
            mscratch: csr.mscratch,
            satp: csr.satp,
            medeleg: csr.medeleg,
            mideleg: csr.mideleg,
            mvendorid: csr.mvendorid,
            marchid: csr.marchid,
            mhartid: csr.mhartid,
            mimpid: csr.mimpid,
            pmpaddr0: csr.pmpaddr0,
            pmpaddr1: csr.pmpaddr1,
            pmpaddr2: csr.pmpaddr2,
            pmpaddr3: csr.pmpaddr3,
            pmpaddr4: csr.pmpaddr4,
            pmpaddr5: csr.pmpaddr5,
            pmpaddr6: csr.pmpaddr6,
            pmpaddr7: csr.pmpaddr7,
            pmpcfg0: csr.pmpcfg0,
            pmpcfg1: csr.pmpcfg1,
            scause: csr.scause,
            stval: csr.stval,
            sscratch: csr.sscratch,
            stvec: csr.stvec,
            mie: csr.mie,
            mcounteren: csr.mcounteren,
            scounteren: csr.scounteren,
            mcountinhibit: csr.mcountinhibit,
        }
    }
}

impl From<RiscvDifftestCsr> for CsrContext {
    fn from(raw: RiscvDifftestCsr) -> Self {
        Self {
            mstatus: raw.mstatus,
            mtvec: raw.mtvec,
            mepc: raw.mepc,
            mcause: raw.mcause,
            mtval: raw.mtval,
            mie: raw.mie,
            mip: 0,
            mscratch: raw.mscratch,
            mcycle: 0,
            minstret: 0,
            sepc: raw.sepc,
            misa: raw.misa,
            mstatush: raw.mstatush,
            satp: raw.satp,
            medeleg: raw.medeleg,
            mideleg: raw.mideleg,
            mvendorid: raw.mvendorid,
            marchid: raw.marchid,
            mhartid: raw.mhartid,
            mimpid: raw.mimpid,
            pmpaddr0: raw.pmpaddr0,
            pmpaddr1: raw.pmpaddr1,
            pmpaddr2: raw.pmpaddr2,
            pmpaddr3: raw.pmpaddr3,
            pmpaddr4: raw.pmpaddr4,
            pmpaddr5: raw.pmpaddr5,
            pmpaddr6: raw.pmpaddr6,
            pmpaddr7: raw.pmpaddr7,
            pmpcfg0: raw.pmpcfg0,
            pmpcfg1: raw.pmpcfg1,
            scause: raw.scause,
            stval: raw.stval,
            sscratch: raw.sscratch,
            stvec: raw.stvec,
            mcounteren: raw.mcounteren,
            scounteren: raw.scounteren,
            mcountinhibit: raw.mcountinhibit,
        }
    }
}
