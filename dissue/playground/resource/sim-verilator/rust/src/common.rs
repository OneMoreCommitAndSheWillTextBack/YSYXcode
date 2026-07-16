//! Shared value types used at module boundaries.
//!
//! This module deliberately contains data only.  Runtime owners such as
//! `Machine`, `Checker`, and `Driver` live in their own modules so this file
//! remains a dependency leaf.

/// Number of integer registers in the RISC-V architectural register file.
pub(crate) const GPR_COUNT: usize = 32;

/// Architectural privilege encoded by the DUT and the difftest ABI.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) enum PrivilegeMode {
    User,
    Supervisor,
    Machine,
    Reserved(u8),
}

impl Default for PrivilegeMode {
    fn default() -> Self {
        Self::Machine
    }
}

impl From<u8> for PrivilegeMode {
    fn from(value: u8) -> Self {
        match value & 0b11 {
            0b00 => Self::User,
            0b01 => Self::Supervisor,
            0b11 => Self::Machine,
            other => Self::Reserved(other),
        }
    }
}

impl From<PrivilegeMode> for u8 {
    fn from(value: PrivilegeMode) -> Self {
        match value {
            PrivilegeMode::User => 0b00,
            PrivilegeMode::Supervisor => 0b01,
            PrivilegeMode::Machine => 0b11,
            PrivilegeMode::Reserved(value) => value & 0b11,
        }
    }
}

/// Control and status registers exported by the RTL and compared by difftest.
#[repr(C)]
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub(crate) struct CsrContext {
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

/// Complete architectural state snapshot produced by the RTL.
///
/// Its C representation matches `NpcCpuContext` in the native bridge.  The
/// raw privilege byte keeps the ABI stable; callers use [`Self::privilege`]
/// rather than interpreting it directly.
#[repr(C)]
#[derive(Debug, Clone, Copy, Default, PartialEq, Eq)]
pub(crate) struct CpuContext {
    pub valid: u8,
    pub pc: u32,
    pub privilege_raw: u8,
    pub gpr: [u32; GPR_COUNT],
    pub csr: CsrContext,
}

impl CpuContext {
    /// Whether the DPI producer supplied a complete architectural snapshot.
    pub(crate) fn is_valid(self) -> bool {
        self.valid != 0
    }

    /// Decodes the ABI privilege value into the architectural privilege mode.
    pub(crate) fn privilege(self) -> PrivilegeMode {
        self.privilege_raw.into()
    }

    /// Updates the ABI privilege value from an architectural privilege mode.
    pub(crate) fn set_privilege(&mut self, privilege: PrivilegeMode) {
        self.privilege_raw = privilege.into();
    }
}
