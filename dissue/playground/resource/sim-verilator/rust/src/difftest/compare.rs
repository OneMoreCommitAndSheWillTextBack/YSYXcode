use super::{DifftestError, DifftestResult, CSR_DIFF_SPECS};
use crate::cpu::{CpuContext, PrivMode};

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
        dut: PrivMode,
        reference: PrivMode,
    },
    Csr {
        name: &'static str,
        dut: u32,
        reference: u32,
    },
}

pub(super) fn compare_contexts(dut: &CpuContext, reference: &CpuContext) -> DifftestResult<()> {
    compare_contexts_raw(dut, reference).map_err(|mismatch| DifftestError::Mismatch {
        pc: dut.pc,
        mismatch,
        dut: *dut,
        reference: *reference,
    })
}

fn compare_contexts_raw(dut: &CpuContext, reference: &CpuContext) -> Result<(), DifftestMismatch> {
    if dut.pc != reference.pc {
        return Err(DifftestMismatch::Pc {
            dut: dut.pc,
            reference: reference.pc,
        });
    }

    for (index, (&dut_value, &ref_value)) in dut.gpr.iter().zip(reference.gpr.iter()).enumerate() {
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

    if dut.priv_mode != reference.priv_mode {
        return Err(DifftestMismatch::Priv {
            dut: dut.priv_mode,
            reference: reference.priv_mode,
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
