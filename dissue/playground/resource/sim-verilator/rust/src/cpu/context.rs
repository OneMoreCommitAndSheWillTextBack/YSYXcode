#[repr(C)]
#[derive(Debug, Clone, Copy, Default)]
pub struct NpcGprContext {
    pub x: [u32; 32],
}

#[repr(C)]
#[derive(Debug, Clone, Copy, Default)]
pub struct NpcCsrContext {
    pub mstatus: u32,
    pub mtvec: u32,
    pub mepc: u32,
    pub mcause: u32,
    pub mtval: u32,
    pub mie: u32,
    pub mip: u32,
    pub mscratch: u32,
    pub mcycle: u32,
    pub minstret: u32,
    pub sepc: u32,
    pub misa: u32,
    pub mstatush: u32,
    pub satp: u32,
    pub medeleg: u32,
    pub mideleg: u32,
    pub mvendorid: u32,
    pub marchid: u32,
    pub mhartid: u32,
    pub mimpid: u32,
    pub pmpaddr0: u32,
    pub pmpaddr1: u32,
    pub pmpaddr2: u32,
    pub pmpaddr3: u32,
    pub pmpaddr4: u32,
    pub pmpaddr5: u32,
    pub pmpaddr6: u32,
    pub pmpaddr7: u32,
    pub pmpcfg0: u32,
    pub pmpcfg1: u32,
    pub scause: u32,
    pub stval: u32,
    pub sscratch: u32,
    pub stvec: u32,
    pub mcounteren: u32,
    pub scounteren: u32,
    pub mcountinhibit: u32,
}

#[repr(C)]
#[derive(Debug, Clone, Copy, Default)]
pub struct NpcCpuContext {
    pub valid: u8,
    pub pc: u32,
    pub priv_: u8,
    pub gpr: NpcGprContext,
    pub csr: NpcCsrContext,
}

impl NpcCpuContext {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn into_context(self) -> Option<CpuContext> {
        if self.valid == 0 {
            return None;
        }

        Some(self.into())
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum PrivMode {
    User,
    Supervisor,
    Machine,
    Reserved(u8),
}

impl Default for PrivMode {
    fn default() -> Self {
        Self::Machine
    }
}

impl From<u8> for PrivMode {
    fn from(value: u8) -> Self {
        match value & 0b11 {
            0b00 => Self::User,
            0b01 => Self::Supervisor,
            0b11 => Self::Machine,
            other => Self::Reserved(other),
        }
    }
}

impl From<PrivMode> for u8 {
    fn from(value: PrivMode) -> Self {
        match value {
            PrivMode::User => 0b00,
            PrivMode::Supervisor => 0b01,
            PrivMode::Machine => 0b11,
            PrivMode::Reserved(value) => value & 0b11,
        }
    }
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct CsrContext {
    pub mstatus: u32,
    pub mtvec: u32,
    pub mepc: u32,
    pub mcause: u32,
    pub mtval: u32,
    pub mie: u32,
    pub mip: u32,
    pub mscratch: u32,
    pub mcycle: u32,
    pub minstret: u32,
    pub sepc: u32,
    pub misa: u32,
    pub mstatush: u32,
    pub satp: u32,
    pub medeleg: u32,
    pub mideleg: u32,
    pub mvendorid: u32,
    pub marchid: u32,
    pub mhartid: u32,
    pub mimpid: u32,
    pub pmpaddr0: u32,
    pub pmpaddr1: u32,
    pub pmpaddr2: u32,
    pub pmpaddr3: u32,
    pub pmpaddr4: u32,
    pub pmpaddr5: u32,
    pub pmpaddr6: u32,
    pub pmpaddr7: u32,
    pub pmpcfg0: u32,
    pub pmpcfg1: u32,
    pub scause: u32,
    pub stval: u32,
    pub sscratch: u32,
    pub stvec: u32,
    pub mcounteren: u32,
    pub scounteren: u32,
    pub mcountinhibit: u32,
}

impl From<NpcCsrContext> for CsrContext {
    fn from(raw: NpcCsrContext) -> Self {
        Self {
            mstatus: raw.mstatus,
            mtvec: raw.mtvec,
            mepc: raw.mepc,
            mcause: raw.mcause,
            mtval: raw.mtval,
            mie: raw.mie,
            mip: raw.mip,
            mscratch: raw.mscratch,
            mcycle: raw.mcycle,
            minstret: raw.minstret,
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

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub struct CpuContext {
    pub pc: u32,
    pub priv_mode: PrivMode,
    pub gpr: [u32; 32],
    pub csr: CsrContext,
}

impl From<NpcCpuContext> for CpuContext {
    fn from(raw: NpcCpuContext) -> Self {
        Self {
            pc: raw.pc,
            priv_mode: raw.priv_.into(),
            gpr: raw.gpr.x,
            csr: raw.csr.into(),
        }
    }
}
