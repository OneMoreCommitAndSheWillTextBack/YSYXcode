use super::{DifftestError, DifftestResult, CSR_DIFF_SPECS};
use crate::common::{CpuContext, PrivilegeMode};
use std::fmt;

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum DifftestMismatch {
    Pc {
        dut: u32,
        reference: u32,
    },
    Gpr {
        index: usize,
        dut: u32,
        reference: u32,
    },
    Priv {
        dut: PrivilegeMode,
        reference: PrivilegeMode,
    },
    Csr {
        name: &'static str,
        dut: u32,
        reference: u32,
    },
}

impl fmt::Display for DifftestMismatch {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Pc { dut, reference } => write!(
                formatter,
                "program counter differs: DUT=0x{dut:08x}, reference=0x{reference:08x}"
            ),
            Self::Gpr {
                index,
                dut,
                reference,
            } => write!(
                formatter,
                "x{index} differs: DUT=0x{dut:08x}, reference=0x{reference:08x}"
            ),
            Self::Priv { dut, reference } => {
                write!(
                    formatter,
                    "privilege mode differs: DUT={dut:?}, reference={reference:?}"
                )
            }
            Self::Csr {
                name,
                dut,
                reference,
            } => write!(
                formatter,
                "CSR `{name}` differs: DUT=0x{dut:08x}, reference=0x{reference:08x}"
            ),
        }
    }
}

pub(super) fn compare_contexts(dut: &CpuContext, reference: &CpuContext) -> DifftestResult<()> {
    compare_contexts_except_gprs(dut, reference, 0)
}

pub(super) fn compare_contexts_except_gprs(
    dut: &CpuContext,
    reference: &CpuContext,
    ignored_gpr_mask: u32,
) -> DifftestResult<()> {
    compare_contexts_raw(dut, reference, ignored_gpr_mask).map_err(|mismatch| {
        DifftestError::Mismatch {
            pc: dut.pc,
            mismatch,
            dut: *dut,
            reference: *reference,
        }
    })
}

fn compare_contexts_raw(
    dut: &CpuContext,
    reference: &CpuContext,
    ignored_gpr_mask: u32,
) -> Result<(), DifftestMismatch> {
    if dut.pc != reference.pc {
        return Err(DifftestMismatch::Pc {
            dut: dut.pc,
            reference: reference.pc,
        });
    }

    for (index, (&dut_value, &ref_value)) in dut.gpr.iter().zip(reference.gpr.iter()).enumerate() {
        if (ignored_gpr_mask & (1 << index)) != 0 {
            continue;
        }
        if dut_value != ref_value {
            return Err(DifftestMismatch::Gpr {
                index,
                dut: dut_value,
                reference: ref_value,
            });
        }
    }

    for spec in CSR_DIFF_SPECS {
        if spec.diff_enabled() {
            compare_csr(spec.name(), spec.read(&dut.csr), spec.read(&reference.csr))?;
        }
    }

    if dut.privilege() != reference.privilege() {
        return Err(DifftestMismatch::Priv {
            dut: dut.privilege(),
            reference: reference.privilege(),
        });
    }

    Ok(())
}

fn compare_csr(name: &'static str, dut: u32, reference: u32) -> Result<(), DifftestMismatch> {
    if dut == reference {
        return Ok(());
    }

    Err(DifftestMismatch::Csr {
        name,
        dut,
        reference,
    })
}
